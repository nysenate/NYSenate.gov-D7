<?php
/**
 * @file
 * nys_senators.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_senators_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_page|node|senator|form';
  $field_group->group_name = 'group_about_page';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About Page',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_chapters',
      2 => 'field_image_main',
      3 => 'field_pull_quote',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about-page field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autoreply|node|senator|form';
  $field_group->group_name = 'group_autoreply';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Auto-Reply Settings',
    'weight' => '8',
    'children' => array(
      0 => 'field_autoreply_text',
      1 => 'field_email_autoreply_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-autoreply field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|senator|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Page',
    'weight' => '6',
    'children' => array(
      0 => 'field_email',
      1 => 'field_press_inquiries',
      2 => 'group_key_staff',
      3 => 'group_office_addresses',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_direct_messages|node|senator|form';
  $field_group->group_name = 'group_direct_messages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Direct Messaging',
    'weight' => '7',
    'children' => array(
      0 => 'field_user_account',
      1 => 'field_message_notification_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-direct-messages field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_key_staff|node|senator|form';
  $field_group->group_name = 'group_key_staff';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Key Staff',
    'weight' => '9',
    'children' => array(
      0 => 'field_office_contacts',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-key-staff field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_legislation|node|senator|form';
  $field_group->group_name = 'group_legislation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Legislation Page',
    'weight' => '5',
    'children' => array(
      0 => 'field_featured_legislation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-legislation field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_microsite_settings|node|senator|form';
  $field_group->group_name = 'group_microsite_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Microsite Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_pallette_selector',
      1 => 'field_image_hero',
      2 => 'field_top_issue',
      3 => 'group_social_media_links',
      4 => 'group_promo_banners',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-microsite-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_newsroom|node|senator|form';
  $field_group->group_name = 'group_newsroom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Newsroom Page',
    'weight' => '4',
    'children' => array(
      0 => 'field_press_kit',
      1 => 'field_media_inquiries',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-newsroom field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_office_addresses|node|senator|form';
  $field_group->group_name = 'group_office_addresses';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Office Addresses',
    'weight' => '10',
    'children' => array(
      0 => 'field_offices',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-office-addresses field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_banners|node|senator|form';
  $field_group->group_name = 'group_promo_banners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_microsite_settings';
  $field_group->data = array(
    'label' => 'Promotional Banners',
    'weight' => '41',
    'children' => array(
      0 => 'field_promotional_banners',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo-banners field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_senator_info|node|senator|form';
  $field_group->group_name = 'group_senator_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Senator Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_current_duties',
      1 => 'field_image_headshot',
      2 => 'field_conference',
      3 => 'field_party',
      4 => 'field_first_name',
      5 => 'field_last_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-senator-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_links|node|senator|form';
  $field_group->group_name = 'group_social_media_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_microsite_settings';
  $field_group->data = array(
    'label' => 'Social Media Links',
    'weight' => '40',
    'children' => array(
      0 => 'field_facebook_url',
      1 => 'field_twitter_url',
      2 => 'field_youtube_url',
      3 => 'field_instagram_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-media-links field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_student_letters|node|senator|form';
  $field_group->group_name = 'group_student_letters';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Student Letters',
    'weight' => '9',
    'children' => array(
      0 => 'field_student_earthday_letter',
      1 => 'field_student_thankful_letter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-student-letters field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About Page');
  t('Auto-Reply Settings');
  t('Contact Page');
  t('Direct Messaging');
  t('Key Staff');
  t('Legislation Page');
  t('Microsite Settings');
  t('Newsroom Page');
  t('Office Addresses');
  t('Promotional Banners');
  t('Senator Information');
  t('Social Media Links');
  t('Student Letters');

  return $field_groups;
}
