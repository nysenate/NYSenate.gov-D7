<?php

/**
 * @file
 * Functions related to the creation of the consolidated composer.json file.
 */

/**
 * Fetches the data in each module's composer.json file.
 *
 * @return array
 *
 * @throws \RuntimeException
 */
function composer_manager_fetch_data() {
  $data = array();
  foreach (module_list() as $module) {

    $module_dir = drupal_get_path('module', $module);
    $composer_file = $module_dir . '/composer.json';
    $args = array('@file' => $composer_file);

    if (!file_exists($composer_file)) {
      continue;
    }

    if (!$filedata = @file_get_contents($composer_file)) {
      throw new \RuntimeException(t('Error reading file: @file', $args));
    }

    if (!$json = @drupal_json_decode($filedata)) {
      throw new \UnexpectedValueException(t('Expecting contents of file to be valid JSON: @file', $args));
    }

    $data[$module] = $json;
  }
  return $data;
}

/**
 * Builds the JSON array ccontaining the combined requirements of each module's
 * composer.json file.
 *
 * @param array $data
 *   An array of JSON arrays parsed from composer.json files keyed by the module
 *   that defines it. This is usually the return value of the
 *   composer_manager_fetch_data() function.
 *
 * @return array
 *   The consolidated JSON array that will be written to a compsoer.json file.
 *
 * @throws \RuntimeException
 */
function composer_manager_build_json(array $data) {
  $combined = array();
  foreach ($data as $module => $json) {

    if (!$combined) {

      $combined = array(
        'require' => array(),
        'config'  => array(
          'autoloader-suffix' => 'ComposerManager',
        ),
        'prefer-stable' => TRUE,
      );

      $vendor_dir = composer_manager_relative_vendor_dir();
      if (0 !== strlen($vendor_dir) && 'vendor' != $vendor_dir) {
        $combined['config']['vendor-dir'] = $vendor_dir;
      }
    }

    // @todo Detect duplicates, maybe add an "ignore" list. Figure out if this
    // encompases all keys that should be merged.
    $to_merge = array(
      'require',
      'require-dev',
      'conflict',
      'replace',
      'provide',
      'suggest',
      'repositories',
      'prefer-stable',
      'config',
    );

    foreach ($to_merge as $key) {
      if (isset($json[$key])) {
        if (isset($combined[$key]) && is_array($combined[$key])) {
          $combined[$key] = array_merge($combined[$key], $json[$key]);
        }
        else {
          $combined[$key] = $json[$key];
        }
      }
    }

    $autoload_blocks = array('autoload', 'autoload-dev');
    foreach ($autoload_blocks as $autoload_block) {
      $autoload_options = array('psr-0', 'psr-4');
      foreach ($autoload_options as $option) {
        if (isset($json[$autoload_block][$option])) {
          $namespaces = (array) $json[$autoload_block][$option];
          foreach ($json[$autoload_block][$option] as $namespace => $dirs) {
            $dirs = (array) $dirs;
            array_walk($dirs, 'composer_manager_relative_autoload_path', $module);
            if (!isset($combined[$autoload_block][$option][$namespace])) {
              $combined[$autoload_block][$option][$namespace] = array();
            }
            $combined[$autoload_block][$option][$namespace] = array_merge(
              $combined[$autoload_block][$option][$namespace], $dirs
            );
          }
        }
      }

      // Merge in the "classmap" and "files" autoload options.
      $autoload_options = array('classmap', 'files');
      foreach ($autoload_options as $option) {
        if (isset($json[$autoload_block][$option])) {
          $dirs = (array) $json[$autoload_block][$option];
          array_walk($dirs, 'composer_manager_relative_autoload_path', $module);
          if (!isset($combined[$autoload_block][$option])) {
            $combined[$autoload_block][$option] = array();
          }
          $combined[$autoload_block][$option] = array_merge(
            $combined[$autoload_block][$option], $dirs
          );
        }
      }
    }

    // Take the lowest stability.
    if (isset($json['minimum-stability'])) {
      if (!isset($combined['minimum-stability']) || -1 == composer_manager_compare_stability($json['minimum-stability'], $combined['minimum-stability'])) {
        $combined['minimum-stability'] = $json['minimum-stability'];
      }
    }
  }

  drupal_alter('composer_json', $combined);
  return $combined;
}

/**
 * Writes the composer.json file in the specified directory.
 *
 * @param string $dir_uri
 *   The URI of the directory that the composer.json file is being written to.
 *   This is usually the "composer_manager_file_dir" system variable.
 * @param array $json
 *   A model of the JSON data being written. This is usually the return value of
 *   composer_manager_build_json().
 *
 * @throws \RuntimeException
 */
