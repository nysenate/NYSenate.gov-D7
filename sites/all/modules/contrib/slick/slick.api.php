<?php

/**
 * @file
 * Hooks and API provided by the Slick module.
 *
 * Modules may implement any of the available hooks to interact with Slick.
 */

/**
 * Slick may be configured using the web interface via sub-modules.
 *
 * However if you want to code it, use slick_build() for easy build.
 *
 * @see slick_fields or slick_views.
 * @see slick_build().
 */

/**
 * Quick sample #1.
 *
 * @see slick_build()
 */
function my_module_render_slick() {
  $element = array();

  // Add items.
  $items = array();

  // Use slick_get_image() to have lazyLoad, or theme_image_style/theme_image.
  // Caption contains: editor, overlay, title, alt, data, link.
  $items[] = array(
    'slide'   => '<img src="https://drupal.org/files/One.gif" />',
    'caption' => array('title' => t('Description #1')),
  );

  $items[] = array(
    'slide'   => '<img src="https://drupal.org/files/Two.gif" />',
    'caption' => array('title' => t('Description #2')),
  );

  $items[] = array(
    'slide'   => '<img src="https://drupal.org/files/Three.gif" />',
    'caption' => array('title' => t('Description #3')),
  );

  // Add options.
  $options = array(
    'autoplay' => TRUE,
    'dots'     => TRUE,
    'arrows'   => FALSE,
  );

  // Build the slick.
  $element = slick_build($items, $options);

  // The following should also work for defaults as the only required is $items:
  $element = slick_build($items);

  // Render the $element, such as found normally at a .tpl file.
  print render($element);

  // Or simply return the $element if a renderable array is expected.
  return $element;
}

/**
 * Detailed sample #2.
 *
 * The example is showing a customized views-view-unformatted--ticker.tpl.php.
 * Practically any content-related .tpl.php file where you have data to print.
 * Do preprocess, or here a direct .tpl.php manipulation for quick illustration.
 *
 * The goal is to create a vertical newsticker, or tweets, with pure text only.
 * First, create an unformatted Views block, says 'Ticker' containing ~ 10
 * titles, or any data for the contents -- using EFQ, or static array will do.
 */
function my_module_render_slick_detail() {
  // 1.
  // Optional $settings, can be removed.
  // Provides HTML settings with optionset name and ID, none of JS related.
  // To add JS key:value pairs, use #options at theme_slick() below instead.
  // If you provide ID, be sure unique per instance as it is cached.
  // Leave empty to be provided by the module.
  $id = 'slick-ticker';
  $settings = array(
    // Optional optionset name, otherwise fallback to default.
    'optionset' => 'blog',

    // Optional skin name fetched from hook_slick_skins_info(), otherwise none.
    // The supported keys: skin, skin_thumbnail, skin_arrows, skin_dots.
    'skin' => 'fullwidth',

    // ID can be used for lightbox group, cache ID, the asnavfor, etc.
    // Do not supply attributes to be provided by the module instead.
    'id' => $id,
  );

  // 3.
  // Obligatory $items, as otherwise empty slick.
  // Prepare $items contents, note the 'slide' key is to hold the actual slide
  // which can be pure and simple text, or any image/media file.
  // Meaning $rows can be text only, or image/audio/video, or a combination
  // of both.
  // To add caption/overlay, use 'caption' key with the supported sub-keys:
  // title, alt, link, overlay, editor, or data for complex content.
  // Sanitize each sub-key content accordingly.
  // @see template_preprocess_slick_item() for more info.
  $items = array();
  foreach ($rows as $key => $row) {
    $items[] = array(
      'slide' => $row,

      // Optional caption contains: editor, overlay, title, alt, data, link.
      // If the above slide is an image, to add text caption, use:
      // 'caption' => array('title' => 'some-caption data'),
      // Optional slide settings to manipulate layout, can be removed.
      // Individual slide supports some useful settings like layout, classes,
      // etc.
      // Meaning each slide can have different layout, or classes.
      // @see slick_layouts()
      // @see slick_fields README.txt for layout, or sub-modules implementation.
      'settings' => array(

        // Optionally adds a custom layout, can be a static uniform value, or
        // dynamic one based on the relevant field value.
        // @see slick_fields README.txt for the supported layout keys.
        'layout' => 'bottom',

        // Optionally adds a custom class, can be a static uniform class, or
        // dynamic one based on the relevant field value.
        'slide_classes' => 'slide--custom-class--' . $key,
      ),
    );
  }

  // 4.
  // Optional assets loader if using slick_build(), yet required for renderable.
  // An empty array should suffice for the most basic slick with no skin at all.
  // @see slick_attach().
  // @see slick_fields/slick_views for the real world samples.
  $attach = array();

  // To add skins, use the $settings variable mentioned above, with supported
  // keys: skin, skin_thumbnail, skin_arrows, skin_dots.
  $attachments = slick_attach($attach, $settings);

  // Add more attachments using regular library keys just as freely:
  $attachments['css'] += array(MYTHEME_PATH . '/css/zoom.css' => array('weight' => 9));
  $attachments['js']  += array(MYTHEME_PATH . '/js/zoom.min.js' => array('weight' => 0));

  // 5.
  // Optional specific JS options, to re-use one optionset, can be removed.
  // Play with speed and options to achieve desired result.
  // @see slick_get_options()
  $options = array(
    'arrows'    => FALSE,
    'autoplay'  => TRUE,
    'vertical'  => TRUE,
    'draggable' => FALSE,
  );

  // 6.A.
  // Build the slick, note key 0 just to mark the thumbnail asNavFor with key 1.
  $slick[0] = array(
    '#theme'    => 'slick',
    '#items'    => $items,

    // The following 3 lines are optional, if needed, and can be removed.
    '#options'  => $options,
    '#settings' => $settings,
    '#attached' => $attachments,
  );

  // Optionally build an asNavFor with $slick[1], and both should be passed to
  // theme_slick_wrapper(), otherwise a single theme_slick() will do.
  // See slick_fields, or slick_views sub-modules for asNavFor samples.
  // ATM, we only have one slick and all is set, so render the Slick.
  print render($slick);

  // 6.B.
  // Optional Cache option, can be removed.
  // Or recommended, use slick_build() to cache the slick instance easily.
  // If it is a hardly updated content, such as profile videos, logo carousels,
  // or more permanent home slideshows, select "Persistent", otherwise time.
  // Cache the slick for 1 hour and fetch fresh contents when the time reached.
  // If stale cache is not cleared, slick will keep fetching fresh contents.
  $settings['cache'] = 3600;

  // Or cache the slick and keep stale contents till the next cron runs.
  $settings['cache'] = 'persistent';

  // Optionally add a custom unique cache ID.
  $settings['cid'] = 'my-extra-unique-id';

  // Build the slick with the arguments as described above:
  $slick = slick_build($items, $options, $settings, $attachments);

  // The following should also work for defaults as the only required is $items:
  $slick = slick_build($items);

  // All is set, render the Slick.
  print render($slick);
}

