<?php
/**
 * @file
 * Variable module integration.
 */

/**
 * Implements hook_variable_group_info().
 */
function stage_file_proxy_variable_group_info() {
  $groups['stage_file_proxy'] = array(
    'title' => t('Stage File Proxy'),
    'description' => t('Stage File Proxy variables.'),
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function stage_file_proxy_variable_info($options) {
  $variables['stage_file_proxy_origin'] = array(
    'title' => t('Origin'),
    'description' => t('The origin website. If the site is using HTTP Basic Authentication (the browser popup for username and password) you can embed those in the url. Be sure to URL encode any special characters.'),
    'type' => 'string',
    'default' => '',
    'group' => 'stage_file_proxy',
  );
  $variables['stage_file_proxy_origin_dir'] = array(
    'title' => t('Origin directory'),
    'description' => t('If this is set then Stage File Proxy will use a different path for the remote files. This is useful for multisite installations where the sites directory contains different names for each url. If this is not set, it defaults to the same path as the local site (sites/default/files).'),
    'type' => 'string',
    'default' => 'sites/default/files',
    'group' => 'stage_file_proxy',
  );
  $variables['stage_file_proxy_hotlink'] = array(
    'title' => t('Hotlink'),
    'description' => t('If this is true then Stage File Proxy will not transfer the remote file to the local machine, it will just serve a 301 to the remote file and let the origin webserver handle it.'),
    'type' => 'boolean',
    'default' => FALSE,
    'group' => 'stage_file_proxy',
  );
  $variables['stage_file_proxy_use_imagecache_root'] = array(
    'title' => t('Use imagecache root'),
    'description' => t('If this is true (default) then Stage File Proxy will look for /imagecache/ in the URL and determine the original file and request that rather than the processed file, then send a header to the browser to refresh the image and let imagecache handle it. This will speed up future imagecache requests for the same original file.'),
    'type' => 'boolean',
    'default' => TRUE,
    'group' => 'stage_file_proxy',
  );
  $variables['stage_file_proxy_sslversion'] = array(
    'title' => t('SSL Version'),
    'description' => t('CURL will try to figure out which ssl version to use, but if it fails to do that properly it can lead to getting an empty file and a 0 status code. The default is 3 which seems relatively common, but if you get 0 byte files you can try changing it to 2.'),
    'type' => 'number',
    'default' => 3,
    'group' => 'stage_file_proxy',
  );
  $variables['stage_file_proxy_headers'] = array(
    'title' => t('HTTP headers'),
    'description' => t('When Stage File Proxy is configured to transfer the remote file to local machine, it will use this headers for HTTP request. Use format like "Referer|http://example.com/".'),
    'type' => 'text',
    'default' => '',
    'group' => 'stage_file_proxy',
  );

  return $variables;
}
