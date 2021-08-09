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

    case 'drush:update-all-statutes':
      return dt('Run update-all-statutes');

    case 'drush:restart-update-all-statutes':
      return dt('Run restart-update-all-statutes');

    case 'drush:audit-all-statutes':
      return dt('Run audit-all-statutes');

    case 'drush:restart-audit-all-statutes':
      return dt('Run restart-audit-all-statutes');

    case 'drush:audit-report':
      return dt('Run audit-report');

    case 'drush:statutes-report':
      return dt('Run statutes-report');

    case 'drush:update-range-statutes':
      return dt('Run update-range-statutes');

    case 'drush:structure-clear-range-statutes':
      return dt('Run structure-clear-range-statutes');

    case 'drush:structure-update-range-statutes':
      return dt('Run structure-update-range-statutes');

    case 'drush:repeal-range-statutes':
      return dt('Run repeal-range-statutes');

    case 'drush:currently-processing-law-id':
      return dt('Run currently-processing-law-id');

    case 'drush:stop-statute-processing':
      return dt('Run stop-statute-processing');

    case 'drush:reset-statute-processing':
      return dt('Run reset-statute-processing');

    case 'drush:status-all-statutes':
      return dt('Run status-all-statutes');

  }
}

/**
 * Implements hook_drush_command().
 */
