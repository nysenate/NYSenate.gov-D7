<?php
/**
 * @file
 * Contains drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function stage_file_proxy_drush_command() {
  $items = array();

  $items['stage-file-proxy-dl'] = array(
    'description' => 'Download all managed files from the origin.',
  );

  return $items;
}

/**
 * Download all managed files from the origin.
 */
function drush_stage_file_proxy_dl() {
  $origin = variable_get('stage_file_proxy_origin');
  if (empty($origin)) {
    drush_print(dt('Configure stage_file_proxy_origin variable in your settings.php.'), 'error');
    return;
  }

  $query = db_select('file_managed', 'fm');
  $query->fields('fm', array('uri'));
  $query->orderBy('fm.fid', 'DESC');
  $results = $query->execute()->fetchCol();

  $got_files_number = 0;

  foreach ($results as $uri) {
    if (stage_file_proxy_process_file_uri($uri)) {
      $got_files_number++;
    }
  }

  drush_print(dt('@got_files_number downladed files.', array(
    '@got_files_number' => $got_files_number,
  )));
}
