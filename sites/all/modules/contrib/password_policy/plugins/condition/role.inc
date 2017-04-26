<?php
/**
 * @file
 * Role-based condition for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_role_admin_form',
  'condition callback' => 'password_policy_role_condition',
  'prime value' => 'role_char_count',
  'config' => array(
    'roles' => array(),
  ),
);

/**
 * Admin form callback for role condition.
 */
function password_policy_role_admin_form($form, &$form_state, $condition) {
  $sub_form['role_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles'),
  );
  $sub_form['role_fieldset']['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enforce policy for specific roles'),
    '#default_value' => $condition->config['roles'],
    '#description' => t('Enforce this policy only for the selected role(s). If you select no roles, the policy will be enforced for all users.'),
    '#options' => user_roles(FALSE),
  );
  return $sub_form;
}

/**
 * Condition callback for role condition.
 */
function password_policy_role_condition($account, $condition) {
  $roles = array_filter($condition->config['roles']);

  // Always enforce this policy if no roles were selected.
  if (count($roles) == 0) {
    return TRUE;
  }

  // Otherwise, test if policy roles intersect with account roles.
  return count(array_intersect_key($account->roles, $roles));
}
