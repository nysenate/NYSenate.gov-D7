<?php

/**
 * Form Builder; Integrates with Devel Generate.
 *
 * @see privatemsg_devel_generate_form_validate()
 * @see privatemsg_devel_generate_form_submit()
 */
function privatemsg_devel_generate_form() {

  // Check if authenticated users can write new messages.
  $perm = 'write privatemsg';
  $role_perms = user_role_permissions(array(DRUPAL_AUTHENTICATED_RID => 'authenticated user'));
  $perms = $role_perms[DRUPAL_AUTHENTICATED_RID];

  if (!in_array($perm, $perms)) {
    drupal_set_message(
      t('Authenticated users do not have %perm permission. This function will not run correctly. <a href="@url">Permissions page</a>.',
      array(
        '%perm' => $perm,
        '@url' => url(
          'admin/people/permissions',
          array(
            'fragment' => 'module-privatemsg',
            'query' => array(
              'destination' => 'admin/generate/privatemsg'
              )
            )
          )
        )
      ),
    'warning');
  }

  $options = array();
  for ($i = 1; $i <= 10; $i++) {
    $options[$i] = $i;
  }

  $form['kill_content'] = array(
    '#type' => 'checkbox',
    '#title' => t('<strong>Delete all messages</strong> before generating new messages.'),
    '#default_value' => FALSE,
  );
  $form['num_threads'] = array(
    '#type' => 'textfield',
    '#title' => t('How many threads would you like to generate?'),
    '#default_value' => 10,
    '#size' => 10,
  );
  $form['max_thread_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Max thread length?'),
    '#default_value' => 5,
    '#size' => 10,
  );
  $form['recipients'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recipients'),
    '#description' => t('A random number of recipients will be generated for each message.'),
  );
  $form['recipients']['min_recipients'] = array(
    '#type' => 'select',
    '#title' => t('Minimum number of recipients for each message'),
    '#default_value' => 1,
    '#options' => $options,
  );
  $form['recipients']['max_recipients'] = array(
    '#type' => 'select',
    '#title' => t('Maximum number of recipients for each message'),
    '#default_value' => 3,
    '#options' => $options,
  );

  $options = array(1 => t('Now'));
  foreach (array(3600, 86400, 604800, 2592000, 31536000) as $interval) {
    $options[$interval] = format_interval($interval, 1) . ' ' . t('ago');
  }
  $form['time_range'] = array(
    '#type' => 'select',
    '#title' => t('How far back in time should the messages be dated?'),
    '#description' => t('Message creation dates will be distributed randomly from the current time, back to the selected time.'),
    '#options' => $options,
    '#default_value' => 604800,
  );

  $form['subject_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Max word length of subjects'),
    '#default_value' => 8,
    '#size' => 10,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate'),
  );
  $form['#redirect'] = FALSE;

  return $form;
}

/**
 * Validate; Integrates with Devel Generate.
 *
 * @see privatemsg_devel_generate_form()
 * @see privatemsg_devel_generate_form_submit()
 */
function privatemsg_devel_generate_form_validate($form_id, &$form_state) {
  module_load_include('inc', 'devel_generate');
  $uids = devel_get_users();
  $max_recipients = $form_state['values']['max_recipients'];

  // Ensure that there are enough users to fit the max recipients.
  // Note, messages cannot be sent from anonymous users, so exclude them.
  if (count($uids) - 1 < $max_recipients) {
    form_set_error('recipients][max_recipients', t('You only have @count_uids users to handle @count_recipients recipients. You must increase the number of users.', array('@count_uids' => count($uids) - 1, '@count_recipients' => $max_recipients)));
  }
}

/**
 * Submit; Integrates with Devel Generate.
 *
 * @see privatemsg_devel_generate_form()
 * @see privatemsg_devel_generate_form_validate()
 */
function privatemsg_devel_generate_form_submit($form_id, &$form_state) {
  if (!$form_state['values']['kill_content'] && $form_state['values']['num_threads'] <= 50 && $form_state['values']['max_thread_length'] <= 10) {
    privatemsg_devel_generate_threads($form_state);
  }
  else {
    privatemsg_devel_batch_generate_threads($form_state);
  }
}

