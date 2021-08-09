<?php
/**
 * @file
 * File nyc_statute_import.monitor.inc.
 */

/**
 * Renders a ststus report if running or after.
 */
function nys_statute_import_status() {

  $age_of_data = nys_statute_import_log_freshness();

  // If a run is im progress.
  if ($age_of_data >= 0 && $age_of_data < 30) {
    // This is a Monitor page.
    drupal_add_html_head(array(
      '#tag' => 'meta',
      '#attributes' => array(
        'http-equiv' => 'refresh',
        'content' => 5,
      ),
    ), 'refresh-page');

    return nys_statute_import_render_status_data(nys_statute_import_get_status_data());
  }
  else {
    // This is a Monitor page.
    drupal_add_html_head(array(
      '#tag' => 'meta',
      '#attributes' => array(
        'http-equiv' => 'refresh',
        'content' => 10,
      ),
    ), 'refresh-page'
    );

    return nys_statute_import_render_status_data(nys_statute_import_get_status_data());
  }

}

/**
 * Status report.
 *
 * Different for running and not ??
 * Returns array of data.
 */
function nys_statute_import_get_status_data() {

  $output_array = array();

  // Is a run in progress.
  $freshness = nys_statute_import_log_freshness();
  $last_processed = nys_statute_import_get_last_law_id_processed_timestamp();
  $started = nys_statute_import_get_first_law_id_processed_timestamp();

  if ($freshness >= 0 && $freshness <= 10) {
    $output_array['Currently Processing'] = 'Currently Processing';
  }
  elseif (nys_statute_import_variable_exists(NYS_STATUTE_IMPORT_ALL_STOP)) {
    $output_array['Processing Paused'] = date("Y-m-d h:i:s", $last_processed);
  }
  else {
    $output_array['Completed Processing'] = date("Y-m-d h:i:s", $last_processed);
  }

  // Run started.
  $output_array['Run Started'] = date("Y-m-d h:i:s", $started);

  // Elapsed Time.
  $output_array['Elapsed Time'] = _format_interval($started, $last_processed);

  // Quantity of law_id's.
  $output_array['Qty Law Ids'] = nys_statute_import_get_law_id_count();

  // Quantity of law_id's processed.
  $output_array['Qty Law Ids Processed'] = nys_statute_import_get_qty_law_ids_processed();

  // Last law_id processed.
  $output_array['Last Law ID Processed'] = nys_statute_import_get_last_law_id_processed();

  // Last Statute processed.
  $output_array['Last Statute Processed'] = date("Y-m-d h:i:s", $last_processed);

  // Quantity of statute's processed.
  $output_array['Qty Statutes Processed'] = db_query("SELECT COUNT(*) FROM `nys_statute_import_log`")->fetchField();

  // Data about Last Statute Processed.
  $output_array['Last Item Processed'] = 'Last Item Processed';

  // Data about the last row imported.
  $result = db_query('SELECT * FROM `nys_statute_import_log` WHERE `olid` = (SELECT MAX(`olid`) FROM `nys_statute_import_log`)');
  foreach ($result as $row) {

    // Add the columns as array elements.
    foreach ($row as $column_title => $column_data) {
      $output_array[$column_title] = $column_data;
    }
  }

  return $output_array;

}

/**
 * Renders Status report.
 *
 * Ready to print.
 */
function nys_statute_import_render_status_data($status_data) {

  $rows = array();
  foreach ($status_data as $title => $data) {
    if ($title != $data) {
      $rows[] = array($title, $data);
    }
    elseif ($title == $data) {
      $rows[] = array('<b>' . $title . '</b>', '');
    }
  }

  $header = array('Description', 'Data');

  drupal_add_css('.page-admin-reports-statute div#navigation ul.tabs.primary {display: none;}', 'inline');

  return '<h1>Status Report</h1>' .
         theme('table', array('header' => $header, 'rows' => $rows)) .
         l(t('DONWLOAD COMPLETE IMPORT LOG - CSV'), 'admin/reports/statute/import-log/0/');

}

/**
 * Renders Status report.
 *
 * Ready to print.
 */
function nys_statute_import_drush_render_status_data($status_data) {

  print "+-----------------------------------------------------+\r\n";
  print "|                        STATUS                       |\r\n";
  print "+--------------------------+--------------------------+\r\n";
  print "| Description              | Data                     |\r\n";
  print "+--------------------------+--------------------------+\r\n";

  foreach ($status_data as $title => $data) {
    if ($title != $data) {
      print '| ';
      print str_pad($title, 25);
      print '| ';
      print str_pad($data, 25);
      print "|\r\n";
    }
    elseif ($title == $data) {
      print "+--------------------------+--------------------------+\r\n";
      print "| $title      |                          |\r\n";
    }
  }
  print "+--------------------------+--------------------------+\r\n";
  print "Type Control C to quit.\r\n";

}

/**
 * Calculates and formats the difference between 2 timestamps HH:MM:SS.
 */
function _format_interval($begin, $end) {

  if (!is_numeric($begin) || !is_numeric($end)) {
    return '';
  }

  // Difference Time.
  if ($end > $begin) {
    $interval = $end - $begin;
  }
  else {
    $interval = $begin - $end;
  }
  if ($interval <= 60) {
    return ':' . $interval;
  }
  elseif ($interval > 60 && $interval < 3600) {
    $minutes = floor($interval / 60);
    $seconds = str_pad($interval % 60, 2, '0', STR_PAD_LEFT);
    return $minutes . ':' . $seconds;
  }
  elseif ($interval >= 3600) {
    $hours = floor($interval / 3600);
    $remainder = $interval % 3600;
    $minutes = str_pad(floor($remainder / 60), 2, '0', STR_PAD_LEFT);
    $seconds = str_pad($remainder % 60, 2, '0', STR_PAD_LEFT);
    return $hours . ':' . $minutes . ':' . $seconds;

  }

  return '';

}
