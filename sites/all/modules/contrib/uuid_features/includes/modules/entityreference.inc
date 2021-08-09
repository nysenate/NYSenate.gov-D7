<?php
/**
 * @file
 * uuid features hooks on behalf of the taxonomy module.
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function entityreference_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  $fields = uuid_features_get_field_items_iterator($export, $entity_type, 'entityreference');
  _entity_reference_uuid_entity_features_export_set_uuid_references($fields);
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function entityreference_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'entityreference');
  _entity_reference_uuid_entity_features_rebuild_fetch_uuid_references($fields);
}

/**
 * Helper function to fetch uuid references in case of different fields types.
 *
 * @param array $fields
 *   A list of entityreference fields to handle.
 */
function _entity_reference_uuid_entity_features_rebuild_fetch_uuid_references(&$fields) {
  // Entityreference fields may have different targets (nodes, users, etc.).
  // So we process them one by one.
  foreach ($fields as $field_name => $field) {
    $field_info = field_info_field($field_name);
    $entity_info = entity_get_info($field_info['settings']['target_type']);

    // uuid_features_fetch_uuid_references accepts only references to array as
    // the first parameter.
    $tmp_fields = array(
      $field_name => &$field,
    );

    uuid_features_fetch_uuid_references($tmp_fields, $field_info['settings']['target_type'], array(
      $entity_info['entity keys']['id'] => 'target_id',
    ));
  }
}

/**
 * Helper function to set uuid references in case of different fields types.
 *
 * @param array $fields
 *   A list of entityreference fields to handle.
 */
function _entity_reference_uuid_entity_features_export_set_uuid_references(&$fields) {
  // Entityreference fields may have different targets (nodes, users, etc.).
  // So we process them one by one.
  foreach ($fields as $field_name => &$field) {
    $field_info = field_info_field($field_name);

    // uuid_features_fetch_uuid_references accepts only references to array as
    // the first parameter.
    $tmp_fields = array(
      $field_name => &$field,
    );

    uuid_features_set_uuid_references($tmp_fields, $field_info['settings']['target_type']);
  }
}
