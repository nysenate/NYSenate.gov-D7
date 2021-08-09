<?php

/**
 * @file
 * Provides the bill form callback.
 */

/**
 * Generates the bill form.
 */
function nys_bills_bill_form($form, &$form_state, $node) {
  // See if the user just voted and load message form instead.
  $vote_results = nys_bills_just_voted($form, $form_state, $node);
  if ($vote_results !== FALSE && $vote_results['voted'] == TRUE) {
    return nys_bills_bill_voted_form($form, $form_state, $vote_results);
  }

  $form['#node'] = $node;
  $form['pass_thru_url'] = array(
    '#type' => 'hidden',
    '#default_value' => request_path(),
  );

  global $user;
  $form_info = array();

  // Initialize values just in case user is anonymous or out-of-state.
  $senator = t('the senator');
  $printno = t('this bill');

  // Check to see if the bill title exists to replace $printno.
  if (isset($node->title) && !empty($node->title)) {
    $printno = $node->title;
  }

  if (user_is_logged_in()) {

    // Only in-state users will have a senator assigned.
    if (!user_is_out_of_state()) {
      $senator_nid = user_get_senator_nid($user);
      if (!empty($senator_nid) && is_numeric($senator_nid)) {
        $sen_emw = entity_metadata_wrapper('node', $senator_nid);
        if ($sen_emw->__isset('field_last_name') && !empty($sen_emw->field_last_name->value())) {
          $senator = 'Sen. ' . $sen_emw->field_last_name->value();
        }
      }
    }

    // Set up EMW since the standard user object does not provide all the data
    // we need.
    $loc_emw = entity_metadata_wrapper('user', $user->uid);

    // User's address is an array of location data. We do this first to
    // leverage the foreach.
    if ($loc_emw->__isset('field_address') && is_array($loc_emw->field_address->value())) {
      foreach ($loc_emw->field_address->value() as $key => $value) {
        $form_info[$key] = $value;
      }
    }

    if ($loc_emw->__isset('field_first_name') && !empty($loc_emw->field_first_name->value())) {
      $form_info['first_name'] = $loc_emw->field_first_name->value();
    }
    if ($loc_emw->__isset('field_last_name') && !empty($loc_emw->field_last_name->value())) {
      $form_info['last_name'] = $loc_emw->field_last_name->value();
    }

    // This will overwrite the value we got from field_address if not empty.
    if (isset($user->mail) && !empty($user->mail)) {
      $form_info['email'] = $user->mail;
    }

    // If the user is already logged in, personal info fields should be hidden.
    $texttype = 'hidden';
    $form_markup = '<p>' . t('Would you like to include a private message to @senator on <span class=\"bill-widget-status\"></span> @printno?', array('@senator' => $senator, '@printno' => $printno)) . '</p>';
  }
  else {
    $texttype = 'textfield';
    $form_markup = t('<p>Please enter your contact information</p>');
  }

  if (user_is_out_of_state() && user_is_logged_in()) {
    $form_markup = '<p>' . t('Thank you for your participation.') . '</p>';
  }

  if (!empty($form_state['errors'])) {
    $form_markup = $form_state['errors'];
  }

  $form['#attributes']['class'] = array('registration-form');

  $form['header_text'] = array(
    '#markup' => $form_markup,
  );

  $form['first_name'] = array(
    '#type' => $texttype,
    '#title' => 'First Name',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 35,
  );

  if (!empty($form_info['first_name'])) {
    $form['first_name']['#default_value'] = $form_info['first_name'];
  }

  $form['last_name'] = array(
    '#type' => $texttype,
    '#title' => t('Last Name'),
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 35,
  );

  if (!empty($form_info['last_name'])) {
    $form['last_name']['#default_value'] = $form_info['last_name'];
  }

  $form['email'] = array(
    '#type' => $texttype,
    '#title' => t('Email Address'),
    '#required' => TRUE,
    '#description' => t('A valid email address is required.'),
    '#maxlength' => 254,
    '#size' => 30,
  );

  if (!empty($form_info['email'])) {
    $form['email']['#default_value'] = $form_info['email'];
  }

  $form['address'] = array(
    '#type' => ($texttype == 'hidden' ? $texttype : 'auto_address'),
    '#description' => 'Home address is used to determine the senate district in which you reside. Your support or opposition to this bill is then shared immediately with the senator who represents you.',
  );

  if (!user_is_logged_in()) {
    $form['options_header'] = [
      '#type' => 'markup',
      '#markup' => t('<hr><p>Optional services from the NY State Senate:</p>'),
    ];

    $form['subscribe'] = [
      '#type' => 'checkbox',
      '#default_value' => 1,
      '#description' => t('Send me alerts for this bill. I can unsubscribe at any time. <a href="/citizen-guide/bill-alerts">Learn more</a>.'),
    ];
  }

  $form['register'] = array(
    '#type' => 'checkbox',
    '#default_value' => 1,
    '#description' => t('<strong>Create an account</strong>. An <a href="/citizen-guide">account</a> allows you to officially support or oppose key legislation, sign petitions with a single click, and follow issues, committees, and bills that matter to you. When you create an account, you agree to this platform\'s <a href="/policies-and-waivers">terms of participation</a>.'),
  );

  if (user_is_logged_in()) {
    unset($form['register']);
  }
  else {
    // Senator NID as Sponsor in case out of state user.
    $form['senator'] = array(
      '#type' => 'hidden',
    );
  }

  // Vote value for entries passed on submit to help with creating message
  // subject.
  $form['vote_value'] = array(
    '#type' => 'hidden',
  );

  // Out of state users do not have a senator and therefore cannot send a
  // message.
  if (!user_is_logged_in() || !user_is_out_of_state()) {
    if (!user_is_logged_in()) {
      $form['message_header'] = [
        '#type' => 'markup',
        '#markup' => t('<hr><p>Include a custom message for your Senator? (Optional)</p>'),
      ];
    }

    $form['message'] = [
      '#type' => 'textarea',
      '#title' =>'',
      '#description' => t('Enter a message to your senator. Many New Yorkers use this to share the reasoning behind their support or opposition to the bill. Others might share a personal anecdote about how the bill would affect them or people they care about.'),
    ];

    if (user_is_logged_in()) {
      $submit_value = 'Send Message';
    }
    else {
      $submit_value = 'Submit Form';
    }

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => $submit_value,
      '#weight' => 15,
      '#attributes' => array('class' => array('c-btn--cta c-btn--cta__sign flag-wrapper flag-sign-bill')),
    );
  }

  honeypot_add_form_protection($form, $form_state, array('honeypot'));

  return $form;
}

