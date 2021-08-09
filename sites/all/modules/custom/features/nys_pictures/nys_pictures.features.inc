<?php
/**
 * @file
 * nys_pictures.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_pictures_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nys_pictures_image_default_styles() {
  $styles = array();

  // Exported image style: 160x160_phone.
  $styles['160x160_phone'] = array(
    'label' => '160x160_phone',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 160x160_phone_retina.
  $styles['160x160_phone_retina'] = array(
    'label' => '160x160_phone_retina',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 160x160_phone_webp.
  $styles['160x160_phone_webp'] = array(
    'label' => '160x160_phone_webp',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 160x160_phone_webp_retina.
  $styles['160x160_phone_webp_retina'] = array(
    'label' => '160x160_phone_webp_retina',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_phone.
  $styles['400x240_phone'] = array(
    'label' => '400x240_phone',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_phone_retina.
  $styles['400x240_phone_retina'] = array(
    'label' => '400x240_phone_retina',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_phone_webp.
  $styles['400x240_phone_webp'] = array(
    'label' => '400x240_phone_webp',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_phone_webp_retina.
  $styles['400x240_phone_webp_retina'] = array(
    'label' => '400x240_phone_webp_retina',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_smartphone.
  $styles['400x240_smartphone'] = array(
    'label' => '400x240_smartphone',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 192,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_smartphone_retina.
  $styles['400x240_smartphone_retina'] = array(
    'label' => '400x240_smartphone_retina',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 384,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_smartphone_webp.
  $styles['400x240_smartphone_webp'] = array(
    'label' => '400x240_smartphone_webp',
    'effects' => array(
      18 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 192,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 400x240_smartphone_webp_retina.
  $styles['400x240_smartphone_webp_retina'] = array(
    'label' => '400x240_smartphone_webp_retina',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 384,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 45x45_phone.
  $styles['45x45_phone'] = array(
    'label' => '45x45_phone',
    'effects' => array(
      172 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 45,
          'height' => 45,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 45x45_phone_retina.
  $styles['45x45_phone_retina'] = array(
    'label' => '45x45_phone_retina',
    'effects' => array(
      171 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 45x45_phone_webp.
  $styles['45x45_phone_webp'] = array(
    'label' => '45x45_phone_webp',
    'effects' => array(
      170 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 45,
          'height' => 45,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 45x45_phone_webp_retina.
  $styles['45x45_phone_webp_retina'] = array(
    'label' => '45x45_phone_webp_retina',
    'effects' => array(
      169 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 60x60_phone.
  $styles['60x60_phone'] = array(
    'label' => '60x60_phone',
    'effects' => array(
      176 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 60x60_phone_retina.
  $styles['60x60_phone_retina'] = array(
    'label' => '60x60_phone_retina',
    'effects' => array(
      175 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 60x60_phone_webp.
  $styles['60x60_phone_webp'] = array(
    'label' => '60x60_phone_webp',
    'effects' => array(
      174 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 60x60_phone_webp_retina.
  $styles['60x60_phone_webp_retina'] = array(
    'label' => '60x60_phone_webp_retina',
    'effects' => array(
      173 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 760x.
  $styles['760x'] = array(
    'label' => '760x',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 760,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: base.
  $styles['base'] = array(
    'label' => 'base',
    'effects' => array(),
  );

  // Exported image style: embed_landscape.
  $styles['embed_landscape'] = array(
    'label' => 'embed_landscape',
    'effects' => array(
      25 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 336,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_landscape_smartphone.
  $styles['embed_landscape_smartphone'] = array(
    'label' => 'embed_landscape_smartphone',
    'effects' => array(
      27 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 336,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_landscape_smartphone_retina.
  $styles['embed_landscape_smartphone_retina'] = array(
    'label' => 'embed_landscape_smartphone_retina',
    'effects' => array(
      29 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 672,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_landscape_smartphone_webp.
  $styles['embed_landscape_smartphone_webp'] = array(
    'label' => 'embed_landscape_smartphone_webp',
    'effects' => array(
      31 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 336,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_landscape_smartphone_webp_retina.
  $styles['embed_landscape_smartphone_webp_retina'] = array(
    'label' => 'embed_landscape_smartphone_webp_retina',
    'effects' => array(
      33 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 672,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_portrait.
  $styles['embed_portrait'] = array(
    'label' => 'embed_portrait',
    'effects' => array(
      35 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 336,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_portrait_smartphone.
  $styles['embed_portrait_smartphone'] = array(
    'label' => 'embed_portrait_smartphone',
    'effects' => array(
      37 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 336,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_portrait_smartphone_retina.
  $styles['embed_portrait_smartphone_retina'] = array(
    'label' => 'embed_portrait_smartphone_retina',
    'effects' => array(
      39 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 672,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_portrait_smartphone_webp.
  $styles['embed_portrait_smartphone_webp'] = array(
    'label' => 'embed_portrait_smartphone_webp',
    'effects' => array(
      41 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 336,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_portrait_smartphone_webp_retina.
  $styles['embed_portrait_smartphone_webp_retina'] = array(
    'label' => 'embed_portrait_smartphone_webp_retina',
    'effects' => array(
      43 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 672,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: embed_signature.
  $styles['embed_signature'] = array(
    'label' => 'embed_signature',
    'effects' => array(
      164 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_signature_smartphone.
  $styles['embed_signature_smartphone'] = array(
    'label' => 'embed_signature_smartphone',
    'effects' => array(
      168 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_signature_smartphone_retina.
  $styles['embed_signature_smartphone_retina'] = array(
    'label' => 'embed_signature_smartphone_retina',
    'effects' => array(
      167 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_signature_smartphone_webp.
  $styles['embed_signature_smartphone_webp'] = array(
    'label' => 'embed_signature_smartphone_webp',
    'effects' => array(
      166 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_signature_smartphone_webp_retina.
  $styles['embed_signature_smartphone_webp_retina'] = array(
    'label' => 'embed_signature_smartphone_webp_retina',
    'effects' => array(
      165 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_square.
  $styles['embed_square'] = array(
    'label' => 'embed_square',
    'effects' => array(
      159 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 336,
          'height' => 336,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_square_smartphone.
  $styles['embed_square_smartphone'] = array(
    'label' => 'embed_square_smartphone',
    'effects' => array(
      163 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 336,
          'height' => 336,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_square_smartphone_retina.
  $styles['embed_square_smartphone_retina'] = array(
    'label' => 'embed_square_smartphone_retina',
    'effects' => array(
      162 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 672,
          'height' => 672,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_square_smartphone_webp.
  $styles['embed_square_smartphone_webp'] = array(
    'label' => 'embed_square_smartphone_webp',
    'effects' => array(
      161 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 336,
          'height' => 336,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_square_smartphone_webp_retina.
  $styles['embed_square_smartphone_webp_retina'] = array(
    'label' => 'embed_square_smartphone_webp_retina',
    'effects' => array(
      160 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 672,
          'height' => 672,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_desktop.
  $styles['hero_1346x330_desktop'] = array(
    'label' => 'hero_1346x330_desktop',
    'effects' => array(
      23 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 294,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_desktop_retina.
  $styles['hero_1346x330_desktop_retina'] = array(
    'label' => 'hero_1346x330_desktop_retina',
    'effects' => array(
      22 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2400,
          'height' => 588,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_desktop_webp.
  $styles['hero_1346x330_desktop_webp'] = array(
    'label' => 'hero_1346x330_desktop_webp',
    'effects' => array(
      24 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 294,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_desktop_webp_retina.
  $styles['hero_1346x330_desktop_webp_retina'] = array(
    'label' => 'hero_1346x330_desktop_webp_retina',
    'effects' => array(
      20 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2400,
          'height' => 588,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_phone.
  $styles['hero_1346x330_phone'] = array(
    'label' => 'hero_1346x330_phone',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 78,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_phone_retina.
  $styles['hero_1346x330_phone_retina'] = array(
    'label' => 'hero_1346x330_phone_retina',
    'effects' => array(
      30 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 156,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_phone_webp.
  $styles['hero_1346x330_phone_webp'] = array(
    'label' => 'hero_1346x330_phone_webp',
    'effects' => array(
      26 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 78,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_phone_webp_retina.
  $styles['hero_1346x330_phone_webp_retina'] = array(
    'label' => 'hero_1346x330_phone_webp_retina',
    'effects' => array(
      28 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 156,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_small_tablet.
  $styles['hero_1346x330_small_tablet'] = array(
    'label' => 'hero_1346x330_small_tablet',
    'effects' => array(
      32 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 188,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_small_tablet_retina.
  $styles['hero_1346x330_small_tablet_retina'] = array(
    'label' => 'hero_1346x330_small_tablet_retina',
    'effects' => array(
      35 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1536,
          'height' => 376,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_small_tablet_webp.
  $styles['hero_1346x330_small_tablet_webp'] = array(
    'label' => 'hero_1346x330_small_tablet_webp',
    'effects' => array(
      33 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 188,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_small_tablet_webp_retina.
  $styles['hero_1346x330_small_tablet_webp_retina'] = array(
    'label' => 'hero_1346x330_small_tablet_webp_retina',
    'effects' => array(
      34 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1536,
          'height' => 376,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_smartphone.
  $styles['hero_1346x330_smartphone'] = array(
    'label' => 'hero_1346x330_smartphone',
    'effects' => array(
      39 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 118,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_smartphone_retina.
  $styles['hero_1346x330_smartphone_retina'] = array(
    'label' => 'hero_1346x330_smartphone_retina',
    'effects' => array(
      41 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 236,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_smartphone_webp.
  $styles['hero_1346x330_smartphone_webp'] = array(
    'label' => 'hero_1346x330_smartphone_webp',
    'effects' => array(
      38 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 118,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_smartphone_webp_retina.
  $styles['hero_1346x330_smartphone_webp_retina'] = array(
    'label' => 'hero_1346x330_smartphone_webp_retina',
    'effects' => array(
      40 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 236,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_tablet.
  $styles['hero_1346x330_tablet'] = array(
    'label' => 'hero_1346x330_tablet',
    'effects' => array(
      45 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 992,
          'height' => 243,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_tablet_retina.
  $styles['hero_1346x330_tablet_retina'] = array(
    'label' => 'hero_1346x330_tablet_retina',
    'effects' => array(
      46 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1984,
          'height' => 486,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_tablet_webp.
  $styles['hero_1346x330_tablet_webp'] = array(
    'label' => 'hero_1346x330_tablet_webp',
    'effects' => array(
      44 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 992,
          'height' => 243,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_tablet_webp_retina.
  $styles['hero_1346x330_tablet_webp_retina'] = array(
    'label' => 'hero_1346x330_tablet_webp_retina',
    'effects' => array(
      47 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1984,
          'height' => 486,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_wide.
  $styles['hero_1346x330_wide'] = array(
    'label' => 'hero_1346x330_wide',
    'effects' => array(
      52 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1346,
          'height' => 330,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_wide_retina.
  $styles['hero_1346x330_wide_retina'] = array(
    'label' => 'hero_1346x330_wide_retina',
    'effects' => array(
      53 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2692,
          'height' => 660,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_wide_webp.
  $styles['hero_1346x330_wide_webp'] = array(
    'label' => 'hero_1346x330_wide_webp',
    'effects' => array(
      51 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1346,
          'height' => 330,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_1346x330_wide_webp_retina.
  $styles['hero_1346x330_wide_webp_retina'] = array(
    'label' => 'hero_1346x330_wide_webp_retina',
    'effects' => array(
      54 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2692,
          'height' => 660,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_phone.
  $styles['hero_680x510_phone'] = array(
    'label' => 'hero_680x510_phone',
    'effects' => array(
      188 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_phone_retina.
  $styles['hero_680x510_phone_retina'] = array(
    'label' => 'hero_680x510_phone_retina',
    'effects' => array(
      187 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_phone_webp.
  $styles['hero_680x510_phone_webp'] = array(
    'label' => 'hero_680x510_phone_webp',
    'effects' => array(
      186 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_phone_webp_retina.
  $styles['hero_680x510_phone_webp_retina'] = array(
    'label' => 'hero_680x510_phone_webp_retina',
    'effects' => array(
      185 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_small_tablet.
  $styles['hero_680x510_small_tablet'] = array(
    'label' => 'hero_680x510_small_tablet',
    'effects' => array(
      180 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 680,
          'height' => 510,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_small_tablet_retina.
  $styles['hero_680x510_small_tablet_retina'] = array(
    'label' => 'hero_680x510_small_tablet_retina',
    'effects' => array(
      179 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1360,
          'height' => 1020,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_small_tablet_webp.
  $styles['hero_680x510_small_tablet_webp'] = array(
    'label' => 'hero_680x510_small_tablet_webp',
    'effects' => array(
      178 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 680,
          'height' => 510,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_small_tablet_webp_retina.
  $styles['hero_680x510_small_tablet_webp_retina'] = array(
    'label' => 'hero_680x510_small_tablet_webp_retina',
    'effects' => array(
      177 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1360,
          'height' => 1020,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_smartphone.
  $styles['hero_680x510_smartphone'] = array(
    'label' => 'hero_680x510_smartphone',
    'effects' => array(
      184 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_smartphone_retina.
  $styles['hero_680x510_smartphone_retina'] = array(
    'label' => 'hero_680x510_smartphone_retina',
    'effects' => array(
      183 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 940,
          'height' => 720,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_smartphone_webp.
  $styles['hero_680x510_smartphone_webp'] = array(
    'label' => 'hero_680x510_smartphone_webp',
    'effects' => array(
      182 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_680x510_smartphone_webp_retina.
  $styles['hero_680x510_smartphone_webp_retina'] = array(
    'label' => 'hero_680x510_smartphone_webp_retina',
    'effects' => array(
      181 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 940,
          'height' => 720,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_desktop.
  $styles['main_1280x510_desktop'] = array(
    'label' => 'main_1280x510_desktop',
    'effects' => array(
      58 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 478,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_desktop_retina.
  $styles['main_1280x510_desktop_retina'] = array(
    'label' => 'main_1280x510_desktop_retina',
    'effects' => array(
      60 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2400,
          'height' => 958,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_desktop_webp.
  $styles['main_1280x510_desktop_webp'] = array(
    'label' => 'main_1280x510_desktop_webp',
    'effects' => array(
      57 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 478,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_desktop_webp_retina.
  $styles['main_1280x510_desktop_webp_retina'] = array(
    'label' => 'main_1280x510_desktop_webp_retina',
    'effects' => array(
      59 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2400,
          'height' => 958,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_phone.
  $styles['main_1280x510_phone'] = array(
    'label' => 'main_1280x510_phone',
    'effects' => array(
      64 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 128,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_phone_retina.
  $styles['main_1280x510_phone_retina'] = array(
    'label' => 'main_1280x510_phone_retina',
    'effects' => array(
      67 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 256,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_phone_webp.
  $styles['main_1280x510_phone_webp'] = array(
    'label' => 'main_1280x510_phone_webp',
    'effects' => array(
      65 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 128,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_phone_webp_retina.
  $styles['main_1280x510_phone_webp_retina'] = array(
    'label' => 'main_1280x510_phone_webp_retina',
    'effects' => array(
      66 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 256,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_small_tablet.
  $styles['main_1280x510_small_tablet'] = array(
    'label' => 'main_1280x510_small_tablet',
    'effects' => array(
      70 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 306,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_small_tablet_retina.
  $styles['main_1280x510_small_tablet_retina'] = array(
    'label' => 'main_1280x510_small_tablet_retina',
    'effects' => array(
      72 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1536,
          'height' => 612,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_small_tablet_webp.
  $styles['main_1280x510_small_tablet_webp'] = array(
    'label' => 'main_1280x510_small_tablet_webp',
    'effects' => array(
      71 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 306,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_small_tablet_webp_retina.
  $styles['main_1280x510_small_tablet_webp_retina'] = array(
    'label' => 'main_1280x510_small_tablet_webp_retina',
    'effects' => array(
      73 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1536,
          'height' => 612,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_smartphone.
  $styles['main_1280x510_smartphone'] = array(
    'label' => 'main_1280x510_smartphone',
    'effects' => array(
      76 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 191,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_smartphone_retina.
  $styles['main_1280x510_smartphone_retina'] = array(
    'label' => 'main_1280x510_smartphone_retina',
    'effects' => array(
      78 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 382,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_smartphone_webp.
  $styles['main_1280x510_smartphone_webp'] = array(
    'label' => 'main_1280x510_smartphone_webp',
    'effects' => array(
      79 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 191,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: main_1280x510_smartphone_webp_retina.
  $styles['main_1280x510_smartphone_webp_retina'] = array(
    'label' => 'main_1280x510_smartphone_webp_retina',
    'effects' => array(
      81 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 382,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_tablet.
  $styles['main_1280x510_tablet'] = array(
    'label' => 'main_1280x510_tablet',
    'effects' => array(
      83 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 992,
          'height' => 395,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_tablet_retina.
  $styles['main_1280x510_tablet_retina'] = array(
    'label' => 'main_1280x510_tablet_retina',
    'effects' => array(
      86 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1984,
          'height' => 790,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_tablet_webp.
  $styles['main_1280x510_tablet_webp'] = array(
    'label' => 'main_1280x510_tablet_webp',
    'effects' => array(
      84 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 992,
          'height' => 395,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_tablet_webp_retina.
  $styles['main_1280x510_tablet_webp_retina'] = array(
    'label' => 'main_1280x510_tablet_webp_retina',
    'effects' => array(
      85 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1984,
          'height' => 790,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_wide.
  $styles['main_1280x510_wide'] = array(
    'label' => 'main_1280x510_wide',
    'effects' => array(
      89 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 510,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_wide_retina.
  $styles['main_1280x510_wide_retina'] = array(
    'label' => 'main_1280x510_wide_retina',
    'effects' => array(
      91 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2560,
          'height' => 1020,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_wide_webp.
  $styles['main_1280x510_wide_webp'] = array(
    'label' => 'main_1280x510_wide_webp',
    'effects' => array(
      90 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 510,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_1280x510_wide_webp_retina.
  $styles['main_1280x510_wide_webp_retina'] = array(
    'label' => 'main_1280x510_wide_webp_retina',
    'effects' => array(
      92 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2560,
          'height' => 1020,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_200x125_phone.
  $styles['main_200x125_phone'] = array(
    'label' => 'main_200x125_phone',
    'effects' => array(
      95 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 125,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_200x125_phone_retina.
  $styles['main_200x125_phone_retina'] = array(
    'label' => 'main_200x125_phone_retina',
    'effects' => array(
      98 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_200x125_phone_webp.
  $styles['main_200x125_phone_webp'] = array(
    'label' => 'main_200x125_phone_webp',
    'effects' => array(
      96 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 125,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_200x125_phone_webp_retina.
  $styles['main_200x125_phone_webp_retina'] = array(
    'label' => 'main_200x125_phone_webp_retina',
    'effects' => array(
      99 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_280x280_phone.
  $styles['main_280x280_phone'] = array(
    'label' => 'main_280x280_phone',
    'effects' => array(
      101 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 280,
          'height' => 280,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_280x280_phone_retina.
  $styles['main_280x280_phone_retina'] = array(
    'label' => 'main_280x280_phone_retina',
    'effects' => array(
      103 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 560,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_280x280_phone_webp.
  $styles['main_280x280_phone_webp'] = array(
    'label' => 'main_280x280_phone_webp',
    'effects' => array(
      102 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 280,
          'height' => 280,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_280x280_phone_webp_retina.
  $styles['main_280x280_phone_webp_retina'] = array(
    'label' => 'main_280x280_phone_webp_retina',
    'effects' => array(
      104 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 560,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_phone.
  $styles['main_360x200_phone'] = array(
    'label' => 'main_360x200_phone',
    'effects' => array(
      107 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 178,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_phone_retina.
  $styles['main_360x200_phone_retina'] = array(
    'label' => 'main_360x200_phone_retina',
    'effects' => array(
      109 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 356,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_phone_webp.
  $styles['main_360x200_phone_webp'] = array(
    'label' => 'main_360x200_phone_webp',
    'effects' => array(
      108 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 178,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_phone_webp_retina.
  $styles['main_360x200_phone_webp_retina'] = array(
    'label' => 'main_360x200_phone_webp_retina',
    'effects' => array(
      113 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 356,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_smartphone.
  $styles['main_360x200_smartphone'] = array(
    'label' => 'main_360x200_smartphone',
    'effects' => array(
      115 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_smartphone_retina.
  $styles['main_360x200_smartphone_retina'] = array(
    'label' => 'main_360x200_smartphone_retina',
    'effects' => array(
      117 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_smartphone_webp.
  $styles['main_360x200_smartphone_webp'] = array(
    'label' => 'main_360x200_smartphone_webp',
    'effects' => array(
      116 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_360x200_smartphone_webp_retina.
  $styles['main_360x200_smartphone_webp_retina'] = array(
    'label' => 'main_360x200_smartphone_webp_retina',
    'effects' => array(
      118 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_phone.
  $styles['main_380x215_phone'] = array(
    'label' => 'main_380x215_phone',
    'effects' => array(
      121 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 181,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_phone_retina.
  $styles['main_380x215_phone_retina'] = array(
    'label' => 'main_380x215_phone_retina',
    'effects' => array(
      123 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 362,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_phone_webp.
  $styles['main_380x215_phone_webp'] = array(
    'label' => 'main_380x215_phone_webp',
    'effects' => array(
      122 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 181,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_phone_webp_retina.
  $styles['main_380x215_phone_webp_retina'] = array(
    'label' => 'main_380x215_phone_webp_retina',
    'effects' => array(
      124 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 362,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_smartphone.
  $styles['main_380x215_smartphone'] = array(
    'label' => 'main_380x215_smartphone',
    'effects' => array(
      127 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 380,
          'height' => 215,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_smartphone_retina.
  $styles['main_380x215_smartphone_retina'] = array(
    'label' => 'main_380x215_smartphone_retina',
    'effects' => array(
      129 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 760,
          'height' => 430,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_smartphone_webp.
  $styles['main_380x215_smartphone_webp'] = array(
    'label' => 'main_380x215_smartphone_webp',
    'effects' => array(
      128 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 380,
          'height' => 215,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_380x215_smartphone_webp_retina.
  $styles['main_380x215_smartphone_webp_retina'] = array(
    'label' => 'main_380x215_smartphone_webp_retina',
    'effects' => array(
      130 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 760,
          'height' => 430,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_phone.
  $styles['main_760x377_phone'] = array(
    'label' => 'main_760x377_phone',
    'effects' => array(
      133 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 159,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_phone_retina.
  $styles['main_760x377_phone_retina'] = array(
    'label' => 'main_760x377_phone_retina',
    'effects' => array(
      135 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 318,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_phone_webp.
  $styles['main_760x377_phone_webp'] = array(
    'label' => 'main_760x377_phone_webp',
    'effects' => array(
      134 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 159,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_phone_webp_retina.
  $styles['main_760x377_phone_webp_retina'] = array(
    'label' => 'main_760x377_phone_webp_retina',
    'effects' => array(
      136 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 318,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_small_tablet.
  $styles['main_760x377_small_tablet'] = array(
    'label' => 'main_760x377_small_tablet',
    'effects' => array(
      139 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 760,
          'height' => 377,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_small_tablet_retina.
  $styles['main_760x377_small_tablet_retina'] = array(
    'label' => 'main_760x377_small_tablet_retina',
    'effects' => array(
      141 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1520,
          'height' => 754,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_small_tablet_webp.
  $styles['main_760x377_small_tablet_webp'] = array(
    'label' => 'main_760x377_small_tablet_webp',
    'effects' => array(
      140 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 760,
          'height' => 377,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_small_tablet_webp_retina.
  $styles['main_760x377_small_tablet_webp_retina'] = array(
    'label' => 'main_760x377_small_tablet_webp_retina',
    'effects' => array(
      142 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1520,
          'height' => 754,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_smartphone.
  $styles['main_760x377_smartphone'] = array(
    'label' => 'main_760x377_smartphone',
    'effects' => array(
      145 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 238,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_smartphone_retina.
  $styles['main_760x377_smartphone_retina'] = array(
    'label' => 'main_760x377_smartphone_retina',
    'effects' => array(
      147 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 476,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_smartphone_webp.
  $styles['main_760x377_smartphone_webp'] = array(
    'label' => 'main_760x377_smartphone_webp',
    'effects' => array(
      146 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 238,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x377_smartphone_webp_retina.
  $styles['main_760x377_smartphone_webp_retina'] = array(
    'label' => 'main_760x377_smartphone_webp_retina',
    'effects' => array(
      148 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 476,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_phone.
  $styles['main_760x_phone'] = array(
    'label' => 'main_760x_phone',
    'effects' => array(
      23 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 320,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_phone_retina.
  $styles['main_760x_phone_retina'] = array(
    'label' => 'main_760x_phone_retina',
    'effects' => array(
      22 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 640,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_phone_webp.
  $styles['main_760x_phone_webp'] = array(
    'label' => 'main_760x_phone_webp',
    'effects' => array(
      21 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 320,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_phone_webp_retina.
  $styles['main_760x_phone_webp_retina'] = array(
    'label' => 'main_760x_phone_webp_retina',
    'effects' => array(
      20 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 640,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_small_tablet.
  $styles['main_760x_small_tablet'] = array(
    'label' => 'main_760x_small_tablet',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 760,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_small_tablet_retina.
  $styles['main_760x_small_tablet_retina'] = array(
    'label' => 'main_760x_small_tablet_retina',
    'effects' => array(
      14 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1520,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_small_tablet_webp.
  $styles['main_760x_small_tablet_webp'] = array(
    'label' => 'main_760x_small_tablet_webp',
    'effects' => array(
      13 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 760,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_small_tablet_webp_retina.
  $styles['main_760x_small_tablet_webp_retina'] = array(
    'label' => 'main_760x_small_tablet_webp_retina',
    'effects' => array(
      12 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1520,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_smartphone.
  $styles['main_760x_smartphone'] = array(
    'label' => 'main_760x_smartphone',
    'effects' => array(
      19 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_smartphone_retina.
  $styles['main_760x_smartphone_retina'] = array(
    'label' => 'main_760x_smartphone_retina',
    'effects' => array(
      18 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 960,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_smartphone_webp.
  $styles['main_760x_smartphone_webp'] = array(
    'label' => 'main_760x_smartphone_webp',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: main_760x_smartphone_webp_retina.
  $styles['main_760x_smartphone_webp_retina'] = array(
    'label' => 'main_760x_smartphone_webp_retina',
    'effects' => array(
      16 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 960,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