function nys_statute_import_drush_command() {
  $items = array();

  $items['update-all-statutes'] = array(
    'description' => dt('Run Import All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional lawID or lawID-locationID argument'),
    ),
    'options' => array(
      'force' => 'Empty and Clear.',
    ),
    'examples' => array(
      'Standard example' => 'drush update-all-statutes',
      'lawID example' => 'drush update-all-statutes ABP',
      'lawID-locationID example' => 'drush update-all-statutes ABP-215',
    ),
    'aliases' => array('uas'),
  );

  $items['restart-update-all-statutes'] = array(
    'description' => dt('Restart Import All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('A required lawID argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush restart-update-all-statutes ABP',
    ),
    'aliases' => array('ruas'),
  );

  $items['audit-all-statutes'] = array(
    'description' => dt('Run Audit All Statutes.'),
    'arguments'   => array(
      'arg1'    => dt('An optional argument'),
    ),
    'options' => array(
      'force' => 'Empty and Clear.',
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

  $items['audit-report'] = array(
    'description' => dt('Various Reports on runs.'),
    'arguments'   => array(
      'arg1'    => dt('An optional report number'),
    ),
    'examples' => array(
      'Standard example' => 'drush audit-report',
      'lawID example' => 'drush audit-report 3',
    ),
    'aliases' => array('arp'),
  );

  $items['statutes-report'] = array(
    'description' => dt('Statutes Report.'),
    'arguments'   => array(
      'arg1'    => dt('An optional lawID argument for single law_id'),
    ),
    'examples' => array(
      'Standard example' => 'drush statutes-report',
      'lawID example' => 'drush statutes-report ABP',
    ),
    'aliases' => array('srp'),
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
    'aliases' => array('urs'),
  );

  $items['structure-clear-range-statutes'] = array(
    'description' => dt('Run structure update range statutes to delete changed law trees of statutes.'),
    'arguments'   => array(
      'from_date_time'    => dt('An optional argument to specify the fromDateTime Use the ISO time format and include slashes.'),
      'to_date_time'    => dt('An optional argument to specify the toDateTime. Use the ISO time format and include slashes.'),
    ),
    'options' => array(
      'dry' => 'Do Not Delete, Just List Them.',
    ),
    'examples' => array(
      'Standard example' => 'drush structure-clear-range-statutes',
      'lawID, fromDateTime & toDateTime example' => 'drush structure-clear-range-statutes 2015-01-01T00:00:00 2016-01-01T00:00:00',
    ),
    'aliases' => array('scrs'),
  );

  $items['structure-update-range-statutes'] = array(
    'description' => dt('Run structure update range statutes to delete changed law trees of statutes.'),
    'aliases' => array('surs'),
  );

  $items['repeal-range-statutes'] = array(
    'description' => dt('Run Repeal range Statutes to delete repealed statutes.'),
    'arguments'   => array(
      'from_date_time'    => dt('An optional argument to specify the fromDateTime Use the ISO time format and include slashes.'),
      'to_date_time'    => dt('An optional argument to specify the toDateTime. Use the ISO time format and include slashes.'),
    ),
    'options' => array(
      'dry' => 'Do Not Delete, Just List Them.',
    ),
    'examples' => array(
      'Standard example' => 'drush repeal-range-statutes',
      'lawID, fromDateTime & toDateTime example' => 'drush repeal-range-statutes /ABP/2015-01-01T00:00:00/2016-01-01T00:00:00/',
    ),
    'aliases' => array('rrs'),
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

  $items['stop-statute-processing'] = array(
    'description' => dt('Run Clear All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('No optional arguments'),
    ),
    'examples' => array(
      'Standard example' => 'drush stop-statute-processing',
    ),
    'aliases' => array('ssp'),
  );

  $items['reset-statute-processing'] = array(
    'description' => dt('Run Clear All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('No optional arguments'),
    ),
    'examples' => array(
      'Standard example' => 'drush reset-statute-processing',
    ),
    'aliases' => array('rsp'),
  );

  $items['process-statutes'] = array(
    'description' => dt('Processes the statutes for a LawID. Used Internally'),
    'arguments'   => array(
      'law_id'    => dt('A lawID'),
      'run_type'    => dt('A Run Type'),
    ),
    'examples' => array(
      'Standard example' => 'process-statutes ABP IMPORT-ALL',
    ),
    'aliases' => array('ps'),
  );

  $items['status-all-statutes'] = array(
    'description' => dt('Gets the status of the current or last run.'),
    'examples' => array(
      'Standard example' => 'status-all-statutes',
    ),
    'aliases' => array('sas'),
  );

  return $items;
}

/**
 * Callback function for drush update-all-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1.
 *   An optional argument
 */
function drush_nys_statute_import_update_all_statutes($arg1 = NULL) {
  // Get the freshness of the log.
  $age_of_data = nys_statute_import_log_freshness();

  // Is an old job running right now.
  if ($age_of_data >= 0 && $age_of_data < 30) {
    print "\r\nIt looks like there is another job running right now.\r\n";
    print "\r\nThe Last Data was added $age_of_data seconds ago.\r\n";
    print "run drush stop-statute-processing to stop a running job and pause it.\r\n";
    print "run drush reset-statute-processing to clear the system and re run this command.\r\n\r\n\r\n";
    return 0;
  }

  // Determine if --force override is desired.
  $force = drush_get_option('force', FALSE);
  if ($force == TRUE) {
    // Delete the stop flag.
    variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  }

  // Was the processing incomplete. or Was a stop issued.
  $all_stop = variable_get(NYS_STATUTE_IMPORT_ALL_STOP);
  if ((!nys_statute_import_processing_run_completed() || $all_stop == TRUE) && nys_statute_import_get_qty_law_ids_processed() > 6) {
    $last_law_id_processed = nys_statute_import_get_last_law_id_processed();

    print "\r\nIt looks like there is a paused job.\r\n";
    print "\r\nIt was paused while procesing $last_law_id_processed.\r\n";
    print "run drush restart-update-all-statutes to restart the paused job and starting with law id $last_law_id_processed.\r\n";
    print "or run drush reset-statute-processing to clear the system and re run this command.\r\n\r\n\r\n";
    return 0;
  }

  if (empty($arg1) == TRUE) {
    $confirmed = drush_confirm('Are you sure you want to continue update-all-statutes?', $indent = 0);
  }
  elseif (strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    $confirmed = drush_confirm("Are you sure you want to continue update-all-statutes. \r\nFor LawID - $arg1  ?", $indent = 0);
  }
  else {
    $confirmed = drush_confirm("Are you sure you want to continue update-all-statutes. \r\nFor StatuteID - $arg1  ?", $indent = 0);
  }

  if (!$confirmed) {
    drush_user_abort();
    return;
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  $retval = nys_statute_import_update_all_statutes($arg1);

  // Log to the command line with an OK status.
  drush_log('Completed Import All Statutes.', 'ok');
  print "No Errors During Run.\r\n";

  nys_utils_set_cron_lastrun('update_all_statutes');

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
    $last_law_id_processed = nys_statute_import_get_last_law_id_processed();
    $confirmed = drush_confirm("Are you sure you want to continue restart-update-all-statutes. \r\nBeginning from LawID $last_law_id_processed", $indent = 0);
  }
  elseif (strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    $confirmed = drush_confirm("Are you sure you want to continue restart-update-all-statutes. \r\nBeginning from LawID - $arg1  ?", $indent = 0);
  }

  if (!$confirmed) {
    drush_user_abort();
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  $retval = nys_statute_import_restart_update_all_statutes($arg1);

  // Log to the command line with an OK status.
  drush_log('Completed Restart Import All Statutes.', 'ok');
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
  // Get the freshness of the log.
  $age_of_data = nys_statute_import_log_freshness();

  // Is an old job running right now.
  if ($age_of_data >= 0 && $age_of_data < 30) {
    print "\r\nIt looks like there is another job running right now.\r\n";
    print "\r\nThe Last Data was added $age_of_data seconds ago.\r\n";
    print "run drush stop-statute-processing to stop a running job and pause it.\r\n";
    print "run drush reset-statute-processing to clear the system and re run this command.\r\n\r\n\r\n";
    return 0;
  }

  // Determine if --force override is desired.
  $force = drush_get_option('force', FALSE);
  if ($force == TRUE) {
    // Delete the stop flag.
    variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  }

  // Was the processing incomplete. or Was a stop issued.
  $all_stop = variable_get(NYS_STATUTE_IMPORT_ALL_STOP);
  if ((!nys_statute_import_processing_run_completed() || $all_stop == TRUE) && nys_statute_import_get_qty_law_ids_processed() > 6) {
    $last_law_id_processed = nys_statute_import_get_last_law_id_processed();

    print "\r\nIt looks like there is a paused job.\r\n";
    print "\r\nIt was paused while procesing $last_law_id_processed.\r\n";
    print "run drush restart-update-all-statutes to restart the paused job and starting with law id $last_law_id_processed.\r\n";
    print "or run drush reset-statute-processing to clear the system and re run this command.\r\n\r\n\r\n";
    return 0;
  }

  if (drush_confirm('Are you sure you run audit-all-statutes ?')) {

    variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
    $retval = nys_statute_import_audit_all_statutes($arg1);
  }
  else {
    drush_user_abort();
  }
  // A drush_log($retval, 'ok');.
  // Log to the command line with an OK status.
  drush_log('Completed Audit All Statutes.', 'ok');
  print "No Errors During Run.\r\n";
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
  if (empty($arg1) == TRUE) {
    $last_law_id_processed = nys_statute_import_get_last_law_id_processed();
    $confirmed = drush_confirm("Are you sure you want to continue restart-audit-all-statutes. \r\nBeginning from LawID $last_law_id_processed", $indent = 0);
  }
  elseif (strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    $confirmed = drush_confirm("Are you sure you want to continue restart-audit-all-statutes. \r\nBeginning from LawID - $arg1  ?", $indent = 0);
  }

  if (!$confirmed) {
    drush_user_abort();
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  $retval = nys_statute_import_restart_audit_all_statutes($arg1);
  if ($retval == 0) {
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }
  // Log to the command line with an OK status.
  drush_log('Completed Restart Audit All Statutes.', 'ok');
}

/**
 * Callback function for drush audit-report arp.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_audit_report($arg1 = NULL) {
  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  $retval = nys_statute_import_run_audit_report($arg1);
  if ($retval == 0) {
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }
  // Log to the command line with an OK status.
  drush_log('Completed Audit Report.', 'ok');
}

/**
 * Callback function for drush statutes-report srp.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument - the law_id to display
 */
function drush_nys_statute_import_statutes_report($arg1 = NULL) {

  if (empty($arg1)) {
    nys_statute_run_import_audit_statutes();
  }
  else {
    nys_statute_run_import_audit_statute($arg1);
  }

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
    $confirmed = drush_confirm("Are you sure you want to continue update-range-statutes. \r\nFor Statutes that have changed since the last time update-range-statutes was run. ?", $indent = 0);
  }
  else {
    $confirmed = drush_confirm("Are you sure you want to continue update-range-statutes. \r\nFor Statutes that have changed $arg1. ?", $indent = 0);
  }

  if (!$confirmed) {
    drush_user_abort();
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  $retval = nys_statute_import_update_range_statutes($arg1);
  // Log to the command line with an OK status.
  drush_log('Completed Update Range Statutes.', 'ok');
}

/**
 * Callback function for drush structure-clear-range-statutes scrs.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_structure_clear_range_statutes($from_date_time = '', $to_date_time = '') {
  if (empty($from_date_time) && empty($to_date_time)) {
    $last_run = variable_get(NYS_STATUTE_IMPORT_LAST_STRUCTURAL_TIMETAMP, "2000-01-01T00:00:00");
    $confirmed = drush_confirm("Are you sure you want to continue structure-clear-range-statutes. \r\n
      For Statutes that have changed since the last time structure-clear-range-statutes was run $last_run. \r\n
      Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }
  elseif (!empty($from_date_time) && empty($to_date_time)) {
    $confirmed = drush_confirm("Are you sure you want to continue structure-clear-range-statutes. \r\n
    For Statutes that have changed since $from_date_time. \r\n
    Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }
  elseif (!empty($from_date_time) && !empty($to_date_time)) {
    $confirmed = drush_confirm("Are you sure you want to continue structure-clear-range-statutes. \r\n
      For Statutes that have changed between $from_date_time and $to_date_time. \r\n
      Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }

  if (!$confirmed) {
    drush_user_abort();
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);

  $retval = nys_statute_import_structure_clear_range_statutes($from_date_time, $to_date_time);

  // Log to the command line with an OK status.
  drush_log('Completed Clear Range Statutes.', 'ok');

  nys_utils_set_cron_lastrun('structure_clear_range_statutes');
}

/**
 * Callback function for drush structure-update-range-statutes surs.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_structure_update_range_statutes() {
  if (empty($from_date_time) && empty($to_date_time)) {
    $last_run = variable_get(NYS_STATUTE_IMPORT_LAST_STRUCTURAL_TIMETAMP, "2000-01-01T00:00:00");
    $confirmed = drush_confirm("Are you sure you want to continue structure-update-range-statutes. \r\n
      For Statutes that have changed since the last time structure-update-range-statutes was run $last_run. \r\n
      Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }
  elseif (!empty($from_date_time) && empty($to_date_time)) {
    $confirmed = drush_confirm("Are you sure you want to continue structure-update-range-statutes. \r\n
    For Statutes that have changed since $from_date_time. \r\n
    Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }
  elseif (!empty($from_date_time) && !empty($to_date_time)) {
    $confirmed = drush_confirm("Are you sure you want to continue structure-update-range-statutes. \r\n
      For Statutes that have changed between $from_date_time and $to_date_time. \r\n
      Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }

  if (!$confirmed) {
    drush_user_abort();
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);

  $retval = nys_statute_import_structure_update_range_statutes($from_date_time, $to_date_time);

  // Log to the command line with an OK status.
  drush_log('Completed Update Range Statutes.', 'ok');
}

/**
 * Callback function for drush repeal-range-statutes.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_repeal_range_statutes($from_date_time = '', $to_date_time = '') {
  if (empty($from_date_time) && empty($to_date_time)) {
    $last_run = variable_get(NYS_STATUTE_IMPORT_LAST_REPEAL_TIMETAMP, "2000-01-01T00:00:00");
    $confirmed = drush_confirm("Are you sure you want to continue repeal-range-statutes. \r\n
      For Statutes that have changed since the last time update-range-statutes was run $last_run. \r\n
      Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }
  elseif (!empty($from_date_time) && empty($to_date_time)) {
    $confirmed = drush_confirm("Are you sure you want to continue repeal-range-statutes. \r\n
    For Statutes that have changed since $from_date_time. \r\n
    Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }
  elseif (!empty($from_date_time) && !empty($to_date_time)) {
    $confirmed = drush_confirm("Are you sure you want to continue repeal-range-statutes. \r\n
      For Statutes that have changed between $from_date_time and $to_date_time. \r\n
      Use the --dry option to display a list of node ids instead of actually deleting the statute nodes. ?", $indent = 0);
  }

  if (!$confirmed) {
    drush_user_abort();
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);

  $retval = nys_statute_import_repeal_range_statutes($from_date_time, $to_date_time);

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

/**
 * Callback function for drush stop-statute-processing ssp.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_stop_statute_processing($arg1 = NULL) {
  if (drush_confirm("Are you sure you want to stop the statute processing. \r\n")) {
    variable_set(NYS_STATUTE_IMPORT_ALL_STOP, TRUE);
  }
  else {
    drush_user_abort();
  }
  drush_log("Stop Directive Issued.", 'ok');
}

/**
 * Callback function for drush reset-statute-processing rsp.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1
 *   An optional argument
 */
function drush_nys_statute_import_reset_statute_processing($arg1 = NULL) {
  if (drush_confirm("Are you sure you want to reset statute processing to begin a new processing job. \r\n")) {
    nys_statute_import_reset_statute_processing();
  }
  else {
    drush_user_abort();
  }

  print "Statute Processing Reset\r\n";

}

/**
 * Callback function for drush process-statutes.
 *
 * This also  calls the nys_statute_import_import_all_statutes() function.
 * It's automated use and not for humans there are no checks of
 * the arguments, warnings or user interaction required.
 * This handles the processing for import-all-statutes
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1.
 *   An optional argument
 */
function drush_nys_statute_import_process_statutes($law_id, $run_type) {

  $retval = nys_statute_import_run_process_statutes($law_id, $run_type);

  // Log to the command line with an OK status. Keeps returning error.
  print "Completed Process Statutes for $law_id - $run_type.\r\n\r\n";
}

/**
 * Callback function for drush status-all-statutes sas.
 *
 * This also  calls the nys_statute_import_import_all_statutes() function.
 * It's automated use and not for humans there are no checks of
 * the arguments, warnings or user interaction required.
 * This handles the processing for import-all-statutes
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters
 * converted to "_" characters (my_command).
 *
 * $arg1.
 *   An optional argument
 */
function drush_nys_statute_import_status_all_statutes($arg1) {

  $retval = nys_statute_import_get_status_all_statutes($arg1);

  // Log to the command line with an OK status. Keeps returning error.
  print "Completed Status.\r\n\r\n";
}
