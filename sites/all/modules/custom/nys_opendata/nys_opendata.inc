<?php

/**
 * @file nys_opendata.inc
 * Helper functions for nys_opendata module.
 */

require_once 'nys_opendata.csv.class.php';

/**
 * Constructs the array for the #attached value of an open data table
 * render array.  Used for loading the datatables JS if *any* table has
 * been rendered. See NysOpenDataCsv->buildAttachedArray() for local
 * table settings.
 *
 * @param array $settings An optional of array of settings to add to
 * the Drupal object.
 *
 * @return array[]
 */
function nys_opendata_construct_attached($settings = []) {
  /**
   * Need the path to the vendor library directory.  This is the best
   * way found so far.
   *
   * @see composer_manager_vendor_dir()
   */
  $vendor_path = variable_get('composer_manager_vendor_dir', 'sites/all/vendor');

  // Set up the paths.
  $css_path = $vendor_path . '/datatables/datatables/media/css/jquery.dataTables.min.css';
  $dt_path = $vendor_path . '/datatables/datatables/media/js/jquery.dataTables.js';
  $od_path = drupal_get_path('module', 'nys_opendata') . '/nys_opendata.js';

  return [
    'js' => [
      url($dt_path, ['external' => TRUE]),
      url($od_path, ['external' => TRUE]),
    ],
    'css' => [url($css_path, ['external' => TRUE])],
  ];
}

/**
 * The AJAX handler for front-end datatables requests.
 *
 * @param int $fid The Drupal managed_file ID
 */
function nys_opendata_fetch_datasource($fid = NULL) {
  if ((int) $fid) {
    $order_column = (int) ($_GET['order'][0]['column'] ?? 0);
    $descend = ($_GET['order'][0]['dir'] ?? 'asc') === 'desc';
    $file = new NysOpenDataCsv($fid);
    $file->sortData($order_column, $descend);
    $content = $file->getDataSlice($_GET['start'] ?? 0, $_GET['length'] ?? 100);
    $ret = [
      'data' => $content,
      'draw' => (int) $_GET['draw'],
      'recordsTotal' => $file->countRows(),
      'recordsFiltered' => $file->countRows(),
    ];
    drupal_json_output($ret);
  }
  drupal_exit();
}
