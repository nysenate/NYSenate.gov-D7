<?php
/**
 * @file
 * nys_wasteland_blog.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_wasteland_blog_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-newsroom-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'newsroom-block_1',
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

  return $export;
}
