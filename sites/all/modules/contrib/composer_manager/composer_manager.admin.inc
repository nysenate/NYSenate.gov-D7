<?php

/**
 * @file
 * Administrative settings for the Composer Manager module.
 */

/**
 * Administrative settings for the Composer Manager module.
 *
 * @see composer_manager_settings_form_validate()
 *
 * @ingroup forms
 */
function composer_manager_settings_form($form, &$form_state) {

  // Don't break sites that upgraded from <= 7.x-1.0-beta5.
  composer_manager_beta5_compatibility();

  $form['composer_manager_vendor_dir'] = array(
    '#title' => 'Vendor Directory',
    '#type' => 'textfield',
    '#default_value' => variable_get('composer_manager_vendor_dir', 'sites/all/vendor'),
    '#description' => t('The relative or absolute path to the vendor directory containing the Composer packages and autoload.php file.'),
  );

  $form['composer_manager_file_dir'] = array(
    '#title' => 'Composer File Directory',
    '#type' => 'textfield',
    '#default_value' => composer_manager_file_dir(),
    '#description' => t('The directory containing the composer.json file and where Composer commands are run.'),
  );

  $form['composer_manager_autobuild_file'] = array(
    '#title' => 'Automatically build the composer.json file when enabling or disabling modules',
    '#type' => 'checkbox',
    '#default_value' => variable_get('composer_manager_autobuild_file', 1),
    '#description' => t('Automatically build the consolidated composer.json for all contributed modules file in the vendor directory above when modules are enabled or disabled. Disable this setting if you want to maintain the composer.json file manually.'),
  );

  $form['composer_manager_autobuild_packages'] = array(
    '#title' => 'Automatically update Composer dependencies when enabling or disabling modules with Drush',
    '#type' => 'checkbox',
    '#default_value' => variable_get('composer_manager_autobuild_packages', 1),
    '#description' => t('Automatically build the consolidated composer.json file and run Composer\'s <code>!command</code> command when enabling or disabling modules with Drush. Disable this setting to manage the composer.json and dependencies manually.', array('!command' => 'update')),
  );

  $form['#validate'] = array('composer_manager_settings_form_validate');

  return system_settings_form($form);
}

/**
 * Form validation handler for composer_manager_settings_form().
 */
function composer_manager_settings_form_validate($form, &$form_state) {
  module_load_include('inc', 'composer_manager', 'composer_manager.writer');
  $autobuild_file = $form_state['values']['composer_manager_autobuild_file'];
  $file_dir = $form_state['values']['composer_manager_file_dir'];
  if ($autobuild_file && !composer_manager_prepare_directory($file_dir)) {
    form_set_error('composer_manager_file_dir', t('Composer file directory must be writable'));
  }
}

/**
 * Page callback; Shows the status of all packages required by contrib.
 */
