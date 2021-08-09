<?php

/**
 * @file
 * Contains optional functions called only if needed by admin pages.
 */

/**
 * Defines a list of options available for the responsive Slick.
 *
 * @param int $count
 *   The number of breakpoints.
 *
 * @return array
 *   A copy of the main options with the removal of problematic options.
 */
function slick_get_responsive_options($count = 0) {
  $options = array();
  $breakpoints = drupal_map_assoc(range(0, ($count - 1)));
  $defaults = slick_get_options();

  foreach ($breakpoints as $key => $breakpoint) {
    $options[$key] = array(
      'breakpoint' => 0,
      'unslick'    => FALSE,
      'settings'   => array(),
    );

    foreach (slick_clean_options($defaults) as $name => $value) {
      $options[$key]['settings'][$name] = $value;
    }
  }

  return $options;
}

/**
 * Removes problematic options for the responsive Slick.
 *
 * They should exist once for a given Slick, or not easy to deal with, or make
 *   no sense in the responsive context. JS takes care of their relevant copy.
 *
 * @param array $options
 *   An array of all available options, can be form elements, or basic ones.
 *
 * @return array
 *   An array of cleaned out options for the responsive displays.
 */
function slick_clean_options(array $options) {
  $excludes = drupal_map_assoc(array(
    'mobileFirst',
    'asNavFor',
    'mousewheel',
    'slide',
    'lazyLoad',
    'prevArrow',
    'nextArrow',
    'dotsClass',
    'appendDots',
    'respondTo',
    'rtl',
  ));

  drupal_alter('slick_clean_options_info', $excludes);
  return array_diff_key($options, $excludes);
}

/**
 * Returns overridable options to re-use one optionset, only accepts boolean.
 *
 * @return array
 *   An array of overridable boolean options.
 */
function slick_get_overridable_options() {
  $overridables = array(
    'arrows'    => t('Arrows'),
    'autoplay'  => t('Autoplay'),
    'dots'      => t('Dots'),
    'draggable' => t('Draggable'),
  );

  drupal_alter('slick_overridable_options_info', $overridables);
  return $overridables;
}

/**
 * Gets default layout options for the core Image, or Views.
 *
 * @return array
 *   An array of available basic layouts.
 */
function slick_layouts() {
  $layouts = &drupal_static(__FUNCTION__, NULL);

  if (!isset($layouts)) {
    $layouts = array(
      'bottom'      => t('Caption bottom'),
      'top'         => t('Caption top'),
      'right'       => t('Caption right'),
      'left'        => t('Caption left'),
      'center'      => t('Caption center'),
      'center-top'  => t('Caption center top'),
      'below'       => t('Caption below the slide'),
      'stage-right' => t('Caption left, stage right'),
      'stage-left'  => t('Caption right, stage left'),
      'split-right' => t('Caption left, stage right, split half'),
      'split-left'  => t('Caption right, stage left, split half'),
      'stage-zebra' => t('Stage zebra'),
      'split-zebra' => t('Split half zebra'),
    );
  }

  return $layouts;
}

/**
 * Load all slick optionsets as select options.
 *
 * @return array
 *   An array containing slick optionsets indexed by their names.
 */
function slick_optionset_options() {
  $optionsets = &drupal_static(__FUNCTION__, NULL);

  if (!isset($optionsets)) {
    $optionsets = array();
    $slicks = slick_optionset_load_all();
    foreach ($slicks as $key => $optionset) {
      $optionsets[$key] = check_plain($optionset->label);
    }
    asort($optionsets);
  }

  return $optionsets;
}

/**
 * Checks whether an optionset with the given name already exists.
 *
 * @param string $optionset_name
 *   The Optionset machine name.
 *
 * @return bool
 *   Returns TRUE if exists, FALSE otherwise.
 */
function slick_optionset_exists($optionset_name) {
  ctools_include('export');
  $optionset = ctools_export_crud_load('slick_optionset', $optionset_name);
  return isset($optionset->name);
}

/**
 * Fetches all optionsets from the storage.
 *
 * @param bool $reset
 *   If TRUE, the static cache of all objects will be flushed prior to
 *   loading all. This can be important on listing pages where items
 *   might have changed on the page load.
 *
 * @return array
 *   The associative array of all optionsets.
 */
