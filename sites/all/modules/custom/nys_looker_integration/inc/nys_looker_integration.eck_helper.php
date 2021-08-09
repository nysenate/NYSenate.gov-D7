<?php
require_once 'nys_looker_integration.looker_helper.php';

define('NYS_LOOKER_INTEGRATION_MANAGE_PATH', 'admin/structure/looker_plans');

/**
 * Helper function to build the bundle-specific submenus for
 * the main admin menu.
 *
 * @param $items array The menu array built so far.
 *
 * @return array The built menu array.
 */
function nys_looker_integration_build_eck_menu($items) {
  $ret = $items;
  $ent_type = entity_type_load('looker_plans');
  $bundles = Bundle::loadByEntityType($ent_type);
  foreach ($bundles as $val) {
    $path = NYS_LOOKER_INTEGRATION_MANAGE_PATH . "/{$val->name}";
    $ret[$path] = [
      'title' => $val->label,
      'description' => "Manage Plan: {$val->label}",
      'page callback' => 'drupal_get_form',
      'page arguments' => ['nys_looker_integration_plan_recipients', 3],
      'access arguments' => ['administer looker recipients'],
      'type' => MENU_NORMAL_ITEM,
    ];
    $ret[$path . '/recipients'] = [
      'title' => "Recipients",
      'page callback' => 'drupal_get_form',
      'page arguments' => ['nys_looker_integration_plan_recipients', 3],
      'access arguments' => ['administer looker recipients'],
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => 1,
    ];
    $ret[$path . '/edit'] = [
      'title' => "Settings",
      'page callback' => 'drupal_get_form',
      'page arguments' => ['nys_looker_integration_plan_edit', 3],
      'access arguments' => ['administer looker scheduled plans'],
      'type' => MENU_LOCAL_TASK,
      'weight' => 2,
    ];
    $ret[$path . '/delete'] = [
      'title' => "Delete",
      'page callback' => 'drupal_get_form',
      'page arguments' => ['nys_looker_integration_plan_delete', 3],
      'access arguments' => ['administer looker scheduled plans'],
      'type' => MENU_LOCAL_TASK,
      'weight' => 10,
    ];
  }

  return $ret;
}

/**
 * Callback for drupal_get_form().  The form to delete a bundle.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 * @param $bundle_name string The bundle name detected from the URL
 *
 * @return array A Drupal form object.
 */
function nys_looker_integration_plan_delete($form, &$form_state, $bundle_name) {
  $form = eck__bundle__delete_form($form, $form_state, 'looker_plans', $bundle_name);

  // Remove the redirections installed by ECK.
  $form['submit_redirect']['#value'] = NYS_LOOKER_INTEGRATION_MANAGE_PATH;
  $form['actions']['cancel']['#href'] = NYS_LOOKER_INTEGRATION_MANAGE_PATH;
  unset($form['actions']['cancel']['#options']);

  return $form;
}

/**
 * Submit handler for deleting a plan (bundle).
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 */
function nys_looker_integration_plan_delete_submit($form, &$form_state) {
  // ECK can handle the delete.
  // TODO: find a better way.. if last bundle is deleted, field goes away!
  eck__bundle__delete_form_submit($form, $form_state);

  // Replace ECK's redirect with our own.
  $form_state['redirect'] = NYS_LOOKER_INTEGRATION_MANAGE_PATH;
}

/**
 * Callback for drupal_get_form().  Builds the list of bundles (reports)
 * belonging to the 'looker_plans' entity type.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 *
 * @return array A Drupal form object.
 */
function nys_looker_integration_plan_list($form, &$form_state) {
  // Load the entity type and all of its bundles (plans).
  $ent_type = entity_type_load('looker_plans');
  $bundles = Bundle::loadByEntityType($ent_type);

  // If the user has permission to modify plans.
  $perm = user_access('administer looker scheduled plans', $GLOBALS['user']);

  // For each bundle, create a table row.  Only add the delete button if
  // permissions allow.
  $rows = [];
  foreach ($bundles as $val) {
    $label = l($val->label, url(NYS_LOOKER_INTEGRATION_MANAGE_PATH . "/{$val->name}", ['absolute' => TRUE]));
    if ($perm) {
      $del = l("Delete", url(NYS_LOOKER_INTEGRATION_MANAGE_PATH . "/{$val->name}/delete", ['absolute' => TRUE]));
      $rows[] = [$label, $del];
    }
    else {
      $rows[] = [$label];
    }

  }

  // If no bundles are available, render a permission-appropriate message
  // so they don't get a blank screen.
  if (!count($bundles)) {
    $form['no_bundles'] = [
      '#markup' => '<h2>No report plans have been configured yet.</h2>',
    ];
    if (!$perm) {
      $form['no_bundles']['#markup'] .= '<h3>Contact STS for more information on available reports.</h3>';
    }
  }
  // Otherwise, build the form's table entry.
  else {
    $headers = [t('Available Reports')];
    if ($perm) {
      $headers[] = t('Operations');
    }
    $form['bundle_table'] = [
      '#theme' => 'table',
      '#header' => $headers,
      '#rows' => $rows,
    ];
  }

  return $form;
}

