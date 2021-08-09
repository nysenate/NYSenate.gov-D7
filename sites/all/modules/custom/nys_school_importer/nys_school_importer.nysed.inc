<?php
/**
 * @file
 * File nys_school_importer.survey.inc.
 */

require_once 'nys_school_importer.inc';

/**
 * Survey page handler.
 */
function nys_school_importer_nysed_page() {
  // Pose file upload form.
  $form = drupal_get_form('nys_school_nysed_importer_form');

  $output = "<p>This tool will import CSV nysed data.</p>";
  $output .= drupal_render($form);

  return $output;

}

/**
 * Main Form To Upload File. nys_school_importer_get_nysed_data_count().
 */
function nys_school_nysed_importer_form() {
  // Upload form.
  $form['#attributes'] = array(
    'enctype' => 'multipart/form-data',
  );

  $form['html_markup'] = array(
    '#markup' => '<p>You can merge multiple NYSED data files by repeatedly uploading csv files. </p>
                  <p>You can get a NYSED csv data export at this link <a href="https://portal.nysed.gov/discoverer/app/export?event=startExport">https://portal.nysed.gov/discoverer/app/export?event=startExport</a></p>',
  );

  $form['html_markup_2'] = array(
    '#markup' => '<h3>There are currently ' . nys_school_importer_get_nysed_data_count() . ' NYSED institutions.</h3>',
  );

  $form['csvfile'] = array(
    '#title' => t('CSV File'),
    '#type'  => 'file',
    '#description' => ($max_size = parse_size(ini_get('upload_max_filesize'))) ? t('Due to server restrictions, the <strong>maximum upload file size is !max_size</strong>. Files that exceed this size will be disregarded.', array('!max_size' => format_size($max_size))) : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Commence Import'),
    '#submit' => array('nys_school_nysed_importer_form_submit'),
  );

  $form['continue_button'] = array(
    '#type' => 'submit',
    '#value' => t('Completed NYSED Uploads - Continue To School Import'),
    '#submit' => array('continue_to_school_upload'),
  );

  $form['#validate'] = array(
    'nys_school_nysed_importer_validate_fileupload',
    'nys_school_nysed_importer_form_validate',
  );

  return $form;

}

/**
 * Validates the file upload.
 */
function nys_school_nysed_importer_validate_fileupload(&$form, &$form_state) {
  // If the continue_to_school_upload button was clicked valid.
  if ($form_state['triggering_element']['#submit'][0] == 'continue_to_school_upload') {
    return;
  }

  // Looking for csv files.
  $validators = array(
    'file_validate_extensions' => array('csv'),
  );

  if ($file = file_save_upload('csvfile', $validators, "public://", FILE_EXISTS_REPLACE)) {
    $form_state['values']['csvupload'] = $file->destination;
  }
  else {
    form_set_error('nys_school_nysed_importer', t('Unable to copy upload file to !dest', array('!dest' => $destination)));
  }
}

/**
 * Validate the form.
 */
function nys_school_nysed_importer_form_validate(&$form, &$form_state) {
  // If the file is specified.
  if (isset($form_state['values']['csvupload'])) {
    if ($handle = fopen($form_state['values']['csvupload'], 'r')) {

      for ($i = 0; $i <= 10; $i++) {

        $line = fgetcsv($handle, 4096);
        if (empty($line) == FALSE && is_array($line) == TRUE) {
          $line_count = count($line);
          foreach ($line as $column) {
            if (($column == 'Institution Id' && $line_count == 19) || ($line_count == 19)) {
              form_set_error('csvfile', t('This file has the incorrect number of columns. Expecting 19'));
            }

          }

        }

      }

      fclose($handle);
    }
    else {
      form_set_error('csvfile', t('Unable to read uploaded file !filepath', array('!filepath' => $form_state['values']['csvupload'])));
    }
  }
}

/**
 * Submit Handler for the input file dialog.
 */
