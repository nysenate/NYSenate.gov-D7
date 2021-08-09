<?php

/**
 * Implements hook_panels_layouts()
 */
function nysenate_f2cb_senators_and_committees_panels_layouts() {
  $items['f2cb_senators_and_committees'] = array(
    'title' => t('Senators and Committees Detail page layout'),
    'category' => t('Foundation: 2'),
    'icon' => 'f2cb_senators_and_committees.png',
    'theme' => 'f2cb_senators_and_committees',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      'senators' => t('Senators'),
      'committees' => t('Committees'),
      //'tabs' => t('Tabs'),
      //'below_left' => t('Below Left'),
      //'below_right' => t('Below Right'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

