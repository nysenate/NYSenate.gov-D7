<?php
/**
 * @file
 * Features hooks for the uuid_commerce_product features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_commerce_product_features_export_options() {
  $options = array();
  $enabled_types = array();

  // Check what content types are enabled for uuid features export.
  $types = commerce_product_types();

  foreach ($types as $type => $info) {
    if (variable_get('uuid_features_entity_commerce_product_' . $type, FALSE)) {
      $enabled_types[] = $type;
    }
  }

  if (!empty($enabled_types)) {
    $query = db_select('commerce_product', 'cp');
    $query->fields('cp', array('product_id', 'title', 'type', 'uuid'))
      ->condition('type', $enabled_types)
      ->orderBy('type')
      ->orderBy('title')
      ->addTag('uuid_commerce_product_features_export_options');
    $products = $query->execute()->fetchAll();
    foreach ($products as $product) {
      $options[$product->uuid] = t('@type: @title', array(
        '@type' => $types[$product->type]['name'],
        '@title' => $product->title,
      ));
    }
  }

  drupal_alter('uuid_commerce_product_features_export_options', $options);
  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_commerce_product_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies']['uuid_features'] = 'uuid_features';

  $product_ids = entity_get_id_by_uuid('commerce_product', $data);
  foreach ($product_ids as $uuid => $product_id) {
    // Load the existing commerce product, with a fresh cache.
    $product = commerce_product_load($product_id, NULL, TRUE);

    $export['features']['uuid_commerce_product'][$uuid] = $uuid;
    $pipe['commerce_product'][$product->type] = $product->type;

    // drupal_alter() normally supports just one byref parameter. Using
    // the __drupal_alter_by_ref key, we can store any additional parameters
    // that need to be altered, and they'll be split out into additional params
    // for the hook_*_alter() implementations.
    $data = &$export;
    $data['__drupal_alter_by_ref']['pipe'] = &$pipe;
    $entity_type = 'commerce_product';
    drupal_alter('uuid_entity_features_export', $entity_type, $data, $product, $module);
    drupal_alter('uuid_commerce_product_features_export', $data, $product, $module);
    unset($data['__drupal_alter_by_ref']);
  }

  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function uuid_commerce_product_features_export_render($module, $data) {
  $translatables = $code = array();

  $code[] = '  $products = array();';
  $code[] = '';
  $product_ids = entity_get_id_by_uuid('commerce_product', $data);
  // Always sort by the uuid to ensure the order is maintained.
  ksort($product_ids);
  foreach ($product_ids as $uuid => $product_id) {
    // Only export the node if it exists.
    if ($product_id === FALSE) {
      continue;
    }
    // Attempt to load the product, using a fresh cache.
    $products = commerce_product_load_multiple(array($product_id), NULL, TRUE);
    if (empty($products)) {
      continue;
    }
    $product = reset($products);
    if (!empty($product->path)) {
      $product->pathauto_perform_alias = FALSE;
    }
    // Clone entity to avoid changes by reference.
    $export = clone $product;

    // Don't cause conflicts with product_id/vid/revision_timestamp/changed
    // fields.
    uuid_features_file_field_export($export, 'commerce_product');

    $entity_type = 'commerce_product';
    drupal_alter('uuid_entity_features_export_render', $entity_type, $export, $product, $module);
    drupal_alter('uuid_commerce_product_features_export_render', $export, $product, $module);

    unset($export->changed);
    unset($export->revision_uid);
    unset($export->revision_timestamp);
    unset($export->product_id);
    unset($export->revision_id);
    unset($export->cid);

    $code[] = '  $products[] = ' . features_var_export($export) . ';';
  }

  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }
  $code[] = '  return $products;';
  $code = implode("\n", $code);
  return array('uuid_features_default_commerce_product' => $code);
}

/**
 * Implements hook_features_revert().
 */
function uuid_commerce_product_features_revert($module) {
  uuid_commerce_product_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds products based on UUID from code defaults.
 */
function uuid_commerce_product_features_rebuild($module) {
  $return = TRUE;

  if (function_exists('uuid_term_features_rebuild')) {
    // Import the terms first.
    uuid_term_features_rebuild($module);
  }

  $products = features_get_default('uuid_commerce_product', $module);
  if (!empty($products)) {
    $return = uuid_commerce_product_features_rebuild_products($products, $module);
    $entity_type = 'commerce_product';
    module_invoke_all('uuid_entity_features_rebuild_complete', $entity_type, $products, $module);
  }
  return $return;
}

/**
 * Runs the product import multiple times to resolve dependencies.
 *
 * We might need several runs of ths function to resolve the dependencies
 * created by reference fields. Those can only be resolved if the target product
 * already exists.
 *
 * @param array $products
 *   The products to process.
 * @param string $module
 *   The module to rebuild for.
 * @param int $max_nesting
 *   Maximal nesting level.
 * @param int $nesting_level
 *   Current nesting level.
 *
 * @return bool
 *   TRUE if all products could be restored.
 */
function uuid_commerce_product_features_rebuild_products($products, $module, $max_nesting = 5, $nesting_level = 0) {
  // Max nesting level hit.
  if ($max_nesting < $nesting_level) {
    watchdog('UUID Features', 'Unable to restore commerce products. Max nesting level reached.', array(), WATCHDOG_ERROR);
    return FALSE;
  }
  $second_run_products = array();
  $entity_info = entity_get_info('commerce_product');
  foreach ($products as $data) {
    try {

      // Double-check that bean can be created/reverted.
      if (!isset($entity_info['bundles'][$data['type']])) {
        drupal_set_message('Bundle not found for commerce product of type ' . $data['type'] . '. Product was not created/reverted.', 'warning');
      }
      else {
        // If this is an update, there will be a by-UUID matching product.
        $existing = entity_get_id_by_uuid('commerce_product', array($data['uuid']));
        if (!empty($existing)) {
          $product = entity_load_single('commerce_product', $existing[$data['uuid']]);
          foreach ($data as $key => $value) {
            $product->$key = $value;
          }
        }
        else {
          // Create a new product.
          $product = entity_create('commerce_product', $data);
        }

        $entity_type = 'commerce_product';
        drupal_alter('uuid_entity_features_rebuild', $entity_type, $product, $data, $module);
        drupal_alter('uuid_commerce_product_features_rebuild', $product, $module);

        uuid_features_file_field_import($product, 'commerce_product');
        commerce_product_save($product);
      }
    }
    catch (Exception $e) {
      $second_run_products[] = $data;
    }
  }
  if (!empty($second_run_products)) {
    return uuid_commerce_product_features_rebuild_products($second_run_products, $module, $max_nesting, ++$nesting_level);
  }
  return TRUE;
}
