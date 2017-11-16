<?php
/**
 * @file
 * nys_senators.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nys_senators_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_active'.
  $permissions['create field_active'] = array(
    'name' => 'create field_active',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conference'.
  $permissions['create field_conference'] = array(
    'name' => 'create field_conference',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_district'.
  $permissions['create field_district'] = array(
    'name' => 'create field_district',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inactive_senator_message'.
  $permissions['create field_inactive_senator_message'] = array(
    'name' => 'create field_inactive_senator_message',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ol_member_id'.
  $permissions['create field_ol_member_id'] = array(
    'name' => 'create field_ol_member_id',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pull_quote'.
  $permissions['create field_pull_quote'] = array(
    'name' => 'create field_pull_quote',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_shortname'.
  $permissions['create field_shortname'] = array(
    'name' => 'create field_shortname',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_user_account'.
  $permissions['create field_user_account'] = array(
    'name' => 'create field_user_account',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_active'.
  $permissions['edit field_active'] = array(
    'name' => 'edit field_active',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conference'.
  $permissions['edit field_conference'] = array(
    'name' => 'edit field_conference',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_district'.
  $permissions['edit field_district'] = array(
    'name' => 'edit field_district',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inactive_senator_message'.
  $permissions['edit field_inactive_senator_message'] = array(
    'name' => 'edit field_inactive_senator_message',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ol_member_id'.
  $permissions['edit field_ol_member_id'] = array(
    'name' => 'edit field_ol_member_id',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pull_quote'.
  $permissions['edit field_pull_quote'] = array(
    'name' => 'edit field_pull_quote',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_shortname'.
  $permissions['edit field_shortname'] = array(
    'name' => 'edit field_shortname',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_user_account'.
  $permissions['edit field_user_account'] = array(
    'name' => 'edit field_user_account',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_active'.
  $permissions['edit own field_active'] = array(
    'name' => 'edit own field_active',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conference'.
  $permissions['edit own field_conference'] = array(
    'name' => 'edit own field_conference',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_district'.
  $permissions['edit own field_district'] = array(
    'name' => 'edit own field_district',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inactive_senator_message'.
  $permissions['edit own field_inactive_senator_message'] = array(
    'name' => 'edit own field_inactive_senator_message',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ol_member_id'.
  $permissions['edit own field_ol_member_id'] = array(
    'name' => 'edit own field_ol_member_id',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pull_quote'.
  $permissions['edit own field_pull_quote'] = array(
    'name' => 'edit own field_pull_quote',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_shortname'.
  $permissions['edit own field_shortname'] = array(
    'name' => 'edit own field_shortname',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_user_account'.
  $permissions['edit own field_user_account'] = array(
    'name' => 'edit own field_user_account',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_active'.
  $permissions['view field_active'] = array(
    'name' => 'view field_active',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conference'.
  $permissions['view field_conference'] = array(
    'name' => 'view field_conference',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_district'.
  $permissions['view field_district'] = array(
    'name' => 'view field_district',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inactive_senator_message'.
  $permissions['view field_inactive_senator_message'] = array(
    'name' => 'view field_inactive_senator_message',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ol_member_id'.
  $permissions['view field_ol_member_id'] = array(
    'name' => 'view field_ol_member_id',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pull_quote'.
  $permissions['view field_pull_quote'] = array(
    'name' => 'view field_pull_quote',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_shortname'.
  $permissions['view field_shortname'] = array(
    'name' => 'view field_shortname',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_user_account'.
  $permissions['view field_user_account'] = array(
    'name' => 'view field_user_account',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_active'.
  $permissions['view own field_active'] = array(
    'name' => 'view own field_active',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conference'.
  $permissions['view own field_conference'] = array(
    'name' => 'view own field_conference',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_district'.
  $permissions['view own field_district'] = array(
    'name' => 'view own field_district',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Constituent' => 'Constituent',
      'Senator' => 'Senator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inactive_senator_message'.
  $permissions['view own field_inactive_senator_message'] = array(
    'name' => 'view own field_inactive_senator_message',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ol_member_id'.
  $permissions['view own field_ol_member_id'] = array(
    'name' => 'view own field_ol_member_id',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pull_quote'.
  $permissions['view own field_pull_quote'] = array(
    'name' => 'view own field_pull_quote',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_shortname'.
  $permissions['view own field_shortname'] = array(
    'name' => 'view own field_shortname',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_user_account'.
  $permissions['view own field_user_account'] = array(
    'name' => 'view own field_user_account',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Web Administrator' => 'Web Administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
