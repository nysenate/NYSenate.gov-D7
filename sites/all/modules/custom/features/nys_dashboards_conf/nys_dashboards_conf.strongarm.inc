<?php
/**
 * @file
 * nys_dashboards_conf.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nys_dashboards_conf_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_default_redirect';
  $strongarm->value = '<new-message>';
  $export['privatemsg_default_redirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_default_redirect_reply';
  $strongarm->value = 0;
  $export['privatemsg_default_redirect_reply'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_disabled_message';
  $strongarm->value = 1;
  $export['privatemsg_display_disabled_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_fields';
  $strongarm->value = array(
    'subject' => TRUE,
    'participants' => 'participants',
    'thread_started' => 0,
    'tags' => 'tags',
    'count' => 'count',
    'last_updated' => TRUE,
  );
  $export['privatemsg_display_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_fields_weights';
  $strongarm->value = array(
    'subject' => '-20',
    'participants' => '-19',
    'thread_started' => '-18',
    'tags' => '-17',
    'count' => '-16',
    'last_updated' => '-15',
  );
  $export['privatemsg_display_fields_weights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_link_self';
  $strongarm->value = 1;
  $export['privatemsg_display_link_self'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_loginmessage';
  $strongarm->value = 0;
  $export['privatemsg_display_loginmessage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_on_comments';
  $strongarm->value = 0;
  $export['privatemsg_display_on_comments'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_on_teaser';
  $strongarm->value = 1;
  $export['privatemsg_display_on_teaser'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_preview_button';
  $strongarm->value = 0;
  $export['privatemsg_display_preview_button'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_display_profile_links';
  $strongarm->value = 1;
  $export['privatemsg_display_profile_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_filter_default_list';
  $strongarm->value = '0';
  $export['privatemsg_filter_default_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_filter_inbox_tag';
  $strongarm->value = '1';
  $export['privatemsg_filter_inbox_tag'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_filter_searchbody';
  $strongarm->value = 0;
  $export['privatemsg_filter_searchbody'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_flush_days';
  $strongarm->value = '100';
  $export['privatemsg_flush_days'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_flush_enabled';
  $strongarm->value = 1;
  $export['privatemsg_flush_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_flush_max';
  $strongarm->value = '200';
  $export['privatemsg_flush_max'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_link_node_types';
  $strongarm->value = array(
    'article' => 'article',
    'in_the_news' => 'in_the_news',
    'petition' => 'petition',
    'press_release' => 'press_release',
    'senator' => 'senator',
    'agenda' => 0,
    'bill' => 0,
    'calendar' => 0,
    'chapter' => 0,
    'event' => 0,
    'initiative' => 0,
    'meeting' => 0,
    'open_data' => 0,
    'page_content' => 0,
    'photo' => 0,
    'promotional_banner' => 0,
    'questionnaire' => 0,
    'session' => 0,
    'bill_status_message' => 0,
    'timeline_item' => 0,
    'video' => 0,
    'webform' => 0,
  );
  $export['privatemsg_link_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_per_page';
  $strongarm->value = '25';
  $export['privatemsg_per_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_view_default_amount';
  $strongarm->value = '10';
  $export['privatemsg_view_default_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_view_max_amount';
  $strongarm->value = '20';
  $export['privatemsg_view_max_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'privatemsg_view_use_max_as_default';
  $strongarm->value = 0;
  $export['privatemsg_view_use_max_as_default'] = $strongarm;

  return $export;
}
