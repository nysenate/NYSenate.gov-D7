<?php
/**
 * @file
 * nys_pictures.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nys_pictures_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'breakpoints_multipliers';
  $strongarm->value = array(
    0 => '1x',
  );
  $export['breakpoints_multipliers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagemagick_convert';
  $strongarm->value = '/usr/bin/convert';
  $export['imagemagick_convert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagemagick_gm';
  $strongarm->value = 0;
  $export['imagemagick_gm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagemagick_quality';
  $strongarm->value = '75';
  $export['imagemagick_quality'] = $strongarm;

  return $export;
}
