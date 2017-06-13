<?php

/**
 * @file
 * This tamper process will take a string and return an id, eg
 * Given a node title, return the node id,
 * suitable for using when mapping to entityreference fields.
 *
 * It uses one of two methods, either
 *   a user-defined view that takes a string and returns ids,
 * or
 *   the entityreference autocomplete lookup (automatically available).
 *
 * All other feeds+entityreference plugins I found
 * (
 *   entityreference.feeds.inc,
 *   entityreference_feeds.module,
 *   feeds_entityreference.module
 * )
 * seemed to require that the referred target was also provided by Feeds and
 * had a Feeds GUID or similar.
 *
 * While that is more accurate, I needed a softer approach and want to resolve
 * references using just string matches, as that's what many datasources give
 * us.
 *
 */

/**
 * The plugin definition.
 */
$plugin = array(
  'form'     => 'feeds_tamper_string2id_resolve_target_form',
  'callback' => 'feeds_tamper_string2id_resolve_target_callback',
  'name'     => 'Convert string into entity ID',
  'multi'    => 'direct',
  'category' => 'Transform',
);

/**
 * User options
 */
function feeds_tamper_string2id_resolve_target_form($importer, $element_key, $settings) {
  $form = array();

  $form['help'] = array(
    '#markup' => "
      <p>
      If using this transformation, you should ensure that the mapping target
      is the </strong>{fieldname}: Entity ID</strong> version,
      to ensure that the resulting numeric ID gets saved correctly.
      </p>",
  );
  // Use FAPI #states to toggle the choice and show the appropriate section.
  $form['method'] = array(
    '#type' => 'radios',
    '#title' => 'Lookup method',
    '#options' => array(
      'autocomplete' => 'Entityreference autocomplete',
      'views' => 'Views'
    ),
    '#default_value' => (isset($settings['method']) ? $settings['method'] : 'autocomplete'),
  );


  /////////////////////////
  // Autocomplete options.
  // All automatic, but with big explanations.

  $form['autocomplete'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        'input[name="settings[method]"]' => array('value' => 'autocomplete'),
      ),
    ),
  );

  $form['autocomplete']['help'] = array(
    '#markup' => "
      <p>
      Given a text string,
      this conversion will find an entity on the current site with that title.
      It uses the entityreference autocomplete mechanism
      and the current target settings for this field as a lookup tool.
      Tranformation will returns a target_id (possibly multiple)
      suitable for saving into an entityreference field.
      </p><p>
      If your input string is multiple (eg coma-separated) you should use
      tamper (List:explode) to split it before this process runs.
      </p><p>
      This transform has no configurable settings here, <em>but</em>
      this settings form must be saved at least once when first setting it up
      to lock in the autodetected settings.
      </p>
      ",
  );

  // If I inspect the importer, I can autodetect the target field definition
  // and thus the settings I need to know to do the lookup when transforming.

  // Is this method getting too nosey into internals?
  $target = '';
  $processor_config = $importer->processor->getConfig();
  foreach ($processor_config['mappings'] as $mapping) {
    if ($mapping['source'] == $element_key) {
      // Found where this data is heading...
      $target = $mapping['target'];
    }
  }

  // Deal with special key used by feeds_entityreference.module
  $field_name = str_replace('entityreference:', '', $target);

  $field_info = field_info_field($field_name);
  if (!empty($target) && $field_info['type'] == 'entityreference') {

    // Figure out what I need to know about the destination,
    // and explain this to the user.
    $target_type = $field_info['settings']['target_type'];
    $target_bundles = $field_info['settings']['handler_settings']['target_bundles'];
    $strings = array(
      '%field_name' => $field_name,
      '%target_type' => $target_type,
      '%target_bundles' => implode(', ', $target_bundles),
      '!field_settings' => url("admin/structure/types/manage/{$processor_config['bundle']}/fields/$field_name"),
    );
    $form['autocomplete']['autodetected'] = array(
      '#prefix' => '<p>', '#suffix' => '</p>',
      '#markup' => t("
        The destination is <a href='!field_settings'>%field_name</a>.
        This means that the values to be inserted there are %target_type items
        of type: %target_bundles.
        These parameters will be used when making the lookup and converting
        a given string into an entity ID.
        To change this, <a href='!field_settings'>edit the parameters of
        the field itself</a>.
        ", $strings),
    );

    // How do I know the target entity type is a node?
    // This doesn't seem discoverable.
    if (is_a($importer->processor, "FeedsNodeProcessor")) {
      $entity_type = 'node';
      // TODO needs work here.
    }
    if (is_a($importer->processor, "FeedsTermProcessor")) {
      $entity_type = 'taxonomy_term';
    }
    if (is_a($importer->processor, "FeedsUserProcessor")) {
      $entity_type = 'user';
    }

    // Now I need to save these detected values as settings so they are
    // available when it comes time to convert.
    // I need this much detail when formulating the lookup later,
    // it's not available in context at callback time.
    $form['autocomplete']['entity_type'] = array(
      '#type' => 'value',
      '#value' => $entity_type,
    );
    $form['autocomplete']['field_name'] = array(
      '#type' => 'value',
      '#value' => $field_name,
    );
    $form['autocomplete']['bundle_name'] = array(
      '#type' => 'value',
      '#value' => $processor_config['bundle'],
    );
  }
  else {
    $strings = array(
      '%element_key' => $element_key,
      '%field_name' => $field_name,
      '!field_settings' => url("admin/structure/types/manage/{$processor_config['bundle']}/fields/$field_name"),
    );
    $form['autocomplete']['not_autodetected'] = array(
      '#prefix' => '<p class="error">', '#suffix' => '</p>',
      '#markup' => t("
        <strong>Invalid processor.</strong>
        This lookup will only work if the target field is an entityreference
        pointing at a set of entities we can link to.
        The target field currently set for %element_key is
        <a href='!field_settings'>%field_name</a>, and I don't expect that to
        be receptive to getting given a raw entity ID.
        ", $strings),
    );
  }

  //// Finished autocomplete UI
  /////////////////////////////////////
  //// Build the UI to choose the view.

  // Toggle visibility.
  $form['views'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        'input[name="settings[method]"]' => array('value' => 'views'),
      ),
    ),
  );

  if (! module_exists('views')) {
    $form['views']['help'] = array(
      '#markup' => t('Views is not available'),
    );
    // Early exit.
    return $form;
  }

  $form['views']['help'] = array(
    '#markup' => "
      <p>
      You should construct a view that:
      <ul><li>
      Takes a string as a 'Contextual filter' argument.
      </li><li>
      Displays 'fields'
      </li><li>
      Returns a row containing just an ID as the first column (not linked).
      </li></ul>
      This view will then be invoked each time a string input is being
      processed. If it returns one or more valid reults, those IDs will be
      returned.
      </p>
      ",
  );

  $views_options = array();

  # EVA though this was needed. Really?
  // Trigger a rebuild of the views object cache, which may not be fully loaded.
  #ctools_include('export');
  #ctools_export_load_object_reset('views_view');

  $views = views_get_all_views();
  foreach ($views as $view_id => $view) {
    // Skip disabled views.
    if (!empty($view->disabled)) {
      continue;
    }
    $view_name = ($view->human_name ? $view->human_name : $view->name);

    foreach ($view->display as $display_id => $display) {
      // Check if it meets expectations.
      // Filter aggressively to ensure we only get useful views.
      // Does it support an argument?
      if (empty($display->display_options['arguments'])) {
        continue;
      }
      // Just one argument please
      if (count($display->display_options['arguments']) != 1) {
        continue;
      }
      // Is the row_plugin 'fields'
      if (! isset($display->display_options['row_plugin']) || $display->display_options['row_plugin'] != 'fields') {
        continue;
      }
      // Is there at least one field?
      if (empty($display->display_options['fields'])) {
        continue;
      }

      $id = $view_id . ':' . $display_id;
      $label =  $display->display_title;
      $views_options[$view_name][$id] = $label;
    }
  }
  $form['views']['view'] = array(
    '#title' => 'Choose the view',
    '#type' => 'select',
    '#options' => $views_options,
    '#description' => '
      It must behave as described here. Only Views that take a single argument
      and return a row of fields are shown in this list.
    ',
    '#default_value' => (isset($settings['views']['view']) ? $settings['views']['view'] : ''),
  );

  if (!empty($settings['views']['view'])) {
    $col_id = isset($settings['views']['col_id']) ? $settings['views']['col_id'] : 'nid';
    // Maybe we can't rely on the target col always being first?
    // If needed, define its name.
    // Note, this UI lags behind if you change the above selection.
    list($view_id, $display_id ) = explode(':', $settings['views']['view']);
    $current_view_display = $views[$view_id]->display[$display_id];
    $cols = array_merge(array('' => '<auto>'), array_keys($current_view_display->display_options['fields']));
    $form['views']['col_id'] = array(
      '#title' => 'Choose ID field',
      '#type' => 'select',
      '#options' => $cols,
      '#description' => "
        This option may not be needed if you are only returning one field.
        The <em>first</em> column in the results should usually be used.
        But if there are other views tools in effect,
        it's safer to define the column name to retrieve explicitly here now.
      ",
      '#default_value' => isset($settings['views']['col_id']) ? $settings['views']['col_id'] : '',
    );
  }

  return $form;
}

