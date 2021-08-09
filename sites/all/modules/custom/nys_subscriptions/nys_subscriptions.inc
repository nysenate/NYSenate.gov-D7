<?php


/**
 * @file
 * NYS Subscriptions inc. internal functions.
 */

/**
 * @deprecated
 *
 * This entire file is deprecated and should be refactored to handle
 * subscriptions in a more robust fashion.  We need a formal subscription
 * object, with methods to support management and reporting.
 */


define("NYS_SUBSCRIPTIONS_SIGNUP_TEMPLATE", "nys_subscriptions_signup_template");


/**
 * Translates the 'why' number into something useful.
 *
 * TODO: this should be distributed, allowing responsible modules to declare
 *       their own "why" values.
 *
 * @param int $why
 *
 * @return string
 */
function _nys_subscriptions_resolve_why_data($why) {
  switch ((int) $why) {
    case 2:
      $ret = 'voted on';
      break;
    default:
      $ret = 'subscribed to alerts for';
      break;
  }
  return $ret;
}

/**
 * Generates the base Mail object used generally by the subscription
 * module.  If successful, it will be returned pre-populated with the
 * From and optional Bcc and Reply-To header information.  If creation
 * fails, a null value will be returned.
 *
 * @returns ?\SendGrid\Mail\Mail
 *
 */
function _nys_subscriptions_generate_mail_object() {
  // Load From and Reply-To header contents from global variables.
  // Note that From address must be populated with a valid email,
  // though the name may be blank.  The Reply-To fields are optional,
  // and will only be used if both are populated.
  $from_addr = variable_get('nys_subscriptions_from_address');
  $from_name = variable_get('nys_subscriptions_from_name');
  $reply_addr = variable_get('nys_subscriptions_replyto_address');
  $reply_name = variable_get('nys_subscriptions_replyto_name');

  // Try to create the objects.  Report on failure.
  try {
    // Create the From object
    $from = new \SendGrid\Mail\From($from_addr, $from_name);

    // Create the Mail object.
    /**
     * @see https://github.com/sendgrid/sendgrid-php/issues/686
     *      Fixed in v7.4.0
     */
    $mail = new \SendGrid\Mail\Mail($from);

    // Set the Reply-To, if configured.
    if ($reply_name && $reply_addr) {
      $mail->SetReplyTo($reply_addr, $reply_name);
    }

    // Set BCC configuration, if conditions require it and it is configured.
    if (!nys_utils_detect_mail_rerouting()
      && ($bcc_address = variable_get('nys_subscriptions_bcc_address', ''))) {
      $mail->setBccSettings(TRUE, $bcc_address);
    }
  }
  catch (Throwable $e) {
    $msg = 'Mail object generation failed due to invalid or poorly-formed From/Reply-To/Bcc information. Check nys_subscriptions configuration at /admin/config/services/nys_subscriptions.';

    // Report in watchdog
    watchdog(
      'nys_subscriptions',
      $msg,
      ['%addr' => $from_addr, '%name' => $from_name, 'msg' => $e->getMessage()],
      WATCHDOG_ERROR
    );

    // Report to slack
    $fields = [
      'event' => $msg,
      'exception' => $e->getMessage(),
      'address' => $from_addr,
      'name' => $from_name,
    ];
    nys_sendgrid_report_to_slack($fields);

    // Return null to signal failure.
    return NULL;
  }

  return $mail;
}

/**
 * Creates a key based on the email and tid and a sitewide secret.
 *
 * Arguments
 *   $email_address   The email address of the subscriber.
 *   $tid             The tid of the bills parent taxonomy term.
 */
function nys_subscriptions_create_subscriber_key($email) {
  $seed = variable_get(NYS_SUBSCRIPTIONS_SUBSCRIPTION_KEY, '');
  if (empty($seed)) {
    $seed = drupal_random_key(10);
    variable_set(NYS_SUBSCRIPTIONS_SUBSCRIPTION_KEY, $seed);
  }

  return drupal_hmac_base64($email . $seed, 'nys');

}

