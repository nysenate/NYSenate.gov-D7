<?php
/**
 * @file
 * nys_polls.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_polls_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create advpoll_cookie_duration'.
  $permissions['create advpoll_cookie_duration'] = array(
    'name' => 'create advpoll_cookie_duration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_advpoll_featured'.
  $permissions['create field_advpoll_featured'] = array(
    'name' => 'create field_advpoll_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit advpoll_cookie_duration'.
  $permissions['edit advpoll_cookie_duration'] = array(
    'name' => 'edit advpoll_cookie_duration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_advpoll_featured'.
  $permissions['edit field_advpoll_featured'] = array(
    'name' => 'edit field_advpoll_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own advpoll_cookie_duration'.
  $permissions['edit own advpoll_cookie_duration'] = array(
    'name' => 'edit own advpoll_cookie_duration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_advpoll_featured'.
  $permissions['edit own field_advpoll_featured'] = array(
    'name' => 'edit own field_advpoll_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view advpoll_cookie_duration'.
  $permissions['view advpoll_cookie_duration'] = array(
    'name' => 'view advpoll_cookie_duration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_advpoll_featured'.
  $permissions['view field_advpoll_featured'] = array(
    'name' => 'view field_advpoll_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own advpoll_cookie_duration'.
  $permissions['view own advpoll_cookie_duration'] = array(
    'name' => 'view own advpoll_cookie_duration',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_advpoll_featured'.
  $permissions['view own field_advpoll_featured'] = array(
    'name' => 'view own field_advpoll_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
