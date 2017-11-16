<?php
/**
 * @file
 * nys_polls.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nys_polls_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|advpoll|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'advpoll';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'advpoll_choice' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_image_main' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['node|advpoll|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nys_polls_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|advpoll|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'advpoll';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image_main',
        1 => 'title',
        2 => 'advpoll_choice',
      ),
    ),
    'fields' => array(
      'field_image_main' => 'ds_content',
      'title' => 'ds_content',
      'advpoll_choice' => 'ds_content',
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
  $export['node|advpoll|teaser'] = $ds_layout;

  return $export;
}
