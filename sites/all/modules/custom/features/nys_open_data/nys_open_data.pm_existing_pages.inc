<?php

/**
 * @file
 * nys_open_data.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function nys_open_data_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'open_data';
  $pm_existing_page->label = 'Open Data';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'open-data';
  $export['open_data'] = $pm_existing_page;

  return $export;
}
