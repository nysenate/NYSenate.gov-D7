<?php
/**
 * @file
 * nys_dashboards_conf.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nys_dashboards_conf_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-constituent-dashboard-menu_bills:menutoken/54f4b9ebecc16
  $menu_links['menu-constituent-dashboard-menu_bills:menutoken/54f4b9ebecc16'] = array(
    'menu_name' => 'menu-constituent-dashboard-menu',
    'link_path' => 'menutoken/54f4b9ebecc16',
    'router_path' => 'menutoken/%',
    'link_title' => 'Bills',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/dashboard/bills',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-constituent-dashboard-menu_bills:menutoken/54f4b9ebecc16',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-constituent-dashboard-menu_committees:menutoken/54f4ba2e5aac3
  $menu_links['menu-constituent-dashboard-menu_committees:menutoken/54f4ba2e5aac3'] = array(
    'menu_name' => 'menu-constituent-dashboard-menu',
    'link_path' => 'menutoken/54f4ba2e5aac3',
    'router_path' => 'menutoken/%',
    'link_title' => 'Committees',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/dashboard/committees',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-constituent-dashboard-menu_committees:menutoken/54f4ba2e5aac3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-constituent-dashboard-menu_inbox:menutoken/54f4baa546d96
  $menu_links['menu-constituent-dashboard-menu_inbox:menutoken/54f4baa546d96'] = array(
    'menu_name' => 'menu-constituent-dashboard-menu',
    'link_path' => 'menutoken/54f4baa546d96',
    'router_path' => 'menutoken/%',
    'link_title' => 'Inbox',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/dashboard/inbox',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-constituent-dashboard-menu_inbox:menutoken/54f4baa546d96',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-constituent-dashboard-menu_issues:menutoken/54f4b9dc31a76
  $menu_links['menu-constituent-dashboard-menu_issues:menutoken/54f4b9dc31a76'] = array(
    'menu_name' => 'menu-constituent-dashboard-menu',
    'link_path' => 'menutoken/54f4b9dc31a76',
    'router_path' => 'menutoken/%',
    'link_title' => 'Issues',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/dashboard/issues',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-constituent-dashboard-menu_issues:menutoken/54f4b9dc31a76',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-constituent-dashboard-menu_petitions--questionnaires:menutoken/54f4ba65d9d60
  $menu_links['menu-constituent-dashboard-menu_petitions--questionnaires:menutoken/54f4ba65d9d60'] = array(
    'menu_name' => 'menu-constituent-dashboard-menu',
    'link_path' => 'menutoken/54f4ba65d9d60',
    'router_path' => 'menutoken/%',
    'link_title' => 'Petitions & Questionnaires',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/dashboard/petitions',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-constituent-dashboard-menu_petitions--questionnaires:menutoken/54f4ba65d9d60',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-dashboard-menu_bills:menutoken/54f4b8d62c52f
  $menu_links['menu-senator-dashboard-menu_bills:menutoken/54f4b8d62c52f'] = array(
    'menu_name' => 'menu-senator-dashboard-menu',
    'link_path' => 'menutoken/54f4b8d62c52f',
    'router_path' => 'menutoken/%',
    'link_title' => 'Bills',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_token_link_path' => 'user/[user:uid]/dashboard/bills',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'identifier' => 'menu-senator-dashboard-menu_bills:menutoken/54f4b8d62c52f',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-dashboard-menu_constituents:menutoken/54f4b8c185dc6
  $menu_links['menu-senator-dashboard-menu_constituents:menutoken/54f4b8c185dc6'] = array(
    'menu_name' => 'menu-senator-dashboard-menu',
    'link_path' => 'menutoken/54f4b8c185dc6',
    'router_path' => 'menutoken/%',
    'link_title' => 'Constituents',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_token_link_path' => 'user/[user:uid]/dashboard/constituents',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'identifier' => 'menu-senator-dashboard-menu_constituents:menutoken/54f4b8c185dc6',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-dashboard-menu_inbox:menutoken/54f4b776e0ee3
  $menu_links['menu-senator-dashboard-menu_inbox:menutoken/54f4b776e0ee3'] = array(
    'menu_name' => 'menu-senator-dashboard-menu',
    'link_path' => 'menutoken/54f4b776e0ee3',
    'router_path' => 'menutoken/%',
    'link_title' => 'Inbox',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'menu_token_link_path' => 'user/[user:uid]/dashboard/inbox',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'identifier' => 'menu-senator-dashboard-menu_inbox:menutoken/54f4b776e0ee3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-dashboard-menu_issues:menutoken/54f4b8e799cb2
  $menu_links['menu-senator-dashboard-menu_issues:menutoken/54f4b8e799cb2'] = array(
    'menu_name' => 'menu-senator-dashboard-menu',
    'link_path' => 'menutoken/54f4b8e799cb2',
    'router_path' => 'menutoken/%',
    'link_title' => 'Issues',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_token_link_path' => 'user/[user:uid]/dashboard/issues',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'identifier' => 'menu-senator-dashboard-menu_issues:menutoken/54f4b8e799cb2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-dashboard-menu_overview:menutoken/54f4b8b003fdd
  $menu_links['menu-senator-dashboard-menu_overview:menutoken/54f4b8b003fdd'] = array(
    'menu_name' => 'menu-senator-dashboard-menu',
    'link_path' => 'menutoken/54f4b8b003fdd',
    'router_path' => 'menutoken/%',
    'link_title' => 'Overview',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_token_link_path' => 'user/[user:uid]/dashboard',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'identifier' => 'menu-senator-dashboard-menu_overview:menutoken/54f4b8b003fdd',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-dashboard-menu_questionnaires:menutoken/54f4b8fc1f701
  $menu_links['menu-senator-dashboard-menu_questionnaires:menutoken/54f4b8fc1f701'] = array(
    'menu_name' => 'menu-senator-dashboard-menu',
    'link_path' => 'menutoken/54f4b8fc1f701',
    'router_path' => 'menutoken/%',
    'link_title' => 'Questionnaires',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_token_link_path' => 'user/[user:uid]/dashboard/questionnaires',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'identifier' => 'menu-senator-dashboard-menu_questionnaires:menutoken/54f4b8fc1f701',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Bills');
  t('Committees');
  t('Constituents');
  t('Inbox');
  t('Issues');
  t('Overview');
  t('Petitions & Questionnaires');
  t('Questionnaires');


  return $menu_links;
}
