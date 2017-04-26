<?php
/**
 * @file
 * Drush command hooks for the Safe cache_form Clear module.
 */

/**
 * Implements hook_drush_command().
 */
function safe_cache_form_clear_drush_command() {
  $items = array();

  $items['safe-cache-form-clear'] = array(
    'description' => t('Clear a limited number of expired items from the cache_form bin.'),
  );

  return $items;
}

/**
 * Implements drush_COMMAND().
 */
function drush_safe_cache_form_clear() {
  safe_cache_form_clear();
}
