<?php
/**
 * @file
 * nys_districts.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_districts_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_district_description|taxonomy_term|districts|form';
  $field_group->group_name = 'group_district_description';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'districts';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'District Description',
    'weight' => '4',
    'children' => array(
      0 => 'field_chapters',
      1 => 'field_subheading',
      2 => 'description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-district-description field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_district_description|taxonomy_term|districts|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('District Description');

  return $field_groups;
}
