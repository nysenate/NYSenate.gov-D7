<?php
/**
 * @file
 * nys_senators.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_senators_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bills_for_featuring';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bill';
  $view->human_name = 'Bills for Featuring';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_bill_id_value']['id'] = 'field_bill_id_value';
  $handler->display->display_options['arguments']['field_bill_id_value']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['arguments']['field_bill_id_value']['field'] = 'field_bill_id_value';
  $handler->display->display_options['arguments']['field_bill_id_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_bill_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_bill_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_bill_id_value']['summary_options']['items_per_page'] = '25';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_bill_id' => 'field_bill_id',
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['bills_for_featuring'] = $view;

  $view = new view();
  $view->name = 'current_session_bills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Current Session Bills';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Session (field_ol_session) */
  $handler->display->display_options['arguments']['field_ol_session_value']['id'] = 'field_ol_session_value';
  $handler->display->display_options['arguments']['field_ol_session_value']['table'] = 'field_data_field_ol_session';
  $handler->display->display_options['arguments']['field_ol_session_value']['field'] = 'field_ol_session_value';
  $handler->display->display_options['arguments']['field_ol_session_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_ol_session_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_ol_session_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ol_session_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ol_session_value']['summary_options']['items_per_page'] = '25';
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

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['current_session_bills'] = $view;

  $view = new view();
  $view->name = 'featured_legislation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Featured Legislation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['id'] = 'field_featured_bill_target_id';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['field'] = 'field_featured_bill_target_id';
  /* Relationship: Field collection item: Entity with the Featured Legislation (field_featured_legislation) */
  $handler->display->display_options['relationships']['field_featured_legislation_node']['id'] = 'field_featured_legislation_node';
  $handler->display->display_options['relationships']['field_featured_legislation_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_featured_legislation_node']['field'] = 'field_featured_legislation_node';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['id'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['field'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['relationship'] = 'field_featured_legislation_node';
  /* Field: Content:  Constituent Vote */
  $handler->display->display_options['fields']['field__constituent_vote']['id'] = 'field__constituent_vote';
  $handler->display->display_options['fields']['field__constituent_vote']['table'] = 'field_data_field__constituent_vote';
  $handler->display->display_options['fields']['field__constituent_vote']['field'] = 'field__constituent_vote';
  $handler->display->display_options['fields']['field__constituent_vote']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field__constituent_vote']['label'] = '';
  $handler->display->display_options['fields']['field__constituent_vote']['element_label_colon'] = FALSE;
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_featured_quote']['id'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['table'] = 'field_data_field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['field'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['label'] = '';
  $handler->display->display_options['fields']['field_featured_quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_quote']['type'] = 'text_plain';
  /* Field: Field: Featured Bill */
  $handler->display->display_options['fields']['field_featured_bill']['id'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['field'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['label'] = '';
  $handler->display->display_options['fields']['field_featured_bill']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_bill']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Last Status */
  $handler->display->display_options['fields']['field_ol_last_status']['id'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['field'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_last_status']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status']['type'] = 'list_key';
  /* Field: Content: Latest Committee Status */
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['id'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['table'] = 'field_data_field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['field'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['label'] = '';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  /* Field: Content: All Statuses */
  $handler->display->display_options['fields']['field_ol_all_statuses']['id'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['table'] = 'field_data_field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['field'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_all_statuses']['label'] = '';
  $handler->display->display_options['fields']['field_ol_all_statuses']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_all_statuses']['type'] = 'text_plain';
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_headshot']['element_class'] = 'c-sponsor--img';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '45x45',
    'image_link' => 'content',
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_name']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_ol_name']['settings'] = array(
    'trim_length' => '220',
  );
  /* Field: Content: All Statuses */
  $handler->display->display_options['fields']['field_ol_all_statuses_1']['id'] = 'field_ol_all_statuses_1';
  $handler->display->display_options['fields']['field_ol_all_statuses_1']['table'] = 'field_data_field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses_1']['field'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses_1']['relationship'] = 'field_featured_bill_target_id';
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_chamber']['type'] = 'list_key';
  /* Field: Content: Last Status Date */
  $handler->display->display_options['fields']['field_ol_last_status_date']['id'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['field'] = 'field_ol_last_status_date';
  $handler->display->display_options['fields']['field_ol_last_status_date']['relationship'] = 'field_featured_bill_target_id';
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor_1']['id'] = 'field_ol_sponsor_1';
  $handler->display->display_options['fields']['field_ol_sponsor_1']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor_1']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor_1']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor_1']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_sponsor_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Co Sponsors */
  $handler->display->display_options['fields']['field_ol_co_sponsors']['id'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['table'] = 'field_data_field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['field'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['label'] = '';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_co_sponsors']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_ol_co_sponsors']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Senator Featured Legislation Main */
  $handler = $view->new_display('block', 'Senator Featured Legislation Main', 'senator_featured_legislation_main');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field: Featured Bill (field_featured_bill) */
  $handler->display->display_options['filters']['field_featured_bill_target_id']['id'] = 'field_featured_bill_target_id';
  $handler->display->display_options['filters']['field_featured_bill_target_id']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['filters']['field_featured_bill_target_id']['field'] = 'field_featured_bill_target_id';
  $handler->display->display_options['filters']['field_featured_bill_target_id']['operator'] = 'not empty';

  /* Display: Senator Featured Legislation Sub */
  $handler = $view->new_display('block', 'Senator Featured Legislation Sub', 'senator_featured_legislation_sub');

  /* Display: News Type Featured Legislation */
  $handler = $view->new_display('block', 'News Type Featured Legislation', 'news_type_related_legislation');
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['id'] = 'field_featured_bill_target_id';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['field'] = 'field_featured_bill_target_id';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_featured_legislation_commi_node']['id'] = 'field_featured_legislation_commi_node';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_node']['field'] = 'field_featured_legislation_commi_node';
  /* Relationship: Taxonomy term: Committee Featured Legislation (field_featured_legislation_commi) */
  $handler->display->display_options['relationships']['field_featured_legislation_commi_value']['id'] = 'field_featured_legislation_commi_value';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_value']['table'] = 'field_data_field_featured_legislation_commi';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_value']['field'] = 'field_featured_legislation_commi_value';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_value']['relationship'] = 'field_featured_legislation_commi_node';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_featured_quote']['id'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['table'] = 'field_data_field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['field'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['label'] = '';
  $handler->display->display_options['fields']['field_featured_quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_quote']['type'] = 'text_plain';
  /* Field: Field: Featured Bill */
  $handler->display->display_options['fields']['field_featured_bill']['id'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['field'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['label'] = '';
  $handler->display->display_options['fields']['field_featured_bill']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_bill']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Last Status */
  $handler->display->display_options['fields']['field_ol_last_status']['id'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['field'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_last_status']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status']['type'] = 'list_key';
  /* Field: Content: Latest Committee Status */
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['id'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['table'] = 'field_data_field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['field'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['label'] = '';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  /* Field: Content: All Statuses */
  $handler->display->display_options['fields']['field_ol_all_statuses']['id'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['table'] = 'field_data_field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['field'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_all_statuses']['label'] = '';
  $handler->display->display_options['fields']['field_ol_all_statuses']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_all_statuses']['type'] = 'text_plain';
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['field_image_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_image_headshot']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_headshot']['element_class'] = 'c-sponsor--img';
  $handler->display->display_options['fields']['field_image_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '45x45',
    'image_link' => 'content',
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  $export['featured_legislation'] = $view;

  $view = new view();
  $view->name = 'featured_legislation_2';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Featured Legislation';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['id'] = 'field_featured_bill_target_id';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['field'] = 'field_featured_bill_target_id';
  /* Relationship: Field collection item: Entity with the Featured Legislation (field_featured_legislation) */
  $handler->display->display_options['relationships']['field_featured_legislation_node']['id'] = 'field_featured_legislation_node';
  $handler->display->display_options['relationships']['field_featured_legislation_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_featured_legislation_node']['field'] = 'field_featured_legislation_node';
  /* Relationship: Field: Homepage Hero Image (field_image_hero:fid) */
  $handler->display->display_options['relationships']['field_image_hero_fid']['id'] = 'field_image_hero_fid';
  $handler->display->display_options['relationships']['field_image_hero_fid']['table'] = 'field_data_field_image_hero';
  $handler->display->display_options['relationships']['field_image_hero_fid']['field'] = 'field_image_hero_fid';
  $handler->display->display_options['relationships']['field_image_hero_fid']['relationship'] = 'field_featured_legislation_node';
  /* Field: Field: Featured Bill */
  $handler->display->display_options['fields']['field_featured_bill']['id'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['field'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['label'] = '';
  $handler->display->display_options['fields']['field_featured_bill']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_bill']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_featured_quote']['id'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['table'] = 'field_data_field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['field'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['label'] = '';
  $handler->display->display_options['fields']['field_featured_quote']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['field_featured_quote']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_featured_quote']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['text'] = 'In [field_openleg_current_committee] Committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['empty'] = 'Unknown Committee';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Senate District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['fields']['field_district']['label'] = '';
  $handler->display->display_options['fields']['field_district']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district']['empty'] = 'District not assigned';
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_hero_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_actions_status']['id'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['table'] = 'field_data_field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['field'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_actions_status']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_actions_status']['element_label_colon'] = FALSE;
  /* Field: : field_bill_user_vote */
  $handler->display->display_options['fields']['field_bill_user_vote']['id'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['table'] = 'field_data_field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['field'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_bill_user_vote']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_featured_legislation_node';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_featured_legislation' => 'field_featured_legislation',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'main');

  /* Display: Secondary */
  $handler = $view->new_display('block', 'Secondary', 'secondary');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '1';

  /* Display: Committee main */
  $handler = $view->new_display('block', 'Committee main', 'committee_main');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all legislation from this committee';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['id'] = 'field_featured_bill_target_id';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['field'] = 'field_featured_bill_target_id';
  /* Relationship: Field collection item: Entity with the Committee Featured Legislation (field_featured_legislation_commi) */
  $handler->display->display_options['relationships']['field_featured_legislation_commi_taxonomy_term']['id'] = 'field_featured_legislation_commi_taxonomy_term';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_taxonomy_term']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_taxonomy_term']['field'] = 'field_featured_legislation_commi_taxonomy_term';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featurer_senator_target_id']['id'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['relationships']['field_featurer_senator_target_id']['table'] = 'field_data_field_featurer_senator';
  $handler->display->display_options['relationships']['field_featurer_senator_target_id']['field'] = 'field_featurer_senator_target_id';
  /* Relationship: Field: Homepage Hero Image (field_image_hero:fid) */
  $handler->display->display_options['relationships']['field_image_hero_fid']['id'] = 'field_image_hero_fid';
  $handler->display->display_options['relationships']['field_image_hero_fid']['table'] = 'field_data_field_image_hero';
  $handler->display->display_options['relationships']['field_image_hero_fid']['field'] = 'field_image_hero_fid';
  $handler->display->display_options['relationships']['field_image_hero_fid']['relationship'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Featured Bill */
  $handler->display->display_options['fields']['field_featured_bill']['id'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['field'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['label'] = '';
  $handler->display->display_options['fields']['field_featured_bill']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_bill']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_featured_quote']['id'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['table'] = 'field_data_field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['field'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['label'] = '';
  $handler->display->display_options['fields']['field_featured_quote']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['field_featured_quote']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_featured_quote']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['text'] = 'In [field_openleg_current_committee] Committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['empty'] = 'Unknown Committee';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Senate District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['fields']['field_district']['label'] = '';
  $handler->display->display_options['fields']['field_district']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district']['empty'] = 'District not assigned';
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_hero_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_actions_status']['id'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['table'] = 'field_data_field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['field'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_actions_status']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_actions_status']['element_label_colon'] = FALSE;
  /* Field: : field_bill_user_vote */
  $handler->display->display_options['fields']['field_bill_user_vote']['id'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['table'] = 'field_data_field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['field'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_bill_user_vote']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_featured_legislation_commi_taxonomy_term';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
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
    'field_featured_legislation_commi' => 'field_featured_legislation_commi',
  );

  /* Display: Committee secondary */
  $handler = $view->new_display('block', 'Committee secondary', 'committee_secondary');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['id'] = 'field_featured_bill_target_id';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['relationships']['field_featured_bill_target_id']['field'] = 'field_featured_bill_target_id';
  /* Relationship: Field collection item: Entity with the Committee Featured Legislation (field_featured_legislation_commi) */
  $handler->display->display_options['relationships']['field_featured_legislation_commi_taxonomy_term']['id'] = 'field_featured_legislation_commi_taxonomy_term';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_taxonomy_term']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_featured_legislation_commi_taxonomy_term']['field'] = 'field_featured_legislation_commi_taxonomy_term';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_featurer_senator_target_id']['id'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['relationships']['field_featurer_senator_target_id']['table'] = 'field_data_field_featurer_senator';
  $handler->display->display_options['relationships']['field_featurer_senator_target_id']['field'] = 'field_featurer_senator_target_id';
  /* Relationship: Field: Homepage Hero Image (field_image_hero:fid) */
  $handler->display->display_options['relationships']['field_image_hero_fid']['id'] = 'field_image_hero_fid';
  $handler->display->display_options['relationships']['field_image_hero_fid']['table'] = 'field_data_field_image_hero';
  $handler->display->display_options['relationships']['field_image_hero_fid']['field'] = 'field_image_hero_fid';
  $handler->display->display_options['relationships']['field_image_hero_fid']['relationship'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Featured Bill */
  $handler->display->display_options['fields']['field_featured_bill']['id'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['table'] = 'field_data_field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['field'] = 'field_featured_bill';
  $handler->display->display_options['fields']['field_featured_bill']['label'] = '';
  $handler->display->display_options['fields']['field_featured_bill']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_bill']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_featured_quote']['id'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['table'] = 'field_data_field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['field'] = 'field_featured_quote';
  $handler->display->display_options['fields']['field_featured_quote']['label'] = '';
  $handler->display->display_options['fields']['field_featured_quote']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['field_featured_quote']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_featured_quote']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['text'] = 'In [field_openleg_current_committee] Committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['empty'] = 'Unknown Committee';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Senate District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_featurer_senator_target_id';
  $handler->display->display_options['fields']['field_district']['label'] = '';
  $handler->display->display_options['fields']['field_district']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district']['empty'] = 'District not assigned';
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_hero_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_actions_status']['id'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['table'] = 'field_data_field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['field'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_openleg_actions_status']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_actions_status']['element_label_colon'] = FALSE;
  /* Field: : field_bill_user_vote */
  $handler->display->display_options['fields']['field_bill_user_vote']['id'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['table'] = 'field_data_field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['field'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['relationship'] = 'field_featured_bill_target_id';
  $handler->display->display_options['fields']['field_bill_user_vote']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_featured_legislation_commi_taxonomy_term';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
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
    'field_featured_legislation_commi' => 'field_featured_legislation_commi',
  );
  $export['featured_legislation_2'] = $view;

  $view = new view();
  $view->name = 'legislation_bills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Legislation Bills';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'c-news-container';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
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
  /* Field: Content: Last Status */
  $handler->display->display_options['fields']['field_ol_last_status']['id'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['field'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status']['type'] = 'list_key';
  /* Field: Content: Latest Committee Status */
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['id'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['table'] = 'field_data_field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['field'] = 'field_ol_latest_status_committee';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['label'] = '';
  $handler->display->display_options['fields']['field_ol_latest_status_committee']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Co Sponsors */
  $handler->display->display_options['fields']['field_ol_co_sponsors']['id'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['table'] = 'field_data_field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['field'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['label'] = '';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_co_sponsors']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_ol_co_sponsors']['delta_offset'] = '0';
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
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Chamber (field_ol_chamber) */
  $handler->display->display_options['filters']['field_ol_chamber_value']['id'] = 'field_ol_chamber_value';
  $handler->display->display_options['filters']['field_ol_chamber_value']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['filters']['field_ol_chamber_value']['field'] = 'field_ol_chamber_value';
  $handler->display->display_options['filters']['field_ol_chamber_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_chamber_value']['value'] = array(
    'senate' => 'senate',
  );
  $handler->display->display_options['filters']['field_ol_chamber_value']['group'] = 1;
  /* Filter criterion: Content: Sponsor (field_ol_sponsor) */
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['id'] = 'field_ol_sponsor_target_id';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['field'] = 'field_ol_sponsor_target_id';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['group'] = 2;
  /* Filter criterion: Content: Co Sponsors (field_ol_co_sponsors) */
  $handler->display->display_options['filters']['field_ol_co_sponsors_target_id']['id'] = 'field_ol_co_sponsors_target_id';
  $handler->display->display_options['filters']['field_ol_co_sponsors_target_id']['table'] = 'field_data_field_ol_co_sponsors';
  $handler->display->display_options['filters']['field_ol_co_sponsors_target_id']['field'] = 'field_ol_co_sponsors_target_id';
  $handler->display->display_options['filters']['field_ol_co_sponsors_target_id']['group'] = 2;

  /* Display: Senator Legislation Bills */
  $handler = $view->new_display('block', 'Senator Legislation Bills', 'senator_legislation_bills');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Chamber (field_ol_chamber) */
  $handler->display->display_options['filters']['field_ol_chamber_value']['id'] = 'field_ol_chamber_value';
  $handler->display->display_options['filters']['field_ol_chamber_value']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['filters']['field_ol_chamber_value']['field'] = 'field_ol_chamber_value';
  $handler->display->display_options['filters']['field_ol_chamber_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_chamber_value']['value'] = array(
    'senate' => 'senate',
  );
  $handler->display->display_options['filters']['field_ol_chamber_value']['group'] = 1;
  /* Filter criterion: Content: Sponsor (field_ol_sponsor) */
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['id'] = 'field_ol_sponsor_target_id';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['field'] = 'field_ol_sponsor_target_id';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['group'] = 2;
  /* Filter criterion: Content: Is Active Version (field_ol_is_active_version) */
  $handler->display->display_options['filters']['field_ol_is_active_version_value']['id'] = 'field_ol_is_active_version_value';
  $handler->display->display_options['filters']['field_ol_is_active_version_value']['table'] = 'field_data_field_ol_is_active_version';
  $handler->display->display_options['filters']['field_ol_is_active_version_value']['field'] = 'field_ol_is_active_version_value';
  $handler->display->display_options['filters']['field_ol_is_active_version_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_ol_is_active_version_value']['group'] = 1;

  /* Display: Senator Homepage Legislation Bills */
  $handler = $view->new_display('block', 'Senator Homepage Legislation Bills', 'senator_homepage_legislation_bills');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Senator Legislation Resolutions */
  $handler = $view->new_display('block', 'Senator Legislation Resolutions', 'senator_legislation_resolutions');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Publish Date (field_ol_publish_date) */
  $handler->display->display_options['sorts']['field_ol_publish_date_value']['id'] = 'field_ol_publish_date_value';
  $handler->display->display_options['sorts']['field_ol_publish_date_value']['table'] = 'field_data_field_ol_publish_date';
  $handler->display->display_options['sorts']['field_ol_publish_date_value']['field'] = 'field_ol_publish_date_value';
  $handler->display->display_options['sorts']['field_ol_publish_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'resolution' => 'resolution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Chamber (field_ol_chamber) */
  $handler->display->display_options['filters']['field_ol_chamber_value']['id'] = 'field_ol_chamber_value';
  $handler->display->display_options['filters']['field_ol_chamber_value']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['filters']['field_ol_chamber_value']['field'] = 'field_ol_chamber_value';
  $handler->display->display_options['filters']['field_ol_chamber_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_ol_chamber_value']['value'] = array(
    'senate' => 'senate',
  );
  $handler->display->display_options['filters']['field_ol_chamber_value']['group'] = 1;
  /* Filter criterion: Content: Sponsor (field_ol_sponsor) */
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['id'] = 'field_ol_sponsor_target_id';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['field'] = 'field_ol_sponsor_target_id';
  $handler->display->display_options['filters']['field_ol_sponsor_target_id']['group'] = 2;
  $export['legislation_bills'] = $view;

  $view = new view();
  $view->name = 'nys_senator_hero';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator Hero';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
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
    'field_active' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_conference' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_current_duties' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_district' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_pallette_selector' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_facebook_url' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_twitter_url' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_youtube_url' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
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
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Active Senator */
  $handler->display->display_options['fields']['field_active']['id'] = 'field_active';
  $handler->display->display_options['fields']['field_active']['table'] = 'field_data_field_active';
  $handler->display->display_options['fields']['field_active']['field'] = 'field_active';
  $handler->display->display_options['fields']['field_active']['label'] = '';
  $handler->display->display_options['fields']['field_active']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_active']['element_label_colon'] = FALSE;
  /* Field: Content: Conference */
  $handler->display->display_options['fields']['field_conference']['id'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['table'] = 'field_data_field_conference';
  $handler->display->display_options['fields']['field_conference']['field'] = 'field_conference';
  $handler->display->display_options['fields']['field_conference']['label'] = '';
  $handler->display->display_options['fields']['field_conference']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_conference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conference']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_conference']['settings'] = array(
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
  $handler->display->display_options['fields']['field_conference']['delta_offset'] = '0';
  /* Field: Content: Titles */
  $handler->display->display_options['fields']['field_current_duties']['id'] = 'field_current_duties';
  $handler->display->display_options['fields']['field_current_duties']['table'] = 'field_data_field_current_duties';
  $handler->display->display_options['fields']['field_current_duties']['field'] = 'field_current_duties';
  $handler->display->display_options['fields']['field_current_duties']['label'] = '';
  $handler->display->display_options['fields']['field_current_duties']['element_label_colon'] = FALSE;
  /* Field: Content: Microsite Theme */
  $handler->display->display_options['fields']['field_pallette_selector']['id'] = 'field_pallette_selector';
  $handler->display->display_options['fields']['field_pallette_selector']['table'] = 'field_data_field_pallette_selector';
  $handler->display->display_options['fields']['field_pallette_selector']['field'] = 'field_pallette_selector';
  $handler->display->display_options['fields']['field_pallette_selector']['label'] = '';
  $handler->display->display_options['fields']['field_pallette_selector']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_pallette_selector']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pallette_selector']['type'] = 'list_key';
  /* Field: Content: Facebook URL */
  $handler->display->display_options['fields']['field_facebook_url']['id'] = 'field_facebook_url';
  $handler->display->display_options['fields']['field_facebook_url']['table'] = 'field_data_field_facebook_url';
  $handler->display->display_options['fields']['field_facebook_url']['field'] = 'field_facebook_url';
  $handler->display->display_options['fields']['field_facebook_url']['label'] = '';
  $handler->display->display_options['fields']['field_facebook_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_facebook_url']['type'] = 'text_plain';
  /* Field: Content: Twitter URL */
  $handler->display->display_options['fields']['field_twitter_url']['id'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['table'] = 'field_data_field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['field'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_url']['type'] = 'text_plain';
  /* Field: Content: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url']['id'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['table'] = 'field_data_field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url']['type'] = 'text_plain';
  /* Field: Content: Instagram URL */
  $handler->display->display_options['fields']['field_instagram_url']['id'] = 'field_instagram_url';
  $handler->display->display_options['fields']['field_instagram_url']['table'] = 'field_data_field_instagram_url';
  $handler->display->display_options['fields']['field_instagram_url']['field'] = 'field_instagram_url';
  $handler->display->display_options['fields']['field_instagram_url']['label'] = '';
  $handler->display->display_options['fields']['field_instagram_url']['element_label_colon'] = FALSE;
  /* Field: Field: Homepage Hero Image */
  $handler->display->display_options['fields']['field_image_hero']['id'] = 'field_image_hero';
  $handler->display->display_options['fields']['field_image_hero']['table'] = 'field_data_field_image_hero';
  $handler->display->display_options['fields']['field_image_hero']['field'] = 'field_image_hero';
  $handler->display->display_options['fields']['field_image_hero']['label'] = '';
  $handler->display->display_options['fields']['field_image_hero']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_hero']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_hero']['settings'] = array(
    'image_style' => '680x510',
    'image_link' => '',
  );
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_party']['settings'] = array(
    'textformatter_type' => 'comma',
    'textformatter_comma_and' => 0,
    'textformatter_comma_full_stop' => 0,
    'textformatter_comma_override' => 0,
    'textformatter_separator_custom' => '',
    'textformatter_separator_custom_tag' => 'span',
    'textformatter_separator_custom_class' => 'textformatter-separator',
    'textformatter_comma_tag' => 'div',
    'textformatter_class' => 'textformatter-list',
  );
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
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
  /* Field: Content: Inactive Senator Message */
  $handler->display->display_options['fields']['field_inactive_senator_message']['id'] = 'field_inactive_senator_message';
  $handler->display->display_options['fields']['field_inactive_senator_message']['table'] = 'field_data_field_inactive_senator_message';
  $handler->display->display_options['fields']['field_inactive_senator_message']['field'] = 'field_inactive_senator_message';
  $handler->display->display_options['fields']['field_inactive_senator_message']['label'] = '';
  $handler->display->display_options['fields']['field_inactive_senator_message']['element_label_colon'] = FALSE;
  /* Field: Content: Member Headshot */
  $handler->display->display_options['fields']['field_image_headshot']['id'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['table'] = 'field_data_field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['field'] = 'field_image_headshot';
  $handler->display->display_options['fields']['field_image_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_headshot']['settings'] = array(
    'image_style' => '160x160',
    'image_link' => '',
  );
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'senator' => 'senator',
  );
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

  /* Display: Senator Detail Hero Block */
  $handler = $view->new_display('block', 'Senator Detail Hero Block', 'block');
  $handler->display->display_options['block_description'] = 'Senator Detail Hero Block';
  $handler->display->display_options['block_caching'] = '-1';

  /* Display: Senator Trimmed Hero Block */
  $handler = $view->new_display('block', 'Senator Trimmed Hero Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Senator Trimmed Hero Block';
  $handler->display->display_options['block_caching'] = '-1';
  $export['nys_senator_hero'] = $view;

  $view = new view();
  $view->name = 'promo_banner_senators_committees';
  $view->description = 'This is for use on the senators and committees landing page';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Promotional Banners';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_call_to_action' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_call_to_action_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'sitewide_footer_promotional_bann' => 'sitewide_footer_promotional_bann',
    'homepage_hero' => 0,
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['id'] = 'field_promotional_content_target_id';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['table'] = 'field_data_field_promotional_content';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['field'] = 'field_promotional_content_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Call to Action */
  $handler->display->display_options['fields']['field_call_to_action']['id'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['table'] = 'field_data_field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['field'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['field_call_to_action']['element_label_colon'] = FALSE;
  /* Field: Content: Call to Action */
  $handler->display->display_options['fields']['field_call_to_action_1']['id'] = 'field_call_to_action_1';
  $handler->display->display_options['fields']['field_call_to_action_1']['table'] = 'field_data_field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action_1']['field'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action_1']['label'] = '';
  $handler->display->display_options['fields']['field_call_to_action_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_call_to_action_1']['type'] = 'list_key';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_promotional_content_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '280x280',
    'image_link' => '',
  );
  /* Field: Content: Link Type */
  $handler->display->display_options['fields']['field_link_type']['id'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['table'] = 'field_data_field_link_type';
  $handler->display->display_options['fields']['field_link_type']['field'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['label'] = '';
  $handler->display->display_options['fields']['field_link_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link_type']['type'] = 'list_key';
  /* Field: Content: External Web Page */
  $handler->display->display_options['fields']['field_external_web_page']['id'] = 'field_external_web_page';
  $handler->display->display_options['fields']['field_external_web_page']['table'] = 'field_data_field_external_web_page';
  $handler->display->display_options['fields']['field_external_web_page']['field'] = 'field_external_web_page';
  $handler->display->display_options['fields']['field_external_web_page']['label'] = '';
  $handler->display->display_options['fields']['field_external_web_page']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_external_web_page']['element_default_classes'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
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
    'promotional_banner' => 'promotional_banner',
  );

  /* Display: Senators and Committees Promo Blocks */
  $handler = $view->new_display('block', 'Senators and Committees Promo Blocks', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'sitewide_promo_banners';
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
    'field_call_to_action' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_call_to_action_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';

  /* Display: Senator Home Feature Promo 1 */
  $handler = $view->new_display('block', 'Senator Home Feature Promo 1', 'senator_home_promo_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'field_call_to_action' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_call_to_action_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['id'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['field'] = 'reverse_field_promotional_banners_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['id'] = 'field_promotional_content_target_id';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['table'] = 'field_data_field_promotional_content';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['field'] = 'field_promotional_content_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'promotional_banner' => 'promotional_banner',
  );

  /* Display: Senator Home Feature Promo 2 */
  $handler = $view->new_display('block', 'Senator Home Feature Promo 2', 'senator_home_promo_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['id'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['field'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['id'] = 'field_promotional_content_target_id';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['table'] = 'field_data_field_promotional_content';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['field'] = 'field_promotional_content_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'promotional_banner' => 'promotional_banner',
  );

  /* Display: Senator Home Feature Promo 3 */
  $handler = $view->new_display('block', 'Senator Home Feature Promo 3', 'senator_home_promo_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '2';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['id'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['field'] = 'reverse_field_promotional_banners_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['id'] = 'field_promotional_content_target_id';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['table'] = 'field_data_field_promotional_content';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['field'] = 'field_promotional_content_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'promotional_banner' => 'promotional_banner',
  );

  /* Display: Senator Microsite Footer Blocks */
  $handler = $view->new_display('block', 'Senator Microsite Footer Blocks', 'senator_microsite_interior_footer');
  $handler->display->display_options['display_description'] = 'These blocks are for the bottom of the senator\'s microsite interior pages.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'field_call_to_action' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_call_to_action_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['id'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['field'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['id'] = 'field_promotional_content_target_id';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['table'] = 'field_data_field_promotional_content';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['field'] = 'field_promotional_content_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'promotional_banner' => 'promotional_banner',
  );

  /* Display: Sitewide Footer Promotion Blocks */
  $handler = $view->new_display('block', 'Sitewide Footer Promotion Blocks', 'news_issues_promos');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'sitewide_promo_banners';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'field_call_to_action' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_call_to_action_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'sitewide_footer_promotional_bann' => 'sitewide_footer_promotional_bann',
    'homepage_hero' => 0,
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['id'] = 'field_promotional_content_target_id';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['table'] = 'field_data_field_promotional_content';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['field'] = 'field_promotional_content_target_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
    'promotional_banner' => 'promotional_banner',
  );
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';

  /* Display: Senator Home Feature Promo Footer */
  $handler = $view->new_display('block', 'Senator Home Feature Promo Footer', 'senator_home_promo_footer');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '3';
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
    'field_call_to_action' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_call_to_action_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'path' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['id'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['field'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['relationships']['reverse_field_promotional_banners_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['id'] = 'field_promotional_content_target_id';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['table'] = 'field_data_field_promotional_content';
  $handler->display->display_options['relationships']['field_promotional_content_target_id']['field'] = 'field_promotional_content_target_id';
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
  /* Field: Content: Call to Action */
  $handler->display->display_options['fields']['field_call_to_action']['id'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['table'] = 'field_data_field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['field'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['field_call_to_action']['element_label_colon'] = FALSE;
  /* Field: Content: Call to Action */
  $handler->display->display_options['fields']['field_call_to_action_1']['id'] = 'field_call_to_action_1';
  $handler->display->display_options['fields']['field_call_to_action_1']['table'] = 'field_data_field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action_1']['field'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action_1']['label'] = '';
  $handler->display->display_options['fields']['field_call_to_action_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_call_to_action_1']['type'] = 'list_key';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_promotional_content_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '280x280',
    'image_link' => '',
  );
  /* Field: Content: Link Type */
  $handler->display->display_options['fields']['field_link_type']['id'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['table'] = 'field_data_field_link_type';
  $handler->display->display_options['fields']['field_link_type']['field'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['label'] = '';
  $handler->display->display_options['fields']['field_link_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_type']['type'] = 'list_key';
  /* Field: Content: External Web Page */
  $handler->display->display_options['fields']['field_external_web_page']['id'] = 'field_external_web_page';
  $handler->display->display_options['fields']['field_external_web_page']['table'] = 'field_data_field_external_web_page';
  $handler->display->display_options['fields']['field_external_web_page']['field'] = 'field_external_web_page';
  $handler->display->display_options['fields']['field_external_web_page']['label'] = '';
  $handler->display->display_options['fields']['field_external_web_page']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_external_web_page']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_promotional_banners_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'promotional_banner' => 'promotional_banner',
  );
  $export['promo_banner_senators_committees'] = $view;

  $view = new view();
  $view->name = 'senator_about';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator About';
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
  $handler->display->display_options['style_options']['row']['element_type'] = 'article';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_account_target_id']['id'] = 'field_user_account_target_id';
  $handler->display->display_options['relationships']['field_user_account_target_id']['table'] = 'field_data_field_user_account';
  $handler->display->display_options['relationships']['field_user_account_target_id']['field'] = 'field_user_account_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['id'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_senator_taxonomy_term']['field'] = 'reverse_field_senator_taxonomy_term';
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '760x377',
    'image_link' => '',
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
  /* Field: Content: Titles */
  $handler->display->display_options['fields']['field_current_duties']['id'] = 'field_current_duties';
  $handler->display->display_options['fields']['field_current_duties']['table'] = 'field_data_field_current_duties';
  $handler->display->display_options['fields']['field_current_duties']['field'] = 'field_current_duties';
  $handler->display->display_options['fields']['field_current_duties']['label'] = '';
  $handler->display->display_options['fields']['field_current_duties']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_current_duties']['type'] = 'text_plain';
  /* Field: Content: Sub-field */
  $handler->display->display_options['fields']['field_pull_quote']['id'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['table'] = 'field_data_field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['field'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['label'] = '';
  $handler->display->display_options['fields']['field_pull_quote']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Field: Chapters */
  $handler->display->display_options['fields']['field_chapters']['id'] = 'field_chapters';
  $handler->display->display_options['fields']['field_chapters']['table'] = 'field_data_field_chapters';
  $handler->display->display_options['fields']['field_chapters']['field'] = 'field_chapters';
  $handler->display->display_options['fields']['field_chapters']['label'] = '';
  $handler->display->display_options['fields']['field_chapters']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chapters']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_chapters']['settings'] = array(
    'view_mode' => 'default',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_chapters']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_chapters']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Party Affiliation */
  $handler->display->display_options['fields']['field_party']['id'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['table'] = 'field_data_field_party';
  $handler->display->display_options['fields']['field_party']['field'] = 'field_party';
  $handler->display->display_options['fields']['field_party']['label'] = '';
  $handler->display->display_options['fields']['field_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party']['delta_offset'] = '0';
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'reverse_field_senator_taxonomy_term';
  $handler->display->display_options['fields']['field_district_number']['label'] = '';
  $handler->display->display_options['fields']['field_district_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_district_number']['alter']['text'] = 'District [field_district_number]';
  $handler->display->display_options['fields']['field_district_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
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
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'senator' => 'senator',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['senator_about'] = $view;

  $view = new view();
  $view->name = 'senator_bills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bill';
  $view->human_name = 'Senator Bills';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'pane 2';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'bill_id' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_bill_id' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_openleg_actions_value']['id'] = 'field_openleg_actions_value';
  $handler->display->display_options['relationships']['field_openleg_actions_value']['table'] = 'field_data_field_openleg_actions';
  $handler->display->display_options['relationships']['field_openleg_actions_value']['field'] = 'field_openleg_actions_value';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'bill/[bill_id]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['text'] = 'In [field_openleg_current_committee] Committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['empty'] = 'Unknown Committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['hide_empty'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_actions_status']['id'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['table'] = 'field_data_field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['field'] = 'field_openleg_actions_status';
  $handler->display->display_options['fields']['field_openleg_actions_status']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_actions_status']['element_label_colon'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['id'] = 'field_openleg_last_action_date_value';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['field'] = 'field_openleg_last_action_date_value';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['order'] = 'DESC';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bill' => 'bill',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['id'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['field'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['group'] = 2;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['id'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['table'] = 'field_data_field_openleg_multisponsors';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['field'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'bills_main');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No sponsored bills so far';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bill' => 'bill',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['id'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['field'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['group'] = 2;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['id'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['table'] = 'field_data_field_openleg_multisponsors';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['field'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['group'] = 2;

  /* Display: For Homepage */
  $handler = $view->new_display('block', 'For Homepage', 'bills_homepage');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bill' => 'bill',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['id'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['field'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['group'] = 2;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['id'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['table'] = 'field_data_field_openleg_multisponsors';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['field'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['group'] = 2;

  /* Display: Dashboard Home */
  $handler = $view->new_display('block', 'Dashboard Home', 'bills_dashboard_home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'bill_id' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_bill_id' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have no bills so far';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_openleg_actions_value']['id'] = 'field_openleg_actions_value';
  $handler->display->display_options['relationships']['field_openleg_actions_value']['table'] = 'field_data_field_openleg_actions';
  $handler->display->display_options['relationships']['field_openleg_actions_value']['field'] = 'field_openleg_actions_value';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'bill/[bill_id]';
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
  /* Field: nay_votes */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'nay_votes';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view']['arguments'] = '[!bill_id]/nay';
  /* Field: aye_votes */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'aye_votes';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!bill_id]/aye';
  /* Field: constituent_aye_votes */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'constituent_aye_votes';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_2']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!bill_id]/aye/!1';
  /* Field: constituent_nay_votes */
  $handler->display->display_options['fields']['view_3']['id'] = 'view_3';
  $handler->display->display_options['fields']['view_3']['table'] = 'views';
  $handler->display->display_options['fields']['view_3']['field'] = 'view';
  $handler->display->display_options['fields']['view_3']['ui_name'] = 'constituent_nay_votes';
  $handler->display->display_options['fields']['view_3']['label'] = '';
  $handler->display->display_options['fields']['view_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_3']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_3']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view_3']['arguments'] = '[!bill_id]/nay/!1';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bill' => 'bill',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['id'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['field'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['filters']['field_openleg_sponsor_target_id']['group'] = 2;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['id'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['table'] = 'field_data_field_openleg_multisponsors';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['field'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['group'] = 2;

  /* Display: Resolutions */
  $handler = $view->new_display('block', 'Resolutions', 'resolutions_main');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'bill_id' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_bill_id' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No sponsored resolutions so far';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'bill/[bill_id]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bill_id']['id'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['table'] = 'field_data_field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['field'] = 'field_bill_id';
  $handler->display->display_options['fields']['field_bill_id']['label'] = '';
  $handler->display->display_options['fields']['field_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['alter']['text'] = 'In [field_openleg_current_committee] Committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_current_committee']['empty'] = 'Unknown Committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['hide_empty'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openleg_last_action_date']['empty'] = 'Unknown date';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['sorts']['bill_id']['table'] = 'bill';
  $handler->display->display_options['sorts']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['sorts']['bill_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_openleg_sponsor_target_id']['id'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['arguments']['field_openleg_sponsor_target_id']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['arguments']['field_openleg_sponsor_target_id']['field'] = 'field_openleg_sponsor_target_id';
  $handler->display->display_options['arguments']['field_openleg_sponsor_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_openleg_sponsor_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_openleg_sponsor_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_openleg_sponsor_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resolution' => 'resolution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['senator_bills'] = $view;

  $view = new view();
  $view->name = 'senator_contact_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator Contact Blocks';
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
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Offices */
  $handler->display->display_options['fields']['field_offices']['id'] = 'field_offices';
  $handler->display->display_options['fields']['field_offices']['table'] = 'field_data_field_offices';
  $handler->display->display_options['fields']['field_offices']['field'] = 'field_offices';
  $handler->display->display_options['fields']['field_offices']['label'] = '';
  $handler->display->display_options['fields']['field_offices']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_offices']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_offices']['separator'] = '';
  /* Field: Content: Senator Contact Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email Address';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_email']['alter']['text'] = '<a href="mailto:[field_email]">[field_email]</a>';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
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
    'senator' => 'senator',
  );

  /* Display: Senator Office Information */
  $handler = $view->new_display('block', 'Senator Office Information', 'senator_office_info_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2 class="nys-title">Contact Senator [title]\'s Office</h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Offices */
  $handler->display->display_options['fields']['field_offices']['id'] = 'field_offices';
  $handler->display->display_options['fields']['field_offices']['table'] = 'field_data_field_offices';
  $handler->display->display_options['fields']['field_offices']['field'] = 'field_offices';
  $handler->display->display_options['fields']['field_offices']['label'] = '';
  $handler->display->display_options['fields']['field_offices']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_offices']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_offices']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_offices']['separator'] = '';
  /* Field: Content: Senator Contact Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = 'Email Address';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_email']['alter']['text'] = '<a href="mailto:[field_email]">[field_email]</a>';
  /* Field: Content: Office Contacts */
  $handler->display->display_options['fields']['field_office_contacts']['id'] = 'field_office_contacts';
  $handler->display->display_options['fields']['field_office_contacts']['table'] = 'field_data_field_office_contacts';
  $handler->display->display_options['fields']['field_office_contacts']['field'] = 'field_office_contacts';
  $handler->display->display_options['fields']['field_office_contacts']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_office_contacts']['delta_offset'] = '0';

  /* Display: Senator Media Inquiries Information */
  $handler = $view->new_display('block', 'Senator Media Inquiries Information', 'senator_media_inquiries_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media Inquiries */
  $handler->display->display_options['fields']['field_media_inquiries']['id'] = 'field_media_inquiries';
  $handler->display->display_options['fields']['field_media_inquiries']['table'] = 'field_data_field_media_inquiries';
  $handler->display->display_options['fields']['field_media_inquiries']['field'] = 'field_media_inquiries';
  $handler->display->display_options['fields']['field_media_inquiries']['label'] = '';
  $handler->display->display_options['fields']['field_media_inquiries']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_inquiries']['hide_empty'] = TRUE;
  /* Field: Location: contact_name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'location_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = '';
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = FALSE;
  /* Field: Location: Email address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'location_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = '';
  $handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
  /* Field: Location: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'location_phone';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = '';
  $handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
  /* Field: Location: Fax */
  $handler->display->display_options['fields']['fax']['id'] = 'fax';
  $handler->display->display_options['fields']['fax']['table'] = 'location_fax';
  $handler->display->display_options['fields']['fax']['field'] = 'fax';
  $handler->display->display_options['fields']['fax']['label'] = '';
  $handler->display->display_options['fields']['fax']['element_label_colon'] = FALSE;
  /* Field: Location: Street */
  $handler->display->display_options['fields']['street']['id'] = 'street';
  $handler->display->display_options['fields']['street']['table'] = 'location';
  $handler->display->display_options['fields']['street']['field'] = 'street';
  $handler->display->display_options['fields']['street']['label'] = '';
  $handler->display->display_options['fields']['street']['element_label_colon'] = FALSE;
  /* Field: Location: Additional */
  $handler->display->display_options['fields']['additional']['id'] = 'additional';
  $handler->display->display_options['fields']['additional']['table'] = 'location';
  $handler->display->display_options['fields']['additional']['field'] = 'additional';
  $handler->display->display_options['fields']['additional']['label'] = '';
  $handler->display->display_options['fields']['additional']['element_label_colon'] = FALSE;
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['label'] = '';
  $handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['element_label_colon'] = FALSE;
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['label'] = '';
  $handler->display->display_options['fields']['postal_code']['element_label_colon'] = FALSE;
  /* Field: Location: Country */
  $handler->display->display_options['fields']['country']['id'] = 'country';
  $handler->display->display_options['fields']['country']['table'] = 'location';
  $handler->display->display_options['fields']['country']['field'] = 'country';
  $handler->display->display_options['fields']['country']['label'] = '';
  $handler->display->display_options['fields']['country']['element_label_colon'] = FALSE;

  /* Display: Senator Press Kit */
  $handler = $view->new_display('block', 'Senator Press Kit', 'senator_press_kit_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Press Kit */
  $handler->display->display_options['fields']['field_press_kit']['id'] = 'field_press_kit';
  $handler->display->display_options['fields']['field_press_kit']['table'] = 'field_data_field_press_kit';
  $handler->display->display_options['fields']['field_press_kit']['field'] = 'field_press_kit';
  $handler->display->display_options['fields']['field_press_kit']['label'] = '';
  $handler->display->display_options['fields']['field_press_kit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_press_kit']['alter']['text'] = '<a class="c-block--btn" href="[field_press_kit]">Download Press Kit</a>';
  $handler->display->display_options['fields']['field_press_kit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_kit']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_press_kit']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_kit']['type'] = 'file_url_plain';
  $export['senator_contact_blocks'] = $view;

  $view = new view();
  $view->name = 'senator_homepage_recent_legislation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bill';
  $view->human_name = 'Senator Homepage Recent Legislation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_bill_id']['id'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_bill_id']['field'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['label'] = '';
  $handler->display->display_options['fields']['openleg_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_issues']['id'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['table'] = 'field_data_field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['field'] = 'field_openleg_issues';
  $handler->display->display_options['fields']['field_openleg_issues']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_issues']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_bill';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_current_committee']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_status_1']['id'] = 'field_openleg_status_1';
  $handler->display->display_options['fields']['field_openleg_status_1']['table'] = 'field_data_field_openleg_status';
  $handler->display->display_options['fields']['field_openleg_status_1']['field'] = 'field_openleg_status';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['id'] = 'field_openleg_last_action_date_value';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['field'] = 'field_openleg_last_action_date_value';
  $handler->display->display_options['sorts']['field_openleg_last_action_date_value']['order'] = 'DESC';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['senator_homepage_recent_legislation'] = $view;

  $view = new view();
  $view->name = 'senator_legislation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator Legislation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Senator Legislation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'entity';
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
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['advpoll_closed_value']['id'] = 'advpoll_closed_value';
  $handler->display->display_options['filters']['advpoll_closed_value']['table'] = 'field_data_advpoll_closed';
  $handler->display->display_options['filters']['advpoll_closed_value']['field'] = 'advpoll_closed_value';
  $handler->display->display_options['filters']['advpoll_closed_value']['value'] = array(
    'open' => 'open',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'senator_featuired_legislation');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Legislation';
  $export['senator_legislation'] = $view;

  $view = new view();
  $view->name = 'senator_petition';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator Petition';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '280x280',
    'image_link' => 'content',
  );
  /* Field: Content: Is Featured */
  $handler->display->display_options['fields']['field_featured']['id'] = 'field_featured';
  $handler->display->display_options['fields']['field_featured']['table'] = 'field_data_field_featured';
  $handler->display->display_options['fields']['field_featured']['field'] = 'field_featured';
  $handler->display->display_options['fields']['field_featured']['label'] = '';
  $handler->display->display_options['fields']['field_featured']['element_label_colon'] = FALSE;
  /* Field: Content: Call to Action */
  $handler->display->display_options['fields']['field_call_to_action']['id'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['table'] = 'field_data_field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['field'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['field_call_to_action']['element_label_colon'] = FALSE;
  /* Field: Content: Call to Action */
  $handler->display->display_options['fields']['field_call_to_action_1']['id'] = 'field_call_to_action_1';
  $handler->display->display_options['fields']['field_call_to_action_1']['table'] = 'field_data_field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action_1']['field'] = 'field_call_to_action';
  $handler->display->display_options['fields']['field_call_to_action_1']['label'] = '';
  $handler->display->display_options['fields']['field_call_to_action_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_call_to_action_1']['type'] = 'list_key';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Is Featured (field_featured) */
  $handler->display->display_options['filters']['field_featured_value']['id'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['table'] = 'field_data_field_featured';
  $handler->display->display_options['filters']['field_featured_value']['field'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'petition' => 'petition',
    'questionnaire' => 'questionnaire',
  );

  /* Display: Home Top */
  $handler = $view->new_display('block', 'Home Top', 'block');

  /* Display: Home Middle */
  $handler = $view->new_display('block', 'Home Middle', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '1';

  /* Display: Home Bottom */
  $handler = $view->new_display('block', 'Home Bottom', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '2';
  $export['senator_petition'] = $view;

  return $export;
}
