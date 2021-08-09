<?php
/**
 * @file
 * nys_paragraphs.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_paragraphs_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_pg_full_width_bleed'.
  $permissions['create field_pg_full_width_bleed'] = array(
    'name' => 'create field_pg_full_width_bleed',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pg_full_width_bleed'.
  $permissions['edit field_pg_full_width_bleed'] = array(
    'name' => 'edit field_pg_full_width_bleed',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pg_full_width_bleed'.
  $permissions['edit own field_pg_full_width_bleed'] = array(
    'name' => 'edit own field_pg_full_width_bleed',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pg_full_width_bleed'.
  $permissions['view field_pg_full_width_bleed'] = array(
    'name' => 'view field_pg_full_width_bleed',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pg_full_width_bleed'.
  $permissions['view own field_pg_full_width_bleed'] = array(
    'name' => 'view own field_pg_full_width_bleed',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
