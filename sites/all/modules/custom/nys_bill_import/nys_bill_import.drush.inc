<?php

/**
 * @file
 * Drush integration functions for the nys_bill_import module.
 */

define("BILL_IMPORT_DATETIME_FORMAT", "Y-m-d\TH:i:s");
define("DATETIME_FORMAT", "Y-m-d\TH:i:s");

/**
 * Implements hook_drush_command().
 */
function nys_bill_import_drush_command() {
  $items = [];

  $items["bill-import"] = [
    "description" => "Import bills from OpenLeg.",
    "options" => [
      "billids" => "Comma separated list of bill ids to fetch. e.g. S1234-2015,S2180-2015",
      "session" => "Re-import all bills during the specified session year. e.g. 2015",
      "offset" => "Set an optional offset to pick up from a failed import. Defaults to 1.",
      "reset-lock" => "Clears the bill import lock.",
      "update-from" => "Timestamp indicating beginning of desired block of updates. (defaults to time of last run)",
      "update-to" => "Timestamp indicating end of desired block of updates. (defaults to 'now')",
    ],
  ];

  return $items;
}

/**
 * Callback for the 'bill-import' command.
 */
function drush_nys_bill_import_bill_import() {
  echo "START ---------------------------------------------------\n";
  echo t("Start time: @start", ['@start' => date("m/d/Y H:i:s", strtotime("now"))]) . "\n";
  $interval = variable_get("bill_import_interval", 60 * 5);
  $bill_ids_str = drush_get_option("billids", "");
  $session = drush_get_option("session", "");

  if (drush_get_option("reset-lock") !== NULL) {
    variable_set("bill_import_is_locked", FALSE);
  }

  $bill_id_arr = [];
  $bill_id_regex = "/([ASLREJKBC][0-9]{1,5}[A-Z]?)-([0-9]{4})/";
  foreach (explode(",", strtoupper($bill_ids_str)) as $key => $val) {
    $bill_id = trim($val);
    $matches = NULL;
    if ($bill_id && preg_match($bill_id_regex, $bill_id, $matches)) {
      array_push($bill_id_arr, [$matches[1], $matches[2]]);
    }
  }

  // Check the lock.
  $is_locked = variable_get("bill_import_is_locked", FALSE);
  $last_lock_time = variable_get("bill_import_last_lock_time", strtotime("now"));

  // If another process isn't running or that process has been locked > 5
  // minutes.
  if (!$is_locked || (strtotime("now") - $last_lock_time) > 300) {
    // Update the lock.
    variable_set("bill_import_is_locked", TRUE);
    variable_set("bill_import_last_lock_time", strtotime("now"));

    echo t("Executing... ");
    if (!empty($bill_id_arr)) {
      echo "importing individual bills...\n";
      foreach ($bill_id_arr as $key => $val) {
        nys_bill_import_fetch($val[1], $val[0]);
      }
    }
    elseif (!empty($session)) {
      echo "session-based import...\n";
      $offset = drush_get_option('offset', 1);
      nys_bill_import_re_import($session, $offset);
    }
    else {
      echo "range-based import...\n";
      $from_time = drush_get_option("update-from");
      $to_time = drush_get_option("update-to");
      $offset = drush_get_option('offset');
      nys_bill_import_run($from_time, $to_time, $offset);
    }
    variable_set("bill_import_is_locked", FALSE);
    variable_set('bill_import_next_execution', time() + $interval);
  }
  else {
    echo t("Skipping execution...");
    echo t("Is locked: '@lock'", ['@lock' => $is_locked]);
    echo t("Last lock time: '@lock'", ['@lock' => date("m/d/y h:i:s", $last_lock_time)]);
  }

  echo t("End time: @end", ['@end' => date("m/d/Y H:i:s", strtotime("now"))]) . "\n";
  nys_utils_set_cron_lastrun('bill_import');
}
