<?php

/**
 * @file
 * nys_legislation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_legislation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
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
function nys_legislation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function nys_legislation_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow Bills".
  $flags['follow_this_bill'] = array(
    'entity_type' => 'node',
    'title' => 'Follow Bills',
    'global' => 0,
    'types' => array(
      0 => 'bill',
    ),
    'flag_short' => 'Follow This Bill',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unfollow this bill',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'node_embed' => 0,
      'token' => 0,
      'sponsor_list' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'nys_legislation',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Sign Petition".
  $flags['sign_petition'] = array(
    'entity_type' => 'node',
    'title' => 'Sign Petition',
    'global' => 0,
    'types' => array(
      0 => 'petition',
    ),
    'flag_short' => 'Sign The Petition',
    'flag_long' => 'Click here to sign this petition',
    'flag_message' => 'Thank you for signing! Please share this page to raise awareness for this cause.',
    'unflag_short' => 'Unsign the petition',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Thank you for your support.',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'node_embed' => 0,
      'token' => 0,
      'bill_list_item' => 0,
      'sponsor_list' => 0,
      'sponsor_list_bill_detail' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'nys_legislation',
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
function nys_legislation_image_default_styles() {
  $styles = array();

  // Exported image style: 45x45.
  $styles['45x45'] = array(
    'label' => '45x45',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 45,
          'height' => 45,
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
function nys_legislation_node_info() {
  $items = array(
    'bill' => array(
      'name' => t('Bill'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Bill Number'),
      'help' => '',
    ),
    'calendar' => array(
      'name' => t('Calendar'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'resolution' => array(
      'name' => t('Resolution'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Number'),
      'help' => '',
    ),
    'session' => array(
      'name' => t('Session'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Session Title'),
      'help' => '',
    ),
    'transcript' => array(
      'name' => t('Transcript'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
