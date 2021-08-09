<?php

/**
 * @file
 * Drush integration functions for the nys_bill_notifications module.
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 */
function nys_bill_notifications_drush_command() {
  return [
    "bill-notification-trigger" => [
      "description" => "Fetch and analyze OpenLeg updates for the purpose of generating notifications.",
      "aliases" => ['bnt', 'detect-bill-changes'],
      "options" => [
        "offset" => "Set an optional offset to pick up from a failed import. Defaults to 1.",
        "reset-lock" => "Clears the change detection lock.",
        "update-from" => "Timestamp indicating beginning of desired block of updates. (defaults to time of last processed update)",
        "update-to" => "Timestamp indicating end of desired block of updates. (defaults to update time of last imported bill)",
      ],
    ],
  ];
}

/**
 * Callback for the 'detect-bill-changes' command.
 * TODO: Add the ability to get updates for a single bill
 */
function drush_nys_bill_notifications_bill_notification_trigger() {
  echo "Processing bill updates to detect changes...\n";
  echo t("Start time: !start", ['!start' => date("m/d/Y H:i:s", strtotime("now"))]) . "\n";

  if (drush_get_option("reset-lock") !== NULL) {
    variable_set("bill_change_detection_lock", 0);
  }

  $lock = variable_get("bill_change_detection_lock", 0);

  // Check that there is no lock in place
  if (!$lock) {
    try {
      // Set the lock.
      variable_set("bill_change_detection_lock", time());

      $from_time = drush_get_option("update-from");
      $to_time = drush_get_option("update-to");
      $offset = drush_get_option("offset");
      // TODO: this should retrieve updates, then call consume()
      _drush_nys_bill_notifications_consume_updates($from_time, $to_time, $offset);
    } finally {
      // Remove the lock.
      variable_set("bill_change_detection_lock", 0);
    }
  }
  else {
    echo t("Skipping execution...\n");
    echo t("Locked since: '!lock'\n", ['!lock' => date("m/d/Y H:i:s", $lock)]);
  }

  echo t("End time: !end", ['!end' => date("m/d/Y H:i:s", strtotime("now"))]) . "\n";
  nys_utils_set_cron_lastrun('bill_change_detection');
}

/**
 * Query bill updates from OpenLeg and run them through change detection.
 * TODO: Limit this to just consuming updates
 *
 * @param ?string $from_time
 *   query for updates after this time. Defaults to last update processed.
 * @param ?string $to_time
 *   query for updates up to this time. Defaults to last update processed by
 *   bill importer.
 * @param ?int $initial_offset
 *   Get results starting at this number. (Useful for picking up after a
 *   failure.) Default 1.
 */
