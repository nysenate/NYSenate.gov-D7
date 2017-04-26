<?php
/**
 * @file
 * Case sensitivity constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_alpha_case_admin_form',
  'constraint callback' => 'password_policy_alpha_case_constraint',
  'message' => t('Password must have upper and lower case letters.'),
  'prime value' => 'alpha_case',
  'config' => array(
    'alpha_case' => NULL,
  ),
);

/**
 * Admin form callback for case sensitivity constraint.
 */
function password_policy_alpha_case_admin_form($form, &$form_state, $constraint) {
  $sub_form['alpha_case_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mixed case'),
  );
  $sub_form['alpha_case_fieldset']['alpha_case'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mixed Case'),
    '#default_value' => $constraint->config['alpha_case'],
    '#description' => t('Password will require upper and lower case letters.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for case sensitivity constraint.
 */
function password_policy_alpha_case_constraint($password, $account, $constraint) {
  $upper = preg_match('/[A-Z]/', $password);
  $lower = preg_match('/[a-z]/', $password);
  return $upper && $lower;
}
