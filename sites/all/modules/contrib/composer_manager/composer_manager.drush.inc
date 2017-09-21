<?php

/**
 * @file
 * Drush hook implementations for the Composer Manager module.
 */

/**
 * Implements hook_drush_command().
 */
function composer_manager_drush_command() {
  $items = array();

  $items['composer-manager'] = array(
    'description' => 'Executes a composer command in the directory containing the composer.json file.',
    'allow-additional-options' => TRUE,
    'aliases' => array('composer-execute'),
    'arguments' => array(
      'command' => 'The command to run through the Composer Manager composer.json file. Defaults to "install".',
    ),
  );

  $items['composer-json-rebuild'] = array(
    'description' => 'Rebuilds the consolidated composer.json file.',
    'allow-additional-options' => TRUE,
    'aliases' => array(
      'composer-rebuild',
      'composer-rebuild-file',
    ),
  );

  return $items;
}

/**
 * Executes a Composer command on Composer Manager's composer.json file.
 *
 * @param $command
 *   Which command to execute on Composer Manager's composer.json file.
 */
function drush_composer_manager($command = 'install') {
  $uri = composer_manager_file_dir();
  if (!$dir = drupal_realpath($uri)) {
    return drush_set_error(dt('Error resolving path: @uri', array('@uri' => $uri)));
  }

  // Check to see if the composer.json file is available.
  if (!file_exists($dir . '/composer.json')) {
    // Ask the user would like to install Drush Composer.
    if (drush_confirm(dt('The composer.json file is missing. Would you like to re-build it?'))) {
      if (drush_invoke('composer-rebuild-file') === FALSE) {
        return FALSE;
      }
    }
    else {
      return drush_set_error(dt('Missing composer.json file: Run `drush composer-rebuild-file`.'));
    }
  }

  // Check if Drush Composer is available.
  if (!drush_is_command('composer')) {
    // Ask the user would like to install Drush Composer.
    if (!drush_confirm(dt('Download and install the Drush Composer extension?'))) {
      drush_print(dt('Installation of the Drush Composer extension was aborted.'));
      return TRUE;
    }

    // Download the Drush extension.
    if (drush_invoke('dl', array('composer-8.x-1.x')) === FALSE) {
      return drush_set_error(dt('Failed installing the Drush Composer extension. Install it manually by following the instructions on the project page: http://drupal.org/project/composer'));
    }

    // Clear the caches by reloading the available command files.
    _drush_find_commandfiles(DRUSH_BOOTSTRAP_DRUSH);
  }
  if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
    $dir = str_replace('\\', '/', $dir);
  }
  // Generate the command arguments to pass to Drush Composer.
  $drush_arguments = drush_get_arguments();
  if ($drush_arguments && $drush_arguments[0] === 'composer-manager') {
    $arguments = $drush_arguments;
    array_shift($arguments); // exclude drush main command, composer-manager
    $arguments[] = '--working-dir=' . escapeshellcmd($dir);
  }
  else {
    $arguments = array(
      $command,
      // The use of escapeshellcmd rather than escapeshellarg is necessary to
      // avoid enclosing the value in quotes, which is incompatible with the way
      // Composer validates that the working directory exists.
      '--working-dir=' . escapeshellcmd($dir),
    );
  }

  $composer_result = drush_invoke('composer', $arguments);
  // Allow modules to perform post-composer install tasks.
  if ($command == 'install' || $command == 'update') {
    // Before invoking other modules, make sure that any new libraries are
    // available.
    drush_composer_manager_update_autoloader();
    module_invoke_all('composer_dependencies_install');
  }

  return $composer_result;
}

/**
 * Rebuilds the consolidated composer.json file.
 */
function drush_composer_manager_composer_json_rebuild() {
  $success = composer_manager_write_file();
  if ($success) {
    drush_log(dt('Completed building composer.json file.'), 'ok');
    return TRUE;
  }
  else {
    return drush_set_error(dt('Error building composer.json file.'));
  }
}

