<?php
/**
 * @file
 * nys_wasteland_blog.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nys_wasteland_blog_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__investigations-cmte-experimental';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Investigations Cmte. (Experimental)',
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
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'committees' => 'committees',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'term',
          'settings' => array(
            'vid' => '11',
            11 => array(
              6536 => '6536',
            ),
            8 => array(),
            4 => array(),
            12 => array(),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'investigations-cmte-experimental',
  );
  $display = new panels_display();
  $display->layout = 'f2cb_committee_detail';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => array(
        'content' => array(
          'element' => 'div',
          'attributes' => array(
            'id' => '',
            'class' => 'c-committee-header',
          ),
        ),
        'theme' => 0,
      ),
      'middle' => NULL,
      'top' => NULL,
      'bottom' => array(
        'content' => array(
          'element' => 'div',
          'attributes' => array(
            'id' => 'members',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'below_top' => NULL,
      'hero' => NULL,
      'tabs' => NULL,
    ),
    'style' => 'wrapper_element',
    'tabs' => array(
      'style' => 'default',
    ),
    'bottom' => array(
      'style' => 'wrapper_element',
    ),
    'below_top' => array(
      'style' => 'naked',
    ),
    'hero' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = 'My title';
  $display->uuid = '04d24cfd-c9a8-4b62-b585-b8d45151b063';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view__investigations-cmte-experimental';
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
    'display' => 'featured_committee_event',
    'context' => array(
      0 => 'argument_term_1.tid',
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
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
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
        'context' => 'argument_term_1',
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
    'display' => 'committee_featured_story',
    'context' => array(
      0 => 'argument_term_1.tid',
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
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
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
        'context' => 'argument_term_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'field_collection_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 1,
      'view_mode' => 'full',
    ),
    'context' => 'argument_term_1',
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
  $pane->uuid = 'b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $display->content['new-b9d3be73-e191-4b4a-944c-2279d1e064a6'] = $pane;
  $display->panels['below_top'][2] = 'new-b9d3be73-e191-4b4a-944c-2279d1e064a6';
  $pane = new stdClass();
  $pane->pid = 'new-654cbc0c-e8ab-4d9a-be3b-f2632b6281a5';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = FALSE;
  $pane->access = array();
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
      0 => 'argument_term_1.tid',
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
      0 => 'argument_term_1.tid',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e4c02344-1999-456a-9789-f02bcbbb664d';
  $display->content['new-e4c02344-1999-456a-9789-f02bcbbb664d'] = $pane;
  $display->panels['bottom'][1] = 'new-e4c02344-1999-456a-9789-f02bcbbb664d';
  $pane = new stdClass();
  $pane->pid = 'new-6ae683bc-b140-4aeb-9f75-1866488fcd19';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
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
        'context' => 'argument_term_1',
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
    'display' => 'block_3',
    'context' => array(
      0 => 'argument_term_1.tid',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6ae683bc-b140-4aeb-9f75-1866488fcd19';
  $display->content['new-6ae683bc-b140-4aeb-9f75-1866488fcd19'] = $pane;
  $display->panels['bottom'][2] = 'new-6ae683bc-b140-4aeb-9f75-1866488fcd19';
  $pane = new stdClass();
  $pane->pid = 'new-18378829-fc0a-4f7b-af9b-835c3fe189c4';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
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
        'context' => 'argument_term_1',
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
    'display' => 'block_2',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'members',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '18378829-fc0a-4f7b-af9b-835c3fe189c4';
  $display->content['new-18378829-fc0a-4f7b-af9b-835c3fe189c4'] = $pane;
  $display->panels['bottom'][3] = 'new-18378829-fc0a-4f7b-af9b-835c3fe189c4';
  $pane = new stdClass();
  $pane->pid = 'new-9fa27b8f-6105-4872-b3f7-24b8617753a8';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
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
        'context' => 'argument_term_1',
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
    'display' => 'members',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
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
    'css_class' => 'c-senators-container',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9fa27b8f-6105-4872-b3f7-24b8617753a8';
  $display->content['new-9fa27b8f-6105-4872-b3f7-24b8617753a8'] = $pane;
  $display->panels['bottom'][4] = 'new-9fa27b8f-6105-4872-b3f7-24b8617753a8';
  $pane = new stdClass();
  $pane->pid = 'new-f5172e25-0a03-4a06-95df-b340625f4aaf';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f5172e25-0a03-4a06-95df-b340625f4aaf';
  $display->content['new-f5172e25-0a03-4a06-95df-b340625f4aaf'] = $pane;
  $display->panels['bottom'][5] = 'new-f5172e25-0a03-4a06-95df-b340625f4aaf';
  $pane = new stdClass();
  $pane->pid = 'new-9a290d56-1ad3-4df6-bbd7-5c8689e712cb';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '9a290d56-1ad3-4df6-bbd7-5c8689e712cb';
  $display->content['new-9a290d56-1ad3-4df6-bbd7-5c8689e712cb'] = $pane;
  $display->panels['bottom'][6] = 'new-9a290d56-1ad3-4df6-bbd7-5c8689e712cb';
  $pane = new stdClass();
  $pane->pid = 'new-0e679027-1256-4fc6-8a56-30436d1b1a7d';
  $pane->panel = 'hero';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_image_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '1346x330',
      'image_link' => '',
    ),
    'context' => 'argument_term_1',
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
    'css_class' => '',
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
    'display' => 'committee_all_updates',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
      0 => 'argument_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
    'display' => 'committee_events',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'panel3',
    'css_class' => 'content',
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
    'title' => '',
    'body' => '<h2 class="nys-title">%term:name&nbsp;%term:field_frontend_display_type</h2>',
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
    'title' => '',
    'body' => '<h2 class="c-committee-type"><a href="/senators-committees" title="Senators &amp; Committees">%term:field-committee-types</a></h2>',
    'format' => 'full_html',
    'substitute' => 1,
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
    'title' => '',
    'body' => '<p class="c-when">%term:field-meeting-frequency</p>
',
    'format' => 'full_html',
    'substitute' => 1,
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
    'title' => '',
    'body' => '%term:description',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'c-description',
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
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
      'view_mode' => 'token',
      'links' => 1,
    ),
    'context' => 'argument_term_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
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
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
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
        'context' => 'argument_term_1',
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
    'display' => 'main',
    'context' => array(
      0 => 'argument_term_1.tid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'l-chair-container',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'c4510ded-9513-4b00-b593-82eab7f7a769';
  $display->content['new-c4510ded-9513-4b00-b593-82eab7f7a769'] = $pane;
  $display->panels['top'][5] = 'new-c4510ded-9513-4b00-b593-82eab7f7a769';
  $pane = new stdClass();
  $pane->pid = 'new-8f8a5fe7-7aa3-4069-a935-b33cf36c6b7a';
  $pane->panel = 'top';
  $pane->type = 'views';
  $pane->subtype = 'committee_members';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:taxonomy_term:committees:field_assemblymen_chair',
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
        'context' => 'argument_term_1',
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
    'display' => 'block_2',
    'context' => array(
      0 => 'argument_term_1.tid',
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '8f8a5fe7-7aa3-4069-a935-b33cf36c6b7a';
  $display->content['new-8f8a5fe7-7aa3-4069-a935-b33cf36c6b7a'] = $pane;
  $display->panels['top'][6] = 'new-8f8a5fe7-7aa3-4069-a935-b33cf36c6b7a';
  $pane = new stdClass();
  $pane->pid = 'new-cf16aa8d-e5aa-4618-b3c4-2755a33f0810';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-investigations_teaser';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'cf16aa8d-e5aa-4618-b3c4-2755a33f0810';
  $display->content['new-cf16aa8d-e5aa-4618-b3c4-2755a33f0810'] = $pane;
  $display->panels['top'][7] = 'new-cf16aa8d-e5aa-4618-b3c4-2755a33f0810';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__investigations-cmte-experimental'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function nys_wasteland_blog_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'gov_ops_letter_list';
  $page->task = 'page';
  $page->admin_title = 'Gov Ops Letter List';
  $page->admin_description = '';
  $page->path = 'chair-letters/gov-ops';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
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
  $handler->name = 'page_gov_ops_letter_list__panel_context_ca2ecca3-8baa-416a-aa55-3bd2f8829fb9';
  $handler->task = 'page';
  $handler->subtask = 'gov_ops_letter_list';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Taxonomy term',
        'keyword' => 'taxonomy_term',
        'name' => 'entity:taxonomy_term',
        'entity_id' => '6536',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'f2cb_wasteland';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'tabs' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Letters from the Chair';
  $display->uuid = '4fd36ccb-ebc3-4206-8078-a20ade9141b4';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_gov_ops_letter_list__panel_context_ca2ecca3-8baa-416a-aa55-3bd2f8829fb9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e6449607-0452-4b8c-bee7-b39588ff524f';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
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
    'display' => 'block_2',
    'context' => array(
      0 => 'context_entity:taxonomy_term_1.tid',
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
  $pane->uuid = 'e6449607-0452-4b8c-bee7-b39588ff524f';
  $display->content['new-e6449607-0452-4b8c-bee7-b39588ff524f'] = $pane;
  $display->panels['bottom'][0] = 'new-e6449607-0452-4b8c-bee7-b39588ff524f';
  $pane = new stdClass();
  $pane->pid = 'new-d721e62f-d32f-428b-a8f9-982a630d0a13';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
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
    'display' => 'members',
    'context' => array(
      0 => 'context_entity:taxonomy_term_1.tid',
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
  $pane->uuid = 'd721e62f-d32f-428b-a8f9-982a630d0a13';
  $display->content['new-d721e62f-d32f-428b-a8f9-982a630d0a13'] = $pane;
  $display->panels['bottom'][1] = 'new-d721e62f-d32f-428b-a8f9-982a630d0a13';
  $pane = new stdClass();
  $pane->pid = 'new-11d2c4fc-dfc6-4171-af49-cc6cd7af2827';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
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
    'display' => 'block_2',
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
  $pane->uuid = '11d2c4fc-dfc6-4171-af49-cc6cd7af2827';
  $display->content['new-11d2c4fc-dfc6-4171-af49-cc6cd7af2827'] = $pane;
  $display->panels['tabs'][0] = 'new-11d2c4fc-dfc6-4171-af49-cc6cd7af2827';
  $pane = new stdClass();
  $pane->pid = 'new-6f696df0-0a0a-41b4-bd27-fb01cdc65d80';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-gov_ops_letters_head';
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
  $pane->uuid = '6f696df0-0a0a-41b4-bd27-fb01cdc65d80';
  $display->content['new-6f696df0-0a0a-41b4-bd27-fb01cdc65d80'] = $pane;
  $display->panels['top'][0] = 'new-6f696df0-0a0a-41b4-bd27-fb01cdc65d80';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['gov_ops_letter_list'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'gov_ops_waste_blog';
  $page->task = 'page';
  $page->admin_title = 'Gov Ops Waste Blog';
  $page->admin_description = '';
  $page->path = 'blogs/wasteland';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
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
  $handler->name = 'page_gov_ops_waste_blog__panel';
  $handler->task = 'page';
  $handler->subtask = 'gov_ops_waste_blog';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Taxonomy term',
        'keyword' => 'taxonomy_term',
        'name' => 'entity:taxonomy_term',
        'entity_id' => '6536',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'f2cb_wasteland';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'tabs' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Waste Blog';
  $display->uuid = '4fd36ccb-ebc3-4206-8078-a20ade9141b4';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_gov_ops_waste_blog__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e6449607-0452-4b8c-bee7-b39588ff524f';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
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
    'display' => 'block_2',
    'context' => array(
      0 => 'context_entity:taxonomy_term_1.tid',
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
  $pane->uuid = 'e6449607-0452-4b8c-bee7-b39588ff524f';
  $display->content['new-e6449607-0452-4b8c-bee7-b39588ff524f'] = $pane;
  $display->panels['bottom'][0] = 'new-e6449607-0452-4b8c-bee7-b39588ff524f';
  $pane = new stdClass();
  $pane->pid = 'new-d721e62f-d32f-428b-a8f9-982a630d0a13';
  $pane->panel = 'bottom';
  $pane->type = 'views';
  $pane->subtype = 'committee_chair';
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
    'display' => 'members',
    'context' => array(
      0 => 'context_entity:taxonomy_term_1.tid',
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
  $pane->uuid = 'd721e62f-d32f-428b-a8f9-982a630d0a13';
  $display->content['new-d721e62f-d32f-428b-a8f9-982a630d0a13'] = $pane;
  $display->panels['bottom'][1] = 'new-d721e62f-d32f-428b-a8f9-982a630d0a13';
  $pane = new stdClass();
  $pane->pid = 'new-26872c53-a445-4e92-8e52-2597e0ae1d91';
  $pane->panel = 'tabs';
  $pane->type = 'views';
  $pane->subtype = 'newsroom';
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
    'display' => 'block_1',
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
  $pane->uuid = '26872c53-a445-4e92-8e52-2597e0ae1d91';
  $display->content['new-26872c53-a445-4e92-8e52-2597e0ae1d91'] = $pane;
  $display->panels['tabs'][0] = 'new-26872c53-a445-4e92-8e52-2597e0ae1d91';
  $pane = new stdClass();
  $pane->pid = 'new-fe0c80c5-fbb4-4b33-8126-5d8131269e2c';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'nys_blocks-wasteland_head';
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
  $pane->uuid = 'fe0c80c5-fbb4-4b33-8126-5d8131269e2c';
  $display->content['new-fe0c80c5-fbb4-4b33-8126-5d8131269e2c'] = $pane;
  $display->panels['top'][0] = 'new-fe0c80c5-fbb4-4b33-8126-5d8131269e2c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fe0c80c5-fbb4-4b33-8126-5d8131269e2c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['gov_ops_waste_blog'] = $page;

  return $pages;

}
