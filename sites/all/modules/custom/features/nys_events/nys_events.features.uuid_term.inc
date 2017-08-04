<?php
/**
 * @file
 * nys_events.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nys_events_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Committee Meeting',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '060e058d-5394-42b2-bc6b-3f9f58dd5644',
    'vocabulary_machine_name' => 'event_types',
  );
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
    'name' => 'Caucus Meeting',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '77c4831f-8b68-46ca-b639-95f9852eed14',
    'vocabulary_machine_name' => 'event_types',
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
    'name' => 'Conference Call',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9b77f347-25f0-40af-8f79-61a666c1cf1b',
    'vocabulary_machine_name' => 'event_types',
  );
  $terms[] = array(
    'name' => 'Forum/Town Hall',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a3d601bb-8cc4-4349-9391-be5afa92d898',
    'vocabulary_machine_name' => 'event_types',
  );
  $terms[] = array(
    'name' => 'Session',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a6b18f9f-c225-4854-be7e-d8952f3c725e',
    'vocabulary_machine_name' => 'event_types',
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
    'name' => 'Public Hearing',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd98ba438-f259-46e9-a502-5e18ad3632d2',
    'vocabulary_machine_name' => 'event_types',
  );
  $terms[] = array(
    'name' => 'Standing',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ea0478a6-0352-40f0-8a3b-f6650fc0d1c6',
    'vocabulary_machine_name' => 'committee_type',
  );
  $terms[] = array(
    'name' => 'Press Conference',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fd76ee6e-6e2c-457c-abbc-4e0505f52ad5',
    'vocabulary_machine_name' => 'event_types',
  );
  return $terms;
}
