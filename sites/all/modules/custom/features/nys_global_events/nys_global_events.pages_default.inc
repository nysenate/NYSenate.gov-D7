<?php
/**
 * @file
 * nys_global_events.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_global_events_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_a81f0e09-5af4-4948-987e-b8ed6606a0d7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Public Hearing Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy term from Node (on Node: Committees [field_committee])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_committee-node-taxonomy_term',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'public_hearing' => 'public_hearing',
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
  $display->layout = 'f2cb_public_hearing';
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
  $display->storage_id = 'node_view__panel_context_a81f0e09-5af4-4948-987e-b8ed6606a0d7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3703dd3a-f266-4890-abc2-2e3789bfc95b';
  $pane->panel = 'bottom';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Committee Header',
    'title' => '',
    'body' => '<div class="c-block"><h2 class="c-title">%node:field_committee Committee</h2><h3 class="c-committee-type">%taxonomy_term:field-committee-types</h3><p class="c-when">%taxonomy_term:field_meeting_frequency</p>%taxonomy_term:description</div>',
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
  $pane->uuid = '3703dd3a-f266-4890-abc2-2e3789bfc95b';
  $display->content['new-3703dd3a-f266-4890-abc2-2e3789bfc95b'] = $pane;
  $display->panels['bottom'][0] = 'new-3703dd3a-f266-4890-abc2-2e3789bfc95b';
  $pane = new stdClass();
  $pane->pid = 'new-efaa7f79-0fa3-4826-bad9-002e67252c12';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'chair',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
    ),
    'override_title' => 1,
    'override_title_text' => 'Members',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'div',
        'attributes' => array(
          'id' => '',
          'class' => 'c-members-title',
        ),
      ),
      'content' => array(
        'element' => '',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'efaa7f79-0fa3-4826-bad9-002e67252c12';
  $display->content['new-efaa7f79-0fa3-4826-bad9-002e67252c12'] = $pane;
  $display->panels['bottom'][1] = 'new-efaa7f79-0fa3-4826-bad9-002e67252c12';
  $pane = new stdClass();
  $pane->pid = 'new-a2ff23d7-dd2c-465a-bf7f-69592e739fc3';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1',
        'not' => FALSE,
      ),
    ),
  );
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
    'display' => 'listing',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
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
  $pane->uuid = 'a2ff23d7-dd2c-465a-bf7f-69592e739fc3';
  $display->content['new-a2ff23d7-dd2c-465a-bf7f-69592e739fc3'] = $pane;
  $display->panels['bottom'][2] = 'new-a2ff23d7-dd2c-465a-bf7f-69592e739fc3';
  $pane = new stdClass();
  $pane->pid = 'new-ce1e237e-0794-4014-8ce1-8ef0239c653b';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ce1e237e-0794-4014-8ce1-8ef0239c653b';
  $display->content['new-ce1e237e-0794-4014-8ce1-8ef0239c653b'] = $pane;
  $display->panels['bottom'][3] = 'new-ce1e237e-0794-4014-8ce1-8ef0239c653b';
  $pane = new stdClass();
  $pane->pid = 'new-4fcb7c2b-ab28-4db1-8f93-66642795802a';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '4fcb7c2b-ab28-4db1-8f93-66642795802a';
  $display->content['new-4fcb7c2b-ab28-4db1-8f93-66642795802a'] = $pane;
  $display->panels['bottom'][4] = 'new-4fcb7c2b-ab28-4db1-8f93-66642795802a';
  $pane = new stdClass();
  $pane->pid = 'new-12636119-dd39-4e2d-b62c-568ab62e5b52';
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
  $pane->uuid = '12636119-dd39-4e2d-b62c-568ab62e5b52';
  $display->content['new-12636119-dd39-4e2d-b62c-568ab62e5b52'] = $pane;
  $display->panels['top'][0] = 'new-12636119-dd39-4e2d-b62c-568ab62e5b52';
  $pane = new stdClass();
  $pane->pid = 'new-bf8da60a-bf79-4261-8c91-a3651f7b4e3b';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_attachment';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'file_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-news--download',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'bf8da60a-bf79-4261-8c91-a3651f7b4e3b';
  $display->content['new-bf8da60a-bf79-4261-8c91-a3651f7b4e3b'] = $pane;
  $display->panels['top'][1] = 'new-bf8da60a-bf79-4261-8c91-a3651f7b4e3b';
  $pane = new stdClass();
  $pane->pid = 'new-ed19af87-2366-4c34-9559-31d164acdff7';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_transcript';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'ed19af87-2366-4c34-9559-31d164acdff7';
  $display->content['new-ed19af87-2366-4c34-9559-31d164acdff7'] = $pane;
  $display->panels['top'][2] = 'new-ed19af87-2366-4c34-9559-31d164acdff7';
  $pane = new stdClass();
  $pane->pid = 'new-299804f2-9fae-4b5b-988c-01da10899cdd';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '299804f2-9fae-4b5b-988c-01da10899cdd';
  $display->content['new-299804f2-9fae-4b5b-988c-01da10899cdd'] = $pane;
  $display->panels['top'][3] = 'new-299804f2-9fae-4b5b-988c-01da10899cdd';
  $pane = new stdClass();
  $pane->pid = 'new-fa3a9391-6217-4ed5-9281-bcfc3f14a153';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'issues_listings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '9',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'meeting_issues',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 0,
    'override_title_text' => 'Related Issues',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'h3',
        'attributes' => array(
          'id' => '',
          'class' => 'nys-title',
        ),
      ),
      'content' => array(
        'element' => '',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'fa3a9391-6217-4ed5-9281-bcfc3f14a153';
  $display->content['new-fa3a9391-6217-4ed5-9281-bcfc3f14a153'] = $pane;
  $display->panels['top'][4] = 'new-fa3a9391-6217-4ed5-9281-bcfc3f14a153';
  $pane = new stdClass();
  $pane->pid = 'new-092c98ca-66db-4efd-9239-a6d348e08e1d';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'committee_meetings';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1',
        'not' => FALSE,
      ),
    ),
  );
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
    'display' => 'past',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => 'Past %taxonomy_term:name Committee Events',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'div',
        'attributes' => array(
          'id' => '',
          'class' => 'c-members-title',
        ),
      ),
      'content' => array(
        'element' => '',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '092c98ca-66db-4efd-9239-a6d348e08e1d';
  $display->content['new-092c98ca-66db-4efd-9239-a6d348e08e1d'] = $pane;
  $display->panels['top'][5] = 'new-092c98ca-66db-4efd-9239-a6d348e08e1d';
  $pane = new stdClass();
  $pane->pid = 'new-61c3ecbb-aadf-4211-b29e-c72bc4efb359';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'committee_news',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => '%taxonomy_term:name Committee News',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'div',
        'attributes' => array(
          'id' => '',
          'class' => 'c-members-title',
        ),
      ),
      'content' => array(
        'element' => '',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '61c3ecbb-aadf-4211-b29e-c72bc4efb359';
  $display->content['new-61c3ecbb-aadf-4211-b29e-c72bc4efb359'] = $pane;
  $display->panels['top'][6] = 'new-61c3ecbb-aadf-4211-b29e-c72bc4efb359';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_a81f0e09-5af4-4948-987e-b8ed6606a0d7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Meeting Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy term from Node (on Node: Committee [field_committee])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_committee-node-taxonomy_term',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'meeting' => 'meeting',
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
  $display->layout = 'f2cb_meeting_page';
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
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3703dd3a-f266-4890-abc2-2e3789bfc95b';
  $pane->panel = 'bottom';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Committee Header',
    'title' => '',
    'body' => '<div class="c-block"><h2 class="c-title">%node:field_committee Committee</h2><h3 class="c-committee-type">%taxonomy_term:field-committee-types</h3><p class="c-when">%taxonomy_term:field_meeting_frequency</p>%taxonomy_term:description</div>',
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
  $pane->uuid = '3703dd3a-f266-4890-abc2-2e3789bfc95b';
  $display->content['new-3703dd3a-f266-4890-abc2-2e3789bfc95b'] = $pane;
  $display->panels['bottom'][0] = 'new-3703dd3a-f266-4890-abc2-2e3789bfc95b';
  $pane = new stdClass();
  $pane->pid = 'new-efaa7f79-0fa3-4826-bad9-002e67252c12';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'chair',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
    ),
    'override_title' => 1,
    'override_title_text' => 'Members',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'div',
        'attributes' => array(
          'id' => '',
          'class' => 'c-members-title',
        ),
      ),
      'content' => array(
        'element' => '',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'efaa7f79-0fa3-4826-bad9-002e67252c12';
  $display->content['new-efaa7f79-0fa3-4826-bad9-002e67252c12'] = $pane;
  $display->panels['bottom'][1] = 'new-efaa7f79-0fa3-4826-bad9-002e67252c12';
  $pane = new stdClass();
  $pane->pid = 'new-a2ff23d7-dd2c-465a-bf7f-69592e739fc3';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1',
        'not' => FALSE,
      ),
    ),
  );
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
    'display' => 'listing',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'a2ff23d7-dd2c-465a-bf7f-69592e739fc3';
  $display->content['new-a2ff23d7-dd2c-465a-bf7f-69592e739fc3'] = $pane;
  $display->panels['bottom'][2] = 'new-a2ff23d7-dd2c-465a-bf7f-69592e739fc3';
  $pane = new stdClass();
  $pane->pid = 'new-f3f87efe-4c1e-479d-8a8a-659f6394d350';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f3f87efe-4c1e-479d-8a8a-659f6394d350';
  $display->content['new-f3f87efe-4c1e-479d-8a8a-659f6394d350'] = $pane;
  $display->panels['bottom'][3] = 'new-f3f87efe-4c1e-479d-8a8a-659f6394d350';
  $pane = new stdClass();
  $pane->pid = 'new-4fcb7c2b-ab28-4db1-8f93-66642795802a';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '4fcb7c2b-ab28-4db1-8f93-66642795802a';
  $display->content['new-4fcb7c2b-ab28-4db1-8f93-66642795802a'] = $pane;
  $display->panels['bottom'][4] = 'new-4fcb7c2b-ab28-4db1-8f93-66642795802a';
  $pane = new stdClass();
  $pane->pid = 'new-3584d50c-ad08-4896-8b6e-62536cdf800f';
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
  $pane->uuid = '3584d50c-ad08-4896-8b6e-62536cdf800f';
  $display->content['new-3584d50c-ad08-4896-8b6e-62536cdf800f'] = $pane;
  $display->panels['top'][0] = 'new-3584d50c-ad08-4896-8b6e-62536cdf800f';
  $pane = new stdClass();
  $pane->pid = 'new-3fdc151b-c041-42fb-bf0c-460e631e8dbf';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'meeting_agenda_block';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
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
    'display' => 'meeting_agenda',
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
  $pane->uuid = '3fdc151b-c041-42fb-bf0c-460e631e8dbf';
  $display->content['new-3fdc151b-c041-42fb-bf0c-460e631e8dbf'] = $pane;
  $display->panels['top'][1] = 'new-3fdc151b-c041-42fb-bf0c-460e631e8dbf';
  $pane = new stdClass();
  $pane->pid = 'new-83f7b7cf-4f4e-4da5-98b2-62abc897978c';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_transcript';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '83f7b7cf-4f4e-4da5-98b2-62abc897978c';
  $display->content['new-83f7b7cf-4f4e-4da5-98b2-62abc897978c'] = $pane;
  $display->panels['top'][2] = 'new-83f7b7cf-4f4e-4da5-98b2-62abc897978c';
  $pane = new stdClass();
  $pane->pid = 'new-299804f2-9fae-4b5b-988c-01da10899cdd';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '299804f2-9fae-4b5b-988c-01da10899cdd';
  $display->content['new-299804f2-9fae-4b5b-988c-01da10899cdd'] = $pane;
  $display->panels['top'][3] = 'new-299804f2-9fae-4b5b-988c-01da10899cdd';
  $pane = new stdClass();
  $pane->pid = 'new-092c98ca-66db-4efd-9239-a6d348e08e1d';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'committee_meetings';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1',
        'not' => FALSE,
      ),
    ),
  );
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
    'display' => 'past',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => 'Past %taxonomy_term:name Committee Events',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'div',
        'attributes' => array(
          'id' => '',
          'class' => 'c-members-title',
        ),
      ),
      'content' => array(
        'element' => '',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '092c98ca-66db-4efd-9239-a6d348e08e1d';
  $display->content['new-092c98ca-66db-4efd-9239-a6d348e08e1d'] = $pane;
  $display->panels['top'][4] = 'new-092c98ca-66db-4efd-9239-a6d348e08e1d';
  $pane = new stdClass();
  $pane->pid = 'new-61c3ecbb-aadf-4211-b29e-c72bc4efb359';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'senator_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'committee_news',
    'context' => array(
      0 => 'relationship_entity_from_field:field_committee-node-taxonomy_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => '%taxonomy_term:name Committee News',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => 'div',
        'attributes' => array(
          'id' => '',
          'class' => 'c-members-title',
        ),
      ),
      'content' => array(
        'element' => '',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'theme' => 0,
    ),
    'style' => 'wrapper_element',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '61c3ecbb-aadf-4211-b29e-c72bc4efb359';
  $display->content['new-61c3ecbb-aadf-4211-b29e-c72bc4efb359'] = $pane;
  $display->panels['top'][5] = 'new-61c3ecbb-aadf-4211-b29e-c72bc4efb359';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
