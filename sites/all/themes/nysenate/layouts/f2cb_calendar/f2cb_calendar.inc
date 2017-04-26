<?php

/**
 * Implements hook_panels_layouts()
 */
function nysenate_f2cb_calendar_panels_layouts() {
  $items['f2cb_calendar'] = array(
    'title' => t('Calendar Tab Layout'),
    'category' => t('Foundation: 2'),
    'icon' => 'f2cb_calendar.png',
    'theme' => 'f2cb_calendar',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      'today' => t('Today'),
      //'tabs' => t('Tabs'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

