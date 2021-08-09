<?php
/**
 * @file
 * Features hooks for the uuid_paragraphs features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_paragraphs_features_export_options() {
  $options = array();
  $all_ids = array();
  $enabled_bundles = array();

  $entity_info = entity_get_info('paragraphs_item');
  foreach ($entity_info['bundles'] as $key => $value) {
    // Only allow enabled bundles to be exported.
    if (variable_get("uuid_features_entity_paragraphs_item_${key}", FALSE)) {
      $enabled_bundles[] = $key;
    }
  }
  if ($enabled_bundles) {
    $efq_paragraphs_items = new EntityFieldQuery();
    $efq_paragraphs_items->entityCondition('entity_type', 'paragraphs_item');
    $efq_paragraphs_items->entityCondition('bundle', $enabled_bundles);
    $efq_paragraphs_items->addTag('uuid_paragraphs_features_export_options');
    $result = $efq_paragraphs_items->execute();

    if (!empty($result['paragraphs_item'])) {
      $all_ids = array_keys($result['paragraphs_item']);
    }

    $items = entity_load('paragraphs_item', $all_ids);

    foreach ($items as $item) {
      $info = $item->instanceInfo();

      $options[$item->uuid] = t('@type: @title', array(
        '@type' => $info['label'] . " Field",
        '@title' => $item->bundle . " - " . $item->item_id,
      ));
    }
  }

  drupal_alter('uuid_paragraphs_features_export_options', $options);
  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_paragraphs_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['paragraphs'] = 'paragraphs';
  $export['dependencies']['uuid'] = 'uuid';
  $export['dependencies']['uuid_features'] = 'uuid_features';

  foreach ($data as $uuid) {
    $export['features']['uuid_paragraphs'][$uuid] = $uuid;
  }
  return array();
}

/**
 * Implements hook_features_export_render().
 */
function uuid_paragraphs_features_export_render($module, $data) {
  $translatables = $code = $return = array();

  $code[] = '  $paragraphs = array();';
  $code[] = '';
  foreach ($data as $uuid) {
    $paragraphs = entity_uuid_load('paragraphs_item', array($uuid), array(), TRUE);
    if (!count($paragraphs)) {
      continue;
    }

    $paragraph = reset($paragraphs);
    // Clone entity to avoid changes by reference.
    $export = clone $paragraph;

    // Do not export ids.
    unset($export->item_id);
    unset($export->revision_id);

    $files = uuid_features_file_field_export($export, 'paragraphs_item');

    $entity_type = 'paragraphs_item';
    drupal_alter('uuid_entity_features_export_render', $entity_type, $export, $paragraph, $module);

    $code[] = '  $paragraphs[] = ' . features_var_export(get_object_vars($export), '  ') . ';';

    // Add packaged files, if any.
    if (!empty($files)) {
      foreach ($files as $filename => $src_path) {
        $return[$filename] = $src_path;
      }
    }
  }

  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }
  $code[] = '  return $paragraphs;';
  $code = implode("\n", $code);

  $return['uuid_features_default_paragraphs'] = $code;
  return $return;
}

/**
 * Implements hook_features_revert().
 */
function uuid_paragraphs_features_revert($module) {
  uuid_paragraphs_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function uuid_paragraphs_features_rebuild($module) {
  // Make sure all referenced entities exist.
  if (module_exists('taxonomy')) {
    // This module may not be installed.
    taxonomy_features_rebuild($module);
  }
  field_features_rebuild($module);
  uuid_node_features_rebuild($module);
  cache_clear_all();

  $paragraphs = features_get_default('uuid_paragraphs', $module);
  if (!empty($paragraphs)) {
    $entity_type = 'paragraphs_item';
    foreach ($paragraphs as $paragraphs_item) {
      try {
        $fields = field_info_instances('paragraphs_item', $paragraphs_item['bundle']);
        foreach ($fields as $field_name => $field_instance_config) {
          $field_config = field_info_field($field_name);
          if (isset($paragraphs_item[$field_name])) {
            foreach ($paragraphs_item[$field_name] as $lang => $field_data) {
              foreach ($field_data as $delta => $value) {
                if ($field_config['type'] == 'entityreference' || $field_config['type'] == 'taxonomy_term_reference') {
                  $columns = array_keys($field_config['columns']);
                  $first_column = reset($columns);
                  if (isset($field_config['settings']['target_type'])) {
                    $target_entity = $field_config['settings']['target_type'];
                  }
                  elseif ($field_config['type'] == 'taxonomy_term_reference') {
                    $target_entity = 'taxonomy_term';
                  }
                  else {
                    throw new Exception('Unknown target.');
                  }
                  $ids = entity_get_id_by_uuid($target_entity, array($value[$first_column]));
                  $paragraphs_item[$field_name][$lang][$delta][$first_column] = $ids ? reset($ids) : UUID_FEATURES_DEFAULT_FALLBACK_ID;
                }
              }
            }
          }
        }

        // Create a new paragraphs.
        $paragraphs_item['original'] = TRUE;
        $entity = entity_import('paragraphs_item', json_encode($paragraphs_item));
        // Hack to ignore missing host entities.
        /* @var ParagraphsItemEntity $entity */
        $entity->is_new = FALSE;

        // If this is an update, there will be a by-UUID matching paragraphs
        // and we'll use that object for further processing.
        $existing = entity_get_id_by_uuid('paragraphs_item', array($paragraphs_item['uuid']));
        if (!empty($existing)) {
          $entity = entity_load_single('paragraphs_item', $existing[$paragraphs_item['uuid']]);
          foreach ($paragraphs_item as $key => $value) {
            $entity->$key = $value;
          }
        }

        drupal_alter('uuid_entity_features_rebuild', $entity_type, $entity, $paragraphs_item, $module);

        uuid_features_file_field_import($entity, 'paragraphs_item', $module);

        $entity->save(TRUE);
      }
      catch (Exception $e) {

      }
    }
    module_invoke_all('uuid_entity_features_rebuild_complete', $entity_type, $paragraphs, $module);
  }
  uuid_node_features_rebuild($module);
}
