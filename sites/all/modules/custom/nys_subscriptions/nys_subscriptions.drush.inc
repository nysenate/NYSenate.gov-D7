<?php

/**
 * @file
 * Drush integration for the devel module.
 */

/**
 * Clean this place up.
 *
 * TODO: all drush-based management functions should migrate to UI/admin
 */

/**
 * Implements hook_drush_command().
 */
function nys_subscriptions_drush_command() {
  return [
    /** ***********************************
     * BEGIN LEGACY ITEMS
     *********************************** */
    'subscriptions' => [
      'description' => dt('Show All Subscriptions.'),
      'aliases' => ['sw', 'sws'],
    ],

    'subscriptions-id' => [
      'description' => dt('Show data for a subscription.'),
      'arguments' => [
        'bwid' => dt('The bwid subscription index.'),
      ],
      'aliases' => ['swi', 'swid'],
    ],

    'subscriptions-key' => [
      'description' => dt('Show data for a subscription.'),
      'arguments' => [
        'key' => dt('The bwid subscription subscription key.'),
      ],
      'aliases' => ['swk', 'swkey'],
    ],

    'subscriptions-tid' => [
      'description' => dt('Show the Subscriptions associated with a bills tid.'),
      'arguments' => [
        'tid' => dt('The tid of the subscription.'),
      ],
      'aliases' => ['swt', 'swtid'],
    ],

    'subscriptions-nid' => [
      'description' => dt('Show the Subscriptions associated with a bills nid.'),
      'arguments' => [
        'nid' => dt('The nid of the subscription.'),
      ],
      'aliases' => ['swn', 'swnid'],
    ],

    'subscriptions-uid' => [
      'description' => dt('Show the Subscriptions associated with a bills nid.'),
      'arguments' => [
        'uid' => dt('The uid of the subscription.'),
      ],
      'aliases' => ['swu', 'swuid'],
    ],

    'subscriptions-email' => [
      'description' => dt('Show data for a Subscriber.'),
      'arguments' => [
        'email' => dt('The email of the subscriber.'),
      ],
      'aliases' => ['swe'],
    ],

    'subscriptions-keys' => [
      'description' => dt('Show data for a Subscriber using either key.'),
      'arguments' => [
        'key' => dt('The subscription or email key of the subscription.'),
      ],
      'aliases' => ['swks', 'swkeys'],
    ],
    /** ***********************************
     * END LEGACY ITEMS
     *********************************** */

    'process-queues' => [
      'description' => dt('Process all notification queues.'),
      'arguments' => ['queue' => dt('An optional queue name')],
      'options' => [
        'force' => dt('Force the command to ignore any existing process lock'),
      ],
      'aliases' => ['pq'],
    ],
  ];
}

/**
 * Implements drush subscription  bw  bws.
 */
function drush_nys_subscriptions_subscriptions() {
  $sql = '
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM `nys_subscriptions`';

  $title = 'Subscriptions';
  nys_subscriptions_render_table_data_in_drush($sql, $title);
  _other_subscriptions_drush_commands();
}

/**
 * Implements drush subscriptions-tid  bwt  bwtid.
 */
function drush_nys_subscriptions_subscriptions_tid($tid) {
  if (empty($tid)) {
    print "A tid must be suppiled\r\n";
    return;
  }
  if (!is_numeric($tid)) {
    print "A valid numeric tid must be suppiled\r\n";
    return;
  }
  $sql = '
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM `nys_subscriptions` WHERE `tid` = ' . $tid;

  $title = "Subscriptions to TID  $tid";
  nys_subscriptions_render_table_data_in_drush($sql, $title);
  _other_subscriptions_drush_commands();
}

/**
 * Implements drush subscriptions-nid  bwn  bwnid.
 */
function drush_nys_subscriptions_subscriptions_nid($nid) {
  if (empty($nid)) {
    print "A tid must be suppiled\r\n";
    return;
  }
  if (!is_numeric($nid)) {
    print "A valid numeric nid must be suppiled\r\n";
    return;
  }
  $sql = '
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM nys_subscriptions WHERE `nid` = ' . $nid;

  $title = "Subscriptions to NID  $nid";
  nys_subscriptions_render_table_data_in_drush($sql, $title);
  _other_subscriptions_drush_commands();
}

/**
 * Implements drush subscriptions-uid  bwu  bwuid.
 */
