<?php

if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'no title override' => TRUE,
    'title' => t('Apache Solr search results'),
    'icon' => 'icon_search.png',
    'description' => t('The results of an Apache Solr search.'),
    'required context' => new ctools_context_optional(t('Context to fetch search query from'), 'string'),
    'render callback' => 'apachesolr_panels_apachesolr_result_content_type_render',
    'edit form' => 'apachesolr_panels_apachesolr_result_content_type_edit_form',
    'category' => t('Apache Solr Search'),
    'defaults' => array(
      'keys_action' => 'none',
      'keys' => '',
      'keys_required' => TRUE,
      'filters_action' => 'none',
      'filters' => '',
      'rows' => 10,
      'env_id' => '',
      'sort_action' => 'none',
      'sort' => '',
      'breadcrumb' => TRUE,
      'title_override' => FALSE,
      'title_override_text' => '',
      'empty_override' => FALSE,
      'empty_override_title' => '',
      'empty_override_text' => '',
      'empty_override_format' => filter_fallback_format(),
      'log' => FALSE,
      'substitute' => FALSE,
    ),
    'render first' => TRUE,
  );
}

/**
 * Render the search results.
 */
function apachesolr_panels_apachesolr_result_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'apachesolr_panels';
  $block->delta = 'results';

  $search = array(
    'keys' => '',
    'filters' => isset($_GET['filters']) ? $_GET['filters'] : '',
    'sort' => isset($_GET['solrsort']) ? $_GET['solrsort'] : '',
  );

  // Use keywords from the selected context if set to do so.
  if (!empty($context) && !empty($context->data)) {
    $search['keys'] = $context->data;
  }

  $display = panels_get_current_page_display();

  // Alter the search parts to use substitutions. Override, append or use a
  // fallback depending on the setting for each part.
  foreach ($search as $key => $value) {
    $value = trim($value);

    if ($conf[$key . '_action'] != 'none' && !empty($conf['substitute']) && !empty($display->context)) {
      $conf[$key] = ctools_context_keyword_substitute($conf[$key], array(), $display->context);
    }

    if ($conf[$key . '_action'] == 'append') {
      $search[$key] .= ' ' . $conf[$key];
    }
    elseif (($conf[$key . '_action'] == 'fallback' && empty($value)) || $conf[$key . '_action'] == 'override') {
      $search[$key] = $conf[$key];
    }
  }

  // Add remaining search information.
  $menu_item = menu_get_item();
  $search['path'] = $menu_item['href'];
  $search['page'] = pager_find_page();
  $search['rows'] = isset($conf['rows']) ? $conf['rows'] : 10;
  $search['env_id'] = isset($conf['env_id']) ? $conf['env_id'] : '';

  if (!empty($conf['log'])) {
    watchdog('search', '%keys (@type).', array('%keys' => $search['keys'], '@type' => t('Search')), WATCHDOG_NOTICE, l(t('results'), $_GET['q']));
  }

  $results = NULL;

  // Execute the search if we have keywords or if keywords aren't required.
  if (!empty($search['keys']) || !$conf['keys_required']) {
    // If set to not show keywords and filters in the breadcrumb trail, first
    // store the original before being changed by the Apache Solr module.
    if (empty($conf['breadcrumb'])) {
      $breadcrumb = drupal_get_breadcrumb();
    }

    try {
      $results = apachesolr_panels_search_execute($search);

      // Don't render suggestions. Use spellchecker pane instead.
      if (isset($results['suggestions'])) {
        unset($results['suggestions']);
      }

      // Restore the original breadcrumb trail if set to do so.
      if (empty($conf['breadcrumb'])) {
        drupal_set_breadcrumb($breadcrumb);
      }
    } catch (Exception $e) {
      watchdog('Apache Solr', nl2br(check_plain($e->getMessage())), NULL, WATCHDOG_ERROR);
    }
  }

  if ($results) {
    // Add title and results.
    if (!empty($conf['title_override'])) {
      if (!empty($conf['substitute']) && !empty($display->context)) {
        $conf['title_override_text'] = ctools_context_keyword_substitute($conf['title_override_text'], array(), $display->context);
      }
      $block->title = $conf['title_override_text'];
    }
    else {
      $block->title = t('Search results');
    }
    $block->content = $results;
  }
  elseif (!empty($search['keys'])) {
    // Show empty text, either overridden or the default.
    if (!empty($conf['empty_override'])) {
      if (!empty($conf['substitute']) && !empty($display->context)) {
        $conf['empty_override_title'] = ctools_context_keyword_substitute($conf['empty_override_title'], array(), $display->context);
        $conf['empty_override_text']['value'] = ctools_context_keyword_substitute($conf['empty_override_text']['value'], array(), $display->context);
      }
      $block->title = $conf['empty_override_title'];
      $block->content = check_markup($conf['empty_override_text']['value'], $conf['empty_override_format'], $langcode = '' /* TODO Set this variable. */, FALSE);
    }
    else {
      $block->title = t('Your search yielded no results');
      $block->content = search_help('search#noresults', drupal_help_arg());
    }
  }

  return $block;
}

/**
 * Return an edit form for the pane's settings.
 */
