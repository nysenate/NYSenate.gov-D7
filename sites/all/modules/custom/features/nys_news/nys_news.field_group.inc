<?php
/**
 * @file
 * nys_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_news_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_committee_settings|node|press_release|form';
  $field_group->group_name = 'group_committee_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_discoverability';
  $field_group->data = array(
    'label' => 'Committee Settings',
    'weight' => '11',
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
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discoverability|node|press_release|form';
  $field_group->group_name = 'group_discoverability';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discoverability',
    'weight' => '5',
    'children' => array(
      0 => 'field_issues',
      1 => 'group_microsite_settings',
      2 => 'group_sitewide_settings',
      3 => 'group_committee_settings',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-discoverability field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_heading_info|node|press_release|form';
  $field_group->group_name = 'group_heading_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Heading Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_image_main',
      1 => 'field_date',
      2 => 'field_article_author',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-heading-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_microsite_settings|node|press_release|form';
  $field_group->group_name = 'group_microsite_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_discoverability';
  $field_group->data = array(
    'label' => 'Senator Microsite Settings',
    'weight' => '8',
    'children' => array(
      0 => 'field_senator',
      1 => 'field_featured',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-microsite-settings field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sitewide_settings|node|press_release|form';
  $field_group->group_name = 'group_sitewide_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_discoverability';
  $field_group->data = array(
    'label' => 'Sitewide Settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_accessible_sitewide',
      1 => 'field_associated_senator',
      2 => 'field_image_hero',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sitewide-settings field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Committee Settings');
  t('Discoverability');
  t('Heading Info');
  t('Senator Microsite Settings');
  t('Sitewide Settings');

  return $field_groups;
}
