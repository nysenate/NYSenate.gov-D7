<?php
/**
 * @file
 * uuid features hooks on behalf of the microdata module.
 * @link https://www.drupal.org/project/microdata
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function microdata_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  // Remove microdata property. It's recreated based on the available data and
  // the entity configuration.
  unset($export->microdata);
}
