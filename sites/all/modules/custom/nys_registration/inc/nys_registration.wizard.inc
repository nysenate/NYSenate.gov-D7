<?php
/**
 * @file
 * This file includes code to process user registrations.
 */

/**
 * Page callback: Handles multistep precessing.
 *
 * @return string
 *   Multistep wizard output.
 *
 * @see nys_registration_menu()
 */
function nys_registration_form($js = NULL, $step = NULL) {
  global $user;

  if ($js) {
    ctools_include('modal');
    ctools_include('ajax');
    ctools_modal_add_js();
  }

  // Define array for CTools multi-step wizard.
  $form_info = array(
    'id' => 'nys_registration',
    'path' => "registration/" . ($js ? 'ajax' : 'nojs') . "/form/%step",
    'show trail' => FALSE,
    'show back' => TRUE,
    'show cancel' => FALSE,
    'show return' => FALSE,
    'next callback' => 'nys_registration_wizard_next',
    'finish callback' => 'nys_registration_wizard_finish',
    'cancel callback' => 'nys_registration_wizard_cancel',
    'forms' => array(
      'start' => array(
        'form id' => 'nys_registration_form_start',
        'title' => 'Registration',
      ),
      'second' => array(
        'form id' => 'nys_registration_form_second',
        'title' => 'Registration',
      ),
    ),
  );

  $object_id = 'regform';

  if (empty($step)) {
    // We reset the form when $step is NULL because that means they have
    // for whatever reason started over.
    nys_registration_cache_clear($object_id);
    $step = 'start';
  }

  // This automatically gets defaults if there wasn't anything saved.
  $object = nys_registration_cache_get($object_id);

  // Live $form_state changes.
  $form_state = array(
    'ajax' => $js,
    // Put our object and ID into the form state cache so we can easily find it.
    'object_id' => $object_id,
    'object' => &$object,
  );

  // Send this all off to our form. This is like drupal_get_form only wizardy.
  ctools_include('wizard');
  $form = ctools_wizard_multistep_form($form_info, $step, $form_state);
  $output = drupal_render($form);

  if ($js) {
    // If javascript is active, we have to use a render array.
    $commands = array();
    if ($output === FALSE || !empty($form_state['complete'])) {
      // Dismiss the modal.
      _nys_registration_create_user($object);
      $commands[] = ctools_modal_command_dismiss();
    }
    elseif (!empty($form_state['cancel'])) {
      // If cancelling, return to the activity.
      $commands[] = ctools_modal_command_dismiss();
      $commands[] = ctools_ajax_command_reload();
    }
    else {
      $commands = ctools_modal_form_render($form_state, $output);
    }
    print ajax_render($commands);
  }
  else {
    if ($output === FALSE || !empty($form_state['complete'])) {
      _nys_registration_create_user($object);
      nys_registration_cache_clear($object_id);
      drupal_goto('<front>');
    }
    elseif (!empty($form_state['cancel'])) {
      nys_registration_cache_clear($object_id);
      drupal_goto('<front>');
    }
    else {
      return $output;
    }
  }
}

/**
 * Generates first form.
 *
 * @ingroup forms
 */
