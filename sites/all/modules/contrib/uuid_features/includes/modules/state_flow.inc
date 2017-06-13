<?php
/**
 * @file
 * uuid features hooks on behalf of the state_flow module.
 */

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function state_flow_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  // The state flow module adds a copy of the entity object which leads to an
  // endless loop in the export.
  unset($export->state_flow);

  // Remove current state timestamp, otherwise we've always an overridden state.
  // Remove published_revision_id as we only export the current version.
  unset(
    $export->current_state_timestamp,
    $export->published_revision_id
  );
}
