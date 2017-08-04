<?php
/**
 * @file
 * nys_cms.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_cms_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-foil-admin-editor'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-foil-admin-editor',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'FOIL Administrator' => 14,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 1,
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-frontpage-editor-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-frontpage-editor-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'Frontpage Editor' => 9,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 3,
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-microsite-content-editor'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-microsite-content-editor',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'Microsite Content Producer' => 10,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-student-program-editor'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-student-program-editor',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'Student Programs' => 13,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-web-administrator-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-web-administrator-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_main',
        'status' => 1,
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
