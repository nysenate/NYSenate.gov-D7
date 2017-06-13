<?php
/**
 * @file
 * Features hooks for the uuid_current_search features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_current_search_configuration_features_export_options() {
  $options = array();

  $current_search_items = db_select('block_current_search', 'b')
    ->fields('b', array('delta', 'searcher'))
    ->addTag('uuid_current_search_configuration_features_export_options')
    ->execute()
    ->fetchAllAssoc('delta');

  foreach ($current_search_items as $config) {
    $options[$config->delta] = $config->delta;
  }

  drupal_alter('uuid_current_search_configuration_features_export_options', $options);

  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_current_search_configuration_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['current_search'] = 'current_search';

  foreach ($data as $uuid) {
    $export['features']['uuid_current_search_configuration'][$uuid] = $uuid;
  }
  return array();
}

/**
 * Implements hook_features_export_render().
 */
function uuid_current_search_configuration_features_export_render($module, $data) {
  $translatables = $code = array();

  $code[] = '  $current_search_configurations = array();';
  $code[] = '';
  foreach ($data as $uuid) {
    $block_config = db_select('block_current_search', 'b')
      ->fields('b', array('delta', 'searcher'))
      ->condition('b.delta', $uuid)
      ->execute()
      ->fetchAssoc();

    if ($block_config) {
      $code[] = '  $current_search_configurations[] = ' . features_var_export($block_config, '  ') . ';';
    }
  }

  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }
  $code[] = '  return $current_search_configurations;';
  $code = implode("\n", $code);
  return array('uuid_features_default_current_search_configurations' => $code);
}

/**
 * Implements hook_features_revert().
 */
function uuid_current_search_configuration_features_revert($module) {
  uuid_current_search_configuration_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function uuid_current_search_configuration_features_rebuild($module) {
  $block_current_search_configurations = features_get_default('uuid_current_search_configuration', $module);
  if (!empty($block_current_search_configurations)) {
    foreach ($block_current_search_configurations as $block_current_search_configuration) {
      db_delete('block_current_search')
        ->condition('delta', $block_current_search_configuration['delta'])
        ->execute();
      $record = new stdClass();
      $record->delta = $block_current_search_configuration['delta'];
      $record->searcher = $block_current_search_configuration['searcher'];
      drupal_write_record('block_current_search', $record);
    }
  }
}
