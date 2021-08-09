<?php

/**
 * @file
 * nys_sitewide_elements.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_sitewide_elements_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|node|initiative|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_add_honoree_list',
      1 => 'field_profile_status',
      2 => 'group_event_details',
    ),
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'classes' => 'group-admin field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Administrative Fields',
    ),
    'format_type' => 'fieldset',
    'label' => 'Administrative Fields',
    'weight' => '9',
  );
  $field_groups['group_admin|node|initiative|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_delete|node|initiative|form';
  $field_group->group_name = 'group_delete';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_webform',
      1 => 'field_associated_senator',
      2 => 'field_hide_webform',
      3 => 'field_honoree_section_title',
      4 => 'field_honorees',
      5 => 'field_accessible_sitewide',
      6 => 'group_honoree_details',
    ),
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'classes' => 'group-delete field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Unused Fields',
    ),
    'format_type' => 'fieldset',
    'label' => 'Unused Fields',
    'weight' => '15',
  );
  $field_groups['group_delete|node|initiative|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dep_fields|node|page_content|form';
  $field_group->group_name = 'group_dep_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_chapters',
      1 => 'field_image_main',
      2 => 'field_date',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-dep-fields field-group-tab',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'Fields not in use',
    ),
    'format_type' => 'tab',
    'label' => 'Fields not in use',
    'weight' => '11',
  );
  $field_groups['group_dep_fields|node|page_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_details|node|initiative|form';
  $field_group->group_name = 'group_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_admin';
  $field_group->data = array(
    'children' => array(
      0 => 'field_profile_attending',
      1 => 'field_profile_guests',
      2 => 'field_profile_handicap',
      3 => 'field_profile_parking',
    ),
    'format_settings' => array(
      'formatter' => 'collapsed',
      'instance_settings' => array(
        'classes' => 'group-event-details field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Honoree Ceremony Details',
    ),
    'format_type' => 'fieldset',
    'label' => 'Honoree Ceremony Details',
    'weight' => '18',
  );
  $field_groups['group_event_details|node|initiative|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_honoree_details|node|initiative|form';
  $field_group->group_name = 'group_honoree_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_delete';
  $field_group->data = array(
    'children' => array(
      0 => 'field_profile_bio',
      1 => 'field_profile_bio_pdf',
      2 => 'field_profile_headshot',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-honoree-details field-group-fieldset',
        'description' => 'Please submit the following information about your Honoree for Senate Services to use for the ceremony and public website.',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Submit your Honoree',
    ),
    'format_type' => 'fieldset',
    'label' => 'Submit your Honoree',
    'weight' => '15',
  );
  $field_groups['group_honoree_details|node|initiative|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_public_website|node|initiative|form';
  $field_group->group_name = 'group_public_website';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'body',
      1 => 'field_attachment',
      2 => 'field_image_main',
      3 => 'field_subheading',
      4 => 'field_honoree_name',
      5 => 'field_pg_video',
      6 => 'field_profile_military_branch',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-public-website field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Final Honoree Information for Publication',
    ),
    'format_type' => 'fieldset',
    'label' => 'Final Honoree Information for Publication',
    'weight' => '5',
  );
  $field_groups['group_public_website|node|initiative|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administrative Fields');
  t('Fields not in use');
  t('Final Honoree Information for Publication');
  t('Honoree Ceremony Details');
  t('Submit your Honoree');
  t('Unused Fields');

  return $field_groups;
}
