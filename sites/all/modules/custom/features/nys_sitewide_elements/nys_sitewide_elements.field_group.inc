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
  $field_group->identifier = 'group_dep_fields|node|page_content|form';
  $field_group->group_name = 'group_dep_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Fields not in use',
    'weight' => '11',
    'children' => array(
      0 => 'field_chapters',
      1 => 'field_image_main',
      2 => 'field_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Fields not in use',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-dep-fields field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_dep_fields|node|page_content|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Fields not in use');

  return $field_groups;
}
