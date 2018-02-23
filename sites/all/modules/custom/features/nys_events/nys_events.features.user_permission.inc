<?php
/**
 * @file
 * nys_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_accessible_sitewide'.
  $permissions['create field_accessible_sitewide'] = array(
    'name' => 'create field_accessible_sitewide',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_featured'.
  $permissions['create field_featured'] = array(
    'name' => 'create field_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_accessible_sitewide'.
  $permissions['edit field_accessible_sitewide'] = array(
    'name' => 'edit field_accessible_sitewide',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_featured'.
  $permissions['edit field_featured'] = array(
    'name' => 'edit field_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_accessible_sitewide'.
  $permissions['edit own field_accessible_sitewide'] = array(
    'name' => 'edit own field_accessible_sitewide',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_featured'.
  $permissions['edit own field_featured'] = array(
    'name' => 'edit own field_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_accessible_sitewide'.
  $permissions['view field_accessible_sitewide'] = array(
    'name' => 'view field_accessible_sitewide',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_featured'.
  $permissions['view field_featured'] = array(
    'name' => 'view field_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_accessible_sitewide'.
  $permissions['view own field_accessible_sitewide'] = array(
    'name' => 'view own field_accessible_sitewide',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_featured'.
  $permissions['view own field_featured'] = array(
    'name' => 'view own field_featured',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Student Programs' => 'Student Programs',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
