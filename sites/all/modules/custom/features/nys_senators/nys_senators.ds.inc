<?php
/**
 * @file
 * nys_senators.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nys_senators_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|senator|agenda_senator_sponsors';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'senator';
  $ds_fieldsetting->view_mode = 'agenda_senator_sponsors';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|senator|agenda_senator_sponsors'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|senator|senator_search_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'senator';
  $ds_fieldsetting->view_mode = 'senator_search_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|senator|senator_search_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|senator|senators_involved';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'senator';
  $ds_fieldsetting->view_mode = 'senators_involved';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|senator|senators_involved'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|senator|sponsor_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'senator';
  $ds_fieldsetting->view_mode = 'sponsor_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|senator|sponsor_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|senator|sponsor_list_bill_detail';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'senator';
  $ds_fieldsetting->view_mode = 'sponsor_list_bill_detail';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|senator|sponsor_list_bill_detail'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|senator|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'senator';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'span',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|senator|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nys_senators_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|senator|agenda_senator_sponsors';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'senator';
  $ds_layout->view_mode = 'agenda_senator_sponsors';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image_headshot',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image_headshot' => 'ds_content',
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
  );
  $export['node|senator|agenda_senator_sponsors'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|senator|senator_search_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'senator';
  $ds_layout->view_mode = 'senator_search_list';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_conference',
        2 => 'field_image_headshot',
        3 => 'field_party',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_conference' => 'ds_content',
      'field_image_headshot' => 'ds_content',
      'field_party' => 'ds_content',
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
  );
  $export['node|senator|senator_search_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|senator|senators_involved';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'senator';
  $ds_layout->view_mode = 'senators_involved';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image_headshot',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image_headshot' => 'ds_content',
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
  );
  $export['node|senator|senators_involved'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|senator|sponsor_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'senator';
  $ds_layout->view_mode = 'sponsor_list';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_current_duties',
        2 => 'field_conference',
        3 => 'field_image_headshot',
        4 => 'field_party',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_current_duties' => 'ds_content',
      'field_conference' => 'ds_content',
      'field_image_headshot' => 'ds_content',
      'field_party' => 'ds_content',
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
  );
  $export['node|senator|sponsor_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|senator|sponsor_list_bill_detail';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'senator';
  $ds_layout->view_mode = 'sponsor_list_bill_detail';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_party',
        1 => 'title',
        2 => 'field_conference',
        3 => 'field_image_headshot',
      ),
    ),
    'fields' => array(
      'field_party' => 'ds_content',
      'title' => 'ds_content',
      'field_conference' => 'ds_content',
      'field_image_headshot' => 'ds_content',
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
  );
  $export['node|senator|sponsor_list_bill_detail'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|senator|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'senator';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
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
  $export['node|senator|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function nys_senators_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'agenda_senator_sponsors';
  $ds_view_mode->label = 'Agenda Senator Sponsors';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['agenda_senator_sponsors'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'senator_search_list';
  $ds_view_mode->label = 'Senator Search List';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['senator_search_list'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'senators_involved';
  $ds_view_mode->label = 'Senators Involved';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['senators_involved'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sponsor_list';
  $ds_view_mode->label = 'Sponsor List';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['sponsor_list'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sponsor_list_bill_detail';
  $ds_view_mode->label = 'Sponsor List Bill Detail';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['sponsor_list_bill_detail'] = $ds_view_mode;

  return $export;
}
