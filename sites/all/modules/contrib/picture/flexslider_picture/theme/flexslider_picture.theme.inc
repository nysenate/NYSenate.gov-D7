<?php

/**
 * @file
 * Picture formatter with flexslider support.
 */

/**
 * Process the items and prepare the item slides to be rendered.
 *
 * @param array $vars
 *   Variables.
 */
function template_preprocess_flexslider_picture_list(array &$vars) {
  $optionset = &$vars['settings']['optionset'];

  // Check if this is a picture optionset.
  $vars['picture_formatter_enabled'] = (isset($optionset->imagestyle_type) && !empty($optionset->imagestyle_type) && $optionset->imagestyle_type == 'picture_mapping');

  if ($vars['picture_formatter_enabled']) {
    $items = &$vars['items'];

    // Get the breakpoints based on the mapping.
    $fallback_image_style = $optionset->fallback;
    $mappings = picture_mapping_load($optionset->mapping);
    if (!$mappings) {
      trigger_error(check_plain("Unable to load picture mapping {$optionset->mapping}."), E_USER_ERROR);
      return;
    }
    $breakpoint_styles = picture_get_mapping_breakpoints($mappings, $fallback_image_style);

    // If colorbox is enabled build additional configuration.
    if (!empty($optionset->options['colorboxEnabled'])) {
      // Add additional necessary scripts and styles.
      drupal_add_js(drupal_get_path('module', 'picture') . '/picture_colorbox.js');
      drupal_add_css(drupal_get_path('module', 'picture') . '/picture_colorbox.css');
      if (!variable_get('colorbox_inline', 0)) {
        drupal_add_js(drupal_get_path('module', 'colorbox') . '/js/colorbox_inline.js');
      }

      $colorbox_fallback_image_style = $optionset->options['colorboxFallbackImageStyle'];
      $mappings = picture_mapping_load($optionset->options['colorboxImageStyle']);
      if (!$mappings) {
        trigger_error(check_plain("Unable to load picture mapping {$optionset->options['colorboxImageStyle']}."), E_USER_ERROR);
        $optionset->options['colorboxEnabled'] = FALSE;
      }
      else {
        $colorbox_breakpoints = picture_get_mapping_breakpoints($mappings, $colorbox_fallback_image_style);
        // Grouping ID for the colorbox gallery. Use more_entropy to ensure the
        // php function works on every environment (cygwin).
        $colorbox_group_id = uniqid('flexgroup', TRUE);
      }
    }

    // Prepare the item slides to be passed to render().
    foreach ($items as &$item) {
      if (isset($item['item'])) {
        $item['slide'] = array(
          '#theme' => 'picture',
          '#style_name' => $fallback_image_style,
          '#uri' => $item['item']['uri'],
          '#height' => $item['item']['height'],
          '#width' => $item['item']['width'],
          '#alt' => $item['item']['alt'],
          '#title' => $item['item']['title'],
          '#breakpoints' => $breakpoint_styles,
        );

        // If colorbox is enabled change the theming function and add settings.
        if (!empty($optionset->options['colorboxEnabled'])) {
          $item['slide'] = array(
            '#theme' => 'picture_formatter_colorbox',
            '#item' => $item['item'],
            '#image_style' => $fallback_image_style,
            '#path' => $item['item']['uri'],
            '#colorbox_image_style' => $colorbox_fallback_image_style,
            '#colorbox' => $colorbox_breakpoints,
            '#colorbox_group_id' => $colorbox_group_id,
            '#width' => $item['item']['width'],
            '#height' => $item['item']['height'],
            '#alt' => $item['item']['alt'],
            '#title' => $item['item']['title'],
            '#breakpoints' => $breakpoint_styles,
          );
        }
        if (!isset($item['thumb'])) {
          $item['thumb'] = image_style_url($fallback_image_style, $item['item']['uri']);
        }
      }
    }
  }
}

/**
 * Theme list item.
 */
function template_process_flexslider_picture_list_item(&$vars) {
  // Call the default process function first.
  template_process_flexslider_list_item($vars);

  $settings = $vars['settings'];
  $attributes = &$vars['settings']['attributes'];
  if (isset($settings['optionset']->options['controlNav']) and $settings['optionset']->options['controlNav'] === "thumbnails" && !isset($attributes['data-thumb']) || empty($attributes['data-thumb'])) {
    if (isset($vars['thumb'])) {
      $attributes['data-thumb'] = $vars['thumb'];
    }
    else {
      $src = array();
      preg_match("<img.+?srcset=[\"'](.+?)[\"'\s].+?>", $vars['item'], $src);

      if (!empty($src[1])) {
        $attributes['data-thumb'] = $src[1];
      }
    }
  }
}

/**
 * Theme callback.
 */
function theme_flexslider_picture_list(&$vars) {
  if (!empty($vars['picture_formatter_enabled'])) {
    // Reference configuration variables.
    $attributes = &$vars['settings']['attributes'];
    $type = &$vars['settings']['type'];
    $output = '';

    // Build the list.
    if (!empty($vars['items'])) {
      $output .= "<$type" . drupal_attributes($attributes) . '>';
      foreach ($vars['items'] as $item) {
        $slide = render($item['slide']);
        $output .= theme('flexslider_list_item', array(
          'item' => $slide,
          'thumb' => isset($item['thumb']) ? $item['thumb'] : NULL,
          'settings' => $vars['settings'],
          'caption' => isset($item['caption']) ? $item['caption'] : '',
        ));
      }
      $output .= "</$type>";
    }

    return $output;
  }
  // If this isn't a picture optionset use the default theming.
  return theme_flexslider_list($vars);
}
