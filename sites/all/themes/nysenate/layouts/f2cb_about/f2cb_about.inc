<?php

/**
 * Implements hook_panels_layouts()
 */
function nysenate_f2cb_about_panels_layouts() {
  $items['f2cb_about'] = array(
    'title' => t('About Layout'),
    'category' => t('Foundation: 2'),
    'icon' => 'f2cb_about.png',
    'theme' => 'f2cb_about',
    'regions' => array(
      'hero' => t('hero'),
      'content' => t('Main Content'),
    ),
  );
  return $items;
}