function nys_registration_form_start($form, &$form_state) {
  $help_text = '';

  $query_paramters = drupal_get_query_parameters();
  $title_text = 'Create Profile';

  // Handle registration via /find-my-senator.
  if (arg(4) == 'find-my-senator') {
    $title_text = 'Find your Senator';
    $help_text = "Create a profile using the form below to find the ";
    $help_text .= "NY State senator who represents you. If you would like to find your senator ";
    $help_text .= "without creating a profile, please use <a href=\"/find-my-senator\">this form</a>.";
  }

  // Handle registration via /follow-issue.
  if (arg(4) == 'follow-issue') {
    $title_text = t('Follow Issues');
    $help_text = t('To follow the issues facing NY State, please create a profile using the form below.');
    if (isset($query_paramters['issue'])) {
      $issue = taxonomy_term_load($query_paramters['issue']);
      if ($issue->vid == '4') {
        $title_text =  t('Follow Issue: ') . $issue->name;
        $help_text = t('To follow this issue, please create a profile using the form below.');
        // $destination_id = $issue; To be used for getting user back to issue eventually.
      }
    }
  }

  // Handle registration via /message-senator.
  if (arg(4) == 'message-senator') {
    $title_text = 'Message a Senator';
    $help_text = 'To send a message to any NY State Senator, please creating a profile or <a href="/user/login">login</a>.';
    if (isset($query_paramters['senator'])) {
      $senator = node_load($query_paramters['senator']);
      if ($senator !== FALSE && $senator->type == 'senator' && ($senator->field_active['und'][0]['value'] ?? '0') == '1') {
        $title_text = 'Message Sen. ' . $senator->title;
        $help_text = t('To send a message to NY State Sen. ') . $senator->field_last_name['und'][0]['value'];
        $help_text .= t(', please create a profile using the form below or <a href="/user/login">login</a>.');
      }
    }
  }

  $form['#attributes']['class'] = array('registration-form');
  $form['registration_teaser'] = array(
    '#markup' => '<div class="c-block c-login">
                  <h2 class="nys-title">' . ($title_text ?? '') . '</h2>
                  <p>'. ($help_text ?? '') .'</p>',
    '#weight' => -100,
  );

  $form['first_name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('First name'),
    '#default_value' => isset($form_state['object']->first_name) ? $form_state['object']->first_name : '',
    '#required'      => TRUE,
    '#maxlength' => 50
  );

  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#default_value' => isset($form_state['object']->last_name) ? $form_state['object']->last_name : '',
    '#required' => TRUE,
    '#maxlength' => 50
  );

  $form['email'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Email Address'),
    '#default_value' => isset($form_state['object']->email) ? $form_state['object']->email : '',
    '#required'      => TRUE,
    '#prefix' => '<div class="c-block--full"><div class="c-block--left">',
    '#suffix' => '</div>',
  );
  $form['note'] = array(
    '#markup' => '<div class="c-block--right"><div class="c-block--field-desc c-block--field--desc-email">A valid email address is required in order to confirm your account.</div></div></div>',
  );
  $form['address'] = array(
    '#type' => 'auto_address',
  );

  $form['agree_terms'] = array(
    '#type' => 'checkbox',
    '#title' => t('Please agree to the New York State Senate\'s terms of participation before creating an account. You can read about our <a href="/policies-and-waivers">Privacy Policy</a> and <a href="/policies-and-waivers">Terms of Participation</a> for further details.'),
    '#default_value' => isset($form_state['object']->agree_terms) ? $form_state['object']->agree_terms : 1,
    '#required' => TRUE,
    '#prefix' => '<div class="c-block--full">',
    '#suffix' => '</div></div>',
    '#attributes' => array('checked' => 'checked'),
  );

  $form['#validate'][] = '_nys_registration_form_validation';
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
  return $form;
}

/**
 * Validation for the user registration form.
 */
function _nys_registration_form_validation($form, &$form_state) {
  nyslog();
  $form_state['object'] = _nys_registration_map_object_values($form_state['values']);

  $mail = $form_state['values']['email'];
  $first_name = $form_state['values']['first_name'] ?? '';
  $last_name = $form_state['values']['last_name'] ?? '';

  // Potential fix for russian accounts, disallow any email with .ru domain.
  $is_ru = (substr($mail, -3) == '.ru');
  // Potential fix for russian accounts, disallow any info with cryllic characters
  $has_cryllic = (boolean) preg_match('/[\p{Cyrillic}]/u', $mail . $first_name . $last_name);
  // Potential fix for russian accounts, disallow any info with non-Latin characters
  // $has_non_lating = (boolean) preg_match('/[^\\p{Common}\\p{Latin}]/u', $mail . $first_name . $last_name);

  if (!valid_email_address($mail) || $is_ru || $has_cryllic) {
    form_set_error('email', t('Please Enter a valid email address.'));
  }

  $check = db_select('users', 'u')
    ->fields('u', array('uid'))
    ->condition('mail', $mail, '=')
    ->execute()
    ->fetchField();

  if ($check != '') {
    form_set_error('mail', t('The email address you entered is already in use. <a href="@password">Have you forgotten your password?</a>', array('@password' => url('user/password', array('query' => array('name' => $form_state['values']['email']))))));
  }

  if (!_nys_registration_validate_zipcode($form_state['object']->postal_code)) {
    form_set_error('postal_code', t('Please enter a valid zip code.'));
  }

}

/**
 * Validates zipcodes.
 */
function _nys_registration_validate_zipcode($zipcode) {
  return preg_match('/^[0-9]{5}([- ]?[0-9]{4})?$/', $zipcode);
}

