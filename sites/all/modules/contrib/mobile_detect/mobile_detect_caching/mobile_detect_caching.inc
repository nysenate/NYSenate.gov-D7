<?php

/**
 * @file
 * Cache backend include for the mobile_detech_caching module.
 */

/**
 * Alters $_SERVER['REQUEST_URI'] to add in the mobile detect results, so that
 * the Drupal page caching system will use them as part of the $cid.
 */
function mobile_detect_caching_alter_cid() {
  @include_once DRUPAL_ROOT . '/sites/all/libraries/Mobile_Detect/Mobile_Detect.php';

  if (class_exists('Mobile_Detect')) {
    try {
      $detect = new Mobile_Detect();

      parse_str($_SERVER['QUERY_STRING'], $query);

      unset($query['mobile_detect_caching_mobile']);
      unset($query['mobile_detect_caching_notmobile']);
      unset($query['mobile_detect_caching_tablet']);
      unset($query['mobile_detect_caching_nottablet']);

      if ($detect->isMobile()) {
        $query['mobile_detect_caching_mobile'] = NULL;
      }
      else {
        $query['mobile_detect_caching_notmobile'] = NULL;
      }

      if ($detect->isTablet()) {
        $query['mobile_detect_caching_tablet'] = NULL;
      }
      else {
        $query['mobile_detect_caching_nottablet'] = NULL;
      }

      $query = _mobile_detect_http_build_query($query);

      if (($i = strpos($_SERVER['REQUEST_URI'], '?')) === FALSE) {
        $_SERVER['REQUEST_URI'] .= '?' . $query;
      }
      else {
        $_SERVER['REQUEST_URI'] = substr($_SERVER['REQUEST_URI'], 0, $i) . '?' . $query;
      }
    } catch (Exception $e) {
      // nop
    }
  }
}

/**
 * Duplicates drupal_http_build_query() because this function isn't available
 * yet (too early in bootstrap).
 */
function _mobile_detect_http_build_query(array $query, $parent = '') {
  $params = array();

  foreach ($query as $key => $value) {
    $key = ($parent ? $parent . '[' . rawurlencode($key) . ']' : rawurlencode($key));

    // Recurse into children.
    if (is_array($value)) {
      $params [] = _mobile_detect_http_build_query($value, $key);
    }
    // If a query parameter value is NULL, only append its key.
    elseif (!isset($value)) {
      $params [] = $key;
    }
    else {
      // For better readability of paths in query strings, we decode slashes.
      $params [] = $key . '=' . str_replace('%2F', '/', rawurlencode($value));
    }
  }

  return implode('&', $params);
}

mobile_detect_caching_alter_cid();
