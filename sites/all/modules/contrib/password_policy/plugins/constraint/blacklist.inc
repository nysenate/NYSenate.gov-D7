<?php
/**
 * @file
 * Blacklist constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_blacklist_admin_form',
  'constraint callback' => 'password_policy_blacklist_constraint',
  'message' => t('Password cannot match certain disallowed passwords.'),
  'prime value' => 'blacklist',
  'config' => array(
    'blacklist' => '',
    'blacklist_match_substrings' => FALSE,
  ),
);

/**
 * Admin form callback for blacklist constraint.
 */
function password_policy_blacklist_admin_form($form, &$form_state, $constraint) {
  $sub_form['blacklist_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Blacklist'),
  );
  $sub_form['blacklist_fieldset']['blacklist'] = array(
    '#type' => 'textarea',
    '#title' => t('Blacklisted passwords'),
    '#default_value' => $constraint->config['blacklist'],
    '#description' => t('Password cannot be a member of this list, ignoring case.  Enter one password per line.'),
  );
  $sub_form['blacklist_fieldset']['blacklist_match_substrings'] = array(
    '#type' => 'checkbox',
    '#title' => t('Also disallow passwords containing blacklisted passwords.'),
    '#default_value' => $constraint->config['blacklist_match_substrings'],
  );

  return $sub_form;
}

/**
 * Constraint callback for blacklist constraint.
 */
function password_policy_blacklist_constraint($password, $account, $constraint) {
  $blacklisted_passwords = _password_policy_blacklist_get_blacklisted_passwords($constraint);
  foreach ($blacklisted_passwords as $blacklisted_password) {
    if (_password_policy_blacklist_match($password, $blacklisted_password, $constraint)) {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Gets blacklisted passwords.
 *
 * @param object $constraint
 *   Constraint object.
 *
 * @return string[]
 *   Blacklisted passwords.
 */
function _password_policy_blacklist_get_blacklisted_passwords($constraint) {
  $blacklisted_passwords = explode("\n", $constraint->config['blacklist']);
  $blacklisted_passwords = array_map('trim', $blacklisted_passwords);
  $blacklisted_passwords = array_filter($blacklisted_passwords, 'strlen');
  return $blacklisted_passwords;
}

/**
 * Checks whether password matches blacklisted password.
 *
 * How a password is matched depends on the constraint configuration.
 *
 * @param string $password
 *   Password.
 * @param string $blacklisted_password
 *   Blacklisted password.
 * @param object $constraint
 *   Constraint object.
 *
 * @return bool
 *   TRUE if the password matches the blacklisted password, FALSE otherwise.
 */
function _password_policy_blacklist_match($password, $blacklisted_password, $constraint) {
  if ($constraint->config['blacklist_match_substrings']) {
    return stripos($password, $blacklisted_password) !== FALSE;
  }
  else {
    return strcasecmp($password, $blacklisted_password) == 0;
  }
}
