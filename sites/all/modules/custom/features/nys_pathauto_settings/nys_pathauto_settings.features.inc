<?php
/**
 * @file
 * nys_pathauto_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_pathauto_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
