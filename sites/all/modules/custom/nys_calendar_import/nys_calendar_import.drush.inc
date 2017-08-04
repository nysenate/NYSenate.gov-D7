<?php

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_calendar_import_drush_command() {
  $items = array();

  $items["calendar-import"] = array(
    "description" => "Import calendars from OpenLeg.",
    "options"     => array(
      "timestamp" => "Override the timestamp passed to the update API",
    ),
  );

  $items["calendar-qa"] = array(
    "description" => "Dump calendar data to OpenLegislation for use in a QA report",
    "options"     => array(
      "from"      => "Check against calendar updates that occurred since this datetime (default: one day ago)",
      "to"        => "Check against calendar updates that occurred up to this datetime (default: now)",
      "year"      => "Check against calendars for a given year" .
                     "This option takes priority over 'from' and 'to' dates if specified. (default: none)",
      "session"   => "Check against calendars in a session year. " .
                     "This option takes priority over 'year', 'from' and 'to' dates if specified. (default: none)",
      "year-to-date"    => "Check against calendars for the current year if set," . 
                           " equivalent to passing 'year' as current year",
      "session-to-date" => "Check against calendars for the current session year if set," .
                           " equivalent to passing 'session' as current session year",
      "print"     => "print the dump instead of sending it to openleg",
    )
  );

  return $items;
}

function drush_nys_calendar_import_calendar_import() {
  echo "Start time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";

  $interval  = variable_get("calendar_import_interval", 60 * 5);
  $timestamp = drush_get_option("timestamp", variable_get("calendar_import_last_update", "2000-01-01T00:00:00"));

  // Check the lock.
  $is_locked      = variable_get("calendar_import_is_locked", false);
  $last_lock_time = variable_get("calendar_import_last_lock_time", strtotime("now"));

  // If another process isn't running or that process has been locked > 5 minutes.
  if (!$is_locked || (strtotime("now") - $last_lock_time) > 300) {
    // Update the lock.
    variable_set("calendar_import_is_locked", true);
    variable_set("calendar_import_last_lock_time", strtotime("now"));

    echo "Executing...\r\n";
    nys_calendar_import_run($timestamp);
    variable_set('calendar_import_next_execution', time() + $interval);
  } else {
    echo "Skipping execution...\r\n";
    echo "Is locked: '" . $is_locked . "'\r\n";
    echo "Last lock time: '" . date("m/d/y h:i:s", $last_lock_time) . "'\r\n";
  }

  echo "End time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";
}

function drush_nys_calendar_import_calendar_qa() {
  // Check the lock.
  $is_locked      = variable_get("calendar_qa_is_locked", false);
  $last_lock_time = variable_get("calendar_qa_last_lock_time", strtotime("now"));

  if (!$is_locked) {
    echo "Start time: " . date(DATE_ISO8601, strtotime("now")) . "\r\n";
    $from = drush_get_option("from", date(DATETIME_FORMAT, strtotime('-1 day', strtotime("now"))));
    $to   = drush_get_option("to", date(DATETIME_FORMAT, strtotime("now")));
    $year = drush_get_option("year");
    $session = drush_get_option("session");
    $print = drush_get_option("print", false);
    $year_to_date = drush_get_option("year-to-date", false);
    $session_to_date = drush_get_option("session-to-date", false);

    $current_year = date("Y");

    if ($year_to_date) {
      $year = $current_year;
    }
    if ($session_to_date) {
      $session = $current_year % 2 === 0 ? $current_year - 1 : $current_year;
    }

    nys_calendar_import_calendar_qa($from, $to, $year, $session);
    echo "End time: " . date(DATE_ISO8601, strtotime("now")) . "\r\n";

    variable_set("calendar_qa_is_locked", false);
  }
  else {
    echo "The calendar qa process is already running.";
  }
}
