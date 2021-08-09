<?php

/**
 * @file
 * User menu callbacks for Privatemsg.
 */


/**
 * Returns a form which handles and displays thread actions.
 *
 * Additional actions can be added with the privatemsg_thread_operations hook.
 * It is also possible to extend this form with additional buttons or other
 * elements, in that case, the definitions in the above hook need no label tag,
 * instead, the submit button key needs to match with the key of the operation.
 *
 * @see hook_privatemsg_thread_operations()
 *
 * @return
 *   The FAPI definitions for the thread action form.
 */
function _privatemsg_action_form($type) {
  $form = array(
      '#prefix'      => '<div class="container-inline">',
      '#suffix'      => '</div>',
      '#weight'      => -5,
  );
  // Display all operations which have a label.
  $operations = module_invoke_all('privatemsg_thread_operations', $type);
  drupal_alter('privatemsg_thread_operations', $operations, $type);
  foreach ($operations as $operation => $array) {
    if (!empty($array['button'])) {
      $form[$operation] = array(
        '#type'   => 'submit',
        '#value'  => $array['label'],
        '#ajax' => array(
          'callback' => 'privatemsg_list_js',
          'wrapper' => 'privatemsg-list-form',
          'effect' => 'fade',
        ),
      );
    }
    elseif (isset($array['label'])) {
      $options[$operation] = $array['label'];
    }
  }
  if (!empty($options)) {
    array_unshift($options, t('Actions...'));
    $form['operation'] = array(
      '#type'          => 'select',
      '#options'       => $options,
      '#ajax' => array(
        'callback' => 'privatemsg_list_js',
        'wrapper' => 'privatemsg-list-form',
        'effect' => 'fade',
      ),
      '#executes_submit_callback' => TRUE,
    );
    $form['submit'] = array(
      '#type'       => 'submit',
      '#value'      => t('Execute'),
      '#attributes' => array('class' => array('form-item')),
      '#states' => array(
        'visible' => array(
          // This is never true, button is always hidden when JS is enabled.
          ':input[name=operation]' => array('value' => 'fake'),
        ),
      ),
    );
  }
  return $form;
}

/**
 * AJAX callback to return the form again.
 */
function privatemsg_list_js($form, $form_state) {
  return $form['updated'];
}

