<?php

/**
 * @file
 * nys_legislation.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_legislation_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_6bce2d53-aaf0-42c6-a93f-588f48517ce6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Session Detail',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'session' => 'session',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'f2cb_session_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'top' => NULL,
      'bottom' => array(
        'content' => array(
          'element' => '0',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'default' => NULL,
    ),
    'style' => 'default',
    'bottom' => array(
      'style' => 'wrapper_element',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cf271ace-12ae-4f90-bb50-9e452f9dfdfb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_6bce2d53-aaf0-42c6-a93f-588f48517ce6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-49d3394b-7fa8-4e98-a8ac-966238edd076';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'news_issues_promos',
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
  $pane->uuid = '49d3394b-7fa8-4e98-a8ac-966238edd076';
  $display->content['new-49d3394b-7fa8-4e98-a8ac-966238edd076'] = $pane;
  $display->panels['bottom'][0] = 'new-49d3394b-7fa8-4e98-a8ac-966238edd076';
  $pane = new stdClass();
  $pane->pid = 'new-68d1acc0-2211-49b4-be49-2d12e4a1c653';
  $pane->panel = 'bottom';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-how_senate_works_block';
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
  $pane->uuid = '68d1acc0-2211-49b4-be49-2d12e4a1c653';
  $display->content['new-68d1acc0-2211-49b4-be49-2d12e4a1c653'] = $pane;
  $display->panels['bottom'][1] = 'new-68d1acc0-2211-49b4-be49-2d12e4a1c653';
  $pane = new stdClass();
  $pane->pid = 'new-5bab3feb-8c80-40d1-9560-6a69eaf08494';
  $pane->panel = 'top';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '5bab3feb-8c80-40d1-9560-6a69eaf08494';
  $display->content['new-5bab3feb-8c80-40d1-9560-6a69eaf08494'] = $pane;
  $display->panels['top'][0] = 'new-5bab3feb-8c80-40d1-9560-6a69eaf08494';
  $pane = new stdClass();
  $pane->pid = 'new-8f63e2bc-5175-477f-a148-d96337e61db9';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
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
    'display' => 'sess_active_list_content',
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
  $pane->uuid = '8f63e2bc-5175-477f-a148-d96337e61db9';
  $display->content['new-8f63e2bc-5175-477f-a148-d96337e61db9'] = $pane;
  $display->panels['top'][1] = 'new-8f63e2bc-5175-477f-a148-d96337e61db9';
  $pane = new stdClass();
  $pane->pid = 'new-fc308bb0-ace5-4d42-8cd6-776a34b8d50c';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
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
    'display' => 'sess_floor_calendar',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'context' => array(
      0 => '',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fc308bb0-ace5-4d42-8cd6-776a34b8d50c';
  $display->content['new-fc308bb0-ace5-4d42-8cd6-776a34b8d50c'] = $pane;
  $display->panels['top'][2] = 'new-fc308bb0-ace5-4d42-8cd6-776a34b8d50c';
  $pane = new stdClass();
  $pane->pid = 'new-d25dd948-c7d5-4b4f-a446-08ce3024ef38';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
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
    'display' => 'sess_supplemental_calendar',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'context' => array(
      0 => '',
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
  $pane->uuid = 'd25dd948-c7d5-4b4f-a446-08ce3024ef38';
  $display->content['new-d25dd948-c7d5-4b4f-a446-08ce3024ef38'] = $pane;
  $display->panels['top'][3] = 'new-d25dd948-c7d5-4b4f-a446-08ce3024ef38';
  $pane = new stdClass();
  $pane->pid = 'new-1e69ae37-fd5b-47ab-b5be-fbd3bcbbfb86';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_transcript';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '1e69ae37-fd5b-47ab-b5be-fbd3bcbbfb86';
  $display->content['new-1e69ae37-fd5b-47ab-b5be-fbd3bcbbfb86'] = $pane;
  $display->panels['top'][4] = 'new-1e69ae37-fd5b-47ab-b5be-fbd3bcbbfb86';
  $pane = new stdClass();
  $pane->pid = 'new-b9ea37a6-285c-4b70-a3bc-24c05a80f2b5';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-simple_social_bar';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-block--session-shares',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'b9ea37a6-285c-4b70-a3bc-24c05a80f2b5';
  $display->content['new-b9ea37a6-285c-4b70-a3bc-24c05a80f2b5'] = $pane;
  $display->panels['top'][5] = 'new-b9ea37a6-285c-4b70-a3bc-24c05a80f2b5';
  $pane = new stdClass();
  $pane->pid = 'new-f562087e-bd09-4d56-89e8-e92bd2b790f8';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-node_related_issues';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'f562087e-bd09-4d56-89e8-e92bd2b790f8';
  $display->content['new-f562087e-bd09-4d56-89e8-e92bd2b790f8'] = $pane;
  $display->panels['top'][6] = 'new-f562087e-bd09-4d56-89e8-e92bd2b790f8';
  $pane = new stdClass();
  $pane->pid = 'new-52cf3d8a-4b99-4871-970c-e28f6db5fbb2';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'previous_sessions';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'previous_sessions',
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
  $pane->uuid = '52cf3d8a-4b99-4871-970c-e28f6db5fbb2';
  $display->content['new-52cf3d8a-4b99-4871-970c-e28f6db5fbb2'] = $pane;
  $display->panels['top'][7] = 'new-52cf3d8a-4b99-4871-970c-e28f6db5fbb2';
  $pane = new stdClass();
  $pane->pid = 'new-7697513a-5156-4f27-84e1-c4b73308ffc8';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'session_detail_calendar_list',
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
  $pane->uuid = '7697513a-5156-4f27-84e1-c4b73308ffc8';
  $display->content['new-7697513a-5156-4f27-84e1-c4b73308ffc8'] = $pane;
  $display->panels['top'][8] = 'new-7697513a-5156-4f27-84e1-c4b73308ffc8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_6bce2d53-aaf0-42c6-a93f-588f48517ce6'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_legislation_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'legislation';
  $page->task = 'page';
  $page->admin_title = 'Legislation';
  $page->admin_description = '';
  $page->path = 'legislation';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Legislation',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_legislation_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'legislation';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Legislation',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'f2cb_legislation';
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
  $display->title = 'Bills & Laws';
  $display->uuid = '0550b341-c65e-4b9f-ba2b-01306aa2f53a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_legislation_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-26ecdd5f-1704-4655-a346-fd030fd6f902';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'news_issues_promos',
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
  $pane->uuid = '26ecdd5f-1704-4655-a346-fd030fd6f902';
  $display->content['new-26ecdd5f-1704-4655-a346-fd030fd6f902'] = $pane;
  $display->panels['bottom'][0] = 'new-26ecdd5f-1704-4655-a346-fd030fd6f902';
  $pane = new stdClass();
  $pane->pid = 'new-8954afd8-171f-4e8a-8ba8-f8fd8eee8796';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
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
    'display' => 'passed_senate',
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
  $pane->uuid = '8954afd8-171f-4e8a-8ba8-f8fd8eee8796';
  $display->content['new-8954afd8-171f-4e8a-8ba8-f8fd8eee8796'] = $pane;
  $display->panels['tabs'][0] = 'new-8954afd8-171f-4e8a-8ba8-f8fd8eee8796';
  $pane = new stdClass();
  $pane->pid = 'new-75c770c9-f727-40ac-a866-8063a1cfa1e2';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
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
    'display' => 'signed_by_governor',
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
  $pane->uuid = '75c770c9-f727-40ac-a866-8063a1cfa1e2';
  $display->content['new-75c770c9-f727-40ac-a866-8063a1cfa1e2'] = $pane;
  $display->panels['tabs'][1] = 'new-75c770c9-f727-40ac-a866-8063a1cfa1e2';
  $pane = new stdClass();
  $pane->pid = 'new-ef40603e-4a22-4d7d-ac75-62e3bdfd7918';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-legislation_bills_and_laws_intro';
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
  $pane->uuid = 'ef40603e-4a22-4d7d-ac75-62e3bdfd7918';
  $display->content['new-ef40603e-4a22-4d7d-ac75-62e3bdfd7918'] = $pane;
  $display->panels['top'][0] = 'new-ef40603e-4a22-4d7d-ac75-62e3bdfd7918';
  $pane = new stdClass();
  $pane->pid = 'new-14564126-78be-4f5b-bfde-f776b445da6f';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-how_senate_works_block';
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
  $pane->uuid = '14564126-78be-4f5b-bfde-f776b445da6f';
  $display->content['new-14564126-78be-4f5b-bfde-f776b445da6f'] = $pane;
  $display->panels['top'][1] = 'new-14564126-78be-4f5b-bfde-f776b445da6f';
  $pane = new stdClass();
  $pane->pid = 'new-a562b77d-0b97-4503-90bc-c55c08ae1f6e';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-leg_leg_accordion';
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
  $pane->uuid = 'a562b77d-0b97-4503-90bc-c55c08ae1f6e';
  $display->content['new-a562b77d-0b97-4503-90bc-c55c08ae1f6e'] = $pane;
  $display->panels['top'][2] = 'new-a562b77d-0b97-4503-90bc-c55c08ae1f6e';
  $pane = new stdClass();
  $pane->pid = 'new-3ab166ca-28bc-4a5e-92f7-f3db77e92f15';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
  $pane->shown = FALSE;
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
    'display' => 'floor_calendar',
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
  $pane->uuid = '3ab166ca-28bc-4a5e-92f7-f3db77e92f15';
  $display->content['new-3ab166ca-28bc-4a5e-92f7-f3db77e92f15'] = $pane;
  $display->panels['top'][3] = 'new-3ab166ca-28bc-4a5e-92f7-f3db77e92f15';
  $pane = new stdClass();
  $pane->pid = 'new-4aa66579-faa1-45ba-8a0f-ec8012563223';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
  $pane->shown = FALSE;
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
    'display' => 'active_list',
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
  $pane->uuid = '4aa66579-faa1-45ba-8a0f-ec8012563223';
  $display->content['new-4aa66579-faa1-45ba-8a0f-ec8012563223'] = $pane;
  $display->panels['top'][4] = 'new-4aa66579-faa1-45ba-8a0f-ec8012563223';
  $pane = new stdClass();
  $pane->pid = 'new-9379fa1f-a75d-4f77-ab4f-71088c1d2ac7';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'upcoming_legislation_calendar';
  $pane->shown = FALSE;
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
    'display' => 'supplemental_calendar',
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
  $pane->uuid = '9379fa1f-a75d-4f77-ab4f-71088c1d2ac7';
  $display->content['new-9379fa1f-a75d-4f77-ab4f-71088c1d2ac7'] = $pane;
  $display->panels['top'][5] = 'new-9379fa1f-a75d-4f77-ab4f-71088c1d2ac7';
  $pane = new stdClass();
  $pane->pid = 'new-deb0b408-b088-4c6d-b92d-26e91743226d';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-up_to';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'deb0b408-b088-4c6d-b92d-26e91743226d';
  $display->content['new-deb0b408-b088-4c6d-b92d-26e91743226d'] = $pane;
  $display->panels['top'][6] = 'new-deb0b408-b088-4c6d-b92d-26e91743226d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['legislation'] = $page;

  return $pages;

}
