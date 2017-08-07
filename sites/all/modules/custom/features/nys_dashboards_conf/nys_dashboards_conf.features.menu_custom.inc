<?php
/**
 * @file
 * nys_dashboards_conf.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nys_dashboards_conf_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-constituent-dashboard-menu.
  $menus['menu-constituent-dashboard-menu'] = array(
    'menu_name' => 'menu-constituent-dashboard-menu',
    'title' => 'Constituent Dashboard Menu',
    'description' => '',
  );
  // Exported menu: menu-senator-dashboard-menu.
  $menus['menu-senator-dashboard-menu'] = array(
    'menu_name' => 'menu-senator-dashboard-menu',
    'title' => 'Senator Dashboard menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Constituent Dashboard Menu');
  t('Senator Dashboard menu');


  return $menus;
}
