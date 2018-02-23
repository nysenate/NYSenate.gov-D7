<?php

/**
 * @file
 * Common pages for the Media Ckeditor module.
 */

/**
 * Callback to fetch the markup of a file with certain overrides.
 */
function media_ckeditor_rendered_file_in_wysiwyg() {

  // If you would like to see how the $tag_info variable below is built, please:
  // @see media_ckeditor/js/plugins/media/library.js.
  $tag_info = drupal_get_query_parameters();

  // Introductory sanity/security check.
  if (!is_numeric($tag_info['fid'])) {
    throw new Exception('Invalid file id.');
  }

  // Start with the file object.
  $file = file_load($tag_info['fid']);
  if (!$file) {
    throw new Exception('Could not load media object');
  }

  // Now attempt to override any specified fields.
  $fields = array();
  foreach ($tag_info['fields'] as $key => $values) {

    // Only operate on actual fields.
    if (strpos($key, 'field_') === 0) {
      $parsed_field = explode('[', str_replace(']', '', $key));
      $field_name = $parsed_field[0];

      if (isset($file->{$field_name})) {

        // Make sure this is a valid field.
        $field_info = field_info_field($field_name);
        if ($field_info) {
          $field_language = $parsed_field[1];
          $column = key($field_info['columns']);

          // Some field values will show up here as a flat string value, so
          // convert it into a Drupal-friendly field value array.
          if (is_string($values)) {
            $values = array(array($column => $values));
          }

          // The values need to be urldecoded.
          foreach ($values as $index => &$value) {
            if (isset($value[$column])) {
              $value[$column] = urldecode($value[$column]);
            }
          }

          // Override the field on the file entity.
          $fields[$field_name] = array($field_language => $values);
        }
      }
    }
  }

  // Make sure it is indicated that this is a wysiwyg rendering.
  $file->override['wysiwyg'] = TRUE;

  // Now simply print the file entity and exit.
  $build = media_ckeditor_render_file_with_overrides($file, $tag_info['view_mode'], $fields);
  print drupal_render($build);
  drupal_page_footer();
}
