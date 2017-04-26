<?php
/**
 * @file
 * Authmap-based condition for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_authmap_admin_form',
  'condition callback' => 'password_policy_authmap_condition',
  'prime value' => 'authmap',
  'config' => array(
    'authmodules' => array(),
  ),
);

/**
 * Admin form callback for authmap condition.
 */
function password_policy_authmap_admin_form($form, &$form_state, $condition) {
  $authmodules = db_select('authmap', 'a')
    ->fields('a', array('module'))
    ->groupBy('module')
    ->execute()
    ->fetchCol();

  $sub_form['authmap_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication systems'),
  );
  $sub_form['authmap_fieldset']['authmodules'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Exclude policy for specific authentication systems'),
    '#default_value' => $condition->config['authmodules'],
    '#description' => t('Exclude this policy from the selected authorization system(s).'),
    '#options' => count($authmodules) ? drupal_map_assoc($authmodules) : array(),
  );
  return $sub_form;
}

/**
 * Condition callback for authmap condition.
 */
function password_policy_authmap_condition($account, $condition) {
  $authmodules = array_filter($condition->config['authmodules']);

  // Always enforce this policy if no authentication modules were excluded.
  if (count($authmodules) == 0) {
    return TRUE;
  }

  // Always enforce this policy for anonymous users.
  if ($account->uid == 0) {
    return TRUE;
  }

  // Otherwise, test if user authmap intersects with any excluded
  // authentication modules.
  $authmaps = user_get_authmaps($account->name);
  if ($authmaps) {
    return !count(array_intersect_key($authmaps, $authmodules));
  }
  else {
    return TRUE;
  }
}
