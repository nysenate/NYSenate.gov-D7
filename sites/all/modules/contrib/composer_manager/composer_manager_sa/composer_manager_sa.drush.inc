<?php

/**
 * @file
 * Drush command callbacks.
 */

/**
 * Implements hook_drush_command().
 */
function composer_manager_sa_drush_command() {
  $items = array();

  $items['composer-manager-sa-check'] = array(
    'description' => 'Check for security advisories for installed Composer packages.',
    'aliases' => array('composer-sa'),
    'drupal dependencies' => array('composer_manager_sa'),
  );

  return $items;
}

/**
 * Command callback to check for security advisories.
 */
function drush_composer_manager_sa_check() {
  composer_manager_sa_print();
}

/**
 * Print security advisories with Drush.
 */
function composer_manager_sa_print() {
  if (!$lock_file = composer_manager_lock_file()) {
    drupal_set_message(t('The composer.lock file is missing or not readable. Skipping security advisory checks.'), 'warning');
    return;
  }

  $output = composer_manager_sa_check($lock_file);

  // This hook is only called from the context of a Drush command.
  drush_print($output->fetch());
}
