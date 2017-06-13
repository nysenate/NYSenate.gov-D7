<?php
/**
 * @file
 * nys_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_committee_settings|node|event|form';
  $field_group->group_name = 'group_committee_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'Committee Settings',
    'weight' => '24',
    'children' => array(
      0 => 'field_committee_featured',
      1 => 'field_committee',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-committee-settings field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discoverability|node|event|form';
  $field_group->group_name = 'group_discoverability';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dicoverability',
    'weight' => '5',
    'children' => array(
      0 => 'field_issues',
      1 => 'group_promotion',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-discoverability field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_content|node|event|form';
  $field_group->group_name = 'group_event_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_image_main',
      2 => 'field_location',
      3 => 'field_event_place',
      4 => 'field_feature_image',
      5 => 'field_attachment',
      6 => 'locations',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_microsite_settings|node|event|form';
  $field_group->group_name = 'group_microsite_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'Senator Microsite Settings',
    'weight' => '22',
    'children' => array(
      0 => 'field_featured',
      1 => 'field_senator',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-microsite-settings field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promotion|node|event|form';
  $field_group->group_name = 'group_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_discoverability';
  $field_group->data = array(
    'label' => 'Promotion and Visibility',
    'weight' => '11',
    'children' => array(
      0 => 'group_microsite_settings',
      1 => 'group_committee_settings',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-promotion field-group-htabs',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_settings|node|event|form';
  $field_group->group_name = 'group_video_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Video Settings',
    'weight' => '3',
    'children' => array(
      0 => 'field_yt',
      1 => 'field_ustream_url',
      2 => 'field_video_status',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video-settings field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Committee Settings');
  t('Content');
  t('Dicoverability');
  t('Event Video Settings');
  t('Promotion and Visibility');
  t('Senator Microsite Settings');

  return $field_groups;
}
