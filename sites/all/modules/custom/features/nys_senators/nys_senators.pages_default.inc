<?php
/**
 * @file
 * nys_senators.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_senators_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_senator_legislation';
  $page->task = 'page';
  $page->admin_title = 'Page Senator Legislation';
  $page->admin_description = 'Page for bills related to Senator';
  $page->path = 'node/%node/legislation';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'senator' => 'senator',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Legislation Landing Page',
    'name' => 'devel',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
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
  $handler->name = 'page_page_senator_legislation_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'page_senator_legislation';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Active Senator Legislation',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'senator' => 'senator',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:senator:field_active',
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
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'f2cb_senator_legislation';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'tabs' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Legislation';
  $display->uuid = 'e1da2d6a-843b-4d66-99fc-785e6715203e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_page_senator_legislation_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b3d03fa7-6097-431e-8ed3-d229fc295647';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_microsite_interior_footer',
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
  $pane->uuid = 'b3d03fa7-6097-431e-8ed3-d229fc295647';
  $display->content['new-b3d03fa7-6097-431e-8ed3-d229fc295647'] = $pane;
  $display->panels['bottom'][0] = 'new-b3d03fa7-6097-431e-8ed3-d229fc295647';
  $pane = new stdClass();
  $pane->pid = 'new-04750a21-a0b6-4f40-999e-963dde32d73a';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'legislation_bills';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_legislation_bills',
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
    'css_id' => 'panel1',
    'css_class' => 'content active',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '04750a21-a0b6-4f40-999e-963dde32d73a';
  $display->content['new-04750a21-a0b6-4f40-999e-963dde32d73a'] = $pane;
  $display->panels['tabs'][0] = 'new-04750a21-a0b6-4f40-999e-963dde32d73a';
  $pane = new stdClass();
  $pane->pid = 'new-5fac7b05-0121-4c5a-a46b-b6f330bc7260';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'legislation_bills';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_legislation_resolutions',
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
    'css_id' => 'panel2',
    'css_class' => 'content',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5fac7b05-0121-4c5a-a46b-b6f330bc7260';
  $display->content['new-5fac7b05-0121-4c5a-a46b-b6f330bc7260'] = $pane;
  $display->panels['tabs'][1] = 'new-5fac7b05-0121-4c5a-a46b-b6f330bc7260';
  $pane = new stdClass();
  $pane->pid = 'new-8dab53dd-1af9-4a21-8cab-bb992ab766d8';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '2',
    'pager_id' => '0',
    'offset' => '1',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8dab53dd-1af9-4a21-8cab-bb992ab766d8';
  $display->content['new-8dab53dd-1af9-4a21-8cab-bb992ab766d8'] = $pane;
  $display->panels['top'][0] = 'new-8dab53dd-1af9-4a21-8cab-bb992ab766d8';
  $pane = new stdClass();
  $pane->pid = 'new-6fd76c79-6285-4cd7-aab6-ce495315ab62';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '2',
    'pager_id' => '0',
    'offset' => '1',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_featured_legislation_sub',
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
  $pane->locks = array();
  $pane->uuid = '6fd76c79-6285-4cd7-aab6-ce495315ab62';
  $display->content['new-6fd76c79-6285-4cd7-aab6-ce495315ab62'] = $pane;
  $display->panels['top'][1] = 'new-6fd76c79-6285-4cd7-aab6-ce495315ab62';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_page_senator_legislation__panel_context_84160caa-2643-4d6b-ba40-f1b5c5a89e05';
  $handler->task = 'page';
  $handler->subtask = 'page_senator_legislation';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Inactive Senator Legislation',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-inactive',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'senator' => 'senator',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:senator:field_active',
          'settings' => array(
            'field_active' => array(
              'und' => array(
                0 => array(
                  'value' => '0',
                ),
              ),
            ),
            'field_active_value' => array(
              0 => '0',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'f2cb_senator_legislation';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'tabs' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Legislation';
  $display->uuid = 'e1da2d6a-843b-4d66-99fc-785e6715203e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_page_senator_legislation__panel_context_84160caa-2643-4d6b-ba40-f1b5c5a89e05';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9ed74bda-0f12-4470-82ab-4f59f021c00f';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'legislation_bills';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_legislation_bills',
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
  $pane->uuid = '9ed74bda-0f12-4470-82ab-4f59f021c00f';
  $display->content['new-9ed74bda-0f12-4470-82ab-4f59f021c00f'] = $pane;
  $display->panels['tabs'][0] = 'new-9ed74bda-0f12-4470-82ab-4f59f021c00f';
  $pane = new stdClass();
  $pane->pid = 'new-e3ed2e18-b2b5-47b3-9d7b-b2b77768080c';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_microsite_interior_footer',
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
  $pane->locks = array();
  $pane->uuid = 'e3ed2e18-b2b5-47b3-9d7b-b2b77768080c';
  $display->content['new-e3ed2e18-b2b5-47b3-9d7b-b2b77768080c'] = $pane;
  $display->panels['tabs'][1] = 'new-e3ed2e18-b2b5-47b3-9d7b-b2b77768080c';
  $pane = new stdClass();
  $pane->pid = 'new-55de4fce-9435-4735-a403-4fc42b719282';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-sntor_inactive_banner';
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
  $pane->uuid = '55de4fce-9435-4735-a403-4fc42b719282';
  $display->content['new-55de4fce-9435-4735-a403-4fc42b719282'] = $pane;
  $display->panels['top'][0] = 'new-55de4fce-9435-4735-a403-4fc42b719282';
  $pane = new stdClass();
  $pane->pid = 'new-8dab53dd-1af9-4a21-8cab-bb992ab766d8';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '2',
    'pager_id' => '0',
    'offset' => '1',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8dab53dd-1af9-4a21-8cab-bb992ab766d8';
  $display->content['new-8dab53dd-1af9-4a21-8cab-bb992ab766d8'] = $pane;
  $display->panels['top'][1] = 'new-8dab53dd-1af9-4a21-8cab-bb992ab766d8';
  $pane = new stdClass();
  $pane->pid = 'new-6fd76c79-6285-4cd7-aab6-ce495315ab62';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '2',
    'pager_id' => '0',
    'offset' => '1',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_featured_legislation_sub',
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
  $pane->uuid = '6fd76c79-6285-4cd7-aab6-ce495315ab62';
  $display->content['new-6fd76c79-6285-4cd7-aab6-ce495315ab62'] = $pane;
  $display->panels['top'][2] = 'new-6fd76c79-6285-4cd7-aab6-ce495315ab62';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_senator_legislation'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'senator_about';
  $page->task = 'page';
  $page->admin_title = 'Senator About';
  $page->admin_description = '';
  $page->path = 'node/%node/about';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'senator' => 'senator',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'About',
    'name' => 'menu-constituent-dashboard-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
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
  $handler->name = 'page_senator_about_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'senator_about';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: Senator [field_senator])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_senator-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:senator:field_active',
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
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'About %node:title';
  $display->uuid = 'addf9895-7ce5-408c-a0f0-b2790026d4fa';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_senator_about_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c091a452-e34a-46a1-aed6-727a32de3af2';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'senator_about';
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
    'display' => 'default',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = 'c091a452-e34a-46a1-aed6-727a32de3af2';
  $display->content['new-c091a452-e34a-46a1-aed6-727a32de3af2'] = $pane;
  $display->panels['middle'][0] = 'new-c091a452-e34a-46a1-aed6-727a32de3af2';
  $pane = new stdClass();
  $pane->pid = 'new-7298fba9-794a-4a32-9137-795fbe33f39f';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_microsite_interior_footer',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7298fba9-794a-4a32-9137-795fbe33f39f';
  $display->content['new-7298fba9-794a-4a32-9137-795fbe33f39f'] = $pane;
  $display->panels['middle'][1] = 'new-7298fba9-794a-4a32-9137-795fbe33f39f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['senator_about'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'senator_contact';
  $page->task = 'page';
  $page->admin_title = 'Senator Contact';
  $page->admin_description = '';
  $page->path = 'node/%node/contact';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'senator' => 'senator',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'About',
    'name' => 'menu-constituent-dashboard-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
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
  $handler->name = 'page_senator_contact__panel_context_9cb463aa-0c79-4053-b850-66a1b775c56c';
  $handler->task = 'page';
  $handler->subtask = 'senator_contact';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: Senator [field_senator])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_senator-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:senator:field_active',
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
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Contact %node:title';
  $display->uuid = 'addf9895-7ce5-408c-a0f0-b2790026d4fa';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_senator_contact__panel_context_9cb463aa-0c79-4053-b850-66a1b775c56c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bd5b52b4-d219-49e2-900d-0bb78093e4e4';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'senator_contact_blocks';
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
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_office_info_block',
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
  $pane->uuid = 'bd5b52b4-d219-49e2-900d-0bb78093e4e4';
  $display->content['new-bd5b52b4-d219-49e2-900d-0bb78093e4e4'] = $pane;
  $display->panels['middle'][0] = 'new-bd5b52b4-d219-49e2-900d-0bb78093e4e4';
  $pane = new stdClass();
  $pane->pid = 'new-447959b8-582e-466b-95c7-8f7a03e2eb37';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'senator_contact_blocks';
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
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_media_inquiries_block',
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
  $pane->locks = array();
  $pane->uuid = '447959b8-582e-466b-95c7-8f7a03e2eb37';
  $display->content['new-447959b8-582e-466b-95c7-8f7a03e2eb37'] = $pane;
  $display->panels['middle'][1] = 'new-447959b8-582e-466b-95c7-8f7a03e2eb37';
  $pane = new stdClass();
  $pane->pid = 'new-41eec7fb-954a-487e-a61e-c5af6baea529';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'senator_contact_blocks';
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
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_press_kit_block',
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
  $pane->uuid = '41eec7fb-954a-487e-a61e-c5af6baea529';
  $display->content['new-41eec7fb-954a-487e-a61e-c5af6baea529'] = $pane;
  $display->panels['middle'][2] = 'new-41eec7fb-954a-487e-a61e-c5af6baea529';
  $pane = new stdClass();
  $pane->pid = 'new-c78597f5-372c-4cba-b4fd-5e4dacb34167';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'nys_messaging-senator_contact';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c78597f5-372c-4cba-b4fd-5e4dacb34167';
  $display->content['new-c78597f5-372c-4cba-b4fd-5e4dacb34167'] = $pane;
  $display->panels['middle'][3] = 'new-c78597f5-372c-4cba-b4fd-5e4dacb34167';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['senator_contact'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'senator_message';
  $page->task = 'page';
  $page->admin_title = 'Senator Message';
  $page->admin_description = '';
  $page->path = 'node/%node/message';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'senator' => 'senator',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'About',
    'name' => 'menu-constituent-dashboard-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
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
  $handler->name = 'page_senator_message__panel_context_db15d642-3307-4253-b54f-0bcaf81e5379';
  $handler->task = 'page';
  $handler->subtask = 'senator_message';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: Senator [field_senator])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_senator-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:senator:field_active',
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
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Message %node:title';
  $display->uuid = 'addf9895-7ce5-408c-a0f0-b2790026d4fa';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_senator_message__panel_context_db15d642-3307-4253-b54f-0bcaf81e5379';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0597dd8d-928a-4a15-bf63-229f5c8a2039';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'nys_messaging-senator_message';
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
  $pane->uuid = '0597dd8d-928a-4a15-bf63-229f5c8a2039';
  $display->content['new-0597dd8d-928a-4a15-bf63-229f5c8a2039'] = $pane;
  $display->panels['middle'][0] = 'new-0597dd8d-928a-4a15-bf63-229f5c8a2039';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['senator_message'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_profile_view';
  $page->task = 'page';
  $page->admin_title = 'User Profile View';
  $page->admin_description = 'Allows senators to view users profiles';
  $page->path = 'profile/%user';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
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
  $handler->name = 'page_user_profile_view__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_profile_view';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'user-profile-view',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5249a759-a1c8-4bd7-84cb-d943633f3511';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_user_profile_view__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5a42fa20-bcac-40e7-bf3e-ac7756c790f1';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-user_card_block';
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
  $pane->uuid = '5a42fa20-bcac-40e7-bf3e-ac7756c790f1';
  $display->content['new-5a42fa20-bcac-40e7-bf3e-ac7756c790f1'] = $pane;
  $display->panels['center'][0] = 'new-5a42fa20-bcac-40e7-bf3e-ac7756c790f1';
  $pane = new stdClass();
  $pane->pid = 'new-9825e87c-ead0-4d0d-ab5b-546b705f0e6c';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9825e87c-ead0-4d0d-ab5b-546b705f0e6c';
  $display->content['new-9825e87c-ead0-4d0d-ab5b-546b705f0e6c'] = $pane;
  $display->panels['center'][1] = 'new-9825e87c-ead0-4d0d-ab5b-546b705f0e6c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_profile_view'] = $page;

  return $pages;

}
