<?php
/**
 * @file
 * nys_schools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_schools_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nys_schools_node_info() {
  $items = array(
    'school' => array(
      'name' => t('School'),
      'base' => 'node_content',
      'description' => t('All content for School has been imported from a spreadsheet provided by the NYS Education Department. All updates should be made by reimporting the spreadsheet with the <a href="/admin/config/system/nys-school-import">custom import tool</a>.'),
      'has_title' => '1',
      'title_label' => t('School City - School Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
