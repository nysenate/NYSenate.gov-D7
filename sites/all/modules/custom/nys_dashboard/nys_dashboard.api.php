<?php
/**
 * @file
 * Analytics Dashboard API definitions.
 */

/**
 * Implements senator_dashboard_bill_overview_alter().
 */
function hook_senator_dashboard_bill_overview_alter($vars) {

  // Add an extra variable for bill overview block
  $vars['overview_source'] = 'Example string';
  return $vars;
}
