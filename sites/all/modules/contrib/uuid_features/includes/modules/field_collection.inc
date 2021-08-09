<?php
/**
 * @file
 * uuid features hooks on behalf of the field collection module.
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function field_collection_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  $fields = uuid_features_get_field_items_iterator($export, $entity_type, 'field_collection');
  uuid_features_set_uuid_references($fields, 'field_collection_item');
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function field_collection_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'field_collection');
  uuid_features_fetch_uuid_references($fields, 'field_collection_item', array(
    'item_id' => 'value',
    'revision_id' => 'revision_id',
  ));
}

/**
 * Implements hook_uuid_entity_features_export_alter().
 */
function field_collection_uuid_entity_features_export_alter($entity_type, &$data, $entity, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'field_collection');

  if (!empty($fields)) {
    $field_collection_ids = array();
    foreach ($fields as $field) {
      foreach ($field as $lang_items) {
        foreach ($lang_items as $values) {
          $field_collection_ids[] = $values['value'];
        }
      }
    }
    // Add dependencies to field collection items.
    $uuids = entity_get_uuid_by_id('field_collection_item', $field_collection_ids);
    foreach ($uuids as $uuid) {
      $data['features']['uuid_field_collection'][$uuid] = $uuid;
    }
  }
}
