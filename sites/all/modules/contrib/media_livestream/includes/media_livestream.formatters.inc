<?php

/**
 * @file
 * Formatter functions for the media_livestream module.
 */

/**
 * Implements hook_file_formatter_info().
 */
function media_livestream_file_formatter_info() {
  $formatters['media_livestream_video'] = array(
    'label' => t('Livestream Video'),
    'file types' => array('video'),
    'default settings' => array(),
    'view callback' => 'media_livestream_file_formatter_video_view',
    'settings callback' => 'media_livestream_file_formatter_video_settings',
  );
  foreach (media_livestream_variable_default() as $setting => $default_value) {
    $formatters['media_livestream_video']['default settings'][$setting] = media_livestream_variable_get($setting);
  }

  $formatters['media_livestream_image'] = array(
    'label' => t('Livestream Preview Image'),
    'file types' => array('video'),
    'default settings' => array(
      'image_style' => '',
    ),
    'view callback' => 'media_livestream_file_formatter_image_view',
    'settings callback' => 'media_livestream_file_formatter_image_settings',
  );
  return $formatters;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_livestream_file_formatter_video_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  // WYSIWYG does not yet support video inside a running editor instance.
  if ($scheme == 'livestream' && empty($file->override['wysiwyg'])) {
    $element = array(
      '#theme' => 'media_livestream_video',
      '#uri' => $file->uri,
      '#options' => array(),
    );
    foreach (media_livestream_variable_default() as $setting => $default_value) {
      $element['#options'][$setting] = isset($file->override[$setting]) ? $file->override[$setting] : $display['settings'][$setting];
    }
    return $element;
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_livestream_file_formatter_video_settings($form, &$form_state, $settings) {
  $element = array();

  $element['width'] = array(
    '#title' => t('Width'),
    '#type' => 'textfield',
    '#default_value' => $settings['width'],
    '#element_validate' => array('_livestream_validate_video_width_and_height'),
  );
  $element['height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#default_value' => $settings['height'],
    '#element_validate' => array('_livestream_validate_video_width_and_height'),
  );

  $element['autoplay_channel'] = array(
    '#title' => t('Autoplay channels'),
    '#type' => 'checkbox',
    '#default_value' => $settings['autoplay_channel'],
  );

  $element['autoplay_video'] = array(
    '#title' => t('Autoplay recorded videos'),
    '#type' => 'checkbox',
    '#default_value' => $settings['autoplay_video'],
  );

  $element['mute'] = array(
    '#title' => t('Mute'),
    '#type' => 'checkbox',
    '#default_value' => $settings['mute'],
  );

  $element['layout'] = array(
    '#title' => t('Layout'),
    '#type' => 'select',
    '#options' => array(
      '0' => 'Player + Chat right + Slider bottom',
      '1' => 'Player top + Slider bottom',
      '2' => 'Player top + Chat bottom',
      '3' => 'Player left + Chat right',
      '4' => 'Player only (full player)',
      '5' => 'Slider only (recordings)',
      '6' => 'Chat only (full chat block)',
    ),
    '#default_value' => $settings['layout'],
  );

  $element['protocol_specify'] = array(
    '#title' => t('Specify an http protocol'),
    '#type' => 'checkbox',
    '#default_value' => $settings['protocol_specify'],
    '#description' => t('An explicit protocol may be neccesary for videos embedded in RSS feeds and emails.
        If no protocol is specified, iframes will be protocol relative.'),
  );

  $element['protocol'] = array(
    '#title' => t('Iframe protocol'),
    '#type' => 'radios',
    '#default_value' => $settings['protocol'],
    '#options' => array(
      'http:' => 'http://',
      'https:' => 'https://',
    ),
    '#states' => array(
      'invisible' => array(
        ':input[name="displays[media_livestream_video][settings][protocol_specify]"]' => array('checked' => FALSE),
      ),
    ),
  );

  return $element;
}

/**
 * Validation for width and height.
 */
function _livestream_validate_video_width_and_height($element, &$form_state, $form) {
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
function media_livestream_file_formatter_image_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
  if ($scheme == 'livestream') {
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
function media_livestream_file_formatter_image_settings($form, &$form_state, $settings) {
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

/**
 * Implements hook_file_default_displays().
 */
function media_livestream_file_default_displays() {

  // Default settings for displaying as a video.
  $default_displays = array();

  $default_video_settings = array(
    'default' => array(
      'width' => 640,
      'height' => 388,
    ),
    'teaser' => array(
      'width' => 560,
      'height' => 348,
      'autoplay_channel' => FALSE,
      'autoplay_video' => FALSE,
    ),

    // Legacy view modes included to support older versions of Media,
    // before #1051090 went through. They do no harm and can sit here
    // until there is a Media 2.x stable.
    // @TODO: Remove when Media 2.0 is released.
    'media_large' => array(
      'width' => 560,
      'height' => 348,
      'autoplay_channel' => FALSE,
      'autoplay_video' => FALSE,
    ),
    'media_original' => array(
      'width' => 640,
      'height' => 388,
      'autoplay_channel' => media_livestream_variable_get('autoplay_channel'),
      'autoplay_video' => media_livestream_variable_get('autoplay_video'),
    ),

  );
  foreach ($default_video_settings as $view_mode => $settings) {
    $display_name = 'video__' . $view_mode . '__media_livestream_video';
    $default_displays[$display_name] = (object) array(
      'api_version' => 1,
      'name' => $display_name,
      'status' => 1,
      'weight' => 1,
      'settings' => $settings,
    );
  }

  // Default settings for displaying a video preview image.
  // We enable preview images even for view modes that also play video
  // for use inside a running WYSIWYG editor. We weight them so video
  // formatters come first in the cascade to make sure the video formatter
  // is used whenever possible.
  $default_image_styles = array(
    'default' => 'large',
    'preview' => 'square_thumbnail',
    'teaser' => 'large',

    // Legacy view modes, see note above.
    'media_preview' => 'square_thumbnail',
    'media_large' => 'large',
    'media_original' => '',

  );
  foreach ($default_image_styles as $view_mode => $image_style) {
    $display_name = 'video__' . $view_mode . '__media_livestream_image';
    $default_displays[$display_name] = (object) array(
      'api_version' => 1,
      'name' => $display_name,
      'status' => 1,
      'weight' => 2,
      'settings' => array('image_style' => $image_style),
    );
  }

  return $default_displays;
}
