<?php

/**
 * @file
 * Entity functions and hooks for the D8 caching system backport.
 */

/**
 * Implements hook_entity_view().
 */
function d8cache_entity_view($entity, $entity_type, $view_mode, $langcode) {
  $tags = _d8cache_entity_get_cache_tags($entity_type, $entity);
  $tags[] = $entity_type . '_view';

  if ($entity_type == 'node' && $view_mode != 'full') {
    // @todo Find a better way to add list cache tags.
    $tags = array_merge($tags, _d8cache_entity_get_list_cache_tags($entity_type, $entity));
  }

  $entity->content['#attached']['drupal_add_cache_tags'][][0] = $tags;
}

/**
 * Implements hook_entity_load().
 */
function d8cache_entity_load($entities, $entity_type) {
  $disabled = &drupal_static(__FUNCTION__, FALSE);

  if ($disabled) {
    return;
  }

  $tags = array();
  foreach ($entities as $entity_id => $entity) {
    $tags[] = $entity_type . ':' . $entity_id;
  }

  drupal_add_cache_tags($tags);
}

/**
 * Implements hook_entity_insert().
 */
function d8cache_entity_insert($entity, $entity_type) {
  _d8cache_entity_invalidate_cache_tags($entity_type, $entity);
}

/**
 * Implements hook_entity_update().
 */
function d8cache_entity_update($entity, $entity_type) {
  _d8cache_entity_invalidate_cache_tags($entity_type, $entity);
}

/**
 * Implements hook_entity_delete().
 */
function d8cache_entity_delete($entity, $entity_type) {
  _d8cache_entity_invalidate_cache_tags($entity_type, $entity);
}

/* -----------------------------------------------------------------------
 * Contrib hooks
 */

/**
 * Implements hook_entitycache_load().
 */
function d8cache_entitycache_load($entities, $entity_type) {
  d8cache_entity_load($entities, $entity_type);
}

/* -----------------------------------------------------------------------
 * Public API
 */

/**
 * Temporarily disable adding of cache tags during entity loading.
 */
function d8cache_disable_cache_tags_for_entity_load($new_state = NULL) {
  $state = &drupal_static('d8cache_entity_load', FALSE);
  $old_state = $state;

  if ($new_state !== NULL) {
    $state = $new_state;
  }

  return $old_state;
}

/* -----------------------------------------------------------------------
 * Helper functions
 */

/**
 * Invalidate entity specific cache tags.
 */
function _d8cache_entity_invalidate_cache_tags($entity_type, $entity) {
  $tags = _d8cache_entity_get_list_cache_tags($entity_type, $entity);
  $tags = array_merge($tags, _d8cache_entity_get_cache_tags($entity_type, $entity));

  drupal_invalidate_cache_tags($tags);
}

/**
 * Get cache tags for an entity type.
 */
function _d8cache_entity_get_list_cache_tags($entity_type, $entity = NULL) {
  $return = array($entity_type . '_list');
  if (!empty($entity)) {
    list(,, $entity_bundle) = entity_extract_ids($entity_type, $entity);
    $return[] = $entity_type . '_' . $entity_bundle . '_list';
  }
  return $return;
}

/**
 * Get cache tags for an entity.
 */
function _d8cache_entity_get_cache_tags($entity_type, $entity) {
  list($entity_id,,) = entity_extract_ids($entity_type, $entity);
  return array(
    $entity_type . ':' . $entity_id,
  );
}
