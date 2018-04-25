<?php

/**
 * @file
 * Defines drush commands for the nys_accumulator module.
 */

require_once 'inc/nys_accumulator.drush.commands.inc';

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
  $items = [
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
  ];

  return $items;
}
