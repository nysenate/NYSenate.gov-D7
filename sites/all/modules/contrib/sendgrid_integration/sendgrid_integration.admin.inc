<?php

/**
 * Provides a form to send a test email through Sendgrid.
 */
function sendgrid_integration_test() {
  $form = [];

  $defaults = variable_get(
    'sendgrid_integration_test_defaults',
    [
      'to' => variable_get('site_mail', 'user@example.com'),
      'subject' => 'Test Email from SendGrid Module',
      'body' => [
        'value' => 'Test Message for SendGrid.',
      ],
      'fromname' => '',
      'toname' => '',
      'replyto' => '',
    ]
  );

  $defaults['body']['format'] = filter_fallback_format();
  $form['fromname'] = [
    '#type' => 'textfield',
    '#title' => t('From name'),
    '#default_value' => (isset($defaults['fromname'])) ? $defaults['fromname'] : '',
    '#maxlength' => 128,
  ];
  $form['to'] = [
    '#type' => 'textfield',
    '#title' => t('To'),
    '#default_value' => $defaults['to'],
    '#maxlength' => 128,
    '#required' => TRUE,
  ];
  $form['toname'] = [
    '#type' => 'textfield',
    '#title' => t('To Name'),
    '#default_value' => (isset($defaults['toname'])) ? $defaults['toname'] : '',
    '#maxlength' => 128,
  ];
  $form['replyto'] = [
    '#type' => 'textfield',
    '#title' => t('Reply-To'),
    '#maxlength' => 128,
    '#default_value' => (isset($defaults['replyto'])) ? $defaults['replyto'] : '',
  ];
  $form['subject'] = [
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $defaults['subject'],
    '#maxlength' => 128,
    '#required' => TRUE,
  ];
  $form['include_attachment'] = [
    '#title' => t('Include attachment'),
    '#type' => 'checkbox',
    '#description' => t('If checked, the Drupal icon will be included as an attachment with the test email.'),
    '#default_value' => TRUE,
  ];
  $form['body'] = [
    '#type' => 'text_format',
    '#title' => t('Body'),
    '#rows' => 20,
    '#default_value' => $defaults['body']['value'],
    '#format' => $defaults['body']['format'],
    '#required' => TRUE,
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Send test message'),
  ];
  return $form;
}

/**
 * Implements hook_submit().
 */
function sendgrid_integration_test_submit($form, &$form_state) {
  // Create defaults array.
  $defaults = [
    'to' => $form_state['values']['to'],
    'subject' => $form_state['values']['subject'],
    'body' => $form_state['values']['body'],
    'toname' => $form_state['values']['toname'],
    'fromname' => $form_state['values']['fromname'],
    'replyto' => $form_state['values']['replyto'],
  ];
  // Set the defaults for reuse.
  variable_set('sendgrid_integration_test_defaults', $defaults);

  $params = [
    'subject' => $form_state['values']['subject'],
    'body' => check_markup(
      $form_state['values']['body']['value'],
      $form_state['values']['body']['format']
    ),
  ];
  if (!empty($form_state['values']['replyto'])) {
    $params['Reply-To'] = $form_state['values']['replyto'];
  }
  if (!empty($form_state['values']['toname'])) {
    $sendto = $form_state['values']['toname'] . '<' . $form_state['values']['to'] . '>';
  }
  else {
    $sendto = $form_state['values']['to'];
  }
  $params['include_test_attachment'] = $form_state['values']['include_attachment'];
  // Setting a specific mail system for the SendGrid Integration Module.
  mailsystem_set(['sendgrid_integration' => 'SendGridMailSystem']);
  // Attempt to send the email and post a message if it was successful.
  if (!empty($form_state['values']['fromname'])) {
    $senderfrom = $form_state['values']['fromname'] . ' <' . variable_get('site_mail') . '>';
  }
  else {
    $senderfrom = variable_get('site_mail');
  }
  $result = drupal_mail('sendgrid_integration', 'test', $sendto, language_default(), $params, $senderfrom);
  if (isset($result['result']) && $result['result'] == 'true') {
    drupal_set_message(t('SendGrid test email sent from %from to %to.', [
      '%from' => $senderfrom,
      '%to' => $sendto,
    ]), 'status');
  }
}
