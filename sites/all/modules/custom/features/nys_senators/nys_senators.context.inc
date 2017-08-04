<?php
/**
 * @file
 * nys_senators.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nys_senators_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'senator_microsite';
  $context->description = 'Senator Microsite elements, blocks and views.';
  $context->tag = 'Pages';
  $context->conditions = array(
    'assigned_senator' => array(
      'values' => array(
        'node_type' => 'a:29:{s:5:"event";s:5:"event";s:7:"article";s:7:"article";s:11:"in_the_news";s:11:"in_the_news";s:13:"press_release";s:13:"press_release";s:5:"video";s:5:"video";s:10:"initiative";s:10:"initiative";s:8:"petition";s:8:"petition";s:13:"questionnaire";s:13:"questionnaire";s:6:"agenda";i:0;s:7:"meeting";i:0;s:14:"public_hearing";i:0;s:4:"bill";i:0;s:8:"calendar";i:0;s:10:"resolution";i:0;s:7:"session";i:0;s:10:"transcript";i:0;s:5:"photo";i:0;s:9:"open_data";i:0;s:14:"paragraph_page";i:0;s:6:"school";i:0;s:7:"chapter";i:0;s:18:"promotional_banner";i:0;s:7:"senator";i:0;s:12:"page_content";i:0;s:15:"student_program";i:0;s:13:"timeline_item";i:0;s:7:"webform";i:0;s:7:"statute";i:0;s:4:"test";i:0;}',
      ),
    ),
    'path_raw' => array(
      'values' => array(
        'senators/*/about' => 'senators/*/about',
        'senators/*/newsroom' => 'senators/*/newsroom',
        'senators/*/calendar' => 'senators/*/calendar',
        'senators/*/message' => 'senators/*/message',
        'senators/*/contact' => 'senators/*/contact',
        'senators/*/legislation' => 'senators/*/legislation',
        'senators/*/thankful-2016' => 'senators/*/thankful-2016',
        'senators/*/earthday-2017' => 'senators/*/earthday-2017',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-micro_header_bar_block' => array(
          'module' => 'nys_blocks',
          'delta' => 'micro_header_bar_block',
          'region' => 'header',
          'weight' => '-81',
        ),
        'views-nys_senator_hero-block' => array(
          'module' => 'views',
          'delta' => 'nys_senator_hero-block',
          'region' => 'header',
          'weight' => '-80',
        ),
        'nys_blocks-microsite_nav_block' => array(
          'module' => 'nys_blocks',
          'delta' => 'microsite_nav_block',
          'region' => 'header',
          'weight' => '-10',
        ),
        'nys_blocks-micro_footer' => array(
          'module' => 'nys_blocks',
          'delta' => 'micro_footer',
          'region' => 'footer_middle',
          'weight' => '-10',
        ),
        'menu-menu-global-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-global-footer',
          'region' => 'footer_last',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  t('Senator Microsite elements, blocks and views.');
  $export['senator_microsite'] = $context;

  return $export;
}
