<?php

/**
 * @file
 * Hooks for integrating Views and Login History.
 */

/**
 * Implements hook_views_data().
 */
function login_history_views_data() {
  $data['login_history']['table']['group'] = t('Login History');
  // Allow users to create views showing user login records.
  $data['login_history']['table']['base'] = array(
    'field' => 'uid',
    'title' => t('User login records'),
    'help' => t('User login records stored by the Login History module.'),
  );

  // Describe join with users table.
  $data['login_history']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // Relationship with users table.
  $data['login_history']['uid'] = array(
    'title' => t('User'),
    'help' => t('The user that logged in.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('User from Login History'),
    ),
  );

  // Login timestamp field.
  $data['login_history']['login'] = array(
    'title' => t('Date'),
    'help' => t('The date of the user login.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Hostname field.
  $data['login_history']['hostname'] = array(
    'title' => t('IP Address'),
    'help' => t('IP address of the user login.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // One time login field.
  $data['login_history']['one_time'] = array(
    'title' => t('One-time login?'),
    'help' => t('Whether the login was through a one-time login link or not.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('One-time login'),
    ),
  );

  // User agent field.
  $data['login_history']['user_agent'] = array(
    'title' => t('User Agent'),
    'help' => t('User agent of the user login.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  return $data;
}
