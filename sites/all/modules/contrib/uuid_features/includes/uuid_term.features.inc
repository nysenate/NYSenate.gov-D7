<?php
/**
 * @file
 * Features hooks for the uuid_term features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_term_features_export_options() {
  $options = array();

  // Check what vocabularies are enabled for uuid features export.
  $vocabs = array();
  $entity_info = entity_get_info('taxonomy_term');
  foreach ($entity_info['bundles'] as $key => $value) {
    if (variable_get("uuid_features_entity_taxonomy_term_${key}", FALSE)) {
      $vocabs[$key] = $key;
    }
  }
  if (!empty($vocabs)) {
    $query = db_select('taxonomy_term_data', 't');
    $query->innerJoin('taxonomy_vocabulary', 'v', 't.vid = v.vid');
    $query->condition('v.machine_name', array_keys($vocabs))
      ->fields('t', array('tid', 'name', 'uuid'))
      ->addField('v', 'name', 'vname');
    $query->orderBy('v.name', 'ASC');
    $query->orderBy('t.name', 'ASC');
    $query->addTag('uuid_term_features_export_options');
    $results = $query->execute()->fetchAll();

    foreach ($results as $term) {
      $options[$term->uuid] = $term->vname . ' - ' . $term->name;
    }
  }

  drupal_alter('uuid_term_features_export_options', $options);
  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_term_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies']['taxonomy'] = 'taxonomy';
  $export['dependencies']['uuid'] = 'uuid';
  $export['dependencies']['uuid_features'] = 'uuid_features';

  $entity_type = 'taxonomy_term';
  // Load all the terms at once by their uuid.
  $terms = entity_uuid_load($entity_type, $data);

  foreach ($terms as $term) {
    uuid_term_features_get_dependencies($export, $term->uuid, $module_name);

    $alter_data = &$export;
    $alter_data['__drupal_alter_by_ref']['pipe'] = &$pipe;
    drupal_alter('uuid_entity_features_export', $entity_type, $export, $term, $module_name);
    drupal_alter('uuid_term_features_export', $alter_data, $term, $module_name);
    unset($alter_data['__drupal_alter_by_ref']);
  }
  return $pipe;
}

/**
 * Adds terms and its dependencies to the export.
 *
 * Parents and term references are handled recursively, other references are not
 * yet supported.
 */
function uuid_term_features_get_dependencies(&$export, $uuid, $module_name = '') {
  $map = features_get_default_map('taxonomy');
  $terms = entity_uuid_load('taxonomy_term', array($uuid));
  if (!isset($export['features']['uuid_term'])) {
    $export['features']['uuid_term'] = array();
  }
  if (!isset($export['features']['taxonomy'])) {
    $export['features']['taxonomy'] = array();
  }
  if (count($terms)) {
    $term = reset($terms);
    $export['features']['uuid_term'][$uuid] = $uuid;
    $machine_name = $term->vocabulary_machine_name;
    if (isset($map[$machine_name]) && $map[$machine_name] != $module_name) {
      $export['dependencies'][$map[$machine_name]] = $map[$machine_name];
    }
    else {
      $export['features']['taxonomy'][$machine_name] = $machine_name;
    }
    // Recursively add all parents and the references of the parents.
    foreach (taxonomy_get_parents($term->tid) as $parent) {
      if (!in_array($parent->uuid, $export['features']['uuid_term'])) {
        uuid_term_features_get_dependencies($export, $parent->uuid, $module_name);
      }
    }
    // Get term references.
    $instances = field_info_instances('taxonomy_term', $machine_name);
    foreach ($instances as $field_name => $instance) {
      $field = field_info_field($field_name);
      if ($field['type'] == 'taxonomy_term_reference') {
        if (isset($term->$field_name)) {
          foreach ($term->$field_name as $lang => $values) {
            foreach ($values as $value) {
              // $value['tid'] already contains the UUID.
              if (!in_array($value['tid'], $export['features']['uuid_term'])) {
                uuid_term_features_get_dependencies($export, $value['tid'], $module_name);
              }
            }
          }
        }
      }
    }
  }
}

/**
 * Implements hook_features_export_render().
 */
function uuid_term_features_export_render($module, $data) {
  $translatables = $code = array();

  $code[] = '  $terms = array();';
  $code[] = '';
  foreach ($data as $uuid) {
    $terms = entity_uuid_load('taxonomy_term', array($uuid));
    if (!count($terms)) {
      continue;
    }

    // Export the parent uuids.
    foreach ($terms as $term) {
      if ($parents = taxonomy_get_parents($term->tid)) {
        foreach ($parents as $parent) {
          $term->parent[] = $parent->uuid;
        }
      }
    }

    $first_term = reset($terms);
    // Clone entity to avoid changes by reference.
    $export = clone $first_term;

    // Do not export ids.
    unset($export->vid);
    unset($export->tid);
    // No need to export the rdf mapping.
    unset($export->rdf_mapping);
    $files = uuid_features_file_field_export($export, 'taxonomy_term');

    $entity_type = 'taxonomy_term';
    drupal_alter('uuid_entity_features_export_render', $entity_type, $export, $first_term, $module);

    $code[] = '  $terms[] = ' . features_var_export(get_object_vars($export), '  ') . ';';

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
  $code[] = '  return $terms;';
  $code = implode("\n", $code);

  $return['uuid_features_default_terms'] = $code;

  return $return;
}

/**
 * Implements hook_features_revert().
 */
function uuid_term_features_revert($module) {
  uuid_term_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds terms based on UUID from code defaults.
 */
function uuid_term_features_rebuild($module) {
  variable_set('menu_rebuild_needed', FALSE);
  lock_acquire('menu_rebuild');

  // Import the vocabularies first.
  taxonomy_features_rebuild($module);
  field_features_rebuild($module);

  $terms = features_get_default('uuid_term', $module);
  if (!empty($terms)) {
    // Verify that term objects is saved before any references are resolved.
    foreach ($terms as $data) {
      $existing = entity_get_id_by_uuid('taxonomy_term', array($data['uuid']));
      if (!count($existing)) {
        $voc = taxonomy_vocabulary_machine_name_load($data['vocabulary_machine_name']);
        // Only save the term, if the corresponding vocabulary already exists.
        if ($voc) {
          $term = new stdClass();
          $term->uuid = $data['uuid'];
          $term->vid = $voc->vid;
          $term->name = $data['name'];
          taxonomy_term_save($term);
        }
      }
    }
    $entity_type = 'taxonomy_term';
    // Save all other data and resolve references.
    foreach ($terms as $data) {
      $term = (object) $data;
      $voc = taxonomy_vocabulary_machine_name_load($term->vocabulary_machine_name);
      if ($voc) {
        $term->vid = $voc->vid;

        drupal_alter('uuid_entity_features_rebuild', $entity_type, $term, $data, $module);

        uuid_features_file_field_import($term, 'taxonomy_term', $module);
        entity_uuid_save('taxonomy_term', $term);
      }
    }
    module_invoke_all('uuid_entity_features_rebuild_complete', $entity_type, $terms, $module);
  }

  lock_release('menu_rebuild');
  variable_set('menu_rebuild_needed', TRUE);
}
