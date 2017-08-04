<?php
/**
 * @file
 * nys_senators.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nys_senators_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-senator-s-microsite-menu_about:menutoken/545bc4ad53efd
  $menu_links['menu-senator-s-microsite-menu_about:menutoken/545bc4ad53efd'] = array(
    'menu_name' => 'menu-senator-s-microsite-menu',
    'link_path' => 'menutoken/545bc4ad53efd',
    'router_path' => 'menutoken/%',
    'link_title' => 'About',
    'options' => array(
      'menu_token_link_path' => '[node:senator_microsite]/about',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_senator_context',
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
      'identifier' => 'menu-senator-s-microsite-menu_about:menutoken/545bc4ad53efd',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-s-microsite-menu_contact:menutoken/545bc4d72fa0b
  $menu_links['menu-senator-s-microsite-menu_contact:menutoken/545bc4d72fa0b'] = array(
    'menu_name' => 'menu-senator-s-microsite-menu',
    'link_path' => 'menutoken/545bc4d72fa0b',
    'router_path' => 'menutoken/%',
    'link_title' => 'Contact',
    'options' => array(
      'menu_token_link_path' => '[node:senator_microsite]/contact',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_senator_context',
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
      'identifier' => 'menu-senator-s-microsite-menu_contact:menutoken/545bc4d72fa0b',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-s-microsite-menu_events:menutoken/545bc4c3139ef
  $menu_links['menu-senator-s-microsite-menu_events:menutoken/545bc4c3139ef'] = array(
    'menu_name' => 'menu-senator-s-microsite-menu',
    'link_path' => 'menutoken/545bc4c3139ef',
    'router_path' => 'menutoken/%',
    'link_title' => 'Events',
    'options' => array(
      'menu_token_link_path' => '[node:senator_microsite]/calendar',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_senator_context',
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
      'identifier' => 'menu-senator-s-microsite-menu_events:menutoken/545bc4c3139ef',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-s-microsite-menu_legislation:menutoken/545bc49a109bd
  $menu_links['menu-senator-s-microsite-menu_legislation:menutoken/545bc49a109bd'] = array(
    'menu_name' => 'menu-senator-s-microsite-menu',
    'link_path' => 'menutoken/545bc49a109bd',
    'router_path' => 'menutoken/%',
    'link_title' => 'Legislation',
    'options' => array(
      'menu_token_link_path' => '[node:senator_microsite]/legislation',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_senator_context',
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
      'identifier' => 'menu-senator-s-microsite-menu_legislation:menutoken/545bc49a109bd',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-s-microsite-menu_newsroom:menutoken/545bc48544bf1
  $menu_links['menu-senator-s-microsite-menu_newsroom:menutoken/545bc48544bf1'] = array(
    'menu_name' => 'menu-senator-s-microsite-menu',
    'link_path' => 'menutoken/545bc48544bf1',
    'router_path' => 'menutoken/%',
    'link_title' => 'Newsroom',
    'options' => array(
      'menu_token_link_path' => '[node:senator_microsite]/newsroom',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_senator_context',
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
      'identifier' => 'menu-senator-s-microsite-menu_newsroom:menutoken/545bc48544bf1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-senator-s-microsite-menu_our-district:menutoken/545bc51352089
  $menu_links['menu-senator-s-microsite-menu_our-district:menutoken/545bc51352089'] = array(
    'menu_name' => 'menu-senator-s-microsite-menu',
    'link_path' => 'menutoken/545bc51352089',
    'router_path' => 'menutoken/%',
    'link_title' => 'Our District',
    'options' => array(
      'menu_token_link_path' => '[node:district_tid]',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_senator_context',
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
      'identifier' => 'menu-senator-s-microsite-menu_our-district:menutoken/545bc51352089',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Contact');
  t('Events');
  t('Legislation');
  t('Newsroom');
  t('Our District');


  return $menu_links;
}
