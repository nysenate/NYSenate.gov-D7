<?php

/**
 * @file
 * Menu functions and hooks for the D8 caching system backport.
 */

/*
 * @todo In theory we should take over cache_menu and re-act to cache clear
 *       events by invalidating a menu_view tag.
 */

/**
 * Implements hook_preprocess_menu_link().
 */
function d8cache_preprocess_menu_link(&$variables) {
  $link = $variables['element']['#original_link'];

  // Unfortunately preprocess_menu_tree does not have the information we need,
  // so we need to add the cache tag for each menu link in a menu separately.
  drupal_add_cache_tags(_d8cache_menu_link_get_cache_tags($link));
}

/**
 * Implements hook_preprocess_links().
 */
function d8cache_preprocess_links(&$variables) {
  $tag_map = array();
  if (isset($variables['links'])) {
    foreach ($variables['links'] as $link) {
      if (isset($link['#menu_name'])) {
        $tag_map['menu:' . strtr($link['#menu_name'], '-', '_')] = TRUE;
      }
    }
    drupal_add_cache_tags(array_keys($tag_map));
  }
}

/**
 * Implements hook_menu_link_alter().
 */
function d8cache_menu_link_alter(&$item) {
  // @todo This needs an upgrade path for existing menu items.
  $item['options']['#menu_name'] = $item['menu_name'];
}

/**
 * Implements hook_menu_link_insert().
 */
function d8cache_menu_link_insert($link) {
  drupal_invalidate_cache_tags(_d8cache_menu_link_get_cache_tags($link));
}

/**
 * Implements hook_menu_link_update().
 */
function d8cache_menu_link_update($link) {
  drupal_invalidate_cache_tags(_d8cache_menu_link_get_cache_tags($link));
}

/**
 * Implements hook_menu_item_delete().
 */
function d8cache_menu_link_delete($link) {
  drupal_invalidate_cache_tags(_d8cache_menu_link_get_cache_tags($link));
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
 * Get cache tags for menu link.
 */
function _d8cache_menu_link_get_cache_tags($link) {
  return array(
    'menu:' . strtr($link['menu_name'], '-', '_'),
  );
}
