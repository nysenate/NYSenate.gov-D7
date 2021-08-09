<?php
/**
 * @file
 * nys_pictures.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function nys_pictures_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.160x160_phone';
  $breakpoint->name = '160x160_phone';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.160x160_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.160x160_phone_retina';
  $breakpoint->name = '160x160_phone_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.160x160_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.160x160_phone_webp';
  $breakpoint->name = '160x160_phone_webp';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.160x160_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.160x160_phone_webp_retina';
  $breakpoint->name = '160x160_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.160x160_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_phone';
  $breakpoint->name = '400x240_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_phone_retina';
  $breakpoint->name = '400x240_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_phone_webp';
  $breakpoint->name = '400x240_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_phone_webp_retina';
  $breakpoint->name = '400x240_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_smartphone';
  $breakpoint->name = '400x240_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_smartphone_retina';
  $breakpoint->name = '400x240_smartphone_retina';
  $breakpoint->breakpoint = ' (min-width: 321px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_smartphone_webp';
  $breakpoint->name = '400x240_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.400x240_smartphone_webp_retina';
  $breakpoint->name = '400x240_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.400x240_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.45x45_phone';
  $breakpoint->name = '45x45_phone';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.45x45_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.45x45_phone_retina';
  $breakpoint->name = '45x45_phone_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.45x45_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.45x45_phone_webp';
  $breakpoint->name = '45x45_phone_webp';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.45x45_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.45x45_phone_webp_retina';
  $breakpoint->name = '45x45_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.45x45_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.60x60_phone';
  $breakpoint->name = '60x60_phone';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.60x60_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.60x60_phone_retina';
  $breakpoint->name = '60x60_phone_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.60x60_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.60x60_phone_webp';
  $breakpoint->name = '60x60_phone_webp';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.60x60_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.60x60_phone_webp_retina';
  $breakpoint->name = '60x60_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.60x60_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_landscape_smartphone';
  $breakpoint->name = 'embed_landscape_smartphone';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_landscape_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_landscape_smartphone_retina';
  $breakpoint->name = 'embed_landscape_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_landscape_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_landscape_smartphone_webp';
  $breakpoint->name = 'embed_landscape_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_landscape_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_landscape_smartphone_webp_retina';
  $breakpoint->name = 'embed_landscape_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_landscape_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_portrait_smartphone';
  $breakpoint->name = 'embed_portrait_smartphone';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_portrait_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_portrait_smartphone_retina';
  $breakpoint->name = 'embed_portrait_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_portrait_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_portrait_smartphone_webp';
  $breakpoint->name = 'embed_portrait_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_portrait_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_portrait_smartphone_webp_retina';
  $breakpoint->name = 'embed_portrait_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_portrait_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_signature_smartphone';
  $breakpoint->name = 'embed_signature_smartphone';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_signature_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_signature_smartphone_retina';
  $breakpoint->name = 'embed_signature_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_signature_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_signature_smartphone_webp';
  $breakpoint->name = 'embed_signature_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_signature_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_signature_smartphone_webp_retina_';
  $breakpoint->name = 'embed_signature_smartphone_webp_retina ';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_signature_smartphone_webp_retina_'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_square_smartphone';
  $breakpoint->name = 'embed_square_smartphone';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_square_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_square_smartphone_retina';
  $breakpoint->name = 'embed_square_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_square_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_square_smartphone_webp';
  $breakpoint->name = 'embed_square_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_square_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.embed_square_smartphone_webp_retina_';
  $breakpoint->name = 'embed_square_smartphone_webp_retina ';
  $breakpoint->breakpoint = '(min-width: 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.embed_square_smartphone_webp_retina_'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_desktop';
  $breakpoint->name = 'hero_1280x510_desktop';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_desktop'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_desktop_retina';
  $breakpoint->name = 'hero_1280x510_desktop_retina';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_desktop_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_desktop_webp';
  $breakpoint->name = 'hero_1280x510_desktop_webp';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_desktop_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_desktop_webp_retina';
  $breakpoint->name = 'hero_1280x510_desktop_webp_retina';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_desktop_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_phone';
  $breakpoint->name = 'hero_1280x510_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_phone_retina';
  $breakpoint->name = 'hero_1280x510_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_phone_webp';
  $breakpoint->name = 'hero_1280x510_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_phone_webp_retina';
  $breakpoint->name = 'hero_1280x510_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_small_tablet';
  $breakpoint->name = 'hero_1280x510_small_tablet';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_small_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_small_tablet_retina';
  $breakpoint->name = 'hero_1280x510_small_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_small_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_small_tablet_webp';
  $breakpoint->name = 'hero_1280x510_small_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_small_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_small_tablet_webp_retina';
  $breakpoint->name = 'hero_1280x510_small_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_small_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_smartphone';
  $breakpoint->name = 'hero_1280x510_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_smartphone_retina';
  $breakpoint->name = 'hero_1280x510_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_smartphone_webp';
  $breakpoint->name = 'hero_1280x510_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_smartphone_webp_retina';
  $breakpoint->name = 'hero_1280x510_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_tablet';
  $breakpoint->name = 'hero_1280x510_tablet';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_tablet_retina';
  $breakpoint->name = 'hero_1280x510_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_tablet_webp';
  $breakpoint->name = 'hero_1280x510_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_tablet_webp_retina';
  $breakpoint->name = 'hero_1280x510_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_wide';
  $breakpoint->name = 'hero_1280x510_wide';
  $breakpoint->breakpoint = '(min-width: 1201px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_wide'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_wide_retina';
  $breakpoint->name = 'hero_1280x510_wide_retina';
  $breakpoint->breakpoint = '(min-width: 1201px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_wide_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_wide_webp';
  $breakpoint->name = 'hero_1280x510_wide_webp';
  $breakpoint->breakpoint = '(min-width: 1201px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_wide_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1280x510_wide_webp_retina';
  $breakpoint->name = 'hero_1280x510_wide_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1201px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1280x510_wide_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_desktop';
  $breakpoint->name = 'hero_1346x330_desktop';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_desktop'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_desktop_retina';
  $breakpoint->name = 'hero_1346x330_desktop_retina';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_desktop_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_desktop_webp';
  $breakpoint->name = 'hero_1346x330_desktop_webp';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_desktop_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_desktop_webp_retina';
  $breakpoint->name = 'hero_1346x330_desktop_webp_retina';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_desktop_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_phone';
  $breakpoint->name = 'hero_1346x330_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_phone_retina';
  $breakpoint->name = 'hero_1346x330_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_phone_webp';
  $breakpoint->name = 'hero_1346x330_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_phone_webp_retina';
  $breakpoint->name = 'hero_1346x330_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_small_tablet';
  $breakpoint->name = 'hero_1346x330_small_tablet';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_small_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_small_tablet_retina';
  $breakpoint->name = 'hero_1346x330_small_tablet_retina';
  $breakpoint->breakpoint = ' (min-width: 481px) and (max-width: 768px)  and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_small_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_small_tablet_webp';
  $breakpoint->name = 'hero_1346x330_small_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_small_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_small_tablet_webp_retina';
  $breakpoint->name = 'hero_1346x330_small_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px)  and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_small_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_smartphone';
  $breakpoint->name = 'hero_1346x330_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_smartphone_retina';
  $breakpoint->name = 'hero_1346x330_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_smartphone_webp';
  $breakpoint->name = 'hero_1346x330_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_smartphone_webp_retina';
  $breakpoint->name = 'hero_1346x330_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_tablet';
  $breakpoint->name = 'hero_1346x330_tablet';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_tablet_retina';
  $breakpoint->name = 'hero_1346x330_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_tablet_webp';
  $breakpoint->name = 'hero_1346x330_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_tablet_webp_retina';
  $breakpoint->name = 'hero_1346x330_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_wide';
  $breakpoint->name = 'hero_1346x330_wide';
  $breakpoint->breakpoint = '(min-width: 1201px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_wide'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_wide_retina';
  $breakpoint->name = 'hero_1346x330_wide_retina';
  $breakpoint->breakpoint = '(min-width: 1201px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_wide_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_wide_webp';
  $breakpoint->name = 'hero_1346x330_wide_webp';
  $breakpoint->breakpoint = '(min-width: 1201px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_wide_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_1346x330_wide_webp_retina';
  $breakpoint->name = 'hero_1346x330_wide_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1201px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_1346x330_wide_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_phone';
  $breakpoint->name = 'hero_680x510_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_phone_retina';
  $breakpoint->name = 'hero_680x510_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_phone_webp';
  $breakpoint->name = 'hero_680x510_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_phone_webp_retina';
  $breakpoint->name = 'hero_680x510_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_small_tablet';
  $breakpoint->name = 'hero_680x510_small_tablet';
  $breakpoint->breakpoint = '(min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_small_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_small_tablet_retina';
  $breakpoint->name = 'hero_680x510_small_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_small_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_small_tablet_webp';
  $breakpoint->name = 'hero_680x510_small_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_small_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_small_tablet_webp_retina';
  $breakpoint->name = 'hero_680x510_small_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_small_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_smartphone';
  $breakpoint->name = 'hero_680x510_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_smartphone_retina';
  $breakpoint->name = 'hero_680x510_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_smartphone_webp';
  $breakpoint->name = 'hero_680x510_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.hero_680x510_smartphone_webp_retina';
  $breakpoint->name = 'hero_680x510_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.hero_680x510_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_desktop';
  $breakpoint->name = 'main_1280x510_desktop';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_desktop'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_desktop_retina';
  $breakpoint->name = 'main_1280x510_desktop_retina';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_desktop_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_desktop_webp';
  $breakpoint->name = 'main_1280x510_desktop_webp';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_desktop_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_desktop_webp_retina';
  $breakpoint->name = 'main_1280x510_desktop_webp_retina';
  $breakpoint->breakpoint = '(min-width: 993px) and (max-width: 1200px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_desktop_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_phone';
  $breakpoint->name = 'main_1280x510_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_phone_retina';
  $breakpoint->name = 'main_1280x510_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_phone_webp';
  $breakpoint->name = 'main_1280x510_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_phone_webp_retina';
  $breakpoint->name = 'main_1280x510_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_small_tablet';
  $breakpoint->name = 'main_1280x510_small_tablet';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_small_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_small_tablet_retina';
  $breakpoint->name = 'main_1280x510_small_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_small_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_small_tablet_webp';
  $breakpoint->name = 'main_1280x510_small_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_small_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_small_tablet_webp_retina';
  $breakpoint->name = 'main_1280x510_small_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (max-width: 768px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_small_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_smartphone';
  $breakpoint->name = 'main_1280x510_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_smartphone_retina';
  $breakpoint->name = 'main_1280x510_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_smartphone_webp';
  $breakpoint->name = 'main_1280x510_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_smartphone_webp_retina';
  $breakpoint->name = 'main_1280x510_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_tablet';
  $breakpoint->name = 'main_1280x510_tablet';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_tablet_retina';
  $breakpoint->name = 'main_1280x510_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_tablet_webp';
  $breakpoint->name = 'main_1280x510_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_tablet_webp_retina';
  $breakpoint->name = 'main_1280x510_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 769px) and (max-width: 992px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_wide';
  $breakpoint->name = 'main_1280x510_wide';
  $breakpoint->breakpoint = '(min-width: 1201px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_wide'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_wide_retina';
  $breakpoint->name = 'main_1280x510_wide_retina';
  $breakpoint->breakpoint = '(min-width: 1201px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_wide_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_wide_webp';
  $breakpoint->name = 'main_1280x510_wide_webp';
  $breakpoint->breakpoint = '(min-width: 1201px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_wide_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_1280x510_wide_webp_retina';
  $breakpoint->name = 'main_1280x510_wide_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1201px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_1280x510_wide_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_200x125_phone';
  $breakpoint->name = 'main_200x125_phone';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_200x125_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_200x125_phone_retina';
  $breakpoint->name = 'main_200x125_phone_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_200x125_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_200x125_phone_webp';
  $breakpoint->name = 'main_200x125_phone_webp';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_200x125_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_200x125_phone_webp_retina';
  $breakpoint->name = 'main_200x125_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_200x125_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_280x280_phone';
  $breakpoint->name = 'main_280x280_phone';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_280x280_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_280x280_phone_retina';
  $breakpoint->name = 'main_280x280_phone_retina';
  $breakpoint->breakpoint = '(min-width :1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_280x280_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_280x280_phone_webp';
  $breakpoint->name = 'main_280x280_phone_webp';
  $breakpoint->breakpoint = '(min-width : 1px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_280x280_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_280x280_phone_webp_retina';
  $breakpoint->name = 'main_280x280_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width : 1px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_280x280_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_phone';
  $breakpoint->name = 'main_360x200_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_phone_retina';
  $breakpoint->name = 'main_360x200_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_phone_webp';
  $breakpoint->name = 'main_360x200_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_phone_webp_retina';
  $breakpoint->name = 'main_360x200_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_smartphone';
  $breakpoint->name = 'main_360x200_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_smartphone_retina';
  $breakpoint->name = 'main_360x200_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_smartphone_webp';
  $breakpoint->name = 'main_360x200_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_360x200_smartphone_webp_retina';
  $breakpoint->name = 'main_360x200_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_360x200_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_phone';
  $breakpoint->name = 'main_380x215_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_phone_retina';
  $breakpoint->name = 'main_380x215_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_phone_webp';
  $breakpoint->name = 'main_380x215_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_phone_webp_retina';
  $breakpoint->name = 'main_380x215_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_smartphone';
  $breakpoint->name = 'main_380x215_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_smartphone_retina';
  $breakpoint->name = 'main_380x215_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_smartphone_webp';
  $breakpoint->name = 'main_380x215_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_380x215_smartphone_webp_retina';
  $breakpoint->name = 'main_380x215_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_380x215_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_phone';
  $breakpoint->name = 'main_760x377_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_phone_retina';
  $breakpoint->name = 'main_760x377_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_phone_webp';
  $breakpoint->name = 'main_760x377_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_phone_webp_retina';
  $breakpoint->name = 'main_760x377_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_small_tablet';
  $breakpoint->name = 'main_760x377_small_tablet';
  $breakpoint->breakpoint = '(min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_small_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_small_tablet_retina';
  $breakpoint->name = 'main_760x377_small_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_small_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_small_tablet_webp';
  $breakpoint->name = 'main_760x377_small_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_small_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_small_tablet_webp_retina';
  $breakpoint->name = 'main_760x377_small_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_small_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_smartphone';
  $breakpoint->name = 'main_760x377_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_smartphone_retina';
  $breakpoint->name = 'main_760x377_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_smartphone_webp';
  $breakpoint->name = 'main_760x377_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x377_smartphone_webp_retina';
  $breakpoint->name = 'main_760x377_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x377_smartphone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_phone';
  $breakpoint->name = 'main_760x_phone';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_phone_retina';
  $breakpoint->name = 'main_760x_phone_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_phone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_phone_webp';
  $breakpoint->name = 'main_760x_phone_webp';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_phone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_phone_webp_retina';
  $breakpoint->name = 'main_760x_phone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 1px) and (max-width: 320px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_phone_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_small_tablet';
  $breakpoint->name = 'main_760x_small_tablet';
  $breakpoint->breakpoint = '(min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_small_tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_small_tablet_retina';
  $breakpoint->name = 'main_760x_small_tablet_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_small_tablet_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_small_tablet_webp';
  $breakpoint->name = 'main_760x_small_tablet_webp';
  $breakpoint->breakpoint = '(min-width: 481px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_small_tablet_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_small_tablet_webp_retina';
  $breakpoint->name = 'main_760x_small_tablet_webp_retina';
  $breakpoint->breakpoint = '(min-width: 481px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_small_tablet_webp_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_smartphone';
  $breakpoint->name = 'main_760x_smartphone';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_smartphone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_smartphone_retina';
  $breakpoint->name = 'main_760x_smartphone_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_smartphone_retina'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_smartphone_webp';
  $breakpoint->name = 'main_760x_smartphone_webp';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_smartphone_webp'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.main_760x_smartphone_webp_retina';
  $breakpoint->name = 'main_760x_smartphone_webp_retina';
  $breakpoint->breakpoint = '(min-width: 321px) and (max-width: 480px) and (min-resolution: 140dpi)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.main_760x_smartphone_webp_retina'] = $breakpoint;

  return $export;
}
