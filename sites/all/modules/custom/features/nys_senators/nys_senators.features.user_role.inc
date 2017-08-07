<?php
/**
 * @file
 * nys_senators.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nys_senators_user_default_roles() {
  $roles = array();

  // Exported role: Senator.
  $roles['Senator'] = array(
    'name' => 'Senator',
    'weight' => 4,
  );

  return $roles;
}
