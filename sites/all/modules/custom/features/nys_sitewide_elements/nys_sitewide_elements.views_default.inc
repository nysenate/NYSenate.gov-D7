<?php
/**
 * @file
 * nys_sitewide_elements.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_sitewide_elements_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bill_related_content';
  $view->description = 'Used to show content on Bill detail page with related content like Bills, Issues and Content';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bill Related Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bill Related Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/news-and-issues">Explore All Issues</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_view_mode';
  $handler->display->display_options['fields']['field_issues']['delta_limit'] = '6';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_issues']['multi_type'] = 'ul';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'term_node_tid';
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
    'bill' => 'bill',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Related Issues */
  $handler = $view->new_display('block', 'Related Issues', 'related_issues');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;

  /* Display: Recent Related Legislation */
  $handler = $view->new_display('block', 'Recent Related Legislation', 'related_bills');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Related Legislation';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Last Status */
  $handler->display->display_options['fields']['field_ol_last_status']['id'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['field'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_name']['type'] = 'text_plain';
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'sponsor_list',
    'links' => 0,
  );
  /* Field: Content: Last Status Date */
  $handler->display->display_options['fields']['field_ol_last_status_date']['id'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['field'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: All Statuses */
  $handler->display->display_options['fields']['field_ol_all_statuses']['id'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['table'] = 'field_data_field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['field'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['label'] = '';
  $handler->display->display_options['fields']['field_ol_all_statuses']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_all_statuses']['type'] = 'text_plain';
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_chamber']['type'] = 'list_key';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issues_tid']['break_phrase'] = TRUE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'bill' => 'bill',
  );

  /* Display: Related Content */
  $handler = $view->new_display('block', 'Related Content', 'related_content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Content';
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
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'month_only';
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['empty'] = '[created]';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'article' => 'article',
    'in_the_news' => 'in_the_news',
    'press_release' => 'press_release',
    'video' => 'video',
  );

  /* Display: Bill Related Issues */
  $handler = $view->new_display('block', 'Bill Related Issues', 'bill_related_issues');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'c-block--issue';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committees' => 0,
    'districts' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  $export['bill_related_content'] = $view;

  $view = new view();
  $view->name = 'bills_by_issue';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bill';
  $view->human_name = 'Bills by issue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
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
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_last_action_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'bill';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown Date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_resolution_id']['id'] = 'field_openleg_resolution_id';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['table'] = 'field_data_field_openleg_resolution_id';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['field'] = 'field_openleg_resolution_id';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['empty'] = 'Unknown Committee';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['id'] = 'field_openleg_last_action_date_value';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['field'] = 'field_openleg_last_action_date_value';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['order'] = 'DESC';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['id'] = 'field_openleg_issues_tid';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['field'] = 'field_openleg_issues_tid';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'main');

  /* Display: Recently Signed */
  $handler = $view->new_display('block', 'Recently Signed', 'recently_signed');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_last_action_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_openleg_sponsor_target_id']['id'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['relationships']['field_openleg_sponsor_target_id']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['relationships']['field_openleg_sponsor_target_id']['field'] = 'field_openleg_sponsor_target_id';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_openleg_votes_value']['id'] = 'field_openleg_votes_value';
  $handler->display->display_options['relationships']['field_openleg_votes_value']['table'] = 'field_data_field_openleg_votes';
  $handler->display->display_options['relationships']['field_openleg_votes_value']['field'] = 'field_openleg_votes_value';
  /* Relationship: Content: Member Headshot (field_image_headshot:fid) */
  $handler->display->display_options['relationships']['field_image_headshot_fid']['id'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['field'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['relationship'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown Date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Senate District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['fields']['field_district']['label'] = '';
  $handler->display->display_options['fields']['field_district']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['id'] = 'field_openleg_ayes_voters';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['table'] = 'field_data_field_openleg_ayes_voters';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['field'] = 'field_openleg_ayes_voters';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['relationship'] = 'field_openleg_votes_value';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_nays_voters']['id'] = 'field_openleg_nays_voters';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['table'] = 'field_data_field_openleg_nays_voters';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['field'] = 'field_openleg_nays_voters';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['relationship'] = 'field_openleg_votes_value';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['element_label_colon'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_headshot_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['id'] = 'field_openleg_current_committee_tid';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['field'] = 'field_openleg_current_committee_tid';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['validate_options']['vocabularies'] = array(
    'committees' => 'committees',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_status_value']['id'] = 'field_openleg_status_value';
  $handler->display->display_options['filters']['field_openleg_status_value']['table'] = 'field_data_field_openleg_status';
  $handler->display->display_options['filters']['field_openleg_status_value']['field'] = 'field_openleg_status_value';
  $handler->display->display_options['filters']['field_openleg_status_value']['value'] = 'SIGNED_BY_GOV';

  /* Display: Recently Passed Senate */
  $handler = $view->new_display('block', 'Recently Passed Senate', 'recently_passed');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_last_action_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_openleg_sponsor_target_id']['id'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['relationships']['field_openleg_sponsor_target_id']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['relationships']['field_openleg_sponsor_target_id']['field'] = 'field_openleg_sponsor_target_id';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_openleg_votes_value']['id'] = 'field_openleg_votes_value';
  $handler->display->display_options['relationships']['field_openleg_votes_value']['table'] = 'field_data_field_openleg_votes';
  $handler->display->display_options['relationships']['field_openleg_votes_value']['field'] = 'field_openleg_votes_value';
  /* Relationship: Content: Member Headshot (field_image_headshot:fid) */
  $handler->display->display_options['relationships']['field_image_headshot_fid']['id'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['field'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['relationship'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown Date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Senate District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['fields']['field_district']['label'] = '';
  $handler->display->display_options['fields']['field_district']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['id'] = 'field_openleg_ayes_voters';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['table'] = 'field_data_field_openleg_ayes_voters';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['field'] = 'field_openleg_ayes_voters';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['relationship'] = 'field_openleg_votes_value';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_ayes_voters']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_nays_voters']['id'] = 'field_openleg_nays_voters';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['table'] = 'field_data_field_openleg_nays_voters';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['field'] = 'field_openleg_nays_voters';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['relationship'] = 'field_openleg_votes_value';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_nays_voters']['element_label_colon'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_headshot_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['id'] = 'field_openleg_current_committee_tid';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['field'] = 'field_openleg_current_committee_tid';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_openleg_current_committee_tid']['validate_options']['vocabularies'] = array(
    'committees' => 'committees',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_status_value']['id'] = 'field_openleg_status_value';
  $handler->display->display_options['filters']['field_openleg_status_value']['table'] = 'field_data_field_openleg_status';
  $handler->display->display_options['filters']['field_openleg_status_value']['field'] = 'field_openleg_status_value';
  $handler->display->display_options['filters']['field_openleg_status_value']['value'] = 'PASSED_SENATE';

  /* Display: Recently Related Legislation */
  $handler = $view->new_display('block', 'Recently Related Legislation', 'recently_related_legislation');
  $handler->display->display_options['display_description'] = 'Block for Bill entity detail page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_openleg_last_action_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown Date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_resolution_id']['id'] = 'field_openleg_resolution_id';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['table'] = 'field_data_field_openleg_resolution_id';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['field'] = 'field_openleg_resolution_id';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_resolution_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['empty'] = 'Unknown Committee';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_actions_status']['id'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['table'] = 'field_data_field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['field'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_actions_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['id'] = 'field_openleg_issues_tid';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['field'] = 'field_openleg_issues_tid';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['validate_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['arguments']['field_openleg_issues_tid']['validate_options']['type'] = 'tids';
  $export['bills_by_issue'] = $view;

  $view = new view();
  $view->name = 'committee_chair';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Committee Chair';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Relationship: Taxonomy term: Members (field_members) */
  $handler->display->display_options['relationships']['field_members_value']['id'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['table'] = 'field_data_field_members';
  $handler->display->display_options['relationships']['field_members_value']['field'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['relationship'] = 'field_members_value';
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Role */
  $handler->display->display_options['fields']['field_committee_member_role']['id'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['field'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['relationship'] = 'field_members_value';
  $handler->display->display_options['fields']['field_committee_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_role']['element_label_colon'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committees' => 'committees',
  );
  /* Filter criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['filters']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['filters']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['relationship'] = 'field_members_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['value'] = array(
    2 => '2',
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'main');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Members (field_members) */
  $handler->display->display_options['relationships']['field_members_value']['id'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['table'] = 'field_data_field_members';
  $handler->display->display_options['relationships']['field_members_value']['field'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['relationship'] = 'field_members_value';
  /* Relationship: Content: Member Headshot (field_image_headshot:fid) */
  $handler->display->display_options['relationships']['field_image_headshot_fid']['id'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['field'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Senator [title]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Role */
  $handler->display->display_options['fields']['field_committee_member_role']['id'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['field'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['relationship'] = 'field_members_value';
  $handler->display->display_options['fields']['field_committee_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_role']['element_label_colon'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_headshot_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['sorts']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['relationship'] = 'field_members_value';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['order'] = 'DESC';

  /* Display: Chair raw */
  $handler = $view->new_display('block', 'Chair raw', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committees' => 'committees',
  );
  /* Filter criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['filters']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['filters']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['relationship'] = 'field_members_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['value'] = array(
    2 => '2',
  );

  /* Display: Members */
  $handler = $view->new_display('block', 'Members', 'members');
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
    'field_committee_member_role' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'uri' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Members (field_members) */
  $handler->display->display_options['relationships']['field_members_value']['id'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['table'] = 'field_data_field_members';
  $handler->display->display_options['relationships']['field_members_value']['field'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['relationship'] = 'field_members_value';
  /* Relationship: Content: Member Headshot (field_image_headshot:fid) */
  $handler->display->display_options['relationships']['field_image_headshot_fid']['id'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['field'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['relationship'] = 'field_senator_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['id'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['field'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Senator [title]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Role */
  $handler->display->display_options['fields']['field_committee_member_role']['id'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['field'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['relationship'] = 'field_members_value';
  $handler->display->display_options['fields']['field_committee_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_role']['element_label_colon'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_headshot_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Other Member Role */
  $handler->display->display_options['fields']['field_other_member_role']['id'] = 'field_other_member_role';
  $handler->display->display_options['fields']['field_other_member_role']['table'] = 'field_data_field_other_member_role';
  $handler->display->display_options['fields']['field_other_member_role']['field'] = 'field_other_member_role';
  $handler->display->display_options['fields']['field_other_member_role']['relationship'] = 'field_members_value';
  $handler->display->display_options['fields']['field_other_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_other_member_role']['element_label_colon'] = FALSE;
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conference']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_conference']['delta_offset'] = '0';
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['field_district_number']['label'] = '';
  $handler->display->display_options['fields']['field_district_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Other Member Role (field_other_member_role) */
  $handler->display->display_options['sorts']['field_other_member_role_value']['id'] = 'field_other_member_role_value';
  $handler->display->display_options['sorts']['field_other_member_role_value']['table'] = 'field_data_field_other_member_role';
  $handler->display->display_options['sorts']['field_other_member_role_value']['field'] = 'field_other_member_role_value';
  $handler->display->display_options['sorts']['field_other_member_role_value']['relationship'] = 'field_members_value';
  $handler->display->display_options['sorts']['field_other_member_role_value']['order'] = 'DESC';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['relationship'] = 'field_senator_target_id';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['relationship'] = 'field_senator_target_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committees' => 'committees',
  );
  /* Filter criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['filters']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['filters']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['relationship'] = 'field_members_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_committee_member_role_value']['value'] = array(
    2 => '2',
    1 => '1',
  );

  /* Display: Chair Block */
  $handler = $view->new_display('block', 'Chair Block', 'block_2');
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
    'field_committee_member_role' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'uri' => array(
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
  $handler->display->display_options['header']['area']['content'] = '  <div class="c-container--header">
    <h2 class="c-container--title">Members</h2>
  </div>
<div style="height: 20px;"></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Members (field_members) */
  $handler->display->display_options['relationships']['field_members_value']['id'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['table'] = 'field_data_field_members';
  $handler->display->display_options['relationships']['field_members_value']['field'] = 'field_members_value';
  $handler->display->display_options['relationships']['field_members_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['relationship'] = 'field_members_value';
  /* Relationship: Content: Member Headshot (field_image_headshot:fid) */
  $handler->display->display_options['relationships']['field_image_headshot_fid']['id'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['field'] = 'field_image_headshot_fid';
  $handler->display->display_options['relationships']['field_image_headshot_fid']['relationship'] = 'field_senator_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['id'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['field'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Senator [title]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Role */
  $handler->display->display_options['fields']['field_committee_member_role']['id'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['field'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['relationship'] = 'field_members_value';
  $handler->display->display_options['fields']['field_committee_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_role']['element_label_colon'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_headshot_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Other Member Role */
  $handler->display->display_options['fields']['field_other_member_role']['id'] = 'field_other_member_role';
  $handler->display->display_options['fields']['field_other_member_role']['table'] = 'field_data_field_other_member_role';
  $handler->display->display_options['fields']['field_other_member_role']['field'] = 'field_other_member_role';
  $handler->display->display_options['fields']['field_other_member_role']['relationship'] = 'field_members_value';
  $handler->display->display_options['fields']['field_other_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_other_member_role']['element_label_colon'] = FALSE;
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conference']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_conference']['delta_offset'] = '0';
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['field_district_number']['label'] = '';
  $handler->display->display_options['fields']['field_district_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['sorts']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['relationship'] = 'field_members_value';
  $handler->display->display_options['sorts']['field_committee_member_role_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committees' => 'committees',
  );
  /* Filter criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['filters']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['filters']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['relationship'] = 'field_members_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['value'] = array(
    2 => '2',
    1 => '1',
  );
  $export['committee_chair'] = $view;

  $view = new view();
  $view->name = 'committee_featurer_senator';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Committee Featurer Senator';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_committee_head_taxonomy_term']['id'] = 'reverse_field_committee_head_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_committee_head_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_committee_head_taxonomy_term']['field'] = 'reverse_field_committee_head_taxonomy_term';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'reverse_field_committee_head_taxonomy_term';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'senator' => 'senator',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['committee_featurer_senator'] = $view;

  $view = new view();
  $view->name = 'committee_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Committee Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'c-senator-block';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Relationship: Field collection item: Entity with the Members (field_members) */
  $handler->display->display_options['relationships']['field_members_taxonomy_term']['id'] = 'field_members_taxonomy_term';
  $handler->display->display_options['relationships']['field_members_taxonomy_term']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_members_taxonomy_term']['field'] = 'field_members_taxonomy_term';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  /* Relationship: Taxonomy term: Misc Legislative Group Members (field_group_members) */
  $handler->display->display_options['relationships']['field_group_members_value']['id'] = 'field_group_members_value';
  $handler->display->display_options['relationships']['field_group_members_value']['table'] = 'field_data_field_group_members';
  $handler->display->display_options['relationships']['field_group_members_value']['field'] = 'field_group_members_value';
  $handler->display->display_options['relationships']['field_group_members_value']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_group_members_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['id'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['field'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['relationship'] = 'field_senator_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Role */
  $handler->display->display_options['fields']['field_committee_member_role']['id'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['field'] = 'field_committee_member_role';
  $handler->display->display_options['fields']['field_committee_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_role']['element_label_colon'] = FALSE;
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Senate District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_district']['label'] = '';
  $handler->display->display_options['fields']['field_district']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'field_members_taxonomy_term';
  $handler->display->display_options['fields']['field_district_number']['label'] = '';
  $handler->display->display_options['fields']['field_district_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_senator_target_id';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_group_members_taxonomy_term';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_members' => 'field_members',
  );
  /* Filter criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['filters']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['filters']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_committee_member_role_value']['value'] = array(
    2 => '2',
  );

  /* Display: Listing */
  $handler = $view->new_display('block', 'Listing', 'listing');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_committee_member_role' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_headshot' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_district' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_conference' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_party' => array(
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conference']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_conference']['delta_offset'] = '0';
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['field_district_number']['label'] = '';
  $handler->display->display_options['fields']['field_district_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );

  /* Display: Chair */
  $handler = $view->new_display('block', 'Chair', 'chair');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => 'content',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conference']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_conference']['delta_offset'] = '0';
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['relationship'] = 'field_senator_target_id';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_members' => 'field_members',
  );
  /* Filter criterion: Field collection item: Role (field_committee_member_role) */
  $handler->display->display_options['filters']['field_committee_member_role_value']['id'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['table'] = 'field_data_field_committee_member_role';
  $handler->display->display_options['filters']['field_committee_member_role_value']['field'] = 'field_committee_member_role_value';
  $handler->display->display_options['filters']['field_committee_member_role_value']['value'] = array(
    2 => '2',
  );

  /* Display: Assembly Listing */
  $handler = $view->new_display('block', 'Assembly Listing', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_committee_member_role' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_headshot' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_district' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_conference' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_party' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Assemblymen Name */
  $handler->display->display_options['fields']['field_assemblymen_name']['id'] = 'field_assemblymen_name';
  $handler->display->display_options['fields']['field_assemblymen_name']['table'] = 'field_data_field_assemblymen_name';
  $handler->display->display_options['fields']['field_assemblymen_name']['field'] = 'field_assemblymen_name';
  /* Field: Field collection item: Assemblymen URL */
  $handler->display->display_options['fields']['field_assemblymen_url']['id'] = 'field_assemblymen_url';
  $handler->display->display_options['fields']['field_assemblymen_url']['table'] = 'field_data_field_assemblymen_url';
  $handler->display->display_options['fields']['field_assemblymen_url']['field'] = 'field_assemblymen_url';
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Taxonomy term: Committee Type */
  $handler->display->display_options['fields']['field_committee_types']['id'] = 'field_committee_types';
  $handler->display->display_options['fields']['field_committee_types']['table'] = 'field_data_field_committee_types';
  $handler->display->display_options['fields']['field_committee_types']['field'] = 'field_committee_types';
  $handler->display->display_options['fields']['field_committee_types']['relationship'] = 'field_members_taxonomy_term';

  /* Display: Assembly Chair */
  $handler = $view->new_display('block', 'Assembly Chair', 'block_2');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '[name]';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Misc Legislative Group Members (field_group_members) */
  $handler->display->display_options['relationships']['field_group_members_taxonomy_term']['id'] = 'field_group_members_taxonomy_term';
  $handler->display->display_options['relationships']['field_group_members_taxonomy_term']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_group_members_taxonomy_term']['field'] = 'field_group_members_taxonomy_term';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_group_members_taxonomy_term';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<a href="#members" class="c-committee--see-all">See all [name] Members</a>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Committee Member Role Type */
  $handler->display->display_options['fields']['field_committee_member_role_type']['id'] = 'field_committee_member_role_type';
  $handler->display->display_options['fields']['field_committee_member_role_type']['table'] = 'field_data_field_committee_member_role_type';
  $handler->display->display_options['fields']['field_committee_member_role_type']['field'] = 'field_committee_member_role_type';
  $handler->display->display_options['fields']['field_committee_member_role_type']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_role_type']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Committee Member URL */
  $handler->display->display_options['fields']['field_committee_member_url']['id'] = 'field_committee_member_url';
  $handler->display->display_options['fields']['field_committee_member_url']['table'] = 'field_data_field_committee_member_url';
  $handler->display->display_options['fields']['field_committee_member_url']['field'] = 'field_committee_member_url';
  $handler->display->display_options['fields']['field_committee_member_url']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_committee_member_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_committee_member_url']['hide_empty'] = TRUE;
  /* Field: Field collection item: Committee Member Name */
  $handler->display->display_options['fields']['field_committee_member_name']['id'] = 'field_committee_member_name';
  $handler->display->display_options['fields']['field_committee_member_name']['table'] = 'field_data_field_committee_member_name';
  $handler->display->display_options['fields']['field_committee_member_name']['field'] = 'field_committee_member_name';
  $handler->display->display_options['fields']['field_committee_member_name']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['text'] = '[field_senator_1]';
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['path'] = '[field_committee_member_url]';
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_committee_member_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_committee_member_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator_1']['id'] = 'field_senator_1';
  $handler->display->display_options['fields']['field_senator_1']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator_1']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator_1']['label'] = '';
  $handler->display->display_options['fields']['field_senator_1']['alter']['text'] = '[field_committee_member_name]';
  $handler->display->display_options['fields']['field_senator_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator_1']['empty'] = '[field_committee_member_name]';
  $handler->display->display_options['fields']['field_senator_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_senator_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_senator_1']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_group_members_taxonomy_term';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_group_members' => 'field_group_members',
  );
  /* Filter criterion: Field collection item: Committee Member Role Type (field_committee_member_role_type) */
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['id'] = 'field_committee_member_role_type_value';
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['table'] = 'field_data_field_committee_member_role_type';
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['field'] = 'field_committee_member_role_type_value';
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['value'] = array(
    'chair' => 'chair',
  );

  /* Display: Assembly Members */
  $handler = $view->new_display('block', 'Assembly Members', 'block_3');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_committee_member_role_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['list']['class'] = 'member-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Members';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Misc Legislative Group Members (field_group_members) */
  $handler->display->display_options['relationships']['field_group_members_taxonomy_term']['id'] = 'field_group_members_taxonomy_term';
  $handler->display->display_options['relationships']['field_group_members_taxonomy_term']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_group_members_taxonomy_term']['field'] = 'field_group_members_taxonomy_term';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_group_members_taxonomy_term';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'See all [name] Members';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Committee Member Role Type */
  $handler->display->display_options['fields']['field_committee_member_role_type']['id'] = 'field_committee_member_role_type';
  $handler->display->display_options['fields']['field_committee_member_role_type']['table'] = 'field_data_field_committee_member_role_type';
  $handler->display->display_options['fields']['field_committee_member_role_type']['field'] = 'field_committee_member_role_type';
  $handler->display->display_options['fields']['field_committee_member_role_type']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_role_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_committee_member_role_type']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Committee Member URL */
  $handler->display->display_options['fields']['field_committee_member_url']['id'] = 'field_committee_member_url';
  $handler->display->display_options['fields']['field_committee_member_url']['table'] = 'field_data_field_committee_member_url';
  $handler->display->display_options['fields']['field_committee_member_url']['field'] = 'field_committee_member_url';
  $handler->display->display_options['fields']['field_committee_member_url']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_committee_member_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_committee_member_url']['hide_empty'] = TRUE;
  /* Field: Field collection item: Committee Member Name */
  $handler->display->display_options['fields']['field_committee_member_name']['id'] = 'field_committee_member_name';
  $handler->display->display_options['fields']['field_committee_member_name']['table'] = 'field_data_field_committee_member_name';
  $handler->display->display_options['fields']['field_committee_member_name']['field'] = 'field_committee_member_name';
  $handler->display->display_options['fields']['field_committee_member_name']['label'] = '';
  $handler->display->display_options['fields']['field_committee_member_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['text'] = '[field_senator_1]';
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['path'] = '[field_committee_member_url]';
  $handler->display->display_options['fields']['field_committee_member_name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_committee_member_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_committee_member_name']['hide_alter_empty'] = FALSE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator_1']['id'] = 'field_senator_1';
  $handler->display->display_options['fields']['field_senator_1']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator_1']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator_1']['label'] = '';
  $handler->display->display_options['fields']['field_senator_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator_1']['empty'] = '[field_committee_member_name] ';
  $handler->display->display_options['fields']['field_senator_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_senator_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_senator_1']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field collection item: Committee Member Role */
  $handler->display->display_options['fields']['field_misc_committee_member_role']['id'] = 'field_misc_committee_member_role';
  $handler->display->display_options['fields']['field_misc_committee_member_role']['table'] = 'field_data_field_misc_committee_member_role';
  $handler->display->display_options['fields']['field_misc_committee_member_role']['field'] = 'field_misc_committee_member_role';
  $handler->display->display_options['fields']['field_misc_committee_member_role']['label'] = '';
  $handler->display->display_options['fields']['field_misc_committee_member_role']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_misc_committee_member_role']['alter']['text'] = '<div class="role">[field_misc_committee_member_role]</div>';
  $handler->display->display_options['fields']['field_misc_committee_member_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Committee Member Role Type (field_committee_member_role_type) */
  $handler->display->display_options['sorts']['field_committee_member_role_type_value']['id'] = 'field_committee_member_role_type_value';
  $handler->display->display_options['sorts']['field_committee_member_role_type_value']['table'] = 'field_data_field_committee_member_role_type';
  $handler->display->display_options['sorts']['field_committee_member_role_type_value']['field'] = 'field_committee_member_role_type_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_group_members_taxonomy_term';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_group_members' => 'field_group_members',
  );
  /* Filter criterion: Field collection item: Committee Member Role Type (field_committee_member_role_type) */
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['id'] = 'field_committee_member_role_type_value';
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['table'] = 'field_data_field_committee_member_role_type';
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['field'] = 'field_committee_member_role_type_value';
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_committee_member_role_type_value']['value'] = array(
    'chair' => 'chair',
  );
  $export['committee_members'] = $view;

  $view = new view();
  $view->name = 'foil_webform';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Foil Webform';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Webform: Webform form body */
  $handler->display->display_options['fields']['webform_form_body']['id'] = 'webform_form_body';
  $handler->display->display_options['fields']['webform_form_body']['table'] = 'node';
  $handler->display->display_options['fields']['webform_form_body']['field'] = 'webform_form_body';
  $handler->display->display_options['fields']['webform_form_body']['label'] = '';
  $handler->display->display_options['fields']['webform_form_body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'webform' => 'webform',
  );
  /* Filter criterion: Content: Content UUID */
  $handler->display->display_options['filters']['uuid']['id'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['table'] = 'node';
  $handler->display->display_options['filters']['uuid']['field'] = 'uuid';
  $handler->display->display_options['filters']['uuid']['value'] = 'ce3332af-17d4-4da8-b04e-911dfbd08345';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['foil_webform'] = $view;

  $view = new view();
  $view->name = 'my_webforms';
  $view->description = 'An administrative list of webform nodes';
  $view->tag = 'webform';
  $view->base_table = 'webform';
  $view->human_name = 'my_webforms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    10 => '10',
    13 => '13',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'status' => 'status',
    'webform_results' => 'webform_results',
    'webform_results_2' => 'webform_results',
    'webform_results_3' => 'webform_results',
    'webform_results_4' => 'webform_results',
    'edit_node' => 'edit_node',
    'webform_edit' => 'edit_node',
    'webform_results_1' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'webform_results' => array(
      'align' => '',
      'separator' => ' &nbsp; ',
      'empty_column' => 0,
    ),
    'webform_results_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'webform_results_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'webform_results_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' &nbsp; ',
      'empty_column' => 0,
    ),
    'webform_edit' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'webform_results_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Webform: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['relationship'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'nid';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Webform: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'webform';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results']['id'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results']['label'] = 'View';
  $handler->display->display_options['fields']['webform_results']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results']['text'] = 'Submissions';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_2']['id'] = 'webform_results_2';
  $handler->display->display_options['fields']['webform_results_2']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_2']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_2']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_2']['label'] = 'Analysis';
  $handler->display->display_options['fields']['webform_results_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results_2']['text'] = 'Analysis';
  $handler->display->display_options['fields']['webform_results_2']['subpath'] = 'analysis';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_3']['id'] = 'webform_results_3';
  $handler->display->display_options['fields']['webform_results_3']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_3']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_3']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_3']['label'] = 'Table';
  $handler->display->display_options['fields']['webform_results_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results_3']['text'] = 'Table';
  $handler->display->display_options['fields']['webform_results_3']['subpath'] = 'table';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_4']['id'] = 'webform_results_4';
  $handler->display->display_options['fields']['webform_results_4']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_4']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_4']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_4']['label'] = 'Download';
  $handler->display->display_options['fields']['webform_results_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results_4']['text'] = 'Download';
  $handler->display->display_options['fields']['webform_results_4']['subpath'] = 'download';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Webform: Webform edit link */
  $handler->display->display_options['fields']['webform_edit']['id'] = 'webform_edit';
  $handler->display->display_options['fields']['webform_edit']['table'] = 'node';
  $handler->display->display_options['fields']['webform_edit']['field'] = 'webform_edit';
  $handler->display->display_options['fields']['webform_edit']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_edit']['label'] = 'Components';
  $handler->display->display_options['fields']['webform_edit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_edit']['text'] = 'Components';
  $handler->display->display_options['fields']['webform_edit']['subpath'] = 'components';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_1']['id'] = 'webform_results_1';
  $handler->display->display_options['fields']['webform_results_1']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_1']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_1']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_1']['label'] = 'Clear';
  $handler->display->display_options['fields']['webform_results_1']['text'] = 'Clear';
  $handler->display->display_options['fields']['webform_results_1']['subpath'] = 'clear';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'nid';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';

  /* Display: My Webforms */
  $handler = $view->new_display('page', 'My Webforms', 'my_webforms');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'nid';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'nid';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Webform: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'webform';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results']['id'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results']['label'] = 'View';
  $handler->display->display_options['fields']['webform_results']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results']['text'] = 'Submissions';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_2']['id'] = 'webform_results_2';
  $handler->display->display_options['fields']['webform_results_2']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_2']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_2']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_2']['label'] = 'Analysis';
  $handler->display->display_options['fields']['webform_results_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results_2']['text'] = 'Analysis';
  $handler->display->display_options['fields']['webform_results_2']['subpath'] = 'analysis';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_3']['id'] = 'webform_results_3';
  $handler->display->display_options['fields']['webform_results_3']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_3']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_3']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_3']['label'] = 'Table';
  $handler->display->display_options['fields']['webform_results_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results_3']['text'] = 'Table';
  $handler->display->display_options['fields']['webform_results_3']['subpath'] = 'table';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_4']['id'] = 'webform_results_4';
  $handler->display->display_options['fields']['webform_results_4']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_4']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_4']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_4']['label'] = 'Download';
  $handler->display->display_options['fields']['webform_results_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_results_4']['text'] = 'Download';
  $handler->display->display_options['fields']['webform_results_4']['subpath'] = 'download';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Webform: Webform edit link */
  $handler->display->display_options['fields']['webform_edit']['id'] = 'webform_edit';
  $handler->display->display_options['fields']['webform_edit']['table'] = 'node';
  $handler->display->display_options['fields']['webform_edit']['field'] = 'webform_edit';
  $handler->display->display_options['fields']['webform_edit']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_edit']['label'] = 'Components';
  $handler->display->display_options['fields']['webform_edit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_edit']['text'] = 'Components';
  $handler->display->display_options['fields']['webform_edit']['subpath'] = 'components';
  /* Field: Webform: Webform results link */
  $handler->display->display_options['fields']['webform_results_1']['id'] = 'webform_results_1';
  $handler->display->display_options['fields']['webform_results_1']['table'] = 'node';
  $handler->display->display_options['fields']['webform_results_1']['field'] = 'webform_results';
  $handler->display->display_options['fields']['webform_results_1']['relationship'] = 'nid';
  $handler->display->display_options['fields']['webform_results_1']['label'] = 'Clear';
  $handler->display->display_options['fields']['webform_results_1']['text'] = 'Clear';
  $handler->display->display_options['fields']['webform_results_1']['subpath'] = 'clear';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'admin/my-webforms';
  $export['my_webforms'] = $view;

  $view = new view();
  $view->name = 'news_by_issue';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content by Issue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Petitions related to this issue';
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
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no news associated to this issue';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
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
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => '',
  );
  /* Field: Content: Published Date */
  $handler->display->display_options['fields']['field_published']['id'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['table'] = 'field_data_field_published';
  $handler->display->display_options['fields']['field_published']['field'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['label'] = '';
  $handler->display->display_options['fields']['field_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_published']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['title'] = 'Latest %1 Video';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issues_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_issues_tid']['validate_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Accessible Sitewide (field_accessible_sitewide) */
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['id'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['table'] = 'field_data_field_accessible_sitewide';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['field'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['value'] = array(
    1 => '1',
  );

  /* Display: News */
  $handler = $view->new_display('block', 'News', 'main');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
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
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/search/global/%1" class="c-tab--link-more">See All News about %1</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There is no news associated to this issue</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['field_issues']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issues_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_issues_tid']['validate_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'article' => 'article',
    'in_the_news' => 'in_the_news',
    'press_release' => 'press_release',
    'video' => 'video',
  );

  /* Display: Video */
  $handler = $view->new_display('block', 'Video', 'video');
  $handler->display->display_options['defaults']['title'] = FALSE;
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
    'field_senator' => array(
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
  $handler->display->display_options['header']['area']['content'] = '<h3 class="pane-title">Latest %1 Video</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Youtube Video */
  $handler->display->display_options['fields']['field_yt']['id'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['table'] = 'field_data_field_yt';
  $handler->display->display_options['fields']['field_yt']['field'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['label'] = '';
  $handler->display->display_options['fields']['field_yt']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_yt']['alter']['text'] = '<div class="flex-video">[field_yt]</div>';
  $handler->display->display_options['fields']['field_yt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_yt']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_yt']['settings'] = array(
    'video_style' => 'normal',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issues_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_issues_tid']['validate_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'video' => 'video',
  );

  /* Display: Petition */
  $handler = $view->new_display('block', 'Petition', 'petition');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['alter']['text'] = '[field_senator]\'s [type]';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="content-title">[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issues_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_issues_tid']['validate_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'petition' => 'petition',
  );

  /* Display: Bills */
  $handler = $view->new_display('block', 'Bills', 'news_by_bill');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
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
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/search/global/%1" class="c-tab--link-more">See All Legislations about %1</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There is no legislation associated to this issue</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_ol_summary']['id'] = 'field_ol_summary';
  $handler->display->display_options['fields']['field_ol_summary']['table'] = 'field_data_field_ol_summary';
  $handler->display->display_options['fields']['field_ol_summary']['field'] = 'field_ol_summary';
  $handler->display->display_options['fields']['field_ol_summary']['label'] = '';
  $handler->display->display_options['fields']['field_ol_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Same As */
  $handler->display->display_options['fields']['field_ol_same_as']['id'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['table'] = 'field_data_field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['field'] = 'field_ol_same_as';
  /* Field: Content: Last Status */
  $handler->display->display_options['fields']['field_ol_last_status']['id'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['field'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status']['type'] = 'list_key';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'month_only';
  /* Field: Content: Last Status Date */
  $handler->display->display_options['fields']['field_ol_last_status_date']['id'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['field'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Latest Committee Status */
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['id'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['table'] = 'field_data_field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['field'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['label'] = '';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['element_label_colon'] = FALSE;
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_chamber']['type'] = 'list_key';
  /* Field: Content: All Statuses */
  $handler->display->display_options['fields']['field_ol_all_statuses']['id'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['table'] = 'field_data_field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['field'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['label'] = '';
  $handler->display->display_options['fields']['field_ol_all_statuses']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_all_statuses']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issues_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_issues_tid']['validate_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'bill' => 'bill',
    'resolution' => 'resolution',
  );

  /* Display: Meetings */
  $handler = $view->new_display('block', 'Meetings', 'meeting_by_issue');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
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
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/search/global/%1" class="c-tab--link-more">See All News about %1</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There are no upcoming meetings or public hearings scheduled at this time</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['field_issues']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Meeting Location */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_meeting_location']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issues_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issues_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issues_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_issues_tid']['validate_options']['vocabularies'] = array(
    'issues' => 'issues',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'meeting' => 'meeting',
    'public_hearing' => 'public_hearing',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['news_by_issue'] = $view;

  $view = new view();
  $view->name = 'nodequeue_2';
  $view->description = 'Display a list of all nodes in queue \'Sitewide Footer Promotional Banners\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Queue \'Sitewide Footer Promotional Banners\'';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'sitewide_footer_promotional_bann' => 'sitewide_footer_promotional_bann',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/2';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Queue \'Sitewide Footer Promotional Banners\'';
  $export['nodequeue_2'] = $view;

  $view = new view();
  $view->name = 'previous_sessions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Previous Sessions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Past Sessions';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_session_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_session_date_2',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => 'event-title',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => 'event-location-name icon-before__circle-pin',
    ),
    'field_session_date' => array(
      'element_type' => 'div',
      'class' => 'event-date',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Location: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'location';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'month_only',
    'custom_date_format' => '',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day_only',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Youtube Video */
  $handler->display->display_options['fields']['field_yt']['id'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['table'] = 'field_data_field_yt';
  $handler->display->display_options['fields']['field_yt']['field'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['label'] = '';
  $handler->display->display_options['fields']['field_yt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_yt']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_yt']['type'] = 'video_embed_field_thumbnail';
  $handler->display->display_options['fields']['field_yt']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'source',
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
  $handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_2']['settings'] = array(
    'format_type' => 'privatemsg_current_day',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['label'] = '';
  $handler->display->display_options['fields']['city']['element_type'] = '0';
  $handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['city']['element_default_classes'] = FALSE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['element_type'] = '0';
  $handler->display->display_options['fields']['province']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['province']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
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
    'session' => 'session',
  );
  /* Filter criterion: Content: Published on - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_date_value2']['granularity'] = 'hour';
  $handler->display->display_options['filters']['field_date_value2']['default_date'] = 'now';

  /* Display: Previous Sessions */
  $handler = $view->new_display('block', 'Previous Sessions', 'previous_sessions');
  $handler->display->display_options['block_description'] = 'Previous Sessions';
  $export['previous_sessions'] = $view;

  $view = new view();
  $view->name = 'senate_timeline';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senate Timeline';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Senate Timeline';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'views_json';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'description';
  /* Field: Content: start */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'y_m_d',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: end */
  $handler->display->display_options['fields']['field_end_date']['id'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['table'] = 'field_data_field_end_date';
  $handler->display->display_options['fields']['field_end_date']['field'] = 'field_end_date';
  $handler->display->display_options['fields']['field_end_date']['settings'] = array(
    'format_type' => 'y_m_d',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'timeline_item' => 'timeline_item',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'api/v1/senate-timeline';
  $export['senate_timeline'] = $view;

  $view = new view();
  $view->name = 'senators';
  $view->description = 'A view to output an index list of all senators';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senators and Committees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Senators and Committees';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_senator_party_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_senator_conference_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'tid_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'c-senator-block';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'picture_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_district' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_user_account' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_committee_members_taxonomy_term']['id'] = 'reverse_field_committee_members_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_committee_members_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_committee_members_taxonomy_term']['field'] = 'reverse_field_committee_members_taxonomy_term';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['id'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['field'] = 'reverse_field_senator_taxonomy_term';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['field_district_number']['label'] = '';
  $handler->display->display_options['fields']['field_district_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district_number']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
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
    'senator' => 'senator',
  );
  /* Filter criterion: Content: FOIL Request Form (field_active) */
  $handler->display->display_options['filters']['field_active_value']['id'] = 'field_active_value';
  $handler->display->display_options['filters']['field_active_value']['table'] = 'field_data_field_active';
  $handler->display->display_options['filters']['field_active_value']['field'] = 'field_active_value';
  $handler->display->display_options['filters']['field_active_value']['value'] = array(
    1 => '1',
  );

  /* Display: Committee Members */
  $handler = $view->new_display('block', 'Committee Members', 'committee_members');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_district' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_headshot' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_committee_members_taxonomy_term']['id'] = 'reverse_field_committee_members_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_committee_members_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_committee_members_taxonomy_term']['field'] = 'reverse_field_committee_members_taxonomy_term';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';

  /* Display: Senators List */
  $handler = $view->new_display('block', 'Senators List', 'senators');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
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
    'tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Filter by Committee',
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
    'field_party_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Filter by Party',
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'picture_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_district' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_user_account' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['id'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['field'] = 'reverse_field_senator_taxonomy_term';
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
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => '',
  );
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['field_district_number']['label'] = '';
  $handler->display->display_options['fields']['field_district_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district_number']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conference']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_conference']['delta_offset'] = '0';
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'senator' => 'senator',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: FOIL Request Form (field_active) */
  $handler->display->display_options['filters']['field_active_value']['id'] = 'field_active_value';
  $handler->display->display_options['filters']['field_active_value']['table'] = 'field_data_field_active';
  $handler->display->display_options['filters']['field_active_value']['field'] = 'field_active_value';
  $handler->display->display_options['filters']['field_active_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_active_value']['group'] = 1;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'committees';
  /* Filter criterion: Content: Party Affiliation (field_party) */
  $handler->display->display_options['filters']['field_party_value']['id'] = 'field_party_value';
  $handler->display->display_options['filters']['field_party_value']['table'] = 'field_data_field_party';
  $handler->display->display_options['filters']['field_party_value']['field'] = 'field_party_value';
  $handler->display->display_options['filters']['field_party_value']['value'] = array(
    'all' => 'all',
    'D' => 'D',
    'R' => 'R',
    'C' => 'C',
    'CNST' => 'CNST',
    'G' => 'G',
    'IP' => 'IP',
    'I' => 'I',
    'Ind' => 'Ind',
    'L' => 'L',
    'LIBT' => 'LIBT',
    'NL' => 'NL',
    'RTL' => 'RTL',
    'SJ' => 'SJ',
    'SC' => 'SC',
    'SWP' => 'SWP',
    'WF' => 'WF',
  );
  $handler->display->display_options['filters']['field_party_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_party_value']['expose']['operator_id'] = 'field_party_value_op';
  $handler->display->display_options['filters']['field_party_value']['expose']['operator'] = 'field_party_value_op';
  $handler->display->display_options['filters']['field_party_value']['expose']['identifier'] = 'field_party_value';
  $handler->display->display_options['filters']['field_party_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_party_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_party_value']['group_info']['label'] = 'Party (field_party)';
  $handler->display->display_options['filters']['field_party_value']['group_info']['identifier'] = 'field_party_value';
  $handler->display->display_options['filters']['field_party_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_party_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $export['senators'] = $view;

  $view = new view();
  $view->name = 'session_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Session Details';
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
    'field_live_message_override' => array(
      'element_type' => 'div',
      'class' => 'live-msg-override',
    ),
    'field_live_message_status' => array(
      'element_type' => 'div',
      'class' => 'live-msg-status',
    ),
    'field_date_1' => array(
      'element_type' => 'div',
      'class' => 'session-month',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => 'session-day',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => 'session-title',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => 'session-location icon-before__circle-pin',
    ),
    'field_date_2' => array(
      'element_type' => 'div',
      'class' => 'session-date',
    ),
    'body' => array(
      'element_type' => 'div',
      'class' => 'session-body',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => 'field-name-field-issues',
    ),
  );
  /* Field: Content: Live Message Override */
  $handler->display->display_options['fields']['field_live_message_override']['id'] = 'field_live_message_override';
  $handler->display->display_options['fields']['field_live_message_override']['table'] = 'field_data_field_live_message_override';
  $handler->display->display_options['fields']['field_live_message_override']['field'] = 'field_live_message_override';
  $handler->display->display_options['fields']['field_live_message_override']['label'] = '';
  $handler->display->display_options['fields']['field_live_message_override']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_live_message_override']['hide_empty'] = TRUE;
  /* Field: Content: Live Message Status */
  $handler->display->display_options['fields']['field_live_message_status']['id'] = 'field_live_message_status';
  $handler->display->display_options['fields']['field_live_message_status']['table'] = 'field_data_field_live_message_status';
  $handler->display->display_options['fields']['field_live_message_status']['field'] = 'field_live_message_status';
  $handler->display->display_options['fields']['field_live_message_status']['label'] = '';
  $handler->display->display_options['fields']['field_live_message_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_live_message_status']['hide_empty'] = TRUE;
  /* Field: Publish Date: Day Only */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['ui_name'] = 'Publish Date: Day Only';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Publish Date: Month Only */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Publish Date: Month Only';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'both',
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
  /* Field: Location: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'location';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_video_status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_video_status']['alter']['text'] = '<span class="c-session-video--status icon-before__youtube">[field_video_status]</span>';
  $handler->display->display_options['fields']['field_video_status']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'session' => 'session',
  );

  /* Display: Session Basic Data */
  $handler = $view->new_display('block', 'Session Basic Data', 'block');
  $handler->display->display_options['block_description'] = 'Session Basic Data Block';
  $export['session_details'] = $view;

  $view = new view();
  $view->name = 'student_programs_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Student Programs News';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'fast';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div><a href="/student-programs" class="c-container--link">Learn More</a></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More';
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
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
    'article' => 'article',
    'in_the_news' => 'in_the_news',
    'press_release' => 'press_release',
    'video' => 'video',
  );
  /* Filter criterion: : field_student_program_related (field_student_program_related) */
  $handler->display->display_options['filters']['field_student_program_related_value']['id'] = 'field_student_program_related_value';
  $handler->display->display_options['filters']['field_student_program_related_value']['table'] = 'field_data_field_student_program_related';
  $handler->display->display_options['filters']['field_student_program_related_value']['field'] = 'field_student_program_related_value';
  $handler->display->display_options['filters']['field_student_program_related_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Student Program Intro (field_student_program_intro) */
  $handler->display->display_options['filters']['field_student_program_intro_value']['id'] = 'field_student_program_intro_value';
  $handler->display->display_options['filters']['field_student_program_intro_value']['table'] = 'field_data_field_student_program_intro';
  $handler->display->display_options['filters']['field_student_program_intro_value']['field'] = 'field_student_program_intro_value';
  $handler->display->display_options['filters']['field_student_program_intro_value']['value'] = array(
    1 => '1',
  );

  /* Display: News */
  $handler = $view->new_display('block', 'News', 'main');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Student Program News';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'fast';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => 'content-title',
    ),
    'type' => array(
      'element_type' => 'div',
      'class' => 'content-type',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => 'published-date',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => 'main-image',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There are no news related to Student Programs at this time</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = 'Article';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'student_program' => 'student_program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Student Program News';

  /* Display: Student Program Latest Article */
  $handler = $view->new_display('block', 'Student Program Latest Article', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'nys-arrow-link';
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'student_program' => 'student_program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Student Program Intro (field_student_program_intro) */
  $handler->display->display_options['filters']['field_student_program_intro_value']['id'] = 'field_student_program_intro_value';
  $handler->display->display_options['filters']['field_student_program_intro_value']['table'] = 'field_data_field_student_program_intro';
  $handler->display->display_options['filters']['field_student_program_intro_value']['field'] = 'field_student_program_intro_value';
  $handler->display->display_options['filters']['field_student_program_intro_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_student_program_intro_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Is Featured (field_featured) */
  $handler->display->display_options['filters']['field_featured_value']['id'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['table'] = 'field_data_field_featured';
  $handler->display->display_options['filters']['field_featured_value']['field'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['value'] = array(
    1 => '1',
  );

  /* Display: Student Program Highlight Article */
  $handler = $view->new_display('block', 'Student Program Highlight Article', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2 class="nys-title">[title]</h2>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'student_program' => 'student_program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Student Program Intro (field_student_program_intro) */
  $handler->display->display_options['filters']['field_student_program_intro_value']['id'] = 'field_student_program_intro_value';
  $handler->display->display_options['filters']['field_student_program_intro_value']['table'] = 'field_data_field_student_program_intro';
  $handler->display->display_options['filters']['field_student_program_intro_value']['field'] = 'field_student_program_intro_value';
  $handler->display->display_options['filters']['field_student_program_intro_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_student_program_intro_value']['group'] = 1;

  /* Display: News No Link */
  $handler = $view->new_display('block', 'News No Link', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Student Program News';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'fast';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => 'content-title',
    ),
    'type' => array(
      'element_type' => 'div',
      'class' => 'content-type',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => 'published-date',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => 'main-image',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There are no news related to Student Programs at this time</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = 'Article';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'student_program' => 'student_program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Student Program News';
  $export['student_programs_news'] = $view;

  return $export;
}
