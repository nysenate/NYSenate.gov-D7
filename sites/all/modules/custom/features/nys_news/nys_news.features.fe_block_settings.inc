<?php
/**
 * @file
 * nys_news.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_news_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['nys_blocks-news_issues_hdr_block'] = array(
    'cache' => 2,
    'custom' => 0,
    'delta' => 'news_issues_hdr_block',
    'module' => 'nys_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-943c9c73b8bb4c2041a76c8bf478a9f5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '943c9c73b8bb4c2041a76c8bf478a9f5',
    'module' => 'views',
    'node_types' => array(
      0 => 'article',
      1 => 'in_the_news',
      2 => 'press_release',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 9,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-a032bdd6c1dfa3fb6227ac24bc48b1b6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'a032bdd6c1dfa3fb6227ac24bc48b1b6',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-newsroom-all_news'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'newsroom-all_news',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-newsroom-featured_video'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'newsroom-featured_video',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-newsroom-press_releases'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'newsroom-press_releases',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-senator_news-all_news'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_news-all_news',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -14,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-senator_news-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_news-block_1',
    'module' => 'views',
    'node_types' => array(
      0 => 'senator',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -63,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-senator_news-featured_story'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_news-featured_story',
    'module' => 'views',
    'node_types' => array(
      0 => 'senator',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -65,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-senator_news-featured_video'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_news-featured_video',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-senator_news-media'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_news-media',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -12,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-senator_news-press_releases'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_news-press_releases',
    'module' => 'views',
    'node_types' => array(
      0 => 'senator',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -12,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
