<?php

/**
 * @file
 * nys_student_submissions.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function nys_student_submissions_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Block with Links to Senate Services Admin pages';
  $fe_block_boxes->format = 'source_html';
  $fe_block_boxes->machine_name = 'student_submissions';
  $fe_block_boxes->body = '<p><a href="/admin/entityforms/thanksgiving">Thanksgiving Student Submissions</a></p>

<p><a href="/admin/entityforms/earthday">Earth Day Student Submissions</a></p>

<p><a href="/admin/entityforms/student-leadership-award">Student Leadership Award Submissions</a></p>

<p><a href="/admin/content/profiles">Manage Honoree Profiles</a> (Veterans and Women of Distinction)</p>
';

  $export['student_submissions'] = $fe_block_boxes;

  return $export;
}
