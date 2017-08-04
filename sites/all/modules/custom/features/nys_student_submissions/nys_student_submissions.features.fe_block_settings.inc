<?php
/**
 * @file
 * nys_student_submissions.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nys_student_submissions_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-student_submissions'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'student_submissions',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'Administrator' => 6,
      'Student Contest Judge' => 17,
    ),
    'themes' => array(
      'adminimal' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'nysenate' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nysenate',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Student Submissions',
    'visibility' => 0,
  );

  return $export;
}
