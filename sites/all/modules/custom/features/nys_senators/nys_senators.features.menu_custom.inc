<?php
/**
 * @file
 * nys_senators.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nys_senators_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-senator-s-microsite-menu.
  $menus['menu-senator-s-microsite-menu'] = array(
    'menu_name' => 'menu-senator-s-microsite-menu',
    'title' => 'Senator\'s Microsite Menu',
    'description' => 'Menu for the senator\'s microsite',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu for the senator\'s microsite');
  t('Senator\'s Microsite Menu');


  return $menus;
}
