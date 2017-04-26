<?php
/**
 * @file
 * Consecutive character count constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_consecutive_admin_form',
  'constraint callback' => 'password_policy_consecutive_constraint',
  'message' => t('Password must have fewer than @consecutive_char_count identical consecutive characters.'),
  'prime value' => 'consecutive_char_count',
  'config' => array(
    'consecutive_char_count' => NULL,
  ),
);

/**
 * Admin form callback for consecutive character count constraint.
 */
function password_policy_consecutive_admin_form($form, &$form_state, $constraint) {
  $sub_form['consecutive_char_count_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Consecutive character count'),
  );
  $sub_form['consecutive_char_count_fieldset']['consecutive_char_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Consecutive character count'),
    '#default_value' => $constraint->config['consecutive_char_count'],
    '#description' => t('Password must have fewer than this number of identical consecutive characters.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for consecutive character count constraint.
 */
function password_policy_consecutive_constraint($password, $account, $constraint) {
  $pattern = '/(.)\1{' . ($constraint->config['consecutive_char_count'] - 1) . '}/';
  return !preg_match($pattern, $password);
}
