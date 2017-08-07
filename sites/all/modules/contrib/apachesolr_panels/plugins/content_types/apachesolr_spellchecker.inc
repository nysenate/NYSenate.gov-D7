<?php

if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'title' => t('Apache Solr spellcheck results'),
    'no title override' => FALSE,
    'icon' => 'icon_search.png',
    'description' => t('The results of the Apache Solr spellchecker, also known as "Did you mean?".'),
    'required context' => new ctools_context_optional(t('Context to fetch search query from'), 'string'),
    'category' => t('Apache Solr Search'),
    'hook theme' => 'apachesolr_panels_apachesolr_spellchecker_theme',
    'defaults' => array(
      'title_override' => FALSE,
      'title_override_text' => '',
    ),
    'render last' => TRUE, // This needs to be evaluated last so it can access the search results
  );
}

/**
 * Render the search results.
 */
function apachesolr_panels_apachesolr_spellchecker_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'apachesolr_panels';
  $block->delta = 'spellchecker';

  $query = apachesolr_current_query(variable_get('apachesolr_default_environment', 'default'));
  if ($query) {
    $searcher = $query->getSearcher();
  }

  $env_id =  variable_get('apachesolr_default_environment', 'default');
  if (variable_get('apachesolr_search_spellcheck', TRUE) && apachesolr_has_searched($env_id) && ($response = apachesolr_static_response_cache($searcher))) {
    // Get spellchecker suggestions into an array.
    if (isset($response->spellcheck->suggestions) && $response->spellcheck->suggestions) {
      $suggestions = get_object_vars($response->spellcheck->suggestions);
      $env_id = apachesolr_default_environment();
      // Allow modules to alter the spelling suggestions (for things like extended results).
      drupal_alter('apachesolr_suggestions', $suggestions, $env_id);
      if ($suggestions) {
        $replacements = array();
        // Get the original query and replace words.
        $query = apachesolr_current_query(variable_get('apachesolr_default_environment', 'default'));

        foreach ($suggestions as $word => $value) {
          // We need to check if it's an object as setting the spellcheck.extendedResults query parameter to true makes words
          // objects instead of strings.
          $replacements[$word] = is_object($value->suggestion[0]) ? $value->suggestion[0]->word : $value->suggestion[0];
        }
        $new_keywords = strtr($query->getParam('q'), $replacements);
        // Show only if suggestion is different than current query.
        if ($query->getParam('q') != $new_keywords) {
          $link = l($new_keywords, $query->getPath($new_keywords));
          $block->title = '';
          $block->content = theme('apachesolr_panels_spellcheck', array('link' => $link));
        }
      }
    }
  }
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function apachesolr_panels_apachesolr_spellchecker_theme(&$theme) {
  $theme['apachesolr_panels_spellcheck'] = array('arguments' => array(
    'link' => NULL,
  ));
}

/**
 * Theme spellchecker results.
 */
function theme_apachesolr_panels_spellcheck($variables) {
  return '<div class="spelling-suggestions"><span class="did-you-mean">' . t('Did you mean?') . '</span>' . $variables['link'] . '</div>';
}
