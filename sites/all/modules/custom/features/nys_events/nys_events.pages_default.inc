<?php
/**
 * @file
 * nys_events.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_events_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'senator_calendar';
  $page->task = 'page';
  $page->admin_title = 'Senator Calendar';
  $page->admin_description = '';
  $page->path = 'node/%node/calendar';
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
  $handler->name = 'page_senator_calendar_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'senator_calendar';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Calendar',
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
  $display->layout = 'f2cb_calendar';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'tabs' => NULL,
      'bottom' => NULL,
      'today' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title Calendar';
  $display->uuid = '017ac56f-fdba-4848-b018-659351ad08d4';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_senator_calendar_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-efd88282-47c7-4c32-b034-3934b619ae84';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'efd88282-47c7-4c32-b034-3934b619ae84';
  $display->content['new-efd88282-47c7-4c32-b034-3934b619ae84'] = $pane;
  $display->panels['bottom'][0] = 'new-efd88282-47c7-4c32-b034-3934b619ae84';
  $pane = new stdClass();
  $pane->pid = 'new-19941332-77d4-4a67-9880-06866cab0c28';
  $pane->panel = 'today';
  $pane->type = 'views';
  $pane->subtype = 'senator_events';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '2',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'senator_today_events',
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
  $pane->uuid = '19941332-77d4-4a67-9880-06866cab0c28';
  $display->content['new-19941332-77d4-4a67-9880-06866cab0c28'] = $pane;
  $display->panels['today'][0] = 'new-19941332-77d4-4a67-9880-06866cab0c28';
  $pane = new stdClass();
  $pane->pid = 'new-514c9a97-1c89-4bfd-9968-6a0eff280b9b';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'senator_events';
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
    'display' => 'featured_event',
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
  $pane->uuid = '514c9a97-1c89-4bfd-9968-6a0eff280b9b';
  $display->content['new-514c9a97-1c89-4bfd-9968-6a0eff280b9b'] = $pane;
  $display->panels['top'][0] = 'new-514c9a97-1c89-4bfd-9968-6a0eff280b9b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['senator_calendar'] = $page;

  return $pages;

}
