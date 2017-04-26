<?php
/**
 * @file
 * Numeric count constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_int_count_admin_form',
  'constraint callback' => 'password_policy_int_count_constraint',
  'message' => t('Password must have at least @int_count digit(s).'),
  'prime value' => 'int_count',
  'config' => array(
    'int_count' => NULL,
  ),
);

/**
 * Admin form callback for numeric count constraint.
 */
function password_policy_int_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['int_count_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Number count'),
  );
  $sub_form['int_count_fieldset']['int_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum integers'),
    '#default_value' => $constraint->config['int_count'],
    '#description' => t('Password will be required to have this many integers.'),
  );
  return $sub_form;
}

/**
 * Constraint callback for numeric count constraint.
 */
function password_policy_int_count_constraint($password, $account, $constraint) {
  $matches = array();
  $count = preg_match_all('/[[:digit:]]/', $password, $matches);
  return $count >= $constraint->config['int_count'];
}
