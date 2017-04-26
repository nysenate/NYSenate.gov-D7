<?php

/**
 * @file
 * Provides feeds implementation hooks for feeds_rules.
 */

/**
 * Implements hook_feeds_plugins().
 */
function feeds_rules_feeds_plugins() {
  $info = array();
  $info['FeedsRulesProcessor'] = array(
    'name' => 'Rules processor',
    'description' => 'Pass data to rules.',
    'help' => 'Handle parsed content by passing it to any defined rule.',
    'handler' => array(
      'parent' => 'FeedsProcessor',
      'class' => 'FeedsRulesProcessor',
      'file' => 'FeedsRulesProcessor.inc',
      'path' => drupal_get_path('module', 'feeds_rules') .'/plugins',
    ),
  );
  return $info;
}

/**
 * Implements hook_feeds_before_import().
 */
function feeds_rules_feeds_before_import(FeedsSource $source) {
  rules_invoke_event('feeds_before_import', $source);
}

/**
 * Implements hook_feeds_after_import().
 */
function feeds_rules_feeds_after_import(FeedsSource $source) {
  rules_invoke_event('feeds_after_import', $source);
}
