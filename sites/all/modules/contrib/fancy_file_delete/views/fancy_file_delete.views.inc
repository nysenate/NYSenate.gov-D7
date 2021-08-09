<?php
/**
 * @file
 * Fancy File Delete Views Settings.
 */

/**
 * Implement hook_views_data().
 */
function fancy_file_delete_views_data() {
  $data = array();

  $data['unmanaged_files']['table']['group'] = t('Unmanaged Files');

  $data['unmanaged_files']['table']['entity type'] = 'unmanaged_files';

  $data['unmanaged_files']['table']['base'] = array(
    'field' => 'unfid',
    'title' => t('Unmanaged Files'),
    'help' => t('Unmanaged Files from the Fancy File Delete Module'),
  );

  $data['unmanaged_files']['unfid'] = array(
    'title' => t('File id'),
    'help' => t('The id of the file.'),
    'field' => array(
      'handler' => 'views_handler_field_file',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_file_fid',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['unmanaged_files']['path'] = array(
    'title' => t('Unmanaged Files Path'),
    'help' => t('Unmanaged Files Path.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['unmanaged_files']['table']['join'] = array(
    'unmanaged_files' => array(
      'field' => 'unfid',
      'left_field' => 'unfid',
    ),
  );

  $data['unmanaged_files']['unmanaged_directories'] = array(
    'title' => t('Directory Choice'),
    'help' => t('Filter by Directory.'),
    'filter' => array(
      'handler' => 'FancyFileDeleteUnmanagedDirectoryFilter',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function fancy_file_delete_views_data_alter(&$data) {
  // Add Orphan File Filter.
  $data['file_managed']['orphan_delete']['title'] = 'Orphan File Delete';
  $data['file_managed']['orphan_delete']['help'] = 'Filter by Orphan Files.';
  $data['file_managed']['orphan_delete']['filter']['handler'] = 'FancyFileDeleteOrphanFileFilter';
}
