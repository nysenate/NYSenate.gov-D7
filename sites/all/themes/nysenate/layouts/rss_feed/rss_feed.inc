<?php
/**
 * @file
 * RSS Feed layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function nysenate_rss_feed_panels_layouts() {
  $items['rss_feed'] = array(
    'title' => t('RSS Feed'),
    'category' => t('Special'),
    'icon' => 'rss_feed.png',
    'theme' => 'rss_feed',
    'regions' => array(
      'feed' => t('Feed'),
    ),
  );
  return $items;
}
