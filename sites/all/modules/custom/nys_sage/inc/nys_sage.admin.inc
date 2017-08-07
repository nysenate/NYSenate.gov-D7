<?php

/**
 * @file
 * Admin config functions for nys_registration module.
 */

/**
* Settings form.
*/
function nys_sage_sagemenu($form, &$form_state) {
  $form['nys_sage_use_ssl'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use SSL on API call'),
    '#default_value' => variable_get('nys_sage_use_ssl', FALSE),
    '#description' => t('If checked, calls to the SAGE API will be executed over an SSL connection.'),
  );
  $form['nys_sage_ssl_verifypeer'] = array(
    '#type' => 'checkbox',
    '#title' => t('Verify SSL peer'),
    '#default_value' => variable_get('nys_sage_ssl_verifypeer', FALSE),
    '#description' => t('If checked, cURL must verify the peer certificate when connecting to SAGE.  Normally, this setting should be left on.  If SSL-based SAGE calls fail inexplicably, try turning this off.')
  );
  $form['nys_sage_api_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('SAGE Base URI'),
    '#default_value' => variable_get('nys_sage_api_endpoint', ''),
    '#description' => t('The base URI to the SAGE API.  Note that this field should have only the domain and path to the top-most level of the API.  No endpoint portions should appear here.'),
  );
  $form['nys_sage_logging'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enable SAGE logging'),
    '#default_value' => variable_get('nys_sage_logging', 0),
    '#description'   => t('Check this box to enable logging of all SAGE API calls.  Logs will be written to the nys_sage_log table.'),
    );
  $form['logging_warning'] = array(
    '#children' => t('SAGE call logging can create a significant amount of data in table `nys_sage_log`.<br />  Remember to occasionally TRUNCATE or archive the table occasionally, and disable logging when it is no longer needed.'),
    '#type' => 'container',
    '#attributes' => array('class' => array('warning')),
    '#states' => array(
      'visible' => array(':input[name="nys_sage_logging"]' => array('checked' => TRUE)),
    ),
  );
  return system_settings_form($form);
}

