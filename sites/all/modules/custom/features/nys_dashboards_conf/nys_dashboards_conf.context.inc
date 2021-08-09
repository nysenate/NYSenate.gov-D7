<?php

/**
 * @file
 * nys_dashboards_conf.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nys_dashboards_conf_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'senator_dashboard';
  $context->description = 'Senator\'s Dashboard';
  $context->tag = 'Pages';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'senator' => 'senator',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path_raw' => array(
      'values' => array(
        'senators/*/dashboard*' => 'senators/*/dashboard*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-micro_header_bar_block' => array(
          'module' => 'nys_blocks',
          'delta' => 'micro_header_bar_block',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  t('Senator\'s Dashboard');
  $export['senator_dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_dashboard';
  $context->description = 'Dashboard for users';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*/dashboard/*' => 'user/*/dashboard/*',
        'user/*/dashboard' => 'user/*/dashboard',
        'user/*/edit' => 'user/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-user_dashboard_hdr' => array(
          'module' => 'nys_blocks',
          'delta' => 'user_dashboard_hdr',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard for users');
  t('Pages');
  $export['user_dashboard'] = $context;

  return $export;
}
