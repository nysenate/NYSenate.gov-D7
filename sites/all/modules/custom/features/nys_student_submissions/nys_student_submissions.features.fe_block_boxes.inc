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
  $fe_block_boxes->info = 'Block with Student Submissions Links';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'student_submissions';
  $fe_block_boxes->body = '<p><a href="/admin/entityforms/earthday">Earth Day 2017 Student Submissions</a></p>';

  $export['student_submissions'] = $fe_block_boxes;

  return $export;
}