/**
 * Callback for drupal_get_form().  Builds the form for adding a new
 * plan (bundle) to the 'looker_plans' entity type.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 *
 * @return array A Drupal form object.
 */
function nys_looker_integration_plan_add($form, &$form_state) {
  // Let ECK build the initial form.
  $form = eck__bundle__add($form, $form_state, 'looker_plans');

  // A better description for the label.
  $form['bundle_label']['#description'] = 'A unique name for this report bundle. ' .
    'This name is exposed to users.';

  // ECK does not include bundle config points in its form.  Add them.
  $form += _nys_looker_integration_bundle_config_fields(new Bundle());

  // Set a reference to the entity type.
  // TODO: Why?  This is in $form already from eck__bundle__add().
  $form_state['values']['entity_type'] = entity_type_load('looker_plans');

  return $form;
}

/**
 * Submit handler for adding a new plan (bundle) to the 'looker_plans'
 * entity type.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 */
function nys_looker_integration_plan_add_submit($form, &$form_state) {
  // Let ECK save the new bundle.
  eck__bundle__add_submit($form, $form_state);

  // ECK does not save the config data points when adding a new bundle, so
  // we need to call the "edit" submit handler also.  It needs a reference
  // to the new bundle in $form_state, and we need to fix a discrepancy in
  // the naming of the label field between the two handlers.
  $bundle = bundle_load('looker_plans', $form_state['values']['bundle_name']);
  $form_state['values']['bundle'] = $bundle;
  $form_state['values']['label'] = $form_state['values']['bundle_label'] ?? [];
  eck__bundle__edit_form_submit($form, $form_state);

  // Replace ECK's redirect with our own.
  $form_state['redirect'] = NYS_LOOKER_INTEGRATION_MANAGE_PATH;
}

/**
 * Callback for drupal_get_form().  Builds the form for editing an
 * existing plan (bundle) in the 'looker_plans' entity type.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 * @param $bundle_name
 *
 * @return array A Drupal form object.
 */
function nys_looker_integration_plan_edit($form, &$form_state, $bundle_name) {
  // Let ECK build the standard form.
  $form = eck__bundle__edit_form($form, $form_state, 'looker_plans', $bundle_name);

  // Add the config fields.
  $form += _nys_looker_integration_bundle_config_fields($form['bundle']['#value']);

  // Rewire the "managed" properties to be more intuitive.
  unset($form['config_managed_properties']);

  return $form;
}

/**
 * Submit handler for editing an existing plan (bundle) in the 'looker_plans'
 * entity type.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 */
function nys_looker_integration_plan_edit_submit($form, &$form_state) {
  // Let ECK manage saving the edits.
  eck__bundle__edit_form_submit($form, $form_state);
}

/**
 * Callback for drupal_get_form().  Builds the form for editing the
 * recipients of a looker_plans entity.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 * @param $bundle_name string The machine name of the bundle.
 *
 * @return array A Drupal form object.
 */
