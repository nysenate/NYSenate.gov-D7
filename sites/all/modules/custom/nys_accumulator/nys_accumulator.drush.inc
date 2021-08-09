<?php

/**
 * @file
 * Defines drush commands for the nys_accumulator module.
 */

require_once 'inc/nys_accumulator.drush.integrity.inc';

/**
 * Implements hook_drush_command().
 *
 * @see drush_parse_command()
 */
function nys_accumulator_drush_command() {
  $commands = _integrity_check_action_types();
  $command_text = '';
  foreach ($commands as $key => $val) {
    $command_text .= "$key (" . implode(', ', $val) . ")\n";
  }
  return [
    'accumulator-integrity' => [
      'aliases' => ['acc-int'],
      'description' => "Check accumulator records against primary database records for data integrity.",
      'arguments' => [
        'type' => "The type of accumulator records to check (e.g., 'petition', 'bill', etc.)  Specifying 'all' checks every type in sequence.\n$command_text",
      ],
      'required-arguments' => TRUE,
      'options' => [
        'start-time' => 'Check records generated on or after this date (default today)',
        'end-time' => 'Check records generated on or before this date (default today)',
      ],
    ],
    'accumulator-archive' => [
      'aliases' => ['acc-arc'],
      'description' => 'Archives accumulator records based on timestamp.',
      'options' => [
        'days' => 'Select for archiving any records older than this number of days.',
      ],
    ],
  ];
}

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

  nys_utils_set_cron_lastrun('accumulator_integrity');
}

/**
 * Implements drush command accumulator-archive.
 */
function drush_nys_accumulator_accumulator_archive() {
  // Resolve the maximum age.  This may be set as a variable, or a drush option.
  $days = variable_get('nys_accumulator_archive_age');
  $days = (int) drush_get_option('days', $days);

  // If the setting is not valid, use the hard-coded default (90 days)
  if ($days < 1) {
    drush_log("Invalid setting for 'days', using default.", 'warn');
    $days = NYSACCUM_DEFAULT_ARCHIVE_AGE;
  }
  drush_log("Archiving accumulator records older than {$days} days ...", 'status');

  $insert = 0;
  if (!($transaction = db_transaction())) {
    echo "(ERROR) Could not start transaction, nothing done\n";
  }
  else {
    try {
      $cutoff = time() - ($days * 86400);
      // Step 1, copy selected records
      $q = "INSERT INTO {accumulator_archive} SELECT * FROM {accumulator} " .
        "WHERE created_at < :cutoff";
      $insert = (int) db_query($q, [':cutoff' => $cutoff])->rowCount();

      // Step 2, delete the original records
      if ($insert) {
        $delete = db_delete('accumulator')
          ->condition('created_at', $cutoff, '<')
          ->execute();

        // If copy doesn't match delete, something went wrong.
        if ($insert !== $delete) {
          throw new Exception("INSERT returned {$insert}, DELETE returned {$delete}");
        }
      }
    } catch (Throwable $e) {
      // If there are any problems, roll back the transaction.
      $transaction->rollback();
      $insert = 0;
      drush_log("Could not archive records: " . $e->getMessage(), 'error');
    }
  }
  unset($transaction);
  drush_log("(DONE) Archived {$insert} records.", 'ok');
}