function slick_optionset_load_all($reset = FALSE) {
  ctools_include('export');
  $optionsets = ctools_export_crud_load_all('slick_optionset', $reset);
  foreach ($optionsets as $optionset) {
    // Ensures the optionset is typecast after being loaded from storage.
    $breakpoints = isset($optionset->breakpoints) ? $optionset->breakpoints : NULL;
    _slick_typecast_optionset($optionset->options, $breakpoints);
  }

  return $optionsets;
}

/**
 * Saves the given option set to the database.
 *
 * Set the $new flag if this set has not been written before.
 *
 * @param object $optionset
 *   The Optionset object.
 * @param bool $new
 *   The Optionset machine name.
 *
 * @return object
 *   Returns the newly saved object, FALSE otherwise.
 */
function slick_optionset_save($optionset, $new = FALSE) {
  // If the machine name is missing or already in use, return an error.
  if (empty($optionset->name) or (FALSE != slick_optionset_exists($optionset->name) and $new)) {
    return FALSE;
  }

  // Check for an invalid list of options.
  if (isset($optionset->options) and !is_array($optionset->options)) {
    return FALSE;
  }

  if (empty($optionset->label)) {
    $optionset->label = $optionset->name;
  }

  // Merge default settings with any given settings.
  $breakpoints = 0;
  if (isset($optionset->breakpoints)) {
    $breakpoints = $optionset->breakpoints;
  }

  $defaults['general']  = array('goodies' => array());
  $defaults['settings'] = slick_get_options();
  $optionset->options   = $optionset->options + $defaults;
  _slick_typecast_optionset($optionset->options, $breakpoints);

  // Prepare the database values.
  $db_values = array(
    'name'        => $optionset->name,
    'label'       => $optionset->label,
    'breakpoints' => $breakpoints,
    'options'     => $optionset->options,
  );

  if ($new) {
    $result = drupal_write_record('slick_optionset', $db_values);
  }
  else {
    $result = drupal_write_record('slick_optionset', $db_values, 'name');
  }

  // Return the object if the values were saved successfully.
  if (($new and SAVED_NEW == $result) or (!$new and SAVED_UPDATED == $result)) {
    return $optionset;
  }

  // Otherwise, an error occured.
  return FALSE;
}

/**
 * Deletes the given option set from the database.
 *
 * @param string|object $optionset
 *   Optionset object, or string machine name.
 */
function slick_optionset_delete($optionset) {
  ctools_include('export');
  $object = is_object($optionset) ? $optionset : slick_optionset_load($optionset);

  // This only deletes from the database, which means that if an item is in
  // code, then this is actually a revert.
  ctools_export_crud_delete('slick_optionset', $object);
}

/**
 * Returns the typecast values, so that JSON object has the right values.
 *
 * @param array $options
 *   An array of Optionset options.
 * @param int $breakpoints
 *   The number of breakpoints if specified.
 */
function _slick_typecast_optionset(array &$options = array(), $breakpoints = 0) {
  if (empty($options)) {
    return;
  }

  $slick_options = slick_get_options();
  foreach ($slick_options as $name => $value) {
    if (isset($options['settings'][$name])) {
      $cast = gettype($slick_options[$name]);
      settype($options['settings'][$name], $cast);
    }
  }

  if (isset($options['responsives']['responsive']) && $breakpoints) {
    $slick_responsive_options = slick_get_responsive_options($breakpoints);
    foreach ($slick_responsive_options as $i => $items) {
      foreach ($items as $name => $item) {
        switch ($name) {
          case 'breakpoint':
            settype($options['responsives']['responsive'][$i][$name], 'int');
            break;

          case 'unslick':
            settype($options['responsives']['responsive'][$i][$name], 'bool');
            break;

          case 'settings':
            foreach ($item as $key => $setting) {
              if (isset($options['responsives']['responsive'][$i][$name][$key])) {
                $cast = gettype($item[$key]);
                settype($options['responsives']['responsive'][$i][$name][$key], $cast);
              }
            }
            break;

          default:
            break;
        }
      }
    }
  }

  drupal_alter('slick_typecast_optionset_info', $options, $breakpoints);
}

/**
 * A helper function to return view modes for a form.
 *
 * @param string $entity_type
 *   The entity type to use with entity_get_info($entity_type) or
 *   entity_get_info($field['settings']['target_type']).
 * @param bool $exclude
 *   If TRUE, then exclude some view modes, such as: 'rss', 'search_index',
 *   'search_result', 'print', 'token'.
 *
 * @return array
 *   An array of available view modes, excluding some.
 */
