<?php
/**
 * @file
 * Provides the petition form callback.
 */

/**
 * Generates the petition form.
 *
 * @param array $form
 *   Drupal input form array.
 * @param array $form_state
 *   Drupal form state.
 * @param object $node
 *   Petition node object.
 *
 * @return array
 *   Petition form.
 */
function nys_petitions_petition_form($form, &$form_state, $node) {
  $form['#node'] = $node;

  $form['#attributes']['class'] = array('registration-form');

  $form['first_name'] = array(
    '#type' => 'textfield',
    '#title' => 'First Name',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 35,
  );

  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 35,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Address'),
    '#required' => TRUE,
    '#description' => t('A valid email address is required in order to confirm your account.'),
    '#maxlength' => 254,
    '#size' => 30,
  );

  $form['address'] = array(
    '#type' => 'auto_address',
  );

  /*  $form['addr_street'] = array(
      '#type' => 'textfield',
      '#title' => 'Street Address',
      '#required' => TRUE,
      '#description' => t('Your valid home address is used to determine which NY State Senator Represents you.'),
      '#maxlength' => 1023,
      '#size' => 40,
    );

    $form['addr_opt'] = array(
      '#type' => 'textfield',
      '#title' => t('Apt/Suite/Floor (Optional)'),
      '#maxlength' => 1023,
      '#size' => 12,
    );

    $form['addr_city'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      '#required' => TRUE,
      '#maxlength' => 255,
      '#size' => 35,
    );

    $form['addr_state'] = array(
      '#type' => 'textfield',
      '#title' => t('State'),
      '#required' => TRUE,
      '#maxlength' => 255,
      '#size' => 35,
    );

    $form['addr_zip'] = array(
      '#type' => 'textfield',
      '#title' => t('Postal Code'),
      '#required' => TRUE,
      '#maxlength' => 5,
      '#size' => 5,
    );
  */
  $form['register'] = array(
    '#type' => 'checkbox',
    '#default_value' => 1,
    '#description' => t('<strong>Create an account</strong>. An <a href="/why-you-should-create-account">account</a> allows you to sign petitions with a single click, officially support or oppose key legislation, and follow issues, committees, and bills that matter to you. When you create an account, you agree to this platform\'s <a href="/policies-and-waivers">terms of participation</a>.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Sign the Petition',
    '#weight' => 15,
    '#attributes' => array('class' => array('c-btn--cta c-btn--cta__sign flag-wrapper flag-sign-petition')),
    '#ajax' => array(
      'callback' => 'nys_petitions_petition_submit',
      'wrapper' => 'nys-petitions-petition-form',
      'method' => 'replace',
      'effect' => 'slide',
    ),
  );

  // Removing all honeypot restrictions on the bill voting form TEMPORARILY.
  // 2020-08-19 SBB.  The time restrictions put in place for the registration
  // form are preventing users from voting.
  /*
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
  */

  return $form;
}

/**
 * Validates the petition submission.
 *
 * @param array $form
 *   Drupal input form array.
 * @param array $form_state
 *   Drupal form state.
 */
function nys_petitions_petition_form_validate($form, &$form_state) {
  nyslog();

  // Need the global user object.
  global $user;

  // Set up some easy references for later.
  $node = $form['#node'];
  $values = $form_state['values'];

  // Form validation is only for unregistered users.
  if (!user_is_logged_in()) {
    // If email address is not valid, cut the validation short.
    if (!valid_email_address($form_state['values']['email'])) {
      form_set_error('email', t('Please enter a valid email address.'));
    }
    // Check for an existing user account registered with this
    // email address, or an existing signature.
    else {
      // Look for an existing user.
      $existing_user = user_load_by_mail($values['email']);

      // If one is found, request a log in before continuing.
      if ($existing_user) {
        form_set_error('email', t('Your email is already registered.  Please log in to continue.'));
      }
      // Otherwise, look for existing anonymous signatures.
      else {
        $query = 'SELECT COUNT(email) FROM {nys_petitions} WHERE email = :e AND pid = :n';
        $found_email = (int) db_query($query, array(
          ':e' => $values['email'],
          ':n' => $node->nid,
        ))
          ->fetchCol()[0];

        // If there is an existing signature, record the form error.
        if ($found_email) {
          nyslog("setting error for duplicate signing\n" . var_export($found_email, 1));
          form_set_error('email', t('You have already signed this petition.'));
        }
      }
    }
  }
  // Validation for registered users means checking for a duplicate signature.
  else {
    // Get the appropriate flag through flagging API.
    $petition_flag = flag_get_flag('sign_petition');

    if ($petition_flag->is_flagged($node->uid, $user->uid)) {
      form_set_error('email', t('You have already signed this petition.'));
    }
  }

  if (empty(form_get_errors())) {
    $form_state['validated'] = TRUE;
  }
}

/**
 * Saves the petition submission.
 *
 * @param array $form
 *   Drupal input form array.
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 *   Result form array.
 */
