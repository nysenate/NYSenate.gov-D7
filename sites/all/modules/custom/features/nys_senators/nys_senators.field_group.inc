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
  $field_group->identifier = 'group_about_senator|node|senator|form';
  $field_group->group_name = 'group_about_senator';
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
        'classes' => 'group-about-senator field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_about_senator|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|senator|form';
  $field_group->group_name = 'group_about';
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
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_about|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_auto_replies|node|senator|form';
  $field_group->group_name = 'group_auto_replies';
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
        'classes' => 'group-auto-replies field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_auto_replies|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|petition|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Petition Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_image_main',
      1 => 'body',
      2 => 'field_subheading',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content|node|petition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_direct_messaging|node|senator|form';
  $field_group->group_name = 'group_direct_messaging';
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
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_direct_messaging|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discoverability|node|petition|form';
  $field_group->group_name = 'group_discoverability';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discoverability',
    'weight' => '2',
    'children' => array(
      0 => 'field_senator',
      1 => 'field_featured',
      2 => 'field_issues',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-discoverability field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_discoverability|node|petition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_content|node|senator|form';
  $field_group->group_name = 'group_featured_content';
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
        'classes' => '',
        'description' => 'Control which bills are featured on the Senator\'s legislation page and front page.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_featured_content|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_heading_information|node|petition|form';
  $field_group->group_name = 'group_heading_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Petition Heading Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_date',
      1 => 'field_article_author',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-heading-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_heading_information|node|petition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|senator|form';
  $field_group->group_name = 'group_images';
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
      4 => 'group_social_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Microsite Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_images|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_key_staff|node|senator|form';
  $field_group->group_name = 'group_key_staff';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Key Staff',
    'weight' => '11',
    'children' => array(
      0 => 'field_office_contacts',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Key Staff',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $field_group->identifier = 'group_media|node|senator|form';
  $field_group->group_name = 'group_media';
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
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_media|node|senator|form'] = $field_group;

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
  $field_group->parent_name = 'group_media';
  $field_group->data = array(
    'label' => 'Office Addresses',
    'weight' => '12',
    'children' => array(
      0 => 'field_offices',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Office Addresses',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $field_group->identifier = 'group_promo_banner_link|node|promotional_banner|form';
  $field_group->group_name = 'group_promo_banner_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotional_banner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Linked Content',
    'weight' => '3',
    'children' => array(
      0 => 'field_promotional_content',
      1 => 'field_external_web_page',
      2 => 'field_link_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo-banner-link field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo_banner_link|node|promotional_banner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_banners|node|senator|form';
  $field_group->group_name = 'group_promo_banners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_images';
  $field_group->data = array(
    'label' => 'Promotional Banners',
    'weight' => '33',
    'children' => array(
      0 => 'field_promotional_banners',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Promotional Banners',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-promo-banners field-group-fieldset',
        'description' => 'Promotional banners can be thought of as ads for content throughout the site. For an example, see <a href="http://adn-demo.nysenate.gov/senators/john-j-flanagan">this fake page</a> set up by STS. Examples are the red petition box and the red teacher evaluations and school aid box. Photos that you upload for the banner should have no words in them. Please rely on the promotional banner text to convey that messaging (this is because the photos don\'t always show up on mobile viewports).',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_promo_banners|node|senator|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_links|node|senator|form';
  $field_group->group_name = 'group_social_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'senator';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_images';
  $field_group->data = array(
    'label' => 'Social Media Links',
    'weight' => '32',
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
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_social_links|node|senator|form'] = $field_group;

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
      'label' => 'Student Letters',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-student-letters field-group-fieldset',
        'description' => 'These are the default letters for the What are you Thankful for? and Earth Day Poster Contest Student Submissions. You can customize these each year.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_student_letters|node|senator|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About Page');
  t('Auto-Reply Settings');
  t('Contact Page');
  t('Direct Messaging');
  t('Discoverability');
  t('Key Staff');
  t('Legislation Page');
  t('Linked Content');
  t('Microsite Settings');
  t('Newsroom Page');
  t('Office Addresses');
  t('Petition Content');
  t('Petition Heading Information');
  t('Promotional Banners');
  t('Senator Information');
  t('Social Media Links');
  t('Student Letters');

  return $field_groups;
}
