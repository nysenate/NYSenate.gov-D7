<?php
/**
 * @file
 * Settings form for the Imagecache Token module.
 */

/**
 * FormAPI callback to load the imagecache_token settings form.
 */
function imagecache_token_settings_form() {
  $fields = field_info_fields();

  $file_fields = array();
  $image_fields = array();
  foreach ($fields as $field) {
    foreach ($field['bundles'] as $entity_type => $bundles) {
      foreach ($bundles as $bundle) {
        $key = $field['type'] . ':' . $field['field_name'] . ':' . $entity_type . ':' . $bundle;
        $label = $entity_type . ': ' . $bundle . ': ' . $field['field_name'];
        if ($field['type'] == 'file' || $field['type'] == 'media') {
          $file_fields[$key] = $label;
        }
        if ($field['type'] == 'image') {
          $image_fields[$key] = $label;
        }
      }
    }
  }

  if (!empty($image_fields)) {
    $form['imagecache_token_images'] = array(
      '#title' => t('Image fields (automatically supported)'),
      '#type' => 'checkboxes',
      '#options' => $image_fields,
      '#default_value' => drupal_map_assoc(array_keys($image_fields)),
      '#description' => t('All image fields are automatically supported by Imagecache Token, nothing needs to be done.'),
      '#disabled' => TRUE,
    );
  }
  else {
    $form['imagecache_token_images'] = array(
      '#type' => 'markup',
      '#markup' => t('There are no image fields on this site.'),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }

  if (!empty($file_fields)) {
    $form['imagecache_token_fields'] = array(
      '#title' => t('"File" and "Media" fields (must be enabled)'),
      '#type' => 'checkboxes',
      '#options' => $file_fields,
      '#default_value' => variable_get('imagecache_token_fields', array()),
      '#description' => t('Both "File" and "Media" fields <em>may</em> be used for images, but they may also be used for other types of files. Select the fields that <em>are</em> used for images so that tokens can be added for them.'),
    );
  }
  else {
    $form['imagecache_token_fields'] = array(
      '#type' => 'markup',
      '#markup' => t('There are no "file" or "media" fields on this site.'),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }

  // Only show the 'save' button if there are fields.
  if (!empty($image_fields) || !empty($file_fields)) {
    $form['#submit'][] = 'imagecache_token_settings_form_submit';

    return system_settings_form($form);
  }

  // If there were *no* fields then show a combined message.
  else {
    $form = array();
    $form['imagecache_token_fields'] = array(
      '#type' => 'markup',
      '#markup' => t('There are no "image", "file" or "media" fields on this site, so there is nothing to configure.'),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
    return $form;
  }
}

/**
 * FormAPI submission callback for imagecache_token_settings_form.
 */
function imagecache_token_settings_form_submit($form, &$form_state) {
  // Make sure the 'images' field isn't saved.
  unset($form_state['values']['imagecache_token_images']);

  // Clear the token caches.
  cache_clear_all('*', 'cache_token', TRUE);
  drupal_static_reset('token_info');

  // Reload the token info.
  token_info();
}
