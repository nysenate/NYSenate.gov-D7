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
  $items = [];

  $items["transcript-import"] = [
    "description" => "Import transcripts from OpenLeg.",
    "options" => [
      "timestamp" => "Override the timestamp passed to the update API",
      "force" => "Ignore any existing process lock and run anyways",
      "dry-run" => "Do not actually save any nodes.  Also turns on debug mode",
    ],
  ];

  return $items;
}

function drush_nys_transcript_import_transcript_import() {
  drush_log("Start time: " . date("Y-m-d H:i:s", time()), 'ok');

  $timestamp = drush_get_option('timestamp', NULL);
  $force = drush_get_option('force', FALSE);
  $dry_run = (boolean) drush_get_option('dry-run', FALSE);
  if ($dry_run) {
    drush_set_context('DRUSH_DEBUG', TRUE);
    drush_log('Dry run enabled, debug enabled', 'debug');
  }
  try {
    $ret = nys_transcript_import_run($timestamp, $force, (!$dry_run));
  } catch (Exception $e) {
    drush_log("EXCEPTION: " . $e->getMessage(), 'error');
    $ret = FALSE;
  }

  if ($ret && (!$dry_run)) {
    nys_utils_set_cron_lastrun('transcript_import');
  }
  drush_log("End time: " . date("m/d/Y H:i:s", strtotime("now")), 'completed');
}

/**
 * First, fetch results from the updates API.  Then iterate and paginate
 * those results and, per transcript, make a request to the transcript API.
 * Finally, map values and save each transcript as a node.
 *
 * @param null $timestamp
 * @param bool $force
 *
 * @return bool
 * @throws \Exception
 */
function nys_transcript_import_run($timestamp = NULL, $force = FALSE, $save = TRUE) {
  // Find the last run.  If no timestamp was passed, used last run instead.
  $last_run = nys_utils_get_cron_lastrun('transcript_import', date("Y-m-d\TH:i:s", 0));
  if (!$timestamp) {
    $timestamp = $last_run;
    drush_log("No timestamp provided, using last run", 'warning');
  }
  // Make sure the timestamp is formatted for OL.
  $timestamp = date('Y-m-d\TH:i:s', strtotime($timestamp));
  drush_log('Searching updates from ' . $timestamp, 'ok');

  // Check the process lock.  Quit, if necessary; otherwise, set the lock.
  $lock = variable_get('nys_transcript_import_lock', 0);
  if ($lock) {
    drush_log("Process lock exists! " . date("Y-m-d H:i:s", $lock), 'warning');
    if ($force) {
      drush_log("Found --force, ignoring lock ...", 'ok');
    }
    else {
      drush_log("Aborting process due to existing lock", 'error');
      return FALSE;
    }
  }
  variable_set('nys_transcript_import_lock', time());

  // Set up drush as the logger
  NysTranscriptImportProcessor::setLog('drush_log');

  // For every transcript type in file_ol_transcript_type options, try
  // to load updates.
  foreach (NysTranscriptImportProcessor::getTranscriptTypes() as $type => $info) {
    // Instantiate processor for this type.
    try {
      $instance = NysTranscriptImportProcessor::getInstance($type);
    } catch (Exception $e) {
      drush_log("Failed to instantiate processor for {$type}", 'error');
      continue;
    }

    // Try to load updates since $timestamp.
    $list = $instance::fetchUpdatesSince($timestamp);

    // Initialize the counters for this type.
    $good_results = $skip_results = 0;
    if (is_array($list)) {
      drush_log("Found " . count($list) . " items to import", 'ok');
      // For each update item, initialize the processor, try to find a
      // a matching node, and save the new/modified node.
      foreach ($list as $one_item) {
        $instance->initFromUpdate($one_item);
        drush_log("Found $type id={$instance->getUpdateId()}", 'debug');
        $node = $instance->getNode();
        $nid = ($node->nid ?? NULL) ? "matched to node {$node->nid}" : "unmatched/new node";
        drush_log("Importing {$instance->getId()}, {$nid}", 'ok');

        // Log and adjust counters, as necessary
        if ($save) {
          if ($instance->save()) {
            $good_results++;
          }
          else {
            $skip_results++;
            drush_log("Failed import for {$type} {$instance->getId()}, check watchdog", 'error');
          }
        }
        else {
          $skip_results++;
          drush_log("Skipping {$type} {$instance->getId()} because saving was disabled", 'status');
        }
      }
    }
    else {
      drush_log('No updates returned from API', 'ok');
    }
    drush_log("$type process complete, $good_results imported, $skip_results skipped", "ok");
  }

  // Release the lock and buh-bye.
  variable_set('nys_transcript_import_lock', 0);
  drush_log("Transcript Import process done", 'ok');
  return TRUE;
}