/**
 * Generates the bill vote thank you message form.
 */
function nys_bills_bill_voted_form($form, &$form_state, $vote_results) {

  if ($vote_results === FALSE || $vote_results['voted'] == FALSE) {
    return $form;
  }

  $alert = 'Thank you for your participation.';

  $form['msg'] = array(
    '#markup' => '<div class="clearfix"></div><div class="l-messages"><div class="alert-box icon-before__petition"><div class="alert-box-message"><p>' . $alert . '</p></div></div></div>',
    '#weight' => 100,
  );

  $form['uid'] = array(
    '#type' => 'hidden',
    '#default_value' => $vote_results['uid'],
  );

  $form['vote_value'] = array(
    '#type' => 'hidden',
    '#default_value' => $vote_results['vote_value'],
  );

  // Adds the javascript to setup the bill and scroll users to the message.
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'nys_bills') . '/js/after_vote.js',
  );

  return $form;
}

/**
 * Vote Test -  Determines if you just voted on this bill.
 */
function nys_bills_just_voted($form, &$form_state, $node) {
  global $user;

  if ($user->uid == 0) {
    // Anonymous user.
    $vote_value = db_query("SELECT `value` FROM `votingapi_vote`, `nys_bills_anon` WHERE nys_bills_anon.vote_id = votingapi_vote.vote_id AND `bid` = :nid AND `vote_source` = :source AND votingapi_vote.timestamp > :recent",
                          array(
                            ':nid' => $node->nid,
                            ':source' => ip_address(),
                            ':recent' => time() - 4,
                          )
                            )->fetchField();

    if ($vote_value === '0') {
      return array('voted' => TRUE, 'uid' => $user->uid, 'vote_value' => '0');
    }
    elseif ($vote_value === '1') {
      return array('voted' => TRUE, 'uid' => $user->uid, 'vote_value' => '1');
    }
    elseif (empty($vote_value) == TRUE && $vote_value !== '0') {
      return FALSE;
    }

  }
  elseif ($user->uid > 0) {
    // Registered user.
    $vote_value = db_query("SELECT `value` FROM `votingapi_vote` WHERE `entity_id` = :entid AND `uid` = :uid AND `timestamp` > :recent",
                            array(
                              ':entid' => $node->nid,
                              ':uid' => $user->uid,
                              ':recent' => time() - 4,
                            )
                              )->fetchField();

    if ($vote_value === '0') {
      return array('voted' => TRUE, 'uid' => $user->uid, 'vote_value' => '0');
    }
    elseif ($vote_value === '1') {
      return array('voted' => TRUE, 'uid' => $user->uid, 'vote_value' => '1');
    }
    elseif (empty($vote_value) == TRUE && $vote_value !== '0') {
      return FALSE;
    }

  }

}

