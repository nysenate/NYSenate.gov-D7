<?php

/**
 * @file
 * Delay constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_delay_admin_form',
  'constraint callback' => 'password_policy_delay_constraint',
  'message' => t('Password cannot be changed within @delay of the last @threshold change(s).'),
  'prime value' => 'delay',
  'config' => array(
    'delay' => NULL,
    'threshold' => 1,
  ),
);

/**
 * Admin form callback for delay constraint.
 */
function password_policy_delay_admin_form($form, &$form_state, $constraint) {
  $sub_form['delay_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Delay'),
  );
  $sub_form['delay_fieldset']['delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Time period'),
    '#default_value' => $constraint->config['delay'],
    '#description' => t('Time period during which the number of password changes is restricted. (Use normal English, like 1 week or 24 hours.)'),
  );
  $sub_form['delay_fieldset']['threshold'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of times password can be changed per time period'),
    '#required' => TRUE,
    '#default_value' => $constraint->config['threshold'],
    '#description' => t('Password can be changed this many times within period above.'),
    '#element_validate' => array('element_validate_integer_positive'),
  );
  return $sub_form;
}

/**
 * Constraint callback for delay constraint.
 */
function password_policy_delay_constraint($password, $account, $constraint) {
  // Determine user.
  global $user;
  if (!$account) {
    $account = $user;
  }

  // @TODO Find out why the hook_user_load is not running correctly.
  if (!isset($account->password_history)) {
    password_policy_user_load(array($account->uid => $account));
  }

  // If password has never been changed, don't apply constraint.
  if (empty($account->password_history)) {
    return TRUE;
  }

  $password_index = !empty($constraint->config['threshold']) ? $constraint->config['threshold'] - 1 : 0;

  // The threshold cannot be exceeded if the password has been changed fewer
  // times than the threshold, so don't apply constraint.
  if (!isset($account->password_history[$password_index])) {
    return TRUE;
  }

  // If user has only system-generated password, uses one-time link and has the
  // token in the URL, don't apply constraint.
  $is_password_generated = count($account->password_history) == 1 && $account->password_history[0]->is_generated;
  $is_one_time_login = isset($_SESSION['pass_reset_' . $account->uid], $_GET['pass-reset-token']) && $_GET['pass-reset-token'] === $_SESSION['pass_reset_' . $account->uid];
  if ($is_password_generated && $is_one_time_login) {
    return TRUE;
  }

  // Apply constraint if last number of password changes defined by threshold
  // happened too recently.
  return $account->password_history[$password_index]->created <= strtotime('-' . $constraint->config['delay']);
}
