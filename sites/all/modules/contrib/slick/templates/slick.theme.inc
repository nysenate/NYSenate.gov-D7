<?php
/**
 * @file
 * Hooks and preprocess functions for the Slick module.
 *
 * The entire functions here, save for theme_slick_wrapper(), are dormant when
 * the render cache option is enabled.
 */

/**
 * Returns HTML for a slick_wrapper when asNavFor, or cache, in use.
 *
 * @param array $variables
 *   An associative array containing:
 *   - items: An array of slick instances: main and thumbnail slicks.
 *   - settings: HTML related settings.
 *
 * @ingroup themeable
 */
function theme_slick_wrapper(array $variables) {
  $build    = '';
  $element  = $variables['element'];
  $items    = $element['#items'];
  $settings = isset($element['#settings']) ? $element['#settings'] : array();
  $skin     = isset($settings['skin']) ? $settings['skin'] : '';

  foreach ($items as $item) {
    $build .= drupal_render($item);
  }

  $attributes['class'] = array('slick-wrapper', 'slick-wrapper--asnavfor');
  if ($skin && $skin != 'asnavfor') {
    $attributes['class'][] = drupal_clean_css_identifier('slick-wrapper--' . $skin);
  }

  // Clean up markups for the cached version if it is a single slick.
  return count($items) > 1 ? '<div' . drupal_attributes($attributes) . '>' . $build . '</div>' : $build;
}

/**
 * Prepares variables for slick templates.
 *
 * Default template: slick.tpl.php.
 *
 * @variables array:
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #items, #settings, #options, #optionset, #attached.
 *     - #settings is set via sub-modules and serves various purposes, and not
 *       related to JS settings, mostly slide layouts or attaching assets.
 *     - #options is set programmatically, or hand-crafted, and only accepts
 *       direct key|value pairs related to JS settings, or an optionset name.
 *     - #optionset, if supplied, ensures the optionset loaded once, and cached.
 */
