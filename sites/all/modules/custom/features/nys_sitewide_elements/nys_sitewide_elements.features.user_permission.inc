<?php

/**
 * @file
 * nys_sitewide_elements.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_sitewide_elements_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_add_honoree_list'.
  $permissions['create field_add_honoree_list'] = array(
    'name' => 'create field_add_honoree_list',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_associated_senator'.
  $permissions['create field_associated_senator'] = array(
    'name' => 'create field_associated_senator',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_form_description'.
  $permissions['create field_form_description'] = array(
    'name' => 'create field_form_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_group_members'.
  $permissions['create field_group_members'] = array(
    'name' => 'create field_group_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_profile_status'.
  $permissions['create field_profile_status'] = array(
    'name' => 'create field_profile_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_add_honoree_list'.
  $permissions['edit field_add_honoree_list'] = array(
    'name' => 'edit field_add_honoree_list',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_associated_senator'.
  $permissions['edit field_associated_senator'] = array(
    'name' => 'edit field_associated_senator',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_form_description'.
  $permissions['edit field_form_description'] = array(
    'name' => 'edit field_form_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_group_members'.
  $permissions['edit field_group_members'] = array(
    'name' => 'edit field_group_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_profile_status'.
  $permissions['edit field_profile_status'] = array(
    'name' => 'edit field_profile_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_add_honoree_list'.
  $permissions['edit own field_add_honoree_list'] = array(
    'name' => 'edit own field_add_honoree_list',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_associated_senator'.
  $permissions['edit own field_associated_senator'] = array(
    'name' => 'edit own field_associated_senator',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_form_description'.
  $permissions['edit own field_form_description'] = array(
    'name' => 'edit own field_form_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_group_members'.
  $permissions['edit own field_group_members'] = array(
    'name' => 'edit own field_group_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_profile_status'.
  $permissions['edit own field_profile_status'] = array(
    'name' => 'edit own field_profile_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_add_honoree_list'.
  $permissions['view field_add_honoree_list'] = array(
    'name' => 'view field_add_honoree_list',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_associated_senator'.
  $permissions['view field_associated_senator'] = array(
    'name' => 'view field_associated_senator',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_form_description'.
  $permissions['view field_form_description'] = array(
    'name' => 'view field_form_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_group_members'.
  $permissions['view field_group_members'] = array(
    'name' => 'view field_group_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_profile_status'.
  $permissions['view field_profile_status'] = array(
    'name' => 'view field_profile_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_add_honoree_list'.
  $permissions['view own field_add_honoree_list'] = array(
    'name' => 'view own field_add_honoree_list',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_associated_senator'.
  $permissions['view own field_associated_senator'] = array(
    'name' => 'view own field_associated_senator',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Frontpage Editor' => 'Frontpage Editor',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_form_description'.
  $permissions['view own field_form_description'] = array(
    'name' => 'view own field_form_description',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Microsite Content Producer' => 'Microsite Content Producer',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_group_members'.
  $permissions['view own field_group_members'] = array(
    'name' => 'view own field_group_members',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_profile_status'.
  $permissions['view own field_profile_status'] = array(
    'name' => 'view own field_profile_status',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senate Services' => 'Senate Services',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
