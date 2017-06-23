<?php
/**
 * @file
 * Fields formatter for the Slick and Media integration.
 */

/**
 * Formats image/media file data.
 */
function slick_format_media(&$settings, $config, $thumb_nav = FALSE) {
  $view_mode = $settings['view_mode'] ? $settings['view_mode'] : 'full';
  $settings['lightbox_ready'] = $settings['picture_ready'] = TRUE;

  $build = array();
  foreach ($config['items'] as $key => $item) {
    // Prevents edge case error with broken data_export_import.
    if (!isset($item['uri'])) {
      continue;
    }
    $file  = (object) $item;
    $uri   = $file->uri;
    $slide = array();
    $media = array(
      'scheme'    => file_uri_scheme($uri),
      'media_uri' => $uri,
    );

    // Build settings for both theme_slick_item() and theme_slick_media().
    slick_extract_image_data($settings, $media, $slide, $item);
    $slide['settings'] += array(
      'ratio'       => !empty($settings['aspect_ratio']) ? $settings['aspect_ratio'] : FALSE,
      'type'        => $file->type,
      'view_mode'   => $view_mode,
      'iframe_lazy' => !empty($settings['iframe_lazy']),
    );

    // Needed settings: type scheme image_style uri view_mode.
    $media['url'] = slick_get_media_url($slide['settings'], $media, $file);

    // Get audio/video thumbnail uri as opposed to the actual video uri.
    if ($media_image_uri = slick_get_media_thumbnail($slide['settings'], $media)) {
      $media['uri'] = $media_image_uri;
    }

    if (!$thumb_nav) {
      slick_get_caption($settings, 'file', $file, $view_mode, $slide);

      // Layout field as opposed from builtin layout above if so configured.
      if (!empty($settings['slide_layout']) && strpos($settings['slide_layout'], 'field_') !== FALSE) {
        $layout = field_get_items('file', $file, $settings['slide_layout']);
        $slide['settings']['layout'] = check_plain($layout[0]['value']);
      }

      // Slide classes, if so configured.
      if (!empty($settings['slide_classes']) && $classes = field_get_items('file', $file, $settings['slide_classes'])) {
        $slide['settings']['slide_classes'] = strip_tags($classes[0]['value']);
      }

      // Image with picture, lazyLoad, and lightbox supports.
      $slide['slide'] = slick_get_image($settings, $media, $key, $slide['settings']);

      // Plain text video URL for plain iframes.
      if (!empty($settings['slide_overlay']) && $overlay = field_get_items('file', $file, $settings['slide_overlay'])) {
        $url = strip_tags($overlay[0]['value']);
        if ($media_id = slick_get_media_id($url)) {
          $slide['caption']['overlay'] = slick_get_media_overlay($url, $media_id);
        }
      }
    }
    else {
      // Thumbnail usages: asNavFor pagers, dot, arrows, photobox thumbnails.
      $slide['slide'] = slick_get_thumbnail($settings['thumbnail_style'], $media);
      if (!empty($settings['thumbnail_caption']) && $caption = field_get_items('file', $file, $settings['thumbnail_caption'])) {
        $slide['caption']['data']['#markup'] = filter_xss($caption[0]['value']);
      }
    }
    $build[$key] = $slide;
  }
  return $build;
}
