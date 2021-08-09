<?php

/**
 * @file
 * Global functions across Slick field formatters and Views.
 */

/**
 * Defines global field formatter and Views settings.
 */
function slick_get_global_default_settings() {
  return array(
    'aspect_ratio'        => '',
    'background'          => FALSE,
    'cache'               => 0,
    'current_display'     => 'main',
    'current_view_mode'   => '',
    'image_style'         => '',
    'media_switch'        => '',
    'mousewheel'          => FALSE,
    'optionset'           => 'default',
    'optionset_thumbnail' => '',
    'override'            => FALSE,
    'overridables'        => array(),
    'skin'                => '',
    'skin_thumbnail'      => '',
    'skin_arrows'         => '',
    'skin_dots'           => '',
    'slide_caption'       => array(),
    'slide_classes'       => '',
    'slide_image'         => '',
    'slide_layout'        => '',
    'slide_overlay'       => array(),
    'slide_link'          => '',
    'slide_title'         => '',
    'thumbnail_caption'   => '',
    'thumbnail_effect'    => '',
    'view_mode'           => '',
    'grid'                => '',
    'grid_medium'         => '',
    'grid_small'          => '',
    'visible_slides'      => '',
    'preserve_keys'       => FALSE,
  );
}

/**
 * Returns the image/video/audio either using Picture mapping, or lazyload.
 *
 * @param array $settings
 *   The module settings to check for the supported features.
 * @param array $media
 *   An array of cherry-picked media information which can be core image, file
 *   image/video/audio, or atom.
 * @param array $item
 *   An array of the actual image item.
 *
 * @return array
 *   The renderable array formatted for the slick_image().
 */
function slick_get_image(array $settings = array(), array &$media = array(), array $item = array()) {
  // The $media can be core image, file image/video/audio, or atom reference.
  // Different fields have different signatures, hence simplify em all.
  $media['type'] = empty($media['type']) ? 'image' : $media['type'];
  foreach (array('alt', 'fid', 'title', 'uri', 'height', 'width') as $data) {
    $media[$data] = isset($media[$data]) ? $media[$data] : (isset($item[$data]) ? $item[$data] : NULL);
  }

  // Build the slide with picture, lightbox or multimedia supports.
  $image = array(
    '#theme'       => 'slick_image',
    '#image_style' => $settings['image_style'],
    '#item'        => $media,
    '#settings'    => $settings,
  );

  // Ensures disabling Picture while being used doesn't screw up.
  $item_attributes = array();
  $picture = !empty($settings['picture']) && !empty($settings['picture_ready']);
  if ($picture) {
    $picture_style = empty($settings['picture_style']) ? 'large' : $settings['picture_style'];
    $fallback      = $settings['picture_fallback'];
    $mappings      = picture_mapping_load($picture_style);
    $breakpoints   = picture_get_mapping_breakpoints($mappings, $fallback);

    $item_attributes['breakpoints'] = $breakpoints;
    $item_attributes['style_name']  = $fallback;
  }
  else {
    $item_attributes['height'] = $media['height'];
    $item_attributes['width']  = $media['width'];
  }

  $image['#item_attributes'] = $item_attributes;

  // Now that picture is inside theme_slick_image(), we can manipulate it.
  if (!empty($settings['media_switch']) && $settings['media_switch'] != 'iframe-switch') {
    drupal_alter('slick_image_info', $image, $settings, $media);
    slick_get_media_switch($image, $item, $settings);
  }

  unset($item, $settings);
  return $image;
}

/**
 * Returns the media switch: colorbox/photobox, content, excluding iframe.
 */
