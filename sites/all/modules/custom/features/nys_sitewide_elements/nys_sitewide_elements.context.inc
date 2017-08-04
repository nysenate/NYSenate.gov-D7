<?php
/**
 * @file
 * nys_sitewide_elements.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nys_sitewide_elements_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about';
  $context->description = '';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about' => 'about',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-about_hero' => array(
          'module' => 'nys_blocks',
          'delta' => 'about_hero',
          'region' => 'hero',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('pages');
  $export['about'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_elements';
  $context->description = 'Sitewide elements for the site.';
  $context->tag = 'Pages';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~senator_microsite' => '~senator_microsite',
        '~user_dashboard' => '~user_dashboard',
      ),
    ),
    'path' => array(
      'values' => array(
        '*' => '*',
        '~<front>' => '~<front>',
        '~home' => '~home',
        '~admin*' => '~admin*',
        '~user/*/edit' => '~user/*/edit',
        '~node/*/edit' => '~node/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-sitewide_header_bar_block' => array(
          'module' => 'nys_blocks',
          'delta' => 'sitewide_header_bar_block',
          'region' => 'header',
          'weight' => '-10',
        ),
        'nys_blocks-sitewide_actionbar_block' => array(
          'module' => 'nys_blocks',
          'delta' => 'sitewide_actionbar_block',
          'region' => 'header',
          'weight' => '-9',
        ),
        'nys_blocks-sitewide_footer' => array(
          'module' => 'nys_blocks',
          'delta' => 'sitewide_footer',
          'region' => 'footer_last',
          'weight' => '-10',
        ),
        'menu-menu-global-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-global-footer',
          'region' => 'footer_last',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  t('Sitewide elements for the site.');
  $export['sitewide_elements'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'taxonomy_issue';
  $context->description = 'Issue taxonomy page detail';
  $context->tag = 'Taxonomy Detail';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'issues' => 'issues',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
  t('Issue taxonomy page detail');
  t('Taxonomy Detail');
  $export['taxonomy_issue'] = $context;

  return $export;
}
