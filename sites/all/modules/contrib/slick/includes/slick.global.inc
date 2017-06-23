<?php
/**
 * @file
 * Global functions across Slick field formatters and Views.
 */

/**
 * Defines global field formatter and Views settings.
 */
function slick_get_global_default_settings() {
  $settings = array(
    'asnavfor_main'       => '',
    'asnavfor_thumbnail'  => '',
    'asnavfor_auto'       => FALSE,
    'aspect_ratio'        => '',
    'image_style'         => '',
    'media_switch'        => '',
    'optionset'           => 'default',
    'optionset_thumbnail' => '',
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
    'view_mode'           => '',
    'grid'                => '',
    'grid_medium'         => '',
    'grid_small'          => '',
    'visible_slides'      => '',
    'preserve_keys'       => FALSE,
    'override'            => FALSE,
    'overridables'        => array(),
    'cache'               => 0,
    'current_display'     => 'main',
  );
  return $settings;
}

/**
 * Gets the image based on the Picture mapping, or Slick image lazy.
 */
function slick_get_image($settings = array(), $media = array(), $key = 0, $media_settings = array()) {
  $image = array();

  // Must be similar for the colorbox rel gallery for image/video/audio.
  $id = isset($settings['lightbox_id']) ? $settings['lightbox_id'] : $settings['attributes']['id'];

  // Ensures disabling Picture while being used doesn't screw up.
  $is_picture = function_exists('picture_mapping_load') && !empty($settings['picture_ready']);
  if ($is_picture && !empty($settings['picture']) && !empty($settings['picture_style'])) {
    $fallback    = $settings['picture_fallback'];
    $mappings    = picture_mapping_load($settings['picture_style']);
    $breakpoints = picture_get_mapping_breakpoints($mappings, $fallback);

    $slide = array(
      '#theme'       => 'picture',
      '#style_name'  => $settings['picture_style'],
      '#breakpoints' => $breakpoints,
      '#attached'    => array(
        'library' => array(
          array('picture', 'picturefill'),
          array('picture', 'picture.ajax'),
        ),
      ),
    );

    foreach (array('uri', 'width', 'height', 'alt', 'title') as $data) {
      $slide["#$data"] = isset($media[$data]) ? $media[$data] : NULL;
    }
    $image = drupal_render($slide);
  }
  else {
    if (!empty($settings['thumbnail_style'])) {
      $media['attributes']['data-thumb'] = image_style_url($settings['thumbnail_style'], $media['uri']);
    }
    $image = array(
      '#theme'        => 'slick_image_lazy',
      '#item'         => $media,
      '#image_style'  => $settings['image_style'],
      '#lazy'         => empty($settings['lazy']) || !empty($settings['unslick']) ? '' : $settings['lazy'],
      '#options'      => array(
        'count'       => $settings['count'],
        'delta'       => $key,
        'has_pattern' => !empty($settings['has_pattern']),
        'type'        => $media['type'],
        'url'         => array(),
      ),
    );

    if (!empty($settings['media_switch'])) {
      // Provide relevant file URL if it is a lightbox.
      if (strpos($settings['media_switch'], 'box') !== FALSE && !empty($settings['lightbox_ready'])) {
        $json = array('type' => $media['type']);
        if (!empty($media['url'])) {
          $url = $media['url'];
          $json['scheme'] = $media['scheme'];
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
          $url = !empty($settings['box_style']) ? image_style_url($settings['box_style'], $media['uri']) : file_create_url($media['uri']);
        }

        $lightbox = str_replace('-switch', '', $settings['media_switch']);
        $classes  = array('slick__' . $lightbox, 'slick__litebox');
        if ($settings['media_switch'] == 'colorbox-switch') {
          if ($settings['count'] > 1) {
            $json['rel'] = $id;
          }
        }
        elseif ($settings['media_switch'] == 'photobox-switch') {
          if (!empty($media['url'])) {
            $image['#options']['url']['attributes']['rel'] = 'video';
          }
        }
        elseif ($settings['media_switch'] == 'slickbox-switch') {
          $classes = array('slick__box', 'slick__litebox');
          $json['entity_id'] = $settings['entity_id'];
          if (!empty($settings['entity_uri']) && !empty($settings['use_ajax'])) {
            $url = $settings['entity_uri'];
            $json['ajax'] = TRUE;
          }
        }

        // Video/audio has special attributes for JS interaction.
        if ($media['type'] != 'image') {
          $json['player'] = TRUE;
          $json['height'] = empty($media['media_height']) ? $media['height'] : $media['media_height'];
          $json['width']  = empty($media['media_width']) ? $media['width'] : $media['media_width'];
          $image['#options']['url']['external'] = TRUE;
        }

        $image['#url'] = $url;
        $image['#options']['url']['attributes']['class'] = $classes;
        $image['#options']['url']['attributes']['data-media'] = drupal_json_encode($json);
        $image['#options']['lightbox'] = $lightbox;
      }
      elseif (strpos($settings['media_switch'], 'content') !== FALSE && !empty($settings['entity_uri'])) {
        $image['#url'] = $settings['entity_uri'];
      }
    }
  }

  drupal_alter('slick_image_info', $image, $settings, $media, $key);

  // Build the slide with picture, lightbox or multimedia supports.
  return array(
    '#theme'    => 'slick_media',
    '#item'     => $image,
    '#settings' => $media_settings,
    '#uri'      => $media['uri'],
  );
}

/**
 * Extracts the needed image data.
 */
function slick_extract_image_data($settings, array &$media, array &$slide, $item = array()) {
  $slide += array(
    'item'     => $item,
    'slide'    => array(),
    'caption'  => array(),
    'settings' => array(
      'count'        => $settings['count'],
      'has_pattern'  => !empty($settings['has_pattern']),
      'image_style'  => $settings['image_style'],
      'layout'       => !empty($settings['slide_layout']) ? $settings['slide_layout'] : '',
      'media_switch' => !empty($settings['media_switch']) ? $settings['media_switch'] : '',
    ),
  );
  $media['bundle'] = !empty($settings['bundle']) ? $settings['bundle'] : '';
  $config = array('fid', 'height', 'width', 'alt', 'title', 'uri', 'type');
  foreach ($config as $data) {
    $media[$data] = isset($item[$data]) ? $item[$data] : NULL;
  }
}

/**
 * Returns items as a grid display.
 */
function slick_build_grids(array $build, &$settings) {
  $grids = array();
  if (!empty($settings['unslick'])) {
    $settings['current_display'] = 'main';
    $settings['current_item'] = 'grid';

    // Displays all items if unslick is enforced such as plain grid to lightbox.
    $grids[0] = array(
      '#theme' => 'slick_grid',
      '#items' => $build,
      '#delta' => 0,
      '#settings' => array(
        'count'   => 2,
        'skin'    => $settings['skin'],
        'unslick' => TRUE,
      ),
    );
  }
  else {
    // Otherwise do chunks to have a grid carousel.
    $preserve_keys = !empty($settings['preserve_keys']) ? TRUE : FALSE;
    $grid_items = array_chunk($build, $settings['visible_slides'], $preserve_keys);
    foreach ($grid_items as $delta => $grid_item) {
      $grids[] = array(
        '#theme' => 'slick_grid',
        '#items' => $grid_item,
        '#delta' => $delta,
        '#settings' => array(
          'count' => count($grid_items),
          'skin'  => $settings['skin'],
        ),
      );
    }
  }

  return $grids;
}
