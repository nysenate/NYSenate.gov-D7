<?php
/**
 * @file
 * nys_senators.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_senators_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
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
function nys_senators_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nys_senators_image_default_styles() {
  $styles = array();

  // Exported image style: 440x230.
  $styles['440x230'] = array(
    'label' => '440x230',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 440,
          'height' => 230,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 80x60.
  $styles['80x60'] = array(
    'label' => '80x60',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
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
function nys_senators_node_info() {
  $items = array(
    'chapter' => array(
      'name' => t('Chapter'),
      'base' => 'node_content',
      'description' => t('This is a generic type for adding chapters to longer form articles. Do not use this content type on it\'s own. Instead create an item that supports chaptering (articles, districts, biographies), and append a chapter to the body.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'promotional_banner' => array(
      'name' => t('Promotional Banner'),
      'base' => 'node_content',
      'description' => t('This is a content type for sitewide promotional banners and is only available for users with front page editing permissions. Senators and their staff can create promotional banners on their microsites by navigating to their <a href="/admin/microsite-producers/senators">senator edit pages</a>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'senator' => array(
      'name' => t('Senator'),
      'base' => 'node_content',
      'description' => t('This type stores senator profiles.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
