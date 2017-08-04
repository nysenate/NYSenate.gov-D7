<?php
/**
 * @file
 * nys_districts.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nys_districts_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_districts_pattern';
  $strongarm->value = 'district/[term:field_district_number]';
  $export['pathauto_taxonomy_term_districts_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_districts';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_districts'] = $strongarm;

  return $export;
}
