<?php
/**
 * @file
 * Drupal strength constraint for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_drupal_strength_admin_form',
  'constraint callback' => 'password_policy_drupal_strength_constraint',
  'message' => t('Password must match a strength level.'),
  'prime value' => 'drupal_strength',
  'config' => array(
    'drupal_strength' => NULL,
  ),
);

/**
 * Admin form callback for Drupal strength constraint.
 */
function password_policy_drupal_strength_admin_form($form, &$form_state, $constraint) {
  $sub_form['drupal_strength_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Drupal strength'),
  );
  $sub_form['drupal_strength_fieldset']['drupal_strength'] = array(
    '#type' => 'textfield',
    '#title' => t('Drupal strength level'),
    '#default_value' => $constraint->config['drupal_strength'],
    '#description' => t('<p>Password will be required to have this level or higher. 0 - 100</p>
<p>Starting from a base of 100 points:</p>
<ul><li>Having only 3 out of 4 of uppercase, lowercase, digit, and symbol loses 12.5 points</li>
<li>Having only 2 out of 4 of uppercase, lowercase, digit, and symbol loses 25 points</li>
<li>Having only 1 out of 4 of uppercase, lowercase, digit, and symbol loses 40 points</li>
<li>Each character fewer than 6 loses 5 points, plus a 30 point penalty for being under 6 characters.</li>
<li>Username used as password without regard to case gets exactly 5 points</li></ul>
<p>For example:</p>
<ul><li>Aa1! is worth 100 - 10 - 30 = 60 points</li>
<li>ABCDefgh is worth 100 - 25 = 75 points</li>
<li>ABcd12#$ is worth 100 points</li>
<li>jsmith23 and JSmith23 are each worth 5 points for user jsmith23 but 75 or 87.5 points respectively for user rlee98</li></ul>'),
  );

  return $sub_form;
}

/**
 * Constraint callback for Drupal strength constraint.
 */
function password_policy_drupal_strength_constraint($password, $account, $constraint) {
  $weaknesses = 0;
  $strength = 100;
  $has_lowercase = preg_match('/[a-z]+/', $password);
  $has_uppercase = preg_match('/[A-Z]+/', $password);
  $has_numbers = preg_match('/[0-9]+/', $password);
  $has_punctuation = preg_match('/[^a-zA-Z0-9]+/', $password);
  // Lose 5 points for every character less than 6, plus a 30 point penalty.
  if (strlen($password) < 6) {
    $strength -= ((6 - strlen($password)) * 5) + 30;
  }
  // Count weaknesses.
  if (!$has_lowercase) {
    ++$weaknesses;
  }
  if (!$has_uppercase) {
    ++$weaknesses;
  }
  if (!$has_numbers) {
    ++$weaknesses;
  }
  if (!$has_punctuation) {
    ++$weaknesses;
  }
  // Apply penalty for each weakness (balanced against length penalty).
  switch ($weaknesses) {
    case 1:
      $strength -= 12.5;
      break;

    case 2:
      $strength -= 25;
      break;

    case 3:
      $strength -= 40;
      break;

    case 4:
      $strength -= 40;
      break;
  }
  // Check if password is the same as the username.
  $username = _password_policy_drupal_strength_get_username($account);
  if ($password !== '' && strtolower($password) === strtolower($username)) {
    // Passwords the same as username are always very weak.
    $strength = 5;
  }
  return $strength >= $constraint->config['drupal_strength'];
}

/**
 * Gets username against which to check password.
 */
function _password_policy_drupal_strength_get_username($account) {
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
