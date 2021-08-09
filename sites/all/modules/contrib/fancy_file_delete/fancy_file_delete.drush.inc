<?php

/**
 * Implements hook_drush_command().
 */
function fancy_file_delete_drush_command() {
  $items  = array(
    'fancy-file-delete' => array(
      'callback'    => 'fancy_file_delete_drush_batch_delete_process',
      'description' => 'Deletes any number of files by fid or path.',
      'aliases' => array('ffd'),
      'arguments'   => array(
        'files' => "A comma separate list of file ID's OR 
          relative paths to any files you wish to delete.",
      ),
      'options' => array(
        'force' => 'Forcefully remove the file, even if it is still being referenced.',
      ),
    ),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function fancy_file_delete_drush_help($section) {
  switch ($section) {
    case 'drush:fancy-file-delete':
      return "Deletes any number of files by fid or path.";
  }
}

/**
 * Run fancy file delete.
 */
function fancy_file_delete_drush_batch_delete_process($file_list) {
  $operations = array();

  // Prompt user for confirmation.
  $confirm = drush_confirm('WARNING! Are you sure you want to delete these files?');
  if (!$confirm) {
    drush_user_abort();
    return;
  }

  // Initialize our batch operations.
  $files = explode(',', $file_list);
  $force = drush_get_option('force', FALSE);
  foreach ($files as $file) {
    $operations[] = array('fancy_file_delete_batch_delete', array($file, $force));
  }

  // Create our batch.
  $batch = array(
    'operations' => $operations,
    'title' => 'Deleting files.',
    'init_message' => 'Initializing.',
    'error_message' => 'An error occurred during file deletion.',
    'finished' => 'fancy_file_delete_batch_delete_finished',
    'file' => drupal_get_path('module', 'fancy_file_delete') .
      '/includes/fancy_file_delete.batch_delete.inc',
  );
  batch_set($batch);
  $batch = &batch_get();
  $batch['progressive'] = FALSE;

  // Start the process.
  drush_backend_batch_process();
}
