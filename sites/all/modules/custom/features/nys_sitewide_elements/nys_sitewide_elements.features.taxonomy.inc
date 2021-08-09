<?php

/**
 * @file
 * nys_sitewide_elements.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nys_sitewide_elements_taxonomy_default_vocabularies() {
  return array(
    'majority_issues' => array(
      'name' => 'Majority Issues',
      'machine_name' => 'majority_issues',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
