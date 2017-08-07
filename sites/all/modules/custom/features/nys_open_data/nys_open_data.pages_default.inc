<?php
/**
 * @file
 * nys_open_data.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_open_data_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_open_data__open_data';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'open_data';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Open Data',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'open-data-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'open_data',
    'access' => array(
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
  $display->uuid = '6f4ef59b-5c23-4469-bd68-e6f5e10292fa';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'pm_existing_pages_open_data__open_data';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-554a691f-ec07-423e-a558-5bf371e8e088';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'open_data';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '19',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page_1',
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
  $pane->uuid = '554a691f-ec07-423e-a558-5bf371e8e088';
  $display->content['new-554a691f-ec07-423e-a558-5bf371e8e088'] = $pane;
  $display->panels['middle'][0] = 'new-554a691f-ec07-423e-a558-5bf371e8e088';
  $pane = new stdClass();
  $pane->pid = 'new-a199a692-67ee-4342-ba82-3c695523f115';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'nodequeue_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
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
  $pane->uuid = 'a199a692-67ee-4342-ba82-3c695523f115';
  $display->content['new-a199a692-67ee-4342-ba82-3c695523f115'] = $pane;
  $display->panels['middle'][1] = 'new-a199a692-67ee-4342-ba82-3c695523f115';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_open_data__open_data'] = $handler;

  return $export;
}
