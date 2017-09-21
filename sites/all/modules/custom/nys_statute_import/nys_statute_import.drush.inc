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

    case 'drush:statutes-report':
        return dt('Run statutes-report');

    case 'drush:update-range-statutes':
      return dt('Run update-range-statutes');

    case 'drush:currently-processing-law-id':
      return dt('Run currently-processing-law-id');

    case 'drush:stop-statute-processing':
      return dt('Run stop-statute-processing');

    case 'drush:reset-statute-processing':
      return dt('Run reset-statute-processing');

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
    'aliases' => array('ias'),
  );

  $items['restart-update-all-statutes'] = array(
    'description' => dt('Restart Import All Statute Nodes.'),
    'arguments'   => array(
      'arg1'    => dt('A required lawID argument'),
    ),
    'examples' => array(
      'Standard example' => 'drush restart-update-all-statutes ABP',
    ),
    'aliases' => array('rias'),
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
      'arg1'    => dt('A lawID'),
      'arg2'    => dt('A Run Type'),
    ),
    'examples' => array(
      'Standard example' => 'process-statutes ABP IMPORT-ALL',
    ),
    'aliases' => array('ps'),
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
  // Determine if --force override is desired.
  $force = drush_get_option('force', FALSE);
  if ($force == TRUE) {
    // Delete the current law_id.
    variable_del('nys_statute_import_process_statutes');
    // Delete the stop flag.
    variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
    // Delete the batch flag.
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }

  $batch_job_in_progress = variable_get(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS, '');
  if (!empty($batch_job_in_progress)) {
    $interval_string = number_format((time() - $batch_job_in_progress) / 3600, 3);
    print "\r\nAnother Processing Has Been Running For $interval_string hours.\r\n";
    print "run drush stop-statute-processing to stop a running job.\r\n";
    print "run drush reset-statute-processing to clear the system and re run this command.\r\n\r\n\r\n";
    return 0;
  }



  if (empty($arg1) == TRUE) {
    drush_confirm('Are you sure you want to continue update-all-statutes?', $indent = 0);
  }
  elseif (strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    drush_confirm("Are you sure you want to continue update-all-statutes. \r\nFor LawID - $arg1  ?", $indent = 0);
  }
  else {
    drush_confirm("Are you sure you want to continue update-all-statutes. \r\nFor StatuteID - $arg1  ?", $indent = 0);
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  variable_set(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS, time());
  $retval = nys_statute_import_update_all_statutes($arg1);
  if ($retval == 0) {
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }
  // Log to the command line with an OK status.
  drush_log('Completed Import All Statutes.', 'ok');
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
  elseif (strpos($arg1, NYS_STATUTE_STATUTE_ID_DELIMITER) === FALSE) {
    drush_confirm("Are you sure you want to continue restart-update-all-statutes. \r\nBeginning from LawID - $arg1  ?", $indent = 0);
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  $retval = nys_statute_import_restart_update_all_statutes($arg1);
  if ($retval == 0) {
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }
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
  $batch_job_in_progress = variable_get(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS, '');
  if (!empty($batch_job_in_progress)) {
    $interval_string = number_format((time() - $batch_job_in_progress) / 3600, 3);
    print "\r\nAnother Processing Has Been Running For $interval_string hours.\r\n";
    print "run drush stop-statute-processing to stop a running job.\r\n";
    print "run drush reset-statute-processing to clear the system and re run this command.\r\n\r\n\r\n";
    return 0;
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  variable_set(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS, time());
  $retval = nys_statute_import_audit_all_statutes($arg1);
  if ($retval == 0) {
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }
  // A drush_log($retval, 'ok');.
  // Log to the command line with an OK status.
  drush_log('Completed Audit All Statutes.', 'ok');
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
  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  $retval = nys_statute_import_restart_audit_all_statutes($arg1);
  if ($retval == 0) {
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }
  // Log to the command line with an OK status.
  drush_log('Completed Restart Audit All Statutes.', 'ok');
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
    drush_confirm("Are you sure you want to continue update-range-statutes. \r\nFor Statutes that have changed since the last time update-range-statutes was run. ?", $indent = 0);
  }
  else {
    drush_confirm("Are you sure you want to continue update-range-statutes. \r\nFor Statutes that have changed $arg1. ?", $indent = 0);
  }

  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);
  variable_set(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS, time());
  $retval = nys_statute_import_update_range_statutes($arg1);
  if ($retval == 0) {
    variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);
  }
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
  drush_confirm("Are you sure you want to stop the statute processing. \r\n");

  variable_set(NYS_STATUTE_IMPORT_ALL_STOP, TRUE);
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
  drush_confirm("Are you sure you want to reset statute processing to begin a new processing job. \r\n");

  // Delete the current law_id.
  variable_del('nys_statute_import_process_statutes');

  // Delete the stop flag.
  variable_del(NYS_STATUTE_IMPORT_ALL_STOP);

  // Delete the batch flag.
  variable_del(NYS_STATUTE_IMPORT_BATCH_JOB_IN_PROGRESS);

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
