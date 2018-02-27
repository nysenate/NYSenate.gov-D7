<?php
/**
 * @file
 * nys_student_submissions.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nys_student_submissions_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'entityform|earth_day_preview|default';
  $ds_fieldsetting->entity_type = 'entityform';
  $ds_fieldsetting->bundle = 'earth_day_preview';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_school_contact_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_teachers_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'School',
          'lb-el' => 'p',
          'lb-cl' => 'form-label',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_stud_earthday_subm' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
        ),
      ),
    ),
  );
  $export['entityform|earth_day_preview|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'entityform|earth_day|default';
  $ds_fieldsetting->entity_type = 'entityform';
  $ds_fieldsetting->bundle = 'earth_day';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_school_contact_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'lb-cl' => 'form-label',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_stud_earthday_subm' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-cl' => 'label-above',
        ),
      ),
    ),
    'field_school_teachers_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_ceo_phone' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_school_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['entityform|earth_day|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'entityform|hannon_photo_contest|default';
  $ds_fieldsetting->entity_type = 'entityform';
  $ds_fieldsetting->bundle = 'hannon_photo_contest';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_hannon_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hannon_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hannon_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hannon_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hannon_photo_upload' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Your submitted photo',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_hannon_phone_num' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hannon_street_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hannon_city' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_hannon_zip_code' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_school_teachers_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['entityform|hannon_photo_contest|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'entityform|new_york_senate_youth_leadership|default';
  $ds_fieldsetting->entity_type = 'entityform';
  $ds_fieldsetting->bundle = 'new_york_senate_youth_leadership';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_attach_letter_of_recommend' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Letter of Recommendation',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_attach_statement_from_stud' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Statement from Student',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_category_being_nominated_f' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Category',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_cumulatve_gpa' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_nominators_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_nominators_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_nominators_phone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Nominator\'s Phone',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_nominators_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_school' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_student_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_student_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_student_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_student_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_student_phone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Student Phone',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['entityform|new_york_senate_youth_leadership|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'entityform|school_submissions|default';
  $ds_fieldsetting->entity_type = 'entityform';
  $ds_fieldsetting->bundle = 'school_submissions';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_school_contact_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fis' => TRUE,
          'fis-el' => 'p',
          'fis-cl' => 'form-results',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_school_contact_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_school_student_submissions' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
        ),
      ),
    ),
    'field_school_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['entityform|school_submissions|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_school_stud_earthday_subm|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_school_stud_earthday_subm';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_school_student_full_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Student\'s Name',
          'lb-el' => 'p',
          'lb-cl' => 'form-label',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_school_submission_upload' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Submission',
          'lb-el' => 'p',
          'lb-cl' => 'form-label',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_school_stud_earthday_subm|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_school_student_submissions|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_school_student_submissions';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_school_submission_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Category',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_school_submission_upload' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Student Submission',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_student_full_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'form-results',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['field_collection_item|field_school_student_submissions|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nys_student_submissions_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|earth_day_preview|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'earth_day_preview';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_contact_name',
        1 => 'field_school_teachers_email',
        2 => 'field_school_grade',
        3 => 'field_school_name',
        4 => 'field_school_stud_earthday_subm',
      ),
    ),
    'fields' => array(
      'field_school_contact_name' => 'ds_content',
      'field_school_teachers_email' => 'ds_content',
      'field_school_grade' => 'ds_content',
      'field_school_name' => 'ds_content',
      'field_school_stud_earthday_subm' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['entityform|earth_day_preview|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|earth_day|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'earth_day';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_contact_name',
        1 => 'field_school_teachers_email',
        2 => 'field_school_grade',
        3 => 'field_school_name',
        4 => 'field_school_ceo_phone',
        5 => 'field_school_stud_earthday_subm',
      ),
    ),
    'fields' => array(
      'field_school_contact_name' => 'ds_content',
      'field_school_teachers_email' => 'ds_content',
      'field_school_grade' => 'ds_content',
      'field_school_name' => 'ds_content',
      'field_school_ceo_phone' => 'ds_content',
      'field_school_stud_earthday_subm' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['entityform|earth_day|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|hannon_photo_contest|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'hannon_photo_contest';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_hannon_school_name',
        1 => 'field_hannon_category',
        2 => 'field_hannon_first_name',
        3 => 'field_hannon_last_name',
        4 => 'field_hannon_street_address',
        5 => 'field_hannon_city',
        6 => 'field_hannon_zip_code',
        7 => 'field_school_teachers_email',
        8 => 'field_hannon_phone_num',
        9 => 'field_hannon_photo_upload',
      ),
    ),
    'fields' => array(
      'field_hannon_school_name' => 'ds_content',
      'field_hannon_category' => 'ds_content',
      'field_hannon_first_name' => 'ds_content',
      'field_hannon_last_name' => 'ds_content',
      'field_hannon_street_address' => 'ds_content',
      'field_hannon_city' => 'ds_content',
      'field_hannon_zip_code' => 'ds_content',
      'field_school_teachers_email' => 'ds_content',
      'field_hannon_phone_num' => 'ds_content',
      'field_hannon_photo_upload' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['entityform|hannon_photo_contest|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|new_york_senate_youth_leadership|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'new_york_senate_youth_leadership';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_student',
        1 => 'field_student_name',
        2 => 'field_student_address',
        3 => 'group_nominator',
        4 => 'field_nominators_name',
        5 => 'field_nominators_title',
        6 => 'field_student_phone_number',
        7 => 'field_nominators_email',
        8 => 'field_school',
        9 => 'field_nominators_phone_number',
        10 => 'field_student_email',
        11 => 'field_attach_letter_of_recommend',
        12 => 'field_cumulatve_gpa',
        13 => 'field_category_being_nominated_f',
        14 => 'field_student_grade',
        15 => 'group_student_contrib',
        16 => 'field_attach_statement_from_stud',
      ),
    ),
    'fields' => array(
      'group_student' => 'ds_content',
      'field_student_name' => 'ds_content',
      'field_student_address' => 'ds_content',
      'group_nominator' => 'ds_content',
      'field_nominators_name' => 'ds_content',
      'field_nominators_title' => 'ds_content',
      'field_student_phone_number' => 'ds_content',
      'field_nominators_email' => 'ds_content',
      'field_school' => 'ds_content',
      'field_nominators_phone_number' => 'ds_content',
      'field_student_email' => 'ds_content',
      'field_attach_letter_of_recommend' => 'ds_content',
      'field_cumulatve_gpa' => 'ds_content',
      'field_category_being_nominated_f' => 'ds_content',
      'field_student_grade' => 'ds_content',
      'group_student_contrib' => 'ds_content',
      'field_attach_statement_from_stud' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['entityform|new_york_senate_youth_leadership|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|school_submissions|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'school_submissions';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_name',
        1 => 'field_school_contact_name',
        2 => 'field_school_contact_email',
        3 => 'field_school_grade',
        4 => 'field_school_student_submissions',
      ),
    ),
    'fields' => array(
      'field_school_name' => 'ds_content',
      'field_school_contact_name' => 'ds_content',
      'field_school_contact_email' => 'ds_content',
      'field_school_grade' => 'ds_content',
      'field_school_student_submissions' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['entityform|school_submissions|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_school_stud_earthday_subm|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_school_stud_earthday_subm';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_student_full_name',
        1 => 'field_school_submission_upload',
      ),
    ),
    'fields' => array(
      'field_school_student_full_name' => 'ds_content',
      'field_school_submission_upload' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_school_stud_earthday_subm|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_school_student_submissions|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_school_student_submissions';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_student_full_name',
        1 => 'field_school_submission_type',
        2 => 'field_school_submission_upload',
      ),
    ),
    'fields' => array(
      'field_school_student_full_name' => 'ds_content',
      'field_school_submission_type' => 'ds_content',
      'field_school_submission_upload' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_school_student_submissions|default'] = $ds_layout;

  return $export;
}