function _drush_nys_bill_notifications_consume_updates($from_time = NULL, $to_time = NULL, $initial_offset = NULL) {
  // Set up default conditions and state variables, necessary for OpenLeg URL.
  $openleg_key = variable_get("openleg_key");
  $ol_base_url = variable_get("openleg_base_url");
  $base_url = $ol_base_url . "/api/3/bills/updates/";
  $ol_url_key = "&key=" . $openleg_key;

  // Timestamp of the last successfully processed update block.
  $last_update = variable_get("bill_change_detection_last_update", date(NYS_BILL_CHANGE_DETECTION_DATETIME_FORMAT, 0));
  // Timestamp of the last update digest processed by the bill importer.
  $last_bill_import_update = variable_get("bill_import_last_update", date(BILL_IMPORT_DATETIME_FORMAT, 0));

  // Indicates more records exist beyond what is currently fetched.
  $more_results = TRUE;

  // Indicates the maximum number of update blocks to process in one loop.
  $throttle = 1000;

  // Indicates the starting offset for this run.  This defaults to '1', but
  // can be read from command line to resume a failed previous run.
  $offset = $initial_offset ?? 1;

  // The global count of processed updates.
  $count = 0;

  // Detect this run's timestamp window for updates.  These could have been
  // passed on the command line, or they will default to "from last run
  // until the last bill import update".
  $from_time = $from_time ?: $last_update;
  $to_time = $to_time ?: $last_bill_import_update;

  if ($from_time === $to_time) {
    echo t("INFO: to_time equals from_time.  No updates to process.\n");
    $more_results = FALSE;
  }
  elseif ($from_time > $to_time) {
    echo t("WARN: from_time exceeds to_time: [$from_time, $to_time]\n");
    echo t("WARN: updates will not be queried.\n");
    $more_results = FALSE;
  }

  // Loop until all results in this set are consumed.
  while ($more_results) {
    // Create this iteration's update block request.  This request goes to
    // OpenLeg's updates API for a specific range of time.  The request is
    // limited by the throttle amount and offset value.
    $ol_url = $base_url . $from_time . "/" . $to_time .
      "?detail=true&order=asc&offset=" . $offset .
      "&limit=" . $throttle;
    $full_url = $ol_url . $ol_url_key;

    // Fetch this iteration's results.
    echo t("INFO: Fetching: !url", ['!url' => $ol_url]) . "\n";
    $base_result = json_decode(file_get_contents($full_url));

    // If we don't have have success in the update blocks call, stop all work.
    if (!isset($base_result->success) || !$base_result->success) {
      // Bad base result. Stop the update prematurely.
      echo t("ERROR: Query for update blocks failed!") . "\n";
      break;
    }

    // Report on the loop iteration status.
    $tracearr = [
      '!count' => count($base_result->result->items),
      '!offsetstart' => $base_result->offsetStart,
      '!offsetend' => $base_result->offsetEnd,
      '!total' => $base_result->total,
    ];
    echo t("INFO: Processing offset !offsetstart -> !offsetend, !count items of !total total", $tracearr) . "\n";

    // Iterate the results and process.
    foreach ($base_result->result->items as $update) {
      _drush_nys_bill_notifications_change_detection($update);
      $last_update = $update->processedDateTime;
      $count++;
    }

    // If there are more pages, cycle the offset and continue the loop.
    if ($base_result->offsetEnd < $base_result->total) {
      $offset = $base_result->offsetEnd + 1;
    }
    // Otherwise, kill the loop flag.
    else {
      echo "INFO: Result datapoints indicate end of cycle.\n";
      $more_results = FALSE;
    }
  }

  // Save the timestamp of the last update processed
  variable_set("bill_change_detection_last_update", $last_update);

  echo t("Processed !count bill update(s).", ["!count" => $count]) . "\n";

  // Finalize detected changes if any updates were processed.
  if ($count > 0) {
    _drush_nys_bill_notifications_finalize_changes();
  }
}

/**
 * Function to detect "important" changes to bills via JSON update blocks
 * received from OpenLeg API call (/api/3/bills/updates).  Each update block
 * received will be tested against all known tests.
 *
 * @param $item object A JSON-decoded object representing a single update block.
 *
 * @see nys_bill_notifications_generate_test_array() for information on tests.
 *
 */