function slick_get_view_modes($entity_type, $exclude = TRUE) {
  $view_mode_options = &drupal_static(__FUNCTION__);

  if (!isset($view_mode_options)) {
    $view_mode_options = array('default' => t('Default'));
    $view_mode_excludes = array(
      'rss',
      'search_index',
      'search_result',
      'print',
      'token',
      'preview',
      'wysiwyg',
    );

    $entity_info = entity_get_info($entity_type);
    if (!empty($entity_info['view modes'])) {
      foreach ($entity_info['view modes'] as $view_mode => $view_mode_settings) {
        if ($exclude && in_array($view_mode, $view_mode_excludes)) {
          continue;
        }
        $view_mode_options[$view_mode] = $view_mode_settings['label'];
      }
    }
  }

  return $view_mode_options;
}

/**
 * Gets a list of fields in the Field collection item.
 */
function slick_get_fc_fields($instance, $field_types) {
  $options = array();
  $fields = field_info_fields();
  $bundle = 'field_collection_item';
  $bundle_instance = $instance['field_name'];

  foreach ($fields as $name => $field) {
    $infos = field_info_instance($bundle, $name, $bundle_instance);
    if ($field_types == '_all') {
      $options[$name] = $infos['label'];
    }
    else {
      if (in_array($bundle, array_keys($field['bundles']))
          && in_array($bundle_instance, $field['bundles'][$bundle])
          && in_array($field['type'], $field_types)) {
        $options[$name] = $infos['label'];
      }
    }
  }

  return $options;
}

/**
 * Gets a list of fields in the Media file field.
 */
function slick_get_media_fields($instance, $widget_types = NULL) {
  $options = array();
  $types = drupal_map_assoc(array('audio', 'image', 'slideshow', 'video'));

  // Expose all media sub-fields, and merge them as available options.
  foreach ($types as $media_type) {
    $fields = field_info_instances('file', $media_type);
    foreach ($fields as $key => $media_field) {
      $type = $media_field['widget']['type'];
      if ($widget_types && in_array($type, $widget_types)) {
        $options[$key] = $media_field['label'];
      }
      else {
        $options[$key] = $media_field['label'];
      }
    }
  }

  return $options;
}

/**
 * Gets a list of fields in the Paragraphs item.
 */
function slick_get_paragraphs_fields($instance, $bundles, $field_types) {
  $entity_type = 'paragraphs_item';
  $paragraphs_options = array();
  // Add panelizer support.
  if ($instance['entity_type'] == 'ctools') {
    foreach ($bundles as $bundle_type => $types) {
      foreach ($types as $type) {
        $instance = field_info_instance($bundle_type, $instance['field_name'], $type);
        $allowed_bundles = $instance['settings']['allowed_bundles'];
        $paragraphs_options += _slick_get_paragraphs_fields_options($allowed_bundles, $entity_type, $field_types);
      }
    }
  }
  else {
    $allowed_bundles = $instance['settings']['allowed_bundles'];
    $paragraphs_options = _slick_get_paragraphs_fields_options($allowed_bundles, $entity_type, $field_types);
  }

  return $paragraphs_options;
}

/**
 * Helper function to get list of supported field base on field_types.
 */
function _slick_get_paragraphs_fields_options($allowed_bundles, $entity_type, $field_types) {
  $options = array();
  foreach ($allowed_bundles as $bundle_name => $bundle) {
    if ($bundle !== -1) {
      $fields = field_info_instances($entity_type, $bundle_name);
      foreach ($fields as $name => $field) {
        $info = field_info_field($name);
        if ($field_types == '_all') {
          $options[$name] = $field['label'];
        }
        else {
          if (in_array($entity_type, array_keys($info['bundles']))
            && in_array($info['type'], $field_types)
          ) {
            $options[$name] = $field['label'];
          }
        }
      }
    }
  }

  return $options;
}

/**
 * Returns shared starting form elements across Slick field formatter and Views.
 */
