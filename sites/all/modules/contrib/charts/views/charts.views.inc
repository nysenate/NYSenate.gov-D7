<?php
/**
 * @file
 * Views integration with Charts.
 */

/**
 * Implementation of hook_views_plugins().
 *
 * Define charts style for Views.
 */
function charts_views_plugins() {
  $plugins = array();

  $plugins['style']['chart'] = array(
    'title' => t('Chart'),
    'help' => t('Displays the content in several Chart styles.'),
    'handler' => 'charts_plugin_style_chart',
    'uses row plugin' => FALSE,
    'uses row class' => FALSE,
    'uses fields' => TRUE,
    'uses options' => TRUE,
    'uses grouping' => FALSE,
    'type' => 'normal',
  );
  $plugins['style']['chart_extension'] = $plugins['style']['chart'];
  $plugins['style']['chart_extension']['type'] = 'chart';

  $plugins['display']['chart'] = array(
    'title' => t('Chart add-on'),
    'admin' => t('Chart add-on'),
    'help' => t('Add chart data to a new or existing chart.'),
    'handler' => 'charts_plugin_display_chart',
    'theme' => 'views_view',
    'register theme' => FALSE,
    'use ajax' => FALSE,
    'use pager' => FALSE,
    'use more' => FALSE,
    'accept attachments' => FALSE,
    'type' => 'chart',
  );

  return $plugins;
}
