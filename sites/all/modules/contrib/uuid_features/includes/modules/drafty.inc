<?php
/**
 * @file
 * uuid features hooks on behalf of the drafty module.
 * @link https://www.drupal.org/project/drafty
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function drafty_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  // Remove drafty properties.
  unset($export->_drafty_revision_requested, $export->is_draft_revision);
}
