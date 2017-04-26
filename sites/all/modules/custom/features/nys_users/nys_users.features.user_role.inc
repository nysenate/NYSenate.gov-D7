<?php
/**
 * @file
 * nys_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nys_users_user_default_roles() {
  $roles = array();

  // Exported role: Administrator.
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => 2,
  );

  // Exported role: Constituent.
  $roles['Constituent'] = array(
    'name' => 'Constituent',
    'weight' => 11,
  );

  // Exported role: FOIL Administrator.
  $roles['FOIL Administrator'] = array(
    'name' => 'FOIL Administrator',
    'weight' => 9,
  );

  // Exported role: Frontpage Editor.
  $roles['Frontpage Editor'] = array(
    'name' => 'Frontpage Editor',
    'weight' => 4,
  );

  // Exported role: Legislative Correspondent.
  $roles['Legislative Correspondent'] = array(
    'name' => 'Legislative Correspondent',
    'weight' => 6,
  );

  // Exported role: Microsite Content Producer.
  $roles['Microsite Content Producer'] = array(
    'name' => 'Microsite Content Producer',
    'weight' => 5,
  );

  // Exported role: Student Contest Judge.
  $roles['Student Contest Judge'] = array(
    'name' => 'Student Contest Judge',
    'weight' => 18,
  );

  // Exported role: Student Programs.
  $roles['Student Programs'] = array(
    'name' => 'Student Programs',
    'weight' => 8,
  );

  // Exported role: Web Administrator.
  $roles['Web Administrator'] = array(
    'name' => 'Web Administrator',
    'weight' => 3,
  );

  return $roles;
}
