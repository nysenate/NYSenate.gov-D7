<?php

/**
 * @file
 * Drush integration for the Picture module.
 */

/**
 * Implementation of hook_drush_command().
 */
function picture_drush_command() {
  $items['picture-mapping-flush'] = array(
    'description' => 'Flush all derived images for a given picture mapping.',
    'arguments' => array(
      'name' => 'A picture mapping machine name. If not provided, user may choose from a list of names.',
    ),
    'examples' => array(
      'drush picture-mapping-flush' => 'Pick a picture mapping and then delete its image derivatives.',
      'drush picture-mapping-flush example_mapping' => 'Delete all image derivatives used by the example_mapping picture mapping.',
    ),
    'aliases' => array('pmf'),
  );

  return $items;
}

function drush_picture_mapping_flush($name = NULL) {
  if (empty($name)) {
    $choices = drupal_map_assoc(array_keys(picture_get_mapping_options()));
    if ($choice = drush_choice($choices, dt("Choose a picture mapping to flush."))) {
      $name = $choice;
    }
    else {
      return;
    }
  }

  /** @var PictureMapping $mapping */
  $mapping = picture_mapping_load($name);
  if (!$mapping) {
    return drush_set_error(dt('Picture mapping !name not recognized.', array('!name' => $name)));
  }

  $image_styles = array();
  foreach ($mapping->getMappings() as $breakpoint_name => $multipliers) {
    $breakpoint = breakpoints_breakpoint_load_by_fullkey($breakpoint_name);
    if ($breakpoint) {
      foreach ($multipliers as $multiplier => $mapping_definition) {
        switch ($mapping_definition['mapping_type']) {
          case 'sizes':
            $image_styles = array_merge($image_styles, array_filter($mapping_definition['sizes_image_styles']));
            break;

          case 'image_style':
            $image_styles[] = $mapping_definition['image_style'];
            break;
        }
      }
    }
  }

  if (!empty($image_styles)) {
    $image_styles = array_unique($image_styles);
    foreach ($image_styles as $image_style) {
      drush_invoke('image-flush', array($image_style));
    }
  }
  else {
    drush_log(dt('No image styles found for picture mapping !name', array('!name' => $name)));
  }
}
