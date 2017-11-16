<?php
/**
 * @file
 * nys_password_reset.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_password_reset_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
