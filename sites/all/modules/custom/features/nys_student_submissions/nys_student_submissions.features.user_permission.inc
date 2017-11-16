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

  // Exported permission: 'create field_hannon_star_rating'.
  $permissions['create field_hannon_star_rating'] = array(
    'name' => 'create field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_hannon_winner_types'.
  $permissions['create field_hannon_winner_types'] = array(
    'name' => 'create field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'create field_school_show_student'.
  $permissions['create field_school_show_student'] = array(
    'name' => 'create field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hannon_star_rating'.
  $permissions['edit field_hannon_star_rating'] = array(
    'name' => 'edit field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hannon_winner_types'.
  $permissions['edit field_hannon_winner_types'] = array(
    'name' => 'edit field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'edit field_school_show_student'.
  $permissions['edit field_school_show_student'] = array(
    'name' => 'edit field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hannon_star_rating'.
  $permissions['edit own field_hannon_star_rating'] = array(
    'name' => 'edit own field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hannon_winner_types'.
  $permissions['edit own field_hannon_winner_types'] = array(
    'name' => 'edit own field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'edit own field_school_show_student'.
  $permissions['edit own field_school_show_student'] = array(
    'name' => 'edit own field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hannon_star_rating'.
  $permissions['view field_hannon_star_rating'] = array(
    'name' => 'view field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hannon_winner_types'.
  $permissions['view field_hannon_winner_types'] = array(
    'name' => 'view field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'view field_school_show_student'.
  $permissions['view field_school_show_student'] = array(
    'name' => 'view field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hannon_star_rating'.
  $permissions['view own field_hannon_star_rating'] = array(
    'name' => 'view own field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hannon_winner_types'.
  $permissions['view own field_hannon_winner_types'] = array(
    'name' => 'view own field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'view own field_school_show_student'.
  $permissions['view own field_school_show_student'] = array(
    'name' => 'view own field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Student Contest Judge' => 'Student Contest Judge',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
