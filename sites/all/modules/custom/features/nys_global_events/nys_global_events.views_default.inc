<?php

/**
 * @file
 * nys_global_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_global_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_event_type_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Filter By Type',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_committee_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Filter By Committee',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_senator_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Filter By Senator',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results Area for Calendars';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h3>There are no events scheduled at this time.</h3>
<p>Please try looking at the <a href="/events/month">monthly</a> or <a href="/events/week">weekly</a> listings.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Location: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'location';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  /* Field: Publication Date (Inline) */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Publication Date (Inline)';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'privatemsg_current_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Committees (field_committee) */
  $handler->display->display_options['filters']['field_committee_tid']['id'] = 'field_committee_tid';
  $handler->display->display_options['filters']['field_committee_tid']['table'] = 'field_data_field_committee';
  $handler->display->display_options['filters']['field_committee_tid']['field'] = 'field_committee_tid';
  $handler->display->display_options['filters']['field_committee_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_committee_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_committee_tid']['expose']['operator_id'] = 'field_committee_tid_op';
  $handler->display->display_options['filters']['field_committee_tid']['expose']['operator'] = 'field_committee_tid_op';
  $handler->display->display_options['filters']['field_committee_tid']['expose']['identifier'] = 'field_committee_tid';
  $handler->display->display_options['filters']['field_committee_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_committee_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_committee_tid']['vocabulary'] = 'committees';
  /* Filter criterion: Field: Senator (field_senator) */
  $handler->display->display_options['filters']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['filters']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['filters']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['filters']['field_senator_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['operator_id'] = 'field_senator_target_id_op';
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['operator'] = 'field_senator_target_id_op';
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['identifier'] = 'field_senator_target_id';
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'meeting' => 'meeting',
    'public_hearing' => 'public_hearing',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
    3 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_date_2',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_date_2',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    2 => array(
      'field' => 'field_date_3',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['group']['element_type'] = 'div';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => 'event-title',
    ),
    'field_senator' => array(
      'element_type' => 'div',
      'class' => 'event-senator',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => 'event-location-name icon-before__circle-pin',
    ),
    'field_event_place' => array(
      'element_type' => 'div',
      'class' => 'event-location',
    ),
    'field_date_1' => array(
      'element_type' => 'div',
      'class' => 'event-date',
    ),
    'field_date_3' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Upcoming Events</h2>
<div><a href="/events" class="upcoming-events-link c-container--link">Go to Events</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Location: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'location';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['label'] = '';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['exclude'] = TRUE;
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['province']['alter']['text'] = '[city], [province]';
  $handler->display->display_options['fields']['province']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['province']['empty'] = '[city]';
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_place']['alter']['text'] = '[province]';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_place']['hide_empty'] = TRUE;
  /* Field: Publication Date (Inline) */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Publication Date (Inline)';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'privatemsg_current_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Publication Date (Day Only Group) */
  $handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
  $handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_2']['ui_name'] = 'Publication Date (Day Only Group)';
  $handler->display->display_options['fields']['field_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_2']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Publication Date (Month Only Group) */
  $handler->display->display_options['fields']['field_date_3']['id'] = 'field_date_3';
  $handler->display->display_options['fields']['field_date_3']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_3']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_3']['ui_name'] = 'Publication Date (Month Only Group)';
  $handler->display->display_options['fields']['field_date_3']['label'] = '';
  $handler->display->display_options['fields']['field_date_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_3']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['block_description'] = 'Upcoming';
  $export['calendar'] = $view;

  $view = new view();
  $view->name = 'committee_meetings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Committee Meetings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="c-container--header">
