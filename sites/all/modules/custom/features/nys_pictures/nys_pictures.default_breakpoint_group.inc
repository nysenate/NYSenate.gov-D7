<?php
/**
 * @file
 * nys_pictures.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function nys_pictures_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = '160x160';
  $breakpoint_group->name = '160x160';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.160x160_phone_webp_retina',
    1 => 'custom.user.160x160_phone_webp',
    2 => 'custom.user.160x160_phone_retina',
    3 => 'custom.user.160x160_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['160x160'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = '400x240';
  $breakpoint_group->name = '400x240';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.400x240_smartphone_webp_retina',
    1 => 'custom.user.400x240_smartphone_webp',
    2 => 'custom.user.400x240_smartphone_retina',
    3 => 'custom.user.400x240_smartphone',
    4 => 'custom.user.400x240_phone_webp_retina',
    5 => 'custom.user.400x240_phone_webp',
    6 => 'custom.user.400x240_phone_retina',
    7 => 'custom.user.400x240_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['400x240'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = '45x45';
  $breakpoint_group->name = '45x45';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.45x45_phone_webp_retina',
    1 => 'custom.user.45x45_phone_webp',
    2 => 'custom.user.45x45_phone_retina',
    3 => 'custom.user.45x45_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['45x45'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = '60x60';
  $breakpoint_group->name = '60x60';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.60x60_phone_webp_retina',
    1 => 'custom.user.60x60_phone_webp',
    2 => 'custom.user.60x60_phone_retina',
    3 => 'custom.user.60x60_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['60x60'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'embed_landscape';
  $breakpoint_group->name = 'embed_landscape';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.embed_landscape_smartphone_webp_retina',
    1 => 'custom.user.embed_landscape_smartphone_webp',
    2 => 'custom.user.embed_landscape_smartphone_retina',
    3 => 'custom.user.embed_landscape_smartphone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['embed_landscape'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'embed_portrait';
  $breakpoint_group->name = 'embed_portrait';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.embed_portrait_smartphone_webp_retina',
    1 => 'custom.user.embed_portrait_smartphone_webp',
    2 => 'custom.user.embed_portrait_smartphone_retina',
    3 => 'custom.user.embed_portrait_smartphone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['embed_portrait'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'embed_signature';
  $breakpoint_group->name = 'embed_signature';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.embed_signature_smartphone_webp_retina_',
    1 => 'custom.user.embed_signature_smartphone_webp',
    2 => 'custom.user.embed_signature_smartphone_retina',
    3 => 'custom.user.embed_signature_smartphone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['embed_signature'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'embed_square';
  $breakpoint_group->name = 'embed_square';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.embed_square_smartphone_webp_retina_',
    1 => 'custom.user.embed_square_smartphone_webp',
    2 => 'custom.user.embed_square_smartphone_retina',
    3 => 'custom.user.embed_square_smartphone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['embed_square'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'hero_1280x510';
  $breakpoint_group->name = 'hero_1280x510';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.hero_1280x510_wide_webp_retina',
    1 => 'custom.user.hero_1280x510_wide_webp',
    2 => 'custom.user.hero_1280x510_wide_retina',
    3 => 'custom.user.hero_1280x510_wide',
    4 => 'custom.user.hero_1280x510_desktop_webp_retina',
    5 => 'custom.user.hero_1280x510_desktop_webp',
    6 => 'custom.user.hero_1280x510_desktop_retina',
    7 => 'custom.user.hero_1280x510_desktop',
    8 => 'custom.user.hero_1280x510_tablet_webp_retina',
    9 => 'custom.user.hero_1280x510_tablet_webp',
    10 => 'custom.user.hero_1280x510_tablet_retina',
    11 => 'custom.user.hero_1280x510_tablet',
    12 => 'custom.user.hero_1280x510_small_tablet_webp_retina',
    13 => 'custom.user.hero_1280x510_small_tablet_webp',
    14 => 'custom.user.hero_1280x510_small_tablet_retina',
    15 => 'custom.user.hero_1280x510_small_tablet',
    16 => 'custom.user.hero_1280x510_smartphone_webp_retina',
    17 => 'custom.user.hero_1280x510_smartphone_webp',
    18 => 'custom.user.hero_1280x510_smartphone_retina',
    19 => 'custom.user.hero_1280x510_smartphone',
    20 => 'custom.user.hero_1280x510_phone_webp_retina',
    21 => 'custom.user.hero_1280x510_phone_webp',
    22 => 'custom.user.hero_1280x510_phone_retina',
    23 => 'custom.user.hero_1280x510_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['hero_1280x510'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'hero_1346x330';
  $breakpoint_group->name = 'hero_1346x330';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.hero_1346x330_wide_webp_retina',
    1 => 'custom.user.hero_1346x330_wide_webp',
    2 => 'custom.user.hero_1346x330_wide_retina',
    3 => 'custom.user.hero_1346x330_wide',
    4 => 'custom.user.hero_1346x330_desktop_webp_retina',
    5 => 'custom.user.hero_1346x330_desktop_webp',
    6 => 'custom.user.hero_1346x330_desktop_retina',
    7 => 'custom.user.hero_1346x330_desktop',
    8 => 'custom.user.hero_1346x330_tablet_webp_retina',
    9 => 'custom.user.hero_1346x330_tablet_webp',
    10 => 'custom.user.hero_1346x330_tablet_retina',
    11 => 'custom.user.hero_1346x330_tablet',
    12 => 'custom.user.hero_1346x330_small_tablet_webp_retina',
    13 => 'custom.user.hero_1346x330_small_tablet_webp',
    14 => 'custom.user.hero_1346x330_small_tablet_retina',
    15 => 'custom.user.hero_1346x330_small_tablet',
    16 => 'custom.user.hero_1346x330_smartphone_webp_retina',
    17 => 'custom.user.hero_1346x330_smartphone_webp',
    18 => 'custom.user.hero_1346x330_smartphone_retina',
    19 => 'custom.user.hero_1346x330_smartphone',
    20 => 'custom.user.hero_1346x330_phone_webp_retina',
    21 => 'custom.user.hero_1346x330_phone_webp',
    22 => 'custom.user.hero_1346x330_phone_retina',
    23 => 'custom.user.hero_1346x330_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['hero_1346x330'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'hero_680x510';
  $breakpoint_group->name = 'hero_680x510';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.hero_680x510_small_tablet_webp_retina',
    1 => 'custom.user.hero_680x510_small_tablet_webp',
    2 => 'custom.user.hero_680x510_small_tablet_retina',
    3 => 'custom.user.hero_680x510_small_tablet',
    4 => 'custom.user.hero_680x510_smartphone_webp_retina',
    5 => 'custom.user.hero_680x510_smartphone_webp',
    6 => 'custom.user.hero_680x510_smartphone_retina',
    7 => 'custom.user.hero_680x510_smartphone',
    8 => 'custom.user.hero_680x510_phone_webp_retina',
    9 => 'custom.user.hero_680x510_phone_webp',
    10 => 'custom.user.hero_680x510_phone_retina',
    11 => 'custom.user.hero_680x510_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['hero_680x510'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'main760x';
  $breakpoint_group->name = 'main760x';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.main_760x_small_tablet_webp_retina',
    1 => 'custom.user.main_760x_small_tablet_webp',
    2 => 'custom.user.main_760x_small_tablet_retina',
    3 => 'custom.user.main_760x_small_tablet',
    4 => 'custom.user.main_760x_smartphone_webp_retina',
    5 => 'custom.user.main_760x_smartphone_webp',
    6 => 'custom.user.main_760x_smartphone_retina',
    7 => 'custom.user.main_760x_smartphone',
    8 => 'custom.user.main_760x_phone_webp_retina',
    9 => 'custom.user.main_760x_phone_webp',
    10 => 'custom.user.main_760x_phone_retina',
    11 => 'custom.user.main_760x_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['main760x'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'main_1280x510';
  $breakpoint_group->name = 'main_1280x510';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.main_1280x510_wide_webp_retina',
    1 => 'custom.user.main_1280x510_wide_webp',
    2 => 'custom.user.main_1280x510_wide_retina',
    3 => 'custom.user.main_1280x510_wide',
    4 => 'custom.user.main_1280x510_desktop_webp_retina',
    5 => 'custom.user.main_1280x510_desktop_webp',
    6 => 'custom.user.main_1280x510_desktop_retina',
    7 => 'custom.user.main_1280x510_desktop',
    8 => 'custom.user.main_1280x510_tablet_webp_retina',
    9 => 'custom.user.main_1280x510_tablet_webp',
    10 => 'custom.user.main_1280x510_tablet_retina',
    11 => 'custom.user.main_1280x510_tablet',
    12 => 'custom.user.main_1280x510_small_tablet_webp_retina',
    13 => 'custom.user.main_1280x510_small_tablet_webp',
    14 => 'custom.user.main_1280x510_small_tablet_retina',
    15 => 'custom.user.main_1280x510_small_tablet',
    16 => 'custom.user.main_1280x510_smartphone_webp_retina',
    17 => 'custom.user.main_1280x510_smartphone_webp',
    18 => 'custom.user.main_1280x510_smartphone_retina',
    19 => 'custom.user.main_1280x510_smartphone',
    20 => 'custom.user.main_1280x510_phone_webp_retina',
    21 => 'custom.user.main_1280x510_phone_webp',
    22 => 'custom.user.main_1280x510_phone_retina',
    23 => 'custom.user.main_1280x510_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['main_1280x510'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'main_200x125';
  $breakpoint_group->name = 'main_200x125';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.main_200x125_phone_webp_retina',
    1 => 'custom.user.main_200x125_phone_webp',
    2 => 'custom.user.main_200x125_phone_retina',
    3 => 'custom.user.main_200x125_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['main_200x125'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'main_280x280';
  $breakpoint_group->name = 'main_280x280';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.main_280x280_phone_webp_retina',
    1 => 'custom.user.main_280x280_phone_webp',
    2 => 'custom.user.main_280x280_phone_retina',
    3 => 'custom.user.main_280x280_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['main_280x280'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'main_360x200';
  $breakpoint_group->name = 'main_360x200';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.main_360x200_smartphone_webp_retina',
    1 => 'custom.user.main_360x200_smartphone_webp',
    2 => 'custom.user.main_360x200_smartphone_retina',
    3 => 'custom.user.main_360x200_smartphone',
    4 => 'custom.user.main_360x200_phone_webp_retina',
    5 => 'custom.user.main_360x200_phone_webp',
    6 => 'custom.user.main_360x200_phone_retina',
    7 => 'custom.user.main_360x200_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['main_360x200'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'main_380x215';
  $breakpoint_group->name = 'main_380x215';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.main_380x215_smartphone_webp_retina',
    1 => 'custom.user.main_380x215_smartphone_webp',
    2 => 'custom.user.main_380x215_smartphone_retina',
    3 => 'custom.user.main_380x215_smartphone',
    4 => 'custom.user.main_380x215_phone_webp_retina',
    5 => 'custom.user.main_380x215_phone_webp',
    6 => 'custom.user.main_380x215_phone_retina',
    7 => 'custom.user.main_380x215_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['main_380x215'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'main_760x377';
  $breakpoint_group->name = 'main_760x377';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.main_760x377_small_tablet_webp_retina',
    1 => 'custom.user.main_760x377_small_tablet_webp',
    2 => 'custom.user.main_760x377_small_tablet_retina',
    3 => 'custom.user.main_760x377_small_tablet',
    4 => 'custom.user.main_760x377_smartphone_webp_retina',
    5 => 'custom.user.main_760x377_smartphone_webp',
    6 => 'custom.user.main_760x377_smartphone_retina',
    7 => 'custom.user.main_760x377_smartphone',
    8 => 'custom.user.main_760x377_phone_webp_retina',
    9 => 'custom.user.main_760x377_phone_webp',
    10 => 'custom.user.main_760x377_phone_retina',
    11 => 'custom.user.main_760x377_phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['main_760x377'] = $breakpoint_group;

  return $export;
}