function slick_get_top_elements(array &$elements, $settings, &$form_state) {
  $slick_path = drupal_get_path('module', 'slick');
  $optionsets = slick_optionset_options();
  $readme     = url($slick_path . '/README.txt');

  $elements['optionset'] = array(
    '#title'       => t('Optionset main'),
    '#type'        => 'select',
    '#options'     => $optionsets,
    '#description' => t('Manage optionsets at <a href="@link" target="_blank">Slick carousel admin page</a>.', array('@link' => url('admin/config/media/slick'))),
  );

  $elements['skin'] = array(
    '#type'        => 'select',
    '#title'       => t('Skin main'),
    '#options'     => slick_get_skins_by_group('main', TRUE),
    '#description' => t('Skins allow swappable layouts like next/prev links, split image and caption, etc. with just CSS. However a combination of skins and options may lead to unpredictable layouts, get yourself dirty. See <a href="@url" target="_blank">SKINS section at README.txt</a> for details on Skins. Leave empty to DIY, or use hook_slick_skins_info() to register ones.', array('@url' => $readme)),
  );

  $elements['optionset_thumbnail'] = array(
    '#title'       => t('Optionset thumbnail'),
    '#type'        => 'select',
    '#options'     => $optionsets,
    '#description' => t('If provided, asNavFor aka thumbnail navigation applies. Leave empty to not use thumbnail navigation.'),
  );

  $elements['skin_thumbnail'] = array(
    '#type'        => 'select',
    '#title'       => t('Skin thumbnail'),
    '#options'     => slick_get_skins_by_group('thumbnail', TRUE),
    '#description' => t('Thumbnail navigation skin. See main <a href="@url" target="_blank">README</a> for details on Skins. Leave empty to not use thumbnail navigation.', array('@url' => $readme)),
  );

  $elements['skin_arrows'] = array(
    '#type'        => 'select',
    '#title'       => t('Skin arrows'),
    '#options'     => array(),
    '#description' => t('Use hook_slick_skins_info() with group propery arrows to add your own arrows skins.'),
    '#access'      => FALSE,
  );

  if ($arrows = slick_get_skins_by_group('arrows', TRUE)) {
    $elements['skin_arrows']['#options'] = $arrows;
    $elements['skin_arrows']['#access'] = TRUE;
  }

  $elements['skin_dots'] = array(
    '#type'        => 'select',
    '#title'       => t('Skin dots'),
    '#options'     => array(),
    '#description' => t('Use hook_slick_skins_info() with group propery dots to add your own dots skins.'),
    '#access'      => FALSE,
  );

  if ($dots = slick_get_skins_by_group('dots', TRUE)) {
    $elements['skin_dots']['#options'] = $dots;
    $elements['skin_dots']['#access'] = TRUE;
  }

  $weight = -99;
  foreach (element_children($elements) as $key) {
    if (!isset($elements[$key]['#weight'])) {
      $elements[$key]['#weight'] = ++$weight;
    }
  }
}

/**
 * Returns shared fieldable form elements for Slick field formatter and Views.
 */
