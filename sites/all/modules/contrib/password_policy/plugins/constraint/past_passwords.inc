<?php
/**
 * @file
 * Password history constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_past_passwords_count_admin_form',
  'constraint callback' => 'password_policy_past_passwords_count_constraint',
  'message' => t('Password cannot match @past_passwords past passwords.'),
  'prime value' => 'past_passwords',
  'config' => array(
    'past_passwords' => NULL,
  ),
);

/**
 * Admin form callback for password history constraint.
 */
function password_policy_past_passwords_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['past_passwords_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Past passwords'),
  );
  $sub_form['past_passwords_fieldset']['past_passwords'] = array(
    '#type' => 'textfield',
    '#title' => t('Check against previous passwords'),
    '#default_value' => $constraint->config['past_passwords'],
    '#description' => t('Password cannot match this many previous passwords.'),
  );

  return $sub_form;
}

/**
 * Constraint callback for password history constraint.
 */
function password_policy_past_passwords_count_constraint($password, $account, $constraint) {
  global $user;

  if (!$account) {
    $account = $user;
  }

  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
  $count = $constraint->config['past_passwords'];
  $match = FALSE;
  // @TODO Find out why the hook_user_load is not running correctly.
  if (!isset($account->password_history)) {
    password_policy_user_load(array($account->uid => $account));
  }

  for ($i = 0; $i < $count; $i++) {
    // If we have that level of depth see if we have a match.
    if (isset($account->password_history[$i])) {
      $match = $match || user_check_password($password, $account->password_history[$i]);
    }
    // If we do not have that amount of history then break out.
    else {
      break;
    }
  }

  return !$match;
}
