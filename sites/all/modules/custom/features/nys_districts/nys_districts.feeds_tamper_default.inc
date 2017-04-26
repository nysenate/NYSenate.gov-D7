<?php
/**
 * @file
 * nys_districts.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function nys_districts_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'district_import-jsonpath_parser_1-cast_to_int';
  $feeds_tamper->importer = 'district_import';
  $feeds_tamper->source = 'jsonpath_parser:1';
  $feeds_tamper->plugin_id = 'cast_to_int';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Cast to integer';
  $export['district_import-jsonpath_parser_1-cast_to_int'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'district_import-jsonpath_parser_3-efq_finder';
  $feeds_tamper->importer = 'district_import';
  $feeds_tamper->source = 'jsonpath_parser:3';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'node',
    'bundle' => 'senator',
    'field' => 'field_shortname',
    'column' => 'value',
    'property' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['district_import-jsonpath_parser_3-efq_finder'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'district_import-jsonpath_parser_4-rewrite';
  $feeds_tamper->importer = 'district_import';
  $feeds_tamper->source = 'jsonpath_parser:4';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'http://pubgeo.nysenate.gov/map/senate/[jsonpath_parser:4]?x=732&y=414;sd=[jsonpath_parser:4]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['district_import-jsonpath_parser_4-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'senator_importer-jsonpath_parser_13-trim';
  $feeds_tamper->importer = 'senator_importer';
  $feeds_tamper->source = 'jsonpath_parser:13';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['senator_importer-jsonpath_parser_13-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'senator_importer-jsonpath_parser_14-trim';
  $feeds_tamper->importer = 'senator_importer';
  $feeds_tamper->source = 'jsonpath_parser:14';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['senator_importer-jsonpath_parser_14-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'senator_importer-jsonpath_parser_15-trim';
  $feeds_tamper->importer = 'senator_importer';
  $feeds_tamper->source = 'jsonpath_parser:15';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['senator_importer-jsonpath_parser_15-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'senator_importer-jsonpath_parser_16-efq_finder';
  $feeds_tamper->importer = 'senator_importer';
  $feeds_tamper->source = 'jsonpath_parser:16';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'taxonomy_term',
    'bundle' => 'districts',
    'field' => 'field_district_number',
    'column' => 'value',
    'property' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['senator_importer-jsonpath_parser_16-efq_finder'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'senator_importer_debug-jsonpath_parser_13-efq_finder';
  $feeds_tamper->importer = 'senator_importer_debug';
  $feeds_tamper->source = 'jsonpath_parser:13';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'taxonomy_term',
    'bundle' => 'districts',
    'field' => 'field_district_number',
    'column' => 'value',
    'property' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['senator_importer_debug-jsonpath_parser_13-efq_finder'] = $feeds_tamper;

  return $export;
}
