<?php

/**
 * @file
 * nys_committees.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_committees_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_committees_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function nys_committees_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow Committee".
  $flags['follow_committee'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'Follow Committee',
    'global' => 0,
    'types' => array(
      0 => 'committees',
    ),
    'flag_short' => 'Follow this committee',
    'flag_long' => 'Follow this committee',
    'flag_message' => 'Following this committee',
    'unflag_short' => 'Unfollow this committee',
    'unflag_long' => 'Unfollow this committee',
    'unflag_message' => 'Not following this committee',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
      'search_index' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'nys_committees',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function nys_committees_image_default_styles() {
  $styles = array();

  // Exported image style: 1346x330.
  $styles['1346x330'] = array(
    'label' => '1346x330',
    'effects' => array(
      33 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1346,
          'height' => 330,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      34 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 85,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 60x60.
  $styles['60x60'] = array(
    'label' => '60x60',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function nys_committees_node_info() {
  $items = array(
    'agenda' => array(
      'name' => t('Agenda'),
      'base' => 'node_content',
      'description' => t('Stores agendas, which are a list of bills discussed in meetings.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
