<?php
/**
 * @file
 * nys_sitewide_elements.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_sitewide_elements_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-dd81dc1e47a7f0113d25350b3fd63f66'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'dd81dc1e47a7f0113d25350b3fd63f66',
    'module' => 'views',
    'node_types' => array(
      0 => 'session',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 127,
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
