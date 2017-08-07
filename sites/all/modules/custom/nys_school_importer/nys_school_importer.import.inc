<?php
/**
 * @file
 * File nys_school_importer.import.inc.
 */

require_once 'nys_school_importer.inc';

/**
 * Page handler for the nys-school-import page.
 */
function nys_school_importer_import_page() {
  // See if there is an upload file.
  $input_file = variable_get('nys_school_importer_csvupload', '');
  if (empty($input_file) == FALSE) {
    // If no name needs more than 4 keys proceed.
    if (nys_school_importer_get_num_max_names_index() < 5) {
      // Process the import file.
      nys_school_importer_process_import();
    }
    else {
      // Pose a form to continue with the import.
      $form = drupal_get_form('nys_school_importer_continue_form');
      $output = "<p>Some School Names are the same and adding grade_organization city and zip code was not enough to make them unique.</p>
                <p>You can go back and fix the issue in the CSV file or Continue with the import and fix the issues later.</p>
                <p>If you continue a unique name will be formed by adding a number to the school name, grade_organization city and zip code.";
      $output .= drupal_render($form);
      return $output;
    }
  }
  else {
    // File Upload Not Specified.
    drupal_set_message('No Upload File Was Specifid. Try Again.');
    drupal_goto('admin/config/system/nys-school-import');
  }

  return "<h1>Import Schools</h1>";
}

/**
 * Continue with the import form.
 */
function nys_school_importer_continue_form() {

  $form['from'] = array(
    '#type' => 'item',
    '#title' => t('Remaining Schools With Name Issues'),
    '#markup' => nys_school_importer_get_offending_school_names_markup(5),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Continue With Import'),
  );

  return $form;

}

/**
 * Continue with the import form.
 */
function nys_school_importer_continue_form_submit() {
  // Continue With The Import.
  nys_school_importer_process_import();
}

/**
 * Process and import a batch of schools.
 */
function nys_school_importer_process_import() {
  $progress = 0;
  $limit = 1;
  $batch = array(
    'operations' => array(),
    'finished' => 'nys_school_importer_process_batch_finished',
    'title' => t('Importing Schools'),
    'init_message' => t('Import is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Import has encountered an error.'),
    'file' => drupal_get_path('module', 'nys_school_importer') . '/nys_school_importer.import.inc',
  );

  $file_path = variable_get('nys_school_importer_csvupload', '');
  if (file_exists($file_path) == TRUE) {
    // Load the file and process it.
    $row = 1;
    if (($handle = fopen($file_path, "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 2000, ",")) !== FALSE) {
        if ($row == 1) {
          // This is the first `column title` row.
          $valid_columns = nys_school_importer_validate_file($data);
          if ($valid_columns == FALSE) {
            print "The Columns in the Import File csv do not match the schema. \r\n";
            fclose($handle);
            return;
          }
        }
        else {
          // Ths is a regular data row.
          $batch['operations'][] = array('nys_school_importer_import_line',
                                         array($progress, $limit, $data),
          );

        }
        $row++;
      }
      fclose($handle);
    }
  }

  batch_set($batch);
  batch_process('/admin/nys-school-report');
}

/**
 * This is what runs multiple times per batch.
 */
function nys_school_importer_import_line($progress, $limit, $line, &$context) {
  // Get the Key columns.
  $raw_legal_name = $line[nys_school_importer_get_column_number('LEGAL NAME') - 1];
  // Since the masaged name is what is in the node.
  // The lookup needs to be for a massaged name.
  // Because (THE) is at the end of the name in the $raw_legal_name sometimes.
  $legal_name = nys_school_importer_cleanup_name($raw_legal_name);
  $grade_organization = $line[nys_school_importer_get_column_number('GRADE ORGANIZATION DESCRIPTION') - 1];
  $city = $line[nys_school_importer_get_column_number('CITY') - 1];
  $zip = $line[nys_school_importer_get_column_number('ZIP') - 1];

  // See if the School exists already.
  $node = nys_school_importer_load_school_node($legal_name, $grade_organization, $city, $zip);

  if ($node !== FALSE) {
    // An existing school node was found.
    if (nys_school_importer_compare_school_node($node, $line) == FALSE) {
      // Reset the values in the node and save.
      nys_school_importer_update_school_node($node, $line);
    }
  }
  else {
    // An existing school node was NOT found.
    // Create new school node.
    $node = nys_school_importer_create_school_node($line);

    // Set the values in the node and save.
    nys_school_importer_update_school_node($node, $line);
  }

}

/**
 * Batch is finished proc.
 */
function nys_school_importer_process_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message('The School Import is Complete');
    // Dont  variable_set('nys_school_importer_csvupload', '');.
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
 * Returns list of School Names that can not be made unique with 4 added keys.
 */
function nys_school_importer_get_offending_school_names_markup($num_keys) {
  // Get schools where `num_keys` equal or greater than $num_keys.
  $result = db_query('SELECT `legal_name` FROM `nys_school_names_index` WHERE num_keys >= :num_keys', array(':num_keys' => $num_keys));
  $markup = '<ul id="offending-school-names">';
  foreach ($result as $record) {
    $markup = $markup . '<li>';
    $markup = $markup . $record->legal_name;
    $markup = $markup . '</li>';
  }

  $markup = $markup . '</ul>';
  return $markup;
}