function slick_get_media_switch(&$image = array(), $file = array(), $settings = array()) {
  $item   = $image['#item'];
  $switch = str_replace('-switch', '', $settings['media_switch']);

  // Provide relevant file URL if it is a lightbox.
  if (!empty($settings['lightbox']) && !empty($settings['lightbox_ready'])) {
    $json = array('type' => $item['type']);
    if (!empty($item['embed_url'])) {
      $url = $item['embed_url'];
      $json['scheme'] = $item['scheme'];
      // Force autoplay for media URL on lightboxes, saving another click.
      if ($json['scheme'] == 'soundcloud') {
        if (strpos($url, 'auto_play') === FALSE || strpos($url, 'auto_play=false') !== FALSE) {
          $url = strpos($url, '?') === FALSE ? $url . '?auto_play=true' : $url . '&amp;auto_play=true';
        }
      }
      elseif (strpos($url, 'autoplay') === FALSE || strpos($url, 'autoplay=0') !== FALSE) {
        $url = strpos($url, '?') === FALSE ? $url . '?autoplay=1' : $url . '&amp;autoplay=1';
      }
    }
    else {
      $url = !empty($settings['box_style']) ? image_style_url($settings['box_style'], $item['uri']) : file_create_url($item['uri']);
    }

    $classes = array('slick__' . $switch, 'litebox');
    if ($switch == 'colorbox' && $settings['count'] > 1) {
      $json['rel'] = $settings['id'];
    }
    elseif ($switch == 'photobox' && !empty($item['embed_url'])) {
      $image['#url_attributes']['rel'] = 'video';
    }
    elseif ($switch == 'slickbox') {
      $classes = array('slick__box', 'litebox');
      $json['entity_id'] = $settings['entity_id'];
      if (!empty($settings['entity_uri']) && !empty($settings['use_ajax'])) {
        $url = $settings['entity_uri'];
        $json['ajax'] = TRUE;
      }
    }

    // Video/audio has special attributes for JS interaction.
    if ($item['type'] != 'image') {
      $json['player'] = TRUE;
      $json['height'] = empty($settings['box_height']) ? $item['height'] : $settings['box_height'];
      $json['width']  = empty($settings['box_width']) ? $item['width'] : $settings['box_width'];
    }

    $image['#url'] = $url;
    $image['#url_attributes']['class'] = $classes;
    $image['#url_attributes']['data-media'] = drupal_json_encode($json);

    if (!empty($settings['box_caption'])) {
      $image['#captions']['lightbox'] = slick_build_captions($item, $file, $settings);
    }
  }
  elseif ($switch == 'content' && !empty($settings['entity_uri'])) {
    $image['#url'] = $settings['entity_uri'];
  }
}

/**
 * Build lightbox captions.
 */
function slick_build_captions($item, $file = array(), $settings = array()) {
  $title   = empty($item['title']) ? '' : $item['title'];
  $alt     = empty($item['alt']) ? '' : $item['alt'];
  $delta   = $settings['delta'];
  $caption = '';
  $entity  = $entity_type = NULL;

  // @todo FC.
  if (!empty($settings['entity'])) {
    $entity_type = $settings['entity_type'];
    $entity = $settings['entity'];
  }

  switch ($settings['box_caption']) {
    case 'auto':
      $caption = $alt ? $alt : $title;
      break;

    case 'alt':
      $caption = $alt;
      break;

    case 'title':
      $caption = $title;
      break;

    case 'alt_title':
    case 'title_alt':
      $alt     = $alt ? '<p>' . $alt . '</p>' : '';
      $title   = $title ? '<h2>' . $title . '</h2>' : '';
      $caption = $settings['box_caption'] == 'alt_title' ? $alt . $title : $title . $alt;
      break;

    case 'entity_title':
      $caption = '';
      if ($entity) {
        $caption = entity_label($entity_type, $entity);
      }
      break;

    case 'custom':
      $caption = '';
      if ($entity) {
        $options = array('clear' => TRUE);
        $caption = token_replace($settings['box_caption_custom'], array($entity_type => $entity, 'file' => (object) $file), $options);

        // Checks for multi-value text fields, and maps its delta to image.
        if (strpos($caption, ", <p>") !== FALSE) {
          $caption = str_replace(", <p>", '| <p>', $caption);
          $captions = explode("|", $caption);
          $caption = isset($captions[$delta]) ? $captions[$delta] : '';
        }
      }
      break;

    default:
      $caption = '';
  }

  $allowed_tags = array('a', 'em', 'strong', 'h2', 'p', 'span', 'ul', 'li');
  return empty($caption) ? '' : filter_xss($caption, $allowed_tags);
}

