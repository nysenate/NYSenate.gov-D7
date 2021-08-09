<?php

/**
 * @file
 * Views hooks for the D8 caching system backport.
 */

/**
 * Implements hook_views_pre_render().
 */
function d8cache_views_pre_render(&$view) {
  $tags = _d8cache_views_get_cache_tags($view);
  drupal_add_cache_tags($tags);
}

/* -----------------------------------------------------------------------
 * Helper functions
 */

/**
 * Get the cache tags for a view.
 */
function _d8cache_views_get_cache_tags($view) {
  return array(
    'views:' . $view->name,
    'views:' . $view->name . '.' . $view->current_display,
  );
}
