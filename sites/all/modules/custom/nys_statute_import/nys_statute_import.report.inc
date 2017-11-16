<?php
/**
 * @file
 * File nyc_statute_import.report.inc.
 */

/**
 * Reports related to a run.
 */
function nys_statute_import_audit_report_sql($choice) {
  switch ($choice) {
    case 0:
      return "
SELECT * from nys_statute_import_log
";

    case 1:
      return "
SELECT `nid`, `title`
FROM `node`
WHERE `type` = 'statute'
AND `nid` NOT IN (SELECT statute_nid from nys_statute_import_log)
ORDER BY `title`
";

    case 2:
      return "
SELECT `statute_nid`
FROM `nys_statute_import_log`
WHERE `statute_nid`
NOT IN (SELECT `entity_id` FROM `field_data_field_statuteid`)
";

    case 3:
      return "
SELECT `statute_nid`
FROM `nys_statute_import_log`
WHERE `statute_nid`
NOT IN (SELECT field_data_field_lawid.entity_id FROM field_data_field_lawid, field_data_field_locationid WHERE field_data_field_lawid.entity_id = field_data_field_locationid.entity_id AND field_data_field_lawid.bundle = field_data_field_locationid.bundle)
";

    case 4:
      return "
SELECT `field_statuteid_value` AS `Statute Id`,COUNT(*) AS `count`
FROM `field_data_field_statuteid`
GROUP BY `field_statuteid_value`
HAVING `count` > 1
ORDER BY `count` DESC
";

    case 5:
      return "
SELECT field_data_field_lawid.entity_id AS `statute_nid`, `field_lawid_value`, `field_locationid_value`, COUNT(*) AS `count`
FROM field_data_field_lawid, field_data_field_locationid
WHERE field_data_field_lawid.entity_id = field_data_field_locationid.entity_id
AND field_data_field_lawid.bundle = field_data_field_locationid.bundle
GROUP BY `field_lawid_value`,`field_locationid_value`
HAVING `count` > 1
ORDER BY `count` DESC
        ";

    case 6:
      return "
SELECT * from nys_statute_import_log
        ";

    case 7:
      return "
SELECT * FROM `nys_statute_import_law_queue`
        ";

    default:
      return "";

  }
}


/**
 * Reports related to a run.
 */
function nys_statute_import_audit_report_title($choice) {
  switch ($choice) {
    case 0:
      return "Statute Import Log";

    case 1:
      return "Statute Pages on NY Senate that are not in OpenLeg.";

    case 2:
      return "Open Leg statute_id not NYSenate Statute Pages.";

    case 3:
      return "Open Leg law_id and location_id not NYSenate Statute Pages.";

    case 4:
      return "Duplicate Statute Pages with the same statute_id.";

    case 5:
      return "Duplicate Statute Pages with the same law_id and location_id.";

    case 6:
      return "Statute Import Log Table";

    case 7:
      return "Statute Import Law Queue Table (created by structure-clear-range-statutes).";

    default:
      return "";
  }
}

/**
 * Reports related to a run.
 */
function nys_statute_import_audit_report_file_name($choice) {
  switch ($choice) {
    case 0:
      return "statute_import_log.csv";

    case 1:
      return "statute_pages_not_in_open_leg.csv";

    case 2:
      return "ol_statute_id_not_in_nys.csv";

    case 3:
      return "ol_law_id_and_location_id_not_in_nys.csv";

    case 4:
      return "duplicate_statutes_with_the_same_statute_id.csv";

    case 5:
      return "duplicate_statutes_with_the_same_law_id_and_location_id.csv";

    case 6:
      return "statute_import_log.csv";

    case 7:
      return "statute_import_law_queue.csv";


    default:
      return "";
  }
}


/**
 * Reports related to a run.
 */
function nys_statute_import_audit_report($choice) {

  $options = array(
    '1' => nys_statute_import_audit_report_title(1),
    '2' => nys_statute_import_audit_report_title(2),
    '3' => nys_statute_import_audit_report_title(3),
    '4' => nys_statute_import_audit_report_title(4),
    '5' => nys_statute_import_audit_report_title(5),
    '6' => nys_statute_import_audit_report_title(6),
    '7' => nys_statute_import_audit_report_title(7),
  );

  if (empty($choice) || (is_numeric($choice) && ($choice < 1 && $choice > 4))) {
    $choice = drush_choice($options, dt('Which Report would you like to run?'));
  }

  $sql = nys_statute_import_audit_report_sql($choice);
  $title = nys_statute_import_audit_report_title($choice);

  if ($sql && $title && $choice > 0) {
    print nys_statute_import_render_table_data_in_drush($choice);
  }

  if ($choice == 0) {
    print "Canceled\r\n";
  }

}

/**
 * Renders a table.
 */