function composer_manager_packages_page() {
  $build = array();
  $error = FALSE;

  $header = array(
    'package' => t('Package'),
    'version' => t('Installed Version'),
    'requirement' => t('Version Required by Module'),
  );

  try {
    $required = composer_manager_required_packages();
    $installed = composer_manager_installed_packages();
    $dependents = composer_manager_package_dependents();
    $combined = array_unique(array_merge(array_keys($required), array_keys($installed)));
  }
  catch (\RuntimeException $e) {
    $error = TRUE;
    drupal_set_message(filter_xss_admin($e->getMessage()));
    watchdog_exception('composer_manager', $e);
    $combined = array();
  }

  // Whether a Composer update is needed.
  $update_needed = FALSE;
  // Whether different modules require different versions of the same package.
  $has_conflicts = FALSE;

  $rows = array();
  foreach ($combined as $package_name) {
    $is_installed = isset($installed[$package_name]);

    // If the package is installed but has no dependents and is not required by
    // any modules, then the module that required it has most likely been
    // disabled and the package will be uninstalled on the next Composer update.
    $not_required = $is_installed && !isset($dependents[$package_name]) && empty($required[$package_name]);

    // Get the package name and description.
    if ($is_installed && !empty($installed[$package_name]['homepage'])) {
      $options = array('attributes' => array('target' => '_blank'));
      $name = l($package_name, $installed[$package_name]['homepage'], $options);
    }
    else {
      $name = check_plain($package_name);
    }
    if ($is_installed && !empty($installed[$package_name]['description'])) {
      $name .= '<div class="description">' . check_plain($installed[$package_name]['description']) . '</div>';
    }

    // Get the version required by the module.
    $has_conflict = FALSE;
    if ($not_required) {
      $update_needed = TRUE;
      $requirement = t('No longer required');
      $requirement .= '<div class="description">' . t('Package will be removed on the next Composer update') . '</div>';
    }
    elseif (isset($required[$package_name])) {

      // Sets message based on whether there is a potential version conflict.
      $has_conflict = count($required[$package_name]) > 1;
      if ($has_conflict) {
        $has_conflicts = TRUE;
        $requirement = t('Potential version conflict');
      }
      else {
        $requirement = check_plain(key($required[$package_name]));
      }

      // Build the list of modules that require this package.
      $modules = array();
      $requirement .= '<div class="description">';
      foreach ($required[$package_name] as $version => $module_names) {
        foreach ($module_names as $module_name) {
          $module_info = system_get_info('module', $module_name);
          $modules[] = check_plain($module_info['name']);
        }
      }
      $requirement .= t('Required by: ') . join(', ', $modules);
      $requirement .= '</div>';
    }
    else {
      // This package is a dependency of a package directly required by a
      // module. Therefore we cannot detect the required version without using
      // the Composer tool which is expensive and too slow for the web.
      $requirement = t('N/A');
      $requirement .= '<div class="description">' . t('Dependency for other packages') . '</div>';
    }

    // Get the version that is installed.
    if ($is_installed) {
      $instaled_version = check_plain($installed[$package_name]['version']);
    }
    else {
      $update_needed = TRUE;
      $instaled_version = t('Not installed');
    }

    // Set the row status.
    if (!$is_installed) {
      $class = array('error');
    }
    elseif ($has_conflict || $not_required) {
      $class = array('warning');
    }
    else {
      $class = array('ok');
    }

    $rows[$package_name] = array(
      'class' => $class,
      'data' => array(
        'package' => $name,
        'installed' => $instaled_version,
        'requirement' => $requirement,
      ),
    );
  }

  ksort($rows);
  $build['packages'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#caption' => t('Status of Packages Managed by Composer'),
    '#attributes' => array(
      'class' => array('system-status-report'),
    ),
  );

  $build['refresh_form'] = drupal_get_form('composer_manager_rebuild_form');

  // Set status messages.
  module_load_install('composer_manager');
  $requirements = module_invoke('composer_manager', 'requirements', 'runtime');

  if (REQUIREMENT_OK != $requirements['composer_manager']['severity']) {
    drupal_set_message($requirements['composer_manager']['description'], 'error');
  }
  elseif ($update_needed) {
    $args = array('!command' => 'update', '@url' => url('http://drupal.org/project/composer_manager', array('absolute' => TRUE)));
    drupal_set_message(t('Packages need to be installed or removed by running Composer\'s <code>!command</code> command.<br/>Refer to the instructions on the <a href="@url" target="_blank">Composer Manager project page</a> for updating packages.', $args), 'warning');
  }
  if ($has_conflicts) {
    drupal_set_message(t('Potentially conflicting versions of the same package are required by different modules.'), 'warning');
  }

  return $build;
}

/**
 * Exposes a button that forces a rebuild of the composer.json file.
 *
 * @see composer_manager_rebuild_form_submit()
 *
 * @ingroup forms
 */
function composer_manager_rebuild_form($form, &$form_state) {
  $file_dir = composer_manager_file_dir();

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild composer.json file'),
    '#disabled' => 0 !== strpos($file_dir, 'public://') && (!is_dir($file_dir) || !is_writable($file_dir)),
  );

  $form['#submit'] = array('composer_manager_rebuild_form_submit');

  return $form;
}

/**
 * Form submission handler for composer_manager_rebuild_form().
 */
