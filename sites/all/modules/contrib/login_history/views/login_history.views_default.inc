<?php

/**
 * @file
 * Default view definitions for Login History.
 */

/**
 * Implementation of hook_views_default_views().
 */
function login_history_views_default_views() {
  $views = array();

  /*
   * View 'login_history_report'
   */
  $view = new view;
  $view->name = 'login_history_report';
  $view->description = 'Global login history report.';
  $view->tag = 'default';
  $view->base_table = 'login_history';
  $view->human_name = 'Login history report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Login history';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'login' => 'login',
    'name' => 'name',
    'hostname' => 'hostname',
    'one_time' => 'one_time',
    'user_agent' => 'user_agent',
  );
  $handler->display->display_options['style_options']['default'] = 'login';
  $handler->display->display_options['style_options']['info'] = array(
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hostname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'one_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user_agent' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No login history available.';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Login History: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'login_history';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Login History: Date */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'login_history';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Login History: IP Address */
  $handler->display->display_options['fields']['hostname']['id'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['table'] = 'login_history';
  $handler->display->display_options['fields']['hostname']['field'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['hostname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['hostname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['hostname']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['hostname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['hostname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['hostname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['hostname']['hide_alter_empty'] = 1;
  /* Field: Login History: One-time login? */
  $handler->display->display_options['fields']['one_time']['id'] = 'one_time';
  $handler->display->display_options['fields']['one_time']['table'] = 'login_history';
  $handler->display->display_options['fields']['one_time']['field'] = 'one_time';
  $handler->display->display_options['fields']['one_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['one_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['one_time']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['one_time']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['one_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['one_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['one_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['one_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['one_time']['not'] = 0;
  /* Field: Login History: User Agent */
  $handler->display->display_options['fields']['user_agent']['id'] = 'user_agent';
  $handler->display->display_options['fields']['user_agent']['table'] = 'login_history';
  $handler->display->display_options['fields']['user_agent']['field'] = 'user_agent';
  $handler->display->display_options['fields']['user_agent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_agent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_agent']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_agent']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['user_agent']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_agent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_agent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['user_agent']['hide_alter_empty'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/login-history';

  $views[$view->name] = $view;

  /*
   * View 'user_login_history'
   */
  $view = new view;
  $view->name = 'user_login_history';
  $view->description = 'Login history for an individual user.';
  $view->tag = 'default';
  $view->base_table = 'login_history';
  $view->human_name = 'User login history';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Login history';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all login histories';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'login' => 'login',
    'name' => 'name',
    'hostname' => 'hostname',
    'one_time' => 'one_time',
    'user_agent' => 'user_agent',
  );
  $handler->display->display_options['style_options']['default'] = 'login';
  $handler->display->display_options['style_options']['info'] = array(
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hostname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'one_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user_agent' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No login history available.';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Login History: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'login_history';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Login History: Date */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'login_history';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  /* Field: Login History: IP Address */
  $handler->display->display_options['fields']['hostname']['id'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['table'] = 'login_history';
  $handler->display->display_options['fields']['hostname']['field'] = 'hostname';
  $handler->display->display_options['fields']['hostname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['hostname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['hostname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['hostname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['hostname']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['hostname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['hostname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['hostname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['hostname']['hide_alter_empty'] = 1;
  /* Field: Login History: One-time login? */
  $handler->display->display_options['fields']['one_time']['id'] = 'one_time';
  $handler->display->display_options['fields']['one_time']['table'] = 'login_history';
  $handler->display->display_options['fields']['one_time']['field'] = 'one_time';
  $handler->display->display_options['fields']['one_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['one_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['one_time']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['one_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['one_time']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['one_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['one_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['one_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['one_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['one_time']['not'] = 0;
  /* Field: Login History: User Agent */
  $handler->display->display_options['fields']['user_agent']['id'] = 'user_agent';
  $handler->display->display_options['fields']['user_agent']['table'] = 'login_history';
  $handler->display->display_options['fields']['user_agent']['field'] = 'user_agent';
  $handler->display->display_options['fields']['user_agent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['user_agent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['user_agent']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['user_agent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['user_agent']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['user_agent']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['user_agent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['user_agent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['user_agent']['hide_alter_empty'] = 1;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['uid']['title'] = '%1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/login-history';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Login history';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  $views[$view->name] = $view;

  return $views;
}
