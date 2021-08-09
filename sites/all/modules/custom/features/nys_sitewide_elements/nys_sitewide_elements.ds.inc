<?php

/**
 * @file
 * nys_sitewide_elements.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nys_sitewide_elements_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|image|square_image';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'square_image';
  $ds_fieldsetting->settings = array(
    'field_file_image_title_text' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['file|image|square_image'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|student_program|search_index';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'student_program';
  $ds_fieldsetting->view_mode = 'search_index';
  $ds_fieldsetting->settings = array(
    'node_type' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
    'title' => array(
      'format' => 'default',
      'formatter_settings' => array(
        'class' => '',
        'link' => '1',
        'wrapper' => 'h2',
      ),
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['node|student_program|search_index'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nys_sitewide_elements_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_details|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_details';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_honoree_name' => 'ds_content',
      'field_link' => 'ds_content',
      'field_subheading' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_honoree_name',
        1 => 'field_subheading',
        2 => 'field_link',
      ),
    ),
    'wrappers' => array(),
  );
  $export['field_collection_item|field_details|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_group_members|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_group_members';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_committee_member_name' => 'ds_content',
      'field_committee_member_url' => 'ds_content',
      'field_misc_committee_member_role' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_committee_member_name',
        1 => 'field_misc_committee_member_role',
        2 => 'field_committee_member_url',
      ),
    ),
    'wrappers' => array(),
  );
  $export['field_collection_item|field_group_members|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_file_image_title_text' => 'ds_content',
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_file_image_title_text',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['file|image|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|landscape_inline';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'landscape_inline';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_file_image_title_text' => 'ds_content',
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_file_image_title_text',
      ),
    ),
    'wrappers' => array(),
  );
  $export['file|image|landscape_inline'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|media_landscape_image';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'media_landscape_image';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_file_image_title_text' => 'ds_content',
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_file_image_title_text',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['file|image|media_landscape_image'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|media_portrait_image';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'media_portrait_image';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_file_image_title_text' => 'ds_content',
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_file_image_title_text',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['file|image|media_portrait_image'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|media_signature';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'media_signature';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['file|image|media_signature'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|portrait_inline';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'portrait_inline';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_file_image_title_text' => 'ds_content',
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_file_image_title_text',
      ),
    ),
    'wrappers' => array(),
  );
  $export['file|image|portrait_inline'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|square_image';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'square_image';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_file_image_title_text' => 'ds_content',
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_file_image_title_text',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['file|image|square_image'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|video|flex_video';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'flex_video';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'file' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
      ),
    ),
    'wrappers' => array(),
  );
  $export['file|video|flex_video'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page_content|token';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page_content';
  $ds_layout->view_mode = 'token';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'body' => 'ds_content',
      'field_active' => 'ds_content',
      'field_chapters' => 'ds_content',
      'field_date' => 'ds_content',
      'field_image_main' => 'ds_content',
      'field_show_sharing_options' => 'ds_content',
      'webform' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_chapters',
        2 => 'field_image_main',
        3 => 'field_active',
        4 => 'field_date',
        5 => 'field_show_sharing_options',
        6 => 'webform',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|page_content|token'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|student_program|search_index';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'student_program';
  $ds_layout->view_mode = 'search_index';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_article_author' => 'ds_content',
      'field_date' => 'ds_content',
      'field_issues' => 'ds_content',
      'node_type' => 'ds_content',
      'title' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'limit' => array(
      'field_issues' => '1',
    ),
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'node_type',
        2 => 'field_article_author',
        3 => 'field_date',
        4 => 'field_issues',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|student_program|search_index'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|node_embed';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'node_embed';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'webform' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'webform',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['node|webform|node_embed'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function nys_sitewide_elements_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'flex_video';
  $ds_view_mode->label = 'Flex-Video';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['flex_video'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'landscape_inline';
  $ds_view_mode->label = 'Landscape Inline';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['landscape_inline'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_landscape_image';
  $ds_view_mode->label = 'Landscape Offset';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_landscape_image'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_portrait_image';
  $ds_view_mode->label = 'Portrait Offset';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_portrait_image'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_signature';
  $ds_view_mode->label = 'Signature';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_signature'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'portrait_inline';
  $ds_view_mode->label = 'Portrait Inline';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['portrait_inline'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'square_image';
  $ds_view_mode->label = 'Square Image';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['square_image'] = $ds_view_mode;

  return $export;
}
