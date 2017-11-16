<?php
/**
 * @file
 * nys_districts.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_districts_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_district_number'.
  $permissions['create field_district_number'] = array(
    'name' => 'create field_district_number',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_map_url'.
  $permissions['create field_map_url'] = array(
    'name' => 'create field_map_url',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_district_number'.
  $permissions['edit field_district_number'] = array(
    'name' => 'edit field_district_number',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_map_url'.
  $permissions['edit field_map_url'] = array(
    'name' => 'edit field_map_url',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_district_number'.
  $permissions['edit own field_district_number'] = array(
    'name' => 'edit own field_district_number',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_map_url'.
  $permissions['edit own field_map_url'] = array(
    'name' => 'edit own field_map_url',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_district_number'.
  $permissions['view field_district_number'] = array(
    'name' => 'view field_district_number',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_map_url'.
  $permissions['view field_map_url'] = array(
    'name' => 'view field_map_url',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_district_number'.
  $permissions['view own field_district_number'] = array(
    'name' => 'view own field_district_number',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_map_url'.
  $permissions['view own field_map_url'] = array(
    'name' => 'view own field_map_url',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
