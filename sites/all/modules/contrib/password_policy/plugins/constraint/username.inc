<?php
/**
 * @file
 * Username constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_username_admin_form',
  'constraint callback' => 'password_policy_username_constraint',
  'message' => t('Password must not contain their username.'),
  'prime value' => 'username',
  'config' => array(
    'username' => FALSE,
  ),
);

/**
 * Admin form callback for username constraint.
 */
function password_policy_username_admin_form($form, &$form_state, $constraint) {
  $sub_form['username_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Username'),
  );
  $sub_form['username_fieldset']['username'] = array(
    '#type' => 'checkbox',
    '#title' => t('Password must not contain their username.'),
    '#default_value' => $constraint->config['username'],
  );

  return $sub_form;
}

/**
 * Constraint callback for username constraint.
 */
function password_policy_username_constraint($password, $account, $constraint) {
  $username = _password_policy_username_get_username($account);
  if (empty($username)) {
    return TRUE;
  }
  $regex_string = '/' . preg_quote($username, '/') . '/';
  return !preg_match($regex_string, $password);
}

/**
 * Gets username against which to check password.
 */
function _password_policy_username_get_username($account) {
  $username = '';
  if (isset($_POST['name'])) {
    // The username will not be displayed, so there is no need to filter it
    // with check_plain() or filter_xss() as suggested by Coder.
    // @ignore security_17
    $username = rawurldecode($_POST['name']);
  }
  elseif ($account->uid > 0) {
    // The username input will not be present on the same form as the password
    // input in some configurations (e.g., sites using Password Tab module). So
    // fall back to retrieving the username from the user object.
    $username = $account->name;
  }
  return $username;
}
