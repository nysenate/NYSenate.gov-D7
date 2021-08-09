<?php

/**
 * @file
 * nys_committees.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function nys_committees_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_featured_legislation_commi|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_featured_legislation_commi';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_featured_bill',
        1 => 'field_featured_quote',
        2 => 'field_featurer_senator',
      ),
    ),
    'fields' => array(
      'field_featured_bill' => 'ds_content',
      'field_featured_quote' => 'ds_content',
      'field_featurer_senator' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_featured_legislation_commi|default'] = $ds_layout;

  return $export;
}