function template_preprocess_slick(&$variables) {
  $element   = $variables['element'];
  $count     = count($element['#items']);
  $defaults  = slick_get_element_default_settings();
  $settings  = isset($element['#settings']) ? array_merge($defaults, $element['#settings']) : $defaults;
  $customs   = isset($element['#options']) ? $element['#options'] : array();
  $name      = isset($customs['optionset']) ? check_plain($customs['optionset']) : $settings['optionset'];
  $optionset = isset($element['#optionset']) && is_object($element['#optionset']) ? $element['#optionset'] : slick_optionset_load($name);
  $general   = $optionset->options['general'];
  $goodies   = $general['goodies'];
  $js        = $customs ? array_merge($optionset->options['settings'], $customs) : $optionset->options['settings'];
  $skin      = $settings['skin'] ? $settings['skin'] : $optionset->skin;

  // Allows manipulating markups with an enforced unslick.
  $settings['count']   = !empty($settings['count']) ? $settings['count'] : $count;
  $settings['unslick'] = !empty($settings['unslick']) || $settings['count'] == 1 ? TRUE : FALSE;

  if ($settings['current_display'] == 'thumbnail') {
    $skin = !empty($settings['skin_thumbnail']) ? $settings['skin_thumbnail'] : $optionset->skin;
  }

  // Prepare attributes.
  $attributes          = &$variables['attributes_array'];
  $attributes['class'] = $variables['classes_array'];
  $content_attributes  = &$variables['content_attributes_array'];

  if (isset($settings['attributes']) && is_array($settings['attributes'])) {
    $attributes = drupal_array_merge_deep($attributes, $settings['attributes']);
  }

  if (!isset($attributes['id'])) {
    $slick_id         = &drupal_static('slick_id', 0);
    $id               = 'slick-' . ++$slick_id;
    $attributes['id'] = $settings['current_display'] == 'thumbnail' ? $id . '-thumbnail' : $id;
  }

  // Consistent styling is always needed even for an unslick.
  if ($skin) {
    foreach (array('boxed', 'split') as $key) {
      if ($skin !== $key && strpos($skin, $key) !== FALSE) {
        $attributes['class'][] = 'slick--skin--' . $key;
      }
    }
    $attributes['class'][] = drupal_clean_css_identifier('slick--skin--' . $skin);
    $settings['skin'] = $skin;
  }

  $attributes['class'][] = drupal_clean_css_identifier('slick--optionset--' . $name);
  if (!empty($general['template_class'])) {
    $attributes['class'][] = $general['template_class'];
  }

  // Some settings are only reasonable for the main display, not thumbnail.
  if ($settings['current_display'] == 'main') {
    $settings['has_pattern'] = $settings['has_pattern'] ? TRUE : !empty($goodies['pattern']);

    if (!empty($settings['media_switch']) && strpos($settings['media_switch'], 'box') !== FALSE) {
      $swicther = str_replace('-switch', '', $settings['media_switch']);
      $attributes['class'][] = 'slick--' . $swicther;
    }
  }

  // Prevents broken slick when only one item given, or an enforced unslick.
  if (!empty($settings['unslick'])) {
    $attributes['class'][] = 'unslick';
  }
  else {
    if (!empty($goodies['random'])) {
      $attributes['class'][] = 'slick--random';
    }

    if (isset($settings['content_attributes']) && is_array($settings['content_attributes'])) {
      $content_attributes = drupal_array_merge_deep($content_attributes, $settings['content_attributes']);
    }
    if (!isset($content_attributes['id'])) {
      $content_attributes['id'] = $attributes['id'] . '-slider';
    }
    $content_attributes['class'][] = 'slick__slider';

    // The slider must have the attribute "dir" set to "rtl", if so configured.
    if (!empty($js['rtl'])) {
      $content_attributes['dir'] = 'rtl';
    }

    // Arrows are enforced to allow responsive options hide/show them.
    $tags = array('a', 'em', 'strong', 'button', 'p', 'div', 'i', 'span');
    $settings['prev_arrow']      = filter_xss($js['prevArrow'], $tags);
    $settings['next_arrow']      = filter_xss($js['nextArrow'], $tags);
    $arrow_attributes            = &$variables['arrow_attributes_array'];
    $arrow_attributes['class'][] = 'slick__arrow';
    if (!empty($settings['skin_arrows'])) {
      $skin_arrows = drupal_clean_css_identifier($settings['skin_arrows']);
      $arrow_attributes['class'][] = 'slick__arrow--' . $skin_arrows;
    }

    // Adds helper class if thumbnail on dots hover provided.
    if (!empty($settings['thumbnail_style']) && !empty($settings['thumbnail_hover'])) {
      $js['dotsClass'] .= ' slick-dots--thumbnail';
    }

    // Adds dots skin modifier class if provided.
    if (!empty($settings['skin_dots'])) {
      $js['dotsClass'] .= ' ' . drupal_clean_css_identifier('slick-dots--' . $settings['skin_dots']);
    }

    // All these s***s are to re-use one optionset when all these disabled.
    // focusOnSelect won't work with empty slide value, so add proper selector.
    $js['slide'] = empty($js['slide']) && $js['focusOnSelect'] ? '.slick__slide' : '';

    // Only if asNavFor, enforce clickable thumbnail, otherwise no joy.
    $settings['asnavfor_target'] = empty($settings['asnavfor_target']) ? $js['asNavFor'] : $settings['asnavfor_target'];
    if (!empty($settings['optionset_thumbnail']) && !empty($settings['asnavfor_target'])) {
      if ($settings['current_display'] == 'thumbnail') {
        $js['slide'] = '.slick__slide';
        $js['focusOnSelect'] = TRUE;
      }

      $attributes['class'][] = 'slick--display--' . $settings['current_display'];
      $js['asNavFor'] = trim($settings['asnavfor_target']);
    }
    // Prevents non-empty, but not-used, asNavFor from breaking the slide.
    else {
      $js['asNavFor'] = '';
    }

    if ($settings['current_display'] == 'main') {
      if (!empty($goodies['arrow-down']) && $general['arrow_down_target']) {
        $attributes['class'][]     = 'slick--has-arrow-down';
        $arrow_down['class']       = array('slick-down', 'jump-scroll');
        $arrow_down['data-target'] = $general['arrow_down_target'];
        $arrow_down['data-offset'] = $general['arrow_down_offset'];
        $variables['arrow_down']   = '<button' . drupal_attributes($arrow_down) . '></button>';
      }
    }

    // Provides s*** classes. Set 'slick_classes' to FALSE to disable them.
    if ($settings['slick_classes']) {
      $attributes['class'][] = $js['slidesToShow'] > 1 ? 'slick--carousel' : 'slick--slider';
      $attributes['class'][] = $js['centerMode'] ? 'slick--center' : 'slick--float';

      // Provide context to fix excessive height with lazyLoad ondemand.
      if ($js['lazyLoad'] == 'ondemand') {
        $attributes['class'][] = 'slick--ondemand';
      }
    }

    // Add the configuration as JSON object into the slick container.
    $js_data = _slick_remove_default_optionset_options($optionset, $js, $settings);
    if (!isset($content_attributes['data-slick']) && $js_data) {
      $content_attributes['data-slick'] = drupal_json_encode($js_data);
    }
  }

  $variables['settings'] = $settings;

  // Process individual item.
  $variables['items'] = array();
  foreach ($element['#items'] as $delta => $item) {
    $settings['current_item'] = $settings['current_display'];
    if (isset($item['settings'])) {
      $settings = array_merge($settings, $item['settings']);
    }
    $variables['items'][$delta] = array(
      '#theme'    => 'slick_item',
      '#item'     => isset($item['slide']) ? $item['slide'] : $item,
      '#delta'    => $delta,
      '#settings' => $settings,
      '#caption'  => isset($item['caption']) ? $item['caption'] : array(),
    );
  }

  $variables['classes_array'] = $variables['attributes_array']['class'];
}

