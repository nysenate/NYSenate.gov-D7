<?php
/**
 * @file
 * nys_schools.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nys_schools_taxonomy_default_vocabularies() {
  return array(
    'nys_counties' => array(
      'name' => 'NYS Counties',
      'machine_name' => 'nys_counties',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
