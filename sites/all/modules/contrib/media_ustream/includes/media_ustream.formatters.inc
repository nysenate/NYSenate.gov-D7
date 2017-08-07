<?php

/**
 * @file
 * Formatter functions for the media_ustream module.
 */

/**
 * Implements hook_file_formatter_info().
 */
function media_ustream_file_formatter_info() {
  $formatters['media_ustream_video'] = array(
    'label' => t('UStream Video'),
    'file types' => array('video'),
    'default settings' => array(),
    'view callback' => 'media_ustream_file_formatter_video_view',
    'settings callback' => 'media_ustream_file_formatter_video_settings',
  );

  $formatters['media_ustream_video']['default settings'] = array(
    'width' => 640,
    'height' => 393,
    'autoplay_live' => FALSE,
    'autoplay_recorded' => FALSE,
    'new_player' => TRUE,
    'player_color' => '',
    'custom_color' => '',
  );

  $formatters['media_ustream_image'] = array(
    'label' => t('UStream Preview Image'),
    'file types' => array('video'),
    'default settings' => array(
      'image_style' => '',
    ),
    'view callback' => 'media_ustream_file_formatter_image_view',
    'settings callback' => 'media_ustream_file_formatter_image_settings',
    'mime types' => array('video/ustream'),
  );
  return $formatters;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_ustream_file_formatter_video_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  // WYSIWYG does not yet support video inside a running editor instance.
  if ($scheme == 'ustream' && empty($file->override['wysiwyg'])) {
    $element = array(
      '#theme' => 'media_ustream_video',
      '#uri' => $file->uri,
      '#options' => array(),
    );
    foreach (array('width', 'height', 'autoplay_live', 'autoplay_recorded', 'new_player', 'player_color', 'custom_color') as $setting) {
      $element['#options'][$setting] = isset($file->override[$setting]) ? $file->override[$setting] : $display['settings'][$setting];
    }
    return $element;
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_ustream_file_formatter_video_settings($form, &$form_state, $settings) {
  $element = array();

  // Player settings.
  $element['width'] = array(
    '#title' => t('Player width'),
    '#type' => 'textfield',
    '#default_value' => $settings['width'],
    '#element_validate' => array('_ustream_validate_video_width_and_height'),
  );

  $element['height'] = array(
    '#title' => t('Player height'),
    '#type' => 'textfield',
    '#default_value' => $settings['height'],
    '#element_validate' => array('_ustream_validate_video_width_and_height'),
  );

  $element['autoplay_live'] = array(
    '#title' => t('Autoplay live channels'),
    '#type' => 'checkbox',
    '#default_value' => $settings['autoplay_live'],
  );

  $element['autoplay_recorded'] = array(
    '#title' => t('Autoplay recorded videos'),
    '#type' => 'checkbox',
    '#default_value' => $settings['autoplay_recorded'],
  );

  $element['new_player'] = array(
    '#title' => t('Render new style player.'),
    '#type' => 'checkbox',
    '#default_value' => $settings['new_player'],
    '#description' => t('Uncheck renders the old player.'),
  );

  $element['player_color'] = array(
    '#title' => t('Player color'),
    '#type' => 'radios',
    '#default_value' => $settings['player_color'],
    '#options' => array(
      ''       => 'default',
      'ff3d23' => 'Red',
      '85a901' => 'Green',
      'e166b7' => 'Pink',
      'ff720a' => 'Orange',
      'colorpicker' => 'Custom',
    ),
    '#prefix' => '<div style="width: 200px; float: left;">',
    '#suffix' => '</div>',
  );

  if (function_exists('gd_info')) {
    $base = drupal_get_path('module', 'media_ustream');
    $element['custom_color'] = array(
      '#type' => 'textfield',
      '#default_value' => $settings['custom_color'],
      '#description' => t('Set a custom color'),
      '#prefix' => '<div style="width: 200px; float: left;"><div id="placeholder"></div>',
      '#suffix' => '</div>',
//    '#element_validate' => array('_ustream_validate_video_color'), TODO.
      '#states' => array(
        'visible' => array(
          ':input[name="displays[media_ustream_video][settings][player_color]"]' => array('value' => 'colorpicker'),
        ),
      ),
      '#tree' => TRUE,
      '#attached' => array(
        'library' => array(
          array('system', 'farbtastic'),
        ),
        'js' => array(
          $base . '/js/media_ustream.js',
        ),
      ),
    );
  }
  else {
    $element['custom_color'] = array(
      '#type' => 'textfield',
      '#default_value' => $settings['custom_color'],
      '#description' => t('Set a custom color'),
      '#prefix' => '<div style="width: 200px; float: left;">',
      '#suffix' => '</div>',
//    '#element_validate' => array('_ustream_validate_video_color'), TODO.
      '#states' => array(
        'visible' => array(
          ':input[name="displays[media_ustream_video][settings][player_color]"]' => array('value' => 'colorpicker'),
        ),
      ),
    );
  }

  return $element;
}

/**
 * Validation for width and height.
 */
function _ustream_validate_video_width_and_height($element, &$form_state, $form) {
  // Check if the value is a number with an optional
  // decimal or percentage sign, or "auto".
  if (!empty($element['#value']) && !preg_match('/^(auto|([0-9]*(\.[0-9]+)?%?))$/', $element['#value'])) {
    form_error($element, t(
      "The value entered for @dimension is invalid.
      Please insert a unitless integer for pixels, a percent, or \"auto\".
      Note that percent and auto may not function correctly depending on the browser and doctype.",
      array('@dimension' => $element['#title']))
    );
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_ustream_file_formatter_image_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  if ($scheme == 'ustream') {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);

    // Only attempt to style the image if a valid image
    // style was specified in the $display settings.
    $image_style = $display['settings']['image_style'];
    $valid_image_styles = image_style_options(FALSE);
    if (empty($image_style) || !isset($valid_image_styles[$image_style])) {
      $element = array(
        '#theme' => 'image',
        '#path' => $wrapper->getOriginalThumbnailPath(),
        '#alt' => isset($file->override['attributes']['alt']) ? $file->override['attributes']['alt'] : $file->filename,
      );
    }
    else {
      $element = array(
        '#theme' => 'image_style',
        '#style_name' => $image_style,
        '#path' => $wrapper->getLocalThumbnailPath(),
        '#alt' => isset($file->override['attributes']['alt']) ? $file->override['attributes']['alt'] : $file->filename,
      );
    }
    return $element;
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_ustream_file_formatter_image_settings($form, &$form_state, $settings) {
  $element = array();
  $element['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#options' => image_style_options(FALSE),
    '#default_value' => $settings['image_style'],
    '#empty_option' => t('None (original image)'),
  );
  return $element;
}