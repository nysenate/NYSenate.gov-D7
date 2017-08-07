<?php

/**
 * @file
 * Default Views for Fancy File Delete.
 */

function fancy_file_delete_views_default_views() {
  // Add in format to prevent errors
  $format = variable_get('fancy_file_delete_format', 'full_html');

  $view = new view();
  $view->name = 'fancy_file_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Fancy File List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Files';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer fancy file delete';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'filename' => 'filename',
    'fid' => 'fid',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filename' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h3>There be no files in your system!</h3>';
  $handler->display->display_options['empty']['area']['format'] = $format;
  /* Relationship: File Usage: Content */
  $handler->display->display_options['relationships']['file_to_node']['id'] = 'file_to_node';
  $handler->display->display_options['relationships']['file_to_node']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['file_to_node']['field'] = 'file_to_node';
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'file_managed';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::fancy_file_delete_files' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::fancy_file_delete_files_force' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = 'File Name';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = 'File ID (FID)';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'file_to_node';
  $handler->display->display_options['fields']['title']['label'] = 'Content Title';
  $handler->display->display_options['fields']['title']['empty'] = 'Not Attached';

  /* Display: All Files */
  $handler = $view->new_display('page', 'All Files', 'all_files');
  $handler->display->display_options['path'] = 'admin/config/content/fancy_file_delete/list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-11';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Fancy File Delete';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Orphaned Files */
  $handler = $view->new_display('page', 'Orphaned Files', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Orphaned Files';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Warning, this will delete all files that have been orphaned.</h2>
  <h5><em>Orphaned = not attached the node table and file_usage table usually as a result from old deleted nodes</em>  <strong>There is no turning back once you delete these files!</strong></h5>';
  $handler->display->display_options['header']['area']['format'] = $format;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h3>There be no orphaned files in your system!</h3>';
  $handler->display->display_options['empty']['area']['format'] = $format;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'file_managed';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::fancy_file_delete_files' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::fancy_file_delete_files_force' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = 'File Name';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = 'File ID (FID)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: File: Orphan File Delete */
  $handler->display->display_options['filters']['orphan_delete']['id'] = 'orphan_delete';
  $handler->display->display_options['filters']['orphan_delete']['table'] = 'file_managed';
  $handler->display->display_options['filters']['orphan_delete']['field'] = 'orphan_delete';
  $handler->display->display_options['path'] = 'admin/config/content/fancy_file_delete/orphan';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Orphaned';
  $handler->display->display_options['menu']['weight'] = '-9';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Fancy File Delete';
  $handler->display->display_options['tab_options']['weight'] = '0';

  // End copy and paste of Export tab output.
  $views['fancy_file_list'] = $view;

  $view = new view();
  $view->name = 'fancy_file_list_unmanaged';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'unmanaged_files';
  $view->human_name = 'Fancy File List Unmanaged';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fancy File List Unmanaged';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer fancy file delete';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'unfid' => 'unfid',
    'path' => 'path',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'unfid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'path' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Warning, this will delete all files that are unmanaged</h2>
    <h5><em>Unmanaged = ones that are in the files directory with no record on the file_managed table </em><strong>There is no turning back once you hit submit!</strong></h5>';
  $handler->display->display_options['header']['area']['format'] = $format;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Unmanaged Files!';
  $handler->display->display_options['empty']['area']['format'] = $format;
  /* Field: Bulk operations: Unmanaged Files */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'unmanaged_files';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::fancy_file_delete_files' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Unmanaged Files: File id */
  $handler->display->display_options['fields']['unfid']['id'] = 'unfid';
  $handler->display->display_options['fields']['unfid']['table'] = 'unmanaged_files';
  $handler->display->display_options['fields']['unfid']['field'] = 'unfid';
  $handler->display->display_options['fields']['unfid']['exclude'] = TRUE;
  /* Field: Unmanaged Files: Unmanaged Files Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'unmanaged_files';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Unmanaged File Path';
  /* Filter criterion: Unmanaged Files: Directory Choice */
  $handler->display->display_options['filters']['unmanaged_directories']['id'] = 'unmanaged_directories';
  $handler->display->display_options['filters']['unmanaged_directories']['table'] = 'unmanaged_files';
  $handler->display->display_options['filters']['unmanaged_directories']['field'] = 'unmanaged_directories';
  $handler->display->display_options['filters']['unmanaged_directories']['value'] = array(
    0 => 'private://',
    1 => 'public://',
    2 => 'public://apps',
    3 => 'public://apps/panopoly_demo',
    4 => 'public://apps/panopoly_faq',
    5 => 'public://apps/panopoly_news',
    6 => 'public://ctools',
    7 => 'public://js',
    8 => 'public://js/wysiwyg',
    9 => 'public://media-icons',
    10 => 'public://media-icons/default',
    11 => 'public://styles',
    12 => 'public://styles/panopoly_image_half',
    13 => 'public://styles/panopoly_image_half/public',
    14 => 'public://styles/panopoly_image_quarter',
    15 => 'public://styles/panopoly_image_quarter/public',
    'private://' => 0,
    'public://' => 0,
    'public://apps' => 0,
    'public://apps/panopoly_demo' => 0,
    'public://apps/panopoly_faq' => 0,
    'public://apps/panopoly_news' => 0,
    'public://ctools' => 0,
    'public://js' => 0,
    'public://js/wysiwyg' => 0,
    'public://media-icons' => 0,
    'public://media-icons/default' => 0,
    'public://styles' => 0,
    'public://styles/panopoly_image_half' => 0,
    'public://styles/panopoly_image_half/public' => 0,
    'public://styles/panopoly_image_quarter' => 0,
    'public://styles/panopoly_image_quarter/public' => 0,
  );
  $handler->display->display_options['filters']['unmanaged_directories']['exposed'] = TRUE;
  $handler->display->display_options['filters']['unmanaged_directories']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['unmanaged_directories']['expose']['label'] = 'Directories to delete from:';
  $handler->display->display_options['filters']['unmanaged_directories']['expose']['operator'] = 'unmanaged_directories_op';
  $handler->display->display_options['filters']['unmanaged_directories']['expose']['identifier'] = 'unmanaged_directories';
  $handler->display->display_options['filters']['unmanaged_directories']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['unmanaged_directories']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['unmanaged_directories']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Unmanaged */
  $handler = $view->new_display('page', 'Unmanaged', 'unmanaged');
  $handler->display->display_options['path'] = 'admin/config/content/fancy_file_delete/unmanaged';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Unmanaged';
  $handler->display->display_options['menu']['weight'] = '-8';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  // End copy and paste of Export tab output.
  $views['fancy_file_list_unmanaged'] = $view;

  // At the end, return array of default views.
  return $views;
}