/**
 * Handles submit of first form.
 */
function nys_registration_form_start_submit($form, &$form_state) {
  $fields = array('email', 'first_name', 'last_name', 'street',
    'additional', 'city', 'state', 'postal_code', 'agree_terms');
  foreach ($fields as $one_field) {
    if (array_key_exists($one_field, $form_state['values']) &&
    $form_state['values'][$one_field]) {
      $form_state['object']->{$one_field} = $form_state['values'][$one_field];
    }
  }
}

/**
 * Generates second form.
 *
 * @ingroup forms
 */
function nys_registration_form_second($form, &$form_state) {
  // If district is not set.
  if (isset($form_state['object']->has_district) && $form_state['object']->has_district === FALSE) {

    $form['account']['intro'] = array(
      '#markup' => '<div class="c-block c-login"><h2 class="nys-title">There was a problem finding your district.</h2><p>If you are from outside NY State, please continue by selecting "FINISH". If not, go back and ensure you entered your NY address correctly.</p></div>',
      '#weight' => 0
    );

  // If district is set, but no senator can be found for the district.
} elseif (!empty($form_state['object']->has_district) && $form_state['object']->has_district === TRUE && isset($form_state['object']->has_senator) && $form_state['object']->has_senator === FALSE) {
    // TODO add a logging action so that the address fields are captured and
    // sent to the SAGE team.
    $form['account']['intro'] = array(
      '#markup' => '<div class="c-block c-login"><h2 class="nys-title">' . t('You are in Senate District ' . $form_state['object']->district_number) . '</h3> <p>We were able to find the NY State Senate district in which you reside, but we could not match you to a senator.</h2><p>Your district seat may be vacant at the moment, or we may be experiencing technical difficultues. Please contact <a href="/contact">NYSenate.gov\'s Support Team</a> with questions or concerns.</p></div>',
      '#weight' => 0,
    );

    // Display district and senator.
  }
  else {
    $current_duties = !empty($form_state['object']->senator->field_current_duties) ? $form_state['object']->senator->field_current_duties[LANGUAGE_NONE][0]['value'] : '';

    $form['senator'] = array(
      '#markup' => '
        <div class="c-block c-login">
        <h3 class="nys-title">' . t('This address is in Senate District ') . ($form_state['object']->district_number ?? '') . '</h3>
        <p>' . t('If your address information below is correct, select "FINISH" to complete the sign-up process and connect with your Senator. If not, please select "BACK"') . '</p>
        <div class="c-login-left" >
        <div class="nys-senator--thumb" ><img src = "/' . drupal_get_path('theme', 'nysenate') . '/images/default-avatar.png" width = "160" height = "160" ></div >
          <ul class="c-user--info" >
            <li >' . ($form_state['object']->first_name ?? '') . ' ' . ($form_state['object']->last_name ?? '') . '</li >
            <li >' . ($form_state['object']->email ?? '') . '</li >
            <li >' . ($form_state['object']->street ?? '') . ' ' . ($form_state['object']->additional ?? '') . '</li >
            <li >' . ($form_state['object']->city ?? '') . ', ' . ($form_state['object']->state ?? '') . ' ' . ($form_state['object']->postal_code ?? '') . '</li >
          </ul >
        </div >
        <div class="c-login-right" >
          <div class="nys-senator--thumb" > ' . _nyss_img(@$form_state['object']->senator->field_image_headshot[LANGUAGE_NONE][0]['uri'], '160x160', '') . '</div >
          <ul class="c-senator--info" >
            <li > Your Senator </li >' .
        '<li >' . ($form_state['object']->senator->title ?? '') . '</li >' .
        '<li >' . ($current_duties ?? '') . '</li > ' .
        '<li >NY Senate District ' . ($form_state['object']->district_number ?? '') . ' (<a href = "/district/' . ($form_state['object']->district_number ?? '') . '" > Map</a >)</li >
        </ul >
        </div > '
      );
  }

  return $form;
}

/**
 * Clears the wizard cache.
 *
 * @param int $id
 *   Cache id.
 */
function nys_registration_cache_clear($id) {
  ctools_include('object-cache');
  ctools_object_cache_clear('nys_registration', $id);
}

/**
 * Stores our little cache so that we can retain data from form to form.
 *
 * @param int $id
 *   Cache id.
 * @param object $object
 *   Object with form values.
 */
