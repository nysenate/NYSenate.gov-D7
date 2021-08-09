<?php

/**
 * @file nys_openleg.inc
 */

use Nys_Openleg\ApiRequest;

// The path to which nys_openleg should respond
const NYS_OPENLEG_MENU_PATH = 'legislation/laws';

// Defaults for URL construction.
const NYS_OPENLEG_DEFAULT_HOST = 'legislation.nysenate.gov';
const NYS_OPENLEG_DEFAULT_VERSION = '3';

// Constants for sort order of OpenLeg result sets
const NYS_OPENLEG_SORT_BY_CODE = 1;
const NYS_OPENLEG_SORT_BY_NAME = 2;

/**
 * Fetches a cache value.
 *
 * @param string $name
 *
 * @return mixed
 */
function _nys_openleg_cache_get($name) {
  return cache_get('openleg:' . $name, 'cache_openleg');
}

/**
 * Sets a cache value, with default retention of 1 day.
 *
 * @param string $name
 * @param mixed $data
 * @param int $retain
 */
function _nys_openleg_cache_set($name, $data, $retain = 86400) {
  cache_set('openleg:' . $name, $data, 'cache_openleg', time() + $retain);
}

/**
 * Fetches a list of all known books of law from OpenLeg API.  The
 * list becomes an array, keyed by the book code (e.g., ABP, PEN),
 * with the values being JSON-decoded objects from the response.
 *
 * @see https://legislation.nysenate.gov/static/docs/html/laws.html#get-a-list-of-law-ids
 *
 * @return array
 */
function _nys_openleg_get_law_books() {
  // Check the cache for an existing list.
  $ret = (_nys_openleg_cache_get('law-tree')->data) ?? [];

  // Call OpenLeg if the cache is not populated.
  if (!$ret) {
    // Call OpenLeg
    $response = ApiRequest::fetch('laws');
    if ($response && ($response->success ?? FALSE)) {
      // Get the items, and re-organize by lawId
      foreach (($response->result->items ?? []) as $val) {
        $ret[$val->lawId] = $val;
      }
      ksort($ret);

      // Save the tree in cache.
      _nys_openleg_cache_set('law-tree', $ret);
    }
  }

  return $ret;
}

/**
 * Retrieve all books belonging to the passed type, e.g., CONSOLIDATED.
 * The $sort parameter can be a property name, or one of the pre-defined
 * constants.
 *
 * @param string $type
 * @param mixed $sort
 *
 * @return array
 */
function _nys_openleg_get_books_by_type($type, $sort = NYS_OPENLEG_SORT_BY_CODE) {
  $books = array_filter(
    _nys_openleg_get_law_books(),
    function ($v) use ($type) {
      return $v->lawType == $type;
    }
  );
  return _nys_openleg_sort_book_list($books, $sort);
}

/**
 * Sorts an array of objects, presumably an array of book entries, but
 * any array of objects will suffice.  The $sort parameter can be one of
 * the pre-defined constants, or the name of a property found in each
 * object.  Sort is always implemented as a string comparison.
 *
 * @param array $list
 * @param mixed $sort
 *
 * @return array
 */
function _nys_openleg_sort_book_list(array $list, $sort = NYS_OPENLEG_SORT_BY_CODE) {
  switch ($sort) {
    case NYS_OPENLEG_SORT_BY_CODE:
      $sort_prop = 'lawId';
      break;
    case NYS_OPENLEG_SORT_BY_NAME:
      $sort_prop = 'name';
      break;
    default:
      $sort_prop = (string) $sort;
      break;
  }
  uasort($list,
    function ($a, $b) use ($sort_prop) {
      return strcmp($a->{$sort_prop}, $b->{$sort_prop});
    }
  );
  return $list;
}

/**
 * Fetches the known law types, based on the population of books
 * from OpenLeg API.
 *
 * @return array
 */
function _nys_openleg_get_law_types() {
  // Get the types from the known books if it is not already set.
  if (!$ret = (_nys_openleg_cache_get('law-types')->data ?? [])) {
    $ret = array_values(array_unique(array_filter(array_map(
      function ($v) {
        return $v->lawType;
      },
      _nys_openleg_get_law_books()
    ))));
    // Store for posterity.
    _nys_openleg_cache_set('law-types', $ret);
  }

  return $ret;
}

/**
 * Returns the "friendly" name for a law type.  Returns a blank string
 * if the type could not be found.  As of 2021, there is no canonical
 * source for these names.
 *
 * @param string $type
 *
 * @return string
 */
