<?php

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_email_digest_drush_command() {
  $items = array();
  
  $items["email-digest"] = array(
    "description" => "Send a weekly digest to all users.",
  );

  return $items;
}

function drush_nys_email_digest_email_digest() {
  echo "Start time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";

  nys_email_digest_run();

  echo "End time: " . date("m/d/Y H:i:s", strtotime("now")) . "\r\n";
}