function nys_looker_integration_plan_recipients($form, &$form_state, $bundle_name) {
  // Identify the current user and their permissions.
  $uid = $GLOBALS['user']->uid;
  $user = user_load($uid);
  $is_lc = nys_utils_user_has_role_name('Legislative Correspondent', $uid);
  $is_admin = nys_utils_user_has_role_name('Administrator');

  // Initialize some stuff.
  $senator_nid = 0;
  $district = $form_state['input']['admin_district'] ?? 0;
  $confirm = $form_state['requires_delete_confirmation'] ?? 0;

  // Discover the owning senator node and district number.
  // For admins, this is from the selector.
  if ($is_admin && $district) {
    $tid = nys_utils_lookup_district_tid($district);
    $senator_nid = nys_utils_get_senator_from_district_id($tid)->nid;
  }
  // For LC users, get the district via the 'Senator Management' field.
  elseif ($is_lc) {
    $senator_nid = $user->field_senator_management[LANGUAGE_NONE][0]['target_id'] ?? 0;
    $district = senator_get_district_number($senator_nid);
  }

  // Admins get to pick the district they will be managing.
  if ($is_admin) {
    $options = _nys_looker_integration_fetch_district_list();
    $form['admin_district'] = [
      '#type' => 'select',
      '#title' => t('Select a District'),
      '#options' => [],
      '#default_value' => $district,
      '#description' => t('Select a district to edit for this report.'),
      '#attributes' => ['onChange' => 'this.form.submit();'],
    ];
    foreach ($options as $key => $val) {
      $form['admin_district']['#options'][$val['district']] =
        t($val['title'] . ' - District ' . $val['district']);
    }
    $form['district_go'] = [
      '#type' => 'submit',
      '#value' => 'Go',
      '#attributes' => ['style' => ($district ? 'display:none' : '')],
    ];
  }

  // If a senator is found, load the entity and let ECK build the form.
  if ($senator_nid && $district) {
    $entity = _nys_looker_integration_load_plan_from_senator($bundle_name, $senator_nid);
    $form = eck__entity__form($form, $form_state, $entity);

    // Set the title according to the district.
    $label = $entity->entityinfo()['bundles'][$bundle_name]['label'];
    $form['title']['#value'] = "{$label} for District {$district}";
    $form['title']['#type'] = 'value';
    $form['title_text'] = [
      '#markup' => "<h1>{$form['title']['#value']}</h1>",
      '#weight' => -10,
    ];

    // Add the delete confirmation if necessary.
    if ($confirm) {
      $form['confirm_delete'] = [
        '#type' => 'checkbox',
        '#title' => 'Confirm deletion of this plan?',
        '#description' => 'Plans without at least one recipient will be deleted.  This is not reversible.  Check this box to confirm, or supply valid recipients in the field below.',
      ];
      $form['actions']['submit']['#value'] = 'DELETE';
      $list = &$form['looker_recipient_list']['und'];
      $list['#title'] = "These recipients will be removed.";
      foreach (element_children($list) as &$val) {
        $list[$val]['#disabled'] = TRUE;
      }
    }

  }

  // Make sure senator nid is populated as a value.
  $form['senator'] = [
    '#type' => 'value',
    '#value' => $senator_nid,
  ];

  // Add the custom validator.
  $form['#validate'][] = 'nys_looker_integration_plan_recipients_validate';

  // Remove ECK's redirect.
  unset($form['redirect']);

  return $form;
}

/**
 * Submit handler for editing the recipients of a looker_plans entity.
 *
 * @param $form array A Drupal form object.
 * @param $form_state array Drupal form state object.
 */
function nys_looker_integration_plan_recipients_submit($form, &$form_state) {
  // Different processes for save vs delete.
  switch ($form_state['values']['op'] ?? '') {
    case 'Save':
      // Write the new addresses to the Looker plan.
      $plan = nys_looker_integration_save_plan($form_state);

      // If this is a new plan, the $form_state entity reference will not
      // have a plan_id yet.  Make sure it is recorded.
      if (isset($plan->plan_id)) {
        $form_state['values']['entity']->plan_id = $plan->plan_id;
      }

      // Let ECK save the entity instance.  Protect the redirect value, since
      // ECK will change it.
      $save_state = $form_state['redirect'];
      eck__entity__form_submit($form, $form_state);
      $form_state['redirect'] = $save_state;
      break;

    case 'DELETE':
      $entity = $form_state['values']['entity'] ?? NULL;
      if ($entity instanceof Entity) {
        // If there's a plan ID, try to remove it from Looker
        if ($entity->plan_id ?? NULL) {
          $plan = new \NYS_Looker_Integration\ScheduledPlan($entity);
          if (!($plan->deleteFromLooker())) {
            drupal_set_message("Failed to remove Looker plan.  Please contact STS.", 'error');
          }
        }

        // Reset entity's recipient field and plan_id.
        $entity->plan_id = 0;
        $entity->looker_recipient_list['und'] = [];
        $entity->save();
        drupal_set_message("All recipient have been removed from Looker for this plan.");
      }
      break;
  }
}

/**
 * @param $form
 * @param $form_state
 */
