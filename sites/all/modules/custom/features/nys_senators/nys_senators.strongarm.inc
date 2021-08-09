<?php

/**
 * @file
 * nys_senators.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nys_senators_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_petition';
  $strongarm->value = 0;
  $export['comment_anonymous_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_senator';
  $strongarm->value = 0;
  $export['comment_anonymous_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_petition';
  $strongarm->value = 1;
  $export['comment_default_mode_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_senator';
  $strongarm->value = 1;
  $export['comment_default_mode_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_petition';
  $strongarm->value = '50';
  $export['comment_default_per_page_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_senator';
  $strongarm->value = '50';
  $export['comment_default_per_page_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_petition';
  $strongarm->value = 1;
  $export['comment_form_location_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_senator';
  $strongarm->value = 1;
  $export['comment_form_location_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_petition';
  $strongarm->value = '0';
  $export['comment_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_petition';
  $strongarm->value = '1';
  $export['comment_preview_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_senator';
  $strongarm->value = '1';
  $export['comment_preview_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_senator';
  $strongarm->value = '0';
  $export['comment_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_petition';
  $strongarm->value = 1;
  $export['comment_subject_field_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_senator';
  $strongarm->value = 1;
  $export['comment_subject_field_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_chapter';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_promotional_banner';
  $strongarm->value = 0;
  $export['diff_enable_revisions_page_node_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_chapter';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_promotional_banner';
  $strongarm->value = 0;
  $export['diff_show_preview_changes_node_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_chapter';
  $strongarm->value = '';
  $export['diff_view_mode_preview_node_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_promotional_banner';
  $strongarm->value = '';
  $export['diff_view_mode_preview_node_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_admin_show_component_field_validation_rule';
  $strongarm->value = 1;
  $export['features_admin_show_component_field_validation_rule'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_component_locked_field_validation_rule';
  $strongarm->value = 0;
  $export['features_component_locked_field_validation_rule'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_half_promo_banner';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'slick_carousel' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_half_promo_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__petition';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'node_embed' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '13',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '12',
        ),
        'metatags' => array(
          'weight' => '14',
        ),
        'redirect' => array(
          'weight' => '15',
        ),
        'xmlsitemap' => array(
          'weight' => '16',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'flag_sign_petition' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'search_index' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__promotional_banner';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'node_embed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'bill_list_item' => array(
        'custom_settings' => FALSE,
      ),
      'block_teaser_content' => array(
        'custom_settings' => FALSE,
      ),
      'sponsor_list' => array(
        'custom_settings' => FALSE,
      ),
      'agenda_senator_sponsors' => array(
        'custom_settings' => FALSE,
      ),
      'senator_search_list' => array(
        'custom_settings' => FALSE,
      ),
      'senators_involved' => array(
        'custom_settings' => FALSE,
      ),
      'sponsor_list_bill_detail' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '9',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__senator';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_embed' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'sponsor_list' => array(
        'custom_settings' => TRUE,
      ),
      'sponsor_list_bill_detail' => array(
        'custom_settings' => TRUE,
      ),
      'senator_search_list' => array(
        'custom_settings' => TRUE,
      ),
      'bill_list_item' => array(
        'custom_settings' => FALSE,
      ),
      'senators_involved' => array(
        'custom_settings' => TRUE,
      ),
      'agenda_senator_sponsors' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '17',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '16',
        ),
        'flag' => array(
          'weight' => '14',
        ),
        'metatags' => array(
          'weight' => '18',
        ),
        'redirect' => array(
          'weight' => '21',
        ),
        'xmlsitemap' => array(
          'weight' => '22',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_chapter';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_petition';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_promotional_banner';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_senator';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_chapter';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_petition';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_promotional_banner';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_senator';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_chapter';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_petition';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_promotional_banner';
  $strongarm->value = array();
  $export['node_options_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_senator';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_chapter';
  $strongarm->value = '0';
  $export['node_preview_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_petition';
  $strongarm->value = '0';
  $export['node_preview_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_promotional_banner';
  $strongarm->value = '0';
  $export['node_preview_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_senator';
  $strongarm->value = '0';
  $export['node_preview_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_chapter';
  $strongarm->value = 1;
  $export['node_submitted_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_petition';
  $strongarm->value = 0;
  $export['node_submitted_petition'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_promotional_banner';
  $strongarm->value = 0;
  $export['node_submitted_promotional_banner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_senator';
  $strongarm->value = 0;
  $export['node_submitted_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_senator';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(),
  );
  $export['panelizer_defaults_node_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:senator:page_manager_selection';
  $strongarm->value = 'node:senator:default';
  $export['panelizer_node:senator:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:senator_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:22:"panelizer_node:senator";s:23:"allowed_layout_settings";a:36:{s:8:"flexible";b:0;s:6:"twocol";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:17:"threecol_33_34_33";b:0;s:13:"twocol_bricks";b:0;s:6:"onecol";b:0;s:14:"twocol_stacked";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:15:"foundation_2col";b:0;s:23:"foundation_3col_stacked";b:0;s:15:"foundation_3col";b:0;s:21:"foundation_6row_combo";b:0;s:23:"foundation_2col_stacked";b:0;s:22:"foundation_2col_bricks";b:0;s:15:"foundation_4col";b:0;s:15:"foundation_1col";b:0;s:28:"f2cb_senators_and_committees";b:0;s:21:"f2cb_committee_detail";b:0;s:13:"f2cb_calendar";b:0;s:13:"f2cb_homepage";b:1;s:17:"f2cb_session_page";b:0;s:14:"f2cb_wasteland";b:0;s:13:"f2cb_newsroom";b:0;s:19:"f2cb_public_hearing";b:0;s:17:"f2cb_issue_detail";b:0;s:16:"f2cb_legislation";b:0;s:17:"f2cb_meeting_page";b:0;s:10:"f2cb_about";b:0;s:24:"f2cb_senator_legislation";b:0;s:8:"rss_feed";b:0;s:14:"f2cb_homepage2";b:1;s:13:"f2cb_earthday";b:1;s:20:"f2cb_majority_issue2";b:1;s:19:"f2cb_majority_issue";b:1;s:12:"f2cb_pbudget";b:1;}s:10:"form_state";N;}';
  $export['panelizer_node:senator_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:senator_allowed_layouts_default';
  $strongarm->value = 0;
  $export['panelizer_node:senator_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:senator_allowed_types';
  $strongarm->value = array(
    'block-nys_blocks-earthday_form' => TRUE,
    'block-nys_blocks-earthday_results' => TRUE,
    'block-nys_blocks-tday_form' => TRUE,
    'block-nys_blocks-tday_results' => TRUE,
    'block-nys_blocks-youth_leadership_form' => TRUE,
    'block-nys_blocks-summer_reading' => TRUE,
    'block-nys_blocks-veterans' => TRUE,
    'block-nys_blocks-women' => TRUE,
    'block-nys_blocks-lyme_prevention' => TRUE,
    'block-nys_blocks-coronavirus_response' => TRUE,
    'block-nys_blocks-pathways_funding' => TRUE,
    'block-nys_blocks-unclaimed_funds' => TRUE,
    'block-nys_utils-news_by_top_issue_output_block' => TRUE,
    'fieldable_panels_pane-fieldable_panels_pane' => TRUE,
    'fieldable_panels_pane-promotional_banner' => TRUE,
    'fieldable_panels_pane-promotional_banner_2up' => TRUE,
    'fieldable_panels_pane-women_of_distinction' => TRUE,
    'views_panes-senator_news-panel_pane_1' => TRUE,
    'views_panes-senator_news-panel_pane_2' => TRUE,
    'views_panes-senator_events-home_events_pane' => TRUE,
    'views_panes-senator_polls-panel_pane_1' => TRUE,
    'views_panes-senator_legislation-featured_legis_pane' => TRUE,
    'views_panes-senator_legislation-featured_legis_list_pane' => TRUE,
  );
  $export['panelizer_node:senator_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:senator_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:senator_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:senator_default';
  $strongarm->value = array(
    'block' => 0,
    'custom' => 0,
    'entity_field' => 0,
    'entity_field_extra' => 0,
    'entity_form_field' => 0,
    'token' => 0,
    'entity_view' => 0,
    'fieldable_panels_pane' => 0,
    'flag_link' => 0,
    'views_panes' => 0,
    'views' => 0,
    'other' => 0,
  );
  $export['panelizer_node:senator_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_chapter_pattern';
  $strongarm->value = '';
  $export['pathauto_node_chapter_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_senator_pattern';
  $strongarm->value = 'senators/[node:title]';
  $export['pathauto_node_senator_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_senator';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.7',
  );
  $export['xmlsitemap_settings_node_senator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_issues';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_issues'] = $strongarm;

  return $export;
}
