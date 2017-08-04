<?php
/**
 * @file
 * nys_global_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_global_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_global_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nys_global_events_node_info() {
  $items = array(
    'meeting' => array(
      'name' => t('Meeting'),
      'base' => 'node_content',
      'description' => t('This type is used for Senate Committee meetings as well as Session Meetings.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'public_hearing' => array(
      'name' => t('Public Hearing'),
      'base' => 'node_content',
      'description' => t('This type is used for public hearings.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
