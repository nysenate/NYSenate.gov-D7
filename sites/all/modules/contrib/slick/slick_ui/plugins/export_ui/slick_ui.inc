<?php
/**
 * @file
 * Export interface plugin.
 */

/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'slick_optionset',
  'access' => 'administer slick',

  // Define the menu item.
  'menu' => array(
    'menu prefix' => 'admin/config/media',
    'menu item' => 'slick',
    'menu title' => 'Slick carousel',
    'menu description' => 'Administer Slick carousel presets.',
  ),

  // Define user interface texts.
  'title singular' => t('optionset'),
  'title plural' => t('optionsets'),
  'title singular proper' => t('Slick carousel optionset'),
  'title plural proper' => t('Slick carousel optionsets'),

  // Define our handler.
  'handler' => array(
    'class' => 'SlickUi',
    'parent' => 'ctools_export_ui',
  ),
);
