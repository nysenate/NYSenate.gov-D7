<?php

/**
 * @file
 * Features module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_feeds_drush_command() {
  $items = array();

  $items['districts-update'] = array(
    'description' => "Update New York Senate districts from SAGE. use --source=<url> to use a different source",
    'options' => array(
      'source' => "URL to pull district json from.",
    ),
    'aliases' => array('district-up', 'districtup'),
  );

  return $items;
}

function drush_nys_feeds_districts_update() {
  $myFeed = feeds_source('district_import');

  $sage_base_url = variable_get('nys_sage_api_endpoint');
  $sage_method = 'map/senate';

  if ($sage_base_url != NULL) {
    $default_source = $sage_base_url . $sage_method;

    $feed_source = drush_get_option('source') ? drush_get_option('source') : $default_source;
    $config = array(
      'FeedsHTTPFetcher' => array(
        'source' => $feed_source,
      ),
    );
    $myFeed->addConfig($config);

    while (FEEDS_BATCH_COMPLETE != $myFeed->import());

    // Running the function below as a separate process
    // Due to larger feed at $default_source json failing to validate and is
    // 3 MB. Also, was getting errors saving raw json to database, so we're
    // serializing objects, which mysql seems to like better.
    nys_feeds_update_districts_sage_data();
  }
}
