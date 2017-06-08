<?php

/**
 * @file
 * Provides Media: WYSIWYG integration for CKEditor.
 */

/**
 * Implements hook_ckeditor_plugin_alter().
 */
function media_ckeditor_ckeditor_plugin_alter(&$plugins) {
  // Override the default CKEditor Media plugin.
  $plugins['media'] = array(
    'name' => 'media',
    'desc' => t('Plugin for embedding files using Media CKEditor'),
    'path' => '%base_path%' . drupal_get_path('module', 'media_ckeditor') . '/js/plugins/media/',
    'buttons' => array(
      'Media' => array(
        'icon' => 'images/icon.gif',
        'label' => 'Add media',
      ),
    ),
    'default' => 'f',
  );
}
