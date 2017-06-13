<?php
/**
 * @file
 * Features hooks for the panelizer features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_panelizer_features_export_options() {
  $options = array();

  // Fetch entity specific display configurations.
  $results = db_select('panelizer_entity')
    ->fields('panelizer_entity', array('entity_type', 'entity_id', 'view_mode'))
    ->isNull('name')
    ->groupBy('entity_type')
    ->groupBy('entity_id')
    ->addTag('uuid_panelizer_features_export_options')
    ->execute();

  foreach ($results as $panelizer_entity) {
    $entity = entity_load_single($panelizer_entity->entity_type, $panelizer_entity->entity_id);

    // Only export the display if its a currently modified display with an uuid.
    if ($entity === FALSE || empty($entity->panelizer[$panelizer_entity->view_mode]->did) || empty($entity->panelizer[$panelizer_entity->view_mode]->display->uuid)) {
      continue;
    }

    $label = entity_label($panelizer_entity->entity_type, $entity);
    $options[$panelizer_entity->entity_type . ':' . $entity->uuid . ':' . $panelizer_entity->view_mode] = t('@entity_type: !label [@id]', array(
      '@entity_type' => $panelizer_entity->entity_type,
      '!label' => $label,
      '@id' => $panelizer_entity->entity_id,
    ));
  }

  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_panelizer_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies']['uuid_features'] = 'uuid_features';
  $export['dependencies']['panelizer'] = 'panelizer';

  foreach ($data as $key) {
    $exploded_key = explode(':', $key);
    if (count($exploded_key) < 3) {
      continue;
    }
    list($entity_type, $entity_uuid, $view_mode) = $exploded_key;

    $entity = entity_uuid_load($entity_type, array($entity_uuid), array(), TRUE);
    $entity = reset($entity);

    // Only export the display if the related entity exists and its a modified
    // display with an uuid.
    if ($entity === FALSE || empty($entity->panelizer[$view_mode]->did) || empty($entity->panelizer[$view_mode]->display->uuid)) {
      continue;
    }

    $panelizer_settings = $entity->panelizer[$view_mode];

    $export['features']['uuid_panelizer'][$key] = $key;

    // Add dependencies to known uuid entity type exports.
    $uuid_features_entity_types = array(
      'taxonomy_term' => 'uuid_term',
      'node' => 'uuid_node',
      'user' => 'uuid_user',
    );

    if (isset($uuid_features_entity_types[$entity_type])) {
      $export['features'][$uuid_features_entity_types[$entity_type]][$entity_uuid] = $entity_uuid;
    }

    $data = &$export;
    $data['__drupal_alter_by_ref']['pipe'] = &$pipe;
    drupal_alter('uuid_panelizer_features_export', $data, $panelizer_settings, $module_name);
    unset($data['__drupal_alter_by_ref']);
  }
  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function uuid_panelizer_features_export_render($module, $data) {
  $translatables = $code = array();

  $code[] = '  $uuid_panelizer = array();';
  $code[] = '';

  foreach ($data as $key) {
    $exploded_key = explode(':', $key);
    if (count($exploded_key) < 3) {
      continue;
    }
    list($entity_type, $entity_uuid, $view_mode) = $exploded_key;

    $entity = entity_uuid_load($entity_type, array($entity_uuid), array(), TRUE);
    $entity = reset($entity);

    // Only export the display if the related entity exists and its a modified
    // display with an uuid.
    if ($entity === FALSE || empty($entity->panelizer[$view_mode]->did) || empty($entity->panelizer[$view_mode]->display->uuid)) {
      continue;
    }

    $panelizer_settings = $entity->panelizer[$view_mode];
    // Clone object to avoid changes by reference.
    $export = clone $panelizer_settings->display;

    drupal_alter('uuid_panelizer_features_export_render', $export, $entity, $module);

    $code[] = '  // Modified panelizer display for '  . $entity_type . ' ' . $entity_uuid . '.';
    $code[] = panels_export_display($export, '  ') . "  \$uuid_panelizer[] = \$display;";
  }

  // Add translatables if any.
  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }

  $code[] = "\n  return \$uuid_panelizer;";
  $code = implode("\n", $code);
  return array('uuid_features_default_panelizer' => $code);
}

/**
 * Implements hook_features_revert().
 */
function uuid_panelizer_features_revert($module) {
  uuid_panelizer_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds users based on UUID from code defaults.
 */
function uuid_panelizer_features_rebuild($module) {
  $panelizer_entity_displays = features_get_default('uuid_panelizer', $module);

  if (!empty($panelizer_entity_displays)) {
    foreach ($panelizer_entity_displays as $display) {
      $did = db_query("SELECT did FROM {panels_display} WHERE uuid = :uuid", array(
        ':uuid' => $display->uuid,
      ))->fetchField();

      if ($did) {
        $display->did = $did;
      }
      drupal_alter('uuid_panelizer_features_rebuild', $display, $module);
      panels_save_display($display);
    }
  }
}
