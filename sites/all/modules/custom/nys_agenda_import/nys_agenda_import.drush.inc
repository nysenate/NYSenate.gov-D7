<?php

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_agenda_import_drush_command() {
  $items = array();
  
  $items["agenda-import"] = array(
    "description" => "Import agendas from OpenLeg.",
    "options"     => array(
      "timestamp" => "Override the timestamp passed to the update API",
      "reset-lock" => "Clears any locks.",
    ),
  );

  return $items;
}

function drush_nys_agenda_import_agenda_import() {
  echo "Start time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";

  $interval  = variable_get("agenda_import_interval", 60 * 5);
  $timestamp = drush_get_option("timestamp", variable_get("agenda_import_last_update", "2000-01-01T00:00:00"));
  $reset_lock = drush_get_option("reset-lock", variable_get("reset-lock", false));

  // Check the lock.
  $is_locked      = variable_get("agenda_import_is_locked", false);
  $last_lock_time = variable_get("agenda_import_last_lock_time", strtotime("now"));

  // If another process isn't running or that process has been locked > 5 minutes.
  if ($reset_lock || !$is_locked || (strtotime("now") - $last_lock_time) > 300) {
    // Update the lock.
    variable_set("agenda_import_is_locked", true);
    variable_set("agenda_import_last_lock_time", strtotime("now"));

    echo "Executing...\r\n";
    nys_agenda_import_run($timestamp);
    variable_set('agenda_import_next_execution', time() + $interval);
  } else {
    echo "Skipping execution...\r\n";
    echo "Is locked: '" . $is_locked . "'\r\n";
    echo "Last lock time: '" . date("m/d/y h:i:s", $last_lock_time) . "'\r\n";
  }

  echo "End time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";
}