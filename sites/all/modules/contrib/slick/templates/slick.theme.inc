<?php

/**
 * @file
 * Hooks and preprocess functions for the Slick module.
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
  $element  = $variables['element'];
  $items    = $element['#items'];
  $settings = isset($element['#settings']) ? $element['#settings'] : array();
  $skin     = isset($settings['skin']) ? $settings['skin'] : '';
  $nav      = isset($settings['nav']) ? $settings['nav'] : isset($items[1]);

  $build = drupal_render($items[0]);
  if ($nav) {
    $build .= drupal_render($items[1]);

    $attributes['class'] = array('slick-wrapper', 'slick-wrapper--asnavfor');
    if ($skin && $skin != 'asnavfor') {
      $attributes['class'][] = str_replace('_', '-', 'slick-wrapper--' . $skin);
    }
    return '<div' . drupal_attributes($attributes) . '>' . $build . '</div>';
  }

  return $build;
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
  $defaults = array(
    'current_display' => 'main',
    'optionset'       => 'default',
    'skin_arrows'     => '',
  );

  $element   = $variables['element'];
  $settings  = isset($element['#settings']) ? array_merge($defaults, $element['#settings']) : $defaults;
  $customs   = isset($element['#options']) ? $element['#options'] : array();
  $name      = isset($customs['optionset']) ? strip_tags($customs['optionset']) : $settings['optionset'];
  $optionset = isset($element['#optionset']) && is_object($element['#optionset']) ? $element['#optionset'] : slick_optionset_load($name);
  $general   = $optionset->options['general'];
  $goodies   = $general['goodies'];
  $js        = $customs ? array_merge($optionset->options['settings'], $customs) : $optionset->options['settings'];
  $skin      = empty($settings['skin']) ? $optionset->skin : $settings['skin'];
  $display   = $settings['current_display'];
  $id        = empty($settings['id']) ? slick_html_id('slick') : $settings['id'];

  // Allows manipulating markups with an enforced unslick.
  $settings['count']        = empty($settings['count']) ? count($element['#items']) : $settings['count'];
  $settings['skin_arrows']  = empty($settings['skin_arrows']) ? '' : ' slick__arrow--' . str_replace('_', '-', $settings['skin_arrows']);
  $settings['unslick']      = !empty($settings['unslick']) || $settings['count'] == 1;
  $settings['slidesToShow'] = $js['slidesToShow'];

  // Prepare attributes, supports Omega 4 alike, or regular.
  $attributes          = &$variables['attributes_array'];
  $attributes['class'] = isset($attributes['class']) ? $attributes['class'] : array('slick');
  $attributes['id']    = $id;
  $content_attributes  = &$variables['content_attributes_array'];

  if ($display == 'thumbnail') {
    $attributes['id'] = $id . '-thumbnail';
    $skin = empty($settings['skin_thumbnail']) ? $optionset->skin : $settings['skin_thumbnail'];
  }
  elseif ($display == 'main') {
    // Some settings are only reasonable for the main display, not thumbnail.
    $settings['has_pattern'] = !empty($settings['has_pattern']) || !empty($goodies['pattern']);

    if (!empty($settings['media_switch']) && strpos($settings['media_switch'], 'box') !== FALSE) {
      $swicther = str_replace('-switch', '', $settings['media_switch']);
      $attributes['class'][] = 'slick--' . $swicther;
    }
  }

  // Sniffs for Views to allow block__no_wrapper, views__no_wrapper, etc.
  if (!empty($settings['view_name']) && !empty($settings['current_view_mode'])) {
    $attributes['class'][] = str_replace('_', '-', 'slick--view--' . $settings['view_name']);
    $attributes['class'][] = str_replace('_', '-', 'slick--view--' . $settings['view_name'] . '--' . $settings['current_view_mode']);
  }

  // @todo: Remove temp fix for when total <= slidesToShow.
  // @see https://github.com/kenwheeler/slick/issues/262
  if ($settings['count'] <= $settings['slidesToShow']) {
    $attributes['class'][] = 'slick--less';
  }

  // Consistent styling is always needed even for an unslick.
  if ($skin) {
    foreach (array('boxed', 'split') as $key) {
      if ($skin !== $key && strpos($skin, $key) !== FALSE) {
        $attributes['class'][] = 'slick--skin--' . $key;
      }
    }
    $attributes['class'][] = str_replace('_', '-', 'slick--skin--' . $skin);
    $settings['skin'] = $skin;
  }

  $attributes['class'][] = str_replace('_', '-', 'slick--optionset--' . $name);
  if (!empty($general['template_class'])) {
    $attributes['class'][] = $general['template_class'];
  }

  // Prevents broken slick when only one item given, or an enforced unslick.
  if (!empty($settings['unslick'])) {
    $attributes['class'][] = 'unslick';
  }
  else {
    $js['randomize'] = !empty($goodies['random']);

    $content_attributes['class'][] = 'slick__slider';
    $content_attributes['id'] = $attributes['id'] . '-slider';

    // The slider must have the attribute "dir" set to "rtl", if so configured.
    if (!empty($js['rtl'])) {
      $attributes['dir'] = 'rtl';
    }

    // Arrows are enforced to allow responsive options hide/show them.
    $tags = '<a><em><strong><button><p><div><i><span>';
    $settings['prev_arrow'] = strip_tags($js['prevArrow'], $tags);
    $settings['next_arrow'] = strip_tags($js['nextArrow'], $tags);

    // Adds helper class if thumbnail on dots hover provided.
    $js['dotsClass'] = empty($js['dotsClass']) ? 'slick-dots' : $js['dotsClass'];

    // @todo drop backward compatibility.
    if (!empty($settings['thumbnail_hover'])) {
      $settings['thumbnail_effect'] = 'hover';
    }
    if (!empty($settings['thumbnail_style']) && !empty($settings['thumbnail_effect'])) {
      $js['dotsClass'] .= ' slick-dots--thumbnail slick-dots--thumbnail-' . $settings['thumbnail_effect'];
    }

    // Adds dots skin modifier class if provided.
    if (!empty($settings['skin_dots'])) {
      $js['dotsClass'] .= ' ' . str_replace('_', '-', 'slick-dots--' . $settings['skin_dots']);
    }

    $js['asNavFor'] = empty($settings['asnavfor_target']) ? $js['asNavFor'] : $settings['asnavfor_target'];
    if (!empty($js['asNavFor'])) {
      // Only if asNavFor, enforce clickable thumbnail, otherwise no joy.
      if ($display == 'thumbnail') {
        $js['focusOnSelect'] = TRUE;
      }

      $attributes['class'][] = 'slick--display--' . $display;
    }

    // focusOnSelect won't work with empty slide value, so add proper selector.
    if (empty($js['slide']) && $js['focusOnSelect']) {
      $js['slide'] = ($js['rows'] == 1 && $js['slidesPerRow'] == 1) ? '.slick__slide' : $js['slide'];
    }

    $has_arrow_down = !empty($goodies['arrow-down']) && !empty($general['arrow_down_target']);
    if ($display == 'main' && $has_arrow_down) {
      $attributes['class'][]     = 'slick--has-arrow-down';
      $arrow_down['class']       = array('slick-down', 'jump-scroll');
      $arrow_down['data-target'] = $general['arrow_down_target'];
      $arrow_down['data-offset'] = $general['arrow_down_offset'];
      $variables['arrow_down']   = '<button' . drupal_attributes($arrow_down) . '></button>';
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
    $settings['current_item'] = $display;
    $settings = isset($item['settings']) ? array_merge($settings, $item['settings']) : $settings;

    $slide = array(
      '#theme'    => 'slick_item',
      '#item'     => isset($item['slide']) ? $item['slide'] : $item,
      '#caption'  => empty($item['caption']) ? array() : array_filter($item['caption']),
      '#delta'    => $delta,
      '#settings' => $settings,
    );
    $variables['items'][$delta] = $slide;
    unset($slide);
  }

  $variables['classes_array'] = $attributes['class'];
}

/**
 * Implements hook_preprocess_slick_item().
 */
