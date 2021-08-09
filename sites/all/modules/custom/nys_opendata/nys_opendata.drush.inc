<?php

/**
 * Implements hook_drush_command().
 */
function nys_opendata_drush_command() {
  $items = [];

  $items["rewrite-open-data"] = [
    "description" => "Import bills from OpenLeg.",
    "options" => [
      "node" => "A comma-delimited list of node numbers to process",
      "file" => "A comma-delimited list of managed file IDs to process",
      "rewrite-all" => "Forces all open data CSV files to be processed.  Note this overrides --node and --file",
    ],
  ];

  return $items;
}

/**
 * Drush command to rewrite opendata CSV reports for formatting.
 */
function drush_nys_opendata_rewrite_open_data() {
  // Get command line options.
  $node = array_filter(explode(',', drush_get_option('node', '')));
  $file = array_filter(explode(',', drush_get_option('file', '')));

  // If rewrite-all, load all the nodes.
  if (drush_get_option('rewrite-all', FALSE)) {
    drush_print("Querying for nodes ...");
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'open_data');
    $result = $query->execute();
    $node += isset($result['node']) ? array_keys($result['node']) : [];
  }

  // If rewriting a list of nodes (e.g., with --node or --rewrite-all),
  // find all the target files.
  if (count($node)) {
    drush_print("Querying for files ...");
    $node_files = db_select('field_data_field_open_data_file', 'odf')
      ->fields('odf', ['field_open_data_file_fid'])
      ->condition('entity_type', 'node')
      ->condition('bundle', 'open_data')
      ->condition('entity_id', $node)
      ->execute()
      ->fetchCol();
    $file += $node_files;
  }

  // If files are found, load all the managed_file objects.
  if (count($file)) {
    drush_print("Discovering target files ...");
    $rewrites = array_filter(file_load_multiple($file),
      function ($v) {
        return ($v->filemime == 'text/csv');
      }
    );
    $file = array_keys($rewrites);
  }

  // Get user confirmation.
  if (drush_confirm('Preparing to rewrite ' . count($file) . ' files.  Are you sure?')) {
    // Rewrite each file.
    foreach ($file as $one_fid) {
      try {
        if (!NysOpenDataCsv::rewriteFile($one_fid)) {
          drush_print("Unknown failure while writing file $one_fid");
        }
      } catch (Exception $e) {
        drush_print("File $one_fid failed with message:\n" . $e->getMessage());
      }
    }
  }
  else {
    drush_user_abort();
  }
}
