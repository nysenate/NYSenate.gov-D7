<?php

/**
 * @file
 * Provides rules hook implementations for feeds-rules module.
 */

/**
 * Implements hook_rules_data_info_alter().
 */
function feeds_rules_rules_data_info_alter(&$data_info) {

  // Only implement the property if feeds itself still does not.
  if (!isset($data_info['feeds_source']['property info']['feed_nid'])) {
    // Add attached node to the feeds source item.
    $data_info['feeds_source']['property info']['feed_nid'] = array(
      'label' => t('Feed Node'),
      'type' => 'node',
      'description' => t('The Node the importer instance is attached to.'),
    );
  }
}
