<?php
// Require the JSON creation functions file.
require_once 'nys_senators_json.inc';

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_senators_json_drush_command() {
  $items = [];

  $items["write-senator-json"] = [
    "description" => "Recreates senators.json from current database.",
    "options" => [
      "shortname" => "Shortname of a single senator to output (instead of all)",
    ],
  ];
  return $items;
}

function drush_nys_senators_json_write_senator_json() {
  $shortname = drush_get_option('shortname', '');
  nys_senators_json($shortname, TRUE);
}
