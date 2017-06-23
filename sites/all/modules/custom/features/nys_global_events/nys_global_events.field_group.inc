<?php
/**
 * @file
 * nys_global_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_global_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_members|taxonomy_term|committees|form';
  $field_group->group_name = 'group_members';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'committees';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Members',
    'weight' => '9',
    'children' => array(
      0 => 'field_members',
      1 => 'field_group_members',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_members|taxonomy_term|committees|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Members');

  return $field_groups;
}
