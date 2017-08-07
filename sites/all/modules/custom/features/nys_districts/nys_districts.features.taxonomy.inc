<?php
/**
 * @file
 * nys_districts.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nys_districts_taxonomy_default_vocabularies() {
  return array(
    'districts' => array(
      'name' => 'Districts',
      'machine_name' => 'districts',
      'description' => 'Senate Districts',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