function nys_registration_cache_set($id, $object) {
  ctools_include('object-cache');
  ctools_object_cache_set('nys_registration', $id, $object);
}

/**
 * Gets the current object from the cache, or default.
 *
 * @param int $id
 *   Cache id.
 *
 * @return object
 *   Cache with stored stuff.
 */
function nys_registration_cache_get($id) {
  ctools_include('object-cache');
  $object = ctools_object_cache_get('nys_registration', $id);
  if (!$object) {
    // Create a default object.
    $object = new stdClass;
  }

  return $object;
}

/**
 * Handles the 'next' click on the add/edit pane form wizard.
 *
 * All we need to do is store the updated pane in the cache.
 *
 * @param array $form_state
 *   Form state.
 */
function nys_registration_wizard_next(&$form_state) {

  // If an address is available, do a SAGE lookup.
  if (isset($form_state['object']->street)) {
    $data = array(
      'street' => $form_state['object']->street,
      'additional' => $form_state['object']->additional,
      'city' => $form_state['object']->city,
      'province' => $form_state['object']->state,
      'postal_code' => $form_state['object']->postal_code,
      'email' => $form_state['object']->email,
    );

    // Fail by default.
    $form_state['object']->has_district = FALSE;
    $form_state['object']->has_senator  = FALSE;
    $form_state['object']->district_id = 0;
    $form_state['object']->district_number = 0;

    // Call SAGE.
    $params = nys_sage_prep_params($data);
    $response = nys_sage_call_api($params);

    // If a district assignment is found, save it with the user.
    if ($response->acceptableMatch) {
      // Load the district's taxonomy id.
      $district_tid = nys_utils_lookup_district_tid($response->districts->senate->district);

      // Record it in the originating form data.
      $form_state['object']->street = $response->address->addr1;
      $form_state['object']->additional = $response->address->addr2;
      $form_state['object']->city = $response->address->city;
      $form_state['object']->postal_code = $response->address->zip5;

      // If there's a district assigned, record it and load the senator.
      if ($district_tid) {
        $form_state['object']->has_district = (boolean) $district_tid;
        $form_state['object']->district_id = $district_tid;
        $form_state['object']->district_number = $response->districts->senate->district;

        // Load the senator.
        $form_state['object']->senator = nys_utils_get_senator_from_district_id($district_tid);
        $form_state['object']->has_senator = (boolean) $form_state['object']->senator;
      }
    }
  }

  nys_registration_cache_set($form_state['object_id'], $form_state['object']);
}

/**
 * Handles the 'finish' click on teh add/edit pane form wizard.
 *
 * All we need to do is set a flag so the return can handle adding
 * the pane.
 */
function nys_registration_wizard_finish(&$form_state) {
  $form_state['complete'] = TRUE;
}

/**
 * Handles the 'cancel' click on the add/edit pane form wizard.
 */
function nys_registration_wizard_cancel(&$form_state) {
  $form_state['cancel'] = FALSE;
}

/**
 * Creates a new nysenate.gov user.
 */
function _nys_registration_create_user($object) {
  // If $object is empty and theres no email address, no point in continuing.
  if (empty($object->email)) {
    return FALSE;
  }

  $password = user_password(8);
  $name = nys_registration_unique_username($object->first_name . '_' . $object->last_name);
  $address = array(
    'street' => $object->street,
    'additional' => $object->additional,
    'postal_code' => $object->postal_code,
    'city' => $object->city,
    'province' => $object->state,
    'is_primary' => 1,
  );

  $new_user         = entity_create('user', array());
  $new_user->name   = $name;
  $new_user->mail   = $object->email;
  $new_user->init   = $object->email;
  $new_user->pass   = user_hash_password($password);
  $new_user->status = 1;

  // Set district for the user?
  $new_user->roles = drupal_map_assoc(array(DRUPAL_AUTHENTICATED_RID));

  $new_user = entity_metadata_wrapper('user', $new_user);

  if ($new_user) {
    $new_user->field_first_name = $object->first_name;
    $new_user->field_last_name = $object->last_name;
    $new_user->field_address = $address;
    $new_user->field_district = $object->district_id;
    $new_user->field_agree_to_terms = $object->agree_terms;
  }

  $new_user->save();
  $uid = $new_user->getIdentifier();

  nys_registration_activation_email($uid);

  return $new_user;
}