/**
 * Mass Message Generation
 */
function privatemsg_devel_generate_threads($form_state) {
  if ($form_state['values']['kill_content']) {
    privatemsg_devel_generate_kill_threads();
  }

  // Generate threads.
  for ($i = 1; $i <= $form_state['values']['num_threads']; $i++) {
    privatemsg_devel_generate_new_thread($form_state['values']);
  }

  drupal_set_message(format_plural($form_state['values']['num_threads'], '1 thread created.', '@count threads created'));
}

/**
 * Single Message Generation
 */
function privatemsg_devel_generate_new_thread($values) {
  module_load_include('inc', 'devel_generate');

  // Make sure that uids are keyed by the actual user id.
  $uids = drupal_map_assoc(devel_get_users());
  // Do not allow anonymous (key) to send/receive private messages
  unset($uids[key($uids)]);

  $author = user_load($uids[array_rand($uids)]);
  $subject = devel_create_greeking(rand(1, $values['subject_length']), TRUE);
  $body = devel_create_content();

  $timestamp = rand(0, $values['time_range']);
  $options = array(
    'author' => $author,
    'timestamp' => REQUEST_TIME - $timestamp,
  );

  // Remove author when adding new recipients.
  unset($uids[array_search($author->uid, $uids)]);

  // Get a random amount of user ids.
  $num_recipients = rand($values['min_recipients'], $values['max_recipients']);
  $recipient_uids = array_rand($uids, $num_recipients);

  // Convert to array if just a single user has been loaded.
  if ($num_recipients > 1) {
    $recipients = user_load_multiple($recipient_uids);
  } else {
    $recipients = user_load($recipient_uids);
    $recipients = array($recipients);
  }

  // Generate message.
  $validated = privatemsg_new_thread($recipients, $subject, $body, $options);

  // Get thread information for generating replies.
  $thread_id = $validated['message']->thread_id;
  $num_replies = rand(0, $values['max_thread_length']);
  $reply_timestamp = $timestamp;

  // Add author back in to possible senders.
  $recipients[$author->uid] = $author;

  // Generate thread replies.
  for ($j = 0; $j <= $num_replies; $j++) {
    $reply_body = devel_create_content();
    $reply_author = $recipients[array_rand($recipients)];
    $reply_timestamp = rand(0, $reply_timestamp);

    $reply_options = array(
      'author' => $reply_author,
      'timestamp' => REQUEST_TIME - $reply_timestamp,
    );
    privatemsg_reply($thread_id, $reply_body, $reply_options);
  }
}

/**
 * Handle the privatemsg_devel_generate_form request to kill all of the threads.
 * This is used by both the batch and non-batch branches of the code.
 */
function privatemsg_devel_generate_kill_threads() {
  db_delete('pm_index')->execute();
  $i = db_delete('pm_message')->execute();

  drupal_set_message(format_plural($i, 'Deleted one message', 'Deleted @count messages'));
}

function privatemsg_devel_batch_generate_threads($form_state) {
  $operations = array();

  // add the kill operation
  if ($form_state['values']['kill_content']) {
    $operations[] = array('privatemsg_devel_generate_batch_kill_threads', array());
  }

  // add the operations to create the nodes
  for ($num = 0; $num < $form_state['values']['num_threads']; $num ++) {
    $operations[] = array('privatemsg_devel_generate_batch_new_thread', array($form_state['values']));
  }

  // start the batch
  $batch = array(
    'title' => t('Generating private messages'),
    'operations' => $operations,
    'finished' => 'privatemsg_devel_generate_batch_finished',
    'file' => drupal_get_path('module', 'privatemsg') . '/privatemsg.devel_generate.inc',
  );
  batch_set($batch);
}

function privatemsg_devel_generate_batch_kill_threads(&$context) {
  privatemsg_devel_generate_kill_threads();
}

function privatemsg_devel_generate_batch_new_thread($values, &$context) {
  privatemsg_devel_generate_new_thread($values);
  $context['results']['num_mids'] ++;
}

function privatemsg_devel_generate_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = t('Created @num_mids messages successfully.', array('@num_mids' => $results['num_mids']));
  }
  else {
    $message = t('Finished with an error.');
  }
  drupal_set_message($message);
}