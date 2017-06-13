<?php
/**
 * @file
 * uuid features hooks on behalf of the core text module.
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function text_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  list($id, $revision, $bundle) = entity_extract_ids($entity_type, $entity);

  $fields_info = field_info_instances($entity_type, $bundle);
  foreach ($fields_info as $field_name => $value) {
    $field_info = field_info_field($field_name);

    switch ($field_info['type']) {
      // Remove save value from text fields as it can be very installation
      // or location specific and it can be rebuilt later.
      case 'text_with_summary':
      case 'text_long':
      case 'text':
        if (!empty($export->{$field_name})) {
          foreach ($export->{$field_name} as $lang => $terms) {
            foreach ($terms as $k => $v) {
              unset($export->{$field_name}[$lang][$k]['safe_value']);
            }
          }
        }
        break;
    }
  }
}
