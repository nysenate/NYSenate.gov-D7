<?php

/**
 * @file
 *   drush integration for mobile_detect.
 *
 *   dl-mobile-detect is based on the command from http://drupal.org/project/views_infinite_scroll
 */

/**
 * Implements hook_drush_command().
 */
function mobile_detect_drush_command() {
  $items = array();

  $items['dl-mobile-detect'] = array(
    'description' => dt('Downloads the required Mobile_Detect.php library.'),
    'callback' => '_mobile_detect_drush_download',
    'options' => array(
      'git' => dt('Clone Mobile_Detect.php from GitHub instead of downloading.'),
    )
  );
  
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function mobile_detect_drush_help($section) {
  switch ($section) {
    case 'drush:dl-mobile-detect':
      return dt("Downloads the required Mobile_Detect.php library from GitHub.");
  }
}

/**
 * Callback for mobile-detect
 */
function _mobile_detect_drush_download() {
  if (module_exists('libraries')) {
    /* TODO: a site may not be using this path for libraries... not sure what API call to use to
     * determine the basepath for all libraries...
     */
    $path = 'sites/all/libraries/Mobile_Detect';
  }
  else {
    $path = 'sites/all/libraries/Mobile_Detect';
  }

  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }
  
  drush_op('chdir', $path);

  if (drush_get_option('git')) {
    if (is_dir('.git')) {
      $ok = drush_shell_exec('git pull');
      if ($ok) {
        drush_log(dt('Mobile_Detect.php has been updated from GitHub in @path', array('@path' => $path)), 'success');
      }
      else {
        drush_log(dt('Drush was unable to update Mobile_Detect.php from GitHub in @path', array('@path' => $path)), 'error');
      }
    }
    else {
      $ok = drush_shell_exec('git clone -n https://github.com/serbanghita/Mobile-Detect.git --depth 1 .');
      $ok = $ok && drush_shell_exec('git checkout HEAD Mobile_Detect.php');
      if ($ok) {
        drush_log(dt('Mobile_Detect.php has been cloned to @path', array('@path' => $path)), 'success');
      }
      else {
        drush_log(dt('Drush was unable to clone Mobile_Detect.php to @path', array('@path' => $path)), 'error');
      }
    }
    
  }
  else {
    if (drush_shell_exec('wget -N https://raw.github.com/serbanghita/Mobile-Detect/master/Mobile_Detect.php')) {
      drush_log(dt('Mobile_Detect.php has been downloaded to @path', array('@path' => $path)), 'success');
    }
    else {
      drush_log(dt('Drush was unable to download Mobile_Detect.php to @path', array('@path' => $path)), 'error');
    }
  }
}
