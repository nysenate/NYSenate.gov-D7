<?php

/**
 * @file
 * nys_student_submissions.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function nys_student_submissions_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Unique Email';
  $rule->name = 'unique_email';
  $rule->field_name = 'field_school_teachers_email';
  $rule->col = 'email';
  $rule->entity_type = 'entityform';
  $rule->bundle = 'hannon_photo_contest';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'bypass' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
    'data' => 'bundle',
    'errors' => 1,
    'per_user' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      14 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
    ),
  );
  $rule->error_message = 'The email you entered has already been used to submit a photo. Only one photo submission per student is permitted. If you think you are receiving this message in error, please call: 516-739-1700';
  $export['unique_email'] = $rule;

  return $export;
}