/**
 * Validates the bills form submission.
 */
function nys_bills_bill_form_validate($form, &$form_state) {
  nyslog(__FUNCTION__);

  // Detect a logged-in user's email address.
  global $user;
  if (isset($user->mail) && !empty($user->mail)) {
    $email = $user->mail;
  }
  else {
    $email = $form_state['values']['email'];
  }

  // Reset the return destination.
  $return_destination = NULL;
  if (!empty($form_state['values']['pass_thru_url'])) {
    $return_destination = '?destination=/' . $form_state['values']['pass_thru_url'];
  }

  // Validate the email address.
  if (!valid_email_address($email)) {
    form_set_error('email', t('Please enter a valid email address.'));
  }
  elseif (user_load_by_mail($email) && !user_is_logged_in()) {
    $href = '/user/login' . $return_destination;
    form_set_error('email', t('Our records show you already have an account. Please <a href="@href">log in</a> to continue', array('@href' => $href)));
  }
  elseif (!user_is_logged_in()) {
    nyslog('checking unauthenticated user');
    $node = $form['#node'];

    $existing_email = _nys_bills_select_single_anonymous_user(
      array('email' => $email, 'bid' => $node->nid),
      array('fid', 'message')
    );

    if (!empty($existing_email)) {
      nyslog('existing email');
      form_set_error('email', t('You have already supported or opposed this bill.'));
    }
  }
  nyslog('done checking, errors=' . var_export(form_get_errors(), 1));
  if (empty(form_get_errors())) {
    $form_state['validated'] = TRUE;
  }
}

/**
 * Saves the bills form submission.
 */
