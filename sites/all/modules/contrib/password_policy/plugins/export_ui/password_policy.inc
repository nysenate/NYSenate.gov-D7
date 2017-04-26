<?php
/**
 * @file
 * Export UI Ctools plugin for Password Policy module.
 */

$plugin = array(
  // The name of the table as found in the schema in hook_install. This
  // must be an exportable type with the 'export' section defined.
  'schema' => 'password_policy',
  // The access permission to use. If not provided it will default to
  // 'administer site configuration'
  'access' => 'administer password policy',
  // You can actually define large chunks of the menu system here. Nothing
  // is required here. If you leave out the values, the prefix will default
  // to admin/structure and the item will default to the plugin name.
  'menu' => array(
    'menu prefix' => 'admin/config/people',
    'menu item' => 'password_policy',
    // Title of the top level menu. Note this should not be translated,
    // as the menu system will translate it.
    'menu title' => 'Password policy',
    // Description of the top level menu, which is usually needed for
    // menu items in an administration list. Will be translated
    // by the menu system.
    'menu description' => 'Administer password policies.',
  ),
  // These are required to provide proper strings for referring to the
  // actual type of exportable. "proper" means it will appear at the
  // beginning of a sentence.
  'title singular' => t('policy'),
  'title singular proper' => t('Policy'),
  'title plural' => t('policies'),
  'title plural proper' => t('Policies'),
  // This will provide you with a form for editing the properties on your
  // exportable, with validate and submit handler.
  //
  // The item being edited will be in $form_state['item'].
  //
  // The submit handler is only responsible for moving data from
  // $form_state['values'] to $form_state['item'].
  //
  // All callbacks will accept &$form and &$form_state as arguments.
  'form' => array(
    'settings' => 'password_policy_admin_settings',
    'validate' => 'password_policy_admin_validate',
    'submit' => 'password_policy_admin_submit',
  ),
);
