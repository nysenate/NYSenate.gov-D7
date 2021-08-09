<?php
/**
 * @file
 * nys_pictures.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function nys_pictures_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = '160x160';
  $picture_mapping->machine_name = '160x160';
  $picture_mapping->breakpoint_group = '160x160';
  $picture_mapping->mapping = array(
    'custom.user.160x160_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '160x160_phone_webp_retina',
      ),
    ),
    'custom.user.160x160_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '160x160_phone_webp',
      ),
    ),
    'custom.user.160x160_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '160x160_phone_retina',
      ),
    ),
    'custom.user.160x160_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '160x160_phone',
      ),
    ),
  );
  $export['160x160'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = '400x240';
  $picture_mapping->machine_name = '400x240';
  $picture_mapping->breakpoint_group = '400x240';
  $picture_mapping->mapping = array(
    'custom.user.400x240_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_smartphone_webp_retina',
      ),
    ),
    'custom.user.400x240_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_smartphone_webp',
      ),
    ),
    'custom.user.400x240_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_smartphone_retina',
      ),
    ),
    'custom.user.400x240_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_smartphone',
      ),
    ),
    'custom.user.400x240_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_phone_webp_retina',
      ),
    ),
    'custom.user.400x240_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_phone_webp',
      ),
    ),
    'custom.user.400x240_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_phone_retina',
      ),
    ),
    'custom.user.400x240_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '400x240_phone',
      ),
    ),
  );
  $export['400x240'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = '45x45';
  $picture_mapping->machine_name = '45x45';
  $picture_mapping->breakpoint_group = '45x45';
  $picture_mapping->mapping = array(
    'custom.user.45x45_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '45x45_phone_webp_retina',
      ),
    ),
    'custom.user.45x45_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '45x45_phone_webp',
      ),
    ),
    'custom.user.45x45_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '45x45_phone_retina',
      ),
    ),
    'custom.user.45x45_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '45x45_phone',
      ),
    ),
  );
  $export['45x45'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = '60x60';
  $picture_mapping->machine_name = '60x60';
  $picture_mapping->breakpoint_group = '60x60';
  $picture_mapping->mapping = array(
    'custom.user.60x60_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '60x60_phone_webp_retina',
      ),
    ),
    'custom.user.60x60_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '60x60_phone_webp',
      ),
    ),
    'custom.user.60x60_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '60x60_phone_retina',
      ),
    ),
    'custom.user.60x60_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '60x60_phone',
      ),
    ),
  );
  $export['60x60'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'embed_landscape';
  $picture_mapping->machine_name = 'embed_landscape';
  $picture_mapping->breakpoint_group = 'embed_landscape';
  $picture_mapping->mapping = array(
    'custom.user.embed_landscape_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_landscape_smartphone_webp_retina',
      ),
    ),
    'custom.user.embed_landscape_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_landscape_smartphone_webp',
      ),
    ),
    'custom.user.embed_landscape_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_landscape_smartphone_retina',
      ),
    ),
    'custom.user.embed_landscape_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_landscape_smartphone',
      ),
    ),
  );
  $export['embed_landscape'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'embed_portrait';
  $picture_mapping->machine_name = 'embed_portrait';
  $picture_mapping->breakpoint_group = 'embed_portrait';
  $picture_mapping->mapping = array(
    'custom.user.embed_portrait_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_portrait_smartphone_webp_retina',
      ),
    ),
    'custom.user.embed_portrait_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_portrait_smartphone_webp',
      ),
    ),
    'custom.user.embed_portrait_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_portrait_smartphone_retina',
      ),
    ),
    'custom.user.embed_portrait_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_portrait_smartphone',
      ),
    ),
  );
  $export['embed_portrait'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'embed_signature';
  $picture_mapping->machine_name = 'embed_signature';
  $picture_mapping->breakpoint_group = 'embed_signature';
  $picture_mapping->mapping = array(
    'custom.user.embed_signature_smartphone_webp_retina_' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_signature_smartphone_webp_retina',
      ),
    ),
    'custom.user.embed_signature_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_signature_smartphone_webp',
      ),
    ),
    'custom.user.embed_signature_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_signature_smartphone_retina',
      ),
    ),
    'custom.user.embed_signature_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_signature_smartphone',
      ),
    ),
  );
  $export['embed_signature'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'embed_square';
  $picture_mapping->machine_name = 'embed_square';
  $picture_mapping->breakpoint_group = 'embed_square';
  $picture_mapping->mapping = array(
    'custom.user.embed_square_smartphone_webp_retina_' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_square_smartphone_webp_retina',
      ),
    ),
    'custom.user.embed_square_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_square_smartphone_webp',
      ),
    ),
    'custom.user.embed_square_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_square_smartphone_retina',
      ),
    ),
    'custom.user.embed_square_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'embed_square_smartphone',
      ),
    ),
  );
  $export['embed_square'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'hero_1280x510';
  $picture_mapping->machine_name = 'hero_1280x510';
  $picture_mapping->breakpoint_group = 'hero_1280x510';
  $picture_mapping->mapping = array(
    'custom.user.hero_1280x510_wide_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide_webp_retina',
      ),
    ),
    'custom.user.hero_1280x510_wide_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide_webp',
      ),
    ),
    'custom.user.hero_1280x510_wide_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide_retina',
      ),
    ),
    'custom.user.hero_1280x510_wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide',
      ),
    ),
    'custom.user.hero_1280x510_desktop_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop_webp_retina',
      ),
    ),
    'custom.user.hero_1280x510_desktop_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop_webp',
      ),
    ),
    'custom.user.hero_1280x510_desktop_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop_retina',
      ),
    ),
    'custom.user.hero_1280x510_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop',
      ),
    ),
    'custom.user.hero_1280x510_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet_webp_retina',
      ),
    ),
    'custom.user.hero_1280x510_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet_webp',
      ),
    ),
    'custom.user.hero_1280x510_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet_retina',
      ),
    ),
    'custom.user.hero_1280x510_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet',
      ),
    ),
    'custom.user.hero_1280x510_small_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet_webp_retina',
      ),
    ),
    'custom.user.hero_1280x510_small_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet_webp',
      ),
    ),
    'custom.user.hero_1280x510_small_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet_retina',
      ),
    ),
    'custom.user.hero_1280x510_small_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet',
      ),
    ),
    'custom.user.hero_1280x510_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone_webp_retina',
      ),
    ),
    'custom.user.hero_1280x510_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone_webp',
      ),
    ),
    'custom.user.hero_1280x510_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone_retina',
      ),
    ),
    'custom.user.hero_1280x510_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone',
      ),
    ),
    'custom.user.hero_1280x510_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone_webp_retina',
      ),
    ),
    'custom.user.hero_1280x510_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone_webp',
      ),
    ),
    'custom.user.hero_1280x510_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone_retina',
      ),
    ),
    'custom.user.hero_1280x510_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone',
      ),
    ),
  );
  $export['hero_1280x510'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'hero_1346x330';
  $picture_mapping->machine_name = 'hero_1346x330';
  $picture_mapping->breakpoint_group = 'hero_1346x330';
  $picture_mapping->mapping = array(
    'custom.user.hero_1346x330_wide_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_wide_webp_retina',
      ),
    ),
    'custom.user.hero_1346x330_wide_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_wide_webp',
      ),
    ),
    'custom.user.hero_1346x330_wide_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_wide_retina',
      ),
    ),
    'custom.user.hero_1346x330_wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_wide',
      ),
    ),
    'custom.user.hero_1346x330_desktop_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_desktop_webp_retina',
      ),
    ),
    'custom.user.hero_1346x330_desktop_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_desktop_webp',
      ),
    ),
    'custom.user.hero_1346x330_desktop_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_desktop_retina',
      ),
    ),
    'custom.user.hero_1346x330_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_desktop',
      ),
    ),
    'custom.user.hero_1346x330_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_tablet_webp_retina',
      ),
    ),
    'custom.user.hero_1346x330_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_tablet_webp',
      ),
    ),
    'custom.user.hero_1346x330_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_tablet_retina',
      ),
    ),
    'custom.user.hero_1346x330_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_tablet',
      ),
    ),
    'custom.user.hero_1346x330_small_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_small_tablet_webp_retina',
      ),
    ),
    'custom.user.hero_1346x330_small_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_small_tablet_webp',
      ),
    ),
    'custom.user.hero_1346x330_small_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_small_tablet_retina',
      ),
    ),
    'custom.user.hero_1346x330_small_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_small_tablet',
      ),
    ),
    'custom.user.hero_1346x330_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_smartphone_webp_retina',
      ),
    ),
    'custom.user.hero_1346x330_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_smartphone_webp',
      ),
    ),
    'custom.user.hero_1346x330_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_smartphone_retina',
      ),
    ),
    'custom.user.hero_1346x330_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_smartphone',
      ),
    ),
    'custom.user.hero_1346x330_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_phone_webp_retina',
      ),
    ),
    'custom.user.hero_1346x330_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_phone_webp',
      ),
    ),
    'custom.user.hero_1346x330_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_phone_retina',
      ),
    ),
    'custom.user.hero_1346x330_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_1346x330_phone',
      ),
    ),
  );
  $export['hero_1346x330'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'hero_680x510';
  $picture_mapping->machine_name = 'hero_680x510';
  $picture_mapping->breakpoint_group = 'hero_680x510';
  $picture_mapping->mapping = array(
    'custom.user.hero_680x510_small_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_small_tablet_webp_retina',
      ),
    ),
    'custom.user.hero_680x510_small_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_small_tablet_webp',
      ),
    ),
    'custom.user.hero_680x510_small_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_small_tablet_retina',
      ),
    ),
    'custom.user.hero_680x510_small_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_small_tablet',
      ),
    ),
    'custom.user.hero_680x510_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_smartphone_webp_retina',
      ),
    ),
    'custom.user.hero_680x510_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_smartphone_webp',
      ),
    ),
    'custom.user.hero_680x510_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_smartphone_retina',
      ),
    ),
    'custom.user.hero_680x510_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_smartphone',
      ),
    ),
    'custom.user.hero_680x510_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_phone_webp_retina',
      ),
    ),
    'custom.user.hero_680x510_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_phone_webp',
      ),
    ),
    'custom.user.hero_680x510_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_phone_retina',
      ),
    ),
    'custom.user.hero_680x510_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'hero_680x510_phone',
      ),
    ),
  );
  $export['hero_680x510'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'main760x';
  $picture_mapping->machine_name = 'main760x';
  $picture_mapping->breakpoint_group = 'main760x';
  $picture_mapping->mapping = array(
    'custom.user.main_760x_small_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_small_tablet_webp_retina',
      ),
    ),
    'custom.user.main_760x_small_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_small_tablet_webp',
      ),
    ),
    'custom.user.main_760x_small_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_small_tablet_retina',
      ),
    ),
    'custom.user.main_760x_small_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_small_tablet',
      ),
    ),
    'custom.user.main_760x_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_smartphone_webp_retina',
      ),
    ),
    'custom.user.main_760x_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_smartphone_webp',
      ),
    ),
    'custom.user.main_760x_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_smartphone_retina',
      ),
    ),
    'custom.user.main_760x_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_smartphone',
      ),
    ),
    'custom.user.main_760x_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_phone_webp_retina',
      ),
    ),
    'custom.user.main_760x_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_phone_webp',
      ),
    ),
    'custom.user.main_760x_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_phone_retina',
      ),
    ),
    'custom.user.main_760x_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x_phone',
      ),
    ),
  );
  $export['main760x'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'main_1280x510';
  $picture_mapping->machine_name = 'main_1280x510';
  $picture_mapping->breakpoint_group = 'main_1280x510';
  $picture_mapping->mapping = array(
    'custom.user.main_1280x510_wide_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide_webp_retina',
      ),
    ),
    'custom.user.main_1280x510_wide_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide_webp',
      ),
    ),
    'custom.user.main_1280x510_wide_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide_retina',
      ),
    ),
    'custom.user.main_1280x510_wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_wide',
      ),
    ),
    'custom.user.main_1280x510_desktop_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop_webp_retina',
      ),
    ),
    'custom.user.main_1280x510_desktop_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop_webp',
      ),
    ),
    'custom.user.main_1280x510_desktop_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop_retina',
      ),
    ),
    'custom.user.main_1280x510_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_desktop',
      ),
    ),
    'custom.user.main_1280x510_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet_webp_retina',
      ),
    ),
    'custom.user.main_1280x510_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet_webp',
      ),
    ),
    'custom.user.main_1280x510_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet_retina',
      ),
    ),
    'custom.user.main_1280x510_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_tablet',
      ),
    ),
    'custom.user.main_1280x510_small_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet_webp_retina',
      ),
    ),
    'custom.user.main_1280x510_small_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet_webp',
      ),
    ),
    'custom.user.main_1280x510_small_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet_retina',
      ),
    ),
    'custom.user.main_1280x510_small_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_small_tablet',
      ),
    ),
    'custom.user.main_1280x510_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone_webp_retina',
      ),
    ),
    'custom.user.main_1280x510_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone_webp',
      ),
    ),
    'custom.user.main_1280x510_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone_retina',
      ),
    ),
    'custom.user.main_1280x510_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_smartphone',
      ),
    ),
    'custom.user.main_1280x510_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone_webp_retina',
      ),
    ),
    'custom.user.main_1280x510_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone_webp',
      ),
    ),
    'custom.user.main_1280x510_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone_retina',
      ),
    ),
    'custom.user.main_1280x510_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_1280x510_phone',
      ),
    ),
  );
  $export['main_1280x510'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'main_200x125';
  $picture_mapping->machine_name = 'main_200x125';
  $picture_mapping->breakpoint_group = 'main_200x125';
  $picture_mapping->mapping = array(
    'custom.user.main_200x125_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_200x125_phone_webp_retina',
      ),
    ),
    'custom.user.main_200x125_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_200x125_phone_webp',
      ),
    ),
    'custom.user.main_200x125_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_200x125_phone_retina',
      ),
    ),
    'custom.user.main_200x125_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_200x125_phone',
      ),
    ),
  );
  $export['main_200x125'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'main_280x280';
  $picture_mapping->machine_name = 'main_280x280';
  $picture_mapping->breakpoint_group = 'main_280x280';
  $picture_mapping->mapping = array(
    'custom.user.main_280x280_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_280x280_phone_webp_retina',
      ),
    ),
    'custom.user.main_280x280_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_280x280_phone_webp',
      ),
    ),
    'custom.user.main_280x280_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_280x280_phone_retina',
      ),
    ),
    'custom.user.main_280x280_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_280x280_phone',
      ),
    ),
  );
  $export['main_280x280'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'main_360x200';
  $picture_mapping->machine_name = 'main_360x200';
  $picture_mapping->breakpoint_group = 'main_360x200';
  $picture_mapping->mapping = array(
    'custom.user.main_360x200_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_smartphone_webp_retina',
      ),
    ),
    'custom.user.main_360x200_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_smartphone_webp',
      ),
    ),
    'custom.user.main_360x200_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_smartphone_retina',
      ),
    ),
    'custom.user.main_360x200_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_smartphone',
      ),
    ),
    'custom.user.main_360x200_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_phone_webp_retina',
      ),
    ),
    'custom.user.main_360x200_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_phone_webp',
      ),
    ),
    'custom.user.main_360x200_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_phone_retina',
      ),
    ),
    'custom.user.main_360x200_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_360x200_phone',
      ),
    ),
  );
  $export['main_360x200'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'main_380x215';
  $picture_mapping->machine_name = 'main_380x215';
  $picture_mapping->breakpoint_group = 'main_380x215';
  $picture_mapping->mapping = array(
    'custom.user.main_380x215_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_smartphone_webp_retina',
      ),
    ),
    'custom.user.main_380x215_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_smartphone_webp',
      ),
    ),
    'custom.user.main_380x215_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_smartphone_retina',
      ),
    ),
    'custom.user.main_380x215_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_smartphone',
      ),
    ),
    'custom.user.main_380x215_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_phone_webp_retina',
      ),
    ),
    'custom.user.main_380x215_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_phone_webp',
      ),
    ),
    'custom.user.main_380x215_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_phone_retina',
      ),
    ),
    'custom.user.main_380x215_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_380x215_phone',
      ),
    ),
  );
  $export['main_380x215'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'main_760x377';
  $picture_mapping->machine_name = 'main_760x377';
  $picture_mapping->breakpoint_group = 'main_760x377';
  $picture_mapping->mapping = array(
    'custom.user.main_760x377_small_tablet_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_small_tablet_webp_retina',
      ),
    ),
    'custom.user.main_760x377_small_tablet_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_small_tablet_webp',
      ),
    ),
    'custom.user.main_760x377_small_tablet_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_small_tablet_retina',
      ),
    ),
    'custom.user.main_760x377_small_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_small_tablet',
      ),
    ),
    'custom.user.main_760x377_smartphone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_smartphone_webp_retina',
      ),
    ),
    'custom.user.main_760x377_smartphone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_smartphone_webp',
      ),
    ),
    'custom.user.main_760x377_smartphone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_smartphone_retina',
      ),
    ),
    'custom.user.main_760x377_smartphone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_smartphone',
      ),
    ),
    'custom.user.main_760x377_phone_webp_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_phone_webp_retina',
      ),
    ),
    'custom.user.main_760x377_phone_webp' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_phone_webp',
      ),
    ),
    'custom.user.main_760x377_phone_retina' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_phone_retina',
      ),
    ),
    'custom.user.main_760x377_phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'main_760x377_phone',
      ),
    ),
  );
  $export['main_760x377'] = $picture_mapping;

  return $export;
}
