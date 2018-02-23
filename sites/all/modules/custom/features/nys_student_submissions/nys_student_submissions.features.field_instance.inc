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
    'description' => 'Start typing your school\'s name and choose from list. If your school does not show up, <a href="/webforms/school-not-showing-contact-form">please contact us</a>.',
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
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
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

  // Exported field_instance:
  // 'field_collection_item-field_school_stud_earthday_subm-field_school_featured_entry'.
  $field_instances['field_collection_item-field_school_stud_earthday_subm-field_school_featured_entry'] = array(
    'bundle' => 'field_school_stud_earthday_subm',
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
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_school_featured_entry',
    'label' => 'Poster Winner?',
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
      'weight' => 4,
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
      'weight' => 1,
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
      'file_extensions' => 'gif jpg png pdf',
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
      'max_filesize' => '4 MB',
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
      'weight' => 2,
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
      'weight' => 5,
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
      'max_filesize' => '',
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(brief statement, max 500 words)');
  t('Agreement');
  t('Attach Letter of Recommendation');
  t('Attach statement from student about an accomplishment they’ve had and why it is important');
  t('Attach your photo');
  t('Attach your submission');
  t('Category');
  t('Category Being Nominated for');
  t('City');
  t('Contact Email');
  t('Contact Name');
  t('Cumulative GPA');
  t('Email');
  t('First Name');
  t('Grade');
  t('If your school is not listed, please call: 516-739-1700');
  t('Last Name');
  t('My submission could best be described as');
  t('Nominator\'s Email');
  t('Nominator\'s Name');
  t('Nominator\'s Phone Number');
  t('Nominator\'s Title');
  t('Phone Number');
  t('Poster Winner?');
  t('School');
  t('School Name');
  t('Show?');
  t('Star Rating');
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
  t('Teacher\'s Email');
  t('Teacher\'s Name');
  t('Winner Types');
  t('Year');
  t('Your email can only be used once to submit a photo. Only one photo per student may be submitted per contest rules.');
  t('Zip Code');

  return $field_instances;
}