function apachesolr_panels_apachesolr_result_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $action_options = array(
    'none' => t('From context'),
    'override' => t('Override'),
    'append' => t('Append to'),
    'fallback' => t('Fallback if empty'),
  );

  $form['keys_action'] = array(
    '#prefix' => '<div class="form-item container-inline">',
    '#title' => t('Keywords'),
    '#type' => 'select',
    '#options' => $action_options,
    '#default_value' => $conf['keys_action'],
  );

  $form['keys'] = array(
    '#title' => '',
    '#type' => 'textfield',
    '#default_value' => $conf['keys'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-keys-action' => array('fallback', 'override', 'append')),
  );

  $form['keys_required'] = array(
    '#title' => t('Required'),
    '#type' => 'checkbox',
    '#default_value' => $conf['keys_required'],
    '#suffix' => '</div>',
  );

  $form['filters_action'] = array(
    '#prefix' => '<div class="form-item container-inline">',
    '#title' => t('Filters'),
    '#type' => 'select',
    '#options' => $action_options,
    '#default_value' => $conf['filters_action'],
  );

  $form['filters'] = array(
    '#title' => '',
    '#type' => 'textfield',
    '#default_value' => $conf['filters'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-filters-action' => array('fallback', 'override', 'append')),
    '#suffix' => '</div>',
  );

  $form['sort_action'] = array(
    '#prefix' => '<div class="form-item container-inline">',
    '#title' => t('Sort'),
    '#type' => 'select',
    '#options' => $action_options,
    '#default_value' => $conf['sort_action'],
  );

  $form['sort'] = array(
    '#title' => '',
    '#type' => 'textfield',
    '#default_value' => $conf['sort'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-sort-action' => array('fallback', 'override', 'append')),
    '#suffix' => '</div>',
  );
  $form['rows'] = array(
    '#prefix' => '<div class="form-item container-inline">',
    '#title' => t('Results per page'),
    '#type' => 'textfield',
    '#default_value' => isset($conf['rows']) ? $conf['rows'] : 10,
    '#suffix' => '</div>',
  );
  $form['env_id'] = array(
    '#prefix' => '<div class="form-item container-inline">',
    '#title' => t('Solr Environment ID'),
    '#description' => t('The machine name of the Solr environment, as defined in the Settings page of the Apache Solr module'),
    '#type' => 'textfield',
    '#default_value' => isset($conf['env_id']) ? $conf['env_id'] : '',
    '#suffix' => '</div>',
  );

  $form['title_override'] = array(
    '#title' => t('Override title'),
    '#type' => 'checkbox',
    '#default_value' => $conf['title_override'],
  );

  $form['title_override_text'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['title_override_text'],
    '#size' => 35,
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-title-override' => array(1)),
  );

  $form['empty_override'] = array(
    '#title' => t('Override "no result" text'),
    '#type' => 'checkbox',
    '#default_value' => $conf['empty_override'],
  );

  $form['empty_override_field']['empty_override_title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $conf['empty_override_title'],
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('edit-empty-override' => array(1)),
  );

  $form['empty_override_field']['empty_override_text'] = array(
    '#title' => t('No result text'),
    '#type' => 'text_format',
    '#base_type' => 'textarea',
    '#default_value' => $conf['empty_override_text'],
    '#format' => $conf['empty_override_format'],
    '#process' => array('filter_process_format', 'ctools_dependent_process'),
    '#dependency' => array('edit-empty-override' => array(1)),
    '#id' => 'edit-empty-override-text-value',
    '#prefix' => '<div id="edit-empty-override-text-value-wrapper">',
    '#suffix' => '</div>',
  );

  $form['breadcrumb'] = array(
    '#title' => t('Show keywords and filters in the breadcrumb trail'),
    '#type' => 'checkbox',
    '#default_value' => $conf['breadcrumb'],
  );

  $form['log'] = array(
    '#title' => t('Record a watchdog log entry when searches are made'),
    '#type' => 'checkbox',
    '#default_value' => $conf['log'],
  );

  // Substitutions.
  if (!empty($form_state['contexts'])) {
    $form['substitute'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use context keywords'),
      '#description' => t('If checked, context keywords will be substituted in this content.'),
      '#default_value' => !empty($conf['substitute']),
    );
    $form['contexts'] = array(
      '#title' => t('Substitutions'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $header = array(t('Keyword'), t('Value'));

    $rows = array();
    foreach ($form_state['contexts'] as $context) {
      foreach (ctools_context_get_converters('%' . check_plain($context->keyword) . ':', $context) as $keyword => $title) {
        $rows[] = array(
          check_plain($keyword),
          t('@identifier: @title', array('@title' => $title, '@identifier' => $context->identifier)),
        );
      }
    }

    $form['contexts']['context'] = array('#value' => theme('table', array('header' => $header, 'rows' => $rows)));
  }

  return $form;
}

/**
 * Handle submission of edit form.
 */
function apachesolr_panels_apachesolr_result_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }

  // Save the format in $conf['empty_override_format'] for easy backwards-compatibility.
  if ($form_state['values']['empty_override_text']['format']) {
    $form_state['conf']['empty_override_format'] = $form_state['values']['empty_override_text']['format'];
  }
}
