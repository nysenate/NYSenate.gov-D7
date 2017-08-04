<?php

/**
 * Load a search block.
 *
 * @param string $search_page_id
 *   The machine name of the search page.
 */
function apachesolr_search_blocks_load($search_page_id) {
  ctools_include('export');
  $result = apachesolr_search_blocks_load_multiple(array($search_page_id));
  if (isset($result[$search_page_id])) {
    return $result[$search_page_id];
  }
}

/**
 * Load multiple search blocks.
 *
 * @param array $search_page_ids
 *   An array of page_id names.
 */
function apachesolr_search_blocks_load_multiple(array $search_page_ids) {
  ctools_include('export');
  return ctools_export_load_object('apachesolr_search_blocks', 'names', $search_page_ids);
}

/**
 * Load all search blocks.
 * @param bool $enabled_only
 * @return array
 */
function apachesolr_search_blocks_load_all($enabled_only = FALSE) {
  ctools_include('export');

  if ($enabled_only) {
    return ctools_export_load_object('apachesolr_search_blocks', 'conditions', array('block_enabled' => 1));
  }
  else {
    return ctools_export_load_object('apachesolr_search_blocks', 'all');
  }
}


/**
 * Save a search block.
 */
function apachesolr_search_blocks_save($search_block) {
  // Normalize to an object.
  $search_block = (object) $search_block;

  $update = (isset($search_block->_update) && $search_block->_update) ? array('search_page_id') : array();
  return drupal_write_record('apachesolr_search_blocks', $search_block, $update);
}


/**
 * Delete search block from the database.
 *
 * @param mixed $rule
 *   Either the page-id machine name of the page, or the full search block object.
 */
function apachesolr_search_blocks_delete($search_block) {
  ctools_include('export');
  ctools_export_crud_delete('apachesolr_search_blocks', $search_block);
}