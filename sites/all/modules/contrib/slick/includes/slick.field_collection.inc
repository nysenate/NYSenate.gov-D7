<?php

/**
 * @file
 * Fields formatter for the Slick and Field collection integration.
 */

/**
 * Formats Field collection data.
 */
function slick_format_field_collection($items, $langcode, array &$settings) {
  $view_mode   = $settings['view_mode'];
  $slick_id    = $settings['id'];
  $nested_name = empty($settings['nested_optionset']) ? 'default' : $settings['nested_optionset'];
  $nested_set  = empty($settings['nested_slick']) ? NULL : slick_optionset_load($nested_name);
  $entity_type = $settings['target_entity_type'] = 'field_collection_item';

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
    $entity  = field_collection_field_get_entity($item);
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
        $options = array(
          'id'          => $id,
          'key'         => $key,
          'nested_name' => $nested_name,
          'nested_set'  => $nested_set,
          'view_mode'   => $view_mode,
          'fields'      => $fields,
          'langcode'    => $langcode,
        );

        if (!in_array($renderables['#formatter'], array('image', 'file_rendered')) && !isset($slides[0]->sid)) {
          // Just display un-managed overlays with unknown formatters.
          $elements = $renderables;
        }
        else {
          // Otherwise do the hard work.
          $elements = _slick_build_fc_overlay($settings, $wrapper, $options);
        }
        $slide['caption']['overlay'] = $elements;
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

/**
 * Build the managed overlays: image, video, audio or nested slicks.
 */
function _slick_build_fc_overlay(&$settings, $wrapper, $options = array()) {
  $elements     = array();
  $key          = $options['key'];
  $items        = $wrapper->{$settings['slide_overlay']}->value();
  $renderables  = $options['fields'][$settings['slide_overlay']];
  $entity_id    = $settings['entity_id'];
  $entity_type  = $renderables['#entity_type'];
  $bundle       = $renderables['#bundle'];
  $field_name   = $renderables['#field_name'];
  $nested_style = empty($settings['nested_style']) ? $settings['image_style'] : $settings['nested_style'];
  $css_id       = slick_html_id("slick-nested-{$entity_type}-{$entity_id}-{$bundle}-{$field_name}");

  $settings['picture_ready'] = FALSE;

  $overlays = array();

  $overset = array(
    'current_display' => 'overlay',
    'image_style'     => $nested_style,
  );

  $overset = array_merge($settings, $overset);
  $overset_global = $overset;

  $dimensions = array();
  if (!empty($nested_style)) {
    $image = array();
    $dimensions = slick_get_dimensions($image, $nested_style);
  }

  switch ($renderables['#field_type']) {
    case 'image':
    case 'file':
      foreach ($items as $i => $item) {
        // Prevents edge case EntityMalformedException: Missing bundle property.
        if (!isset($item['uri'])) {
          continue;
        }

        $media = $dimensions;

        $overset['delta'] = $i;
        if ($renderables['#field_type'] == 'file') {
          $file = (object) $item;

          // Needed settings: type scheme image_style uri view_mode.
          // Extracts media data for: embed_url, box_height, box_width, uri.
          slick_extract_media_data($overset, $media, $file);
        }

        $overlays[$i]['item'] = $item;
        $overlays[$i]['media'] = $media;
        $overlays[$i]['settings'] = $overset;
      }
      break;

    case 'atom_reference':
      foreach ($items as $i => $item) {
        $sid             = $item->sid;
        $atom            = scald_atom_load($sid);
        $base_id         = $item->base_id;
        $langcode        = isset($item->language) ? $item->language : $options['langcode'];
        $thumbnail       = isset($item->scald_thumbnail[$langcode][0]) ? $item->scald_thumbnail[$langcode][0] : array();
        $media           = $dimensions;
        $media['scheme'] = $item->provider;

        $providers = array(
          'scald_youtube',
          'scald_vimeo',
          'scald_dailymotion',
          'video',
        );

        $overset['delta'] = $i;
        if (in_array($item->provider, $providers)) {
          $media['media_id'] = $base_id;
          if (strpos($item->provider, 'scald_') !== FALSE) {
            $media['scheme'] = substr($item->provider, -6);
          }
        }

        $media['embed_url'] = '';
        switch ($item->provider) {
          case 'scald_youtube':
            $media['embed_url'] = '//www.youtube.com/embed/' . $base_id;
            break;

          case 'scald_vimeo':
            $media['embed_url'] = '//player.vimeo.com/video/' . $base_id;
            break;

          case 'scald_dailymotion':
            $media['embed_url'] = '//www.dailymotion.com/embed/video/' . $base_id;
            break;

          case 'video':
            $media['embed_url'] = $atom->file_source;
            break;

          default:
            break;
        }

        $media['uri']   = $atom->file_source;
        $media['type']  = $item->type == 'slick' ? 'image' : $item->type;
        $overset['sid'] = $sid;

        $overlays[$i]['item'] = $thumbnail;
        $overlays[$i]['media'] = $media;
        $overlays[$i]['settings'] = $overset;
      }
      break;

    default:
      break;
  }

  $slides = $overlays;

  // Build the overlays: single static image/audio/video, or nested slicks.
  // Managed overlays with known formatters are nested slicks, or static.
  if ($slides) {
    $nested_settings = array(
      'count'          => count($slides),
      'id'             => $css_id,
      'lightbox_ready' => strpos($settings['media_switch'], 'box') !== FALSE,
      'optionset'      => $options['nested_name'],
      'picture'        => FALSE,
      'picture_ready'  => FALSE,
      'attributes'     => array('class' => array('slick--nested')),
    );

    $nested_settings = array_merge($overset_global, $nested_settings);
    $nested_settings_global = $nested_settings;

    // Process individual slick overlay.
    $element = $js = array();
    foreach ($slides as $delta => $item) {
      $slide = array();
      $media = $item['media'];

      $item_settings = array_merge($item['settings'], $nested_settings);
      $item_settings['delta'] = $delta;

      if (empty($settings['nested_slick'])) {
        $delta = 0;
      }

      // Image with picture, lazyLoad, and lightbox supports.
      $slide['slide'] = slick_get_image($item_settings, $media, $item['item']);
      $slide['settings'] = $item_settings;

      $element[$delta] = $slide;
      unset($slide);
    }

    // Build the nested slicks.
    if (!empty($settings['nested_slick'])) {
      $attach['attach_media'] = $settings['media_switch'] == 'iframe-switch';
      $elements = slick_build($element, $js, $nested_settings_global, $attach, $css_id, $options['nested_set']);
    }
    else {
      // Otherwise cares for a single overlay item to not break small layout.
      $elements = $element[0];
    }
  }
  return $elements;
}
