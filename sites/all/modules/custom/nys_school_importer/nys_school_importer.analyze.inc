<?php
/**
 * @file
 * File nyc_statute_import.module.
 */

require_once 'nys_school_importer.inc';

/**
 * Analyzes all the school names in the nys_school_names table.
 */
function nys_school_importer_analyze_page() {
  // Seup the batch.
  $batch = array(
    'operations' => array(),
    'finished' => 'nys_school_importer_analyze_batch_finished',
    'title' => t('Analyzing School Names'),
    'init_message' => t('Import is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Import has encountered an error.'),
    'file' => drupal_get_path('module', 'nys_school_importer') . '/nys_school_importer.analyze.inc',
  );

  // Clear out the nys_school_names_index table.
  nys_school_importer_clear_nys_school_names_index();
  $progress = 0;
  // How many to process for each run.
  $limit = 1;

  // Iterate thru all the rows in the nys_school_names table.
  $result = db_query('SELECT * FROM `nys_school_names` WHERE 1');
  foreach ($result as $record) {
    $batch['operations'][] = array('nys_school_importer_analyze_process',
                             array($progress, $limit, $record),
    );
    $progress = $progress + 1;
  }

  batch_set($batch);
  batch_process('admin/nys-school-import');
}

/**
 * This is what runs multiple times per batch.
 */
function nys_school_importer_analyze_process($progress, $limit, $record, &$context) {
  // Calculate the index.
  nys_school_importer_calculate_name_index($record);
}

/**
 * Analyze batch finished.
 */
function nys_school_importer_analyze_batch_finished($success, $results, $operations) {
  // If run was successful.
  if ($success) {
    // Perform final adjustments and override number of keys needed for a name.
    nys_school_importer_analyze_exceptions();
    drupal_set_message('Import is complete');
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    ));
    drupal_set_message($message, 'error');
  }
}

/**
 * Override and fix problems.
 */
function nys_school_importer_analyze_exceptions() {
  // Get the path for the exceptions file and perform.
  $exception_file_path = drupal_get_path('module', 'nys_school_importer') . '/nys_school_importer_exceptions.json';
  $exception_list = json_decode(file_get_contents($exception_file_path));

  if ($exception_list !== NULL && $exception_list !== FALSE && is_array($exception_list) && count($exception_list) > 0) {
    foreach ($exception_list as $exception) {
      $legal_name = $exception->legal_name;
      $num_keys = $exception->num_keys;
      nys_school_importer_create_school_name_index($legal_name, $num_keys);
    }
  }
}
