<?php

/**
 * @file
 * Fields formatter for the Slick and Paragraphs integration.
 */

/**
 * Formats Paragraphs data.
 */
function slick_format_paragraphs($items, array &$settings) {
  $view_mode   = $settings['view_mode'];
  $slick_id    = $settings['id'];
  $nested_name = empty($settings['nested_optionset']) ? 'default' : $settings['nested_optionset'];
  $nested_set  = empty($settings['nested_slick']) ? NULL : slick_optionset_load($nested_name);
  $entity_type = $settings['target_entity_type'] = 'paragraphs_item';

  // It is un-reasonable to make large image as colorbox, so disable it.
  $settings['lightbox_ready'] = FALSE;
  $settings['picture_ready']  = TRUE;

  $build = $dimensions = array();

  if (!empty($settings['image_style'])) {
    $image = array();
    $dimensions = slick_get_dimensions($image, $settings['image_style']);
  }

  foreach ($items as $key => $item) {
    $slide   = $thumb = array();
    $entity  = paragraphs_item_load($item['value']);
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $view    = $entity->view($view_mode);
    $id      = array_keys($view[$entity_type]);
    $id      = reset($id);
    $fields  = $view[$entity_type][$id];

    // Main background image can be core Image, or File entity, multi or single.
    $settings['delta'] = $key;
    $settings['target_entity_id'] = $id;
    if (!empty($settings['slide_image']) && $stage = $wrapper->{$settings['slide_image']}->value()) {
      $file  = isset($stage['fid']) ? $stage : (isset($stage[0]) ? $stage[0] : array());
      $media = $dimensions;

      // Image with picture, lazyLoad, and lightbox supports.
      $slide['slide'] = slick_get_image($settings, $media, $file);

      // Build the thumbnail display.
      if ($settings['nav']) {
        // Thumbnail usages: asNavFor pagers, dot, arrows, photobox thumbnails.
        // Note: $media here has the expected image URI, not video URI.
        $thumb['slide'] = slick_get_thumbnail($settings['thumbnail_style'], $media);
        if (!empty($settings['thumbnail_caption']) && $caption = $wrapper->{$settings['thumbnail_caption']}->value()) {
          $thumb['caption']['data']['#markup'] = isset($caption['safe_value']) ? $caption['safe_value'] : filter_xss($caption);
        }
        $build['thumb'][$key] = $thumb;
      }
    }

    // Main slide overlays.
    if ($settings['current_display'] == 'main') {
      // Nested slicks, or image/video/audio overlays applies to main display.
      // EMW fails to check empty for disabled fields, so use the fields.
      if (!empty($settings['slide_overlay']) && isset($fields[$settings['slide_overlay']])) {
        $slides = $wrapper->{$settings['slide_overlay']}->value();
        $renderables = $fields[$settings['slide_overlay']];
      }

      // Build the fieldable captions.
      slick_get_caption($settings, $entity_type, $entity, $slide);

      // Layout field as opposed to the builtin layout options.
      if (!empty($settings['layout'])) {
        if (strpos($settings['layout'], 'field_') !== FALSE && $slide_layout = $wrapper->{$settings['layout']}->value()) {
          $settings['layout'] = strip_tags($slide_layout);
        }
      }

      // Color can be plain text, or color_field.module.
      // @todo CSS background lazyload when Blazy landed instead.
      if (!empty($settings['color_field']) && $colors = $wrapper->{$settings['color_field']}->value()) {
        $color = is_string($colors) ? $colors : (!empty($colors['rgb']) ? $colors['rgb'] : '');
        if (!empty($color)) {
          // @see http://tympanus.net/Development/CreativeLinkEffects/
          $light = slick_color_brightness($color, 42);
          $hover = slick_color_brightness($color, 62);

          $css[] = "#{$slick_id} .slide--{$key} {color: {$color}}";
          $css[] = "#{$slick_id} .slide--{$key} .slide__title {color: {$color}}";
          $css[] = "#{$slick_id} .slide--{$key} .slide__link a::before, #{$slick_id} .slide--{$key} .slide__link a::after {background-color: {$color}}";

          if ($color != '#fff' || $color != '#ffffff') {
            $css[] = "#{$slick_id} .slide--{$key} .slide__link a {color: {$color}}";
            $css[] = "#{$slick_id} .slide--{$key} .slide__link a:hover {color: {$hover}}";
            $css[] = "#{$slick_id} .slide--{$key} .slide__caption {color: {$light}}";
          }
        }
      }
    }

    $slide['settings'] = $settings;
    $build['items'][$key] = $slide;
    unset($slide, $thumb);
  }

  unset($nested_set);
  if (isset($css)) {
    $settings['inline_css'] = $css;
    unset($css);
  }
  return $build;
}
