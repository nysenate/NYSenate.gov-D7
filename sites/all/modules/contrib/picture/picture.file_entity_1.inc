<?php

/**
 * @file
 * Hooks and functions to support version 1 of the File Entity module.
 */

/**
 * Implements hook_file_formatter_info().
 */
function picture_file_formatter_info() {
  $formatters['file_picture'] = array(
    'label' => t('Picture'),
    'default settings' => array(
      'picture_group' => '',
      'fallback_image_style' => '',
      'lazyload' => '',
      'lazyload_aspect_ratio' => '',
      'alt' => '',
      'title' => '',
    ),
    'view callback' => 'picture_file_formatter_picture_view',
    'settings callback' => 'picture_file_formatter_picture_settings',
  );

  return $formatters;
}

/**
 * View callback for hook_file_formatter_info().
 */
function picture_file_formatter_picture_view($file, $display, $langcode) {
  // Prevent PHP notices when trying to read empty files.
  // @see http://drupal.org/node/681042
  if (!$file->filesize) {
    return;
  }

  // Do not bother proceeding if this file does not have an image mime type.
  if (strpos($file->filemime, 'image/') !== 0) {
    return;
  }

  $scheme = file_uri_scheme($file->uri);
  $wrappers = file_get_stream_wrappers(STREAM_WRAPPERS_READ);
  $readable = !empty($wrappers[$scheme]);
  if ($readable) {
    $fallback_image_style = '';
    $group_name = $display['settings']['picture_group'];
    $mappings = picture_mapping_load($group_name);
    if (!$mappings) {
      trigger_error(check_plain("Unable to load picture mapping $group_name."), E_USER_ERROR);
      return;
    }
    $breakpoint_styles = picture_get_mapping_breakpoints($mappings, $fallback_image_style);

    if (isset($display['settings']['fallback_image_style']) && !empty($display['settings']['fallback_image_style'])) {
      $fallback_image_style = $display['settings']['fallback_image_style'];
    }
    if (isset($file->override) && isset($file->override['wysiwyg']) && $file->override['wysiwyg']) {
      return array(
        '#theme' => 'image_style',
        '#style_name' => $fallback_image_style,
        '#path' => $file->uri,
      );
    }
    $replace_options = array(
      'clear' => 1,
      'sanitize' => 0,
    );
    $dimensions = array(
      'width' => '',
      'height' => '',
    );
    if (isset($file->image_dimensions['width'])) {
      $dimensions['width'] = $file->image_dimensions['width'];
    }
    elseif (isset($file->metadata['width'])) {
      $dimensions['width'] = $file->metadata['width'];
    }
    if (isset($file->image_dimensions['height'])) {
      $dimensions['height'] = $file->image_dimensions['height'];
    }
    elseif (isset($file->metadata['height'])) {
      $dimensions['height'] = $file->metadata['height'];
    }

    $libraries = array(
      array('picture', 'picturefill_head'),
      array('picture', 'picturefill'),
      array('picture', 'picture.ajax'),
    );
    if (!empty($display['settings']['lazyload'])) {
      $libraries[] = array('picture', 'lazysizes');

      if (!empty($display['settings']['lazyload_aspect_ratio'])) {
        $libraries[] = array('picture', 'lazysizes_aspect_ratio');
      };

    };


    $element = array(
      '#theme' => 'picture_formatter',
      '#attached' => array(
        'library' => $libraries
      ),
      '#item' => array(
        'style_name' => $fallback_image_style,
        'path' => $file->uri,
        'uri' => $file->uri,
        'alt' => token_replace($display['settings']['alt'], array('file' => $file), $replace_options),
        'title' => token_replace($display['settings']['title'], array('file' => $file), $replace_options),
      ) + $dimensions,
      '#image_style' => $fallback_image_style,
      '#breakpoints' => $breakpoint_styles,
      '#path' => '',
      '#lazyload' => !empty($display['settings']['lazyload']),
      '#lazyload_aspect_ratio' => !empty($display['settings']['lazyload_aspect_ratio']),
    );

    return $element;
  }
}

/**
 * Settings callback for hook_file_formatter_info().
 */
function picture_file_formatter_picture_settings($form, &$form_state, $settings) {
  $picture_group_options = array();
  $picture_mappings = picture_mapping_load_all();
  if ($picture_mappings && !empty($picture_mappings)) {
    foreach ($picture_mappings as $machine_name => $picture_mapping) {
      $breakpoint_group = $picture_mapping->getBreakpointGroup();
      if ($breakpoint_group) {
        $picture_group_options[$machine_name] = $picture_mapping->label;
      }
    }
  }

  $element['picture_group'] = array(
    '#title' => t('Picture group'),
    '#type' => 'select',
    '#default_value' => $settings['picture_group'],
    '#required' => TRUE,
    '#options' => $picture_group_options,
  );

  $image_styles = image_style_options(FALSE);
  $element['fallback_image_style'] = array(
    '#title' => t('Fallback image style'),
    '#type' => 'select',
    '#default_value' => $settings['fallback_image_style'],
    '#empty_option' => t('Automatic'),
    '#options' => $image_styles + array(
      PICTURE_EMPTY_IMAGE => t('Empty image'),
    ),
  );

  $element['lazyload'] = array(
    '#title' => t('Picture lazyload'),
    '#type' => 'checkbox',
    '#description' => t('Image will be rendered when it appears in viewport, helps to optimize page load speed.'),
    '#default_value' => !empty($settings['lazyload']),
  );

  $element['lazyload_aspect_ratio'] = array(
    '#title' => t('Keep aspect ratio'),
    '#type' => 'checkbox',
    '#description' => t('Preserve the space for the image being lazyloaded to avoid layout reflows. <br /> Image ratio is defined per breakpoint, make sure all images from srcset have the same ratio. <br />Output example: !example',
      array('!example' => htmlentities('<source media="(...)" data-srcset="image_400x200.jpg x1, iamge_800x400.jpg x2, image_1200x600.jpg x3" data-aspectratio="2" />'))
    ),
    '#default_value' => !empty($settings['lazyload_aspect_ratio']),
    '#states' => array(
      'visible' => array(
        ':input[name="displays[file_picture][settings][lazyload]"]' => array('checked' => TRUE),
        ':input[name="displays[file_picture][settings][fallback_image_style]"]' => array('value' => PICTURE_EMPTY_IMAGE),
      )
    )
  );

  $element['alt'] = array(
    '#title' => t('Alt attribute'),
    '#description' => t('The text to use as value for the <em>img</em> tag <em>alt</em> attribute.'),
    '#type' => 'textfield',
    '#default_value' => $settings['alt'],
  );

  // Allow the setting of the title attribute.
  $element['title'] = array(
    '#title' => t('Title attribute'),
    '#description' => t('The text to use as value for the <em>img</em> tag <em>title</em> attribute.'),
    '#type' => 'textfield',
    '#default_value' => $settings['title'],
  );

  return $element;
}