/**
 * Drush hook; Called after a project is enabled.
 *
 * @see drush_composer_manager_write_if_changed()
 */
function drush_composer_manager_post_pm_enable() {
  drush_composer_manager_write_if_changed();
}

/**
 * Drush hook; Called after a project is disabled.
 *
 * @see drush_composer_manager_write_if_changed()
 */
function drush_composer_manager_post_pm_disable() {
  drush_composer_manager_write_if_changed();
}

/**
 * If one or more extensions being acted on contain a composer.json file, prompt
 * the user to automatically run Composer's update command.
 *
 * @see composer_manager_write_if_changed()
 * @see drush_composer_manager_post_pm_enable()
 * @see drush_composer_manager_post_pm_disable()
 */
function drush_composer_manager_write_if_changed() {
  $changed = &drupal_static('composer_manager_write_if_changed', FALSE);
  if (variable_get('composer_manager_autobuild_packages', 1) && $changed) {
    drush_print('One or more extensions have dependencies managed by Composer.');
    if (drush_confirm(dt('Update packages managed by Composer?'))) {
      drush_composer_manager('update');
    }
  }
}

/**
 * Add new autoloader paths to the Class Loader.
 */
function drush_composer_manager_update_autoloader() {
  $loader = composer_manager_register_autoloader();
  $composer = composer_manager_vendor_dir() . '/composer';

  drush_composer_manager_update_classmap($loader, $composer);
  drush_composer_manager_update_psr4($loader, $composer);
  drush_composer_manager_update_psr0($loader, $composer);
  drush_composer_manager_update_files($composer);
}

/**
 * Add new class maps to the class loader.
 *
 * @param \Composer\Autoload\ClassLoader $loader
 *   The autoloader to attach the updated class map to.
 * @param string $composer
 *   Path to the Composer library.
 */
function drush_composer_manager_update_classmap(\Composer\Autoload\ClassLoader $loader, $composer) {
  $autoload_classmap = $composer . '/autoload_classmap.php';
  if (file_exists($autoload_classmap)) {
    $class_map = $loader->getClassMap();
    $updated_class_map = require $autoload_classmap;
    $loader->addClassMap(array_diff($updated_class_map, $class_map));
  }
}

/**
 * Add new PSR-4 namespaces to the class loader.
 *
 * @param \Composer\Autoload\ClassLoader $loader
 *   The autoloader to add the new namespaces to.
 * @param string $composer
 *   Path to the Composer library.
 */
function drush_composer_manager_update_psr4($loader, $composer) {
  $autoload_psr4 = $composer . '/autoload_psr4.php';
  if (file_exists($autoload_psr4)) {
    $updated_psr4 = require $autoload_psr4;
    foreach ($updated_psr4 as $prefix => $paths) {
      $loader->addPsr4($prefix, $paths);
    }
  }
}

/**
 * Add new PSR-0 namespaces to the class loader.
 *
 * @param \Composer\Autoload\ClassLoader $loader
 *   The autoloader to add the new namespaces to.
 * @param string $composer
 *   Path to the Composer library.
 */
function drush_composer_manager_update_psr0($loader, $composer) {
  $autoload_psr0 = $composer . '/autoload_namespaces.php';
  if (file_exists($autoload_psr0)) {
    $updated_psr0 = require $autoload_psr0;
    foreach ($updated_psr0 as $prefix => $paths) {
      $loader->add($prefix, $paths);
    }
  }
}

/**
 * Require new files added by Composer libraries.
 *
 * @param string $composer
 *   Path to the Composer library.
 */
function drush_composer_manager_update_files($composer) {
  $autoload_files = $composer . '/autoload_files.php';
  if (file_exists($autoload_files)) {
    $updated_files = require $autoload_files;
    foreach ($updated_files as $file) {
      require_once $file;
    }
  }
}
