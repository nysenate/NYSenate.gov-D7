<?php
/**
 * @file
 * uuid_node hooks on behalf of the taxonomy module.
 */

/**
 * Implements hook_uuid_node_features_export_render_alter().
 */
function taxonomy_uuid_node_features_export_alter(&$export, $node) {
  // Access / modify the pipe.
  $pipe = &$export['__drupal_alter_by_ref']['pipe'];
  if (!empty($node->taxonomy)) {
    foreach ($node->taxonomy as $term) {
      $vocabulary = taxonomy_vocabulary_load($term->vid);
      $voc_uuid = $vocabulary->machine_name;
      $pipe['uuid_vocabulary'][$voc_uuid] = $voc_uuid;

      $term_uuid = $term->uuid;
      $pipe['uuid_term'][$term_uuid] = $term_uuid;
    }
  }
}

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function taxonomy_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  $fields = uuid_features_get_field_items_iterator($export, $entity_type, 'taxonomy_term_reference');
  uuid_features_set_uuid_references($fields, 'taxonomy_term');
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function taxonomy_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'taxonomy_term_reference');
  uuid_features_fetch_uuid_references($fields, 'taxonomy_term', array(
    'tid' => 'tid',
  ));
}
