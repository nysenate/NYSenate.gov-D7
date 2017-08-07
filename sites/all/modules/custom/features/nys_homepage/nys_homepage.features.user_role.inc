<?php
/**
 * @file
 * nys_homepage.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nys_homepage_user_default_roles() {
  $roles = array();

  // Exported role: Frontpage Editor.
  $roles['Frontpage Editor'] = array(
    'name' => 'Frontpage Editor',
    'weight' => 4,
  );

  return $roles;
}
