<?php

/**
 * @file
 * nys_committees.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_committees_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_assemblymen_chair'.
  $permissions['create field_assemblymen_chair'] = array(
    'name' => 'create field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_chair'.
  $permissions['create field_chair'] = array(
    'name' => 'create field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_committee_types'.
  $permissions['create field_committee_types'] = array(
    'name' => 'create field_committee_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_frontend_display_type'.
  $permissions['create field_frontend_display_type'] = array(
    'name' => 'create field_frontend_display_type',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_members'.
  $permissions['create field_members'] = array(
    'name' => 'create field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_assemblymen_chair'.
  $permissions['edit field_assemblymen_chair'] = array(
    'name' => 'edit field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_chair'.
  $permissions['edit field_chair'] = array(
    'name' => 'edit field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_committee_types'.
  $permissions['edit field_committee_types'] = array(
    'name' => 'edit field_committee_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_frontend_display_type'.
  $permissions['edit field_frontend_display_type'] = array(
    'name' => 'edit field_frontend_display_type',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_members'.
  $permissions['edit field_members'] = array(
    'name' => 'edit field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_assemblymen_chair'.
  $permissions['edit own field_assemblymen_chair'] = array(
    'name' => 'edit own field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_chair'.
  $permissions['edit own field_chair'] = array(
    'name' => 'edit own field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_committee_types'.
  $permissions['edit own field_committee_types'] = array(
    'name' => 'edit own field_committee_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_frontend_display_type'.
  $permissions['edit own field_frontend_display_type'] = array(
    'name' => 'edit own field_frontend_display_type',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_members'.
  $permissions['edit own field_members'] = array(
    'name' => 'edit own field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_assemblymen_chair'.
  $permissions['view field_assemblymen_chair'] = array(
    'name' => 'view field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_chair'.
  $permissions['view field_chair'] = array(
    'name' => 'view field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_committee_types'.
  $permissions['view field_committee_types'] = array(
    'name' => 'view field_committee_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_frontend_display_type'.
  $permissions['view field_frontend_display_type'] = array(
    'name' => 'view field_frontend_display_type',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_members'.
  $permissions['view field_members'] = array(
    'name' => 'view field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_assemblymen_chair'.
  $permissions['view own field_assemblymen_chair'] = array(
    'name' => 'view own field_assemblymen_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_chair'.
  $permissions['view own field_chair'] = array(
    'name' => 'view own field_chair',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_committee_types'.
  $permissions['view own field_committee_types'] = array(
    'name' => 'view own field_committee_types',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_frontend_display_type'.
  $permissions['view own field_frontend_display_type'] = array(
    'name' => 'view own field_frontend_display_type',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_members'.
  $permissions['view own field_members'] = array(
    'name' => 'view own field_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Legislative Correspondent' => 'Legislative Correspondent',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
