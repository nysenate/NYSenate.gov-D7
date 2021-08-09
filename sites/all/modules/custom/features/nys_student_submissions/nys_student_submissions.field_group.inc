<?php

/**
 * @file
 * nys_student_submissions.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_student_submissions_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_add_child|entityform|summer_reading|form';
  $field_group->group_name = 'group_add_child';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'summer_reading';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_children',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-add-child field-group-fieldset',
        'description' => 'For each of your children fill out their name, grade, school, and three books they read this summer. Add additional children by selecting "Add another Child."',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Add your Child',
    ),
    'format_type' => 'fieldset',
    'label' => 'Add your Child',
    'weight' => '3',
  );
  $field_groups['group_add_child|entityform|summer_reading|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|entityform|hannon_photo_contest|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'hannon_photo_contest';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_hannon_city',
      1 => 'field_hannon_phone_num',
      2 => 'field_hannon_street_address',
      3 => 'field_hannon_zip_code',
      4 => 'field_school_teachers_email',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-address field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Contact Information',
    ),
    'format_type' => 'fieldset',
    'label' => 'Contact Information',
    'weight' => '5',
  );
  $field_groups['group_address|entityform|hannon_photo_contest|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_administrative|field_collection_item|field_school_student_submissions|form';
  $field_group->group_name = 'group_administrative';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_school_student_submissions';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_school_show_student',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-administrative field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Administrative',
    ),
    'format_type' => 'fieldset',
    'label' => 'Administrative',
    'weight' => '3',
  );
  $field_groups['group_administrative|field_collection_item|field_school_student_submissions|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|entityform|hannon_photo_contest|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'hannon_photo_contest';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_hannon_star_rating',
      1 => 'field_hannon_winner_types',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-admin field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Administrative',
    'weight' => '8',
  );
  $field_groups['group_admin|entityform|hannon_photo_contest|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|field_collection_item|field_school_stud_earthday_subm|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_school_stud_earthday_subm';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_school_show_student',
      1 => 'field_year',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-admin field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Adminstrative',
    ),
    'format_type' => 'fieldset',
    'label' => 'Adminstrative',
    'weight' => '2',
  );
  $field_groups['group_admin|field_collection_item|field_school_stud_earthday_subm|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nominator|entityform|new_york_senate_youth_leadership|default';
  $field_group->group_name = 'group_nominator';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'new_york_senate_youth_leadership';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_attach_letter_of_recommend',
      1 => 'field_nominators_email',
      2 => 'field_nominators_name',
      3 => 'field_nominators_phone_number',
      4 => 'field_nominators_title',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-nominator field-group-fieldset',
        'description' => '',
        'id' => '',
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Nominator\'s Information',
    'weight' => '2',
  );
  $field_groups['group_nominator|entityform|new_york_senate_youth_leadership|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nominator|entityform|new_york_senate_youth_leadership|form';
  $field_group->group_name = 'group_nominator';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'new_york_senate_youth_leadership';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_attach_letter_of_recommend',
      1 => 'field_nominators_email',
      2 => 'field_nominators_name',
      3 => 'field_nominators_phone_number',
      4 => 'field_nominators_title',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-nominator field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Nominator\'s Information',
    'weight' => '1',
  );
  $field_groups['group_nominator|entityform|new_york_senate_youth_leadership|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pr_details|entityform|participatory_budgeting|form';
  $field_group->group_name = 'group_pr_details';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'participatory_budgeting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_pbudg_submit_project',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-pr-details field-group-fieldset',
        'description' => 'If you are just interested in volunteering, you are ready to submit the form. Otherwise, please check this box to propose a project, which must be in Senate District 20 [<a target="_blank" href="/district/20">view District 20 map</a>].',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Propose a Project',
    ),
    'format_type' => 'fieldset',
    'label' => 'Propose a Project',
    'weight' => '7',
  );
  $field_groups['group_pr_details|entityform|participatory_budgeting|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project|entityform|participatory_budgeting|default';
  $field_group->group_name = 'group_project';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'participatory_budgeting';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_pbudg_category',
      1 => 'field_pbudg_guestimate',
      2 => 'field_pbudg_neighborhood',
      3 => 'field_pbudg_project_description',
      4 => 'field_pbudg_project_location',
      5 => 'field_pbudg_project_name',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-project field-group-fieldset',
        'description' => '',
        'id' => '',
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Project Details',
    'weight' => '1',
  );
  $field_groups['group_project|entityform|participatory_budgeting|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_student_contrib|entityform|new_york_senate_youth_leadership|default';
  $field_group->group_name = 'group_student_contrib';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'new_york_senate_youth_leadership';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_attach_statement_from_stud',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-student-contrib field-group-fieldset',
        'description' => '',
        'id' => '',
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Student\'s Contribution',
    'weight' => '8',
  );
  $field_groups['group_student_contrib|entityform|new_york_senate_youth_leadership|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_student_contrib|entityform|new_york_senate_youth_leadership|form';
  $field_group->group_name = 'group_student_contrib';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'new_york_senate_youth_leadership';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_attach_statement_from_stud',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-student-contrib field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Student\'s Contribution',
    'weight' => '2',
  );
  $field_groups['group_student_contrib|entityform|new_york_senate_youth_leadership|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_student|entityform|new_york_senate_youth_leadership|default';
  $field_group->group_name = 'group_student';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'new_york_senate_youth_leadership';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_category_being_nominated_f',
      1 => 'field_cumulatve_gpa',
      2 => 'field_school',
      3 => 'field_student_address',
      4 => 'field_student_email',
      5 => 'field_student_grade',
      6 => 'field_student_name',
      7 => 'field_student_phone_number',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-student field-group-fieldset',
        'description' => '',
        'id' => '',
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Student Information',
    'weight' => '0',
  );
  $field_groups['group_student|entityform|new_york_senate_youth_leadership|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_student|entityform|new_york_senate_youth_leadership|form';
  $field_group->group_name = 'group_student';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'new_york_senate_youth_leadership';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_category_being_nominated_f',
      1 => 'field_cumulatve_gpa',
      2 => 'field_school',
      3 => 'field_student_address',
      4 => 'field_student_email',
      5 => 'field_student_grade',
      6 => 'field_student_name',
      7 => 'field_student_phone_number',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-student field-group-fieldset',
        'description' => '',
        'id' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Student Information',
    'weight' => '0',
  );
  $field_groups['group_student|entityform|new_york_senate_youth_leadership|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_volunteer|entityform|participatory_budgeting|form';
  $field_group->group_name = 'group_volunteer';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'participatory_budgeting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_pbpudg_volunteer',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-volunteer field-group-fieldset',
        'description' => 'Neighborhood Organizers are community members like you, who help operate vote sites during Vote Week to bring the ballot to the people. Volunteers receive training, and can then work for a few hours or a few days. If you check this box, our volunteer coordinator or a district staff member will follow up with you. To find out more email us at Hamilton@NYSenate.gov or call 718-284-4700.',
        'id' => '',
        'required_fields' => 1,
      ),
      'label' => 'Sign up to be a Neighborhood Organizer!',
    ),
    'format_type' => 'fieldset',
    'label' => 'Sign up to be a Neighborhood Organizer!',
    'weight' => '3',
  );
  $field_groups['group_volunteer|entityform|participatory_budgeting|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_your_info|entityform|participatory_budgeting|default';
  $field_group->group_name = 'group_your_info';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'participatory_budgeting';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_pbpudg_volunteer',
      1 => 'field_pbudg_email',
      2 => 'field_pbudg_first_name',
      3 => 'field_pbudg_last_name',
      4 => 'field_pbudg_mailing_address',
      5 => 'field_pbudg_phone',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-your-info field-group-fieldset',
        'description' => '',
        'id' => '',
      ),
    ),
    'format_type' => 'fieldset',
    'label' => 'Your Information',
    'weight' => '0',
  );
  $field_groups['group_your_info|entityform|participatory_budgeting|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add your Child');
  t('Administrative');
  t('Adminstrative');
  t('Contact Information');
  t('Nominator\'s Information');
  t('Project Details');
  t('Propose a Project');
  t('Sign up to be a Neighborhood Organizer!');
  t('Student Information');
  t('Student\'s Contribution');
  t('Your Information');

  return $field_groups;
}