/**
 * AsNavFor sample #3.
 *
 * Requirements for asNavFor:
 *   - $settings['current_display'] = 'thumbnail';
 *     Must be defined explicitly only for the thumbnail $settings.
 *
 *   - $options['asNavFor'] = '#TARGETID-slider';
 *     Defined for both slick main and thumbnail where "TARGETID-slider" is the
 *     actual target which is placed within the $content_attributes.
 *
 *     See the HTML structure below to get a clear idea.
 *
 * 1. Main slider:
 * <div id="slick-for" class="slick slick-processed">
 *   <div class="slick__slider slick-initialized slick-slider">
 *     <div class="slick__slide"></div>
 *   </div>
 * </div>
 *
 * 2. Thumbnail slider:
 * <div id="slick-nav" class="slick slick-processed">
 *   <div class="slick__slider slick-initialized slick-slider">
 *     <div class="slick__slide"></div>
 *   </div>
 * </div>
 *
 * At both cases, asNavFor should target slick-initialized class/ID attributes,
 * hence "#slick-for-slider" and "#slick-nav-slider" respectively.
 * Note the "#" before the ID. Slick is expecting valid CSS selector.
 * The suffix "-slider" is automatically added by module.
 */
function my_module_render_slick_asnavfor() {
  $slick = array();

  // 1. Main slider ------------------------------------------------------------
  // Main caption contain: editor, overlay, title, alt, data, link.
  // Add items.
  $items = array();

  // Use slick_get_image() to have lazyLoad, or theme_image_style/theme_image.
  $images = array(1, 2, 3, 4, 6, 7);
  foreach ($images as $key) {
    $items[] = array(
      'slide'   => '<img src="/sites/all/images/image-0' . $key . '.jpg" width="1140" />',
      'caption' => array('title' => 'Description #' . $key),
    );
  }

  // Add options.
  $options = array(
    // If the main slick ID is "slick-for", the asNavfor target is targetting
    // the thumbnail slider ID, suffixed with "-slider" automatically.
    'asNavFor'      => '#slick-nav-slider',
    'arrows'        => FALSE,
    'centerMode'    => TRUE,
    'centerPadding' => '',
  );

  // Satisfy requirements for the main asnavfor.
  $settings = array(
    'optionset' => 'optionset_main',
    'id'        => 'slick-for',
  );

  // Build the main slider.
  $attach = array();
  $slick[0] = slick_build($items, $options, $settings, $attach);

  // 2. Thumbnail slider -------------------------------------------------------
  // Thumbnail caption only accepts: data.
  $items = array();
  foreach ($images as $key) {
    $items[] = array(
      'slide'   => '<img src="/sites/all/images/image-0' . $key . '.jpg" width="210" />',
      'caption' => array('data' => 'Description #' . $key),
    );
  }

  // Add options.
  $options = array(
    // If the thumbnail slick ID is "slick-nav", the asNavfor target is
    // targetting the main slider ID, suffixed with "-slider" automatically.
    'asNavFor'      => '#slick-for-slider',
    'arrows'        => TRUE,
    'centerMode'    => TRUE,
    'centerPadding' => '10px',

    // Be sure to have multiple slides for the thumbnail, otherwise nonsense.
    'slidesToShow'  => 5,
  );

  // Satisfy requirements for the thumbnail asnavfor.
  $settings = array(
    'optionset'       => 'optionset_thumbnail',

    // Must define 'current_display' explicitly to 'thumbnail'.
    'current_display' => 'thumbnail',
  );

  // Build the thumbnail slider, empty $attach means basic libraries only.
  $attach = array();
  $slick[1] = slick_build($items, $options, $settings, $attach);

  // Pass both slicks to theme_slick_wrapper() to get a wrapper.
  $element = array(
    '#theme' => 'slick_wrapper',
    '#items' => $slick,
  );

  return $element;
}

