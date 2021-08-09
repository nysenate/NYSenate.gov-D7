<?php

/**
 * @file
 * nys_senators.fieldable_panels_pane_type.inc
 */

/**
 * Implements hook_default_fieldable_panels_pane_type().
 */
function nys_senators_default_fieldable_panels_pane_type() {
  $export = array();

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'fieldable_panels_pane';
  $fieldable_panels_pane_type->title = 'Panels Pane';
  $fieldable_panels_pane_type->description = '';
  $export['fieldable_panels_pane'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'promotional_banner';
  $fieldable_panels_pane_type->title = 'Custom Promotional Banner';
  $fieldable_panels_pane_type->description = '';
  $export['promotional_banner'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'promotional_banner_2up';
  $fieldable_panels_pane_type->title = 'Add Promotional Banners - 2 Col Square';
  $fieldable_panels_pane_type->description = 'Adds half square format promotional banners in two column grid.';
  $export['promotional_banner_2up'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'promotional_banner_reference';
  $fieldable_panels_pane_type->title = 'Add Full Promotional Banner';
  $fieldable_panels_pane_type->description = '';
  $export['promotional_banner_reference'] = $fieldable_panels_pane_type;

  $fieldable_panels_pane_type = new stdClass();
  $fieldable_panels_pane_type->disabled = FALSE; /* Edit this to true to make a default fieldable_panels_pane_type disabled initially */
  $fieldable_panels_pane_type->api_version = 1;
  $fieldable_panels_pane_type->name = 'women_of_distinction';
  $fieldable_panels_pane_type->title = 'Nomination Form for Women or Veterans';
  $fieldable_panels_pane_type->description = '';
  $export['women_of_distinction'] = $fieldable_panels_pane_type;

  return $export;
}