function privatemsg_delete($form, $form_state, $thread, $message) {
  $form['pmid'] = array(
    '#type' => 'value',
    '#value' => $message->mid,
  );
  $form['delete_destination'] = array(
    '#type' => 'value',
    '#value' => count($thread['messages']) > 1 ? 'messages/view/' . $message->thread_id : 'messages',
  );

  if (privatemsg_user_access('read all private messages')) {
    $form['delete_options'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete this message for all users?'),
      '#description' => t('Tick the box to delete the message for all users.'),
      '#default_value' => FALSE,
    );
  }
  return confirm_form($form,
    t('Are you sure you want to delete this message?'),
    isset($_GET['destination']) ? $_GET['destination'] : 'messages/view/' . $message->thread_id,
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

function privatemsg_delete_submit($form, &$form_state) {
  global $user;
  $account = clone $user;

  if ($form_state['values']['confirm']) {
    if (isset($form_state['values']['delete_options']) && $form_state['values']['delete_options']) {
      privatemsg_message_change_delete($form_state['values']['pmid'], 1);
      drupal_set_message(t('Message has been deleted for all users.'));
    }
    else {
      privatemsg_message_change_delete($form_state['values']['pmid'], 1, $account);
      drupal_set_message(t('Message has been deleted.'));
    }
  }
  $form_state['redirect'] = $form_state['values']['delete_destination'];
}

/**
 * List messages.
 *
 * @param $argument
 *   An argument to pass through to the query builder.
 * @param $uid
 *   User id messages of another user should be displayed
 *
 * @return
 *   Form array
 */
function privatemsg_list_page($argument = 'list', $uid = NULL) {
  global $user;

  // Setting default behavior...
  $account = $user;
  // Because uid is submitted by the menu system, it's a string not a integer.
  if ((int)$uid > 0 && $uid != $user->uid) {
    // Trying to view someone else's messages...
    if (!$account_check = user_load($uid)) {
      return MENU_NOT_FOUND;
    }
    if (!privatemsg_user_access('read all private messages')) {
      return MENU_ACCESS_DENIED;
    }
    // Has rights and user_load return an array so user does exist
    $account = $account_check;
  }

  return drupal_get_form('privatemsg_list', $argument, $account);
}

function privatemsg_list($form, &$form_state, $argument, $account) {
  // If this is an AJAX request, update $_GET['q'] so that table sorting and
  // similar links are using the correct base path.
  if ($_GET['q'] == 'system/ajax') {
    $q = 'messages';
    if (!empty($argument)) {
      $q .= '/' . $argument;
    }
    $_GET['q'] = $q;
  }

  // Load the themed list headers based on the available data.
  $headers = privatemsg_get_headers(TRUE);

  $form = array(
    '#list_argument' => $argument,
    '#submit' => array('privatemsg_list_submit'),
    'updated' => array(
      '#prefix' => '<div id="privatemsg-list-form">',
      '#suffix' => '</div>',
    ),
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-list.css',
      ),
    ),
  );
  $form['updated']['list'] = array(
    '#type' => 'tableselect',
    '#header' => $headers,
    '#options' => array(),
    '#attributes' => array('class' => array('privatemsg-list')),
    '#empty' => t('No messages available.'),
    '#weight' => 5,
    '#pre_render' => array('_privatemsg_list_thread'),
  );

  $query = _privatemsg_assemble_query('list', $account, $argument);
  $i = 0;
  foreach ($query->execute() as $row) {

    // Store the raw row data.
    $form['updated']['list']['#options'][$row->thread_id] = (array)$row;
    // Tableselect sorts the options, set a weight so that the order doesn't get
    // changed.
    $form['updated']['list']['#options'][$row->thread_id]['#weight'] = $i++;
  }

  if (!empty($form['updated']['list']['#options'])) {
    // Load the last reply that is not from the current user.
    $result = db_query('SELECT pmi.thread_id, MAX(pm.mid) AS last_message FROM {pm_message} pm INNER JOIN {pm_index} pmi ON pm.mid = pmi.mid WHERE pmi.thread_id IN (:thread_ids) AND pm.author <> :current_uid GROUP BY pmi.thread_id', array(':current_uid' => $account->uid, ':thread_ids' => array_keys($form['updated']['list']['#options'])));
    foreach ($result as $row) {
      // Set replied flag if there is no newer message from another user than
      // the last replied.
      if ($row->last_message <= $form['updated']['list']['#options'][$row->thread_id]['last_reply_to_mid']) {
        $form['updated']['list']['#options'][$row->thread_id]['is_replied'] = TRUE;
      }
    }

    $form['updated']['actions'] = _privatemsg_action_form($argument);
  }

  // Save the currently active account, used for actions.
  $form['account'] = array('#type' => 'value', '#value' => $account);

  // Define checkboxes, pager and theme
  $form['updated']['pager'] = array('#markup' => theme('pager'), '#weight' => 20);
  return $form;
}

/**
 * Process privatemsg_list form submissions.
 *
 * Execute the chosen action on the selected messages. This function is
 * based on node_admin_nodes_submit().
 */
function privatemsg_list_submit($form, &$form_state) {
  // Load all available operation definitions.
  $operations = module_invoke_all('privatemsg_thread_operations', $form['#list_argument']);
  drupal_alter('privatemsg_thread_operations', $operations, $form['#list_argument']);

  // Default "default" operation, which won't do anything.
  $operation = array('callback' => 0);

  // Check if a valid operation has been submitted.
  if (isset($form_state['values']['operation']) && isset($operations[$form_state['values']['operation']])) {
    $operation = $operations[$form_state['values']['operation']];
  }

  if (!empty($form_state['values']['op'])) {
    // Load all keys where the value is the current op.
    $keys = array_keys($form_state['values'], $form_state['values']['op']);

    // Loop over them and detect if a matching button was pressed.
    foreach ($keys as $key) {
      if ($key != 'op' && isset($operations[$key])) {
        $operation = $operations[$key];
      }
    }
  }

  // Only execute something if we have a valid callback and at least one checked thread.
  if (!empty($operation['callback'])) {
    // Hack to fix destination during ajax requests.
    if (isset($form_state['input']['ajax_page_state'])) {
      $destination = 'messages';
      if (!empty($form['#list_argument'])) {
        $destination .= '/' . $form['#list_argument'];
      }
      $_GET['destination'] = $destination;
    }
    privatemsg_operation_execute($operation, $form_state['values']['list'], $form_state['values']['account']);
  }

  $form_state['rebuild'] = TRUE;
  $form_state['input'] = array();
}

