<?php
/**
 * @file
 * nys_sitewide_elements.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_sitewide_elements_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_sitewide_elements_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function nys_sitewide_elements_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: legislation_current_session
  $nodequeues['legislation_current_session'] = array(
    'name' => 'legislation_current_session',
    'title' => 'Legislation Current Session',
    'subqueue_title' => '',
    'size' => 1,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'session',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: sitewide_footer_promotional_bann
  $nodequeues['sitewide_footer_promotional_bann'] = array(
    'name' => 'sitewide_footer_promotional_bann',
    'title' => 'Sitewide Footer Promotional Banners',
    'subqueue_title' => '',
    'size' => 3,
    'link' => 'Add to Footer Promo Banners',
    'link_remove' => 'Remove from Footer Promo Banners',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'promotional_banner',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_flag_default_flags().
 */
function nys_sitewide_elements_flag_default_flags() {
  $flags = array();
  // Exported flag: "Bookmarks".
  $flags['bookmarks'] = array(
    'entity_type' => 'node',
    'title' => 'Bookmarks',
    'global' => 0,
    'types' => array(
      0 => 'senator',
    ),
    'flag_short' => 'Bookmark this',
    'flag_long' => 'Add this post to your bookmarks',
    'flag_message' => 'This post has been added to your bookmarks',
    'unflag_short' => 'Unbookmark this',
    'unflag_long' => 'Remove this post from your bookmarks',
    'unflag_message' => 'This post has been removed from your bookmarks',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => 'others',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'nys_sitewide_elements',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Follow Group".
  $flags['follow_group'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'Follow Group',
    'global' => 0,
    'types' => array(
      0 => 'committees',
    ),
    'flag_short' => 'Follow this group',
    'flag_long' => 'Follow this group',
    'flag_message' => 'Following this group',
    'unflag_short' => 'Unfollow this group',
    'unflag_long' => 'Unfollow this group',
    'unflag_message' => 'Not following this group',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
      'search_index' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'nys_sitewide_elements',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function nys_sitewide_elements_image_default_styles() {
  $styles = array();

  // Exported image style: embed_landscape_400x225.
  $styles['embed_landscape_400x225'] = array(
    'label' => 'Embed Landscape 400x225',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 225,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_portrait_225x345.
  $styles['embed_portrait_225x345'] = array(
    'label' => 'Embed Portrait 225x345',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 225,
          'height' => 345,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: square_thumbnail.
  $styles['square_thumbnail'] = array(
    'label' => 'Square Thumbnail',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function nys_sitewide_elements_node_info() {
  $items = array(
    'initiative' => array(
      'name' => t('Initiative'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page_content' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'petition' => array(
      'name' => t('Petition'),
      'base' => 'node_content',
      'description' => t('Create a publicly accessible Petition'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'questionnaire' => array(
      'name' => t('Questionnaire'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'student_program' => array(
      'name' => t('Student Program'),
      'base' => 'node_content',
      'description' => t('An article type to be used exclusively for the student program section of the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'timeline_item' => array(
      'name' => t('Timeline Item'),
      'base' => 'node_content',
      'description' => t('Timeline item for the About page Senate Timeline'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
