<?php
/**
 * @file
 * Features hooks for the user features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_user_features_export_options() {
  $options = array();

  if (variable_get('uuid_features_entity_user_user', FALSE)) {
    $query = db_select('users', 'u')
      ->fields('u', array('uid', 'name', 'mail', 'uuid'))
      ->condition('u.uid', 0, '>')
      ->orderBy('u.name', 'ASC')
      ->addTag('uuid_user_features_export_options');

    $results = $query->execute()->fetchAll();
    foreach ($results as $user) {
      $options[$user->uuid] = t('@name: @mail', array(
        '@name' => $user->name,
        '@mail' => $user->mail,
      ));
    }
  }

  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_user_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies']['uuid_features'] = 'uuid_features';

  $uids = entity_get_id_by_uuid('user', $data);
  foreach ($uids as $uuid => $uid) {
    // Load the existing user.
    $user = user_load($uid, TRUE);

    $export['features']['uuid_user'][$uuid] = $uuid;

    $data = &$export;
    $data['__drupal_alter_by_ref']['pipe'] = &$pipe;
    $entity_type = 'user';
    drupal_alter('uuid_entity_features_export', $entity_type, $data, $user, $module_name);
    drupal_alter('uuid_user_features_export', $data, $user, $module_name);
    unset($data['__drupal_alter_by_ref']);
  }

  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function uuid_user_features_export_render($module, $data) {
  $translatables = $code = array();

  $code[] = '  $users = array();';
  $code[] = '';
  $uids = entity_get_id_by_uuid('user', $data);
  // Always sort by the uuid to ensure the order is maintained.
  ksort($uids);
  foreach ($uids as $uuid => $uid) {
    // Only export the user if it exists.
    if ($uid === FALSE) {
      continue;
    }
    // Attempt to load the user, using a fresh cache.
    $account = user_load($uid, TRUE);
    if (empty($account)) {
      continue;
    }
    // Clone entity to avoid changes by reference.
    $export = clone $account;

    // Use date instead of created - same format used by node_object_prepare.
    $export->date = format_date($export->created, 'custom', 'Y-m-d H:i:s O');
    unset(
      $export->uid,
      $export->pass,
      $export->access,
      $export->login
    );

    $entity_type = 'user';
    drupal_alter('uuid_entity_features_export_render', $entity_type, $export, $account, $module);
    drupal_alter('uuid_user_features_export_render', $export, $account, $module);

    $code[] = '  $users[] = ' . features_var_export($export) . ';';
  }

  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }

  $code[] = '  return $users;';
  $code = implode("\n", $code);
  return array('uuid_features_default_users' => $code);
}

/**
 * Implements hook_features_revert().
 */
function uuid_user_features_revert($module) {
  uuid_user_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 *
 * Rebuilds users based on UUID from code defaults.
 */
function uuid_user_features_rebuild($module) {
  $users = features_get_default('uuid_user', $module);
  uuid_node_features_rebuild($module);
  cache_clear_all();

  if (!empty($users)) {
    module_load_include('inc', 'user', 'user.pages');
    $entity_type = 'user';

    foreach ($users as $data) {
      $uid = NULL;
      $account = (object) $data;
      $existing = new stdClass();

      // Find the matching uid.
      $efq = new EntityFieldQuery();
      $efq->entityCondition('entity_type', 'user');
      $efq->propertyCondition('name', $account->name);
      $result = $efq->execute();

      if (isset($result['user'])) {
        $uids = array_keys($result['user']);
        $uid = reset($uids);
      }

      if (!empty($uid)) {
        if ($uid == 1) {
          global $user;
          if (!empty($user->uid) && $user->uid == 1) {
            $existing = $user;
          }
          else {
            $existing = user_load(1);
          }
        }
        else {
          // Find the matching user by name with a fresh cache.
          $existing = user_load($uid, TRUE);
          $existing->uid = $uid;
        }
        $account->uid = $uid;
      }
      else {
        $existing->uid = NULL;
      }

      drupal_alter('uuid_entity_features_rebuild', $entity_type, $account, $data, $module);
      drupal_alter('uuid_user_features_rebuild', $account, $module);

      if ($existing->uid === NULL) {
        // Ensure a new user gets a new password.
        $account->pass = user_password(16);
        $account = user_save(NULL, (array) $account);
      }
      else {
        // Ensure we don't reset the password.
        unset($account->pass);
        $account = user_save($existing, (array) $account);
      }
      // Clear out previously loaded user account if one was found.
      unset($existing);
    }
    module_invoke_all('uuid_entity_features_rebuild_complete', $entity_type, $users, $module);
  }
  uuid_node_features_rebuild($module);
}