/**
 * Creates a key based on the email and tid and a sitewide secret.
 *
 * Arguments
 *   $email_address   The email address of the subscriber.
 *   $tid             The tid of the bills parent taxonomy term.
 */
function nys_subscriptions_create_subscription_key($email, $tid) {
  $seed = variable_get(NYS_SUBSCRIPTIONS_SUBSCRIPTION_KEY, '');
  if (empty($seed)) {
    $seed = drupal_random_key(10);
    variable_set(NYS_SUBSCRIPTIONS_SUBSCRIPTION_KEY, $seed);
  }

  return drupal_hmac_base64($email . $tid . $seed, 'nys');

}

/**
 * Subscriptions Status Meessage.
 */
function nys_subscriptions_status_message($message) {
  return '<h3>' . urldecode($message) . '</h3>';
}

/**
 * Lookup the name of the taxonomy term tid.
 */
function nys_subscriptions_get_parents_name($tid) {
  $term = taxonomy_term_load($tid);
  if ($term !== FALSE) {
    return $term->name;
  }
  return FALSE;
}

/**
 * Lookup the name of the taxonomy term tid.
 */
function nys_subscriptions_get_parents_description($tid) {
  $term = taxonomy_term_load($tid);
  if ($term !== FALSE) {
    return $term->description;
  }
  return FALSE;
}

/**
 * Lookup the name of the bill by its nid.
 */
function nys_subscriptions_get_bill_title($nid) {
  $node = node_load($nid);
  if ($node !== FALSE) {
    $name = (isset($node->field_ol_name['und'][0]['value']) ? $node->field_ol_name['und'][0]['value'] : '');
    $summary = (isset($node->field_ol_summary['und'][0]['value']) ? $node->field_ol_summary['und'][0]['value'] : '');
    if (!empty($name)) {
      return "$node->title - $name";
    }
    elseif (empty($name) && !empty($summary) && strlen($summary) < 128) {
      return $node->title . ' - ' . $summary;
    }
    elseif (empty($name) && !empty($summary) && strlen($summary) >= 128) {
      return $node->title . ' - ' . substr($summary, 0, 128) . '...';
    }
    return $node->title;
  }
  return FALSE;
}

/**
 * Adds a subscription to the nys_subscriptions table.
 *
 *   $tid             The tid of the bills parent taxonomy term.
 *   $nid             The $nid node id of the bill page subscribed on.
 *   $email_address   The email address of the subscriber.
 *   $why             The reason the email is being sent subscribed= 2 voted = 1
 */
function nys_subscriptions_subscription_signup($tid, $nid, $email_address, $why = 0) {
  global $user;

  $fields = [
    'email' => $email_address,
    'tid' => $tid,
    'nid' => $nid,
    'why' => $why,
    'uid' => $user->uid,
    'confirmed' => time(),
  ];

  _real_nys_subscriptions_subscription_signup($fields);
}


/**
 * This is a hack.  The original function was bound to the global user object,
 * but we need a way to create subscriptions for users who are not logged in
 * or are creating an account during the current request.
 * TODO: refactor the entirety of subscription mechanics
 *
 * @param array $data An array with field names as keys.
 */
