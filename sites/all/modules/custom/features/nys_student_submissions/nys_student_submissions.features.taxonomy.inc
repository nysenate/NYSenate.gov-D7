<?php

/**
 * @file
 * nys_student_submissions.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nys_student_submissions_taxonomy_default_vocabularies() {
  return array(
    'participatory_budgeting_categories' => array(
      'name' => 'Participatory Budgeting Categories',
      'machine_name' => 'participatory_budgeting_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
