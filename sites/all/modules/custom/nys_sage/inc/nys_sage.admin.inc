<?php

/**
 * @file
 * Admin config functions for nys_registration module.
 */

/**
 * Settings form.
 */
function nys_sage_sagemenu($form, &$form_state) {
  $form['nys_sage_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#default_value' => variable_get('nys_sage_api_key', ''),
    '#description' => t('The API key to use with requests.  Note that requests will return a failure if no API key is available.  Callers are responsible for interpreting that failure; they may not be visibly reported.'),
  ];
  $form['nys_sage_use_ssl'] = [
    '#type' => 'checkbox',
    '#title' => t('Use SSL on API call'),
    '#default_value' => variable_get('nys_sage_use_ssl', FALSE),
    '#description' => t('If checked, calls to the SAGE API will be executed over an SSL connection.'),
  ];
  $form['nys_sage_ssl_verifypeer'] = [
    '#type' => 'checkbox',
    '#title' => t('Verify SSL peer'),
    '#default_value' => variable_get('nys_sage_ssl_verifypeer', FALSE),
    '#description' => t('If checked, cURL must verify the peer certificate when connecting to SAGE.  Normally, this setting should be left on.  If SSL-based SAGE calls fail inexplicably, try turning this off.'),
  ];
  $form['nys_sage_api_endpoint'] = [
    '#type' => 'textfield',
    '#title' => t('SAGE Base URI'),
    '#default_value' => variable_get('nys_sage_api_endpoint', ''),
    '#description' => t('The base URI to the SAGE API.  Note that this field should have only the domain and path to the top-most level of the API.  No endpoint portions should appear here.'),
  ];
  $form['nys_sage_logging'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable SAGE logging'),
    '#default_value' => variable_get('nys_sage_logging', 0),
    '#description' => t('Check this box to enable logging of all SAGE API calls.  Logs will be written to the nys_sage_log table.'),
  ];
  $form['nys_sage_logging_warning'] = [
    '#children' => t('SAGE call logging can create a significant amount of data in table `nys_sage_log`.<br />It is strongly recommended to set a maximum retention range, or disable logging if it is not needed.'),
    '#type' => 'container',
    '#attributes' => ['class' => ['warning']],
    '#states' => [
      'visible' => [':input[name="nys_sage_logging"]' => ['checked' => TRUE]],
    ],
  ];
  $form['nys_sage_maximum_retention'] = [
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => 'Maximum Retention',
    '#field_suffix' => t('days'),
    '#description' => 'The maximum number of days to keep a record in the sage log.  Set to zero to keep forever.',
    '#default_value' => variable_get('nys_sage_maximum_retention', 15),
    '#states' => [
      'visible' => [':input[name="nys_sage_logging"]' => ['checked' => TRUE]],
    ],
  ];
  $form['actions']['submit_truncate'] = [
    '#type' => 'submit',
    '#value' => 'Save and Truncate',
    '#submit' => ['nys_sage_truncate_table', 'system_settings_form_submit'],
  ];
  return system_settings_form($form);
}

/**
 * Truncates the nys_sage_log table.
 */
function nys_sage_truncate_table() {
  try {
    db_query('TRUNCATE nys_sage_log;');
    drupal_set_message('Table successfully truncated.');
  }
  catch (Exception $e) {
    drupal_set_message("Could not truncate the table: " . $e->getMessage());
    watchdog('nys_sage', 'Could not truncate nys_sage_log!', ['msg' => $e->getMessage()], WATCHDOG_WARNING);
  }
}
