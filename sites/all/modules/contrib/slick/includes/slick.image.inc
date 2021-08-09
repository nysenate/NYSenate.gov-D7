<?php

/**
 * @file
 * Fields formatter for Slick and core Image field integration.
 */

/**
 * Formats core image data.
 */
function slick_format_image($items, $langcode, array &$settings) {
  $settings['picture_ready'] = $settings['lightbox_ready'] = TRUE;

  $build       = $dimensions = array();
  $has_caption = !empty($settings['slide_caption']);

  // Defines image dimensions once to reduce function calls.
  if (!empty($settings['image_style'])) {
    $image = array();
    $dimensions = slick_get_dimensions($image, $settings['image_style']);
  }

  // Build the main display.
  foreach ($items as $key => $item) {
    $media = $dimensions;

    $settings['delta'] = $key;
    if ($has_caption) {
      foreach ($settings['slide_caption'] as $caption) {
        $data = str_replace('_field', '', $caption);
        if (!empty($item[$data])) {
          $slide['caption'][$data]['#markup'] = filter_xss($item[$data]);
        }
      }
    }

    // Image with picture, lazyLoad, and lightbox supports.
    $slide['slide'] = slick_get_image($settings, $media, $item);
    $slide['settings'] = $settings;

    // Build the slide.
    $build['items'][$key] = $slide;
    unset($slide);
  }

  // Build the thumbnail display.
  if (!empty($settings['nav'])) {
    $has_caption = !empty($settings['thumbnail_caption']);
    foreach ($items as $key => $item) {
      // Thumbnail usages: asNavFor pagers, dot, arrows, photobox thumbnails.
      $slide['slide'] = slick_get_thumbnail($settings['thumbnail_style'], $item);

      if ($has_caption) {
        $data = str_replace('_field', '', $settings['thumbnail_caption']);
        if (!empty($item[$data])) {
          $slide['caption']['data']['#markup'] = filter_xss($item[$data]);
        }
      }

      // Build the thumbnail slide.
      $build['thumb'][$key] = $slide;
      unset($slide);
    }
  }

  return $build;
}