function _drush_nys_bill_notifications_change_detection($item) {
  // Only test actual bills, i.e., print number begins with 'S' or 'A'.
  if (!preg_match('/^[sa]/i', $item->id->basePrintNo)) {
    return;
  }

  // Get/Initialize the set of changes being tracked.
  $changes = &_nys_bill_notifications_session_changes();

  // Get all the tests.
  $all_tests = nys_bill_notifications_generate_test_array();

  // Iterate through all the tests.  If any are matched (return true),
  // generate a change record.
  foreach ($all_tests as $test_name => $test_def) {
    if (_test_openleg_update_block($item, $test_def)) {
      // Derive the key for this bill.
      $key = $item->id->session . '-' . $item->id->basePrintNo;

      // Make sure current changelist has a spot for this print number.
      if (!is_array($changes[$key] ?? FALSE)) {
        $changes[$key] = [];
      }

      // Initialize the new item array.
      $passed_test_item = [
        'name' => $test_name,
        'timestamp' => strtotime($item->sourceDateTime),
        'text' => '',
        'priority' => _nys_bill_notifications_get_event_priority($test_name),
      ];

      // Look for the actual formatting function.
      $hook_name = "ol_update_format_" . nys_utils_make_name_safe($test_name);

      // A custom-named callback may be defined in the test.  If it doesn't
      // exist, use the standard callback convention.
      if (isset($test_def['#callback']) && function_exists($test_def['#callback'])) {
        $formatter_name = $test_def['#callback'];
      }
      else {
        $formatter_name = "nys_bill_notifications_" . $hook_name;
      }

      // Call the formatter.
      if (function_exists($formatter_name)) {
        $passed_test_item['text'] = $formatter_name($item);
      }

      // Allow other modules to modify this update reporting.
      drupal_alter($hook_name, $passed_test_item, $item);

      // Save the new change item.
      $changes[$key]['#changes'][] = $passed_test_item;
    }
  }
}

/**
 * Processes detected changes to add them to the notification queue.
 *
 * The print numbers contained in this session's changes are correlated to
 * the root taxonomies representing the bill lineage.
 */
function _drush_nys_bill_notifications_finalize_changes() {
  // Set the root tid markers for all changes.
  _nys_bill_notifications_find_taxonomy_roots();

  // Get the current session's changes.
  $changes = &_nys_bill_notifications_session_changes();

  // Get the configured max recipient count.
  $max_recip = (int) variable_get('nys_bill_notifications_max_recip_count', 0);
  if ($max_recip < 1) {
    $max_recip = NYS_BILL_NOTIFICATIONS_MAX_RECIP_COUNT;
  }

  // Get the queue we're using.
  $queue = NYSSubscriptionQueue::getInstance(NYS_BILL_NOTIFICATIONS_QUEUE);
  echo t("Finalizing changes using queue !name", ['!name' => $queue->getName()]) . "\n";

  // Load each set of changes into the notification queue.
  $success = TRUE;

  foreach ($changes as $key => $val) {
    $one_success = TRUE;
    // If the taxonomy ID or node ID is missing, report and skip.
    if (!(($val['#info']['tid'] ?? FALSE) && ($val['#info']['nid'] ?? FALSE))) {
      echo t('Bill !print_num is missing target information... ', ['!print_num' => $key]) . "\n";
      $one_success = FALSE;
    }
    // Otherwise, load the subscribers, chunk them, and add the queue items.
    else {
      // Load the subscriber UIDs and chunk them according to the configured max.
      $all_users = _nys_bill_notifications_fetch_bill_subscribers($key);
      $users = array_chunk($all_users, $max_recip);

      echo t("(INFO) Adding !changes event(s) for !print with !users subscribers in !groups group(s)", [
          '!changes' => count($val['#changes']),
          '!print' => $key,
          '!users' => count($all_users),
          '!groups' => count($users),
        ]) . "\n";

      // Prepare the common item data.
      $item_data = [
        'tax_name' => $key,
        'tid' => $val['#info']['tid'],
        'nid' => $val['#info']['nid'],
        'events' => $val['#changes'],
      ];

      // For each chunk, set recipients and save the queue item.
      foreach ($users as $one_batch) {
        $item_data['recipients'] = $one_batch;
        if (!$good_write = $queue->createItem($item_data)) {
          echo t('  !! failed to write an event chunk with !subs subscribers',
              ['!subs' => count($one_batch)]) . "\n";
        }
        $one_success &= $good_write;
      }
    }

    if (!$one_success) {
      echo t('  !! some event chunks for !print_num were not saved', ['!print_num' => $key]) . "\n";
    }
    $success &= $one_success;
  }

  if (!$success) {
    echo t("(WARN) At least one event could not be queued.  See log for details.") . "\n";
  }

  return $success;
}
