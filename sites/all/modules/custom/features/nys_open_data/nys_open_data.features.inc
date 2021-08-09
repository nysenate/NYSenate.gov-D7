<?php

/**
 * @file
 * nys_open_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_open_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_open_data_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nys_open_data_node_info() {
  $items = array(
    'open_data' => array(
      'name' => t('Open Data'),
      'base' => 'node_content',
      'description' => t('This is open data entries to be shown as direct links to PDF docs.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
