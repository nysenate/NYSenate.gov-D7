<?php
/**
 * @file
 * nys_dashboards_conf.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nys_dashboards_conf_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'privatemsg_message-privatemsg_message-field_featured_bill'.
  $field_instances['privatemsg_message-privatemsg_message-field_featured_bill'] = array(
    'bundle' => 'privatemsg_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'privatemsg_message',
    'field_name' => 'field_featured_bill',
    'label' => 'Featured Bill',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'STARTS_WITH',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'privatemsg_message-privatemsg_message-field_issues'.
  $field_instances['privatemsg_message-privatemsg_message-field_issues'] = array(
    'bundle' => 'privatemsg_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'privatemsg_message',
    'field_name' => 'field_issues',
    'label' => 'Issues',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Featured Bill');
  t('Issues');

  return $field_instances;
}
