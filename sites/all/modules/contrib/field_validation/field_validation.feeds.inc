<?php
/**
 * @file
 * Integration with feeds to support unique targets in mappers.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see field_feeds_processor_targets_alter().
 */
function field_validation_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  module_load_include('inc', 'ctools', 'includes/export');
  $rules = ctools_export_load_object('field_validation_rule', 'conditions', array('entity_type' => $entity_type, 'bundle' => $bundle_name, 'validator' => 'field_validation_unique_validator'));
  foreach ($rules as $rule) {
    if (!empty($rule->disabled)) {
      continue;
    }
    $targets[$rule->field_name]['optional_unique'] = TRUE;
    $targets[$rule->field_name]['unique_callbacks'][] = 'field_validation_feeds_existing_entity_id';
    $targets[$rule->field_name]['bundle_name'] = $bundle_name;
  }
}

/**
 * Callback for Feeds processor unique entity ID.
 *
 * @param string $target
 *   The unique field name, containing the value to be checked.
 * @param int|string $value
 *   The unique field value to be checked.
 * @param string $entity_type
 *   Entity type for the entity to be processed.
 * @param string $bundle_name
 *   Bundle name for the entity to be processed.
 *
 * @return int
 *   Feeds processor existing entity ID.
 *
 * @see field_validation_feeds_processor_targets_alter()
 * @see FeedsProcessor::existingEntityId()
 */
function field_validation_feeds_existing_entity_id($target, $value, $entity_type, $bundle_name) {
  module_load_include('inc', 'ctools', 'includes/export');
  $unique_rules = ctools_export_load_object('field_validation_rule', 'conditions', array('entity_type' => $entity_type, 'bundle' => $bundle_name, 'field_name' => $target, 'validator' => 'field_validation_unique_validator'));
  $unique_rule = reset($unique_rules);
  if (!empty($unique_rule)) {
    // Get unique entity ID from unique field value. Note that we are not using
    // field_validation_unique_validator::validate() because we don't want to
    // fire set_error().
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', $entity_type)
      ->entityCondition('bundle', $bundle_name)
      ->fieldCondition($target, $unique_rule->col, $value, '=')
      // Run the query as user 1.
      ->addMetaData('account', user_load(1))
      ->execute();
    if (isset($result[$entity_type])) {
      $ids = array_keys($result[$entity_type]);
      return reset($ids);
    }
  }
}