<h3 class="c-container--title ">past %1 committee events</h3>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  /* Field: Content: Meeting Location Extra */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
  $handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_2']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Published on - end date (field_date:value2) */
  $handler->display->display_options['sorts']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['sorts']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['sorts']['field_date_value2']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Committees (field_committee) */
  $handler->display->display_options['arguments']['field_committee_tid']['id'] = 'field_committee_tid';
  $handler->display->display_options['arguments']['field_committee_tid']['table'] = 'field_data_field_committee';
  $handler->display->display_options['arguments']['field_committee_tid']['field'] = 'field_committee_tid';
  $handler->display->display_options['arguments']['field_committee_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_committee_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_committee_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_committee_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_committee_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_committee_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_committee_tid']['validate_options']['vocabularies'] = array(
    'committees' => 'committees',
  );
  /* Filter criterion: Content: Published status */
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
    'meeting' => 'meeting',
  );
  /* Filter criterion: Content: Published on - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '<';
  $handler->display->display_options['filters']['field_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_date_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = 'now';

  /* Display: Past Meetings in Committee of a Meeting */
  $handler = $view->new_display('block', 'Past Meetings in Committee of a Meeting', 'past');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'c-meeting-detail--past';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_event_place' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_meeting_location' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date_2' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  /* Field: Content: Meeting Location Extra */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
  $handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_2']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Committees (field_committee) */
  $handler->display->display_options['arguments']['field_committee_tid']['id'] = 'field_committee_tid';
  $handler->display->display_options['arguments']['field_committee_tid']['table'] = 'field_data_field_committee';
  $handler->display->display_options['arguments']['field_committee_tid']['field'] = 'field_committee_tid';
  $handler->display->display_options['arguments']['field_committee_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_committee_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_committee_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_committee_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_committee_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_committee_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_committee_tid']['validate_options']['vocabularies'] = array(
    'committees' => 'committees',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;

  /* Display: Committee Meeting Details */
  $handler = $view->new_display('block', 'Committee Meeting Details', 'committee_meeting_details');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_event_place' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_meeting_location' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date_2' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_event_status' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['alter']['text'] = 'Related Issues: [field_issues] ';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_issues']['separator'] = ',';
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  /* Field: Content: Meeting Location Extra */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
  $handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_2']['settings'] = array(
    'format_type' => 'privatemsg_current_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Video Status */
  $handler->display->display_options['fields']['field_video_status']['id'] = 'field_video_status';
  $handler->display->display_options['fields']['field_video_status']['table'] = 'field_data_field_video_status';
  $handler->display->display_options['fields']['field_video_status']['field'] = 'field_video_status';
  $handler->display->display_options['fields']['field_video_status']['label'] = '';
  $handler->display->display_options['fields']['field_video_status']['element_label_colon'] = FALSE;
  /* Field: Content: Meeting Status */
  $handler->display->display_options['fields']['field_event_status']['id'] = 'field_event_status';
  $handler->display->display_options['fields']['field_event_status']['table'] = 'field_data_field_event_status';
  $handler->display->display_options['fields']['field_event_status']['field'] = 'field_event_status';
  $handler->display->display_options['fields']['field_event_status']['label'] = '';
  $handler->display->display_options['fields']['field_event_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_status']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_event_status']['settings'] = array(
    'textformatter_type' => 'ul',
    'textformatter_comma_and' => 0,
    'textformatter_comma_full_stop' => 0,
    'textformatter_comma_override' => 0,
    'textformatter_separator_custom' => '',
    'textformatter_separator_custom_tag' => 'span',
    'textformatter_separator_custom_class' => 'textformatter-separator',
    'textformatter_comma_tag' => 'div',
    'textformatter_class' => 'textformatter-list',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: If checked, will display "OFF THE FLOOR" */
  $handler->display->display_options['fields']['field_off_the_floor']['id'] = 'field_off_the_floor';
  $handler->display->display_options['fields']['field_off_the_floor']['table'] = 'field_data_field_off_the_floor';
  $handler->display->display_options['fields']['field_off_the_floor']['field'] = 'field_off_the_floor';
  $handler->display->display_options['fields']['field_off_the_floor']['type'] = 'list_key';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
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
    'meeting' => 'meeting',
  );
  $export['committee_meetings'] = $view;

  $view = new view();
  $view->name = 'embedded_youtube_video';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Embedded YouTube Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_yt' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Field: Content: Youtube Video */
  $handler->display->display_options['fields']['field_yt']['id'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['table'] = 'field_data_field_yt';
  $handler->display->display_options['fields']['field_yt']['field'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['label'] = '';
  $handler->display->display_options['fields']['field_yt']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_yt']['alter']['text'] = '<div class="c-block c-meeting-detail--embed">[field_yt]</div>';
  $handler->display->display_options['fields']['field_yt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_yt']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_yt']['settings'] = array(
    'video_style' => 'normal',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published status */
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
    'meeting' => 'meeting',
  );

  /* Display: YouTube Embed Meeting */
  $handler = $view->new_display('block', 'YouTube Embed Meeting', 'block');

  /* Display: YouTube Embed Session */
  $handler = $view->new_display('block', 'YouTube Embed Session', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
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
    'session' => 'session',
  );
  $export['embedded_youtube_video'] = $view;

  $view = new view();
  $view->name = 'legislative_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Legislative Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Legislative Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_date',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    2 => array(
      'field' => 'field_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['group']['element_type'] = 'div';
  $handler->display->display_options['style_options']['group']['class'] = 'date-title';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'h3',
      'class' => 'event-title',
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div><a href="/events" class="upcoming-events-link c-container--link">Go to Events</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h3>There are no Legislative Events scheduled at this time</h3>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Meeting Date Day Only */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['ui_name'] = 'Meeting Date Day Only';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Meeting Date Month Only */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Meeting Date Month Only';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_date][field_date_1]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  /* Filter criterion: Content: Published status */
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
    'meeting' => 'meeting',
    'public_hearing' => 'public_hearing',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published on - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = '12AM today';
  /* Filter criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value_1']['id'] = 'field_date_value_1';
  $handler->display->display_options['filters']['field_date_value_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value_1']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value_1']['default_date'] = '+7 Days';

  /* Display: Upcoming Legislative Events Block */
  $handler = $view->new_display('block', 'Upcoming Legislative Events Block', 'block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div><a href="/events" class="upcoming-events-link c-container--link">Go to Events</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published on - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = '12AM today';
  /* Filter criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value_1']['id'] = 'field_date_value_1';
  $handler->display->display_options['filters']['field_date_value_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value_1']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value_1']['default_date'] = '+7 Days';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'meeting' => 'meeting',
    'public_hearing' => 'public_hearing',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Accessible Sitewide (field_accessible_sitewide) */
  $handler->display->display_options['filters']['field_accessible_sitewide_value_1']['id'] = 'field_accessible_sitewide_value_1';
  $handler->display->display_options['filters']['field_accessible_sitewide_value_1']['table'] = 'field_data_field_accessible_sitewide';
  $handler->display->display_options['filters']['field_accessible_sitewide_value_1']['field'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value_1']['operator'] = 'not';
  $handler->display->display_options['filters']['field_accessible_sitewide_value_1']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_accessible_sitewide_value_1']['group'] = 1;
  $export['legislative_events'] = $view;

  $view = new view();
  $view->name = 'meeting_agenda_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Meeting Agenda - Detail Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_ol_law_section' => array(
      'element_type' => 'div',
      'class' => '',
      'label_element_type' => 'label',
      'label_class' => '',
    ),
    'field_ol_sponsor' => array(
      'element_type' => 'div',
      'class' => '',
      'label_element_type' => 'label',
      'label_class' => '',
    ),
    'field_ol_bill_message' => array(
      'element_type' => 'div',
      'class' => '',
      'label_element_type' => 'label',
      'label_class' => '',
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_meeting_agenda_target_id']['id'] = 'field_meeting_agenda_target_id';
  $handler->display->display_options['relationships']['field_meeting_agenda_target_id']['table'] = 'field_data_field_meeting_agenda';
  $handler->display->display_options['relationships']['field_meeting_agenda_target_id']['field'] = 'field_meeting_agenda_target_id';
  /* Relationship: Content: Agenda Bills (field_ol_agenda_bills) */
  $handler->display->display_options['relationships']['field_ol_agenda_bills_value']['id'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['relationships']['field_ol_agenda_bills_value']['table'] = 'field_data_field_ol_agenda_bills';
  $handler->display->display_options['relationships']['field_ol_agenda_bills_value']['field'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['relationships']['field_ol_agenda_bills_value']['relationship'] = 'field_meeting_agenda_target_id';
  $handler->display->display_options['relationships']['field_ol_agenda_bills_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['id'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['table'] = 'field_data_field_ol_bill';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['field'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['required'] = TRUE;
  /* Field: Content: Agenda Bills */
  $handler->display->display_options['fields']['field_ol_agenda_bills']['id'] = 'field_ol_agenda_bills';
  $handler->display->display_options['fields']['field_ol_agenda_bills']['table'] = 'field_data_field_ol_agenda_bills';
  $handler->display->display_options['fields']['field_ol_agenda_bills']['field'] = 'field_ol_agenda_bills';
  $handler->display->display_options['fields']['field_ol_agenda_bills']['relationship'] = 'field_meeting_agenda_target_id';
  $handler->display->display_options['fields']['field_ol_agenda_bills']['label'] = '';
  $handler->display->display_options['fields']['field_ol_agenda_bills']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_agenda_bills']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_agenda_bills']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_ol_agenda_bills']['delta_offset'] = '0';
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['alter']['text'] = '[field_ol_summary] [field_ol_sponsor]';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 0,
  );
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_name']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Votes */
  $handler->display->display_options['fields']['field_ol_votes']['id'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['field'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_votes']['label'] = '';
  $handler->display->display_options['fields']['field_ol_votes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_votes']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_ol_votes']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_ol_votes']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ol_votes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_votes']['delta_reversed'] = TRUE;
  /* Field: Content: Last Status */
  $handler->display->display_options['fields']['field_ol_last_status']['id'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['field'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_last_status']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status']['element_label_colon'] = FALSE;
  /* Field: Content: Last Status Date */
  $handler->display->display_options['fields']['field_ol_last_status_date']['id'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['field'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_last_status_date']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Absent Count */
  $handler->display->display_options['fields']['field_ol_absent_count']['id'] = 'field_ol_absent_count';
  $handler->display->display_options['fields']['field_ol_absent_count']['table'] = 'field_data_field_ol_absent_count';
  $handler->display->display_options['fields']['field_ol_absent_count']['field'] = 'field_ol_absent_count';
  $handler->display->display_options['fields']['field_ol_absent_count']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['fields']['field_ol_absent_count']['label'] = '';
  $handler->display->display_options['fields']['field_ol_absent_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_absent_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Abstained Count */
  $handler->display->display_options['fields']['field_ol_abstained_count']['id'] = 'field_ol_abstained_count';
  $handler->display->display_options['fields']['field_ol_abstained_count']['table'] = 'field_data_field_ol_abstained_count';
  $handler->display->display_options['fields']['field_ol_abstained_count']['field'] = 'field_ol_abstained_count';
  $handler->display->display_options['fields']['field_ol_abstained_count']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['fields']['field_ol_abstained_count']['label'] = '';
  $handler->display->display_options['fields']['field_ol_abstained_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_abstained_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Aye Count */
  $handler->display->display_options['fields']['field_ol_aye_count']['id'] = 'field_ol_aye_count';
  $handler->display->display_options['fields']['field_ol_aye_count']['table'] = 'field_data_field_ol_aye_count';
  $handler->display->display_options['fields']['field_ol_aye_count']['field'] = 'field_ol_aye_count';
  $handler->display->display_options['fields']['field_ol_aye_count']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['fields']['field_ol_aye_count']['label'] = '';
  $handler->display->display_options['fields']['field_ol_aye_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_aye_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Aye With Reservations Count */
  $handler->display->display_options['fields']['field_ol_aye_wr_count']['id'] = 'field_ol_aye_wr_count';
  $handler->display->display_options['fields']['field_ol_aye_wr_count']['table'] = 'field_data_field_ol_aye_wr_count';
  $handler->display->display_options['fields']['field_ol_aye_wr_count']['field'] = 'field_ol_aye_wr_count';
  $handler->display->display_options['fields']['field_ol_aye_wr_count']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['fields']['field_ol_aye_wr_count']['label'] = '';
  $handler->display->display_options['fields']['field_ol_aye_wr_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_aye_wr_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Excused Count */
  $handler->display->display_options['fields']['field_ol_excused_count']['id'] = 'field_ol_excused_count';
  $handler->display->display_options['fields']['field_ol_excused_count']['table'] = 'field_data_field_ol_excused_count';
  $handler->display->display_options['fields']['field_ol_excused_count']['field'] = 'field_ol_excused_count';
  $handler->display->display_options['fields']['field_ol_excused_count']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['fields']['field_ol_excused_count']['label'] = '';
  $handler->display->display_options['fields']['field_ol_excused_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_excused_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Nay Count */
  $handler->display->display_options['fields']['field_ol_nay_count']['id'] = 'field_ol_nay_count';
  $handler->display->display_options['fields']['field_ol_nay_count']['table'] = 'field_data_field_ol_nay_count';
  $handler->display->display_options['fields']['field_ol_nay_count']['field'] = 'field_ol_nay_count';
  $handler->display->display_options['fields']['field_ol_nay_count']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['fields']['field_ol_nay_count']['label'] = '';
  $handler->display->display_options['fields']['field_ol_nay_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_nay_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Bill Message */
  $handler->display->display_options['fields']['field_ol_bill_message']['id'] = 'field_ol_bill_message';
  $handler->display->display_options['fields']['field_ol_bill_message']['table'] = 'field_data_field_ol_bill_message';
  $handler->display->display_options['fields']['field_ol_bill_message']['field'] = 'field_ol_bill_message';
  $handler->display->display_options['fields']['field_ol_bill_message']['relationship'] = 'field_ol_agenda_bills_value';
  $handler->display->display_options['fields']['field_ol_bill_message']['label'] = '';
  $handler->display->display_options['fields']['field_ol_bill_message']['element_label_colon'] = FALSE;
  /* Field: Content: Additional Sponsor Names */
  $handler->display->display_options['fields']['field_ol_add_sponsor_names']['id'] = 'field_ol_add_sponsor_names';
  $handler->display->display_options['fields']['field_ol_add_sponsor_names']['table'] = 'field_data_field_ol_add_sponsor_names';
  $handler->display->display_options['fields']['field_ol_add_sponsor_names']['field'] = 'field_ol_add_sponsor_names';
  $handler->display->display_options['fields']['field_ol_add_sponsor_names']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_add_sponsor_names']['label'] = '';
  $handler->display->display_options['fields']['field_ol_add_sponsor_names']['element_label_colon'] = FALSE;
  /* Field: Content: Additional Sponsors */
  $handler->display->display_options['fields']['field_ol_add_sponsors']['id'] = 'field_ol_add_sponsors';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['table'] = 'field_data_field_ol_add_sponsors';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['field'] = 'field_ol_add_sponsors';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['label'] = '';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_add_sponsors']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_ol_add_sponsors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['separator'] = '<br />';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'meeting' => 'meeting',
  );
  /* Filter criterion: Content: Published status */
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
    'meeting' => 'meeting',
  );
  /* Filter criterion: Content: Meeting Agenda (field_meeting_agenda) */
  $handler->display->display_options['filters']['field_meeting_agenda_target_id']['id'] = 'field_meeting_agenda_target_id';
  $handler->display->display_options['filters']['field_meeting_agenda_target_id']['table'] = 'field_data_field_meeting_agenda';
  $handler->display->display_options['filters']['field_meeting_agenda_target_id']['field'] = 'field_meeting_agenda_target_id';
  $handler->display->display_options['filters']['field_meeting_agenda_target_id']['operator'] = 'not empty';

  /* Display: Meeting Agenda */
  $handler = $view->new_display('block', 'Meeting Agenda', 'meeting_agenda');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '4';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="nys-title">Meeting Agenda</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $export['meeting_agenda_block'] = $view;

  $view = new view();
  $view->name = 'public_hearing_detail';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Public Hearing Detail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="c-container--header">
<h3 class="c-container--title ">past %1 committee events</h3>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  /* Field: Content: Meeting Location Extra */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
  $handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_2']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Published on - end date (field_date:value2) */
  $handler->display->display_options['sorts']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['sorts']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['sorts']['field_date_value2']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Committees (field_committee) */
  $handler->display->display_options['arguments']['field_committee_tid']['id'] = 'field_committee_tid';
  $handler->display->display_options['arguments']['field_committee_tid']['table'] = 'field_data_field_committee';
  $handler->display->display_options['arguments']['field_committee_tid']['field'] = 'field_committee_tid';
  $handler->display->display_options['arguments']['field_committee_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_committee_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_committee_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_committee_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_committee_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_committee_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_committee_tid']['validate_options']['vocabularies'] = array(
    'committees' => 'committees',
  );
  /* Filter criterion: Content: Published status */
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
    'meeting' => 'meeting',
  );
  /* Filter criterion: Content: Published on - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '<';
  $handler->display->display_options['filters']['field_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_date_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = 'now';

  /* Display: Public Hearing Details */
  $handler = $view->new_display('block', 'Public Hearing Details', 'public_hearign_detail');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_event_status' => array(
      'element_type' => 'div',
      'class' => 'meeting-status',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => 'hearing-month',
    ),
    'field_date_1' => array(
      'element_type' => 'div',
      'class' => 'hearing-day',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => 'hearing-title',
    ),
    'field_meeting_location' => array(
      'element_type' => 'div',
      'class' => 'hearing-location icon-before__circle-pin',
    ),
    'field_event_place' => array(
      'element_type' => 'div',
      'class' => 'hearing-place',
    ),
    'field_date_2' => array(
      'element_type' => 'div',
      'class' => 'hearing-date',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => 'field-name-field-issues ',
    ),
    'body' => array(
      'element_type' => 'div',
      'class' => 'hearing-body',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Meeting Status */
  $handler->display->display_options['fields']['field_event_status']['id'] = 'field_event_status';
  $handler->display->display_options['fields']['field_event_status']['table'] = 'field_data_field_event_status';
  $handler->display->display_options['fields']['field_event_status']['field'] = 'field_event_status';
  $handler->display->display_options['fields']['field_event_status']['label'] = '';
  $handler->display->display_options['fields']['field_event_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_status']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_event_status']['settings'] = array(
    'textformatter_type' => 'ul',
    'textformatter_comma_and' => 0,
    'textformatter_comma_full_stop' => 0,
    'textformatter_comma_override' => 0,
    'textformatter_separator_custom' => '',
    'textformatter_separator_custom_tag' => 'span',
    'textformatter_separator_custom_class' => 'textformatter-separator',
    'textformatter_comma_tag' => 'div',
    'textformatter_class' => 'textformatter-list',
  );
  /* Field: Content: Publish Date (Month Only) */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['ui_name'] = 'Content: Publish Date (Month Only)';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Publish Date (Day Only) */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Content: Publish Date (Day Only)';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Meeting Location Extra */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_meeting_location']['hide_empty'] = TRUE;
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
  $handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_2']['settings'] = array(
    'format_type' => 'privatemsg_current_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['alter']['text'] = 'Related Issues: [field_issues] ';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'textformatter_list';
  $handler->display->display_options['fields']['field_issues']['settings'] = array(
    'textformatter_type' => 'ul',
    'textformatter_comma_and' => 0,
    'textformatter_comma_full_stop' => 0,
    'textformatter_comma_override' => 0,
    'textformatter_separator_custom' => '',
    'textformatter_separator_custom_tag' => 'span',
    'textformatter_separator_custom_class' => 'textformatter-separator',
    'textformatter_comma_tag' => 'div',
    'textformatter_class' => 'textformatter-list',
    'textformatter_term_plain' => 0,
  );
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_issues']['separator'] = ',';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
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
    'public_hearing' => 'public_hearing',
  );
  $handler->display->display_options['block_description'] = 'Public Hearing Details';
  $export['public_hearing_detail'] = $view;

  return $export;
}
