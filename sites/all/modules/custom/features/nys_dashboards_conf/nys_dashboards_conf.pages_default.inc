<?php

/**
 * @file
 * nys_dashboards_conf.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_dashboards_conf_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dashboard';
  $page->task = 'page';
  $page->admin_title = 'dashboard';
  $page->admin_description = 'dashboard landing page';
  $page->path = 'user/%user/dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
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
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Overview',
    'name' => 'menu-senator-dashboard-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
      'keyword' => 'user',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Senator Inbox',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'php function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Senator\', \'inbox\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Dashboard Inbox';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->uuid = '02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $display->content['new-02b0b706-35c5-45a5-979e-2cf05a1eaf21'] = $pane;
  $display->panels['left'][0] = 'new-02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $pane = new stdClass();
  $pane->pid = 'new-b9148dea-ffd1-4919-b69f-c1751317f71a';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-senator-dashboard-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'menu-dashboard-inbox',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b9148dea-ffd1-4919-b69f-c1751317f71a';
  $display->content['new-b9148dea-ffd1-4919-b69f-c1751317f71a'] = $pane;
  $display->panels['left'][1] = 'new-b9148dea-ffd1-4919-b69f-c1751317f71a';
  $pane = new stdClass();
  $pane->pid = 'new-6d6fe0d9-02fd-4bbe-8981-5842fec7e4ee';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-sen_leading_issues_block';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => '*/inbox',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->uuid = '6d6fe0d9-02fd-4bbe-8981-5842fec7e4ee';
  $display->content['new-6d6fe0d9-02fd-4bbe-8981-5842fec7e4ee'] = $pane;
  $display->panels['right'][0] = 'new-6d6fe0d9-02fd-4bbe-8981-5842fec7e4ee';
  $pane = new stdClass();
  $pane->pid = 'new-76cdb780-3ae5-41d0-8e12-13977f1682ca';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_inbox-nys_inbox';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '76cdb780-3ae5-41d0-8e12-13977f1682ca';
  $display->content['new-76cdb780-3ae5-41d0-8e12-13977f1682ca'] = $pane;
  $display->panels['right'][1] = 'new-76cdb780-3ae5-41d0-8e12-13977f1682ca';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Senator Overview',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Senator\', \'\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-074f65e8-46a5-438c-b7c3-6dba0f2098ff';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->uuid = '074f65e8-46a5-438c-b7c3-6dba0f2098ff';
  $display->content['new-074f65e8-46a5-438c-b7c3-6dba0f2098ff'] = $pane;
  $display->panels['left'][0] = 'new-074f65e8-46a5-438c-b7c3-6dba0f2098ff';
  $pane = new stdClass();
  $pane->pid = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-senator-dashboard-menu';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $display->content['new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2'] = $pane;
  $display->panels['left'][1] = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane = new stdClass();
  $pane->pid = 'new-8780ef95-2070-4003-9129-749424f4eb21';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-year_updates_block';
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
  $pane->uuid = '8780ef95-2070-4003-9129-749424f4eb21';
  $display->content['new-8780ef95-2070-4003-9129-749424f4eb21'] = $pane;
  $display->panels['right'][0] = 'new-8780ef95-2070-4003-9129-749424f4eb21';
  $pane = new stdClass();
  $pane->pid = 'new-e258976b-bb0a-479a-8adf-e537eddcc696';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-active_list_block';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e258976b-bb0a-479a-8adf-e537eddcc696';
  $display->content['new-e258976b-bb0a-479a-8adf-e537eddcc696'] = $pane;
  $display->panels['right'][1] = 'new-e258976b-bb0a-479a-8adf-e537eddcc696';
  $pane = new stdClass();
  $pane->pid = 'new-854d50e9-2048-42d9-86bd-8af626561a70';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-pet_block';
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
  $pane->uuid = '854d50e9-2048-42d9-86bd-8af626561a70';
  $display->content['new-854d50e9-2048-42d9-86bd-8af626561a70'] = $pane;
  $display->panels['right'][2] = 'new-854d50e9-2048-42d9-86bd-8af626561a70';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_4';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Senator Bills',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Senator\', \'bills\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f82382c6-c7bb-40d7-a211-064e357eb3f6';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->uuid = 'f82382c6-c7bb-40d7-a211-064e357eb3f6';
  $display->content['new-f82382c6-c7bb-40d7-a211-064e357eb3f6'] = $pane;
  $display->panels['left'][0] = 'new-f82382c6-c7bb-40d7-a211-064e357eb3f6';
  $pane = new stdClass();
  $pane->pid = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-senator-dashboard-menu';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $display->content['new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2'] = $pane;
  $display->panels['left'][1] = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane = new stdClass();
  $pane->pid = 'new-bd92dee9-8fff-4a0c-84a5-58611cb01ee1';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-sen_bills_leg_block';
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
  $pane->uuid = 'bd92dee9-8fff-4a0c-84a5-58611cb01ee1';
  $display->content['new-bd92dee9-8fff-4a0c-84a5-58611cb01ee1'] = $pane;
  $display->panels['right'][0] = 'new-bd92dee9-8fff-4a0c-84a5-58611cb01ee1';
  $pane = new stdClass();
  $pane->pid = 'new-5e4748d4-72bb-40de-939b-fa83c26c11bb';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-sen_bills_msg_block';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5e4748d4-72bb-40de-939b-fa83c26c11bb';
  $display->content['new-5e4748d4-72bb-40de-939b-fa83c26c11bb'] = $pane;
  $display->panels['right'][1] = 'new-5e4748d4-72bb-40de-939b-fa83c26c11bb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_5';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Senator Constituents',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Senator\', \'constituents\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8736c1aa-a1b1-4341-806c-da03b694eb29';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->uuid = '8736c1aa-a1b1-4341-806c-da03b694eb29';
  $display->content['new-8736c1aa-a1b1-4341-806c-da03b694eb29'] = $pane;
  $display->panels['left'][0] = 'new-8736c1aa-a1b1-4341-806c-da03b694eb29';
  $pane = new stdClass();
  $pane->pid = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-senator-dashboard-menu';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $display->content['new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2'] = $pane;
  $display->panels['left'][1] = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane = new stdClass();
  $pane->pid = 'new-e65933c2-bdb3-4416-9de9-71530ad29ac9';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-sen_const_block';
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
  $pane->uuid = 'e65933c2-bdb3-4416-9de9-71530ad29ac9';
  $display->content['new-e65933c2-bdb3-4416-9de9-71530ad29ac9'] = $pane;
  $display->panels['right'][0] = 'new-e65933c2-bdb3-4416-9de9-71530ad29ac9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_6';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Senator Issues',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Senator\', \'issues\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-81602488-714f-4868-802f-8932d4a7d834';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->uuid = '81602488-714f-4868-802f-8932d4a7d834';
  $display->content['new-81602488-714f-4868-802f-8932d4a7d834'] = $pane;
  $display->panels['left'][0] = 'new-81602488-714f-4868-802f-8932d4a7d834';
  $pane = new stdClass();
  $pane->pid = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-senator-dashboard-menu';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $display->content['new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2'] = $pane;
  $display->panels['left'][1] = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane = new stdClass();
  $pane->pid = 'new-08ef12ff-c23d-4a3c-97d3-ec8850c667b3';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-sen_issues_block';
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
  $pane->uuid = '08ef12ff-c23d-4a3c-97d3-ec8850c667b3';
  $display->content['new-08ef12ff-c23d-4a3c-97d3-ec8850c667b3'] = $pane;
  $display->panels['right'][0] = 'new-08ef12ff-c23d-4a3c-97d3-ec8850c667b3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard__panel_context_a027660e-559c-4ff3-9cef-4ece70129f6b';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Senator Questionnaires',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Senator\', \'questionnaires\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard__panel_context_a027660e-559c-4ff3-9cef-4ece70129f6b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-074f65e8-46a5-438c-b7c3-6dba0f2098ff';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->uuid = '074f65e8-46a5-438c-b7c3-6dba0f2098ff';
  $display->content['new-074f65e8-46a5-438c-b7c3-6dba0f2098ff'] = $pane;
  $display->panels['left'][0] = 'new-074f65e8-46a5-438c-b7c3-6dba0f2098ff';
  $pane = new stdClass();
  $pane->pid = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-senator-dashboard-menu';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $display->content['new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2'] = $pane;
  $display->panels['left'][1] = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $pane = new stdClass();
  $pane->pid = 'new-b5e4cd51-db84-4242-91ae-25ae8e51c71c';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-quest_block';
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
  $pane->uuid = 'b5e4cd51-db84-4242-91ae-25ae8e51c71c';
  $display->content['new-b5e4cd51-db84-4242-91ae-25ae8e51c71c'] = $pane;
  $display->panels['right'][0] = 'new-b5e4cd51-db84-4242-91ae-25ae8e51c71c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e7ca85a2-b60a-48dd-95cc-20a7cd7956c2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Constituent Inbox',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'constituent-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Constituent\', \'inbox\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Dashboard Inbox';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9e754187-cf1f-4095-99b2-2f58cd197da3';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-user_card_block';
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
  $pane->uuid = '9e754187-cf1f-4095-99b2-2f58cd197da3';
  $display->content['new-9e754187-cf1f-4095-99b2-2f58cd197da3'] = $pane;
  $display->panels['left'][0] = 'new-9e754187-cf1f-4095-99b2-2f58cd197da3';
  $pane = new stdClass();
  $pane->pid = 'new-02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $display->content['new-02b0b706-35c5-45a5-979e-2cf05a1eaf21'] = $pane;
  $display->panels['left'][1] = 'new-02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $pane = new stdClass();
  $pane->pid = 'new-6f7d7e25-8e67-4a4b-9384-06807f204801';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-constituent-dashboard-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Items You\'re Following',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6f7d7e25-8e67-4a4b-9384-06807f204801';
  $display->content['new-6f7d7e25-8e67-4a4b-9384-06807f204801'] = $pane;
  $display->panels['left'][2] = 'new-6f7d7e25-8e67-4a4b-9384-06807f204801';
  $pane = new stdClass();
  $pane->pid = 'new-dbd433fe-4e84-4ba6-8055-f36ed1e43a3a';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_inbox-nys_inbox';
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
  $pane->uuid = 'dbd433fe-4e84-4ba6-8055-f36ed1e43a3a';
  $display->content['new-dbd433fe-4e84-4ba6-8055-f36ed1e43a3a'] = $pane;
  $display->panels['right'][0] = 'new-dbd433fe-4e84-4ba6-8055-f36ed1e43a3a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard__panel_context_ab834175-bc9e-44fb-9f1b-c8367afd5e21';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Senator Analytics Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'senator-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Senator\', \'analytics\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e7d29085-9c69-4136-a5ab-3b3b1ece719f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard__panel_context_ab834175-bc9e-44fb-9f1b-c8367afd5e21';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cbf188ca-09a3-4b4b-a00c-fd6521a500cd';
  $pane->panel = 'left';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cbf188ca-09a3-4b4b-a00c-fd6521a500cd';
  $display->content['new-cbf188ca-09a3-4b4b-a00c-fd6521a500cd'] = $pane;
  $display->panels['left'][0] = 'new-cbf188ca-09a3-4b4b-a00c-fd6521a500cd';
  $pane = new stdClass();
  $pane->pid = 'new-9eee356f-aad2-4a7f-b1c2-b823ab064659';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-senator-dashboard-menu';
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
  $pane->uuid = '9eee356f-aad2-4a7f-b1c2-b823ab064659';
  $display->content['new-9eee356f-aad2-4a7f-b1c2-b823ab064659'] = $pane;
  $display->panels['left'][1] = 'new-9eee356f-aad2-4a7f-b1c2-b823ab064659';
  $pane = new stdClass();
  $pane->pid = 'new-06e23cea-e51b-409c-8667-4d5987590a6b';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Looker Embed',
    'title' => 'Advanced Analytics',
    'body' => '<p><iframe frameborder="0" height="338" src="https://nysenate.looker.com/embed/public/rSJdd7hWP4z9nySV58p6FhKTYVdrj3G7?type=table" width="100%"></iframe></p>',
    'format' => 'full_html',
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
  $pane->uuid = '06e23cea-e51b-409c-8667-4d5987590a6b';
  $display->content['new-06e23cea-e51b-409c-8667-4d5987590a6b'] = $pane;
  $display->panels['right'][0] = 'new-06e23cea-e51b-409c-8667-4d5987590a6b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cbf188ca-09a3-4b4b-a00c-fd6521a500cd';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_9';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -22;
  $handler->conf = array(
    'title' => 'Constituent Bills',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'constituent-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Constituent\', \'bills\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Bills and Updates';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-aaf4058e-ee70-4b02-b75c-df8c9a996355';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-user_card_block';
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
  $pane->uuid = 'aaf4058e-ee70-4b02-b75c-df8c9a996355';
  $display->content['new-aaf4058e-ee70-4b02-b75c-df8c9a996355'] = $pane;
  $display->panels['left'][0] = 'new-aaf4058e-ee70-4b02-b75c-df8c9a996355';
  $pane = new stdClass();
  $pane->pid = 'new-f82382c6-c7bb-40d7-a211-064e357eb3f6';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f82382c6-c7bb-40d7-a211-064e357eb3f6';
  $display->content['new-f82382c6-c7bb-40d7-a211-064e357eb3f6'] = $pane;
  $display->panels['left'][1] = 'new-f82382c6-c7bb-40d7-a211-064e357eb3f6';
  $pane = new stdClass();
  $pane->pid = 'new-93aab4be-77a8-46d6-a188-71271abc1234';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-constituent-dashboard-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Items You\'re Following',
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
  $pane->uuid = '93aab4be-77a8-46d6-a188-71271abc1234';
  $display->content['new-93aab4be-77a8-46d6-a188-71271abc1234'] = $pane;
  $display->panels['left'][2] = 'new-93aab4be-77a8-46d6-a188-71271abc1234';
  $pane = new stdClass();
  $pane->pid = 'new-f0f8a88c-9822-4fbd-b47c-1089c0e269f2';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-const_bills_flw_block';
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
  $pane->uuid = 'f0f8a88c-9822-4fbd-b47c-1089c0e269f2';
  $display->content['new-f0f8a88c-9822-4fbd-b47c-1089c0e269f2'] = $pane;
  $display->panels['right'][0] = 'new-f0f8a88c-9822-4fbd-b47c-1089c0e269f2';
  $pane = new stdClass();
  $pane->pid = 'new-c6ec500c-80f5-44f4-bf01-ee995b5a87bc';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'constituent_bills';
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
    'display' => 'constituent_bills_voted_on',
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
  $pane->uuid = 'c6ec500c-80f5-44f4-bf01-ee995b5a87bc';
  $display->content['new-c6ec500c-80f5-44f4-bf01-ee995b5a87bc'] = $pane;
  $display->panels['right'][1] = 'new-c6ec500c-80f5-44f4-bf01-ee995b5a87bc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_10';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -21;
  $handler->conf = array(
    'title' => 'Constituent Petitions',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'constituent-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Constituent\', \'petitions\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_10';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4f96e0cf-eba0-4a38-b928-d64fa170570f';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-user_card_block';
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
  $pane->uuid = '4f96e0cf-eba0-4a38-b928-d64fa170570f';
  $display->content['new-4f96e0cf-eba0-4a38-b928-d64fa170570f'] = $pane;
  $display->panels['left'][0] = 'new-4f96e0cf-eba0-4a38-b928-d64fa170570f';
  $pane = new stdClass();
  $pane->pid = 'new-e3682b8c-86d2-4bd3-a813-f4904acde104';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e3682b8c-86d2-4bd3-a813-f4904acde104';
  $display->content['new-e3682b8c-86d2-4bd3-a813-f4904acde104'] = $pane;
  $display->panels['left'][1] = 'new-e3682b8c-86d2-4bd3-a813-f4904acde104';
  $pane = new stdClass();
  $pane->pid = 'new-6e2c2a55-c60e-4f80-9b92-cf7b9f391d82';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-constituent-dashboard-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Items You\'re Following',
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
  $pane->uuid = '6e2c2a55-c60e-4f80-9b92-cf7b9f391d82';
  $display->content['new-6e2c2a55-c60e-4f80-9b92-cf7b9f391d82'] = $pane;
  $display->panels['left'][2] = 'new-6e2c2a55-c60e-4f80-9b92-cf7b9f391d82';
  $pane = new stdClass();
  $pane->pid = 'new-59989be4-3c5c-49af-8847-6a11e53392bd';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-const_pet_quest_block';
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
  $pane->uuid = '59989be4-3c5c-49af-8847-6a11e53392bd';
  $display->content['new-59989be4-3c5c-49af-8847-6a11e53392bd'] = $pane;
  $display->panels['right'][0] = 'new-59989be4-3c5c-49af-8847-6a11e53392bd';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_11';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -20;
  $handler->conf = array(
    'title' => 'Constituent Issues',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'constituent-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Constituent\', \'issues\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_11';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9b410950-8290-481d-a5e8-ada8f572b8dd';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-user_card_block';
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
  $pane->uuid = '9b410950-8290-481d-a5e8-ada8f572b8dd';
  $display->content['new-9b410950-8290-481d-a5e8-ada8f572b8dd'] = $pane;
  $display->panels['left'][0] = 'new-9b410950-8290-481d-a5e8-ada8f572b8dd';
  $pane = new stdClass();
  $pane->pid = 'new-81602488-714f-4868-802f-8932d4a7d834';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '81602488-714f-4868-802f-8932d4a7d834';
  $display->content['new-81602488-714f-4868-802f-8932d4a7d834'] = $pane;
  $display->panels['left'][1] = 'new-81602488-714f-4868-802f-8932d4a7d834';
  $pane = new stdClass();
  $pane->pid = 'new-0652b5f3-205f-4eb1-8990-7382718c833d';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-constituent-dashboard-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Items You Are Following',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0652b5f3-205f-4eb1-8990-7382718c833d';
  $display->content['new-0652b5f3-205f-4eb1-8990-7382718c833d'] = $pane;
  $display->panels['left'][2] = 'new-0652b5f3-205f-4eb1-8990-7382718c833d';
  $pane = new stdClass();
  $pane->pid = 'new-12ba20b6-8c56-47db-a7db-6eace2e6b911';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-const_issues_flw_block';
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
  $pane->uuid = '12ba20b6-8c56-47db-a7db-6eace2e6b911';
  $display->content['new-12ba20b6-8c56-47db-a7db-6eace2e6b911'] = $pane;
  $display->panels['right'][0] = 'new-12ba20b6-8c56-47db-a7db-6eace2e6b911';
  $pane = new stdClass();
  $pane->pid = 'new-0653ac2c-8bcf-4053-a814-ab1c396d0a67';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'explore_issues_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '21',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'constituents_issues_followed',
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
  $pane->uuid = '0653ac2c-8bcf-4053-a814-ab1c396d0a67';
  $display->content['new-0653ac2c-8bcf-4053-a814-ab1c396d0a67'] = $pane;
  $display->panels['right'][1] = 'new-0653ac2c-8bcf-4053-a814-ab1c396d0a67';
  $pane = new stdClass();
  $pane->pid = 'new-e5b6a228-118c-4723-94e4-557aca2d86d4';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'views-d305eaa52e2b1cc18e518f4b21733969';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 0,
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e5b6a228-118c-4723-94e4-557aca2d86d4';
  $display->content['new-e5b6a228-118c-4723-94e4-557aca2d86d4'] = $pane;
  $display->panels['right'][2] = 'new-e5b6a228-118c-4723-94e4-557aca2d86d4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context_12';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = -19;
  $handler->conf = array(
    'title' => 'Constituent Committees',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'constituent-dashboard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'function nys_dashboard_variant_access',
            'php' => 'return nys_dashboard_variant_access(\'Constituent\', \'committees\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'inbox';
  $display->uuid = '7c4fd832-2d8f-420f-a296-b82d5f82c078';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context_12';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9e754187-cf1f-4095-99b2-2f58cd197da3';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-user_card_block';
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
  $pane->uuid = '9e754187-cf1f-4095-99b2-2f58cd197da3';
  $display->content['new-9e754187-cf1f-4095-99b2-2f58cd197da3'] = $pane;
  $display->panels['left'][0] = 'new-9e754187-cf1f-4095-99b2-2f58cd197da3';
  $pane = new stdClass();
  $pane->pid = 'new-02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $display->content['new-02b0b706-35c5-45a5-979e-2cf05a1eaf21'] = $pane;
  $display->panels['left'][1] = 'new-02b0b706-35c5-45a5-979e-2cf05a1eaf21';
  $pane = new stdClass();
  $pane->pid = 'new-6f7d7e25-8e67-4a4b-9384-06807f204801';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-constituent-dashboard-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Items You\'re Following',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6f7d7e25-8e67-4a4b-9384-06807f204801';
  $display->content['new-6f7d7e25-8e67-4a4b-9384-06807f204801'] = $pane;
  $display->panels['left'][2] = 'new-6f7d7e25-8e67-4a4b-9384-06807f204801';
  $pane = new stdClass();
  $pane->pid = 'new-575ac8ff-1676-41fa-81b0-57f1a74cadde';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-const_comm_flw_block';
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
  $pane->uuid = '575ac8ff-1676-41fa-81b0-57f1a74cadde';
  $display->content['new-575ac8ff-1676-41fa-81b0-57f1a74cadde'] = $pane;
  $display->panels['right'][0] = 'new-575ac8ff-1676-41fa-81b0-57f1a74cadde';
  $pane = new stdClass();
  $pane->pid = 'new-3115f051-ebe2-43f4-9768-7392d81c3753';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'constituent_committees_following';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '6',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
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
  $pane->uuid = '3115f051-ebe2-43f4-9768-7392d81c3753';
  $display->content['new-3115f051-ebe2-43f4-9768-7392d81c3753'] = $pane;
  $display->panels['right'][1] = 'new-3115f051-ebe2-43f4-9768-7392d81c3753';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dashboard'] = $page;

  return $pages;

}
