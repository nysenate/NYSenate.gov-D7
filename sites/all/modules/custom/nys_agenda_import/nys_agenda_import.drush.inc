<?php

/**
 * @file
 * Drush integration functions for the nys_agenda_import module.
 */

/**
 * Implements hook_drush_command().
 *
 * @see drush_parse_command()
 */
function nys_agenda_import_drush_command() {
  $items = [];

  $items["agenda-import"] = [
    "description" => "Import agendas from OpenLeg.",
    "options"     => [
      "timestamp"  => "Override the timestamp passed to the update API",
      "agendaids"  => "Comma separated list of agenda ids to fetch. e.g. 2015-1,2017-18",
      "year"       => "Re-import all agendas from the specified year. e.g. 2015",
      "reset-lock" => "Clears any locks.",
    ],
  ];

  return $items;
}

/**
 * Callback for the agenda-import command.
 */
function drush_nys_agenda_import_agenda_import() {
  echo "Start time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";

  $interval = variable_get("agenda_import_interval", 60 * 5);
  $timestamp = drush_get_option(
    "timestamp",
    variable_get("agenda_import_last_update", "2000-01-01T00:00:00")
  );
  $year = drush_get_option("year", "");
  $agenda_ids_raw = drush_get_option("agendaids", "");
  $reset_lock = drush_get_option(
    "reset-lock", variable_get("reset-lock", FALSE)
  );

  // Check the lock.
  $is_locked = variable_get("agenda_import_is_locked", FALSE);
  $last_lock_time = variable_get(
    "agenda_import_last_lock_time", strtotime("now")
  );

  // If another process isn't running or that process has been locked > 5
  // minutes.
  if ($reset_lock || !$is_locked
    || (strtotime("now") - $last_lock_time) > 300
  ) {
    try {
      // Update the lock.
      variable_set("agenda_import_is_locked", TRUE);
      variable_set("agenda_import_last_lock_time", strtotime("now"));

      echo "Executing...\r\n";

      if (!empty($agenda_ids_raw)) {
        $agenda_ids = drush_nys_agenda_import_parse_agenda_ids($agenda_ids_raw);
        foreach ($agenda_ids as $key => $val) {
          nys_agenda_import_fetch($val[0], $val[1]);
        }
      }
      else {
        if (!empty($year)) {
          drush_nys_agenda_import_verify_int("year", $year);
          nys_agenda_import_year($year);
        }
        else {
          nys_agenda_import_run($timestamp);
          variable_set('agenda_import_next_execution', time() + $interval);
        }
      }
    }
    catch (InvalidArgumentException $ex) {
      drush_log($ex->getMessage(), 'failed');
    } finally {
      variable_set("agenda_import_is_locked", FALSE);
    }
  }
  else {
    echo "Skipping execution...\r\n";
    echo "Is locked: '" . $is_locked . "'\r\n";
    echo "Last lock time: '" . date("m/d/y h:i:s", $last_lock_time) . "'\r\n";
  }

  echo "End time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";
}

/**
 * Verifies that the given parameter is an integer.
 *
 * Throws an exception if not.
 *
 * @param string $param_name
 *   The parameter name.
 * @param mixed $value
 *   The value to check.
 */
function drush_nys_agenda_import_verify_int($param_name, $value) {
  if (!(is_int($value) || ctype_digit($value))) {
    throw new InvalidArgumentException(
      "$param_name parameter must be an integer value.  Got '$value'"
    );
  }
}

/**
 * Parses a comma separated list of agenda ids into an array of agenda ids.
 *
 * @param string $agenda_ids_raw
 *   Comma separated agenda ids.
 *
 * @return array
 *   Parsed agenda ids with year and week broken out.
 */
function drush_nys_agenda_import_parse_agenda_ids($agenda_ids_raw) {
  $agenda_ids = [];
  $agenda_id_regex = "/^([0-9]{4})-([0-9]+)$/";
  foreach (explode(",", $agenda_ids_raw) as $key => $val) {
    $agenda_id = trim($val);
    $matches = NULL;
    if ($agenda_id && preg_match($agenda_id_regex, $agenda_id, $matches)) {
      array_push($agenda_ids, [$matches[1], $matches[2]]);
    }
    else {
      throw new InvalidArgumentException("Invalid agenda ids provided.");
    }
  }
  return $agenda_ids;
}
