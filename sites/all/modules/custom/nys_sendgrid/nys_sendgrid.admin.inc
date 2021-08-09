<?php


/**
 * Callback to generate the admin form for NYS Sendgrid module.
 *
 * @return array The admin form.
 */
function nys_sendgrid_admin() {
  // Get the existing API key.  This will not be rendered, but it is used for
  // specific warning text.
  $apikey = variable_get('nys_sendgrid_apikey', FALSE);
  $apikey_text = $apikey
    ? "An API key is already saved.  Leave the box blank to keep it, or input a new one to change it."
    : "<h2><b>No API key has been configured.  The API key is required before attempting to send mail.</b></h2>";
  $apikey_required = !((boolean) $apikey);

  $form = [
    'nys_sendgrid_api_frame' => [
      '#type' => 'fieldset',
      '#title' => 'API Settings',
      '#description' => 'Basic requirements for API calls.',
      'nys_sendgrid_apikey' => [
        '#type' => 'password',
        '#required' => $apikey_required,
        '#title' => 'SendGrid API Key',
        '#description' => $apikey_text,
        '#default_value' => '',
      ],
    ],

    'nys_sendgrid_behavior_frame' => [
      '#type' => 'fieldset',
      '#title' => 'Behavioral Options',
      '#description' => 'Manage options controlling how the module will construct Mail objects.',
      'nys_sendgrid_suppress_categories' => [
        '#type' => 'checkbox',
        '#title' => 'Suppress category auto-assignment',
        '#description' => 'By default, NYS SendGrid will add the originating module name and email key as categories for SendGrid.  Checking this box will suppress this behavior.  This feature can be reproduced on an ad-hoc basis by setting params["suppress_categories"] to TRUE.',
        '#default_value' => variable_get('nys_sendgrid_suppress_categories', FALSE),
      ],
    ],

    'nys_sendgrid_template_frame' => [
      '#type' => 'fieldset',
      '#title' => 'Templates',
      '#description' => 'Manage how the module behaves with template-related options.',

      'nys_sendgrid_suppress_template' => [
        '#type' => 'checkbox',
        '#title' => 'Suppress Templates',
        '#description' => 'Prevents automatic template assignment, for both default and mail-specific templates.  This feature can be reproduced on an ad-hoc basis by setting params["suppress_template"] to TRUE.',
        '#default_value' => variable_get('nys_sendgrid_suppress_template', FALSE),
      ],

      'nys_sendgrid_default_template' => _nys_sendgrid_construct_template_select(
        variable_get('nys_sendgrid_default_template', 0),
        'Default Template',
        'The template ID to attach to SendGrid requests when one is not specified by the caller or matched to an assignment.'
      ),

      'nys_sendgrid_add_assignment' => [
        '#prefix' => '<div class="nys_sendgrid_template_wrapper"><div>Add a template assignment to a specific mail key/ID.  The mail ID is generated as &quot;<i>&lt;module&gt;_&lt;mail_name&gt;</i>&quot;. <br />Wildcards using just &quot;<i>&lt;module&gt;</i>&quot; are acceptable as well.</div>',
        '#suffix' => '</div>',
        'add_assign_id' => [
            '#default_value' => 0,
            '#weight' => 2,
          ] + _nys_sendgrid_construct_template_select(),
        'add_assign_name' => [
          '#type' => 'textfield',
          '#default_value' => '',
          '#size' => 20,
          '#weight' => 1,
        ],
      ],

      'nys_sendgrid_content_substitution' => [
        '#type' => 'checkbox',
        '#title' => 'Auto-populate Content Tokens',
        '#description' => 'Enables the auto-population of the {{{body}}} and {{{subject}}} tokens for dynamic templates.  The values for those tokens will be derived from mail object\'s respective values.',
        '#default_value' => variable_get('nys_sendgrid_content_substitution', FALSE),
      ],
      'nys_sendgrid_content_token_body' => [
        '#type' => 'textfield',
        '#default_value' => variable_get('nys_sendgrid_content_token_body', 'body'),
        '#title' => 'Token Name for Body',
        '#description' => 'When auto-populating the body content into a dynamic token, use this token name.',
      ],
      'nys_sendgrid_content_token_subject' => [
        '#type' => 'textfield',
        '#default_value' => variable_get('nys_sendgrid_content_token_subject', 'subject'),
        '#title' => 'Token Name for Subject',
        '#description' => 'When auto-populating the subject into a dynamic token, use this token name.',
      ],
    ],

    'submit' => [
      '#type' => 'submit',
      '#value' => 'Save Settings',
    ],
  ];

  // Create the assignment lists.
  $select = _nys_sendgrid_construct_template_select();
  $assigns = [];
  $assigned = variable_get('nys_sendgrid_template_assignments', []);
  foreach ($assigned as $t_name => $t_id) {
    $ctrl = ['#default_value' => $t_id, '#weight' => 2] + $select;
    $input = [
      '#type' => 'textfield',
      '#default_value' => $t_name,
      '#size' => 20,
      '#weight' => 1,
    ];
    $assigns[] = [
      'template_id' => $ctrl,
      'mail_key' => $input,
      '#prefix' => '<div class="nys_sendgrid_template_wrapper">',
      '#suffix' => '</div>',
    ];
  }
  if (count($assigns)) {
    $assigns['#tree'] = TRUE;
    $assigns['#parents'] = ['templates'];
    $assigns['#prefix'] = '<p><br />Existing Assignments &nbsp;(To remove an entry, set the template to &quot;None&quot;)</p>';
    $form['nys_sendgrid_template_frame']['nys_sendgrid_template_assigns'] = $assigns;
  }

  // Add the style sheet.
  drupal_add_css(drupal_get_path('module', 'nys_sendgrid') . '/nys_sendgrid.admin.css');

  /* For debugging, this allows the admin page to send an email on every refresh. */
  //_user_mail_notify('register_no_approval_required', user_load(211101));

  return $form;
}

