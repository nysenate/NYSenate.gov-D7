<?php
/**
 * @file
 * nys_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_users_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "password_policy" && $api == "default_password_policy") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_users_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