/**
 * Process the field data transformation, given a string to search for.
 *
 * Switches based on chosen method and delegates to the actual resolver.
 *
 * @param $field The string value to search for. Could also be an array.
 *   Modified by reference into an array of ids that matched.
 *   Unchanged if no match (remains a string).
 */
function feeds_tamper_string2id_resolve_target_callback($source, $item_key, $element_key, &$field, $settings) {
  if (empty($field)) {
    return;
  }
  if (! is_array($field)) {
    // coerce field into an array. Easier code later.
    $field = array($field);
  }

  switch ($settings['method']) {
    case 'autocomplete' :
      return feeds_tamper_string2id_resolve_target_callback_via_autocomplete($source, $item_key, $element_key, $field, $settings);
      break;
    case 'views' :
      return feeds_tamper_string2id_resolve_target_callback_via_views($source, $item_key, $element_key, $field, $settings);
      break;
  }
}

/**
 * Process the field data transformation, given a string to search for.
 *
 * Uses search rules as defined in the field widget settings,
 * eg if the 'match operator' is 'begins with' or 'contains'.
 *
 * Respects cardinality - it supports multiple values if multiple matches
 * are found and allowed.
 *
 * @param $field array of string values to search for.
 *   Modified by reference into an array of ids that matched.
 *   Unchanged if no match (remains a string).
 */
