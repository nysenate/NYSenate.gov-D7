<?php
/**
 * @file
 * nys_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_search_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_apachesolr_search_panel_context';
  $handler->task = 'search';
  $handler->subtask = 'apachesolr_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Search',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'explore/issues
explore/issues/*',
          ),
          'context' => 'empty',
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
  $display->title = 'Search';
  $display->uuid = '12c56fcc-857e-4e24-9469-ef0e1bbe3a88';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'search_apachesolr_search_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0da8ba4d-4462-426c-a2a4-36a8c2255274';
  $pane->panel = 'middle';
  $pane->type = 'apachesolr_form';
  $pane->subtype = 'apachesolr_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'path_type' => 'same',
    'path' => '',
    'override_prompt' => 0,
    'prompt' => '',
    'show_keys' => 1,
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
  $pane->uuid = '0da8ba4d-4462-426c-a2a4-36a8c2255274';
  $display->content['new-0da8ba4d-4462-426c-a2a4-36a8c2255274'] = $pane;
  $display->panels['middle'][0] = 'new-0da8ba4d-4462-426c-a2a4-36a8c2255274';
  $pane = new stdClass();
  $pane->pid = 'new-4f2b3ad6-e8eb-421d-9289-506dfa85f112';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-gyH7wbGvSsVMNJAY3LG1uu7sdWxHh14P';
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
  $pane->uuid = '4f2b3ad6-e8eb-421d-9289-506dfa85f112';
  $display->content['new-4f2b3ad6-e8eb-421d-9289-506dfa85f112'] = $pane;
  $display->panels['middle'][1] = 'new-4f2b3ad6-e8eb-421d-9289-506dfa85f112';
  $pane = new stdClass();
  $pane->pid = 'new-12b83ed2-63ae-4aea-af8d-4dafecdb740e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '12b83ed2-63ae-4aea-af8d-4dafecdb740e';
  $display->content['new-12b83ed2-63ae-4aea-af8d-4dafecdb740e'] = $pane;
  $display->panels['middle'][2] = 'new-12b83ed2-63ae-4aea-af8d-4dafecdb740e';
  $pane = new stdClass();
  $pane->pid = 'new-d9ee7651-39df-4f2b-954c-73785b5cda5e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-sLTiKOwDd40I6a1o3R4tQsMqLWzf2eZQ';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd9ee7651-39df-4f2b-954c-73785b5cda5e';
  $display->content['new-d9ee7651-39df-4f2b-954c-73785b5cda5e'] = $pane;
  $display->panels['middle'][3] = 'new-d9ee7651-39df-4f2b-954c-73785b5cda5e';
  $pane = new stdClass();
  $pane->pid = 'new-74aa0eff-c0b4-4817-bc72-a2359cdb48a9';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-esi5aP16jsumHPGllhv2PepWoxTSpB1W';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '74aa0eff-c0b4-4817-bc72-a2359cdb48a9';
  $display->content['new-74aa0eff-c0b4-4817-bc72-a2359cdb48a9'] = $pane;
  $display->panels['middle'][4] = 'new-74aa0eff-c0b4-4817-bc72-a2359cdb48a9';
  $pane = new stdClass();
  $pane->pid = 'new-4265b869-7373-4343-a269-f19ee53c18fd';
  $pane->panel = 'middle';
  $pane->type = 'apachesolr_result';
  $pane->subtype = 'apachesolr_result';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'keys_action' => 'none',
    'keys' => '',
    'keys_required' => 0,
    'filters_action' => 'none',
    'filters' => '',
    'rows' => '25',
    'env_id' => '',
    'sort_action' => 'none',
    'sort' => '',
    'breadcrumb' => 1,
    'title_override' => 0,
    'title_override_text' => '',
    'empty_override' => 1,
    'empty_override_title' => 'Sorry, We Couldn\'t Find What You Were Looking For',
    'empty_override_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'empty_override_format' => 'full_html',
    'log' => 0,
    'substitute' => 0,
    'context' => 'empty',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '4265b869-7373-4343-a269-f19ee53c18fd';
  $display->content['new-4265b869-7373-4343-a269-f19ee53c18fd'] = $pane;
  $display->panels['middle'][5] = 'new-4265b869-7373-4343-a269-f19ee53c18fd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0da8ba4d-4462-426c-a2a4-36a8c2255274';
  $handler->conf['display'] = $display;
  $export['search_apachesolr_search_panel_context'] = $handler;

  return $export;
}
