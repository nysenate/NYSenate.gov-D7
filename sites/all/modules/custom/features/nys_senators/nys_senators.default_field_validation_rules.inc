<?php
/**
 * @file
 * nys_senators.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function nys_senators_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Promo Banner External URL';
  $rule->name = 'promo_banner_external_url';
  $rule->field_name = 'field_external_web_page';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'promotional_banner';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      6 => 0,
      8 => 0,
      9 => 0,
      3 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      14 => 0,
      7 => 0,
      16 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'You must specify a full URL when entering an external web link for your promotional banner.';
  $export['promo_banner_external_url'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Quote length';
  $rule->name = 'quote_length';
  $rule->field_name = 'field_featured_quote';
  $rule->col = 'value';
  $rule->entity_type = 'field_collection_item';
  $rule->bundle = 'field_featured_legislation';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '20',
    'max' => '140',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      6 => 0,
      8 => 0,
      9 => 0,
      3 => 0,
      10 => 0,
      11 => 0,
      13 => 0,
      14 => 0,
      7 => 0,
      16 => 0,
      17 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'The quote entered ("[value]") is [length] characters. Senator quotes must be at least 20 characters and not more than 140 characters.';
  $export['quote_length'] = $rule;

  return $export;
}
