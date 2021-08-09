<?php
/**
 * @file
 * nys_variables.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function nys_variables_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'nys_messaging_senator_contact_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['nys_messaging_senator_contact_form'] = $captcha;

  return $export;
}
