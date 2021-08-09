<?php
/**
 * @file
 * nys_senators.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_senators_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-senator-s-microsite-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-senator-s-microsite-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'node/*/newsroom
node/*/legislation
node/*/about
node/*/calendar
node/*/contact',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 148,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -35,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['nys_utils-news_by_top_issue_output_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news_by_top_issue_output_block',
    'module' => 'nys_utils',
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
        'weight' => 140,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -47,
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

  $export['views-1b3cb0862ec040f257c15644f64e179e'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '1b3cb0862ec040f257c15644f64e179e',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'senators-committees',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 217,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -22,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-275c4e859ad42076cd3fa3b95ba1a271'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '275c4e859ad42076cd3fa3b95ba1a271',
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
        'weight' => 213,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -54,
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

  $export['views-85e3554e3bf81ab852cebba34169145f'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '85e3554e3bf81ab852cebba34169145f',
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
        'weight' => 212,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -55,
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

  $export['views-88588cdf3933fc3d3a00204b3cdf77d8'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '88588cdf3933fc3d3a00204b3cdf77d8',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'senators/*/newsroom
senators/*/calendar
senators/*/about
senators/*',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 216,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -45,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-d0ac5718ec3a5ba564bec885e8d17fde'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'd0ac5718ec3a5ba564bec885e8d17fde',
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
        'weight' => 214,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -49,
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

  $export['views-issues-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'issues-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 202,
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

  $export['views-nys_senator_hero-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'nys_senator_hero-block',
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
        'weight' => 137,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -37,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-nys_senator_hero-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'nys_senator_hero-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'district/*',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 144,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -40,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-senator_petition-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_petition-block',
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
        'weight' => 247,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -25,
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

  $export['views-senator_petition-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_petition-block_1',
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
        'weight' => 246,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -21,
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

  $export['views-senator_petition-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_petition-block_2',
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
        'weight' => 245,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -17,
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