function slick_get_fieldable_elements(array &$elements, $settings, $definition = array()) {
  $slick_fields   = url(drupal_get_path('module', 'slick_fields') . '/README.txt');
  $layout_builtin = slick_layouts();

  $image_options      = isset($definition['images']) ? $definition['images'] : array();
  $thumb_options      = isset($definition['thumbnails']) ? $definition['thumbnails'] : array();
  $overlay_options    = isset($definition['overlays']) ? $definition['overlays'] : array();
  $layout_options     = isset($definition['layouts']) ? $definition['layouts'] : array();
  $title_options      = isset($definition['titles']) ? $definition['titles'] : array();
  $link_options       = isset($definition['links']) ? $definition['links'] : array();
  $caption_options    = isset($definition['captions']) ? $definition['captions'] : array();
  $tn_caption_options = isset($definition['thumb_captions']) ? $definition['thumb_captions'] : array();
  $class_options      = isset($definition['classes']) ? $definition['classes'] : array();
  $fieldable          = isset($definition['fieldable']) || isset($definition['overlays']);

  $elements['slide_layout'] = array(
    '#type'        => 'select',
    '#title'       => t('Slide layout'),
    '#options'     => $layout_options + $layout_builtin,
    '#prefix'      => '<h3 class="form--slick__title">' . t('Fields') . '</h3>',
    '#description' => t('Two options: <ol><li>A custom list text field, to control each slide layout. Choose "key" under its Formatter.</li><li>Builtin layouts, to apply uniformly to all slides.</li></ol>Leave empty to DIY. <a href="@url">Read more</a> about layouts.', array('@url' => $slick_fields)),
    '#access'      => isset($definition['layouts']),
  );

  if ($fieldable) {
    $elements['slide_title'] = array(
      '#type'        => 'select',
      '#title'       => t('Slide title'),
      '#options'     => $title_options,
      '#description' => t('If provided, it will be wrapped with H2 and class .slide__title.'),
      '#access'      => isset($definition['titles']),
    );
  }

  if (isset($definition['images'])) {
    $elements['slide_image'] = array(
      '#type'        => 'select',
      '#title'       => t('Main image'),
      '#options'     => $image_options,
      '#description' => t('Main image, treated as background if overlay is provided. It will be lazy-loaded if the Formatter is <strong>Image</strong> and lazyLoad is enabled. Only one image is displayed per slide, even if it is a multi-value field.'),
      '#access'      => isset($definition['images']),
    );
  }

  if (isset($definition['thumbnails'])) {
    $elements['slide_thumbnail'] = array(
      '#type'        => 'select',
      '#title'       => t('Thumbnail image'),
      '#options'     => $thumb_options,
      '#description' => t("Only needed if <em>Option set thumbnail</em> is provided. Maybe the same field as the main image, only different instance. Leave empty to not use thumbnail pager."),
      '#access'      => isset($definition['thumbnails']),
    );
  }

  $elements['thumbnail_caption'] = array(
    '#type'        => 'select',
    '#title'       => t('Thumbnail caption'),
    '#options'     => $tn_caption_options,
    '#description' => t('Thumbnail caption maybe just title/ plain text. If Thumbnail image is not provided, the thumbnail pagers will be just text like regular tabs.'),
    '#access'      => isset($definition['thumb_captions']),
  );

  if ($fieldable) {
    $elements['slide_overlay'] = array(
      '#type'        => 'select',
      '#title'       => t('Overlay media/slicks'),
      '#options'     => $overlay_options,
      '#description' => t('For audio/video, be sure the display is not image. For nested slicks, use the Slick carousel formatter for this field. Zebra layout is reasonable for overlay and captions.'),
      '#access'      => isset($definition['overlays']),
    );
  }

  if (isset($definition['links'])) {
    $elements['slide_link'] = array(
      '#type'        => 'select',
      '#title'       => t('Link'),
      '#options'     => $link_options,
      '#description' => t('Link to content: Read more, View Case Study, etc, wrapped with class .slide__link.'),
      '#access'      => isset($definition['links']),
    );
  }

  if (isset($definition['classes'])) {
    $elements['slide_classes'] = array(
      '#title'       => t('Slide class'),
      '#type'        => 'select',
      '#options'     => $class_options,
      '#description' => t('If provided, individual slide will have this class, e.g.: to have different background with transparent images and skin Split, or Slick filtering. Be sure to have a Key, Label or Plain text under Formatter without links accordingly. Supported fields: Node title, Entityreference, Taxonomy term, List, Text.'),
      '#access'      => isset($definition['classes']),
    );
  }

  $slide_captions = is_array($settings['slide_caption']) ? array_values($settings['slide_caption']) : $settings['slide_caption'];
  $elements['slide_caption'] = array(
    '#type'          => 'checkboxes',
    '#title'         => t('Caption fields'),
    '#description'   => t("Select fields for the caption, excluding those already selected above."),
    '#options'       => $caption_options,
    '#default_value' => $slide_captions,
    '#access'        => isset($definition['captions']),
  );
}

/**
 * Returns shared fieldable form elements for Slick field formatter and Views.
 */
