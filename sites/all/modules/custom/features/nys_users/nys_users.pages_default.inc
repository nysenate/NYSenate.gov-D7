<?php

/**
 * @file
 * nys_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_users_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_edit__panel_context_6398c854-99e9-40e6-acd2-93973e5f12fe';
  $handler->task = 'user_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_user_edit_1',
          'name' => 'role',
          'not' => FALSE,
          'settings' => array(
            'rids' => array(
              0 => 7,
            ),
          ),
        ),
        1 => array(
          'context' => 'empty',
          'name' => 'path_visibility',
          'not' => FALSE,
          'settings' => array(
            'paths' => 'user/*/edit',
            'visibility_setting' => '1',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => 'page-user-dashboard constituent-dashboard',
    'body_classes_to_remove' => '',
    'contexts' => array(
      0 => array(
        'id' => 1,
        'identifier' => 'User',
        'keyword' => 'user_2',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
      ),
    ),
    'css' => '',
    'css_id' => '',
    'name' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
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
  $display->title = '%user:field_first_name %user:field-last-name';
  $display->uuid = '1b380c48-5f90-4f8a-b078-bec0511692cd';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_edit__panel_context_6398c854-99e9-40e6-acd2-93973e5f12fe';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-39aa8836-730a-442e-ba2a-7ffaee7a8e5a';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-user_card_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '39aa8836-730a-442e-ba2a-7ffaee7a8e5a';
  $display->content['new-39aa8836-730a-442e-ba2a-7ffaee7a8e5a'] = $pane;
  $display->panels['left'][0] = 'new-39aa8836-730a-442e-ba2a-7ffaee7a8e5a';
  $pane = new stdClass();
  $pane->pid = 'new-df26eeb7-d442-4c59-ad3f-1d9c3534fa60';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'nys_dashboard-senator_card_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'df26eeb7-d442-4c59-ad3f-1d9c3534fa60';
  $display->content['new-df26eeb7-d442-4c59-ad3f-1d9c3534fa60'] = $pane;
  $display->panels['left'][1] = 'new-df26eeb7-d442-4c59-ad3f-1d9c3534fa60';
  $pane = new stdClass();
  $pane->pid = 'new-39beb5d7-16f5-4090-8209-5f8e439e658c';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-constituent-dashboard-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '39beb5d7-16f5-4090-8209-5f8e439e658c';
  $display->content['new-39beb5d7-16f5-4090-8209-5f8e439e658c'] = $pane;
  $display->panels['left'][2] = 'new-39beb5d7-16f5-4090-8209-5f8e439e658c';
  $pane = new stdClass();
  $pane->pid = 'new-d39a6f01-50c5-4460-abc8-a865fb792d9b';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'user:field_top_issue';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'formatter' => '',
    'label' => '',
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'd39a6f01-50c5-4460-abc8-a865fb792d9b';
  $display->content['new-d39a6f01-50c5-4460-abc8-a865fb792d9b'] = $pane;
  $display->panels['right'][0] = 'new-d39a6f01-50c5-4460-abc8-a865fb792d9b';
  $pane = new stdClass();
  $pane->pid = 'new-429b4f52-b20c-4ebf-9019-9849f8179656';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'user:field_first_name';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'formatter' => '',
    'label' => '',
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '429b4f52-b20c-4ebf-9019-9849f8179656';
  $display->content['new-429b4f52-b20c-4ebf-9019-9849f8179656'] = $pane;
  $display->panels['right'][1] = 'new-429b4f52-b20c-4ebf-9019-9849f8179656';
  $pane = new stdClass();
  $pane->pid = 'new-f8e2d6fc-078b-4912-b52c-777f50d1887f';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'user:field_last_name';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'formatter' => '',
    'label' => '',
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'f8e2d6fc-078b-4912-b52c-777f50d1887f';
  $display->content['new-f8e2d6fc-078b-4912-b52c-777f50d1887f'] = $pane;
  $display->panels['right'][2] = 'new-f8e2d6fc-078b-4912-b52c-777f50d1887f';
  $pane = new stdClass();
  $pane->pid = 'new-becce1aa-0311-455b-a670-0c8cc81931c1';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'user:field_address';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'formatter' => '',
    'label' => '',
    'override_title' => 0,
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
  $pane->uuid = 'becce1aa-0311-455b-a670-0c8cc81931c1';
  $display->content['new-becce1aa-0311-455b-a670-0c8cc81931c1'] = $pane;
  $display->panels['right'][3] = 'new-becce1aa-0311-455b-a670-0c8cc81931c1';
  $pane = new stdClass();
  $pane->pid = 'new-b5bfa19f-9acd-4eb1-a3d3-2e5f98482046';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'user:field_dateofbirth';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'formatter' => '',
    'label' => '',
    'override_title' => 0,
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
  $pane->uuid = 'b5bfa19f-9acd-4eb1-a3d3-2e5f98482046';
  $display->content['new-b5bfa19f-9acd-4eb1-a3d3-2e5f98482046'] = $pane;
  $display->panels['right'][4] = 'new-b5bfa19f-9acd-4eb1-a3d3-2e5f98482046';
  $pane = new stdClass();
  $pane->pid = 'new-abb13ca9-54b8-41a7-b915-e49e096aea52';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'user:field_gender_user';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'formatter' => '',
    'label' => '',
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'abb13ca9-54b8-41a7-b915-e49e096aea52';
  $display->content['new-abb13ca9-54b8-41a7-b915-e49e096aea52'] = $pane;
  $display->panels['right'][5] = 'new-abb13ca9-54b8-41a7-b915-e49e096aea52';
  $pane = new stdClass();
  $pane->pid = 'new-cabe7353-c741-4174-aed6-f8a9fded5bf8';
  $pane->panel = 'right';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_user_edit_1',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'cabe7353-c741-4174-aed6-f8a9fded5bf8';
  $display->content['new-cabe7353-c741-4174-aed6-f8a9fded5bf8'] = $pane;
  $display->panels['right'][6] = 'new-cabe7353-c741-4174-aed6-f8a9fded5bf8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_edit__panel_context_6398c854-99e9-40e6-acd2-93973e5f12fe'] = $handler;

  return $export;
}
