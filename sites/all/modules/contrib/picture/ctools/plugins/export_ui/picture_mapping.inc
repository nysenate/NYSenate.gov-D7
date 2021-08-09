<?php

/**
 * Implements HOOK_PLUGIN_ctools_export_ui().
 */
function picture_picture_mapping_ctools_export_ui() {
  /**
   * Form functions.
   */
  module_load_include('inc', 'picture', 'picture.admin');

  return array(
    'schema' => 'picture_mapping',
    'access' => 'administer pictures',
    'menu' => array(
      'menu prefix' => 'admin/config/media',
      'menu item' => 'picture',
      'menu title' => 'Picture mappings',
      'menu description' => 'Manage picture mappings.',
    ),
    'title singular' => t('picture mapping'),
    'title plural' => t('picture mappings'),
    'title singular proper' => t('Picture mapping'),
    'title plural proper' => t('Picture mappings'),
    'form' => array(
      'settings' => 'picture_mapping_form',
    ),
    'use wizard' => TRUE,
    'form info' => array(
      'free trail' => FALSE,
      'order' => array(
        'pick_breakpoint_group' => t('Breakpoint group'),
        'configure' => t('Configure picture mappings'),
      ),
      'edit order' => array(
        'configure' => t('Configure the matching engine'),
      ),
      'clone order' => array(
        'configure' => t('Configure the matching engine'),
      ),
      'import order' => array(
        'import' => t('Import code'),
      ),
      'forms' => array(
        'pick_breakpoint_group' => array(
          'form id' => 'picture_select_breakpoint_group_form',
        ),
      ),
    ),
  );
}

/**
 * Define this Export UI plugin.
 */
$plugin = picture_picture_mapping_ctools_export_ui();
