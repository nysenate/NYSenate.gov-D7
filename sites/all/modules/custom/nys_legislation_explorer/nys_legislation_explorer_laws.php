<?php 

/** --- Law Browser Functionality --- */

/**
 * Handles all basic law related functionality including rendering the listings as well
 * as the individual law document pages.
 */
function nys_legislation_explorer_law_search() {
  $vars = array();
  $url_paths = explode("/", current_path());
  $url_path_count = count($url_paths);
  $page_title = "Laws of New York State";
  if ($url_path_count == 2) {
    $vars['law_listings'] = get_law_listings_by_group();
    $vars['view'] = 'listing';
  }
  else if ($url_path_count >= 3) {
    // Ajax requests
    if ($url_paths[2] == 'ajax' && $url_paths[3] == 'search') {
      $search_term = $_GET['term'];
      if ($search_term != null) {
        exit(get_law_search_results_json($_GET['lawId'], $search_term, $_GET['limit'], $_GET['offset']));
      }
      else {
        exit(get_empty_law_search_result());
      }
    }
    // Law tree/doc requests
    else {
      $law_id = $url_paths[2];
      $law_location_id = !empty($url_paths[3]) ? $url_paths[3] : '';
      $vars['view'] = 'law-tree-view';
      $vars['law_info'] = get_law_info($law_id);
      if ($law_location_id) {
        $vars['law_tree'] = get_law_tree_from_node($law_id, $law_location_id, 1);
        $vars['law_doc'] = get_law_doc($law_id, $law_location_id);
      }
      else {
        $vars['law_tree'] = get_law_tree_from_node($law_id, '', '');
        $vars['law_doc'] = get_law_doc($law_id, $vars['law_tree']->documents->locationId);
      }
      $page_title = "{$vars['law_tree']->info->name}";  
    }
  }
  drupal_set_title($page_title);
  return theme('legislation_explorer_search_laws', $vars);
}

/**
 * Returns a string containing the base openleg laws api url.
 */
function get_base_openleg_law_url() {
  $ol_base_url   = variable_get("openleg_base_url");
  $base_url = $ol_base_url . '/api/3/laws';
  return $base_url;
}

/**
 * Returns the string ?key={openleg_key_here} if $is_first_param is true.
 * Otherwise &key={openleg_key_here} will be returned.
 */
function get_openleg_key($is_first_param) {
  $openleg_key = variable_get('openleg_key');
  return (($is_first_param) ? '?' : '&') . 'key=' . $openleg_key; 
}

function law_name_sort($law1, $law2) {
  return strcmp($law1->name, $law2->name);  
}

/**
 * Returns a json listing of all the laws (i.e. law ids and names).
 */
function get_law_listings_by_group() {
  $law_listings = get_law_listings();
  $grouped_law_listings = array();
  foreach($law_listings as $law_id => &$law_info) {
    if (!isset($grouped_law_listings[$law_info->lawType])) {
      $grouped_law_listings[$law_info->lawType] = array();
    }
    array_push($grouped_law_listings[$law_info->lawType], $law_info);
  } 
  foreach($grouped_law_listings as $key => &$arr) {
    usort($arr, 'law_name_sort');
  }  
  return $grouped_law_listings;
}

/**
 * Retrieves the law info given a three letter law id.
 */
function get_law_info($law_id) {
  $listings = get_law_listings();
  return $listings[$law_id];
}

/**
 * Retrieves the law listings from open leg and caches them.
 */
function get_law_listings() {
  $CACHE_KEY = 'nys_legislation_explorer_law_listings';
  $law_listings = cache_get($CACHE_KEY);
  if (!$law_listings) {
    $base_result = file_get_contents(get_base_openleg_law_url() . get_openleg_key(true));
    $json_response = json_decode($base_result);  
    $law_listings = array();
    foreach($json_response->result->items as $k => &$v) {
      $law_listings[$v->lawId] = $v;
    }
    cache_set($CACHE_KEY, $law_listings);
  }
  else {
    $law_listings = $law_listings->data;
  }
  return $law_listings;    
} 

/** 
 * Returns a json node containing the law hierarchy using the given parameters.
 * Params: 
 *   $law_id - The three letter law id
 *   $law_location_id - The location id of the starting node (leave blank for root)
 *   $depth - The depth of the children nodes (set to 1 to view only immediate children law docs).      
 */
function get_law_tree_from_node($law_id, $law_location_id, $depth) {
  $url = get_base_openleg_law_url() . "/{$law_id}/?fromLocation=${law_location_id}&depth={$depth}" . get_openleg_key(false);
  $base_result = file_get_contents($url);
  $law_tree = json_decode($base_result);
  return $law_tree->result;
}

/**
 * Returns a json node containing the actual text body of the given law document.
 * Params:
 *   $law_id - The three letter law id
 *   $law_loc_id - The location id of the law document (obtained from the law tree result)  
 */
function get_law_doc($law_id, $law_loc_id) {
   $url = get_base_openleg_law_url() . "/{$law_id}/{$law_loc_id}/" . get_openleg_key(true);
   $law_doc = json_decode(file_get_contents($url));
   // Clean up law doc text
   $law_doc->result->text = html_format_raw_law_text($law_doc->result->title, $law_doc->result->text);
   return $law_doc->result;
}

/**
 * Returns a simple html formatted view from the raw law document text. This is a solution for rendering 
 * laws nicely when the law xml is not available. 
 */
function html_format_raw_law_text($title, $law_doc_text) {
  if ($law_doc_text) {
    $law_doc_text = preg_replace("/\\\\n\s{2}/", "<br/><br/>&nbsp;&nbsp;", $law_doc_text);
    $law_doc_text = preg_replace("/\\\\n/", " ", $law_doc_text);
  }
  return $law_doc_text;
}

/**
 * Queries open leg for a law search response.
 */
function get_law_search_results_json($law_id, $search_query, $limit = 25, $offset = 1) {
  $url = get_base_openleg_law_url() . (!empty($law_id) ? '/' . $law_id : '') 
         . '/search?term=' . urlencode($search_query) . get_openleg_key(false) . '&limit=' . $limit . 
         '&offset=' . $offset;
  $json = file_get_contents($url);
  return ($json == FALSE) ? get_empty_law_search_result() : $json;  
}

/**
 * Empty law search result json from openleg. Avoids having to make an api request when input is empty. 
 */ 
function get_empty_law_search_result() {
  return '{
    "success": true,
    "message": "",
    "responseType": "empty list",
    "total": 0,
    "offsetStart": 1,
    "offsetEnd": 0,
    "limit": 25,
    "result": {
      "items": [ ],
      "size": 0
    }
  }';
}