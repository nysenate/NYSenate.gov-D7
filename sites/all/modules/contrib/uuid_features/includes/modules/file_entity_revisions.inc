<?php
/**
 * @file
 * uuid features hooks on behalf of the file entity module.
 */

/**
 * Implements hook_uuid_entity_features_export_alter().
 */
function file_entity_revisions_uuid_entity_features_export_alter($entity_type, &$data, $entity, $module) {
  if ($entity_type != 'file') {
    return;
  }
  // Remove revision id.
  unset($data->vid);
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function file_entity_revisions_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  if ($entity_type != 'file') {
    return;
  }
  // Set latest revision id if possible.
  if (isset($entity->fid)) {
    $existing_file = file_entity_revision_load($entity->fid, NULL, TRUE);
    $entity->vid = $existing_file->vid;
  }
}
