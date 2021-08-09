<?php

/**
 * @file
 * nys_student_submissions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_student_submissions_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__earth-day';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        1 => array(
          'name' => 'php',
          'not' => FALSE,
          'settings' => array(
            'description' => 'node_has_senator_nid',
            'php' => 'return node_has_senator_nid($contexts["argument_entity_id:node_1"]->data);',
          ),
        ),
        2 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'entity_field_value:node:article:field_issues',
          'not' => FALSE,
          'settings' => array(
            'field_issues' => array(
              'und' => array(
                0 => array(
                  'tid' => '6986',
                ),
              ),
            ),
            'field_issues_tid' => array(
              0 => '6986',
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
    'name' => 'earth-day',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Earth Day',
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'bottom' => array(
      'style' => 'wrapper_element',
    ),
    'style' => 'default',
    'style_settings' => array(
      'bottom' => array(
        'content' => array(
          'attributes' => array(
            'class' => '',
            'id' => '',
          ),
          'element' => '',
        ),
        'theme' => 0,
      ),
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cf271ace-12ae-4f90-bb50-9e452f9dfdfb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__earth-day';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b10b80c8-191f-4ff2-8ec4-84c63a9312f0';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'identifier' => '',
    'leave_node_title' => 0,
    'link' => 0,
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b10b80c8-191f-4ff2-8ec4-84c63a9312f0';
  $display->content['new-b10b80c8-191f-4ff2-8ec4-84c63a9312f0'] = $pane;
  $display->panels['middle'][0] = 'new-b10b80c8-191f-4ff2-8ec4-84c63a9312f0';
  $pane = new stdClass();
  $pane->pid = 'new-44d5b68b-9124-4a96-b5c7-1363b3742ed6';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_3',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '44d5b68b-9124-4a96-b5c7-1363b3742ed6';
  $display->content['new-44d5b68b-9124-4a96-b5c7-1363b3742ed6'] = $pane;
  $display->panels['middle'][1] = 'new-44d5b68b-9124-4a96-b5c7-1363b3742ed6';
  $pane = new stdClass();
  $pane->pid = 'new-70a54e75-7542-4007-99cd-6f8728f6b67c';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_news_article_footer',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '70a54e75-7542-4007-99cd-6f8728f6b67c';
  $display->content['new-70a54e75-7542-4007-99cd-6f8728f6b67c'] = $pane;
  $display->panels['middle'][2] = 'new-70a54e75-7542-4007-99cd-6f8728f6b67c';
  $pane = new stdClass();
  $pane->pid = 'new-2502f9a7-21b2-4a29-a0b3-25167b031bf4';
  $pane->panel = 'middle';
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
    'override_title_heading' => 'h2',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2502f9a7-21b2-4a29-a0b3-25167b031bf4';
  $display->content['new-2502f9a7-21b2-4a29-a0b3-25167b031bf4'] = $pane;
  $display->panels['middle'][3] = 'new-2502f9a7-21b2-4a29-a0b3-25167b031bf4';
  $pane = new stdClass();
  $pane->pid = 'new-dc467b83-949f-4a04-930b-c39df0e8a100';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-how_senate_works_block';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'name' => 'node_type',
        'not' => FALSE,
        'settings' => array(
          'type' => array(
            'event' => 'event',
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'dc467b83-949f-4a04-930b-c39df0e8a100';
  $display->content['new-dc467b83-949f-4a04-930b-c39df0e8a100'] = $pane;
  $display->panels['middle'][4] = 'new-dc467b83-949f-4a04-930b-c39df0e8a100';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__earth-day'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_student_submissions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'earth_day_2017';
  $page->task = 'page';
  $page->admin_title = 'Earth Day';
  $page->admin_description = '';
  $page->path = 'node/%node/earthday';
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
      2 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 1,
            1 => 6,
          ),
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
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
  $handler->name = 'page_earth_day_2017__panel_context_e0d1e98b-9c68-45d5-a45a-2f268861334a';
  $handler->task = 'page';
  $handler->subtask = 'earth_day_2017';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
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
          'name' => 'entity_field_value:node:senator:field_last_name',
          'not' => FALSE,
          'settings' => array(
            'field_last_name' => array(
              'und' => array(
                0 => array(
                  'format' => '',
                  'value' => 'Stewart-Cousins',
                ),
              ),
            ),
            'field_last_name_format' => array(
              0 => '',
            ),
            'field_last_name_value' => array(
              0 => 'Stewart-Cousins',
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'delta' => 0,
        'id' => 1,
        'identifier' => 'Content from Content (on Content: Senator [field_senator])',
        'keyword' => 'Senator',
        'name' => 'entity_from_field:field_senator-node-node',
      ),
    ),
    'title' => 'Majority Leader',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_earthday';
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
  $display->title = '';
  $display->uuid = 'ec903ef9-9a29-45cb-8724-3da49a1e0cf7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_earth_day_2017__panel_context_e0d1e98b-9c68-45d5-a45a-2f268861334a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5727b2e6-4ee3-44b1-944e-ad5d2301f01b';
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
  $pane->uuid = '5727b2e6-4ee3-44b1-944e-ad5d2301f01b';
  $display->content['new-5727b2e6-4ee3-44b1-944e-ad5d2301f01b'] = $pane;
  $display->panels['bottom'][0] = 'new-5727b2e6-4ee3-44b1-944e-ad5d2301f01b';
  $pane = new stdClass();
  $pane->pid = 'new-d1393005-04e0-42bf-b815-56a78e259bc9';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '2021 Poster Submissions',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
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
  $pane->uuid = 'd1393005-04e0-42bf-b815-56a78e259bc9';
  $display->content['new-d1393005-04e0-42bf-b815-56a78e259bc9'] = $pane;
  $display->panels['tabs'][0] = 'new-d1393005-04e0-42bf-b815-56a78e259bc9';
  $pane = new stdClass();
  $pane->pid = 'new-37b1c751-eee8-44de-848e-d3a4d31a948a';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_4',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '37b1c751-eee8-44de-848e-d3a4d31a948a';
  $display->content['new-37b1c751-eee8-44de-848e-d3a4d31a948a'] = $pane;
  $display->panels['tabs'][1] = 'new-37b1c751-eee8-44de-848e-d3a4d31a948a';
  $pane = new stdClass();
  $pane->pid = 'new-f01aa8bb-32e6-47bc-9b27-0d2e6c0d7eb7';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_student_earthday_letter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'hidden',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '2021 Earth Day Poster Contest Celebration',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f01aa8bb-32e6-47bc-9b27-0d2e6c0d7eb7';
  $display->content['new-f01aa8bb-32e6-47bc-9b27-0d2e6c0d7eb7'] = $pane;
  $display->panels['top'][0] = 'new-f01aa8bb-32e6-47bc-9b27-0d2e6c0d7eb7';
  $pane = new stdClass();
  $pane->pid = 'new-613478fc-a92e-4687-a2df-b1da93ae0187';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sincerely',
    'body' => '<div class="p-regular">Sincerely,<br>
<br>
Andrea Stewart-Cousins<br>
New York State Senator, District 35<br>
President Pro Tem, Majority Leader</div>
',
    'format' => 'source_html',
    'substitute' => 1,
    'title' => '',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '613478fc-a92e-4687-a2df-b1da93ae0187';
  $display->content['new-613478fc-a92e-4687-a2df-b1da93ae0187'] = $pane;
  $display->panels['top'][1] = 'new-613478fc-a92e-4687-a2df-b1da93ae0187';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-f01aa8bb-32e6-47bc-9b27-0d2e6c0d7eb7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_earth_day_2017__panel';
  $handler->task = 'page';
  $handler->subtask = 'earth_day_2017';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
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
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'delta' => 0,
        'id' => 1,
        'identifier' => 'Content from Content (on Content: Senator [field_senator])',
        'keyword' => 'Senator',
        'name' => 'entity_from_field:field_senator-node-node',
      ),
    ),
    'title' => 'Earth Day',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_earthday';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'bottom' => NULL,
      'default' => NULL,
      'middle' => NULL,
      'tabs' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Earth Day 2017 Poster Submissions ';
  $display->uuid = '628c1965-7bd8-4b6b-882b-3381e2adef49';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_earth_day_2017__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e0157d12-e09e-4fac-a674-73e955390ce0';
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
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'e0157d12-e09e-4fac-a674-73e955390ce0';
  $display->content['new-e0157d12-e09e-4fac-a674-73e955390ce0'] = $pane;
  $display->panels['bottom'][0] = 'new-e0157d12-e09e-4fac-a674-73e955390ce0';
  $pane = new stdClass();
  $pane->pid = 'new-cc43c7e7-0028-4275-a1da-ffdf34848353';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'block_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '2021 Poster Submissions',
    'pager_id' => '0',
    'panel_args' => 1,
    'url' => '',
    'use_pager' => 0,
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
  $pane->uuid = 'cc43c7e7-0028-4275-a1da-ffdf34848353';
  $display->content['new-cc43c7e7-0028-4275-a1da-ffdf34848353'] = $pane;
  $display->panels['tabs'][0] = 'new-cc43c7e7-0028-4275-a1da-ffdf34848353';
  $pane = new stdClass();
  $pane->pid = 'new-35dbd87a-6417-4d64-98b2-b9ebf96cb209';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_4',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '35dbd87a-6417-4d64-98b2-b9ebf96cb209';
  $display->content['new-35dbd87a-6417-4d64-98b2-b9ebf96cb209'] = $pane;
  $display->panels['tabs'][1] = 'new-35dbd87a-6417-4d64-98b2-b9ebf96cb209';
  $pane = new stdClass();
  $pane->pid = 'new-fb884470-2bad-4d4c-b45d-342128108314';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_5',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fb884470-2bad-4d4c-b45d-342128108314';
  $display->content['new-fb884470-2bad-4d4c-b45d-342128108314'] = $pane;
  $display->panels['tabs'][2] = 'new-fb884470-2bad-4d4c-b45d-342128108314';
  $pane = new stdClass();
  $pane->pid = 'new-c9805355-97d6-417d-a997-5165f2017916';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_student_earthday_letter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_field:field_senator-node-node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'hidden',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '2021 Earth Day Poster Contest Celebration',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c9805355-97d6-417d-a997-5165f2017916';
  $display->content['new-c9805355-97d6-417d-a997-5165f2017916'] = $pane;
  $display->panels['top'][0] = 'new-c9805355-97d6-417d-a997-5165f2017916';
  $pane = new stdClass();
  $pane->pid = 'new-784663eb-a5c3-47c8-8c2d-89a95045312c';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'relationship_entity_from_field:field_senator-node-node_1.nid',
    ),
    'display' => 'block_3',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '784663eb-a5c3-47c8-8c2d-89a95045312c';
  $display->content['new-784663eb-a5c3-47c8-8c2d-89a95045312c'] = $pane;
  $display->panels['top'][1] = 'new-784663eb-a5c3-47c8-8c2d-89a95045312c';
  $pane = new stdClass();
  $pane->pid = 'new-b545324d-5d57-491d-b80b-654684922afe';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sincerely',
    'body' => '<div class="p-regular">Sincerely,</div>
',
    'format' => 'source_html',
    'substitute' => 1,
    'title' => '',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b545324d-5d57-491d-b80b-654684922afe';
  $display->content['new-b545324d-5d57-491d-b80b-654684922afe'] = $pane;
  $display->panels['top'][2] = 'new-b545324d-5d57-491d-b80b-654684922afe';
  $pane = new stdClass();
  $pane->pid = 'new-fb6f6385-cd7d-4ecd-bcfc-5fe51eaa52f2';
  $pane->panel = 'top';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'class' => 'p-regular',
    'context' => 'relationship_entity_from_field:field_senator-node-node_1',
    'id' => '',
    'link' => 0,
    'markup' => 'div',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'fb6f6385-cd7d-4ecd-bcfc-5fe51eaa52f2';
  $display->content['new-fb6f6385-cd7d-4ecd-bcfc-5fe51eaa52f2'] = $pane;
  $display->panels['top'][3] = 'new-fb6f6385-cd7d-4ecd-bcfc-5fe51eaa52f2';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-c9805355-97d6-417d-a997-5165f2017916';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['earth_day_2017'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'participatory_budgeting';
  $page->task = 'page';
  $page->admin_title = 'Participatory Budgeting';
  $page->admin_description = '';
  $page->path = 'node/%node/pb-projects';
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
    'node' => array(
      'id' => 1,
      'identifier' => 'Content: ID',
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
  $handler->name = 'page_participatory_budgeting__panel';
  $handler->task = 'page';
  $handler->subtask = 'participatory_budgeting';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => 'pbudget-map-page',
    'name' => 'panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Participatory Budgeting Map and List',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_pbudget';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'bottom' => NULL,
      'default' => NULL,
      'middle' => NULL,
      'tabs' => array(
        'active_border_color' => '#9C905C',
        'active_content_border_color' => '#FFF',
        'activetab_bg' => '#B5AC5F',
        'closed' => '0',
        'fit' => '1',
        'inactive_bg' => '#E0D78C',
        'tabidentify' => 'map',
        'type' => 'default',
        'width' => 'auto',
      ),
      'top' => NULL,
    ),
    'tabs' => array(
      'style' => 'panels_responsive_tabs',
    ),
  );
  $display->cache = array();
  $display->title = 'Participatory Budgeting in Senate District 20';
  $display->uuid = '62bca53d-2d44-4c1a-a33a-71421731c1a5';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_participatory_budgeting__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e0517bf0-7845-4af7-b800-e7212844d223';
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
  $pane->uuid = 'e0517bf0-7845-4af7-b800-e7212844d223';
  $display->content['new-e0517bf0-7845-4af7-b800-e7212844d223'] = $pane;
  $display->panels['bottom'][0] = 'new-e0517bf0-7845-4af7-b800-e7212844d223';
  $pane = new stdClass();
  $pane->pid = 'new-e9341c89-e6d4-4b17-a165-8195569ed90d';
  $pane->panel = 'tabs';
  $pane->type = 'views_panes';
  $pane->subtype = 'participatory_budgeting_map-pbudget_map';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e9341c89-e6d4-4b17-a165-8195569ed90d';
  $display->content['new-e9341c89-e6d4-4b17-a165-8195569ed90d'] = $pane;
  $display->panels['tabs'][0] = 'new-e9341c89-e6d4-4b17-a165-8195569ed90d';
  $pane = new stdClass();
  $pane->pid = 'new-0ce7d79c-7d08-47d4-8eb9-ab0347b9befd';
  $pane->panel = 'tabs';
  $pane->type = 'views_panes';
  $pane->subtype = 'participatory_budgeting_map-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0ce7d79c-7d08-47d4-8eb9-ab0347b9befd';
  $display->content['new-0ce7d79c-7d08-47d4-8eb9-ab0347b9befd'] = $pane;
  $display->panels['tabs'][1] = 'new-0ce7d79c-7d08-47d4-8eb9-ab0347b9befd';
  $pane = new stdClass();
  $pane->pid = 'new-3616ff63-1a9a-44b1-90d9-3266611eca4a';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Description',
    'body' => '<div class="c-block c-block--img"><img alt="" height="377" src="/sites/default/files/pb_flyer_web_banner_aug_v1.jpg" width="760"></div>

<p>Welcome to District 20 Participatory Budgeting Page. Below you will find the list of proposed projects. <a href="/senators/jesse-hamilton/pb">Find out&nbsp;more about the Participatory Budget process&nbsp;here</a>.</p>

<p><a class="c-paragraph--more-link a-left" href="/senators/jesse-hamilton/pb-form">To propose a project or volunteer, fill out an online form</a></p>
',
    'format' => 'source_html',
    'substitute' => 1,
    'title' => 'Proposed Participatory Budgeting Projects in District 20',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3616ff63-1a9a-44b1-90d9-3266611eca4a';
  $display->content['new-3616ff63-1a9a-44b1-90d9-3266611eca4a'] = $pane;
  $display->panels['top'][0] = 'new-3616ff63-1a9a-44b1-90d9-3266611eca4a';
  $pane = new stdClass();
  $pane->pid = 'new-7cf08ae6-be62-4438-b67b-fbcac095ca1c';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Ballot',
    'body' => '<h2>Participatory Budgeting Ballot&nbsp;dated 8/1/18</h2>

<p><em><strong>August 6-12, 2018</strong></em></p>

<ul>
	<li>You may cast up to 5 votes</li>
	<li>If you make a mistake, ask for a new ballot</li>
	<li>You may only vote once</li>
	<li>Do not fold ballot</li>
	<li>Every ballot must have an affidavit</li>
</ul>

<p>&nbsp;</p>

<h3>Education</h3>

<p><strong>1. The Dream of STEAM for the MECP Team — $235,000</strong><br>
Medgar Evers College Prep: Buy STEAM Science Carts with classroom upgrades to provide the best in science education.</p>

<p><strong>2. Homes for their Tomes — $145,000</strong><br>
There are no lockers at PS375 Jackie-Robinson School in Crown Heights, so students are forced to carry all their belongings throughout the day. The students need lockers to help their classroom environment become places of learning instead of storage and to improve overall school climate and culture.</p>

<p><strong>3. Lights! Curtains! Action! —$125,000</strong><br>
Provide infrastructure upgrade auditorium: new window and stage curtains for PS 235 in East Flatbush.</p>

<p>&nbsp;</p>

<h3>Housing</h3>

<p><strong>4. Safety for our Seniors — $75,000</strong><br>
Security cameras at Marcus Garvey Senior Center.</p>

<p>&nbsp;</p>

<h3>Transportation and Street Safety</h3>

<p><strong>5. Smoothing the Way in Brooklyn — $250,000</strong><br>
Street repaving in Brooklyn Community Boards 17, 16 &amp; 9 (East Flatbush, PLG, Brownsville, etc.).</p>

<p><strong>6. Safe Passage to School — $220,000</strong><br>
Safety improvements including sidewalk extensions, and pedestrian safety islands at Our Lady of Perpetual Help and P.S. 169 in Sunset Park.</p>

<p>&nbsp;</p>

<h3>Parks &amp; Recreation</h3>

<p><strong>7. Making a Rough Gem Shine — $500,000</strong><br>
General improvements at Lincoln Terrace/Adult fitness or pavement.</p>

<p><strong>8. More Greensville for Brownville — $120,000</strong><br>
Gardens in Brownsville need water, so this would provide water spigots for Isabahlia Gardens on Saratoga Avenue and the Student Farm at 514 Rockaway Avenue.</p>

<p>&nbsp;</p>

<h3>Safety</h3>

<p><strong>9. Making the Walk Home Safer — $150,000</strong><br>
Fund and install NYPD security cameras for Wingate Park are, Prospect Lefferts Garden, East Flatbush, and beyond. These security cameras would enhance crime prevention (Locations at NYPD discretion).</p>

<p>&nbsp;</p>
',
    'format' => 'source_html',
    'substitute' => 1,
    'title' => '',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7cf08ae6-be62-4438-b67b-fbcac095ca1c';
  $display->content['new-7cf08ae6-be62-4438-b67b-fbcac095ca1c'] = $pane;
  $display->panels['top'][1] = 'new-7cf08ae6-be62-4438-b67b-fbcac095ca1c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['participatory_budgeting'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'thankful_2106';
  $page->task = 'page';
  $page->admin_title = 'Thanksgiving';
  $page->admin_description = '';
  $page->path = 'node/%node/thankful';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
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
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 1,
            1 => 6,
            2 => 10,
            3 => 17,
          ),
        ),
      ),
      3 => array(
        'context' => 'argument_entity_id:node_1',
        'name' => 'context_exists',
        'not' => FALSE,
        'settings' => array(
          'exists' => '1',
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
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
  $handler->name = 'page_thankful_2106__panel_context_a4731ea8-4f7f-42dd-b0b5-489f2076d86d';
  $handler->task = 'page';
  $handler->subtask = 'thankful_2106';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'entity_field_value:node:senator:field_last_name',
          'not' => FALSE,
          'settings' => array(
            'field_last_name' => array(
              'und' => array(
                0 => array(
                  'format' => '',
                  'value' => 'Stewart-Cousins',
                ),
              ),
            ),
            'field_last_name_format' => array(
              0 => '',
            ),
            'field_last_name_value' => array(
              0 => 'Stewart-Cousins',
            ),
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
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Majority Leader',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '582d5fbb-45e0-45a2-8405-e4035510d73c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_thankful_2106__panel_context_a4731ea8-4f7f-42dd-b0b5-489f2076d86d';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e92ad99a-740b-4b1f-b1f7-6df459e9f587';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_student_thankful_letter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'hidden',
    'override_title' => 1,
    'override_title_heading' => 'h1',
    'override_title_text' => '2020 Thanksgiving Day Creative Celebration',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e92ad99a-740b-4b1f-b1f7-6df459e9f587';
  $display->content['new-e92ad99a-740b-4b1f-b1f7-6df459e9f587'] = $pane;
  $display->panels['center'][0] = 'new-e92ad99a-740b-4b1f-b1f7-6df459e9f587';
  $pane = new stdClass();
  $pane->pid = 'new-51ea16fa-7e62-4f7e-af25-9901d2dc550d';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_6',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '51ea16fa-7e62-4f7e-af25-9901d2dc550d';
  $display->content['new-51ea16fa-7e62-4f7e-af25-9901d2dc550d'] = $pane;
  $display->panels['center'][1] = 'new-51ea16fa-7e62-4f7e-af25-9901d2dc550d';
  $pane = new stdClass();
  $pane->pid = 'new-5677c49d-daf8-4d4f-a047-007fc60b7c4e';
  $pane->panel = 'center';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5677c49d-daf8-4d4f-a047-007fc60b7c4e';
  $display->content['new-5677c49d-daf8-4d4f-a047-007fc60b7c4e'] = $pane;
  $display->panels['center'][2] = 'new-5677c49d-daf8-4d4f-a047-007fc60b7c4e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e92ad99a-740b-4b1f-b1f7-6df459e9f587';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_thankful_2106__panel';
  $handler->task = 'page';
  $handler->subtask = 'thankful_2106';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
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
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Thanksgiving',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2da98002-1db5-4936-a3a9-e0332684a8e2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_thankful_2106__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c4166b03-8a9e-469a-abf3-aac5b940c332';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_student_thankful_letter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'hidden',
    'override_title' => 1,
    'override_title_heading' => 'h1',
    'override_title_text' => '2020 Thanksgiving Day Creative Celebration',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c4166b03-8a9e-469a-abf3-aac5b940c332';
  $display->content['new-c4166b03-8a9e-469a-abf3-aac5b940c332'] = $pane;
  $display->panels['middle'][0] = 'new-c4166b03-8a9e-469a-abf3-aac5b940c332';
  $pane = new stdClass();
  $pane->pid = 'new-f01a5793-d8db-4136-88ce-689b72239ce1';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'f01a5793-d8db-4136-88ce-689b72239ce1';
  $display->content['new-f01a5793-d8db-4136-88ce-689b72239ce1'] = $pane;
  $display->panels['middle'][1] = 'new-f01a5793-d8db-4136-88ce-689b72239ce1';
  $pane = new stdClass();
  $pane->pid = 'new-d840e82a-ff88-4f86-bc34-79e5a7a3c002';
  $pane->panel = 'middle';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd840e82a-ff88-4f86-bc34-79e5a7a3c002';
  $display->content['new-d840e82a-ff88-4f86-bc34-79e5a7a3c002'] = $pane;
  $display->panels['middle'][2] = 'new-d840e82a-ff88-4f86-bc34-79e5a7a3c002';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['thankful_2106'] = $page;

  return $pages;

}
