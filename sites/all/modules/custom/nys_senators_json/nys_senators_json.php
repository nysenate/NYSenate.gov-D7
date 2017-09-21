<?php

/**
 * Loads senator nodes and outputs a subset of the data as JSON.
 */
function nys_senators_json() {
  // The array of node IDs to load.  An empty array will load *all* senators.
  $nids = array();

  // Check to see if a valid shortname was passed.  If yes, we want to
  // load just that senator.
  $shortname = arg(1);
  if ($shortname) {
    $ent_query = new EntityFieldQuery();
    try {
      $requested_senator = $ent_query->entityCondition('entity_type', 'node')
        ->fieldCondition('field_shortname', 'value', arg(1))
        ->execute();
    } catch (Exception $e) {
      $requested_senator = array('node' => NULL);
    }

    // If the shortname was valid, set the "nodes to load" variable appropriately.
    if (!empty($requested_senator['node'])) {
      $nids = array_keys($requested_senator['node']);
    }
  }

  // Load senator nids
  $senator_nodes = node_load_multiple($nids, array('type' => 'senator'));

  // Load district vocabulary terms
  $vocabulary = taxonomy_vocabulary_machine_name_load('districts');
  $districts = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
  $districts_by_senator = array();

  // Cache the district mapping for ease-of-use.  SBB: I think there is a
  // function in nys_utils to do this already...
  foreach ($districts as &$district) {
    $district_wrapper = entity_metadata_wrapper('taxonomy_term', $district);
    $senator_nid = $district_wrapper->field_senator->value()->nid;
    $district_code = $district_wrapper->field_district_number->value();
    $districts_by_senator[$senator_nid] = $district_code;
  }

  // Iterate over the loaded senators and create the JSON response.
  $senators_response = array();
  foreach ($senator_nodes as &$senator_node) {
    if (array_key_exists($senator_node->nid, $districts_by_senator)) {
      $senate_district = intval($districts_by_senator[$senator_node->nid]);
      $senator = create_senator_response($senator_node, $senate_district);
      array_push($senators_response, $senator);
    }
  }

  // If there's only one senator, remove the parent array structure.
  if (count($senators_response) == 1) {
    $senators_response = reset($senators_response);
  }

  // Encode to JSON, and push that puppy out.
  $json_response = json_encode($senators_response);
  drupal_add_http_header('Content-Type', 'application/json; charset="UTF-8"');
  drupal_add_http_header('Content-Length', mb_strlen($json_response));

  exit($json_response);
}

/**
 * Constructs and returns an array containing relevant senator data.
 */