function nys_statute_import_render_table_data($choice, $width = 100) {
  $data = array();
  $header = array();
  $columns = array();

  $sql = nys_statute_import_audit_report_sql($choice);
  $title = nys_statute_import_audit_report_title($choice);

  drupal_add_css('.page-admin-reports-statute div#navigation ul.tabs.primary {display: none;}', 'inline');

  if (empty($sql) || empty($title)) {
    return "<h1>Sorry No Report $choice</h1>";
  }

  $results = db_query($sql);

  $row_count = $results->rowCount();

  if ($row_count == 0) {
    return '<h1> No Results </h1>';
  }

  // Get the result data.
  foreach ($results as $row_key => $row) {
    // Go thru the columns including the title and remember the max length.
    $output_row = array();
    foreach ($row as $col_key => $col_value) {
      $output_row[$col_key] = $col_value;
    }
    $data[$row_key] = $output_row;
  }

  if (count($data) > 0) {
    foreach ($data[0] as $column_name => $column_value) {
      $header[] = ucfirst($column_name);
    }
  }

  return '<h1>' . $title . '</h1>' .
         theme('table', array('header' => $header, 'rows' => $data)) .
         l(t('CSV'), 'admin/reports/statute/import-log/' . $choice . '/');

}

/**
 * Renders a table.
 */
function nys_statute_import_render_table_data_in_drush($choice, $width = 100) {
  $data = array();
  $columns = array();

  $sql = nys_statute_import_audit_report_sql($choice);
  $title = nys_statute_import_audit_report_title($choice);

  if (empty($sql) || empty($title)) {
    print 'Sorry No Report ' . $choice . "\r\n";
    return;
  }

  $results = db_query($sql);

  $row_count = $results->rowCount();

  if ($row_count == 0) {
    print "No Results\r\n";
    return;
  }

  // Get the result data.
  foreach ($results as $row_key => $row) {
    // Go thru the columns including the title and remember the max length.
    $output_row = array();
    foreach ($row as $col_key => $col_value) {
      $output_row[$col_key] = $col_value;
    }
    $data[$row_key] = $output_row;
  }

  // Survey the in query result data and find the lengths.
  foreach ($data as $row_key => $row) {
    // Go thru the columns including the title and remember the max length.
    foreach ($row as $col_key => $col_value) {
      // If this is row 1.
      if ($row_key == 0) {
        $columns[$col_key] = max(strlen($col_key), strlen($col_value));
      }
      else {
        // This is a regular data row.
        $columns[$col_key] = max($columns[$col_key], strlen($col_value));
      }

    }
  }

  // Print the table header.
  // Upper Header Line.
  print '+';
  $col_num = 0;
  foreach ($columns as $column_title => $column_length) {
    $col_num++;

    print str_pad('-', $column_length + 3, '-');

    if ($col_num < count($columns)) {
      print '-';
    }
    else {
      print '+';
    }

  }
  print "\r\n";

  $column_width_sum = 0;
  foreach ($columns as $column_title => $column_length) {
    $column_width_sum = $column_width_sum + $column_length + 3;
  }

  print '|  ';
  print $title;
  $num_spaces_needed = $column_width_sum - strlen($title);

  for ($i = 0; $i <= $num_spaces_needed; $i++) {
    print " ";
  }

  print "|\r\n";

  print '+';
  foreach ($columns as $column_title => $column_length) {

    print str_pad('-', $column_length + 3, '-');
    print '+';

  }
  print "\r\n";

  // Header Line.
  print '|';
  foreach ($columns as $column_title => $column_length) {

    print str_pad($column_title, $column_length + 3);
    print '|';

  }
  print "\r\n";

  // Lower Header Line.
  print '+';
  foreach ($columns as $column_title => $column_length) {

    print str_pad('-', $column_length + 3, '-');
    print '+';

  }
  print "\r\n";

  // Print the table body.
  // Iterate over and render the data.
  foreach ($data as $row_key => $row) {

    print '|';
    foreach ($row as $key => $value) {
      print '  ';
      print str_pad($value, $columns[$key]);
      print ' |';
    }
    print "\r\n";

  } // Rendering the data.

  // Footer Line.
  print '+';
  foreach ($columns as $column_title => $column_length) {

    print str_pad('-', $column_length + 3, '-');
    print '+';

  }
  print "\r\n";

}

/**
 * Returns a csv file.
 */
function nys_statute_import_log($choice) {
  $row_num = 1;
  $column_titles_array = array();

  $sql = nys_statute_import_audit_report_sql($choice);
  $title = nys_statute_import_audit_report_title($choice);
  $file_name = nys_statute_import_audit_report_file_name($choice);

  // Do the query.
  $results = db_query($sql);

  if ($results->rowCount() == 0) {
    return 0;
  }

  header("Content-Type: text/csv; charset=utf-8");
  header("Content-disposition: attachment; filename=$file_name");
  header("Content-Type: application/force-download");
  header("Content-Transfer-Encoding: binary");
  header("Pragma: no-cache");
  header("Expires: 0");

  // Create a file pointer connected to the output stream.
  $output = fopen('php://output', 'w');

  // Get the result data.
  foreach ($results as $row_key => $row) {

    $row_array = array();

    // Iterate thru the columns.
    foreach ($row as $col_key => $col_value) {
      if ($row_num == 1) {
        // On the first row gather the titles.
        $column_titles_array[] = $col_key;
      }

      // On every row gather the column values.
      $row_array[] = $col_value;

    } // For each column.

    if ($row_num == 1) {
      fputcsv($output, $column_titles_array);
    }

    fputcsv($output, $row_array);

    $row_num++;
  }

  fclose($output);

}
