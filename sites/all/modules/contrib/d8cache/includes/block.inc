<?php

/**
 * @file
 * Block functions and hooks for the D8 caching system backport.
 */

/**
 * Implements hook_block_list_alter().
 */
function d8cache_block_list_alter(&$blocks) {
  foreach ($blocks as $key => $block) {
    $block->drupal_cache_tags[] = 'block_list';
  }
}

/**
 * Implements hook_block_view_alter().
 */
function d8cache_block_view_alter(&$data, $block) {
  $tags = _d8cache_block_get_cache_tags($block);
  $tags[] = 'block_view';
  drupal_add_cache_tags($tags);

  $cid = _block_get_cache_id($block);
  // If this cid is empty, reset the state of the current attachments
  // collector group.
  if (empty($cid)) {
    $cache = d8cache_cache_get_object('cache_block');
    if (is_object($cache) && $cache instanceof D8CacheAttachmentsCollector) {
      /** @var D8CacheAttachmentsCollector $cache */
      $cache->resetCurrentAttachmentsCollector();
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function d8cache_form_block_admin_configure_alter(&$form, $form_state) {
  $form['#submit'][] = '_d8cache_block_admin_configure_submit';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function d8cache_form_block_add_block_form_alter(&$form, $form_state) {
  $form['#submit'][] = '_d8cache_invalidate_block_view_submit';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function d8cache_form_block_custom_block_delete_alter(&$form, $form_state) {
  $form['#submit'][] = '_d8cache_invalidate_block_view_submit';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function d8cache_form_block_admin_display_form_alter(&$form, $form_state) {
  $form['#submit'][] = '_d8cache_invalidate_block_view_submit';
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

/**
 * Get cache tags for block.
 */
function _d8cache_block_get_cache_tags($block) {
  $tags = array();
  $tags[] = 'block:' . $block->module . '.' . str_replace('-', '_', drupal_html_class($block->delta));

  // Allow blocks to set cache tags.
  if (!empty($block->drupal_cache_tags)) {
    $tags = array_merge($tags, $block->drupal_cache_tags);
  }

  return $tags;
}

/**
 * Submit handler for block_admin_configure form.
 */
function _d8cache_block_admin_configure_submit($form, $form_state) {
  if (!form_get_errors()) {
    // Create a pseudo block.
    $block = (object) $form_state['values'];
    drupal_invalidate_cache_tags(_d8cache_block_get_cache_tags($block));
  }
}

/**
 * Submit handler to invalidate block_view cache tag.
 */
function _d8cache_invalidate_block_view_submit($form, $form_state) {
  drupal_invalidate_cache_tags(array('block_view'));
}
