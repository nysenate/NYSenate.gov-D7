<?php
/**
 * @file
 * nys_polls.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_polls_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'senator_polls';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Polls by Senators';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Polls';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advpoll' => 'advpoll',
  );
  /* Filter criterion: Content: Poll availability -  start date (advpoll_dates) */
  $handler->display->display_options['filters']['advpoll_dates_value']['id'] = 'advpoll_dates_value';
  $handler->display->display_options['filters']['advpoll_dates_value']['table'] = 'field_data_advpoll_dates';
  $handler->display->display_options['filters']['advpoll_dates_value']['field'] = 'advpoll_dates_value';
  $handler->display->display_options['filters']['advpoll_dates_value']['operator'] = '<=';
  $handler->display->display_options['filters']['advpoll_dates_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['advpoll_dates_value']['year_range'] = '-0:+1';
  /* Filter criterion: Content: Poll availability - end date (advpoll_dates:value2) */
  $handler->display->display_options['filters']['advpoll_dates_value2']['id'] = 'advpoll_dates_value2';
  $handler->display->display_options['filters']['advpoll_dates_value2']['table'] = 'field_data_advpoll_dates';
  $handler->display->display_options['filters']['advpoll_dates_value2']['field'] = 'advpoll_dates_value2';
  $handler->display->display_options['filters']['advpoll_dates_value2']['operator'] = '>';
  $handler->display->display_options['filters']['advpoll_dates_value2']['default_date'] = 'now';
  $handler->display->display_options['filters']['advpoll_dates_value2']['year_range'] = '-0:+1';
  /* Filter criterion: Content: Is Featured (field_advpoll_featured) */
  $handler->display->display_options['filters']['field_advpoll_featured_value']['id'] = 'field_advpoll_featured_value';
  $handler->display->display_options['filters']['field_advpoll_featured_value']['table'] = 'field_data_field_advpoll_featured';
  $handler->display->display_options['filters']['field_advpoll_featured_value']['field'] = 'field_advpoll_featured_value';
  $handler->display->display_options['filters']['field_advpoll_featured_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['senator_polls'] = $view;

  return $export;
}
