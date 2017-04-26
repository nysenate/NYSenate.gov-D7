<?php

/**
 * @file
 * Session API admin functions.
 */

/**
 * Session API admin settings form.
 */
function session_api_settings_form() {
  // Find modules that implement hook_session_api_cleanup().
  $modules = module_implements('session_api_cleanup');

  // Cookie expiry.
  $form['session_api_cookie_expire_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie expire time'),
    '#description' => t("The <strong>Session API</strong> module sets an additional cookie in the end users' browsers in order to better track sessions across logins and logouts. This is the amount of time, in seconds, that the cookie will stay valid in a user's browser. If set to -1, then the cookie will expire when the session ends (i.e, when the browser closes)"),
    '#default_value' => variable_get('session_api_cookie_expire_time', 2592000),
  );

  // Cookie name.
  $description = t('This name will be used for the cookie key used by this module. Certain names for cookies might be incompatible with caching systems such as Varnish.');
  $description .= ' ' . t('<strong>Warning</strong>: Changing the cookie name will invalidate all current Session API sessions. A new cookie could also conflict with another module\'s cookie name.');
  $form['session_api_cookie_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie name'),
    '#default_value' => session_api_get_cookie_name(),
    '#description' => $description,
  );

  return system_settings_form($form);
}
