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
  $view->name = 'hannon_high_schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hannon High Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hannon High Schools';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    17 => '17',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
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
    'school' => 'school',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value']['id'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['value'] = 'Senior High';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_3']['id'] = 'title_3';
  $handler->display->display_options['filters']['title_3']['table'] = 'node';
  $handler->display->display_options['filters']['title_3']['field'] = 'title';
  $handler->display->display_options['filters']['title_3']['operator'] = 'not';
  $handler->display->display_options['filters']['title_3']['value'] = 'Massapequa High School, Senior High';
  $handler->display->display_options['filters']['title_3']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_2']['id'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['table'] = 'node';
  $handler->display->display_options['filters']['title_2']['field'] = 'title';
  $handler->display->display_options['filters']['title_2']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_2']['value'] = 'Our Lady of Mercy Academy';
  $handler->display->display_options['filters']['title_2']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['value'] = 'Holy Trinity Diocesan High School';
  $handler->display->display_options['filters']['title_1']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['value'] = 'Regis High School';
  $handler->display->display_options['filters']['title']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_4']['id'] = 'postal_code_4';
  $handler->display->display_options['filters']['postal_code_4']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_4']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_4']['value'] = '11010';
  $handler->display->display_options['filters']['postal_code_4']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code']['value'] = '11501';
  $handler->display->display_options['filters']['postal_code']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_1']['id'] = 'postal_code_1';
  $handler->display->display_options['filters']['postal_code_1']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_1']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_1']['value'] = '11530';
  $handler->display->display_options['filters']['postal_code_1']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_5']['id'] = 'postal_code_5';
  $handler->display->display_options['filters']['postal_code_5']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_5']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_5']['value'] = '11550';
  $handler->display->display_options['filters']['postal_code_5']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_2']['id'] = 'postal_code_2';
  $handler->display->display_options['filters']['postal_code_2']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_2']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_2']['value'] = '11553';
  $handler->display->display_options['filters']['postal_code_2']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_11']['id'] = 'postal_code_11';
  $handler->display->display_options['filters']['postal_code_11']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_11']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_11']['value'] = '11554';
  $handler->display->display_options['filters']['postal_code_11']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_10']['id'] = 'postal_code_10';
  $handler->display->display_options['filters']['postal_code_10']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_10']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_10']['value'] = '11590';
  $handler->display->display_options['filters']['postal_code_10']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_9']['id'] = 'postal_code_9';
  $handler->display->display_options['filters']['postal_code_9']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_9']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_9']['value'] = '11714';
  $handler->display->display_options['filters']['postal_code_9']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_8']['id'] = 'postal_code_8';
  $handler->display->display_options['filters']['postal_code_8']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_8']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_8']['value'] = '11735';
  $handler->display->display_options['filters']['postal_code_8']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_7']['id'] = 'postal_code_7';
  $handler->display->display_options['filters']['postal_code_7']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_7']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_7']['value'] = '11756';
  $handler->display->display_options['filters']['postal_code_7']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_6']['id'] = 'postal_code_6';
  $handler->display->display_options['filters']['postal_code_6']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_6']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_6']['value'] = '11758';
  $handler->display->display_options['filters']['postal_code_6']['group'] = 2;
  /* Filter criterion: Location: Postal Code */
  $handler->display->display_options['filters']['postal_code_3']['id'] = 'postal_code_3';
  $handler->display->display_options['filters']['postal_code_3']['table'] = 'location';
  $handler->display->display_options['filters']['postal_code_3']['field'] = 'postal_code';
  $handler->display->display_options['filters']['postal_code_3']['value'] = '11803';
  $handler->display->display_options['filters']['postal_code_3']['group'] = 2;

  /* Display: Hannon HS */
  $handler = $view->new_display('page', 'Hannon HS', 'page');
  $handler->display->display_options['path'] = 'hannon-high-schools';
  $export['hannon_high_schools'] = $view;

  $view = new view();
  $view->name = 'student_hannon_photo_contest';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Student Hannon Photo Contest';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hannon Photo Contest';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_hannon_school_name_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_hannon_category_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_hannon_last_name_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_hannon_winner_types_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_hannon_star_rating_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_hannon_first_name' => 'field_hannon_first_name',
    'field_hannon_last_name' => 'field_hannon_last_name',
    'field_hannon_school_name' => 'field_hannon_school_name',
    'field_hannon_category' => 'field_hannon_category',
    'field_hannon_photo_upload' => 'field_hannon_photo_upload',
    'field_hannon_winner_types' => 'field_hannon_winner_types',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_hannon_city' => 'field_hannon_city',
    'field_hannon_street_address' => 'field_hannon_street_address',
    'field_hannon_zip_code' => 'field_hannon_last_name',
    'field_school_teachers_email' => 'field_hannon_last_name',
    'field_hannon_phone_num' => 'field_hannon_last_name',
    'field_hannon_star_rating' => 'field_hannon_winner_types',
    'created' => 'field_hannon_last_name',
    'edit_entityform' => 'edit_entityform',
    'field_hannon_district_status' => 'field_hannon_last_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_hannon_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_hannon_school_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_photo_upload' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_winner_types' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_street_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_zip_code' => array(
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
    'field_hannon_phone_num' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_star_rating' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_entityform' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hannon_district_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Entityform Submission: First Name */
  $handler->display->display_options['fields']['field_hannon_first_name']['id'] = 'field_hannon_first_name';
  $handler->display->display_options['fields']['field_hannon_first_name']['table'] = 'field_data_field_hannon_first_name';
  $handler->display->display_options['fields']['field_hannon_first_name']['field'] = 'field_hannon_first_name';
  $handler->display->display_options['fields']['field_hannon_first_name']['exclude'] = TRUE;
  /* Field: Entityform Submission: Last Name */
  $handler->display->display_options['fields']['field_hannon_last_name']['id'] = 'field_hannon_last_name';
  $handler->display->display_options['fields']['field_hannon_last_name']['table'] = 'field_data_field_hannon_last_name';
  $handler->display->display_options['fields']['field_hannon_last_name']['field'] = 'field_hannon_last_name';
  $handler->display->display_options['fields']['field_hannon_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_hannon_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hannon_last_name']['alter']['text'] = '[field_hannon_first_name] [field_hannon_last_name]';
  /* Field: Entityform Submission: School */
  $handler->display->display_options['fields']['field_hannon_school_name']['id'] = 'field_hannon_school_name';
  $handler->display->display_options['fields']['field_hannon_school_name']['table'] = 'field_data_field_hannon_school_name';
  $handler->display->display_options['fields']['field_hannon_school_name']['field'] = 'field_hannon_school_name';
  $handler->display->display_options['fields']['field_hannon_school_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Entityform Submission: Category */
  $handler->display->display_options['fields']['field_hannon_category']['id'] = 'field_hannon_category';
  $handler->display->display_options['fields']['field_hannon_category']['table'] = 'field_data_field_hannon_category';
  $handler->display->display_options['fields']['field_hannon_category']['field'] = 'field_hannon_category';
  /* Field: Entityform Submission: Attach your photo */
  $handler->display->display_options['fields']['field_hannon_photo_upload']['id'] = 'field_hannon_photo_upload';
  $handler->display->display_options['fields']['field_hannon_photo_upload']['table'] = 'field_data_field_hannon_photo_upload';
  $handler->display->display_options['fields']['field_hannon_photo_upload']['field'] = 'field_hannon_photo_upload';
  $handler->display->display_options['fields']['field_hannon_photo_upload']['label'] = 'Photo Submission';
  $handler->display->display_options['fields']['field_hannon_photo_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hannon_photo_upload']['settings'] = array(
    'image_style' => '280x280',
    'image_link' => 'file',
  );
  /* Field: Entityform Submission: Winner Types */
  $handler->display->display_options['fields']['field_hannon_winner_types']['id'] = 'field_hannon_winner_types';
  $handler->display->display_options['fields']['field_hannon_winner_types']['table'] = 'field_data_field_hannon_winner_types';
  $handler->display->display_options['fields']['field_hannon_winner_types']['field'] = 'field_hannon_winner_types';
  $handler->display->display_options['fields']['field_hannon_winner_types']['label'] = 'Winner/Ratings Status';
  $handler->display->display_options['fields']['field_hannon_winner_types']['alter']['text'] = '[field_hannon_winner]<br>
[field_hannon_winner_types]
';
  /* Field: Bulk operations: Entityform Submission */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_entityform';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select Winners or Change Star Ratings';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Select Winners or Change Star Ratings',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'hannon_photo_contest::field_hannon_star_rating' => 'hannon_photo_contest::field_hannon_star_rating',
          'hannon_photo_contest::field_hannon_winner_types' => 'hannon_photo_contest::field_hannon_winner_types',
          'hannon_photo_contest::field_school_show_student' => 'hannon_photo_contest::field_school_show_student',
          'hannon_photo_contest::field_hannon_district_status' => 'hannon_photo_contest::field_hannon_district_status',
        ),
      ),
    ),
  );
  /* Field: Entityform Submission: City */
  $handler->display->display_options['fields']['field_hannon_city']['id'] = 'field_hannon_city';
  $handler->display->display_options['fields']['field_hannon_city']['table'] = 'field_data_field_hannon_city';
  $handler->display->display_options['fields']['field_hannon_city']['field'] = 'field_hannon_city';
  $handler->display->display_options['fields']['field_hannon_city']['label'] = '';
  $handler->display->display_options['fields']['field_hannon_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hannon_city']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Street Address */
  $handler->display->display_options['fields']['field_hannon_street_address']['id'] = 'field_hannon_street_address';
  $handler->display->display_options['fields']['field_hannon_street_address']['table'] = 'field_data_field_hannon_street_address';
  $handler->display->display_options['fields']['field_hannon_street_address']['field'] = 'field_hannon_street_address';
  $handler->display->display_options['fields']['field_hannon_street_address']['label'] = '';
  $handler->display->display_options['fields']['field_hannon_street_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hannon_street_address']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Zip Code */
  $handler->display->display_options['fields']['field_hannon_zip_code']['id'] = 'field_hannon_zip_code';
  $handler->display->display_options['fields']['field_hannon_zip_code']['table'] = 'field_data_field_hannon_zip_code';
  $handler->display->display_options['fields']['field_hannon_zip_code']['field'] = 'field_hannon_zip_code';
  $handler->display->display_options['fields']['field_hannon_zip_code']['label'] = '';
  $handler->display->display_options['fields']['field_hannon_zip_code']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hannon_zip_code']['alter']['text'] = '[field_hannon_street_address]<br>
