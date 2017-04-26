<?php

/**
 * @file
 * Handle the custom Page manager custom tasks.
 */

/**
 * Specialized implementation of hook_page_manager_task_tasks(). See api-task.html for
 * more information.
 */
function pm_existing_pages_pm_existing_pages_page_manager_tasks() {

  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',
    'title' => t('Existing page'),

    // There are multiple pages, let's override each of them
    // separately.
    'subtasks' => TRUE,
    'subtask callback' => 'pm_existing_pages_pm_existing_pages_subtask',
    'subtasks callback' => 'pm_existing_pages_pm_existing_pages_subtasks',

    // Menu hooks so that we can alter the node/%node menu entry to point to us.
    'hook menu alter' => 'pm_existing_pages_pm_existing_pages_menu_alter',

    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'pm_existing_pages_pm_existing_pages_get_arguments',
    'get context placeholders' => 'pm_existing_pages_pm_existing_pages_get_contexts',
  );
}

/**
 * Callback defined by pm_existing_pages_pm_existing_pages_page_manager_tasks().
 *
 * Override the page callbacks for custom tasks.
 */
function pm_existing_pages_pm_existing_pages_menu_alter(&$items, $task) {

  $custom_tasks = pm_existing_pages_get_existing_pages();
  foreach ($custom_tasks as $task_id => $task_info) {

    if (variable_get('pm_existing_pages_disabled_' . $task_id, TRUE)) {
      continue;
    }

    $paths = explode("\n", $task_info->paths);
    foreach ($paths as $path) {
      $path = trim($path);

      // Make sure we have a path.
      if (empty($path) || !isset($items[$path])) {
        drupal_set_message(t('%path has not been overridden because the menu item does not exist.', array('%path' => $path)));
        continue;
      }

      // Make sure we have a page callback. We silently continue here, as this
      // is a menu item that will inherit the page callback from its parent
      // menu item.
      if (empty($items[$path]['page callback'])) {
        continue;
      }

      // Add more page arguments.
      $pm_args = array(
        'ti' => $task_id,
        'pc' => $items[$path]['page callback'],
        'f' => isset($items[$path]['file']) ? $items[$path]['file'] : '',
        'fp' => isset($items[$path]['file path']) ? $items[$path]['file path'] : '',
        'm' => isset($items[$path]['module']) ? $items[$path]['module'] : '',
      );
      $page_arguments = isset($items[$path]['page arguments']) ? $items[$path]['page arguments'] : array();
      $page_arguments[] = $pm_args;
      $items[$path]['page callback'] = 'pm_existing_pages_pm_existing_pages_page';
      $items[$path]['page arguments'] = $page_arguments;
      $items[$path]['file path'] = $task['path'];
      $items[$path]['file'] = $task['file'];
    }
  }
}

/**
 * Entry point for our overridden task page.
 */
function pm_existing_pages_pm_existing_pages_page() {
  $args = func_get_args();

  // Determine which are the menu and pmep arguments.
  $split_args = _pm_existing_pages_get_pm_args($args);
  $menu_args = $split_args['menu'];

  // Get pmep arguments.
  $pm_args = $split_args['pmep'];
  $task_id = $pm_args['ti'];
  $function = $pm_args['pc'];
  $file = $pm_args['f'];
  $file_path = $pm_args['fp'];
  $module = $pm_args['m'];

  // Load task plugin.
  $task = page_manager_get_task('pm_existing_pages');
  $subtask = page_manager_get_task_subtask($task, $task_id);

  // Render through CTools.
  ctools_include('context');
  ctools_include('context-task-handler');
  $context_args = _pm_existing_pages_get_context_arguments($menu_args, $pm_args, $task_id);
  $contexts = ctools_context_handler_get_task_contexts($task, $subtask, array($context_args[0]));
  $output = ctools_context_handler_render($task, $subtask, $contexts, array($context_args[1], $menu_args, $pm_args));
  if ($output !== FALSE) {
    return $output;
  }

  // Fallback.
  if ($file) {
    if (empty($file_path) && !empty($module)) {
      $file_path = drupal_get_path('module', $module);
    }
    require_once DRUPAL_ROOT . '/' . $file_path . '/' . $file;
  }
  return call_user_func_array($function, $menu_args);
}

/**
 * Callback to get arguments provided by this task handler.
 */
