<?php
/**
 * @file
 * nys_homepage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_homepage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_hero';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Hero';
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
    'field_image_main' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_published' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'field_issues' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '  
  <!-- This is just the huge hero area for the landing page. -->
  <div class="l-header-region l-row l-row--hero c-hero">
    <?php echo _nyss_img(variable_get(\'hero_default_path\'), \'1280x510\', \'\'); ?>
    <div class="l-row l-row--main c-hero--tout">
      <!-- NOT LOGGED IN -->
      <p class="c-hero--welcome">The New York State Senate is here to serve all New Yorkers. You can <a href="/explore-issues">explore issues</a> that matter to you, see what our <a href="/senators-committees">Senators &amp; Committees</a> are working on, or learn about <a href="/about">Senate history</a> and <a href="/how-it-works">how it works</a>.</p>
    </div><!-- .l-row--main-->
  </div><!-- .l-row--hero -->';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'homepage_hero' => 'homepage_hero',
    'sitewide_footer_promotional_bann' => 0,
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  /* Field: Field: Homepage Hero Image */
  $handler->display->display_options['fields']['field_image_hero']['id'] = 'field_image_hero';
  $handler->display->display_options['fields']['field_image_hero']['table'] = 'field_data_field_image_hero';
  $handler->display->display_options['fields']['field_image_hero']['field'] = 'field_image_hero';
  $handler->display->display_options['fields']['field_image_hero']['label'] = '';
  $handler->display->display_options['fields']['field_image_hero']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_hero']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_hero']['settings'] = array(
    'image_style' => '1280x510',
    'image_link' => 'content',
  );
  /* Field: Content: Publish Date */
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
  /* Field: Content: uStream URL */
  $handler->display->display_options['fields']['field_ustream_url']['id'] = 'field_ustream_url';
  $handler->display->display_options['fields']['field_ustream_url']['table'] = 'field_data_field_ustream_url';
  $handler->display->display_options['fields']['field_ustream_url']['field'] = 'field_ustream_url';
  $handler->display->display_options['fields']['field_ustream_url']['label'] = '';
  $handler->display->display_options['fields']['field_ustream_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ustream_url']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ustream_url']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_ustream_url']['settings'] = array(
    'file_view_mode' => 'full',
  );
  /* Field: Content: Ustream URL */
  $handler->display->display_options['fields']['field_ustream']['id'] = 'field_ustream';
  $handler->display->display_options['fields']['field_ustream']['table'] = 'field_data_field_ustream';
  $handler->display->display_options['fields']['field_ustream']['field'] = 'field_ustream';
  $handler->display->display_options['fields']['field_ustream']['label'] = '';
  $handler->display->display_options['fields']['field_ustream']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ustream']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ustream']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_ustream']['settings'] = array(
    'file_view_mode' => 'full',
  );
  /* Field: Content: Session Calendar */
  $handler->display->display_options['fields']['field_session_calendars']['id'] = 'field_session_calendars';
  $handler->display->display_options['fields']['field_session_calendars']['table'] = 'field_data_field_session_calendars';
  $handler->display->display_options['fields']['field_session_calendars']['field'] = 'field_session_calendars';
  $handler->display->display_options['fields']['field_session_calendars']['label'] = '';
  $handler->display->display_options['fields']['field_session_calendars']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session_calendars']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_calendars']['delta_offset'] = '0';
  /* Field: Field collection item: Bill */
  $handler->display->display_options['fields']['field_ol_bill']['id'] = 'field_ol_bill';
  $handler->display->display_options['fields']['field_ol_bill']['table'] = 'field_data_field_ol_bill';
  $handler->display->display_options['fields']['field_ol_bill']['field'] = 'field_ol_bill';
  $handler->display->display_options['fields']['field_ol_bill']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['fields']['field_ol_bill']['label'] = '';
  $handler->display->display_options['fields']['field_ol_bill']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ol_bill']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_ol_bill']['settings'] = array(
    'view_mode' => 'token',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_ol_bill']['delta_limit'] = '5';
  $handler->display->display_options['fields']['field_ol_bill']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ol_bill']['multi_type'] = 'ul';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field collection item: Type (field_ol_type) */
  $handler->display->display_options['filters']['field_ol_type_value']['id'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['table'] = 'field_data_field_ol_type';
  $handler->display->display_options['filters']['field_ol_type_value']['field'] = 'field_ol_type_value';
  $handler->display->display_options['filters']['field_ol_type_value']['relationship'] = 'field_ol_cal_value';
  $handler->display->display_options['filters']['field_ol_type_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_ol_type_value']['value'] = array(
    'supplemental_calendar' => 'supplemental_calendar',
    'floor_calendar' => 'floor_calendar',
  );

  /* Display: Homepage Hero */
  $handler = $view->new_display('block', 'Homepage Hero', 'homepage_hero');
  $handler->display->display_options['block_caching'] = '-1';
  $export['homepage_hero'] = $view;

  $view = new view();
  $view->name = 'homepage_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage News';
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p>There are no updates for this filter.</p>';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
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
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic lgt-text';
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
  /* Field: Content: Published */
  $handler->display->display_options['fields']['field_published']['id'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['table'] = 'field_data_field_published';
  $handler->display->display_options['fields']['field_published']['field'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['label'] = '';
  $handler->display->display_options['fields']['field_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_published']['settings'] = array(
    'format_type' => 'news_date_format',
    'fromto' => 'both',
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
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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

  /* Display: Homepage Featured Story */
  $handler = $view->new_display('block', 'Homepage Featured Story', 'hp_featured_stories');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'c-event-featured-story';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3 class="c-title">Featured Story</h3>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'homepage_featured_story' => 'homepage_featured_story',
    'homepage_hero' => 0,
    'sitewide_footer_promotional_bann' => 0,
  );
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
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path'] = '[term_node_tid-vocabulary-machine-name]/[term_node_tid-name]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-story-link';
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'issues' => 'issues',
    'committees' => 0,
    'districts' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
  $handler->display->display_options['filters']['field_accessible_sitewide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Homepage Featured Story';

  /* Display: Homepage News and Updates */
  $handler = $view->new_display('block', 'Homepage News and Updates', 'hp_news_updates');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['style_options']['row']['class'] = 'c-news-block';
  $handler->display->display_options['style_options']['row']['striping_classes'] = 'u-odd u-even';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
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
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['label'] = 'Front-page News Queue';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'frontpage_news' => 'frontpage_news',
    'homepage_hero' => 0,
    'sitewide_footer_promotional_bann' => 0,
    'homepage_featured_story' => 0,
    'legislation_current_session' => 0,
  );
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
  $handler->display->display_options['fields']['term_node_tid']['alter']['link_class'] = 'c-press-release--topic lgt-text';
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
  /* Field: Content: Publish Date */
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
  $handler->display->display_options['fields']['field_yt']['settings'] = array(
    'video_style' => 'normal',
  );
  /* Field: Field: Senator */
  $handler->display->display_options['fields']['field_senator']['id'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['table'] = 'field_data_field_senator';
  $handler->display->display_options['fields']['field_senator']['field'] = 'field_senator';
  $handler->display->display_options['fields']['field_senator']['label'] = '';
  $handler->display->display_options['fields']['field_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_senator']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_senator']['settings'] = array(
    'view_mode' => 'senators_involved',
    'links' => 0,
  );
  /* Field: Content: Associated Senators */
  $handler->display->display_options['fields']['field_associated_senator']['id'] = 'field_associated_senator';
  $handler->display->display_options['fields']['field_associated_senator']['table'] = 'field_data_field_associated_senator';
  $handler->display->display_options['fields']['field_associated_senator']['field'] = 'field_associated_senator';
  $handler->display->display_options['fields']['field_associated_senator']['label'] = '';
  $handler->display->display_options['fields']['field_associated_senator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_associated_senator']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_associated_senator']['delta_offset'] = '0';
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
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Homepage News and Updates';
  $export['homepage_news'] = $view;

  return $export;
}
