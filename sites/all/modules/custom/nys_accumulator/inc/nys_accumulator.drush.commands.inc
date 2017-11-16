<?php
// Logging levels
define('NYS_LOGGING_ERROR', 1);
define('NYS_LOGGING_WARN', 2);
define('NYS_LOGGING_REPORT', 3);
define('NYS_LOGGING_INFO', 4);
define('NYS_LOGGING_DEBUG', 5);

function drush_nys_accumulator_accumulator_integrity($type) {
  $check_type = strtolower((string) $type);
  $known_sections = _integrity_check_action_types();
  $checked_sections = [];

  foreach ($known_sections as $known_type => $type_aliases) {
    if ($check_type == $known_type || in_array($check_type, $type_aliases)) {
      $function = "_integrity_check_type_{$known_type}";
      if (!function_exists($function)) {
        _output("Could not locate function $function to check type '$known_type'!", NYS_LOGGING_ERROR);
        continue;
      }
      $checked_sections[] = $known_type;
      _output("Processing type '$known_type' ...");
      $function();
      _output("Processing complete for type '$known_type'.");
    }
  }

  if (!count($checked_sections)) {
    _output("Found no process for type $type, no action taken.", NYS_LOGGING_WARN);
  }

  _finalize_output();
}

function _integrity_check_logging_level_labels() {
  return [1 => 'ERROR', 2 => 'WARN', 3 => 'REPORT', 4 => 'INFO', 5 => "DEBUG"];
}

function _finalize_output() {
  $output = &drupal_static('accumulator_integrity_output', []);
  $report = [];

  $send_report = variable_get('integrity_check_send_report', FALSE);
  $current_log_level = variable_get('integrity_check_log_level', NYS_LOGGING_WARN);
  foreach ($output as $val) {
    if (!empty($current_log_level[$val['level']])) {
      drupal_set_message("[" . $val['ts'] . "] " . $val['levelname'] . ": " . trim($val['msg']));
    }
    if ($send_report && $val['level'] == NYS_LOGGING_REPORT) {
      $report[] = $val;
    }
  }

  if ($send_report && count($report) && $email = variable_get('integrity_check_report_email')) {
    // Prepare the mail parameters.
    $mail_params = array(
      'body' => implode("<br />", array_column($report, 'msg')),
      'subject' => "[NYSenate.gov] Accumulator Integrity Check",
      'content-type' => 'text/html; charset=UTF-8; format=flowed',
    );

    // Send the email.
    $one_message = drupal_mail('nys_accumulator',
      "drush_automated_checks",
      $email,
      language_default(),
      $mail_params
    );
  }
}

function _output($msg, $level = NYS_LOGGING_INFO) {
  static $current_log_level;

  $output = &drupal_static('accumulator_integrity_output', []);

  $levels = _integrity_check_logging_level_labels();
  if (!$current_log_level) {
    $current_log_level = variable_get('integrity_check_log_level', NYS_LOGGING_WARN);
    if (!in_array($current_log_level, array_keys($levels))) {
      $current_log_level = NYS_LOGGING_WARN;
    }
  }

  $stamp = date("Y-m-d H:i:s");
  $lvlname = strtoupper($levels[$level]);
  $output[] = ['level' => $level, 'levelname' => $lvlname, 'ts' => $stamp, 'msg' => $msg];
}

function _integrity_check_get_object_property($array, $prop) {
  return array_map(function ($i) use ($prop) { return $i->$prop; }, $array);
}

function _integrity_check_action_types() {
  return [
    'petition_sign' => ['petitions', 'petition', 'ps', 'all'],
    'bill_votes' => ['bill_vote', 'bills', 'votes', 'bv', 'all'],
    'bill_follow' => ['bf'],
    'issues' => ['issue', 'all'],
    'committees' => ['comm', 'all'],
    'questionnaire' => ['question', 'all'],
    'account_create' => ['account', 'ac', 'all'],
  ];
}

function _integrity_check_session_expire_limit() {
  return variable_get('session_api_cookie_expire_time', 2592000);
}