function composer_manager_put_file($dir_uri, array $json) {
  composer_manager_prepare_directory($dir_uri);

  // Make the composer.json file human readable for PHP >= 5.4.
  // @see drupal_json_encode()
  // @see http://drupal.org/node/1943608
  // @see http://drupal.org/node/1948012
  $json_options = JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT;
  if (defined('JSON_PRETTY_PRINT')) {
    $json_options = $json_options | JSON_PRETTY_PRINT;
  }
  if (defined('JSON_UNESCAPED_SLASHES')) {
    $json_options = $json_options | JSON_UNESCAPED_SLASHES;
  }

  $file_uri = $dir_uri . '/composer.json';
  if (!@file_put_contents($file_uri, json_encode($json, $json_options) . PHP_EOL)) {
    throw new \RuntimeException(t('Error writing composer.json file: @file', array('@file' => $file_uri)));
  }

  // Displays a message to admins that a file was written.
  if (user_access('administer site configuration')) {
    $command = file_exists($dir_uri . '/composer.lock') ? 'update' : 'install';
    drupal_set_message(t('A composer.json file was written to @path.', array('@path' => drupal_realpath($dir_uri))));
    if ('admin/config/system/composer-manager' != current_path()) {
      $args = array('!command' => $command, '@url' => url('http://drupal.org/project/composer_manager', array('absolute' => TRUE)));
      if ('install' == $command) {
        $message = t('Composer\'s <code>!command</code> command must be run to generate the autoloader and install the required packages.<br/>Refer to the instructions on the <a href="@url" target="_blank">Composer Manager project page</a> for installing packages.', $args);
      }
      else {
        $message = t('Composer\'s <code>!command</code> command must be run to install the required packages.<br/>Refer to the instructions on the <a href="@url" target="_blank">Composer Manager project page</a> for updating packages.', $args);
      }
      drupal_set_message($message, 'warning');
    }
  }
}

/**
 * Ensures the directory is created and protected via .htaccess if necessary.
 *
 * @param string $directory
 *   The URI or path to the directory being prepared.
 *
 * @return bool
 */
function composer_manager_prepare_directory($directory) {
  if (!file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    return FALSE;
  }
  if (0 === strpos($directory, 'public://')) {
    file_create_htaccess($directory, TRUE);
  }
  return TRUE;
}

/**
 * Compares the passed minimum stability requirements.
 *
 * @return int
 *   Returns -1 if the first version is lower than the second, 0 if they are
 *   equal, and 1 if the second is lower.
 *
 * @throws \UnexpectedValueException
 */
function composer_manager_compare_stability($a, $b) {
  $number = array(
    'dev' => 0,
    'alpha' => 1,
    'beta' => 2,
    'RC' => 3,
    'rc' => 3,
    'stable' => 4,
  );

  if (!isset($number[$a]) || !isset($number[$b])) {
    throw new \UnexpectedValueException(t('Unexpected value for "minimum-stability"'));
  }

  if ($number[$a] == $number[$b]) {
    return 0;
  }
  else {
    return $number[$a] < $number[$b] ? -1 : 1;
  }
}

/**
 * Returns the path for the autoloaded directory or class relative to the
 * directory containing the composer.json file.
 */
function composer_manager_relative_autoload_path(&$path, $key, $module) {
  static $dir_from = NULL;
  if (NULL === $dir_from) {
    $dir_from = composer_manager_file_dir();
  }
  $dir_to = drupal_realpath(DRUPAL_ROOT . '/' . drupal_get_path('module', $module) . '/' . $path);
  $path = composer_manager_relative_dir($dir_to, $dir_from);
}

/**
 * Returns the vendor directory relative to the composer file directory.
 *
 * @return string
 *
 * @throws \RuntimeException
 */
function composer_manager_relative_vendor_dir() {
  return composer_manager_relative_dir(
    composer_manager_vendor_dir(),
    composer_manager_file_dir()
  );
}

/**
 * Gets the path of the "to" directory relative to the "from" directory.
 *
 * @param array $dir_to
 *   The absolute path of the directory that the relative path refers to.
 * @param array $dir_from
 *   The absolute path of the directory from which the relative path is being
 *   calculated.
 *
 * @return string
 */
function composer_manager_relative_dir($dir_to, $dir_from) {
  $dirs_to = explode('/', ltrim($dir_to, '/'));
  $dirs_from = explode('/', ltrim($dir_from, '/'));

  // Strip the matching directories so that both arrays are relative to a common
  // position. The count of the $dirs_from array tells us how many levels up we
  // need to traverse from the directory containing the composer.json file, and
  // $dirs_to is relative to the common position.
  foreach ($dirs_to as $pos => $dir) {
    if (!isset($dirs_from[$pos]) || $dirs_to[$pos] != $dirs_from[$pos]) {
      break;
    }
    unset($dirs_to[$pos], $dirs_from[$pos]);
  }

  $path = str_repeat('../', count($dirs_from)) . join('/', $dirs_to);
  if (PHP_OS == 'WINNT'){
    $path = preg_replace('%..\\/([a-zA-Z])%i', '${1}', $path, 1);
  }
  return $path;
}