function nys_looker_integration_plan_recipients_validate($form, &$form_state) {
  // Get the action and element which triggered the submission
  $action = $form_state['values']['op'] ?? '';
  $element = $form_state['triggering_element']['#name'] ?? '';

  // E.g., if an admin selects a different district.  The form needs to be
  // rebuilt, and the form state for the recipient field needs to be unset.
  if ($action == 'Go' && $element == 'op') {
    unset($form_state['field']['looker_recipient_list']);
    unset($form_state['input']['looker_recipient_list']);
    $form_state['rebuild'] = TRUE;
  }

  // If saving, make sure we have at least one destination.  If not, get
  // confirmation for deleting the plan.  This requires rebuilding the form,
  // so we can't trigger an error.
  if ($action == 'Save') {
    // Get the emails from the form and filter for validity.
    $entries = array_filter(
      ($form_state['values']['looker_recipient_list']['und'] ?? []),
      function ($v, $k) {
        return is_numeric($k) && valid_email_address($v['email'] ?? '');
      },
      ARRAY_FILTER_USE_BOTH
    );
    // If the form was submitted before, we may have a confirmation.
    $confirm = $form_state['values']['confirm_delete'] ?? 0;

    // If we don't have emails and don't have confirmation, send the form
    // back to the user to get confirmation.  Since we can't create an error
    // (it will block rebuild), render a warning message instead.
    if (!(count($entries) || $confirm)) {
      $form_state['requires_delete_confirmation'] = 1;
      $form_state['rebuild'] = TRUE;
      drupal_set_message("Plans without at least one recipient will be deleted", 'warning', FALSE);
    }
  }

  // Make sure the confirmation button is lit if deleting
  if ($action == 'DELETE') {
    if (!($form_state['values']['confirm_delete'] ?? NULL)) {
      form_set_error('Confirm Delete', 'You must confirm the deletion request to delete this report.');
    }
  }
}

/**
 * Implements hook_eck_bundle_save_message_alter().
 * This hook fires only after a new bundle is saved.  This allows us the
 * ability to attach a new field instance to the bundle.  In this case,
 * we are adding field looker_recipient_list, with unlimited entries.
 *
 * NOTE: A previous iteration tried to use field_email, but the field data
 * would mysteriously not save.  Using field_contact_email was problematic
 * because of the global cardinality setting.  Using a new field removed
 * these issues.
 *
 * @param $msg string The message being reported after a successful save.
 * @param $args array Holds labels for entity_type and bundle.
 * @param $context array Holds the bundle object and form_state array.
 *
 * @see _nys_looker_integration_create_recipient_field()
 *
 */
function nys_looker_integration_eck_bundle_save_message_alter(&$msg, $args, $context) {
  // Only act on looker_plans entities.
  if ($context['bundle']->entity_type == 'looker_plans') {
    try {
      // Try to create the field instance for the new bundle.
      _nys_looker_integration_attach_recipient_field($context['bundle']->name);
      $msg = 'Report "' . $context['bundle']->label . '" added as a scheduled plan option.';
    } catch (Exception $e) {
      // Uh-oh...
      $msg = 'WARNING: failed to add looker_recipient_list type to new bundle!  Please contact STS.';
    }
  }
}

/**
 * Retrieves a config value, specified by $key, from an ECK Bundle object.
 * Returns the value if it exists, or an empty string.
 *
 * @param $bundle Bundle Populated from ECK.
 * @param $key string The data key to extract.
 *
 * @return string
 */
function _nys_looker_integration_extract_config(Bundle $bundle, $key) {
  $ret = '';
  $data = $bundle->config ?? [];
  if (is_array($data) && array_key_exists($key, $data)) {
    $ret = $data[$key];
  }

  return $ret ?: '';
}

/**
 * @param $bundle
 * @param $nid
 *
 * @return entity|FALSE
 */
function _nys_looker_integration_load_plan_from_senator($bundle, $nid) {
  // Load the specific plan, based on bundle and senator nid.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'looker_plans')
    ->entityCondition('bundle', $bundle)
    ->propertyCondition('senator', $nid);
  $result = $query->execute();

  // If we found one, load it.
  if (isset($result['looker_plans']) && count($result['looker_plans'])) {
    $entity_id = key($result['looker_plans']);
    $entity = entity_load_single('looker_plans', $entity_id);
  }
  // Otherwise, create a new one.
  else {
    $entity = entity_create('looker_plans', ['type' => $bundle]);
  }

  return $entity;
}

/**
 * Uses ECK to create the "looker_plans" entity type.  We can re-use the
 * default properties provided by ECK, and add two of our own as well.
 */
function _nys_looker_integration_create_entity_type() {
  // Use ECK to establish the custom looker_plans entity type.
  $entity_type = new EntityType();
  $entity_type->label = 'Looker Plans';
  $entity_type->name = 'looker_plans';
  foreach (['title', 'created', 'changed'] as $val) {
    $field = eck_get_default_property($val);
    $entity_type->addProperty($val, $field['label'], $field['type'], $field['behavior']);
  }
  $entity_type->addProperty('plan_id', 'Plan ID', 'integer');
  $entity_type->addProperty('senator', 'Senator', 'integer');
  $entity_type->save();
}

