<?php

/**
 * @file
 * Documents Services API Key Authentication's hooks for API reference.
 */

/**
 * Alter whether the API key is considered valid or not, before the access
 * callback returns. This allows you to add your own logic to the callback.
 *
 * @param &$valid
 *   Boolean showing whether the API key is already considered valid.
 *
 * @param &$args
 *   Array of arguments passed to the access callback. Can be useful for context.
 */
function hook_services_api_key_valid_alter(&$valid, &$args) {
  if (arg(0) === 'xyz-rest' && arg(1) === 'allow-everyone') {
    $valid = TRUE;
  }
}
