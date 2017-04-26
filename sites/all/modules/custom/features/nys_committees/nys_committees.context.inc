<?php
/**
 * @file
 * nys_committees.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nys_committees_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'committee_content';
  $context->description = 'Committee Actionbar should be shown when committee is assigned.';
  $context->tag = 'Pages';
  $context->conditions = array(
    'assigned_committee' => array(
      'values' => array(
        'node_type' => 'a:25:{s:5:"event";s:5:"event";s:7:"meeting";s:7:"meeting";s:14:"public_hearing";s:14:"public_hearing";s:7:"article";s:7:"article";s:11:"in_the_news";s:11:"in_the_news";s:13:"press_release";s:13:"press_release";s:5:"video";s:5:"video";s:13:"questionnaire";s:13:"questionnaire";s:6:"agenda";i:0;s:4:"bill";i:0;s:8:"calendar";i:0;s:10:"resolution";i:0;s:7:"session";i:0;s:10:"transcript";i:0;s:5:"photo";i:0;s:9:"open_data";i:0;s:7:"chapter";i:0;s:18:"promotional_banner";i:0;s:7:"senator";i:0;s:10:"initiative";i:0;s:12:"page_content";i:0;s:8:"petition";i:0;s:15:"student_program";i:0;s:13:"timeline_item";i:0;s:7:"webform";i:0;}',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
  t('Committee Actionbar should be shown when committee is assigned.');
  t('Pages');
  $export['committee_content'] = $context;

  return $export;
}
