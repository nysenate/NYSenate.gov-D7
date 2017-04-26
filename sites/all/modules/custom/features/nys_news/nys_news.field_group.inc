<?php
/**
 * @file
 * nys_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nys_news_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_committee_settings|node|article|form';
  $field_group->group_name = 'group_committee_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_promotion';
  $field_group->data = array(
    'label' => 'Committee Settings',
    'weight' => '8',
    'children' => array(
      0 => 'field_committee_featured',
      1 => 'field_committee',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_committee_settings|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_committee_settings|node|in_the_news|form';
  $field_group->group_name = 'group_committee_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion_visibility';
  $field_group->data = array(
    'label' => 'Committee Settings',
    'weight' => '20',
    'children' => array(
      0 => 'field_committee_featured',
      1 => 'field_committee',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_committee_settings|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_committee_settings|node|press_release|form';
  $field_group->group_name = 'group_committee_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion_and_visibility';
  $field_group->data = array(
    'label' => 'Committee Settings',
    'weight' => '10',
    'children' => array(
      0 => 'field_committee_featured',
      1 => 'field_committee',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_committee_settings|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|in_the_news|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '\'In the News\' Content',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_image_main',
      2 => 'field_date',
      3 => 'field_subheading',
      4 => 'group_publication_source_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '\'In the News\' Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-content field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discoverability|node|article|form';
  $field_group->group_name = 'group_discoverability';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discoverability',
    'weight' => '2',
    'children' => array(
      0 => 'field_issues',
      1 => 'group_site_promotion',
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
  $field_groups['group_discoverability|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discoverability|node|in_the_news|form';
  $field_group->group_name = 'group_discoverability';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discoverability',
    'weight' => '2',
    'children' => array(
      0 => 'field_issues',
      1 => 'group_promotion_visibility',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discoverability',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-discoverability field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_discoverability|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discoverability|node|press_release|form';
  $field_group->group_name = 'group_discoverability';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discoverability',
    'weight' => '5',
    'children' => array(
      0 => 'field_issues',
      1 => 'group_promotion_and_visibility',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_discoverability|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_heading_information|node|press_release|form';
  $field_group->group_name = 'group_heading_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Press Release Heading Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_image_main',
      1 => 'field_date',
      2 => 'field_article_author',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Press Release Heading Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-heading-information field-group-fieldset',
        'description' => 'Do not use ALL CAPS headlines on site press releases. It affects readability for our users.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_heading_information|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_headline_and_authorship|node|in_the_news|form';
  $field_group->group_name = 'group_headline_and_authorship';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Headline & Authorship',
    'weight' => '0',
    'children' => array(
      0 => 'field_attachment',
      1 => 'field_article_author',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Headline & Authorship',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-headline-and-authorship field-group-fieldset',
        'description' => 'Good titles for in the news articles often start with a short indicator for the source publication or pundit, followed by a quote (e.g. "WABC: \'Senator Meets with Advocacy Group\'")

<strong>Do not</strong> use dates in the title. Instead, use the "Publication Date" field below.
<strong>Do not</strong> use ALL CAPS. Research proves it\'s harder to read, and our site typography is not designed to handle it well.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_headline_and_authorship|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|press_release|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images and Attachments',
    'weight' => '18',
    'children' => array(
      0 => 'field_image_main',
      1 => 'field_attachment',
      2 => 'field_image_hero',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Images and Attachments',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_images|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_microsite_settings|node|article|form';
  $field_group->group_name = 'group_microsite_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_promotion';
  $field_group->data = array(
    'label' => 'Senator Microsite Settings',
    'weight' => '6',
    'children' => array(
      0 => 'field_featured',
      1 => 'field_senator',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_microsite_settings|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_microsite_settings|node|in_the_news|form';
  $field_group->group_name = 'group_microsite_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion_visibility';
  $field_group->data = array(
    'label' => 'Senator Microsite Settings',
    'weight' => '17',
    'children' => array(
      0 => 'field_senator',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-microsite-settings field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_microsite_settings|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promotion_and_visibility|node|press_release|form';
  $field_group->group_name = 'group_promotion_and_visibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_discoverability';
  $field_group->data = array(
    'label' => 'Promotion and Visibility',
    'weight' => '7',
    'children' => array(
      0 => 'group_committee_settings',
      1 => 'group_senators',
      2 => 'group_senator_microsite_settings',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-promotion-and-visibility field-group-htabs',
      ),
    ),
  );
  $field_groups['group_promotion_and_visibility|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promotion_visibility|node|in_the_news|form';
  $field_group->group_name = 'group_promotion_visibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_discoverability';
  $field_group->data = array(
    'label' => 'Promotion and Visibility',
    'weight' => '10',
    'children' => array(
      0 => 'group_committee_settings',
      1 => 'group_microsite_settings',
      2 => 'group_sitewide',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-promotion-visibility field-group-htabs',
      ),
    ),
  );
  $field_groups['group_promotion_visibility|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_source_info|node|in_the_news|form';
  $field_group->group_name = 'group_publication_source_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Source Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_publication_title',
      1 => 'field_publication_source_link',
      2 => 'field_itn_publication_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Source Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_publication_source_info|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_images|node|in_the_news|form';
  $field_group->group_name = 'group_related_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Display Images',
    'weight' => '3',
    'children' => array(
      0 => 'field_image_main',
      1 => 'field_image_hero',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-images field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_images|node|in_the_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_senator_microsite_settings|node|press_release|form';
  $field_group->group_name = 'group_senator_microsite_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion_and_visibility';
  $field_group->data = array(
    'label' => 'Senator MIcrosite Settings',
    'weight' => '8',
    'children' => array(
      0 => 'field_senator',
      1 => 'field_featured',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_senator_microsite_settings|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_senators|node|press_release|form';
  $field_group->group_name = 'group_senators';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion_and_visibility';
  $field_group->data = array(
    'label' => 'Sitewide Settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_accessible_sitewide',
      1 => 'field_associated_senator',
      2 => 'field_image_hero',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Sitewide Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => 'These options are only available to front page editors',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_senators|node|press_release|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_promotion|node|article|form';
  $field_group->group_name = 'group_site_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_discoverability';
  $field_group->data = array(
    'label' => 'Promotion and Visibility',
    'weight' => '2',
    'children' => array(
      0 => 'group_committee_settings',
      1 => 'group_microsite_settings',
      2 => 'group_sitewide_settings',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Promotion and Visibility',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_site_promotion|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sitewide_settings|node|article|form';
  $field_group->group_name = 'group_sitewide_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_site_promotion';
  $field_group->data = array(
    'label' => 'Sitewide Settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_image_hero',
      1 => 'field_accessible_sitewide',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_sitewide_settings|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sitewide|node|in_the_news|form';
  $field_group->group_name = 'group_sitewide';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'in_the_news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion_visibility';
  $field_group->data = array(
    'label' => 'Sitewide Settings',
    'weight' => '18',
    'children' => array(
      0 => 'field_accessible_sitewide',
      1 => 'field_image_hero',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sitewide field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_sitewide|node|in_the_news|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('\'In the News\' Content');
  t('Committee Settings');
  t('Discoverability');
  t('Display Images');
  t('Headline & Authorship');
  t('Images and Attachments');
  t('Press Release Heading Information');
  t('Promotion and Visibility');
  t('Senator MIcrosite Settings');
  t('Senator Microsite Settings');
  t('Sitewide Settings');
  t('Source Information');

  return $field_groups;
}
