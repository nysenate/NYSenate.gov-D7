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

    case 'drush:clear-all-law-ids':
      return dt('Run clear-all-law-ids');

    case 'drush:clear-law-id':
      return dt('Run clear-law-id');

    case 'drush:get-statute-count':
      return dt('Run get-statute-count');

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

  $items['clear-all-law-ids'] = array(
    'description' => dt('Run Delete All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush clear-all-law-ids',
    ),
    'aliases' => array('cali'),
  );

  $items['clear-law-id'] = array(
    'description' => dt('Run Delete Statutes for a suppied law ID.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush clear-law-id',
      'Argument example' => 'drush clear-law-id ABP',
    ),
    'aliases' => array('clid'),
  );

  $items['get-statute-count'] = array(
    'description' => dt('Gets the number of statutes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush get-statute-count',
      'Argument example' => 'drush get-statute-count ABP',
    ),
    'aliases' => array('gsc'),
  );





  return $items;
}

/**
 * Callback function for drush clear-all-statutes casn.
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
  $confirmed = drush_confirm('Are you sure you want to DElETE ALL THE STATUTE NODES - clear-all-statutes ?', $indent = 0);
  if (!$confirmed) {
    drush_user_abort();
  }

  $retval = nys_statute_delete_clear_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Clear All Statutes.', 'ok');
}

/**
 * Callback function for drush clear-all-law-ids cali.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_delete_clear_all_law_ids($arg1 = NULL) {
  $confirmed = drush_confirm('Are you sure you want to DElETE ALL THE STATUTE NODES - clear-all-law-ids ?', $indent = 0);
  if (!$confirmed) {
    drush_user_abort();
  }

  $retval = nys_statute_delete_clear_all_law_ids($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Clear All Statutes by Law IDS.', 'ok');
}

/**
 * Callback function for drush clear-law-id.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_delete_clear_law_id($arg1 = NULL) {
  $retval = nys_statute_delete_clear_law_id($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Clear Law Id.', 'ok');
}

/**
 * Callback function for drush get-statute-count gsc.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_delete_get_statute_count($arg1 = NULL) {
  $retval = nys_statute_delete_get_statute_count($arg1);
  //drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  //drush_log('Completed Get Statute Count.', 'ok');
}
