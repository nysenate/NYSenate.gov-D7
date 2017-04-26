<?php

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_transcript_import_drush_command() {
  $items = array();
  
  $items["transcript-import"] = array(
    "description" => "Import transcripts from OpenLeg.",
    "options"     => array(
      "timestamp" => "Override the timestamp passed to the update API",
    ),
  );

  return $items;
}

function drush_nys_transcript_import_transcript_import() {
  echo "Start time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";

  $interval   = variable_get("transcript_import_interval", 60 * 5);
  $timestamps = array(
    "transcripts" => drush_get_option("timestamp", variable_get("transcripts_import_last_run", "2000-01-01T00:00:00")),
    "hearings"    => drush_get_option("timestamp", variable_get("hearings_import_last_run", "2000-01-01T00:00:00"))
  );

  // Check the lock.
  $is_locked      = variable_get("transcript_import_is_locked", false);
  $last_lock_time = variable_get("transcript_import_last_lock_time", strtotime("now"));

  // If another process isn't running or that process has been locked > 5 minutes.
  if (!$is_locked || (strtotime("now") - $last_lock_time) > 300) {
    // Update the lock.
    variable_set("transcript_import_is_locked", true);
    variable_set("transcript_import_last_lock_time", strtotime("now"));
    echo "Executing...\r\n";
    nys_transcript_import_run($timestamps);
    variable_set('transcript_import_next_execution', time() + $interval);
  } else {
    echo "Skipping execution...\r\n";
    echo "Is locked: '" . $is_locked . "'\r\n";
    echo "Last lock time: '" . date("m/d/y h:i:s", $last_lock_time) . "'\r\n";
  }

  echo "End time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";
}