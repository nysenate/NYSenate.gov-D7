<?php
/**
 * @file
 * nys_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function nys_paragraphs_paragraphs_info() {
  $items = array(
    'feature_image' => array(
      'name' => 'Feature Image',
      'bundle' => 'feature_image',
      'locked' => '1',
    ),
    'pg_accordion' => array(
      'name' => 'Accordion Chapters',
      'bundle' => 'pg_accordion',
      'locked' => '1',
    ),
    'pg_block_reference' => array(
      'name' => 'Block Reference',
      'bundle' => 'pg_block_reference',
      'locked' => '1',
    ),
    'pg_entity_form' => array(
      'name' => 'Entity Form',
      'bundle' => 'pg_entity_form',
      'locked' => '1',
    ),
    'pg_featured_bills' => array(
      'name' => 'Featured Bill',
      'bundle' => 'pg_featured_bills',
      'locked' => '1',
    ),
    'pg_file_uploads' => array(
      'name' => 'File Uploads',
      'bundle' => 'pg_file_uploads',
      'locked' => '1',
    ),
    'pg_image_left' => array(
      'name' => 'Image Left',
      'bundle' => 'pg_image_left',
      'locked' => '1',
    ),
    'pg_image_slider' => array(
      'name' => 'Image Slider',
      'bundle' => 'pg_image_slider',
      'locked' => '1',
    ),
    'pg_poll' => array(
      'name' => 'Poll',
      'bundle' => 'pg_poll',
      'locked' => '1',
    ),
    'pg_quick_facts' => array(
      'name' => 'Quick Facts',
      'bundle' => 'pg_quick_facts',
      'locked' => '1',
    ),
    'pg_text' => array(
      'name' => 'Text',
      'bundle' => 'pg_text',
      'locked' => '1',
    ),
    'pg_video' => array(
      'name' => 'Video',
      'bundle' => 'pg_video',
      'locked' => '1',
    ),
    'two_column_button_links' => array(
      'name' => 'Two Column Text',
      'bundle' => 'two_column_button_links',
      'locked' => '1',
    ),
  );
  return $items;
}