function template_preprocess_slick_item(&$variables) {
  $element  = $variables['element'];
  $delta    = $element['#delta'];
  $item     = $variables['item'] = $element['#item'];
  $settings = $element['#settings'];
  $type     = isset($item['#item']['type']) ? $item['#item']['type'] : '';

  // Prepare variables, and remove non-BEM default class.
  foreach (array('content', 'item', 'title', 'wrapper') as $key) {
    $variables[$key . '_prefix'] = $variables[$key . '_suffix'] = '';
  }

  // Configure attributes for containing elements.
  $attributes['class'] = array('slick__slide', 'slide', 'slide--' . $delta);

  // Media module has type: image, audio, video, as opposed to field_type.
  if ($type && $type != 'image') {
    $attributes['class'][] = 'slide--' . $type;
  }

  // All slide types -- main, thumbnail, grid, overlay -- may have captions.
  $variables['caption'] = $element['#caption'];
  $variables['slide_pattern'] = '';

  // Title, caption and overlay, or nested media.
  if ($settings['current_item'] != 'thumbnail') {
    // Each slide can have unique, or uniform layout.
    if (!empty($settings['layout'])) {
      $attributes['class'][] = str_replace('_', '-', 'slide--caption--' . $settings['layout']);
    }

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
    if (!empty($settings['has_pattern']) && empty($settings['lightbox'])) {
      $variables['slide_pattern'] = '<div class="slide__pattern"></div>';
    }

    // Add helper classes for nested sliders.
    if (!empty($settings['nested_slick'])) {
      $attributes['class'][] = $settings['current_item'] == 'overlay' ? 'slide--nested' : 'slide--nester';
    }

    // Custom individual slide classes.
    if (!empty($settings['slide_classes'])) {
      $attributes['class'][] = trim($settings['slide_classes']);
    }
  }

  // Do not add divities for a single slick (unslick) to have clean markups.
  // Or when it is a grid item.
  if ($settings['current_item'] != 'grid') {
    $variables['wrapper_prefix'] = '<div' . drupal_attributes($attributes) . '>';
    $variables['wrapper_suffix'] = '</div>';
  }

  $settings['wrapper'] = $settings['count'] > 1 && $settings['current_item'] != 'grid';
  if ($settings['wrapper'] && empty($settings['grid'])) {
    $variables['content_prefix'] = '<div class="slide__content">';
    $variables['content_suffix'] = '</div>';
  }
  $variables['settings'] = $settings;
}

