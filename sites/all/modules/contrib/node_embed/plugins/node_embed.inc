<?php
/**
 * @file
 * Define a Wysiwyg plugin.
 *
 * Supposed to be used for "Drupal plugins" (cross-editor plugins) only.
 *
 * @see hook_wysiwyg_plugin()
 *
 * Each plugin file in the specified plugin directory of a module needs to
 * define meta information about the particular plugin provided.
 * The plugin's hook implementation function name is built out of the following:
 * - 'hook': The name of the module providing the plugin.
 * - 'INCLUDE': The basename of the file containing the plugin definition.
 * - 'plugin': Static.
 *
 * For example, if your module's name is 'mymodule' and
 * mymodule_wysiwyg_include_directory() returned 'plugins' as plugin directory,
 * and this directory contains an "awesome" plugin file named 'awesome.inc', i.e.
 *   sites/all/modules/mymodule/plugins/awesome.inc
 * then the corresponding plugin hook function name is:
 *   mymodule_awesome_plugin()
 *
 * @see hook_wysiwyg_include_directory()
 *
 * @return
 *   Meta information about the buttons provided by this plugin.
 */
function node_embed_node_embed_plugin() {

  // add necessary jQuery ui libs
  drupal_add_library('system', 'ui');
  drupal_add_library('system', 'ui.draggable');
  drupal_add_library('system', 'ui.droppable');
  drupal_add_library('system', 'ui.dialog');

  $plugins['node_embed'] = array(
    // The plugin's title;
    'title' => t('Node Embed'),
    // The (vendor) homepage of this plugin; defaults to ''.
    'vendor url' => 'http://drupal.org/project/node_embed',
    // The button image filename; defaults to '[plugin-name].png'.
    'icon path' => drupal_get_path('module', 'node_embed') . '/plugins/images',
    'icon file' => 'icon.gif',
    // The button title to display on hover.
    'icon title' => t('Embed a Node'),
    // An alternative path to the integration JavaScript; defaults to
    // '[path-to-module]/[plugins-directory]/[plugin-name]'.
    'js path' => drupal_get_path('module', 'node_embed') . '/plugins/js',
    // An alternative filename of the integration JavaScript; defaults to
    // '[plugin-name].js'.
    'js file' => 'node_embed.js',
    // An array of settings for this button. Required, but API is still in flux.
    'settings' => array(),
  );
  return $plugins;
}
