<?php

/**
 * @file
 * File nyc_statute_import.drush.inc.
 */

/**
 * Implements hook_drush_help().
 */
function nys_statute_import_drush_help($command) {
  switch ($command) {

    case 'drush:import-all-statutes':
      return dt('Run import-all-statutes');

    case 'drush:restart-import-all-statutes':
      return dt('Run restart-import-all-statutes');

    case 'drush:describe-import-all-statutes':
      return dt('Run describe-import-all-statutes');

    case 'drush:update-all-statutes':
      return dt('Run update-all-statutes');

    case 'drush:restart-update-all-statutes':
      return dt('Run restart-update-all-statutes');

    case 'drush:describe-update-all-statutes':
      return dt('Run describe-update-all-statutes');

    case 'drush:audit-all-statutes':
      return dt('Run audit-all-statutes');

    case 'drush:restart-audit-all-statutes':
      return dt('Run restart-audit-all-statutes');

    case 'drush:describe-audit-all-statutes':
      return dt('Run describe-audit-all-statutes');

    case 'drush:update-range-statutes':
      return dt('Run update-range-statutes');

    case 'drush:currently-processing-law-id':
      return dt('Run currently-processing-law-id');

  }
}

/**
 * Implements hook_drush_command().
 */
function nys_statute_import_drush_command() {
  $items = array();

  $items['import-all-statutes'] = array(
    'description' => dt('Run Import All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional lawID or lawID-locationID argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush import-all-statutes',
      'lawID example' => 'drush import-all-statutes ABP',
      'lawID-locationID example' => 'drush import-all-statutes ABP-215',
    ),
    'aliases' => array('ias'),
  );

  $items['restart-import-all-statutes'] = array(
    'description' => dt('Restart Import All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('A required lawID argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush restart-import-all-statutes ABP',
    ),
    'aliases' => array('rias'),
  );

  $items['describe-import-all-statutes'] = array(
    'description' => dt('Prints Import All Statute Nodes individual drush commands.'),
    'arguments'   => array(
      'arg1'    => dt('An optional lawID argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush describe-import-all-statutes',
      'lawID example' => 'drush describe-import-all-statutes ABP',
    ),
    'aliases' => array('dias'),
  );

  $items['update-all-statutes'] = array(
    'description' => dt('Run Update All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush update-all-statutes',
      'lawID example' => 'drush update-all-statutes ABP',
      'lawID-locationID example' => 'drush update-all-statutes ABP-215',
    ),
    'aliases' => array('uas'),
  );

  $items['restart-update-all-statutes'] = array(
    'description' => dt('Restart Update All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('A required lawID Starting Point argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush restart-update-all-statutes ABP',
    ),
    'aliases' => array('ruas'),
  );

  $items['describe-update-all-statutes'] = array(
    'description' => dt('Prints Update All Statute Nodes individual drush commands.'),
    'arguments'   => array(
      'arg1'    => dt('An optional lawID Starting Point argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush describe-update-all-statutes',
      'lawID example' => 'drush describe-update-all-statutes ABP',
    ),
    'aliases' => array('duas'),
  );

  $items['audit-all-statutes'] = array(
    'description' => dt('Run Audit All Statutes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush audit-all-statutes',
      'lawID example' => 'drush audit-all-statutes ABP',
      'lawID-locationID example' => 'drush audit-all-statutes ABP-215',
    ),
    'aliases' => array('aas'),
  );

  $items['restart-audit-all-statutes'] = array(
    'description' => dt('Restart Audit All Statutes.'),
    'arguments'   => array(
      'arg1'    => dt('A required lawID Starting Point argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush audit-all-statutes',
      'lawID example' => 'drush audit-all-statutes ABP',
      'lawID-locationID example' => 'drush audit-all-statutes ABP-215',
    ),
    'aliases' => array('raas'),
  );

  $items['describe-audit-all-statutes'] = array(
    'description' => dt('Prints Audit All Statute Nodes individual drush commands.'),
    'arguments'   => array(
      'arg1'    => dt('An optional lawID Starting Point argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush audit-all-statutes',
      'lawID example' => 'drush audit-all-statutes ABP',
      'lawID-locationID example' => 'drush audit-all-statutes ABP-215',
    ),
    'aliases' => array('daas'),
  );

  $items['update-range-statutes'] = array(
    'description' => dt('Run Update range Statutes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument to specify the lawID, fromDateTime & toDateTime. Use the ISO time format and include slashes.'),
    ),
    'examples' => array(
      'Standard example' => 'drush update-range-statutes',
      'lawID, fromDateTime & toDateTime example' => 'drush update-range-statutes /ABP/2015-01-01T00:00:00/2016-01-01T00:00:00/',
    ),
    'aliases' => array('uns'),
  );

  $items['currently-processing-law-id'] = array(
    'description' => dt('Run Clear All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('No optional arguments'),
    ),
    'examples' => array(
      'Standard example' => 'drush currently-processing-law-id',
    ),
    'aliases' => array('cpli'),
  );

  return $items;
}

/**
 * Callback function for drush import-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1.
 *   An optional argument
 */
function drush_nys_statute_import_import_all_statutes($arg1 = NULL) {
  if (empty($arg1) == TRUE) {
    drush_confirm('Are you sure you want to continue import-all-statutes?', $indent = 0);
  }
  elseif(strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    drush_confirm("Are you sure you want to continue import-all-statutes. \r\nFor LawID - $arg1  ?", $indent = 0);
  }
  else {
    drush_confirm("Are you sure you want to continue import-all-statutes. \r\nFor StatuteID - $arg1  ?", $indent = 0);
  }
  $retval = nys_statute_import_import_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Import All Statutes.', 'ok');
}

/**
 * Callback function for drush restart-import-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_restart_import_all_statutes($arg1 = NULL) {
  if (empty($arg1) == TRUE) {
    drush_confirm("Are you sure you want to continue restart-import-all-statutes. \r\nBeginning from the last complete LawID ?", $indent = 0);
  }
  elseif(strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    drush_confirm("Are you sure you want to continue restart-import-all-statutes. \r\nBeginning from LawID - $arg1  ?", $indent = 0);
  }

  $retval = nys_statute_import_restart_import_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Restart Import All Statutes.', 'ok');
}

/**
 * Callback function for drush describe-import-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_describe_import_all_statutes($arg1 = NULL) {
  // A drush_confirm('Are you sure you want to continue?', $indent = 0);.
  $retval = nys_statute_import_describe_import_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  // A drush_log('Completed Describe Import All Statutes.', 'ok');.
}

/**
 * Callback function for drush update-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_update_all_statutes($arg1 = NULL) {
  if (empty($arg1) == TRUE) {
    drush_confirm('Are you sure you want to continue update-all-statutes ?', $indent = 0);
  }
  elseif(strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    drush_confirm("Are you sure you want to continue update-all-statutes \r\nFor LawID - $arg1  ?", $indent = 0);
  }
  else {
    drush_confirm("Are you sure you want to continue update-all-statutes \r\nFor StatuteID - $arg1  ?", $indent = 0);
  }

  $retval = nys_statute_import_update_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Update All Statutes.', 'ok');
}

/**
 * Callback function for drush restart-update-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_restart_update_all_statutes($arg1 = NULL) {
  if (empty($arg1) == TRUE) {
    drush_confirm("Are you sure you want to continue restart-update-all-statutes. \r\nBeginning from the last complete LawID ?", $indent = 0);
  }
  elseif(strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    drush_confirm("Are you sure you want to continue restart-update-all-statutes ? \r\nBeginning from LawID - $arg1  ?", $indent = 0);
  }

  $retval = nys_statute_import_restart_update_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Restart Update All Statutes.', 'ok');
}

/**
 * Callback function for drush describe-update-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_describe_update_all_statutes($arg1 = NULL) {
  // A drush_confirm('Are you sure you want to continue?', $indent = 0);.
  $retval = nys_statute_import_describe_update_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status
  // A drush_log('Completed Describe Update All Statutes.', 'ok');.
}

/**
 * Callback function for drush audit-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_audit_all_statutes($arg1 = NULL) {
  $retval = nys_statute_import_audit_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status
  // A drush_log('Completed Audit All Statutes.', 'ok');.
}

/**
 * Callback function for drush restart-audit-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_restart_audit_all_statutes($arg1 = NULL) {
  $retval = nys_statute_import_restart_audit_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status
  // A drush_log('Completed Restart Audit All Statutes.', 'ok');.
}

/**
 * Callback function for drush describe-audit-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_describe_audit_all_statutes($arg1 = NULL) {
  $retval = nys_statute_import_audit_describe_all_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status
  // A drush_log('Completed Describe Audit All Statutes.', 'ok');.
}

/**
 * Callback function for drush update-range-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_update_range_statutes($arg1 = NULL) {
  if (empty($arg1) == TRUE) {
    drush_confirm("Are you sure you want to continue update-range-statutes. \r\nFor Statutes that have changed since the last time update-range-statutes was run. ?", $indent = 0);
  }
  else {
      drush_confirm("Are you sure you want to continue update-range-statutes. \r\nFor Statutes that have changed $arg1. ?", $indent = 0);
  }

  $retval = nys_statute_import_update_range_statutes($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  drush_log('Completed Update Range Statutes.', 'ok');
}

/**
 * Callback function for drush currently-processing-law-id.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_currently_processing_law_id($arg1 = NULL) {
  $retval = nys_statute_import_currently_processing_law_id($arg1);
  drush_log($retval, 'ok');

  // Log to the command line with an OK status.
  // A drush_log('Completed Currently Processing Law.', 'ok');.
}