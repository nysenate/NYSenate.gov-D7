<?php

/**
 * @file
 * Node functions and hooks for the D8 caching system backport.
 */

/* -----------------------------------------------------------------------
 * Core hooks
 */

/**
 * Implements hook_node_update_index().
 */
function d8cache_node_update_index($node) {
  // Invalidate the node search index.
  drupal_invalidate_cache_tags(array('search_index:node'));

  return '';
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
