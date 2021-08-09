<?php

/**
 * Implements hook_drush_command().
 */
function nys_utils_drush_command() {
  $items = [
    'entityform-bulk-delete' => [
      'description' => 'Bulk deletes entityform submissions for a given time period.',
      'aliases' => ['efd'],
      'options' => [
        'size' => [
          'description' => 'The number of submissions to process in a single batch request. Defaults to 50.'
        ],
      ],
      'examples' => [
        '$ drush efd' =>
        'A list to select year and entityform type will be displayed.',
      ]
    ]
  ];
  return $items;
}

/**
 * Callback for drush entityform-bulk-delete.
 */ 
function drush_nys_utils_entityform_bulk_delete() {
  // Setup choice for bundle type.
  $info = entity_get_info('entityform');
  $options = array_keys($info['bundles']);
  $choice = drush_choice($options, dt('Select an entityform bundle'));
  if ($choice === FALSE) {
    return drush_set_error('NYS_UTILS_ERROR', dt('Bundle type is required.'));
  }
  else {
    $bundle = $options[$choice];
  }
  // Setup choice for year.
  $options = range(2017, (date("Y") - 1));
  $choice = drush_choice($options, dt('Select a year'));
  if ($choice === FALSE) {
    return drush_set_error('NYS_UTILS_ERROR', dt('Year is required.'));
  }
  else {
    $year = $options[$choice];
  }
  // All submissions created in the chosen year are targeted for deletion.
  $start = new DateTime('first day of january ' . $year);
  $start = $start->getTimeStamp();
  $end = new DateTime('last day of december ' . $year . ' 23:59:59');
  $end = $end->getTimeStamp();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'entityform')
        ->entityCondition('bundle', $bundle)
        ->propertyCondition('created', [$start, $end], 'BETWEEN');
  $result = $query->execute();
  if (isset($result['entityform'])) {
    $total = count($result['entityform']);
    // Prompt user for confirmation.
    $confirm = drush_confirm(dt('Found @total submissions of type @bundle for year @year. Are you sure you want to delete these?', ['@total' => $total,'@bundle' => $bundle, '@year' => $year]));
    if (!$confirm) {
      return drush_user_abort();
    }
    $batch_size = drush_get_option('size', 50);
    $chunks = array_chunk(array_keys($result['entityform']), $batch_size);

    $ops = [];
    $progress = 0;
    foreach ($chunks as $chunk) {
      $progress += count($chunk);
      $ops[] = ['_entityform_delete_multiple', [
        $chunk,
        dt('Processing @progress of @total @bundle submissions',
          ['@progress' => $progress, '@total' => $total, '@bundle' => $bundle])
      ]];
    }
    $batch = [
      'operations' => $ops,
      'title' => dt('Bulk deleting entityform submissions'),
      'finished' => '_entityform_delete_multiple_finished',
      'progress_message' => dt('@current submissions of @total were deleted.'),
    ];

    batch_set($batch);
    // Start processing.
    drush_backend_batch_process();
  }
  else {
    return drush_print(dt('No submissions were found for entityform @bundle bundle in @year. Aborting.', ['@year' => $year, '@bundle' => $bundle]));
  }
}

/**
 * Operations function to process a batch.
 */
function _entityform_delete_multiple($chunk, $msg, &$context) {
  $context['message'] = $msg;
  foreach ($chunk as $id) {
    entity_delete('entityform', $id);
    $context['results'][] = $id;
  }
}

/**
 * Batch finished callback.
 */
function _entityform_delete_multiple_finished($success, $results, $operations) {
  if ($success) {
    drush_print(dt("Success! Deleted @count submissions.", ['@count' => count($results)]));
  }
}