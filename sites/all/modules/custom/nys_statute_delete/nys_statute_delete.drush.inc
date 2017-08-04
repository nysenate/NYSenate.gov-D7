<?php

/**
 * @file
 * File nys_statute_delete.drush.inc.
 */

/**
 * Implements hook_drush_help().
 */
function nys_statute_delete_drush_help($command) {
  switch ($command) {
    case 'drush:clear-all-statutes':
      return dt('Run clear-all-statutes');

  }
}

/**
 * Implements hook_drush_command().
 */
function nys_statute_delete_drush_command() {
  $items = array();

  $items['clear-all-statutes'] = array(
    'description' => dt('Run Delete All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush clear-all-statutes',
      'Argument example' => 'drush clear-all-statutes 5',
    ),
    'aliases' => array('casn'),
  );

  return $items;
}

/**
 * Callback function for drush clear-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_delete_clear_all_statutes($arg1 = NULL) {
  drush_confirm('Are you sure you want to DElETE ALL THE STATUTE NODES - clear-all-statutes ?', $indent = 0);
  $retval = nys_statute_delete_clear_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Clear All Statutes.', 'ok');
}
