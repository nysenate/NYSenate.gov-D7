<?php

/**
 * @file
 * nys_variables.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_variables_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_variables_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nys_variables_image_default_styles() {
  $styles = array();

  // Exported image style: 1280x510.
  $styles['1280x510'] = array(
    'label' => '1280x510',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 510,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      18 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 85,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 160x160.
  $styles['160x160'] = array(
    'label' => '160x160',
    'effects' => array(
      25 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 160,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      26 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 100,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 200x125.
  $styles['200x125'] = array(
    'label' => '200x125',
    'effects' => array(
      19 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 125,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      20 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 100,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 280x280.
  $styles['280x280'] = array(
    'label' => '280x280',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 280,
          'height' => 280,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      28 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 100,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 360x200.
  $styles['360x200'] = array(
    'label' => '360x200',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 200,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      30 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 100,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 380x215.
  $styles['380x215'] = array(
    'label' => '380x215',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 380,
          'height' => 215,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      32 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 100,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 400x240.
  $styles['400x240'] = array(
    'label' => '400x240',
    'effects' => array(
      21 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 680x510.
  $styles['680x510'] = array(
    'label' => '680x510',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 680,
          'height' => 510,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      17 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 92,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 760x377.
  $styles['760x377'] = array(
    'label' => '760x377',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 760,
          'height' => 377,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
      15 => array(
        'name' => 'image_style_quality',
        'data' => array(
          'quality' => 92,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: retina_100x100.
  $styles['retina_100x100'] = array(
    'label' => 'retina 100x100',
    'effects' => array(
      11 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_dashboard_100x100.
  $styles['user_dashboard_100x100'] = array(
    'label' => 'User Dashboard 100x100',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
