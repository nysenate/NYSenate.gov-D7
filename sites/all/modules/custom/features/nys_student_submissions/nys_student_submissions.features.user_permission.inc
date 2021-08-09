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

  // Exported permission: 'create field_hannon_district_status'.
  $permissions['create field_hannon_district_status'] = array(
    'name' => 'create field_hannon_district_status',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_hannon_star_rating'.
  $permissions['create field_hannon_star_rating'] = array(
    'name' => 'create field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_hannon_winner_types'.
  $permissions['create field_hannon_winner_types'] = array(
    'name' => 'create field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_approval_status'.
  $permissions['create field_pbudg_approval_status'] = array(
    'name' => 'create field_pbudg_approval_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_category'.
  $permissions['create field_pbudg_category'] = array(
    'name' => 'create field_pbudg_category',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_guestimate'.
  $permissions['create field_pbudg_guestimate'] = array(
    'name' => 'create field_pbudg_guestimate',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_neighborhood'.
  $permissions['create field_pbudg_neighborhood'] = array(
    'name' => 'create field_pbudg_neighborhood',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_project_description'.
  $permissions['create field_pbudg_project_description'] = array(
    'name' => 'create field_pbudg_project_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_project_location'.
  $permissions['create field_pbudg_project_location'] = array(
    'name' => 'create field_pbudg_project_location',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_project_name'.
  $permissions['create field_pbudg_project_name'] = array(
    'name' => 'create field_pbudg_project_name',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pbudg_submit_project'.
  $permissions['create field_pbudg_submit_project'] = array(
    'name' => 'create field_pbudg_submit_project',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_school_show_student'.
  $permissions['create field_school_show_student'] = array(
    'name' => 'create field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_year'.
  $permissions['create field_year'] = array(
    'name' => 'create field_year',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hannon_district_status'.
  $permissions['edit field_hannon_district_status'] = array(
    'name' => 'edit field_hannon_district_status',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hannon_star_rating'.
  $permissions['edit field_hannon_star_rating'] = array(
    'name' => 'edit field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hannon_winner_types'.
  $permissions['edit field_hannon_winner_types'] = array(
    'name' => 'edit field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_approval_status'.
  $permissions['edit field_pbudg_approval_status'] = array(
    'name' => 'edit field_pbudg_approval_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_category'.
  $permissions['edit field_pbudg_category'] = array(
    'name' => 'edit field_pbudg_category',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_guestimate'.
  $permissions['edit field_pbudg_guestimate'] = array(
    'name' => 'edit field_pbudg_guestimate',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_neighborhood'.
  $permissions['edit field_pbudg_neighborhood'] = array(
    'name' => 'edit field_pbudg_neighborhood',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_project_description'.
  $permissions['edit field_pbudg_project_description'] = array(
    'name' => 'edit field_pbudg_project_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_project_location'.
  $permissions['edit field_pbudg_project_location'] = array(
    'name' => 'edit field_pbudg_project_location',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_project_name'.
  $permissions['edit field_pbudg_project_name'] = array(
    'name' => 'edit field_pbudg_project_name',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pbudg_submit_project'.
  $permissions['edit field_pbudg_submit_project'] = array(
    'name' => 'edit field_pbudg_submit_project',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_school_show_student'.
  $permissions['edit field_school_show_student'] = array(
    'name' => 'edit field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_year'.
  $permissions['edit field_year'] = array(
    'name' => 'edit field_year',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hannon_district_status'.
  $permissions['edit own field_hannon_district_status'] = array(
    'name' => 'edit own field_hannon_district_status',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hannon_star_rating'.
  $permissions['edit own field_hannon_star_rating'] = array(
    'name' => 'edit own field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hannon_winner_types'.
  $permissions['edit own field_hannon_winner_types'] = array(
    'name' => 'edit own field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_approval_status'.
  $permissions['edit own field_pbudg_approval_status'] = array(
    'name' => 'edit own field_pbudg_approval_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_category'.
  $permissions['edit own field_pbudg_category'] = array(
    'name' => 'edit own field_pbudg_category',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_guestimate'.
  $permissions['edit own field_pbudg_guestimate'] = array(
    'name' => 'edit own field_pbudg_guestimate',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_neighborhood'.
  $permissions['edit own field_pbudg_neighborhood'] = array(
    'name' => 'edit own field_pbudg_neighborhood',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_project_description'.
  $permissions['edit own field_pbudg_project_description'] = array(
    'name' => 'edit own field_pbudg_project_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_project_location'.
  $permissions['edit own field_pbudg_project_location'] = array(
    'name' => 'edit own field_pbudg_project_location',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_project_name'.
  $permissions['edit own field_pbudg_project_name'] = array(
    'name' => 'edit own field_pbudg_project_name',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pbudg_submit_project'.
  $permissions['edit own field_pbudg_submit_project'] = array(
    'name' => 'edit own field_pbudg_submit_project',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_school_show_student'.
  $permissions['edit own field_school_show_student'] = array(
    'name' => 'edit own field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_year'.
  $permissions['edit own field_year'] = array(
    'name' => 'edit own field_year',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hannon_district_status'.
  $permissions['view field_hannon_district_status'] = array(
    'name' => 'view field_hannon_district_status',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hannon_star_rating'.
  $permissions['view field_hannon_star_rating'] = array(
    'name' => 'view field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hannon_winner_types'.
  $permissions['view field_hannon_winner_types'] = array(
    'name' => 'view field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_approval_status'.
  $permissions['view field_pbudg_approval_status'] = array(
    'name' => 'view field_pbudg_approval_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_category'.
  $permissions['view field_pbudg_category'] = array(
    'name' => 'view field_pbudg_category',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_guestimate'.
  $permissions['view field_pbudg_guestimate'] = array(
    'name' => 'view field_pbudg_guestimate',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_neighborhood'.
  $permissions['view field_pbudg_neighborhood'] = array(
    'name' => 'view field_pbudg_neighborhood',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_project_description'.
  $permissions['view field_pbudg_project_description'] = array(
    'name' => 'view field_pbudg_project_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_project_location'.
  $permissions['view field_pbudg_project_location'] = array(
    'name' => 'view field_pbudg_project_location',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_project_name'.
  $permissions['view field_pbudg_project_name'] = array(
    'name' => 'view field_pbudg_project_name',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pbudg_submit_project'.
  $permissions['view field_pbudg_submit_project'] = array(
    'name' => 'view field_pbudg_submit_project',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_school_show_student'.
  $permissions['view field_school_show_student'] = array(
    'name' => 'view field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_year'.
  $permissions['view field_year'] = array(
    'name' => 'view field_year',
    'roles' => array(
      'Administrator' => 'Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hannon_district_status'.
  $permissions['view own field_hannon_district_status'] = array(
    'name' => 'view own field_hannon_district_status',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hannon_star_rating'.
  $permissions['view own field_hannon_star_rating'] = array(
    'name' => 'view own field_hannon_star_rating',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hannon_winner_types'.
  $permissions['view own field_hannon_winner_types'] = array(
    'name' => 'view own field_hannon_winner_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_approval_status'.
  $permissions['view own field_pbudg_approval_status'] = array(
    'name' => 'view own field_pbudg_approval_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_category'.
  $permissions['view own field_pbudg_category'] = array(
    'name' => 'view own field_pbudg_category',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_guestimate'.
  $permissions['view own field_pbudg_guestimate'] = array(
    'name' => 'view own field_pbudg_guestimate',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_neighborhood'.
  $permissions['view own field_pbudg_neighborhood'] = array(
    'name' => 'view own field_pbudg_neighborhood',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_project_description'.
  $permissions['view own field_pbudg_project_description'] = array(
    'name' => 'view own field_pbudg_project_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_project_location'.
  $permissions['view own field_pbudg_project_location'] = array(
    'name' => 'view own field_pbudg_project_location',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_project_name'.
  $permissions['view own field_pbudg_project_name'] = array(
    'name' => 'view own field_pbudg_project_name',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pbudg_submit_project'.
  $permissions['view own field_pbudg_submit_project'] = array(
    'name' => 'view own field_pbudg_submit_project',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_school_show_student'.
  $permissions['view own field_school_show_student'] = array(
    'name' => 'view own field_school_show_student',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_year'.
  $permissions['view own field_year'] = array(
    'name' => 'view own field_year',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
