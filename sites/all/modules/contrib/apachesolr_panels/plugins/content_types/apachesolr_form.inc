<?php

if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'title' => t('Apache Solr search form'),
    'icon' => 'icon_search.png',
    'description' => t('A search form for Apache Solr.'),
    'category' => t('Apache Solr Search'),
    'defaults' => array(
      'path_type' => 'same',
      'path' => '',
      'override_prompt' => FALSE,
      'prompt' => '',
      'show_keys' => TRUE,
    ),
  );
}

/**
 * Render a search form for Apache Solr.
 */
function apachesolr_panels_apachesolr_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module  = 'search';
  $block->delta   = 'form';
  $block->title   = '';

  $search = apachesolr_panels_static_search_cache();

  // Set destination path depending on setting.
  switch ($conf['path_type']) {
    default:
    case 'same':
      $menu_item = menu_get_item();
      $path = $menu_item['href'];
      break;
    case 'custom':
      $path = $conf['path'];
      break;
  }

  // Set keys depending on setting.
  if ($conf['show_keys'] && $search) {
    $keys = $search['keys'];
  }
  else {
    $keys = '';
  }

  // Set prompt depending on setting.
  $prompt = $conf['override_prompt'] ? $conf['prompt'] : NULL;

  module_load_include('inc', 'search', 'search.pages');

  $form_state = array(
    'no_redirect' => TRUE,
    'args' => array(url($path), $keys, 'apachesolr_panels', $prompt),
  );

  $block->content = drupal_build_form('apachesolr_panels_search_form', $form_state);

  // We do the redirect manually because the built in search form is stupid
  // and won't redirect even though action is a valid argument for it.
  if (!empty($form_state['submitted'])) {
    drupal_goto($path . '/' . $form_state['values']['apachesolr_panels_search_form']);
  }

  return $block;
}

/**
 * Panel plugin edit form.
 */
function apachesolr_panels_apachesolr_form_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['path_type'] = array(
    '#prefix' => '<div class="container-inline">',
    '#type' => 'select',
    '#title' => t('Path'),
    '#options' => array(
      'same' => t('Same page'),
      'custom' => t('Custom'),
    ),
    '#default_value' => $conf['path_type'],
  );

  $form['path'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['path'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-path-type' => array('custom')),
    '#suffix' => '</div>',
  );

  $form['override_prompt'] = array(
    '#prefix' => '<div class="container-inline">',
    '#type' => 'checkbox',
    '#default_value' => $conf['override_prompt'],
    '#title' => t('Override default prompt'),
  );

  $form['prompt'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['prompt'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-override-prompt' => array(1)),
    '#suffix' => '</div>',
  );

  $form['show_keys'] = array(
    '#title' => t('Show current search keys'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_keys'],
  );

  return $form;
}

/**
 * Handle submission of edit form.
 */
function apachesolr_panels_apachesolr_form_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function apachesolr_panels_form_apachesolr_panels_search_form_alter(&$form, &$form_state) {
  // These don't work in D7 any more.
  //$form['#validate'] = array('search_form_validate');
  //$form['#submit'] = array('search_form_submit');

  // Set the default keys
  $keys = $form_state['args'][1];
  $form['apachesolr_panels_search_form']['#default_value'] = $keys;

  // Set the prompt:
  if (!is_null($form_state['args'][3])) {
    $form['apachesolr_panels_search_form']['#attributes']['title'] = $form_state['args'][3];
  }

  // Support the Apache Solr Autocomplete module if it exists.
  if (module_exists('apachesolr_autocomplete')) {
    $form['basic']['inline']['keys']['#autocomplete_path'] = 'apachesolr_autocomplete';
  }
}
