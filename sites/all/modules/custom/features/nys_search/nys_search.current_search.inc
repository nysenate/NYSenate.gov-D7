<?php

/**
 * @file
 * nys_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function nys_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'active_links';
  $item->label = 'Active Links';
  $item->settings = array(
    'items' => array(
      'clear_filters' => array(
        'id' => 'active',
        'label' => 'Clear Filters',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 0,
        'css' => 1,
        'classes' => 'c-block-facets--clear',
        'nofollow' => 1,
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '3',
    ),
  );
  $export['active_links'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'global_search_result_count';
  $item->label = 'Global Search Result Count';
  $item->settings = array(
    'items' => array(),
    'advanced' => array(
      'empty_searches' => '0',
    ),
  );
  $export['global_search_result_count'] = $item;

  return $export;
}
