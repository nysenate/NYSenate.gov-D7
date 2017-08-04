<?php
/**
 * @file
 * nys_student_submissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_student_submissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer entityform types'.
  $permissions['administer entityform types'] = array(
    'name' => 'administer entityform types',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'create field_school_featured_entry'.
  $permissions['create field_school_featured_entry'] = array(
    'name' => 'create field_school_featured_entry',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'delete any entityform'.
  $permissions['delete any entityform'] = array(
    'name' => 'delete any entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'delete own entityform'.
  $permissions['delete own entityform'] = array(
    'name' => 'delete own entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit any entityform'.
  $permissions['edit any entityform'] = array(
    'name' => 'edit any entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit field_school_featured_entry'.
  $permissions['edit field_school_featured_entry'] = array(
    'name' => 'edit field_school_featured_entry',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own entityform'.
  $permissions['edit own entityform'] = array(
    'name' => 'edit own entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit own field_school_featured_entry'.
  $permissions['edit own field_school_featured_entry'] = array(
    'name' => 'edit own field_school_featured_entry',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view any entityform'.
  $permissions['view any entityform'] = array(
    'name' => 'view any entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view field_school_featured_entry'.
  $permissions['view field_school_featured_entry'] = array(
    'name' => 'view field_school_featured_entry',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own entityform'.
  $permissions['view own entityform'] = array(
    'name' => 'view own entityform',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view own field_school_featured_entry'.
  $permissions['view own field_school_featured_entry'] = array(
    'name' => 'view own field_school_featured_entry',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
