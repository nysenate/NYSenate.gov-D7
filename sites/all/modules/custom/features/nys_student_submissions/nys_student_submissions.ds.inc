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
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'School',
          'lb-cl' => 'form-label',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_stud_earthday_subm' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-cl' => 'label-above',
          'lb-el' => 'h3',
        ),
      ),
    ),
    'field_school_teachers_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
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
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-cl' => 'form-label',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_stud_earthday_subm' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-cl' => 'label-above',
          'lb-el' => 'h3',
        ),
      ),
    ),
    'field_school_teachers_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
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
    'field_hannon_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_hannon_city' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_hannon_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_hannon_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_hannon_phone_num' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
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
    'field_hannon_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_hannon_street_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_hannon_zip_code' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_teachers_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
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
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => '',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Letter of Recommendation',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_attach_statement_from_stud' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => '',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Statement from Student',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_category_being_nominated_f' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Category',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_cumulatve_gpa' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_nominators_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_nominators_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_nominators_phone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Nominator\'s Phone',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_nominators_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_phone_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Student Phone',
          'lb-el' => 'p',
        ),
      ),
    ),
  );
  $export['entityform|new_york_senate_youth_leadership|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'entityform|participatory_budgeting|default';
  $ds_fieldsetting->entity_type = 'entityform';
  $ds_fieldsetting->bundle = 'participatory_budgeting';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_pbpudg_volunteer' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb' => 'Volunteer?',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_category' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_guestimate' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb' => 'Budget Guestimate',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_last_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_mailing_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_neighborhood' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_phone' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_project_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => '',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_project_location' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_pbudg_project_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
  );
  $export['entityform|participatory_budgeting|default'] = $ds_fieldsetting;

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
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => 'form-results',
          'fis-def-at' => FALSE,
          'fis-el' => 'p',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_contact_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
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
  );
  $export['entityform|school_submissions|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'entityform|summer_reading|default';
  $ds_fieldsetting->entity_type = 'entityform';
  $ds_fieldsetting->bundle = 'summer_reading';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_children' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Your Child\'s Information',
          'lb-cl' => 'header',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_district' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Your Senate District',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_parent_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Parent or Guardian',
          'lb-el' => 'p',
        ),
      ),
    ),
  );
  $export['entityform|summer_reading|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_children|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_children';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_school_reading' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_books' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => '',
          'fi-def-at' => FALSE,
          'fi-el' => 'li',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'ul',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Books Read',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_student_reading_grade' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_children|default'] = $ds_fieldsetting;

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
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'fis' => TRUE,
          'fis-at' => '',
          'fis-cl' => '',
          'fis-def-at' => FALSE,
          'fis-el' => 'div',
          'func' => 'theme_ds_field_expert',
          'lb' => 'Student\'s Name',
          'lb-cl' => 'form-label',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_submission_upload' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Submission',
          'lb-cl' => 'form-label',
          'lb-el' => 'p',
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
    'field_school_student_full_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'p',
        ),
      ),
    ),
    'field_school_submission_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'fi' => TRUE,
          'fi-at' => '',
          'fi-cl' => 'form-results',
          'fi-def-at' => FALSE,
          'fi-el' => 'p',
          'fi-first-last' => FALSE,
          'fi-odd-even' => FALSE,
          'func' => 'theme_ds_field_expert',
          'lb' => 'Category',
          'lb-el' => 'p',
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
    'classes' => array(),
    'fields' => array(
      'field_school_contact_name' => 'ds_content',
      'field_school_grade' => 'ds_content',
      'field_school_name' => 'ds_content',
      'field_school_stud_earthday_subm' => 'ds_content',
      'field_school_teachers_email' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_contact_name',
        1 => 'field_school_teachers_email',
        2 => 'field_school_grade',
        3 => 'field_school_name',
        4 => 'field_school_stud_earthday_subm',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
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
    'classes' => array(),
    'fields' => array(
      'field_school_contact_name' => 'ds_content',
      'field_school_grade' => 'ds_content',
      'field_school_name' => 'ds_content',
      'field_school_stud_earthday_subm' => 'ds_content',
      'field_school_teachers_email' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_contact_name',
        1 => 'field_school_teachers_email',
        2 => 'field_school_grade',
        3 => 'field_school_name',
        4 => 'field_school_stud_earthday_subm',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
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
    'classes' => array(),
    'fields' => array(
      'field_hannon_category' => 'ds_content',
      'field_hannon_city' => 'ds_content',
      'field_hannon_first_name' => 'ds_content',
      'field_hannon_last_name' => 'ds_content',
      'field_hannon_phone_num' => 'ds_content',
      'field_hannon_photo_upload' => 'ds_content',
      'field_hannon_school_name' => 'ds_content',
      'field_hannon_street_address' => 'ds_content',
      'field_hannon_zip_code' => 'ds_content',
      'field_school_teachers_email' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
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
    'wrappers' => array(
      'ds_content' => 'div',
    ),
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
    'classes' => array(),
    'fields' => array(
      'field_attach_letter_of_recommend' => 'ds_content',
      'field_attach_statement_from_stud' => 'ds_content',
      'field_category_being_nominated_f' => 'ds_content',
      'field_cumulatve_gpa' => 'ds_content',
      'field_nominators_email' => 'ds_content',
      'field_nominators_name' => 'ds_content',
      'field_nominators_phone_number' => 'ds_content',
      'field_nominators_title' => 'ds_content',
      'field_school' => 'ds_content',
      'field_student_address' => 'ds_content',
      'field_student_email' => 'ds_content',
      'field_student_grade' => 'ds_content',
      'field_student_name' => 'ds_content',
      'field_student_phone_number' => 'ds_content',
      'group_nominator' => 'ds_content',
      'group_student' => 'ds_content',
      'group_student_contrib' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
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
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['entityform|new_york_senate_youth_leadership|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|participatory_budgeting|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'participatory_budgeting';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_pbpudg_volunteer' => 'ds_content',
      'field_pbudg_category' => 'ds_content',
      'field_pbudg_email' => 'ds_content',
      'field_pbudg_first_name' => 'ds_content',
      'field_pbudg_guestimate' => 'ds_content',
      'field_pbudg_last_name' => 'ds_content',
      'field_pbudg_mailing_address' => 'ds_content',
      'field_pbudg_neighborhood' => 'ds_content',
      'field_pbudg_phone' => 'ds_content',
      'field_pbudg_project_description' => 'ds_content',
      'field_pbudg_project_location' => 'ds_content',
      'field_pbudg_project_name' => 'ds_content',
      'group_project' => 'ds_content',
      'group_your_info' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'group_your_info',
        1 => 'field_pbudg_first_name',
        2 => 'group_project',
        3 => 'field_pbudg_last_name',
        4 => 'field_pbudg_project_name',
        5 => 'field_pbudg_category',
        6 => 'field_pbudg_phone',
        7 => 'field_pbudg_email',
        8 => 'field_pbudg_guestimate',
        9 => 'field_pbudg_mailing_address',
        10 => 'field_pbudg_project_description',
        11 => 'field_pbpudg_volunteer',
        12 => 'field_pbudg_neighborhood',
        13 => 'field_pbudg_project_location',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['entityform|participatory_budgeting|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|school_submissions|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'school_submissions';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_school_contact_email' => 'ds_content',
      'field_school_contact_name' => 'ds_content',
      'field_school_grade' => 'ds_content',
      'field_school_name' => 'ds_content',
      'field_school_student_submissions' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_name',
        1 => 'field_school_contact_name',
        2 => 'field_school_contact_email',
        3 => 'field_school_grade',
        4 => 'field_school_student_submissions',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['entityform|school_submissions|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'entityform|summer_reading|default';
  $ds_layout->entity_type = 'entityform';
  $ds_layout->bundle = 'summer_reading';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_address' => 'ds_content',
      'field_children' => 'ds_content',
      'field_district' => 'ds_content',
      'field_student_email' => 'ds_content',
      'field_student_parent_name' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_student_parent_name',
        1 => 'field_student_email',
        2 => 'field_address',
        3 => 'field_district',
        4 => 'field_children',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['entityform|summer_reading|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_children|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_children';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_school_reading' => 'ds_content',
      'field_student_books' => 'ds_content',
      'field_student_name' => 'ds_content',
      'field_student_reading_grade' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_student_name',
        1 => 'field_student_reading_grade',
        2 => 'field_school_reading',
        3 => 'field_student_books',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['field_collection_item|field_children|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_school_stud_earthday_subm|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_school_stud_earthday_subm';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'field_school_student_full_name' => 'ds_content',
      'field_school_submission_upload' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_student_full_name',
        1 => 'field_school_submission_upload',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
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
    'classes' => array(),
    'fields' => array(
      'field_school_student_full_name' => 'ds_content',
      'field_school_submission_type' => 'ds_content',
      'field_school_submission_upload' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_school_student_full_name',
        1 => 'field_school_submission_type',
        2 => 'field_school_submission_upload',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['field_collection_item|field_school_student_submissions|default'] = $ds_layout;

  return $export;
}
