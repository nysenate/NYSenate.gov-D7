<?php
/**
 * @file
 * Letter count constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_alpha_count_admin_form',
  'constraint callback' => 'password_policy_alpha_count_constraint',
  'message' => t('Password must have at least @alpha_count letter(s).'),
  'prime value' => 'alpha_count',
  'config' => array(
    'alpha_count' => NULL,
  ),
);

/**
 * Admin form callback for letter count constraint.
 */
function password_policy_alpha_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['alpha_count_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Letter count'),
  );
  $sub_form['alpha_count_fieldset']['alpha_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum letters'),
    '#default_value' => $constraint->config['alpha_count'],
    '#description' => t('Password will be required to have at least this many letters.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for letter count constraint.
 */
function password_policy_alpha_count_constraint($password, $account, $constraint) {
  $matches = array();
  $count = preg_match_all('/[[:alpha:]]/', $password, $matches);
  return $count >= $constraint->config['alpha_count'];
}
