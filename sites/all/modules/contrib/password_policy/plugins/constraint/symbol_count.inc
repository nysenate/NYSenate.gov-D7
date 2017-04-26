<?php
/**
 * @file
 * Symbol count constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_symbol_count_admin_form',
  'constraint callback' => 'password_policy_symbol_count_constraint',
  'message' => t('Password must have at least @symbol_count symbol(s).'),
  'prime value' => 'symbol_count',
  'config' => array(
    'symbol_count' => NULL,
    'symbol_count_symbols' => "!@#$%^&*()_+=-|}{\"?:><,./;'\[]",
  ),
);

/**
 * Admin form callback for symbol count constraint.
 */
function password_policy_symbol_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['symbol_count_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Symbols'),
  );
  $sub_form['symbol_count_fieldset']['symbol_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum symbols'),
    '#default_value' => $constraint->config['symbol_count'],
    '#description' => t('Password will be required to have this many symbols.'),
  );
  $sub_form['symbol_count_fieldset']['symbol_count_symbols'] = array(
    '#type' => 'textfield',
    '#title' => t('Symbol characters'),
    '#default_value' => $constraint->config['symbol_count_symbols'],
    '#description' => t('Determine which characters are symbols.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for symbol count constraint.
 */
function password_policy_symbol_count_constraint($password, $account, $constraint) {
  $matches = array();
  $pattern = '/[' . preg_quote($constraint->config['symbol_count_symbols'], '/') . ']/';
  $count = preg_match_all($pattern, $password, $matches);
  return $count >= $constraint->config['symbol_count'];
}