/**
 * Implements hook_process_slick().
 */
function template_process_slick(&$variables) {
  $variables['attributes'] = empty($variables['attributes_array']) ? '' : drupal_attributes($variables['attributes_array']);
  $variables['arrow_attributes'] = empty($variables['arrow_attributes_array']) ? '' : drupal_attributes($variables['arrow_attributes_array']);
}

/**
 * Implements hook_preprocess_slick_item().
 */
function template_preprocess_slick_item(&$variables) {
  $element  = $variables['element'];
  $item     = $variables['item'] = $element['#item'];
  $settings = $element['#settings'];
  $captions = $element['#caption'];

  // Prepare variables, and remove non-BEM default class.
  $variables['classes_array']  = array_diff($variables['classes_array'], array('slick-item'));
  $variables['wrapper_prefix'] = $variables['wrapper_suffix'] = array();
  $variables['content_prefix'] = $variables['content_suffix'] = array();
  $variables['item_prefix']    = $variables['item_suffix'] = array();

  // Configure attributes for containing elements.
  $attributes          = $content_attributes = array();
  $attributes['class'] = $variables['classes_array'];
  $variables['tag']    = $variables['content_tag'] = 'div';

  if ($settings['current_item'] == 'grid') {
    $one                      = !empty($settings['unslick']) ? 'slick__grid' : 'slide__grid';
    $two                      = 'grid';
    $three                    = 'grid--' . $element['#delta'];
    $variables['tag']         = 'li';
    $variables['content_tag'] = 'div';
    $content_attributes['class'][] = 'grid__content';
  }
  else {
    $one              = 'slick__slide';
    $two              = 'slide';
    $three            = 'slide--' . $element['#delta'];
    $variables['tag'] = 'div';
    $content_attributes['class'][] = 'slide__content';
    // Thumbnail may not have settings as it just prints the image.
    $settings = isset($item['#settings']) && is_array($item['#settings']) ? array_merge($settings, $item['#settings']) : $settings;
  }

  // 1, 2, 3, 1, 2, 3, drink.
  $attributes['class'] += array($one, $two, $three);

  // Only add relevant Foundation block-grid classes if the skin is Grid.
  if (!empty($settings['grid']) && $settings['current_item'] == 'main') {
    $settings['grid_large'] = $settings['grid'];
    if (!empty($settings['skin']) && $settings['skin'] == 'grid') {
      $grids = array('small', 'medium', 'large');
      $content_attributes['class'][] = 'block-grid';
      foreach ($grids as $grid) {
        if ($column = $settings['grid_' . $grid]) {
          $content_attributes['class'][] = $grid . '-block-grid-' . $column;
        }
      }
    }
    $attributes['class'][] = 'slide--grid';
    $variables['content_tag'] = 'ul';
  }

  // Media module has type: image, audio, video, as opposed to field_type.
  if (!empty($settings['type']) && $settings['type'] != 'image') {
    $attributes['class'][] = drupal_clean_css_identifier('slide--' . $settings['type']);
  }

  // All slide types -- main, thumbnail, grid, overlay -- may have captions.
  $variables['caption'] = $variables['editor'] = array();
  $variables['slide_pattern'] = '';

  // Title, caption and overlay, or nested media.
  if ($settings['current_item'] == 'thumbnail') {
    $variables['caption'] = empty($captions['data']) ? array() : $captions['data'];
  }
  else {
    // Each slide can have unique, or uniform layout.
    if (!empty($settings['layout'])) {
      $attributes['class'][] = drupal_clean_css_identifier('slide--caption--' . $settings['layout']);
    }

    // Captions contain: editor, overlay, title, alt, data, link.
    if (!empty($captions['editor'])) {
      if (empty($settings['cache'])) {
        $variables['editor'] = $captions['editor'];
      }
      unset($captions['editor']);
    }
    $variables['caption'] = $captions;

    // Split image from captions if we do have captions, and main image.
    if (($variables['caption'] && $item) || (!empty($settings['skin']) && strpos($settings['skin'], '3d') !== FALSE)) {
      $variables['item_prefix'] = '<div class="slide__media">';
      $variables['item_suffix'] = '</div>';
    }

    // If fullwidth or fullscreen, add wrappers to hold caption and overlay.
    if (!empty($settings['skin']) && strpos($settings['skin'], 'full') !== FALSE) {
      $variables['title_prefix'] = '<div class="slide__constrained">';
      $variables['title_suffix'] = '</div>';
    }

    // Exclude lightbox switcher as it has its own pattern DIV within A tag.
    if (!empty($settings['has_pattern']) && strpos($settings['media_switch'], 'box') === FALSE) {
      $variables['slide_pattern'] = '<div class="slide__pattern"></div>';
    }
  }

  // Custom individual slide classes.
  if (!empty($settings['slide_classes'])) {
    $attributes['class'][] = trim($settings['slide_classes']);
  }

  // Do not add divities for a single slick (unslick) to have clean markups.
  if ($settings['count'] > 1) {
    $variables['wrapper_prefix'] = '<' . $variables['tag'] . drupal_attributes($attributes) . '>';
    $variables['wrapper_suffix'] = '</' . $variables['tag'] . '>';
    $variables['content_prefix'] = '<' . $variables['content_tag'] . drupal_attributes($content_attributes) . '>';
    $variables['content_suffix'] = '</' . $variables['content_tag'] . '>';
  }

  // Removes useless .slick__slide DIV if it is an enforced unslick grid.
  if ($settings['current_item'] == 'main' && $variables['content_tag'] == 'ul' && !empty($settings['unslick'])) {
    $variables['wrapper_prefix'] = $variables['wrapper_suffix'] = array();
    $variables['content_prefix'] = str_replace("slide__content", "slide", $variables['content_prefix']);
  }

  $variables['settings'] = $settings;
}

