<?php
/**
 * @file
 * nys_search.apachesolr_search_blocks.inc
 */

/**
 * Implements hook_default_apachesolr_search_blocks().
 */
function nys_search_default_apachesolr_search_blocks() {
  $export = array();

  $apachesolr_search_block = new stdClass();
  $apachesolr_search_block->disabled = FALSE; /* Edit this to true to make a default apachesolr_search_block disabled initially */
  $apachesolr_search_block->api_version = 1;
  $apachesolr_search_block->search_page_id = 'core_search';
  $apachesolr_search_block->block_enabled = 1;
  $apachesolr_search_block->block_title = '';
  $apachesolr_search_block->page_title = 'Site';
  $export['core_search'] = $apachesolr_search_block;

  return $export;
}
