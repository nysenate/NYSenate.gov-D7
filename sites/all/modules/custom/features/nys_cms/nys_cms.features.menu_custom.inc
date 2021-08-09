<?php
/**
 * @file
 * nys_cms.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nys_cms_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-foil-admin-editor.
  $menus['menu-foil-admin-editor'] = array(
    'menu_name' => 'menu-foil-admin-editor',
    'title' => 'Foil Admin Editor',
    'description' => 'This menu holds the action links for FOIL Admins in the CMS Dashboard',
  );
  // Exported menu: menu-frontpage-editor-menu.
  $menus['menu-frontpage-editor-menu'] = array(
    'menu_name' => 'menu-frontpage-editor-menu',
    'title' => 'Frontpage Editor Menu',
    'description' => 'This menu holds the action links for Frontpage Editors in the CMS Dashboard',
  );
  // Exported menu: menu-microsite-content-editor.
  $menus['menu-microsite-content-editor'] = array(
    'menu_name' => 'menu-microsite-content-editor',
    'title' => 'Microsite Content Editor',
    'description' => 'This menu holds the action links for Microsite Content Editors in the CMS Dashboard',
  );
  // Exported menu: menu-student-program-editor.
  $menus['menu-student-program-editor'] = array(
    'menu_name' => 'menu-student-program-editor',
    'title' => 'Student Program Editor',
    'description' => 'This menu holds the action links for Student Program Editor in the CMS Dashboard',
  );
  // Exported menu: menu-web-administrator-menu.
  $menus['menu-web-administrator-menu'] = array(
    'menu_name' => 'menu-web-administrator-menu',
    'title' => 'Web Administrator Menu',
    'description' => 'This menu is for the dashboard page of Web Administrators.',
  );
  // Exported menu: navigation.
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Foil Admin Editor');
  t('Frontpage Editor Menu');
  t('Microsite Content Editor');
  t('Navigation');
  t('Student Program Editor');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t('This menu holds the action links for FOIL Admins in the CMS Dashboard');
  t('This menu holds the action links for Frontpage Editors in the CMS Dashboard');
  t('This menu holds the action links for Microsite Content Editors in the CMS Dashboard');
  t('This menu holds the action links for Student Program Editor in the CMS Dashboard');
  t('This menu is for the dashboard page of Web Administrators.');
  t('Web Administrator Menu');


  return $menus;
}
