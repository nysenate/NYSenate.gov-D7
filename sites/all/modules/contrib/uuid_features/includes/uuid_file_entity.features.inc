<?php
/**
 * @file
 * Features hooks for the uuid_file_entity features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_file_entity_features_export_options() {
  $options = array();

  // Check what content types are enabled for uuid features export.
  $enabled_types = variable_get('uuid_features_entity_file', FALSE);
  if (!empty($enabled_types)) {
    $query = new EntityFieldQuery();
    $query
      ->entityCondition('entity_type', 'file')
      ->propertyCondition('type', $enabled_types, 'IN')
      ->propertyOrderBy('filename')
      ->propertyOrderBy('type')
      ->addTag('uuid_file_entity_features_export_options');

    $result = $query->execute();
    if (!empty($result['file'])) {
      $files = file_load_multiple(array_keys($result['file']));
      foreach ($files as $file) {
        $options[$file->uuid] = $file->filename;
      }
    }
  }

  drupal_alter('uuid_file_entity_features_export_options', $options);
  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_file_entity_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies']['uuid_features'] = 'uuid_features';

  $fids = entity_get_id_by_uuid('file', $data);
  foreach ($fids as $uuid => $fid) {
    // Load the existing file, with a fresh cache.
    $file = file_load($fid, NULL, TRUE);

    $export['features']['uuid_file_entity'][$uuid] = $uuid;
    $pipe['file'][$file->type] = $file->type;

    // drupal_alter() normally supports just one byref parameter. Using
    // the __drupal_alter_by_ref key, we can store any additional parameters
    // that need to be altered, and they'll be split out into additional params
    // for the hook_*_alter() implementations.
    $data = &$export;
    $data['__drupal_alter_by_ref']['pipe'] = &$pipe;
    $entity_type = 'file';
    drupal_alter('uuid_entity_features_export', $entity_type, $data, $file, $module);
    drupal_alter('uuid_file_entity_features_export', $data, $file, $module);
    unset($data['__drupal_alter_by_ref']);
  }

  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function uuid_file_entity_features_export_render($module, $data) {
  $translatables = $code = array();

  $export_mode = variable_get('uuid_features_file_mode', 'inline');
  switch ($export_mode) {
    case 'local':
      $export_var = 'uuid_features_file_path';
      break;

    case 'remote':
      $export_var = 'uuid_features_file_url';
      break;

    case 'packaged':
      $export_var = 'uuid_features_packaged_file_path';
      break;

    default:
    case 'inline':
      $export_var = 'uuid_features_file_data';
      break;
  }

  $code[] = '  $files = array();';
  $code[] = '';
  $fids = entity_get_id_by_uuid('file', $data);
  // Always sort by the uuid to ensure the order is maintained.
  ksort($fids);
  foreach ($fids as $uuid => $fid) {
    // Only export the file if it exists.
    if ($fid === FALSE) {
      continue;
    }
    // Attempt to load the file, using a fresh cache.
    $file = file_load($fid, NULL, TRUE);
    if (empty($file)) {
      continue;
    }
    if (!empty($file->path)) {
      $file->pathauto_perform_alias = FALSE;
    }
    // Clone entity to avoid changes by reference.
    $export = clone $file;

    // Don't cause conflicts with fid/vid/revision_timestamp/changed fields.
    $export->{$export_var} = uuid_features_file_export($export, $export_mode);

    $entity_type = 'file';
    drupal_alter('uuid_entity_features_export_render', $entity_type, $export, $file, $module);
    drupal_alter('uuid_file_entity_features_export_render', $export, $file, $module);

    unset(
      $export->fid,
      $export->timestamp,
      $export->created
    );

    $code[] = '  $files[] = ' . features_var_export($export, '  ') . ';';
  }

  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }
  $code[] = '  return $files;';
  $code = implode("\n", $code);
  return array('uuid_features_default_file_entities' => $code);
}

/**
 * Implements hook_features_revert().
 */
function uuid_file_entity_features_revert($module) {
  uuid_file_entity_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds files based on UUID from code defaults.
 */
function uuid_file_entity_features_rebuild($module) {
  $rebuild_cache = &drupal_static(__FUNCTION__, array());
  if (!isset($rebuild_cache[$module])) {
    $rebuild_cache[$module] = TRUE;
    module_load_include('inc', 'features', 'features.export');
    $files = features_get_default('uuid_file_entity', $module);
    if (!empty($files)) {

      $rebuild_cache[$module] = uuid_file_entity_features_rebuild_files($files, $module);

      $entity_type = 'file';
      module_invoke_all('uuid_entity_features_rebuild_complete', $entity_type, $files, $module);
    }
  }
  return $rebuild_cache[$module];
}

/**
 * Runs the file import multiple times to resolve dependencies.
 *
 * We might need several runs of ths function to resolve the dependencies
 * created by reference fields. Those can only be resolved if the target file
 * already exists.
 *
 * @param array $files
 *   The files to process.
 * @param string $module
 *   The module to rebuild for.
 * @param int $max_nesting
 *   Maximal nesting level.
 * @param int $nesting_level
 *   Current nesting level.
 *
 * @return bool
 *   TRUE if all files could be restored.
 */
function uuid_file_entity_features_rebuild_files($files, $module, $max_nesting = 5, $nesting_level = 0) {
  // Max nesting level hit.
  if ($max_nesting < $nesting_level) {
    watchdog('UUID Features', 'Unable to restore files. Max nesting level reached.', array(), WATCHDOG_ERROR);
    return FALSE;
  }
  $second_run_files = array();
  foreach ($files as $data) {
    try {
      $file = (object) $data;
      $file->uid = 0;

      // Find the matching UUID, with a fresh cache.
      $fids = entity_get_id_by_uuid('file', array($file->uuid));
      if (isset($fids[$file->uuid])) {
        $fid = array_key_exists($file->uuid, $fids) ? $fids[$file->uuid] : FALSE;
        $existing = file_load($fid);
        if (!empty($existing)) {
          $file->fid = $existing->fid;
        }
      }

      $entity_type = 'file';
      drupal_alter('uuid_entity_features_rebuild', $entity_type, $file, $data, $module);
      drupal_alter('uuid_file_entity_features_rebuild', $file, $module);

      // Already calls file_save().
      _uuid_features_file_field_import_file($file, $module);
    }
    catch (Exception $e) {
      $second_run_files[] = $data;
    }
  }
  if (!empty($second_run_files)) {
    return uuid_file_entity_features_rebuild_files($second_run_files, $module, $max_nesting, ++$nesting_level);
  }
  return TRUE;
}
