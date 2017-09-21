<?php

/**
 * @file
 * Provides reports pages for Sendgrid Reports module.
 */

/**
 * Global stats page.
 * @return array
 */
function sendgrid_integration_reports_global() {
  $stats = sendgrid_integration_reports_get_stats_global();
  $settings = array();
  foreach ($stats['global'] as $items) {
    $settings['sendgrid_integration_reports']['global'][] = array(
      'date' => $items['date'],
      'opens' => $items['opens'],
      'clicks' => $items['clicks'],
      'delivered' => $items['delivered'],
      'spam_reports' => $items['spam_reports'],
      'spam_report_drops' => $items['spam_report_drops'],
    );
  }
  $path = drupal_get_path('module', 'sendgrid_integration_reports');
  $render = array(
    '#attached' => array(
      'js' => array(
        array(
          'data' => 'https://www.google.com/jsapi',
          'type' => 'external',
        ),
        $path . '/sendgrid_integration_reports.js',
        array(
          'data' => $settings,
          'type' => 'setting',
        ),
      ),
    ),
    'message' => array(
      '#markup' => t(
        'The following reports are the from the Global Statistics provided by Sendgrid. For more comprehensive data, please visit your !dashboard. !cache to ensure the data is current. !settings to alter the time frame of this data.',
        array(
          '!dashboard' => l(t('Sendgrid Dashboard'), 'https://app.sengrid.com/'),
          '!cache' => l(t('Clear your cache'), 'admin/config/development/performance'),
          '!settings' => l(t('Change your settings'), 'admin/config/services/sendgrid/reports'),
        )
      ),
    ),
    'volume' => array(
      '#prefix' => '<h2>' . t('Sending Volume') . '</h2>',
      '#markup' => '<div id="sendgrid-global-volume-chart"></div>',
    ),
    'spam' => array(
      '#prefix' => '<h2>' . t('Spam Reports') . '</h2>',
      '#markup' => '<div id="sendgrid-global-spam-chart"></div>',
    ),
  );
  $browserstats = sendgrid_integration_reports_get_stats_browser();
  $rows = array();
  foreach ($browserstats as $key => $value) {
    $rows[] = array(
      $key,
      $value
    );
  }
  $headerbrowser = array(
    t('Browser'),
    t('Click Count'),
  );
  $render['browsers'] = array(
    '#prefix' => '<h2>' . t('Browser Statistics') . '</h2>',
    '#theme' => 'table',
    '#header' => $headerbrowser,
    '#rows' => $rows,
    'attributes' => array('width' => '75%')
  );

  $devicestats = sendgrid_integration_reports_get_stats_devices();
  $rowsdevices = array();
  foreach ($devicestats as $key => $value) {
    $rowsdevices[] = array(
      $key,
      $value
    );
  }
  $headerdevices = array(
    t('Device'),
    t('Open Count'),
  );
  $render['devices'] = array(
    '#prefix' => '<h2>' . t('Device Statistics') . '</h2>',
    '#theme' => 'table',
    '#header' => $headerdevices,
    '#rows' => $rowsdevices,
    'attributes' => array('width' => '75%')
  );

  return $render;
}