/**
 * Form builder function; Write a new private message.
 */
function privatemsg_new($form, &$form_state, $recipients = '', $subject = '') {

  // Convert recipients to array of user objects.
  $unique = FALSE;
  if (!empty($recipients) && is_string($recipients) || is_int($recipients)) {
    $unique = TRUE;
    $recipients = _privatemsg_generate_user_array($recipients);
  }
  else {
    $recipients = array();
  }

  // Subject has / encoded twice if clean urls are enabled to get it through
  // mod_rewrite and the menu system. Decode it once more.
  $subject = str_replace('%2F', '/', $subject);

  if (isset($form_state['values'])) {
    if (isset($form_state['values']['recipient'])) {
      $recipients_plain = $form_state['values']['recipient'];
    }
    $subject   = $form_state['values']['subject'];
  }
  else {
    $to = _privatemsg_get_allowed_recipients($recipients);

    $recipients_plain = '';
    if (!empty($to)) {
      $to_plain = array();
      $to_title = array();
      foreach ($to as $recipient) {
        // Load user(s) with that name
        $to_user = _privatemsg_parse_userstring($recipient->name);
        // If the count of duplicated is more than 0 that means the recipient name is used by the other recipient type,
        // so we should use unique.
        $to_plain[] = privatemsg_recipient_format($recipient, array('plain' => TRUE, 'unique' => (count($to_user[2]) > 0)));
        $to_title[] = privatemsg_recipient_format($recipient, array('plain' => TRUE));
      }
      $recipients_plain = implode(', ', $to_plain);
      $recipients_title = implode(', ', $to_title);
    }
  }

  if (!empty($recipients_title)) {
    drupal_set_title(t('Write new message to %recipient', array('%recipient' => $recipients_title)), PASS_THROUGH);
  }
  else {
    drupal_set_title(t('Write new message'));
  }

  $form = array(
    '#access' => privatemsg_user_access('write privatemsg'),
  );

  $form += _privatemsg_form_base_fields($form, $form_state);

  $description_array = array();
  foreach (privatemsg_recipient_get_types() as $name => $type) {
    if (privatemsg_recipient_access($name, 'write')) {
      $description_array[] = $type['description'];
    }
  }
  $description = t('Enter the recipient, separate recipients with commas.');
  $description .= theme('item_list', array('items' => $description_array));

  $form['recipient'] = array(
    '#type'               => 'textfield',
    '#title'              => t('To'),
    '#description'        => $description,
    '#default_value'      => $recipients_plain,
    '#required'           => TRUE,
    '#weight'             => -10,
    '#size'               => 50,
    '#autocomplete_path'  => 'messages/autocomplete',
    // Disable #maxlength, make it configurable by number of recipients, not
    // their name length.
    '#after_build'        => array('privatemsg_disable_maxlength'),
  );
  $form['subject'] = array(
    '#type'               => 'textfield',
    '#title'              => t('Subject'),
    '#size'               => 50,
    '#maxlength'          => 255,
    '#default_value'      => $subject,
    '#weight'             => -5,
  );

  $url = 'messages';
  if (isset($_REQUEST['destination'])) {
    $url = $_REQUEST['destination'];
  }

  $form['actions']['cancel'] = array(
    '#value'  => l(t('Cancel'), $url, array('attributes' => array('id' => 'edit-cancel'))),
    '#weight' => 20,
  );

  return $form;
}

/**
 * Remove the maxlength attribute from a field.
 */
function privatemsg_disable_maxlength($element) {
  unset($element['#maxlength']);
  return $element;
}

/**
 * Form builder function; Write a reply to a thread.
 */
