<?php
/**
 * @file
 * uuid features hooks on behalf of the panelizer module.
 */

/**
 * Implements hook_uuid_entity_features_export_alter().
 */
function panelizer_uuid_entity_features_export_alter($entity_type, &$data, $entity, $module) {
  list($entity_id, $revision_id, $bundle) = entity_extract_ids($entity_type, $entity);

  $handler = panelizer_entity_plugin_get_handler($entity_type);
  if (!$handler) {
    return;
  }

  if (panelizer_is_panelized($handler, $bundle) && !empty($entity->panelizer)) {
    // Access / modify the pipe.
    $pipe = &$data['__drupal_alter_by_ref']['pipe'];

    foreach ($entity->panelizer as $view_mode => $panelize_settings) {
      // If there's no uuid - skip the whole action.
      if (empty($panelize_settings->display->uuid)) {
        continue;
      }

      // Check if to export or not.
      switch (TRUE) {
        // If the settings are already exported, add dependency to the module.
        case isset($panelize_settings->export_module):
          $pipe['dependencies'][$panelize_settings->export_module] = $panelize_settings->export_module;
          break;

        // Add dependency to the panelizer default configuration.
        case isset($panelize_settings->name):
          $data['features']['panelizer_defaults'][$panelize_settings->name] = $panelize_settings->name;
          break;

        // If this is a modified display add dependency to uuid panelizer.
        case (!empty($panelize_settings->entity_id) && !empty($panelize_settings->did)):
          $export_key = $entity_type . ':' . $entity->uuid . ':' . $view_mode;
          $data['features']['uuid_panelizer'][$export_key] = $export_key;
          break;
      }

    }
  }
}

/**
 * Implements hook_uuid_entity_features_export_render_alter().
 */
function panelizer_uuid_entity_features_export_render_alter($entity_type, &$export, &$entity, $module) {
  list($entity_id, $revision_id, $bundle) = entity_extract_ids($entity_type, $entity);

  $handler = panelizer_entity_plugin_get_handler($entity_type);
  if (!$handler) {
    return;
  }

  if (panelizer_is_panelized($handler, $bundle) && !empty($export->panelizer)) {
    foreach ($export->panelizer as $view_mode => $panelize_settings) {

      // Only deal with the property if the panelizer has uuid support.
      if (!empty($panelize_settings->display->uuid)) {

        // Just export customized displays or bundles with a choice. All other
        // cases are automatically regenerated.
        if ($handler->is_panelized($bundle, $view_mode) && ($handler->has_panel_choice($bundle . '.' . $view_mode) || !empty($panelize_settings->did))) {

          // By default we just store the name of the selected display.
          if (!empty($panelize_settings->name)) {
            $export->panelizer[$view_mode] = array('name' => $panelize_settings->name);
          }
          elseif (!empty($panelize_settings->did)) {
            // This is a modified display, dependency to the configuration
            // should have been added. Now replace the did by it's uuid.
            // @see panelizer_uuid_entity_features_export_alter()
            $export->panelizer[$view_mode]->did_uuid = $panelize_settings->display->uuid;
            unset(
              $export->panelizer[$view_mode]->did,
              $export->panelizer[$view_mode]->display,
              $export->panelizer[$view_mode]->entity_id,
              $export->panelizer[$view_mode]->revision_id
            );
          }
        }
        else {
          unset($export->panelizer[$view_mode]);
        }
      }
      else {
        unset($export->panelizer[$view_mode]);
      }
    }
  }
  // Remove unnecessary panelizer array.
  if (empty($export->panelizer)) {
    unset($export->panelizer);
  }
}

/**
 * Implements hook_uuid_entity_features_rebuild_alter().
 */
function panelizer_uuid_entity_features_rebuild_alter($entity_type, &$entity, $data, $module) {
  static $modified_displays_rebuilt;

  if (!empty($entity->panelizer)) {

    foreach ($entity->panelizer as $view_mode => $panelizer_settings) {

      // This was an modified display. Ensure those are imported.
      if (!empty($panelizer_settings['did_uuid'])) {

        if (empty($modified_displays_rebuilt)) {
          $modified_displays_rebuilt = TRUE;
          uuid_panelizer_features_rebuild($module);
        }

        // Fetch display and set it.
        $did = db_query("SELECT did FROM {panels_display} WHERE uuid = :uuid", array(
          ':uuid' => $panelizer_settings['did_uuid'],
        ))->fetchField();

        if ($did) {
          $entity->panelizer[$view_mode] = (object) $entity->panelizer[$view_mode];
          $entity->panelizer[$view_mode]->did = $did;
          $entity->panelizer[$view_mode]->display = panels_load_display($did);
        }
      }
      elseif (count($panelizer_settings['name']) == 1 && !empty($panelizer_settings['name'])) {
        // This uses a the default panelizer configuration restore it.
        list($entity_id, $revision_id, $bundle) = entity_extract_ids($entity_type, $entity);
        $handler = panelizer_entity_plugin_get_handler($entity_type);
        $entity->panelizer[$view_mode] = $handler->get_default_panelizer_object($bundle . '.' . $view_mode, $panelizer_settings['name']);
        $entity->panelizer[$view_mode]->did = NULL;
        list($entity_id, $revision_id, $bundle) = entity_extract_ids($entity_type, $entity);
        // Ensure these variables are set - if not panelizer will try to insert
        // instead update in certain cases.
        $entity->panelizer[$view_mode]->entity_id = $entity_id;
        $entity->panelizer[$view_mode]->revision_id = $revision_id;
      }
    }
  }
}