/**
 * Implements hook_preprocess_slick_grid().
 */
function template_preprocess_slick_grid(&$variables) {
  $element  = $variables['element'];
  $settings = $element['#settings'];
  $variables['wrapper_prefix'] = $variables['wrapper_suffix'] = array();

  // Implementors should be responsible to pass proper grid chunks.
  $variables['items'] = array();
  foreach ($element['#items'] as $delta => $item) {
    $settings['current_item'] = 'grid';
    if (isset($item['settings'])) {
      $settings = array_merge($settings, $item['settings']);
    }

    $variables['items'][$delta] = array(
      '#theme'    => 'slick_item',
      '#item'     => isset($item['slide']) ? $item['slide'] : '',
      '#delta'    => $delta,
      '#settings' => $settings,
      '#caption'  => isset($item['caption']) ? $item['caption'] : array(),
    );
  }
}

/**
 * Implements hook_preprocess_slick_media().
 */
function template_preprocess_slick_media(&$variables) {
  $element    = $variables['element'];
  $settings   = $element['#settings'];
  $item       = $variables['item'] = $element['#item'];
  $media      = isset($item['#item']) ? $item['#item'] : $settings;
  $type       = isset($settings['type']) ? $settings['type'] : 'image';
  $switcher   = $settings['media_switch'] = isset($settings['media_switch']) ? $settings['media_switch'] : FALSE;
  $multimedia = in_array($type, array('video', 'audio'));

  // Prepare variables.
  // $variables['classes_array'] = array_diff($variables['classes_array'], array('slick-media'));
  $variables['item_prefix'] = $variables['item_suffix'] = array();
  $variables['is_lightbox'] = $switcher && strpos($switcher, 'box') !== FALSE;
  $settings['is_media']     = isset($settings['is_media']) && $multimedia ? $settings['is_media'] : FALSE;
  $variables['alternative_content'] = '';

  // Configure attributes for containing elements.
  $attributes            = &$variables['attributes_array'];
  $content_attributes    = &$variables['content_attributes_array'];
  $attributes['class']   = $variables['classes_array'];
  $attributes['class'][] = 'media';
  $attributes['class'][] = 'media--' . $type;

  if (isset($settings['content_attributes']) && is_array($settings['content_attributes'])) {
    $content_attributes = drupal_array_merge_deep($content_attributes, $settings['content_attributes']);
  }

  // All media types: image/audio/video files.
  if (!empty($switcher)) {
    $attributes['class'][] = 'media--switch';
    // Lightbox switcher applies to all media types, including core image field.
    if ($variables['is_lightbox'] || $switcher == 'content') {
      $switched = str_replace('-switch', '', $switcher);
      $attributes['class'][] = 'media--switch--' . $switched;
    }
  }

  // Pure CSS responsive iframes/images based on aspect ratio to get
  // consistent display for a mix of image/audio/video at one slick.
  if (!empty($settings['ratio'])) {
    $attributes['class'][] = 'media--ratio--on';
    $attributes['class'][] = drupal_clean_css_identifier('media--ratio--' . $settings['ratio']);
  }

  // The media audio/video files.
  if ($settings['is_media'] && !empty($media['url'])) {
    $content_attributes['class'][] = 'media__iframe';
    $content_attributes['src'] = $media['url'];

    // If iframe switch disabled, fallback to just iframe, and remove overlay.
    if (empty($switcher)) {
      $variables['item'] = array();
    }
    else {
      // If no colorbox/photobox, it is an image to iframe switcher.
      if (!$variables['is_lightbox']) {
        $attributes['class'][] = 'media--player';
        $attributes['class'][] = 'media--switch--player';
        $attributes['class'][] = drupal_clean_css_identifier('media--' . $media['scheme'] . '-player');
        if (!empty($settings['iframe_lazy'])) {
          $content_attributes['src'] = 'about:blank';
        }
      }

      // Gets consistent with colorbox to share JS manipulation.
      $json = array(
        'type'   => $type,
        'player' => TRUE,
        'scheme' => $media['scheme'],
      );
      $content_attributes['data-media'] = drupal_json_encode($json);
      $content_attributes['data-lazy']  = $media['url'];
    }
    $variables['alternative_content'] = empty($media['title']) ? '' : filter_xss($media['title']);
  }

  $variables['settings']      = $settings;
  $variables['classes_array'] = $variables['attributes_array']['class'];
}

