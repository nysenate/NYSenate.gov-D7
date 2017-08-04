<?php
/**
 * @file
 * nys_statutes_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_statutes_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nys_statutes_feature_node_info() {
  $items = array(
    'statute' => array(
      'name' => t('Law'),
      'base' => 'node_content',
      'description' => t('New York State Laws'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
