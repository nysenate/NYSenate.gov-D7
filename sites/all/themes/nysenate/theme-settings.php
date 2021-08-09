<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function nysenate_form_system_theme_settings_alter(&$form, &$form_state) {

  // Container fieldset
  $form['zurb_foundation']['hero'] = array(
    '#type' => 'fieldset',
    '#title' => t('Homepage Hero'),
  );
  
  // Default path for image
  $hero_default_path = theme_get_setting('hero_default_path');
  if (file_uri_scheme($hero_default_path) == 'public') {
    $hero_default_path = file_uri_target($hero_default_path);
  }
  
  // Helpful text showing the file name, disabled to avoid the user thinking it can be used for any purpose.
  $form['zurb_foundation']['hero']['hero_default_path'] = array(
    '#type' => 'textfield',
    '#title' => 'Path to hero default image',
    '#default_value' => $hero_default_path,
    '#disabled' => TRUE,
  );

  // Upload field
  $form['zurb_foundation']['hero']['hero_default_upload'] = array(
    '#type' => 'file',
    '#title' => 'Upload hero image',
    '#description' => 'Upload a new default hero image for use when their is no featured story or live event on homepage.',
  );

  // Attach custom submit handler to the form
  $form['#submit'][] = 'nysenate_settings_submit';
}

/**
 * Capture theme settings submissions and update uploaded image
 */
function nysenate_settings_submit($form, &$form_state) {
	$settings = array();
	// Get the previous value
	$previous = 'public://' . $form['hero']['hero_default_path']['#default_value'];

	$file = file_save_upload('hero_default_upload');
	if ($file) {
		$parts = pathinfo($file->filename);
		$destination = 'public://' . $parts['basename'];
		$file->status = FILE_STATUS_PERMANENT;

		if(file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
		  $_POST['hero_default_path'] = $form_state['values']['hero_default_path'] = $destination;
		  // If new file has a different name than the old one, delete the old
		  if ($destination != $previous) {
		    drupal_unlink($previous);
		  }
		}
	} else {
		// Avoid error when the form is submitted without specifying a new image
		$_POST['hero_default_path'] = $form_state['values']['hero_default_path'] = $previous;
	}
}
