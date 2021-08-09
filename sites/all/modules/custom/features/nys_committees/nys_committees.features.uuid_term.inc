<?php
/**
 * @file
 * nys_committees.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nys_committees_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Task Force & Other Entities',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '0a223d53-5afc-46b3-84e2-f20bea2e7df8',
    'vocabulary_machine_name' => 'committee_type',
  );
  $terms[] = array(
    'name' => 'Legislative Commissions',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '25683420-6e4b-4783-bdbd-cb40baa87702',
    'vocabulary_machine_name' => 'committee_type',
  );
  $terms[] = array(
    'name' => 'Subcommittee',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '8543a96b-150f-413e-bfa0-7d985d5ca2bb',
    'vocabulary_machine_name' => 'committee_type',
  );
  $terms[] = array(
    'name' => 'Temporary',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'c6a31f1c-bb7e-485a-9923-8ee85ed8c8eb',
    'vocabulary_machine_name' => 'committee_type',
  );
  $terms[] = array(
    'name' => 'Standing',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ea0478a6-0352-40f0-8a3b-f6650fc0d1c6',
    'vocabulary_machine_name' => 'committee_type',
  );
  return $terms;
}