function slick_get_media_switch_elements(array &$elements, $settings, $definition = array()) {
  $is_colorbox  = function_exists('_colorbox_doheader');
  $is_photobox  = function_exists('photobox_library');
  $is_token     = function_exists('token_theme');
  $image_styles = image_style_options(FALSE, PASS_THROUGH);
  $field_type   = isset($definition['field_type']) ? $definition['field_type'] : '';

  $elements['media_switch'] = array(
    '#title'       => t('Media switcher'),
    '#type'        => 'select',
    '#options'     => array(
      'content'       => t('Image linked to content'),
      'iframe-switch' => t('Image to iframe switcher'),
    ),
    '#description' => t('Dependent on the enabled supported modules.<ol><li>Link to content: for aggregated small slicks.</li><li>Media file iframe: audio/video is hidden below image until toggled, otherwise iframe is always displayed, and draggable fails. Aspect ratio applies.</li><li>Colorbox.</li><li>Photobox. Be sure to select "Thumbnail style" for the overlay thumbnails.</li></ol>'),
    '#weight'      => 60,
    '#prefix'      => '<h3 class="form--slick__title">' . t('Misc') . '</h3>',
  );

  if ($field_type && in_array($field_type, array('field_collection_item', 'file'))) {
    $elements['iframe_lazy'] = array(
      '#type'        => 'checkbox',
      '#title'       => t('Lazy iframe'),
      '#description' => t('Check to make the video/audio iframes truly lazyloaded, and speed up loading time. Depends on JS enabled at client side.'),
      '#weight'      => 61,
      '#states' => array(
        'visible' => array(
          array('select[name*="[media_switch]"]' => array('value' => 'iframe-switch')),
        ),
      ),
    );
  }

  // http://en.wikipedia.org/wiki/List_of_common_resolutions
  $ratio = array('1:1', '3:2', '4:3', '8:5', '16:9', 'fluid');
  $elements['aspect_ratio'] = array(
    '#type'        => 'select',
    '#title'       => t('Aspect ratio'),
    '#options'     => drupal_map_assoc($ratio),
    '#description' => t('Aspect ratio to get consistently responsive images and iframes within responsive layout, required if using media file to switch between iframe and overlay image, otherwise you have to do it properly. This also fixes layout reflow and excessive height issues with lazyload ondemand. <a href="@dimensions" target="_blank">Image styles and video dimensions</a> must <a href="@follow" target="_blank">follow the ratio</a>, otherwise your images will be unexpectedly distorted. <a href="@link" target="_blank">Learn more</a>, or leave empty if you care not for aspect ratio, or prefer to DIY, etc. Choose fluid if unsure.', array(
      '@dimensions' => '//size43.com/jqueryVideoTool.html',
      '@follow'     => '//en.wikipedia.org/wiki/Aspect_ratio_%28image%29',
      '@link'       => '//www.smashingmagazine.com/2014/02/27/making-embedded-content-work-in-responsive-design/',
    )),
    '#weight'       => 62,
    '#states'       => array(
      'visible' => array(
        ':input[name*="[picture]"]' => array('checked' => FALSE),
      ),
    ),
  );

  // Optional colorbox integration.
  if ($is_colorbox || $is_photobox || isset($definition['lightbox'])) {
    $lightbox_enabled = array(
      'visible' => array(
        array('select[name*="[media_switch]"]' => array('value' => 'colorbox-switch')),
        array('select[name*="[media_switch]"]' => array('value' => 'photobox-switch')),
      ),
    );

    $lightbox_custom = array(
      'visible' => array(
        array('select[name*="[media_switch]"]' => array(array('value' => 'colorbox'), array('value' => 'photobox'))),
        array('select[name$="[box_caption]"]' => array('value' => 'custom')),
      ),
    );

    // Re-use the same image style for both boxes.
    $elements['colorbox_style'] = array(
      '#title'        => t('Lightbox image style'),
      '#type'         => 'select',
      '#empty_option' => t('None (original)'),
      '#options'      => $image_styles,
      '#weight'       => 63,
      '#states'       => $lightbox_enabled,
    );

    if ($is_colorbox) {
      $elements['media_switch']['#options']['colorbox-switch'] = t('Image to colorbox');
    }

    if ($is_photobox) {
      $elements['media_switch']['#options']['photobox-switch'] = t('Image to photobox');
    }

    $box_captions = array(
      'auto'         => t('Automatic'),
      'alt'          => t('Alt text'),
      'title'        => t('Title text'),
      'alt_title'    => t('Alt and Title'),
      'title_alt'    => t('Title and Alt'),
      'entity_title' => t('Content title'),
      'custom'       => t('Custom'),
    );

    $elements['box_caption'] = array(
      '#type'        => 'select',
      '#title'       => t('Lightbox caption'),
      '#options'     => $box_captions,
      '#access'      => isset($definition['box_captions']),
      '#weight'      => 63,
      '#states'      => $lightbox_enabled,
      '#description' => t('Automatic will search for Alt text first, then Title text.'),
    );

    $elements['box_caption_custom'] = array(
      '#title'       => t('Lightbox custom caption'),
      '#type'        => 'textfield',
      '#access'      => isset($definition['box_captions']),
      '#weight'      => 63,
      '#states'      => $lightbox_custom,
      '#description' => t('Multi-value rich text field will be mapped to each image by its delta.'),
      '#attributes'  => array('class' => array('js-expandable')),
    );

    if ($is_token) {
      $token_tree = array(
        '#theme'       => 'token_tree_link',
        '#text'        => t('Tokens'),
        '#token_types' => isset($definition['entity_type']) ? array('user', $definition['entity_type']) : array(),
      );
      $elements['box_caption_custom']['#field_suffix'] = drupal_render($token_tree);
    }
    else {
      $elements['box_caption_custom']['#description'] .= ' ' . t('Install Token module to browse available tokens.');
    }
  }
}

