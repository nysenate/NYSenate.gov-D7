<?php
/**
 * @file
 * uuid features hooks on behalf of the entity_translation module.
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function entity_translation_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  if (entity_translation_enabled($entity_type, $entity)) {
    $entity_info = entity_get_info($entity_type);
    if (isset($entity_info['entity keys']['translations']) && isset($entity->{$entity_info['entity keys']['translations']})) {
      $translations = $entity->{$entity_info['entity keys']['translations']};
      // Don't export certain parts of entity translation.
      if (isset($translations->data)) {
        foreach ($translations->data as $language => $value) {
          // Replace entity_id by uuid.
          if (isset($translations->data[$language]['entity_id'])) {
            $uuids = entity_get_uuid_by_id($entity_type, array($translations->data[$language]['entity_id']));
            $translations->data[$language]['entity_uuid'] = reset($uuids);
          }
          // Replace user id by uuid.
          if (isset($translations->data[$language]['uid'])) {
            $uuids = entity_get_uuid_by_id('user', array($translations->data[$language]['uid']));
            $translations->data[$language]['user_uuid'] = reset($uuids);
          }
          // Remove unnecessary keys.
          unset(
            $translations->data[$language]['uid'],
            $translations->data[$language]['entity_id'],
            $translations->data[$language]['revision_id'],
            $translations->data[$language]['changed']
          );
        }
      }
      // Don't export the translation handler id from entity translation.
      unset($export->entity_translation_handler_id);
    }
  }
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function entity_translation_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  if (entity_translation_enabled($entity_type, $entity)) {
    $entity_info = entity_get_info($entity_type);
    if (isset($entity_info['entity keys']['translations']) && isset($entity->{$entity_info['entity keys']['translations']})) {
      // The translations property of entity translation has to be an object.
      $entity->{$entity_info['entity keys']['translations']} = (object) $entity->{$entity_info['entity keys']['translations']};
      $translations = $entity->{$entity_info['entity keys']['translations']};
      // Don't export certain parts of entity translation.
      if (isset($translations->data)) {
        foreach ($translations->data as $language => $value) {
          // Restore entity_id by uuid.
          if (isset($translations->data[$language]['entity_uuid'])) {
            $entity_ids = entity_get_id_by_uuid($entity_type, array($translations->data[$language]['entity_uuid']));
            $translations->data[$language]['entity_id'] = (!empty($entity_ids)) ? reset($entity_ids) : UUID_FEATURES_DEFAULT_FALLBACK_ID;
          }
          // Replace user id by uuid if possible - set 1 otherwise.
          if (isset($translations->data[$language]['user_uuid'])) {
            $user_ids = entity_get_id_by_uuid('user', array($translations->data[$language]['user_uuid']));
            $translations->data[$language]['uid'] = (!empty($user_ids)) ? reset($user_ids) : UUID_FEATURES_DEFAULT_FALLBACK_ID;
          }
          // Remove unnecessary keys.
          unset(
            $translations->data[$language]['entity_uuid'],
            $translations->data[$language]['user_uuid']
          );
        }
      }
    }
  }
}
