<?php

/**
 * @file
 * Plugin to handle an existing pages content.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Existing page'),
  'single' => TRUE,
  'defaults' => array(
    'task_id',
  ),
  'category' => t('Existing pages'),
  'all contexts' => TRUE,
);

/**
 * Output function for the existing page.
 */
function pm_existing_pages_pm_existing_pages_content_type_render($subtype, $conf, $panel_args) {

  $task = pm_existing_pages_get_existing_pages($conf['task_id']);
  if (!$task || empty($panel_args)) {
    return;
  }

  $menu_args = $panel_args[1];
  $pm_args = $panel_args[2];

  $function = $pm_args['pc'];
  $file = $pm_args['f'];
  $file_path = $pm_args['fp'];
  $module = $pm_args['m'];

  if ($file) {
    if (empty($file_path) && !empty($module)) {
      $file_path = drupal_get_path('module', $module);
    }
    require_once DRUPAL_ROOT . '/' . $file_path . '/' . $file;
  }
  $content = call_user_func_array($function, $menu_args);

  $block = new stdClass();
  $block->module = 'pm_existing_pages';
  $block->title = check_plain($task->label);
  $block->content = $content;

  return $block;
}

/**
 * Select the task/page.
 */
function pm_existing_pages_pm_existing_pages_content_type_edit_form($form, &$form_state) {
  $options = array('' => t('-- Select --'));

  $custom_tasks = pm_existing_pages_get_existing_pages();
  foreach ($custom_tasks as $task_id => $info) {
    $options[$task_id] = $info->label;
  }

  $form['task_id'] = array(
    '#required' => TRUE,
    '#title' => t('Existing page'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => isset($form_state['conf']['task_id']) ? $form_state['conf']['task_id'] : '',
  );

  return $form;
}

/**
 * Save the task selection.
 */
function pm_existing_pages_pm_existing_pages_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['task_id'] = $form_state['values']['task_id'];
}

/**
 * Returns the administrative title for the existing page.
 */
function pm_existing_pages_pm_existing_pages_content_type_admin_title($subtype, $conf) {
  $existing_page = pm_existing_pages_get_existing_pages($conf['task_id']);
  return t('Existing page: @title', array('@title' => $existing_page->label));
}

/**
 * Display the administrative information for a content pane.
 */
function pm_existing_pages_pm_existing_pages_content_type_admin_info($subtype, $conf) {
  return t('This pane will render on front end.');
}