function privatemsg_form_reply($form, &$form_state, $thread) {
  $form = array(
    '#access' => privatemsg_user_access('write privatemsg') || privatemsg_user_access('reply only privatemsg'),
  );

  $to = _privatemsg_get_allowed_recipients($thread['participants'], $thread['thread_id']);
  if (empty($to)) {
    // Display a message if some users are blocked.
    // @todo: Move this check out of the form, don't use the form in that case.
    $blocked_messages = &drupal_static('privatemsg_blocked_messages', array());
    if (count($blocked_messages)) {
      $blocked = t('You can not reply to this conversation because all recipients are blocked.');
      $blocked .= theme('item_list', array('items' => $blocked_messages));
      $form['blocked']['#markup'] = $blocked;
    }
    else {
      $form['#access'] = FALSE;
    }
    return $form;
  }

  $form += _privatemsg_form_base_fields($form, $form_state);

  $form['actions']['cancel'] = array(
    '#value'  => l(t('Clear'), $_GET['q'], array('attributes' => array('id' => 'edit-cancel'))),
    '#weight' => 20,
  );

  // Include the mid of the message we're responding to so we can mark it as
  // replied when the form is submitted.
  $reply_to_mid = end($thread['messages'])->mid;
  $form['reply_to_mid'] = array(
    '#type' => 'value',
    '#value' => $reply_to_mid,
  );
  $form['thread_id'] = array(
    '#type' => 'value',
    '#value' => $thread['thread_id'],
  );
  $form['subject'] = array(
    '#type' => 'value',
    '#default_value' => $thread['subject'],
  );
  $form['reply'] = array(
    '#markup' =>  '<h2 class="privatemsg-reply">' . t('Reply') . '</h2>',
    '#weight' => -10,
  );

  $form['read_all'] = array(
    '#type'  => 'value',
    '#value' => $thread['read_all'],
  );

  return $form;
}

/**
 * Returns the common fields of the reply and new form.
 */
