<?php
/**
 * @file
 * uuid features hooks on behalf of the user collection module.
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function user_uuid_entity_features_export_render_alter($entity_type, $export, $entity, $module) {
  if (isset($entity->uid) && isset($export->uid)) {
    $uuids = entity_get_uuid_by_id('user', array($entity->uid));
    $uuid = reset($uuids);
    if ($uuid) {
      $export->user_uuid = $uuid;
    }
    unset($export->uid);

    if ($entity_type == 'node') {
      // Ensure we don't export the name or uid property which could lead to a
      // user override due to the handling in node_submit().
      unset($export->name);

      // Remove other properties handled solely by user module.
      unset($export->data, $export->picture);
    }
  }
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function user_uuid_entity_features_rebuild_alter($entity_type, $entity, $data, $module) {
  if (isset($entity->user_uuid) && uuid_is_valid($entity->user_uuid)) {
    $uids = entity_get_id_by_uuid('user', array($entity->user_uuid));
    $uid = reset($uids);
    if ($uid) {
      $entity->uid = $uid;
    }
    else {
      $entity->uid = 1;
    }
  }
  elseif (in_array($entity_type, array('node', 'file'))) {
    $entity->uid = 1;
  }
}
