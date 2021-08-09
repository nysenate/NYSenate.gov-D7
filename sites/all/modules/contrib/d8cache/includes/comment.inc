<?php

/**
 * @file
 * Comment functions and hooks for the D8 caching system backport.
 */

/**
 * Implements hook_comment_insert().
 */
function d8cache_comment_insert($comment) {
  drupal_invalidate_cache_tags(array('node:' . $comment->nid));
}

/**
 * Implements hook_comment_delete().
 */
function d8cache_comment_delete($comment) {
  drupal_invalidate_cache_tags(array('node:' . $comment->nid));
}

/**
 * Implements hook_comment_publish().
 */
function d8cache_comment_publish($comment) {
  drupal_invalidate_cache_tags(array('node:' . $comment->nid));
}

/**
 * Implements hook_comment_unpublish().
 */
function d8cache_comment_unpublish($comment) {
  drupal_invalidate_cache_tags(array('node:' . $comment->nid));
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
