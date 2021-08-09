<?php

/**
 * @file
 * Hooks for uuid_features on behalf of the file_entity module.
 */

/**
 * Implements hook_uuid_entity_features_export_alter().
 */
function file_entity_uuid_entity_features_export_alter($entity_type, &$data, $entity, $module) {
  // Only alter pipe if the handling of files is enabled.
  $enabled_types = variable_get('uuid_features_entity_file', FALSE);
  $supported_fields = array_map('trim', explode(',', variable_get('uuid_features_file_supported_fields', 'file, image')));
  if ($entity_type == 'file' || empty($enabled_types) || empty($supported_fields)) {
    return;
  }

  list($entity_id, $revision_id, $export_bundle) = entity_extract_ids($entity_type, $entity);

  // Handle referenced file entities in fields and add dependencies where
  // possible.
  $bundles = variable_get('uuid_features_file_' . $entity_type, array());
  if (in_array($export_bundle, $bundles)) {
    $fields = field_info_instances($entity_type, $export_bundle);
    foreach ($fields as $field_name => $field_instance) {
      $field_info = field_info_field($field_name);
      if (!in_array($field_info['type'], $supported_fields) || empty($entity->{$field_name})) {
        continue;
      }
      // Add file entity dependencies.
      foreach ($entity->{$field_name} as $lang_code => $field_values) {
        foreach ($field_values as $i => $field_value) {
          if (!empty($field_value)) {
            $file_entity = (object) $field_value;
            if (!empty($enabled_types[$file_entity->type])) {
              $data['features']['uuid_file_entity'][$file_entity->uuid] = $file_entity->uuid;
            }
          }
        }
      }
    }
  }
}

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function file_entity_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  list($entity_id, $revision_id, $export_bundle) = entity_extract_ids($entity_type, $entity);

  // Handle referenced file entities in fields.
  $supported_fields = array_map('trim', explode(',', variable_get('uuid_features_file_supported_fields', 'file, image')));
  $enabled_types = variable_get('uuid_features_entity_file', FALSE);
  $bundles = variable_get('uuid_features_file_' . $entity_type, array());
  if (in_array($export_bundle, $bundles)) {
    $fields = field_info_instances($entity_type, $export_bundle);
    foreach ($fields as $field_name => $field_instance) {
      $field_info = field_info_field($field_name);
      if (!in_array($field_info['type'], $supported_fields) || empty($export->{$field_name})) {
        continue;
      }
      // Ensure file entity is properly processed for the export.
      foreach ($entity->{$field_name} as $lang_code => $field_values) {
        foreach ($field_values as $i => $field_value) {
          if (!empty($field_value)) {
            $file_entity = (object) $field_value;
            // Export as file entity or inline? Also check that there's an uuid
            // on the file object - if not we're better off with the inline file
            // handling.
            if (!empty($enabled_types[$file_entity->type]) && !empty($file_entity->uuid)) {
              $files_loaded = entity_uuid_load('file', array($file_entity->uuid), array(), TRUE);
              // Ensure additional keys added to the field value are preserved
              // but all the other properties are removed in favor of the uuid.
              $file_export = array(
                'file_uuid' => $file_entity->uuid,
              ) + array_diff_key($field_value, (array) reset($files_loaded));
            }
            else {
              $file_entity_type = 'file';
              $export_file_entity = clone $file_entity;
              drupal_alter('uuid_entity_features_export_render', $file_entity_type, $export_file_entity, $file_entity, $module);
              $file_export = (array) $export_file_entity;
            }
            $export->{$field_name}[$lang_code][$i] = $file_export;
          }
        }
      }
    }
  }

  // Handle file entities itself.
  if ($entity_type == 'file') {
    $info = entity_get_info($entity_type);
    // Ensure we don't export a revision key.
    if (!empty($info['entity keys']['revision']) && isset($export->{$info['entity keys']['revision']})) {
      unset($export->{$info['entity keys']['revision']});
    }
    unset(
      $export->created,
      $export->changed
    );
  }
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function file_entity_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  list($entity_id, $revision_id, $import_bundle) = entity_extract_ids($entity_type, $entity);

  // Ensure the file entity import was run first. The function has a static
  // cache to avoid multiple runs in the same feature module.
  module_load_include('inc', 'uuid_features', 'includes/uuid_file_entity.features');
  uuid_file_entity_features_rebuild($module);

  // Handle referenced file entities in fields.
  // Get all fields from this bundle.
  $fields = field_info_instances($entity_type, $import_bundle);
  $supported_fields = array_map('trim', explode(',', variable_get('uuid_features_file_supported_fields', 'file, image')));

  foreach ($fields as $field_name => $field_instance) {
    if (isset($entity->{$field_name})) {
      // Load field info to check the type.
      $info = field_info_field($field_name);
      if (in_array($info['type'], $supported_fields) && !empty($entity->{$field_name})) {
        // Ensure file entity is properly processed for the import.
        foreach ($entity->{$field_name} as $lang_code => $field_values) {
          foreach ($field_values as $i => $field_value) {
            if (isset($field_value['file_uuid'])) {
              $fids = entity_get_id_by_uuid('file', array($field_value['file_uuid']));
              $import_file_entity = file_load(reset($fids));
              unset($field_value['file_uuid']);
              // Ensure additional added array keys are preserved.
              $entity->{$field_name}[$lang_code][$i] = ((array) $import_file_entity) + $field_value;
            }
            else {
              $file_entity_type = 'file';
              $import_file_entity = (object) $field_value;
              drupal_alter('uuid_entity_features_rebuild', $file_entity_type, $import_file_entity);
              $entity->{$field_name}[$lang_code][$i] = (array) $import_file_entity;
            }
          }
        }
      }
    }
  }
}
