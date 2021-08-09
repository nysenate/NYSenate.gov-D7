<?php

/**
 * @file
 * nys_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nys_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_autocomplete_counts';
  $strongarm->value = 1;
  $export['apachesolr_autocomplete_counts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_autocomplete_suggest_keywords';
  $strongarm->value = 1;
  $export['apachesolr_autocomplete_suggest_keywords'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_autocomplete_suggest_spellcheck';
  $strongarm->value = 1;
  $export['apachesolr_autocomplete_suggest_spellcheck'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_autocomplete_widget';
  $strongarm->value = 'custom';
  $export['apachesolr_autocomplete_widget'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_cron_limit';
  $strongarm->value = '200';
  $export['apachesolr_cron_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_default_environment';
  $strongarm->value = 'solr';
  $export['apachesolr_default_environment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_failure';
  $strongarm->value = 'apachesolr:show_error';
  $export['apachesolr_failure'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_default_search_page';
  $strongarm->value = 'core_search';
  $export['apachesolr_search_default_search_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_mlt_blocks';
  $strongarm->value = array(
    'mlt-001' => array(
      'name' => 'More like this',
      'num_results' => '5',
      'mlt_fl' => array(
        'label' => 'label',
        'taxonomy_names' => 'taxonomy_names',
      ),
      'mlt_env_id' => 'solr',
      'mlt_mintf' => '1',
      'mlt_mindf' => '1',
      'mlt_minwl' => '3',
      'mlt_maxwl' => '15',
      'mlt_maxqt' => '20',
      'mlt_type_filters' => array(),
      'mlt_custom_filters' => '',
      'delta' => 'mlt-001',
    ),
    'mlt-002' => array(
      'name' => 'Related News',
      'mlt_env_id' => 'solr',
      'num_results' => '5',
      'mlt_fl' => array(
        'tm_vid_4_names' => 'tm_vid_4_names',
      ),
      'mlt_mintf' => '1',
      'mlt_mindf' => '1',
      'mlt_minwl' => '3',
      'mlt_maxwl' => '15',
      'mlt_maxqt' => '20',
      'mlt_type_filters' => array(
        'article' => 'article',
        'in_the_news' => 'in_the_news',
        'press_release' => 'press_release',
      ),
      'mlt_custom_filters' => '',
      'delta' => 'mlt-002',
    ),
  );
  $export['apachesolr_search_mlt_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_set_nodeapi_messages';
  $strongarm->value = '1';
  $export['apachesolr_set_nodeapi_messages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_site_hash';
  $strongarm->value = 'gwrgtg';
  $export['apachesolr_site_hash'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_apachesolr_current_filters_default';
  $strongarm->value = 0;
  $export['ds_search_apachesolr_current_filters_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_apachesolr_hide_current_filters';
  $strongarm->value = 0;
  $export['ds_search_apachesolr_hide_current_filters'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_apachesolr_multisite';
  $strongarm->value = 0;
  $export['ds_search_apachesolr_multisite'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_apachesolr_multisite_boost';
  $strongarm->value = 0;
  $export['ds_search_apachesolr_multisite_boost'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_apachesolr_multisite_group';
  $strongarm->value = 0;
  $export['ds_search_apachesolr_multisite_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_apachesolr_multisite_group_config';
  $strongarm->value = '';
  $export['ds_search_apachesolr_multisite_group_config'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_file_render';
  $strongarm->value = 1;
  $export['ds_search_file_render'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_group_by_type';
  $strongarm->value = 0;
  $export['ds_search_group_by_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_group_by_type_other';
  $strongarm->value = 'Other';
  $export['ds_search_group_by_type_other'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_group_by_type_other_wrapper';
  $strongarm->value = 'fieldset';
  $export['ds_search_group_by_type_other_wrapper'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_group_by_type_settings';
  $strongarm->value = array(
    'agenda' => array(
      'status' => 1,
      'label' => 'Results for agenda',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'article' => array(
      'status' => 1,
      'label' => 'Results for article',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'bill' => array(
      'status' => 1,
      'label' => 'Results for bill',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'calendar' => array(
      'status' => 1,
      'label' => 'Results for calendar',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'chapter' => array(
      'status' => 1,
      'label' => 'Results for chapter',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'event' => array(
      'status' => 1,
      'label' => 'Results for event',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'in_the_news' => array(
      'status' => 1,
      'label' => 'Results for in the news',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'initiative' => array(
      'status' => 1,
      'label' => 'Results for initiative',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'meeting' => array(
      'status' => 1,
      'label' => 'Results for meeting',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'open_data' => array(
      'status' => 1,
      'label' => 'Results for open data',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'page_content' => array(
      'status' => 1,
      'label' => 'Results for page',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'petition' => array(
      'status' => 1,
      'label' => 'Results for petition',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'photo' => array(
      'status' => 1,
      'label' => 'Results for photo',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'press_release' => array(
      'status' => 1,
      'label' => 'Results for press release',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'promotional_banner' => array(
      'status' => 1,
      'label' => 'Results for promotional banner',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'public_hearing' => array(
      'status' => 1,
      'label' => 'Results for public hearing',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'questionnaire' => array(
      'status' => 1,
      'label' => 'Results for questionnaire',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'resolution' => array(
      'status' => 1,
      'label' => 'Results for resolution',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'senator' => array(
      'status' => 1,
      'label' => 'Results for senator',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'session' => array(
      'status' => 1,
      'label' => 'Results for session',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'student_program' => array(
      'status' => 1,
      'label' => 'Results for student program',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'timeline_item' => array(
      'status' => 1,
      'label' => 'Results for timeline item',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'transcript' => array(
      'status' => 1,
      'label' => 'Results for transcript',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'video' => array(
      'status' => 1,
      'label' => 'Results for video',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
    'webform' => array(
      'status' => 1,
      'label' => 'Results for webform',
      'wrapper' => 'fieldset',
      'weight' => '0',
    ),
  );
  $export['ds_search_group_by_type_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_highlight';
  $strongarm->value = 1;
  $export['ds_search_highlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_highlight_selector';
  $strongarm->value = '.view-mode-search_result';
  $export['ds_search_highlight_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_language';
  $strongarm->value = 0;
  $export['ds_search_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_node_form_alter';
  $strongarm->value = 0;
  $export['ds_search_node_form_alter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_node_limit';
  $strongarm->value = '10';
  $export['ds_search_node_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_path';
  $strongarm->value = 'global';
  $export['ds_search_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_show_title';
  $strongarm->value = 1;
  $export['ds_search_show_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_type';
  $strongarm->value = 'apachesolr_search';
  $export['ds_search_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_variables';
  $strongarm->value = 'search_totals_plus_keywords';
  $export['ds_search_variables'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_search_view_mode';
  $strongarm->value = 'search_index';
  $export['ds_search_view_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:apachesolr@solr';
  $strongarm->value = '-1';
  $export['facetapi:block_cache:apachesolr@solr'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_active_modules';
  $strongarm->value = array(
    'apachesolr_search' => 'apachesolr_search',
    'ds_search' => 'ds_search',
    'file_entity' => 0,
    'node' => 0,
    'user' => 0,
  );
  $export['search_active_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_cron_limit';
  $strongarm->value = '500';
  $export['search_cron_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_default_module';
  $strongarm->value = 'apachesolr_search';
  $export['search_default_module'] = $strongarm;

  return $export;
}
