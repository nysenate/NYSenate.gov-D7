<?php
/**
 * @file
 * uuid features hooks on behalf of the commerce_product_reference module.
 */

/**
 * Implements hook_uuid_entity_features_export_alter().
 */
function commerce_product_reference_uuid_entity_features_export_alter($entity_type, &$data, $entity, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'commerce_product_reference');

  if (!empty($fields)) {
    $commerce_product_ids = array();
    foreach ($fields as $field) {
      foreach ($field as $lang_items) {
        foreach ($lang_items as $values) {
          $commerce_product_ids[] = $values['product_id'];
        }
      }
    }
    // Add dependencies to products.
    $uuids = entity_get_uuid_by_id('commerce_product', $commerce_product_ids);
    foreach ($uuids as $uuid) {
      $data['features']['uuid_commerce_product'][$uuid] = $uuid;
    }
  }
}

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function commerce_product_reference_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  $fields = uuid_features_get_field_items_iterator($export, $entity_type, 'commerce_product_reference');
  uuid_features_set_uuid_references($fields, 'commerce_product');
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function commerce_product_reference_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  $fields = uuid_features_get_field_items_iterator($entity, $entity_type, 'commerce_product_reference');
  uuid_features_fetch_uuid_references($fields, 'commerce_product', array(
    'product_id' => 'product_id',
  ));
}
