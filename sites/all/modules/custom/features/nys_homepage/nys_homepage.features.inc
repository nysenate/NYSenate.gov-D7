<?php
/**
 * @file
 * nys_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function nys_homepage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: frontpage_news
  $nodequeues['frontpage_news'] = array(
    'name' => 'frontpage_news',
    'title' => 'Frontpage News',
    'subqueue_title' => '',
    'size' => 4,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: homepage_featured_story
  $nodequeues['homepage_featured_story'] = array(
    'name' => 'homepage_featured_story',
    'title' => 'Homepage Featured Story',
    'subqueue_title' => '',
    'size' => 2,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'article',
      1 => 'in_the_news',
      2 => 'press_release',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: homepage_hero
  $nodequeues['homepage_hero'] = array(
    'name' => 'homepage_hero',
    'title' => 'Homepage Hero',
    'subqueue_title' => '',
    'size' => 1,
    'link' => 'Feature on NYSenate.gov Front Page',
    'link_remove' => 'Remove from Front Page',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'article',
      1 => 'event',
      2 => 'in_the_news',
      3 => 'meeting',
      4 => 'press_release',
      5 => 'session',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
