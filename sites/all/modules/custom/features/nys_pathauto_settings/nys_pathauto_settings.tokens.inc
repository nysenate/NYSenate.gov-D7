<?php
/**
 * @file
 * nys_pathauto_settings.tokens.inc
 */

/**
 * Implements hook_token_info().
 */
function nys_pathauto_settings_token_info() {
  // Bill id tokens
  // Used to map bill nodes to urls
  // Adds a 'version' node token which is subsituted with a bill's amendment version
  $node['amend-version'] = array(
    'name' => t('Amendment Version'),
    'description' => t('The version id of a bill amendment'),
  );

  return array(
    'tokens' => array(
      'node' => $node,
    ),
  );
}

/**
 * Implements hook_tokens().
 * @param $type
 * @param $tokens
 * @param array $data
 * @param array $options
 * @return array
 */
function nys_pathauto_settings_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'node' & !empty($data['node'])) {
    $node = $data['node'];

    foreach ($tokens as $name => $original) {
      // Substitute an amend-version token with the parsed version if the node is a bill
      if ($name == 'amend-version' && $node->type === 'bill') {
        $print_no = $node->field_ol_print_no[LANGUAGE_NONE][0]['value'];
        $print_no_version_pattern = '/^[A-Z]\d+([A-Z]?)/';
        preg_match_all($print_no_version_pattern, $print_no, $print_no_matches);
        $version = $print_no_matches[1][0];
        if (empty($version)) {
          $version = 'original';
        }
        $replacements[$original] = $version;
      }
    }
  }

  return $replacements;
}

