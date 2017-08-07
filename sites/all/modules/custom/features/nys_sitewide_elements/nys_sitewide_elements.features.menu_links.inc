<?php
/**
 * @file
 * nys_sitewide_elements.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nys_sitewide_elements_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-global-footer_accessibility-statement:about
  $menu_links['menu-global-footer_accessibility-statement:about'] = array(
    'menu_name' => 'menu-global-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'Accessibility Statement',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-footer_accessibility-statement:about',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-global-footer_contact-the-senate:contact
  $menu_links['menu-global-footer_contact-the-senate:contact'] = array(
    'menu_name' => 'menu-global-footer',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact the Senate',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-footer_contact-the-senate:contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-global-footer_creative-commons:about
  $menu_links['menu-global-footer_creative-commons:about'] = array(
    'menu_name' => 'menu-global-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'Creative Commons',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-footer_creative-commons:about',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-global-footer_policies--waivers:about
  $menu_links['menu-global-footer_policies--waivers:about'] = array(
    'menu_name' => 'menu-global-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'Policies & Waivers',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-footer_policies--waivers:about',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-global-footer_privacy-policy:about
  $menu_links['menu-global-footer_privacy-policy:about'] = array(
    'menu_name' => 'menu-global-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-footer_privacy-policy:about',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-global-footer_rss:about
  $menu_links['menu-global-footer_rss:about'] = array(
    'menu_name' => 'menu-global-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'RSS',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-footer_rss:about',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-global-footer_terms-of-participation:about
  $menu_links['menu-global-footer_terms-of-participation:about'] = array(
    'menu_name' => 'menu-global-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'Terms of Participation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-global-footer_terms-of-participation:about',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Accessibility Statement');
  t('Contact the Senate');
  t('Creative Commons');
  t('Developers');
  t('Policies & Waivers');
  t('Privacy Policy');
  t('RSS');
  t('Terms of Participation');


  return $menu_links;
}
