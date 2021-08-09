<?php

/**
 * @file
 * nys_senators.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nys_senators_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'senator';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:senator:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'f2cb_homepage2';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'content' => NULL,
      'sidebar_right' => NULL,
      'footer_first' => NULL,
      'footer_middle' => NULL,
      'footer_last' => NULL,
      'top_content' => NULL,
      'middle_content' => NULL,
      'bottom_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'adcd58d3-e389-411c-827a-ee0a2277fd57';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:senator:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3bae6cb2-3cff-4012-8873-dad443fa4d08';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3bae6cb2-3cff-4012-8873-dad443fa4d08';
  $display->content['new-3bae6cb2-3cff-4012-8873-dad443fa4d08'] = $pane;
  $display->panels['content'][0] = 'new-3bae6cb2-3cff-4012-8873-dad443fa4d08';
  $pane = new stdClass();
  $pane->pid = 'new-3c0402ec-e48e-4a65-84a7-14a06fd1b65e';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_polls-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3c0402ec-e48e-4a65-84a7-14a06fd1b65e';
  $display->content['new-3c0402ec-e48e-4a65-84a7-14a06fd1b65e'] = $pane;
  $display->panels['content'][1] = 'new-3c0402ec-e48e-4a65-84a7-14a06fd1b65e';
  $pane = new stdClass();
  $pane->pid = 'new-38d2a312-8372-4266-a429-cf08489a3ba2';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_news-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '1',
    'fields_override' => array(
      'title' => 1,
      'field_image_main' => 1,
      'type' => 0,
      'field_date' => 1,
      'body' => 0,
      'field_issues' => 1,
    ),
    'context' => array(
      0 => 'panelizer',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '38d2a312-8372-4266-a429-cf08489a3ba2';
  $display->content['new-38d2a312-8372-4266-a429-cf08489a3ba2'] = $pane;
  $display->panels['content'][2] = 'new-38d2a312-8372-4266-a429-cf08489a3ba2';
  $pane = new stdClass();
  $pane->pid = 'new-009363c5-d97d-4c6b-8ba7-3f60dab8f1cf';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_legislation-featured_legis_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '009363c5-d97d-4c6b-8ba7-3f60dab8f1cf';
  $display->content['new-009363c5-d97d-4c6b-8ba7-3f60dab8f1cf'] = $pane;
  $display->panels['content'][3] = 'new-009363c5-d97d-4c6b-8ba7-3f60dab8f1cf';
  $pane = new stdClass();
  $pane->pid = 'new-4c903c50-c01a-457b-99ba-2778fd5dd554';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_news-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '4c903c50-c01a-457b-99ba-2778fd5dd554';
  $display->content['new-4c903c50-c01a-457b-99ba-2778fd5dd554'] = $pane;
  $display->panels['content'][4] = 'new-4c903c50-c01a-457b-99ba-2778fd5dd554';
  $pane = new stdClass();
  $pane->pid = 'new-8ae503b2-e51b-4e15-8d30-4a69ddddbfd7';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '1',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_2',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '8ae503b2-e51b-4e15-8d30-4a69ddddbfd7';
  $display->content['new-8ae503b2-e51b-4e15-8d30-4a69ddddbfd7'] = $pane;
  $display->panels['content'][5] = 'new-8ae503b2-e51b-4e15-8d30-4a69ddddbfd7';
  $pane = new stdClass();
  $pane->pid = 'new-b1ae60fb-62b6-49b2-8729-77c53e850581';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_events-home_events_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'b1ae60fb-62b6-49b2-8729-77c53e850581';
  $display->content['new-b1ae60fb-62b6-49b2-8729-77c53e850581'] = $pane;
  $display->panels['content'][6] = 'new-b1ae60fb-62b6-49b2-8729-77c53e850581';
  $pane = new stdClass();
  $pane->pid = 'new-db1c5cdd-34bf-4d64-a761-9fa4060ab076';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_utils-news_by_top_issue_output_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'db1c5cdd-34bf-4d64-a761-9fa4060ab076';
  $display->content['new-db1c5cdd-34bf-4d64-a761-9fa4060ab076'] = $pane;
  $display->panels['content'][7] = 'new-db1c5cdd-34bf-4d64-a761-9fa4060ab076';
  $pane = new stdClass();
  $pane->pid = 'new-3a0f114e-75e6-4c52-b736-c49980c65074';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '2',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_3',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '3a0f114e-75e6-4c52-b736-c49980c65074';
  $display->content['new-3a0f114e-75e6-4c52-b736-c49980c65074'] = $pane;
  $display->panels['content'][8] = 'new-3a0f114e-75e6-4c52-b736-c49980c65074';
  $pane = new stdClass();
  $pane->pid = 'new-3af18704-1022-436f-b778-554069e43f5e';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_legislation-featured_legis_list_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '3af18704-1022-436f-b778-554069e43f5e';
  $display->content['new-3af18704-1022-436f-b778-554069e43f5e'] = $pane;
  $display->panels['content'][9] = 'new-3af18704-1022-436f-b778-554069e43f5e';
  $pane = new stdClass();
  $pane->pid = 'new-fa75d6c7-3827-427b-b1e5-5a8cead831c3';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '9',
    'pager_id' => '0',
    'offset' => '3',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_footer',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'fa75d6c7-3827-427b-b1e5-5a8cead831c3';
  $display->content['new-fa75d6c7-3827-427b-b1e5-5a8cead831c3'] = $pane;
  $display->panels['content'][10] = 'new-fa75d6c7-3827-427b-b1e5-5a8cead831c3';
  $pane = new stdClass();
  $pane->pid = 'new-2a56fe67-7900-4b8a-8a54-59fe93d281ac';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'footer_first' => 'footer_first',
    ),
  );
  $pane->uuid = '2a56fe67-7900-4b8a-8a54-59fe93d281ac';
  $display->content['new-2a56fe67-7900-4b8a-8a54-59fe93d281ac'] = $pane;
  $display->panels['footer_first'][0] = 'new-2a56fe67-7900-4b8a-8a54-59fe93d281ac';
  $pane = new stdClass();
  $pane->pid = 'new-de3ff1d1-a2ed-4102-9b5c-2b949622a499';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-global-footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-site-footer',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'footer_first' => 'footer_first',
    ),
  );
  $pane->uuid = 'de3ff1d1-a2ed-4102-9b5c-2b949622a499';
  $display->content['new-de3ff1d1-a2ed-4102-9b5c-2b949622a499'] = $pane;
  $display->panels['footer_first'][1] = 'new-de3ff1d1-a2ed-4102-9b5c-2b949622a499';
  $pane = new stdClass();
  $pane->pid = 'new-cf87bc8a-5ce7-4980-b74d-bdd36e79451b';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_header_bar_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = 'cf87bc8a-5ce7-4980-b74d-bdd36e79451b';
  $display->content['new-cf87bc8a-5ce7-4980-b74d-bdd36e79451b'] = $pane;
  $display->panels['header'][0] = 'new-cf87bc8a-5ce7-4980-b74d-bdd36e79451b';
  $pane = new stdClass();
  $pane->pid = 'new-d479c30d-123b-4bd1-96ce-a9c3010cffde';
  $pane->panel = 'header';
  $pane->type = 'views';
  $pane->subtype = 'nys_senator_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = 'd479c30d-123b-4bd1-96ce-a9c3010cffde';
  $display->content['new-d479c30d-123b-4bd1-96ce-a9c3010cffde'] = $pane;
  $display->panels['header'][1] = 'new-d479c30d-123b-4bd1-96ce-a9c3010cffde';
  $pane = new stdClass();
  $pane->pid = 'new-de4c5fcd-9bd3-406f-887c-c7f2d64816df';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-microsite_nav_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = 'de4c5fcd-9bd3-406f-887c-c7f2d64816df';
  $display->content['new-de4c5fcd-9bd3-406f-887c-c7f2d64816df'] = $pane;
  $display->panels['header'][2] = 'new-de4c5fcd-9bd3-406f-887c-c7f2d64816df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:senator:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = TRUE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Display 2';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'senator';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:senator:display_2';
  $panelizer->css_id = '';
  $panelizer->css_class = 'senator-display2';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'f2cb_homepage2';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'content' => NULL,
      'footer_first' => NULL,
      'footer_middle' => NULL,
      'footer_last' => NULL,
      'sidebar_right' => NULL,
      'top' => NULL,
      'top_first' => NULL,
      'top_second' => NULL,
      'top_third' => NULL,
      'top_fourth' => NULL,
      'middle_small' => NULL,
      'middle_large' => NULL,
      'middle_first' => NULL,
      'middle_second' => NULL,
      'bottom_first' => NULL,
      'bottom_second' => NULL,
      'bottom_third' => NULL,
      'bottom_fourth' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '344661ea-68d4-4369-910f-98cb5fa46b0d';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:senator:display_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5d745b7e-ff45-4ed1-a93d-0e6c75c67a08';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_news-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'fields_override' => array(
      'title' => 1,
      'field_image_main' => 1,
      'type' => 0,
      'field_date' => 0,
      'body' => 1,
      'field_issues' => 1,
    ),
    'context' => array(
      0 => 'panelizer',
    ),
    'override_title' => 1,
    'override_title_text' => 'Featured Story - January 2018',
    'override_title_heading' => 'h3',
    'items_per_page' => '1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-block c-event-featured-story',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5d745b7e-ff45-4ed1-a93d-0e6c75c67a08';
  $display->content['new-5d745b7e-ff45-4ed1-a93d-0e6c75c67a08'] = $pane;
  $display->panels['content'][0] = 'new-5d745b7e-ff45-4ed1-a93d-0e6c75c67a08';
  $pane = new stdClass();
  $pane->pid = 'new-8066e9fd-362a-429c-818e-d858c24fce2f';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_news-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8066e9fd-362a-429c-818e-d858c24fce2f';
  $display->content['new-8066e9fd-362a-429c-818e-d858c24fce2f'] = $pane;
  $display->panels['content'][1] = 'new-8066e9fd-362a-429c-818e-d858c24fce2f';
  $pane = new stdClass();
  $pane->pid = 'new-d9765457-b01b-462b-a527-be229b54c62e';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_featured_legislation_main',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd9765457-b01b-462b-a527-be229b54c62e';
  $display->content['new-d9765457-b01b-462b-a527-be229b54c62e'] = $pane;
  $display->panels['content'][2] = 'new-d9765457-b01b-462b-a527-be229b54c62e';
  $pane = new stdClass();
  $pane->pid = 'new-bbac12d1-56d3-479b-87ef-1286bfc9962f';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_events-home_events_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
    'fields_override' => array(
      'field_date' => 1,
      'field_date_1' => 1,
      'title' => 1,
      'path' => 1,
      'additional' => 1,
      'city' => 1,
      'name' => 1,
      'postal_code' => 1,
      'province' => 1,
      'street' => 1,
      'name_1' => 1,
      'field_image_main' => 1,
      'field_date_2' => 1,
      'field_feature_image' => 1,
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'bbac12d1-56d3-479b-87ef-1286bfc9962f';
  $display->content['new-bbac12d1-56d3-479b-87ef-1286bfc9962f'] = $pane;
  $display->panels['content'][3] = 'new-bbac12d1-56d3-479b-87ef-1286bfc9962f';
  $pane = new stdClass();
  $pane->pid = 'new-2452c6e8-6475-47e9-b74e-4fb2f69b2394';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_utils-news_by_top_issue_output_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2452c6e8-6475-47e9-b74e-4fb2f69b2394';
  $display->content['new-2452c6e8-6475-47e9-b74e-4fb2f69b2394'] = $pane;
  $display->panels['content'][4] = 'new-2452c6e8-6475-47e9-b74e-4fb2f69b2394';
  $pane = new stdClass();
  $pane->pid = 'new-68d396e0-13d5-4119-ab96-3c1431cf0484';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '68d396e0-13d5-4119-ab96-3c1431cf0484';
  $display->content['new-68d396e0-13d5-4119-ab96-3c1431cf0484'] = $pane;
  $display->panels['footer_first'][0] = 'new-68d396e0-13d5-4119-ab96-3c1431cf0484';
  $pane = new stdClass();
  $pane->pid = 'new-8ffc82aa-fc64-49ec-ac2f-d2165128e9df';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-global-footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-site-footer',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8ffc82aa-fc64-49ec-ac2f-d2165128e9df';
  $display->content['new-8ffc82aa-fc64-49ec-ac2f-d2165128e9df'] = $pane;
  $display->panels['footer_first'][1] = 'new-8ffc82aa-fc64-49ec-ac2f-d2165128e9df';
  $pane = new stdClass();
  $pane->pid = 'new-d2997945-0220-4c07-91f4-4e065117d140';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_header_bar_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd2997945-0220-4c07-91f4-4e065117d140';
  $display->content['new-d2997945-0220-4c07-91f4-4e065117d140'] = $pane;
  $display->panels['header'][0] = 'new-d2997945-0220-4c07-91f4-4e065117d140';
  $pane = new stdClass();
  $pane->pid = 'new-52db9a07-625f-43c0-9c3b-e865b00bcd4b';
  $pane->panel = 'header';
  $pane->type = 'views_panes';
  $pane->subtype = 'nys_senator_hero-smblock';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '52db9a07-625f-43c0-9c3b-e865b00bcd4b';
  $display->content['new-52db9a07-625f-43c0-9c3b-e865b00bcd4b'] = $pane;
  $display->panels['header'][1] = 'new-52db9a07-625f-43c0-9c3b-e865b00bcd4b';
  $pane = new stdClass();
  $pane->pid = 'new-aa799708-e88d-45bb-9ceb-eb03304e651b';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-microsite_nav_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'aa799708-e88d-45bb-9ceb-eb03304e651b';
  $display->content['new-aa799708-e88d-45bb-9ceb-eb03304e651b'] = $pane;
  $display->panels['header'][2] = 'new-aa799708-e88d-45bb-9ceb-eb03304e651b';
  $pane = new stdClass();
  $pane->pid = 'new-54cfeab3-b624-48dd-97bc-e9c6945b9008';
  $pane->panel = 'hero';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Custom Services',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<ul class="c-block-services">
	<li class="c-block-services--1"><span class="icon-before__recruit-friends"><span class="icon-large">Constituent<br>
	Services</span></span></li>
	<li class="c-block-services--2"><span class="icon-before__petition"><span class="icon-large">Request A<br>
	Citation</span></span></li>
	<li class="c-block-services--3"><span class="icon-before__calendar-month"><span class="icon-large">Request A<br>MEETING</span></span></li>
</ul>
',
    'format' => 'source_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '54cfeab3-b624-48dd-97bc-e9c6945b9008';
  $display->content['new-54cfeab3-b624-48dd-97bc-e9c6945b9008'] = $pane;
  $display->panels['hero'][0] = 'new-54cfeab3-b624-48dd-97bc-e9c6945b9008';
  $pane = new stdClass();
  $pane->pid = 'new-5a0e1370-f62a-4e1e-87d3-e32af0ca1a84';
  $pane->panel = 'sidebar_right';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'vertical',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5a0e1370-f62a-4e1e-87d3-e32af0ca1a84';
  $display->content['new-5a0e1370-f62a-4e1e-87d3-e32af0ca1a84'] = $pane;
  $display->panels['sidebar_right'][0] = 'new-5a0e1370-f62a-4e1e-87d3-e32af0ca1a84';
  $pane = new stdClass();
  $pane->pid = 'new-643d0e37-32d3-44b4-b574-8fe36d5e6696';
  $pane->panel = 'sidebar_right';
  $pane->type = 'views';
  $pane->subtype = 'senator_polls';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'context' => array(
      0 => '',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'vertical',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '643d0e37-32d3-44b4-b574-8fe36d5e6696';
  $display->content['new-643d0e37-32d3-44b4-b574-8fe36d5e6696'] = $pane;
  $display->panels['sidebar_right'][1] = 'new-643d0e37-32d3-44b4-b574-8fe36d5e6696';
  $pane = new stdClass();
  $pane->pid = 'new-2cfdf5e0-8855-4094-8060-d3cf784363eb';
  $pane->panel = 'sidebar_right';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '1',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_2',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'vertical',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2cfdf5e0-8855-4094-8060-d3cf784363eb';
  $display->content['new-2cfdf5e0-8855-4094-8060-d3cf784363eb'] = $pane;
  $display->panels['sidebar_right'][2] = 'new-2cfdf5e0-8855-4094-8060-d3cf784363eb';
  $pane = new stdClass();
  $pane->pid = 'new-348540a3-998b-40b9-947f-69a35e6de082';
  $pane->panel = 'sidebar_right';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '2',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_3',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'vertical',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '348540a3-998b-40b9-947f-69a35e6de082';
  $display->content['new-348540a3-998b-40b9-947f-69a35e6de082'] = $pane;
  $display->panels['sidebar_right'][3] = 'new-348540a3-998b-40b9-947f-69a35e6de082';
  $pane = new stdClass();
  $pane->pid = 'new-7cf48f4a-4c4d-4f8e-b14b-8f5eced21827';
  $pane->panel = 'sidebar_right';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '9',
    'pager_id' => '0',
    'offset' => '3',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_footer',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'vertical',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7cf48f4a-4c4d-4f8e-b14b-8f5eced21827';
  $display->content['new-7cf48f4a-4c4d-4f8e-b14b-8f5eced21827'] = $pane;
  $display->panels['sidebar_right'][4] = 'new-7cf48f4a-4c4d-4f8e-b14b-8f5eced21827';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:senator:display_2'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = TRUE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Flexible';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'senator';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:senator:display_3';
  $panelizer->css_id = '';
  $panelizer->css_class = 'senator-home-flex';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'f2cb_homepage2';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'content' => NULL,
      'sidebar_right' => NULL,
      'footer_first' => NULL,
      'footer_middle' => NULL,
      'footer_last' => NULL,
      'top_content' => NULL,
      'middle_content' => NULL,
      'bottom_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'adcd58d3-e389-411c-827a-ee0a2277fd57';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:senator:display_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3c0402ec-e48e-4a65-84a7-14a06fd1b65e';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_polls-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3c0402ec-e48e-4a65-84a7-14a06fd1b65e';
  $display->content['new-3c0402ec-e48e-4a65-84a7-14a06fd1b65e'] = $pane;
  $display->panels['content'][0] = 'new-3c0402ec-e48e-4a65-84a7-14a06fd1b65e';
  $pane = new stdClass();
  $pane->pid = 'new-009363c5-d97d-4c6b-8ba7-3f60dab8f1cf';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_legislation-featured_legis_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '009363c5-d97d-4c6b-8ba7-3f60dab8f1cf';
  $display->content['new-009363c5-d97d-4c6b-8ba7-3f60dab8f1cf'] = $pane;
  $display->panels['content'][1] = 'new-009363c5-d97d-4c6b-8ba7-3f60dab8f1cf';
  $pane = new stdClass();
  $pane->pid = 'new-4c903c50-c01a-457b-99ba-2778fd5dd554';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_news-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4c903c50-c01a-457b-99ba-2778fd5dd554';
  $display->content['new-4c903c50-c01a-457b-99ba-2778fd5dd554'] = $pane;
  $display->panels['content'][2] = 'new-4c903c50-c01a-457b-99ba-2778fd5dd554';
  $pane = new stdClass();
  $pane->pid = 'new-b1ae60fb-62b6-49b2-8729-77c53e850581';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_events-home_events_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b1ae60fb-62b6-49b2-8729-77c53e850581';
  $display->content['new-b1ae60fb-62b6-49b2-8729-77c53e850581'] = $pane;
  $display->panels['content'][3] = 'new-b1ae60fb-62b6-49b2-8729-77c53e850581';
  $pane = new stdClass();
  $pane->pid = 'new-db1c5cdd-34bf-4d64-a761-9fa4060ab076';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_utils-news_by_top_issue_output_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'db1c5cdd-34bf-4d64-a761-9fa4060ab076';
  $display->content['new-db1c5cdd-34bf-4d64-a761-9fa4060ab076'] = $pane;
  $display->panels['content'][4] = 'new-db1c5cdd-34bf-4d64-a761-9fa4060ab076';
  $pane = new stdClass();
  $pane->pid = 'new-3af18704-1022-436f-b778-554069e43f5e';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_legislation-featured_legis_list_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '3af18704-1022-436f-b778-554069e43f5e';
  $display->content['new-3af18704-1022-436f-b778-554069e43f5e'] = $pane;
  $display->panels['content'][5] = 'new-3af18704-1022-436f-b778-554069e43f5e';
  $pane = new stdClass();
  $pane->pid = 'new-fa75d6c7-3827-427b-b1e5-5a8cead831c3';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '9',
    'pager_id' => '0',
    'offset' => '3',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_home_promo_footer',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'fa75d6c7-3827-427b-b1e5-5a8cead831c3';
  $display->content['new-fa75d6c7-3827-427b-b1e5-5a8cead831c3'] = $pane;
  $display->panels['content'][6] = 'new-fa75d6c7-3827-427b-b1e5-5a8cead831c3';
  $pane = new stdClass();
  $pane->pid = 'new-2a56fe67-7900-4b8a-8a54-59fe93d281ac';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'footer_first' => 'footer_first',
    ),
  );
  $pane->uuid = '2a56fe67-7900-4b8a-8a54-59fe93d281ac';
  $display->content['new-2a56fe67-7900-4b8a-8a54-59fe93d281ac'] = $pane;
  $display->panels['footer_first'][0] = 'new-2a56fe67-7900-4b8a-8a54-59fe93d281ac';
  $pane = new stdClass();
  $pane->pid = 'new-de3ff1d1-a2ed-4102-9b5c-2b949622a499';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-global-footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-site-footer',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'footer_first' => 'footer_first',
    ),
  );
  $pane->uuid = 'de3ff1d1-a2ed-4102-9b5c-2b949622a499';
  $display->content['new-de3ff1d1-a2ed-4102-9b5c-2b949622a499'] = $pane;
  $display->panels['footer_first'][1] = 'new-de3ff1d1-a2ed-4102-9b5c-2b949622a499';
  $pane = new stdClass();
  $pane->pid = 'new-cf87bc8a-5ce7-4980-b74d-bdd36e79451b';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_header_bar_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = 'cf87bc8a-5ce7-4980-b74d-bdd36e79451b';
  $display->content['new-cf87bc8a-5ce7-4980-b74d-bdd36e79451b'] = $pane;
  $display->panels['header'][0] = 'new-cf87bc8a-5ce7-4980-b74d-bdd36e79451b';
  $pane = new stdClass();
  $pane->pid = 'new-d479c30d-123b-4bd1-96ce-a9c3010cffde';
  $pane->panel = 'header';
  $pane->type = 'views';
  $pane->subtype = 'nys_senator_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = 'd479c30d-123b-4bd1-96ce-a9c3010cffde';
  $display->content['new-d479c30d-123b-4bd1-96ce-a9c3010cffde'] = $pane;
  $display->panels['header'][1] = 'new-d479c30d-123b-4bd1-96ce-a9c3010cffde';
  $pane = new stdClass();
  $pane->pid = 'new-de4c5fcd-9bd3-406f-887c-c7f2d64816df';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-microsite_nav_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array(
    'type' => 'immovable',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = 'de4c5fcd-9bd3-406f-887c-c7f2d64816df';
  $display->content['new-de4c5fcd-9bd3-406f-887c-c7f2d64816df'] = $pane;
  $display->panels['header'][2] = 'new-de4c5fcd-9bd3-406f-887c-c7f2d64816df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:senator:display_3'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Flexible Layout';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'senator';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:senator:flexible_layout';
  $panelizer->css_id = '';
  $panelizer->css_class = 'senator-home-flex';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'f2cb_homepage2';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'content' => NULL,
      'footer_first' => NULL,
      'footer_middle' => NULL,
      'footer_last' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7b713666-9440-4674-b875-1ad4934233df';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:senator:flexible_layout';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-26e3fbd1-9662-402c-8f9a-29cfb56b05c3';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_polls-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '26e3fbd1-9662-402c-8f9a-29cfb56b05c3';
  $display->content['new-26e3fbd1-9662-402c-8f9a-29cfb56b05c3'] = $pane;
  $display->panels['content'][0] = 'new-26e3fbd1-9662-402c-8f9a-29cfb56b05c3';
  $pane = new stdClass();
  $pane->pid = 'new-d24a55c7-9809-450b-b8a8-827dd6d1b9ab';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_news-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '1',
    'fields_override' => array(
      'title' => 1,
      'field_image_main' => 1,
      'type' => 0,
      'field_date' => 1,
      'body' => 1,
      'field_issues' => 1,
    ),
    'context' => array(
      0 => 'panelizer',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd24a55c7-9809-450b-b8a8-827dd6d1b9ab';
  $display->content['new-d24a55c7-9809-450b-b8a8-827dd6d1b9ab'] = $pane;
  $display->panels['content'][1] = 'new-d24a55c7-9809-450b-b8a8-827dd6d1b9ab';
  $pane = new stdClass();
  $pane->pid = 'new-07c9c531-88f8-4c2a-91d0-63ba4300a07f';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_legislation-featured_legis_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '07c9c531-88f8-4c2a-91d0-63ba4300a07f';
  $display->content['new-07c9c531-88f8-4c2a-91d0-63ba4300a07f'] = $pane;
  $display->panels['content'][2] = 'new-07c9c531-88f8-4c2a-91d0-63ba4300a07f';
  $pane = new stdClass();
  $pane->pid = 'new-4f7b1074-39bc-48aa-9d4d-5d09a712433c';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_news-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '4f7b1074-39bc-48aa-9d4d-5d09a712433c';
  $display->content['new-4f7b1074-39bc-48aa-9d4d-5d09a712433c'] = $pane;
  $display->panels['content'][3] = 'new-4f7b1074-39bc-48aa-9d4d-5d09a712433c';
  $pane = new stdClass();
  $pane->pid = 'new-3366055f-c96d-47c9-aab3-9de652248571';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_events-home_events_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '4',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '3366055f-c96d-47c9-aab3-9de652248571';
  $display->content['new-3366055f-c96d-47c9-aab3-9de652248571'] = $pane;
  $display->panels['content'][4] = 'new-3366055f-c96d-47c9-aab3-9de652248571';
  $pane = new stdClass();
  $pane->pid = 'new-8a50c808-9eb8-4d58-b86b-244fd37381a3';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_utils-news_by_top_issue_output_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '8a50c808-9eb8-4d58-b86b-244fd37381a3';
  $display->content['new-8a50c808-9eb8-4d58-b86b-244fd37381a3'] = $pane;
  $display->panels['content'][5] = 'new-8a50c808-9eb8-4d58-b86b-244fd37381a3';
  $pane = new stdClass();
  $pane->pid = 'new-e9c40b30-8d97-4aae-9b43-70863e32750b';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'senator_legislation-featured_legis_list_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'e9c40b30-8d97-4aae-9b43-70863e32750b';
  $display->content['new-e9c40b30-8d97-4aae-9b43-70863e32750b'] = $pane;
  $display->panels['content'][6] = 'new-e9c40b30-8d97-4aae-9b43-70863e32750b';
  $pane = new stdClass();
  $pane->pid = 'new-40ef6798-f6c1-4b47-936c-93fb71ddbdc6';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array(
    'type' => 'regions',
    'regions' => array(
      'footer_first' => 'footer_first',
    ),
  );
  $pane->uuid = '40ef6798-f6c1-4b47-936c-93fb71ddbdc6';
  $display->content['new-40ef6798-f6c1-4b47-936c-93fb71ddbdc6'] = $pane;
  $display->panels['footer_first'][0] = 'new-40ef6798-f6c1-4b47-936c-93fb71ddbdc6';
  $pane = new stdClass();
  $pane->pid = 'new-3cbbeddc-1877-4d7c-9499-86cdd322b9a6';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-global-footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-site-footer',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array(
    'type' => 'regions',
    'regions' => array(
      'footer_first' => 'footer_first',
    ),
  );
  $pane->uuid = '3cbbeddc-1877-4d7c-9499-86cdd322b9a6';
  $display->content['new-3cbbeddc-1877-4d7c-9499-86cdd322b9a6'] = $pane;
  $display->panels['footer_first'][1] = 'new-3cbbeddc-1877-4d7c-9499-86cdd322b9a6';
  $pane = new stdClass();
  $pane->pid = 'new-78874195-913f-4b4e-bbf3-d4cb3cbca1fa';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_header_bar_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array(
    'type' => 'regions',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = '78874195-913f-4b4e-bbf3-d4cb3cbca1fa';
  $display->content['new-78874195-913f-4b4e-bbf3-d4cb3cbca1fa'] = $pane;
  $display->panels['header'][0] = 'new-78874195-913f-4b4e-bbf3-d4cb3cbca1fa';
  $pane = new stdClass();
  $pane->pid = 'new-2107fb82-2bd3-4f1e-9b0c-c69ad99dacb0';
  $pane->panel = 'header';
  $pane->type = 'views';
  $pane->subtype = 'nys_senator_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array(
    'type' => 'regions',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = '2107fb82-2bd3-4f1e-9b0c-c69ad99dacb0';
  $display->content['new-2107fb82-2bd3-4f1e-9b0c-c69ad99dacb0'] = $pane;
  $display->panels['header'][1] = 'new-2107fb82-2bd3-4f1e-9b0c-c69ad99dacb0';
  $pane = new stdClass();
  $pane->pid = 'new-55e2db9d-8684-43d1-a04e-0fcce22f07b5';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-microsite_nav_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array(
    'type' => 'regions',
    'regions' => array(
      'header' => 'header',
    ),
  );
  $pane->uuid = '55e2db9d-8684-43d1-a04e-0fcce22f07b5';
  $display->content['new-55e2db9d-8684-43d1-a04e-0fcce22f07b5'] = $pane;
  $display->panels['header'][2] = 'new-55e2db9d-8684-43d1-a04e-0fcce22f07b5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:senator:flexible_layout'] = $panelizer;

  return $export;
}