function _privatemsg_form_base_fields($form, &$form_state) {
  global $user;

  if (isset($form_state['privatemsg_preview'])) {

    $preview_subject = '';
    // Only display subject on preview for new messages.
    if (empty($form_state['validate_built_message']->thread_id)) {
      $preview_subject = check_plain($form_state['validate_built_message']->subject);
      // If message has tokens, replace them.
      if ($form_state['validate_built_message']->has_tokens) {
        $preview_subject = privatemsg_token_replace($preview_subject, array('privatemsg_message' => $form_state['validate_built_message']), array('sanitize' => TRUE, 'privatemsg-show-span' => FALSE));
      }
    }
    $form['message_header'] = array(
      '#type' => 'fieldset',
      '#title' => !empty($preview_subject) ? $preview_subject : t('Preview'),
      '#attributes' => array('class' => array('preview')),
      '#weight' => -20,
    );
    $form['message_header']['message_preview'] = $form_state['privatemsg_preview'];
  }

  $form['author'] = array(
    '#type' => 'value',
    '#value' => $user,
  );

  // The input filter widget looses the format during preview, specify it
  // explicitly.
  if (isset($form_state['values']) && array_key_exists('format', $form_state['values'])) {
    $format = $form_state['values']['format'];
  }
  $form['body'] = array(
    '#type'               => 'text_format',
    '#title'              => t('Message'),
    '#rows'               => 6,
    '#weight'             => -3,
    '#resizable'          => TRUE,
    '#format'             => isset($format) ? $format : NULL,
    '#after_build'        => array('privatemsg_check_format_access'),
  );

  if (privatemsg_user_access('use tokens in privatemsg') && module_exists('token')) {
    $form['token'] = array(
      '#type' => 'fieldset',
      '#title' => t('Token browser'),
      '#weight' => -1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['token']['browser'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('privatemsg_message'),
    );
  }
  $form['actions'] = array('#type' => 'actions');

  if (variable_get('privatemsg_display_preview_button', FALSE)) {
    $form['actions']['preview'] = array(
      '#type'     => 'submit',
      '#value'    => t('Preview message'),
      '#validate' => array('privatemsg_new_validate'),
      '#submit'   => array('privatemsg_new_preview'),
      '#weight'   => 10,
    );
  }

  $form['actions']['submit'] = array(
    '#type'     => 'submit',
    '#value'    => t('Send message'),
    '#weight'   => 15,
    '#validate' => array('privatemsg_new_validate'),
    '#submit'   => array('privatemsg_new_submit'),
  );

  // Attach field widgets.
  $message = (object) array();
  if (isset($form_state['validate_built_message'])) {
    $message = $form_state['validate_built_message'];
  }

  // If a module (e.g. OG) adds a validate or submit callback to the form in
  // field_attach_form, the form system will not add ours automatically
  // anymore. Therefore, explicitly adding them here.
  $form['#submit'] = array('privatemsg_new_submit');
  $form['#validate'] = array('privatemsg_new_validate');

  field_attach_form('privatemsg_message', $message, $form, $form_state);
  return $form;
}

/**
 * Check if the current user is allowed to write these recipients.
 *
 * @param $recipients
 *   Array of recipient objects.
 *
 * @return
 *   Array of allowed recipient objects.
 */
function _privatemsg_get_allowed_recipients($recipients, $thread_id = NULL) {
  global $user;

  $usercount = 0;
  $valid = array();
  $blocked_messages = &drupal_static('privatemsg_blocked_messages', array());
  foreach ($recipients as $recipient) {
    // Allow to pass in normal user objects.
    if (empty($recipient->type)) {
      $recipient->type = 'user';
      $recipient->recipient = $recipient->uid;
    }
    if ($recipient->type == 'hidden') {
      continue;
    }
    if (isset($valid[privatemsg_recipient_key($recipient)])) {
      // We already added the recipient to the list, skip him.
      continue;
    }
    if (!privatemsg_recipient_access($recipient->type, 'write', $recipient)) {
      // User does not have access to write to this recipient, continue.
      continue;
    }
    if ($recipient->type == 'user' && $recipient->recipient == $user->uid) {
      // Skip putting author in the recipients list for now.
      // Will be added if he is the only recipient.
      $usercount++;
      continue;
    }
    $valid[privatemsg_recipient_key($recipient)] = $recipient;
  }

  foreach (module_invoke_all('privatemsg_block_message', $user, $valid, array('thread_id' => $thread_id)) as $blocked) {
    // Unset the recipient.
    unset($valid[$blocked['recipient']]);
    // Store blocked messages. These are only displayed if all recipients
    // are blocked.
    $blocked_messages[] = $blocked['message'];
  }

  if (empty($valid) && $usercount >= 1 && empty($blocked_messages)) {
    // Assume the user sent message to own account as if the usercount is one or
    // less, then the user sent a message but not to self.
    $valid['user_' . $user->uid] = $user;
  }
  return $valid;
}

/**
 * After build callback; Hide format widget if user doesn't have permission.
 */
function privatemsg_check_format_access($element) {
  if (isset($element['format'])) {
    $element['format']['#access'] = privatemsg_user_access('select text format for privatemsg');
  }
  return $element;
}

function privatemsg_new_validate($form, &$form_state) {
  // The actual message that is being sent, we create this during validation and
  // pass to submit to send out.
  $message = (object)$form_state['values'];
  $message->mid       = 0;
  $message->format    = $message->body['format'];
  $message->body      = $message->body['value'];
  $message->timestamp = REQUEST_TIME;
  // Avoid subjects which only consist of a space as these can not be clicked.
  $message->subject = trim($message->subject);

  $trimmed_body = trim(truncate_utf8(strip_tags($message->body), 50, TRUE, TRUE));
  if (empty($message->thread_id) && empty($message->subject) && !empty($trimmed_body)) {
    $message->subject = $trimmed_body;
  }
  // Only parse the user string for a new thread.
  if (!isset($message->thread_id)) {
    list($message->recipients, $invalid, $duplicates, $denieds) = _privatemsg_parse_userstring($message->recipient);
  }
  else {
    // Load participants. Limit recipients to visible unless read_all is TRUE.
    $message->recipients = _privatemsg_load_thread_participants($message->thread_id, $message->read_all ? FALSE : $message->author);
  }

  if (!empty($invalid)) {
    // Display information about invalid recipients.
    drupal_set_message(t('The following recipients will not receive this private message: @invalid.', array('@invalid' => implode(", ", $invalid))), 'error');
  }
  if (!empty($denieds)) {
    // Display information about denied recipients.
    drupal_set_message(t('You do not have access to write these recipients: @denieds.', array('@denieds' => implode(", ", $denieds))), 'error');
  }

  if (!empty($duplicates)) {
    // Add JS and CSS to allow choosing the recipient.
    drupal_add_js(drupal_get_path('module', 'privatemsg') . '/privatemsg-alternatives.js');

    // Display information about recipients that couldn't be identified
    // uniquely.
    $js_duplicates = array();
    foreach ($duplicates as $string => $duplicate) {
      $alternatives = array();
      foreach ($duplicate as $match) {
        $formatted_match = privatemsg_recipient_format($match, array('plain' => TRUE, 'unique' => TRUE));
        $js_duplicates[$formatted_match] = $string;
        $alternatives[] = '<span class="privatemsg-recipient-alternative">' . $formatted_match . '</span>';
      }
      // Build a formatted list of possible recipients.
      $alternatives = theme('item_list', array('items' => $alternatives, 'attributes' => array('class' => array('action-links'))));
      form_set_error('recipient', '<span class="privatemsg-alternative-description">' . t('The site has multiple recipients named %string. Please choose your intended recipient: !list', array('%string' => $string, '!list' => $alternatives)) . '</span>');
    }

    // Also make that information available to the javascript replacement code.
    drupal_add_js(array('privatemsg_duplicates' => $js_duplicates), 'setting');
  }

  $validated = _privatemsg_validate_message($message, TRUE);
  foreach ($validated['messages'] as $type => $texts) {
    foreach ($texts as $text) {
      drupal_set_message($text, $type);
    }
  }
  $form_state['validate_built_message'] = $message;
}

function privatemsg_new_preview($form, &$form_state) {
  $message = $form_state['validate_built_message'];
  // Execute submit hook, removes empty fields.
  field_attach_submit('privatemsg_message', $message, $form, $form_state);
  // Load information attached to the message. Use an internal function
  // to avoid the internal field cache.
  _field_invoke_multiple('load', 'privatemsg_message', array($message->mid => $message));
  $form_state['privatemsg_preview'] = array(
    '#markup' => theme('privatemsg_view', array('message' => $message)),
    '#attached' => array(
      drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.base.css',
      drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.theme.css',
    ),
  );
  // This forces the form to be rebuilt instead of being submitted.
  $form_state['rebuild'] = TRUE;
}


/**
 * Submit callback for the privatemsg_new form.
 */
function privatemsg_new_submit($form, &$form_state) {
  $message = $form_state['validate_built_message'];
  field_attach_submit('privatemsg_message', $message, $form, $form_state);

  // Format each recipient.
  $recipient_names = array();
  foreach ($message->recipients as $recipient) {
    $recipient_names[] = privatemsg_recipient_format($recipient);
  }
  try {
    $message = _privatemsg_send($message);
    _privatemsg_handle_recipients($message->mid, $message->recipients);
    drupal_set_message(t('A message has been sent to !recipients.', array('!recipients' => implode(', ', $recipient_names))));
    // Only redirect on new threads.
    if ($message->mid == $message->thread_id || variable_get('privatemsg_default_redirect_reply', FALSE)) {
      $redirect = variable_get('privatemsg_default_redirect', '<new-message>');
      if ($redirect == '<new-message>' || (!empty($_REQUEST['destination']) && $_REQUEST['destination'] == '[new-message]')) {
        if (!empty($_REQUEST['destination']) && $_REQUEST['destination'] == '[new-message]') {
          // Remove GET param so that drupal_goto() uses the redirect from
          // $form_state.
          unset($_GET['destination']);
        }
        // Forward to the new message in the thread.
        $form_state['redirect'] = array('messages/view/' . $message->thread_id, array('fragment' => 'privatemsg-mid-' . $message->mid));
      }
      elseif (!empty($redirect)) {
        $form_state['redirect'] = $redirect;
      }
    }
  }
  catch (Exception $e) {
    if (error_displayable()) {
      require_once DRUPAL_ROOT . '/includes/errors.inc';
      $variables = _drupal_decode_exception($e);
      drupal_set_message(t('Failed to send a message to !recipients. %type: !message in %function (line %line of %file).', array('!recipients' => implode(', ', $recipient_names)) + $variables), 'error');
    }
    else {
      drupal_set_message(t('Failed to send a message to !recipients. Contact your site administrator.', array('!recipients' => implode(', ', $recipient_names))), 'error');
    }
  }
}


/**
 * Menu callback for messages/undo/action.
 *
 * This function will test if an undo callback is stored in SESSION and execute it.
 */
function privatemsg_undo_action() {
  // Check if a undo callback for that user exists.
  if (isset($_SESSION['privatemsg']['undo callback']) && is_array($_SESSION['privatemsg']['undo callback'])) {
    $undo = $_SESSION['privatemsg']['undo callback'];
    // If the defined undo callback exists, execute it
    if (isset($undo['function']) && isset($undo['args'])) {
      // Load the user object.
      if (isset($undo['args']['account']) && $undo['args']['account'] > 0) {
        $undo['args']['account'] = user_load((int)$undo['args']['account']);
      }
      call_user_func_array($undo['function'], $undo['args']);
    }
  }
  // Return back to the site defined by the destination GET param.
  drupal_goto();
}


/**
 * Return autocomplete results for usernames.
 *
 * Prevents usernames from being used and/or suggested twice.
 */
function privatemsg_autocomplete($string) {
  $names = array();
  // 1: Parse $string and build list of valid user names.
  $fragments = explode(',', $string);
  foreach ($fragments as $name) {
    if ($name = trim($name)) {
      $names[$name] = $name;
    }
  }
  // 2: Find the next user name suggestion.
  $fragment = array_pop($names);
  $matches = array();
  if (!empty($fragment)) {
    $remaining = 10;
    $types = privatemsg_recipient_get_types();
    foreach ($types as $name => $type) {
      if (isset($type['autocomplete']) && is_callable($type['autocomplete']) && privatemsg_recipient_access($name, 'write')) {
        $function = $type['autocomplete'];
        $return = $function($fragment, $names, $remaining, $name);
        if (is_array($return) && !empty($return)) {
          $matches = array_merge($matches, $return);
        }
        $remaining = 10 - count($matches);
        if ($remaining <= 0) {
          break;
        }
      }
    }
  }
  // Allow modules to alter the autocomplete list.
  drupal_alter('privatemsg_autocomplete', $matches, $names, $fragment);

  // Format the suggestions.
  $themed_matches = array();
  foreach ($matches as $key => $match) {
    $themed_matches[$key] = privatemsg_recipient_format($match, array('plain' => TRUE));
  }

  // Check if there are any duplicates.
  if (count(array_unique($themed_matches)) != count($themed_matches)) {
    // Loop over matches, look for duplicates of each one.
    foreach ($themed_matches as $themed_match) {
      $duplicate_keys = array_keys($themed_matches, $themed_match);
      if (count($duplicate_keys) > 1) {
        // There are duplicates, make them unique.
        foreach ($duplicate_keys as $duplicate_key) {
          // Reformat them with unique argument.
          $themed_matches[$duplicate_key] = privatemsg_recipient_format($matches[$duplicate_key], array('plain' => TRUE, 'unique' => TRUE));
        }
      }
    }
  }

  // Prefix the matches and convert them to the correct form for the
  // autocomplete.
  $prefix = count($names) ? implode(", ", $names) . ", " : '';
  $suggestions = array();
  foreach ($themed_matches as $match) {
    $suggestions[$prefix . $match . ', '] = $match;
  }

  // convert to object to prevent drupal bug, see http://drupal.org/node/175361
  drupal_json_output((object)$suggestions);
}


/**
 * Menu callback for viewing a thread.
 *
 * @param $thread
 *   A array containing all information about a specific thread, generated by
 *   privatemsg_thread_load().
 * @return
 *   The page content.
 *
 * @see privatemsg_thread_load()
 */
function privatemsg_view($thread) {
  drupal_set_title($thread['subject-tokenized']);

  $content = array(
    '#thread' => $thread,
  );

  if ($thread['to'] != $thread['message_count'] || !empty($thread['start'])) {
    // Generate paging links.
    $older = '';
    if (isset($thread['older_start'])) {
      $options = array(
        'query' => array('start' => $thread['older_start']),
        'attributes' => array(
          'title' => t('Display older messages'),
        ),
      );
      $older = l(t('<<'), 'messages/view/' . $thread['thread_id'], $options);
    }
    $newer = '';
    if (isset($thread['newer_start'])) {
      $options = array(
        'query' => array('start' => $thread['newer_start']),
        'attributes' => array(
          'title' => t('Display newer messages'),
        ),
      );
      $newer = l(t('>>'), 'messages/view/' . $thread['thread_id'], $options);
    }
    $substitutions = array('@from' => $thread['from'], '@to' => $thread['to'], '@total' => $thread['message_count'], '!previous_link' => $older, '!newer_link' => $newer);
    $title = t('!previous_link Displaying messages @from - @to of @total !newer_link', $substitutions);
    $content['pager'] = array(
      '#markup'  => trim($title),
      '#prefix' => '<div class="privatemsg-view-pager">',
      '#suffix' => '</div>',
      '#weight' => 3,
    );
  }

  // Render the participants.
  $content['participants'] = array(
    '#markup' => theme('privatemsg_recipients', array('thread' => $thread)),
    '#weight' => -5,
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-recipients.css',
      ),
    ),
  );

  // Render the messages.
  $content['messages']['#weight'] = 0;
  $i = 1;
  $count = count($thread['messages']);
  foreach ($thread['messages'] as $pmid => $message) {
    // Set message as read and theme it.
    // Add CSS classes.
    $message->classes = array('privatemsg-message', 'privatemsg-message-' . $i, $i % 2 == 1 ? 'privatemsg-message-even' : 'privatemsg-message-odd');
    if (!empty($message->is_new)) {
      // Mark message as read.
      privatemsg_message_change_status($pmid, PRIVATEMSG_READ, $thread['user']);
      $message->classes[] = 'privatemsg-message-new';
    }

    if ($i == 1) {
      $message->classes[] = 'privatemsg-message-first';
    }
    if ($i == $count) {
      $message->classes[] = 'privatemsg-message-last';
    }
    $i++;
    $content['messages'][$pmid] = array(
      '#markup' => theme('privatemsg_view', array('message' => $message)),
      '#attached' => array(
        'css' => array(
          drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.base.css',
          drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.theme.css',
        ),
      ),
    );
  }

  // Display the reply form if user is allowed to use it.
  if (privatemsg_user_access('write privatemsg') || privatemsg_user_access('reply only privatemsg')) {
    $content['reply'] = drupal_get_form('privatemsg_form_reply', $thread);
    $content['reply']['#weight'] = 5;
  }
  // Check after calling the privatemsg_new form so that this message is only
  // displayed when we are not sending a message.
  if ($thread['read_all']) {
    // User has permission to read all messages AND is not a participant of the current thread.
    drupal_set_message(t('This conversation is being viewed with escalated privileges and may not be the same as shown to normal users.'), 'warning');
  }

  drupal_alter('privatemsg_view', $content);

  return $content;
}