/**
 * Tries to create the custom field used by looker_plans bundles.  If
 * this fails, everything else will break, so let the Exception go.
 *
 * @throws \FieldException
 */
function _nys_looker_integration_create_recipient_field() {
  $new_field = [
    'field_name' => 'looker_recipient_list',
    'type' => 'email',
    'module' => 'nys_looker_integration',
    'cardinality' => -1,
  ];
  field_create_field($new_field);
}

/**
 * Tries to attach the custom field to a looker_plans bundle.  If
 * this fails, everything else will break, so let the Exception go.
 *
 * @param $bundle_name
 *
 * @throws \FieldException
 */
function _nys_looker_integration_attach_recipient_field($bundle_name) {
  $instance = [
    'label' => 'Recipients',
    'required' => 0,
    'description' => 'List of desired recipients for this report.',
    'custom_add_another' => 'Add',
    'custom_remove' => 'Remove',
    'field_name' => 'looker_recipient_list',
    'entity_type' => 'looker_plans',
    'bundle' => $bundle_name,
    'cardinality' => -1,
  ];
  field_create_instance($instance);
}

/**
 * Returns an array whose elements are arrays with they keys 'district',
 * 'lastname', 'title', and 'nid'.  The first is the district number.  All
 * the others are from the senator node for that district.
 *
 * @return array
 */
function _nys_looker_integration_fetch_district_list() {
  $query = db_select('taxonomy_term_data', 'ttd');
  $query->join('taxonomy_vocabulary', 'tv', 'ttd.vid=tv.vid');
  $query->join('field_data_field_senator', 'fdfs', 'fdfs.entity_id=ttd.tid');
  $query->join('node', 'ns', 'ns.nid=fdfs.field_senator_target_id');
  $query->join('field_data_field_last_name', 'fdfln', 'fdfln.entity_id=ns.nid');
  $query->join('field_data_field_district_number', 'fdfdn', 'fdfdn.entity_id=ttd.tid');
  $query->addField('fdfln', 'field_last_name_value', 'lastname');
  $query->addField('fdfdn', 'field_district_number_value', 'district');
  $query->condition('tv.machine_name', 'districts')
    ->fields('ns', ['title', 'nid'])
    ->orderBy('lastname');
  $result = $query->execute();
  $ret = [];
  while ($row = $result->fetchAssoc()) {
    $ret[] = $row;
  }
  return $ret;
}

function _nys_looker_integration_bundle_config_fields(Bundle $bundle) {
  $senator = _nys_looker_integration_extract_config($bundle, 'senator_filter');
  $timeframe = _nys_looker_integration_extract_config($bundle, 'time_filter');

  return [
    'config_dashboard_id' => [
      '#type' => 'textfield',
      '#title' => 'Dashboard ID',
      '#required' => TRUE,
      '#size' => 5,
      '#default_value' => _nys_looker_integration_extract_config($bundle, 'dashboard_id'),
      '#description' => 'The Looker dashboard ID being used to generate this report',
    ],
    'config_schedule' => [
      '#type' => 'select',
      '#title' => 'Schedule',
      '#options' => [
        'daily' => t('Daily'),
        'weekly' => t('Weekly'),
      ],
      '#required' => TRUE,
      '#default_value' => _nys_looker_integration_extract_config($bundle, 'schedule'),
      '#description' => 'Desired schedule for this report (daily or weekly)',
    ],
    'filter_config' => [
      '#type' => 'fieldset',
      '#title' => 'Filter Names',
      '#description' => 'Reports must be filtered by a Senator, and optionally a timeframe.  These are the filter names Looker is expecting, e.g., "Constituent Action Timeframe" or "Senator Last Name".',
      'config_senator_filter' => [
        '#type' => 'textfield',
        '#title' => 'Senator Name',
        '#default_value' => $senator ?: 'Senator Last Name',
        '#description' => 'The name of Looker\'s filter for the Senator\'s last name.',
      ],
      'config_time_filter' => [
        '#type' => 'textfield',
        '#title' => 'Dashboard ID',
        '#default_value' => $timeframe ?: 'Constituent Action Timeframe',
        '#description' => 'The name of Looker\'s filter for the timeframe.  Leave blank to remove filtering by timeframe.',
      ],
    ],
  ];
}