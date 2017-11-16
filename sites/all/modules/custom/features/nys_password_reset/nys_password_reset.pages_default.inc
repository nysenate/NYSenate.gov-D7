<?php
/**
 * @file
 * nys_password_reset.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_password_reset_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'password_reset';
  $page->task = 'page';
  $page->admin_title = 'Password Reset';
  $page->admin_description = 'Custom page to handle password resets, including first-time confirmation logins.';
  $page->path = 'password-reset';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_password_reset__panel';
  $handler->task = 'page';
  $handler->subtask = 'password_reset';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Password Reset',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
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
  $display->title = 'Password Reset Form';
  $display->uuid = '843ca2df-68e7-431d-aaa4-7d8f43da49d9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_password_reset__panel';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['password_reset'] = $page;

  return $pages;

}
