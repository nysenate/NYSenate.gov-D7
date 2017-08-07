<?php

/**
 * @file
 * The media_livestream/includes/media_livestream.variables.inc file.
 *
 * Variable defaults for Media: Livestream.
 */

/**
 * Define our constants.
 */

/**
 * This is the variable namespace, automatically prepended to module variables.
 */
define('MEDIA_LIVESTREAM_NAMESPACE', 'media_livestream__');

/**
 * This is the rest point for the Livestream channel api.
 */
define('MEDIA_LIVESTREAM_REST_CHANNEL_API', 'api.channel.livestream.com/2.0/');

/**
 * This is the rest point for the Livestream account api.
 */
define('MEDIA_LIVESTREAM_REST_ACCOUNT_API', 'api.account.livestream.com/2.0/');

/**
 * This is the rest point for the Livestream guide api.
 */
define('MEDIA_LIVESTREAM_REST_GUIDE_API', 'channelguide.api.livestream.com/programguide');

/**
 * Wrapper for variable_get() using the Media: Livestream variable registry.
 *
 * @param string $name
 *   The variable name to retrieve. Note that it will be namespaced by
 *   pre-pending MEDIA_LIVESTREAM_NAMESPACE, as to avoid variable collisions
 *   with other modules.
 *
 * @param unknown $default
 *   An optional default variable to return if the variable hasn't been set
 *   yet. Note that within this module, all variables should already be set
 *   in the media_livestream_variable_default() function.
 *
 * @return unknown
 *   Returns the stored variable or its default.
 *
 * @see media_livestream_variable_set()
 * @see media_livestream_variable_del()
 * @see media_livestream_variable_default()
 */
function media_livestream_variable_get($name, $default = NULL) {
  // Allow for an override of the default.
  // Useful when a variable is required (like $path),
  // but namespacing is still desired.
  if (!isset($default)) {
    $default = media_livestream_variable_default($name);
  }
  // Namespace all variables.
  $variable_name = MEDIA_LIVESTREAM_NAMESPACE . $name;
  return variable_get($variable_name, $default);
}

/**
 * Wrapper for variable_set() using the Media: Livestream variable registry.
 *
 * @param string $name
 *   The variable name to set. Note that it will be namespaced by
 *   pre-pending MEDIA_LIVESTREAM_NAMESPACE, as to avoid variable collisions with
 *   other modules.
 *
 * @param unknown $value
 *   The value for which to set the variable.
 *
 * @return unknown
 *   Returns the stored variable after setting.
 *
 * @see media_livestream_variable_get()
 * @see media_livestream_variable_del()
 * @see media_livestream_variable_default()
 */
function media_livestream_variable_set($name, $value) {
  $variable_name = MEDIA_LIVESTREAM_NAMESPACE . $name;
  return variable_set($variable_name, $value);
}

/**
 * Wrapper for variable_del() using the Media: Livestream variable registry.
 *
 * @param string $name
 *   The variable name to delete. Note that it will be namespaced by
 *   pre-pending MEDIA_LIVESTREAM_NAMESPACE, as to avoid variable collisions with
 *   other modules.
 *
 * @see media_livestream_variable_get()
 * @see media_livestream_variable_set()
 * @see media_livestream_variable_default()
 */
function media_livestream_variable_del($name) {
  $variable_name = MEDIA_LIVESTREAM_NAMESPACE . $name;
  variable_del($variable_name);
}

/**
 * The default variables within the Media: Livestream namespace.
 *
 * @param string $name
 *   Optional variable name to retrieve the default. Note that it has not yet
 *   been prepended with the MEDIA_LIVESTREAM_NAMESPACE namespace at this time.
 *
 * @return unknown
 *   The default value of this variable, if it's been set, or NULL, unless
 *   $name is NULL, in which case we return an array of all default values.
 *
 * @see media_livestream_variable_get()
 * @see media_livestream_variable_set()
 * @see media_livestream_variable_del()
 */
function media_livestream_variable_default($name = NULL) {
  static $defaults;

  if (!isset($defaults)) {
    $defaults = array(
      'width' => 640,
      'height' => 388,
      'autoplay_video' => false,
      'autoplay_channel' => false,
      'protocol' => 'https:',
      'protocol_specify' => FALSE,
      'mute' => false,
      'layout' => 4,
    );
  }

  if (!isset($name)) {
    return $defaults;
  }

  if (isset($defaults[$name])) {
    return $defaults[$name];
  }
}

/**
 * Return the fully namespace variable name.
 *
 * @param string $name
 *   The variable name to retrieve the namespaced name.
 *
 * @return string
 *   The fully namespace variable name, prepended with
 *   MEDIA_LIVESTREAM_NAMESPACE.
 */
function media_livestream_variable_name($name) {
  return MEDIA_LIVESTREAM_NAMESPACE . $name;
}
