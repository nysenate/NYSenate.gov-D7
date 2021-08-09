<?php

/**
 * @file
 * Features hooks for the uuid_fpp features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_fpp_features_export_options() {
  $options = array();

  $query = db_select('fieldable_panels_panes', 'f')
    ->fields('f', array('fpid', 'admin_title', 'title', 'bundle', 'uuid'))
    ->orderBy('f.bundle', 'ASC')
    ->orderBy('f.title', 'ASC')
    ->addTag('uuid_fpp_features_export_options');

  $results = $query->execute()->fetchAll();
  foreach ($results as $fpp) {
    $bundle_name = ucwords(str_replace('_', ' ', $fpp->bundle));
    $display_title = ($fpp->admin_title) ? $fpp->admin_title : $fpp->uuid;

    $options[$fpp->uuid] = $bundle_name . ' - ' . $display_title;
  }

  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_fpp_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['fieldable_panels_panes'] = 'fieldable_panels_panes';
  $export['dependencies']['uuid_features'] = 'uuid_features';

  // Add extra dependencies so we don't lose track of bundles.
  $fpp_modules = _uuid_fpp_features_dependencies($data);
  foreach ($fpp_modules as $module) {
    $export['dependencies'][$module] = $module;
  }

  $fpids = entity_get_id_by_uuid('fieldable_panels_pane', $data);
  foreach ($fpids as $uuid => $fpid) {
    // Load the FPP matching the $fpid.
    $query = new EntityFieldQuery();
    $fpp = $query
      // We just want one FPP: the one matching
      // the current $fpid.
      ->entityCondition('entity_type', 'fieldable_panels_pane')
      ->propertyCondition('fpid', $fpid)
      ->range(0, 1)
      ->execute();

    $export['features']['uuid_fpp'][$uuid] = $uuid;
    $pipe['fieldable_panels_pane'][$fpp['fieldable_panels_pane'][$fpid]->bundle] = $fpp['fieldable_panels_pane'][$fpid]->bundle;

    // drupal_alter() normally supports just one byref parameter. Using
    // the __drupal_alter_by_ref key, we can store any additional parameters
    // that need to be altered, and they'll be split out into additional params
    // for the hook_*_alter() implementations.  The hook_alter signature is
    // hook_uuid_fpp_features_export_alter(&$export, &$pipe, $fpp).
    $data = &$export;
    $data['__drupal_alter_by_ref']['pipe'] = array(&$pipe);
    drupal_alter('uuid_fpp_features_export', $data, $fpp);
  }

  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function uuid_fpp_features_export_render($module, $data) {
  $translatables = $code = array();

  $code[] = '  $fpps = array();';
  $code[] = '';
  foreach ($data as $uuid) {
    // @todo reset = TRUE as otherwise references (parent, fields) were
    // destroyed.
    $fpps = entity_uuid_load('fieldable_panels_pane', array($uuid), array(), TRUE);
    if (!count($fpps)) {
      continue;
    }

    $first_fpp = reset($fpps);
    $export = clone $first_fpp;

    $entity_type = 'fieldable_panels_pane';
    drupal_alter('uuid_entity_features_export_render', $entity_type, $export, $first_fpp, $module);

    // Do not export ids.
    unset($export->vid);
    unset($export->fpid);
    unset($export->current_vid);
    unset($export->changed);
    unset($export->uid);

    uuid_features_file_field_export($export, 'fieldable_panels_pane');

    $json = json_encode($export);
    $export_array = json_decode($json, TRUE);

    $code[] = '  $fpps[] = ' . features_var_export($export_array, '  ') . ';';
  }

  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }

  $code[] = '  return $fpps;';
  $code = implode("\n", $code);
  return array('uuid_features_default_fpps' => $code);
}

/**
 * Implements hook_features_revert().
 */