function _integrity_check_get_standard_date() {
  static $printed = FALSE;

  // Get the time range from command line.  If not provide, use today.
  $start_time = strtotime(drush_get_option('start-time', date("Y-m-d")));
  $end_time = strtotime(drush_get_option('end-time', date("Y-m-d")));

  // Sanity check on the time range.
  if ($end_time < $start_time) {
    if (!$printed) {
      _output("end-time is earlier than start-time, setting end-time to start-time.", NYS_LOGGING_WARN);
    }
    $end_time = $start_time;
  }

  // Set to start to midnight, end to 23:59:59 of their respective days.
  $start_time = strtotime(date("Y-m-d 00:00:00", $start_time));
  $end_time = strtotime(date("Y-m-d 23:59:59", $end_time));
  if (!$printed) {
    $date_msg = ($start_time == $end_time) ? '' : " - " . date("Y-m-d", $end_time);
    _output("Fetched standard timestamps [ $start_time, $end_time ]", NYS_LOGGING_DEBUG);
    _output("Examining date range " . date("Y-m-d", $start_time) . $date_msg . "\n", NYS_LOGGING_REPORT);
  }
  $printed = TRUE;

  return [$start_time, $end_time];
}

function _integrity_check_is_unauth_check_ok($start_time, $end_time) {
  $one_month_ago = time() - _integrity_check_session_expire_limit();
  return min($start_time, $one_month_ago, $end_time) == $one_month_ago;
}

