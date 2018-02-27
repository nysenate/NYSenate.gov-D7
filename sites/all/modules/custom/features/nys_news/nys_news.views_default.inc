<?php
/**
 * @file
 * nys_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'issues';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Issues';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Issues';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_issue_target_id']['id'] = 'field_top_issue_target_id';
  $handler->display->display_options['relationships']['field_top_issue_target_id']['table'] = 'field_data_field_top_issue';
  $handler->display->display_options['relationships']['field_top_issue_target_id']['field'] = 'field_top_issue_target_id';
  $handler->display->display_options['relationships']['field_top_issue_target_id']['relationship'] = 'field_senator_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_top_issue_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
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
    'article' => 'article',
    'in_the_news' => 'in_the_news',
    'press_release' => 'press_release',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
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
  );
  $export['issues'] = $view;

  $view = new view();
  $view->name = 'issues_listings';
  $view->description = 'Used for various display of issue dispays for explorer page and other sections.';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Issues Listings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'tid' => array(
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'c-block--issue';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="c-block--explore-issues">
<a href="/explore-issues">Explore Issues</a>
</div>';
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
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'issues' => 'issues',
  );

  /* Display: News and Issues Listing */
  $handler = $view->new_display('block', 'News and Issues Listing', 'news_issues_listing');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3 class="nys-subtitle-title">Find and Follow Issues</h2>