function nys_school_nysed_importer_form_submit(&$form, &$form_state) {
  // Setup the batch.
  $batch = array(
    'title' => t('Importing School Names CSV ...'),
    'operations' => array(),
    'init_message' => t('Commencing'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('An error occurred during processing'),
    'finished' => 'nys_school_nysed_importer_import_finished',
    'file' => drupal_get_path('module', 'nys_school_importer') . '/nys_school_importer.nysed.inc',
  );

  if (isset($form_state['values']['csvupload'])) {
    // File uploaded.
    variable_set('nys_school_nysed_importer_csvupload', $form_state['values']['csvupload']);

    // Clear the nys_school_names table.
    // nys_school_importer_clear_nys_school_names();
    // Reset the importer status.
    variable_set('nys_school_importer_failed', FALSE);

    // Load the nys_school_names table.
    if ($handle = fopen($form_state['values']['csvupload'], 'r')) {
      $batch['operations'][] = array('_nys_school_nysed_importer_remember_filename', array($form_state['values']['csvupload']));
      $line_count = 1;
      $first = TRUE;
      // Read the header line.
      $header_line = fgetcsv($handle, 4096);
      // Read the rest of the lines.
      $line = fgetcsv($handle, 4096);
      while ($line = fgetcsv($handle, 4096)) {
        /*
         * we use base64_encode to ensure we don't overload the batch
         * processor by stuffing complex objects into it
         */
        $line_count++;
        $batch['operations'][] = array(
          '_nys_school_nysed_importer_import_school_names_line',
          array(array_map('base64_encode', $line),
          ),
        );
      }
      fclose($handle);
    } // we caught this in nys_school_nysed_importer_form_validate()
  } // we caught this in nys_school_nysed_importer_form_validate()
  batch_set($batch);
}

/**
 * Processsing complete.
 */
function nys_school_nysed_importer_import_finished($success, $results, $operations) {
  // If there were failures.
  if (!empty($results['failed_rows'])) {
    $dir = file_directory_path() . '/csvImporter/';
    if (file_check_directory($dir, FILE_CREATE_DIRECTORY)) {
      $csv_filename = 'failed_rows-' . basename($results['uploaded_filename']);
      $csv_filepath = $dir . '/' . $csv_filename;
      $targs = array(
        '!csv_url' => l(check_plain($csv_filename), $csv_filepath),
        '%csv_filename' => $csv_filename,
        '%csv_filepath' => $csv_filepath,
      );

      if ($handle = fopen($csv_filepath, 'w+')) {
        foreach ($results['failed_rows'] as $failed_row) {
          fputcsv($handle, $failed_row);
        }
        fclose($handle);
        drupal_set_message(t('Some rows failed to import. You may download a CSV of these rows: !csv_url', $targs), 'error');
      }
      else {
        drupal_set_message(t('Some rows failed to import, but unable to write error CSV to %csv_filepath', $targs), 'error');
      }
    }
    else {
      drupal_set_message(t('Some rows failed to import, but unable to create directory for error CSV at %csv_directory', $targs), 'error');
    }
  }

  $nys_school_nysed_importer_failed = variable_get('nys_school_importer_failed', FALSE);
  if ($nys_school_nysed_importer_failed == TRUE) {
    drupal_set_message(t('The School Survey failed because of a missing or mismatched County Taxonomy Term.'), 'warning');
    drupal_goto('admin/nys-school-report');
    return t('The CSV import was not complete.');
  }
  else {
    drupal_set_message(t('The CSV import has completed.'));
    return t('The CSV import has completed.');
  }

}

/**
 * Helper function.
 */
function _nys_school_nysed_importer_remember_filename($filename, &$context) {
  $context['results']['uploaded_filename'] = $filename;
}

/**
 * Processs the line.
 */
function _nys_school_nysed_importer_import_school_names_line($line, $session_nid, &$context = NULL) {
  $line = $cleaned_line = array_map('base64_decode', $line);
  if (is_numeric($line[0]) == TRUE && is_numeric($line[2]) == TRUE) {

    nys_school_importer_insert_or_update_nysed_data($line[0],
                                                    $line[1],
                                                    $line[2],
                                                    $line[3],
                                                    $line[4],
                                                    $line[5],
                                                    $line[6],
                                                    $line[7],
                                                    $line[8],
                                                    $line[9],
                                                    $line[10],
                                                    $line[11],
                                                    $line[12],
                                                    $line[13],
                                                    $line[14],
                                                    $line[15],
                                                    $line[16],
                                                    $line[17],
                                                    $line[18],
                                                    $line[19]);

  }
}

/**
 * Handler for the continue_button.
 */
function continue_to_school_upload(&$form, &$form_state) {
  drupal_goto('admin/config/system/nys-school-import');
}