function create_senator_response(&$senator_node, $senate_district) {
  $senator_wrapper = entity_metadata_wrapper('node', $senator_node);

  $open_leg_id = $senator_wrapper->field_ol_member_id->value();
  $senator['open_leg_id'] = isset($open_leg_id) ? $open_leg_id : -1;

  $senator['senate_district'] = $senate_district;
  $senator['senate_district_ordinal'] = nys_utils_ordinal_suffix($senate_district);

  $senator['senate_district_url'] = $senate_district > 0
    ? url('/district/' . $senate_district, array('absolute' => TRUE)) : null;
  $senator['url'] = url('/', array('absolute' => TRUE)) . drupal_get_path_alias('node/' . $senator_wrapper->nid->value());
  $senator['is_active'] = !empty($senator['senate_district']);

  $full_name = $senator_wrapper->title->value();
  $senator['full_name'] = isset($full_name) ? $full_name : '';

  $first_name = $senator_wrapper->field_first_name->value();
  $senator['first_name'] = isset($first_name) ? $first_name : '';

  $last_name = $senator_wrapper->field_last_name->value();
  $senator['last_name'] = isset($last_name) ? $last_name : '';

  $short_name = $senator_wrapper->field_shortname->value();
  $senator['short_name'] = isset($short_name) ? $short_name : '';

  $email = $senator_wrapper->field_email->value();
  $senator['email'] = isset($email) ? $email : '';

  $senator['offices'] = array();
  $field_offices = $senator_wrapper->field_offices->value();
  if (isset($field_offices)) {
    foreach ($field_offices as &$office) {
      // Filter out empty offices
      if (!empty($office['street']) || !empty($office['name'])) {
        array_push($senator['offices'], $office);
      }
    }
  }

  $senator['party'] = array();
  $field_parties = $senator_wrapper->field_party->value();
  if (!empty($field_parties)) {
    foreach ($field_parties as &$party) {
      if (is_array($party) && array_key_exists('value', $party)) {
        array_push($senator['party'], $party['value']);
      }
    }
  }

  // Add senator's headshot image.
  $field_image_headshot = $senator_wrapper->field_image_headshot->value();
  $senator_img_path = FALSE;
  if (isset($field_image_headshot) && !empty($field_image_headshot['uri'])) {
    $senator_img_path = nys_senators_json_suppress_image_token(
      image_style_url('160x160', $field_image_headshot['uri'])
    );
  }
  $senator['img'] = $senator_img_path ? $senator_img_path : null;

  // Add senator's microsite "hero" image.
  $field_image_hero = $senator_wrapper->field_image_hero->value();
  $senator_heroimg_path = FALSE;
  if (isset($field_image_hero) && !empty($field_image_hero['uri'])) {
    $senator_heroimg_path = nys_senators_json_suppress_image_token(
      image_style_url('680x510', $field_image_hero['uri'])
    );
  }
  $senator['hero_img'] = $senator_heroimg_path ? $senator_heroimg_path : null;

  // Add custom palette information.
  $palette_name = $senator_wrapper->field_pallette_selector->value();
  $senator['palette'] = array_merge(
    array('name' => $palette_name),
    fetch_palette_map($palette_name)
  );

  // Add current duties/roles.
  $senator['role'] = $senator_wrapper->field_current_duties->value();

  // Add social media links.
  $media_array = array('facebook', 'twitter', 'youtube', 'instagram');
  foreach ($media_array as $val) {
    $property_name = "field_{$val}_url";
    $one_val = $senator_wrapper->$property_name->value();
    if ($one_val) {
      $senator['social_media'][] = array('name' => $val, 'url' => $one_val);
    }
  }

  $summary = $senator_wrapper->body->value();
  $senator['summary'] = isset($summary['safe_summary']) ? $summary['safe_summary'] : '';

  return $senator;
}

/**
 * When passed the name of a microsite custom style, return as array holding the
 * color selections created for that style.  On first call, the SCSS files are
 * read and parse with PREG.  Those results are cached for future reference,
 * keyed by the style name.
 *
 * If the passed $palette_name does not exist as a key, then "trad_blue" is used.
 * If no palette is found, the return array will have all colors set to "#FFFFFF".
 *
 * @param $palette_name Name of the microsite style palette being used.
 *
 * @return array|mixed An array with the light, medium, and dark color values.
 */
function fetch_palette_map($palette_name) {
  $palettes = &drupal_static(__FUNCTION__);

  if (!$palettes) {
    $css = file_get_contents('sites/all/themes/nysenate/scss/base/_senators_pallettes.scss');
    $results = array();
    preg_match_all('/\\$([a-z_]+)_(lgt|med|drk) : (#[a-zA-Z0-9]{6})/', $css, $results);
    $palettes = array();
    if (is_array($results) && count($results) == 4) {
      foreach ($results[1] as $key => $val) {
        if (!array_key_exists($val, $palettes)) {
          $palettes[$val] = array();
        }
        $palettes[$val][$results[2][$key]] = $results[3][$key];
      }
    }
  }

  // Set default palette if one can't be found.
  $ret = array (
    'lgt' => '#FFFFFF',
    'med' => '#FFFFFF',
    'drk' => '#FFFFFF',
  );

  // If the passed palette name does not exist, fall back to "trad_blue".
  if (!array_key_exists($palette_name, $palettes)) {
    $palette_name = 'trad_blue';
  }

  // Overwrite the default if the name is found.
  if (array_key_exists($palette_name, $palettes)) {
    $ret = $palettes[$palette_name];
  }

  return $ret;
}

/**
 * Removes the query string from a URL.  Drupal adds an 'itok' security token
 * to image URLs, which is inappropriate for the JSON export.
 *
 * @param $url Any URL from which to remove the query string.
 * @return bool|string The same URL sans query string, or FALSE on parsing failure.
 */
function nys_senators_json_suppress_image_token($url) {
  if ($parsed_url = parse_url($url)) {
    return $parsed_url['scheme'] . '://' . $parsed_url['host'] . $parsed_url['path'];
  }

  return false;
}
