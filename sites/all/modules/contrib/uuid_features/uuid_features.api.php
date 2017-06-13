<?php
/**
 * @file
 * Hooks provided by the UUID Features module.
 */

/**
 * Allows to modify features metadata for an entity.
 *
 * @param string $entity_type
 *   The entity type to export.
 * @param array $data
 *   The array of the features export data
 * @param object $entity
 *   The entity to export
 * @param string $module
 *   The module to export for..
 */
function hook_uuid_entity_features_export_alter($entity_type, &$data, $entity, $module) {
  // Access / modify the pipe.
  $pipe = &$data['__drupal_alter_by_ref']['pipe'];
  $data['features']['uuid_panelizer']['xyz'] = 'xyz';
  $pipe['dependencies']['module_xyz'] = 'module_xyz';
}

/**
 * Allows to modify the export object of an entity.
 *
 * @param string $entity_type
 *   The entity type to export.
 * @param object $export
 *   The for the export modified entity.
 * @param object $entity
 *   The original entity.
 * @param string $module
 *   The module to export for.
 */
function hook_uuid_entity_features_export_render_alter($entity_type, $export, $entity, $module) {

}

/**
 * Allows to handle specific import tasks for an entity.
 *
 * @param string $entity_type
 *   The entity type to rebuild.
 * @param object $entity
 *   The entity to import.
 * @param array $data
 *   The raw data from the export.
 * @param string $module
 *   The module to import for.
 */
function hook_uuid_entity_features_rebuild_alter($entity_type, $entity, $data, $module) {

}

/**
 * Allows to act whenever all entities of a type / module are rebuilt.
 *
 * @param string $entity_type
 *   The entity type to export.
 * @param array $entities
 *   The entities to import.
 * @param string $module
 *   The module to import for.
 */
function hook_uuid_entity_features_rebuild_complete($entity_type, $entities, $module) {
}

/**
 * Allows to modify features metadata for a node.
 *
 * @param array $data
 *   The array of the features export data
 * @param object $node
 *   The node to export.
 */
function hook_uuid_node_features_export_alter(&$data, $node, $module) {
  // Access / modify the pipe.
  $pipe = &$export['__drupal_alter_by_ref']['pipe'];
}

/**
 * Allows to adjust the features export options for nodes.
 *
 * @param array $options
 *   The features export options.
 */
function hook_uuid_node_features_export_options_alter(&$options) {

}

/**
 * Allows to modify the export object of a node.
 *
 * @param object $export
 *   The for the export modified node.
 * @param object $node
 *   The original node.
 * @param string $module
 *   The module this is exported for.
 */
function hook_uuid_node_features_export_render_alter(&$export, $node, $module) {

}

/**
 * Allows to handle specific import tasks for a node.
 *
 * @param object $node
 *   The node to import.
 * @param string $module
 *   The module to import for.
 */
function hook_uuid_node_features_rebuild_alter(&$node, $module) {

}

/**
 * Allows to modify features metadata for an user.
 *
 * @param array $data
 *   The array of the features export data
 * @param object $user
 *   The user to export.
 */
function hook_uuid_user_features_export_alter(&$data, $user) {

}

/**
 * Allows to modify the export object of an user.
 *
 * @param object $export
 *   The for the export modified user.
 * @param object $user
 *   The original user.
 * @param string $module
 *   The module this is exported for.
 */
function hook_uuid_user_features_export_render_alter(&$export, $user, $module) {

}

/**
 * Allows to handle specific import tasks for an user.
 *
 * @param object $user
 *   The user to import.
 * @param string $module
 *   The module to import for.
 */
function hook_uuid_user_features_rebuild_alter(&$user, $module) {

}

/**
 * Allows to adjust the features export options for terms.
 *
 * @param array $options
 *   The features export options.
 */
function hook_uuid_term_features_export_options_alter(&$options) {

}

/**
 * Allows to adjust the features export options for field collections.
 *
 * @param array $options
 *   The features export options.
 */
function hook_uuid_field_collection_features_export_options_alter(&$options) {

}

/**
 * Allows to adjust the export options for the current search configuration.
 *
 * @param array $options
 *   The features export options.
 */
function hook_uuid_current_search_configuration_features_export_options_alter(&$options) {

}

/**
 * Allows to modify features metadata for a bean.
 *
 * @param array $data
 *   The array of the features export data
 * @param object $bean
 *   The bean to export.
 */
function hook_uuid_bean_features_export_alter(&$data, $bean) {

}

/**
 * Allows to modify the export object of a bean.
 *
 * @param object $export
 *   The for the export modified bean.
 * @param object $bean
 *   The original bean.
 * @param string $module
 *   The module this is exported for.
 */
function hook_uuid_bean_features_export_render_alter(&$export, $bean, $module) {

}