function drush_nys_subscriptions_subscriptions_uid($uid) {
  if (empty($uid)) {
    print "A tid must be suppiled\r\n";
    return;
  }
  if (!is_numeric($uid)) {
    print "A valid numeric uid must be suppiled\r\n";
    return;
  }
  $sql = '
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM nys_subscriptions WHERE `uid` = ' . $uid;

  $title = "Subscriptions to UID  $uid";
  nys_subscriptions_render_table_data_in_drush($sql, $title);
  _other_subscriptions_drush_commands();
}

/**
 * Implements drush subscriptions-email  bwe.
 */
function drush_nys_subscriptions_subscriptions_email($email) {
  if (empty($email)) {
    print "An email must be suppiled\r\n";
    return;
  }
  if (!valid_email_address($email)) {
    print "A valid email must be suppiled\r\n";
    return;
  }

  $sql = "
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM nys_subscriptions WHERE `email` = '$email'";

  $title = "Subscriptions to email $email";

  nys_subscriptions_render_table_data_in_drush($sql, $title);
  _other_subscriptions_drush_commands();
}

/**
 * Implements drush subscriptions-keys  bwks  bwkeys.
 */
function drush_nys_subscriptions_subscriptions_keys($key) {

  if (empty($key)) {
    print "An key must be suppiled\r\n";
    return;
  }
  elseif ((strlen($key) > 40 && strlen($key) < 50) == FALSE) {
    print "A valid key must be suppiled\r\n";
    return;
  }

  $sql = "
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM nys_subscriptions WHERE `subscription_key` = '$key' OR `email_address_key` = '$key'";

  $title = "Subscriptions with key $key";

  nys_subscriptions_render_table_data_in_drush($sql, $title);
  _other_subscriptions_drush_commands();
}

/**
 * Implements drush subscriptions-id  bwi  bwid.
 */
function drush_nys_subscriptions_subscriptions_id($bwid) {
  if (empty($bwid)) {
    print "A tid must be suppiled\r\n";
    return;
  }
  if (!is_numeric($bwid)) {
    print "A valid numeric bwid must be suppiled\r\n";
    return;
  }
  $sql = '
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM nys_subscriptions WHERE `bwid` = ' . $bwid;

  $title = "Subscription ID $bwid";
  nys_subscriptions_render_table_data_in_drush($sql, $title);

  $subscription = db_query("SELECT * FROM `nys_subscriptions` WHERE `bwid` = :bwid LIMIT 1", [":bwid" => $bwid])->fetchObject();
  if ($subscription !== FALSE) {
    print "Confirmation Link                    /subscription/subscribe/$subscription->subscription_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
    print "UNSubsubscribe RESubscribribe Link /subscription/unsubscribe/$subscription->subscription_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
    print "Manage Subscriptions      /subscription/manage-subscriptions/$subscription->email_address_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
    print "Global UNSubscrube          /subscription/global-unsubscribe/$subscription->email_address_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
  }
  _other_subscriptions_drush_commands();
}

/**
 * Implements drush subscriptions-key  bwk  bwkey.
 */
function drush_nys_subscriptions_subscriptions_key($key) {
  if (empty($key)) {
    print "An key must be suppiled\r\n";
    return;
  }
  elseif ((strlen($key) > 40 && strlen($key) < 50) == FALSE) {
    print "A valid key must be suppiled\r\n";
    return;
  }

  $sql = "
  SELECT `bwid`, `email`, `uid`, `tid`, `nid`, `why`,
  substr(`subscription_timestamp`,1,1) AS `sub`,
  substr(`confirmation_timestamp`,1,1) AS `cnf`,
  substr(`unsubscribe_timestamp`,1,1) AS `uns`,
  substr(`last_begin_source_datetime_timestamp`,1,1) AS `beg`,
  substr(`last_end_source_datetime_timestamp`,1,1) AS `end`,
  `option`, `subscription_key`, `email_address_key`
  FROM nys_subscriptions WHERE `subscription_key` = '$key'";

  $title = "Subscription KEY $key";
  nys_subscriptions_render_table_data_in_drush($sql, $title);

  $subscription = db_query("SELECT * FROM `nys_subscriptions` WHERE `subscription_key` = :skey LIMIT 1", [":skey" => $key])->fetchObject();
  if ($subscription !== FALSE) {
    print "Confirmation Link                    /subscription/subscribe/$subscription->subscription_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
    print "UNSubsubscribe RESubscribribe Link /subscription/unsubscribe/$subscription->subscription_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
    print "Manage Subscriptions      /subscription/manage-subscriptions/$subscription->email_address_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
    print "Global UNSubscrube          /subscription/global-unsubscribe/$subscription->email_address_key/\r\n";
    print "----------------------------------------------------------------------------------------------------------|\r\n";
  }
  _other_subscriptions_drush_commands();
}

/**
 * Implements the list of drush commands.
 */
