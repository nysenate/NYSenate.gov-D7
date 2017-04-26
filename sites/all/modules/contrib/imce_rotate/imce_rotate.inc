<?php

/**
 * @file
 * Implements the IMCE Rotate Function.
 */

/**
 * Implements hook_form_formID_alter().
 */
function _imce_rotate_form_imce_fileop_form_alter(&$form, &$form_state, &$imce) {
  $form['fset_rotate'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rotate'),
  ) + imce_rotate_form($imce);
}

/**
 * Rotate form.
 */
function imce_rotate_form(&$imce) {

  $form['rotate_direction'] = array(
    '#type' => 'radios',
    '#title' => t('Rotate direction'),
    '#default_value' => 'clockwise',
    '#options' => array(
      'clockwise' => t('90deg Clockwise'),
      'counterclockwise' => t('90deg Counterclockwise'),
      'flip' => t('180 Degrees'),
    ),
  );
  $form['rotate_copy'] = array(
    '#type' => 'checkbox',
    '#prefix' => '</br>',
    '#title' => t('Create a new image'),
    '#default_value' => 0,
  );
  $form['rotate'] = array(
    '#type' => 'submit',
    '#value' => t('Rotate'),
    '#submit' => $imce['perm']['rotate'] ? array('imce_rotate_submit') : NULL,
  );
  $path = drupal_get_path('module', 'imce_rotate');
  $form['#attached'] = array(
    'js' => array($path . '/imce_rotate.js'),
    'css' => array($path . '/imce_rotate.css'),
  );
  return $form;
}

/**
 * Submit rotate form.
 */
function imce_rotate_submit($form, &$form_state) {
  $form_state['redirect'] = FALSE;
  $imce = &$form_state['build_info']['args'][0]['imce'];
  $rotated = imce_process_files($form_state['values']['filenames'], $imce, 'imce_rotate_file', array($form_state['values']['rotate_direction'], $form_state['values']['rotate_copy']));
  if (!empty($rotated)) {
    drupal_set_message(t('File rotation successful: %files.', array('%files' => utf8_encode(implode(', ', $rotated)))));
  }
}

/**
 * Rotate a file in the file list.
 */
function imce_rotate_file($filename, &$imce, $rotate = '90', $copy = FALSE) {
  // Prevent degrading the quality of an image by forcing 100% quality.
  $org_quality = variable_get('image_jpeg_quality', 75);
  variable_set('image_jpeg_quality', 100);

  switch ($rotate) {
    case 'clockwise':
      $rotate_direction = 90;
      break;

    case 'counterclockwise':
      $rotate_direction = -90;
      break;

    case 'flip':
      $rotate_direction = 180;
      break;
  }

  $destdir = imce_dir_uri($imce);
  $imguri = $destdir . $filename;
  $image = image_load($imguri);
  // Here's where we rotate the image.
  if (!$image || !image_rotate($image, $rotate_direction)) {
    drupal_set_message(t('Rotate failed for "@file" .', array('@file' => utf8_encode($filename))), 'error');
    return FALSE;
  }
  // We only run these operations if we are going to create a new image.
  if ($copy == TRUE) {
    // Create file object.
    $file = new stdClass();
    $file->uri = file_create_filename($filename, $destdir);
    $file->filename = basename($file->uri);

    // Validate file new name.
    $errors = file_validate_name_length($file);
    if (!empty($errors)) {
      drupal_set_message($errors[0], 'error');
      return FALSE;
    }

    // Copy to a temp file.
    if (!$tempuri = drupal_tempnam('temporary://', 'imce')) {
      return FALSE;
    }
    register_shutdown_function('file_unmanaged_delete', $tempuri);
    if (!image_save($image, $tempuri) || !$image->info) {
      return FALSE;
    }

    // Validate user quota with IMCE for new file creation.
    $file->filesize = $image->info['file_size'];
    $quotadiff = $file->filename == $filename ? -$imce['files'][$filename]['size'] : 0;
    if (!imce_validate_quotas($file, $imce, $quotadiff)) {
      return FALSE;
    }

    // Build the rest of the file object.
    $file->uid = $imce['uid'];
    $file->filemime = $image->info['mime_type'];
    $file->status = FILE_STATUS_PERMANENT;
    $file->timestamp = REQUEST_TIME;

    // Copy from temp to file uri.
    $destination = $file->uri;
    $file->uri = $tempuri;
    if (!$file = file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
      return FALSE;
    }
    imce_file_register($file);

    // Update file list.
    // Get the new dimensions of the rotated image.
    $img = imce_image_info($file->uri);
    $file->width = $img['width'];
    $file->height = $img['height'];
    imce_add_file($file, $imce);

    drupal_set_message(t('"@file" created.', array('@file' => utf8_encode($file->filename))));
    return $file;
  }
  else {
    // Save the original image if we have created a new one.
    image_save($image);

    // Set image quality back.
    variable_set('image_jpeg_quality', $org_quality);
    drupal_set_message(t('"@file" Rotated.', array('@file' => utf8_encode($filename))));
  }
}
