<?php
/**
 * @file
 * File nyc_statute_import.report.inc.
 */

require_once 'nys_school_importer.inc';

/**
 * Analyzes all the school names in the nys_school_names table.
 */
function nys_school_importer_report_page() {
  $duplicate_school_names = nys_school_importer_duplicate_school_titles();
  if (empty($duplicate_school_names) == FALSE) {
    return $duplicate_school_names;
  }
  else {
    return "No Duplicate School Names Found.";
  }
}

/**
 * Reports on any duplicate school titles.
 */
function nys_school_importer_duplicate_school_titles() {
  // Get schools where `num_keys` equal or greater than $num_keys.
  $results = FALSE;
  $result = db_query("SELECT `nid`, `title` FROM `node` WHERE title = (SELECT `title` FROM `node` WHERE type='school' GROUP BY `title` HAVING COUNT(*) > 1)");
  $markup = '<h2>Duplicate School Names</h2><ul id="duplicate-school-names">';
  foreach ($result as $record) {
    $markup = $markup . '<li>';
    $markup = $markup . l($record->title, '/node/' . $record->nid . '/edit/');
    $markup = $markup . '</li>';
    $results = TRUE;
  }
  $markup = $markup . '</ul>';

  if ($results == FALSE) {
    $markup = '';
  }

  return $markup;
}
