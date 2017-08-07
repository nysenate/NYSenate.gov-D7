<?php
/**
 * @file
 * Uses drush to import tweets via twitter_cron().
 */

/**
 * Implements hook_drush_command().
 *
 * @see drush_parse_command()
 */
function nys_twitter_import_drush_command() {
  $items = array();

  $items["twitter-import"] = array(
    "description" => "Import tweets from Twitter.",
  );

  return $items;
}

/**
 * Invoke twitter_cron from drush.
 */
function drush_nys_twitter_import_twitter_import() {
  echo "Start time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";
  echo "Executing...\r\n";
  nys_twitter_import_run();
  echo "End time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";
}