/**
 * Returns shared ending form elements across Slick field formatter and Views.
 */
function slick_get_elements(array &$elements, $settings, &$form_state) {
  $elements['mousewheel'] = array(
    '#type'        => 'checkbox',
    '#title'       => t('Mousewheel'),
    '#description' => t('Be sure to download the <a href="@url" target="_blank">mousewheel</a> library, and it is available at <em>sites/.../libraries/mousewheel/jquery.mousewheel.min.js</em>.', array('@url' => '//github.com/brandonaaron/jquery-mousewheel')),
    '#weight'      => 96,
  );

  $a = array(300, 600, 900, 1800, 2700, 3600, 10800, 21600, 32400, 43200, 86400);
  $period = drupal_map_assoc($a, 'format_interval');
  $elements['cache'] = array(
    '#type'        => 'select',
    '#title'       => t('Cache'),
    '#options'     => $period + array('persistent' => t('Persistent')),
    '#weight'      => 97,
    '#description' => t('Ditch all slick logic to cached bare HTML. <ol><li><strong>Persistent</strong>: cached contents will persist (be displayed) till the next cron runs.</li><li><strong>Any number</strong>: expired by the selected expiration time, and fresh contents are fetched till the next cache rebuilt.</li></ol>A working cron job is required to clear stale cache. At any rate, cached contents will be refreshed regardless of the expiration time after the cron hits.<br /><strong>Warning!</strong> Be sure no useless/ sensitive data such as Edit links as they are rendered as is regardless permissions. No permissions are changed, just ugly. Note: Slick is already faster, lighter and less memory than <a href="@similar" target="_blank">similar</a> <a href="@url" target="_blank">solutions</a> for anonymous users with just Drupal cache. This is more useful for authenticated traffic, best with Authcache. Only enable it when all is done, otherwise cached options will be displayed while changing them. Leave empty to disable caching, or if traffics are mostly anonymous.', array('@similar' => 'https://www.drupal.org/node/2313461#comment-10817842', '@url' => 'https://www.drupal.org/node/2463305#comment-10850288')),
  );

  // Re-uses one optionset for various displays.
  $elements['override'] = array(
    '#title'       => t('Override main optionset'),
    '#type'        => 'checkbox',
    '#description' => t('If checked, the following options will override the main optionset. Useful to re-use one optionset for several different displays.'),
    '#weight'      => 98,
  );

  $overridable_options = slick_get_overridable_options();
  $overridable_values = is_array($settings['overridables']) ? array_values($settings['overridables']) : $settings['overridables'];
  $elements['overridables'] = array(
    '#type'          => 'checkboxes',
    '#title'         => t('Overridable options'),
    '#description'   => t("Override the main optionset to re-use one. Anything dictated here will override the current main optionset. Unchecked means FALSE"),
    '#options'       => $overridable_options,
    '#default_value' => $overridable_values,
    '#weight'      => 99,
    '#states' => array(
      'visible' => array(
        ':input[name$="[override]"]' => array('checked' => TRUE),
      ),
    ),
  );

  drupal_alter('slick_elements_info', $elements, $settings, $form_state);
}

/**
 * Returns reusable grid elements across Slick field formatter and Views.
 */
