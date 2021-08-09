<?php
/**
 * @file
 * nys_polls.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_polls_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_polls_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nys_polls_node_info() {
  $items = array(
    'advpoll' => array(
      'name' => t('Poll Question'),
      'base' => 'node_content',
      'description' => t('Allows offices to add a simple Yes or No poll question to Senator\'s home page or to embed poll into an Article.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
