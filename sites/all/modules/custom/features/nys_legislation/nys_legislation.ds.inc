<?php
/**
 * @file
 * nys_legislation.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nys_legislation_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|transcript|search_index';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'transcript';
  $ds_fieldsetting->view_mode = 'search_index';
  $ds_fieldsetting->settings = array(
    'node_type' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|transcript|search_index'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nys_legislation_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_ol_votes|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_ol_votes';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_ol_vote_type',
        1 => 'field_ol_excused_count',
        2 => 'field_ol_aye_wr_count',
        3 => 'field_ol_committee',
        4 => 'field_ol_nay_count',
        5 => 'field_ol_aye_count',
        6 => 'field_ol_aye_names',
        7 => 'field_ol_abstained_count',
      ),
    ),
    'fields' => array(
      'field_ol_vote_type' => 'ds_content',
      'field_ol_excused_count' => 'ds_content',
      'field_ol_aye_wr_count' => 'ds_content',
      'field_ol_committee' => 'ds_content',
      'field_ol_nay_count' => 'ds_content',
      'field_ol_aye_count' => 'ds_content',
      'field_ol_aye_names' => 'ds_content',
      'field_ol_abstained_count' => 'ds_content',
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
  $export['field_collection_item|field_ol_votes|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|bill|bill_list_item';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'bill';
  $ds_layout->view_mode = 'bill_list_item';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_ol_print_no',
        1 => 'field_ol_name',
        2 => 'field_issues',
        3 => 'field_ol_chamber',
        4 => 'field_ol_sponsor',
        5 => 'field_ol_sponsor_name',
        6 => 'field_ol_session',
        7 => 'field_ol_votes',
        8 => 'field_ol_last_status',
        9 => 'field_ol_last_status_date',
        10 => 'field_ol_latest_status_committee',
        11 => 'field_ol_all_statuses',
      ),
    ),
    'fields' => array(
      'field_ol_print_no' => 'ds_content',
      'field_ol_name' => 'ds_content',
      'field_issues' => 'ds_content',
      'field_ol_chamber' => 'ds_content',
      'field_ol_sponsor' => 'ds_content',
      'field_ol_sponsor_name' => 'ds_content',
      'field_ol_session' => 'ds_content',
      'field_ol_votes' => 'ds_content',
      'field_ol_last_status' => 'ds_content',
      'field_ol_last_status_date' => 'ds_content',
      'field_ol_latest_status_committee' => 'ds_content',
      'field_ol_all_statuses' => 'ds_content',
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
  $export['node|bill|bill_list_item'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|bill|node_embed';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'bill';
  $ds_layout->view_mode = 'node_embed';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_ol_chamber',
        1 => 'field_ol_name',
        2 => 'field_ol_print_no',
        3 => 'field_ol_sponsor',
        4 => 'field_ol_sponsor_name',
        5 => 'field_ol_all_statuses',
        6 => 'field_ol_latest_status_committee',
        7 => 'field_ol_amendments',
        8 => 'field_ol_session',
        9 => 'field_issues',
        10 => 'field_ol_votes',
        11 => 'field_ol_last_status',
        12 => 'field_ol_last_status_date',
        13 => 'field__constituent_vote',
        14 => 'field_ol_co_sponsors',
        15 => 'field_ol_multi_sponsors',
      ),
    ),
    'fields' => array(
      'field_ol_chamber' => 'ds_content',
      'field_ol_name' => 'ds_content',
      'field_ol_print_no' => 'ds_content',
      'field_ol_sponsor' => 'ds_content',
      'field_ol_sponsor_name' => 'ds_content',
      'field_ol_all_statuses' => 'ds_content',
      'field_ol_latest_status_committee' => 'ds_content',
      'field_ol_amendments' => 'ds_content',
      'field_ol_session' => 'ds_content',
      'field_issues' => 'ds_content',
      'field_ol_votes' => 'ds_content',
      'field_ol_last_status' => 'ds_content',
      'field_ol_last_status_date' => 'ds_content',
      'field__constituent_vote' => 'ds_content',
      'field_ol_co_sponsors' => 'ds_content',
      'field_ol_multi_sponsors' => 'ds_content',
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
  $export['node|bill|node_embed'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function nys_legislation_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'bill_list_item';
  $ds_view_mode->label = 'Bill List Item';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['bill_list_item'] = $ds_view_mode;

  return $export;
}