function uuid_fpp_features_revert($module) {
  uuid_fpp_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds terms based on UUID from code defaults.
 */
function uuid_fpp_features_rebuild($module) {
  $fpps = features_get_default('uuid_fpp', $module);

  if (!empty($fpps)) {
    // Get info about current FPP types available in system.
    $entity_info = entity_get_info('fieldable_panels_pane');
    $entity_type = 'fieldable_panels_pane';

    // Loop through the export.
    foreach ($fpps as $data) {
      // Double-check that FPP can be created/reverted.
      if (!isset($entity_info['bundles'][$data['bundle']])) {
        drupal_set_message('Bundle not found for fieldable panels pane of type ' . $data['bundle'] . '. Fieldable panels pane was not created/reverted.', 'warning');
      }
      else {
        // If this is an update, there will be a by-UUID matching FPP.
        $existing = entity_get_id_by_uuid('fieldable_panels_pane', array($data['uuid']));
        if (!empty($existing)) {
          $fpp = entity_load_single('fieldable_panels_pane', $existing[$data['uuid']]);
          foreach ($data as $key => $value) {
            $fpp->$key = $value;
          }
        }
        else {
          // Create a new FPP.
          $fpp = entity_create('fieldable_panels_pane', $data);
        }

        drupal_alter('uuid_entity_features_rebuild', $entity_type, $fpp, $data, $module);

        uuid_features_file_field_import($fpp, 'fieldable_panels_pane');

        if (!fieldable_panels_panes_save($fpp)) {
          drupal_set_message('Failed to create ' . $data['bundle'] . ' fieldable panels pane ' . $data['label'], 'error');
        }
      }
    }
    module_invoke_all('uuid_entity_features_rebuild_complete', $entity_type, $fpps, $module);
  }
}

/**
 * Discovers modules which affect the FPP bundle info for dependency mapping.
 */
function _uuid_fpp_features_dependencies($uuids) {
  $implements = array();

  $entity_info = array();
  $bundles = array();
  foreach (entity_uuid_load('fieldable_panels_pane', $uuids, array(), TRUE) as $entity) {
    list(, , $bundle) = entity_extract_ids('fieldable_panels_pane', $entity);
    $bundles[$bundle] = $bundle;
  }

  // Check for modules that affect the bundle info of the given entity's bundle.
  foreach (module_implements('entity_info') as $module) {
    $result = module_invoke($module, 'entity_info');
    foreach ($bundles as $bundle) {
      if (isset($result['fieldable_panels_pane']['bundles'][$bundle])) {
        $implements[$module] = $module;
      }

      if (isset($result) && is_array($result)) {
        $entity_info = array_replace_recursive($entity_info, $result);
      }
    }
  }

  foreach ($entity_info as $name => $data) {
    $entity_info[$name] += array(
      'fieldable' => FALSE,
      'controller class' => 'DrupalDefaultEntityController',
      'static cache' => TRUE,
      'field cache' => TRUE,
      'load hook' => $name . '_load',
      'bundles' => array(),
      'view modes' => array(),
      'entity keys' => array(),
      'translation' => array(),
    );
    $entity_info[$name]['entity keys'] += array(
      'revision' => '',
      'bundle' => '',
    );
    foreach ($entity_info[$name]['view modes'] as $view_mode => $view_mode_info) {
      $entity_info[$name]['view modes'][$view_mode] += array(
        'custom settings' => FALSE,
      );
    }
    // If no bundle key is provided, assume a single bundle, named after
    // the entity type.
    if (empty($entity_info[$name]['entity keys']['bundle']) && empty($entity_info[$name]['bundles'])) {
      $entity_info[$name]['bundles'] = array($name => array('label' => $entity_info[$name]['label']));
    }
    // Prepare entity schema fields SQL info for
    // DrupalEntityControllerInterface::buildQuery().
    if (isset($entity_info[$name]['base table'])) {
      $entity_info[$name]['schema_fields_sql']['base table'] = drupal_schema_fields_sql($entity_info[$name]['base table']);
      if (isset($entity_info[$name]['revision table'])) {
        $entity_info[$name]['schema_fields_sql']['revision table'] = drupal_schema_fields_sql($entity_info[$name]['revision table']);
      }
    }
  }

  // Discover all modules which implement entity_info_alter.
  foreach (module_implements('entity_info_alter') as $module) {
    $function = $module . '_entity_info_alter';
    if (function_exists($function)) {
      // Keep a backup of the FPP entity info so we can compare it later.
      $backup = $entity_info['fieldable_panels_pane']['bundles'];
      $function($entity_info);

      foreach ($bundles as $bundle) {
        // Check if the module changes anything in the entity info.
        if (isset($backup[$bundle]) && !isset($entity_info['fieldable_panels_pane']['bundles'][$bundle])) {
          $implements[$module] = $module;
        }
        elseif ($backup[$bundle] != $entity_info['fieldable_panels_pane']['bundles'][$bundle]) {
          $implements[$module] = $module;
        }
      }
    }
  }
  return $implements;
}

/**
 * If the PHP version is < 5.3.0 we need to create array_replace_recursive().
 */
if (!function_exists('array_replace_recursive')) {

  /**
   * Replaces elements from passed arrays into the first array recursively.
   *
   * @link http://php.net/manual/en/function.array-replace-recursive.php
   *
   * @param array $array
   *   The array in which elements are replaced.
   * @param array $array1
   *   The array from which elements will be extracted.
   *
   * @return array|null
   *   An array, or null if an error occurs.
   */
  function array_replace_recursive(array $array, array $array1) {
    // Get array arguments.
    $arrays = func_get_args();

    // Define the original array.
    $original = array_shift($arrays);

    // Loop through arrays.
    foreach ($arrays as $array) {
      // Loop through array key/value pairs.
      foreach ($array as $key => $value) {
        // Value is an array.
        if (is_array($value)) {
          // Traverse the array; replace or add result to original array.
          $original[$key] = array_replace_recursive($original[$key], $array[$key]);
        }
        // Value is not an array.
        else {
          // Replace or add current value to original array.
          $original[$key] = $value;
        }
      }
    }

    // Return the joined array.
    return $original;
  }

}
