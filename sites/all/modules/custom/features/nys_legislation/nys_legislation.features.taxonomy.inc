<?php
/**
 * @file
 * nys_legislation.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nys_legislation_taxonomy_default_vocabularies() {
  return array(
    'prev_ver' => array(
      'name' => 'Previous Versions',
      'machine_name' => 'prev_ver',
      'description' => 'Previous Version tree',
      'hierarchy' => 0,
      'module' => 'nys_bill_taxonomy',
      'weight' => 0,
    ),
  );
}
