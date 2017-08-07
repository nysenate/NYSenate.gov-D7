<?php

/**
 * Implements hook_panels_layouts()
 */
function nysenate_f2cb_meeting_page_panels_layouts() {
  $items['f2cb_meeting_page'] = array(
    'title' => t('Meeting page layout'),
    'category' => t('Foundation: 2'),
    'icon' => 'f2cb_meeting_page.png',
    'theme' => 'f2cb_meeting_page',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      //'above_left' => t('Above Left'),
      //'above_right' => t('Above Right'),
      //'tabs' => t('Tabs'),
      //'below_left' => t('Below Left'),
      //'below_right' => t('Below Right'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

