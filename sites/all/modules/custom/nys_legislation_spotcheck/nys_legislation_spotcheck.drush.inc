<?php

require_once 'nys_legislation_spotcheck.inc';

/**
 * Implements hook_drush_command().
 */
function nys_legislation_spotcheck_drush_command() {
  $items = [];

  $items['spotcheck-dump'] = [
    'description' => dt('Dump a session of legislative data to OpenLegislation, triggering a Spotcheck report to be run'),
    'arguments' => [
      'arg1' => dt('A required content type that will be dumped (' . SpotcheckContentType::getTypesStr() . ')'),
    ],
    'options' => [
      'session' => dt('An optional session year indicating the session to be dumped (defaults to the current session.)'),
    ],
  ];

  return $items;
}

// Callback functions.

/**
 * Callback function for drush spotcheck-dump
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters converted to "_" characters
 * (my_command)
 *
 * @param $arg1
 */
function drush_nys_legislation_spotcheck_spotcheck_dump($arg1) {
  $content_type = SpotcheckContentType::getSpotcheckContentType($arg1);
  if (!$content_type) {
    drush_log("Invalid content type $arg1.  Try (" . SpotcheckContentType::getTypesStr() . ')', 'failed');
    return;
  }
  $session = drush_get_option('session', nys_legislation_spotcheck_get_session_year(date('Y')));
  if (!is_numeric($session)) {
    drush_log("'session' parameter must be a numeric value.  Got '$session'", 'failed');
    return;
  }
  if ($session % 2 === 0) {
    drush_log("Invalid session year: $session .  Session years are odd", 'warning');
    $session = nys_legislation_spotcheck_get_session_year($session);
    drush_log("Using adjusted session year: $session", 'warning');
  }
  nys_legislation_spotcheck_handle_spotcheck_dump($content_type, $session);
  drush_log('success', 'ok');
}