/**
 * Validation callback for admin settings form.
 *
 * @param $form
 * @param $form_state
 */
function nys_sendgrid_admin_validate($form, &$form_state) {
  // Check for API secret key. If missing throw error.
  if (empty(variable_get('nys_sendgrid_apikey', ''))
    && empty($form_state['values']['nys_sendgrid_apikey'])) {
    form_set_error('nys_sendgrid_apikey', t('An API key is required.'));
  }
}

/**
 * Submit callback handler for admin settings form.
 *
 * @param $form
 * @param $form_state
 *
 * @return bool
 */
function nys_sendgrid_admin_submit($form, $form_state) {
  $values = $form_state['values'];
  if (!empty($values['nys_sendgrid_apikey'])) {
    variable_set('nys_sendgrid_apikey', check_plain($values['nys_sendgrid_apikey']));
  }
  if (isset($values['nys_sendgrid_suppress_categories'])) {
    variable_set('nys_sendgrid_suppress_categories', (boolean) $values['nys_sendgrid_suppress_categories']);
  }
  variable_set('nys_sendgrid_default_template', $values['nys_sendgrid_default_template']);
  variable_set('nys_sendgrid_suppress_template', (boolean) $values['nys_sendgrid_suppress_template']);

  variable_set('nys_sendgrid_content_substitution', (boolean) $values['nys_sendgrid_content_substitution']);
  variable_set('nys_sendgrid_content_token_body', $values['nys_sendgrid_content_token_body']);
  variable_set('nys_sendgrid_content_token_subject', $values['nys_sendgrid_content_token_subject']);

  $assigns = [];
  if (!empty($values['templates'] ?? [])) {
    foreach ($values['templates'] as $val) {
      if ($val['template_id']) {
        $assigns[$val['mail_key']] = $val['template_id'];
      }
    }
  }
  if (!(empty($values['add_assign_id']) && empty($values['add_assign_name']))) {
    $assigns[$values['add_assign_name']] = $values['add_assign_id'];
  }
  variable_set('nys_sendgrid_template_assignments', $assigns);
  drupal_set_message(t('SendGrid Settings Saved'), 'status', FALSE);

  return TRUE;
}

/**
 * Helper function to create a Drupal Form API element for SendGrid templates.
 *
 * @param string|int $selected The template ID to be marked as selected.
 * @param string $title The title of the form element.
 * @param string $description The description of the form element.
 *
 * @return array The element, as a Drupal Forms API array.
 */
