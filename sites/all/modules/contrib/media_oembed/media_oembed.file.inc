<?php

/**
 * @file
 * File hooks implemented by the Media: oEmbed module.
 */

/**
 * Implements hook_file_operations().
 */
function media_oembed_file_operations() {
  $operations = array(
    'media_oembed_refresh' => array(
      'label' => t('Refresh oEmbed information from source'),
      'callback' => 'media_oembed_cache_clear',
    ),
  );

  return $operations;
}

/**
 * Clear the cached oEmbed content for the selected files.
 */
function media_oembed_cache_clear($fids) {
  $fids = array_keys($fids);

  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'file')
    ->propertyCondition('uri', 'oembed:', 'STARTS_WITH')
    ->propertyCondition('fid', $fids)
    ->execute();

  $files = file_load_multiple(array_keys($results['file']));

  foreach ($files as $file) {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
    $url = $wrapper->getExternalUrl();
    $cid = hash('sha256', $url);
    cache_clear_all($cid, 'cache_media_oembed', TRUE);
  }
}
