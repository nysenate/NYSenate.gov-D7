<?php
/**
 * @file
 * Global functions across Slick field formatters.
 */

/**
 * Defines default field formatter settings to avoid notices.
 */
function slick_get_fields_default_settings() {
  module_load_include('inc', 'slick', 'includes/slick.global');
  $settings = array(
    'color_field'       => '',
    'colorbox_style'    => '',
    'markup'            => FALSE,
    'mousewheel'        => FALSE,
    'nested_slick'      => FALSE,
    'nested_optionset'  => '',
    'nested_style'      => '',
    'picture'           => FALSE,
    'picture_style'     => '',
    'picture_fallback'  => '',
    'thumbnail_style'   => '',
    'thumbnail_hover'   => FALSE,
    'type'              => '',
    'current_view_mode' => '',
    'iframe_lazy'       => FALSE,
    'lightbox_ready'    => FALSE,
    'picture_ready'     => FALSE,
    'use_ajax'          => FALSE,
  ) + slick_get_global_default_settings();

  drupal_alter('slick_fields_default_settings_info', $settings);
  return $settings;
}

/**
 * Gets the thumbnail image.
 */
function slick_get_thumbnail($thumbnail_style = '', $media = array()) {
  $thumbnail = array();
  if (!empty($thumbnail_style)) {
    $thumbnail = array(
      '#theme'      => 'image_style',
      '#style_name' => $thumbnail_style,
      '#path'       => $media['uri'],
    );
    foreach (array('alt', 'height', 'title', 'width') as $data) {
      $thumbnail["#$data"] = isset($media[$data]) ? $media[$data] : NULL;
    }
  }
  return $thumbnail;
}

/**
 * Checks whether a skin expecting inline CSS background, not images.
 */
function slick_get_inline_css_skins($skin = NULL) {
  $inline_css = &drupal_static(__FUNCTION__, NULL);
  if (!isset($inline_css)) {
    $skins = slick_skins();
    $inline_css = empty($skin) ? FALSE : isset($skins[$skin]['inline css']) && $skins[$skin]['inline css'];
  }
  return $inline_css;
}

/**
 * Builds the inline CSS output for skins with explicit 'inline css' key.
 */
function slick_get_inline_css(array &$settings, array &$items) {
  $css = array();
  if (slick_get_inline_css_skins($settings['skin'])) {
    $id = $settings['attributes']['id'];
    foreach ($items as $key => &$item) {
      $slick = $settings['count'] > 1 ? $id . " .slide--{$key}" : $id;
      if (isset($item['slide']['#uri']) && $uri = $item['slide']['#uri']) {
        $image_url     = !empty($settings['image_style']) ? image_style_url($settings['image_style'], $uri) : file_create_url($uri);
        $css[]         = "#{$slick} {background-image: url('{$image_url}')}";
        $item['slide'] = array();
      }
    }
  }

  // Or individual dynamic slide colors as offered by FC.
  if (!empty($settings['inline_css'])) {
    $css = array_merge($css, $settings['inline_css']);
    unset($settings['inline_css']);
  }

  if ($css) {
    $css = implode("\n", $css);
    drupal_alter('slick_inline_css_info', $css, $items, $settings);

    $css = array(
      'data'  => $css,
      'type'  => 'inline',
      'group' => CSS_THEME + 1,
      'slick' => 'fields',
    );
  }
  return $css;
}
