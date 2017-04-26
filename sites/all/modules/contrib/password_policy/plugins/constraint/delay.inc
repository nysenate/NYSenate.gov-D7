<?php
/**
 * @file
 * Delay constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_delay_admin_form',
  'constraint callback' => 'password_policy_delay_constraint',
  'message' => t('Password cannot be changed within @delay of the last change.'),
  'prime value' => 'delay',
  'config' => array(
    'delay' => NULL,
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
    '#title' => t('Minimum time between password changes'),
    '#default_value' => $constraint->config['delay'],
    '#description' => t('Password cannot be changed until this much time has passed since the last password change (use normal English, like 1 week or 24 hours).'),
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

  // Apply constraint if most recent password change happened too recently.
  return $account->password_history[0]->created <= strtotime('-' . $constraint->config['delay']);
}