function _other_subscriptions_drush_commands() {
  print "\r\n\r\n";
  print "+---------------------+--------------+-------------------------------+\r\n";
  print "| drush commands      | aliases      | argument description          |\r\n";
  print "+---------------------+--------------+-------------------------------+\r\n";
  print "| subscriptions       | bw   bws     | All Subscriptions NO ARGUMENT |\r\n";
  print "| subscriptions-key   | bwk  bwkey   | Subscription with subscr KEY  |\r\n";
  print "| subscriptions-id    | bwi  bwid    | Subscription ID               |\r\n";
  print "| subscriptions-tid   | bwt  bwtid   | Subscriptions to TID          |\r\n";
  print "| subscriptions-nid   | bwn  bwnid   | Subscriptions to NID          |\r\n";
  print "| subscriptions-uid   | bwu  bwuid   | Subscriptions by UID          |\r\n";
  print "| subscriptions-email | bwe          | Subscriptions by email        |\r\n";
  print "| subscriptions-keys  | bwks  bwkeys | Subscriptions by either KEY   |\r\n";
  print "+---------------------+--------------+-------------------------------+\r\n";
}


/**
 * Helper Functions.
 */

/**
 * Renders a table.
 */
function nys_subscriptions_render_table_data_in_drush($sql, $title, $width = 100) {
  $data = [];
  $columns = [];

  if (empty($sql) || empty($title)) {
    print 'Sorry No Report ' . $choice . "\r\n";
    return;
  }

  $results = db_query($sql);

  $row_count = $results->rowCount();

  if ($row_count == 0) {
    print "No Results\r\n";
    return;
  }

  // Get the result data.
  foreach ($results as $row_key => $row) {
    // Go thru the columns including the title and remember the max length.
    $output_row = [];
    foreach ($row as $col_key => $col_value) {
      $output_row[$col_key] = $col_value;
    }
    $data[$row_key] = $output_row;
  }

  // Survey the in query result data and find the lengths.
  foreach ($data as $row_key => $row) {
    // Go thru the columns including the title and remember the max length.
    foreach ($row as $col_key => $col_value) {
      // If this is row 1.
      if ($row_key == 0) {
        $columns[$col_key] = max(strlen($col_key), strlen($col_value));
      }
      else {
        // This is a regular data row.
        $columns[$col_key] = max($columns[$col_key], strlen($col_value));
      }

    }
  }

  // Print the table header.
  // Upper Header Line.
  print '+';
  $col_num = 0;
  foreach ($columns as $column_title => $column_length) {
    $col_num++;

    print str_pad('-', $column_length + 3, '-');

    if ($col_num < count($columns)) {
      print '-';
    }
    else {
      print '+';
    }

  }
  print "\r\n";

  $column_width_sum = 0;
  foreach ($columns as $column_title => $column_length) {
    $column_width_sum = $column_width_sum + $column_length + 3;
  }

  print '|  ';
  print $title;
  $num_spaces_needed = $column_width_sum - strlen($title);

  for ($i = 0; $i <= $num_spaces_needed; $i++) {
    print " ";
  }

  print "|\r\n";

  print '+';
  foreach ($columns as $column_title => $column_length) {

    print str_pad('-', $column_length + 3, '-');
    print '+';

  }
  print "\r\n";

  // Header Line.
  print '|';
  foreach ($columns as $column_title => $column_length) {

    print str_pad($column_title, $column_length + 3);
    print '|';

  }
  print "\r\n";

  // Lower Header Line.
  print '+';
  foreach ($columns as $column_title => $column_length) {

    print str_pad('-', $column_length + 3, '-');
    print '+';

  }
  print "\r\n";

  // Print the table body.
  // Iterate over and render the data.
  foreach ($data as $row_key => $row) {

    print '|';
    foreach ($row as $key => $value) {
      print '  ';
      print str_pad($value, $columns[$key]);
      print ' |';
    }
    print "\r\n";

  } // Rendering the data.

  // Footer Line.
  print '+';
  foreach ($columns as $column_title => $column_length) {

    print str_pad('-', $column_length + 3, '-');
    print '+';

  }
  print "\r\n";

}

/**
 * Process queues.
 *
 * @param string $queue_names A comma-delimited string of queue names.  An
 * array of names is also acceptable.
 */
