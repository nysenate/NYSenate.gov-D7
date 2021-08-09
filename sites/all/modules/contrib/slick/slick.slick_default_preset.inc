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

  $values = array(
    'name' => 'default',
    'label' => 'Default',
    'breakpoints' => 0,
    'skin' => '',
  );
  $preset = slick_optionset_create($values);
  $preset->disabled = TRUE;
  $preset->api_version = 1;
  $presets['default'] = $preset;

  return $presets;
}
