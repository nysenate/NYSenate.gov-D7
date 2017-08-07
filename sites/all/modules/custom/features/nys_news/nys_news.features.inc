<?php
/**
 * @file
 * nys_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_news_ctools_plugin_api($module = NULL, $api = NULL) {
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
function nys_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function nys_news_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow Issue".
  $flags['follow_issue'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'Follow Issue',
    'global' => 0,
    'types' => array(
      0 => 'issues',
    ),
    'flag_short' => 'Follow This Issue',
    'flag_long' => 'Follow this issue',
    'flag_message' => 'Following this Issue',
    'unflag_short' => 'Unfollow This Issue',
    'unflag_long' => 'Unfollow this issue',
    'unflag_message' => 'Not following this issue',
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
    'show_contextual_link' => 1,
    'module' => 'nys_news',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function nys_news_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('The most commonly used content type. <em>Articles</em> should be written in the Senator\'s voice. When articles are tagged with an issue, they will appear on the dashboards of constituents that follow that issue (Press Releases, in contrast, do not appear on constituent dashboards). '),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => t('The <em>article</em> is the most commonly used content type. When articles are tagged with an issue, they will appear on the dashboards of constituents that follow that issue (Press Releases, in contrast, do not appear on constituent dashboards). '),
    ),
    'in_the_news' => array(
      'name' => t('In The News'),
      'base' => 'node_content',
      'description' => t('Senators can use this content type to link to external articles in traditional and new media (newspapers, blogs, etc.) in which the Senator was recently quoted or featured, or to reports and articles that are relevant to bills currently being considered. You will be required to put the external source\'s title, link, and original publication date.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => t('Senators can use this content type to draw readers\' attention to articles in traditional and new media (newspapers, blogs, etc.) in which the Senator was recently quoted or featured, or to reports and articles that are relevant to bills currently being considered. For the purposes of avoiding copyright infringement claims, please do not post news articles in their entirety. The best use is one or two paragraphs to entice the reader to click the link and read the article on the page of the original source.'),
    ),
    'photo' => array(
      'name' => t('Photo'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'press_release' => array(
      'name' => t('Press Release'),
      'base' => 'node_content',
      'description' => t('The <em>press release</em> is a tool of communication between members and reporters. Unlike most other content types, press releases <em>do not appear</em> on constituent dashboards. They appear prominently in the Senator\'s front page newsroom section and their newsroom page.'),
      'has_title' => '1',
      'title_label' => t('Release Title'),
      'help' => '',
    ),
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
