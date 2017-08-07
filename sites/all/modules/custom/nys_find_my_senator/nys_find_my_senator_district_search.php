<?php

function nys_legislation_explorer_district_search() {
  $vars = array();

  if (isset($_GET['search']) && $_GET['search'] == 'true') {
    // Initialize the data required for the API call.
    $api_data = array(
      'uspsValidate' => 'true',
      'showMembers' => 'true',
    );
    foreach (array('addr1', 'city', 'zip5') as $val) {
      $api_data[$val] = isset($_GET[$val]) ? $_GET[$val] : '';
      $vars[$val] = check_plain($api_data[$val]);
    }
    // Call the SAGE API.
    $sage_return = nys_sage_call_api($api_data);

    // If the address was found and a district assigned, add the senator info for the template.
    if ($sage_return->status == 'SUCCESS' && $sage_return->senateAssigned && $sage_return->uspsValidated) {
      $vars['senator_info'] = get_senator_info_by_shortname($sage_return->districts->senate->senator->shortName);
    }
    $vars['json_resp'] = $sage_return;
    $vars['searched'] = TRUE;
  }

  drupal_set_title("Find My Senator");
  return theme('legislation_explorer_search_district', $vars);
}


/**
 * Cache certain fields from the senator nodes and retrieve them based on the short name. We use the short name
 * because SAGE had the old senate site's data when this was written and the short name was the only thing
 * that was consistent between the two sites. Eventually SAGE should have all of this information in it's own
 * JSON response and so we wont have to do this.
 */
function get_senator_info_by_shortname($shortname) {
  $cache_key = 'nys_legislation_explorer_senator_paths';
  if (cache_get($cache_key) == FALSE) {
    $senators_nodes = node_load_multiple(array(), array('type' => 'senator'));
    $shortname_cache = array();
    foreach ($senators_nodes as &$node) {
      $senator_wrapper = entity_metadata_wrapper('node', $node);
      $shortname_value = $senator_wrapper->field_shortname->value();
      if (!empty($shortname_value)) {
        $field_image_headshot = $senator_wrapper->field_image_headshot->value();
        if (isset($field_image_headshot)) {
          // Getting the filename from the uri because the filename field is not always accurate
          $senator_img_file_name = $field_image_headshot['uri'];
          if (!empty($senator_img_file_name)) {
            $senator_img_file_name = str_replace('public://', '', $senator_img_file_name);
            $senator_img_path = url("/sites/default/files/styles/60x60/public/${senator_img_file_name}");
          }
        }
        $shortname_cache[$shortname_value] =
          array(
            'nid' => $senator_wrapper->nid->value(),
            'path_alias' => url('/', array('absolute' => TRUE)) . drupal_get_path_alias('node/' . $senator_wrapper->nid->value()),
            'image_path' => isset($senator_img_path) ? $senator_img_path : ''
          );
      }
    }
    cache_set($cache_key, $shortname_cache);
  }
  $mappings = cache_get($cache_key)->data;
  if (array_key_exists($shortname, $mappings)) {
    return $mappings[$shortname];
  }
  return FALSE;
}
