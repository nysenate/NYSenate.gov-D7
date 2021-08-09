<?php
/**
 * @file
 * Find active contributed modules drush command.
 */

/**
 * Implements hook_drush_command().
 */
function find_active_contrib_drush_command() {
  $items['find-active-contrib'] = array(
    'description' => 'Generates a file containing a list of active contributed modules for $alias in the form e.g. views-3.18',
    'aliases' => array('fac'),
    'arguments' => array(
      'alias' => 'Drush alias of the site to check',
    ),
    'options' => array(
      'to' => 'The path where the file should be created. Defaults to the current directory.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_NONE,
    'examples' => [
      'drush fac @example.com --to=~/Downloads' => "Creates a file called active_contrib_list.txt in the user's Downloads/ directory",
      'drush @example.com dl -y $(cat ~/Downloads/active_contrib_list.txt)' => "Download all currently installed active contrib to identify patches"
    ],
  );

  return $items;
}

function drush_find_active_contrib($alias = FALSE) {
  if (!$alias) {
    return drush_set_error(dt('The Drush alias of the site to check is required'));
  }
  $modules = drush_invoke_process($alias, 'pml', NULL, [
    'format' => 'var_export',
    'status' => 'enabled',
    'type' => 'module',
    'no-core' => TRUE,
    'quiet' => TRUE,
  ]);

  $path = drush_get_option('to', getcwd()) . '/active_contrib_list.txt';
  try {
    $handle = fopen($path, 'w+');
    if (!$handle) {
      throw new Exception('File open failed', 900);
    }
    $filtered_list = [];
    foreach ($modules['object'] as $machine_name => $value) {
      // Don't bother with custom modules.
      $prefix = substr($machine_name, 0, 4);
      if ($prefix == 'nys_') {
        continue;
      }
      // Filter out sub-modules.
      $pmi = drush_invoke_process($alias, 'pmi', [$machine_name], [
        'format' => 'var_export',
        'quiet' => TRUE,
      ]);
      $info = reset($pmi['object']);
      if ($machine_name != $info['project']) {
        continue;
      }
      $filtered_list[$machine_name] = $value;
    }
    $array_keys = array_keys($filtered_list);
    $last_key = array_pop($array_keys);
    foreach ($filtered_list as $machine_name => $value) {
      $ver = substr($value['version'], 3);
      if ($machine_name == $last_key) {
        fwrite($handle, $machine_name . $ver);
        break;
      }
      fwrite($handle, $machine_name . $ver . ',');
    }
    fclose($handle);
  }
  catch (Exception $e) {
    switch ($e->getCode()) {
      case 900:
        return drush_set_error(dt($e->getMessage() . ' at @path', ['path' => $path]));
    }
  }
}