function _real_nys_subscriptions_subscription_signup($data = []) {
  // Make sure important data points exist.
  $fields = $data + [
      'email' => '',
      'tid' => 0,
      'nid' => 0,
      'uid' => 0,
      'confirmed' => 0,
    ];

  // Make sure the required data points are populated.
  if ($fields['email'] && $fields['tid'] && $fields['nid']) {
    // Check to see if a subscription exists for this email/tid combination.
    $query = "SELECT COUNT(*) FROM `nys_subscriptions` WHERE `tid` = :tid AND `email` = :email";
    $tokens = [":tid" => $fields['tid'], ":email" => $fields['email']];
    $quantity = (int) db_query($query, $tokens)->fetchField();

    // If no duplicate exists, write the subscription.
    if ($quantity == 0) {
      // Generate the meta-data fields.
      $why = isset($fields['why']) ? $fields['why'] : 1;
      $fields = [
          'subscription_timestamp' => time(),
          'confirmation_timestamp' => ($fields['confirmed'] ? time() : 0),
          'data' => nys_subscriptions_get_bill_data($why),
          'subscription_key' => nys_subscriptions_create_subscription_key($fields['email'], $fields['tid']),
          'email_address_key' => nys_subscriptions_create_subscriber_key($fields['email']),
        ] +
        $fields +
        ['type' => 'bill'];

      // Clean up some stuff.
      unset($fields['why']);
      unset($fields['confirmed']);

      try {
        db_insert('nys_subscriptions')->fields($fields)->execute();
      }
      catch (Exception $e) {
        watchdog('php', "Query to create subscription failed with exceptions");
      }
    }
  }
}

/**
 * Confirms a subscription in the nys_subscriptions table.
 *
 * Argument.
 *   $subscription_key  The key of the subscription.
 */
function nys_subscriptions_subscription_confirmation($subscription_key) {

  $num_updated = db_update('nys_subscriptions')
    ->fields(array(
      'confirmation_timestamp' => time(),
    ))
    ->condition('subscription_key', $subscription_key, '=')
    ->execute();

  // The publishing cache for the topic of the subscription is no longer valid.
  nys_subscriptions_invalidate_topic_cache($subscription_key);

}

/**
 * Confirms a subscription in the nys_subscriptions table.
 *
 * Argument.
 *   $subscription_key  The key of the subscription.
 */
function nys_subscriptions_subscription_unsubscribe($subscription_key) {

  $num_updated = db_update('nys_subscriptions')
    ->fields(array(
      'unsubscribe_timestamp' => time(),
    ))
    ->condition('subscription_key', $subscription_key, '=')
    ->execute();

  // The publishing cache for the topic of the subscription is no longer valid.
  nys_subscriptions_invalidate_topic_cache($subscription_key);
}

/**
 * Confirms a subscription in the nys_subscriptions table.
 *
 * Argument
 *   $subscription_key The key of the subscription.
 */
function nys_subscriptions_subscription_resubscribe($subscription_key) {

  $num_updated = db_update('nys_subscriptions')
    ->fields(array(
      'unsubscribe_timestamp' => 0,
    ))
    ->condition('subscription_key', $subscription_key, '=')
    ->execute();

  // The publishing cache for the topic of the subscription is no longer valid.
  nys_subscriptions_invalidate_topic_cache($subscription_key);
}

/**
 * Confirms a subscription in the nys_subscriptions table.
 *
 * Argument.
 *   $email_address_key  The key of the subscription.
 *   $tid  The tid of the subscription.
 */
function nys_subscriptions_subscription_unsubscribe_by_tid($email_address_key, $tid) {

  $num_updated = db_update('nys_subscriptions')
    ->fields(array(
      'unsubscribe_timestamp' => time(),
    ))
    ->condition('email_address_key', $email_address_key, '=')
    ->condition('tid', $tid, '=')
    ->execute();

}

/**
 * Confirms a subscription in the nys_subscriptions table.
 *
 * Argument.
 *   $email_address_key  The key of the subscription.
 *   $tid  The tid of the subscription.
 */
function nys_subscriptions_subscription_resubscribe_by_tid($email_address_key, $tid) {

  $num_updated = db_update('nys_subscriptions')
    ->fields(array(
      'unsubscribe_timestamp' => 0,
    ))
    ->condition('email_address_key', $email_address_key, '=')
    ->condition('tid', $tid, '=')
    ->execute();

}

/**
 * Gets the data in the nys_subscriptions table specified by $email_address_key.
 *
 * Argument.
 *   $email_address_key  The key of the subscriber.
 */
