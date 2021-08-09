<?php

/**
 * @file
 * nys_sitewide_elements.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_sitewide_elements_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'contact_user_panel_context';
  $handler->task = 'contact_user';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Senator',
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
  $display->uuid = 'd52b11e4-4dc3-4faf-a150-0e7cb3a36dd8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'contact_user_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fc611171-6612-4ea4-926d-5adc2cb040b1';
  $pane->panel = 'middle';
  $pane->type = 'user_contact';
  $pane->subtype = 'user_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_uid_1',
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
  $pane->uuid = 'fc611171-6612-4ea4-926d-5adc2cb040b1';
  $display->content['new-fc611171-6612-4ea4-926d-5adc2cb040b1'] = $pane;
  $display->panels['middle'][0] = 'new-fc611171-6612-4ea4-926d-5adc2cb040b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fc611171-6612-4ea4-926d-5adc2cb040b1';
  $handler->conf['display'] = $display;
  $export['contact_user_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = TRUE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit__panel_context_1e953563-e4d7-431c-9c07-da2e5a6d9f78';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => 'constituent-dashboard',
    'body_classes_to_remove' => '',
    'contexts' => array(),
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
  $display->title = '';
  $display->uuid = '0ebda63d-4cd5-4d49-b2f6-1bd6e8892fd5';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit__panel_context_1e953563-e4d7-431c-9c07-da2e5a6d9f78';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6105771f-c236-4590-9902-da3af0e13406';
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
  $pane->uuid = '6105771f-c236-4590-9902-da3af0e13406';
  $display->content['new-6105771f-c236-4590-9902-da3af0e13406'] = $pane;
  $display->panels['left'][0] = 'new-6105771f-c236-4590-9902-da3af0e13406';
  $pane = new stdClass();
  $pane->pid = 'new-df9f5653-416f-4a0a-839e-c6265bbe6a8d';
  $pane->panel = 'right';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = 'df9f5653-416f-4a0a-839e-c6265bbe6a8d';
  $display->content['new-df9f5653-416f-4a0a-839e-c6265bbe6a8d'] = $pane;
  $display->panels['right'][0] = 'new-df9f5653-416f-4a0a-839e-c6265bbe6a8d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit__panel_context_1e953563-e4d7-431c-9c07-da2e5a6d9f78'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__initiative-women';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -4;
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
              'initiative' => 'initiative',
            ),
          ),
        ),
        1 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'entity_field_value:node:initiative:field_profile_type',
          'not' => FALSE,
          'settings' => array(
            'field_profile_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'women',
                ),
              ),
            ),
            'field_profile_type_value' => array(
              0 => 'women',
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
    'name' => 'initiative-women',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'delta' => 0,
        'id' => 1,
        'identifier' => 'Content from Content (on Content: Senator [field_senator])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_senator-node-node',
      ),
    ),
    'title' => 'Initiative - Women',
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'default' => NULL,
      'footer' => NULL,
      'footer_first' => NULL,
      'footer_last' => NULL,
      'footer_middle' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title | Initiative';
  $display->uuid = '091d93ee-fe14-49a7-84e0-658fc719e151';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__initiative-women';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane->panel = 'middle';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '56e29f93-6395-4821-8abf-a3ae4578e705';
  $display->content['new-56e29f93-6395-4821-8abf-a3ae4578e705'] = $pane;
  $display->panels['middle'][0] = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane = new stdClass();
  $pane->pid = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'identifier' => '',
    'leave_node_title' => 1,
    'link' => 0,
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
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
  $pane->uuid = '1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $display->content['new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac'] = $pane;
  $display->panels['middle'][1] = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane = new stdClass();
  $pane->pid = 'new-090e743d-d60f-4069-9ad2-83d634040c3d';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'manage_profiles';
  $pane->shown = TRUE;
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
    'css_class' => 'c-block--honorees',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '090e743d-d60f-4069-9ad2-83d634040c3d';
  $display->content['new-090e743d-d60f-4069-9ad2-83d634040c3d'] = $pane;
  $display->panels['middle'][2] = 'new-090e743d-d60f-4069-9ad2-83d634040c3d';
  $pane = new stdClass();
  $pane->pid = 'new-ec814d12-8439-4631-aeb7-bad9db871c5a';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
      1 => '',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ec814d12-8439-4631-aeb7-bad9db871c5a';
  $display->content['new-ec814d12-8439-4631-aeb7-bad9db871c5a'] = $pane;
  $display->panels['middle'][3] = 'new-ec814d12-8439-4631-aeb7-bad9db871c5a';
  $pane = new stdClass();
  $pane->pid = 'new-1e3c7538-0fed-4ff7-9a99-97f62b362f23';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '1e3c7538-0fed-4ff7-9a99-97f62b362f23';
  $display->content['new-1e3c7538-0fed-4ff7-9a99-97f62b362f23'] = $pane;
  $display->panels['middle'][4] = 'new-1e3c7538-0fed-4ff7-9a99-97f62b362f23';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__initiative-women'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_05514a4a-42ac-4fc6-81f2-bdfb9c9f588d';
  $handler->task = 'node_view';
  $handler->subtask = '';
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
              'questionnaire' => 'questionnaire',
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Questionnaire',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'default' => NULL,
      'footer' => NULL,
      'footer_first' => NULL,
      'footer_last' => NULL,
      'footer_middle' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title | Questionnaire';
  $display->uuid = '091d93ee-fe14-49a7-84e0-658fc719e151';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_05514a4a-42ac-4fc6-81f2-bdfb9c9f588d';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane->panel = 'middle';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '56e29f93-6395-4821-8abf-a3ae4578e705';
  $display->content['new-56e29f93-6395-4821-8abf-a3ae4578e705'] = $pane;
  $display->panels['middle'][0] = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane = new stdClass();
  $pane->pid = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'identifier' => '',
    'leave_node_title' => 1,
    'link' => 0,
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
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
  $pane->uuid = '1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $display->content['new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac'] = $pane;
  $display->panels['middle'][1] = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane = new stdClass();
  $pane->pid = 'new-1f600603-527f-4e63-91d7-9ad955cc3e91';
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
  $pane->uuid = '1f600603-527f-4e63-91d7-9ad955cc3e91';
  $display->content['new-1f600603-527f-4e63-91d7-9ad955cc3e91'] = $pane;
  $display->panels['middle'][2] = 'new-1f600603-527f-4e63-91d7-9ad955cc3e91';
  $pane = new stdClass();
  $pane->pid = 'new-853a3fca-58b1-43ef-b145-fbc5ae96e7a5';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '853a3fca-58b1-43ef-b145-fbc5ae96e7a5';
  $display->content['new-853a3fca-58b1-43ef-b145-fbc5ae96e7a5'] = $pane;
  $display->panels['middle'][3] = 'new-853a3fca-58b1-43ef-b145-fbc5ae96e7a5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_05514a4a-42ac-4fc6-81f2-bdfb9c9f588d'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_1417153f-d49b-4eb3-b8ce-3f943573f655';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'empty',
          'name' => 'path_visibility',
          'not' => FALSE,
          'settings' => array(
            'paths' => 'manage-honoree-profiles',
            'visibility_setting' => '1',
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
    'title' => 'Manage Honoree Profiles',
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
  $display->uuid = 'e8f53606-d99b-4ef5-a5ac-b86b56c4023d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_1417153f-d49b-4eb3-b8ce-3f943573f655';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6387d1bf-cad2-41f4-94b6-73c76039c122';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'teaser',
    'context' => 'argument_entity_id:node_1',
    'identifier' => '',
    'leave_node_title' => 0,
    'link' => 1,
    'links' => 1,
    'no_extras' => 1,
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
  $pane->uuid = '6387d1bf-cad2-41f4-94b6-73c76039c122';
  $display->content['new-6387d1bf-cad2-41f4-94b6-73c76039c122'] = $pane;
  $display->panels['middle'][0] = 'new-6387d1bf-cad2-41f4-94b6-73c76039c122';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_1417153f-d49b-4eb3-b8ce-3f943573f655'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_ab9928f3-417f-4796-90d4-37e407f0c3b1';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
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
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Senator Content',
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
  $display->storage_id = 'node_view__panel_context_ab9928f3-417f-4796-90d4-37e407f0c3b1';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '70a54e75-7542-4007-99cd-6f8728f6b67c';
  $display->content['new-70a54e75-7542-4007-99cd-6f8728f6b67c'] = $pane;
  $display->panels['middle'][1] = 'new-70a54e75-7542-4007-99cd-6f8728f6b67c';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2502f9a7-21b2-4a29-a0b3-25167b031bf4';
  $display->content['new-2502f9a7-21b2-4a29-a0b3-25167b031bf4'] = $pane;
  $display->panels['middle'][2] = 'new-2502f9a7-21b2-4a29-a0b3-25167b031bf4';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'dc467b83-949f-4a04-930b-c39df0e8a100';
  $display->content['new-dc467b83-949f-4a04-930b-c39df0e8a100'] = $pane;
  $display->panels['middle'][3] = 'new-dc467b83-949f-4a04-930b-c39df0e8a100';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_ab9928f3-417f-4796-90d4-37e407f0c3b1'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_c2859a94-94b6-49fa-8a10-bd88ce84691a';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -3;
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
                  'value' => '0',
                ),
              ),
            ),
            'field_active_value' => array(
              0 => '0',
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => 'senator-inactive',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Senator Inactive',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_homepage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'default' => NULL,
      'footer' => NULL,
      'footer_first' => NULL,
      'footer_last' => NULL,
      'footer_middle' => NULL,
      'header' => NULL,
      'hero' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Senator %node:title';
  $display->uuid = '091d93ee-fe14-49a7-84e0-658fc719e151';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_c2859a94-94b6-49fa-8a10-bd88ce84691a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9528091d-1d57-4d2e-b075-a5a352cf0c4c';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-sntor_inactive_banner';
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
  $pane->uuid = '9528091d-1d57-4d2e-b075-a5a352cf0c4c';
  $display->content['new-9528091d-1d57-4d2e-b075-a5a352cf0c4c'] = $pane;
  $display->panels['content'][0] = 'new-9528091d-1d57-4d2e-b075-a5a352cf0c4c';
  $pane = new stdClass();
  $pane->pid = 'new-68a423d5-ff4b-4c41-a9ea-0d08b050abc5';
  $pane->panel = 'content';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'About Former Senator %node:title',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'c-senator-inactive-about',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '68a423d5-ff4b-4c41-a9ea-0d08b050abc5';
  $display->content['new-68a423d5-ff4b-4c41-a9ea-0d08b050abc5'] = $pane;
  $display->panels['content'][1] = 'new-68a423d5-ff4b-4c41-a9ea-0d08b050abc5';
  $pane = new stdClass();
  $pane->pid = 'new-b8b56f3e-3946-49e6-9b5e-3efda86f8b49';
  $pane->panel = 'content';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Last edited statement',
    'body' => '<div style="padding-top:24px;padding-bottom:48px;">
<p><em>Last edited by Senator %node:title\'s staff prior to last day in office.</em></p>
</div>
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
  $pane->uuid = 'b8b56f3e-3946-49e6-9b5e-3efda86f8b49';
  $display->content['new-b8b56f3e-3946-49e6-9b5e-3efda86f8b49'] = $pane;
  $display->panels['content'][2] = 'new-b8b56f3e-3946-49e6-9b5e-3efda86f8b49';
  $pane = new stdClass();
  $pane->pid = 'new-c1c8b25e-6b12-41b9-9acb-40a6ab99922c';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_featured_legislation_main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c1c8b25e-6b12-41b9-9acb-40a6ab99922c';
  $display->content['new-c1c8b25e-6b12-41b9-9acb-40a6ab99922c'] = $pane;
  $display->panels['content'][3] = 'new-c1c8b25e-6b12-41b9-9acb-40a6ab99922c';
  $pane = new stdClass();
  $pane->pid = 'new-5566a983-eae6-4ed8-a179-c86afc4cef6b';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'legislation_bills';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_homepage_legislation_bills',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '5566a983-eae6-4ed8-a179-c86afc4cef6b';
  $display->content['new-5566a983-eae6-4ed8-a179-c86afc4cef6b'] = $pane;
  $display->panels['content'][4] = 'new-5566a983-eae6-4ed8-a179-c86afc4cef6b';
  $pane = new stdClass();
  $pane->pid = 'new-6d48b677-c38b-444b-a41e-423e93990d10';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_footer';
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
  $pane->uuid = '6d48b677-c38b-444b-a41e-423e93990d10';
  $display->content['new-6d48b677-c38b-444b-a41e-423e93990d10'] = $pane;
  $display->panels['footer_first'][0] = 'new-6d48b677-c38b-444b-a41e-423e93990d10';
  $pane = new stdClass();
  $pane->pid = 'new-02a133a6-60cd-4af9-9adf-e9acb42c5412';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-global-footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'c-site-footer',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '02a133a6-60cd-4af9-9adf-e9acb42c5412';
  $display->content['new-02a133a6-60cd-4af9-9adf-e9acb42c5412'] = $pane;
  $display->panels['footer_first'][1] = 'new-02a133a6-60cd-4af9-9adf-e9acb42c5412';
  $pane = new stdClass();
  $pane->pid = 'new-0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_header_bar_block';
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
  $pane->uuid = '0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $display->content['new-0e5d23cd-8638-44a7-ba96-e450ea0a3452'] = $pane;
  $display->panels['header'][0] = 'new-0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $pane = new stdClass();
  $pane->pid = 'new-f599365d-c3a8-43fe-861f-90ce28eb01f1';
  $pane->panel = 'header';
  $pane->type = 'views';
  $pane->subtype = 'nys_senator_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'block',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
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
  $pane->uuid = 'f599365d-c3a8-43fe-861f-90ce28eb01f1';
  $display->content['new-f599365d-c3a8-43fe-861f-90ce28eb01f1'] = $pane;
  $display->panels['header'][1] = 'new-f599365d-c3a8-43fe-861f-90ce28eb01f1';
  $pane = new stdClass();
  $pane->pid = 'new-72943d03-aa1d-42f6-9a1d-0086c1151188';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-microsite_nav_block';
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
  $pane->uuid = '72943d03-aa1d-42f6-9a1d-0086c1151188';
  $display->content['new-72943d03-aa1d-42f6-9a1d-0086c1151188'] = $pane;
  $display->panels['header'][2] = 'new-72943d03-aa1d-42f6-9a1d-0086c1151188';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_c2859a94-94b6-49fa-8a10-bd88ce84691a'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_c8c299e6-d178-454e-8e74-4f6e0758cba4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
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
              'event' => 'event',
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Event Page',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'default' => NULL,
      'footer' => NULL,
      'footer_first' => NULL,
      'footer_last' => NULL,
      'footer_middle' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title | Initiative';
  $display->uuid = '091d93ee-fe14-49a7-84e0-658fc719e151';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_c8c299e6-d178-454e-8e74-4f6e0758cba4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane->panel = 'middle';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '56e29f93-6395-4821-8abf-a3ae4578e705';
  $display->content['new-56e29f93-6395-4821-8abf-a3ae4578e705'] = $pane;
  $display->panels['middle'][0] = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane = new stdClass();
  $pane->pid = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'identifier' => '',
    'leave_node_title' => 1,
    'link' => 0,
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
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
  $pane->uuid = '1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $display->content['new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac'] = $pane;
  $display->panels['middle'][1] = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane = new stdClass();
  $pane->pid = 'new-0aade494-7dd4-4436-b1af-9247946453a2';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0aade494-7dd4-4436-b1af-9247946453a2';
  $display->content['new-0aade494-7dd4-4436-b1af-9247946453a2'] = $pane;
  $display->panels['middle'][2] = 'new-0aade494-7dd4-4436-b1af-9247946453a2';
  $pane = new stdClass();
  $pane->pid = 'new-3551182a-c9e3-4c5a-8005-e5ca0bba6e64';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-how_senate_works_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3551182a-c9e3-4c5a-8005-e5ca0bba6e64';
  $display->content['new-3551182a-c9e3-4c5a-8005-e5ca0bba6e64'] = $pane;
  $display->panels['middle'][3] = 'new-3551182a-c9e3-4c5a-8005-e5ca0bba6e64';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_c8c299e6-d178-454e-8e74-4f6e0758cba4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__student_program';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
              'student_program' => 'student_program',
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => 'article-student-program',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'student_program',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Student Program',
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
  $display->uuid = '2c50c1af-e1e7-4068-b3c1-fe6029634862';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__student_program';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-049f59b9-86f2-47c0-99dc-8d703fb387cd';
  $pane->panel = 'center';
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
    'no_extras' => 1,
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
  $pane->uuid = '049f59b9-86f2-47c0-99dc-8d703fb387cd';
  $display->content['new-049f59b9-86f2-47c0-99dc-8d703fb387cd'] = $pane;
  $display->panels['center'][0] = 'new-049f59b9-86f2-47c0-99dc-8d703fb387cd';
  $pane = new stdClass();
  $pane->pid = 'new-ed10f1d6-1dec-4448-b8b6-41106bf6deda';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'student_programs_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_3',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ed10f1d6-1dec-4448-b8b6-41106bf6deda';
  $display->content['new-ed10f1d6-1dec-4448-b8b6-41106bf6deda'] = $pane;
  $display->panels['center'][1] = 'new-ed10f1d6-1dec-4448-b8b6-41106bf6deda';
  $pane = new stdClass();
  $pane->pid = 'new-a8080846-9c81-412e-9442-19b35b7ffc48';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-stdnt_prog_are_you';
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
  $pane->uuid = 'a8080846-9c81-412e-9442-19b35b7ffc48';
  $display->content['new-a8080846-9c81-412e-9442-19b35b7ffc48'] = $pane;
  $display->panels['center'][2] = 'new-a8080846-9c81-412e-9442-19b35b7ffc48';
  $pane = new stdClass();
  $pane->pid = 'new-7fc1398c-c59c-44b1-8124-7a3914c671e2';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-stdnt_prog_contact';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '7fc1398c-c59c-44b1-8124-7a3914c671e2';
  $display->content['new-7fc1398c-c59c-44b1-8124-7a3914c671e2'] = $pane;
  $display->panels['center'][3] = 'new-7fc1398c-c59c-44b1-8124-7a3914c671e2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-ed10f1d6-1dec-4448-b8b6-41106bf6deda';
  $handler->conf['display'] = $display;
  $export['node_view__student_program'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -6;
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Senator Active',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_homepage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'default' => NULL,
      'footer' => NULL,
      'footer_first' => NULL,
      'footer_last' => NULL,
      'footer_middle' => NULL,
      'header' => NULL,
      'hero' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Senator %node:title';
  $display->uuid = '091d93ee-fe14-49a7-84e0-658fc719e151';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-081b3939-db34-46d6-ac9e-0fa6a52bbe76';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'senator_home_promo_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '081b3939-db34-46d6-ac9e-0fa6a52bbe76';
  $display->content['new-081b3939-db34-46d6-ac9e-0fa6a52bbe76'] = $pane;
  $display->panels['content'][0] = 'new-081b3939-db34-46d6-ac9e-0fa6a52bbe76';
  $pane = new stdClass();
  $pane->pid = 'new-f7fa4291-8f36-4e4e-be46-e554c831b6e2';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'senator_polls';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block',
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
  $pane->uuid = 'f7fa4291-8f36-4e4e-be46-e554c831b6e2';
  $display->content['new-f7fa4291-8f36-4e4e-be46-e554c831b6e2'] = $pane;
  $display->panels['content'][1] = 'new-f7fa4291-8f36-4e4e-be46-e554c831b6e2';
  $pane = new stdClass();
  $pane->pid = 'new-f66f4b67-da8d-4cdd-86fd-ea03d0e2b682';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'featured_story',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = 'f66f4b67-da8d-4cdd-86fd-ea03d0e2b682';
  $display->content['new-f66f4b67-da8d-4cdd-86fd-ea03d0e2b682'] = $pane;
  $display->panels['content'][2] = 'new-f66f4b67-da8d-4cdd-86fd-ea03d0e2b682';
  $pane = new stdClass();
  $pane->pid = 'new-deb87bac-be35-41a8-860d-bf7a9768dee7';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'senator_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'sen_featured_legis',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'deb87bac-be35-41a8-860d-bf7a9768dee7';
  $display->content['new-deb87bac-be35-41a8-860d-bf7a9768dee7'] = $pane;
  $display->panels['content'][3] = 'new-deb87bac-be35-41a8-860d-bf7a9768dee7';
  $pane = new stdClass();
  $pane->pid = 'new-c1c8b25e-6b12-41b9-9acb-40a6ab99922c';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_featured_legislation_main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c1c8b25e-6b12-41b9-9acb-40a6ab99922c';
  $display->content['new-c1c8b25e-6b12-41b9-9acb-40a6ab99922c'] = $pane;
  $display->panels['content'][4] = 'new-c1c8b25e-6b12-41b9-9acb-40a6ab99922c';
  $pane = new stdClass();
  $pane->pid = 'new-08cf0cb5-274e-467e-91b3-6008cc393256';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'featured_legislation';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_featured_legislation_sub',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '2',
    'offset' => '1',
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '08cf0cb5-274e-467e-91b3-6008cc393256';
  $display->content['new-08cf0cb5-274e-467e-91b3-6008cc393256'] = $pane;
  $display->panels['content'][5] = 'new-08cf0cb5-274e-467e-91b3-6008cc393256';
  $pane = new stdClass();
  $pane->pid = 'new-9c3654bd-ae6f-45ce-85a3-5444a8090ed9';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'block_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '9c3654bd-ae6f-45ce-85a3-5444a8090ed9';
  $display->content['new-9c3654bd-ae6f-45ce-85a3-5444a8090ed9'] = $pane;
  $display->panels['content'][6] = 'new-9c3654bd-ae6f-45ce-85a3-5444a8090ed9';
  $pane = new stdClass();
  $pane->pid = 'new-a7b0f50e-e85b-48c5-8412-595a2bd1fb08';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'senator_home_promo_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '1',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'a7b0f50e-e85b-48c5-8412-595a2bd1fb08';
  $display->content['new-a7b0f50e-e85b-48c5-8412-595a2bd1fb08'] = $pane;
  $display->panels['content'][7] = 'new-a7b0f50e-e85b-48c5-8412-595a2bd1fb08';
  $pane = new stdClass();
  $pane->pid = 'new-c101573f-6d77-4024-b811-592695cded78';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'senator_tweets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'block',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'c101573f-6d77-4024-b811-592695cded78';
  $display->content['new-c101573f-6d77-4024-b811-592695cded78'] = $pane;
  $display->panels['content'][8] = 'new-c101573f-6d77-4024-b811-592695cded78';
  $pane = new stdClass();
  $pane->pid = 'new-3cf1e583-fc3b-4d7d-9b21-45067b363ba1';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'senator_events';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
      1 => '',
      2 => '',
    ),
    'display' => 'block_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '3cf1e583-fc3b-4d7d-9b21-45067b363ba1';
  $display->content['new-3cf1e583-fc3b-4d7d-9b21-45067b363ba1'] = $pane;
  $display->panels['content'][9] = 'new-3cf1e583-fc3b-4d7d-9b21-45067b363ba1';
  $pane = new stdClass();
  $pane->pid = 'new-b8b48d3a-8ff6-4fee-851a-4d93c6cc055d';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_utils-news_by_top_issue_output_block';
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
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'b8b48d3a-8ff6-4fee-851a-4d93c6cc055d';
  $display->content['new-b8b48d3a-8ff6-4fee-851a-4d93c6cc055d'] = $pane;
  $display->panels['content'][10] = 'new-b8b48d3a-8ff6-4fee-851a-4d93c6cc055d';
  $pane = new stdClass();
  $pane->pid = 'new-c8797a74-60ea-4652-a490-29fdef1dd195';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'senator_home_promo_3',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '2',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = 'c8797a74-60ea-4652-a490-29fdef1dd195';
  $display->content['new-c8797a74-60ea-4652-a490-29fdef1dd195'] = $pane;
  $display->panels['content'][11] = 'new-c8797a74-60ea-4652-a490-29fdef1dd195';
  $pane = new stdClass();
  $pane->pid = 'new-ecf5b0e6-ce6c-466b-8421-bbdf2ed9107c';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'senator_legislation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'sen_featured_legis_home_sub',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '1',
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
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = 'ecf5b0e6-ce6c-466b-8421-bbdf2ed9107c';
  $display->content['new-ecf5b0e6-ce6c-466b-8421-bbdf2ed9107c'] = $pane;
  $display->panels['content'][12] = 'new-ecf5b0e6-ce6c-466b-8421-bbdf2ed9107c';
  $pane = new stdClass();
  $pane->pid = 'new-de6d36f1-823e-4729-a0a5-2670eb0dcf62';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_home_promo_footer',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '3',
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
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = 'de6d36f1-823e-4729-a0a5-2670eb0dcf62';
  $display->content['new-de6d36f1-823e-4729-a0a5-2670eb0dcf62'] = $pane;
  $display->panels['content'][13] = 'new-de6d36f1-823e-4729-a0a5-2670eb0dcf62';
  $pane = new stdClass();
  $pane->pid = 'new-48834b8a-2242-46fb-8a02-831eb05f452b';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'legislation_bills';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'senator_homepage_legislation_bills',
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
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = '48834b8a-2242-46fb-8a02-831eb05f452b';
  $display->content['new-48834b8a-2242-46fb-8a02-831eb05f452b'] = $pane;
  $display->panels['content'][14] = 'new-48834b8a-2242-46fb-8a02-831eb05f452b';
  $pane = new stdClass();
  $pane->pid = 'new-6d48b677-c38b-444b-a41e-423e93990d10';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_footer';
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
  $pane->uuid = '6d48b677-c38b-444b-a41e-423e93990d10';
  $display->content['new-6d48b677-c38b-444b-a41e-423e93990d10'] = $pane;
  $display->panels['footer_first'][0] = 'new-6d48b677-c38b-444b-a41e-423e93990d10';
  $pane = new stdClass();
  $pane->pid = 'new-e331081a-ff45-4871-98b9-e743ec91fd4b';
  $pane->panel = 'footer_first';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-global-footer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'c-site-footer',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e331081a-ff45-4871-98b9-e743ec91fd4b';
  $display->content['new-e331081a-ff45-4871-98b9-e743ec91fd4b'] = $pane;
  $display->panels['footer_first'][1] = 'new-e331081a-ff45-4871-98b9-e743ec91fd4b';
  $pane = new stdClass();
  $pane->pid = 'new-0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-micro_header_bar_block';
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
  $pane->uuid = '0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $display->content['new-0e5d23cd-8638-44a7-ba96-e450ea0a3452'] = $pane;
  $display->panels['header'][0] = 'new-0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $pane = new stdClass();
  $pane->pid = 'new-f599365d-c3a8-43fe-861f-90ce28eb01f1';
  $pane->panel = 'header';
  $pane->type = 'views';
  $pane->subtype = 'nys_senator_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'block',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
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
  $pane->uuid = 'f599365d-c3a8-43fe-861f-90ce28eb01f1';
  $display->content['new-f599365d-c3a8-43fe-861f-90ce28eb01f1'] = $pane;
  $display->panels['header'][1] = 'new-f599365d-c3a8-43fe-861f-90ce28eb01f1';
  $pane = new stdClass();
  $pane->pid = 'new-c8e77207-37d3-4e2f-bc41-4aa0b1b00f68';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-microsite_nav_block';
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
  $pane->uuid = 'c8e77207-37d3-4e2f-bc41-4aa0b1b00f68';
  $display->content['new-c8e77207-37d3-4e2f-bc41-4aa0b1b00f68'] = $pane;
  $display->panels['header'][2] = 'new-c8e77207-37d3-4e2f-bc41-4aa0b1b00f68';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0e5d23cd-8638-44a7-ba96-e450ea0a3452';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -5;
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
              'initiative' => 'initiative',
            ),
          ),
        ),
        1 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'entity_field_value:node:initiative:field_profile_type',
          'not' => FALSE,
          'settings' => array(
            'field_profile_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'veterans',
                ),
              ),
            ),
            'field_profile_type_value' => array(
              0 => 'veterans',
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'delta' => 0,
        'id' => 1,
        'identifier' => 'Content from Content (on Content: Senator [field_senator])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_senator-node-node',
      ),
    ),
    'title' => 'Initiative - Veterans',
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'default' => NULL,
      'footer' => NULL,
      'footer_first' => NULL,
      'footer_last' => NULL,
      'footer_middle' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title | Initiative';
  $display->uuid = '091d93ee-fe14-49a7-84e0-658fc719e151';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane->panel = 'middle';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '56e29f93-6395-4821-8abf-a3ae4578e705';
  $display->content['new-56e29f93-6395-4821-8abf-a3ae4578e705'] = $pane;
  $display->panels['middle'][0] = 'new-56e29f93-6395-4821-8abf-a3ae4578e705';
  $pane = new stdClass();
  $pane->pid = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'identifier' => '',
    'leave_node_title' => 1,
    'link' => 0,
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
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
  $pane->uuid = '1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $display->content['new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac'] = $pane;
  $display->panels['middle'][1] = 'new-1f1c72db-3861-4d1a-8a4a-dfe0902402ac';
  $pane = new stdClass();
  $pane->pid = 'new-c70efb54-c8b0-4f90-b1f5-ddfd4430a816';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'manage_profiles';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'relationship_entity_from_field:field_senator-node-node_1.nid',
      1 => '',
    ),
    'display' => 'block_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '10',
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
  $pane->css = array(
    'css_class' => 'c-block--honorees',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c70efb54-c8b0-4f90-b1f5-ddfd4430a816';
  $display->content['new-c70efb54-c8b0-4f90-b1f5-ddfd4430a816'] = $pane;
  $display->panels['middle'][2] = 'new-c70efb54-c8b0-4f90-b1f5-ddfd4430a816';
  $pane = new stdClass();
  $pane->pid = 'new-ec814d12-8439-4631-aeb7-bad9db871c5a';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
      1 => '',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ec814d12-8439-4631-aeb7-bad9db871c5a';
  $display->content['new-ec814d12-8439-4631-aeb7-bad9db871c5a'] = $pane;
  $display->panels['middle'][3] = 'new-ec814d12-8439-4631-aeb7-bad9db871c5a';
  $pane = new stdClass();
  $pane->pid = 'new-1e3c7538-0fed-4ff7-9a99-97f62b362f23';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '1e3c7538-0fed-4ff7-9a99-97f62b362f23';
  $display->content['new-1e3c7538-0fed-4ff7-9a99-97f62b362f23'] = $pane;
  $display->panels['middle'][4] = 'new-1e3c7538-0fed-4ff7-9a99-97f62b362f23';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__coronavirus';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        1 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'majority_issues' => 'majority_issues',
            ),
          ),
        ),
        2 => array(
          'context' => 'argument_term_1',
          'name' => 'term',
          'not' => FALSE,
          'settings' => array(
            'vid' => '16',
            4 => array(),
            8 => array(),
            11 => array(),
            12 => array(),
            13 => array(),
            14 => array(),
            15 => array(),
            16 => array(
              78716 => '78716',
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
    'name' => 'coronavirus',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Coronavirus',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_majority_issue2';
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
  $display->title = '%term:name';
  $display->uuid = '263c9dfc-44b3-4cfd-b4fa-4eb5c3ad397c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view__coronavirus';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c32305a6-fc70-4833-b000-dba2cc18e62d';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'majority_issues';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
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
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c32305a6-fc70-4833-b000-dba2cc18e62d';
  $display->content['new-c32305a6-fc70-4833-b000-dba2cc18e62d'] = $pane;
  $display->panels['tabs'][0] = 'new-c32305a6-fc70-4833-b000-dba2cc18e62d';
  $pane = new stdClass();
  $pane->pid = 'new-cbaa317e-3924-4d15-8407-6c75b0c9ffa0';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'majority_issues';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => '',
    ),
    'display' => 'covid',
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
  $pane->uuid = 'cbaa317e-3924-4d15-8407-6c75b0c9ffa0';
  $display->content['new-cbaa317e-3924-4d15-8407-6c75b0c9ffa0'] = $pane;
  $display->panels['tabs'][1] = 'new-cbaa317e-3924-4d15-8407-6c75b0c9ffa0';
  $pane = new stdClass();
  $pane->pid = 'new-9bbba8a0-da82-4557-a2d7-8f679b13b351';
  $pane->panel = 'tabs';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<p>&nbsp;</p>

<p><a class="c-paragraph--more-link a-left" href="/important-information-senate-employees">Important Information for Senate Employees</a></p>
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9bbba8a0-da82-4557-a2d7-8f679b13b351';
  $display->content['new-9bbba8a0-da82-4557-a2d7-8f679b13b351'] = $pane;
  $display->panels['tabs'][2] = 'new-9bbba8a0-da82-4557-a2d7-8f679b13b351';
  $pane = new stdClass();
  $pane->pid = 'new-b77a7bb0-7482-4c7b-921c-19305901dfd8';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'majority_issues';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'bills',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '6',
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel4',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b77a7bb0-7482-4c7b-921c-19305901dfd8';
  $display->content['new-b77a7bb0-7482-4c7b-921c-19305901dfd8'] = $pane;
  $display->panels['tabs'][3] = 'new-b77a7bb0-7482-4c7b-921c-19305901dfd8';
  $pane = new stdClass();
  $pane->pid = 'new-3caec5bc-5f51-4fa4-b1fa-e3f3afc09885';
  $pane->panel = 'top';
  $pane->type = 'term_description';
  $pane->subtype = 'term_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
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
  $pane->uuid = '3caec5bc-5f51-4fa4-b1fa-e3f3afc09885';
  $display->content['new-3caec5bc-5f51-4fa4-b1fa-e3f3afc09885'] = $pane;
  $display->panels['top'][0] = 'new-3caec5bc-5f51-4fa4-b1fa-e3f3afc09885';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__coronavirus'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_3f7ee106-6f9a-435f-aacf-a795e550f2c8';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        1 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'majority_issues' => 'majority_issues',
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
    'title' => 'Majority Issues',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_majority_issue';
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
  $display->title = '%term:name';
  $display->uuid = '263c9dfc-44b3-4cfd-b4fa-4eb5c3ad397c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view__panel_context_3f7ee106-6f9a-435f-aacf-a795e550f2c8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c32305a6-fc70-4833-b000-dba2cc18e62d';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'majority_issues';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
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
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c32305a6-fc70-4833-b000-dba2cc18e62d';
  $display->content['new-c32305a6-fc70-4833-b000-dba2cc18e62d'] = $pane;
  $display->panels['tabs'][0] = 'new-c32305a6-fc70-4833-b000-dba2cc18e62d';
  $pane = new stdClass();
  $pane->pid = 'new-a79d0e3d-7499-4c21-921b-032f331c0bec';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'majority_issues';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'meetings',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
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
  $pane->uuid = 'a79d0e3d-7499-4c21-921b-032f331c0bec';
  $display->content['new-a79d0e3d-7499-4c21-921b-032f331c0bec'] = $pane;
  $display->panels['tabs'][1] = 'new-a79d0e3d-7499-4c21-921b-032f331c0bec';
  $pane = new stdClass();
  $pane->pid = 'new-b77a7bb0-7482-4c7b-921c-19305901dfd8';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'majority_issues';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'bills',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '6',
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b77a7bb0-7482-4c7b-921c-19305901dfd8';
  $display->content['new-b77a7bb0-7482-4c7b-921c-19305901dfd8'] = $pane;
  $display->panels['tabs'][2] = 'new-b77a7bb0-7482-4c7b-921c-19305901dfd8';
  $pane = new stdClass();
  $pane->pid = 'new-3caec5bc-5f51-4fa4-b1fa-e3f3afc09885';
  $pane->panel = 'top';
  $pane->type = 'term_description';
  $pane->subtype = 'term_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
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
  $pane->uuid = '3caec5bc-5f51-4fa4-b1fa-e3f3afc09885';
  $display->content['new-3caec5bc-5f51-4fa4-b1fa-e3f3afc09885'] = $pane;
  $display->panels['top'][0] = 'new-3caec5bc-5f51-4fa4-b1fa-e3f3afc09885';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_3f7ee106-6f9a-435f-aacf-a795e550f2c8'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_a14491f4-6fdb-4369-a228-dc473ca16418';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'committees' => 'committees',
            ),
          ),
        ),
        1 => array(
          'context' => 'argument_term_1',
          'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
          'not' => FALSE,
          'settings' => array(
            'field_assemblymen_chair' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_assemblymen_chair_value' => array(
              0 => 1,
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Misc Congressional Group',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_committee_detail';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'below_top' => array(
      'style' => 'naked',
    ),
    'bottom' => array(
      'style' => 'wrapper_element',
    ),
    'hero' => array(
      'style' => 'default',
    ),
    'style' => 'wrapper_element',
    'style_settings' => array(
      'below_top' => NULL,
      'bottom' => array(
        'content' => array(
          'attributes' => array(
            'class' => '',
            'id' => 'members',
          ),
          'element' => 'div',
        ),
        'theme' => 0,
      ),
      'default' => array(
        'content' => array(
          'attributes' => array(
            'class' => 'c-committee-header',
            'id' => '',
          ),
          'element' => 'div',
        ),
        'theme' => 0,
      ),
      'hero' => NULL,
      'middle' => NULL,
      'tabs' => NULL,
      'top' => NULL,
    ),
    'tabs' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = 'My title';
  $display->uuid = '04d24cfd-c9a8-4b62-b585-b8d45151b063';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view__panel_context_a14491f4-6fdb-4369-a228-dc473ca16418';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-559f1114-36db-4554-a77d-e28775b8de5d';
  $pane->panel = 'below_top';
  $pane->type = 'views';
  $pane->subtype = 'senator_events';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'featured_committee_event',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '559f1114-36db-4554-a77d-e28775b8de5d';
  $display->content['new-559f1114-36db-4554-a77d-e28775b8de5d'] = $pane;
  $display->panels['below_top'][0] = 'new-559f1114-36db-4554-a77d-e28775b8de5d';
  $pane = new stdClass();
  $pane->pid = 'new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $pane->panel = 'below_top';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_featured_story',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $display->content['new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38'] = $pane;
  $display->panels['below_top'][1] = 'new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $pane = new stdClass();
  $pane->pid = 'new-65e8e19e-1d2b-4828-9f0c-fdb8440426db';
  $pane->panel = 'below_top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '    <div class="c-container--header__top-border">
      <h3 class="c-container--title">Featured Legislation</h3>
    </div>
',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '65e8e19e-1d2b-4828-9f0c-fdb8440426db';
  $display->content['new-65e8e19e-1d2b-4828-9f0c-fdb8440426db'] = $pane;
  $display->panels['below_top'][2] = 'new-65e8e19e-1d2b-4828-9f0c-fdb8440426db';
  $pane = new stdClass();
  $pane->pid = 'new-b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $pane->panel = 'below_top';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_featured_legislation_commi';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter' => 'field_collection_view',
    'formatter_settings' => array(
      'add' => '',
      'delete' => '',
      'description' => 1,
      'edit' => '',
      'view_mode' => 'full',
    ),
    'label' => 'hidden',
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
  $pane->uuid = 'b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $display->content['new-b9d3be73-e191-4b4a-944c-2279d1e064a6'] = $pane;
  $display->panels['below_top'][3] = 'new-b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $pane = new stdClass();
  $pane->pid = 'new-654cbc0c-e8ab-4d9a-be3b-f2632b6281a5';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'chair',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_text' => 'Members',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'content' => array(
        'attributes' => array(
          'class' => '',
          'id' => '',
        ),
        'element' => '',
      ),
      'theme' => 0,
      'title' => array(
        'attributes' => array(
          'class' => 'c-members-title',
          'id' => '',
        ),
        'element' => 'div',
      ),
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '654cbc0c-e8ab-4d9a-be3b-f2632b6281a5';
  $display->content['new-654cbc0c-e8ab-4d9a-be3b-f2632b6281a5'] = $pane;
  $display->panels['bottom'][0] = 'new-654cbc0c-e8ab-4d9a-be3b-f2632b6281a5';
  $pane = new stdClass();
  $pane->pid = 'new-e4c02344-1999-456a-9789-f02bcbbb664d';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'listing',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = 'e4c02344-1999-456a-9789-f02bcbbb664d';
  $display->content['new-e4c02344-1999-456a-9789-f02bcbbb664d'] = $pane;
  $display->panels['bottom'][1] = 'new-e4c02344-1999-456a-9789-f02bcbbb664d';
  $pane = new stdClass();
  $pane->pid = 'new-33ef0ee9-a576-4a57-9792-8a59e041b2f8';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
  $pane->uuid = '33ef0ee9-a576-4a57-9792-8a59e041b2f8';
  $display->content['new-33ef0ee9-a576-4a57-9792-8a59e041b2f8'] = $pane;
  $display->panels['bottom'][2] = 'new-33ef0ee9-a576-4a57-9792-8a59e041b2f8';
  $pane = new stdClass();
  $pane->pid = 'new-0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $pane->panel = 'hero';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_image_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'image',
    'formatter_settings' => array(
      'image_link' => '',
      'image_style' => '',
    ),
    'label' => 'hidden',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
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
  $pane->uuid = '0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $display->content['new-0e679027-1256-4fc6-8a56-30436d1b1a7d'] = $pane;
  $display->panels['hero'][0] = 'new-0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $pane = new stdClass();
  $pane->pid = 'new-f36c959c-86c2-42e6-9044-51d184c10ba0';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_all_updates',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f36c959c-86c2-42e6-9044-51d184c10ba0';
  $display->content['new-f36c959c-86c2-42e6-9044-51d184c10ba0'] = $pane;
  $display->panels['tabs'][0] = 'new-f36c959c-86c2-42e6-9044-51d184c10ba0';
  $pane = new stdClass();
  $pane->pid = 'new-db63f7fc-3013-459b-aa98-687ac55ead2d';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_news',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'db63f7fc-3013-459b-aa98-687ac55ead2d';
  $display->content['new-db63f7fc-3013-459b-aa98-687ac55ead2d'] = $pane;
  $display->panels['tabs'][1] = 'new-db63f7fc-3013-459b-aa98-687ac55ead2d';
  $pane = new stdClass();
  $pane->pid = 'new-f660a804-a650-4f46-903f-44d3d596b70c';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_events',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f660a804-a650-4f46-903f-44d3d596b70c';
  $display->content['new-f660a804-a650-4f46-903f-44d3d596b70c'] = $pane;
  $display->panels['tabs'][2] = 'new-f660a804-a650-4f46-903f-44d3d596b70c';
  $pane = new stdClass();
  $pane->pid = 'new-4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2 class="nys-title">%term:name Committee</h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $display->content['new-4e10f907-b7ad-4d70-9666-92ca25e54c5e'] = $pane;
  $display->panels['top'][0] = 'new-4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $pane = new stdClass();
  $pane->pid = 'new-0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2 class="c-committee-type"><a href="/senators-committees" title="Senators &amp; Committees">%term:field-committee-types</a></h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $display->content['new-0c07afde-6e5d-48c1-9406-2a5d78e3733f'] = $pane;
  $display->panels['top'][1] = 'new-0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $pane = new stdClass();
  $pane->pid = 'new-cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<p class="c-when">%term:field-meeting-frequency</p>
',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $display->content['new-cd6f1445-5646-4527-b2fc-6b6844254ff7'] = $pane;
  $display->panels['top'][2] = 'new-cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $pane = new stdClass();
  $pane->pid = 'new-277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '%term:description',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_class' => 'c-description',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $display->content['new-277fb6bd-a50e-4752-aff3-647a85d1f6bc'] = $pane;
  $display->panels['top'][3] = 'new-277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $pane = new stdClass();
  $pane->pid = 'new-c4510ded-9513-4b00-b593-82eab7f7a769';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
    'css_class' => 'l-chair-container',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c4510ded-9513-4b00-b593-82eab7f7a769';
  $display->content['new-c4510ded-9513-4b00-b593-82eab7f7a769'] = $pane;
  $display->panels['top'][4] = 'new-c4510ded-9513-4b00-b593-82eab7f7a769';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_a14491f4-6fdb-4369-a228-dc473ca16418'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_b622e587-ed14-495c-bcfb-0832a3491a82';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'committees' => 'committees',
            ),
          ),
        ),
        1 => array(
          'context' => 'argument_term_1',
          'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
          'not' => FALSE,
          'settings' => array(
            'field_assemblymen_chair' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_assemblymen_chair_value' => array(
              0 => 1,
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Miscellaneous Legislative Groups',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_committee_detail';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'below_top' => array(
      'style' => 'naked',
    ),
    'bottom' => array(
      'style' => 'wrapper_element',
    ),
    'hero' => array(
      'style' => 'default',
    ),
    'style' => 'wrapper_element',
    'style_settings' => array(
      'below_top' => NULL,
      'bottom' => array(
        'content' => array(
          'attributes' => array(
            'class' => '',
            'id' => 'members',
          ),
          'element' => 'div',
        ),
        'theme' => 0,
      ),
      'default' => array(
        'content' => array(
          'attributes' => array(
            'class' => 'c-committee-header',
            'id' => '',
          ),
          'element' => 'div',
        ),
        'theme' => 0,
      ),
      'hero' => NULL,
      'middle' => NULL,
      'tabs' => NULL,
      'top' => NULL,
    ),
    'tabs' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = 'My title';
  $display->uuid = '04d24cfd-c9a8-4b62-b585-b8d45151b063';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view__panel_context_b622e587-ed14-495c-bcfb-0832a3491a82';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-559f1114-36db-4554-a77d-e28775b8de5d';
  $pane->panel = 'below_top';
  $pane->type = 'views';
  $pane->subtype = 'senator_events';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'featured_committee_event',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '559f1114-36db-4554-a77d-e28775b8de5d';
  $display->content['new-559f1114-36db-4554-a77d-e28775b8de5d'] = $pane;
  $display->panels['below_top'][0] = 'new-559f1114-36db-4554-a77d-e28775b8de5d';
  $pane = new stdClass();
  $pane->pid = 'new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $pane->panel = 'below_top';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_featured_story',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $display->content['new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38'] = $pane;
  $display->panels['below_top'][1] = 'new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $pane = new stdClass();
  $pane->pid = 'new-65e8e19e-1d2b-4828-9f0c-fdb8440426db';
  $pane->panel = 'below_top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '    <div class="c-container--header__top-border">
      <h3 class="c-container--title">Featured Legislation</h3>
    </div>
',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '65e8e19e-1d2b-4828-9f0c-fdb8440426db';
  $display->content['new-65e8e19e-1d2b-4828-9f0c-fdb8440426db'] = $pane;
  $display->panels['below_top'][2] = 'new-65e8e19e-1d2b-4828-9f0c-fdb8440426db';
  $pane = new stdClass();
  $pane->pid = 'new-b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $pane->panel = 'below_top';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_featured_legislation_commi';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter' => 'field_collection_view',
    'formatter_settings' => array(
      'add' => '',
      'delete' => '',
      'description' => 1,
      'edit' => '',
      'view_mode' => 'full',
    ),
    'label' => 'hidden',
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
  $pane->uuid = 'b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $display->content['new-b9d3be73-e191-4b4a-944c-2279d1e064a6'] = $pane;
  $display->panels['below_top'][3] = 'new-b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $pane = new stdClass();
  $pane->pid = 'new-654cbc0c-e8ab-4d9a-be3b-f2632b6281a5';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'chair',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_text' => 'Members',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'content' => array(
        'attributes' => array(
          'class' => '',
          'id' => '',
        ),
        'element' => '',
      ),
      'theme' => 0,
      'title' => array(
        'attributes' => array(
          'class' => 'c-members-title',
          'id' => '',
        ),
        'element' => 'div',
      ),
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '654cbc0c-e8ab-4d9a-be3b-f2632b6281a5';
  $display->content['new-654cbc0c-e8ab-4d9a-be3b-f2632b6281a5'] = $pane;
  $display->panels['bottom'][0] = 'new-654cbc0c-e8ab-4d9a-be3b-f2632b6281a5';
  $pane = new stdClass();
  $pane->pid = 'new-e4c02344-1999-456a-9789-f02bcbbb664d';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'listing',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = 'e4c02344-1999-456a-9789-f02bcbbb664d';
  $display->content['new-e4c02344-1999-456a-9789-f02bcbbb664d'] = $pane;
  $display->panels['bottom'][1] = 'new-e4c02344-1999-456a-9789-f02bcbbb664d';
  $pane = new stdClass();
  $pane->pid = 'new-a1dff8dd-459d-4d38-9654-ffbb99edea9a';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
  $pane->uuid = 'a1dff8dd-459d-4d38-9654-ffbb99edea9a';
  $display->content['new-a1dff8dd-459d-4d38-9654-ffbb99edea9a'] = $pane;
  $display->panels['bottom'][2] = 'new-a1dff8dd-459d-4d38-9654-ffbb99edea9a';
  $pane = new stdClass();
  $pane->pid = 'new-0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $pane->panel = 'hero';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_image_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'image',
    'formatter_settings' => array(
      'image_link' => '',
      'image_style' => '',
    ),
    'label' => 'hidden',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
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
  $pane->uuid = '0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $display->content['new-0e679027-1256-4fc6-8a56-30436d1b1a7d'] = $pane;
  $display->panels['hero'][0] = 'new-0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $pane = new stdClass();
  $pane->pid = 'new-f36c959c-86c2-42e6-9044-51d184c10ba0';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_all_updates',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f36c959c-86c2-42e6-9044-51d184c10ba0';
  $display->content['new-f36c959c-86c2-42e6-9044-51d184c10ba0'] = $pane;
  $display->panels['tabs'][0] = 'new-f36c959c-86c2-42e6-9044-51d184c10ba0';
  $pane = new stdClass();
  $pane->pid = 'new-db63f7fc-3013-459b-aa98-687ac55ead2d';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_news',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'db63f7fc-3013-459b-aa98-687ac55ead2d';
  $display->content['new-db63f7fc-3013-459b-aa98-687ac55ead2d'] = $pane;
  $display->panels['tabs'][1] = 'new-db63f7fc-3013-459b-aa98-687ac55ead2d';
  $pane = new stdClass();
  $pane->pid = 'new-f660a804-a650-4f46-903f-44d3d596b70c';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_events',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f660a804-a650-4f46-903f-44d3d596b70c';
  $display->content['new-f660a804-a650-4f46-903f-44d3d596b70c'] = $pane;
  $display->panels['tabs'][2] = 'new-f660a804-a650-4f46-903f-44d3d596b70c';
  $pane = new stdClass();
  $pane->pid = 'new-4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2 class="nys-title">%term:name Committee</h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $display->content['new-4e10f907-b7ad-4d70-9666-92ca25e54c5e'] = $pane;
  $display->panels['top'][0] = 'new-4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $pane = new stdClass();
  $pane->pid = 'new-0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2 class="c-committee-type"><a href="/senators-committees" title="Senators &amp; Committees">%term:field-committee-types</a></h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $display->content['new-0c07afde-6e5d-48c1-9406-2a5d78e3733f'] = $pane;
  $display->panels['top'][1] = 'new-0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $pane = new stdClass();
  $pane->pid = 'new-cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<p class="c-when">%term:field-meeting-frequency</p>
',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $display->content['new-cd6f1445-5646-4527-b2fc-6b6844254ff7'] = $pane;
  $display->panels['top'][2] = 'new-cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $pane = new stdClass();
  $pane->pid = 'new-277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '%term:description',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_class' => 'c-description',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $display->content['new-277fb6bd-a50e-4752-aff3-647a85d1f6bc'] = $pane;
  $display->panels['top'][3] = 'new-277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $pane = new stdClass();
  $pane->pid = 'new-c4510ded-9513-4b00-b593-82eab7f7a769';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
    'css_class' => 'l-chair-container',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c4510ded-9513-4b00-b593-82eab7f7a769';
  $display->content['new-c4510ded-9513-4b00-b593-82eab7f7a769'] = $pane;
  $display->panels['top'][4] = 'new-c4510ded-9513-4b00-b593-82eab7f7a769';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_b622e587-ed14-495c-bcfb-0832a3491a82'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -5;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'issues' => 'issues',
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Issues',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_issue_detail';
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
  $display->title = '%term:name';
  $display->uuid = 'd0a50fb1-f27d-4c91-9186-9e15b68f835a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5ca58b31-0d53-4d59-bfb5-b6b976892cbe';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'news_by_issue';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'video',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '5ca58b31-0d53-4d59-bfb5-b6b976892cbe';
  $display->content['new-5ca58b31-0d53-4d59-bfb5-b6b976892cbe'] = $pane;
  $display->panels['bottom'][0] = 'new-5ca58b31-0d53-4d59-bfb5-b6b976892cbe';
  $pane = new stdClass();
  $pane->pid = 'new-b6e8f2cf-5447-4776-9f96-1ba6947acb80';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'news_by_issue';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b6e8f2cf-5447-4776-9f96-1ba6947acb80';
  $display->content['new-b6e8f2cf-5447-4776-9f96-1ba6947acb80'] = $pane;
  $display->panels['tabs'][0] = 'new-b6e8f2cf-5447-4776-9f96-1ba6947acb80';
  $pane = new stdClass();
  $pane->pid = 'new-3547f0ea-691c-44f7-b3a9-1c7ea0ab23c4';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'bills_by_issue';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3547f0ea-691c-44f7-b3a9-1c7ea0ab23c4';
  $display->content['new-3547f0ea-691c-44f7-b3a9-1c7ea0ab23c4'] = $pane;
  $display->panels['tabs'][1] = 'new-3547f0ea-691c-44f7-b3a9-1c7ea0ab23c4';
  $pane = new stdClass();
  $pane->pid = 'new-c39036c2-3ce9-463a-877d-1eb36de8f614';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'news_by_issue';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'news_by_bill',
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
    'use_pager' => 1,
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c39036c2-3ce9-463a-877d-1eb36de8f614';
  $display->content['new-c39036c2-3ce9-463a-877d-1eb36de8f614'] = $pane;
  $display->panels['tabs'][2] = 'new-c39036c2-3ce9-463a-877d-1eb36de8f614';
  $pane = new stdClass();
  $pane->pid = 'new-e55ccb21-be05-4b9d-af71-c439658defd0';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'news_by_issue';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'meeting_by_issue',
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
    'use_pager' => 1,
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e55ccb21-be05-4b9d-af71-c439658defd0';
  $display->content['new-e55ccb21-be05-4b9d-af71-c439658defd0'] = $pane;
  $display->panels['tabs'][3] = 'new-e55ccb21-be05-4b9d-af71-c439658defd0';
  $pane = new stdClass();
  $pane->pid = 'new-326dfeef-751e-4717-a23d-debd697eac8f';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-issue_quick_facts';
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
  $pane->uuid = '326dfeef-751e-4717-a23d-debd697eac8f';
  $display->content['new-326dfeef-751e-4717-a23d-debd697eac8f'] = $pane;
  $display->panels['top'][0] = 'new-326dfeef-751e-4717-a23d-debd697eac8f';
  $pane = new stdClass();
  $pane->pid = 'new-8b5c7edd-42d6-4129-8f66-82c4843063dc';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-senators_talking_about_issue';
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
  $pane->uuid = '8b5c7edd-42d6-4129-8f66-82c4843063dc';
  $display->content['new-8b5c7edd-42d6-4129-8f66-82c4843063dc'] = $pane;
  $display->panels['top'][1] = 'new-8b5c7edd-42d6-4129-8f66-82c4843063dc';
  $pane = new stdClass();
  $pane->pid = 'new-12c8cd56-9c58-40dd-9057-e91822fda512';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'news_by_issue';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'petition',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '4',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '12c8cd56-9c58-40dd-9057-e91822fda512';
  $display->content['new-12c8cd56-9c58-40dd-9057-e91822fda512'] = $pane;
  $display->panels['top'][2] = 'new-12c8cd56-9c58-40dd-9057-e91822fda512';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_2';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -4;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'districts' => 'districts',
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Districts',
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
  $display->uuid = '9464b364-2aec-466a-8c19-85fd89fd44f9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-91540312-d269-4e87-9f0f-b09fd66554d2';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Out District & term name',
    'body' => '<h2 class="nys-title nys-title--district">Our District</h2><h2 class="c-subpage-header--subtitle05">%term:name</h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '91540312-d269-4e87-9f0f-b09fd66554d2';
  $display->content['new-91540312-d269-4e87-9f0f-b09fd66554d2'] = $pane;
  $display->panels['middle'][0] = 'new-91540312-d269-4e87-9f0f-b09fd66554d2';
  $pane = new stdClass();
  $pane->pid = 'new-67ae5475-f822-4b1f-babe-fa3d804fbce5';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'district_map';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '',
    'format' => 'full_html',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '67ae5475-f822-4b1f-babe-fa3d804fbce5';
  $display->content['new-67ae5475-f822-4b1f-babe-fa3d804fbce5'] = $pane;
  $display->panels['middle'][1] = 'new-67ae5475-f822-4b1f-babe-fa3d804fbce5';
  $pane = new stdClass();
  $pane->pid = 'new-fac73831-5678-4a3b-b79c-9a5c067e6cc1';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_subheading';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'hidden',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'c-subpage-header--title03',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fac73831-5678-4a3b-b79c-9a5c067e6cc1';
  $display->content['new-fac73831-5678-4a3b-b79c-9a5c067e6cc1'] = $pane;
  $display->panels['middle'][2] = 'new-fac73831-5678-4a3b-b79c-9a5c067e6cc1';
  $pane = new stdClass();
  $pane->pid = 'new-6a6b87f2-63aa-45f7-8c6b-af9439453ce6';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<div class="c-block">%term:description</div>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '6a6b87f2-63aa-45f7-8c6b-af9439453ce6';
  $display->content['new-6a6b87f2-63aa-45f7-8c6b-af9439453ce6'] = $pane;
  $display->panels['middle'][3] = 'new-6a6b87f2-63aa-45f7-8c6b-af9439453ce6';
  $pane = new stdClass();
  $pane->pid = 'new-8eb6d33c-c1d5-4865-9398-a29584df8e65';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_chapters';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter' => 'entityreference_entity_view',
    'formatter_settings' => array(
      'link' => 0,
      'links' => 1,
      'view_mode' => 'default',
    ),
    'label' => 'hidden',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'c-block',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '8eb6d33c-c1d5-4865-9398-a29584df8e65';
  $display->content['new-8eb6d33c-c1d5-4865-9398-a29584df8e65'] = $pane;
  $display->panels['middle'][4] = 'new-8eb6d33c-c1d5-4865-9398-a29584df8e65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_3';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_term_1',
          'name' => 'term_vocabulary',
          'not' => FALSE,
          'settings' => array(
            'machine_name' => array(
              'committees' => 'committees',
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
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Committees',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_committee_detail';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'below_top' => array(
      'style' => 'naked',
    ),
    'bottom' => array(
      'style' => 'wrapper_element',
    ),
    'hero' => array(
      'style' => 'default',
    ),
    'style' => 'wrapper_element',
    'style_settings' => array(
      'below_top' => NULL,
      'bottom' => array(
        'content' => array(
          'attributes' => array(
            'class' => '',
            'id' => 'members',
          ),
          'element' => 'div',
        ),
        'theme' => 0,
      ),
      'default' => array(
        'content' => array(
          'attributes' => array(
            'class' => 'c-committee-header',
            'id' => '',
          ),
          'element' => 'div',
        ),
        'theme' => 0,
      ),
      'hero' => NULL,
      'middle' => NULL,
      'tabs' => NULL,
      'top' => NULL,
    ),
    'tabs' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = 'My title';
  $display->uuid = '04d24cfd-c9a8-4b62-b585-b8d45151b063';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-559f1114-36db-4554-a77d-e28775b8de5d';
  $pane->panel = 'below_top';
  $pane->type = 'views';
  $pane->subtype = 'senator_events';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'featured_committee_event',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '559f1114-36db-4554-a77d-e28775b8de5d';
  $display->content['new-559f1114-36db-4554-a77d-e28775b8de5d'] = $pane;
  $display->panels['below_top'][0] = 'new-559f1114-36db-4554-a77d-e28775b8de5d';
  $pane = new stdClass();
  $pane->pid = 'new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $pane->panel = 'below_top';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_term_1',
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
        'not' => FALSE,
        'settings' => array(
          'field_assemblymen_chair' => array(
            'und' => array(
              0 => array(
                'value' => 0,
              ),
            ),
          ),
          'field_assemblymen_chair_value' => array(
            0 => 0,
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_featured_story',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = '5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $display->content['new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38'] = $pane;
  $display->panels['below_top'][1] = 'new-5e9a7d39-f04f-4d22-9b51-d7ec1a385d38';
  $pane = new stdClass();
  $pane->pid = 'new-b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $pane->panel = 'below_top';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_featured_legislation_commi';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_term_1',
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
        'not' => FALSE,
        'settings' => array(
          'field_assemblymen_chair' => array(
            'und' => array(
              0 => array(
                'value' => 0,
              ),
            ),
          ),
          'field_assemblymen_chair_value' => array(
            0 => 0,
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter' => 'field_collection_view',
    'formatter_settings' => array(
      'add' => '',
      'delete' => '',
      'description' => 1,
      'edit' => '',
      'view_mode' => 'full',
    ),
    'label' => 'hidden',
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
  $pane->uuid = 'b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $display->content['new-b9d3be73-e191-4b4a-944c-2279d1e064a6'] = $pane;
  $display->panels['below_top'][2] = 'new-b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $pane = new stdClass();
  $pane->pid = 'new-18378829-fc0a-4f7b-af9b-835c3fe189c4';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_term_1',
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
        'not' => FALSE,
        'settings' => array(
          'field_assemblymen_chair' => array(
            'und' => array(
              0 => array(
                'value' => 0,
              ),
            ),
          ),
          'field_assemblymen_chair_value' => array(
            0 => 0,
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'block_2',
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
    'css_class' => '',
    'css_id' => 'members',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '18378829-fc0a-4f7b-af9b-835c3fe189c4';
  $display->content['new-18378829-fc0a-4f7b-af9b-835c3fe189c4'] = $pane;
  $display->panels['bottom'][0] = 'new-18378829-fc0a-4f7b-af9b-835c3fe189c4';
  $pane = new stdClass();
  $pane->pid = 'new-9fa27b8f-6105-4872-b3f7-24b8617753a8';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_term_1',
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
        'not' => FALSE,
        'settings' => array(
          'field_assemblymen_chair' => array(
            'und' => array(
              0 => array(
                'value' => 0,
              ),
            ),
          ),
          'field_assemblymen_chair_value' => array(
            0 => 0,
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'members',
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
    'css_class' => 'c-senators-container',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9fa27b8f-6105-4872-b3f7-24b8617753a8';
  $display->content['new-9fa27b8f-6105-4872-b3f7-24b8617753a8'] = $pane;
  $display->panels['bottom'][1] = 'new-9fa27b8f-6105-4872-b3f7-24b8617753a8';
  $pane = new stdClass();
  $pane->pid = 'new-3ea09336-b7b7-4498-ae42-394664605ccd';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
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
  $pane->css = array(
    'css_class' => 'c-block',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3ea09336-b7b7-4498-ae42-394664605ccd';
  $display->content['new-3ea09336-b7b7-4498-ae42-394664605ccd'] = $pane;
  $display->panels['bottom'][2] = 'new-3ea09336-b7b7-4498-ae42-394664605ccd';
  $pane = new stdClass();
  $pane->pid = 'new-f5172e25-0a03-4a06-95df-b340625f4aaf';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f5172e25-0a03-4a06-95df-b340625f4aaf';
  $display->content['new-f5172e25-0a03-4a06-95df-b340625f4aaf'] = $pane;
  $display->panels['bottom'][3] = 'new-f5172e25-0a03-4a06-95df-b340625f4aaf';
  $pane = new stdClass();
  $pane->pid = 'new-9a290d56-1ad3-4df6-bbd7-5c8689e712cb';
  $pane->panel = 'bottom';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-how_senate_works_block';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9a290d56-1ad3-4df6-bbd7-5c8689e712cb';
  $display->content['new-9a290d56-1ad3-4df6-bbd7-5c8689e712cb'] = $pane;
  $display->panels['bottom'][4] = 'new-9a290d56-1ad3-4df6-bbd7-5c8689e712cb';
  $pane = new stdClass();
  $pane->pid = 'new-0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $pane->panel = 'hero';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_image_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'image',
    'formatter_settings' => array(
      'image_link' => '',
      'image_style' => '1346x330',
    ),
    'label' => 'hidden',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
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
  $pane->uuid = '0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $display->content['new-0e679027-1256-4fc6-8a56-30436d1b1a7d'] = $pane;
  $display->panels['hero'][0] = 'new-0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $pane = new stdClass();
  $pane->pid = 'new-f36c959c-86c2-42e6-9044-51d184c10ba0';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_all_updates',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content active',
    'css_id' => 'panel1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f36c959c-86c2-42e6-9044-51d184c10ba0';
  $display->content['new-f36c959c-86c2-42e6-9044-51d184c10ba0'] = $pane;
  $display->panels['tabs'][0] = 'new-f36c959c-86c2-42e6-9044-51d184c10ba0';
  $pane = new stdClass();
  $pane->pid = 'new-db63f7fc-3013-459b-aa98-687ac55ead2d';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_news',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel2',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'db63f7fc-3013-459b-aa98-687ac55ead2d';
  $display->content['new-db63f7fc-3013-459b-aa98-687ac55ead2d'] = $pane;
  $display->panels['tabs'][1] = 'new-db63f7fc-3013-459b-aa98-687ac55ead2d';
  $pane = new stdClass();
  $pane->pid = 'new-f660a804-a650-4f46-903f-44d3d596b70c';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'committee_events',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->css = array(
    'css_class' => 'content',
    'css_id' => 'panel3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f660a804-a650-4f46-903f-44d3d596b70c';
  $display->content['new-f660a804-a650-4f46-903f-44d3d596b70c'] = $pane;
  $display->panels['tabs'][2] = 'new-f660a804-a650-4f46-903f-44d3d596b70c';
  $pane = new stdClass();
  $pane->pid = 'new-4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2 class="nys-title">%term:name&nbsp;%term:field_frontend_display_type</h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $display->content['new-4e10f907-b7ad-4d70-9666-92ca25e54c5e'] = $pane;
  $display->panels['top'][0] = 'new-4e10f907-b7ad-4d70-9666-92ca25e54c5e';
  $pane = new stdClass();
  $pane->pid = 'new-0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2 class="c-committee-type"><a href="/senators-committees" title="Senators &amp; Committees">%term:field-committee-types</a></h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $display->content['new-0c07afde-6e5d-48c1-9406-2a5d78e3733f'] = $pane;
  $display->panels['top'][1] = 'new-0c07afde-6e5d-48c1-9406-2a5d78e3733f';
  $pane = new stdClass();
  $pane->pid = 'new-cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<p class="c-when">%term:field-meeting-frequency</p>
',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $display->content['new-cd6f1445-5646-4527-b2fc-6b6844254ff7'] = $pane;
  $display->panels['top'][2] = 'new-cd6f1445-5646-4527-b2fc-6b6844254ff7';
  $pane = new stdClass();
  $pane->pid = 'new-277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '%term:description',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_class' => 'c-description',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $display->content['new-277fb6bd-a50e-4752-aff3-647a85d1f6bc'] = $pane;
  $display->panels['top'][3] = 'new-277fb6bd-a50e-4752-aff3-647a85d1f6bc';
  $pane = new stdClass();
  $pane->pid = 'new-5bb38488-fdf1-46e2-961c-e4ec5f35d560';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_learn_more_page';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_term_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'entityreference_entity_view',
    'formatter_settings' => array(
      'link' => 1,
      'links' => 1,
      'view_mode' => 'token',
    ),
    'label' => 'hidden',
    'override_title' => 1,
    'override_title_heading' => 'span',
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
  $pane->uuid = '5bb38488-fdf1-46e2-961c-e4ec5f35d560';
  $display->content['new-5bb38488-fdf1-46e2-961c-e4ec5f35d560'] = $pane;
  $display->panels['top'][4] = 'new-5bb38488-fdf1-46e2-961c-e4ec5f35d560';
  $pane = new stdClass();
  $pane->pid = 'new-c4510ded-9513-4b00-b593-82eab7f7a769';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_term_1',
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
        'not' => FALSE,
        'settings' => array(
          'field_assemblymen_chair' => array(
            'und' => array(
              0 => array(
                'value' => 0,
              ),
            ),
          ),
          'field_assemblymen_chair_value' => array(
            0 => 0,
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'display' => 'main',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
    'css_class' => 'l-chair-container',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'c4510ded-9513-4b00-b593-82eab7f7a769';
  $display->content['new-c4510ded-9513-4b00-b593-82eab7f7a769'] = $pane;
  $display->panels['top'][5] = 'new-c4510ded-9513-4b00-b593-82eab7f7a769';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'plugins' => array(),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'User Profile',
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
  $display->uuid = '84435144-2bd0-44a1-a9ee-98465f3eaa2c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0f3eb0a4-00de-47c6-aed1-9065cbf09770';
  $pane->panel = 'left';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'user:profile_district_and_senator';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:user_1',
    'override_title' => 0,
    'override_title_text' => '',
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0f3eb0a4-00de-47c6-aed1-9065cbf09770';
  $display->content['new-0f3eb0a4-00de-47c6-aed1-9065cbf09770'] = $pane;
  $display->panels['left'][0] = 'new-0f3eb0a4-00de-47c6-aed1-9065cbf09770';
  $pane = new stdClass();
  $pane->pid = 'new-b7b1b5e7-001f-448e-84d3-5b611bdc7394';
  $pane->panel = 'left';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'user:profile_vitals';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:user_1',
    'override_title' => 0,
    'override_title_text' => '',
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b7b1b5e7-001f-448e-84d3-5b611bdc7394';
  $display->content['new-b7b1b5e7-001f-448e-84d3-5b611bdc7394'] = $pane;
  $display->panels['left'][1] = 'new-b7b1b5e7-001f-448e-84d3-5b611bdc7394';
  $pane = new stdClass();
  $pane->pid = 'new-5683c20f-fca5-465a-9e62-b6ba6d45d367';
  $pane->panel = 'right';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'user:privatemsg_send_new_message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:user_1',
    'override_title' => 0,
    'override_title_text' => '',
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5683c20f-fca5-465a-9e62-b6ba6d45d367';
  $display->content['new-5683c20f-fca5-465a-9e62-b6ba6d45d367'] = $pane;
  $display->panels['right'][0] = 'new-5683c20f-fca5-465a-9e62-b6ba6d45d367';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_sitewide_elements_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about_the_senate';
  $page->task = 'page';
  $page->admin_title = 'About the Senate';
  $page->admin_description = '';
  $page->path = 'about';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array(
    'name' => 'main-menu',
    'parent' => array(
      'name' => 'navigation',
      'title' => '',
      'type' => 'none',
      'weight' => '0',
    ),
    'title' => 'About the Senate',
    'type' => 'normal',
    'weight' => '0',
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_about_the_senate_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about_the_senate';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_about';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'content' => NULL,
      'default' => NULL,
      'hero' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'About the Senate';
  $display->uuid = '910a64b7-db97-4ee2-a624-50b9af37b4cd';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_about_the_senate_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4302c745-318d-4121-b91d-d3fe08dab0ec';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-about_quick_facts';
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
  $pane->uuid = '4302c745-318d-4121-b91d-d3fe08dab0ec';
  $display->content['new-4302c745-318d-4121-b91d-d3fe08dab0ec'] = $pane;
  $display->panels['content'][0] = 'new-4302c745-318d-4121-b91d-d3fe08dab0ec';
  $pane = new stdClass();
  $pane->pid = 'new-b55fcbb5-678c-4e4f-949e-df6d5fafb796';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-about_how_works';
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
  $pane->uuid = 'b55fcbb5-678c-4e4f-949e-df6d5fafb796';
  $display->content['new-b55fcbb5-678c-4e4f-949e-df6d5fafb796'] = $pane;
  $display->panels['content'][1] = 'new-b55fcbb5-678c-4e4f-949e-df6d5fafb796';
  $pane = new stdClass();
  $pane->pid = 'new-55bfe67b-a431-4fbb-a725-720b3b826cda';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-about_map';
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
  $pane->uuid = '55bfe67b-a431-4fbb-a725-720b3b826cda';
  $display->content['new-55bfe67b-a431-4fbb-a725-720b3b826cda'] = $pane;
  $display->panels['content'][2] = 'new-55bfe67b-a431-4fbb-a725-720b3b826cda';
  $pane = new stdClass();
  $pane->pid = 'new-c60e9ed4-c0a0-46f0-95fb-4f5d35c78ef5';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-about_timeline';
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
  $pane->uuid = 'c60e9ed4-c0a0-46f0-95fb-4f5d35c78ef5';
  $display->content['new-c60e9ed4-c0a0-46f0-95fb-4f5d35c78ef5'] = $pane;
  $display->panels['content'][3] = 'new-c60e9ed4-c0a0-46f0-95fb-4f5d35c78ef5';
  $pane = new stdClass();
  $pane->pid = 'new-0c39fb72-7429-4001-abaa-479b039afa54';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-about_seal';
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
  $pane->uuid = '0c39fb72-7429-4001-abaa-479b039afa54';
  $display->content['new-0c39fb72-7429-4001-abaa-479b039afa54'] = $pane;
  $display->panels['content'][4] = 'new-0c39fb72-7429-4001-abaa-479b039afa54';
  $pane = new stdClass();
  $pane->pid = 'new-ca13c414-f71a-47f7-b0cf-2c4e8164d3bf';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-about_tour';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'ca13c414-f71a-47f7-b0cf-2c4e8164d3bf';
  $display->content['new-ca13c414-f71a-47f7-b0cf-2c4e8164d3bf'] = $pane;
  $display->panels['content'][5] = 'new-ca13c414-f71a-47f7-b0cf-2c4e8164d3bf';
  $pane = new stdClass();
  $pane->pid = 'new-953cf9dc-96dd-43a9-8546-4bf864a47b2c';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'student_programs_news';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '953cf9dc-96dd-43a9-8546-4bf864a47b2c';
  $display->content['new-953cf9dc-96dd-43a9-8546-4bf864a47b2c'] = $pane;
  $display->panels['content'][6] = 'new-953cf9dc-96dd-43a9-8546-4bf864a47b2c';
  $pane = new stdClass();
  $pane->pid = 'new-a7aa4a8a-c8a5-47a3-95c9-f7961eed00f4';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-stdnt_prog_are_you';
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
  $pane->css = array(
    'css_class' => '',
    'css_id' => 'section-6',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'a7aa4a8a-c8a5-47a3-95c9-f7961eed00f4';
  $display->content['new-a7aa4a8a-c8a5-47a3-95c9-f7961eed00f4'] = $pane;
  $display->panels['content'][7] = 'new-a7aa4a8a-c8a5-47a3-95c9-f7961eed00f4';
  $pane = new stdClass();
  $pane->pid = 'new-b9dd9ba3-9cf1-4235-80f9-aeaca33331c1';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'student_programs_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'b9dd9ba3-9cf1-4235-80f9-aeaca33331c1';
  $display->content['new-b9dd9ba3-9cf1-4235-80f9-aeaca33331c1'] = $pane;
  $display->panels['content'][8] = 'new-b9dd9ba3-9cf1-4235-80f9-aeaca33331c1';
  $pane = new stdClass();
  $pane->pid = 'new-e58fa462-61be-45db-9bc5-0efc5a2fd77f';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-about_access';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'e58fa462-61be-45db-9bc5-0efc5a2fd77f';
  $display->content['new-e58fa462-61be-45db-9bc5-0efc5a2fd77f'] = $pane;
  $display->panels['content'][9] = 'new-e58fa462-61be-45db-9bc5-0efc5a2fd77f';
  $pane = new stdClass();
  $pane->pid = 'new-865d3db0-eb8b-4a4f-bbd7-602169a3e77e';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '865d3db0-eb8b-4a4f-bbd7-602169a3e77e';
  $display->content['new-865d3db0-eb8b-4a4f-bbd7-602169a3e77e'] = $pane;
  $display->panels['content'][10] = 'new-865d3db0-eb8b-4a4f-bbd7-602169a3e77e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about_the_senate'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'honoring_veterans';
  $page->task = 'page';
  $page->admin_title = 'Honoring our Veterans';
  $page->admin_description = '';
  $page->path = 'honoring-our-veterans';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_honoring_veterans__panel';
  $handler->task = 'page';
  $handler->subtask = 'honoring_veterans';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Honoring our Veterans',
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
  $display->title = 'Honoring our Veterans';
  $display->uuid = '27341acd-da15-4862-b223-43b89103e501';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_honoring_veterans__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3dd71508-6a51-4ac4-bd19-7796f9fe5669';
  $pane->panel = 'middle';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'identifier' => '',
    'leave_node_title' => 1,
    'link_node_title' => 0,
    'links' => 0,
    'nid' => '6152896',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Honoring our Veterans',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => 'veterans1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3dd71508-6a51-4ac4-bd19-7796f9fe5669';
  $display->content['new-3dd71508-6a51-4ac4-bd19-7796f9fe5669'] = $pane;
  $display->panels['middle'][0] = 'new-3dd71508-6a51-4ac4-bd19-7796f9fe5669';
  $pane = new stdClass();
  $pane->pid = 'new-836e6e04-3ab7-48c8-b57b-8d5db0f19b4f';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'manage_profiles';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'veterans_all',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Veterans\' Hall of Fame Honorees',
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
  $pane->uuid = '836e6e04-3ab7-48c8-b57b-8d5db0f19b4f';
  $display->content['new-836e6e04-3ab7-48c8-b57b-8d5db0f19b4f'] = $pane;
  $display->panels['middle'][1] = 'new-836e6e04-3ab7-48c8-b57b-8d5db0f19b4f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3dd71508-6a51-4ac4-bd19-7796f9fe5669';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['honoring_veterans'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'senators_and_committees';
  $page->task = 'page';
  $page->admin_title = 'Senators and Committees';
  $page->admin_description = '';
  $page->path = 'senators-committees';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_senators_and_committees_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'senators_and_committees';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_senators_and_committees';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'bottom' => NULL,
      'committees' => NULL,
      'default' => NULL,
      'middle' => NULL,
      'senators' => NULL,
      'top' => NULL,
    ),
    'top' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '68da0d8f-8461-4343-87ba-92fd215a7457';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_senators_and_committees_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f2068c72-bf4b-4565-b162-b4415b32ee31';
  $pane->panel = 'committees';
  $pane->type = 'views';
  $pane->subtype = 'committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'senators_committees',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = 'f2068c72-bf4b-4565-b162-b4415b32ee31';
  $display->content['new-f2068c72-bf4b-4565-b162-b4415b32ee31'] = $pane;
  $display->panels['committees'][0] = 'new-f2068c72-bf4b-4565-b162-b4415b32ee31';
  $pane = new stdClass();
  $pane->pid = 'new-5830cd82-a4a0-4254-82fe-59acffd7c1ee';
  $pane->panel = 'committees';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
  $pane->uuid = '5830cd82-a4a0-4254-82fe-59acffd7c1ee';
  $display->content['new-5830cd82-a4a0-4254-82fe-59acffd7c1ee'] = $pane;
  $display->panels['committees'][1] = 'new-5830cd82-a4a0-4254-82fe-59acffd7c1ee';
  $pane = new stdClass();
  $pane->pid = 'new-eed6bed8-280c-4077-8cd2-0a93e2c8c930';
  $pane->panel = 'senators';
  $pane->type = 'views';
  $pane->subtype = 'senators';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'senators',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = 'eed6bed8-280c-4077-8cd2-0a93e2c8c930';
  $display->content['new-eed6bed8-280c-4077-8cd2-0a93e2c8c930'] = $pane;
  $display->panels['senators'][0] = 'new-eed6bed8-280c-4077-8cd2-0a93e2c8c930';
  $pane = new stdClass();
  $pane->pid = 'new-03458ba8-2568-42eb-897b-7b8ebf6c1680';
  $pane->panel = 'senators';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-senate_directories';
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
  $pane->uuid = '03458ba8-2568-42eb-897b-7b8ebf6c1680';
  $display->content['new-03458ba8-2568-42eb-897b-7b8ebf6c1680'] = $pane;
  $display->panels['senators'][1] = 'new-03458ba8-2568-42eb-897b-7b8ebf6c1680';
  $pane = new stdClass();
  $pane->pid = 'new-3778442e-f6f7-445f-bc49-cbec5378b1bb';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-sen_comm_header';
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
  $pane->uuid = '3778442e-f6f7-445f-bc49-cbec5378b1bb';
  $display->content['new-3778442e-f6f7-445f-bc49-cbec5378b1bb'] = $pane;
  $display->panels['top'][0] = 'new-3778442e-f6f7-445f-bc49-cbec5378b1bb';
  $pane = new stdClass();
  $pane->pid = 'new-b22955d7-03a3-44eb-b5c0-5ce139af77f4';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Senators and Committee Text',
    'body' => '<p>The Senate\'s sixty-three members represent districts from across New York State. Senators belong to a single conference, and one or more political party.</p><p>We\'ve made it easy to filter senators by conference or party. You can also filter by the committees and other legislative groups senators use to consider the merit of proposed legislation and to better understand complex legislative issues.</p>',
    'format' => 'full_html',
    'substitute' => TRUE,
    'title' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b22955d7-03a3-44eb-b5c0-5ce139af77f4';
  $display->content['new-b22955d7-03a3-44eb-b5c0-5ce139af77f4'] = $pane;
  $display->panels['top'][1] = 'new-b22955d7-03a3-44eb-b5c0-5ce139af77f4';
  $pane = new stdClass();
  $pane->pid = 'new-0578061c-899d-4b5a-8bfd-f9a3c3e139df';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-active_senator_count';
  $pane->shown = TRUE;
  $pane->access = array();
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0578061c-899d-4b5a-8bfd-f9a3c3e139df';
  $display->content['new-0578061c-899d-4b5a-8bfd-f9a3c3e139df'] = $pane;
  $display->panels['top'][2] = 'new-0578061c-899d-4b5a-8bfd-f9a3c3e139df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['senators_and_committees'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'student_programs';
  $page->task = 'page';
  $page->admin_title = 'Student Programs';
  $page->admin_description = '';
  $page->path = 'student-programs';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_student_programs_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'student_programs';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Student Programs',
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
  $display->title = 'Student Programs';
  $display->uuid = '87c3a6cd-200c-4977-8817-7a0eb6798d84';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_student_programs_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-062b2d0d-8ac3-47a1-93b7-1bc7056a559a';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_programs_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_2',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
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
  $pane->uuid = '062b2d0d-8ac3-47a1-93b7-1bc7056a559a';
  $display->content['new-062b2d0d-8ac3-47a1-93b7-1bc7056a559a'] = $pane;
  $display->panels['middle'][0] = 'new-062b2d0d-8ac3-47a1-93b7-1bc7056a559a';
  $pane = new stdClass();
  $pane->pid = 'new-896f1b50-3522-4105-b9c2-81b2cf8cb2f9';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Read More Senate',
    'body' => '<div><a href="/content/senate-student-programs" class="explore-link icon-after__arrow">Learn more</a></div>',
    'format' => 'full_html',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '896f1b50-3522-4105-b9c2-81b2cf8cb2f9';
  $display->content['new-896f1b50-3522-4105-b9c2-81b2cf8cb2f9'] = $pane;
  $display->panels['middle'][1] = 'new-896f1b50-3522-4105-b9c2-81b2cf8cb2f9';
  $pane = new stdClass();
  $pane->pid = 'new-8523fb99-13d1-41de-aab6-4b8e868352db';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-stdnt_prog_are_you';
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
  $pane->uuid = '8523fb99-13d1-41de-aab6-4b8e868352db';
  $display->content['new-8523fb99-13d1-41de-aab6-4b8e868352db'] = $pane;
  $display->panels['middle'][2] = 'new-8523fb99-13d1-41de-aab6-4b8e868352db';
  $pane = new stdClass();
  $pane->pid = 'new-0df67403-3c62-4621-ad29-2c2c846eaa70';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_programs_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '1',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '0df67403-3c62-4621-ad29-2c2c846eaa70';
  $display->content['new-0df67403-3c62-4621-ad29-2c2c846eaa70'] = $pane;
  $display->panels['middle'][3] = 'new-0df67403-3c62-4621-ad29-2c2c846eaa70';
  $pane = new stdClass();
  $pane->pid = 'new-7b90a0ac-d1c1-4a87-a589-b5e314eb3a07';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-stdnt_prog_contact';
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
  $pane->uuid = '7b90a0ac-d1c1-4a87-a589-b5e314eb3a07';
  $display->content['new-7b90a0ac-d1c1-4a87-a589-b5e314eb3a07'] = $pane;
  $display->panels['middle'][4] = 'new-7b90a0ac-d1c1-4a87-a589-b5e314eb3a07';
  $pane = new stdClass();
  $pane->pid = 'new-a784b32e-a00e-41bd-9cac-4032a7d62c3b';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'student_programs_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'block_3',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a784b32e-a00e-41bd-9cac-4032a7d62c3b';
  $display->content['new-a784b32e-a00e-41bd-9cac-4032a7d62c3b'] = $pane;
  $display->panels['middle'][5] = 'new-a784b32e-a00e-41bd-9cac-4032a7d62c3b';
  $pane = new stdClass();
  $pane->pid = 'new-cdec030c-8c69-47aa-94aa-e6a916da200e';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'promo_banner_senators_committees';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_issues_promos',
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
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'cdec030c-8c69-47aa-94aa-e6a916da200e';
  $display->content['new-cdec030c-8c69-47aa-94aa-e6a916da200e'] = $pane;
  $display->panels['middle'][6] = 'new-cdec030c-8c69-47aa-94aa-e6a916da200e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['student_programs'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'thanks_page';
  $page->task = 'page';
  $page->admin_title = 'Thanks Page';
  $page->admin_description = '';
  $page->path = 'thanks/%type';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_thanks_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'thanks_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'site_contact',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
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
  $display->uuid = '85261381-349b-4a0f-86f5-c26ac746e170';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_thanks_page_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-51a2e4f4-c470-4dc4-979e-fafad13307e4';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Thank you text (TODO: Make it a block to include here)',
    'body' => '<h2 class="c-page-header--title">Thank you for Contacting the New York State Senate</h2>',
    'format' => 'full_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '51a2e4f4-c470-4dc4-979e-fafad13307e4';
  $display->content['new-51a2e4f4-c470-4dc4-979e-fafad13307e4'] = $pane;
  $display->panels['middle'][0] = 'new-51a2e4f4-c470-4dc4-979e-fafad13307e4';
  $pane = new stdClass();
  $pane->pid = 'new-f52fea82-ad8a-4e1c-bc25-0fb89b387b1e';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'all_news',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '5',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f52fea82-ad8a-4e1c-bc25-0fb89b387b1e';
  $display->content['new-f52fea82-ad8a-4e1c-bc25-0fb89b387b1e'] = $pane;
  $display->panels['middle'][1] = 'new-f52fea82-ad8a-4e1c-bc25-0fb89b387b1e';
  $pane = new stdClass();
  $pane->pid = 'new-ec53c3f2-5b98-42a3-8d98-15db1cd51423';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'news_block',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '3',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
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
  $pane->uuid = 'ec53c3f2-5b98-42a3-8d98-15db1cd51423';
  $display->content['new-ec53c3f2-5b98-42a3-8d98-15db1cd51423'] = $pane;
  $display->panels['middle'][2] = 'new-ec53c3f2-5b98-42a3-8d98-15db1cd51423';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f52fea82-ad8a-4e1c-bc25-0fb89b387b1e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_thanks_page_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'thanks_page';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'foil',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'FOIL Request',
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
  $display->title = 'Thanks';
  $display->uuid = '85261381-349b-4a0f-86f5-c26ac746e170';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_thanks_page_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-51a2e4f4-c470-4dc4-979e-fafad13307e4';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Thank you text',
    'body' => '<section class="l-messages l-messages-thanks">
<div data-alert="" class="alert-box success">
<div class="alert-box-message">
<h2 class="element-invisible">Status message</h2>
Thank you. Your FOIL request has been submitted.<a href="#" class="close">×</a>
</div>
</div>
</section>',
    'format' => 'php_code',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '51a2e4f4-c470-4dc4-979e-fafad13307e4';
  $display->content['new-51a2e4f4-c470-4dc4-979e-fafad13307e4'] = $pane;
  $display->panels['middle'][0] = 'new-51a2e4f4-c470-4dc4-979e-fafad13307e4';
  $pane = new stdClass();
  $pane->pid = 'new-a109e91b-177a-4e26-82a5-fbbdef22baa0';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'foil_news_block',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a109e91b-177a-4e26-82a5-fbbdef22baa0';
  $display->content['new-a109e91b-177a-4e26-82a5-fbbdef22baa0'] = $pane;
  $display->panels['middle'][1] = 'new-a109e91b-177a-4e26-82a5-fbbdef22baa0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['thanks_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'women_of_distinction';
  $page->task = 'page';
  $page->admin_title = 'Women of Distinction';
  $page->admin_description = 'Page for all Women of Distinction Honorees';
  $page->path = 'women-of-distinction';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_women_of_distinction__panel';
  $handler->task = 'page';
  $handler->subtask = 'women_of_distinction';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
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
  $display->title = 'Women of Distinction';
  $display->uuid = '989634e4-f370-4cfe-ad5a-d6672775a01a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_women_of_distinction__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a673f6f1-8518-470b-b1e0-fbeac681b0f5';
  $pane->panel = 'middle';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'identifier' => '',
    'leave_node_title' => 1,
    'link_node_title' => 0,
    'links' => 0,
    'nid' => '6152901',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => 'veterans1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a673f6f1-8518-470b-b1e0-fbeac681b0f5';
  $display->content['new-a673f6f1-8518-470b-b1e0-fbeac681b0f5'] = $pane;
  $display->panels['middle'][0] = 'new-a673f6f1-8518-470b-b1e0-fbeac681b0f5';
  $pane = new stdClass();
  $pane->pid = 'new-caf68c16-a107-4df5-b102-ef616ae73752';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'manage_profiles';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'women_all',
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
  $pane->uuid = 'caf68c16-a107-4df5-b102-ef616ae73752';
  $display->content['new-caf68c16-a107-4df5-b102-ef616ae73752'] = $pane;
  $display->panels['middle'][1] = 'new-caf68c16-a107-4df5-b102-ef616ae73752';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-a673f6f1-8518-470b-b1e0-fbeac681b0f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['women_of_distinction'] = $page;

  return $pages;

}
