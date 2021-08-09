<?php
/**
 * @file
 * Features hooks for the uuid_node features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_node_features_export_options() {
  $options = array();

  // Check what content types are enabled for uuid features export.
  $enabled_types = array();
  $entity_info = entity_get_info('node');
  foreach ($entity_info['bundles'] as $key => $value) {
    if (variable_get("uuid_features_entity_node_${key}", FALSE)) {
      $enabled_types[$key] = $key;
    }
  }
  if (!empty($enabled_types)) {
    $types = node_type_get_names();
    $query = db_select('node', 'n');
    $query->fields('n', array('nid', 'title', 'type', 'uuid'))
      ->condition('type', $enabled_types)
      ->orderBy('type')
      ->orderBy('title')
      ->addTag('uuid_node_features_export_options');
    $nodes = $query->execute()->fetchAll();
    foreach ($nodes as $node) {
      $options[$node->uuid] = t('@type: @title', array(
        '@type' => $types[$node->type],
        '@title' => $node->title,
      ));
    }
  }

  drupal_alter('uuid_node_features_export_options', $options);
  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_node_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies']['uuid_features'] = 'uuid_features';

  $nids = entity_get_id_by_uuid('node', $data);
  foreach ($nids as $uuid => $nid) {
    // Load the existing node, with a fresh cache.
    $node = node_load($nid, NULL, TRUE);
    entity_make_entity_universal('node', array($node));

    $export['features']['uuid_node'][$uuid] = $uuid;
    $pipe['node'][$node->type] = $node->type;

    // drupal_alter() normally supports just one byref parameter. Using
    // the __drupal_alter_by_ref key, we can store any additional parameters
    // that need to be altered, and they'll be split out into additional params
    // for the hook_*_alter() implementations.
    $data = &$export;
    $data['__drupal_alter_by_ref']['pipe'] = &$pipe;
    $entity_type = 'node';
    drupal_alter('uuid_entity_features_export', $entity_type, $data, $node, $module);
    drupal_alter('uuid_node_features_export', $data, $node, $module);
    unset($data['__drupal_alter_by_ref']);
  }

  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function uuid_node_features_export_render($module, $data) {
  $translatables = $code = $files = $return = array();

  $code[] = '  $nodes = array();';
  $code[] = '';
  $nids = entity_get_id_by_uuid('node', $data);
  // Always sort by the uuid to ensure the order is maintained.
  ksort($nids);
  foreach ($nids as $uuid => $nid) {
    // Only export the node if it exists.
    if ($nid === FALSE) {
      continue;
    }
    // Attempt to load the node, using a fresh cache.
    $node = node_load($nid, NULL, TRUE);
    if (empty($node)) {
      continue;
    }

    // If pathauto is set to 0, don't override it.
    $uri = entity_uri('node', $node);
    $path = drupal_get_path_alias($uri['path']);

    if ($uri['path'] != $path) {
      // Add path and pathauto settings.
      if (!property_exists($node, 'path')) {
        $node->path = array();
      }

      if (module_exists('pathauto')) {

        // If we're not using pathauto, ensure it is disabled.
        if (!isset($node->path['pathauto']) || $node->path['pathauto'] == 0) {
          $node->path['pathauto'] = FALSE;
          $node->path['alias'] = $path;
        }
        else {
          $node->path['pathauto'] = TRUE;
        }
      }
      else {
        $node->path['alias'] = $path;
      }
    }

    // Clone entity to avoid changes by reference.
    $export = clone $node;

    // Use date instead of created, in the same format used by
    // node_object_prepare().
    $export->date = format_date($export->created, 'custom', 'Y-m-d H:i:s O');

    $files = uuid_features_file_field_export($export, 'node');

    $entity_type = 'node';
    drupal_alter('uuid_entity_features_export_render', $entity_type, $export, $node, $module);
    drupal_alter('uuid_node_features_export_render', $export, $node, $module);

    // Don't cause conflicts with nid/vid/revision_timestamp/changed fields.
    unset($export->revision_uid);
    unset($export->revision_timestamp);
    unset($export->nid);
    unset($export->vid);
    unset($export->vuuid);
    unset($export->changed);
    unset($export->last_comment_timestamp);
    unset($export->last_comment_id);
    unset($export->last_comment_name);
    unset($export->last_comment_uid);
    unset($export->cid);

    $code[] = '  $nodes[] = ' . features_var_export($export) . ';';

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
  $code[] = '  return $nodes;';
  $code = implode("\n", $code);
  $return['uuid_features_default_content'] = $code;

  return $return;
}

/**
 * Implements hook_features_revert().
 */
