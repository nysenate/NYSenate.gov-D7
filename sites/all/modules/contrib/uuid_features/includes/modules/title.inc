<?php
/**
 * @file
 * uuid features hooks on behalf of the title module.
 * @link https://www.drupal.org/project/title
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function title_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  $entity_info = entity_get_info($entity_type);

  // Don't export title module original fields.
  // @see title_field_sync_get()
  if (isset($entity_info['field replacement'])) {
    foreach ($entity_info['field replacement'] as $legacy_field => $replacement_info) {
      // Remove legacy field backup from title module.
      unset($export->{$legacy_field . '_original'});
    }
  }
}