<p class="c-explore-issues--descript">Find and follow the issues that matter to you, and see how they\'re being handled in the Senate. Send your senator messages by issue, and let them know you care.</p>
';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="c-block--explore-issues">
<a href="/explore-issues" title="explore issues">Explore Issues</a>
</div>';
  $handler->display->display_options['block_description'] = 'News and Issues Listing';

  /* Display: Meeting related Issues */
  $handler = $view->new_display('block', 'Meeting related Issues', 'meeting_issues');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'explore all issues';
  $handler->display->display_options['link_url'] = 'news-and-issues';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = ' <h3 class="nys-title">Related Issues</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Content using Issues */
  $handler->display->display_options['relationships']['reverse_field_issues_node']['id'] = 'reverse_field_issues_node';
  $handler->display->display_options['relationships']['reverse_field_issues_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_issues_node']['field'] = 'reverse_field_issues_node';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_issues_node';
  $handler->display->display_options['arguments']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['issues_listings'] = $view;

  $view = new view();
  $view->name = 'newsroom';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News and Issues';
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
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => 'c-press-release--img',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>There are no updates for this filter.</p>';
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
  $handler->display->display_options['fields']['field_image_main']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['alter']['text'] = '[field_image_main]';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committees' => 0,
    'districts' => 0,
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
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'press_release' => 'press_release',
  );

  /* Display: News and Issues All News Tab */
  $handler = $view->new_display('block', 'News and Issues All News Tab', 'all_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
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
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  /* Filter criterion: Content: Accessible Sitewide (field_accessible_sitewide) */
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['id'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['table'] = 'field_data_field_accessible_sitewide';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['field'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'News and Issues All News Tab';

  /* Display: News and Issues Press Releases */
  $handler = $view->new_display('block', 'News and Issues Press Releases', 'press_releases');
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
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => 'c-press-release--img',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  $handler->display->display_options['fields']['field_image_main']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['alter']['text'] = '[field_image_main]';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '200x125',
    'image_link' => 'content',
  );
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
    'press_release' => 'press_release',
  );
  /* Filter criterion: Content: Accessible Sitewide (field_accessible_sitewide) */
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['id'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['table'] = 'field_data_field_accessible_sitewide';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['field'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'News and Issues Press Releases Tab';

  /* Display: News and Issues Video */
  $handler = $view->new_display('block', 'News and Issues Video', 'featured_video');
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
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary-machine-name]/[term_node_tid-name] ';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-story-link';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['separator'] = '  ';
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committees' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Youtube Video */
  $handler->display->display_options['fields']['field_yt']['id'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['table'] = 'field_data_field_yt';
  $handler->display->display_options['fields']['field_yt']['field'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['label'] = '';
  $handler->display->display_options['fields']['field_yt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_yt']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_yt']['settings'] = array(
    'video_style' => 'normal',
  );
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
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  /* Filter criterion: Content: Is Featured (field_featured) */
  $handler->display->display_options['filters']['field_featured_value']['id'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['table'] = 'field_data_field_featured';
  $handler->display->display_options['filters']['field_featured_value']['field'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Accessible Sitewide (field_accessible_sitewide) */
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['id'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['table'] = 'field_data_field_accessible_sitewide';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['field'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'News and Issues Video';

  /* Display: News Block */
  $handler = $view->new_display('block', 'News Block', 'news_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  );
  /* Filter criterion: Content: Accessible Sitewide (field_accessible_sitewide) */
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['id'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['table'] = 'field_data_field_accessible_sitewide';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['field'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'News and Issues All News Tab';

  /* Display: Foil News Block */
  $handler = $view->new_display('block', 'Foil News Block', 'foil_news_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  );
  /* Filter criterion: Content: Accessible Sitewide (field_accessible_sitewide) */
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['id'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['table'] = 'field_data_field_accessible_sitewide';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['field'] = 'field_accessible_sitewide_value';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'News and Issues All News Tab';

  /* Display: Waste in NY Government */
  $handler = $view->new_display('block', 'Waste in NY Government', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Special view for Investigations and Gov\'t Ops waste blog';
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
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  $handler->display->display_options['fields']['field_image_main']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['alter']['text'] = '[field_image_main]';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
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
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    10042 => '10042',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'content_experiments';
  $handler->display->display_options['block_description'] = 'Waste Blog';

  /* Display: Letters to Agency Heads */
  $handler = $view->new_display('block', 'Letters to Agency Heads', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Special view for Investigations and Gov\'t Ops waste blog';
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
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_date' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  $handler->display->display_options['fields']['field_image_main']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['alter']['text'] = '[field_image_main]';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
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
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    10043 => '10043',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'content_experiments';
  $handler->display->display_options['block_description'] = 'Letters to agency heads';
  $export['newsroom'] = $view;

  $view = new view();
  $view->name = 'senator_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Senator Newsroom';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => 'c-press-release--img',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type' => array(
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
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['alter']['text'] = '[field_image_main]';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '360x200',
    'image_link' => 'content',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  /* Sort criterion: Content: Published on -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'press_release' => 'press_release',
  );

  /* Display: All News */
  $handler = $view->new_display('block', 'All News', 'all_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No news so far';
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
    'image_link' => 'file',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Hide from News Feed (field_hide_feed) */
  $handler->display->display_options['filters']['field_hide_feed_value']['id'] = 'field_hide_feed_value';
  $handler->display->display_options['filters']['field_hide_feed_value']['table'] = 'field_data_field_hide_feed';
  $handler->display->display_options['filters']['field_hide_feed_value']['field'] = 'field_hide_feed_value';
  $handler->display->display_options['filters']['field_hide_feed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_hide_feed_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Views: Views Exclude Previous */
  $handler->display->display_options['filters']['views_exclude_previous']['id'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['table'] = 'node';
  $handler->display->display_options['filters']['views_exclude_previous']['field'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['value'] = array(
    'node_load' => 'node_load',
  );
  $handler->display->display_options['block_description'] = 'Senator All News Tab';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Senator News';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'feed_1';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'path';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['creator_field'] = 'field_senator';
  $handler->display->display_options['row_options']['date_field'] = 'field_date';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['alter']['text'] = '[field_image_main]';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '360x200',
    'image_link' => 'content',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'committees' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'rfc822',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_senator_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_senator_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_senator_target_id']['validate_options']['types'] = array(
    'senator' => 'senator',
  );
  $handler->display->display_options['path'] = 'senators/%/newsroom/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'all_news' => 0,
    'press_releases' => 0,
    'featured_story' => 0,
    'page_1' => 0,
    'block_1' => 0,
    'media' => 0,
    'featured_video' => 0,
    'committee_featured_story' => 0,
    'committee_all_updates_tab' => 0,
    'senator_news_article_footer' => 0,
    'committee_events' => 0,
    'committee_all_updates' => 0,
    'committee_news' => 0,
    'senator_questionnaire_article_footer' => 0,
    'meeting_committee_news' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Press Releases */
  $handler = $view->new_display('block', 'Press Releases', 'press_releases');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No press releases so far';
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
    'press_release' => 'press_release',
  );
  $handler->display->display_options['block_description'] = 'Senator Press Releases Tab';

  /* Display: Featured Story */
  $handler = $view->new_display('block', 'Featured Story', 'featured_story');
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
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '380x215',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  /* Filter criterion: Content: Is Featured (field_featured) */
  $handler->display->display_options['filters']['field_featured_value']['id'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['table'] = 'field_data_field_featured';
  $handler->display->display_options['filters']['field_featured_value']['field'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Senator Featured Story';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'senators/%/newsroom';

  /* Display: Senator Home Newsroom */
  $handler = $view->new_display('block', 'Senator Home Newsroom', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['element_type'] = 'article';
  $handler->display->display_options['style_options']['row']['class'] = 'c-news-block';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => 'c-newsroom-name',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => 'c-newsroom-image',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type' => array(
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
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['alter']['text'] = '[field_image_main]';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '360x200',
    'image_link' => 'content',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  /* Field: Content: Youtube Video */
  $handler->display->display_options['fields']['field_yt']['id'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['table'] = 'field_data_field_yt';
  $handler->display->display_options['fields']['field_yt']['field'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['label'] = '';
  $handler->display->display_options['fields']['field_yt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_yt']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_yt']['type'] = 'video_embed_field_thumbnail';
  $handler->display->display_options['fields']['field_yt']['settings'] = array(
    'image_style' => '360x200',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  /* Filter criterion: Content: Hide from News Feed (field_hide_feed) */
  $handler->display->display_options['filters']['field_hide_feed_value']['id'] = 'field_hide_feed_value';
  $handler->display->display_options['filters']['field_hide_feed_value']['table'] = 'field_data_field_hide_feed';
  $handler->display->display_options['filters']['field_hide_feed_value']['field'] = 'field_hide_feed_value';
  $handler->display->display_options['filters']['field_hide_feed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_hide_feed_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Views: Views Exclude Previous */
  $handler->display->display_options['filters']['views_exclude_previous']['id'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['table'] = 'node';
  $handler->display->display_options['filters']['views_exclude_previous']['field'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['value'] = array(
    'node_load' => 'node_load',
  );

  /* Display: Media Inquiries */
  $handler = $view->new_display('block', 'Media Inquiries', 'media');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_media_inquiries' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_press_kit' => array(
      'element_type' => 'div',
      'class' => 'c-block--btn icon-before__presskit lgt-bg',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media Inquiries */
  $handler->display->display_options['fields']['field_media_inquiries']['id'] = 'field_media_inquiries';
  $handler->display->display_options['fields']['field_media_inquiries']['table'] = 'field_data_field_media_inquiries';
  $handler->display->display_options['fields']['field_media_inquiries']['field'] = 'field_media_inquiries';
  $handler->display->display_options['fields']['field_media_inquiries']['label'] = '';
  $handler->display->display_options['fields']['field_media_inquiries']['element_label_colon'] = FALSE;
  /* Field: Content: Press Kit */
  $handler->display->display_options['fields']['field_press_kit']['id'] = 'field_press_kit';
  $handler->display->display_options['fields']['field_press_kit']['table'] = 'field_data_field_press_kit';
  $handler->display->display_options['fields']['field_press_kit']['field'] = 'field_press_kit';
  $handler->display->display_options['fields']['field_press_kit']['label'] = '';
  $handler->display->display_options['fields']['field_press_kit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_kit']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_press_kit']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_press_kit']['settings'] = array(
    'file_view_mode' => 'default',
  );
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'senator' => 'senator',
  );

  /* Display: Featured Video */
  $handler = $view->new_display('block', 'Featured Video', 'featured_video');
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
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '360x200',
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary-machine-name]/[term_node_tid-name] ';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-story-link';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
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
  /* Field: Content: Youtube Video */
  $handler->display->display_options['fields']['field_yt']['id'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['table'] = 'field_data_field_yt';
  $handler->display->display_options['fields']['field_yt']['field'] = 'field_yt';
  $handler->display->display_options['fields']['field_yt']['label'] = '';
  $handler->display->display_options['fields']['field_yt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_yt']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_yt']['type'] = 'video_embed_field_thumbnail';
  $handler->display->display_options['fields']['field_yt']['settings'] = array(
    'image_style' => '360x200',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  /* Filter criterion: Content: Is Featured (field_featured) */
  $handler->display->display_options['filters']['field_featured_value']['id'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['table'] = 'field_data_field_featured';
  $handler->display->display_options['filters']['field_featured_value']['field'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Senator Featured Video';

  /* Display: Committee Featured Story */
  $handler = $view->new_display('block', 'Committee Featured Story', 'committee_featured_story');
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
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image Main */
  $handler->display->display_options['fields']['field_image_main']['id'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['table'] = 'field_data_field_image_main';
  $handler->display->display_options['fields']['field_image_main']['field'] = 'field_image_main';
  $handler->display->display_options['fields']['field_image_main']['label'] = '';
  $handler->display->display_options['fields']['field_image_main']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_main']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_main']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_main']['settings'] = array(
    'image_style' => '380x215',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  );
  /* Filter criterion: Content: Committee Featured (field_committee_featured) */
  $handler->display->display_options['filters']['field_committee_featured_value']['id'] = 'field_committee_featured_value';
  $handler->display->display_options['filters']['field_committee_featured_value']['table'] = 'field_data_field_committee_featured';
  $handler->display->display_options['filters']['field_committee_featured_value']['field'] = 'field_committee_featured_value';
  $handler->display->display_options['filters']['field_committee_featured_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Committee Featured Story';

  /* Display: Committee All Updates Tab */
  $handler = $view->new_display('block', 'Committee All Updates Tab', 'committee_all_updates_tab');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  /* Field: Field: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['label'] = '';
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'press_release' => 'press_release',
  );
  $handler->display->display_options['block_description'] = 'Committee All Updates Tab';

  /* Display: Senator News List on Article Footer */
  $handler = $view->new_display('block', 'Senator News List on Article Footer', 'senator_news_article_footer');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  /* Contextual filter: Field: Senator (field_senator) */
  $handler->display->display_options['arguments']['field_senator_target_id']['id'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['table'] = 'field_data_field_senator';
  $handler->display->display_options['arguments']['field_senator_target_id']['field'] = 'field_senator_target_id';
  $handler->display->display_options['arguments']['field_senator_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_senator_target_id']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  );
  /* Filter criterion: Views: Views Exclude Previous */
  $handler->display->display_options['filters']['views_exclude_previous']['id'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['table'] = 'node';
  $handler->display->display_options['filters']['views_exclude_previous']['field'] = 'views_exclude_previous';
  $handler->display->display_options['filters']['views_exclude_previous']['value'] = array(
    'node_load' => 'node_load',
  );
  $handler->display->display_options['block_description'] = 'Senator News List Article Footer';

  /* Display: Committee Events */
  $handler = $view->new_display('block', 'Committee Events', 'committee_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
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
    'image_link' => '',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'committees' => 'committees',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'meeting' => 'meeting',
    'public_hearing' => 'public_hearing',
  );
  $handler->display->display_options['block_description'] = 'Committee News';

  /* Display: Committee All Updates */
  $handler = $view->new_display('block', 'Committee All Updates', 'committee_all_updates');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
    'public_hearing' => 'public_hearing',
  );
  $handler->display->display_options['block_description'] = 'Committee News';

  /* Display: Committee News */
  $handler = $view->new_display('block', 'Committee News', 'committee_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  $handler->display->display_options['block_description'] = 'Committee News';

  /* Display: Senator News List on Questionnaire Footer */
  $handler = $view->new_display('block', 'Senator News List on Questionnaire Footer', 'senator_questionnaire_article_footer');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
    'image_link' => '',
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  /* Contextual filter: Field: Issues (field_issues) */
  $handler->display->display_options['arguments']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['arguments']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_issues_tid']['default_argument_options']['limit'] = TRUE;
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
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  );
  $handler->display->display_options['block_description'] = 'Senator News List Article Footer';

  /* Display: Meeting Committee News */
  $handler = $view->new_display('block', 'Meeting Committee News', 'meeting_committee_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More News';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'created' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
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
  $handler->display->display_options['header']['area']['content'] = '<div class="c-container--header">
<h3 class="c-container--title ">committee news</h3>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Published on */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
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
  $handler->display->display_options['block_description'] = 'Committee News';

  /* Display: Videos */
  $handler = $view->new_display('block', 'Videos', 'videos');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'See More Videos';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'field_article_type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'title' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => 'c-press-release--img',
    ),
    'term_node_tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'type' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No press releases so far';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committee_type' => 0,
    'committee' => 0,
    'conference' => 0,
    'districts' => 0,
    'event_types' => 0,
    'initiatives' => 0,
    'party' => 0,
    'source_publication' => 0,
    'tags' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
    'image_link' => 'content',
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
  $handler->display->display_options['block_description'] = 'Senator Press Releases Tab';
  $export['senator_news'] = $view;

  return $export;
}
