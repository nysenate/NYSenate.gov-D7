<?php
/**
 * @file
 * nys_student_submissions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_student_submissions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'student_submission_entity_reference';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Student Submission Entity Reference';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'school' => 'school',
  );
  /* Filter criterion: Content: County (field_county) */
  $handler->display->display_options['filters']['field_county_tid']['id'] = 'field_county_tid';
  $handler->display->display_options['filters']['field_county_tid']['table'] = 'field_data_field_county';
  $handler->display->display_options['filters']['field_county_tid']['field'] = 'field_county_tid';
  $handler->display->display_options['filters']['field_county_tid']['value'] = array(
    9599 => '9599',
  );
  $handler->display->display_options['filters']['field_county_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_county_tid']['vocabulary'] = 'nys_counties';

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
  $export['student_submission_entity_reference'] = $view;

  $view = new view();
  $view->name = 'student_submissions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Student Submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What are you thankful for this year?';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'title' => array(
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
    'field_senator_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_school_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_school_student_full_name' => 'field_school_student_full_name',
  );
  /* Relationship: Field Collection Items */
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['id'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['table'] = 'field_data_field_school_student_submissions';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['field'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['ui_name'] = 'Field Collection Items';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_name_target_id']['id'] = 'field_school_name_target_id';
  $handler->display->display_options['relationships']['field_school_name_target_id']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['relationships']['field_school_name_target_id']['field'] = 'field_school_name_target_id';
  /* Relationship: Entityform Type: Entityform Submission */
  $handler->display->display_options['relationships']['entityform']['id'] = 'entityform';
  $handler->display->display_options['relationships']['entityform']['table'] = 'entityform_type';
  $handler->display->display_options['relationships']['entityform']['field'] = 'entityform';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['relationships']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['relationship'] = 'field_school_name_target_id';
  /* Relationship: Field collection item: Attach your submission (field_school_submission_upload:fid) */
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['id'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['field'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['relationship'] = 'field_school_student_submissions_value';
  /* Field: Field collection item: My submission could best be described as */
  $handler->display->display_options['fields']['field_school_submission_type']['id'] = 'field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['table'] = 'field_data_field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['field'] = 'field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_submission_type']['label'] = '';
  $handler->display->display_options['fields']['field_school_submission_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_submission_type']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = '';
  $handler->display->display_options['fields']['field_school_submission_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_submission_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_url_plain';
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_school_first_name']['id'] = 'field_school_first_name';
  $handler->display->display_options['fields']['field_school_first_name']['table'] = 'field_data_field_school_first_name';
  $handler->display->display_options['fields']['field_school_first_name']['field'] = 'field_school_first_name';
  $handler->display->display_options['fields']['field_school_first_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_first_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_school_last_name']['id'] = 'field_school_last_name';
  $handler->display->display_options['fields']['field_school_last_name']['table'] = 'field_data_field_school_last_name';
  $handler->display->display_options['fields']['field_school_last_name']['field'] = 'field_school_last_name';
  $handler->display->display_options['fields']['field_school_last_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_last_name']['alter']['text'] = '<a href="[field_school_submission_upload]">[field_school_first_name] [field_school_last_name]</a> | [field_school_submission_type] ';
  $handler->display->display_options['fields']['field_school_last_name']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_school_last_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: School Name */
  $handler->display->display_options['fields']['field_school_name']['id'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['fields']['field_school_name']['field'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_name']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: School Address */
  $handler->display->display_options['fields']['field_school_address']['id'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['table'] = 'field_data_field_school_address';
  $handler->display->display_options['fields']['field_school_address']['field'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_address']['label'] = '';
  $handler->display->display_options['fields']['field_school_address']['element_label_colon'] = FALSE;
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school_submissions' => 'school_submissions',
  );

  /* Display: Thankful */
  $handler = $view->new_display('page', 'Thankful', 'page');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'senators/%/thankful-2016';

  /* Display: Thankful Block */
  $handler = $view->new_display('block', 'Thankful Block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = '';
  $handler->display->display_options['fields']['field_school_submission_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_submission_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_url_plain';
  /* Field: Field collection item: My submission could best be described as */
  $handler->display->display_options['fields']['field_school_submission_type']['id'] = 'field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['table'] = 'field_data_field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['field'] = 'field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_submission_type']['label'] = '';
  $handler->display->display_options['fields']['field_school_submission_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_submission_type']['element_label_colon'] = FALSE;
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['relationship'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['fields']['filemime']['label'] = '';
  $handler->display->display_options['fields']['filemime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filemime']['element_label_colon'] = FALSE;
  /* Field: File: Extension */
  $handler->display->display_options['fields']['extension']['id'] = 'extension';
  $handler->display->display_options['fields']['extension']['table'] = 'file_managed';
  $handler->display->display_options['fields']['extension']['field'] = 'extension';
  $handler->display->display_options['fields']['extension']['relationship'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['fields']['extension']['label'] = '';
  $handler->display->display_options['fields']['extension']['exclude'] = TRUE;
  $handler->display->display_options['fields']['extension']['element_label_colon'] = FALSE;
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_school_first_name']['id'] = 'field_school_first_name';
  $handler->display->display_options['fields']['field_school_first_name']['table'] = 'field_data_field_school_first_name';
  $handler->display->display_options['fields']['field_school_first_name']['field'] = 'field_school_first_name';
  $handler->display->display_options['fields']['field_school_first_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_first_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_school_last_name']['id'] = 'field_school_last_name';
  $handler->display->display_options['fields']['field_school_last_name']['table'] = 'field_data_field_school_last_name';
  $handler->display->display_options['fields']['field_school_last_name']['field'] = 'field_school_last_name';
  $handler->display->display_options['fields']['field_school_last_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_last_name']['alter']['text'] = '<a href="[field_school_submission_upload]">[field_school_first_name] [field_school_last_name] <span>([extension])</span></a> | [field_school_submission_type]';
  $handler->display->display_options['fields']['field_school_last_name']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_school_last_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: School Name */
  $handler->display->display_options['fields']['field_school_name']['id'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['fields']['field_school_name']['field'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_name']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Earth Day Block */
  $handler = $view->new_display('block', 'Earth Day Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All 2017 Poster Submissions';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_school_legal_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_school_grade',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_school_student_full_name' => 'field_school_student_full_name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_name_target_id']['id'] = 'field_school_name_target_id';
  $handler->display->display_options['relationships']['field_school_name_target_id']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['relationships']['field_school_name_target_id']['field'] = 'field_school_name_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['relationships']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['relationship'] = 'field_school_name_target_id';
  /* Relationship: Entityform Submission: Student Submissions (field_school_stud_earthday_subm) */
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['id'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['table'] = 'field_data_field_school_stud_earthday_subm';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['field'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['label'] = 'Field Collection Items';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['delta'] = '-1';
  /* Relationship: Field collection item: Attach your submission (field_school_submission_upload:fid) */
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['id'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['field'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: School Legal Name */
  $handler->display->display_options['fields']['field_school_legal_name']['id'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['table'] = 'field_data_field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['field'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_legal_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_legal_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_legal_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: School Name */
  $handler->display->display_options['fields']['field_school_name']['id'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['fields']['field_school_name']['field'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_name']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_school_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_name']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['relationship'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['fields']['filemime']['label'] = '';
  $handler->display->display_options['fields']['filemime']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filemime']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = '';
  $handler->display->display_options['fields']['field_school_submission_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_submission_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_school_submission_upload']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: File: Extension */
  $handler->display->display_options['fields']['extension']['id'] = 'extension';
  $handler->display->display_options['fields']['extension']['table'] = 'file_managed';
  $handler->display->display_options['fields']['extension']['field'] = 'extension';
  $handler->display->display_options['fields']['extension']['relationship'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['fields']['extension']['label'] = '';
  $handler->display->display_options['fields']['extension']['exclude'] = TRUE;
  $handler->display->display_options['fields']['extension']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Student's Full Name */
  $handler->display->display_options['fields']['field_school_student_full_name']['id'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['field'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_student_full_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_student_full_name']['alter']['text'] = '<a href="[field_school_submission_upload]">[field_school_student_full_name] <span>([extension])</span></a>';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Entityform Submission: Grade (field_school_grade) */
  $handler->display->display_options['sorts']['field_school_grade_value']['id'] = 'field_school_grade_value';
  $handler->display->display_options['sorts']['field_school_grade_value']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['sorts']['field_school_grade_value']['field'] = 'field_school_grade_value';
  $handler->display->display_options['sorts']['field_school_grade_value']['allowed_values'] = '1';
  /* Sort criterion: Field collection item: Student&#039;s Full Name (field_school_student_full_name) */
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['id'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['field'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'earth_day' => 'earth_day',
  );
  /* Filter criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-02-07';
  /* Filter criterion: Field collection item: Show? (field_school_show_student) */
  $handler->display->display_options['filters']['field_school_show_student_value']['id'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['filters']['field_school_show_student_value']['field'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_school_show_student_value']['value'] = array(
    0 => '0',
  );

  /* Display: Featured Earth Day Poster */
  $handler = $view->new_display('block', 'Featured Earth Day Poster', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Earth Day 2017 Poster Winner';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_school_student_full_name' => 'field_school_student_full_name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<br>
<p>Sincerely,</p>
<p>[field_senator]<br>
NYS Senator, District [field_district_number]</p>
<br>
<h2>2017 Earth Day Poster Winner(s)</h2>

<p>I am pleased to announce the winner(s) of the 2017 Earth Day Poster Contest from my District:</p>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_name_target_id']['id'] = 'field_school_name_target_id';
  $handler->display->display_options['relationships']['field_school_name_target_id']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['relationships']['field_school_name_target_id']['field'] = 'field_school_name_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['relationships']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['relationship'] = 'field_school_name_target_id';
  /* Relationship: Entityform Submission: Student Submissions (field_school_stud_earthday_subm) */
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['id'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['table'] = 'field_data_field_school_stud_earthday_subm';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['field'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['label'] = 'Field Collection Items';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['relationships']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['relationships']['field_senator_target_id']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Student's Full Name */
  $handler->display->display_options['fields']['field_school_student_full_name']['id'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['field'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_student_full_name']['alter']['text'] = '<a href="[field_school_submission_upload]">[field_school_student_full_name] <span>([extension])</span></a>';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_student_full_name']['element_wrapper_type'] = 'p';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_school_grade']['element_class'] = 'nospace';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Content: School Legal Name */
  $handler->display->display_options['fields']['field_school_legal_name']['id'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['table'] = 'field_data_field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['field'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_legal_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_legal_name']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_school_legal_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: School Name */
  $handler->display->display_options['fields']['field_school_name']['id'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['fields']['field_school_name']['field'] = 'field_school_name';
  $handler->display->display_options['fields']['field_school_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_name']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_school_name']['element_class'] = 'nospace';
  $handler->display->display_options['fields']['field_school_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_name']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = '';
  $handler->display->display_options['fields']['field_school_submission_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_school_submission_upload']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Field: District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_district']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_district_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Student&#039;s Full Name (field_school_student_full_name) */
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['id'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['field'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'earth_day' => 'earth_day',
  );
  /* Filter criterion: Field collection item: Poster Winner? (field_school_featured_entry) */
  $handler->display->display_options['filters']['field_school_featured_entry_value']['id'] = 'field_school_featured_entry_value';
  $handler->display->display_options['filters']['field_school_featured_entry_value']['table'] = 'field_data_field_school_featured_entry';
  $handler->display->display_options['filters']['field_school_featured_entry_value']['field'] = 'field_school_featured_entry_value';
  $handler->display->display_options['filters']['field_school_featured_entry_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['filters']['field_school_featured_entry_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-02-07';
  $export['student_submissions'] = $view;

  $view = new view();
  $view->name = 'student_submissions_admin_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Student Submissions Admin Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Student Submissions Admin Lists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '175';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school_address' => 'field_school_address',
    'field_senator' => 'field_senator',
    'field_school_student_full_name' => 'field_school_student_full_name',
    'field_school_grade' => 'field_school_student_full_name',
    'field_school_contact_name' => 'field_school_student_full_name',
    'field_school_teachers_email' => 'field_school_student_full_name',
    'field_school_submission_upload' => 'field_school_submission_upload',
    'field_school_submission_upload_1' => 'field_school_submission_upload',
    'field_school_featured_entry' => 'field_school_featured_entry',
    'edit_entityform' => 'edit_entityform',
    'created' => 'created',
    'link_entityform' => 'edit_entityform',
    'title' => 'title',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_school_show_student' => 'field_school_student_full_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_senator' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_student_full_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_school_grade' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_contact_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_teachers_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_submission_upload' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_school_submission_upload_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_featured_entry' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'edit_entityform' => array(
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_entityform' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_show_student' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Entityform Submission: Student Submissions (field_school_stud_earthday_subm) */
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['id'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['table'] = 'field_data_field_school_stud_earthday_subm';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['field'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_name_target_id']['id'] = 'field_school_name_target_id';
  $handler->display->display_options['relationships']['field_school_name_target_id']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['relationships']['field_school_name_target_id']['field'] = 'field_school_name_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['relationships']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['relationship'] = 'field_school_name_target_id';
  /* Relationship: Field collection item: Attach your submission (field_school_submission_upload:fid) */
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['id'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['field'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['relationship'] = 'field_school_stud_earthday_subm_value';
  /* Field: Content: School Address */
  $handler->display->display_options['fields']['field_school_address']['id'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['table'] = 'field_data_field_school_address';
  $handler->display->display_options['fields']['field_school_address']['field'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_address']['label'] = 'School';
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Student's Full Name */
  $handler->display->display_options['fields']['field_school_student_full_name']['id'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['field'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['label'] = 'Student\'s Name';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'strong';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Contact Name */
  $handler->display->display_options['fields']['field_school_contact_name']['id'] = 'field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['table'] = 'field_data_field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['field'] = 'field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_contact_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Teacher's Email */
  $handler->display->display_options['fields']['field_school_teachers_email']['id'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['table'] = 'field_data_field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['field'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['label'] = '';
  $handler->display->display_options['fields']['field_school_teachers_email']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = 'Submission';
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_school_submission_upload']['settings'] = array(
    'file_view_mode' => 'teaser',
  );
  /* Field: URL to File */
  $handler->display->display_options['fields']['field_school_submission_upload_1']['id'] = 'field_school_submission_upload_1';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['ui_name'] = 'URL to File';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['label'] = '';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_submission_upload_1']['alter']['text'] = '<a href="[field_school_submission_upload_1]">Link to file</a>';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_submission_upload_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload_1']['type'] = 'file_url_plain';
  /* Field: Field collection item: Poster Winner? */
  $handler->display->display_options['fields']['field_school_featured_entry']['id'] = 'field_school_featured_entry';
  $handler->display->display_options['fields']['field_school_featured_entry']['table'] = 'field_data_field_school_featured_entry';
  $handler->display->display_options['fields']['field_school_featured_entry']['field'] = 'field_school_featured_entry';
  $handler->display->display_options['fields']['field_school_featured_entry']['relationship'] = 'field_school_stud_earthday_subm_value';
  /* Field: Entityform Submission: Edit Link */
  $handler->display->display_options['fields']['edit_entityform']['id'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['edit_entityform']['field'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_entityform']['text'] = 'Edit';
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'month_only';
  /* Field: Entityform Submission: Link */
  $handler->display->display_options['fields']['link_entityform']['id'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['link_entityform']['field'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['label'] = '';
  $handler->display->display_options['fields']['link_entityform']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link_entityform']['text'] = 'View';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Bulk operations: Field collection item */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'field_school_stud_earthday_subm::field_school_featured_entry' => 'field_school_stud_earthday_subm::field_school_featured_entry',
          'field_school_stud_earthday_subm::field_school_student_full_name' => 'field_school_stud_earthday_subm::field_school_student_full_name',
          'field_school_stud_earthday_subm::field_school_submission_upload' => 'field_school_stud_earthday_subm::field_school_submission_upload',
          'field_school_stud_earthday_subm::field_school_show_student' => 'field_school_stud_earthday_subm::field_school_show_student',
        ),
      ),
    ),
  );
  /* Field: Field collection item: Show? */
  $handler->display->display_options['fields']['field_school_show_student']['id'] = 'field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['field'] = 'field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_show_student']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_show_student']['alter']['text'] = 'Show status: [field_school_show_student]';
  /* Sort criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Sort by date submitted';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Sort criterion: Field collection item: Student&#039;s Full Name (field_school_student_full_name) */
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['id'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['field'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['expose']['label'] = 'Student Name';
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'earth_day' => 'earth_day',
  );
  /* Filter criterion: Field: Senator (field_senator) */
  $handler->display->display_options['filters']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['filters']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['filters']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['filters']['field_senator_target_id']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['filters']['field_senator_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['operator_id'] = 'field_senator_target_id_op';
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['label'] = 'Senator';
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['operator'] = 'field_senator_target_id_op';
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['identifier'] = 'field_senator_target_id';
  $handler->display->display_options['filters']['field_senator_target_id']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
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
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-02-07';
  /* Filter criterion: Entityform Submission: Contact Name (field_school_contact_name) */
  $handler->display->display_options['filters']['field_school_contact_name_value']['id'] = 'field_school_contact_name_value';
  $handler->display->display_options['filters']['field_school_contact_name_value']['table'] = 'field_data_field_school_contact_name';
  $handler->display->display_options['filters']['field_school_contact_name_value']['field'] = 'field_school_contact_name_value';
  $handler->display->display_options['filters']['field_school_contact_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_school_contact_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['operator_id'] = 'field_school_contact_name_value_op';
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['label'] = 'Teacher Name';
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['operator'] = 'field_school_contact_name_value_op';
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['identifier'] = 'field_school_contact_name_value';
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['remember_roles'] = array(
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
    17 => 0,
  );
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['autocomplete_field'] = 'field_school_contact_name';
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_school_contact_name_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Earth Day Submissions */
  $handler = $view->new_display('page', 'Earth Day Submissions', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    17 => '17',
  );
  $handler->display->display_options['path'] = 'admin/entityforms/earthday';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Student Submissions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export CSV */
  $handler = $view->new_display('views_data_export', 'Data export CSV', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Student Submissions Data Export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'student-export.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityform Submission: Student Submissions (field_school_stud_earthday_subm) */
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['id'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['table'] = 'field_data_field_school_stud_earthday_subm';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['field'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['relationships']['field_school_stud_earthday_subm_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_name_target_id']['id'] = 'field_school_name_target_id';
  $handler->display->display_options['relationships']['field_school_name_target_id']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['relationships']['field_school_name_target_id']['field'] = 'field_school_name_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['relationships']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['relationship'] = 'field_school_name_target_id';
  /* Relationship: Field collection item: Attach your submission (field_school_submission_upload:fid) */
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['id'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['field'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['relationship'] = 'field_school_stud_earthday_subm_value';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'districts' => 'districts',
    'committees' => 0,
    'content_experiments' => 0,
    'issues' => 0,
    'nys_counties' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'month_only';
  /* Field: Field collection item: Student's Full Name */
  $handler->display->display_options['fields']['field_school_student_full_name']['id'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['field'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['label'] = 'Student\'s Name';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'strong';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Contact Name */
  $handler->display->display_options['fields']['field_school_contact_name']['id'] = 'field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['table'] = 'field_data_field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['field'] = 'field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['label'] = 'Teacher';
  $handler->display->display_options['fields']['field_school_contact_name']['element_label_colon'] = FALSE;
  /* Field: Content: School Legal Name */
  $handler->display->display_options['fields']['field_school_legal_name']['id'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['table'] = 'field_data_field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['field'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_legal_name']['label'] = 'School Name';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Location: Street */
  $handler->display->display_options['fields']['street']['id'] = 'street';
  $handler->display->display_options['fields']['street']['table'] = 'location';
  $handler->display->display_options['fields']['street']['field'] = 'street';
  $handler->display->display_options['fields']['street']['relationship'] = 'field_school_name_target_id';
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['province']['label'] = 'City/State';
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['province']['alter']['text'] = '[city], [province]';
  $handler->display->display_options['fields']['province']['style'] = 'code';
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['postal_code']['label'] = 'Zip';
  /* Field: Entityform Submission: Teacher's Email */
  $handler->display->display_options['fields']['field_school_teachers_email']['id'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['table'] = 'field_data_field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['field'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_school_teachers_email']['element_label_colon'] = FALSE;
  /* Field: Content: Principal Phone Number */
  $handler->display->display_options['fields']['field_school_ceo_phone']['id'] = 'field_school_ceo_phone';
  $handler->display->display_options['fields']['field_school_ceo_phone']['table'] = 'field_data_field_school_ceo_phone';
  $handler->display->display_options['fields']['field_school_ceo_phone']['field'] = 'field_school_ceo_phone';
  $handler->display->display_options['fields']['field_school_ceo_phone']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_ceo_phone']['label'] = 'School Phone Number';
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_district']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'link' => 0,
  );
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = 'URL';
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_url_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'earth_day' => 'earth_day',
  );
  /* Filter criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-02-07';
  /* Filter criterion: Field collection item: Show? (field_school_show_student) */
  $handler->display->display_options['filters']['field_school_show_student_value']['id'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['filters']['field_school_show_student_value']['field'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_school_show_student_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'student-export.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['segment_size'] = '500';
  $export['student_submissions_admin_lists'] = $view;

  return $export;
}