function slick_get_grid_elements(array &$elements, $settings, &$form_state) {
  $grid_options = drupal_map_assoc(range(1, 12));
  $elements['grid'] = array(
    '#type'        => 'select',
    '#title'       => t('Grid large'),
    '#options'     => $grid_options,
    '#description' => t('The amount of block grid columns for large monitors 64.063em - 90em. <br /><strong>Requires</strong>:<ol><li>Visible slides,</li><li>Skin Grid for starter,</li><li>A reasonable amount of contents,</li><li>Optionset with Rows and slidesPerRow = 1.</li></ol>This is module feature using the Foundation block grid, older than core Rows, and offers more flexibility. Leave empty to DIY, or to not build grids.'),
    '#prefix'      => '<h3 class="form--slick__title">' . t('Group individual slide as block grid?<small>An older alternative to core <strong>Rows</strong> option. Only works if the total items &gt; <strong>Visible slides</strong>. <br />block grid != slidesToShow option, yet both can work in tandem.<br />block grid = Rows option, yet the first is module feature, the later core.</small>') . '</h3>',
  );

  $elements['grid_medium'] = array(
    '#type'        => 'select',
    '#title'       => t('Grid medium'),
    '#options'     => $grid_options,
    '#description' => t('The amount of block grid columns for medium devices 40.063em - 64em.'),
  );

  $elements['grid_small'] = array(
    '#type'        => 'select',
    '#title'       => t('Grid small'),
    '#options'     => $grid_options,
    '#description' => t('The amount of block grid columns for small devices 0 - 40em.'),
  );

  $elements['visible_slides'] = array(
    '#type'        => 'select',
    '#title'       => t('Visible slides'),
    '#options'     => drupal_map_assoc(range(1, 32)),
    '#description' => t('How many items per slide displayed at a time. Required if Grid provided. Grid will not work if Views rows count &lt; <strong>Visible slides</strong>.'),
  );

  $elements['preserve_keys'] = array(
    '#title'       => t('Preserve keys'),
    '#type'        => 'checkbox',
    '#description' => t('If checked, keys will be preserved. Default is FALSE which will reindex the grid chunk numerically.'),
  );

  drupal_alter('slick_grid_elements_info', $elements, $settings, $form_state);
}

/**
 * Returns reusable logic, styling and assets across Slick fields and Views.
 */
function slick_get_admin_assets(array &$elements, $settings = array()) {
  $excludes = array('container', 'fieldset', 'item', 'hidden');
  $admin_css = variable_get('slick_admin_css', TRUE);
  foreach (element_children($elements) as $key) {
    if (isset($elements[$key]['#type']) && !in_array($elements[$key]['#type'], $excludes)) {
      if (!isset($elements[$key]['#default_value']) && isset($settings[$key])) {
        $elements[$key]['#default_value'] = $settings[$key];
      }
      if (!isset($elements[$key]['#attributes']) && isset($elements[$key]['#description'])) {
        $elements[$key]['#attributes'] = array('class' => array('is-tooltip'));
      }
      if ($admin_css) {
        if ($elements[$key]['#type'] == 'checkbox' && $elements[$key]['#type'] != 'checkboxes') {
          $elements[$key]['#field_suffix'] = '';
          $elements[$key]['#title_display'] = 'before';
        }
        elseif ($elements[$key]['#type'] == 'checkboxes' && !empty($elements[$key]['#options'])) {
          foreach ($elements[$key]['#options'] as $i => $option) {
            $elements[$key][$i]['#field_suffix'] = '';
            $elements[$key][$i]['#title_display'] = 'before';
          }
        }
      }
      if ($elements[$key]['#type'] == 'select' && $key != 'optionset') {
        if (!isset($elements[$key]['#empty_option']) && !isset($elements[$key]['#required'])) {
          $elements[$key]['#empty_option'] = t('- None -');
        }
      }
    }
  }

  if ($admin_css) {
    if (module_exists('slick_ui')) {
      $elements['#attached']['library'][] = array('slick_ui', 'slick.ui');
    }
    else {
      $slick_path = drupal_get_path('module', 'slick');
      $elements['#attached']['css'] = array(
        $slick_path . '/css/admin/slick.admin--ui.css' => array('group' => CSS_THEME + 1),
        $slick_path . '/css/admin/slick.admin--ui--field.css' => array('group' => CSS_THEME + 1),
      );

      $elements['#attached']['js'][] = $slick_path . '/js/slick.admin.ui.min.js';
    }
  }

  drupal_alter('slick_admin_assets_info', $elements, $settings);
}

/**
 * Returns reusable summaries across Slick field formatters.
 */
function slick_get_admin_summary($field, $instance, $view_mode, $module) {
  $display  = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $summary  = $form = $form_state = array();
  $function = $module . '_field_formatter_settings_form';
  $elements = $function($field, $instance, $view_mode, $form, $form_state);

  foreach ($settings as $key => $setting) {
    $title = isset($elements[$key]['#title']) ? $elements[$key]['#title'] : '';
    if (is_array($setting) || empty($title)) {
      continue;
    }

    if (is_numeric($setting) || is_bool($setting)) {
      $setting = empty($setting) ? t('No') : t('Yes');
    }
    elseif (empty($setting)) {
      continue;
    }
    if (isset($settings[$key])) {
      $summary[] = t('@title: <strong>@setting</strong>', array(
        '@title' => $title,
        '@setting' => $setting,
      ));
    }
  }
  return $summary;
}