/**
 * Implements hook_preprocess_slick_grid().
 */
function template_preprocess_slick_grid(&$variables) {
  $element  = $variables['element'];
  $settings = $element['#settings'];

  $attributes = &$variables['attributes_array'];
  $attributes = array('class' => array('slick__grid', 'block-grid'));

  if (empty($settings['unslick'])) {
    $attributes['class'][] = 'slide__content';
  }

  $settings['grid_large'] = $settings['grid'];
  foreach (array('small', 'medium', 'large') as $grid) {
    if ($column = $settings['grid_' . $grid]) {
      $attributes['class'][] = $grid . '-block-grid-' . $column;
    }
  }

  $variables['items'] = array();
  foreach ($element['#items'] as $delta => $item) {
    $settings['current_item'] = 'grid';
    $settings = isset($item['settings']) ? array_merge($settings, $item['settings']) : $settings;
    $classes = array('slide__grid', 'grid', 'grid--' . $delta);
    $variables['item_attributes_array'][$delta]['class'] = $classes;

    $slide['slide'] = array(
      '#theme'    => 'slick_item',
      '#item'     => isset($item['slide']) ? $item['slide'] : $item,
      '#caption'  => empty($item['caption']) ? array() : array_filter($item['caption']),
      '#delta'    => $delta,
      '#settings' => $settings,
    );
    $variables['items'][$delta] = $slide;
    unset($slide);
  }

  $variables['classes_array'] = $attributes['class'];
}

/**
 * Implements hook_process_slick_grid().
 */
function template_process_slick_grid(&$variables) {
  $variables['attributes'] = empty($variables['attributes_array']) ? '' : drupal_attributes($variables['attributes_array']);
  foreach ($variables['items'] as $delta => $item) {
    $variables['item_attributes'][$delta] = empty($variables['item_attributes_array'][$delta]) ? '' : drupal_attributes($variables['item_attributes_array'][$delta]);
  }
}

