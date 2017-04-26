<?php
/**
 * @file
 * nys_committees.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_committees_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-senators_committees_heade'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'senators_committees_heade',
    'module' => 'block',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'nysenate',
        'weight' => 10,
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

  $export['nys_utils-committee_chairs_output_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'committee_chairs_output_block',
    'module' => 'nys_utils',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'nysenate',
        'weight' => 15,
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

  $export['nys_utils-committee_cochairs_output_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'committee_cochairs_output_block',
    'module' => 'nys_utils',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'nysenate',
        'weight' => 16,
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

  $export['nys_utils-committee_tabs_output_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'committee_tabs_output_block',
    'module' => 'nys_utils',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'nysenate',
        'weight' => 14,
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

  $export['views-17af221e56c701572f55f5891e248244'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '17af221e56c701572f55f5891e248244',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'nysenate',
        'weight' => 12,
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

  $export['views-fcb8937208ecc3d4673a35b4a88d2f57'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'fcb8937208ecc3d4673a35b4a88d2f57',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'nysenate',
        'weight' => 13,
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

  return $export;
}
