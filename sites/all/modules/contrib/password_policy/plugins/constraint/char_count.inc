<?php
/**
 * @file
 * Character count constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_char_count_admin_form',
  'constraint callback' => 'password_policy_char_count_constraint',
  'message' => t('Password must have at least @char_count character(s).'),
  'prime value' => 'char_count',
  'config' => array(
    'char_count' => NULL,
  ),
);

/**
 * Admin form callback for character count constraint.
 */
function password_policy_char_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['char_count_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Character count'),
  );
  $sub_form['char_count_fieldset']['char_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum total characters'),
    '#default_value' => $constraint->config['char_count'],
    '#description' => t('Password will be required to have this many characters.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for character count constraint.
 */
function password_policy_char_count_constraint($password, $account, $constraint) {
  return drupal_strlen($password) >= $constraint->config['char_count'];
}