[field_hannon_city], NY [field_hannon_zip_code]';
  $handler->display->display_options['fields']['field_hannon_zip_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hannon_zip_code']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Entityform Submission: Teacher's Email */
  $handler->display->display_options['fields']['field_school_teachers_email']['id'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['table'] = 'field_data_field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['field'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['label'] = '';
  $handler->display->display_options['fields']['field_school_teachers_email']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Phone Number */
  $handler->display->display_options['fields']['field_hannon_phone_num']['id'] = 'field_hannon_phone_num';
  $handler->display->display_options['fields']['field_hannon_phone_num']['table'] = 'field_data_field_hannon_phone_num';
  $handler->display->display_options['fields']['field_hannon_phone_num']['field'] = 'field_hannon_phone_num';
  $handler->display->display_options['fields']['field_hannon_phone_num']['label'] = '';
  $handler->display->display_options['fields']['field_hannon_phone_num']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Star Rating */
  $handler->display->display_options['fields']['field_hannon_star_rating']['id'] = 'field_hannon_star_rating';
  $handler->display->display_options['fields']['field_hannon_star_rating']['table'] = 'field_data_field_hannon_star_rating';
  $handler->display->display_options['fields']['field_hannon_star_rating']['field'] = 'field_hannon_star_rating';
  $handler->display->display_options['fields']['field_hannon_star_rating']['label'] = '';
  $handler->display->display_options['fields']['field_hannon_star_rating']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'privatemsg_years';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'month_only';
  /* Field: Entityform Submission: Edit Link */
  $handler->display->display_options['fields']['edit_entityform']['id'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['edit_entityform']['field'] = 'edit_entityform';
  /* Field: Entityform Submission: District Status */
  $handler->display->display_options['fields']['field_hannon_district_status']['id'] = 'field_hannon_district_status';
  $handler->display->display_options['fields']['field_hannon_district_status']['table'] = 'field_data_field_hannon_district_status';
  $handler->display->display_options['fields']['field_hannon_district_status']['field'] = 'field_hannon_district_status';
  $handler->display->display_options['fields']['field_hannon_district_status']['label'] = '';
  $handler->display->display_options['fields']['field_hannon_district_status']['element_label_colon'] = FALSE;
  /* Sort criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Entityform Submission: Star Rating (field_hannon_star_rating) */
  $handler->display->display_options['sorts']['field_hannon_star_rating_value']['id'] = 'field_hannon_star_rating_value';
  $handler->display->display_options['sorts']['field_hannon_star_rating_value']['table'] = 'field_data_field_hannon_star_rating';
  $handler->display->display_options['sorts']['field_hannon_star_rating_value']['field'] = 'field_hannon_star_rating_value';
  $handler->display->display_options['sorts']['field_hannon_star_rating_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_hannon_star_rating_value']['allowed_values'] = '1';
  /* Sort criterion: Entityform Submission: Winner Types (field_hannon_winner_types) */
  $handler->display->display_options['sorts']['field_hannon_winner_types_value']['id'] = 'field_hannon_winner_types_value';
  $handler->display->display_options['sorts']['field_hannon_winner_types_value']['table'] = 'field_data_field_hannon_winner_types';
  $handler->display->display_options['sorts']['field_hannon_winner_types_value']['field'] = 'field_hannon_winner_types_value';
  $handler->display->display_options['sorts']['field_hannon_winner_types_value']['allowed_values'] = '1';
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hannon_photo_contest' => 'hannon_photo_contest',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Entityform Submission: School (field_hannon_school_name) */
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['id'] = 'field_hannon_school_name_target_id';
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['table'] = 'field_data_field_hannon_school_name';
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['field'] = 'field_hannon_school_name_target_id';
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['expose']['operator_id'] = 'field_hannon_school_name_target_id_op';
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['expose']['operator'] = 'field_hannon_school_name_target_id_op';
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['expose']['identifier'] = 'field_hannon_school_name_target_id';
  $handler->display->display_options['filters']['field_hannon_school_name_target_id']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Entityform Submission: Category (field_hannon_category) */
  $handler->display->display_options['filters']['field_hannon_category_value']['id'] = 'field_hannon_category_value';
  $handler->display->display_options['filters']['field_hannon_category_value']['table'] = 'field_data_field_hannon_category';
  $handler->display->display_options['filters']['field_hannon_category_value']['field'] = 'field_hannon_category_value';
  $handler->display->display_options['filters']['field_hannon_category_value']['group'] = 1;
  $handler->display->display_options['filters']['field_hannon_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hannon_category_value']['expose']['operator_id'] = 'field_hannon_category_value_op';
  $handler->display->display_options['filters']['field_hannon_category_value']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_hannon_category_value']['expose']['operator'] = 'field_hannon_category_value_op';
  $handler->display->display_options['filters']['field_hannon_category_value']['expose']['identifier'] = 'field_hannon_category_value';
  $handler->display->display_options['filters']['field_hannon_category_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Entityform Submission: Last Name (field_hannon_last_name) */
  $handler->display->display_options['filters']['field_hannon_last_name_value']['id'] = 'field_hannon_last_name_value';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['table'] = 'field_data_field_hannon_last_name';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['field'] = 'field_hannon_last_name_value';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_hannon_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['operator_id'] = 'field_hannon_last_name_value_op';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['label'] = 'Student\'s Last Name';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['operator'] = 'field_hannon_last_name_value_op';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['identifier'] = 'field_hannon_last_name_value';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['autocomplete_min_chars'] = '1';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['autocomplete_field'] = 'field_hannon_last_name';
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_hannon_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Entityform Submission: Star Rating (field_hannon_star_rating) */
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['id'] = 'field_hannon_star_rating_value';
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['table'] = 'field_data_field_hannon_star_rating';
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['field'] = 'field_hannon_star_rating_value';
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['group'] = 1;
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['expose']['operator_id'] = 'field_hannon_star_rating_value_op';
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['expose']['label'] = 'Star Rating';
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['expose']['operator'] = 'field_hannon_star_rating_value_op';
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['expose']['identifier'] = 'field_hannon_star_rating_value';
  $handler->display->display_options['filters']['field_hannon_star_rating_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Entityform Submission: Winner Types (field_hannon_winner_types) */
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['id'] = 'field_hannon_winner_types_value';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['table'] = 'field_data_field_hannon_winner_types';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['field'] = 'field_hannon_winner_types_value';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['group'] = 1;
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['expose']['operator_id'] = 'field_hannon_winner_types_value_op';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['expose']['label'] = 'Winner Types';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['expose']['description'] = 'To choose winners, click box in column next to photo submission, and then click "Select Winners" button below to change value.';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['expose']['operator'] = 'field_hannon_winner_types_value_op';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['expose']['identifier'] = 'field_hannon_winner_types_value';
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_hannon_winner_types_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Field: Show? (field_school_show_student) */
  $handler->display->display_options['filters']['field_school_show_student_value']['id'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['filters']['field_school_show_student_value']['field'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_school_show_student_value']['value'] = array(
    0 => '0',
  );

  /* Display: Admin */
  $handler = $view->new_display('page', 'Admin', 'results');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    17 => '17',
  );
  $handler->display->display_options['path'] = 'admin/entityforms/hannon-photo';
  $handler->display->display_options['menu']['title'] = 'Hannon Photo Contest';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Front */
  $handler = $view->new_display('page', 'Front', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hannon Photo Contest Results';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    17 => '17',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Enter # of Items to Skip';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1 class="nys-article-title">Photo Contest Submissions</h1>';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['path'] = 'hannon/photo-contest-submissions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Hannon Photo Contest';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    17 => '17',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityform Submission: Attach your photo (field_hannon_photo_upload:fid) */
  $handler->display->display_options['relationships']['field_hannon_photo_upload_fid']['id'] = 'field_hannon_photo_upload_fid';
  $handler->display->display_options['relationships']['field_hannon_photo_upload_fid']['table'] = 'field_data_field_hannon_photo_upload';
  $handler->display->display_options['relationships']['field_hannon_photo_upload_fid']['field'] = 'field_hannon_photo_upload_fid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform Submission: Last Name */
  $handler->display->display_options['fields']['field_hannon_last_name']['id'] = 'field_hannon_last_name';
  $handler->display->display_options['fields']['field_hannon_last_name']['table'] = 'field_data_field_hannon_last_name';
  $handler->display->display_options['fields']['field_hannon_last_name']['field'] = 'field_hannon_last_name';
  $handler->display->display_options['fields']['field_hannon_last_name']['alter']['text'] = '[field_hannon_first_name] [field_hannon_last_name]';
  /* Field: Entityform Submission: First Name */
  $handler->display->display_options['fields']['field_hannon_first_name']['id'] = 'field_hannon_first_name';
  $handler->display->display_options['fields']['field_hannon_first_name']['table'] = 'field_data_field_hannon_first_name';
  $handler->display->display_options['fields']['field_hannon_first_name']['field'] = 'field_hannon_first_name';
  /* Field: Entityform Submission: School */
  $handler->display->display_options['fields']['field_hannon_school_name']['id'] = 'field_hannon_school_name';
  $handler->display->display_options['fields']['field_hannon_school_name']['table'] = 'field_data_field_hannon_school_name';
  $handler->display->display_options['fields']['field_hannon_school_name']['field'] = 'field_hannon_school_name';
  $handler->display->display_options['fields']['field_hannon_school_name']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Entityform Submission: Street Address */
  $handler->display->display_options['fields']['field_hannon_street_address']['id'] = 'field_hannon_street_address';
  $handler->display->display_options['fields']['field_hannon_street_address']['table'] = 'field_data_field_hannon_street_address';
  $handler->display->display_options['fields']['field_hannon_street_address']['field'] = 'field_hannon_street_address';
  $handler->display->display_options['fields']['field_hannon_street_address']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: City */
  $handler->display->display_options['fields']['field_hannon_city']['id'] = 'field_hannon_city';
  $handler->display->display_options['fields']['field_hannon_city']['table'] = 'field_data_field_hannon_city';
  $handler->display->display_options['fields']['field_hannon_city']['field'] = 'field_hannon_city';
  $handler->display->display_options['fields']['field_hannon_city']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'State';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'NY';
  /* Field: Entityform Submission: Zip Code */
  $handler->display->display_options['fields']['field_hannon_zip_code']['id'] = 'field_hannon_zip_code';
  $handler->display->display_options['fields']['field_hannon_zip_code']['table'] = 'field_data_field_hannon_zip_code';
  $handler->display->display_options['fields']['field_hannon_zip_code']['field'] = 'field_hannon_zip_code';
  $handler->display->display_options['fields']['field_hannon_zip_code']['alter']['text'] = '[field_hannon_street_address]<br>
[field_hannon_city], NY [field_hannon_zip_code]';
  $handler->display->display_options['fields']['field_hannon_zip_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hannon_zip_code']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Entityform Submission: Teacher's Email */
  $handler->display->display_options['fields']['field_school_teachers_email']['id'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['table'] = 'field_data_field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['field'] = 'field_school_teachers_email';
  $handler->display->display_options['fields']['field_school_teachers_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_school_teachers_email']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Phone Number */
  $handler->display->display_options['fields']['field_hannon_phone_num']['id'] = 'field_hannon_phone_num';
  $handler->display->display_options['fields']['field_hannon_phone_num']['table'] = 'field_data_field_hannon_phone_num';
  $handler->display->display_options['fields']['field_hannon_phone_num']['field'] = 'field_hannon_phone_num';
  $handler->display->display_options['fields']['field_hannon_phone_num']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_hannon_phone_num']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Category */
  $handler->display->display_options['fields']['field_hannon_category']['id'] = 'field_hannon_category';
  $handler->display->display_options['fields']['field_hannon_category']['table'] = 'field_data_field_hannon_category';
  $handler->display->display_options['fields']['field_hannon_category']['field'] = 'field_hannon_category';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_hannon_photo_upload_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'Link to File';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Entityform Submission: Winner Types */
  $handler->display->display_options['fields']['field_hannon_winner_types']['id'] = 'field_hannon_winner_types';
  $handler->display->display_options['fields']['field_hannon_winner_types']['table'] = 'field_data_field_hannon_winner_types';
  $handler->display->display_options['fields']['field_hannon_winner_types']['field'] = 'field_hannon_winner_types';
  $handler->display->display_options['fields']['field_hannon_winner_types']['label'] = 'Winner Status';
  $handler->display->display_options['fields']['field_hannon_winner_types']['alter']['text'] = '[field_hannon_winner]<br>
[field_hannon_winner_types]
';
  $handler->display->display_options['path'] = 'hannon-photo-export.csv';
  $handler->display->display_options['displays'] = array(
    'results' => 'results',
    'page_1' => 'page_1',
    'default' => 0,
  );
  $export['student_hannon_photo_contest'] = $view;

  $view = new view();
  $view->name = 'student_leadership_award';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Student Leadership Award';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Student Leadership Award Submissions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    17 => '17',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_senator' => 'field_school',
    'field_district' => 'field_school',
    'field_student_name' => 'field_student_name',
    'field_student_grade' => 'field_student_name',
    'field_cumulatve_gpa' => 'field_student_name',
    'field_student_address' => 'field_student_name',
    'field_student_email' => 'field_student_name',
    'field_student_phone_number' => 'field_student_name',
    'field_nominators_name' => 'field_nominators_name',
    'field_nominators_email' => 'field_nominators_name',
    'field_nominators_phone_number_1' => 'field_nominators_name',
    'field_nominators_title' => 'field_nominators_name',
    'field_category_being_nominated_f' => 'field_category_being_nominated_f',
    'field_attach_letter_of_recommend' => 'field_attach_letter_of_recommend',
    'field_attach_statement_from_stud' => 'field_attach_letter_of_recommend',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_senator' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_district' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_student_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_student_grade' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cumulatve_gpa' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_student_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_student_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_student_phone_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nominators_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_nominators_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nominators_phone_number_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nominators_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_category_being_nominated_f' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attach_letter_of_recommend' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_attach_statement_from_stud' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_target_id']['id'] = 'field_school_target_id';
  $handler->display->display_options['relationships']['field_school_target_id']['table'] = 'field_data_field_school';
  $handler->display->display_options['relationships']['field_school_target_id']['field'] = 'field_school_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['relationships']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['relationship'] = 'field_school_target_id';
  /* Field: Entityform Submission: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Field: Senate District */
  $handler->display->display_options['fields']['field_district']['id'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['table'] = 'field_data_field_district';
  $handler->display->display_options['fields']['field_district']['field'] = 'field_district';
  $handler->display->display_options['fields']['field_district']['relationship'] = 'field_school_target_id';
  $handler->display->display_options['fields']['field_district']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Entityform Submission: Student Name */
  $handler->display->display_options['fields']['field_student_name']['id'] = 'field_student_name';
  $handler->display->display_options['fields']['field_student_name']['table'] = 'field_data_field_student_name';
  $handler->display->display_options['fields']['field_student_name']['field'] = 'field_student_name';
  $handler->display->display_options['fields']['field_student_name']['label'] = 'Student Information';
  /* Field: Entityform Submission: Student Grade */
  $handler->display->display_options['fields']['field_student_grade']['id'] = 'field_student_grade';
  $handler->display->display_options['fields']['field_student_grade']['table'] = 'field_data_field_student_grade';
  $handler->display->display_options['fields']['field_student_grade']['field'] = 'field_student_grade';
  /* Field: Entityform Submission: Cumulative GPA */
  $handler->display->display_options['fields']['field_cumulatve_gpa']['id'] = 'field_cumulatve_gpa';
  $handler->display->display_options['fields']['field_cumulatve_gpa']['table'] = 'field_data_field_cumulatve_gpa';
  $handler->display->display_options['fields']['field_cumulatve_gpa']['field'] = 'field_cumulatve_gpa';
  $handler->display->display_options['fields']['field_cumulatve_gpa']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cumulatve_gpa']['alter']['text'] = '<strong>GPA:</strong> [field_cumulatve_gpa-value]';
  /* Field: Entityform Submission: Student Address */
  $handler->display->display_options['fields']['field_student_address']['id'] = 'field_student_address';
  $handler->display->display_options['fields']['field_student_address']['table'] = 'field_data_field_student_address';
  $handler->display->display_options['fields']['field_student_address']['field'] = 'field_student_address';
  /* Field: Entityform Submission: Student Email */
  $handler->display->display_options['fields']['field_student_email']['id'] = 'field_student_email';
  $handler->display->display_options['fields']['field_student_email']['table'] = 'field_data_field_student_email';
  $handler->display->display_options['fields']['field_student_email']['field'] = 'field_student_email';
  /* Field: Entityform Submission: Student Phone Number */
  $handler->display->display_options['fields']['field_student_phone_number']['id'] = 'field_student_phone_number';
  $handler->display->display_options['fields']['field_student_phone_number']['table'] = 'field_data_field_student_phone_number';
  $handler->display->display_options['fields']['field_student_phone_number']['field'] = 'field_student_phone_number';
  /* Field: Entityform Submission: Nominator's Name */
  $handler->display->display_options['fields']['field_nominators_name']['id'] = 'field_nominators_name';
  $handler->display->display_options['fields']['field_nominators_name']['table'] = 'field_data_field_nominators_name';
  $handler->display->display_options['fields']['field_nominators_name']['field'] = 'field_nominators_name';
  $handler->display->display_options['fields']['field_nominators_name']['label'] = 'Nominator\'s Information';
  /* Field: Entityform Submission: Nominator's Title */
  $handler->display->display_options['fields']['field_nominators_title']['id'] = 'field_nominators_title';
  $handler->display->display_options['fields']['field_nominators_title']['table'] = 'field_data_field_nominators_title';
  $handler->display->display_options['fields']['field_nominators_title']['field'] = 'field_nominators_title';
  /* Field: Entityform Submission: Nominator's Email */
  $handler->display->display_options['fields']['field_nominators_email']['id'] = 'field_nominators_email';
  $handler->display->display_options['fields']['field_nominators_email']['table'] = 'field_data_field_nominators_email';
  $handler->display->display_options['fields']['field_nominators_email']['field'] = 'field_nominators_email';
  /* Field: Entityform Submission: Nominator's Phone Number */
  $handler->display->display_options['fields']['field_nominators_phone_number_1']['id'] = 'field_nominators_phone_number_1';
  $handler->display->display_options['fields']['field_nominators_phone_number_1']['table'] = 'field_data_field_nominators_phone_number';
  $handler->display->display_options['fields']['field_nominators_phone_number_1']['field'] = 'field_nominators_phone_number';
  /* Field: Entityform Submission: Category Being Nominated for */
  $handler->display->display_options['fields']['field_category_being_nominated_f']['id'] = 'field_category_being_nominated_f';
  $handler->display->display_options['fields']['field_category_being_nominated_f']['table'] = 'field_data_field_category_being_nominated_f';
  $handler->display->display_options['fields']['field_category_being_nominated_f']['field'] = 'field_category_being_nominated_f';
  /* Field: Entityform Submission: Attach Letter of Recommendation */
  $handler->display->display_options['fields']['field_attach_letter_of_recommend']['id'] = 'field_attach_letter_of_recommend';
  $handler->display->display_options['fields']['field_attach_letter_of_recommend']['table'] = 'field_data_field_attach_letter_of_recommend';
  $handler->display->display_options['fields']['field_attach_letter_of_recommend']['field'] = 'field_attach_letter_of_recommend';
  $handler->display->display_options['fields']['field_attach_letter_of_recommend']['label'] = 'Attachments';
  $handler->display->display_options['fields']['field_attach_letter_of_recommend']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_attach_letter_of_recommend']['alter']['text'] = '<strong>Letter of Recommendation:</strong><br>
[field_attach_letter_of_recommend]
';
  $handler->display->display_options['fields']['field_attach_letter_of_recommend']['click_sort_column'] = 'fid';
  /* Field: Entityform Submission: Attach statement from student about an accomplishment they’ve had and why it is important */
  $handler->display->display_options['fields']['field_attach_statement_from_stud']['id'] = 'field_attach_statement_from_stud';
  $handler->display->display_options['fields']['field_attach_statement_from_stud']['table'] = 'field_data_field_attach_statement_from_stud';
  $handler->display->display_options['fields']['field_attach_statement_from_stud']['field'] = 'field_attach_statement_from_stud';
  $handler->display->display_options['fields']['field_attach_statement_from_stud']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_attach_statement_from_stud']['alter']['text'] = '<strong>Student Statement:</strong><br>
[field_attach_statement_from_stud] ';
  $handler->display->display_options['fields']['field_attach_statement_from_stud']['click_sort_column'] = 'fid';
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'new_york_senate_youth_leadership' => 'new_york_senate_youth_leadership',
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filter criterion: Content: School Legal Name (field_school_legal_name) */
  $handler->display->display_options['filters']['field_school_legal_name_value']['id'] = 'field_school_legal_name_value';
  $handler->display->display_options['filters']['field_school_legal_name_value']['table'] = 'field_data_field_school_legal_name';
  $handler->display->display_options['filters']['field_school_legal_name_value']['field'] = 'field_school_legal_name_value';
  $handler->display->display_options['filters']['field_school_legal_name_value']['relationship'] = 'field_school_target_id';
  $handler->display->display_options['filters']['field_school_legal_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_school_legal_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['operator_id'] = 'field_school_legal_name_value_op';
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['label'] = 'School Name';
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['description'] = 'Enter any part of school name';
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['operator'] = 'field_school_legal_name_value_op';
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['identifier'] = 'field_school_legal_name_value';
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_school_legal_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Entityform Submission: Category Being Nominated for (field_category_being_nominated_f) */
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['id'] = 'field_category_being_nominated_f_value';
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['table'] = 'field_data_field_category_being_nominated_f';
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['field'] = 'field_category_being_nominated_f_value';
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['expose']['operator_id'] = 'field_category_being_nominated_f_value_op';
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['expose']['label'] = 'Category Being Nominated for';
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['expose']['operator'] = 'field_category_being_nominated_f_value_op';
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['expose']['identifier'] = 'field_category_being_nominated_f_value';
  $handler->display->display_options['filters']['field_category_being_nominated_f_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );

  /* Display: Student Leadership Submissions */
  $handler = $view->new_display('page', 'Student Leadership Submissions', 'page');
  $handler->display->display_options['path'] = 'admin/entityforms/student-leadership-award';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Student Leadership';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['student_leadership_award'] = $view;

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

  /* Display: Hannon D6 HS */
  $handler = $view->new_display('entityreference', 'Hannon D6 HS', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    3 => 'OR',
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
    'school' => 'school',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_3']['id'] = 'title_3';
  $handler->display->display_options['filters']['title_3']['table'] = 'node';
  $handler->display->display_options['filters']['title_3']['field'] = 'title';
  $handler->display->display_options['filters']['title_3']['operator'] = 'not';
  $handler->display->display_options['filters']['title_3']['value'] = 'Hebrew Academy Of Nassau';
  $handler->display->display_options['filters']['title_3']['group'] = 1;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['id'] = 'field_school_grade_organization_value_1';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['value'] = 'K-12 School';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['group'] = 3;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value']['id'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['value'] = 'Senior High';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['group'] = 3;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['id'] = 'field_school_grade_organization_value_2';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['value'] = 'Junior Senior School';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['group'] = 3;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_6']['id'] = 'title_6';
  $handler->display->display_options['filters']['title_6']['table'] = 'node';
  $handler->display->display_options['filters']['title_6']['field'] = 'title';
  $handler->display->display_options['filters']['title_6']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_6']['value'] = 'Chaminade High';
  $handler->display->display_options['filters']['title_6']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_8']['id'] = 'title_8';
  $handler->display->display_options['filters']['title_8']['table'] = 'node';
  $handler->display->display_options['filters']['title_8']['field'] = 'title';
  $handler->display->display_options['filters']['title_8']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_8']['value'] = 'Wantagh Senior High School';
  $handler->display->display_options['filters']['title_8']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_4']['id'] = 'title_4';
  $handler->display->display_options['filters']['title_4']['table'] = 'node';
  $handler->display->display_options['filters']['title_4']['field'] = 'title';
  $handler->display->display_options['filters']['title_4']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_4']['value'] = 'Plainview-Old Bethpage/JFK';
  $handler->display->display_options['filters']['title_4']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_7']['id'] = 'title_7';
  $handler->display->display_options['filters']['title_7']['table'] = 'node';
  $handler->display->display_options['filters']['title_7']['field'] = 'title';
  $handler->display->display_options['filters']['title_7']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_7']['value'] = 'Farmingdale High';
  $handler->display->display_options['filters']['title_7']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['value'] = 'Our Lady of Mercy Academy';
  $handler->display->display_options['filters']['title_1']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_2']['id'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['table'] = 'node';
  $handler->display->display_options['filters']['title_2']['field'] = 'title';
  $handler->display->display_options['filters']['title_2']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_2']['value'] = 'Holy Trinity Diocesan High School';
  $handler->display->display_options['filters']['title_2']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['value'] = 'Regis High School';
  $handler->display->display_options['filters']['title']['group'] = 2;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_5']['id'] = 'title_5';
  $handler->display->display_options['filters']['title_5']['table'] = 'node';
  $handler->display->display_options['filters']['title_5']['field'] = 'title';
  $handler->display->display_options['filters']['title_5']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_5']['value'] = 'Bethpage Senior';
  $handler->display->display_options['filters']['title_5']['group'] = 2;
  /* Filter criterion: Field: Senate District (field_district) */
  $handler->display->display_options['filters']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['filters']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['filters']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['filters']['field_district_target_id']['value'] = array(
    6291 => '6291',
  );
  $handler->display->display_options['filters']['field_district_target_id']['group'] = 2;

  /* Display: K-8 */
  $handler = $view->new_display('entityreference', 'K-8', 'entityreference_3');
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
    'school' => 'school',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['id'] = 'field_school_grade_organization_value_2';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['value'] = 'Junior High';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['group'] = 2;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['id'] = 'field_school_grade_organization_value_1';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['value'] = 'Middle School';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['group'] = 2;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_4']['id'] = 'field_school_grade_organization_value_4';
  $handler->display->display_options['filters']['field_school_grade_organization_value_4']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_4']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_4']['value'] = 'K-12 School';
  $handler->display->display_options['filters']['field_school_grade_organization_value_4']['group'] = 2;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value']['id'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['value'] = 'Elementary';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['group'] = 2;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_3']['id'] = 'field_school_grade_organization_value_3';
  $handler->display->display_options['filters']['field_school_grade_organization_value_3']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_3']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_3']['value'] = 'K-12';
  $handler->display->display_options['filters']['field_school_grade_organization_value_3']['group'] = 2;

  /* Display: All HS */
  $handler = $view->new_display('entityreference', 'All HS', 'entityreference_4');
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
    'school' => 'school',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['id'] = 'field_school_grade_organization_value_2';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['value'] = 'K-12 School';
  $handler->display->display_options['filters']['field_school_grade_organization_value_2']['group'] = 2;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value']['id'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['value'] = 'Senior High';
  $handler->display->display_options['filters']['field_school_grade_organization_value']['group'] = 2;
  /* Filter criterion: Content: Grade Organization (field_school_grade_organization) */
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['id'] = 'field_school_grade_organization_value_1';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['table'] = 'field_data_field_school_grade_organization';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['field'] = 'field_school_grade_organization_value';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['value'] = 'Junior Senior School';
  $handler->display->display_options['filters']['field_school_grade_organization_value_1']['group'] = 2;
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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_school_name_target_id']['id'] = 'field_school_name_target_id';
  $handler->display->display_options['relationships']['field_school_name_target_id']['table'] = 'field_data_field_school_name';
  $handler->display->display_options['relationships']['field_school_name_target_id']['field'] = 'field_school_name_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_district_target_id']['id'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['table'] = 'field_data_field_district';
  $handler->display->display_options['relationships']['field_district_target_id']['field'] = 'field_district_target_id';
  $handler->display->display_options['relationships']['field_district_target_id']['relationship'] = 'field_school_name_target_id';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
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
  /* Relationship: Entityform Submission: Student Submissions (field_school_student_submissions) */
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['id'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['table'] = 'field_data_field_school_student_submissions';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['field'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: School Legal Name */
  $handler->display->display_options['fields']['field_school_legal_name']['id'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['table'] = 'field_data_field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['field'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_legal_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_legal_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_legal_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Content: School Address */
  $handler->display->display_options['fields']['field_school_address']['id'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['table'] = 'field_data_field_school_address';
  $handler->display->display_options['fields']['field_school_address']['field'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_address']['label'] = '';
  $handler->display->display_options['fields']['field_school_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_address']['element_label_colon'] = FALSE;
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
  /* Field: Field collection item: Student's Full Name */
  $handler->display->display_options['fields']['field_school_student_full_name']['id'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['field'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'senators/%/thankful';

  /* Display: Thankful Block */
  $handler = $view->new_display('block', 'Thankful Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<br><p>Sincerely,<br><br>

[field_senator]</p><br>
<h2>2017 Submissions</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
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
  /* Relationship: Entityform Submission: Student Submissions (field_school_student_submissions) */
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['id'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['table'] = 'field_data_field_school_student_submissions';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['field'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['label'] = 'field collection items';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['delta'] = '-1';
  /* Relationship: Field collection item: Attach your submission (field_school_submission_upload:fid) */
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['id'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['field'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: School Legal Name */
  $handler->display->display_options['fields']['field_school_legal_name']['id'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['table'] = 'field_data_field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['field'] = 'field_school_legal_name';
  $handler->display->display_options['fields']['field_school_legal_name']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_legal_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_legal_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_legal_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_student_full_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_student_full_name']['alter']['text'] = '<a href="[field_school_submission_upload]">[field_school_student_full_name]</a><em> [field_school_submission_type]</em><span> ([extension])</span>';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: School Legal Name (field_school_legal_name) */
  $handler->display->display_options['sorts']['field_school_legal_name_value']['id'] = 'field_school_legal_name_value';
  $handler->display->display_options['sorts']['field_school_legal_name_value']['table'] = 'field_data_field_school_legal_name';
  $handler->display->display_options['sorts']['field_school_legal_name_value']['field'] = 'field_school_legal_name_value';
  $handler->display->display_options['sorts']['field_school_legal_name_value']['relationship'] = 'field_school_name_target_id';
  /* Sort criterion: Entityform Submission: Grade (field_school_grade) */
  $handler->display->display_options['sorts']['field_school_grade_value']['id'] = 'field_school_grade_value';
  $handler->display->display_options['sorts']['field_school_grade_value']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['sorts']['field_school_grade_value']['field'] = 'field_school_grade_value';
  $handler->display->display_options['sorts']['field_school_grade_value']['allowed_values'] = '1';
  /* Sort criterion: Field collection item: Student&#039;s Full Name (field_school_student_full_name) */
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['id'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['field'] = 'field_school_student_full_name_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['relationship'] = 'field_school_student_submissions_value';
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
    'school_submissions' => 'school_submissions',
  );
  /* Filter criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-08-01';
  /* Filter criterion: Field: Show? (field_school_show_student) */
  $handler->display->display_options['filters']['field_school_show_student_value']['id'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['filters']['field_school_show_student_value']['field'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_school_show_student_value']['value'] = array(
    0 => '0',
  );

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
  $handler->display->display_options['filters']['created']['operator'] = '<=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-12-31';
  /* Filter criterion: Field: Show? (field_school_show_student) */
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
  /* Field: Field: Senate District */
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
  $handler->display->display_options['filters']['created']['operator'] = '<=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-12-31';

  /* Display: Earth Day Archives */
  $handler = $view->new_display('block', 'Earth Day Archives', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archived Submissions';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'created_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
  );
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
  $handler->display->display_options['filters']['created']['operator'] = '<=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-12-31';
  /* Filter criterion: Field: Show? (field_school_show_student) */
  $handler->display->display_options['filters']['field_school_show_student_value']['id'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['filters']['field_school_show_student_value']['field'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_school_show_student_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Field collection item: Year (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['filters']['field_year_value']['value']['value'] = '2017';
  $handler->display->display_options['filters']['field_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator_id'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['label'] = 'Select Year';
  $handler->display->display_options['filters']['field_year_value']['expose']['description'] = 'Archive only goes back to 2017';
  $handler->display->display_options['filters']['field_year_value']['expose']['operator'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['identifier'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_year_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_year_value']['year_range'] = '-1:2017';

  /* Display: ED Past Winners */
  $handler = $view->new_display('block', 'ED Past Winners', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past Poster Winners';
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
  /* Field: Field collection item: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_year']['label'] = '';
  $handler->display->display_options['fields']['field_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_year']['alter']['text'] = '[field_year] Winner(s)';
  $handler->display->display_options['fields']['field_year']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'format_type' => 'year_only',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
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
  /* Field: Field: Senate District */
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
  $handler->display->display_options['filters']['created']['operator'] = '<=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-12-31';
  /* Filter criterion: Field collection item: Year (field_year) */
  $handler->display->display_options['filters']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['filters']['field_year_value']['value']['value'] = '2017';
  $handler->display->display_options['filters']['field_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_year_value']['expose']['operator_id'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['label'] = 'View by Year';
  $handler->display->display_options['filters']['field_year_value']['expose']['operator'] = 'field_year_value_op';
  $handler->display->display_options['filters']['field_year_value']['expose']['identifier'] = 'field_year_value';
  $handler->display->display_options['filters']['field_year_value']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['field_year_value']['granularity'] = 'year';
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
    'field_school_grade' => 'field_school_grade',
    'field_school_contact_name' => 'field_school_contact_email',
    'field_school_contact_email' => 'field_school_contact_email',
    'field_school_submission_upload' => 'field_school_submission_upload',
    'edit_entityform' => 'edit_entityform',
    'created' => 'created',
    'link_entityform' => 'edit_entityform',
    'title' => 'title',
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
    'field_school_contact_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_school_submission_upload' => array(
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
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'strong';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Teacher's Name */
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
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_field_collection_item';
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
  /* Field: Field: Show? */
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
  /* Filter criterion: Entityform Submission: Teacher&#039;s Name (field_school_contact_name) */
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
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Earth Day Submissions';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    17 => '17',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school_address' => 'field_school_address',
    'field_senator' => 'field_senator',
    'field_school_student_full_name' => 'field_school_student_full_name',
    'field_school_grade' => 'field_school_student_full_name',
    'field_school_contact_name' => 'field_school_student_full_name',
    'field_school_teachers_email' => 'field_school_student_full_name',
    'field_school_submission_upload' => 'field_school_submission_upload_1',
    'field_school_submission_upload_1' => 'field_school_submission_upload_1',
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
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_submission_upload_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_school_featured_entry' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'strong';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Teacher's Name */
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
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_field_collection_item';
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
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'field_school_stud_earthday_subm::field_school_featured_entry' => 'field_school_stud_earthday_subm::field_school_featured_entry',
          'field_school_stud_earthday_subm::field_school_show_student' => 'field_school_stud_earthday_subm::field_school_show_student',
          'field_school_stud_earthday_subm::field_year' => 'field_school_stud_earthday_subm::field_year',
        ),
      ),
    ),
  );
  /* Field: Field: Show? */
  $handler->display->display_options['fields']['field_school_show_student']['id'] = 'field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['field'] = 'field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['relationship'] = 'field_school_stud_earthday_subm_value';
  $handler->display->display_options['fields']['field_school_show_student']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_show_student']['alter']['text'] = 'Show status: [field_school_show_student]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['created']['value']['value'] = '2018-02-09';
  /* Filter criterion: Entityform Submission: Teacher&#039;s Name (field_school_contact_name) */
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
  $handler->display->display_options['path'] = 'admin/entityforms/earthday';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Earth Day Submissions';
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
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'strong';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Teacher's Name */
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
  /* Field: Field: Senate District */
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
  /* Filter criterion: Field: Show? (field_school_show_student) */
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

  /* Display: Thankful Submissions */
  $handler = $view->new_display('page', 'Thankful Submissions', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school_address' => 'field_school_address',
    'field_senator' => 'field_senator',
    'field_school_contact_name' => 'field_school_contact_email',
    'field_school_contact_email' => 'field_school_contact_email',
    'field_school_grade' => 'field_school_contact_email',
    'field_school_student_full_name' => 'field_school_submission_upload',
    'field_school_submission_type' => 'field_school_submission_upload',
    'field_school_submission_upload' => 'field_school_submission_upload',
    'edit_entityform' => 'edit_entityform',
    'created' => 'created',
    'link_entityform' => 'edit_entityform',
    'title' => 'title',
    'field_school_show_student' => 'field_school_submission_upload',
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
    'field_school_contact_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_contact_email' => array(
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
    'field_school_student_full_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school_submission_type' => array(
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
    'field_school_show_student' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
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
  /* Relationship: Entityform Submission: Student Submissions (field_school_student_submissions) */
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['id'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['table'] = 'field_data_field_school_student_submissions';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['field'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Entityform Submission: Teacher's Name */
  $handler->display->display_options['fields']['field_school_contact_name']['id'] = 'field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['table'] = 'field_data_field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['field'] = 'field_school_contact_name';
  $handler->display->display_options['fields']['field_school_contact_name']['label'] = '';
  $handler->display->display_options['fields']['field_school_contact_name']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Contact Email */
  $handler->display->display_options['fields']['field_school_contact_email']['id'] = 'field_school_contact_email';
  $handler->display->display_options['fields']['field_school_contact_email']['table'] = 'field_data_field_school_contact_email';
  $handler->display->display_options['fields']['field_school_contact_email']['field'] = 'field_school_contact_email';
  $handler->display->display_options['fields']['field_school_contact_email']['label'] = 'Contact Information';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['label'] = '';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Student's Full Name */
  $handler->display->display_options['fields']['field_school_student_full_name']['id'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['table'] = 'field_data_field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['field'] = 'field_school_student_full_name';
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['element_type'] = 'strong';
  /* Field: Field collection item: My submission could best be described as */
  $handler->display->display_options['fields']['field_school_submission_type']['id'] = 'field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['table'] = 'field_data_field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['field'] = 'field_school_submission_type';
  $handler->display->display_options['fields']['field_school_submission_type']['relationship'] = 'field_school_student_submissions_value';
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = 'Submission';
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_school_submission_upload']['settings'] = array(
    'file_view_mode' => 'teaser',
  );
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
  /* Field: Field: Show? */
  $handler->display->display_options['fields']['field_school_show_student']['id'] = 'field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['field'] = 'field_school_show_student';
  $handler->display->display_options['fields']['field_school_show_student']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_show_student']['label'] = '';
  $handler->display->display_options['fields']['field_school_show_student']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_school_show_student']['alter']['text'] = 'Show status: [field_school_show_student]';
  $handler->display->display_options['fields']['field_school_show_student']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: Field collection item */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_field_collection_item';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Filter duplicates';
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
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'field_school_student_submissions::field_school_show_student' => 'field_school_student_submissions::field_school_show_student',
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_school_student_full_name_value']['expose']['label'] = 'Student Name';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school_submissions' => 'school_submissions',
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
  /* Filter criterion: Entityform Submission: Teacher&#039;s Name (field_school_contact_name) */
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
  $handler->display->display_options['path'] = 'admin/entityforms/thanksgiving';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Thanksgiving Submissions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export Tksgiving */
  $handler = $view->new_display('views_data_export', 'Data export Tksgiving', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
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
  /* Relationship: Entityform Submission: Student Submissions (field_school_student_submissions) */
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['id'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['table'] = 'field_data_field_school_student_submissions';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['field'] = 'field_school_student_submissions_value';
  $handler->display->display_options['relationships']['field_school_student_submissions_value']['delta'] = '-1';
  /* Relationship: Field collection item: Attach your submission (field_school_submission_upload:fid) */
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['id'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['field'] = 'field_school_submission_upload_fid';
  $handler->display->display_options['relationships']['field_school_submission_upload_fid']['relationship'] = 'field_school_student_submissions_value';
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
  $handler->display->display_options['fields']['field_school_student_full_name']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_student_full_name']['label'] = 'Student\'s Name';
  /* Field: Entityform Submission: Grade */
  $handler->display->display_options['fields']['field_school_grade']['id'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['table'] = 'field_data_field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['field'] = 'field_school_grade';
  $handler->display->display_options['fields']['field_school_grade']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Teacher's Name */
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
  $handler->display->display_options['fields']['field_school_legal_name']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['province']['label'] = 'City, State';
  $handler->display->display_options['fields']['province']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['province']['alter']['text'] = '[city], NY';
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['postal_code']['label'] = 'Zip Code';
  $handler->display->display_options['fields']['postal_code']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Contact Email */
  $handler->display->display_options['fields']['field_school_contact_email']['id'] = 'field_school_contact_email';
  $handler->display->display_options['fields']['field_school_contact_email']['table'] = 'field_data_field_school_contact_email';
  $handler->display->display_options['fields']['field_school_contact_email']['field'] = 'field_school_contact_email';
  $handler->display->display_options['fields']['field_school_contact_email']['label'] = 'Email';
  /* Field: Content: Principal Phone Number */
  $handler->display->display_options['fields']['field_school_ceo_phone']['id'] = 'field_school_ceo_phone';
  $handler->display->display_options['fields']['field_school_ceo_phone']['table'] = 'field_data_field_school_ceo_phone';
  $handler->display->display_options['fields']['field_school_ceo_phone']['field'] = 'field_school_ceo_phone';
  $handler->display->display_options['fields']['field_school_ceo_phone']['relationship'] = 'field_school_name_target_id';
  $handler->display->display_options['fields']['field_school_ceo_phone']['label'] = 'School Phone';
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Taxonomy term: District Number */
  $handler->display->display_options['fields']['field_district_number']['id'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['table'] = 'field_data_field_district_number';
  $handler->display->display_options['fields']['field_district_number']['field'] = 'field_district_number';
  $handler->display->display_options['fields']['field_district_number']['relationship'] = 'field_district_target_id';
  $handler->display->display_options['fields']['field_district_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Attach your submission */
  $handler->display->display_options['fields']['field_school_submission_upload']['id'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['table'] = 'field_data_field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['field'] = 'field_school_submission_upload';
  $handler->display->display_options['fields']['field_school_submission_upload']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['fields']['field_school_submission_upload']['label'] = 'URL';
  $handler->display->display_options['fields']['field_school_submission_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_school_submission_upload']['type'] = 'file_url_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school_submissions' => 'school_submissions',
  );
  /* Filter criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '2017-08-01';
  /* Filter criterion: Field: Show? (field_school_show_student) */
  $handler->display->display_options['filters']['field_school_show_student_value']['id'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['table'] = 'field_data_field_school_show_student';
  $handler->display->display_options['filters']['field_school_show_student_value']['field'] = 'field_school_show_student_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['relationship'] = 'field_school_student_submissions_value';
  $handler->display->display_options['filters']['field_school_show_student_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_school_show_student_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'tksgiving-student-export.csv';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
  );
  $export['student_submissions_admin_lists'] = $view;

  return $export;
}
