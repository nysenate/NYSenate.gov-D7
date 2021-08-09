<?php

/**
 * @file
 * nys_files.file_type.inc
 */

/**
 * Implements hook_file_default_types().
 */
function nys_files_file_default_types() {
  $export = array();

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = 'home_page_hero';
  $file_type->label = 'Home Page Hero';
  $file_type->description = 'Use for home page hero only.';
  $file_type->mimetypes = array(
    0 => 'image/jpeg',
    1 => 'image/jpeg',
    2 => 'image/png',
  );
  $export['home_page_hero'] = $file_type;

  return $export;
}
