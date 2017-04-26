<?php

/**
 * @file
 * File nys_statute.drush.inc.
 */

/**
 * Implements hook_drush_help().
 */
function nys_statute_drush_help($command) {
  switch ($command) {
    case 'drush:test-statute':
      return dt('Run test-statute');
  }
}

/**
 * Implements hook_drush_command().
 */
function nys_statute_drush_command() {
  $items = array();

  $items['test-statute'] = array(
    'description' => dt('Run Test Statute.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush test-statute',
      'Argument example' => 'drush test-statute 5',
    ),
    'aliases' => array('ts'),
  );

  return $items;
}

/**
 * Callback function for drush test-statute.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1  -  An optional argument.
 */
function drush_nys_statute_test_statute($arg1 = NULL) {
  $retval = nys_statute_test_statute($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Test.', 'ok');
}
