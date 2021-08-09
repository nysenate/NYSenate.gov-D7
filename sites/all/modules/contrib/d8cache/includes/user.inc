<?php

/**
 * @file
 * User functions and hooks for the D8 caching system backport.
 */

/* -----------------------------------------------------------------------
 * Core hooks
 */

/**
 * Implements hook_user_insert().
 */
function d8cache_user_insert(&$edit, $account, $category) {
  drupal_invalidate_cache_tags(array('search_index:user'));
}

/**
 * Implements hook_user_update().
 */
function d8cache_user_update(&$edit, $account, $category) {
  drupal_invalidate_cache_tags(array('search_index:user'));
}

/**
 * Implements hook_user_cancel().
 */
function d8cache_user_cancel($edit, $account, $method) {
  $tags = array();
  $tags[] = 'user:' . $account->uid;
  $tags[] = 'user_list';
  $tags[] = 'search_index:user';
  drupal_invalidate_cache_tags($tags);
}

/**
 * Implements hook_user_delete().
 */
function d8cache_user_delete($account) {
  drupal_invalidate_cache_tags(array('search_index:user'));
}

/* -----------------------------------------------------------------------
 * Contrib hooks
 */

/* -----------------------------------------------------------------------
 * Public API
 */

/* -----------------------------------------------------------------------
 * Helper functions
 */
