<?php
/**
 * @file
 * Batch function.
 *
 * This perfoms all the fun batch ops for the module.
 */

/**
 * Batch function.
 */
function fancy_file_delete_batch_delete($fid, $force, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  // Remove line endings to prevent fail and convert to integer.
  // @see https://www.drupal.org/node/2719619 for related issue.
  $fid = str_replace(array("\r", "\n"), '', $fid);

  // Manual / Orphan Delete.
  if ((int)$fid) {
    $fid = (int) $fid;
    $file = file_load($fid);

    if ($file) {
      if ($force) {
        db_delete('file_managed')->condition('fid', $file->fid)->execute();
        db_delete('file_usage')->condition('fid', $file->fid)->execute();
        file_unmanaged_delete($file->uri);
      }
      else {
        $result = file_delete($file);
        if (is_array($result)) {
          // The file is still being referenced and not set to be forcefully deleted.
          // Notify the user instead.
          $context['results']['error'][] = array(
            'fid' => $fid,
            'message' => t('The file with fid#%fid cannot be delete because it
            is still referenced in the file_usage table. %file_usage', array(
              '%fid' => $fid,
              '%file_usage' => print_r($result, TRUE),
            )),
          );
        }
        else {
          $context['results'][] = $fid;
        }
      }
    }
  }
  // Delete unmanaged.
  else {
    db_delete('unmanaged_files')
      ->condition('path', $fid)
      ->execute();
    file_unmanaged_delete($fid);
    $context['results'][] = $fid;
  }
  // Set the processing message.
  $context['message'] = t('Now cleansing the system of fid#%fid', array('%fid' => $fid));
}

/**
 * Batch finished.
 */
function fancy_file_delete_batch_delete_finished($success, $results, $operations) {
  if ($success) {
    // Reset the cache
    entity_get_controller('file')->resetCache();

    // Handle errors.
    if (!empty($results['error'])) {
      foreach ($results['error'] as $error) {
        drupal_set_message($error['message'], 'warning');
      }
      unset ($results['error']);
    }

    $message = format_plural(count($results), 'One file cleansed.', '@count files cleansed.');
  }
  else {
    $message = t('Assimilation was futile!');
  }

  drupal_set_message($message);

  // Return to the overview page if the batch was initiated from the UI.
  if (!drupal_is_cli()) {
    drupal_goto('admin/config/content/fancy_file_delete');
  }
}
