<?php
/**
 * @file
 * Off-loaded hooks for the Slick fields admin.
 */

/**
 * Off-loaded hook_field_formatter_settings_form().
 */
function _slick_fields_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  form_load_include($form_state, 'inc', 'slick', 'includes/slick.admin');
  $path       = drupal_get_path('module', 'slick_fields');
  $slick_path = drupal_get_path('module', 'slick');
  $display    = $instance['display'][$view_mode];
  $settings   = $display['settings'];
  $field_type = $field['type'];

  // $field empty at admin/structure/file-types/manage/image/file-display,
  // and this form is also loaded there via file_entity_file_formatter_info().
  if (empty($field)) {
    $field_type = $instance['entity_type'];
  }

  $is_picture     = function_exists('picture_get_mapping_options');
  $is_colorbox    = function_exists('_colorbox_doheader');
  $is_photobox    = function_exists('photobox_library');
  $elements       = $caption_options = $title_options = $link_options = array();
  $color_options  = $slide_classes = $thumb_captions = array();
  $layout_builtin = slick_layouts();
  $layout_options = $layout_builtin;
  $optionsets     = slick_optionset_options();
  $readme         = url($slick_path . '/README.txt');
  $image_styles   = image_style_options(FALSE, PASS_THROUGH);
  $is_views_ui    = '';

  $field_entity_type = $field_type;
  switch ($field_type) {
    case 'file':
      $field_layouts   = slick_get_media_fields($instance, array('options_select'));
      $layout_options  = $field_layouts ? $field_layouts : $layout_options;
      $slide_classes   = slick_get_media_fields($instance, array('options_select', 'text_textfield'));
      $title_fields    = array('link_field', 'text_textfield', 'text_textarea');
      $title_options   = slick_get_media_fields($instance, $title_fields);
      $link_fields     = array('text_textfield', 'link_field', 'url_external');
      $link_options    = slick_get_media_fields($instance, $link_fields);
      $thumb_captions  = slick_get_media_fields($instance, array('text_textfield', 'text_textarea'));
      $caption_options = slick_get_media_fields($instance);
      $overlay_options = slick_get_media_fields($instance, array('text_textfield'));
      break;

    // This should go as a separate module, but alas.
    case 'field_collection':
      $field_entity_type = 'field_collection_item';
      $field_layouts   = slick_get_fc_fields($instance, array('list_text'));
      $layout_options  = $field_layouts ? $field_layouts : $layout_options;
      $color_options   = slick_get_fc_fields($instance, array('text', 'color_field_rgb'));
      $image_options   = slick_get_fc_fields($instance, array('image', 'file'));
      $overlay_fields  = array('image', 'file', 'atom_reference');
      $overlay_options = slick_get_fc_fields($instance, $overlay_fields);
      $title_fields    = array('link_field', 'text', 'text_long');
      $title_options   = slick_get_fc_fields($instance, $title_fields);
      $link_fields     = array('text', 'link_field', 'url');
      $link_options    = slick_get_fc_fields($instance, $link_fields);
      $thumb_captions  = slick_get_fc_fields($instance, array('text', 'text_long'));
      $caption_options = slick_get_fc_fields($instance, array(
        'file',
        'image',
        'link_field',
        'list_text',
        'text_long',
        'text_with_summary',
        'taxonomy_term_reference',
        'text',
      ));
      break;

    default:
      break;
  }

  if ($instance['entity_type'] == 'ctools') {
    $is_views_ui = '<h3 class="form--slick__title">' . t('Check "Use field template" under "Style settings" below, if using multiple-value field for the slides. <small>Views preview works with jQuery > 1.7.</small>') . '</h3>';
  }

  $elements['opening'] = array(
    '#markup' => '<div class="form--slick form--compact form--field has-tooltip">' . $is_views_ui,
    '#weight' => -100,
  );

  slick_get_top_elements($elements, $settings, $form_state);

  $elements['image_style'] = array(
    '#title'        => t('Image style'),
    '#type'         => 'select',
    '#empty_option' => t('None (original image)'),
    '#options'      => $image_styles,
    '#description'  => t('The main image style. This allows more variants per view mode with a single optionset. If Media module installed, this also determines iframe sizes to have various iframe dimensions with just a single file entity view mode, relevant for a mix of image and multimedia to get a consistent display.'),
  );

  $elements['thumbnail_style'] = array(
    '#title'       => t('Thumbnail style'),
    '#type'        => 'select',
    '#options'     => $image_styles,
    '#description' => t('Usages: <ol><li>If <em>Optionset thumbnail</em> provided, it is for asNavFor thumbnail navigation.</li><li>If <em>Dots with thumbnail</em> selected, displayed when hovering over dots.</li><li>Photobox thumbnail.</li><li>Custom work to build arrows with thumbnails via the provided data-thumb attributes.</li></ol>Leave empty to not use thumbnails.'),
  );

  $elements['thumbnail_hover'] = array(
    '#title'       => t('Dots with thumbnail'),
    '#type'        => 'checkbox',
    '#description' => t('Dependent on a skin, dots option enabled, and Thumbnail style. If checked, dots pager are kept, and thumbnail will be hidden and only visible on mouseover, default to min-width 120px. Alternative to asNavFor aka separate thumbnails as slider.'),
    '#states' => array(
      'invisible' => array(
        'select[name*="[thumbnail_style]"]' => array('value' => ''),
      ),
    ),
  );

  // Layout to all supported fields.
  $elements['slide_layout'] = array(
    '#title'       => t('Slide layout'),
    '#type'        => 'select',
    '#options'     => $layout_options + $layout_builtin,
    '#description' => t('This affects the entire slides. Split half requires any skin Split. Leave empty to DIY.'),
  );

  $elements['thumbnail_caption'] = array(
    '#type'        => 'select',
    '#title'       => t('Thumbnail caption'),
    '#options'     => array(),
    '#access'      => FALSE,
    '#description' => t('Thumbnail caption maybe just title/ plain text. If Thumbnail image style is not provided, the thumbnail pagers will be just text like regular tabs.'),
    '#states' => array(
      'invisible' => array(
        'select[name*="[optionset_thumbnail]"]' => array('value' => ''),
      ),
    ),
  );

  if (in_array($field_entity_type, array('field_collection_item', 'file'))) {
    $elements['slide_layout']['#prefix'] = '<h3 class="form--slick__title">' . t('Fields') . '</h3>';

    // Media overlay.
    $elements['slide_overlay'] = array(
      '#title'       => t('Overlay video'),
      '#type'        => 'select',
      '#options'     => $overlay_options,
      '#description' => t("Choose the plain text field containing Youtube or Vimeo url to display video overlay over the main image background. Provided as currently file entity media browser doesn't support nested files. Be sure the parent file type is image, not video."),
    );

    // Complex slide layout is provided by FC alone.
    // Skip media file field as it is the main/ background media already.
    if (in_array($field_entity_type, array('field_collection_item'))) {
      // Field collection overlay.
      $elements['slide_overlay']['#title'] = t('Overlay image/video');
      $elements['slide_overlay']['#description'] = t('Overlays can be single image/auvio/video, or nested slicks. If audio/video, be sure the display is not image. Manage its display at its own entity View mode (there). Two ways to build nested slicks: <ol><li>Make this field use Slick formatter there, and leave <strong>Enable nested slicks</strong> unchecked.</li><li>Or check <strong>Enable nested slicks</strong> here and be sure to use Image or Rendered file formatter (not Slick) there for the supported fields: Image, Media, Atom reference.</li></ol>');

      $elements['slide_image'] = array(
        '#title'       => t('Main image'),
        '#type'        => 'select',
        '#options'     => $image_options,
        '#description' => t('Main background image field'),
      );

      // Field collection nested slicks, slicks within a slick.
      $elements['nested_slick'] = array(
        '#title'       => t('Enable nested slicks'),
        '#type'        => 'checkbox',
        '#description' => t('If checked, multiple overlay items will be rendered as nested slicks, otherwise only the first image/video/audio is displayed. Applied to Image and Rendered file formatters. Alternatively, use the Slick carousel formatter for this particular overlay field at its own View mode display to build similar nested slick, and leave this unchecked.'),
        '#states' => array(
          'invisible' => array(
            'select[name*="[slide_overlay]"]' => array('value' => ''),
          ),
        ),
      );

      $elements['nested_style'] = array(
        '#title'       => t('Nested image style'),
        '#type'        => 'select',
        '#options'     => $image_styles,
        '#description' => t('Choose the image style for the nested slicks to get them uniformly.'),
        '#states' => array(
          'invisible' => array(
            array('select[name*="[slide_overlay]"]' => array('value' => '')),
            array(':input[name*="[nested_slick]"]' => array('checked' => FALSE)),
          ),
        ),
      );

      $elements['nested_optionset'] = array(
        '#title'       => t('Nested optionset'),
        '#type'        => 'select',
        '#options'     => $optionsets,
        '#description' => t('Choose the optionset for the nested slicks.'),
        '#states' => array(
          'invisible' => array(
            array('select[name*="[slide_overlay]"]' => array('value' => '')),
            array(':input[name*="[nested_slick]"]' => array('checked' => FALSE)),
          ),
        ),
      );
    }

    $elements['slide_title'] = array(
      '#title'       => t('Slide title'),
      '#type'        => 'select',
      '#options'     => $title_options,
      '#description' => t('If provided, it will bre wrapped with H2 and class .slide__title.'),
    );

    $elements['slide_link'] = array(
      '#title'       => t('Link'),
      '#type'        => 'select',
      '#options'     => $link_options,
      '#description' => t('Link to content: Read more, View Case Study, etc, wrapped with class .slide__link.'),
    );

    if ($field_entity_type == 'file') {
      $elements['slide_classes'] = array(
        '#title'       => t('Slide class'),
        '#type'        => 'select',
        '#options'     => $slide_classes,
        '#description' => t('If provided, individual slide will have this class, e.g.: to have different background with transparent images and skin Split.'),
      );
    }

    $elements['slide_caption'] = array(
      '#title'       => t('Caption fields'),
      '#type'        => 'checkboxes',
      '#options'     => $caption_options,
      '#description' => t('Enable any of the following fields as slide caption. These fields are treated and wrapped as captions. Be sure to make them visible at their relevant Manage display.'),
    );

    if ($field_entity_type == 'field_collection_item') {
      $elements['slide_caption']['#description'] .= ' ' . t('And not choose the same field as main/ background image.');
    }

    if (empty($caption_options)) {
      $elements['slide_caption']['#description'] = t('No fields found for the captions. You need to add relevant fields for the captions.');
    }

    // Layout fields to make individual slide more variant.
    $elements['slide_layout']['#description'] = t('Create a dedicated List (text - max number 1) field related to the caption placement with the following supported keys: top, right, bottom, left, center, center-top, etc. See <a href="@url" target="_blank">README</a> under "Slide layout" for more info. Split half requires any skin Split. Leave empty to DIY.', array('@url' => url($path . '/README.txt')));

    $view_mode_options = slick_get_view_modes($field_entity_type, TRUE);
    $elements['view_mode'] = array(
      '#type'        => 'select',
      '#title'       => t('View mode'),
      '#options'     => $view_mode_options,
      '#description' => t('Required to grab the fields. Be sure the "View mode" is enabled, and the enabled fields here are not hidden there. Create view modes using hook_entity_info_alter, or <a href="@url" target="_blank">entity_view_mode</a>.', array('@url' => '//drupal.org/project/entity_view_mode')),
      '#access'      => count($view_mode_options) > 1,
    );

    if ($field_entity_type == 'file') {
      $elements['view_mode']['#description'] .= '<br />' . t('For video, make sure to choose relevant video display, not as image.');
    }
  }

  $elements['media_switch'] = array(
    '#title'       => t('Media switcher'),
    '#type'        => 'select',
    '#options'     => array(
      'content'       => t('Image linked to content'),
      'iframe-switch' => t('Image to iframe switcher'),
    ),
    '#description' => t('Dependent on the enabled supported modules.<ol><li>Link to content: for aggregated small slicks.</li><li>Media file iframe: audio/video is hidden below image until toggled, otherwise iframe is always displayed, and draggable fails. Aspect ratio applies.</li><li>Colorbox.</li><li>Photobox. Be sure to select "Thumbnail style" for the overlay thumbnails.</li></ol>'),
  );

  if (in_array($field_entity_type, array('field_collection_item', 'file'))) {
    $elements['iframe_lazy'] = array(
      '#type'        => 'checkbox',
      '#title'       => t('Lazy iframe'),
      '#description' => t('Check to make the video/audio iframes truly lazyloaded, and speed up loading time. Depends on JS enabled at client side.'),
      '#states' => array(
        'visible' => array(
          array('select[name*="[media_switch]"]' => array('value' => 'iframe-switch')),
        ),
      ),
    );

    // http://en.wikipedia.org/wiki/List_of_common_resolutions
    $elements['aspect_ratio'] = array(
      '#type'        => 'select',
      '#title'       => t('Aspect ratio'),
      '#options'     => drupal_map_assoc(array('1:1', '4:3', '16:9')),
      '#description' => t('Aspect ratio to get consistently responsive images and iframes within responsive layout, required if using media file to switch between iframe and overlay image, otherwise you have to do it properly. <a href="@dimensions" target="_blank">Image styles and video dimensions</a> must <a href="@follow" target="_blank">follow the ratio</a>, otherwise your images will be unexpedtedly resized. <a href="@link" target="_blank">Learn more</a>, or leave empty if you care not for aspect ratio, or prefer to DIY, etc.', array(
        '@dimensions' => '//size43.com/jqueryVideoTool.html',
        '@follow'     => '//en.wikipedia.org/wiki/Aspect_ratio_%28image%29',
        '@link'       => '//www.smashingmagazine.com/2014/02/27/making-embedded-content-work-in-responsive-design/',
      )),
      '#states' => array(
        'visible' => array(
          array('select[name*="[media_switch]"]' => array('value' => 'iframe-switch')),
          array('select[name*="[media_switch]"]' => array('value' => '')),
        ),
      ),
    );

    if ($field_entity_type == 'field_collection_item') {
      $elements['media_switch']['#title'] = t('Media overlay switcher');
      $elements['media_switch']['#description'] .= t('<br />Applied to overlay only.');

      $elements['color_field'] = array(
        '#type'        => 'select',
        '#title'       => t('Color field'),
        '#options'     => $color_options,
        '#description' => t('Color text field or <a href="@url" target="_blank">color_field</a> to colorize individual slide.', array('@url' => '//drupal.org/project/color_field')),
      );
    }
  }

  // Optional colorbox integration.
  if ($is_colorbox || $is_photobox) {

    // Re-use the same image style for both boxes.
    $elements['colorbox_style'] = array(
      '#title'        => t('Lightbox image style'),
      '#type'         => 'select',
      '#empty_option' => t('None (original)'),
      '#options'      => $image_styles,
      '#states' => array(
        'visible' => array(
          array('select[name*="[media_switch]"]' => array('value' => 'colorbox-switch')),
          array('select[name*="[media_switch]"]' => array('value' => 'photobox-switch')),
        ),
      ),
    );

    if ($is_colorbox) {
      $elements['media_switch']['#options']['colorbox-switch'] = t('Image to colorbox');
    }

    if ($is_photobox) {
      $elements['media_switch']['#options']['photobox-switch'] = t('Image to photobox');
    }
  }

  // Good old core image field.
  if ($field_entity_type == 'image') {
    unset($elements['media_switch']['#options']['iframe-switch']);
    if (!$is_colorbox) {
      unset($elements['media_switch']['#options']['colorbox-switch']);
    }
    if (!$is_photobox) {
      unset($elements['media_switch']['#options']['photobox-switch']);
    }

    $slide_caption_options = $thumb_captions = array(
      'title_field' => t('Title'),
      'alt_field' => t('Alt'),
    );

    $elements['slide_caption'] = array(
      '#title'       => t('Caption fields'),
      '#type'        => 'checkboxes',
      '#options'     => $slide_caption_options,
      '#description' => t('Captions will attempt to use Alt and Title attributes if enabled.'),
    );

    // If the image field doesn't have the Title field enabled, tell the user.
    if (isset($instance['settings']['title_field'])
      && $instance['settings']['title_field'] == FALSE
      || isset($instance['settings']['alt_field'])
      && $instance['settings']['alt_field'] == FALSE) {

      // Loosen up for Views UI.
      if ($instance['entity_type'] != 'ctools') {
        $elements['slide_caption']['#disabled'] = TRUE;
      }
      $elements['slide_caption']['#description'] = t('You need to <a href="@url" target="_blank">enable both title and alt fields</a> to use them as caption.', array(
        '@url' => url('admin/structure/types/manage/' . $instance['bundle'] . '/fields/' . $instance['field_name'],
            array(
              'fragment' => 'edit-instance-settings-title-field',
              'query' => array(
                'destination' => 'admin/structure/types/manage/' . $instance['bundle'] . '/display',
              ),
            )
          ),
      ));
    }
  }

  if ($thumb_captions) {
    $elements['thumbnail_caption']['#options'] = $thumb_captions;
    $elements['thumbnail_caption']['#access'] = TRUE;
  }

  $elements['mousewheel'] = array(
    '#type'        => 'checkbox',
    '#title'       => t('Mousewheel'),
    '#description' => t('Be sure to download the <a href="@url" target="_blank">mousewheel</a> library, and it is available at <em>sites/.../libraries/mousewheel/jquery.mousewheel.min.js</em>.', array('@url' => '//github.com/brandonaaron/jquery-mousewheel')),
  );

  // Picture module integration.
  if ($is_picture) {
    $elements['media_switch']['#description'] .= t('<br />Ignored if Picture mapping is enabled.');

    $elements['picture'] = array(
      '#type'        => 'checkbox',
      '#title'       => t('Picture mapping'),
      '#description' => t('Picture mapping is only reasonable for large images. Note: The Slick lazyLoad and Media switchers are not supported with picture-enabled images. Slick only accommodates Picture to get in. The image formatting is taken over by Picture.'),
    );

    $picture_options = picture_get_mapping_options();
    $elements['picture_style'] = array(
      '#title'  => t('Picture group'),
      '#states' => array(
        'visible' => array(
          ':input[name*="[picture]"]' => array('checked' => TRUE),
        ),
      ),
    );

    if (!empty($picture_options)) {
      $elements['picture_style'] += array(
        '#type'        => 'select',
        '#description' => t('Picture mapping for the main stage image.'),
        '#options'     => $picture_options,
      );
    }
    else {
      $elements['picture_style'] += array(
        '#type'   => 'item',
        '#markup' => t('<a href="@url" target="_blank">No picture mappings</a> defined.', array('@url' => url('admin/config/media/picture'))),
      );
    }

    $elements['picture_fallback'] = array(
      '#title'        => t('Fallback image style'),
      '#type'         => 'select',
      '#empty_option' => t('Automatic'),
      '#options'      => $image_styles,
      '#states' => array(
        'visible' => array(
          ':input[name*="[picture]"]' => array('checked' => TRUE),
        ),
      ),
    );
  }

  $elements['markup'] = array(
    '#type'        => 'checkbox',
    '#title'       => t('Keep field markups'),
    '#description' => t('Uncheck to clean up caption field markups, otherwise deep markups kept -- .field > .field-items > .field-item. Check only if you need renderable array at Views, e.g. for custom work with collages containing slick instances with your own advanced lazyLoad with recipe -- "Use field template" disabled and this option enabled, otherwise Views flattens/renders the array.'),
  );

  slick_get_elements($elements, $settings, $form_state);
  $elements['current_view_mode'] = array(
    '#type' => 'hidden',
    '#default_value' => $view_mode,
  );

  $elements['closing'] = array(
    '#markup' => '</div>',
    '#weight' => 100,
  );

  slick_get_admin_assets($elements, $settings);
  return $elements;
}
