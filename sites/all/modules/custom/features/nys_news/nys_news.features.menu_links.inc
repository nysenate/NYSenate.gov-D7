<?php
/**
 * @file
 * nys_news.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nys_news_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_news--issues:news-and-issues
  $menu_links['main-menu_news--issues:news-and-issues'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'news-and-issues',
    'router_path' => 'news-and-issues',
    'link_title' => 'News & Issues',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_news--issues:news-and-issues',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('News & Issues');


  return $menu_links;
}
