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
  $elements       = $options = array();
  $layout_builtin = slick_layouts();
  $optionsets     = slick_optionset_options();
  $readme         = url($slick_path . '/README.txt');
  $image_styles   = image_style_options(FALSE, PASS_THROUGH);
  $is_views_ui    = '';

  $field_entity_type       = $field_type;
  $options['layouts']      = $layout_builtin;
  $options['field_type']   = $field_type;
  $options['box_captions'] = TRUE;

  switch ($field_type) {
    case 'file':
      $title_fields  = array('link_field', 'text_textfield', 'text_textarea');
      $field_layouts = slick_get_media_fields($instance, array('options_select'));
      $link_fields   = array('text_textfield', 'link_field', 'url_external');

      $options['fieldable']      = TRUE;
      $options['entity_type']    = 'file';
      $options['layouts']        = $field_layouts ? $field_layouts : $options['layouts'];
      $options['classes']        = slick_get_media_fields($instance, array('options_select', 'text_textfield'));
      $options['titles']         = slick_get_media_fields($instance, $title_fields);
      $options['links']          = slick_get_media_fields($instance, $link_fields);
      $options['thumb_captions'] = slick_get_media_fields($instance, array('text_textfield', 'text_textarea'));
      $options['captions']       = slick_get_media_fields($instance);
      $options['overlays']       = slick_get_media_fields($instance, array('text_textfield'));
      break;

    // This should go as a separate module, but alas.
    case 'field_collection':
      $field_entity_type = 'field_collection_item';
      $overlay_fields    = array('image', 'file', 'atom_reference');
      $title_fields      = array('link_field', 'text', 'text_long');
      $link_fields       = array('text', 'link_field', 'url');
      $field_layouts     = slick_get_fc_fields($instance, array('list_text'));

      $options['fieldable']      = TRUE;
      $options['entity_type']    = $field_entity_type;
      $options['images']         = slick_get_fc_fields($instance, array('image', 'file'));
      $options['layouts']        = $field_layouts ? $field_layouts : $options['layouts'];
      $options['colors']         = slick_get_fc_fields($instance, array('text', 'color_field_rgb'));
      $options['overlays']       = slick_get_fc_fields($instance, $overlay_fields);
      $options['titles']         = slick_get_fc_fields($instance, $title_fields);
      $options['links']          = slick_get_fc_fields($instance, $link_fields);
      $options['thumb_captions'] = slick_get_fc_fields($instance, array('text', 'text_long'));
      $options['captions']       = slick_get_fc_fields($instance, array(
        'blockreference',
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

    case 'paragraphs':
      $bundles           = $field['bundles'];
      $field_entity_type = 'paragraphs_item';
      $overlay_fields    = array('image', 'file');
      $title_fields      = array('link_field', 'text', 'text_long');
      $link_fields       = array('text', 'link_field', 'url');
      $field_layouts     = slick_get_paragraphs_fields($instance, $bundles, array('list_text'));

      $options['fieldable']      = TRUE;
      $options['entity_type']    = $field_entity_type;
      $options['images']         = slick_get_paragraphs_fields($instance, $bundles, array('image', 'file'));
      $options['layouts']        = $field_layouts ? $field_layouts : $options['layouts'];
      $options['colors']         = slick_get_paragraphs_fields($instance, $bundles, array('text', 'color_field_rgb'));
      $options['overlays']       = slick_get_paragraphs_fields($instance, $bundles, $overlay_fields);
      $options['titles']         = slick_get_paragraphs_fields($instance, $bundles, $title_fields);
      $options['links']          = slick_get_paragraphs_fields($instance, $bundles, $link_fields);
      $options['thumb_captions'] = slick_get_paragraphs_fields($instance, $bundles, array('text', 'text_long'));
      $options['captions']       = slick_get_paragraphs_fields($instance, $bundles, array(
        'blockreference',
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

    case 'image':
      $captions = array(
        'title_field' => t('Title'),
        'alt_field'   => t('Alt'),
      );

      // @todo re-check.
      $options['entity_type'] = $instance['entity_type'] == 'ctools' ? 'node' : $instance['entity_type'];
      $options['captions']    = $options['thumb_captions'] = $captions;
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

  // The top form elements.
  slick_get_top_elements($elements, $settings, $form_state);

  // Only applied to fields.
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

  $elements['thumbnail_effect'] = array(
    '#title'       => t('Thumbnail effect'),
    '#type'        => 'select',
    '#options'     => array(
      'hover' => t('Hoverable'),
      'grid'  => t('Static grid'),
    ),
    '#description' => t('Dependent on a Skin, Dots and Thumbnail style options. <ol><li><strong>Hoverable</strong>: Dots pager are kept, and thumbnail will be hidden and only visible on dot mouseover, default to min-width 120px.</li><li><strong>Static grid</strong>: Dots are hidden, and thumbnails are displayed as a static grid acting like dots pager.</li></ol>Alternative to asNavFor aka separate thumbnails as slider.'),
    '#states' => array(
      'invisible' => array(
        'select[name*="[thumbnail_style]"]' => array('value' => ''),
      ),
    ),
  );

  // The fieldable form elements.
  slick_get_fieldable_elements($elements, $settings, $options);

  $elements['thumbnail_caption']['#states'] = array(
    'invisible' => array(
      'select[name*="[optionset_thumbnail]"]' => array('value' => ''),
    ),
  );

  if ($field_entity_type == 'field_collection_item') {
    $elements['color_field'] = array(
      '#type'        => 'select',
      '#title'       => t('Color field'),
      '#options'     => $options['colors'],
      '#description' => t('Color text field or <a href="@url" target="_blank">color_field</a> to colorize individual slide.', array('@url' => '//drupal.org/project/color_field')),
    );
  }

  // Build the media switch form elements.
  slick_get_media_switch_elements($elements, $settings, $options);

  $elements['background'] = array(
    '#type'        => 'checkbox',
    '#title'       => t('Use CSS background'),
    '#description' => t('Check this to turn the image into CSS background instead. This opens up the goodness of CSS, such as background cover, fixed attachment, etc. Works best with a single visible slide, skins full width/screen. <br /><strong>Important!</strong> Requires a consistent Aspect ratio, otherwise collapsed containers. Unless a min-height is added manually to <strong>.media--background</strong> selector. Not compatible with Picture, of course.'),
    '#weight'        => 70,
  );

  $elements['markup'] = array(
    '#type'        => 'checkbox',
    '#title'       => t('Keep field markups'),
    '#description' => t('Uncheck to clean up caption field markups, otherwise deep markups kept -- .field > .field-items > .field-item. Check only if you need renderable array at Views, e.g. for custom work with collages containing slick instances with your own advanced lazyLoad with recipe -- "Use field template" disabled and this option enabled, otherwise Views flattens/renders the array.'),
    '#weight'        => 71,
  );

  // Media or FC.
  if (in_array($field_entity_type, array('field_collection_item', 'file'))) {
    $elements['slide_layout']['#prefix'] = '<h3 class="form--slick__title">' . t('Fields') . '</h3>';

    $view_mode_options = slick_get_view_modes($field_entity_type, TRUE);
    $elements['view_mode'] = array(
      '#type'        => 'select',
      '#title'       => t('View mode'),
      '#options'     => $view_mode_options,
      '#description' => t('Required to grab the fields. Be sure the "View mode" is enabled, and the enabled fields here are not hidden there. Create view modes using hook_entity_info_alter, or <a href="@url" target="_blank">entity_view_mode</a>.', array('@url' => '//drupal.org/project/entity_view_mode')),
      '#access'      => count($view_mode_options) > 1,
      '#weight'      => 68,
    );

    // Media overlay.
    $elements['slide_overlay']['#title'] = t('Overlay video');
    $elements['slide_overlay']['#description'] = t("Choose the plain text field containing Youtube or Vimeo url to display video overlay over the main image background. Provided as currently file entity media browser doesn't support nested files. Be sure the parent file type is image, not video.");

    $elements['slide_caption']['#description'] = t('Enable any of the following fields as slide caption. These fields are treated and wrapped as captions. Be sure to make them visible at their relevant Manage display.');

    // Layout fields to make individual slide more variant.
    $elements['slide_layout']['#description'] = t('Create a dedicated List (text - max number 1) field related to the caption placement with the following supported keys: top, right, bottom, left, center, center-top, etc. See <a href="@url" target="_blank">README</a> under "Slide layout" for more info. Split half requires any skin Split. Leave empty to DIY.', array('@url' => url($path . '/README.txt')));

    // Media or FC.
    if ($field_entity_type == 'file') {
      $elements['slide_classes']['#description'] = t('If provided, individual slide will have this class, e.g.: to have different background with transparent images and skin Split, or Slick filtering. Be sure to have a Key, Label or Plain text under Formatter without links accordingly. Supported fields: List, Text.');
      $elements['view_mode']['#description'] .= '<br />' . t('For video, make sure to choose relevant video display, not as image.');
    }
    elseif ($field_entity_type == 'field_collection_item') {
      // Complex slide layout is provided by FC alone.
      // Skip media file field as it is the main/ background media already.
      $elements['media_switch']['#title'] = t('Media overlay switcher');
      $elements['media_switch']['#description'] .= t('<br />Applied to overlay only.');

      $elements['slide_caption']['#description'] .= ' ' . t('And not choose the same field as main/ background image.');
      // Field collection overlay.
      $elements['slide_overlay']['#title'] = t('Overlay image/video');
      $elements['slide_overlay']['#description'] = t('Overlays can be single image/auvio/video, or nested slicks. If audio/video, be sure the display is not image. Manage its display at its own entity View mode (there). Two ways to build nested slicks: <ol><li>Make this field use Slick formatter there, and leave <strong>Enable nested slicks</strong> unchecked.</li><li>Or check <strong>Enable nested slicks</strong> here and be sure to use Image or Rendered file formatter (not Slick) there for the supported fields: Image, Media, Atom reference.</li></ol>');

      $elements['slide_image']['#description'] = t('Main background image field');

      // Field collection nested slicks, slicks within a slick.
      $elements['nested_slick'] = array(
        '#title'       => t('Enable nested slicks'),
        '#type'        => 'checkbox',
        '#description' => t('If checked, multiple overlay items will be rendered as nested slicks, otherwise only the first image/video/audio is displayed. Applied to Image and Rendered file formatters. Alternatively, use the Slick carousel formatter for this particular overlay field at its own View mode display to build similar nested slick, and leave this unchecked.'),
        '#weight'      => 76,
        '#prefix'      => '<h3 class="form--slick__title">' . t('Nested slicks') . '</h3>',
        '#states'      => array(
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
        '#weight'      => 77,
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
        '#weight'      => 78,
        '#states' => array(
          'invisible' => array(
            array('select[name*="[slide_overlay]"]' => array('value' => '')),
            array(':input[name*="[nested_slick]"]' => array('checked' => FALSE)),
          ),
        ),
      );
    }

    if (empty($options['captions'])) {
      $elements['slide_caption']['#description'] = t('No fields found for the captions. You need to add relevant fields for the captions.');
    }
  }

  // Good old core image field.
  if ($field_entity_type == 'image') {
    $elements['slide_layout']['#prefix'] = '';
    unset($elements['media_switch']['#options']['iframe-switch']);
    if (!$is_colorbox) {
      unset($elements['media_switch']['#options']['colorbox-switch']);
    }
    if (!$is_photobox) {
      unset($elements['media_switch']['#options']['photobox-switch']);
    }

    $elements['slide_layout']['#description'] = t('This affects the entire slides. Split half requires any skin Split. Leave empty to DIY.');

    $elements['slide_caption']['#description'] = t('Captions will attempt to use Alt and Title attributes if enabled.');

    // If the image field doesn't have the Title field enabled, tell the user.
    if (isset($instance['settings']['title_field'])
      && $instance['settings']['title_field'] == FALSE
      || isset($instance['settings']['alt_field'])
      && $instance['settings']['alt_field'] == FALSE) {

      // Loosen up for Views UI.
      if ($instance['entity_type'] != 'ctools') {
        $elements['slide_caption']['#disabled'] = TRUE;
      }

      $bundle_path = _slick_fields_get_bundle_path($instance);

      $elements['slide_caption']['#description'] = t('You need to <a href="@url" target="_blank">enable both title and alt fields</a> to use them as caption.', array(
        '@url' => url($bundle_path['field'],
          array(
            'fragment' => 'edit-instance-settings-alt-field',
            'query' => array(
              'destination' => $bundle_path['display'],
            ),
          )
        ),
      ));
    }
  }

  $elements['slide_caption']['#weight'] = 79;

  // Picture module integration.
  if ($is_picture) {
    $elements['picture'] = array(
      '#type'        => 'checkbox',
      '#title'       => t('Picture mapping'),
      '#description' => t('Picture mapping is only reasonable for large images. Note: The Slick aspect ratio, and lazyLoad are not supported with picture-enabled images. Slick only accommodates Picture to get in. The image formatting is taken over by Picture.'),
      '#weight'      => 80,
    );

    $picture_options = picture_get_mapping_options();
    $elements['picture_style'] = array(
      '#title'  => t('Picture group'),
      '#states' => array(
        'visible' => array(
          ':input[name*="[picture]"]' => array('checked' => TRUE),
        ),
      ),
      '#weight' => 81,
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
      '#weight'       => 82,
    );
  }

  // Build the rest of form elements.
  slick_get_elements($elements, $settings, $form_state);

  $elements['current_view_mode'] = array(
    '#type'          => 'hidden',
    '#default_value' => $view_mode,
    '#weight'        => 99,
  );

  $elements['closing'] = array(
    '#markup' => '</div>',
    '#weight' => 100,
  );

  slick_get_admin_assets($elements, $settings);
  return $elements;
}

/**
 * Helper function for getting correct bundle for manage field/display path.
 */
function _slick_fields_get_bundle_path($instance) {
  $path = array();

  switch ($instance['entity_type']) {
    case 'bean':
      $path['field'] = 'admin/structure/block-types/manage/' . $instance['bundle'] . '/fields/' . $instance['field_name'];
      $path['display'] = 'admin/structure/block-types/manage/' . $instance['bundle'] . '/display';
      break;

    case 'taxonomy_term':
      $path['field'] = 'admin/structure/taxonomy/' . $instance['bundle'] . '/fields/' . $instance['field_name'];
      $path['display'] = 'admin/structure/taxonomy/' . $instance['bundle'] . '/display';
      break;

    default:
      $path['field'] = 'admin/structure/types/manage/' . $instance['bundle'] . '/fields/' . $instance['field_name'];
      $path['display'] = 'admin/structure/types/manage/' . $instance['bundle'] . '/display';
      break;
  }

  return $path;
}