/**
 * Returns HTML for a slick_image.
 *
 * @param array $variables
 *   An associative array containing:
 *   - item: Associative array of image data, which may include "uri", "alt",
 *     "width", "height", "title" and "attributes".
 *   - image_style: The name of the style to alter the original image.
 *   - url: A string containing the link 'url'.
 *   - item_attributes: Associative array of attributes to be placed in the img.
 *   - settings: An array of options.
 *
 * @ingroup themeable
 */
function theme_slick_image(array $variables) {
  $element  = $variables['element'];
  $elements = array(
    'captions',
    'item',
    'item_attributes',
    'image_style',
    'settings',
    'url',
    'url_attributes',
  );

  // Faking variables as we don't do preprocess.
  foreach ($elements as $key) {
    $variables[$key] = isset($element["#$key"]) ? $element["#$key"] : array();
  }

  // Load the supported formatter variables for the possesive blazy wrapper.
  $settings          = &$variables['settings'];
  $item              = $variables['item'];
  $image_attributes  = &$variables['item_attributes'];
  $url_attributes    = &$variables['url_attributes'];
  $iframe_attributes = array();

  if (isset($settings['content_attributes'])) {
    $iframe_attributes = &$settings['content_attributes'];
  }

  // Modifies variables.
  foreach (array('icon', 'lightbox', 'media_switch') as $key) {
    $settings[$key] = isset($settings[$key]) ? $settings[$key] : '';
  }

  $build  = '';
  $type   = empty($item['type']) ? 'image' : $item['type'];
  $media  = !empty($item['embed_url']) && $type != 'image';
  $switch = $settings['media_switch'];
  $uri    = $item['uri'];

  $settings['image_url'] = empty($variables['image_style']) ? file_create_url($uri) : image_style_url($variables['image_style'], $uri);
  $settings['ratio']     = empty($settings['ratio']) ? '' : str_replace(':', '', $settings['ratio']);

  // Build attributes.
  $attributes = array('class' => array('media', 'media--' . $type));

  if ($switch) {
    $attributes['class'][] = 'media--switch';
  }

  foreach (array('width', 'height', 'alt', 'title') as $key) {
    if (isset($item[$key])) {
      if (array_key_exists($key, $image_attributes)) {
        continue;
      }
      $image_attributes[$key] = $item[$key];
    }
  }

  // Picture integration, else Slick lazyload, or regular image.
  $params = $image_attributes;
  if (empty($params['breakpoints'])) {
    $image_attributes['class'][] = 'media__image media__element';

    // Aspect ratio to fix layout reflow with lazyloaded images responsively.
    if (!empty($settings['ratio'])) {
      $attributes['class'][] = 'media--ratio media--ratio--' . $settings['ratio'];

      if (!empty($image_attributes['height']) && in_array($settings['ratio'], array('enforced', 'fluid'))) {
        $attributes['style'] = 'padding-bottom: ' . round((($image_attributes['height'] / $image_attributes['width']) * 100), 2) . '%';
      }
    }

    if (!empty($settings['background'])) {
      // @todo Blazy integration with multi-serving bakground images.
      // slick_build_breakpoint_attributes($attributes, $settings);
      $attributes['class'][] = 'media--background';
    }

    if (!empty($settings['lazy'])) {
      $attributes['class'][] = 'media--loading';

      // Attach data-attributes to the either DIV or IMG container.
      $image_attributes['src'] = 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7';

      slick_build_breakpoint_attributes($image_attributes, $settings);

      // Do not pass to theme_image() as D7 doesn't support data URI, yet.
      $build = '<img' . drupal_attributes($image_attributes) . ' />';
    }
    else {
      $params['path'] = $settings['image_url'];
      $build = theme('image', $params);
    }
  }
  else {
    $params['uri'] = $uri;
    $build = theme('picture', $params);
  }

  // With CSS background, IMG may be emptied, so add to the container instead.
  if (!empty($settings['thumbnail_style'])) {
    $attributes['data-thumb'] = image_style_url($settings['thumbnail_style'], $uri);
  }

  // Prepares a media player.
  // build : If iframe switch disabled, use iframe only, remove image.
  // player: If no colorbox/photobox, it is an image to iframe switcher.
  // data- : Gets consistent with colorbox to share JS manipulation.
  // @todo re-check blazy 'data-src' IFRAME lazyload against blazy.media.js.
  if ($media) {
    $build                           = empty($switch) ? '' : $build;
    $settings['player']              = empty($settings['lightbox']) && $switch != 'content';
    $iframe_attributes['data-media'] = drupal_json_encode(array('type' => $type, 'scheme' => $item['scheme']));
    $iframe_attributes['data-lazy']  = $item['embed_url'];
    $iframe_attributes['src']        = empty($settings['iframe_lazy']) ? $item['embed_url'] : 'about:blank';
    $iframe_attributes['class'][]    = 'media__iframe media__element';

    if ($settings['player']) {
      $attributes['class'][] = 'media--player';
      $build .= '<iframe' . drupal_attributes($iframe_attributes) . ' allowfullscreen></iframe>';
      $build .= '<span class="media-icon media-icon--close"></span>';
      $build .= '<span class="media-icon media-icon--play"></span>';
    }
  }

  $build .= $settings['icon'];
  $build = '<div' . drupal_attributes($attributes) . '>' . $build . '</div>';

  // The link to content or lightboxes.
  if (!empty($variables['url'])) {
    if (!empty($settings['lightbox'])) {
      $lightbox = TRUE;
      $icon = '<span class="media-icon media-icon--lightbox media-icon--' . $settings['lightbox'] . '"></span>';
      $build .= empty($settings['icon']) ? $icon : $settings['icon'];
      if (!empty($settings['has_pattern'])) {
        $build .= '<div class="slide__pattern"></div>';
      }
    }

    $link_options = empty($url_attributes) ? array() : array('attributes' => $url_attributes);
    $link_options['html'] = TRUE;
    $build = l($build, $variables['url'], $link_options);

    if (isset($lightbox) && !empty($variables['captions']['lightbox'])) {
      $build .= '<div class="litebox-caption element-invisible">' . $variables['captions']['lightbox'] . '</div>';
    }
  }

  return $build;
}

