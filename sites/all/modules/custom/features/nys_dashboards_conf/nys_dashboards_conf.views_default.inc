<?php
/**
 * @file
 * nys_dashboards_conf.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_dashboards_conf_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'active_session_bills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Active Session Bills';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Active Session Bills';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'legislation_current_session' => 'legislation_current_session',
    'homepage_hero' => 0,
    'sitewide_footer_promotional_bann' => 0,
    'homepage_featured_story' => 0,
  );
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
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'count',
  );
  /* Field: Content: Calendar */
  $handler->display->display_options['fields']['field_ol_cal']['id'] = 'field_ol_cal';
  $handler->display->display_options['fields']['field_ol_cal']['table'] = 'field_data_field_ol_cal';
  $handler->display->display_options['fields']['field_ol_cal']['field'] = 'field_ol_cal';
  $handler->display->display_options['fields']['field_ol_cal']['relationship'] = 'field_session_calendars_target_id';
  $handler->display->display_options['fields']['field_ol_cal']['label'] = '';
  $handler->display->display_options['fields']['field_ol_cal']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_cal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_cal']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_ol_cal']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_ol_cal']['delta_offset'] = '0';
  /* Field: Field collection item: Bill */
  $handler->display->display_options['fields']['field_ol_bill']['id'] = 'field_ol_bill';
  $handler->display->display_options['fields']['field_ol_bill']['table'] = 'field_data_field_ol_bill';
  $handler->display->display_options['fields']['field_ol_bill']['field'] = 'field_ol_bill';
  $handler->display->display_options['fields']['field_ol_bill']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['fields']['field_ol_bill']['label'] = '';
  $handler->display->display_options['fields']['field_ol_bill']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ol_bill']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_bill']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_bill']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_ol_bill']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['relationship'] = 'field_ol_bill_target_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 0,
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
    'session' => 'session',
  );
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'active_list' => 'active_list',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['active_session_bills'] = $view;

  $view = new view();
  $view->name = 'bill_search_autocomplete';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bill';
  $view->human_name = 'Bill Search Autocomplete';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bill Search Autocomplete';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_bill_id']['id'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_bill_id']['field'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['label'] = '';
  $handler->display->display_options['fields']['openleg_bill_id']['element_label_colon'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['openleg_bill_id']['id'] = 'openleg_bill_id';
  $handler->display->display_options['sorts']['openleg_bill_id']['table'] = 'bill';
  $handler->display->display_options['sorts']['openleg_bill_id']['field'] = 'openleg_bill_id';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['bill_search_autocomplete'] = $view;

  $view = new view();
  $view->name = 'bills_voting_subview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bill';
  $view->human_name = 'Bills Voting Subview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['bill_id']['element_default_classes'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['arguments']['bill_id']['table'] = 'bill';
  $handler->display->display_options['arguments']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['arguments']['bill_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['bill_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bill_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bill_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = 'aye';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bill' => 'bill',
  );

  /* Display: All Votes */
  $handler = $view->new_display('block', 'All Votes', 'all_votes');
  $handler->display->display_options['display_description'] = 'Shows how much users voted a given option on a given Bill';

  /* Display: Constituent Voting */
  $handler = $view->new_display('block', 'Constituent Voting', 'constituent_votes');
  $handler->display->display_options['display_description'] = 'Shows how much constituent user of a given senator voted a given option on a given Bill';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['arguments']['bill_id']['table'] = 'bill';
  $handler->display->display_options['arguments']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['arguments']['bill_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['bill_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bill_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bill_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: vote_type */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'vote_type';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = 'aye';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: senator */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'senator';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $export['bills_voting_subview'] = $view;

  $view = new view();
  $view->name = 'constituent_bills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Constituent Bills';
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
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.view-content';
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
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = TRUE;
  /* Relationship: Flags: follow_this_bill */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'follow_this_bill';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['separator'] = '';
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['type'] = 'ds_taxonomy_separator';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content:  Constituent Vote */
  $handler->display->display_options['fields']['field__constituent_vote']['id'] = 'field__constituent_vote';
  $handler->display->display_options['fields']['field__constituent_vote']['table'] = 'field_data_field__constituent_vote';
  $handler->display->display_options['fields']['field__constituent_vote']['field'] = 'field__constituent_vote';
  $handler->display->display_options['fields']['field__constituent_vote']['label'] = '';
  $handler->display->display_options['fields']['field__constituent_vote']['element_label_colon'] = FALSE;
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
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'hyphen';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'month_only';
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
  /* Contextual filter: Flags: User uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'flagging';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Flags: User uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'flagging';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User uid';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';

  /* Display: Constituent Bills Voted On */
  $handler = $view->new_display('block', 'Constituent Bills Voted On', 'constituent_bills_voted_on');
  $export['constituent_bills'] = $view;

  $view = new view();
  $view->name = 'constituent_bills_following';
  $view->description = '';
  $view->tag = 'dashboard, bills';
  $view->base_table = 'bill';
  $view->human_name = 'Constituent Bill Following';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
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
    'type_2' => array(
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
    'openleg_bill_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
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
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.bill-widget-wrapper';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'bill';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_bill_node']['id'] = 'reverse_field_bill_node';
  $handler->display->display_options['relationships']['reverse_field_bill_node']['table'] = 'bill';
  $handler->display->display_options['relationships']['reverse_field_bill_node']['field'] = 'reverse_field_bill_node';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_openleg_status']['id'] = 'field_openleg_status';
  $handler->display->display_options['fields']['field_openleg_status']['table'] = 'field_data_field_openleg_status';
  $handler->display->display_options['fields']['field_openleg_status']['field'] = 'field_openleg_status';
  $handler->display->display_options['fields']['field_openleg_status']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_status']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor']['id'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_multisponsors']['id'] = 'field_openleg_multisponsors';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['table'] = 'field_data_field_openleg_multisponsors';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['field'] = 'field_openleg_multisponsors';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_act_clause']['id'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_act_clause']['field'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['label'] = '';
  $handler->display->display_options['fields']['openleg_act_clause']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee_1']['id'] = 'field_openleg_current_committee_1';
  $handler->display->display_options['fields']['field_openleg_current_committee_1']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee_1']['field'] = 'field_openleg_current_committee';
  /* Field: : field_bill_user_vote */
  $handler->display->display_options['fields']['field_bill_user_vote']['id'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['table'] = 'field_data_field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['field'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['label'] = '';
  $handler->display->display_options['fields']['field_bill_user_vote']['element_label_colon'] = FALSE;
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_bill';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_bill_node';
  /* Contextual filter: Votes: User */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'all' => 'all',
    'bill' => 'bill',
    'resolution' => 'resolution',
  );

  /* Display: Constituent Bill Following */
  $handler = $view->new_display('block', 'Constituent Bill Following', 'constituent_bills_following');
  $handler->display->display_options['display_description'] = 'dashboard, bills';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'bill';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_openleg_status']['id'] = 'field_openleg_status';
  $handler->display->display_options['fields']['field_openleg_status']['table'] = 'field_data_field_openleg_status';
  $handler->display->display_options['fields']['field_openleg_status']['field'] = 'field_openleg_status';
  $handler->display->display_options['fields']['field_openleg_status']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_status']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_last_action_date']['id'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['table'] = 'field_data_field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['field'] = 'field_openleg_last_action_date';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_last_action_date']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor']['id'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_multisponsors']['id'] = 'field_openleg_multisponsors';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['table'] = 'field_data_field_openleg_multisponsors';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['field'] = 'field_openleg_multisponsors';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_multisponsors']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_act_clause']['id'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_act_clause']['field'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['label'] = '';
  $handler->display->display_options['fields']['openleg_act_clause']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee']['id'] = 'field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee']['field'] = 'field_openleg_current_committee';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_current_committee_1']['id'] = 'field_openleg_current_committee_1';
  $handler->display->display_options['fields']['field_openleg_current_committee_1']['table'] = 'field_data_field_openleg_current_committee';
  $handler->display->display_options['fields']['field_openleg_current_committee_1']['field'] = 'field_openleg_current_committee';
  /* Field: : field_bill_user_vote */
  $handler->display->display_options['fields']['field_bill_user_vote']['id'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['table'] = 'field_data_field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['field'] = 'field_bill_user_vote';
  $handler->display->display_options['fields']['field_bill_user_vote']['label'] = '';
  $handler->display->display_options['fields']['field_bill_user_vote']['element_label_colon'] = FALSE;
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_bill';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Constituent Bill News Updates */
  $handler = $view->new_display('block', 'Constituent Bill News Updates', 'constituents_bill_news_updates');
  $handler->display->display_options['display_description'] = 'dashboard, bills';
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
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type_1']['machine_name'] = TRUE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bill';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'all' => 'all',
    'bill' => 'bill',
    'resolution' => 'resolution',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['filters']['title']['operator'] = 'not empty';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'article' => 'article',
    'in_the_news' => 'in_the_news',
    'initiative' => 'initiative',
    'meeting' => 'meeting',
    'petition' => 'petition',
    'press_release' => 'press_release',
    'questionnaire' => 'questionnaire',
    'session' => 'session',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'node';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['relationship'] = 'reverse_field_bill_node';
  $handler->display->display_options['filters']['type_2']['value'] = array(
    'article' => 'article',
    'event' => 'event',
    'in_the_news' => 'in_the_news',
    'initiative' => 'initiative',
    'meeting' => 'meeting',
    'petition' => 'petition',
    'press_release' => 'press_release',
    'questionnaire' => 'questionnaire',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_2']['expose']['operator_id'] = 'type_2_op';
  $handler->display->display_options['filters']['type_2']['expose']['label'] = 'Filter by Type';
  $handler->display->display_options['filters']['type_2']['expose']['operator'] = 'type_2_op';
  $handler->display->display_options['filters']['type_2']['expose']['identifier'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['type_2']['expose']['reduce'] = TRUE;
  $export['constituent_bills_following'] = $view;

  $view = new view();
  $view->name = 'constituent_committees_following';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Constituent Committees Following';
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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'SEE MORE';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = 'section';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No updates to show.</p>

<p>To find Committees and Senate groups you might be interested in following, browse our <a href="/senators-committees">Senators & Committees</a> page.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Flags: follow_issue */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'follow_issue';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Contextual filter: Flags: User uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'flagging';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committees' => 'committees',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['constituent_committees_following'] = $view;

  $view = new view();
  $view->name = 'constituent_petitions_and_questionairres';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Constituent Petitions and Questionairres';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Questionnaires You\'ve Filled out';
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
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
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
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'timestamp' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Petitions to show.
Please sign petitions on <a href="/">NYSenate.gov</a> to view updates.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Flags: sign_petition */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'sign_petition';
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
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['alter']['text'] = 'By: [field_senator]';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = 'Signed on [timestamp]';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'medium';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'month_only';
  /* Sort criterion: Webform submissions: Submitted */
  $handler->display->display_options['sorts']['submitted']['id'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['submitted']['field'] = 'submitted';
  $handler->display->display_options['sorts']['submitted']['relationship'] = 'webform_submission';
  $handler->display->display_options['sorts']['submitted']['order'] = 'DESC';
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
    'questionnaire' => 'questionnaire',
  );

  /* Display: constituent petitions signed */
  $handler = $view->new_display('block', 'constituent petitions signed', 'constituent_petitions_signed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Petitions You\'ve Signed';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: sign_petition */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'sign_petition';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
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

  /* Display: constituent questionnaires submitted */
  $handler = $view->new_display('block', 'constituent questionnaires submitted', 'constituent_questionnaires_submitted');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Questionnaires You\'ve Filled out';
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
    'field_senator' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No Questionnaires to show.
Please answer questionnaires on <a href="/">NYSenate.gov</a> to view updates.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_webform_target_id']['id'] = 'field_webform_target_id';
  $handler->display->display_options['relationships']['field_webform_target_id']['table'] = 'field_data_field_webform';
  $handler->display->display_options['relationships']['field_webform_target_id']['field'] = 'field_webform_target_id';
  $handler->display->display_options['relationships']['field_webform_target_id']['required'] = TRUE;
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
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['alter']['text'] = 'By: [field_senator]';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Webform */
  $handler->display->display_options['fields']['field_webform']['id'] = 'field_webform';
  $handler->display->display_options['fields']['field_webform']['table'] = 'field_data_field_webform';
  $handler->display->display_options['fields']['field_webform']['field'] = 'field_webform';
  $handler->display->display_options['fields']['field_webform']['label'] = '';
  $handler->display->display_options['fields']['field_webform']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webform']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_webform']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'questionnaire' => 'questionnaire',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $export['constituent_petitions_and_questionairres'] = $view;

  $view = new view();
  $view->name = 'constituent_updates';
  $view->description = 'View to store Issue Committee Updates on Constituent Dashboard';
  $view->tag = 'dashboard, constituent';
  $view->base_table = 'node';
  $view->human_name = 'Constituent Content Updates';
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
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'type' => array(
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
    'field_issues_tid' => array(
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
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '4';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.comm-widget-wrapper';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_publication_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_article_author' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_issue_target_id']['id'] = 'field_top_issue_target_id';
  $handler->display->display_options['relationships']['field_top_issue_target_id']['table'] = 'field_data_field_top_issue';
  $handler->display->display_options['relationships']['field_top_issue_target_id']['field'] = 'field_top_issue_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
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
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_article_author']['id'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['table'] = 'field_data_field_article_author';
  $handler->display->display_options['fields']['field_article_author']['field'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['label'] = '';
  $handler->display->display_options['fields']['field_article_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_author']['type'] = 'text_plain';
  /* Field: Content: Committees */
  $handler->display->display_options['fields']['field_committee']['id'] = 'field_committee';
  $handler->display->display_options['fields']['field_committee']['table'] = 'field_data_field_committee';
  $handler->display->display_options['fields']['field_committee']['field'] = 'field_committee';
  $handler->display->display_options['fields']['field_committee']['label'] = '';
  $handler->display->display_options['fields']['field_committee']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_committee']['element_label_colon'] = FALSE;
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Meeting Location */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  /* Field: Content: Meeting Place */
  $handler->display->display_options['fields']['field_event_place']['id'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['table'] = 'field_data_field_event_place';
  $handler->display->display_options['fields']['field_event_place']['field'] = 'field_event_place';
  $handler->display->display_options['fields']['field_event_place']['label'] = '';
  $handler->display->display_options['fields']['field_event_place']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'privatemsg_current_day',
    'fromto' => 'value',
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
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  /* Contextual filter: Field: Top Issue (field_top_issue) */
  $handler->display->display_options['arguments']['field_top_issue_target_id']['id'] = 'field_top_issue_target_id';
  $handler->display->display_options['arguments']['field_top_issue_target_id']['table'] = 'field_data_field_top_issue';
  $handler->display->display_options['arguments']['field_top_issue_target_id']['field'] = 'field_top_issue_target_id';
  $handler->display->display_options['arguments']['field_top_issue_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_top_issue_target_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_top_issue_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_top_issue_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_top_issue_target_id']['summary_options']['items_per_page'] = '25';
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
    'event' => 'event',
    'in_the_news' => 'in_the_news',
    'meeting' => 'meeting',
    'press_release' => 'press_release',
    'session' => 'session',
    'bill_status_message' => 'bill_status_message',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field: Issues (field_issues) */
  $handler->display->display_options['filters']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['filters']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['filters']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['filters']['field_issues_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_issues_tid']['expose']['operator_id'] = 'field_issues_tid_op';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['label'] = 'Issues';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['operator'] = 'field_issues_tid_op';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['identifier'] = 'field_issues_tid';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_issues_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_issues_tid']['vocabulary'] = 'issues';

  /* Display: Constituent All Issue Updates */
  $handler = $view->new_display('block', 'Constituent All Issue Updates', 'constituent_all_issue_updates');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '4';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.top-issue-updates';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
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
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_publication_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_article_author' => array(
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
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="c-container--title">Updates on Issues You\'re Following</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Updates.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Issues (field_issues) */
  $handler->display->display_options['relationships']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['relationships']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['relationships']['field_issues_tid']['field'] = 'field_issues_tid';
  /* Relationship: Flags: follow_issue */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_issues_tid';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'follow_issue';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
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
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_article_author']['id'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['table'] = 'field_data_field_article_author';
  $handler->display->display_options['fields']['field_article_author']['field'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['label'] = '';
  $handler->display->display_options['fields']['field_article_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_author']['type'] = 'text_plain';
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Meeting Location */
  $handler->display->display_options['fields']['field_meeting_location']['id'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['table'] = 'field_data_field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['field'] = 'field_meeting_location';
  $handler->display->display_options['fields']['field_meeting_location']['label'] = '';
  $handler->display->display_options['fields']['field_meeting_location']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'privatemsg_current_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Committees */
  $handler->display->display_options['fields']['field_committee']['id'] = 'field_committee';
  $handler->display->display_options['fields']['field_committee']['table'] = 'field_data_field_committee';
  $handler->display->display_options['fields']['field_committee']['field'] = 'field_committee';
  $handler->display->display_options['fields']['field_committee']['label'] = '';
  $handler->display->display_options['fields']['field_committee']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_ol_name']['id'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['table'] = 'field_data_field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['field'] = 'field_ol_name';
  $handler->display->display_options['fields']['field_ol_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_name']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor */
  $handler->display->display_options['fields']['field_ol_sponsor']['id'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['table'] = 'field_data_field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['field'] = 'field_ol_sponsor';
  $handler->display->display_options['fields']['field_ol_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: All Statuses */
  $handler->display->display_options['fields']['field_ol_all_statuses']['id'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['table'] = 'field_data_field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['field'] = 'field_ol_all_statuses';
  $handler->display->display_options['fields']['field_ol_all_statuses']['label'] = '';
  $handler->display->display_options['fields']['field_ol_all_statuses']['element_label_colon'] = FALSE;
  /* Field: Content: Publish Date */
  $handler->display->display_options['fields']['field_ol_publish_date']['id'] = 'field_ol_publish_date';
  $handler->display->display_options['fields']['field_ol_publish_date']['table'] = 'field_data_field_ol_publish_date';
  $handler->display->display_options['fields']['field_ol_publish_date']['field'] = 'field_ol_publish_date';
  $handler->display->display_options['fields']['field_ol_publish_date']['label'] = '';
  $handler->display->display_options['fields']['field_ol_publish_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_publish_date']['settings'] = array(
    'format_type' => 'medium',
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
  /* Field: Content: Last Status */
  $handler->display->display_options['fields']['field_ol_last_status']['id'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['table'] = 'field_data_field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['field'] = 'field_ol_last_status';
  $handler->display->display_options['fields']['field_ol_last_status']['label'] = '';
  $handler->display->display_options['fields']['field_ol_last_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_last_status']['type'] = 'list_key';
  /* Field: Content: Chamber */
  $handler->display->display_options['fields']['field_ol_chamber']['id'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['table'] = 'field_data_field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['field'] = 'field_ol_chamber';
  $handler->display->display_options['fields']['field_ol_chamber']['label'] = '';
  $handler->display->display_options['fields']['field_ol_chamber']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_chamber']['type'] = 'list_key';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
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
    'article' => 'article',
    'bill' => 'bill',
    'in_the_news' => 'in_the_news',
    'meeting' => 'meeting',
    'public_hearing' => 'public_hearing',
    'resolution' => 'resolution',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'article' => 'article',
    'bill' => 'bill',
    'in_the_news' => 'in_the_news',
    'meeting' => 'meeting',
    'public_hearing' => 'public_hearing',
    'resolution' => 'resolution',
  );
  /* Filter criterion: Flags: User uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'flagging';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['uid']['value'] = '';

  /* Display: Constituent Top Issue Updates */
  $handler = $view->new_display('block', 'Constituent Top Issue Updates', 'constituent_top_issue_updates');
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
    'event' => 'event',
    'in_the_news' => 'in_the_news',
    'meeting' => 'meeting',
    'press_release' => 'press_release',
    'session' => 'session',
    'bill_status_message' => 'bill_status_message',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
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

  /* Display: Constituent All Committee Updates */
  $handler = $view->new_display('block', 'Constituent All Committee Updates', 'constituent_all_committees_updates');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '4';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.top-issue-updates';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Committees (field_committee) */
  $handler->display->display_options['relationships']['field_committee_tid']['id'] = 'field_committee_tid';
  $handler->display->display_options['relationships']['field_committee_tid']['table'] = 'field_data_field_committee';
  $handler->display->display_options['relationships']['field_committee_tid']['field'] = 'field_committee_tid';
  /* Relationship: Flags: follow_committee */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_committee_tid';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'follow_committee';
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
    'article' => 'article',
    'bill' => 'bill',
    'in_the_news' => 'in_the_news',
    'meeting' => 'meeting',
    'press_release' => 'press_release',
    'public_hearing' => 'public_hearing',
    'resolution' => 'resolution',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
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
  /* Filter criterion: Content: Committees (field_committee) */
  $handler->display->display_options['filters']['field_committee_tid']['id'] = 'field_committee_tid';
  $handler->display->display_options['filters']['field_committee_tid']['table'] = 'field_data_field_committee';
  $handler->display->display_options['filters']['field_committee_tid']['field'] = 'field_committee_tid';
  $handler->display->display_options['filters']['field_committee_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_committee_tid']['expose']['operator_id'] = 'field_committee_tid_op';
  $handler->display->display_options['filters']['field_committee_tid']['expose']['label'] = 'Committee';
  $handler->display->display_options['filters']['field_committee_tid']['expose']['operator'] = 'field_committee_tid_op';
  $handler->display->display_options['filters']['field_committee_tid']['expose']['identifier'] = 'field_committee_tid';
  $handler->display->display_options['filters']['field_committee_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_committee_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_committee_tid']['vocabulary'] = 'committees';

  /* Display: Constituent All Bill Updates */
  $handler = $view->new_display('block', 'Constituent All Bill Updates', 'constituent_all_bill_updates');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '4';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.top-issue-updates';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
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
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type_1' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_publication_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_senator' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_article_author' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No Updates to show.
You must follow Bills on <a href="/">NYSenate.gov</a> for bill updates.  Either you are not 
following any bills, or there are no updates related to the bills you are following.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_bills_target_id']['id'] = 'field_bills_target_id';
  $handler->display->display_options['relationships']['field_bills_target_id']['table'] = 'field_data_field_bills';
  $handler->display->display_options['relationships']['field_bills_target_id']['field'] = 'field_bills_target_id';
  /* Relationship: Flags: follow_this_bill */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_bills_target_id';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'follow_this_bill';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
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
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_article_author']['id'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['table'] = 'field_data_field_article_author';
  $handler->display->display_options['fields']['field_article_author']['field'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['label'] = '';
  $handler->display->display_options['fields']['field_article_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_author']['type'] = 'text_plain';
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
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
    'article' => 'article',
    'event' => 'event',
    'in_the_news' => 'in_the_news',
    'meeting' => 'meeting',
    'press_release' => 'press_release',
    'session' => 'session',
    'bill_status_message' => 'bill_status_message',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Flags: User uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'flagging';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $export['constituent_updates'] = $view;

  $view = new view();
  $view->name = 'dashboard_senator_petitions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'dashboard_senator_petitions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'dashboard_senator_petitions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Webform submissions: Serial number */
  $handler->display->display_options['fields']['serial']['id'] = 'serial';
  $handler->display->display_options['fields']['serial']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['serial']['field'] = 'serial';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['dashboard_senator_petitions'] = $view;

  $view = new view();
  $view->name = 'senator_dashboard_bills';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bill';
  $view->human_name = 'Senator Dashboard Bills';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Senator Dashboard Bills';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Load More';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.view-content table tbody';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['element_type'] = '0';
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_bill_id']['id'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_bill_id']['field'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['label'] = '';
  $handler->display->display_options['fields']['openleg_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_law_section']['id'] = 'openleg_law_section';
  $handler->display->display_options['fields']['openleg_law_section']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_law_section']['field'] = 'openleg_law_section';
  $handler->display->display_options['fields']['openleg_law_section']['label'] = '';
  $handler->display->display_options['fields']['openleg_law_section']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_act_clause']['id'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_act_clause']['field'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['label'] = '';
  $handler->display->display_options['fields']['openleg_act_clause']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor']['id'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['id'] = 'field_openleg_sponsor_1';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['ui_name'] = 'Bill: Sponsor Name';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['element_label_colon'] = FALSE;
  /* Field: View: Constituent Aye Votes */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'View: Constituent Aye Votes';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_type'] = '0';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view']['arguments'] = '[!bill_id]/aye/!1';
  /* Field: View: Constituent Nay Votes */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'View: Constituent Nay Votes';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_type'] = '0';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_1']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!bill_id]/nay/!1';
  /* Field: View: All Aye Votes */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'View: All Aye Votes';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_type'] = '0';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_2']['display'] = 'all_votes';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!bill_id]/aye';
  /* Field: View: All Nay Votes */
  $handler->display->display_options['fields']['view_3']['id'] = 'view_3';
  $handler->display->display_options['fields']['view_3']['table'] = 'views';
  $handler->display->display_options['fields']['view_3']['field'] = 'view';
  $handler->display->display_options['fields']['view_3']['ui_name'] = 'View: All Nay Votes';
  $handler->display->display_options['fields']['view_3']['label'] = '';
  $handler->display->display_options['fields']['view_3']['element_type'] = '0';
  $handler->display->display_options['fields']['view_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_3']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_3']['display'] = 'all_votes';
  $handler->display->display_options['fields']['view_3']['arguments'] = '[!bill_id]/nay';
  /* Contextual filter: Null: Bill ID */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Null: Bill ID';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Null: Vote Type */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'Null: Vote Type';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Null: Senator ID */
  $handler->display->display_options['arguments']['null_2']['id'] = 'null_2';
  $handler->display->display_options['arguments']['null_2']['table'] = 'views';
  $handler->display->display_options['arguments']['null_2']['field'] = 'null';
  $handler->display->display_options['arguments']['null_2']['ui_name'] = 'Null: Senator ID';
  $handler->display->display_options['arguments']['null_2']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_2']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_2']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_2']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['field_openleg_co_sponsors_target_id']['id'] = 'field_openleg_co_sponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_co_sponsors_target_id']['table'] = 'field_data_field_openleg_co_sponsors';
  $handler->display->display_options['filters']['field_openleg_co_sponsors_target_id']['field'] = 'field_openleg_co_sponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_co_sponsors_target_id']['group'] = 2;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_other_sponsors_target_id']['id'] = 'field_openleg_other_sponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_other_sponsors_target_id']['table'] = 'field_data_field_openleg_other_sponsors';
  $handler->display->display_options['filters']['field_openleg_other_sponsors_target_id']['field'] = 'field_openleg_other_sponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_other_sponsors_target_id']['group'] = 2;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['id'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['table'] = 'field_data_field_openleg_multisponsors';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['field'] = 'field_openleg_multisponsors_target_id';
  $handler->display->display_options['filters']['field_openleg_multisponsors_target_id']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['element_type'] = '0';
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_bill_id']['id'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_bill_id']['field'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['label'] = '';
  $handler->display->display_options['fields']['openleg_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_law_section']['id'] = 'openleg_law_section';
  $handler->display->display_options['fields']['openleg_law_section']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_law_section']['field'] = 'openleg_law_section';
  $handler->display->display_options['fields']['openleg_law_section']['label'] = '';
  $handler->display->display_options['fields']['openleg_law_section']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_act_clause']['id'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_act_clause']['field'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['label'] = '';
  $handler->display->display_options['fields']['openleg_act_clause']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor']['id'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['id'] = 'field_openleg_sponsor_1';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['ui_name'] = 'Bill: Sponsor Name';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['element_label_colon'] = FALSE;
  /* Field: View: Constituent Aye Votes */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'View: Constituent Aye Votes';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_type'] = '0';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view']['arguments'] = '[!bill_id]/aye/!1';
  /* Field: View: Constituent Nay Votes */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'View: Constituent Nay Votes';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_type'] = '0';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_1']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!bill_id]/nay/!1';
  /* Field: View: All Aye Votes */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'View: All Aye Votes';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_type'] = '0';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_2']['display'] = 'all_votes';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!bill_id]/aye';
  /* Field: View: All Nay Votes */
  $handler->display->display_options['fields']['view_3']['id'] = 'view_3';
  $handler->display->display_options['fields']['view_3']['table'] = 'views';
  $handler->display->display_options['fields']['view_3']['field'] = 'view';
  $handler->display->display_options['fields']['view_3']['ui_name'] = 'View: All Nay Votes';
  $handler->display->display_options['fields']['view_3']['label'] = '';
  $handler->display->display_options['fields']['view_3']['element_type'] = '0';
  $handler->display->display_options['fields']['view_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_3']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_3']['display'] = 'all_votes';
  $handler->display->display_options['fields']['view_3']['arguments'] = '[!bill_id]/nay';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Null: Constituent IDs */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Null: Constituent IDs';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['filters']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['filters']['bill_id']['table'] = 'bill';
  $handler->display->display_options['filters']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['block_description'] = 'Constituent Bills';

  /* Display: Active Bill List */
  $handler = $view->new_display('block', 'Active Bill List', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.view-content table tbody';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['fields']['bill_id']['label'] = '';
  $handler->display->display_options['fields']['bill_id']['element_type'] = '0';
  $handler->display->display_options['fields']['bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_bill_id']['id'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_bill_id']['field'] = 'openleg_bill_id';
  $handler->display->display_options['fields']['openleg_bill_id']['label'] = '';
  $handler->display->display_options['fields']['openleg_bill_id']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_law_section']['id'] = 'openleg_law_section';
  $handler->display->display_options['fields']['openleg_law_section']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_law_section']['field'] = 'openleg_law_section';
  $handler->display->display_options['fields']['openleg_law_section']['label'] = '';
  $handler->display->display_options['fields']['openleg_law_section']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'bill';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['openleg_act_clause']['id'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['table'] = 'bill';
  $handler->display->display_options['fields']['openleg_act_clause']['field'] = 'openleg_act_clause';
  $handler->display->display_options['fields']['openleg_act_clause']['label'] = '';
  $handler->display->display_options['fields']['openleg_act_clause']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor']['id'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['id'] = 'field_openleg_sponsor_1';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['table'] = 'field_data_field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['field'] = 'field_openleg_sponsor';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['ui_name'] = 'Bill: Sponsor Name';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['label'] = '';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_openleg_sponsor_1']['element_label_colon'] = FALSE;
  /* Field: View: Constituent Aye Votes */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'View: Constituent Aye Votes';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_type'] = '0';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view']['arguments'] = '[!bill_id]/aye/!1';
  /* Field: View: Constituent Nay Votes */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['ui_name'] = 'View: Constituent Nay Votes';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_type'] = '0';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_1']['display'] = 'constituent_votes';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!bill_id]/nay/!1';
  /* Field: View: All Aye Votes */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['ui_name'] = 'View: All Aye Votes';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_type'] = '0';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_2']['display'] = 'all_votes';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!bill_id]/aye';
  /* Field: View: All Nay Votes */
  $handler->display->display_options['fields']['view_3']['id'] = 'view_3';
  $handler->display->display_options['fields']['view_3']['table'] = 'views';
  $handler->display->display_options['fields']['view_3']['field'] = 'view';
  $handler->display->display_options['fields']['view_3']['ui_name'] = 'View: All Nay Votes';
  $handler->display->display_options['fields']['view_3']['label'] = '';
  $handler->display->display_options['fields']['view_3']['element_type'] = '0';
  $handler->display->display_options['fields']['view_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_3']['view'] = 'bills_voting_subview';
  $handler->display->display_options['fields']['view_3']['display'] = 'all_votes';
  $handler->display->display_options['fields']['view_3']['arguments'] = '[!bill_id]/nay';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Null: Bill IDs */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Null: Bill IDs';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['filters']['bill_id']['id'] = 'bill_id';
  $handler->display->display_options['filters']['bill_id']['table'] = 'bill';
  $handler->display->display_options['filters']['bill_id']['field'] = 'bill_id';
  $handler->display->display_options['block_description'] = 'Active Bills';
  $export['senator_dashboard_bills'] = $view;

  $view = new view();
  $view->name = 'senator_dashboard_bills_new';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator Dashboard Bills';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Senator Dashboard Bills';
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
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See more';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.view-content table tbody';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Law Section */
  $handler->display->display_options['fields']['field_ol_law_section']['id'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['table'] = 'field_data_field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['field'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['label'] = '';
  $handler->display->display_options['fields']['field_ol_law_section']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: Content: Multi Sponsors (field_ol_multi_sponsors) */
  $handler->display->display_options['filters']['field_ol_multi_sponsors_target_id']['id'] = 'field_ol_multi_sponsors_target_id';
  $handler->display->display_options['filters']['field_ol_multi_sponsors_target_id']['table'] = 'field_data_field_ol_multi_sponsors';
  $handler->display->display_options['filters']['field_ol_multi_sponsors_target_id']['field'] = 'field_ol_multi_sponsors_target_id';
  $handler->display->display_options['filters']['field_ol_multi_sponsors_target_id']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    8 => 0,
    9 => 0,
    3 => 0,
    10 => 0,
    11 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    16 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No bills found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Law Section */
  $handler->display->display_options['fields']['field_ol_law_section']['id'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['table'] = 'field_data_field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['field'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['label'] = '';
  $handler->display->display_options['fields']['field_ol_law_section']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Co Sponsors */
  $handler->display->display_options['fields']['field_ol_co_sponsors']['id'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['table'] = 'field_data_field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['field'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['label'] = '';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_co_sponsors']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_ol_co_sponsors']['delta_offset'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Senator Dashboard Bills - Constituents';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No bills found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Law Section */
  $handler->display->display_options['fields']['field_ol_law_section']['id'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['table'] = 'field_data_field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['field'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['label'] = '';
  $handler->display->display_options['fields']['field_ol_law_section']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Senator Dashboard Bills - Constituents';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Law Section */
  $handler->display->display_options['fields']['field_ol_law_section']['id'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['table'] = 'field_data_field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['field'] = 'field_ol_law_section';
  $handler->display->display_options['fields']['field_ol_law_section']['label'] = '';
  $handler->display->display_options['fields']['field_ol_law_section']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_ol_sponsor']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_sponsor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Sponsor Name */
  $handler->display->display_options['fields']['field_ol_sponsor_name']['id'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['table'] = 'field_data_field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['field'] = 'field_ol_sponsor_name';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['label'] = '';
  $handler->display->display_options['fields']['field_ol_sponsor_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Co Sponsors */
  $handler->display->display_options['fields']['field_ol_co_sponsors']['id'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['table'] = 'field_data_field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['field'] = 'field_ol_co_sponsors';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['label'] = '';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_co_sponsors']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_ol_co_sponsors']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_ol_co_sponsors']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Status Date (field_ol_last_status_date) */
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['id'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['table'] = 'field_data_field_ol_last_status_date';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['field'] = 'field_ol_last_status_date_value';
  $handler->display->display_options['sorts']['field_ol_last_status_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
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
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['filters']['nid_1']['table'] = 'node';
  $handler->display->display_options['filters']['nid_1']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_1']['group'] = 1;
  $export['senator_dashboard_bills_new'] = $view;

  $view = new view();
  $view->name = 'senator_dashboard_inbox';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'pm_message';
  $view->human_name = 'Senator Dashboard Inbox';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Senator Dashboard Inbox';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Privatemsg: Recipient */
  $handler->display->display_options['relationships']['recipient']['id'] = 'recipient';
  $handler->display->display_options['relationships']['recipient']['table'] = 'pm_index';
  $handler->display->display_options['relationships']['recipient']['field'] = 'recipient';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_user_account_node']['id'] = 'reverse_field_user_account_node';
  $handler->display->display_options['relationships']['reverse_field_user_account_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_user_account_node']['field'] = 'reverse_field_user_account_node';
  $handler->display->display_options['relationships']['reverse_field_user_account_node']['relationship'] = 'recipient';
  /* Field: Bulk operations: Privatemsg */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'pm_message';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
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
  );
  /* Field: Privatemsg: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'pm_message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['exclude'] = TRUE;
  /* Field: Privatemsg: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'pm_message';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = 'Regarding';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['subject']['alter']['text'] = '<a href="inbox/message/[mid]">[subject]</a>';
  $handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
  /* Field: Privatemsg: Send date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'pm_message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Time Sent';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'M j G:i';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'privatemsg_current_day';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'recipient';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['senator_dashboard_inbox'] = $view;

  $view = new view();
  $view->name = 'senator_dashboard_issues';
  $view->description = 'Used for various display of issue dispays for explorer page and other sections.';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Senator Dashboard Issues';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Filter by';
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
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'secondary_label' => NULL,
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
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  /* Relationship: Flags: follow_issue counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'follow_issue';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = '';
  $handler->display->display_options['fields']['count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['count']['alter']['text'] = 'See [count] Followers';
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['empty'] = 'No Followers';
  $handler->display->display_options['fields']['count']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['count']['separator'] = '';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Sort criterion: Flags: Flag counter */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'flag_counts';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['sorts']['count']['order'] = 'DESC';
  $handler->display->display_options['sorts']['count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['count']['expose']['label'] = 'Most Popular';
  /* Sort criterion: Flags: Time last flagged */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'flag_counts';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  $handler->display->display_options['sorts']['last_updated']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['last_updated']['expose']['label'] = 'Most Recent';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['null']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'issues' => 'issues',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: Taxonomy term: Term ID */
  $handler->display->display_options['filters']['tid_raw']['id'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid_raw']['field'] = 'tid_raw';

  /* Display: Issues */
  $handler = $view->new_display('block', 'Issues', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'Issues';
  $export['senator_dashboard_issues'] = $view;

  $view = new view();
  $view->name = 'senator_dashboard_message_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'pm_message';
  $view->human_name = 'Senator Dashboard Inbox Message';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Field: Privatemsg: Message */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'pm_message';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Privatemsg: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'pm_message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['exclude'] = TRUE;
  /* Contextual filter: Privatemsg: Message ID */
  $handler->display->display_options['arguments']['mid']['id'] = 'mid';
  $handler->display->display_options['arguments']['mid']['table'] = 'pm_message';
  $handler->display->display_options['arguments']['mid']['field'] = 'mid';
  $handler->display->display_options['arguments']['mid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['mid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['mid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['mid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['mid']['summary_options']['items_per_page'] = '25';

  /* Display: Message View */
  $handler = $view->new_display('block', 'Message View', 'message_view');

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['senator_dashboard_message_view'] = $view;

  $view = new view();
  $view->name = 'senator_dashboard_petitions_and_questionnaires';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator Dashboard Petitions and Questionnaires';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Senator Dashboard Petitions and Questionnaires';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = 'Created on [field_date]';
  $handler->display->display_options['fields']['field_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['empty'] = '[created]';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Webform: Webform submission count */
  $handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
  $handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['label'] = '';
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_type'] = '0';
  $handler->display->display_options['fields']['webform_submission_count_node']['element_label_colon'] = FALSE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'fixed';
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
    'questionnaire' => 'questionnaire',
  );

  /* Display: Questionnaires */
  $handler = $view->new_display('block', 'Questionnaires', 'questionnaires');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = 'Created on [field_date]';
  $handler->display->display_options['fields']['field_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['empty'] = '[created]';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Webform: Webform submission count */
  $handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
  $handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['label'] = '';
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_type'] = '0';
  $handler->display->display_options['fields']['webform_submission_count_node']['element_label_colon'] = FALSE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
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
    'questionnaire' => 'questionnaire',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['operator'] = '!=';

  /* Display: Petitions */
  $handler = $view->new_display('block', 'Petitions', 'petitions');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = 'Created on [field_date]';
  $handler->display->display_options['fields']['field_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['empty'] = '[created]';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Webform: Webform submission count */
  $handler->display->display_options['fields']['webform_submission_count_node']['id'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['table'] = 'node';
  $handler->display->display_options['fields']['webform_submission_count_node']['field'] = 'webform_submission_count_node';
  $handler->display->display_options['fields']['webform_submission_count_node']['label'] = '';
  $handler->display->display_options['fields']['webform_submission_count_node']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_count_node']['element_type'] = '0';
  $handler->display->display_options['fields']['webform_submission_count_node']['element_label_colon'] = FALSE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['operator'] = '!=';
  $export['senator_dashboard_petitions_and_questionnaires'] = $view;

  return $export;
}
