<?php

/**
 * Implements hook_panels_layouts()
 */
function nysenate_f2cb_pbudget_panels_layouts() {
  $items['f2cb_pbudget'] = array(
    'title' => t('Participatory Budget layout'),
    'category' => t('Foundation: 2'),
    'icon' => 'f2cb_newsroom.png',
    'theme' => 'f2cb_pbudget',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      //'above_left' => t('Above Left'),
      //'above_right' => t('Above Right'),
      'tabs' => t('Tabs'),
      //'below_left' => t('Below Left'),
      //'below_right' => t('Below Right'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