function feeds_tamper_string2id_resolve_target_callback_via_autocomplete($source, $item_key, $element_key, &$field, $settings) {
  // Leverage entityreference autocomplete lookup handler to do our job.

  // Need to retrieve a bunch of dull context first though...
  $field_info = field_info_field($settings['autocomplete']['field_name']);
  $instance = field_info_instance(
    $settings['autocomplete']['entity_type'],
    $settings['autocomplete']['field_name'],
    $settings['autocomplete']['bundle_name']
  );
  $entity = NULL;
  $handler = entityreference_get_selection_handler(
    $field_info,
    $instance,
    $settings['autocomplete']['entity_type'],
    NULL//$entity
  );
  $found = array();

  // Allow as many results as the field can take. Multiples are allowed.
  // TODO See if I can prefer an exact match before opening it up to all
  //      possibilities.
  //      If I have both 'Auckland' and 'Auckland Central' to match to,
  //      I'd get bogus results.
  //      Keeping the field settings to 1 will prevent that.

  $max_results = $field_info['cardinality'];

  // Field is already an array (maybe of just one). Run lookups for each.
  foreach ($field as $field_string) {
    if (! is_string($field_string)) {
      watchdog(__FUNCTION__, 'Expected string, got <pre>!data</pre>', array('!data' => print_r(get_defined_vars(), 1)), WATCHDOG_NOTICE);
      continue;
    }
    $field_string = trim($field_string);

    if (empty($field_string)) {
      continue;
    }
    // Run the search now
    $entity_labels = $handler->getReferencableEntities(
      $field_string,
      $instance['widget']['settings']['match_operator'],
      $max_results
    );

    // This will return a nested array, unpack it.
    // ?? this is NOT nested by $found_bundle_name in
    // entityreference v 7.x-1.0-rc1 1332279946
    // It IS nested in 7.x-1.0 1353230808 and that's what we will assume.

    // Support multiples.
    foreach ($entity_labels as $found_bundle_name => $found_labels) {
      foreach ($found_labels as $found_id => $found_title) {
        $found[] = $found_id;
      }
    }
  }
  if (!empty($found)) {
    $field = $found;
  }
}

/**
 * Process the field data transformation, given a string to search for.
 *
 * Uses the nominated view and passes it our string value as an argument.
 *
 * Respects cardinality - it supports multiple values if multiple matches
 * are found and allowed.
 *
 * @param $field Array of string values to search for.
 *   Modified by reference into an array of ids that matched.
 *   Unchanged if no match (remains a string).
 */
function feeds_tamper_string2id_resolve_target_callback_via_views($source, $item_key, $element_key, &$field, $settings) {
  // Leverage views to do our job.
  list($view_id, $display_id ) = explode(':', $settings['views']['view']);
  $col_id = isset($settings['views']['col_id']) ? $settings['views']['col_id'] : '';
  $found = array();

  // field is already an array (maybe of just one). Run lookups for each value.
  foreach ($field as $field_string) {
    // Load and run the view in one go
    $results = views_get_view_result($view_id, $display_id, $field_string);
    // The result better include a row we can make use of.
    // Support multiples.
    foreach ($results as $row) {
      // This is an object, we may know the id of the attribute/col to use.
      if (!empty($col_id)) {
        if (isset($row->{$col_id})) {
          $found[] = $row->{$col_id};
        }
        elseif (is_numeric($col_id)) {
          $vals = get_object_vars($row);
          $values = array_values($vals);
          if (!empty($values[$col_id])) {
            $found[] = $values[$col_id];
          }
        }
      }
      else {
        // Force a pop from the first part of the result and hope for the best.
        $row_array = (array)$row;
        $found[] = reset($row_array);
      }
    }
  }
  if (!empty($found)) {
    $field = $found;
  }
}
