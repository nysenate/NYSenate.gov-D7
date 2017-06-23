<?php
/**
 * @file
 * Slick default preset API include file.
 */

/**
 * Implements hook_slick_default_presets().
 */
function slick_slick_default_presets() {
  $presets = array();

  $preset = slick_optionset_create();
  $preset->disabled = FALSE;
  $preset->api_version = 1;
  $preset->name = 'default';
  $preset->label = 'Default';
  $preset->breakpoints = 0;
  $preset->skin = '';
  $presets['default'] = $preset;

  return $presets;
}
