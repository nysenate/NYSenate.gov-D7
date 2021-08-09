<?php

/**
 * @file
 * nys_legislation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_legislation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'upcoming_legislation_calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Upcoming Legislation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Legislation';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '[field_date] / cal no. [field_ol_cal_no]';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['id'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['table'] = 'field_data_field_session_calendars';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['field'] = 'field_session_calendars_target_id';
  /* Relationship: Content: Calendar (field_ol_cal) */
  $handler->display->display_options['relationships']['field_ol_cal_value']['id'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['table'] = 'field_data_field_ol_cal';
  $handler->display->display_options['relationships']['field_ol_cal_value']['field'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_ol_cal_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['id'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['table'] = 'field_data_field_ol_bill';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['field'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['relationship'] = 'field_ol_cal_value';
  /* Relationship: Content: Votes (field_ol_votes) */
  $handler->display->display_options['relationships']['field_ol_votes_value']['id'] = 'field_ol_votes_value';
  $handler->display->display_options['relationships']['field_ol_votes_value']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['relationships']['field_ol_votes_value']['field'] = 'field_ol_votes_value';
  $handler->display->display_options['relationships']['field_ol_votes_value']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_votes_value']['delta'] = '-1';
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Type */
  $handler->display->display_options['fields']['field_ol_type']['id'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['field'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['fields']['field_ol_type']['label'] = '';
  $handler->display->display_options['fields']['field_ol_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
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
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'sponsor_list',
    'links' => 0,
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Calendar Number */
  $handler->display->display_options['fields']['field_ol_cal_no']['id'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['table'] = 'field_data_field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['field'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['fields']['field_ol_cal_no']['label'] = '';
  $handler->display->display_options['fields']['field_ol_cal_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_cal_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Votes */
  $handler->display->display_options['fields']['field_ol_votes']['id'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['field'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_votes']['label'] = '';
  $handler->display->display_options['fields']['field_ol_votes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_votes']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_ol_votes']['settings'] = array(
    'view_mode' => 'search_index',
  );
  $handler->display->display_options['fields']['field_ol_votes']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ol_votes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_votes']['delta_reversed'] = TRUE;
  $handler->display->display_options['fields']['field_ol_votes']['delta_first_last'] = TRUE;
  /* Field: Field collection item: Bill Cal Number */
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['id'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['table'] = 'field_data_field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['field'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['relationship'] = 'field_ol_cal_value';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Field collection item: Vote Type */
  $handler->display->display_options['fields']['field_ol_vote_type']['id'] = 'field_ol_vote_type';
  $handler->display->display_options['fields']['field_ol_vote_type']['table'] = 'field_data_field_ol_vote_type';
  $handler->display->display_options['fields']['field_ol_vote_type']['field'] = 'field_ol_vote_type';
  $handler->display->display_options['fields']['field_ol_vote_type']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['fields']['field_ol_vote_type']['label'] = '';
  $handler->display->display_options['fields']['field_ol_vote_type']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
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
  /* Filter criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-0:+2';
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'active_list' => 'active_list',
  );

  /* Display: Recently Signed By the Governor */
  $handler = $view->new_display('block', 'Recently Signed By the Governor', 'signed_by_governor');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
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
    'title_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Votes (field_ol_votes) */
  $handler->display->display_options['relationships']['field_ol_votes_value']['id'] = 'field_ol_votes_value';
  $handler->display->display_options['relationships']['field_ol_votes_value']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['relationships']['field_ol_votes_value']['field'] = 'field_ol_votes_value';
  $handler->display->display_options['relationships']['field_ol_votes_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_ol_votes_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ol_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_ol_name']['alter']['max_length'] = '135';
  $handler->display->display_options['fields']['field_ol_name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
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
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 0,
  );
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Votes */
  $handler->display->display_options['fields']['field_ol_votes']['id'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['field'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_ol_votes']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_ol_votes']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_ol_votes']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_ol_votes']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ol_votes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_votes']['delta_reversed'] = TRUE;
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  /* Field: Content: Has Same As */
  $handler->display->display_options['fields']['field_ol_has_same_as']['id'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['table'] = 'field_data_field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['field'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_has_same_as']['element_label_colon'] = FALSE;
  /* Field: Content: Same As */
  $handler->display->display_options['fields']['field_ol_same_as']['id'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['table'] = 'field_data_field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['field'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_same_as']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'bill' => 'bill',
  );
  /* Filter criterion: Content: Last Status (field_ol_last_status) */
  $handler->display->display_options['filters']['field_ol_last_status_value']['id'] = 'field_ol_last_status_value';
  $handler->display->display_options['filters']['field_ol_last_status_value']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['filters']['field_ol_last_status_value']['field'] = 'field_ol_last_status_value';
  $handler->display->display_options['filters']['field_ol_last_status_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_last_status_value']['value'] = array(
    'SIGNED_BY_GOV' => 'SIGNED_BY_GOV',
  );
  /* Filter criterion: Content: Session (field_ol_session) */
  $handler->display->display_options['filters']['field_ol_session_value']['id'] = 'field_ol_session_value';
  $handler->display->display_options['filters']['field_ol_session_value']['table'] = 'field_data_field_ol_session';
  $handler->display->display_options['filters']['field_ol_session_value']['field'] = 'field_ol_session_value';
  $handler->display->display_options['filters']['field_ol_session_value']['value']['min'] = '2015';
  $handler->display->display_options['filters']['field_ol_session_value']['value']['max'] = '2015';
  /* Filter criterion: Content: Is Amended (field_ol_is_amended) */
  $handler->display->display_options['filters']['field_ol_is_amended_value']['id'] = 'field_ol_is_amended_value';
  $handler->display->display_options['filters']['field_ol_is_amended_value']['table'] = 'field_data_field_ol_is_amended';
  $handler->display->display_options['filters']['field_ol_is_amended_value']['field'] = 'field_ol_is_amended_value';
  $handler->display->display_options['filters']['field_ol_is_amended_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Field collection item: Vote Type (field_ol_vote_type) */
  $handler->display->display_options['filters']['field_ol_vote_type_value']['id'] = 'field_ol_vote_type_value';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['table'] = 'field_data_field_ol_vote_type';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['field'] = 'field_ol_vote_type_value';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['relationship'] = 'field_ol_votes_value';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['value'] = array(
    'floor' => 'floor',
  );

  /* Display: Recently Passed Senate */
  $handler = $view->new_display('block', 'Recently Passed Senate', 'passed_senate');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
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
    'title_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Votes (field_ol_votes) */
  $handler->display->display_options['relationships']['field_ol_votes_value']['id'] = 'field_ol_votes_value';
  $handler->display->display_options['relationships']['field_ol_votes_value']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['relationships']['field_ol_votes_value']['field'] = 'field_ol_votes_value';
  $handler->display->display_options['relationships']['field_ol_votes_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_ol_votes_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ol_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_ol_name']['alter']['max_length'] = '135';
  $handler->display->display_options['fields']['field_ol_name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
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
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 0,
  );
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Votes */
  $handler->display->display_options['fields']['field_ol_votes']['id'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['field'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['group_type'] = 'max';
  $handler->display->display_options['fields']['field_ol_votes']['label'] = '';
  $handler->display->display_options['fields']['field_ol_votes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_votes']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_ol_votes']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_ol_votes']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_ol_votes']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ol_votes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_votes']['delta_reversed'] = TRUE;
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Has Same As */
  $handler->display->display_options['fields']['field_ol_has_same_as']['id'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['table'] = 'field_data_field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['field'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_has_same_as']['element_label_colon'] = FALSE;
  /* Field: Content: Same As */
  $handler->display->display_options['fields']['field_ol_same_as']['id'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['table'] = 'field_data_field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['field'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_same_as']['element_label_colon'] = FALSE;
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'bill' => 'bill',
  );
  /* Filter criterion: Content: Last Status (field_ol_last_status) */
  $handler->display->display_options['filters']['field_ol_last_status_value']['id'] = 'field_ol_last_status_value';
  $handler->display->display_options['filters']['field_ol_last_status_value']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['filters']['field_ol_last_status_value']['field'] = 'field_ol_last_status_value';
  $handler->display->display_options['filters']['field_ol_last_status_value']['value'] = array(
    'PASSED_SENATE' => 'PASSED_SENATE',
    'DELIVERED_TO_GOV' => 'DELIVERED_TO_GOV',
  );
  /* Filter criterion: Content: Session (field_ol_session) */
  $handler->display->display_options['filters']['field_ol_session_value']['id'] = 'field_ol_session_value';
  $handler->display->display_options['filters']['field_ol_session_value']['table'] = 'field_data_field_ol_session';
  $handler->display->display_options['filters']['field_ol_session_value']['field'] = 'field_ol_session_value';
  /* Filter criterion: Content: Is Amended (field_ol_is_amended) */
  $handler->display->display_options['filters']['field_ol_is_amended_value']['id'] = 'field_ol_is_amended_value';
  $handler->display->display_options['filters']['field_ol_is_amended_value']['table'] = 'field_data_field_ol_is_amended';
  $handler->display->display_options['filters']['field_ol_is_amended_value']['field'] = 'field_ol_is_amended_value';
  $handler->display->display_options['filters']['field_ol_is_amended_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Field collection item: Vote Type (field_ol_vote_type) */
  $handler->display->display_options['filters']['field_ol_vote_type_value']['id'] = 'field_ol_vote_type_value';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['table'] = 'field_data_field_ol_vote_type';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['field'] = 'field_ol_vote_type_value';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['relationship'] = 'field_ol_votes_value';
  $handler->display->display_options['filters']['field_ol_vote_type_value']['value'] = array(
    'floor' => 'floor',
  );

  /* Display: Active List Content */
  $handler = $view->new_display('block', 'Active List Content', 'active_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.active-list-wrapper';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Floor Calendar Content */
  $handler = $view->new_display('block', 'Floor Calendar Content', 'floor_calendar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.floor-calendar-wrapper';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[field_date]';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-0:+2';
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'floor_calendar' => 'floor_calendar',
  );

  /* Display: Supplemental Calendar Content */
  $handler = $view->new_display('block', 'Supplemental Calendar Content', 'supplemental_calendar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.supplemental-calendar-wrapper';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'supplemental_calendar' => 'supplemental_calendar',
  );
  $handler->display->display_options['filters']['field_ol_type_value']['group'] = 1;

  /* Display: Session Active List Content */
  $handler = $view->new_display('block', 'Session Active List Content', 'sess_active_list_content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['id'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['table'] = 'field_data_field_session_calendars';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['field'] = 'field_session_calendars_target_id';
  /* Relationship: Content: Calendar (field_ol_cal) */
  $handler->display->display_options['relationships']['field_ol_cal_value']['id'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['table'] = 'field_data_field_ol_cal';
  $handler->display->display_options['relationships']['field_ol_cal_value']['field'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_ol_cal_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['id'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['table'] = 'field_data_field_ol_bill';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['field'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Type */
  $handler->display->display_options['fields']['field_ol_type']['id'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['field'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['fields']['field_ol_type']['label'] = '';
  $handler->display->display_options['fields']['field_ol_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
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
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 0,
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Calendar Number */
  $handler->display->display_options['fields']['field_ol_cal_no']['id'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['table'] = 'field_data_field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['field'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['fields']['field_ol_cal_no']['label'] = '';
  $handler->display->display_options['fields']['field_ol_cal_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_cal_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Bill Cal Number */
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['id'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['table'] = 'field_data_field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['field'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['relationship'] = 'field_ol_cal_value';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_ol_add_sponsors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['separator'] = '<br />';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'session' => 'session',
  );
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'active_list' => 'active_list',
  );

  /* Display: Session Floor Calendar Content */
  $handler = $view->new_display('block', 'Session Floor Calendar Content', 'sess_floor_calendar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.floor-calendar-wrapper';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_ol_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_committee_status' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_last_status' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_last_status_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_sponsor' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_cal_no' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_sponsor_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_bill_cal_number' => array(
      'element_type' => 'div',
      'class' => '',
      'label_element_type' => 'label',
      'label_class' => '',
    ),
    'counter' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['id'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['table'] = 'field_data_field_session_calendars';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['field'] = 'field_session_calendars_target_id';
  /* Relationship: Content: Calendar (field_ol_cal) */
  $handler->display->display_options['relationships']['field_ol_cal_value']['id'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['table'] = 'field_data_field_ol_cal';
  $handler->display->display_options['relationships']['field_ol_cal_value']['field'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_ol_cal_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['id'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['table'] = 'field_data_field_ol_bill';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['field'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ol_name']['alter']['text'] = '<a href="[path]">[field_ol_name]</a>';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Type */
  $handler->display->display_options['fields']['field_ol_type']['id'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['field'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['fields']['field_ol_type']['label'] = '';
  $handler->display->display_options['fields']['field_ol_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
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
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 0,
  );
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Calendar Number */
  $handler->display->display_options['fields']['field_ol_cal_no']['id'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['table'] = 'field_data_field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['field'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['fields']['field_ol_cal_no']['label'] = '';
  $handler->display->display_options['fields']['field_ol_cal_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_cal_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Bill Cal Number */
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['id'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['table'] = 'field_data_field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['field'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['relationship'] = 'field_ol_cal_value';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
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
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_ol_add_sponsors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['separator'] = '<br />';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'session' => 'session',
  );
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'floor_calendar' => 'floor_calendar',
  );

  /* Display: Session Supplemental Calendar Content */
  $handler = $view->new_display('block', 'Session Supplemental Calendar Content', 'sess_supplemental_calendar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.supplemental-calendar-wrapper';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['id'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['table'] = 'field_data_field_session_calendars';
  $handler->display->display_options['relationships']['field_session_calendars_target_id']['field'] = 'field_session_calendars_target_id';
  /* Relationship: Content: Calendar (field_ol_cal) */
  $handler->display->display_options['relationships']['field_ol_cal_value']['id'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['table'] = 'field_data_field_ol_cal';
  $handler->display->display_options['relationships']['field_ol_cal_value']['field'] = 'field_ol_cal_value';
  $handler->display->display_options['relationships']['field_ol_cal_value']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['relationships']['field_ol_cal_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['id'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['table'] = 'field_data_field_ol_bill';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['field'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['field_ol_bill_target_id']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Type */
  $handler->display->display_options['fields']['field_ol_type']['id'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['field'] = 'field_ol_type';
  $handler->display->display_options['fields']['field_ol_type']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['fields']['field_ol_type']['label'] = '';
  $handler->display->display_options['fields']['field_ol_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
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
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 0,
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Calendar Number */
  $handler->display->display_options['fields']['field_ol_cal_no']['id'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['table'] = 'field_data_field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['field'] = 'field_ol_cal_no';
  $handler->display->display_options['fields']['field_ol_cal_no']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['fields']['field_ol_cal_no']['label'] = '';
  $handler->display->display_options['fields']['field_ol_cal_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_cal_no']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Bill Cal Number */
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['id'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['table'] = 'field_data_field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['field'] = 'field_ol_bill_cal_number';
  $handler->display->display_options['fields']['field_ol_bill_cal_number']['relationship'] = 'field_ol_cal_value';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  /* Field: Content: Has Same As */
  $handler->display->display_options['fields']['field_ol_has_same_as']['id'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['table'] = 'field_data_field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['field'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_has_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_has_same_as']['element_label_colon'] = FALSE;
  /* Field: Content: Same As */
  $handler->display->display_options['fields']['field_ol_same_as']['id'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['table'] = 'field_data_field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['field'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_same_as']['element_label_colon'] = FALSE;
  /* Field: Content: Substituted By */
  $handler->display->display_options['fields']['field_ol_substituted_by']['id'] = 'field_ol_substituted_by';
  $handler->display->display_options['fields']['field_ol_substituted_by']['table'] = 'field_data_field_ol_substituted_by';
  $handler->display->display_options['fields']['field_ol_substituted_by']['field'] = 'field_ol_substituted_by';
  $handler->display->display_options['fields']['field_ol_substituted_by']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_substituted_by']['label'] = '';
  $handler->display->display_options['fields']['field_ol_substituted_by']['element_label_colon'] = FALSE;
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
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_ol_add_sponsors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_add_sponsors']['separator'] = '<br />';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'session' => 'session',
  );
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'supplemental_calendar' => 'supplemental_calendar',
  );

  /* Display: A/S Replacement Display */
  $handler = $view->new_display('block', 'A/S Replacement Display', 'a_s_replace_record');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Used in Back-End to Replace Assembly Bills with Senate Same-As';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_ol_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ol_name']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_ol_name']['alter']['max_length'] = '135';
  $handler->display->display_options['fields']['field_ol_name']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
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
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'view_mode' => 'agenda_senator_sponsors',
    'links' => 0,
  );
  /* Field: Content: Committee Status */
  $handler->display->display_options['fields']['field_committee_status']['id'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['table'] = 'field_data_field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['field'] = 'field_committee_status';
  $handler->display->display_options['fields']['field_committee_status']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_committee_status']['label'] = '';
  $handler->display->display_options['fields']['field_committee_status']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Votes */
  $handler->display->display_options['fields']['field_ol_votes']['id'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['table'] = 'field_data_field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['field'] = 'field_ol_votes';
  $handler->display->display_options['fields']['field_ol_votes']['label'] = '';
  $handler->display->display_options['fields']['field_ol_votes']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_votes']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_ol_votes']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_ol_votes']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_ol_votes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_votes']['delta_reversed'] = TRUE;
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Has Same As */
  $handler->display->display_options['fields']['field_ol_has_same_as']['id'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['table'] = 'field_data_field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['field'] = 'field_ol_has_same_as';
  $handler->display->display_options['fields']['field_ol_has_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_has_same_as']['element_label_colon'] = FALSE;
  /* Field: Content: Same As */
  $handler->display->display_options['fields']['field_ol_same_as']['id'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['table'] = 'field_data_field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['field'] = 'field_ol_same_as';
  $handler->display->display_options['fields']['field_ol_same_as']['label'] = '';
  $handler->display->display_options['fields']['field_ol_same_as']['element_label_colon'] = FALSE;
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $export['upcoming_legislation_calendar'] = $view;

  return $export;
}