function composer_manager_rebuild_form_submit($form, &$form_state) {
  composer_manager_write_file();
}

/**
 * Parses a JSON file into a PHP array.
 *
 * @param string $file_uri
 *   The URI of the JSON sile being parsed.
 *
 * @return array
 *   The parsed JSON, and empty array if the file doesn't exist.
 *
 * @throws \RuntimeException
 */
function composer_manager_read_composer_file($file_uri) {
  $json = array();
  if (file_exists($file_uri)) {
    if (!$filedata = @file_get_contents($file_uri)) {
      throw new \RuntimeException(t('Error reading file: @file', array('@file' => $file_uri)));
    }
    $json = @drupal_json_decode($filedata);
    if ($json === NULL) {
      throw new \RuntimeException(t('Error parsing file: @file', array('@file' => $file_uri)));
    }
    elseif ($json === FALSE) {
      $json = array();
    }
  }
  return $json;
}

/**
 * Loads the composer.lock file if it exists.
 *
 * @return array
 *   The parsed JSON, and empty array if the file doesn't exist.
 *
 * @throws \RuntimeException
 */
function composer_manager_lockfile_load() {
  $json = &drupal_static(__FUNCTION__);
  if ($json === NULL) {
    $dir_uri = composer_manager_file_dir();
    $json = composer_manager_read_composer_file($dir_uri . '/composer.lock');
  }
  return $json;
}

/**
 * Loads the composer.lock file if it exists.
 *
 * @return array
 *   The parsed JSON, and empty array if the file doesn't exist.
 *
 * @throws \RuntimeException
 */
function composer_manager_installed_packages_load() {
  $json = &drupal_static(__FUNCTION__);
  if ($json === NULL) {
    $file_uri = composer_manager_vendor_dir() . '/composer/installed.json';
    $json = composer_manager_read_composer_file($file_uri);
  }
  return $json;
}

/**
 * Reads installed package versions from the composer.lock file.
 *
 * NOTE: Tried using `composer show -i`, but it didn't return the versions or
 * descriptions for some strange reason even though it does on the command line.
 *
 * @return array
 *   An associative array of package version information.
 *
 * @throws \RuntimeException
 */
function composer_manager_installed_packages() {
  $installed = &drupal_static(__FUNCTION__, NULL);
  if (NULL === $installed) {
    $installed = array();

    $json = composer_manager_installed_packages_load();
    foreach ($json as $package) {
      $installed[$package['name']] = array(
        'version' => $package['version'],
        'description' => !empty($package['description']) ? $package['description'] : '',
        'homepage' => !empty($package['homepage']) ? $package['homepage'] : '',
      );
    }

    ksort($installed);
  }

  return $installed;
}

/**
 * Returns each installed packages dependents.
 *
 * @return array
 *   An associative array of installed packages to their dependents.
 *
 * @throws \RuntimeException
 */
function composer_manager_package_dependents() {
  $dependents = array();

  $json = composer_manager_installed_packages_load();
  foreach ($json as $package) {
    if (!empty($package['require'])) {
      foreach ($package['require'] as $dependent => $version) {
        $dependents[$dependent][] = $package['name'];
      }
    }
  }

  return $dependents;
}

/**
 * Returns the packages, versions, and the modules that require them in the
 * composer.json files contained in contributed modules.
 *
 * @return array
 */
function composer_manager_required_packages() {
  $required = &drupal_static(__FUNCTION__, NULL);
  if (NULL === $required) {
    require_once __DIR__ . '/composer_manager.writer.inc';

    // Gathers package versions.
    $required = array();
    $data = composer_manager_fetch_data();
    foreach ($data as $module => $json) {
      if (isset($json['require'])) {
        foreach ($json['require'] as $package => $version) {
          $pattern = '@^[A-Za-z0-9][A-Za-z0-9_.-]*/[A-Za-z0-9][A-Za-z0-9_.-]+$@';
          if (preg_match($pattern, $package)) {
            if (!isset($required[$package])) {
              $required[$package][$version] = array();
            }
            $required[$package][$version][] = $module;
          }
        }
      }
    }

    ksort($required);
  }

  return $required;
}
