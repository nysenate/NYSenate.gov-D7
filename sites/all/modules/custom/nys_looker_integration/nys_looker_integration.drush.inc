<?php

/**
 * @file
 * Drush integration functions for the nys_looker_integration module.
 */

/**
 * Implements hook_drush_command().
 */
function nys_looker_integration_drush_command() {
  $items = [
    "looker-reset-perms" => [
      "description" => 'Ensure the Looker integration permissions are added to the appropriate roles.',
    ],
  ];

  return $items;
}

/**
 * Callback for 'looker-reset-perms' command.
 */
function drush_nys_looker_integration_looker_reset_perms() {
  _nys_looker_integration_set_looker_permissions();
  drush_log("Looker integration permissions have been set.", 'ok');
}