/**
 * Implements hook_process_slick_media().
 */
function template_process_slick_media(&$variables) {
  $variables['attributes'] = empty($variables['attributes_array']) ? '' : drupal_attributes($variables['attributes_array']);
}

/**
 * Overrides theme_image with Slick lazy loading.
 *
 * @param array $variables
 *   An associative array containing:
 *   - item: Associative array of image data, which may include "uri", "alt",
 *     "width", "height", "title" and "attributes".
 *   - lazy: A flag whether to use the lazyload, or not.
 *   - image_style: The name of the style to alter the original image.
 *   - url: A string containing the link 'url'.
 *   - attributes: Associative array of attributes to be placed in the img tag.
 *   - options: An array of options, including the 'url' options.
 *
 * @ingroup themeable
 */
function theme_slick_image_lazy(array $variables) {
  $build      = '';
  $image      = &$variables['item'];
  $options    = $variables['options'];
  $attributes = &$variables['attributes'];

  if (isset($image['attributes']) && is_array($image['attributes'])) {
    $attributes = drupal_array_merge_deep($attributes, $image['attributes']);
  }

  $attributes['class'][] = 'slick__image';
  $image['path'] = $image['uri'];
  $image_url     = file_create_url($image['path']);

  if ($variables['image_style']) {
    // If dimensions have not been defined before.
    if (!isset($image['dimensions'])) {
      $dimensions = array(
        'width'  => $image['width'],
        'height' => $image['height'],
      );

      image_style_transform_dimensions($variables['image_style'], $dimensions);

      $image['width']  = $dimensions['width'];
      $image['height'] = $dimensions['height'];
    }
    $image_url     = image_style_url($variables['image_style'], $image['uri']);
    $image['path'] = $image_url;
  }

  $image_rendered = theme('image', $image);

  // Be sure to avoid images with breakpoints, taken over by picture.module.
  if (!isset($variables['breakpoints']) && $options['count'] > 1 && $variables['lazy']) {
    foreach (array('width', 'height', 'alt', 'title') as $key) {
      if (isset($image[$key])) {
        // If the property has already been defined in the attributes,
        // do not override, including NULL.
        if (array_key_exists($key, $attributes)) {
          continue;
        }
        $attributes[$key] = $image[$key];
      }
    }

    $attributes['class'][] = 'lazy';
    $attributes['src'] = 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7';

    // Use 'advanced' to DIY with: blazy, responsimg, lazysizes, etc.
    if ($variables['lazy'] != 'advanced') {
      $attributes['data-lazy'] = $image_url;
    }

    $build .= '<img' . drupal_attributes($attributes) . ' />';
    if ($options['delta'] == 0) {
      $build .= theme('html_tag', array(
        'element' => array(
          '#tag' => 'noscript',
          '#value' => $image_rendered,
        ),
      ));
    }
  }
  else {
    $build = $image_rendered;
  }

  // The link url and link options are both optional.
  if (isset($variables['url'])) {
    if (isset($options['lightbox']) && $switcher = $options['lightbox']) {
      $build .= empty($options['icon']) ? '<i class="media-icon media-icon--lightbox media-icon--' . $switcher . '"></i>' : $options['icon'];
      if (!empty($options['has_pattern'])) {
        $build .= '<div class="slide__pattern"></div>';
      }
    }

    $url = $variables['url'];
    $link_options = isset($options['url']) ? (array) $options['url'] : array();
    $link_options['html'] = TRUE;
    $build = l($build, $url, $link_options);
  }
  return $build;
}

