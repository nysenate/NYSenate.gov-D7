<?php
/**
 * @file
 * Fields formatter for Slick and core Image field integration.
 */

/**
 * Formats core image data.
 */
function slick_format_image(&$settings, $config, $thumb_nav = FALSE) {
  $settings['picture_ready'] = $settings['lightbox_ready'] = TRUE;

  $build = array();
  foreach ($config['items'] as $key => $item) {
    $media = $slide = array();
    $item['type'] = !isset($item['type']) ? 'image' : $item['type'];
    slick_extract_image_data($settings, $media, $slide, $item);

    if (!$thumb_nav) {
      if (!empty($settings['slide_caption'])) {
        foreach ($settings['slide_caption'] as $caption) {
          $data = str_replace("_field", "", $caption);
          if (!empty($media[$data])) {
            $slide['caption'][$data]['#markup'] = filter_xss($media[$data]);
          }
        }
      }

      // Image with picture, lazyLoad, and lightbox supports.
      $slide['slide'] = slick_get_image($settings, $media, $key, $slide['settings']);
    }
    else {
      // Thumbnail usages: asNavFor pagers, dot, arrows, photobox thumbnails.
      $slide['slide'] = slick_get_thumbnail($settings['thumbnail_style'], $media);
      if (!empty($settings['thumbnail_caption'])) {
        $data = str_replace("_field", "", $settings['thumbnail_caption']);
        if (!empty($media[$data])) {
          $slide['caption']['data']['#markup'] = filter_xss($media[$data]);
        }
      }
    }
    $build[$key] = $slide;
  }
  return $build;
}
