<?php

if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'title' => t('Apache Solr search information'),
    'description' => t('Information about an Apache Solr search.'),
    'icon' => 'icon_search.png',
    'category' => t('Apache Solr Search'),
    'hook theme' => 'apachesolr_panels_apachesolr_info_theme',
    'defaults' => array(
      'title_override' => FALSE,
      'title_override_text' => '',
    ),
  );
}

/**
 * Delegated implementation of hook_theme().
 */
function apachesolr_panels_apachesolr_info_theme(&$theme) {
  $theme['apachesolr_panels_info'] = array('arguments' => array(
    'response' => NULL,
    'search' => NULL,
  ));
}

/**
 * Execute the search and render results.
 */
function apachesolr_panels_apachesolr_info_content_type_render($subtype, $conf, $panel_args, $context) {
  $query = apachesolr_current_query(variable_get('apachesolr_default_environment', 'default'));
  if ($query) {
    $searcher = $query->getSearcher();
    $response = apachesolr_static_response_cache($searcher);
  }

  $search = apachesolr_panels_static_search_cache();

  if (empty($response) || empty($search)) {
    return;
  }

  $block = new stdClass();
  $block->module  = 'apachesolr_panels';
  $block->delta   = 'info';
  $block->title   = '';
  $block->content = theme('apachesolr_panels_info', array('response' => $response, 'search' => $search));

  return $block;
}

/**
 * Empty form so we can have the default override title.
 */
function apachesolr_panels_apachesolr_info_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Theme search result information.
 */
function theme_apachesolr_panels_info($variables) {
  $response = $variables['response'];
  $search = $variables['search'];
  if ($total = $response->response->numFound) {
    $start = $response->response->start + 1;
    $end = $response->response->start + count($response->response->docs);

    if (!empty($search['keys'])) {
      $info = t('Results %start - %end of %total for %keys', array('%start' => $start, '%end' => $end, '%total' => $total, '%keys' => $search['keys']));
    }
    else {
      $info = t('Results %start - %end of %total', array('%start' => $start, '%end' => $end, '%total' => $total));
    }

    return $info;
  }
}
