<?php

/**
 * @file
 * Special character count constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_special_count_admin_form',
  'constraint callback' => 'password_policy_special_count_constraint',
  'message' => t('Password must have at least @special_count special character(s).'),
  'prime value' => 'special_count',
  'config' => array(
    'special_count' => NULL,
    'special_count_chars' => '`~!@#$%^&*()_+=-|}{"?:><,./;\'\\[]',
  ),
);

/**
 * Admin form callback for special character count constraint.
 */
function password_policy_special_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['special_count_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Special characters'),
  );
  $sub_form['special_count_fieldset']['special_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum special characters'),
    '#default_value' => $constraint->config['special_count'],
    '#description' => t('Password will be required to have this many special characters.'),
  );
  $sub_form['special_count_fieldset']['special_count_chars'] = array(
    '#type' => 'textfield',
    '#title' => t('Special characters'),
    '#default_value' => $constraint->config['special_count_chars'],
    '#description' => t('Determine which characters are special characters.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for special character count constraint.
 */
function password_policy_special_count_constraint($password, $account, $constraint) {
  $matches = array();
  $pattern = '/[' . preg_quote($constraint->config['special_count_chars'], '/') . ']/';
  $count = preg_match_all($pattern, $password, $matches);
  return $count >= $constraint->config['special_count'];
}
