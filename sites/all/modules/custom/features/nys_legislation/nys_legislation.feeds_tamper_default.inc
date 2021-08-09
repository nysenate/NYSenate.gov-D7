<?php
/**
 * @file
 * nys_legislation.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function nys_legislation_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'activelist_importer-blank_source_1-default_value';
  $feeds_tamper->importer = 'activelist_importer';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'active',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['activelist_importer-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_14-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:14';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_sponsor',
      'bundle_name' => 'bill',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_importer-jsonpath_parser_14-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_16-string2id';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:16';
  $feeds_tamper->plugin_id = 'string2id';
  $feeds_tamper->settings = array(
    'method' => 'views',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_same_as',
      'bundle_name' => 'bill',
    ),
    'views' => array(
      'view' => 'bills_by_id:default',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into entity ID';
  $export['custom_bills_json_importer-jsonpath_parser_16-string2id'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_33-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:33';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_multisponsors',
      'bundle_name' => 'bill',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_importer-jsonpath_parser_33-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_34-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:34';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_co_sponsors',
      'bundle_name' => 'bill',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_importer-jsonpath_parser_34-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_35-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:35';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_other_sponsors',
      'bundle_name' => 'bill',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_importer-jsonpath_parser_35-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_41-string2id';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:41';
  $feeds_tamper->plugin_id = 'string2id';
  $feeds_tamper->settings = array(
    'method' => 'views',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_bill_amendments',
      'bundle_name' => 'bill',
    ),
    'views' => array(
      'view' => 'bills_by_id:default',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into entity ID';
  $export['custom_bills_json_importer-jsonpath_parser_41-string2id'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_6-truncate_text';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:6';
  $feeds_tamper->plugin_id = 'truncate_text';
  $feeds_tamper->settings = array(
    'num_char' => '250',
    'ellipses' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Truncate';
  $export['custom_bills_json_importer-jsonpath_parser_6-truncate_text'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_8-find_replace';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:8';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'true',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^true$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['custom_bills_json_importer-jsonpath_parser_8-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_8-find_replace2';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:8';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'false',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^false$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['custom_bills_json_importer-jsonpath_parser_8-find_replace2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_9-find_replace';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:9';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'true',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^true$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['custom_bills_json_importer-jsonpath_parser_9-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_importer-jsonpath_parser_9-find_replace2';
  $feeds_tamper->importer = 'custom_bills_json_importer';
  $feeds_tamper->source = 'jsonpath_parser:9';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'false',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^false$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['custom_bills_json_importer-jsonpath_parser_9-find_replace2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_17-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:17';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_absent',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_17-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_18-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:18';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_abstains',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_18-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_19-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:19';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_ayes_voters',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_19-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_20-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:20';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_ayeswr',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_20-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_21-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:21';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_excused',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_21-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_22-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:22';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_nays_voters',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_22-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_3-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:3';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_absent',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_3-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_4-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:4';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_abstains',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_4-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_5-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:5';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_ayes_voters',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_5-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_6-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:6';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_ayeswr',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_6-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_7-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:7';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_excused',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_7-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'custom_bills_json_votes_importer-jsonpath_parser_8-s2id_auto_create';
  $feeds_tamper->importer = 'custom_bills_json_votes_importer';
  $feeds_tamper->source = 'jsonpath_parser:8';
  $feeds_tamper->plugin_id = 's2id_auto_create';
  $feeds_tamper->settings = array(
    'method' => 'autocomplete',
    'autocomplete' => array(
      'entity_type' => NULL,
      'field_name' => 'field_openleg_nays_voters',
      'bundle_name' => 'field_openleg_votes',
    ),
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert string into existent or generated entity ID';
  $export['custom_bills_json_votes_importer-jsonpath_parser_8-s2id_auto_create'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'floor_calendar_importer-blank_source_1-default_value';
  $feeds_tamper->importer = 'floor_calendar_importer';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'floor',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['floor_calendar_importer-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'supplemental_calendar_importer-blank_source_1-default_value';
  $feeds_tamper->importer = 'supplemental_calendar_importer';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'supplemental',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['supplemental_calendar_importer-blank_source_1-default_value'] = $feeds_tamper;

  return $export;
}
