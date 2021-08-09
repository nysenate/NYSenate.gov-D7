<?php

/**
 * @file
 * nys_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nys_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_global';
  $context->description = '';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/global' => 'search/global',
        'search/global/*' => 'search/global/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-a032bdd6c1dfa3fb6227ac24bc48b1b6' => array(
          'module' => 'views',
          'delta' => 'a032bdd6c1dfa3fb6227ac24bc48b1b6',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  $export['search_global'] = $context;

  return $export;
}