function nys_petitions_petition_submit($form, &$form_state) {
  nyslog();

  // If validation failed, return the error-laden form.
  if ($form_state['validated'] !== TRUE) {
    return $form;
  }

  // Ensure some utility items have been included.
  ctools_include('ajax');
  ctools_include('object-cache');
  ctools_include('nys_registration.wizard', 'nys_registration', 'inc');

  // Need the global user object.
  global $user;

  // Set up some easy references for later.
  $node = $form['#node'];
  $values = $form_state['values'];
  nyslog("Received values=\n" . var_export($values, 1));

  // Create the flag through flagging API.
  $petition_flag = flag_get_flag('sign_petition');

  $anon_insert_id = NULL;
  if (!user_is_logged_in()) {
    $anon_insert_id = _nys_petitions_record_anonymous_user($node, $values);
  }

  // Commit the petition flag.  If it does not work, back out the
  // nys_petitions row and report.
  if (!$petition_flag->flag('flag', $node->nid, $user, TRUE)) {
    $flag_errors = implode(' ', $petition_flag->get_errors());
    drupal_set_message($flag_errors, 'error');
    watchdog('nys_petitions', $flag_errors);
    // Remember to delete the anonymous row.
    if (!user_is_logged_in() && $anon_insert_id) {
      db_delete('nys_petitions')->condition('sid', $anon_insert_id)->execute();
    }
  }

  // Flagging contrib module will "convert" all anonymous flags to the uid of
  // a newly logged in user based on session ID.  Since we are only allowing
  // a single flag to be converted, we need to recycle the session and get
  // a new session id, if the user is anonymous.
  if (!user_is_logged_in()) {
    nys_utils_regenerate_session();
  }

  // If an anonymous user selected "Create an Account", pass the form
  // through nys_registration.
  if (!user_is_logged_in() && !empty($values['register'])) {
    nyslog('Begin registration form for anonymous user');

    // Get a new registration form.
    $registration_form_state = _nys_registration_create_form_object($values);
    $registration_form_state['values'] = $values;
    $registration_form_state['values']['agree_terms'] = TRUE;

    // Create the registration form, then call the registration
    // SAGE district lookup.
    drupal_form_submit('nys_registration_form_start', $registration_form_state);
    if (form_get_errors()) {
      nyslog("form errors=\n" . var_export(form_get_errors(), 1));
      ctools_object_cache_set('nys_registration',
        $registration_form_state['object_id'],
        $registration_form_state['object']
      );
      $form_state['redirect'] = 'registration/nojs/form/start';
    }
    else {
      nyslog("no errors");
      $form_state['redirect'] = 'registration/nojs/form/second';
      nys_registration_wizard_next($registration_form_state);
    }

    // If the form redirect is blocked due to ajax usage, then use the ajax
    // responder mechanism to effect an ajax redirect.
    if ($form_state['no_redirect']) {
      nyslog('implementing ajax redirect');
      ctools_add_js('ajax-responder');
      print ajax_render(array(ctools_ajax_command_redirect($form_state['redirect'])));
      drupal_exit();
    }
  }

  $flag_message = '<div class="l-messages"><div class="alert-box icon-before__petition"><div class="alert-box-message"><p>' . $petition_flag->flag_message . '</p></div></div></div>';
  $message['submit']['#markup'] = $petition_flag ? $flag_message : t('Unable to process form. Please try again later.');
  return $message;
}

/**
 * Record anonymous user information for submitted a petition signatures.
 *
 * @param array $node
 *   The petition node object receiving the signature.
 * @param array $values
 *   The $form_state['values'] array of the form submission.
 *
 * @return bool|int
 *   Returns the auto-increment value of the newly inserted record,
 *   or false if the current user is logged in (i.e., not anonymous).
 */
function _nys_petitions_record_anonymous_user($node, $values) {
  nyslog();

  // If this user is logged in, exit.
  global $user;
  if ($user->uid) {
    return FALSE;
  }

  // Some includes to support this process.
  ctools_include('ajax');
  ctools_include('object-cache');
  ctools_include('nys_registration.wizard', 'nys_registration', 'inc');

  // Create a default registration form ...
  $registration_form_state = _nys_registration_create_form_object($values);
  $registration_form_state['object']->agree_terms = TRUE;
  $registration_form_state['object']->fbuid       = NULL;

  // ... and call SAGE district lookup.
  nys_registration_wizard_next($registration_form_state);

  // Retrieve the relevant senator/district information.
  $senator = !empty($registration_form_state['object']->senator->nid) ? $registration_form_state['object']->senator->nid : NULL;
  $district_id = !empty($registration_form_state['object']->district_id) ? $registration_form_state['object']->district_id : NULL;
  $district_number = !empty($registration_form_state['object']->district_number) ? $registration_form_state['object']->district_number : 0;

  // Insert the new anonymous record into nys_petitions.
  nyslog("Inserting into nys_petitions");
  // Insert the new row into nys_petitions.
  $anon_insert = db_insert('nys_petitions')
    ->fields(array(
      'pid' => $node->nid,
      'fid' => 0,
      'session_id' => flag_get_sid(0, TRUE),
      'email' => $values['email'],
      'first_name' => $values['first_name'],
      'last_name' => $values['last_name'],
      'addr_street' => $values['addr_street'],
      'addr_opt' => $values['addr_opt'],
      'addr_city' => $values['addr_city'],
      'addr_state' => $values['addr_state'],
      'addr_zip' => $values['addr_zip'],
      'senator' => $senator,
      'district_id' => $district_id,
      'district_number' => $district_number,
      'timestamp' => REQUEST_TIME,
    ))
    ->execute();
  nyslog("inserted, return=\n".var_export($anon_insert,1));

  // Return the new record PK.
  return $anon_insert;
}