function uuid_node_features_revert($module) {
  uuid_node_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds nodes based on UUID from code defaults.
 */
function uuid_node_features_rebuild($module) {
  $return = TRUE;

  variable_set('menu_rebuild_needed', FALSE);
  lock_acquire('menu_rebuild');

  if (function_exists('uuid_term_features_rebuild')) {
    // Import the terms first.
    uuid_term_features_rebuild($module);
  }

  $nodes = features_get_default('uuid_node', $module);
  if (!empty($nodes)) {
    module_load_include('inc', 'node', 'node.pages');

    $tmp = array();
    foreach ($nodes as $key => $data) {
      if (isset($data['og_group_ref'])) {
        $tmp[] = $data;
        unset($nodes[$key]);
      }
    }

    $nodes = array_merge($nodes, $tmp);
    $return = uuid_node_features_rebuild_nodes($nodes, $module);

    $entity_type = 'node';
    module_invoke_all('uuid_entity_features_rebuild_complete', $entity_type, $nodes, $module);
  }
  return $return;
}

/**
 * Runs the node import multiple times to resolve dependencies.
 *
 * We might need several runs of ths function to resolve the dependencies
 * created by reference fields. Those can only be resolved if the target node
 * already exists.
 *
 * @param array $nodes
 *   The nodes to process.
 * @param string $module
 *   The module to rebuild for.
 * @param int $max_nesting
 *   Maximal nesting level.
 * @param int $nesting_level
 *   Current nesting level.
 *
 * @return bool
 *   TRUE if all nodes could be restored.
 */
function uuid_node_features_rebuild_nodes($nodes, $module, $max_nesting = 5, $nesting_level = 0) {
  // Max nesting level hit.
  if ($max_nesting < $nesting_level) {
    watchdog('UUID Features', 'Unable to restore nodes. Max nesting level reached.', array(), WATCHDOG_ERROR);
    return FALSE;
  }
  $second_run_nodes = array();
  foreach ($nodes as $data) {
    try {
      $node = (object) $data;
      $node->uid = 0;
      node_object_prepare($node);

      // Find the matching UUID, with a fresh cache.
      $nids = entity_get_id_by_uuid('node', array($node->uuid));
      if (isset($nids[$node->uuid])) {
        $nid = array_key_exists($node->uuid, $nids) ? $nids[$node->uuid] : FALSE;
        $existing = node_load($nid, NULL, TRUE);
        if (!empty($existing)) {
          $node->nid = $existing->nid;
          $node->vid = $existing->vid;
        }
      }

      $entity_type = 'node';
      drupal_alter('uuid_entity_features_rebuild', $entity_type, $node, $data, $module);
      drupal_alter('uuid_node_features_rebuild', $node, $module);

      $node = node_submit($node);
      uuid_features_file_field_import($node, 'node', $module);
      entity_uuid_save('node', $node);

      if (!empty($node->path)) {
        $saved_node = entity_uuid_load('node', array($node->uuid));
        $saved_node = reset($saved_node);
        if (empty($saved_node->path['alias'])) {
          $saved_node->path['alias'] = $node->path['alias'];
          node_save($saved_node);
        }
      }
    }
    catch (Exception $e) {
      $second_run_nodes[] = $data;
    }
  }
  if (!empty($second_run_nodes)) {
    return uuid_node_features_rebuild_nodes($second_run_nodes, $module, $max_nesting, ++$nesting_level);
  }
  lock_release('menu_rebuild');
  variable_set('menu_rebuild_needed', TRUE);
  return TRUE;
}