/**
 * Batch processing function for rebuilding the index.
 */
function privatemsg_load_recipients($mid, $recipient, &$context) {
  // Get type information.
  $type = privatemsg_recipient_get_type($recipient->type);

  // First run, initialize sandbox.
  if (!isset($context['sandbox']['current_offset'])) {
    $context['sandbox']['current_offset'] = 0;
    $count_function = $type['count'];
    $context['sandbox']['count'] = $count_function($recipient);
  }

  // Fetch the 10 next recipients.
  $load_function = $type['generate recipients'];
  $uids = $load_function($recipient, 10, $context['sandbox']['current_offset']);

  if (!empty($uids)) {
    foreach ($uids as $uid) {
      privatemsg_message_change_recipient($mid, $uid, 'hidden');
    }

    $context['sandbox']['current_offset'] += 10;
    // Set finished based on sandbox.
    $context['finished'] = empty($context['sandbox']['count']) ? 1 : ($context['sandbox']['current_offset'] / $context['sandbox']['count']);
  }
  else {
    // If no recipients were returned, mark as finished too.
    $context['sandbox']['finished'] = 1;
  }

  // If we are finished, mark the recipient as read.
  if ($context['finished'] >= 1) {
    db_update('pm_index')
      ->fields(array('is_new' => PRIVATEMSG_READ))
      ->condition('mid', $mid)
      ->condition('recipient', $recipient->recipient)
      ->condition('type', $recipient->type)
      ->execute();
  }
}
