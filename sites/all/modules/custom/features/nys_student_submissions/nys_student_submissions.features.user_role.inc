<?php
/**
 * @file
 * nys_student_submissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nys_student_submissions_user_default_roles() {
  $roles = array();

  // Exported role: Student Contest Judge.
  $roles['Student Contest Judge'] = array(
    'name' => 'Student Contest Judge',
    'weight' => 18,
  );

  return $roles;
}
