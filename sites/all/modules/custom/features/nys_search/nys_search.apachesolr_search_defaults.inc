<?php
/**
 * @file
 * nys_search.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function nys_search_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'core_search';
  $searcher->label = 'Core Search';
  $searcher->description = 'Core Search';
  $searcher->search_path = 'search/global';
  $searcher->page_title = 'Site';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => '-bundle:agenda',
      1 => '-bundle:calendar',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 0,
    'apachesolr_search_search_box' => 0,
    'apachesolr_search_allow_user_input' => 1,
    'apachesolr_search_browse' => 'results',
  );
  $export['core_search'] = $searcher;

  return $export;
}
