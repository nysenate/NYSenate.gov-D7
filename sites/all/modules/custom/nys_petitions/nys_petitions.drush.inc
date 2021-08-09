<?php

/**
 * @file
 * Drush integration functions for the nys_petitions module.
 */

/**
 * Implements hook_drush_command().
 */
function nys_petitions_drush_command() {
  $items = [];

  $items["reconcile-questionnaires"] = [
    "description" => "Reconcile questionnaire submissions not received by the accumulator.",
    "aliases" => ['rec-quest'],
    "options" => [
      'detail' => 'A message to add to the detail field, used to indicate the reason for the import.',
    ],
  ];

  return $items;
}

/**
 * Tries to locate any webform submissions for webforms attached to
 * a questionnaire content node, but which were not handled as a
 * questionnare submission.  This relies on missing entries from
 * table webform_submissions_questionnaires, as compared to entries
 * found in table webform_submissions.
 */
function drush_nys_petitions_reconcile_questionnaires() {
  // Query for all suspect entries.
  $query = "SELECT ws.sid AS sid, ws.uid, ws.completed, " .
    "nq.nid AS quest_nid, nq.vid AS quest_vid, nq.title AS quest_title, " .
    "ts.field_title_stub_value AS quest_stub, nw.nid AS webform_nid, " .
    "nw.vid AS webform_vid, nw.title AS webform_title, " .
    "wc.name as comp_name, wsd.data as comp_data, ws.submitted FROM " .
    "(SELECT wst.* FROM webform_submissions wst " .
    "LEFT JOIN webform_submissions_questionnaires wsqt " .
    "ON wst.sid=wsqt.sid WHERE wsqt.sid IS null) ws " .
    "INNER JOIN node nw " .
    "ON ws.nid = nw.nid AND nw.TYPE='webform' " .
    "INNER JOIN webform_submitted_data wsd " .
    "ON ws.sid=wsd.sid " .
    "INNER JOIN webform_component wc " .
    "ON ws.nid = wc.nid AND wsd.cid=wc.cid " .
    "INNER JOIN field_data_field_webform wfd " .
    "ON wfd.field_webform_target_id=ws.nid " .
    "INNER JOIN node nq " .
    "ON nq.nid=wfd.entity_id AND nq.TYPE='questionnaire' " .
    "INNER JOIN field_data_field_title_stub ts " .
    "ON nq.nid = ts.entity_id " .
    "ORDER BY sid, wsd.cid";
  $results = db_query($query);

  // Group the entries by submission ID for processing.
  $sorted = [];
  foreach ($results as $val) {
    $sorted[$val->sid] = $sorted[$val->sid] ?? [];
    $sorted[$val->sid][] = $val;
  }

  $msg = count($sorted)
    ? "Found @num untracked submissions.\n"
    : "No untracked submissions found.\n";
  echo t($msg, ['@num' => count($sorted)]);

  $detail_msg = drush_get_option('detail', '');

  foreach ($sorted as $sid => $answers) {
    // Initialize the response.
    $response = array_merge(
      _nys_accumulator_init_response(),
      [
        'msg_type' => 'petition',
        'msg_action' => 'questionnaire response',
      ]
    );

    // Get the first item as a sample for common values, and add them to the
    // response object.
    $sample = current($answers);
    $response['msg_info']['form_id'] = $sample->quest_vid;
    $response['msg_info']['form_title'] = $sample->quest_title;
    $response['msg_info']['stub'] = $sample->quest_stub;
    $response['msg_info']['detail'] = $detail_msg;


    // Reset the UID.
    $uid = $sample->uid ?? 0;

    // Compile the answers.
    $fields = [];
    foreach ($answers as $answer) {
      $fields[] = [
        'field' => $answer->comp_name,
        'value' => $answer->comp_data,
      ];
    }

    // Add the answers to the response object.
    $response['msg_info']['form_values'] = $fields;

    // Load the user info.
    $a_user = user_load($uid);

    // Load the Senator's shortname and user's district.
    $a_district = $a_user->field_district[LANGUAGE_NONE][0]['target_id'] ?? 0;

    // Load the user.
    nys_accumulator_retrieve_senator_and_district($a_district, $response);

    // Set the user data.
    nys_accumulator_populate_user_info($a_user, $response);

    // Manually set the verified bit since this is not on a live request.
    $response['user_is_verified'] = nys_accumulator_calculate_user_verified_bitflag($a_user);

    echo t("Inserting submission @sid into accumulator.\n", ['@sid' => $sid]);

    // Store in the accumulator table.
    nys_accumulator_action_insert($response);

    // Add to the custom questionnaires table also.
    db_insert('webform_submissions_questionnaires')
      ->fields([
        'uid' => $uid,
        'nid' => $sample->quest_vid,
        'sid' => $sid,
        'wid' => $sample->webform_nid,
        'timestamp' => $sample->completed,
      ])
      ->execute();
  }
}
