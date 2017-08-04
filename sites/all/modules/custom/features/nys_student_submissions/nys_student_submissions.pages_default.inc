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
    'title' => 'Earth Day',
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
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'node_has_senator_nid',
            'php' => 'return node_has_senator_nid($contexts["argument_entity_id:node_1"]->data);',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'entity_field_value:node:article:field_issues',
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
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'earth-day',
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'top' => NULL,
      'bottom' => array(
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'default' => NULL,
      'middle' => NULL,
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
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 1,
    'override_title_text' => '<none>',
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
    'display' => 'block_3',
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
    'display' => 'senator_news_article_footer',
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
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'event' => 'event',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
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
  $page->admin_title = 'Earth Day 2017';
  $page->admin_description = '';
  $page->path = 'node/%node/earthday-2017';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'senator' => 'senator',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
            1 => 6,
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
  $handler->name = 'page_earth_day_2017__panel';
  $handler->task = 'page';
  $handler->subtask = 'earth_day_2017';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Earth Day 2017',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Content from Content (on Content: Senator [field_senator])',
        'keyword' => 'Senator',
        'name' => 'entity_from_field:field_senator-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'panel',
    'access' => array(
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
      'logic' => 'and',
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
  $display->title = 'Earth Day 2017 Poster Submissions ';
  $display->uuid = '628c1965-7bd8-4b6b-882b-3381e2adef49';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_earth_day_2017__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c9805355-97d6-417d-a997-5165f2017916';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_student_earthday_letter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_entity_from_field:field_senator-node-node_1',
    'override_title' => 1,
    'override_title_text' => '2017 Earth Day Poster Contest Submissions',
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
  $pane->uuid = 'c9805355-97d6-417d-a997-5165f2017916';
  $display->content['new-c9805355-97d6-417d-a997-5165f2017916'] = $pane;
  $display->panels['middle'][0] = 'new-c9805355-97d6-417d-a997-5165f2017916';
  $pane = new stdClass();
  $pane->pid = 'new-784663eb-a5c3-47c8-8c2d-89a95045312c';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_3',
    'context' => array(
      0 => 'relationship_entity_from_field:field_senator-node-node_1.nid',
    ),
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
  $pane->uuid = '784663eb-a5c3-47c8-8c2d-89a95045312c';
  $display->content['new-784663eb-a5c3-47c8-8c2d-89a95045312c'] = $pane;
  $display->panels['middle'][1] = 'new-784663eb-a5c3-47c8-8c2d-89a95045312c';
  $pane = new stdClass();
  $pane->pid = 'new-cc43c7e7-0028-4275-a1da-ffdf34848353';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_2',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 1,
    'override_title_text' => 'All 2017 Poster Submissions',
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
  $pane->uuid = 'cc43c7e7-0028-4275-a1da-ffdf34848353';
  $display->content['new-cc43c7e7-0028-4275-a1da-ffdf34848353'] = $pane;
  $display->panels['middle'][2] = 'new-cc43c7e7-0028-4275-a1da-ffdf34848353';
  $pane = new stdClass();
  $pane->pid = 'new-e0157d12-e09e-4fac-a674-73e955390ce0';
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
  $pane->uuid = 'e0157d12-e09e-4fac-a674-73e955390ce0';
  $display->content['new-e0157d12-e09e-4fac-a674-73e955390ce0'] = $pane;
  $display->panels['middle'][3] = 'new-e0157d12-e09e-4fac-a674-73e955390ce0';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-c9805355-97d6-417d-a997-5165f2017916';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['earth_day_2017'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'thankful_2106';
  $page->task = 'page';
  $page->admin_title = 'Thankful 2106';
  $page->admin_description = '';
  $page->path = 'node/%node/thankful-2016';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(),
    'type' => 'none',
    'settings' => NULL,
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
  $handler->name = 'page_thankful_2106__panel';
  $handler->task = 'page';
  $handler->subtask = 'thankful_2106';
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
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
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
    ),
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
  $pane->pid = 'new-f01a5793-d8db-4136-88ce-689b72239ce1';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_submissions';
  $pane->shown = TRUE;
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
    'display' => 'block_1',
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
  $pane->uuid = 'f01a5793-d8db-4136-88ce-689b72239ce1';
  $display->content['new-f01a5793-d8db-4136-88ce-689b72239ce1'] = $pane;
  $display->panels['middle'][0] = 'new-f01a5793-d8db-4136-88ce-689b72239ce1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['thankful_2106'] = $page;

  return $pages;

}