function nys_subscriptions_subscriber_lookup($email_address_key) {
  // Get the subscription.
  return db_query("SELECT * FROM `nys_subscriptions` WHERE `email_address_key` = :email_address_key LIMIT 1", array(":email_address_key" => $email_address_key))->fetchObject();

}

/**
 * Gets the data in the nys_subscriptions table specified by $email_address_key.
 *
 * Argument.
 *   $email_address_key  The key of the subscriber.
 */
function nys_subscriptions_subscriber_delete($email_address_key) {
  // Get the subscription.
  return db_query("DELETE FROM `nys_subscriptions` WHERE `email_address_key` = :email_address_key", array(":email_address_key" => $email_address_key));

}

/**
 * Gets the data in the nys_subscriptions table specified by $subscription_key.
 *
 * Argument.
 *   $subscription_key  The key of the subscription.
 */
function nys_subscriptions_subscription_lookup($subscription_key) {
  // Get the subscription.
  return db_query("SELECT * FROM `nys_subscriptions` WHERE `subscription_key` = :subscription_key LIMIT 1", array(":subscription_key" => $subscription_key))->fetchObject();

}

/**
 * Invalidates the publishing cache for the tid of the $subscription_key.
 *
 * Argument.
 *   $subscription_key  The key of the subscription.
 */
