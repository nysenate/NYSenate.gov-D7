<?php

/**
 * @file
 * Views functions for views exclude previous.
 */

/**
 * Implements hook_views_data_alter()
 */
function views_exclude_previous_views_data_alter(&$data) {
  $data['node']['views_exclude_previous'] = array(
    'group' => t('Views'),
    'title' => t('Views Exclude Previous'),
    'help' => t('Excludes nodes that have already been loaded/viewed in the current page.'),
    'filter' => array(
      'handler' => 'views_exclude_previous_handler_filter',
    ),
  );
}

/**
 * Implements hook_views_handlers
 */
function views_exclude_previous_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_exclude_previous'),
    ),
    'handlers' => array(
      'views_exclude_previous_handler_filter' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
    ),
  );
}

/**
 * Implements hook_views_post_execute().
 */
function views_exclude_previous_views_post_execute($view) {
  if ($view->base_table === 'node') {
    foreach ($view->result AS $result) {
      if (!empty($result->nid)) {
        _views_exclude_previous('views', $result->nid);
      }
    }
  }
}