/**
 * Alter Slick attach information before they are called.
 *
 * This function lives in a module file, not my_module.slick.inc.
 *
 * @param array $attach
 *   The modified array of $attach information from slick_attach().
 * @param array $settings
 *   An array of settings to check for the supported features.
 *
 * @see slick_attach()
 * @see slick_example.module
 */
function hook_slick_attach_info_alter(array &$attach, array $settings = []) {
  // Disable inline CSS after copying the output to theme at final stage.
  // Inline CSS are only used for 1 case now: Field collection
  // individual slide color.
  // If you need to turn images into CSS background, use 'Use CSS background'
  // option instead, be sure to have Aspect ratio enabled, or min-height, to
  // selector .media--background accordingly, otherwise collapsed container.
  // @see slick_slick_skins_info()
  $attach['attach_inline_css'] = NULL;

  // Disable module JS: slick.load.min.js to use your own slick JS.
  $attach['attach_module_js'] = FALSE;
}

/**
 * Alter Slick load information before they are called.
 *
 * This function lives in a module file, not my_module.slick.inc.
 *
 * @param array $load
 *   The modified array of $load information.
 * @param array $attach
 *   The contextual array of $attach information.
 * @param array $skins
 *   The contextual array of $skins information.
 * @param array $settings
 *   An array of settings to check for the supported features.
 *
 * @see slick_attach()
 * @see slick_example.module
 * @see slick_devel.module
 */
function hook_slick_attach_load_info_alter(array &$load, array $attach = [], array $skins = [], array $settings = []) {
  $slick_path = drupal_get_path('module', 'slick');
  $min = $slick_path . '/js/slick.load.min.js';
  $dev = $slick_path . '/js/slick.load.js';

  if (MYMODULE_DEBUG) {
    // Switch to the non-minified version of the slick.load.min.js.
    $load['js'] += array(
      $dev => array('group' => JS_DEFAULT, 'weight' => 0),
    );
    if (isset($load['js'][$min])) {
      unset($load['js'][$min]);
    }
  }
}

/**
 * Using slick_attach() to a custom theme or renderable array.
 *
 * The slick_attach() is just an array as normally used with #attached property.
 * This can be used to merge extra 3d party libraries along with the slick.
 * Previously slick_add() was provided as a fallback. It was dropped since it
 * was never actually used by slick. However you can add slick assets using a
 * few alternatives: drupal_add_library(), drupal_add_js(), or the recommended
 * #attached, the D8 way, just as easily. Hence slick_attach() acts as a
 * shortcut to load the basic Slick assets.
 *
 * Passing an empty array will load 3 basic files:
 *  - slick.min.js, slick.css, slick.load.min.js.
 */
function my_module_render_slick_theme() {
  // Empty array for the basic files, or optionally pass a skin to have a proper
  // display where appropriate, see slick_fields/slick_views for more samples.
  $attach = array();
  $settings = array('skin' => 'fullwidth', 'skin_thumbnail' => 'asnavfor');
  $attachments = slick_attach($attach, $settings);

  // Add another custom library to the array.
  $transit = libraries_get_path('jquery.transit') . '/jquery.transit.min.js';
  $attachments['js'] += array($transit => array('group' => JS_LIBRARY, 'weight' => -5));

  // Add another asset.
  $my_module_path = drupal_get_path('module', 'my_module');
  $attachments['css'] += array($my_module_path . '/css/my_module.css' => array('weight' => 5));

  // Pass the $attachments to theme_slick(), or any theme with bigger scope.
  $my_module_theme = array(
    '#theme' => 'my_module_theme',
    // More properties...
    '#attached' => $attachments,
  );

  return $my_module_theme;
}

