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

  $export['block-dashboard_help_text'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'dashboard_help_text',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'Administrator' => 6,
      'FOIL Administrator' => 14,
      'Frontpage Editor' => 9,
      'Legislative Correspondent' => 11,
      'Microsite Content Producer' => 10,
      'Student Programs' => 13,
      'Web Administrator' => 8,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 2,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'nysenate_admin' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'nysenate_admin',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Website Support',
    'visibility' => 0,
  );

  $export['menu-menu-foil-admin-editor'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-foil-admin-editor',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'Administrator' => 6,
      'FOIL Administrator' => 14,
      'Web Administrator' => 8,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 6,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'nysenate_admin' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'nysenate_admin',
        'weight' => 5,
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
      'Administrator' => 6,
      'Frontpage Editor' => 9,
      'Web Administrator' => 8,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 3,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'nysenate_admin' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'nysenate_admin',
        'weight' => 4,
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
      'Administrator' => 6,
      'Microsite Content Producer' => 10,
    ),
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
      'nysenate_admin' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'nysenate_admin',
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
      'Administrator' => 6,
      'Student Programs' => 13,
      'Web Administrator' => 8,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 1,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'nysenate_admin' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'nysenate_admin',
        'weight' => 2,
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
    'roles' => array(
      'Administrator' => 6,
      'Web Administrator' => 8,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 2,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'nysenate_admin' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'nysenate_admin',
        'weight' => 3,
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

  $export['views-all_petitions-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_petitions-block',
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
      'nysenate_admin' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'nysenate_admin',
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

  $export['views-bills_with_no_tags-number'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'bills_with_no_tags-number',
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
      'nysenate_admin' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'nysenate_admin',
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