function drush_nys_subscriptions_process_queues($queue_names = '') {
  // Check for the process lock, and any request to bypass it.
  $force = drush_get_option('force', FALSE);
  $lock = variable_get('nys_subscriptions_process_queues_lock', 0);
  if ($lock) {
    echo "(WARN) Found existing process lock: " . date("Y-m-d H:i:s", $lock) . "\n";
    if ($force) {
      echo "(INFO) Found --force, ignoring lock ...\n";
    }
    else {
      echo "(FAIL) Aborting process due to existing lock.  Use --force to bypass.\n";
      return;
    }
  }

  // Set the process lock
  variable_set('nys_subscriptions_process_queues_lock', time());

  // Load the time limit, in seconds
  $bedtime = _nys_subscriptions_execution_limit();

  // If no name, get all the queues.
  if (!$queue_names) {
    echo "(INFO) No queue named passed, processing all queues.\n";
    $queue_names = array_keys(NYSSubscriptionQueue::listQueues());
  }

  // Make sure we are working with an array
  if (!is_array($queue_names)) {
    $queue_names = explode(',', $queue_names);
  }

  // Iterate through each queue and process it.
  foreach ($queue_names as $queue_name) {
    if ($one_queue = NYSSubscriptionQueue::getInstance($queue_name)) {
      // Process the queue.
      _drush_nys_subscriptions_process_queue($one_queue);
    }
    else {
      echo "(WARN) Could not instantiate queue $queue_name, skipping.\n";
    }
    if ($bedtime && ($bedtime < time())) {
      echo "(INFO) Max processing time exceeded, stopping processing.\n";
      break;
    }
  }

  // Set the last run marker
  nys_utils_set_cron_lastrun('process_queues');

  // All done, clear the process lock
  variable_set('nys_subscriptions_process_queues_lock', 0);
}

/**
 * Processes a single queue.  This duplicates $queue->process(), except it
 * does not stop on encountering a failure.  It will continue until all
 * items have been attempted at least once, or the maximum execution time
 * has been reached.  It also has significantly more reporting.
 *
 * TODO: this should be default behavior, but ...
 * The reporting is not appropriate outside of drush.  Also don't want to
 * flood watchdog, so hook_watchdog() is bad.  Need an intelligent logger.
 * Like NysTranscriptImportProcessor::setLog(), but global.
 *
 * @param NYSSubscriptionQueue $queue The queue to process.
 */
function _drush_nys_subscriptions_process_queue($queue) {
  echo "(INFO) Begin processing queue " . $queue->getName() . " ... \n";

  // Initialize the count variables.
  $total = $success = 0;
  // Need to hold fails until all is finished to prevent endless loop.
  $fails = [];

  // Get the time limit, in seconds
  $bedtime = _nys_subscriptions_execution_limit();

  // Get the list of suppressed taxonomies
  $suppress = explode(',', variable_get('nys_subscriptions_suppress_tid', ''));

  // Get each item in the queue and process() it.
  while ($item = $queue->claimItem()) {
    $total++;
    if (in_array($item->data['tid'], $suppress)) {
      $msg = t(
        '(INFO) Item !item (tid: !tid, name: !key) has been suppressed. Item will be returned to queue.',
        [
          '!item' => $item->item_id,
          '!key' => $item->data['tax_name'],
          '!tid' => $item->data['tid'],
        ]
      );
      echo $msg . "\n";
      $one_success = FALSE;
    }
    else {
      try {
        // The return will be as from drupal_mail()
        $result = $item->process();
        $one_success = $result['result'] ?? FALSE;
      } catch (Exception $e) {
        // The item will throw an exception if something in the item data
        // prevents processing.  API failures (e.g., SendGrid returns a
        // 404) are considered "normal" failures.
        $one_success = FALSE;
        echo "(WARN) Exception while processing item " . $item->item_id . ":\n" .
          $e->getMessage() . "\n";
      }
    }

    // If processing was successful, delete the queue item.
    if ($one_success) {
      $queue->deleteItem($item);
      $success++;
    }
    // Reinstate the fails for the next try.
    else {
      $fails[] = $item;
    }

    // If we're past our bedtime, leave
    if ($bedtime && ($bedtime < time())) {
      echo "(INFO) Stopping this queue due to maximum runtime.\n";
      break;
    }
  }

  // Release all the failures back into queue.
  foreach ($fails as $val) {
    $queue->releaseItem($val);
  }

  echo "(INFO) ... processed $success items, with " . count($fails) . " failures ($total total).\n";
}

function _nys_subscriptions_execution_limit() {
  $bedtime = &drupal_static(__FUNCTION__);
  if (!$bedtime) {
    $limit = (int) variable_get('nys_subscriptions_max_drush_time', NYS_SUBSCRIPTIONS_MAX_DRUSH_TIME);
    $bedtime = $limit ? ($limit * 60) + time() : 0;
  }
  return $bedtime;
}
