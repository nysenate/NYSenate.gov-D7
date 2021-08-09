<?php

/**
 * @file
 * Helper functions for login_history that have no dependencies.
 *
 * @see https://funcptr.net/2014/06/10/tamper-proof-session-cookies-and-session-storage/
 * @see https://paragonie.com/blog/2015/05/using-encryption-and-authentication-correctly
 */

/**
 * Gets a device id from a login history cookie while validating authenticity.
 *
 * @param array $cookie
 *   The cookie array i.e. $_COOKIE.
 * @param string $salt
 *   The salt, e.g. from drupal_get_hash_salt().
 *
 * @return string
 *   The device id, if it exists and is authenticated by the hmac.
 *
 * @throws Exception
 *   If there's any problem parsing the cookie.
 */
function login_history_get_device_id_from_cookie($cookie, $salt) {
  // Is the cookie value even set?
  if (array_key_exists('Drupal_visitor_login_history', $cookie)) {

    // Are the elements set? Does it have some data right elements?
    $potential_device_message = explode('-', $cookie['Drupal_visitor_login_history']);
    if (3 == count($potential_device_message)) {

      list($message_hmac, $device_id, $login_id) = $potential_device_message;
      // Test all the required data is present and minimally valid.
      if (strlen($message_hmac) == 64 && strlen($device_id) == 64 && !empty($login_id)) {
        // If the hmac is valid, return the device id.
        if (hash_equals(login_history_assemble_cookie($device_id, $login_id, $salt), $cookie['Drupal_visitor_login_history'])) {
          return $device_id;
        }
        throw new Exception('Invalid login history hmac');

      }
      throw new Exception('Login history cookie data not structured properly.');

    }
    throw new Exception('Invalid login history cookie data.');

  }
  throw new Exception('Login history device id not present.');
}

/**
 * Assembles and signs a device ID cookie.
 *
 * @param string $device_id
 *   The device id.
 * @param int $login_id
 *   The login_history.login_id.
 * @param $salt
 *   The salt, e.g. from drupal_get_hash_salt().
 *
 * @return string
 *   A signed string to set in a cookie.
 */
function login_history_assemble_cookie($device_id, $login_id, $salt) {
  $message = $device_id . '-' . $login_id;
  return hash_hmac('sha256', $message, $salt) . '-' . $message;
}

/**
 * Compares strings in constant time.
 *
 * @param string $known_string
 *   The expected string.
 * @param string $user_string
 *   The user supplied string to check.
 *
 * @return bool
 *   Returns TRUE when the two strings are equal, FALSE otherwise.
 */
if (!function_exists('hash_equals')) {
  function hash_equals($known_string, $user_string) {
    // Backport of hash_equals() function from PHP 5.6
    // @see https://github.com/php/php-src/blob/PHP-5.6/ext/hash/hash.c#L739
    if (!is_string($known_string)) {
      trigger_error(sprintf("Expected known_string to be a string, %s given", gettype($known_string)), E_USER_WARNING);
      return FALSE;
    }

    if (!is_string($user_string)) {
      trigger_error(sprintf("Expected user_string to be a string, %s given", gettype($user_string)), E_USER_WARNING);
      return FALSE;
    }

    $known_len = strlen($known_string);
    if ($known_len !== strlen($user_string)) {
      return FALSE;
    }

    // This is security sensitive code. Do not optimize this for speed.
    $result = 0;
    for ($i = 0; $i < $known_len; $i++) {
      $result |= (ord($known_string[$i]) ^ ord($user_string[$i]));
    }

    return $result === 0;
  }
}