function nys_bills_bill_form_submit($form, &$form_state) {
  nyslog();

  // Need the global user object.
  global $user;

  // Set up some easy references for later.
  $node = $form['#node'];
  $values = $form_state['values'];
  $user_id = (int) (user_is_logged_in() ? $user->uid : 0);
  $user_mail = user_is_logged_in() ? $user->mail : $values['email'];
  $node_tid = (int) $node->field_bill_multi_session_root[LANGUAGE_NONE][0]['tid'];
  nyslog("Received values=\n" . var_export($values, 1));

  // Get the vote options.
  $vote_options = nys_bill_vote_get_options();

  $vote_index = $values['vote_value'];
  $vote_label = $vote_options[$vote_index];

  // Check for an existing vote.  The method differs based on login status.
  $anon_user_record = NULL;
  $the_vote = NULL;
  if (user_is_logged_in()) {
    // For users, check votingapi_vote with uid/entity_id/tag.
    $the_vote = votingapi_select_votes(array(
      'uid' => $user->uid,
      'entity_id' => $node->nid,
      'tag' => 'nys_bill_vote',
    ));

    // Note the user's senator's node id.
    $senator_nid = user_get_senator_nid($user);
  }
  else {
    // For non-users, check nys_bills_anon with email.
    $anon_user_record = _nys_bills_select_single_anonymous_user(
      array('email' => $values['email'], 'bid' => $node->nid)
    );

    // If no record was found, add a new entry.
    if (!$anon_user_record) {
      $new_record_id = _nys_bills_record_anonymous_user($node, $values);
      nyslog("anon record added: " . var_export($new_record_id, 1));
      $anon_user_record = _nys_bills_select_single_anonymous_user(
        array('sid' => $new_record_id)
      );
    }

    // If a record is found, then get the vote based on vote_id and entity_id.
    if ($anon_user_record->vote_id) {
      $the_vote = votingapi_select_votes(array(
        'vote_id' => $anon_user_record->vote_id,
        'entity_id' => $node->nid,
      ));
    }

    // Note the senator's node.
    $senator_nid = $anon_user_record->senator;

  }

  // Voting API returns an array.  We only need the first record.
  $the_vote = (count($the_vote) > 0) ? $the_vote[0] : NULL;
  nyslog("tried to discover existing vote, found:\n" . var_export($the_vote, 1));

  // If there is no existing vote, or the vote value differs from
  // the existing vote, record the new vote.
  nyslog("vote value={$the_vote['value']}, vote_index={$vote_index}");
  if (is_null($the_vote) || $the_vote['value'] != $vote_index) {
    $new_vote = nys_bill_vote_process_vote('node', $node->nid, $vote_index);
    nyslog("registered new vote=\n" . var_export($new_vote, 1));
  }

  // Commit the follow flag.  If it does not work, report.
  $bills_flag = flag_get_flag('follow_this_bill');
  if (!$bills_flag->flag('flag', $node->nid, $user, TRUE)) {
    $flag_errors = implode(' ', $bills_flag->get_errors());
    nyslog("could not flag! dumping ...\n" . var_export($flag_errors, 1));
    drupal_set_message($flag_errors, 'error');
    watchdog('nys_bills_form', $flag_errors);
  }

  // Array for return warnings/errors/success.
  $bills_flag_message = array();

  // Now deal with any message being passed.
  // Validation for the ability to send a message *SHOULD* have been
  // taken care of in nys_bills_bill_form_validate().  This process
  // is now restricted to logged in users only.
  if (user_is_logged_in() && !empty($values['message'])) {
    // The user must have a senator associated with their address.
    if (empty($senator_nid)) {
      $bills_flag_message[] = t('You must be a NY resident to send messages to a Senator.');
    }
    else {
      // Prepare array for sending a bills message.
      $message = array(
        'senator_nid' => $senator_nid,
        'author' => $user,
        'vote_label' => $vote_label,
        'values' => $values,
        'node' => $node,
      );

      $bills_flag_message[] = nys_bills_send_private_message($message);
    }
  }

  // Destroy anonymous session only.
  if (user_is_anonymous()) {
    nys_utils_regenerate_session();
  }

  // Finally, deal with anonymous users creating an account right now.
  // This will pass flow control over to the registration system and
  // out of the voting/flagging hooks.
  nyslog("check account creation");
  if (!user_is_logged_in() && !empty($values['register'])) {
    $registration_form_state = _nys_registration_create_form_object($values);

    $registration_form_state['values'] = $values;
    $registration_form_state['values']['agree_terms'] = TRUE;

    // Create the registration form, then call the registration SAGE
    // district lookup.
    drupal_form_submit('nys_registration_form_start', $registration_form_state);
    if (form_get_errors()) {
      nyslog("form errors=\n" . var_export(form_get_errors(), 1));
      ctools_object_cache_set('nys_registration', 'regform', $registration_form_state['object']);
      $form_state['redirect'] = 'registration/nojs/form/start';
    }
    else {
      nyslog("no form errors, invoking wizard_next");

      // Create new user object.
      nys_registration_wizard_next($registration_form_state);
      $new_user = _nys_registration_create_user($registration_form_state['object']);
      $user_id = $new_user->uid->value();

      // As a newly registered user, send a message to your senator.
      if (!empty($values['message'])) {
        // Prepare array to send message as an anon user that is registering.
        $message = array(
          'senator_nid' => $senator_nid,
          'author' => $new_user->value(),
          'vote_label' => $vote_label,
          'values' => $values,
          'node' => $node,
        );

        $bills_flag_message[] = nys_bills_send_private_message($message);
      }
    }
    nyslog("creation complete");
  }

  // If a subscription was requested, create it.
  if (!empty($values['subscribe']) && !user_is_logged_in()) {
    $data = [
      'email' => $user_mail,
      'tid' => $node_tid,
      'nid' => $node->nid,
      'uid' => $user_id,
      'why' => 2,
      'confirmed' => user_is_logged_in(),
    ];
    _real_nys_subscriptions_subscription_signup($data);
    $notice_msg = (isset($user_mail))
      ? 'Please click the confirmation link in the email that was just sent to ' . $user_mail
      : 'Your subscription has been processed';
    drupal_set_message($notice_msg);

    // Send a confirmation email only
    if (empty($values['register'])) {
      $info = ['tid' => $node_tid, 'nid' => $node->nid, 'email' => $user_mail];
      drupal_mail(
        'nys_subscriptions_confirmation',  // module
        'confirmation',                    // key
        '',                                // to (irrelevant with SendGrid API mail)
        language_default(),                // language
        ['confirmation' => $info]          // params
      );
    }
  }

  // If the form redirect is blocked due to ajax usage, but a redirect is
  // indicated, then use the ajax responder to create a proper redirect.
  nyslog('checking redirect');
  if ($form_state['no_redirect']) {
    ctools_add_js('ajax-responder');
    nyslog("Implementing ajax redirect to {$form_state['redirect']}");
    $redirect = [ctools_ajax_command_redirect($form_state['redirect'])];
    nyslog("Setting redirect to:\n" . var_export(ajax_render($redirect),1));
    print ajax_render($redirect);
    drupal_exit();
  }

  // If there are errors or message has been sent, convert to item list.
  if (!empty($bills_flag_message)) {
    $bills_items = theme('item_list', array(
      'items' => $bills_flag_message,
      'type' => 'ul',
    ));
    drupal_set_message($bills_items);
  }

  drupal_add_js(drupal_get_path('module', 'nys_bills') . '/js/form_validated.js');
}
