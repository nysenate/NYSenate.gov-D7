<?php

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets()
 */
function blockreference_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'blockreference') {
      $targets[$name . ':moddelta'] = array(
        'name' => check_plain($instance['label']) . ' (moddelta)',
        'callback' => 'blockreference_feeds_set_target',
        'description' => t('The field instance @label of @field_name matched by moddelta.', array(
          '@label' => $instance['label'],
          '@field_name' => $name,
        )),
        'real_target' => $name,
      );
    }
  }
}

/**
 * Block reference callback for mapping.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 *
 * @param $source
 *   A FeedsSource object.
 * @param $entity
 *   The entity to map to.
 * @param $target
 *   The target key on $entity to map to.
 * @param $value
 *   The value to map. MUST be an array.
 */
function blockreference_feeds_set_target($source, $entity, $target, $value) {
  // Assume that the passed in value could really be any number of values.
  $values = array_filter((array) $value);

  // Don't do anything if we weren't given any data.
  if (!$value) {
    return;
  }

  list($target, $match_key) = explode(':', $target, 2);

  // Set the language of the field depending on the mapping.
  $language = isset($mapping['language']) ? $mapping['language'] : LANGUAGE_NONE;

  // Iterate over all values.
  $items = array();
  foreach ($values as $value) {
    @list($module, $delta) = explode(':', $value);
    if ($module && $delta) {
      $exists = db_query('SELECT bid FROM {block} WHERE module = ? AND delta = ?', array($module, $delta))->fetchField();
      if ($exists) {
        $items[$language][]['moddelta'] = $value;
      }
    }
  }

  $entity->$target = $items;
}
