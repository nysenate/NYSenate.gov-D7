<?php

/**
 * @file
 * nys_student_submissions.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nys_student_submissions_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-earth_day-field_school_contact_name'.
  $field_instances['entityform-earth_day-field_school_contact_name'] = array(
    'bundle' => 'earth_day',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_contact_name',
    'label' => 'Teacher\'s Name',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'advanced_html' => 'advanced_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'advanced_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'entityform-earth_day-field_school_grade'.
  $field_instances['entityform-earth_day-field_school_grade'] = array(
    'bundle' => 'earth_day',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => -4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_grade',
    'label' => 'Grade',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-earth_day-field_school_name'.
  $field_instances['entityform-earth_day-field_school_name'] = array(
    'bundle' => 'earth_day',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Start typing your school\'s name and choose from list (you must CLICK ON NAME in drop down). If your school does not show up, <a href="/webforms/school-not-showing-contact-form">please contact us</a>.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => -3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_name',
    'label' => 'School Name',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 1,
    'options_limit_fields' => array(),
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'autofill' => array(
          'overwrite' => 1,
          'status' => 1,
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => 1,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'entityform-earth_day-field_school_stud_earthday_subm'.
  $field_instances['entityform-earth_day-field_school_stud_earthday_subm'] = array(
    'bundle' => 'earth_day',
    'custom_add_another' => 'Add another student',
    'custom_remove' => 'Remove this student',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => -1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_stud_earthday_subm',
    'label' => 'Student Submissions',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'entityform-earth_day-field_school_teachers_email'.
  $field_instances['entityform-earth_day-field_school_teachers_email'] = array(
    'bundle' => 'earth_day',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => -5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_teachers_email',
    'label' => 'Teacher\'s Email',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'entityform-hannon_photo_contest-field_agreement'.
  $field_instances['entityform-hannon_photo_contest-field_agreement'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 13,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_agreement',
    'label' => 'Agreement',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_category'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_category'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_category',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_city'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_city'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_city',
    'label' => 'City',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_district_status'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_district_status'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_district_status',
    'label' => 'District Status',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_first_name'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_first_name'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_first_name',
    'label' => 'First Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_last_name'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_last_name'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_last_name',
    'label' => 'Last Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_phone_num'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_phone_num'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_phone_num',
    'label' => 'Phone Number',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_photo_upload'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_photo_upload'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'file_rendered',
        'weight' => 9,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_photo_upload',
    'label' => 'Attach your photo',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'jpg jpeg',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => '[entityform:field-hannon-last-name]_[entityform:field-hannon-first-name]_[entityform:field-hannon-category].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => 'students/hannon-photo/[current-date:custom:Y]',
        ),
        'redirect' => 0,
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_45x45' => 0,
          'image_60x60' => 0,
          'image_80x60' => 0,
          'image_160x160' => 0,
          'image_200x125' => 0,
          'image_280x280' => 0,
          'image_360x200' => 0,
          'image_380x215' => 0,
          'image_400x240' => 0,
          'image_440x230' => 0,
          'image_680x510' => 0,
          'image_760x377' => 0,
          'image_1280x510' => 0,
          'image_1346x330' => 0,
          'image_embed_landscape_400x225' => 0,
          'image_embed_portrait_225x345' => 0,
          'image_large' => 0,
          'image_large_retina' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_medium_retina' => 0,
          'image_retina_100x100' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_thumbnail_retina' => 0,
          'image_user_dashboard_100x100' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_school_name'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_school_name'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If your school is not listed, please call: 516-739-1700',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => 0,
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_school_name',
    'label' => 'School',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_star_rating'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_star_rating'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_star_rating',
    'label' => 'Star Rating',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_street_address'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_street_address'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_street_address',
    'label' => 'Street Address',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_winner_types'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_winner_types'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 'none',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_winner_types',
    'label' => 'Winner Types',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_hannon_zip_code'.
  $field_instances['entityform-hannon_photo_contest-field_hannon_zip_code'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_hannon_zip_code',
    'label' => 'Zip Code',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'max' => 99999,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_school_show_student'.
  $field_instances['entityform-hannon_photo_contest-field_school_show_student'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_show_student',
    'label' => 'Show?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'entityform-hannon_photo_contest-field_school_teachers_email'.
  $field_instances['entityform-hannon_photo_contest-field_school_teachers_email'] = array(
    'bundle' => 'hannon_photo_contest',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Your email can only be used once to submit a photo. Only one photo per student may be submitted per contest rules.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_teachers_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_attach_letter_of_recommend'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_attach_letter_of_recommend'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_attach_letter_of_recommend',
    'label' => 'Attach Letter of Recommendation',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt doc docx pdf',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => '',
        ),
        'redirect' => 0,
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '100 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_45x45' => 0,
          'image_60x60' => 0,
          'image_80x60' => 0,
          'image_160x160' => 0,
          'image_200x125' => 0,
          'image_280x280' => 0,
          'image_360x200' => 0,
          'image_380x215' => 0,
          'image_400x240' => 0,
          'image_440x230' => 0,
          'image_680x510' => 0,
          'image_760x377' => 0,
          'image_1280x510' => 0,
          'image_1346x330' => 0,
          'image_embed_landscape_400x225' => 0,
          'image_embed_portrait_225x345' => 0,
          'image_large' => 0,
          'image_large_retina' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_medium_retina' => 0,
          'image_retina_100x100' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_thumbnail_retina' => 0,
          'image_user_dashboard_100x100' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_attach_statement_from_stud'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_attach_statement_from_stud'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '(brief statement, max 500 words)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 10,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_attach_statement_from_stud',
    'label' => 'Attach statement from student about an accomplishment they’ve had and why it is important',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt doc docx pdf',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => 'students/earthday/[current-date:custom:Y]',
        ),
        'redirect' => 0,
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '100 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_45x45' => 0,
          'image_60x60' => 0,
          'image_80x60' => 0,
          'image_160x160' => 0,
          'image_200x125' => 0,
          'image_280x280' => 0,
          'image_360x200' => 0,
          'image_380x215' => 0,
          'image_400x240' => 0,
          'image_440x230' => 0,
          'image_680x510' => 0,
          'image_760x377' => 0,
          'image_1280x510' => 0,
          'image_1346x330' => 0,
          'image_embed_landscape_400x225' => 0,
          'image_embed_portrait_225x345' => 0,
          'image_large' => 0,
          'image_large_retina' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_medium_retina' => 0,
          'image_retina_100x100' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_thumbnail_retina' => 0,
          'image_user_dashboard_100x100' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_category_being_nominated_f'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_category_being_nominated_f'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_category_being_nominated_f',
    'label' => 'Category Being Nominated for',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_cumulatve_gpa'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_cumulatve_gpa'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_cumulatve_gpa',
    'label' => 'Cumulative GPA',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_nominators_email'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_nominators_email'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_nominators_email',
    'label' => 'Nominator\'s Email',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_nominators_name'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_nominators_name'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_nominators_name',
    'label' => 'Nominator\'s Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_nominators_phone_number'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_nominators_phone_number'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_nominators_phone_number',
    'label' => 'Nominator\'s Phone Number',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_nominators_title'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_nominators_title'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_nominators_title',
    'label' => 'Nominator\'s Title',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_school'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_school'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Start typing your school\'s name and choose from list. If your school does not show up, <a href="/webforms/school-not-showing-contact-form">please contact us</a>.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => 0,
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school',
    'label' => 'School',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_student_address'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_student_address'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_student_address',
    'label' => 'Student Address',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_student_email'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_student_email'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_student_email',
    'label' => 'Student Email',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_student_grade'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_student_grade'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_student_grade',
    'label' => 'Student Grade',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_student_name'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_student_name'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_student_name',
    'label' => 'Student Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'entityform-new_york_senate_youth_leadership-field_student_phone_number'.
  $field_instances['entityform-new_york_senate_youth_leadership-field_student_phone_number'] = array(
    'bundle' => 'new_york_senate_youth_leadership',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_student_phone_number',
    'label' => 'Student Phone Number',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_district'.
  $field_instances['entityform-participatory_budgeting-field_district'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_district',
    'label' => 'District',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbpudg_volunteer'.
  $field_instances['entityform-participatory_budgeting-field_pbpudg_volunteer'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbpudg_volunteer',
    'label' => 'Yes! I would like to sign up to be a neighborhood organizer.',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_approval_status'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_approval_status'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 'pending',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_approval_status',
    'label' => 'Approval Status',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_category'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_category'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_category',
    'label' => 'Project Category',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_email'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_email'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_plain',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_first_name'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_first_name'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_first_name',
    'label' => 'First Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 30,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_guestimate'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_guestimate'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Only projects under $1 million are eligible for funding. [Enter only numbers; commas and decimals are not allowed in this field].',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 1,
          'scale' => 0,
          'thousand_separator' => ',',
        ),
        'type' => 'number_integer',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_guestimate',
    'label' => 'Initial Budget Guestimate',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'max' => '',
      'min' => '',
      'prefix' => '$',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_last_name'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_last_name'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_last_name',
    'label' => 'Last Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 30,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_mailing_address'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_mailing_address'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'location_settings' => array(
          'display' => array(
            'hide' => array(
              'additional' => 0,
              'city' => 'city',
              'contact_name' => 'contact_name',
              'coords' => 'coords',
              'country' => 'country',
              'country_name' => 'country_name',
              'email' => 'email',
              'fax' => 'fax',
              'locpick' => 'locpick',
              'map_link' => 'map_link',
              'name' => 'name',
              'phone' => 'phone',
              'postal_code' => 0,
              'province' => 'province',
              'province_name' => 'province_name',
              'street' => 0,
            ),
          ),
          'form' => array(
            'fields' => array(
              'additional' => array(
                '#parents' => array(
                  0 => 'field_pbudg_mailing_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => 6,
              ),
              'city' => array(
                '#parents' => array(
                  0 => 'field_pbudg_mailing_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'Brooklyn',
                'weight' => 8,
              ),
              'contact_name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 25,
              ),
              'country' => array(
                '#parents' => array(
                  0 => 'field_pbudg_mailing_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'us',
                'weight' => 14,
              ),
              'delete_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'email' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 25,
              ),
              'fax' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 30,
              ),
              'is_primary' => array(
                'default' => 0,
              ),
              'latitude' => array(
                'default' => 0,
              ),
              'lid' => array(
                'default' => FALSE,
              ),
              'locpick' => array(
                'collect' => 0,
                'default' => FALSE,
                'nodiff' => TRUE,
                'weight' => 20,
              ),
              'longitude' => array(
                'default' => 0,
              ),
              'name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 2,
              ),
              'phone' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 25,
              ),
              'postal_code' => array(
                '#parents' => array(
                  0 => 'field_pbudg_mailing_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => 12,
              ),
              'province' => array(
                '#parents' => array(
                  0 => 'field_pbudg_mailing_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'New York',
                'weight' => 10,
                'widget' => 'select',
              ),
              're_geocode_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'source' => array(
                'default' => 0,
              ),
              'street' => array(
                '#parents' => array(
                  0 => 'field_pbudg_mailing_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => 4,
              ),
            ),
          ),
        ),
        'street' => '',
        'additional' => '',
        'city' => 'Brooklyn',
        'province' => 'NY',
        'postal_code' => '',
        'country' => 'us',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'location_cck',
        'settings' => array(),
        'type' => 'location_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_mailing_address',
    'label' => 'Mailing Address',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'location_cck',
      'settings' => array(),
      'type' => 'location',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_neighborhood'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_neighborhood'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_neighborhood',
    'label' => 'Neighborhood',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_phone'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_phone'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_phone',
    'label' => 'Phone',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 30,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_project_description'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_project_description'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_project_description',
    'label' => 'Project Description',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_project_location'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_project_location'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'location_settings' => array(
          'display' => array(
            'hide' => array(
              'additional' => 0,
              'city' => 0,
              'contact_name' => 0,
              'coords' => 'coords',
              'country' => 'country',
              'country_name' => 0,
              'email' => 0,
              'fax' => 0,
              'locpick' => 'locpick',
              'map_link' => 0,
              'name' => 0,
              'phone' => 0,
              'postal_code' => 0,
              'province' => 0,
              'province_name' => 0,
              'street' => 0,
            ),
          ),
          'form' => array(
            'fields' => array(
              'additional' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 6,
              ),
              'city' => array(
                '#parents' => array(
                  0 => 'field_pbudg_project_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => 'Brooklyn',
                'weight' => 8,
              ),
              'contact_name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 25,
              ),
              'country' => array(
                '#parents' => array(
                  0 => 'field_pbudg_project_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'us',
                'weight' => 14,
              ),
              'delete_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'email' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 25,
              ),
              'fax' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 30,
              ),
              'is_primary' => array(
                'default' => 0,
              ),
              'latitude' => array(
                'default' => 0,
              ),
              'lid' => array(
                'default' => FALSE,
              ),
              'locpick' => array(
                '#parents' => array(
                  0 => 'field_pbudg_project_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => FALSE,
                'nodiff' => TRUE,
                'weight' => 20,
              ),
              'longitude' => array(
                'default' => 0,
              ),
              'name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 2,
              ),
              'phone' => array(
                'collect' => 0,
                'default' => '',
                'weight' => 25,
              ),
              'postal_code' => array(
                '#parents' => array(
                  0 => 'field_pbudg_project_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => 12,
              ),
              'province' => array(
                '#parents' => array(
                  0 => 'field_pbudg_project_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'New York',
                'weight' => 10,
                'widget' => 'select',
              ),
              're_geocode_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'source' => array(
                'default' => 0,
              ),
              'street' => array(
                '#parents' => array(
                  0 => 'field_pbudg_project_location',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => 4,
              ),
            ),
          ),
        ),
        'street' => '',
        'city' => 'Brooklyn',
        'province' => 'NY',
        'postal_code' => '',
        'country' => 'us',
        'locpick' => array(
          'user_latitude' => '',
          'user_longitude' => '',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => 'Make sure to click the "Find Address on Map" button to properly map the location. If you change the address after clicking the button, you will need to click again to reset the new address. The form will not submit unless this button is clicked.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'location_cck',
        'settings' => array(),
        'type' => 'location_all',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_project_location',
    'label' => 'Project Location',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'location_cck',
      'settings' => array(),
      'type' => 'location',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_project_name'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_project_name'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_project_name',
    'label' => 'Project Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'entityform-participatory_budgeting-field_pbudg_submit_project'.
  $field_instances['entityform-participatory_budgeting-field_pbudg_submit_project'] = array(
    'bundle' => 'participatory_budgeting',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_pbudg_submit_project',
    'label' => 'Submit Project',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'entityform-school_submissions-field_school_contact_email'.
  $field_instances['entityform-school_submissions-field_school_contact_email'] = array(
    'bundle' => 'school_submissions',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_contact_email',
    'label' => 'Contact Email',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'entityform-school_submissions-field_school_contact_name'.
  $field_instances['entityform-school_submissions-field_school_contact_name'] = array(
    'bundle' => 'school_submissions',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_contact_name',
    'label' => 'Contact Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'entityform-school_submissions-field_school_grade'.
  $field_instances['entityform-school_submissions-field_school_grade'] = array(
    'bundle' => 'school_submissions',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_grade',
    'label' => 'Grade',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'entityform-school_submissions-field_school_name'.
  $field_instances['entityform-school_submissions-field_school_name'] = array(
    'bundle' => 'school_submissions',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Start typing your school\'s name and choose from list. If your school does not show up, <a href="/webforms/school-not-showing-contact-form">please contact us</a>.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => 0,
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_name',
    'label' => 'School Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'entityform-school_submissions-field_school_student_submissions'.
  $field_instances['entityform-school_submissions-field_school_student_submissions'] = array(
    'bundle' => 'school_submissions',
    'custom_add_another' => 'Add another student',
    'custom_remove' => 'Remove this student',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_school_student_submissions',
    'label' => 'Student Submissions',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'entityform-summer_reading-field_address'.
  $field_instances['entityform-summer_reading-field_address'] = array(
    'bundle' => 'summer_reading',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'location_settings' => array(
          'display' => array(
            'hide' => array(
              'additional' => 0,
              'city' => 0,
              'contact_name' => 'contact_name',
              'coords' => 'coords',
              'country' => 'country',
              'country_name' => 'country_name',
              'email' => 'email',
              'fax' => 'fax',
              'locpick' => 'locpick',
              'map_link' => 'map_link',
              'name' => 'name',
              'phone' => 'phone',
              'postal_code' => 0,
              'province' => 0,
              'province_name' => 'province_name',
              'street' => 0,
            ),
          ),
          'form' => array(
            'fields' => array(
              'additional' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -98,
              ),
              'city' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -97,
              ),
              'contact_name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -93,
              ),
              'country' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'us',
                'weight' => -94,
              ),
              'delete_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'email' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -90,
              ),
              'fax' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -89,
              ),
              'is_primary' => array(
                'default' => 0,
              ),
              'latitude' => array(
                'default' => 0,
              ),
              'lid' => array(
                'default' => FALSE,
              ),
              'locpick' => array(
                'collect' => 0,
                'default' => FALSE,
                'nodiff' => TRUE,
                'weight' => -92,
              ),
              'longitude' => array(
                'default' => 0,
              ),
              'name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -100,
              ),
              'phone' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -91,
              ),
              'postal_code' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -95,
              ),
              'province' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'New York',
                'weight' => -96,
                'widget' => 'select',
              ),
              're_geocode_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'source' => array(
                'default' => 0,
              ),
              'street' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -99,
              ),
            ),
          ),
        ),
        'street' => '',
        'additional' => '',
        'city' => '',
        'province' => '',
        'postal_code' => '',
        'country' => 'us',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'location_cck',
        'settings' => array(),
        'type' => 'location_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_address',
    'label' => 'Address',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'location_cck',
      'settings' => array(),
      'type' => 'location',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'entityform-summer_reading-field_children'.
  $field_instances['entityform-summer_reading-field_children'] = array(
    'bundle' => 'summer_reading',
    'custom_add_another' => 'Add another Child',
    'custom_remove' => 'Remove this Child',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_children',
    'label' => 'Child\'s Information',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'entityform-summer_reading-field_district'.
  $field_instances['entityform-summer_reading-field_district'] = array(
    'bundle' => 'summer_reading',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'use_content_language' => 1,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_district',
    'label' => 'District',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'entityform-summer_reading-field_student_email'.
  $field_instances['entityform-summer_reading-field_student_email'] = array(
    'bundle' => 'summer_reading',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_plain',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_student_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'entityform-summer_reading-field_student_parent_name'.
  $field_instances['entityform-summer_reading-field_student_parent_name'] = array(
    'bundle' => 'summer_reading',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'entityform',
    'field_name' => 'field_student_parent_name',
    'label' => 'Name of Parent or Guardian',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_children-field_school_reading'.
  $field_instances['field_collection_item-field_children-field_school_reading'] = array(
    'bundle' => 'field_children',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Start typing your school\'s name and choose from list. If your school does not show up, <a href="/webforms/school-not-showing-contact-form">please contact us</a>.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => 0,
          'link' => 0,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_reading',
    'label' => 'School',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => 0,
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_children-field_student_books'.
  $field_instances['field_collection_item-field_children-field_student_books'] = array(
    'bundle' => 'field_children',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_student_books',
    'label' => 'Add Three(3) Books Read by your Child this Summer',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_children-field_student_name'.
  $field_instances['field_collection_item-field_children-field_student_name'] = array(
    'bundle' => 'field_children',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the name that will print on certificate from your Senator.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_student_name',
    'label' => 'Student Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_children-field_student_reading_grade'.
  $field_instances['field_collection_item-field_children-field_student_reading_grade'] = array(
    'bundle' => 'field_children',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_student_reading_grade',
    'label' => 'Grade (in Fall 2021)',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_stud_earthday_subm-field_school_show_student'.
  $field_instances['field_collection_item-field_school_stud_earthday_subm-field_school_show_student'] = array(
    'bundle' => 'field_school_stud_earthday_subm',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_show_student',
    'label' => 'Show?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_stud_earthday_subm-field_school_student_full_name'.
  $field_instances['field_collection_item-field_school_stud_earthday_subm-field_school_student_full_name'] = array(
    'bundle' => 'field_school_stud_earthday_subm',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_student_full_name',
    'label' => 'Student\'s Full Name',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'advanced_html' => 'advanced_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'advanced_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_stud_earthday_subm-field_school_submission_upload'.
  $field_instances['field_collection_item-field_school_stud_earthday_subm-field_school_submission_upload'] = array(
    'bundle' => 'field_school_stud_earthday_subm',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'teaser',
        ),
        'type' => 'file_rendered',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_submission_upload',
    'label' => 'Attach your submission',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'gif jpg png pdf jpeg',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 1,
            'slashes' => 0,
            'transliterate' => 1,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 1,
            'slashes' => 0,
            'transliterate' => 1,
          ),
          'value' => 'students/earthday/[current-date:custom:Y]',
        ),
        'redirect' => 0,
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '10 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_45x45' => 0,
          'image_45x45_phone' => 0,
          'image_45x45_phone_retina' => 0,
          'image_45x45_phone_webp' => 0,
          'image_45x45_phone_webp_retina' => 0,
          'image_60x60' => 0,
          'image_60x60_phone' => 0,
          'image_60x60_phone_retina' => 0,
          'image_60x60_phone_webp' => 0,
          'image_60x60_phone_webp_retina' => 0,
          'image_80x60' => 0,
          'image_160x160' => 0,
          'image_160x160_phone' => 0,
          'image_160x160_phone_retina' => 0,
          'image_160x160_phone_webp' => 0,
          'image_160x160_phone_webp_retina' => 0,
          'image_200x125' => 0,
          'image_280x280' => 0,
          'image_360x200' => 0,
          'image_380x215' => 0,
          'image_400x240' => 0,
          'image_400x240_phone' => 0,
          'image_400x240_phone_retina' => 0,
          'image_400x240_phone_webp' => 0,
          'image_400x240_phone_webp_retina' => 0,
          'image_400x240_smartphone' => 0,
          'image_400x240_smartphone_retina' => 0,
          'image_400x240_smartphone_webp' => 0,
          'image_400x240_smartphone_webp_retina' => 0,
          'image_440x230' => 0,
          'image_680x510' => 0,
          'image_760x' => 0,
          'image_760x377' => 0,
          'image_1280x510' => 0,
          'image_1346x330' => 0,
          'image_base' => 0,
          'image_embed_landscape' => 0,
          'image_embed_landscape_400x225' => 0,
          'image_embed_landscape_smartphone' => 0,
          'image_embed_landscape_smartphone_retina' => 0,
          'image_embed_landscape_smartphone_webp' => 0,
          'image_embed_landscape_smartphone_webp_retina' => 0,
          'image_embed_portrait' => 0,
          'image_embed_portrait_225x345' => 0,
          'image_embed_portrait_smartphone' => 0,
          'image_embed_portrait_smartphone_retina' => 0,
          'image_embed_portrait_smartphone_webp' => 0,
          'image_embed_portrait_smartphone_webp_retina' => 0,
          'image_embed_signature' => 0,
          'image_embed_signature_smartphone' => 0,
          'image_embed_signature_smartphone_retina' => 0,
          'image_embed_signature_smartphone_webp' => 0,
          'image_embed_signature_smartphone_webp_retina' => 0,
          'image_embed_square' => 0,
          'image_embed_square_smartphone' => 0,
          'image_embed_square_smartphone_retina' => 0,
          'image_embed_square_smartphone_webp' => 0,
          'image_embed_square_smartphone_webp_retina' => 0,
          'image_hero_680x510_phone' => 0,
          'image_hero_680x510_phone_retina' => 0,
          'image_hero_680x510_phone_webp' => 0,
          'image_hero_680x510_phone_webp_retina' => 0,
          'image_hero_680x510_small_tablet' => 0,
          'image_hero_680x510_small_tablet_retina' => 0,
          'image_hero_680x510_small_tablet_webp' => 0,
          'image_hero_680x510_small_tablet_webp_retina' => 0,
          'image_hero_680x510_smartphone' => 0,
          'image_hero_680x510_smartphone_retina' => 0,
          'image_hero_680x510_smartphone_webp' => 0,
          'image_hero_680x510_smartphone_webp_retina' => 0,
          'image_hero_1346x330_desktop' => 0,
          'image_hero_1346x330_desktop_retina' => 0,
          'image_hero_1346x330_desktop_webp' => 0,
          'image_hero_1346x330_desktop_webp_retina' => 0,
          'image_hero_1346x330_phone' => 0,
          'image_hero_1346x330_phone_retina' => 0,
          'image_hero_1346x330_phone_webp' => 0,
          'image_hero_1346x330_phone_webp_retina' => 0,
          'image_hero_1346x330_small_tablet' => 0,
          'image_hero_1346x330_small_tablet_retina' => 0,
          'image_hero_1346x330_small_tablet_webp' => 0,
          'image_hero_1346x330_small_tablet_webp_retina' => 0,
          'image_hero_1346x330_smartphone' => 0,
          'image_hero_1346x330_smartphone_retina' => 0,
          'image_hero_1346x330_smartphone_webp' => 0,
          'image_hero_1346x330_smartphone_webp_retina' => 0,
          'image_hero_1346x330_tablet' => 0,
          'image_hero_1346x330_tablet_retina' => 0,
          'image_hero_1346x330_tablet_webp' => 0,
          'image_hero_1346x330_tablet_webp_retina' => 0,
          'image_hero_1346x330_wide' => 0,
          'image_hero_1346x330_wide_retina' => 0,
          'image_hero_1346x330_wide_webp' => 0,
          'image_hero_1346x330_wide_webp_retina' => 0,
          'image_large' => 0,
          'image_main_200x125_phone' => 0,
          'image_main_200x125_phone_retina' => 0,
          'image_main_200x125_phone_webp' => 0,
          'image_main_200x125_phone_webp_retina' => 0,
          'image_main_280x280_phone' => 0,
          'image_main_280x280_phone_retina' => 0,
          'image_main_280x280_phone_webp' => 0,
          'image_main_280x280_phone_webp_retina' => 0,
          'image_main_360x200_phone' => 0,
          'image_main_360x200_phone_retina' => 0,
          'image_main_360x200_phone_webp' => 0,
          'image_main_360x200_phone_webp_retina' => 0,
          'image_main_360x200_smartphone' => 0,
          'image_main_360x200_smartphone_retina' => 0,
          'image_main_360x200_smartphone_webp' => 0,
          'image_main_360x200_smartphone_webp_retina' => 0,
          'image_main_380x215_phone' => 0,
          'image_main_380x215_phone_retina' => 0,
          'image_main_380x215_phone_webp' => 0,
          'image_main_380x215_phone_webp_retina' => 0,
          'image_main_380x215_smartphone' => 0,
          'image_main_380x215_smartphone_retina' => 0,
          'image_main_380x215_smartphone_webp' => 0,
          'image_main_380x215_smartphone_webp_retina' => 0,
          'image_main_760x377_phone' => 0,
          'image_main_760x377_phone_retina' => 0,
          'image_main_760x377_phone_webp' => 0,
          'image_main_760x377_phone_webp_retina' => 0,
          'image_main_760x377_small_tablet' => 0,
          'image_main_760x377_small_tablet_retina' => 0,
          'image_main_760x377_small_tablet_webp' => 0,
          'image_main_760x377_small_tablet_webp_retina' => 0,
          'image_main_760x377_smartphone' => 0,
          'image_main_760x377_smartphone_retina' => 0,
          'image_main_760x377_smartphone_webp' => 0,
          'image_main_760x377_smartphone_webp_retina' => 0,
          'image_main_760x_phone' => 0,
          'image_main_760x_phone_retina' => 0,
          'image_main_760x_phone_webp' => 0,
          'image_main_760x_phone_webp_retina' => 0,
          'image_main_760x_small_tablet' => 0,
          'image_main_760x_small_tablet_retina' => 0,
          'image_main_760x_small_tablet_webp' => 0,
          'image_main_760x_small_tablet_webp_retina' => 0,
          'image_main_760x_smartphone' => 0,
          'image_main_760x_smartphone_retina' => 0,
          'image_main_760x_smartphone_webp' => 0,
          'image_main_760x_smartphone_webp_retina' => 0,
          'image_main_1280x510_desktop' => 0,
          'image_main_1280x510_desktop_retina' => 0,
          'image_main_1280x510_desktop_webp' => 0,
          'image_main_1280x510_desktop_webp_retina' => 0,
          'image_main_1280x510_phone' => 0,
          'image_main_1280x510_phone_retina' => 0,
          'image_main_1280x510_phone_webp' => 0,
          'image_main_1280x510_phone_webp_retina' => 0,
          'image_main_1280x510_small_tablet' => 0,
          'image_main_1280x510_small_tablet_retina' => 0,
          'image_main_1280x510_small_tablet_webp' => 0,
          'image_main_1280x510_small_tablet_webp_retina' => 0,
          'image_main_1280x510_smartphone' => 0,
          'image_main_1280x510_smartphone_retina' => 0,
          'image_main_1280x510_smartphone_webp' => 0,
          'image_main_1280x510_smartphone_webp_retina' => 0,
          'image_main_1280x510_tablet' => 0,
          'image_main_1280x510_tablet_retina' => 0,
          'image_main_1280x510_tablet_webp' => 0,
          'image_main_1280x510_tablet_webp_retina' => 0,
          'image_main_1280x510_wide' => 0,
          'image_main_1280x510_wide_retina' => 0,
          'image_main_1280x510_wide_webp' => 0,
          'image_main_1280x510_wide_webp_retina' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_retina_100x100' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_user_dashboard_100x100' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_stud_earthday_subm-field_year'.
  $field_instances['field_collection_item-field_school_stud_earthday_subm-field_year'] = array(
    'bundle' => 'field_school_stud_earthday_subm',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_year',
    'label' => 'Year',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'Y M j - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'none',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-1:+0',
      ),
      'type' => 'date_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_student_submissions-field_school_show_student'.
  $field_instances['field_collection_item-field_school_student_submissions-field_school_show_student'] = array(
    'bundle' => 'field_school_student_submissions',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_show_student',
    'label' => 'Show?',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_student_submissions-field_school_student_full_name'.
  $field_instances['field_collection_item-field_school_student_submissions-field_school_student_full_name'] = array(
    'bundle' => 'field_school_student_submissions',
    'custom_add_another' => '',
    'custom_remove' => '',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Student\'s last name is optional.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_student_full_name',
    'label' => 'Student\'s Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_student_submissions-field_school_submission_type'.
  $field_instances['field_collection_item-field_school_student_submissions-field_school_submission_type'] = array(
    'bundle' => 'field_school_student_submissions',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_submission_type',
    'label' => 'My submission could best be described as',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_school_student_submissions-field_school_submission_upload'.
  $field_instances['field_collection_item-field_school_student_submissions-field_school_submission_upload'] = array(
    'bundle' => 'field_school_student_submissions',
    'custom_add_another' => '',
    'custom_remove' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'file_rendered',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_submission_upload',
    'label' => 'Attach your submission',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt png jpg jpeg pdf doc docx',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 1,
            'slashes' => 0,
            'transliterate' => 1,
          ),
          'value' => 'students/thanksgiving/[current-date:custom:Y]',
        ),
        'redirect' => 0,
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '10 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'icon_link' => 0,
          'image' => 0,
          'image_45x45' => 0,
          'image_45x45_phone' => 0,
          'image_45x45_phone_retina' => 0,
          'image_45x45_phone_webp' => 0,
          'image_45x45_phone_webp_retina' => 0,
          'image_60x60' => 0,
          'image_60x60_phone' => 0,
          'image_60x60_phone_retina' => 0,
          'image_60x60_phone_webp' => 0,
          'image_60x60_phone_webp_retina' => 0,
          'image_80x60' => 0,
          'image_160x160' => 0,
          'image_160x160_phone' => 0,
          'image_160x160_phone_retina' => 0,
          'image_160x160_phone_webp' => 0,
          'image_160x160_phone_webp_retina' => 0,
          'image_200x125' => 0,
          'image_280x280' => 0,
          'image_360x200' => 0,
          'image_380x215' => 0,
          'image_400x240' => 0,
          'image_400x240_phone' => 0,
          'image_400x240_phone_retina' => 0,
          'image_400x240_phone_webp' => 0,
          'image_400x240_phone_webp_retina' => 0,
          'image_400x240_smartphone' => 0,
          'image_400x240_smartphone_retina' => 0,
          'image_400x240_smartphone_webp' => 0,
          'image_400x240_smartphone_webp_retina' => 0,
          'image_440x230' => 0,
          'image_680x510' => 0,
          'image_760x' => 0,
          'image_760x377' => 0,
          'image_1280x510' => 0,
          'image_1346x330' => 0,
          'image_base' => 0,
          'image_embed_landscape' => 0,
          'image_embed_landscape_400x225' => 0,
          'image_embed_landscape_smartphone' => 0,
          'image_embed_landscape_smartphone_retina' => 0,
          'image_embed_landscape_smartphone_webp' => 0,
          'image_embed_landscape_smartphone_webp_retina' => 0,
          'image_embed_portrait' => 0,
          'image_embed_portrait_225x345' => 0,
          'image_embed_portrait_smartphone' => 0,
          'image_embed_portrait_smartphone_retina' => 0,
          'image_embed_portrait_smartphone_webp' => 0,
          'image_embed_portrait_smartphone_webp_retina' => 0,
          'image_embed_signature' => 0,
          'image_embed_signature_smartphone' => 0,
          'image_embed_signature_smartphone_retina' => 0,
          'image_embed_signature_smartphone_webp' => 0,
          'image_embed_signature_smartphone_webp_retina' => 0,
          'image_embed_square' => 0,
          'image_embed_square_smartphone' => 0,
          'image_embed_square_smartphone_retina' => 0,
          'image_embed_square_smartphone_webp' => 0,
          'image_embed_square_smartphone_webp_retina' => 0,
          'image_hero_680x510_phone' => 0,
          'image_hero_680x510_phone_retina' => 0,
          'image_hero_680x510_phone_webp' => 0,
          'image_hero_680x510_phone_webp_retina' => 0,
          'image_hero_680x510_small_tablet' => 0,
          'image_hero_680x510_small_tablet_retina' => 0,
          'image_hero_680x510_small_tablet_webp' => 0,
          'image_hero_680x510_small_tablet_webp_retina' => 0,
          'image_hero_680x510_smartphone' => 0,
          'image_hero_680x510_smartphone_retina' => 0,
          'image_hero_680x510_smartphone_webp' => 0,
          'image_hero_680x510_smartphone_webp_retina' => 0,
          'image_hero_1346x330_desktop' => 0,
          'image_hero_1346x330_desktop_retina' => 0,
          'image_hero_1346x330_desktop_webp' => 0,
          'image_hero_1346x330_desktop_webp_retina' => 0,
          'image_hero_1346x330_phone' => 0,
          'image_hero_1346x330_phone_retina' => 0,
          'image_hero_1346x330_phone_webp' => 0,
          'image_hero_1346x330_phone_webp_retina' => 0,
          'image_hero_1346x330_small_tablet' => 0,
          'image_hero_1346x330_small_tablet_retina' => 0,
          'image_hero_1346x330_small_tablet_webp' => 0,
          'image_hero_1346x330_small_tablet_webp_retina' => 0,
          'image_hero_1346x330_smartphone' => 0,
          'image_hero_1346x330_smartphone_retina' => 0,
          'image_hero_1346x330_smartphone_webp' => 0,
          'image_hero_1346x330_smartphone_webp_retina' => 0,
          'image_hero_1346x330_tablet' => 0,
          'image_hero_1346x330_tablet_retina' => 0,
          'image_hero_1346x330_tablet_webp' => 0,
          'image_hero_1346x330_tablet_webp_retina' => 0,
          'image_hero_1346x330_wide' => 0,
          'image_hero_1346x330_wide_retina' => 0,
          'image_hero_1346x330_wide_webp' => 0,
          'image_hero_1346x330_wide_webp_retina' => 0,
          'image_large' => 0,
          'image_main_200x125_phone' => 0,
          'image_main_200x125_phone_retina' => 0,
          'image_main_200x125_phone_webp' => 0,
          'image_main_200x125_phone_webp_retina' => 0,
          'image_main_280x280_phone' => 0,
          'image_main_280x280_phone_retina' => 0,
          'image_main_280x280_phone_webp' => 0,
          'image_main_280x280_phone_webp_retina' => 0,
          'image_main_360x200_phone' => 0,
          'image_main_360x200_phone_retina' => 0,
          'image_main_360x200_phone_webp' => 0,
          'image_main_360x200_phone_webp_retina' => 0,
          'image_main_360x200_smartphone' => 0,
          'image_main_360x200_smartphone_retina' => 0,
          'image_main_360x200_smartphone_webp' => 0,
          'image_main_360x200_smartphone_webp_retina' => 0,
          'image_main_380x215_phone' => 0,
          'image_main_380x215_phone_retina' => 0,
          'image_main_380x215_phone_webp' => 0,
          'image_main_380x215_phone_webp_retina' => 0,
          'image_main_380x215_smartphone' => 0,
          'image_main_380x215_smartphone_retina' => 0,
          'image_main_380x215_smartphone_webp' => 0,
          'image_main_380x215_smartphone_webp_retina' => 0,
          'image_main_760x377_phone' => 0,
          'image_main_760x377_phone_retina' => 0,
          'image_main_760x377_phone_webp' => 0,
          'image_main_760x377_phone_webp_retina' => 0,
          'image_main_760x377_small_tablet' => 0,
          'image_main_760x377_small_tablet_retina' => 0,
          'image_main_760x377_small_tablet_webp' => 0,
          'image_main_760x377_small_tablet_webp_retina' => 0,
          'image_main_760x377_smartphone' => 0,
          'image_main_760x377_smartphone_retina' => 0,
          'image_main_760x377_smartphone_webp' => 0,
          'image_main_760x377_smartphone_webp_retina' => 0,
          'image_main_760x_phone' => 0,
          'image_main_760x_phone_retina' => 0,
          'image_main_760x_phone_webp' => 0,
          'image_main_760x_phone_webp_retina' => 0,
          'image_main_760x_small_tablet' => 0,
          'image_main_760x_small_tablet_retina' => 0,
          'image_main_760x_small_tablet_webp' => 0,
          'image_main_760x_small_tablet_webp_retina' => 0,
          'image_main_760x_smartphone' => 0,
          'image_main_760x_smartphone_retina' => 0,
          'image_main_760x_smartphone_webp' => 0,
          'image_main_760x_smartphone_webp_retina' => 0,
          'image_main_1280x510_desktop' => 0,
          'image_main_1280x510_desktop_retina' => 0,
          'image_main_1280x510_desktop_webp' => 0,
          'image_main_1280x510_desktop_webp_retina' => 0,
          'image_main_1280x510_phone' => 0,
          'image_main_1280x510_phone_retina' => 0,
          'image_main_1280x510_phone_webp' => 0,
          'image_main_1280x510_phone_webp_retina' => 0,
          'image_main_1280x510_small_tablet' => 0,
          'image_main_1280x510_small_tablet_retina' => 0,
          'image_main_1280x510_small_tablet_webp' => 0,
          'image_main_1280x510_small_tablet_webp_retina' => 0,
          'image_main_1280x510_smartphone' => 0,
          'image_main_1280x510_smartphone_retina' => 0,
          'image_main_1280x510_smartphone_webp' => 0,
          'image_main_1280x510_smartphone_webp_retina' => 0,
          'image_main_1280x510_tablet' => 0,
          'image_main_1280x510_tablet_retina' => 0,
          'image_main_1280x510_tablet_webp' => 0,
          'image_main_1280x510_tablet_webp_retina' => 0,
          'image_main_1280x510_wide' => 0,
          'image_main_1280x510_wide_retina' => 0,
          'image_main_1280x510_wide_webp' => 0,
          'image_main_1280x510_wide_webp_retina' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_retina_100x100' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'image_user_dashboard_100x100' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(brief statement, max 500 words)');
  t('Add Three(3) Books Read by your Child this Summer');
  t('Address');
  t('Agreement');
  t('Approval Status');
  t('Attach Letter of Recommendation');
  t('Attach statement from student about an accomplishment they’ve had and why it is important');
  t('Attach your photo');
  t('Attach your submission');
  t('Category');
  t('Category Being Nominated for');
  t('Child\'s Information');
  t('City');
  t('Contact Email');
  t('Contact Name');
  t('Cumulative GPA');
  t('District');
  t('District Status');
  t('Email');
  t('First Name');
  t('Grade');
  t('Grade (in Fall 2021)');
  t('If your school is not listed, please call: 516-739-1700');
  t('Initial Budget Guestimate');
  t('Last Name');
  t('Mailing Address');
  t('Make sure to click the "Find Address on Map" button to properly map the location. If you change the address after clicking the button, you will need to click again to reset the new address. The form will not submit unless this button is clicked.');
  t('My submission could best be described as');
  t('Name of Parent or Guardian');
  t('Neighborhood');
  t('Nominator\'s Email');
  t('Nominator\'s Name');
  t('Nominator\'s Phone Number');
  t('Nominator\'s Title');
  t('Only projects under $1 million are eligible for funding. [Enter only numbers; commas and decimals are not allowed in this field].');
  t('Phone');
  t('Phone Number');
  t('Project Category');
  t('Project Description');
  t('Project Location');
  t('Project Name');
  t('School');
  t('School Name');
  t('Show?');
  t('Star Rating');
  t('Start typing your school\'s name and choose from list (you must CLICK ON NAME in drop down). If your school does not show up, <a href="/webforms/school-not-showing-contact-form">please contact us</a>.');
  t('Start typing your school\'s name and choose from list. If your school does not show up, <a href="/webforms/school-not-showing-contact-form">please contact us</a>.');
  t('Street Address');
  t('Student Address');
  t('Student Email');
  t('Student Grade');
  t('Student Name');
  t('Student Phone Number');
  t('Student Submissions');
  t('Student\'s Full Name');
  t('Student\'s Name');
  t('Student\'s last name is optional.');
  t('Submit Project');
  t('Teacher\'s Email');
  t('Teacher\'s Name');
  t('This is the name that will print on certificate from your Senator.');
  t('Winner Types');
  t('Year');
  t('Yes! I would like to sign up to be a neighborhood organizer.');
  t('Your email can only be used once to submit a photo. Only one photo per student may be submitted per contest rules.');
  t('Zip Code');

  return $field_instances;
}
