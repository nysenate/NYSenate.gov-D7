<?php

/**
 * @file
 * nys_files.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function nys_files_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['document__default__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__file_field_slick';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'default',
  );
  $export['document__default__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__default__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__default__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['document__default__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__media_link__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['document__media_link__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__media_link__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__media_link__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__media_link__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__file_field_slick';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'media_link',
  );
  $export['document__media_link__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['document__media_link__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__media_link__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_link__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['document__media_link__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['document__media_original__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__file_field_slick';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'media_original',
  );
  $export['document__media_original__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['document__media_original__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__media_original__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__media_original__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['document__media_original__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['document__preview__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__file_field_slick';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'preview',
  );
  $export['document__preview__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['document__preview__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['document__preview__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['document__teaser__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__teaser__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__teaser__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__teaser__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__file_field_slick';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'teaser',
  );
  $export['document__teaser__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__teaser__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__teaser__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['document__teaser__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__wysiwyg__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['document__wysiwyg__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__wysiwyg__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['document__wysiwyg__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__wysiwyg__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__file_field_slick';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'wysiwyg',
  );
  $export['document__wysiwyg__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__media_oembed';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['document__wysiwyg__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__media_oembed_thumbnail';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['document__wysiwyg__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__wysiwyg__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['document__wysiwyg__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['home_page_hero__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['home_page_hero__default__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['home_page_hero__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['home_page_hero__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
    'image_link' => '',
  );
  $export['home_page_hero__default__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['home_page_hero__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_picture';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'picture_mapping' => 'hero_1346x330',
    'fallback_image_style' => '',
    'lazyload' => 0,
    'lazyload_aspect_ratio' => 0,
    'image_link' => '',
  );
  $export['home_page_hero__default__file_field_picture'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_picture_sizes_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'sizes' => '(min-width: 0px)',
    'image_styles' => array(
      '_empty image_' => '_empty image_',
      'thumbnail' => 0,
      'medium' => 0,
      'large' => 0,
      'media_thumbnail' => 0,
      '1346x330' => 0,
      '60x60' => 0,
      '45x45' => 0,
      '160x160_phone' => 0,
      '160x160_phone_retina' => 0,
      '160x160_phone_webp' => 0,
      '160x160_phone_webp_retina' => 0,
      '400x240_phone' => 0,
      '400x240_phone_retina' => 0,
      '400x240_phone_webp' => 0,
      '400x240_phone_webp_retina' => 0,
      '400x240_smartphone' => 0,
      '400x240_smartphone_retina' => 0,
      '400x240_smartphone_webp' => 0,
      '400x240_smartphone_webp_retina' => 0,
      '45x45_phone' => 0,
      '45x45_phone_retina' => 0,
      '45x45_phone_webp' => 0,
      '45x45_phone_webp_retina' => 0,
      '60x60_phone' => 0,
      '60x60_phone_retina' => 0,
      '60x60_phone_webp' => 0,
      '60x60_phone_webp_retina' => 0,
      '760x' => 0,
      'base' => 0,
      'embed_landscape' => 0,
      'embed_landscape_smartphone' => 0,
      'embed_landscape_smartphone_retina' => 0,
      'embed_landscape_smartphone_webp' => 0,
      'embed_landscape_smartphone_webp_retina' => 0,
      'embed_portrait' => 0,
      'embed_portrait_smartphone' => 0,
      'embed_portrait_smartphone_retina' => 0,
      'embed_portrait_smartphone_webp' => 0,
      'embed_portrait_smartphone_webp_retina' => 0,
      'embed_signature' => 0,
      'embed_signature_smartphone' => 0,
      'embed_signature_smartphone_retina' => 0,
      'embed_signature_smartphone_webp' => 0,
      'embed_signature_smartphone_webp_retina' => 0,
      'embed_square' => 0,
      'embed_square_smartphone' => 0,
      'embed_square_smartphone_retina' => 0,
      'embed_square_smartphone_webp' => 0,
      'embed_square_smartphone_webp_retina' => 0,
      'hero_1346x330_desktop' => 0,
      'hero_1346x330_desktop_retina' => 0,
      'hero_1346x330_desktop_webp' => 0,
      'hero_1346x330_desktop_webp_retina' => 0,
      'hero_1346x330_phone' => 0,
      'hero_1346x330_phone_retina' => 0,
      'hero_1346x330_phone_webp' => 0,
      'hero_1346x330_phone_webp_retina' => 0,
      'hero_1346x330_small_tablet' => 0,
      'hero_1346x330_small_tablet_retina' => 0,
      'hero_1346x330_small_tablet_webp' => 0,
      'hero_1346x330_small_tablet_webp_retina' => 0,
      'hero_1346x330_smartphone' => 0,
      'hero_1346x330_smartphone_retina' => 0,
      'hero_1346x330_smartphone_webp' => 0,
      'hero_1346x330_smartphone_webp_retina' => 0,
      'hero_1346x330_tablet' => 0,
      'hero_1346x330_tablet_retina' => 0,
      'hero_1346x330_tablet_webp' => 0,
      'hero_1346x330_tablet_webp_retina' => 0,
      'hero_1346x330_wide' => 0,
      'hero_1346x330_wide_retina' => 0,
      'hero_1346x330_wide_webp' => 0,
      'hero_1346x330_wide_webp_retina' => 0,
      'hero_680x510_phone' => 0,
      'hero_680x510_phone_retina' => 0,
      'hero_680x510_phone_webp' => 0,
      'hero_680x510_phone_webp_retina' => 0,
      'hero_680x510_small_tablet' => 0,
      'hero_680x510_small_tablet_retina' => 0,
      'hero_680x510_small_tablet_webp' => 0,
      'hero_680x510_small_tablet_webp_retina' => 0,
      'hero_680x510_smartphone' => 0,
      'hero_680x510_smartphone_retina' => 0,
      'hero_680x510_smartphone_webp' => 0,
      'hero_680x510_smartphone_webp_retina' => 0,
      'main_1280x510_desktop' => 0,
      'main_1280x510_desktop_retina' => 0,
      'main_1280x510_desktop_webp' => 0,
      'main_1280x510_desktop_webp_retina' => 0,
      'main_1280x510_phone' => 0,
      'main_1280x510_phone_retina' => 0,
      'main_1280x510_phone_webp' => 0,
      'main_1280x510_phone_webp_retina' => 0,
      'main_1280x510_small_tablet' => 0,
      'main_1280x510_small_tablet_retina' => 0,
      'main_1280x510_small_tablet_webp' => 0,
      'main_1280x510_small_tablet_webp_retina' => 0,
      'main_1280x510_smartphone' => 0,
      'main_1280x510_smartphone_retina' => 0,
      'main_1280x510_smartphone_webp' => 0,
      'main_1280x510_smartphone_webp_retina' => 0,
      'main_1280x510_tablet' => 0,
      'main_1280x510_tablet_retina' => 0,
      'main_1280x510_tablet_webp' => 0,
      'main_1280x510_tablet_webp_retina' => 0,
      'main_1280x510_wide' => 0,
      'main_1280x510_wide_retina' => 0,
      'main_1280x510_wide_webp' => 0,
      'main_1280x510_wide_webp_retina' => 0,
      'main_200x125_phone' => 0,
      'main_200x125_phone_retina' => 0,
      'main_200x125_phone_webp' => 0,
      'main_200x125_phone_webp_retina' => 0,
      'main_280x280_phone' => 0,
      'main_280x280_phone_retina' => 0,
      'main_280x280_phone_webp' => 0,
      'main_280x280_phone_webp_retina' => 0,
      'main_360x200_phone' => 0,
      'main_360x200_phone_retina' => 0,
      'main_360x200_phone_webp' => 0,
      'main_360x200_phone_webp_retina' => 0,
      'main_360x200_smartphone' => 0,
      'main_360x200_smartphone_retina' => 0,
      'main_360x200_smartphone_webp' => 0,
      'main_360x200_smartphone_webp_retina' => 0,
      'main_380x215_phone' => 0,
      'main_380x215_phone_retina' => 0,
      'main_380x215_phone_webp' => 0,
      'main_380x215_phone_webp_retina' => 0,
      'main_380x215_smartphone' => 0,
      'main_380x215_smartphone_retina' => 0,
      'main_380x215_smartphone_webp' => 0,
      'main_380x215_smartphone_webp_retina' => 0,
      'main_760x377_phone' => 0,
      'main_760x377_phone_retina' => 0,
      'main_760x377_phone_webp' => 0,
      'main_760x377_phone_webp_retina' => 0,
      'main_760x377_small_tablet' => 0,
      'main_760x377_small_tablet_retina' => 0,
      'main_760x377_small_tablet_webp' => 0,
      'main_760x377_small_tablet_webp_retina' => 0,
      'main_760x377_smartphone' => 0,
      'main_760x377_smartphone_retina' => 0,
      'main_760x377_smartphone_webp' => 0,
      'main_760x377_smartphone_webp_retina' => 0,
      'main_760x_phone' => 0,
      'main_760x_phone_retina' => 0,
      'main_760x_phone_webp' => 0,
      'main_760x_phone_webp_retina' => 0,
      'main_760x_small_tablet' => 0,
      'main_760x_small_tablet_retina' => 0,
      'main_760x_small_tablet_webp' => 0,
      'main_760x_small_tablet_webp_retina' => 0,
      'main_760x_smartphone' => 0,
      'main_760x_smartphone_retina' => 0,
      'main_760x_smartphone_webp' => 0,
      'main_760x_smartphone_webp_retina' => 0,
      '440x230' => 0,
      '80x60' => 0,
      'embed_landscape_400x225' => 0,
      'embed_portrait_225x345' => 0,
      'square_thumbnail' => 0,
      '1280x510' => 0,
      '160x160' => 0,
      '200x125' => 0,
      '280x280' => 0,
      '360x200' => 0,
      '380x215' => 0,
      '400x240' => 0,
      '680x510' => 0,
      '760x377' => 0,
      'retina_100x100' => 0,
      'user_dashboard_100x100' => 0,
      '_original image_' => 0,
    ),
    'fallback_image_style' => 'thumbnail',
    'image_link' => '',
  );
  $export['home_page_hero__default__file_field_picture_sizes_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__file_field_slick';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_effect' => '',
    'slide_layout' => '',
    'slide_title' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'background' => 0,
    'markup' => 0,
    'view_mode' => '',
    'picture' => 0,
    'picture_style' => '',
    'picture_fallback' => '',
    'mousewheel' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'default',
  );
  $export['home_page_hero__default__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__default__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['home_page_hero__default__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_file_default';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['home_page_hero__preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_file_download_link';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['home_page_hero__preview__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_file_table';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['home_page_hero__preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_file_url_plain';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['home_page_hero__preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_image';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'media_thumbnail',
    'image_link' => '',
  );
  $export['home_page_hero__preview__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_media_large_icon';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'media_thumbnail',
  );
  $export['home_page_hero__preview__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_picture';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'picture_mapping' => '160x160',
    'fallback_image_style' => '',
    'lazyload' => 0,
    'lazyload_aspect_ratio' => 0,
    'image_link' => '',
  );
  $export['home_page_hero__preview__file_field_picture'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_picture_sizes_formatter';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'sizes' => '(min-width: 0px)',
    'image_styles' => array(
      '_empty image_' => '_empty image_',
      'thumbnail' => 0,
      'medium' => 0,
      'large' => 0,
      'media_thumbnail' => 0,
      '1346x330' => 0,
      '60x60' => 0,
      '45x45' => 0,
      '160x160_phone' => 0,
      '160x160_phone_retina' => 0,
      '160x160_phone_webp' => 0,
      '160x160_phone_webp_retina' => 0,
      '400x240_phone' => 0,
      '400x240_phone_retina' => 0,
      '400x240_phone_webp' => 0,
      '400x240_phone_webp_retina' => 0,
      '400x240_smartphone' => 0,
      '400x240_smartphone_retina' => 0,
      '400x240_smartphone_webp' => 0,
      '400x240_smartphone_webp_retina' => 0,
      '45x45_phone' => 0,
      '45x45_phone_retina' => 0,
      '45x45_phone_webp' => 0,
      '45x45_phone_webp_retina' => 0,
      '60x60_phone' => 0,
      '60x60_phone_retina' => 0,
      '60x60_phone_webp' => 0,
      '60x60_phone_webp_retina' => 0,
      '760x' => 0,
      'base' => 0,
      'embed_landscape' => 0,
      'embed_landscape_smartphone' => 0,
      'embed_landscape_smartphone_retina' => 0,
      'embed_landscape_smartphone_webp' => 0,
      'embed_landscape_smartphone_webp_retina' => 0,
      'embed_portrait' => 0,
      'embed_portrait_smartphone' => 0,
      'embed_portrait_smartphone_retina' => 0,
      'embed_portrait_smartphone_webp' => 0,
      'embed_portrait_smartphone_webp_retina' => 0,
      'embed_signature' => 0,
      'embed_signature_smartphone' => 0,
      'embed_signature_smartphone_retina' => 0,
      'embed_signature_smartphone_webp' => 0,
      'embed_signature_smartphone_webp_retina' => 0,
      'embed_square' => 0,
      'embed_square_smartphone' => 0,
      'embed_square_smartphone_retina' => 0,
      'embed_square_smartphone_webp' => 0,
      'embed_square_smartphone_webp_retina' => 0,
      'hero_1346x330_desktop' => 0,
      'hero_1346x330_desktop_retina' => 0,
      'hero_1346x330_desktop_webp' => 0,
      'hero_1346x330_desktop_webp_retina' => 0,
      'hero_1346x330_phone' => 0,
      'hero_1346x330_phone_retina' => 0,
      'hero_1346x330_phone_webp' => 0,
      'hero_1346x330_phone_webp_retina' => 0,
      'hero_1346x330_small_tablet' => 0,
      'hero_1346x330_small_tablet_retina' => 0,
      'hero_1346x330_small_tablet_webp' => 0,
      'hero_1346x330_small_tablet_webp_retina' => 0,
      'hero_1346x330_smartphone' => 0,
      'hero_1346x330_smartphone_retina' => 0,
      'hero_1346x330_smartphone_webp' => 0,
      'hero_1346x330_smartphone_webp_retina' => 0,
      'hero_1346x330_tablet' => 0,
      'hero_1346x330_tablet_retina' => 0,
      'hero_1346x330_tablet_webp' => 0,
      'hero_1346x330_tablet_webp_retina' => 0,
      'hero_1346x330_wide' => 0,
      'hero_1346x330_wide_retina' => 0,
      'hero_1346x330_wide_webp' => 0,
      'hero_1346x330_wide_webp_retina' => 0,
      'hero_680x510_phone' => 0,
      'hero_680x510_phone_retina' => 0,
      'hero_680x510_phone_webp' => 0,
      'hero_680x510_phone_webp_retina' => 0,
      'hero_680x510_small_tablet' => 0,
      'hero_680x510_small_tablet_retina' => 0,
      'hero_680x510_small_tablet_webp' => 0,
      'hero_680x510_small_tablet_webp_retina' => 0,
      'hero_680x510_smartphone' => 0,
      'hero_680x510_smartphone_retina' => 0,
      'hero_680x510_smartphone_webp' => 0,
      'hero_680x510_smartphone_webp_retina' => 0,
      'main_1280x510_desktop' => 0,
      'main_1280x510_desktop_retina' => 0,
      'main_1280x510_desktop_webp' => 0,
      'main_1280x510_desktop_webp_retina' => 0,
      'main_1280x510_phone' => 0,
      'main_1280x510_phone_retina' => 0,
      'main_1280x510_phone_webp' => 0,
      'main_1280x510_phone_webp_retina' => 0,
      'main_1280x510_small_tablet' => 0,
      'main_1280x510_small_tablet_retina' => 0,
      'main_1280x510_small_tablet_webp' => 0,
      'main_1280x510_small_tablet_webp_retina' => 0,
      'main_1280x510_smartphone' => 0,
      'main_1280x510_smartphone_retina' => 0,
      'main_1280x510_smartphone_webp' => 0,
      'main_1280x510_smartphone_webp_retina' => 0,
      'main_1280x510_tablet' => 0,
      'main_1280x510_tablet_retina' => 0,
      'main_1280x510_tablet_webp' => 0,
      'main_1280x510_tablet_webp_retina' => 0,
      'main_1280x510_wide' => 0,
      'main_1280x510_wide_retina' => 0,
      'main_1280x510_wide_webp' => 0,
      'main_1280x510_wide_webp_retina' => 0,
      'main_200x125_phone' => 0,
      'main_200x125_phone_retina' => 0,
      'main_200x125_phone_webp' => 0,
      'main_200x125_phone_webp_retina' => 0,
      'main_280x280_phone' => 0,
      'main_280x280_phone_retina' => 0,
      'main_280x280_phone_webp' => 0,
      'main_280x280_phone_webp_retina' => 0,
      'main_360x200_phone' => 0,
      'main_360x200_phone_retina' => 0,
      'main_360x200_phone_webp' => 0,
      'main_360x200_phone_webp_retina' => 0,
      'main_360x200_smartphone' => 0,
      'main_360x200_smartphone_retina' => 0,
      'main_360x200_smartphone_webp' => 0,
      'main_360x200_smartphone_webp_retina' => 0,
      'main_380x215_phone' => 0,
      'main_380x215_phone_retina' => 0,
      'main_380x215_phone_webp' => 0,
      'main_380x215_phone_webp_retina' => 0,
      'main_380x215_smartphone' => 0,
      'main_380x215_smartphone_retina' => 0,
      'main_380x215_smartphone_webp' => 0,
      'main_380x215_smartphone_webp_retina' => 0,
      'main_760x377_phone' => 0,
      'main_760x377_phone_retina' => 0,
      'main_760x377_phone_webp' => 0,
      'main_760x377_phone_webp_retina' => 0,
      'main_760x377_small_tablet' => 0,
      'main_760x377_small_tablet_retina' => 0,
      'main_760x377_small_tablet_webp' => 0,
      'main_760x377_small_tablet_webp_retina' => 0,
      'main_760x377_smartphone' => 0,
      'main_760x377_smartphone_retina' => 0,
      'main_760x377_smartphone_webp' => 0,
      'main_760x377_smartphone_webp_retina' => 0,
      'main_760x_phone' => 0,
      'main_760x_phone_retina' => 0,
      'main_760x_phone_webp' => 0,
      'main_760x_phone_webp_retina' => 0,
      'main_760x_small_tablet' => 0,
      'main_760x_small_tablet_retina' => 0,
      'main_760x_small_tablet_webp' => 0,
      'main_760x_small_tablet_webp_retina' => 0,
      'main_760x_smartphone' => 0,
      'main_760x_smartphone_retina' => 0,
      'main_760x_smartphone_webp' => 0,
      'main_760x_smartphone_webp_retina' => 0,
      '440x230' => 0,
      '80x60' => 0,
      'embed_landscape_400x225' => 0,
      'embed_portrait_225x345' => 0,
      'square_thumbnail' => 0,
      '1280x510' => 0,
      '160x160' => 0,
      '200x125' => 0,
      '280x280' => 0,
      '360x200' => 0,
      '380x215' => 0,
      '400x240' => 0,
      '680x510' => 0,
      '760x377' => 0,
      'retina_100x100' => 0,
      'user_dashboard_100x100' => 0,
      '_original image_' => 0,
    ),
    'fallback_image_style' => 'thumbnail',
    'image_link' => '',
  );
  $export['home_page_hero__preview__file_field_picture_sizes_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__file_field_slick';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_effect' => '',
    'slide_layout' => '',
    'slide_title' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'background' => 0,
    'markup' => 0,
    'view_mode' => '',
    'picture' => 0,
    'picture_style' => '',
    'picture_fallback' => '',
    'mousewheel' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'preview',
  );
  $export['home_page_hero__preview__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'home_page_hero__preview__media_ustream_video';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['home_page_hero__preview__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__default__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__media_livestream_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__default__media_livestream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__default__media_livestream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '388',
    'autoplay_channel' => 0,
    'autoplay_video' => 0,
    'mute' => 0,
    'layout' => '4',
    'protocol_specify' => 0,
    'protocol' => 'https:',
  );
  $export['image__default__media_livestream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_field_file_default';
  $file_display->weight = -44;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__full__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_field_file_download_link';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__full__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_field_file_table';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__full__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_field_file_url_plain';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__full__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_field_image';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '760x377',
    'image_link' => '',
  );
  $export['image__full__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_field_media_large_icon';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__full__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_image';
  $file_display->weight = 5;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'large',
  );
  $export['image__full__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__media_livestream_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__full__media_livestream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__media_livestream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '388',
    'autoplay_channel' => 0,
    'autoplay_video' => 0,
    'mute' => 0,
    'layout' => '4',
    'protocol_specify' => 0,
    'protocol' => 'https:',
  );
  $export['image__full__media_livestream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_file_default';
  $file_display->weight = -44;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__landscape_inline__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_file_download_link';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__landscape_inline__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_file_table';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__landscape_inline__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_file_url_plain';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__landscape_inline__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_image';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'embed_landscape',
    'image_link' => '',
  );
  $export['image__landscape_inline__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_media_large_icon';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__landscape_inline__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_picture';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'picture_mapping' => 'embed_landscape',
    'fallback_image_style' => 'embed_landscape',
    'lazyload' => 0,
    'lazyload_aspect_ratio' => 0,
    'image_link' => '',
  );
  $export['image__landscape_inline__file_field_picture'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_picture_sizes_formatter';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'sizes' => '(min-width: 0px)',
    'image_styles' => array(
      '_empty image_' => '_empty image_',
      'thumbnail' => 0,
      'medium' => 0,
      'large' => 0,
      'media_thumbnail' => 0,
      '1346x330' => 0,
      '60x60' => 0,
      'embed_landscape' => 0,
      'embed_landscape_smartphone' => 0,
      'embed_landscape_smartphone_retina' => 0,
      'embed_landscape_smartphone_webp' => 0,
      'embed_landscape_smartphone_webp_retina' => 0,
      'embed_portrait' => 0,
      'embed_portrait_smartphone' => 0,
      'embed_portrait_smartphone_retina' => 0,
      'embed_portrait_smartphone_webp' => 0,
      'embed_portrait_smartphone_webp_retina' => 0,
      'embed_signature' => 0,
      'embed_signature_smartphone' => 0,
      'embed_signature_smartphone_retina' => 0,
      'embed_signature_smartphone_webp' => 0,
      'embed_signature_smartphone_webp_retina' => 0,
      'embed_square' => 0,
      'embed_square_smartphone' => 0,
      'embed_square_smartphone_retina' => 0,
      'embed_square_smartphone_webp' => 0,
      'embed_square_smartphone_webp_retina' => 0,
      '45x45' => 0,
      '160x160_phone' => 0,
      '160x160_phone_retina' => 0,
      '160x160_phone_webp' => 0,
      '160x160_phone_webp_retina' => 0,
      '400x240_phone' => 0,
      '400x240_phone_retina' => 0,
      '400x240_phone_webp' => 0,
      '400x240_phone_webp_retina' => 0,
      '400x240_smartphone' => 0,
      '400x240_smartphone_retina' => 0,
      '400x240_smartphone_webp' => 0,
      '400x240_smartphone_webp_retina' => 0,
      'base' => 0,
      'hero_1346x330_desktop' => 0,
      'hero_1346x330_desktop_retina' => 0,
      'hero_1346x330_desktop_webp' => 0,
      'hero_1346x330_desktop_webp_retina' => 0,
      'hero_1346x330_phone' => 0,
      'hero_1346x330_phone_retina' => 0,
      'hero_1346x330_phone_webp' => 0,
      'hero_1346x330_phone_webp_retina' => 0,
      'hero_1346x330_small_tablet' => 0,
      'hero_1346x330_small_tablet_retina' => 0,
      'hero_1346x330_small_tablet_webp' => 0,
      'hero_1346x330_small_tablet_webp_retina' => 0,
      'hero_1346x330_smartphone' => 0,
      'hero_1346x330_smartphone_retina' => 0,
      'hero_1346x330_smartphone_webp' => 0,
      'hero_1346x330_smartphone_webp_retina' => 0,
      'hero_1346x330_tablet' => 0,
      'hero_1346x330_tablet_retina' => 0,
      'hero_1346x330_tablet_webp' => 0,
      'hero_1346x330_tablet_webp_retina' => 0,
      'hero_1346x330_wide' => 0,
      'hero_1346x330_wide_retina' => 0,
      'hero_1346x330_wide_webp' => 0,
      'hero_1346x330_wide_webp_retina' => 0,
      'main_1280x510_desktop' => 0,
      'main_1280x510_desktop_retina' => 0,
      'main_1280x510_desktop_webp' => 0,
      'main_1280x510_desktop_webp_retina' => 0,
      'main_1280x510_phone' => 0,
      'main_1280x510_phone_retina' => 0,
      'main_1280x510_phone_webp' => 0,
      'main_1280x510_phone_webp_retina' => 0,
      'main_1280x510_small_tablet' => 0,
      'main_1280x510_small_tablet_retina' => 0,
      'main_1280x510_small_tablet_webp' => 0,
      'main_1280x510_small_tablet_webp_retina' => 0,
      'main_1280x510_smartphone' => 0,
      'main_1280x510_smartphone_retina' => 0,
      'main_1280x510_smartphone_webp' => 0,
      'main_1280x510_smartphone_webp_retina' => 0,
      'main_1280x510_tablet' => 0,
      'main_1280x510_tablet_retina' => 0,
      'main_1280x510_tablet_webp' => 0,
      'main_1280x510_tablet_webp_retina' => 0,
      'main_1280x510_wide' => 0,
      'main_1280x510_wide_retina' => 0,
      'main_1280x510_wide_webp' => 0,
      'main_1280x510_wide_webp_retina' => 0,
      'main_200x125_phone' => 0,
      'main_200x125_phone_retina' => 0,
      'main_200x125_phone_webp' => 0,
      'main_200x125_phone_webp_retina' => 0,
      'main_280x280_phone' => 0,
      'main_280x280_phone_retina' => 0,
      'main_280x280_phone_webp' => 0,
      'main_280x280_phone_webp_retina' => 0,
      'main_360x200_phone' => 0,
      'main_360x200_phone_retina' => 0,
      'main_360x200_phone_webp' => 0,
      'main_360x200_phone_webp_retina' => 0,
      'main_360x200_smartphone' => 0,
      'main_360x200_smartphone_retina' => 0,
      'main_360x200_smartphone_webp' => 0,
      'main_360x200_smartphone_webp_retina' => 0,
      'main_380x215_phone' => 0,
      'main_380x215_phone_retina' => 0,
      'main_380x215_phone_webp' => 0,
      'main_380x215_phone_webp_retina' => 0,
      'main_380x215_smartphone' => 0,
      'main_380x215_smartphone_retina' => 0,
      'main_380x215_smartphone_webp' => 0,
      'main_380x215_smartphone_webp_retina' => 0,
      'main_760x377_phone' => 0,
      'main_760x377_phone_retina' => 0,
      'main_760x377_phone_webp' => 0,
      'main_760x377_phone_webp_retina' => 0,
      'main_760x377_small_tablet' => 0,
      'main_760x377_small_tablet_retina' => 0,
      'main_760x377_small_tablet_webp' => 0,
      'main_760x377_small_tablet_webp_retina' => 0,
      'main_760x377_smartphone' => 0,
      'main_760x377_smartphone_retina' => 0,
      'main_760x377_smartphone_webp' => 0,
      'main_760x377_smartphone_webp_retina' => 0,
      '440x230' => 0,
      '80x60' => 0,
      'embed_landscape_400x225' => 0,
      'embed_portrait_225x345' => 0,
      'square_thumbnail' => 0,
      '1280x510' => 0,
      '160x160' => 0,
      '200x125' => 0,
      '280x280' => 0,
      '360x200' => 0,
      '380x215' => 0,
      '400x240' => 0,
      '680x510' => 0,
      '760x377' => 0,
      'retina_100x100' => 0,
      'user_dashboard_100x100' => 0,
      'thumbnail_retina' => 0,
      'medium_retina' => 0,
      'large_retina' => 0,
      '_original image_' => 0,
    ),
    'fallback_image_style' => 'thumbnail',
    'image_link' => '',
  );
  $export['image__landscape_inline__file_field_picture_sizes_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__file_field_slick';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'picture' => 0,
    'picture_style' => '',
    'picture_fallback' => '',
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'landscape_inline',
  );
  $export['image__landscape_inline__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__media_oembed';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['image__landscape_inline__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__media_oembed_thumbnail';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__landscape_inline__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__landscape_inline__media_ustream_video';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['image__landscape_inline__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_landscape_image__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_landscape_image__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_landscape_image__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__media_landscape_image__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_landscape_image__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_landscape_image__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_landscape_image__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_landscape_image__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_landscape_image__file_field_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'embed_landscape_400x225',
    'image_link' => '',
  );
  $export['image__media_landscape_image__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_landscape_image__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_landscape_image__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_landscape_image__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['image__media_landscape_image__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_original__file_image';
  $file_display->weight = 5;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__media_original__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_portrait_image__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_portrait_image__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_portrait_image__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__media_portrait_image__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_portrait_image__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_portrait_image__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_portrait_image__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_portrait_image__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_portrait_image__file_field_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'embed_portrait_225x345',
    'image_link' => '',
  );
  $export['image__media_portrait_image__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_portrait_image__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_portrait_image__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_portrait_image__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['image__media_portrait_image__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_file_default';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__media_signature__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_file_download_link';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__media_signature__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_file_table';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_signature__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_file_url_plain';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__media_signature__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_image';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'embed_signature',
    'image_link' => '',
  );
  $export['image__media_signature__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_media_large_icon';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__media_signature__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_picture';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'picture_mapping' => 'embed_signature',
    'fallback_image_style' => 'embed_signature',
    'lazyload' => 0,
    'lazyload_aspect_ratio' => 0,
    'image_link' => '',
  );
  $export['image__media_signature__file_field_picture'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_picture_sizes_formatter';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'sizes' => '(min-width: 0px)',
    'image_styles' => array(
      '_empty image_' => '_empty image_',
      'thumbnail' => 0,
      'medium' => 0,
      'large' => 0,
      'media_thumbnail' => 0,
      '1346x330' => 0,
      '60x60' => 0,
      'embed_landscape' => 0,
      'embed_landscape_smartphone' => 0,
      'embed_landscape_smartphone_retina' => 0,
      'embed_landscape_smartphone_webp' => 0,
      'embed_landscape_smartphone_webp_retina' => 0,
      'embed_portrait' => 0,
      'embed_portrait_smartphone' => 0,
      'embed_portrait_smartphone_retina' => 0,
      'embed_portrait_smartphone_webp' => 0,
      'embed_portrait_smartphone_webp_retina' => 0,
      'embed_signature' => 0,
      'embed_signature_smartphone' => 0,
      'embed_signature_smartphone_retina' => 0,
      'embed_signature_smartphone_webp' => 0,
      'embed_signature_smartphone_webp_retina' => 0,
      'embed_square' => 0,
      'embed_square_smartphone' => 0,
      'embed_square_smartphone_retina' => 0,
      'embed_square_smartphone_webp' => 0,
      'embed_square_smartphone_webp_retina' => 0,
      '45x45' => 0,
      '160x160_phone' => 0,
      '160x160_phone_retina' => 0,
      '160x160_phone_webp' => 0,
      '160x160_phone_webp_retina' => 0,
      '400x240_phone' => 0,
      '400x240_phone_retina' => 0,
      '400x240_phone_webp' => 0,
      '400x240_phone_webp_retina' => 0,
      '400x240_smartphone' => 0,
      '400x240_smartphone_retina' => 0,
      '400x240_smartphone_webp' => 0,
      '400x240_smartphone_webp_retina' => 0,
      'base' => 0,
      'hero_1346x330_desktop' => 0,
      'hero_1346x330_desktop_retina' => 0,
      'hero_1346x330_desktop_webp' => 0,
      'hero_1346x330_desktop_webp_retina' => 0,
      'hero_1346x330_phone' => 0,
      'hero_1346x330_phone_retina' => 0,
      'hero_1346x330_phone_webp' => 0,
      'hero_1346x330_phone_webp_retina' => 0,
      'hero_1346x330_small_tablet' => 0,
      'hero_1346x330_small_tablet_retina' => 0,
      'hero_1346x330_small_tablet_webp' => 0,
      'hero_1346x330_small_tablet_webp_retina' => 0,
      'hero_1346x330_smartphone' => 0,
      'hero_1346x330_smartphone_retina' => 0,
      'hero_1346x330_smartphone_webp' => 0,
      'hero_1346x330_smartphone_webp_retina' => 0,
      'hero_1346x330_tablet' => 0,
      'hero_1346x330_tablet_retina' => 0,
      'hero_1346x330_tablet_webp' => 0,
      'hero_1346x330_tablet_webp_retina' => 0,
      'hero_1346x330_wide' => 0,
      'hero_1346x330_wide_retina' => 0,
      'hero_1346x330_wide_webp' => 0,
      'hero_1346x330_wide_webp_retina' => 0,
      'main_1280x510_desktop' => 0,
      'main_1280x510_desktop_retina' => 0,
      'main_1280x510_desktop_webp' => 0,
      'main_1280x510_desktop_webp_retina' => 0,
      'main_1280x510_phone' => 0,
      'main_1280x510_phone_retina' => 0,
      'main_1280x510_phone_webp' => 0,
      'main_1280x510_phone_webp_retina' => 0,
      'main_1280x510_small_tablet' => 0,
      'main_1280x510_small_tablet_retina' => 0,
      'main_1280x510_small_tablet_webp' => 0,
      'main_1280x510_small_tablet_webp_retina' => 0,
      'main_1280x510_smartphone' => 0,
      'main_1280x510_smartphone_retina' => 0,
      'main_1280x510_smartphone_webp' => 0,
      'main_1280x510_smartphone_webp_retina' => 0,
      'main_1280x510_tablet' => 0,
      'main_1280x510_tablet_retina' => 0,
      'main_1280x510_tablet_webp' => 0,
      'main_1280x510_tablet_webp_retina' => 0,
      'main_1280x510_wide' => 0,
      'main_1280x510_wide_retina' => 0,
      'main_1280x510_wide_webp' => 0,
      'main_1280x510_wide_webp_retina' => 0,
      'main_200x125_phone' => 0,
      'main_200x125_phone_retina' => 0,
      'main_200x125_phone_webp' => 0,
      'main_200x125_phone_webp_retina' => 0,
      'main_280x280_phone' => 0,
      'main_280x280_phone_retina' => 0,
      'main_280x280_phone_webp' => 0,
      'main_280x280_phone_webp_retina' => 0,
      'main_360x200_phone' => 0,
      'main_360x200_phone_retina' => 0,
      'main_360x200_phone_webp' => 0,
      'main_360x200_phone_webp_retina' => 0,
      'main_360x200_smartphone' => 0,
      'main_360x200_smartphone_retina' => 0,
      'main_360x200_smartphone_webp' => 0,
      'main_360x200_smartphone_webp_retina' => 0,
      'main_380x215_phone' => 0,
      'main_380x215_phone_retina' => 0,
      'main_380x215_phone_webp' => 0,
      'main_380x215_phone_webp_retina' => 0,
      'main_380x215_smartphone' => 0,
      'main_380x215_smartphone_retina' => 0,
      'main_380x215_smartphone_webp' => 0,
      'main_380x215_smartphone_webp_retina' => 0,
      'main_760x377_phone' => 0,
      'main_760x377_phone_retina' => 0,
      'main_760x377_phone_webp' => 0,
      'main_760x377_phone_webp_retina' => 0,
      'main_760x377_small_tablet' => 0,
      'main_760x377_small_tablet_retina' => 0,
      'main_760x377_small_tablet_webp' => 0,
      'main_760x377_small_tablet_webp_retina' => 0,
      'main_760x377_smartphone' => 0,
      'main_760x377_smartphone_retina' => 0,
      'main_760x377_smartphone_webp' => 0,
      'main_760x377_smartphone_webp_retina' => 0,
      '440x230' => 0,
      '80x60' => 0,
      'embed_landscape_400x225' => 0,
      'embed_portrait_225x345' => 0,
      'square_thumbnail' => 0,
      '1280x510' => 0,
      '160x160' => 0,
      '200x125' => 0,
      '280x280' => 0,
      '360x200' => 0,
      '380x215' => 0,
      '400x240' => 0,
      '680x510' => 0,
      '760x377' => 0,
      'retina_100x100' => 0,
      'user_dashboard_100x100' => 0,
      'thumbnail_retina' => 0,
      'medium_retina' => 0,
      'large_retina' => 0,
      '_original image_' => 0,
    ),
    'fallback_image_style' => 'thumbnail',
    'image_link' => '',
  );
  $export['image__media_signature__file_field_picture_sizes_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__file_field_slick';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'picture' => 0,
    'picture_style' => '',
    'picture_fallback' => '',
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'media_signature',
  );
  $export['image__media_signature__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__media_oembed';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['image__media_signature__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__media_oembed_thumbnail';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__media_signature__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__media_signature__media_ustream_video';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['image__media_signature__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_file_default';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__portrait_inline__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_file_download_link';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__portrait_inline__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_file_table';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__portrait_inline__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_file_url_plain';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__portrait_inline__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_image';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'embed_portrait',
    'image_link' => '',
  );
  $export['image__portrait_inline__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_media_large_icon';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__portrait_inline__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_picture';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'picture_mapping' => 'embed_portrait',
    'fallback_image_style' => 'embed_portrait',
    'lazyload' => 1,
    'lazyload_aspect_ratio' => 0,
    'image_link' => '',
  );
  $export['image__portrait_inline__file_field_picture'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_picture_sizes_formatter';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'sizes' => '(min-width: 0px)',
    'image_styles' => array(
      '_empty image_' => '_empty image_',
      'thumbnail' => 0,
      'medium' => 0,
      'large' => 0,
      'media_thumbnail' => 0,
      '1346x330' => 0,
      '60x60' => 0,
      'embed_landscape' => 0,
      'embed_landscape_smartphone' => 0,
      'embed_landscape_smartphone_retina' => 0,
      'embed_landscape_smartphone_webp' => 0,
      'embed_landscape_smartphone_webp_retina' => 0,
      'embed_portrait' => 0,
      'embed_portrait_smartphone' => 0,
      'embed_portrait_smartphone_retina' => 0,
      'embed_portrait_smartphone_webp' => 0,
      'embed_portrait_smartphone_webp_retina' => 0,
      'embed_signature' => 0,
      'embed_signature_smartphone' => 0,
      'embed_signature_smartphone_retina' => 0,
      'embed_signature_smartphone_webp' => 0,
      'embed_signature_smartphone_webp_retina' => 0,
      'embed_square' => 0,
      'embed_square_smartphone' => 0,
      'embed_square_smartphone_retina' => 0,
      'embed_square_smartphone_webp' => 0,
      'embed_square_smartphone_webp_retina' => 0,
      '45x45' => 0,
      '160x160_phone' => 0,
      '160x160_phone_retina' => 0,
      '160x160_phone_webp' => 0,
      '160x160_phone_webp_retina' => 0,
      '400x240_phone' => 0,
      '400x240_phone_retina' => 0,
      '400x240_phone_webp' => 0,
      '400x240_phone_webp_retina' => 0,
      '400x240_smartphone' => 0,
      '400x240_smartphone_retina' => 0,
      '400x240_smartphone_webp' => 0,
      '400x240_smartphone_webp_retina' => 0,
      'base' => 0,
      'hero_1346x330_desktop' => 0,
      'hero_1346x330_desktop_retina' => 0,
      'hero_1346x330_desktop_webp' => 0,
      'hero_1346x330_desktop_webp_retina' => 0,
      'hero_1346x330_phone' => 0,
      'hero_1346x330_phone_retina' => 0,
      'hero_1346x330_phone_webp' => 0,
      'hero_1346x330_phone_webp_retina' => 0,
      'hero_1346x330_small_tablet' => 0,
      'hero_1346x330_small_tablet_retina' => 0,
      'hero_1346x330_small_tablet_webp' => 0,
      'hero_1346x330_small_tablet_webp_retina' => 0,
      'hero_1346x330_smartphone' => 0,
      'hero_1346x330_smartphone_retina' => 0,
      'hero_1346x330_smartphone_webp' => 0,
      'hero_1346x330_smartphone_webp_retina' => 0,
      'hero_1346x330_tablet' => 0,
      'hero_1346x330_tablet_retina' => 0,
      'hero_1346x330_tablet_webp' => 0,
      'hero_1346x330_tablet_webp_retina' => 0,
      'hero_1346x330_wide' => 0,
      'hero_1346x330_wide_retina' => 0,
      'hero_1346x330_wide_webp' => 0,
      'hero_1346x330_wide_webp_retina' => 0,
      'main_1280x510_desktop' => 0,
      'main_1280x510_desktop_retina' => 0,
      'main_1280x510_desktop_webp' => 0,
      'main_1280x510_desktop_webp_retina' => 0,
      'main_1280x510_phone' => 0,
      'main_1280x510_phone_retina' => 0,
      'main_1280x510_phone_webp' => 0,
      'main_1280x510_phone_webp_retina' => 0,
      'main_1280x510_small_tablet' => 0,
      'main_1280x510_small_tablet_retina' => 0,
      'main_1280x510_small_tablet_webp' => 0,
      'main_1280x510_small_tablet_webp_retina' => 0,
      'main_1280x510_smartphone' => 0,
      'main_1280x510_smartphone_retina' => 0,
      'main_1280x510_smartphone_webp' => 0,
      'main_1280x510_smartphone_webp_retina' => 0,
      'main_1280x510_tablet' => 0,
      'main_1280x510_tablet_retina' => 0,
      'main_1280x510_tablet_webp' => 0,
      'main_1280x510_tablet_webp_retina' => 0,
      'main_1280x510_wide' => 0,
      'main_1280x510_wide_retina' => 0,
      'main_1280x510_wide_webp' => 0,
      'main_1280x510_wide_webp_retina' => 0,
      'main_200x125_phone' => 0,
      'main_200x125_phone_retina' => 0,
      'main_200x125_phone_webp' => 0,
      'main_200x125_phone_webp_retina' => 0,
      'main_280x280_phone' => 0,
      'main_280x280_phone_retina' => 0,
      'main_280x280_phone_webp' => 0,
      'main_280x280_phone_webp_retina' => 0,
      'main_360x200_phone' => 0,
      'main_360x200_phone_retina' => 0,
      'main_360x200_phone_webp' => 0,
      'main_360x200_phone_webp_retina' => 0,
      'main_360x200_smartphone' => 0,
      'main_360x200_smartphone_retina' => 0,
      'main_360x200_smartphone_webp' => 0,
      'main_360x200_smartphone_webp_retina' => 0,
      'main_380x215_phone' => 0,
      'main_380x215_phone_retina' => 0,
      'main_380x215_phone_webp' => 0,
      'main_380x215_phone_webp_retina' => 0,
      'main_380x215_smartphone' => 0,
      'main_380x215_smartphone_retina' => 0,
      'main_380x215_smartphone_webp' => 0,
      'main_380x215_smartphone_webp_retina' => 0,
      'main_760x377_phone' => 0,
      'main_760x377_phone_retina' => 0,
      'main_760x377_phone_webp' => 0,
      'main_760x377_phone_webp_retina' => 0,
      'main_760x377_small_tablet' => 0,
      'main_760x377_small_tablet_retina' => 0,
      'main_760x377_small_tablet_webp' => 0,
      'main_760x377_small_tablet_webp_retina' => 0,
      'main_760x377_smartphone' => 0,
      'main_760x377_smartphone_retina' => 0,
      'main_760x377_smartphone_webp' => 0,
      'main_760x377_smartphone_webp_retina' => 0,
      '440x230' => 0,
      '80x60' => 0,
      'embed_landscape_400x225' => 0,
      'embed_portrait_225x345' => 0,
      'square_thumbnail' => 0,
      '1280x510' => 0,
      '160x160' => 0,
      '200x125' => 0,
      '280x280' => 0,
      '360x200' => 0,
      '380x215' => 0,
      '400x240' => 0,
      '680x510' => 0,
      '760x377' => 0,
      'retina_100x100' => 0,
      'user_dashboard_100x100' => 0,
      'thumbnail_retina' => 0,
      'medium_retina' => 0,
      'large_retina' => 0,
      '_original image_' => 0,
    ),
    'fallback_image_style' => 'thumbnail',
    'image_link' => '',
  );
  $export['image__portrait_inline__file_field_picture_sizes_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__file_field_slick';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'picture' => 0,
    'picture_style' => '',
    'picture_fallback' => '',
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'portrait_inline',
  );
  $export['image__portrait_inline__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__media_oembed';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['image__portrait_inline__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__media_oembed_thumbnail';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__portrait_inline__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__portrait_inline__media_ustream_video';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['image__portrait_inline__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_image';
  $file_display->weight = 5;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'square_thumbnail',
  );
  $export['image__preview__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_file_default';
  $file_display->weight = -46;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['image__square_image__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_file_download_link';
  $file_display->weight = -50;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__square_image__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_file_table';
  $file_display->weight = -41;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__square_image__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_file_url_plain';
  $file_display->weight = -40;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__square_image__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_image';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'embed_square',
    'image_link' => '',
  );
  $export['image__square_image__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_media_large_icon';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__square_image__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_picture';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'picture_mapping' => 'embed_square',
    'fallback_image_style' => 'embed_square',
    'lazyload' => 1,
    'lazyload_aspect_ratio' => 0,
    'image_link' => '',
  );
  $export['image__square_image__file_field_picture'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_picture_sizes_formatter';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'sizes' => '(min-width: 0px)',
    'image_styles' => array(
      '_empty image_' => '_empty image_',
      'thumbnail' => 0,
      'medium' => 0,
      'large' => 0,
      'media_thumbnail' => 0,
      '1346x330' => 0,
      '60x60' => 0,
      'embed_landscape' => 0,
      'embed_landscape_smartphone' => 0,
      'embed_landscape_smartphone_retina' => 0,
      'embed_landscape_smartphone_webp' => 0,
      'embed_landscape_smartphone_webp_retina' => 0,
      'embed_portrait' => 0,
      'embed_portrait_smartphone' => 0,
      'embed_portrait_smartphone_retina' => 0,
      'embed_portrait_smartphone_webp' => 0,
      'embed_portrait_smartphone_webp_retina' => 0,
      'embed_signature' => 0,
      'embed_signature_smartphone' => 0,
      'embed_signature_smartphone_retina' => 0,
      'embed_signature_smartphone_webp' => 0,
      'embed_signature_smartphone_webp_retina' => 0,
      'embed_square' => 0,
      'embed_square_smartphone' => 0,
      'embed_square_smartphone_retina' => 0,
      'embed_square_smartphone_webp' => 0,
      'embed_square_smartphone_webp_retina' => 0,
      '45x45' => 0,
      '160x160_phone' => 0,
      '160x160_phone_retina' => 0,
      '160x160_phone_webp' => 0,
      '160x160_phone_webp_retina' => 0,
      '400x240_phone' => 0,
      '400x240_phone_retina' => 0,
      '400x240_phone_webp' => 0,
      '400x240_phone_webp_retina' => 0,
      '400x240_smartphone' => 0,
      '400x240_smartphone_retina' => 0,
      '400x240_smartphone_webp' => 0,
      '400x240_smartphone_webp_retina' => 0,
      'base' => 0,
      'hero_1346x330_desktop' => 0,
      'hero_1346x330_desktop_retina' => 0,
      'hero_1346x330_desktop_webp' => 0,
      'hero_1346x330_desktop_webp_retina' => 0,
      'hero_1346x330_phone' => 0,
      'hero_1346x330_phone_retina' => 0,
      'hero_1346x330_phone_webp' => 0,
      'hero_1346x330_phone_webp_retina' => 0,
      'hero_1346x330_small_tablet' => 0,
      'hero_1346x330_small_tablet_retina' => 0,
      'hero_1346x330_small_tablet_webp' => 0,
      'hero_1346x330_small_tablet_webp_retina' => 0,
      'hero_1346x330_smartphone' => 0,
      'hero_1346x330_smartphone_retina' => 0,
      'hero_1346x330_smartphone_webp' => 0,
      'hero_1346x330_smartphone_webp_retina' => 0,
      'hero_1346x330_tablet' => 0,
      'hero_1346x330_tablet_retina' => 0,
      'hero_1346x330_tablet_webp' => 0,
      'hero_1346x330_tablet_webp_retina' => 0,
      'hero_1346x330_wide' => 0,
      'hero_1346x330_wide_retina' => 0,
      'hero_1346x330_wide_webp' => 0,
      'hero_1346x330_wide_webp_retina' => 0,
      'main_1280x510_desktop' => 0,
      'main_1280x510_desktop_retina' => 0,
      'main_1280x510_desktop_webp' => 0,
      'main_1280x510_desktop_webp_retina' => 0,
      'main_1280x510_phone' => 0,
      'main_1280x510_phone_retina' => 0,
      'main_1280x510_phone_webp' => 0,
      'main_1280x510_phone_webp_retina' => 0,
      'main_1280x510_small_tablet' => 0,
      'main_1280x510_small_tablet_retina' => 0,
      'main_1280x510_small_tablet_webp' => 0,
      'main_1280x510_small_tablet_webp_retina' => 0,
      'main_1280x510_smartphone' => 0,
      'main_1280x510_smartphone_retina' => 0,
      'main_1280x510_smartphone_webp' => 0,
      'main_1280x510_smartphone_webp_retina' => 0,
      'main_1280x510_tablet' => 0,
      'main_1280x510_tablet_retina' => 0,
      'main_1280x510_tablet_webp' => 0,
      'main_1280x510_tablet_webp_retina' => 0,
      'main_1280x510_wide' => 0,
      'main_1280x510_wide_retina' => 0,
      'main_1280x510_wide_webp' => 0,
      'main_1280x510_wide_webp_retina' => 0,
      'main_200x125_phone' => 0,
      'main_200x125_phone_retina' => 0,
      'main_200x125_phone_webp' => 0,
      'main_200x125_phone_webp_retina' => 0,
      'main_280x280_phone' => 0,
      'main_280x280_phone_retina' => 0,
      'main_280x280_phone_webp' => 0,
      'main_280x280_phone_webp_retina' => 0,
      'main_360x200_phone' => 0,
      'main_360x200_phone_retina' => 0,
      'main_360x200_phone_webp' => 0,
      'main_360x200_phone_webp_retina' => 0,
      'main_360x200_smartphone' => 0,
      'main_360x200_smartphone_retina' => 0,
      'main_360x200_smartphone_webp' => 0,
      'main_360x200_smartphone_webp_retina' => 0,
      'main_380x215_phone' => 0,
      'main_380x215_phone_retina' => 0,
      'main_380x215_phone_webp' => 0,
      'main_380x215_phone_webp_retina' => 0,
      'main_380x215_smartphone' => 0,
      'main_380x215_smartphone_retina' => 0,
      'main_380x215_smartphone_webp' => 0,
      'main_380x215_smartphone_webp_retina' => 0,
      'main_760x377_phone' => 0,
      'main_760x377_phone_retina' => 0,
      'main_760x377_phone_webp' => 0,
      'main_760x377_phone_webp_retina' => 0,
      'main_760x377_small_tablet' => 0,
      'main_760x377_small_tablet_retina' => 0,
      'main_760x377_small_tablet_webp' => 0,
      'main_760x377_small_tablet_webp_retina' => 0,
      'main_760x377_smartphone' => 0,
      'main_760x377_smartphone_retina' => 0,
      'main_760x377_smartphone_webp' => 0,
      'main_760x377_smartphone_webp_retina' => 0,
      '440x230' => 0,
      '80x60' => 0,
      'embed_landscape_400x225' => 0,
      'embed_portrait_225x345' => 0,
      'square_thumbnail' => 0,
      '1280x510' => 0,
      '160x160' => 0,
      '200x125' => 0,
      '280x280' => 0,
      '360x200' => 0,
      '380x215' => 0,
      '400x240' => 0,
      '680x510' => 0,
      '760x377' => 0,
      'retina_100x100' => 0,
      'user_dashboard_100x100' => 0,
      'thumbnail_retina' => 0,
      'medium_retina' => 0,
      'large_retina' => 0,
      '_original image_' => 0,
    ),
    'fallback_image_style' => 'thumbnail',
    'image_link' => '',
  );
  $export['image__square_image__file_field_picture_sizes_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__file_field_slick';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'optionset' => 'default',
    'skin' => '',
    'optionset_thumbnail' => '',
    'skin_thumbnail' => '',
    'skin_arrows' => '',
    'skin_dots' => '',
    'asnavfor_main' => '',
    'asnavfor_thumbnail' => '',
    'asnavfor_auto' => 0,
    'image_style' => '',
    'thumbnail_style' => '',
    'thumbnail_hover' => 0,
    'slide_layout' => '',
    'thumbnail_caption' => '',
    'slide_overlay' => '',
    'slide_title' => '',
    'slide_link' => '',
    'slide_classes' => '',
    'slide_caption' => array(
      'field_file_image_alt_text' => 0,
      'field_file_image_title_text' => 0,
    ),
    'view_mode' => '',
    'media_switch' => '',
    'iframe_lazy' => 0,
    'aspect_ratio' => '',
    'mousewheel' => 0,
    'picture' => 0,
    'picture_style' => '',
    'picture_fallback' => '',
    'markup' => 0,
    'cache' => '',
    'override' => 0,
    'overridables' => array(
      'arrows' => 0,
      'autoplay' => 0,
      'dots' => 0,
      'draggable' => 0,
    ),
    'current_view_mode' => 'square_image',
  );
  $export['image__square_image__file_field_slick'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__media_oembed';
  $file_display->weight = -49;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '360',
  );
  $export['image__square_image__media_oembed'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__media_oembed_thumbnail';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__square_image__media_oembed_thumbnail'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__square_image__media_ustream_video';
  $file_display->weight = -39;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['image__square_image__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__teaser__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__teaser__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__file_image';
  $file_display->weight = 5;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'medium',
  );
  $export['image__teaser__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__media_livestream_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__teaser__media_livestream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__teaser__media_livestream_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '388',
    'autoplay_channel' => 0,
    'autoplay_video' => 0,
    'mute' => 0,
    'layout' => '4',
    'protocol_specify' => 0,
    'protocol' => 'https:',
  );
  $export['image__teaser__media_livestream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_default';
  $file_display->weight = -42;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_download_link';
  $file_display->weight = -44;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['video__default__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_table';
  $file_display->weight = -43;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_file_url_plain';
  $file_display->weight = -46;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__file_field_media_large_icon';
  $file_display->weight = -45;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__default__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__media_ustream_image';
  $file_display->weight = -48;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '760x377',
  );
  $export['video__default__media_ustream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__media_ustream_video';
  $file_display->weight = -50;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '760',
    'height' => '460',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '#45505c',
  );
  $export['video__default__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__default__media_youtube_image';
  $file_display->weight = -47;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '760x377',
  );
  $export['video__default__media_youtube_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__flex_video__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['video__flex_video__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__flex_video__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__flex_video__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__file_field_file_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'autoplay' => 0,
    'loop' => 0,
    'muted' => 0,
    'width' => '',
    'height' => '',
    'multiple_file_behavior' => 'tags',
  );
  $export['video__flex_video__file_field_file_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__flex_video__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__media_ustream_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__flex_video__media_ustream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['video__flex_video__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__media_youtube_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__flex_video__media_youtube_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__flex_video__media_youtube_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '760',
    'height' => '400',
    'theme' => 'dark',
    'color' => 'red',
    'autohide' => '2',
    'captions' => '0',
    'autoplay' => 0,
    'loop' => 0,
    'showinfo' => 0,
    'modestbranding' => 0,
    'rel' => 0,
    'nocookie' => 0,
    'protocol_specify' => 0,
    'protocol' => 'https:',
    'enablejsapi' => 0,
    'origin' => '',
  );
  $export['video__flex_video__media_youtube_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['video__media_link__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_link__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_link__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__file_field_file_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'autoplay' => 0,
    'loop' => 0,
    'muted' => 0,
    'width' => '',
    'height' => '',
    'multiple_file_behavior' => 'tags',
  );
  $export['video__media_link__file_field_file_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_link__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__media_ustream_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__media_link__media_ustream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '393',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['video__media_link__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__media_youtube_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__media_link__media_youtube_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_link__media_youtube_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '640',
    'height' => '390',
    'theme' => 'dark',
    'color' => 'red',
    'autohide' => '2',
    'autoplay' => 0,
    'loop' => 0,
    'showinfo' => 1,
    'modestbranding' => 0,
    'rel' => 1,
    'nocookie' => 0,
    'protocol_specify' => 0,
    'protocol' => 'https:',
    'enablejsapi' => 0,
    'origin' => '',
  );
  $export['video__media_link__media_youtube_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_original__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['video__media_original__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_original__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_original__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_file_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'controls' => 1,
    'autoplay' => 0,
    'loop' => 0,
    'muted' => 0,
    'width' => '',
    'height' => '',
    'multiple_file_behavior' => 'tags',
  );
  $export['video__media_original__file_field_file_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__media_original__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__media_ustream_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__media_original__media_ustream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '760',
    'height' => '460',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['video__media_original__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__media_original__media_youtube_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__media_original__media_youtube_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__teaser__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['video__teaser__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__teaser__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['video__teaser__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['video__teaser__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__media_ustream_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => '360x200',
  );
  $export['video__teaser__media_ustream_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__media_ustream_video';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'width' => '760',
    'height' => '460',
    'autoplay_live' => 0,
    'autoplay_recorded' => 0,
    'new_player' => 1,
    'player_color' => '',
    'custom_color' => '',
  );
  $export['video__teaser__media_ustream_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__teaser__media_youtube_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'thumbnail',
  );
  $export['video__teaser__media_youtube_image'] = $file_display;

  return $export;
}
