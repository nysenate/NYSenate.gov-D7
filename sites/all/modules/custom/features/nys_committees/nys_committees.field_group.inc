<?php

/**
 * @file
 * nys_committees.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_committees_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comm_featured_legislation|taxonomy_term|committees|form';
  $field_group->group_name = 'group_comm_featured_legislation';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'committees';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured Legislation',
    'weight' => '8',
    'children' => array(
      0 => 'field_featured_legislation_commi',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Featured Legislation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-comm-featured-legislation field-group-fieldset',
        'description' => 'Committee chairs can feature any member\'s legislation on the committee page if it is important to the committee chair. The chair can attribute the quote to himself or herself, or to any member of the committee.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_comm_featured_legislation|taxonomy_term|committees|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|taxonomy_term|committees|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'committees';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Committee Mission',
    'weight' => '6',
    'children' => array(
      0 => 'field_learn_more_page',
      1 => 'description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Committee Mission',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-description field-group-fieldset',
        'description' => 'A short overviews describing the mission of the committee. Descriptions longer than 180 characters are truncated with an ellipsis. If you\'d like to create a longer document about the committee\'s mission, create an <a href=/node/add/article>article</a>, associate it with the committee under "Discoverability > Committee Settings", and use the "Learn More Page" field below to link to that article.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_description|taxonomy_term|committees|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Committee Mission');
  t('Featured Legislation');

  return $field_groups;
}
