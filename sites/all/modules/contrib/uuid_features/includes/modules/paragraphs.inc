<?php
/**
 * @file
 * uuid features hooks on behalf of the paragraphs module.
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function paragraphs_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  $fields = uuid_features_get_field_items_iterator($export, $entity_type, 'paragraphs');
  uuid_features_set_uuid_references($fields, 'paragraphs_item');
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function paragraphs_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'paragraphs');
  uuid_features_fetch_uuid_references($fields, 'paragraphs_item', array(
    'item_id' => 'value',
    'revision_id' => 'revision_id',
  ));
}

/**
 * Implements hook_uuid_entity_features_export_alter().
 */
function paragraphs_uuid_entity_features_export_alter($entity_type, &$data, $entity, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'paragraphs');

  if (!empty($fields)) {
    $paragraphs_ids = array();
    foreach ($fields as $field) {
      foreach ($field as $lang_items) {
        foreach ($lang_items as $values) {
          $paragraphs_ids[] = $values['value'];
        }
      }
    }
    // Add dependencies to paragraphs items.
    $uuids = entity_get_uuid_by_id('paragraphs_item', $paragraphs_ids);
    foreach ($uuids as $uuid) {
      $data['features']['uuid_paragraphs'][$uuid] = $uuid;
    }
  }
}
