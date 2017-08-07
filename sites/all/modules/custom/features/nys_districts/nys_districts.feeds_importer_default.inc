<?php
/**
 * @file
 * nys_districts.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nys_districts_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'district_import';
  $feeds_importer->config = array(
    'name' => 'District Import',
    'description' => 'import districts from SAGE',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '300',
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.districts.*',
        'sources' => array(
          'jsonpath_parser:0' => 'name',
          'jsonpath_parser:1' => 'district',
          'jsonpath_parser:3' => 'member.shortName',
          'jsonpath_parser:4' => 'district',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:4' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'field_district_number',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'entityreference:field_senator',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:4',
            'target' => 'field_map_url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'districts',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['district_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'senator_importer';
  $feeds_importer->config = array(
    'name' => 'Senator Importer',
    'description' => 'An importer for Senators',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml json',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.senators.*.senator',
        'sources' => array(
          'jsonpath_parser:0' => 'guid',
          'jsonpath_parser:3' => 'title',
          'jsonpath_parser:1' => 'body',
          'jsonpath_parser:10' => 'shortname',
        ),
        'debug' => array(
          'options' => array(
            'context' => 'context',
            'jsonpath_parser:0' => 'jsonpath_parser:0',
            'jsonpath_parser:3' => 'jsonpath_parser:3',
            'jsonpath_parser:1' => 'jsonpath_parser:1',
            'jsonpath_parser:10' => 'jsonpath_parser:10',
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'body',
            'format' => 'full_html',
          ),
          5 => array(
            'source' => 'jsonpath_parser:10',
            'target' => 'field_shortname',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'senator',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['senator_importer'] = $feeds_importer;

  return $export;
}
