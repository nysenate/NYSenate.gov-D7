<?php

/**
 * Implements hook_panels_layouts()
 */
function nysenate_f2cb_public_hearing_panels_layouts() {
  $items['f2cb_public_hearing'] = array(
    'title' => t('Public Hearing Detail Layout'),
    'category' => t('Foundation: 2'),
    'icon' => 'f2cb_public_hearing.png',
    'theme' => 'f2cb_public_hearing',
    'regions' => array(
      'top' => t('Top'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

