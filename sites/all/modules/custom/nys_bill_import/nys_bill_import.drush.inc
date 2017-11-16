<?php

define("DATETIME_FORMAT", "Y-m-d\TH:i:s");

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_bill_import_drush_command() {
  $items = array();

  $items["bill-import"] = array(
    "description" => "Import bills from OpenLeg.",
    "options"     => array(
      "timestamp" => "Override the timestamp passed to the update API",
      "billids"   => "Comma separated list of bill ids to fetch. e.g. S1234-2015,S2180-2015",
      "session" => "Re-import all bills during the specified session year. e.g. 2015",
      "offset" => "If reimporting a session year, set an optional offset to pick up from a failed import.",
      "reset-lock" => "Clears any locks."
    ),
  );

  $items["bill-qa"] = array(
    "description" => "Create a data quality report against Open Legislation.",
    "options"     => array(
      "from"      => "Check against bill updates that occurred since this datetime (default: one day ago)",
      "to"        => "Check against bill updates that occurred up to this datetime (default: now)",
      "session"   => "Check against bills in a session year. This option takes priority over 'from' and 'to' dates if specified. (default: none)",
      "session-to-date" => "Check against bills in the current session. (default: false)",
      "year-to-date" => "Check against bills since the start of the year. (default: false)"
    )
  );

  return $items;
}

function drush_nys_bill_import_bill_qa() {
  // Check the lock.
  $is_locked      = variable_get("bill_qa_is_locked", false);
  $last_lock_time = variable_get("bill_qa_last_lock_time", strtotime("now"));

  if (!$is_locked) {
    drupal_set_message(t("Start time: @start", ['@start' => date(DATE_ISO8601, strtotime("now"))]));
    $from = drush_get_option("from", date(DATETIME_FORMAT, strtotime('-1 day', strtotime("now"))));
    $to   = drush_get_option("to", date(DATETIME_FORMAT, strtotime("now")));
    $session = drush_get_option("session");
    $session_to_date = drush_get_option("session-to-date", false);
    $year_to_date = drush_get_option("year-to-date", false);

    if ($session_to_date) {
      $year = date("Y");
      $session = $year % 2 == 0 ? $year - 1 : $year;
    }

    if ($year_to_date) {
      $from = date(DATETIME_FORMAT, mktime(0,0,1,1,1, date("Y")));
      $to = date(DATETIME_FORMAT, strtotime("now"));
    }

    nys_bill_import_bill_qa($from, $to, $session);
    drupal_set_message(t("End time: @end", ['@end' => date(DATE_ISO8601, strtotime("now"))]));

    variable_set("bill_qa_is_locked", false);
  }
  else {
    drupal_set_message(t("The bill qa process is already running."));
  }
}

function drush_nys_bill_import_bill_import() {
  drupal_set_message(t("Start time: @start", ['@start' => date("m/d/Y H:i:s", strtotime("now"))]));
  $interval     = variable_get("bill_import_interval", 60 * 5);
  $bill_ids_str = drush_get_option("billids", "");
  $session      = drush_get_option("session", "");
  $timestamp    = drush_get_option("timestamp", variable_get("bill_import_last_update", "2000-01-01T00:00:00"));

  if (drush_get_option("reset-lock") !== NULL) {
    variable_set("bill_import_is_locked", false);
  }

  $bill_id_arr = array();
  $bill_id_regex = "/([ASLREJKBC][0-9]{1,5}[A-Z]?)-([0-9]{4})/";
  foreach (explode(",", strtoupper($bill_ids_str)) as $key=>$val) {
    $bill_id = trim($val);
    $matches = null;
    if ($bill_id && preg_match($bill_id_regex, $bill_id, $matches)) {
      array_push($bill_id_arr, array($matches[1], $matches[2]));
    }
  }

  // Check the lock.
  $is_locked      = variable_get("bill_import_is_locked", false);
  $last_lock_time = variable_get("bill_import_last_lock_time", strtotime("now"));

  // If another process isn't running or that process has been locked > 5 minutes.
  if (!$is_locked || (strtotime("now") - $last_lock_time) > 300) {
    // Update the lock.
    variable_set("bill_import_is_locked", true);
    variable_set("bill_import_last_lock_time", strtotime("now"));

    drupal_set_message(t("Executing..."));
    if (!empty($bill_id_arr)) {
      foreach ($bill_id_arr as $key=>$val) {
        nys_bill_import_fetch($val[1], $val[0]);
      }
    }
    else if (!empty($session)) {
      $offset = drush_get_option('offset', 1);
      nys_bill_import_re_import($session, $offset);
    }
    else {
      nys_bill_import_run($timestamp);
    }
    variable_set("bill_import_is_locked", false);
    variable_set('bill_import_next_execution', time() + $interval);
   } else {
     drupal_set_message(t("Skipping execution..."));
     drupal_set_message(t("Is locked: '@lock'", ['@lock' => $is_locked]));
     drupal_set_message(t("Last lock time: '@lock'", ['@lock' => date("m/d/y h:i:s", $last_lock_time)]));
   }

  drupal_set_message(t("End time: @end", ['@end' => date("m/d/Y H:i:s", strtotime("now"))]));
}
