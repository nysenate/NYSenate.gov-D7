<?php

/**
 * @file
 * Views 3 support for Location contact_name.
 */

/**
 * Implements hook_views_data().
 */
function location_contact_name_views_data() {
  // location_contact_name table -- basic table information.
  // Define the base group of this table.
  // Fields that don' have a group defined will go into this field by default.
  $data['location_contact_name']['table']['group'] = t('Location', array(), array('context' => 'geolocation'));

  // Join location_contact_name to all the tables that would be useful.
  $data['location_contact_name']['table']['join'] = array(
    // location_contact_name links to location via lid.
    'location' => array(
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_contact_name links to node through location_instance via lid.
    'node' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_contact_name links to node_revision through location_instance
    // via lid.
    'node_revision' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_contact_name links to users through location_instance via lid.
    'users' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
  );

  // location_contact_name table -- fields.
  $data['location_contact_name']['contact_name'] = array(
    'title' => t('contact_name'),
    'help' => t('The Contact Name of the selected location.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'empty field name' => t('None'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
  );

  return $data;
}