/**
 * Provides re-usable breakpoint data-attributes.
 */
function slick_build_breakpoint_attributes(array &$attributes = array(), $settings = array()) {
  // Blazy can lazyload a single image, Slick not, yet, here comes the trouble.
  if (!empty($settings['blazy'])) {
    $settings['lazy_attribute'] = 'src';
    $settings['lazy_class'] = 'b-lazy';
  }

  $lazy_class     = empty($settings['lazy_class']) ? 'lazy' : $settings['lazy_class'];
  $lazy_attribute = empty($settings['lazy_attribute']) ? 'lazy' : $settings['lazy_attribute'];

  // Defines attributes, builtin, or supported lazyload such as Slick.
  $attributes['class'][] = $lazy_class;
  $attributes['data-' . $lazy_attribute] = $settings['image_url'];

  // @todo Blazy integration.
  if (!empty($settings['breakpoints'])) {
    if (!empty($settings['background'])) {
      foreach ($settings['breakpoints'] as $key => $breakpoint) {
        if (!empty($breakpoint['url'])) {
          $attributes['data-src-' . $key] = $breakpoint['url'];
        }
      }
    }
    elseif (!empty($settings['srcset'])) {
      $attributes['srcset'] = '';
      $attributes['data-srcset'] = $settings['srcset'];
      $attributes['sizes'] = '100w';

      if (!empty($settings['sizes'])) {
        $attributes['sizes'] = trim($settings['sizes']);
        unset($attributes['width']);
        unset($attributes['height']);
      }
    }
  }
}

/**
 * Strips out options similar to default values from the optionset options.
 */
function _slick_remove_default_optionset_options($optionset, $js = array(), $context = array()) {
  $config   = array();
  $options  = $optionset->options;
  $defaults = slick_get_options();

  // Remove wasted dependent options if disabled, empty or not.
  slick_remove_wasted_dependent_options($js);
  $config = array_diff_assoc($js, $defaults);

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

  return $config;
}

/**
 * Removes wasted dependent options, even if not empty.
 */
function slick_remove_wasted_dependent_options(array &$config = array()) {
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

  if (!empty($config['useCSS']) && !empty($config['cssEaseBezier'])) {
    $config['cssEase'] = $config['cssEaseBezier'];
  }
  unset($config['cssEaseOverride'], $config['cssEaseBezier']);
}
