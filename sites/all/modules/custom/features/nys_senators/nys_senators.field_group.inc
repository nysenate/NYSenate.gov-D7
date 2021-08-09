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
      'label' => 'About Page',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-about-page field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_about_page|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_analytics|node|senator|form';
  $field_group->group_name = 'group_analytics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Constituent Analytics Reporting',
    'weight' => '9',
    'children' => array(
      0 => 'field_analytics_reporting',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Constituent Analytics Reporting',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-analytics field-group-fieldset',
        'description' => 'NYSenate.gov features automated reports of constituent activity on the site, giving members and staff a deeper understanding of the bills, issues, and petitions that their constituents care about. Keep this list updated as staff join and leave the Senator\'s service.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_analytics|node|senator|form'] = $field_group;

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
      'label' => 'Auto-Reply Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-autoreply field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_autoreply|node|senator|form'] = $field_group;

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
      'label' => 'Contact Page',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_contact|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_daily|field_collection_item|field_analytics_reporting|form';
  $field_group->group_name = 'group_daily';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_analytics_reporting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Daily',
    'weight' => '2',
    'children' => array(
      0 => 'field_analytics_daily',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Daily',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-daily',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_daily|field_collection_item|field_analytics_reporting|form'] = $field_group;

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
      'label' => 'Direct Messaging',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-direct-messages field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_direct_messages|node|senator|form'] = $field_group;

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
      'label' => 'Key Staff',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-key-staff field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_key_staff|node|senator|form'] = $field_group;

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
      'label' => 'Legislation Page',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-legislation field-group-fieldset',
        'description' => 'The first bill will show as "Featured" on Senator\'s home page and at top of legislation page. The next 4 will show on Senator\'s home page as more of a list format, and also on Senator\'s legislation page as modified versions of the Featured layout with quotes. All bills added will also show quotes from Senator on the bill node page of Senator sponsored legislation.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_legislation|node|senator|form'] = $field_group;

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
      3 => 'group_promo_banners',
      4 => 'group_social_media_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Microsite Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-microsite-settings field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_microsite_settings|node|senator|form'] = $field_group;

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
      'label' => 'Newsroom Page',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-newsroom field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_newsroom|node|senator|form'] = $field_group;

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
      'label' => 'Office Addresses',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-office-addresses field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_office_addresses|node|senator|form'] = $field_group;

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
      'label' => 'Promotional Banners',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-promo-banners field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_promo_banners|node|senator|form'] = $field_group;

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
      'label' => 'Senator Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-senator-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_senator_info|node|senator|form'] = $field_group;

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
      'label' => 'Social Media Links',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-social-media-links field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_social_media_links|node|senator|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'field_student_earthday_letter',
      1 => 'field_student_thankful_letter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Student Letters',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-student-letters field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_student_letters|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_weekly|field_collection_item|field_analytics_reporting|form';
  $field_group->group_name = 'group_weekly';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_analytics_reporting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Weekly',
    'weight' => '3',
    'children' => array(
      0 => 'field_analytics_weekly',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Weekly',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-weekly',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_weekly|field_collection_item|field_analytics_reporting|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About Page');
  t('Auto-Reply Settings');
  t('Constituent Analytics Reporting');
  t('Contact Page');
  t('Daily');
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
  t('Weekly');

  return $field_groups;
}
