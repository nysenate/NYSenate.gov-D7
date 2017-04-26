<?php
/**
 * @file
 * nys_senators.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nys_senators_taxonomy_default_vocabularies() {
  return array(
    'issues' => array(
      'name' => 'Issues',
      'machine_name' => 'issues',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