function _integrity_check_unauth_petitions($start_time, $end_time) {
  // Initialize the arrays used to compare.
  $accumulator_records = [];

  // Get the unauthenticated user records and index them by the signing_id.
  // The signing_id field is in the JSON.
  $unauth_records = db_select('accumulator', 'acc')
    ->fields('acc')
    ->condition('created_at', [$start_time, $end_time], 'BETWEEN')
    ->condition('msg_type', 'petition')
    ->condition('msg_action', 'sign')
    ->condition('user_id', 0)
    ->execute();
  while ($record = $unauth_records->fetchAssoc()) {
    $info = json_decode($record['msg_info']);
    $accumulator_records[$info->form_info->signing_id] = $record;
  }

  // Get the nys_petitions records, indexed by sid.
  $petition_records = db_select('nys_petitions', 'nysp')
    ->fields('nysp')
    ->condition('timestamp', [$start_time, $end_time], 'BETWEEN')
    ->execute()
    ->fetchAllAssoc('sid');

  // The two arrays should have the same keys.  Do a diff comparison to
  // find any records with no match.
  $diff = FALSE;
  $record_diff1 = array_diff_key($accumulator_records, $petition_records);
  $record_diff2 = array_diff_key($petition_records, $accumulator_records);

  // If diff1 has a count, that means the accumulator had records which
  // could not be matched to nys_petitions.
  if (count($record_diff1)) {
    // First, check the users table for a valid account using that email.
    // If it exists, the user confirmed their account, and the missing
    // nys_petitions record is expected behavior - remove it from the diff.
    foreach ($record_diff1 as $key => $val) {
      $info = json_decode($val['msg_info']);
      $user_check = db_select('users', 'u')
        ->fields('u', ['mail'])
        ->condition('mail', $info->form_info->user_email)
        ->where('login > created')
        ->countQuery();
      if ((int) $user_check->execute()->fetchField(0) == 1) {
        unset($record_diff1[$key]);
      }
    }
    // If diff1 still has a count, notify the authorities.
    if (count($record_diff1)) {
      $diff = TRUE;
      $plural = count($record_diff1) == 1 ? '' : 's';
      _output("Accumulator has " . count($record_diff1) . " record{$plural} not found in nys_petitions", NYS_LOGGING_REPORT);
      _output("Accumulator IDs: " . implode(', ', array_column($record_diff1, 'id')) . "\n", NYS_LOGGING_REPORT);
    }
  }

  // If diff2 has a count, that means nys_petitions has a row not reflected in
  // the accumulator.  There is no circumstance when this should be the case.
  // Notify the authorities.
  if (count($record_diff2)) {
    $diff = TRUE;
    $plural = count($record_diff2) == 1 ? '' : 's';
    $ids = implode(', ', _integrity_check_get_object_property($record_diff2, 'sid'));
    _output("NYS_petitions has " . count($record_diff2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
    _output("Signing IDs: {$ids}\n", NYS_LOGGING_REPORT);
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Petitions: unauthenticated accumulator matched nys_petitions OK!\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_auth_petitions($start_time, $end_time) {
  // Get the unauthenticated user records and index them with a complex key
  // created with user_id, created_at, and the node ID parsed from JSON.
  $accumulator = db_select('accumulator', 'acc')
    ->fields('acc')
    ->condition('created_at', [$start_time, $end_time], 'BETWEEN')
    ->condition('msg_type', 'petition')
    ->condition('msg_action', 'sign')
    ->condition('user_id', 0, '<>');
  $accumulator_records = [];
  foreach ($accumulator->execute() as $val) {
    $nid = basename(json_decode($val->msg_info)->event_info->content_url);
    $key = $val->user_id . '_' . $nid . '_' . $val->created_at;
    $accumulator_records[$key] = $val;
  }

  // Get the flagging records, and use the same index as the accumulator.
  $flagging = db_select('flagging', 'fg');
  $flagging->join('flag', 'f', 'f.fid=fg.fid AND f.name=:type',
    [':type' => 'sign_petition']);
  $flagging->fields('fg')
    ->condition('fg.timestamp', [$start_time, $end_time], 'BETWEEN')
    ->condition('fg.entity_type', 'node')
    ->condition('fg.sid', '0');
  $flagging_records = [];
  foreach ($flagging->execute() as $val) {
    $key = $val->uid . '_' . $val->entity_id . '_' . $val->timestamp;
    $flagging_records[$key] = $val;
  }

  // The two arrays should have the same keys.  Do a diff comparison to
  // find any records with no match.
  $diff = FALSE;
  $record_diff1 = array_diff_key($accumulator_records, $flagging_records);
  $record_diff2 = array_diff_key($flagging_records, $accumulator_records);

  // If diff1 has a count, that means the accumulator had records which
  // could not be matched to flagging.
  if (count($record_diff1)) {
    $diff = TRUE;
    $plural = count($record_diff1) == 1 ? '' : 's';
    $ids = implode(', ', _integrity_check_get_object_property($record_diff1, 'id'));
    _output("Accumulator has " . count($record_diff1) . " record{$plural} not found in flagging", NYS_LOGGING_REPORT);
    _output("Accumulator IDs: {$ids}\n", NYS_LOGGING_REPORT);
  }

  // If diff2 has a count, that means flagging has a row not reflected in
  // the accumulator.  We will need to check the user's account creation date
  // to make sure it was *after* the flag was recorded (i.e., the user created
  // their account during the petition process)
  if (count($record_diff2)) {
    // First, check the users table for a valid account using that email.
    // If it exists, the user confirmed their account, and the missing
    // nys_petitions record is expected behavior - remove it from the diff.
    foreach ($record_diff2 as $key => $val) {
      $user_check = db_select('users', 'u')
        ->fields('u', ['uid'])
        ->condition('uid', $val->uid)
        ->condition('created', $val->timestamp, '>=')
        ->countQuery();
      if ((int) $user_check->execute()->fetchField(0) == 1) {
        unset($record_diff2[$key]);
      }
    }
    // If diff1 still has a count, notify the authorities.
    if (count($record_diff2)) {
      $diff = TRUE;
      $plural = count($record_diff2) == 1 ? '' : 's';
      $ids = implode(', ', _integrity_check_get_object_property($record_diff2, 'flagging_id'));
      _output("Flagging has " . count($record_diff2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
      _output("Flagging IDs: {$ids}\n", NYS_LOGGING_REPORT);
    }
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Petitions: authenticated accumulator matched flagging OK!\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_auth_bill_follow($start_time, $end_time) {
  // Get the unauthenticated user records and index them with a complex key
  // created with user_id, created_at, and the node ID parsed from JSON.
  $accumulator = db_select('accumulator', 'acc')
    ->fields('acc')
    ->condition('created_at', [$start_time, $end_time], 'BETWEEN')
    ->condition('msg_type', 'bill')
    ->condition('msg_action', 'follow')
    ->condition('user_id', 0, '<>');
  $accumulator_records = [];
  foreach ($accumulator->execute() as $val) {
    $nid = basename(json_decode($val->msg_info)->event_info->content_url);
    $key = $val->user_id . '_' . $nid . '_' . $val->created_at;
    $accumulator_records[$key] = $val;
  }

  // Get the flagging records, and use the same index as the accumulator.
  $flagging = db_select('flagging', 'fg');
  $flagging->join('flag', 'f', 'f.fid=fg.fid AND f.name=:type',
    [':type' => 'follow_this_bill']);
  $flagging->fields('fg')
    ->condition('fg.timestamp', [$start_time, $end_time], 'BETWEEN')
    ->condition('fg.entity_type', 'node')
    ->condition('fg.sid', '0');
  $flagging_records = [];
  foreach ($flagging->execute() as $val) {
    $key = $val->uid . '_' . $val->entity_id . '_' . $val->timestamp;
    $flagging_records[$key] = $val;
  }


  // The two arrays should have the same keys.  Do a diff comparison to
  // find any records with no match.
  $diff = FALSE;
  $record_diff1 = array_diff_key($accumulator_records, $flagging_records);
  $record_diff2 = array_diff_key($flagging_records, $accumulator_records);

  // If diff1 has a count, that means the accumulator had records which
  // could not be matched to flagging.
  if (count($record_diff1)) {
    $diff = TRUE;
    $plural = count($record_diff1) == 1 ? '' : 's';
    $ids = implode(', ', _integrity_check_get_object_property($record_diff1, 'id'));
    _output("Accumulator has " . count($record_diff1) . " record{$plural} not found in flagging", NYS_LOGGING_REPORT);
    _output("Accumulator IDs: {$ids}\n", NYS_LOGGING_REPORT);
  }

  // If diff2 has a count, that means flagging has a row not reflected in
  // the accumulator.  We will need to check the user's account creation date
  // to make sure it was *after* the flag was recorded (i.e., the user created
  // their account during the bill follow process)
  if (count($record_diff2)) {
    // First, check the users table for a valid account using that email.
    // If it exists, the user confirmed their account, and the missing
    // nys_petitions record is expected behavior - remove it from the diff.
    foreach ($record_diff2 as $key => $val) {
      $user_check = db_select('users', 'u')
        ->fields('u', ['uid'])
        ->condition('uid', $val->uid)
        ->condition('created', $val->timestamp, '>=')
        ->countQuery();
      if ((int) $user_check->execute()->fetchField(0) == 1) {
        unset($record_diff2[$key]);
      }
    }
    // If diff1 still has a count, notify the authorities.
    if (count($record_diff2)) {
      $diff = TRUE;
      $plural = count($record_diff2) == 1 ? '' : 's';
      $ids = implode(', ', _integrity_check_get_object_property($record_diff2, 'flagging_id'));
      _output("Flagging has " . count($record_diff2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
      _output("Flagging IDs: {$ids}\n", NYS_LOGGING_REPORT);
    }
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Bill-follow: authenticated accumulator matched flagging OK!\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_unauth_bill_vote($start_time, $end_time) {
  // Initialize the arrays used to compare.
  $accumulator_records = [];

  // Get the unauthenticated user records and index them by the signing_id.
  // The signing_id field is in the JSON.
  $unauth_records = db_select('accumulator', 'acc')
    ->fields('acc')
    ->condition('created_at', [$start_time, $end_time], 'BETWEEN')
    ->condition('msg_type', 'bill')
    ->condition('msg_action', ['aye', 'nay'], 'IN')
    ->condition('user_id', 0)
    ->execute();
  while ($record = $unauth_records->fetchAssoc()) {
    $info = json_decode($record['msg_info']);
    $accumulator_records[$info->form_info->signing_id] = $record;
  }

  // Get the bills_anon records, indexed by sid.
  $bill_records = db_select('nys_bills_anon', 'nysba')
    ->fields('nysba')
    ->condition('timestamp', [$start_time, $end_time], 'BETWEEN')
    ->execute()
    ->fetchAllAssoc('sid');

  // The two arrays should have the same keys.  Do a diff comparison to
  // find any records with no match.
  $diff = FALSE;
  $record_diff1 = array_diff_key($accumulator_records, $bill_records);
  $record_diff2 = array_diff_key($bill_records, $accumulator_records);

  // If diff1 has a count, that means the accumulator had records which
  // could not be matched to nys_bills_anon.
  if (count($record_diff1)) {
    // First, check the users table for a valid account using that email.
    // If it exists, the user confirmed their account, and the missing
    // nys_bills_anon record is expected behavior - remove it from the diff.
    foreach ($record_diff1 as $key => $val) {
      $info = json_decode($val['msg_info']);
      $user_check = db_select('users', 'u')
        ->fields('u', ['mail'])
        ->condition('mail', $info->form_info->user_email)
        ->where('login > created')
        ->countQuery();
      if ((int) $user_check->execute()->fetchField(0) == 1) {
        unset($record_diff1[$key]);
      }
    }
    // If diff1 still has a count, notify the authorities.
    if (count($record_diff1)) {
      $diff = TRUE;
      $plural = count($record_diff1) == 1 ? '' : 's';
      _output("Accumulator has " . count($record_diff1) . " record{$plural} not found in nys_bills_anon", NYS_LOGGING_REPORT);
      _output("Accumulator IDs: " . implode(', ', array_column($record_diff1, 'id')) . "\n", NYS_LOGGING_REPORT);
    }
  }

  // If diff2 has a count, that means nys_bills_anon has a row not reflected in
  // the accumulator.  There is no circumstance when this should be the case.
  // Notify the authorities.
  if (count($record_diff2)) {
    $diff = TRUE;
    $plural = count($record_diff2) == 1 ? '' : 's';
    $ids = implode(', ', _integrity_check_get_object_property($record_diff2, 'sid'));
    _output("NYS_bills_anon has " . count($record_diff2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
    _output("Signing IDs: {$ids}\n", NYS_LOGGING_REPORT);
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Bill Vote: unauthenticated accumulator matched nys_bills_anon (OK!)\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_auth_bill_vote($start_time, $end_time) {
  // Get the unauthenticated user records and index them with a complex key
  // created with user_id and the node ID parsed from JSON.  Because of the
  // potential for multiple votes on the same bill, we exclude timestamp
  // from the check and only keep duplicates keys with the latest timestamp.
  $accumulator = db_select('accumulator', 'acc')
    ->fields('acc')
    ->condition('created_at', [$start_time, $end_time], 'BETWEEN')
    ->condition('msg_type', 'bill')
    ->condition('msg_action', ['aye', 'nay'], 'IN')
    ->condition('user_id', 0, '<>');
  $accumulator_records = [];
  foreach ($accumulator->execute() as $val) {
    $nid = basename(json_decode($val->msg_info)->event_info->content_url);
    $key = $val->user_id . '_' . $nid;
    if (!array_key_exists($key, $accumulator_records)
      || $val->created_at > $accumulator_records[$key]->created_at)
    {
      $accumulator_records[$key] = $val;
    }
  }

  // Get the voting records, indexed by uid and node id.  Timestamp is not
  // part of this check since the accumulator may have multiple votes per node.
  $voting = db_select('votingapi_vote', 'vote')
    ->fields('vote')
    ->condition('timestamp', [$start_time, $end_time], 'BETWEEN')
    ->condition('entity_type', 'node')
    ->condition('uid', '0', '>');
  $voting_records = [];
  foreach ($voting->execute() as $val) {
    $key = $val->uid . '_' . $val->entity_id;
    $voting_records[$key] = $val;
  }

  // The two arrays should have the same keys.  Do a diff comparison to
  // find any records with no match.
  $diff = FALSE;
  $record_diff1 = array_diff_key($accumulator_records, $voting_records);
  $record_diff2 = array_diff_key($voting_records, $accumulator_records);

  // If diff1 has a count, that means the accumulator had records which
  // could not be matched to votingapi_vote.
  if (count($record_diff1)) {
    $diff = TRUE;
    $plural = count($record_diff1) == 1 ? '' : 's';
    $ids = implode(', ', _integrity_check_get_object_property($record_diff1, 'id'));
    _output("Accumulator has " . count($record_diff1) . " record{$plural} not found in votingapi_vote", NYS_LOGGING_REPORT);
    _output("Accumulator IDs: {$ids}\n", NYS_LOGGING_REPORT);
  }

  // If diff2 has a count, that means votingapi_vote has a row not reflected in
  // the accumulator.  We will need to check the user's account creation date
  // to make sure it was *after* the vote was recorded (i.e., the user created
  // their account during the bill vote process)
  if (count($record_diff2)) {
    // First, check the users table for a valid account using that email.
    // If it exists, the user confirmed their account - remove it from the diff.
    foreach ($record_diff2 as $key => $val) {
      $user_check = db_select('users', 'u')
        ->fields('u', ['uid'])
        ->condition('uid', $val->uid)
        ->condition('created', $val->timestamp, '>=')
        ->countQuery();
      if ((int) $user_check->execute()->fetchField(0) == 1) {
        unset($record_diff2[$key]);
      }
    }
    // If diff1 still has a count, notify the authorities.
    if (count($record_diff2)) {
      $diff = TRUE;
      $plural = count($record_diff2) == 1 ? '' : 's';
      $ids = implode(', ', _integrity_check_get_object_property($record_diff2, 'vote_id'));
      _output("Votingapi_vote has " . count($record_diff2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
      _output("Voting IDs: {$ids}\n", NYS_LOGGING_REPORT);
    }
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Bill Vote: authenticated accumulator matched votingapi_vote OK!\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_auth_issue_follow($start_time, $end_time) {
  // Get the unauthenticated user records and index them with a complex key
  // created with user_id, created_at, and the term ID parsed from JSON.
  $accumulator = db_select('accumulator', 'acc')
    ->fields('acc')
    ->condition('created_at', [$start_time, $end_time], 'BETWEEN')
    ->condition('msg_type', 'issue')
    ->condition('msg_action', 'follow')
    ->condition('user_id', 0, '<>');
  $accumulator_records = [];
  foreach ($accumulator->execute() as $val) {
    $nid = basename(json_decode($val->msg_info)->event_info->content_url);
    $key = $val->user_id . '_' . $nid . '_' . $val->created_at;
    $val->node_id = $nid;
    $accumulator_records[$key] = $val;
  }

  // Get the flagging records, and use the same index as the accumulator.
  $flagging = db_select('flagging', 'fg');
  $flagging->join('flag', 'f', 'f.fid=fg.fid AND f.name=:type',
    [':type' => 'follow_issue']);
  $flagging->fields('fg')
    ->condition('fg.timestamp', [$start_time, $end_time], 'BETWEEN')
    ->condition('fg.entity_type', 'taxonomy_term')
    ->condition('fg.sid', '0');
  $flagging_records = [];
  foreach ($flagging->execute() as $val) {
    $key = $val->uid . '_' . $val->entity_id . '_' . $val->timestamp;
    $flagging_records[$key] = $val;
  }


  // The two arrays should have the same keys.  Do a diff comparison to
  // find any records with no match.
  $diff = FALSE;
  $record_diff1 = array_diff_key($accumulator_records, $flagging_records);
  $record_diff2 = array_diff_key($flagging_records, $accumulator_records);

  // If diff1 has a count, that means the accumulator had records which
  // could not be matched to flagging.  Re-check the accumulator for a
  // subsequent unfollow for the same users.
  if (count($record_diff1)) {
    // Check the accumulator unfollow records for the same user and term id.
    // If one is found, then the user unfollowed the issue, and the missing
    // flagging record is expected - remove it from the diff.
    foreach ($record_diff1 as $key => $val) {
      $unfollow_check = db_select('accumulator', 'acc')
        ->fields('acc')
        ->condition('msg_type', 'issue')
        ->condition('msg_action', 'unfollow')
        ->condition('user_id', $val->user_id)
        ->condition('msg_info', '%content_url":"\\\\/taxonomy\\\\/term\\\\/' . $val->node_id . '%', 'LIKE')
        ->countQuery();
      if ((int) $unfollow_check->execute()->fetchField(0) == 1) {
        unset($record_diff1[$key]);
      }
    }
    // If diff1 still has a count, notify the authorities.
    if (count($record_diff1)) {
      $diff = TRUE;
      $plural = count($record_diff1) == 1 ? '' : 's';
      $ids = implode(', ', _integrity_check_get_object_property($record_diff1, 'id'));
      _output("Accumulator has " . count($record_diff1) . " record{$plural} not found in flagging", NYS_LOGGING_REPORT);
      _output("Accumulator IDs: {$ids}\n", NYS_LOGGING_REPORT);
    }
  }

  // If diff2 has a count, that means flagging has a row not reflected in
  // the accumulator.
  if (count($record_diff2)) {
    $diff = TRUE;
    $plural = count($record_diff2) == 1 ? '' : 's';
    $ids = implode(', ', _integrity_check_get_object_property($record_diff2, 'flagging_id'));
    _output("Flagging has " . count($record_diff2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
    _output("Flagging IDs: {$ids}\n", NYS_LOGGING_REPORT);
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Follow Issue: authenticated accumulator matched flagging OK!\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_auth_committee_follow($start_time, $end_time) {
  // Get the unauthenticated user records and index them with a complex key
  // created with user_id, created_at, and the term ID parsed from JSON.
  $accumulator = db_select('accumulator', 'acc')
    ->fields('acc')
    ->condition('created_at', [$start_time, $end_time], 'BETWEEN')
    ->condition('msg_type', 'committee')
    ->condition('msg_action', 'follow')
    ->condition('user_id', 0, '<>');
  $accumulator_records = [];
  foreach ($accumulator->execute() as $val) {
    $nid = basename(json_decode($val->msg_info)->event_info->content_url);
    $key = $val->user_id . '_' . $nid . '_' . $val->created_at;
    $val->node_id = $nid;
    $accumulator_records[$key] = $val;
  }

  // Get the flagging records, and use the same index as the accumulator.
  $flagging = db_select('flagging', 'fg');
  $flagging->join('flag', 'f', 'f.fid=fg.fid AND f.name=:type',
    [':type' => 'follow_committee']);
  $flagging->fields('fg')
    ->condition('fg.timestamp', [$start_time, $end_time], 'BETWEEN')
    ->condition('fg.entity_type', 'taxonomy_term')
    ->condition('fg.sid', '0');
  $flagging_records = [];
  foreach ($flagging->execute() as $val) {
    $key = $val->uid . '_' . $val->entity_id . '_' . $val->timestamp;
    $flagging_records[$key] = $val;
  }


  // The two arrays should have the same keys.  Do a diff comparison to
  // find any records with no match.
  $diff = FALSE;
  $record_diff1 = array_diff_key($accumulator_records, $flagging_records);
  $record_diff2 = array_diff_key($flagging_records, $accumulator_records);

  // If diff1 has a count, that means the accumulator had records which
  // could not be matched to flagging.  Re-check the accumulator for a
  // subsequent unfollow for the same users.
  if (count($record_diff1)) {
    // Check the accumulator unfollow records for the same user and term id.
    // If one is found, then the user unfollowed the committee, and the missing
    // flagging record is expected - remove it from the diff.
    foreach ($record_diff1 as $key => $val) {
      $unfollow_check = db_select('accumulator', 'acc')
        ->fields('acc')
        ->condition('msg_type', 'committee')
        ->condition('msg_action', 'unfollow')
        ->condition('user_id', $val->user_id)
        ->condition('msg_info', '%content_url":"\\\\/taxonomy\\\\/term\\\\/' . $val->node_id . '%', 'LIKE')
        ->countQuery();
      if ((int) $unfollow_check->execute()->fetchField(0) == 1) {
        unset($record_diff1[$key]);
      }
    }
    // If diff1 still has a count, notify the authorities.
    if (count($record_diff1)) {
      $diff = TRUE;
      $plural = count($record_diff1) == 1 ? '' : 's';
      $ids = implode(', ', _integrity_check_get_object_property($record_diff1, 'id'));
      _output("Accumulator has " . count($record_diff1) . " record{$plural} not found in flagging", NYS_LOGGING_REPORT);
      _output("Accumulator IDs: {$ids}\n", NYS_LOGGING_REPORT);
    }
  }

  // If diff2 has a count, that means flagging has a row not reflected in
  // the accumulator.
  if (count($record_diff2)) {
    $diff = TRUE;
    $plural = count($record_diff2) == 1 ? '' : 's';
    $ids = implode(', ', _integrity_check_get_object_property($record_diff2, 'flagging_id'));
    _output("Flagging has " . count($record_diff2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
    _output("Flagging IDs: {$ids}\n", NYS_LOGGING_REPORT);
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Follow Committee: authenticated accumulator matched flagging OK!\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_auth_questionnaire($start_time, $end_time) {
  _output("Integrity checks on questionnaires has been disabled for now.  No work done.\n", NYS_LOGGING_INFO);
}

function _integrity_check_account_creations($start_time, $end_time) {
  // We can use a single, complex query to draw all accumulator records,
  // matched to the respective user accounts.  Pull a couple extra fields
  // from `u2` in order to analyze any with a NULL match.  The created_at
  // value is blurred by 10 seconds to account for timing anomalies.
  $filter = [':start' => $start_time, ':end' => $end_time];
  $query = "SELECT a.id, a.user_id, u.uid, a.created_at, u2.login, u2.status " .
    "FROM accumulator a LEFT JOIN users u " .
    "ON a.user_id=u.uid AND (a.created_at - 10) <= u.login " .
    "LEFT JOIN users u2 ON u2.uid=a.user_id " .
    "WHERE a.msg_type='account' AND a.msg_action='account created' " .
    "AND u.uid IS NULL AND a.created_at BETWEEN :start AND :end";
  $check1 = db_query($query, $filter)->fetchAllKeyed();

  $diff = FALSE;

  // Iterate over the results, analyzing each one for the reason it was
  // selected.
  if (count($check1)) {
    $diff = TRUE;
    $plural = count($check1) == 1 ? '' : 's';
    _output("Accumulator has " . count($check1) . " record{$plural} not found in users", NYS_LOGGING_REPORT);
    _output("Accumulator IDs: " . implode(', ', array_keys($check1)) . "\n", NYS_LOGGING_REPORT);
  }

  // Do the same thing in reverse - grab all users in the time range and
  // verify an accumulator record exists.  We can't depend on timestamps
  // here, so simply verifying the user_id will be enough.
  $query = "SELECT u.uid FROM users u LEFT JOIN accumulator a ON u.uid=a.user_id " .
    "AND a.msg_type='account' AND a.msg_action='account created' WHERE " .
    "u.created BETWEEN :start AND :end AND a.user_id IS NULL AND u.login > 0";
  $check2 = db_query($query, $filter)->fetchAllKeyed();

  // If any records are returned, notify the authorities.  There should be no
  // reason for a valid, confirmed user to not have an accumulator record.
  if (count($check2)) {
    $diff = TRUE;
    $plural = count($check2) == 1 ? '' : 's';
    _output("Users has " . count($check2) . " record{$plural} not found in accumulator", NYS_LOGGING_REPORT);
    _output("User IDs: " . implode(', ', array_keys($check2)) . "\n", NYS_LOGGING_REPORT);
  }

  // If both diffs are OK, say so.
  if (!$diff) {
    _output("Account creations: accumulator matched users OK!\n", NYS_LOGGING_REPORT);
  }
}

function _integrity_check_type_petition_sign() {
  // Get the timestamps/dates to be used.
  list($start_time, $end_time) = _integrity_check_get_standard_date();

  // Check unauth records only if date range is within the session limits.
  if (_integrity_check_is_unauth_check_ok($start_time, $end_time)) {
    _integrity_check_unauth_petitions($start_time, $end_time);
  }
  else {
    _output("Disabling sign petition checks for unauthenticated users due to session limits.", NYS_LOGGING_INFO);
  }

  // Check authenticated user records.
  _integrity_check_auth_petitions($start_time, $end_time);
}

function _integrity_check_type_bill_follow() {
  // Get the timestamps/dates to be used.
  list($start_time, $end_time) = _integrity_check_get_standard_date();

  // Check authenticated user records.
  _integrity_check_auth_bill_follow($start_time, $end_time);
}

function _integrity_check_type_bill_votes() {
  // Checking the bill votes also includes checking the associated follows.
  _integrity_check_type_bill_follow();

  // Get the timestamps/dates to be used.
  list($start_time, $end_time) = _integrity_check_get_standard_date();

  // Check unauth records only if date range is within the session limits.
  if (_integrity_check_is_unauth_check_ok($start_time, $end_time)) {
    _integrity_check_unauth_bill_vote($start_time, $end_time);
  }
  else {
    _output("Disabling bill vote checks for unauthenticated users due to session limits.", NYS_LOGGING_INFO);
  }

  // Check authenticated user records.
  _integrity_check_auth_bill_vote($start_time, $end_time);
}

function _integrity_check_type_issues() {
  // Get the timestamps/dates to be used.
  list($start_time, $end_time) = _integrity_check_get_standard_date();

  _integrity_check_auth_issue_follow($start_time, $end_time);
}

function _integrity_check_type_committees() {
  // Get the timestamps/dates to be used.
  list($start_time, $end_time) = _integrity_check_get_standard_date();

  _integrity_check_auth_committee_follow($start_time, $end_time);
}

function _integrity_check_type_questionnaire() {
  // Get the timestamps/dates to be used.
  list($start_time, $end_time) = _integrity_check_get_standard_date();

  _integrity_check_auth_questionnaire($start_time, $end_time);
}

function _integrity_check_type_account_create() {
  // Get the timestamps/dates to be used.
  list($start_time, $end_time) = _integrity_check_get_standard_date();

  _integrity_check_account_creations($start_time, $end_time);
}
