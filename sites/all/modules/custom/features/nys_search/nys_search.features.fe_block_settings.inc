<?php
/**
 * @file
 * nys_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['apachesolr_search-mlt-001'] = array(
    'cache' => 4,
    'custom' => 0,
    'delta' => 'mlt-001',
    'module' => 'apachesolr_search',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['apachesolr_search-mlt-002'] = array(
    'cache' => 4,
    'custom' => 0,
    'delta' => 'mlt-002',
    'module' => 'apachesolr_search',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['apachesolr_search-sort'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'sort',
    'module' => 'apachesolr_search',
    'node_types' => array(),
    'pages' => 'search/global
search/global/*',
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

  $export['apachesolr_search_blocks-core_search'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'core_search',
    'module' => 'apachesolr_search_blocks',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['current_search-active_links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'active_links',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => 'search/global
search/global/*',
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

  $export['current_search-global_search_result_count'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'global_search_result_count',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 29,
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

  $export['current_search-standard'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'standard',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 30,
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

  $export['facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/site
search/site/*
search/global
search/global/*',
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
    'visibility' => 1,
  );

  $export['facetapi-YY4QSjLTY0X1t1FlrYWkbq3Yqvz12f7V'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'YY4QSjLTY0X1t1FlrYWkbq3Yqvz12f7V',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/site
search/site/*
search/global
search/global/*',
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
        'weight' => 9,
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

  $export['facetapi-esi5aP16jsumHPGllhv2PepWoxTSpB1W'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'esi5aP16jsumHPGllhv2PepWoxTSpB1W',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/site
search/site/*
search/global
search/global/*',
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
    'visibility' => 1,
  );

  $export['facetapi-gyH7wbGvSsVMNJAY3LG1uu7sdWxHh14P'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'gyH7wbGvSsVMNJAY3LG1uu7sdWxHh14P',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/site
search/site/*
search/global
search/global/*',
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
    'visibility' => 1,
  );

  $export['facetapi-jDFqu9d1636ykpAEusZMlSLq0N1zs6AW'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'jDFqu9d1636ykpAEusZMlSLq0N1zs6AW',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 68,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 65,
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

  $export['facetapi-qIvxTuoKAjaPgnb4jj3IH92jSXX1X9DH'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'qIvxTuoKAjaPgnb4jj3IH92jSXX1X9DH',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search/global
search/global/*',
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
        'weight' => 8,
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

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => -1,
      ),
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-ae9baaf6925a06addb59f2e3e1ce1b59'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ae9baaf6925a06addb59f2e3e1ce1b59',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'explore-issues
explore-issues/*',
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
    'visibility' => 1,
  );

  return $export;
}