/**
 * Invokes drupal_mail() via _user_mail_notify().  Sends the account verification
 * email.
 *
 * @param object $uid
 *    Drupal user ID.
 */
function nys_registration_activation_email($uid) {
  $account = user_load($uid);
  if ($account) {
    $op = 'register_no_approval_required';
    $status = _user_mail_notify($op, $account);
    // Notify user of newly created account.
    if ($status) {
      drupal_set_message(t('Success! Your NY State Senate Account has been created. You can activate your account by visiting the URL that was just sent to the email address you provided.'), 'status', FALSE);
    }
  }
}

/**
 * Generate Unique Username.
 *
 * @param string $name
 *    Users first and last name.
 * @param int $uid
 *    Drupal user ID.
 */
function nys_registration_unique_username($name, $uid = 0) {
  // Strip illegal characters.
  $name = preg_replace('/[^\x{80}-\x{F7} a-zA-Z0-9@_.\'-]/', '', $name);
  // Strip leading and trailing spaces.
  $name = trim($name);

  // Convert any other series of spaces to a single underscore.
  $name = preg_replace('/ +/', '_', $name);

  // If there's nothing left use a default.
  $name = ('' === $name) ? t('user') : $name;

  // Truncate to reasonable size.
  $name = (drupal_strlen($name) > (USERNAME_MAX_LENGTH - 10)) ? drupal_substr($name, 0, USERNAME_MAX_LENGTH - 11) : $name;

  // Iterate until we find a unique name.
  $i = 0;

  do {
    $new_name = empty($i) ? $name : $name . '_' . $i;
    $found = db_query_range("SELECT uid from {users} WHERE uid <> :uid AND name = :name", 0, 1, array(':uid' => $uid, ':name' => $new_name))->fetchAssoc();
    $i++;
  } while (!empty($found));

  return $new_name;
}

/**
 * Generates and returns an nys_registration wizard form object.  Any values
 * passed are used to seed the object.
 *
 * @param $values
 *   Array of form values used to seed the object.  Valid elements are:
 *   first_name, last_name, email, addr_street, addr_opt, addr_city,
 *   addr_state, addr_zip, agree_terms.  The agree_terms value is force-
 *   typed to boolean.  All other values are assigned unmodified.
 * @param bool|string $object_id
 *   An optional ID to assign the object's cache storage record.  If
 *   not provided, defaults to 'regform'.
 * @return form state array
 */
function _nys_registration_create_form_object($values, $object_id = FALSE) {
  nyslog();
  // Create a default registration form for SAGE validation & user creation.
  $registration_form_state = form_state_defaults();

  // Set the object id, if provided.
  $object_id = (string) ($object_id === FALSE ? 'regform' : $object_id);

  // Make sure the ctools cache is clear.
  nys_registration_cache_clear($object_id);

  // Create the mapped-value object.  This is necessary because of changes
  // to field names on the form which were not propagated to the module
  // code.
  $object = _nys_registration_map_object_values($values);

  // Add the object, object_id to the form.  Default to no ajax.
  $registration_form_state += array(
    'ajax' => 'nojs',
    'object_id' => $object_id,
    'object' => &$object,
  );

  // Build the form.
  drupal_retrieve_form('nys_registration_form_start', $registration_form_state);

  return $registration_form_state;
}

/**
 * This function translates from the new, standardized form field names into
 * the legacy field names expected by nys_registration.  This is necessary
 * until refactoring rids us of this plague.
 *
 * @param $values Submitted/cached form values.
 *
 * @return object A new object, to be used as $values['object'], with the
 *                translated field names.
 */
function _nys_registration_map_object_values($values) {
  // A mapping from common form control names to object names.
  $map = array(
    'first_name'   => 'first_name',
    'last_name'    => 'last_name',
    'email'        => 'email',
    'street'       => 'addr_street',
    'additional'   => 'addr_opt',
    'city'         => 'addr_city',
    'state'        => 'addr_state',
    'postal_code'  => 'addr_zip',
    'agree_terms'  => 'agree_terms',
  );

  $object = new stdClass();

  // Assign all passed values using the above map.
  foreach ($map as $key => $val) {
    $tval = array_key_exists($val, $values) ? $values[$val] : '';
    $object->{$key} = $tval;
  }

  // Make sure agree_terms is a boolean value.
  $object->agree_terms = (boolean) $object->agree_terms;

  return $object;
}