function _nys_sendgrid_construct_template_select($selected = 0, $title = '', $description = '') {
  $all_templates = nys_sendgrid_get_templates();
  $options = [];
  foreach ($all_templates as $id => $temp) {
    $options[$id] = $temp['name'];
  }

  return [
    '#type' => 'select',
    '#title' => $title,
    '#description' => $description,
    '#options' => array_merge([0 => 'None'], $options),
    '#default_value' => $selected,
  ];

}

/**
 * A "private" function to provide easy defaults for the test message form.
 *
 * @return array The defaults.
 */
function _nys_sendgrid_test_defaults() {
  return [
    'fromname' => '',
    'to' => '',
    'toname' => '',
    'subject' => 'Test Email from NYS SendGrid Module',
    'body' => [
      'value' => 'Test Message for SendGrid.',
      'format' => filter_fallback_format(),
    ],
  ];

}

/**
 * Callback to generate the test email form for NYS Sendgrid module.
 *
 * @return array The form.
 */
function nys_sendgrid_test_email() {
  $defaults = variable_get('nys_sendgrid_test_defaults', _nys_sendgrid_test_defaults());

  $form = [
    'intro' => [
      '#markup' => 'Submitting this form will attempt to send an email out via the NYS SendGrid mail system interface.  The attempt will be made using Drupal\'s standard mail system, including any rerouting, etc.<br />NOTE: If the mail system interface assignment for nys_sendgrid has been changed, this will test THAT interface, not nys_sendgrid.',
    ],
    'fromname' => [
      '#type' => 'textfield',
      '#title' => t('From name'),
      '#description' => 'The from address is taken from system variable site_mail',
      '#default_value' => $defaults['fromname'] ?? '',
      '#maxlength' => 128,
    ],
    'to' => [
      '#type' => 'textfield',
      '#title' => t('To'),
      '#default_value' => $defaults['to'] ?? '',
      '#maxlength' => 128,
      '#required' => TRUE,
    ],
    'toname' => [
      '#type' => 'textfield',
      '#title' => t('To Name'),
      '#default_value' => $defaults['toname'] ?? '',
      '#maxlength' => 128,
    ],
    'subject' => [
      '#type' => 'textfield',
      '#title' => t('Subject'),
      '#default_value' => $defaults['subject'],
      '#maxlength' => 128,
      '#required' => TRUE,
    ],
    'body' => [
      '#type' => 'text_format',
      '#title' => t('Body'),
      '#rows' => 20,
      '#default_value' => $defaults['body']['value'],
      '#format' => $defaults['body']['format'],
      '#required' => TRUE,
    ],
    'submit' => [
      '#type' => 'submit',
      '#value' => t('Send test message'),
    ],
  ];

  return $form;
}

/**
 * Submit callback handler for test email form.
 *
 * @param $form
 * @param $form_state
 *
 * @return bool
 */
function nys_sendgrid_test_email_submit($form, &$form_state) {
  // Create defaults array.
  $defaults = [
    'to' => $form_state['values']['to'],
    'subject' => $form_state['values']['subject'],
    'body' => $form_state['values']['body'],
    'toname' => $form_state['values']['toname'],
    'fromname' => $form_state['values']['fromname'],
  ];

  // Set the defaults for reuse.
  variable_set('nys_sendgrid_test_defaults', $defaults);

  $params = [
    'subject' => $form_state['values']['subject'],
    'body' => check_markup(
      $form_state['values']['body']['value'],
      $form_state['values']['body']['format']
    ),
  ];
  $send_to = $form_state['values']['to'];
  if (!empty($form_state['values']['toname'])) {
    $send_to = $form_state['values']['toname'] . ' <' . $send_to . '>';
  }

  // Attempt to send the email and post a message if it was successful.
  $send_from = variable_get('site_mail');
  if (!empty($form_state['values']['fromname'])) {
    $send_from = $form_state['values']['fromname'] . ' <' . $send_from . '>';
  }

  $result = drupal_mail('nys_sendgrid', 'test', $send_to, language_default(), $params, $send_from);

  if (isset($result['result']) && $result['result'] == 'true') {
    drupal_set_message(t('Test email sent from %from to %to.', [
      '%from' => $send_from,
      '%to' => $send_to,
    ]), 'status');
  }

  return $result['result'];
}