/**
 * Registers Slick skins.
 *
 * This function may live in module file, or my_module.slick.inc if you have
 * many skins.
 *
 * This hook can be used to register skins for the Slick. Skins will be
 * available when configuring the Optionset, Field formatter, or Views style.
 * It should be used in relation to individual slide layout to get the most out
 * of it, see README.txt on slick_fields.module for possible Slide layouts using
 * a field with Field collection.
 *
 * Slick skins get a unique CSS class to use for styling, e.g.:
 * If your skin name is "my_module_slick_carousel_rounded", the class is:
 * slick--skin--my-module-slick-carousel-rounded
 *
 * A skin can specify some CSS and JS files to include when Slick is displayed,
 * except for a thumbnail, arrows, or dots skin which accepts CSS only.
 *
 * Each skin supports 5 keys:
 * - name: The human readable name of the skin.
 * - group: The group the skin belongs to reduce confusing UI selection,
 *    with the supported keys: arrows, dots, main, overlay, thumbnail.
 * - description: The description about the skin, for help and manage pages.
 * - css: An array of CSS files to attach.
 * - js: An array of JS files to attach, e.g.: image zoomer, reflection, etc.
 * - inline css: An optional flag to determine whether the image is turned into
 *   CSS background rather than image with SRC, see fullscreen skin.
 *
 * @see hook_hook_info()
 * @see slick_example.module
 * @see slick.slick.inc
 */
function hook_slick_skins_info() {
  // The source can be theme, or module.
  $theme_path = drupal_get_path('theme', 'my_theme');

  return array(
    'skin_name' => array(

      // Human readable skin name.
      'name' => t('Skin name'),

      // Description of the skin.
      'description' => t('Skin description.'),

      // Not yet implemented by now, 3/5/16.
      // Defines group for the skin to reduce selection confusion at UI.
      // Accepted keys: arrows, dots, overlay, main, thumbnail.
      // This is deprecating hook_slick_arrows_info(), hook_slick_dots_info().
      'group' => 'main',

      'css' => array(
        // Full path to a CSS file to include with the skin.
        $theme_path . '/css/my-theme.slick.theme--slider.css' => array(),
        $theme_path . '/css/my-theme.slick.theme--carousel.css' => array(),
      ),

      'js' => array(

        // Full path to a JS file to include with the skin.
        $theme_path . '/js/my-theme.slick.theme--slider.js' => array(),
        $theme_path . '/js/my-theme.slick.theme--carousel.js' => array(),

        // If you want to act on afterSlick event, or any other slick events,
        // put a lighter weight before slick.load.min.js (0).
        $theme_path . '/js/slick.skin.menu.min.js' => array('weight' => -2),
      ),
    ),
  );
}

/**
 * Alter Slick skins.
 *
 * This function lives in a module file, not my_module.slick.inc.
 * Overriding skin CSS can be done via theme.info, hook_css_alter(), or below
 * before anything passed before being passed to drupal_process_attached().
 *
 * @param array $skins
 *   The associative array of skin information from hook_slick_skins_info().
 *
 * @deprecated, removed at D9:
 *
 * @see https://www.drupal.org/node/1901550
 * @see https://www.drupal.org/node/1892574
 * @see hook_slick_skins_info()
 * @see slick_example.module
 */
function hook_slick_skins_info_alter(array &$skins) {
  // The source can be theme, or module.
  // Hence the CSS is provided by my_theme.
  $path = drupal_get_path('theme', 'my_theme');

  // Modify the default skin's name and description.
  $skins['default']['name'] = t('My Theme: Default');
  $skins['default']['description'] = t('My Theme default skin.');

  // This one won't work.
  // $skins['default']['css'][$path . '/css/slick.theme--base.css'] = array();
  // This one overrides slick.theme--default.css with slick.theme--base.css.
  $skins['default']['css'] = array($path . '/css/slick.theme--base.css' => array());

  // Overrides skin asNavFor with theme CSS.
  $skins['asnavfor']['name'] = t('My Theme: asnavfor');
  $skins['asnavfor']['css'] = array($path . '/css/slick.theme--asnavfor.css' => array());

  // Or with the new name.
  $skins['asnavfor']['css'] = array($path . '/css/slick.theme--asnavfor-new.css' => array());

  // Overrides skin Fullwidth with theme CSS.
  $skins['fullwidth']['name'] = t('My Theme: fullwidth');
  $skins['fullwidth']['css'] = array($path . '/css/slick.theme--fullwidth.css' => array());
}