function _nys_openleg_get_law_type_name($type) {
  $type_names = [
    'CONSOLIDATED' => 'Consolidated Laws of New York',
    'UNCONSOLIDATED' => 'Unconsolidated Laws of New York',
    'COURT_ACTS' => 'Court Acts of New York',
    'RULES' => 'Legislative House Rules',
    'MISC' => 'Misc / Other',
  ];
  return $type_names[strtoupper($type)] ?? '';
}

/**
 * Generates an array of breadcrumb items.  If no law_type is provided,
 * the return will be an empty array.  With a law_type, the return will
 * have at least the top-level breadcrumb.  If parents is also an array,
 * a second breadcrumb pointing to law_type will be added.  If parents
 * is also populated, each entry generates an additional elements.
 *
 * All elements conform to _nys_openleg_generate_list_item().
 *
 * @param string $law_type
 * @param ?array $parents
 *
 * @return array
 * @see _nys_openleg_generate_list_item()
 *
 */
function _nys_openleg_generate_breadcrumbs($law_type = '', $parents = NULL) {
  $ret = [];
  $type_name = _nys_openleg_get_law_type_name($law_type);
  if ($type_name) {
    $ret[] = [
      'name' => 'The Laws of New York',
      'url' => '/' . NYS_OPENLEG_MENU_PATH . '/all',
    ];
    if (is_array($parents)) {
      $ret[] = [
        'name' => _nys_openleg_get_law_type_name($law_type),
        'url' => '/' . NYS_OPENLEG_MENU_PATH . '/' . $law_type,
      ];
      foreach ($parents as $v) {
        $ret[] = _nys_openleg_list_item_callback_location($v);
      }
    }
  }
  return $ret;
}

/**
 * Prepares an array suitable to be passed to the nys_openleg_result_item
 * theme as a single item.
 *
 * @param $name
 * @param string $description
 * @param string $url
 *
 * @return array
 */
function _nys_openleg_generate_list_item($name, $description = '', $url = '') {
  return [
    'name' => $name,
    'description' => $description,
    'url' => $url,
  ];
}

/**
 * Receives an array of strings, assumed to be the path of the current
 * request.  The first element is the book, the second element is the
 * specific location.  Any other elements are considered "extra".  The
 * "share_path" is the plain absolute link (i.e., no "extra") to the
 * currently requested statute.
 *
 * @param array $args
 *
 * @return array
 */
function _nys_openleg_resolve_path_info(array $args = []) {
  global $base_url;

  $book = check_plain(array_shift($args) ?? 'all');
  $location = check_plain(array_shift($args) ?? '');
  $share_path = implode('/', array_filter([$book, $location]));

  return [
    'book' => $book,
    'location' => $location,
    'extra' => $args,
    'share_path' => $base_url . '/' . NYS_OPENLEG_MENU_PATH . '/' . $share_path,
  ];
}

/**
 * A wrapper around theme() to prevent unhandled exceptions.
 *
 * @param string $theme_name
 * @param array $vars
 *
 * @return string
 */
function _nys_openleg_theme_wrapper($theme_name, $vars = []) {
  try {
    $ret = theme($theme_name, $vars);
  } catch (Throwable $e) {
    watchdog(
      'nys_openleg',
      'Theme Exception while rendering ":theme_name": :msg',
      [
        ':msg' => $e->getMessage(),
        ':theme_name' => $theme_name,
        ':vars' => $vars,
      ],
      WATCHDOG_WARNING
    );
    $ret = '<!-- Exception during theme render; no content -->';
  }
  return $ret;
}

/**
 * A callback wrapper for the preparation of a list of books.
 *
 * @param object $v
 *
 * @return array
 */
function _nys_openleg_list_item_callback_book($v) {
  return _nys_openleg_generate_list_item(
    $v->lawId,
    $v->name,
    '/' . NYS_OPENLEG_MENU_PATH . '/' . $v->lawId,
  );
}

/**
 * A callback wrapper for the preparation of a list of book types.
 *
 * @param string $v
 *
 * @return array
 */
function _nys_openleg_list_item_callback_book_type($v) {
  return _nys_openleg_generate_list_item(
    ucwords(strtolower(str_replace('_', ' ', $v))),
    _nys_openleg_get_law_type_name($v),
    '/' . NYS_OPENLEG_MENU_PATH . '/' . $v,
  );
}

/**
 * A callback wrapper for the preparation of a list of locations.
 *
 * @param object $v
 *
 * @return array
 */
function _nys_openleg_list_item_callback_location($v) {
  $ret = [];
  if ($v) {
    $ret = _nys_openleg_generate_list_item(
      $v->docType . ' ' . $v->docLevelId,
      $v->title,
      '/' . NYS_OPENLEG_MENU_PATH . '/' . $v->lawId . '/' . $v->locationId,
    );
  }
  return $ret;
}