function pm_existing_pages_pm_existing_pages_get_arguments($task, $subtask_id) {
  return _pm_existing_pages_get_context($task, $subtask_id);
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function pm_existing_pages_pm_existing_pages_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(pm_existing_pages_pm_existing_pages_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function pm_existing_pages_pm_existing_pages_enable($cache, $status) {
  variable_set('pm_existing_pages_disabled_' . $cache->subtask_id, $status);

  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['page_manager_enabling_search'] = TRUE;
  }
}

/**
 * Task callback to get all subtasks.
 */
function pm_existing_pages_pm_existing_pages_subtasks($task) {
  $return = array();

  $custom_tasks = pm_existing_pages_get_existing_pages();
  foreach ($custom_tasks as $task_id => $info) {
    $return[$task_id] = pm_existing_pages_pm_existing_pages_build_subtask($task, $task_id);
  }

  return $return;
}

/**
 * Callback to return a single subtask.
 */
function pm_existing_pages_pm_existing_pages_subtask($task, $subtask_id) {
  return pm_existing_pages_pm_existing_pages_build_subtask($task, $subtask_id);
}

/**
 * Build a subtask array for a given page.
 */
function pm_existing_pages_pm_existing_pages_build_subtask($task, $task_id) {
  $info = pm_existing_pages_get_existing_pages($task_id);
  $paths = explode("\n", $info->paths);
  $main_path = $paths[0];
  $subtask = array(
    'name' => $task_id,
    'admin title' => check_plain($info->label),
    'admin path' => check_plain($main_path),
    'admin description' => check_plain($info->label),
    'admin type' => t('Existing'),
    'storage' => t('In code'),
    'disabled' => variable_get('pm_existing_pages_disabled_' . $task_id, TRUE),
    'enable callback' => 'pm_existing_pages_pm_existing_pages_enable',
  );

  return $subtask;
}

/**
 * Get the context for task and subtask.
 */
function _pm_existing_pages_get_context($task, $subtask) {
  $existing_page = pm_existing_pages_get_existing_pages($subtask['name']);
  if (!$existing_page || empty($existing_page->context)) {
    return array();
  }

  list($type, $info, $other) = explode('|', $existing_page->context);
  switch ($type) {
    case 'entity':
      return array(
        array(
          'keyword' => $info,
          'identifier' => t('@type being viewed', array('@type' => ucfirst(check_plain($info)))),
          'id' => 1,
          'name' => 'entity_id:' . $info,
          'settings' => array(),
        )
      );
      break;
  }

  // Nothing found.
  return array();
}

/**
 * Get the arguments for context - if possible.
 *
 * We probably need to look at _menu_load_objects() for more
 * inspiration to get this completely right.
 *
 * @param $args
 *   The arguments passed by the menu.
 * @param $pm_args
 *   The page manager arguments.
 * @param $task_id
 *   The name of
 *
 * @return $context_args
 *   A collection of arguments we need for CTools.
 */
function _pm_existing_pages_get_context_arguments($menu_args, $pm_args, $task_id) {

  // If no menu arguments, we can skip.
  if (empty($menu_args)) {
    return array(0 => '', 1 => '');
  }

  $existing_page = pm_existing_pages_get_existing_pages($task_id);
  if (!empty($existing_page->context)) {
    list($type, $info, $other) = explode('|', $existing_page->context);
    switch ($type) {
      case 'entity':
        $position = 1;
        $router_item = menu_get_item();
        $lf = is_array($router_item['load_functions']) ? $router_item['load_functions'] : array();
        foreach ($lf as $pos => $function) {
          if ($function == $info . '_load') {
            $position = $pos;
            break;
          }
        }
        $object = menu_get_object($info, $position);
        if ($object) {
          return array(
            0 => $object,
            1 => $object->{$other},
          );
        }
        break;
    }
  }

  // Nothing found.
  return array(0 => '', 1 => '');
}

/**
 * Helper function to split menu arguments from pm arguments.
 *
 * We don't know if there will be any additional arguments
 * send along through the URL which are not menu loader
 * arguments or unknown in the menu router path. So
 * depending on the path, the array we need for pmep
 * can be the first or last.
 *
 * @param $args
 *   A collection of arguments.
 */
function _pm_existing_pages_get_pm_args($args) {

  $arguments = array('menu' => array(), 'pmep' => array());

  foreach ($args as $key => $value) {
    if (is_array($value) && isset($value['ti'])) {
      // Supposing this pmep argument.
      $arguments['pmep'] = $args[$key];
    }
    else {
      $arguments['menu'][] = $value;
    }
  }

  return $arguments;
}
