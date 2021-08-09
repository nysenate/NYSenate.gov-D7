<?php

/**
 * @file
 * nys_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_and_issues';
  $page->task = 'page';
  $page->admin_title = 'News and Issues';
  $page->admin_description = '';
  $page->path = 'news-and-issues';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'main-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'News & Issues',
    'type' => 'normal',
    'weight' => '0',
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_and_issues_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news_and_issues';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => 'gen_blue',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_newsroom';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'bottom' => NULL,
      'center' => NULL,
      'default' => NULL,
      'tabs' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'News & issues';
  $display->uuid = '1770542c-69b1-4493-b09f-8a27379aeab5';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_news_and_issues_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4b2dc5c1-9f74-4bb3-a8ba-a64de2caa95a';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'senator_tweets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'homepage_tweets',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '2',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4b2dc5c1-9f74-4bb3-a8ba-a64de2caa95a';
  $display->content['new-4b2dc5c1-9f74-4bb3-a8ba-a64de2caa95a'] = $pane;
  $display->panels['bottom'][0] = 'new-4b2dc5c1-9f74-4bb3-a8ba-a64de2caa95a';
  $pane = new stdClass();
  $pane->pid = 'new-64ab0a45-5497-4af0-b44b-94a599e8a0b0';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'tweets';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_tweets',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '64ab0a45-5497-4af0-b44b-94a599e8a0b0';
  $display->content['new-64ab0a45-5497-4af0-b44b-94a599e8a0b0'] = $pane;
  $display->panels['bottom'][1] = 'new-64ab0a45-5497-4af0-b44b-94a599e8a0b0';
  $pane = new stdClass();
  $pane->pid = 'new-6b001f7a-6d8f-488e-acc9-3f8e1a527e64';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'featured_video',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6b001f7a-6d8f-488e-acc9-3f8e1a527e64';
  $display->content['new-6b001f7a-6d8f-488e-acc9-3f8e1a527e64'] = $pane;
  $display->panels['bottom'][2] = 'new-6b001f7a-6d8f-488e-acc9-3f8e1a527e64';
  $pane = new stdClass();
  $pane->pid = 'new-b0b6561e-e50c-4c23-824d-43c9038b8810';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'issues_listings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_listing',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '8',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b0b6561e-e50c-4c23-824d-43c9038b8810';
  $display->content['new-b0b6561e-e50c-4c23-824d-43c9038b8810'] = $pane;
  $display->panels['bottom'][3] = 'new-b0b6561e-e50c-4c23-824d-43c9038b8810';
  $pane = new stdClass();
  $pane->pid = 'new-7f98749d-f2ba-4da6-9b14-29275f9f2912';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7f98749d-f2ba-4da6-9b14-29275f9f2912';
  $display->content['new-7f98749d-f2ba-4da6-9b14-29275f9f2912'] = $pane;
  $display->panels['bottom'][4] = 'new-7f98749d-f2ba-4da6-9b14-29275f9f2912';
  $pane = new stdClass();
  $pane->pid = 'new-5d25f411-8f7d-449e-a64d-da079c6ae34b';
  $pane->panel = 'bottom';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-how_senate_works_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '5d25f411-8f7d-449e-a64d-da079c6ae34b';
  $display->content['new-5d25f411-8f7d-449e-a64d-da079c6ae34b'] = $pane;
  $display->panels['bottom'][5] = 'new-5d25f411-8f7d-449e-a64d-da079c6ae34b';
  $pane = new stdClass();
  $pane->pid = 'new-9cd2714d-ff56-4339-8d3b-9b5a248b45fe';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'all_news',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9cd2714d-ff56-4339-8d3b-9b5a248b45fe';
  $display->content['new-9cd2714d-ff56-4339-8d3b-9b5a248b45fe'] = $pane;
  $display->panels['tabs'][0] = 'new-9cd2714d-ff56-4339-8d3b-9b5a248b45fe';
  $pane = new stdClass();
  $pane->pid = 'new-163d80dd-2618-4060-b847-6f3a1c889db8';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'press_releases',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '163d80dd-2618-4060-b847-6f3a1c889db8';
  $display->content['new-163d80dd-2618-4060-b847-6f3a1c889db8'] = $pane;
  $display->panels['tabs'][1] = 'new-163d80dd-2618-4060-b847-6f3a1c889db8';
  $pane = new stdClass();
  $pane->pid = 'new-37810f82-d0d0-4fc9-9573-636cc3a53d73';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-news_issues_hdr_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '37810f82-d0d0-4fc9-9573-636cc3a53d73';
  $display->content['new-37810f82-d0d0-4fc9-9573-636cc3a53d73'] = $pane;
  $display->panels['top'][0] = 'new-37810f82-d0d0-4fc9-9573-636cc3a53d73';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_and_issues'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_senator_newsroom';
  $page->task = 'page';
  $page->admin_title = 'Page Senator Newsroom';
  $page->admin_description = 'Senator\'s newsroom';
  $page->path = 'node/%node/newsroom/!display';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'name' => 'context_exists',
        'not' => FALSE,
        'settings' => array(
          'exists' => '1',
        ),
      ),
      1 => array(
        'context' => 'argument_entity_id:node_1',
        'name' => 'node_type',
        'not' => FALSE,
        'settings' => array(
          'type' => array(
            'senator' => 'senator',
          ),
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array(
    'display' => array(
      'id' => 1,
      'identifier' => 'Display String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_page_senator_newsroom_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'page_senator_newsroom';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_type',
          'not' => FALSE,
          'settings' => array(
            'type' => array(
              'senator' => 'senator',
            ),
          ),
        ),
        1 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'entity_field_value:node:senator:field_active',
          'not' => FALSE,
          'settings' => array(
            'field_active' => array(
              'und' => array(
                0 => array(
                  'value' => '1',
                ),
              ),
            ),
            'field_active_value' => array(
              0 => '1',
            ),
          ),
        ),
        2 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '!=',
            'value' => 'feed',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Active Senator Newsroom',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_newsroom';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'middle' => array(
      'style' => '-1',
    ),
    'style_settings' => array(
      'above_left' => NULL,
      'above_right' => NULL,
      'below_left' => NULL,
      'below_right' => NULL,
      'bottom' => NULL,
      'default' => NULL,
      'middle' => NULL,
      'tabs' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Newsroom';
  $display->uuid = 'fab2261b-df76-48a5-a082-7b46d1eec98a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_page_senator_newsroom_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-da519680-00e6-4c4c-9852-4c4af374f497';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'senator_tweets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'da519680-00e6-4c4c-9852-4c4af374f497';
  $display->content['new-da519680-00e6-4c4c-9852-4c4af374f497'] = $pane;
  $display->panels['bottom'][0] = 'new-da519680-00e6-4c4c-9852-4c4af374f497';
  $pane = new stdClass();
  $pane->pid = 'new-328d35cf-61aa-40e8-a519-96f1bf3ff48b';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'featured_video',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '328d35cf-61aa-40e8-a519-96f1bf3ff48b';
  $display->content['new-328d35cf-61aa-40e8-a519-96f1bf3ff48b'] = $pane;
  $display->panels['bottom'][1] = 'new-328d35cf-61aa-40e8-a519-96f1bf3ff48b';
  $pane = new stdClass();
  $pane->pid = 'new-4fd27661-c7d9-4fcd-a409-e0fae9be2483';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_microsite_interior_footer',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4fd27661-c7d9-4fcd-a409-e0fae9be2483';
  $display->content['new-4fd27661-c7d9-4fcd-a409-e0fae9be2483'] = $pane;
  $display->panels['bottom'][2] = 'new-4fd27661-c7d9-4fcd-a409-e0fae9be2483';
  $pane = new stdClass();
  $pane->pid = 'new-9ab1b284-8439-4302-aac1-215633672293';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'all_news',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9ab1b284-8439-4302-aac1-215633672293';
  $display->content['new-9ab1b284-8439-4302-aac1-215633672293'] = $pane;
  $display->panels['tabs'][0] = 'new-9ab1b284-8439-4302-aac1-215633672293';
  $pane = new stdClass();
  $pane->pid = 'new-f213af00-8b2a-407a-ae61-5ee8180f4d17';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'press_releases',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f213af00-8b2a-407a-ae61-5ee8180f4d17';
  $display->content['new-f213af00-8b2a-407a-ae61-5ee8180f4d17'] = $pane;
  $display->panels['tabs'][1] = 'new-f213af00-8b2a-407a-ae61-5ee8180f4d17';
  $pane = new stdClass();
  $pane->pid = 'new-52e12f49-6730-439c-bf26-4d69e62d95c7';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'videos',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '52e12f49-6730-439c-bf26-4d69e62d95c7';
  $display->content['new-52e12f49-6730-439c-bf26-4d69e62d95c7'] = $pane;
  $display->panels['tabs'][2] = 'new-52e12f49-6730-439c-bf26-4d69e62d95c7';
  $pane = new stdClass();
  $pane->pid = 'new-2f05c08d-3879-4c2e-b86e-d935685690a0';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'featured_story',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f05c08d-3879-4c2e-b86e-d935685690a0';
  $display->content['new-2f05c08d-3879-4c2e-b86e-d935685690a0'] = $pane;
  $display->panels['top'][0] = 'new-2f05c08d-3879-4c2e-b86e-d935685690a0';
  $pane = new stdClass();
  $pane->pid = 'new-8d28ed72-a2bb-4b27-a9d9-1f8b370813ed';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'media',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8d28ed72-a2bb-4b27-a9d9-1f8b370813ed';
  $display->content['new-8d28ed72-a2bb-4b27-a9d9-1f8b370813ed'] = $pane;
  $display->panels['top'][1] = 'new-8d28ed72-a2bb-4b27-a9d9-1f8b370813ed';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_page_senator_newsroom__panel_context_57b0b590-2167-4bae-b45d-cd1c7aec9f58';
  $handler->task = 'page';
  $handler->subtask = 'page_senator_newsroom';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'feed',
          ),
        ),
        1 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_type',
          'not' => FALSE,
          'settings' => array(
            'type' => array(
              'senator' => 'senator',
            ),
          ),
        ),
        2 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'entity_field_value:node:senator:field_active',
          'not' => FALSE,
          'settings' => array(
            'field_active' => array(
              'und' => array(
                0 => array(
                  'value' => '1',
                ),
              ),
            ),
            'field_active_value' => array(
              0 => '1',
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => '',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Newsroom Feed',
  );
  $display = new panels_display();
  $display->layout = 'rss_feed';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'feed' => array(
      'style' => 'naked',
    ),
    'style_settings' => array(
      'default' => NULL,
      'feed' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0aa9837c-0097-484e-8acc-49aa56d80491';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_page_senator_newsroom__panel_context_57b0b590-2167-4bae-b45d-cd1c7aec9f58';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0efa1c51-2a24-4103-a1cf-b0e3ca0d8e24';
  $pane->panel = 'feed';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'feed_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'div',
    'override_title_text' => '',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'block',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0efa1c51-2a24-4103-a1cf-b0e3ca0d8e24';
  $display->content['new-0efa1c51-2a24-4103-a1cf-b0e3ca0d8e24'] = $pane;
  $display->panels['feed'][0] = 'new-0efa1c51-2a24-4103-a1cf-b0e3ca0d8e24';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0efa1c51-2a24-4103-a1cf-b0e3ca0d8e24';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_senator_newsroom'] = $page;

  return $pages;

}