/**
 * Defines image style dimensions once for all images as it costs a bit.
 */
function slick_get_dimensions($media = array(), $image_style = 'large') {
  $dimensions = array(
    'height' => isset($media['height']) ? $media['height'] : NULL,
    'width'  => isset($media['width']) ? $media['width'] : NULL,
  );

  image_style_transform_dimensions($image_style, $dimensions);
  $dimensions['_dimensions'] = TRUE;
  return $dimensions;
}

/**
 * Returns items as a grid display.
 */
function slick_build_grids(array $build, &$settings) {
  $grids = array();

  // Display all items if unslick is enforced for plain grid to lightbox.
  if (!empty($settings['unslick'])) {
    $settings['current_display'] = 'main';
    $settings['current_item']    = 'grid';
    $settings['count']           = 2;

    $slide['slide'] = array(
      '#theme'    => 'slick_grid',
      '#items'    => $build,
      '#delta'    => 0,
      '#settings' => $settings,
    );
    $slide['settings'] = $settings;
    $grids[0] = $slide;
  }
  else {
    // Otherwise do chunks to have a grid carousel.
    $preserve_keys     = !empty($settings['preserve_keys']);
    $grid_items        = array_chunk($build, $settings['visible_slides'], $preserve_keys);
    $settings['count'] = count($grid_items);

    foreach ($grid_items as $delta => $grid_item) {
      $slide = array();
      $slide['slide'] = array(
        '#theme'    => 'slick_grid',
        '#items'    => $grid_item,
        '#delta'    => $delta,
        '#settings' => $settings,
      );
      $slide['settings'] = $settings;
      $grids[] = $slide;
      unset($slide);
    }
  }

  return $grids;
}

/**
 * Returns slick instances from the cache with simplified renderable.
 */
function slick_render_cache($settings = array()) {
  $cached = FALSE;
  $cid = $settings['id'] . ':' . $settings['cid'];
  if ($cache = cache_get($cid)) {
    $cached = $settings['cache'] == 'persistent' ? TRUE : REQUEST_TIME < $cache->expire;
  }

  if ($cached) {
    $slick[0] = $cache->data;
    if ($settings['nav'] && $thumb_cache = cache_get($cid . ':thumbnail')) {
      $slick[1] = $thumb_cache->data;
    }
    return $slick;
  }

  return $cached;
}

/**
 * Gets the thumbnail image.
 */
function slick_get_thumbnail($thumbnail_style = '', $item = array()) {
  $thumbnail = array();
  if (!empty($thumbnail_style)) {
    $thumbnail = array(
      '#theme'      => 'image_style',
      '#style_name' => $thumbnail_style,
      '#path'       => $item['uri'],
    );
    foreach (array('alt', 'height', 'title', 'width') as $data) {
      $thumbnail["#$data"] = isset($item[$data]) ? $item[$data] : NULL;
    }
  }
  return $thumbnail;
}

/**
 * Builds the inline CSS output for skins if provided.
 */
function slick_get_inline_css(array &$settings, array &$items) {
  $css = $settings['inline_css'];
  $css = implode("\n", $css);

  drupal_alter('slick_inline_css_info', $css, $items, $settings);

  return array(
    'data'  => $css,
    'type'  => 'inline',
    'group' => CSS_THEME + 1,
    'slick' => 'fields',
  );
}

/**
 * Extracts the needed image data.
 *
 * @deprecated, merged into slick_get_image() to reduce function calls.
 */
function slick_extract_image_data($settings, &$media = array(), &$slide = array(), $item = array()) {
  if (!empty($settings['image_style']) && !isset($media['_dimensions'])) {
    slick_get_dimensions($media, $settings['image_style']);
  }

  foreach (array('alt', 'title', 'uri', 'type', 'height', 'width') as $data) {
    $media[$data] = isset($media[$data]) ? $media[$data] : (isset($item[$data]) ? $item[$data] : NULL);
  }
}