function nys_subscriptions_invalidate_topic_cache($subscription_key) {
  $subscription = nys_subscriptions_subscription_lookup($subscription_key);
  if ($subscription !== FALSE) {
    cache_clear_all('tid:' . $subscription->tid, 'cache_bill_notifications');
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Create Bill specific data.
 * Add more arguments and array elements as needed.
 *
 * Argument.
 *   why        -  why your receiving this 1=subscribe 2=voted.
 */
 function nys_subscriptions_get_bill_data($why) {
  // Check the input data.
  if (is_numeric($why)) {
    $bill_data_array = array("why" => $why);
    return json_encode($bill_data_array);
  }
  return FALSE;
}


/**
 * Nuclear SendGrid Unsubscribe Signup.
 *
 * Argument.
 *   $subscriber_key  The key of the subscriber not subscription.
 */
function nys_subscriptions_nuclear_sendgrid_unsubscribe($subscriber_key) {
  // To do add to SendGrid Global Unsubscribe list uing sendGrid API.
  $subscriber = nys_subscriptions_subscriber_lookup($subscriber_key);
  if ($subscriber !== FALSE) {
    // Valid subscriber.
    $subscriber_email = $subscriber->email;

    // See if there is already a global unsubscribe.
    if (nys_subscriptions_get_global_unsubscriber($subscriber_email) == FALSE) {
      // Add the email to the unsubscribe list.
    	$added_obj = nys_subscriptions_add_global_unsubscriber($subscriber_email);
    	if (isset($added_obj->recipient_emails) && is_array($added_obj->recipient_emails)) {
    	  $added_email = $added_obj->recipient_emails[0];
    	  if ($added_email == $subscriber_email) {
    			drupal_set_message("$added_email has been unsubscribed.");
          nys_subscriptions_subscriber_delete($subscriber_key);
          return TRUE;
    	  }
    	}
    	else {
    		drupal_set_message("There was a problam unsubscribing $subscriber_email.");
    	}

    }
    else {
      drupal_set_message("$subscriber_email was already unsubscribed.");
    }

  }
  return FALSE;
}

/**
 * Wrappers for sendgrid global unsubscribe.
 *
 * @see
 * https://sendgrid.com/docs/API_Reference/Web_API_v3/Suppression_Management/global_suppressions.html
 */

/**
 * Function to retrieve global unsubscribers.
 *
 * Arguments.
 * $start_time  Refers start of the time range in unix timestamp when an unsubscribe email was created (inclusive).
 * $end_time    Refers end of the time range in unix timestamp when an unsubscribe email was created (inclusive).
 * $limit       Limit the number of items
 * $offset      Paging offset
 * @return array of unsubscribers.
 */
function nys_subscriptions_get_global_unsubscribers($start_time = 0, $end_time = null, $limit = 1000, $offset = 0) {
  // If no end time provided use now.
  if(!isset($end_time)) {
    $end_time = time();
  }

  // Load key from variables and throw errors if not there.
  $key_secret = variable_get('sendgrid_integration_apikey', '');
  if (empty($key_secret)) {
    watchdog('sendgrid_integration_reports', t('Sendgrid Module is not setup with API key.'), array(), 'WATCHDOG_NOTICE', NULL);
    drupal_set_message(t('Sengrid Module is not setup with an API key.'), 'warning', TRUE);
    return FALSE;
  }

  // Set headers and create a Guzzle client to communicate with Sendgrid.
  $headers['Authorization'] = 'Bearer' . ' ' . $key_secret;
  $clienttest = new GuzzleHttp\Client(
    [
      'base_uri' => 'https://api.sendgrid.com/v3/',
      'headers' => $headers,
    ]
  );

  $query = array(
    'start_time' => $start_time,
    'end_time' => $end_time,
    'limit' => $limit,
    'offset' => $offset,
  );

  // Lets try and retrieve the browser statistics.
  try {
    $response = $clienttest->get('suppression/unsubscribes', ['query' => $query]);
    //$response = $clienttest->get('suppression/unsubscribes');
  }
  catch (GuzzleHttp\Exception\ClientException $e) {
    $code = filter_xss($e->getCode());
    watchdog('sendgrid_integration_reports', t('NYS Subscriptions module faield to recieve data. HTTP Error Code @errno'), array('@errno' => $code), 'WATCHDOG_ERROR', NULL);
    drupal_set_message(t('NYS Subscriptions  module faield to recieve data. See logs.'), 'error', TRUE);
    return FALSE;
  }
  // Sanitize return before using in Drupal.
  $body = $response->getBody();
  $data = json_decode($body);

  return $data;
}

/**
 * Function to add one or more global unsubscribers.
 *
 * Argument.
 * $subscriber_email can be a string containing a single email addres to unsubsubscribe.
 * $subscriber_email can be an array containing multiple email addreses to unsubsubscribe.
 * @return array of email addresses that were added to the unsubscribers list.
 */
function nys_subscriptions_add_global_unsubscriber($subscriber_email) {
  if (empty($subscriber_email)) {
    return FALSE;
  }

  // Load key from variables and throw errors if not there.
  $key_secret = variable_get('sendgrid_integration_apikey', '');
  if (empty($key_secret)) {
    watchdog('sendgrid_integration_reports', t('Sendgrid Module is not setup with API key.'), array(), 'WATCHDOG_NOTICE', NULL);
    drupal_set_message(t('Sengrid Module is not setup with an API key.'), 'warning', TRUE);
    return FALSE;
  }

  // Set headers and create a Guzzle client to communicate with Sendgrid.
  $headers['Authorization'] = 'Bearer' . ' ' . $key_secret;
  $clienttest = new GuzzleHttp\Client(
    [
      'base_uri' => 'https://api.sendgrid.com/v3/',
      'headers' => $headers,
    ]
  );


  // Lets try and retrieve the browser statistics.
  try {

  	if (is_string($subscriber_email)) {
  	  // If the $subscriber_email is a string wrap it in an array.
  	  $response = $clienttest->request('POST', 'asm/suppressions/global', array('json' => array('recipient_emails' => array($subscriber_email))));

  	}
  	elseif (is_array($subscriber_email)) {
  	  // If the $subscriber_email is an array feed it in dirctly.
  	  $response = $clienttest->request('POST', 'asm/suppressions/global', array('json' => array('recipient_emails' => $subscriber_email)));
  	}

  }
  catch (GuzzleHttp\Exception\ClientException $e) {
    $code = filter_xss($e->getCode());
    watchdog('sendgrid_integration_reports', t('NYS Subscriptions module faield to recieve data. HTTP Error Code @errno'), array('@errno' => $code), 'WATCHDOG_ERROR', NULL);
    drupal_set_message(t('NYS Subscriptions  module faield to recieve data. See logs.'), 'error', TRUE);
    return FALSE;
  }
  // Sanitize return before using in Drupal.
  $body = $response->getBody();
  $data = json_decode($body);

  return $data;
}

/**
 * Function to check if an email is in the list of global unsubscribers.
 *
 * Returns the email if $subscriber_email in the global unsubscribe list.
 * Returns FALSE if email is NOT in the global unsubscribe list.
 */
function nys_subscriptions_get_global_unsubscriber($subscriber_email) {

  // Load key from variables and throw errors if not there.
  $key_secret = variable_get('sendgrid_integration_apikey', '');
  if (empty($key_secret)) {
    watchdog('sendgrid_integration_reports', t('Sendgrid Module is not setup with API key.'), array(), 'WATCHDOG_NOTICE', NULL);
    drupal_set_message(t('Sengrid Module is not setup with an API key.'), 'warning', TRUE);
    return FALSE;
  }

  // Set headers and create a Guzzle client to communicate with Sendgrid.
  $headers['Authorization'] = 'Bearer' . ' ' . $key_secret;
  $clienttest = new GuzzleHttp\Client(
    [
      'base_uri' => 'https://api.sendgrid.com/v3/',
      'headers' => $headers,
    ]
  );

  // Lets try and retrieve the global subscriber.
  try {
    $response = $clienttest->get("asm/suppressions/global/$subscriber_email");
  }
  catch (GuzzleHttp\Exception\ClientException $e) {
    $code = filter_xss($e->getCode());
    watchdog('sendgrid_integration_reports', t('NYS Subscriptions module faield to recieve data. HTTP Error Code @errno'), array('@errno' => $code), 'WATCHDOG_ERROR', NULL);
    drupal_set_message(t('NYS Subscriptions  module faield to recieve data. See logs.'), 'error', TRUE);
    return FALSE;
  }

  // Sanitize return before using in Drupal.
  $body = $response->getBody();
  $data = json_decode($body);

  if (count(get_object_vars($data)) && property_exists($data, 'recipient_email')) {
    return $data->recipient_email;
  }

  return FALSE;

}

/**
 * Function to remove an email from the list of global unsubscribers. global unsubscribers.
 * @return array
 */
function nys_subscriptions_remove_global_unsubscriber($subscriber_email) {

  // Load key from variables and throw errors if not there.
  $key_secret = variable_get('sendgrid_integration_apikey', '');
  if (empty($key_secret)) {
    watchdog('sendgrid_integration_reports', t('Sendgrid Module is not setup with API key.'), array(), 'WATCHDOG_NOTICE', NULL);
    drupal_set_message(t('Sengrid Module is not setup with an API key.'), 'warning', TRUE);
    return FALSE;
  }

  // Set headers and create a Guzzle client to communicate with Sendgrid.
  $headers['Authorization'] = 'Bearer' . ' ' . $key_secret;
  $clienttest = new GuzzleHttp\Client(
    [
      'base_uri' => 'https://api.sendgrid.com/v3/',
      'headers' => $headers,
    ]
  );

  // Lets try and delete an item from the unsubscribe list
  try {
    $response = $clienttest->request('DELETE', "asm/suppressions/global/$subscriber_email");
  }
  catch (GuzzleHttp\Exception\ClientException $e) {
    $code = filter_xss($e->getCode());
    watchdog('sendgrid_integration_reports', t('NYS Subscriptions module failed to receive data. HTTP Error Code @errno'), array('@errno' => $code), 'WATCHDOG_ERROR', NULL);
    drupal_set_message(t('NYS Subscriptions module failed to receive data. See logs.'), 'error', TRUE);
    return FALSE;
  }

  $status_code = $response->getStatusCode();

  if ($status_code == 204) {
    return TRUE;
  }

  return FALSE;

}