/**
 * Returns HTML or layout related settings to avoid extra checks and notices.
 */
function slick_get_element_default_settings() {
  $settings = array(
    'current_display' => 'main',
    'has_pattern'     => FALSE,
    'media_switch'    => '',
    'optionset'       => 'default',
    'skin'            => '',
    'slick_classes'   => TRUE,
  );
  drupal_alter('slick_element_default_settings_info', $settings);
  return $settings;
}

/**
 * Strips out options similar to default values from the optionset options.
 *
 * @param object $optionset
 *   The Optionset object.
 * @param array $settings
 *   An array of handed-over JS options manipulated at theme_slick().
 * @param array $context
 *   The context to check for before doing alteration, such as module settings.
 *
 * @return array
 *   An array of reduced duplicated options since JS will fallback to defaults.
 */
function _slick_remove_default_optionset_options($optionset, $settings = array(), $context = array()) {
  $config   = array();
  $options  = $optionset->options;
  $defaults = slick_get_options();

  // Remove wasted dependent options if disabled, empty or not.
  slick_remove_wasted_dependent_options($settings);
  $config = array_diff_assoc($settings, $defaults);

  if (empty($config['lazyLoad'])) {
    unset($config['lazyLoad']);
  }
  unset($config['prevArrow'], $config['nextArrow']);

  // Clean up responsive options if similar to the defaults.
  $responses = array();
  if (isset($options['responsives']) && isset($options['responsives']['responsive'])) {
    $responsives = $options['responsives']['responsive'];
    foreach ($responsives as $key => $responsive) {
      if (empty($responsives[$key]['breakpoint'])) {
        unset($responsives[$key]);
      }
      if (isset($responsives[$key])) {
        $responses[$key] = $responsive;
      }
    }
    if ($responses) {
      $cleaned = array();
      foreach ($responses as $i => $response) {
        $cleaned[$i]['breakpoint'] = $responses[$i]['breakpoint'];
        if (isset($responses[$i]['unslick']) && $responses[$i]['unslick']) {
          $cleaned[$i]['settings'] = 'unslick';
          unset($responses[$i]['unslick']);
        }
        else {
          slick_remove_wasted_dependent_options($responses[$i]['settings']);
          $cleaned[$i]['settings'] = array_diff_assoc($responses[$i]['settings'], $defaults);
        }
      }
      $config['responsive'] = $cleaned;
    }
  }
  drupal_alter('slick_remove_options_info', $config, $settings, $options, $context);
  return $config;
}

/**
 * Removes wasted dependent options, even if not empty.
 *
 * @param array $config
 *   An array of Optionset options.
 */
function slick_remove_wasted_dependent_options(array &$config) {
  $options = array(
    'autoplay'   => array('pauseOnHover', 'pauseOnDotsHover', 'autoplaySpeed'),
    'centerMode' => array('centerPadding'),
    'dots'       => array('dotsClass', 'appendDots'),
    'rows'       => array('slidesPerRow'),
    'swipe'      => array('swipeToSlide'),
    'vertical'   => array('verticalSwiping'),
    'useCSS'     => array('cssEase', 'cssEaseBezier', 'cssEaseOverride'),
  );

  foreach ($options as $key => $option) {
    if (isset($config[$key]) && empty($config[$key])) {
      foreach ($option as $dependent) {
        unset($config[$dependent]);
      }
    }
  }

  if ($config['useCSS'] && isset($config['cssEaseBezier']) && $config['cssEaseBezier']) {
    $config['cssEase'] = $config['cssEaseBezier'];
    unset($config['cssEaseOverride'], $config['cssEaseBezier']);
  }
}
