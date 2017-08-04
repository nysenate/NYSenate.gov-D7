<?php
/**
 * @file
 * nys_files.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_files_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
}
