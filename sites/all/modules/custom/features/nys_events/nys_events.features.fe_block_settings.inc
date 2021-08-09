<?php

/**
 * @file
 * nys_events.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_events_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-13da96c20741daa3375a02564795aa11'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '13da96c20741daa3375a02564795aa11',
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
        'region' => '',
        'status' => 0,
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

  $export['views-senator_events-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_events-block_1',
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
        'weight' => -30,
      ),
      'nysenate_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate_admin',
        'weight' => -30,
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

  $export['views-senator_events-featured_event'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_events-featured_event',
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
        'weight' => -13,
      ),
      'nysenate_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate_admin',
        'weight' => -13,
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

  $export['views-senator_events-upcoming_events'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'senator_events-upcoming_events',
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
      'nysenate_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate_admin',
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
