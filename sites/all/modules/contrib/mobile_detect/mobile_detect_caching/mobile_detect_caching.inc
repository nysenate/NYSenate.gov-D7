<?php

/**
 * @file
 * Cache backend include for the mobile_detect_caching module.
 */

/**
 * Defines a Mobile Detect cache implementation.
 *
 * To use this functionality, the following needs to be added to settings.php
 *
 * @code
 * $conf['cache_backends'][] = 'sites/all/modules/mobile_detect/mobile_detect_caching/mobile_detect_caching.inc';
 * $conf['cache_class_cache_page'] = 'MobileDetectCache';
 * $conf['mobile_detect_library'] = 'sites/all/libraries/Mobile_Detect/Mobile_Detect.php';
 * @endcode
 */
class MobileDetectCache extends DrupalDatabaseCache implements DrupalCacheInterface {

  /**
   * {@inheritdoc}
   */
  function __construct($bin) {
    include_once DRUPAL_ROOT . '/' . variable_get('mobile_detect_library', 'sites/all/libraries/Mobile_Detect/Mobile_Detect.php');

    parent::__construct($bin);
  }

  /**
   * {@inheritdoc}
   */
  function set($cid, $data, $expire = CACHE_PERMANENT) {
    $cid = $this->mobile_detect_caching_alter_cid() . $cid;
    parent::set($cid, $data, $expire);
  }

  /**
   * {@inheritdoc}
   */
  function getMultiple(&$cids) {
    if (is_array($cids)) {
      foreach ($cids as $key => $cid) {
        $cids[$key] = $this->mobile_detect_caching_alter_cid() . $cid;
      }
    }
    return parent::getMultiple($cids);
  }

  /**
   * Determines a prefix for the page cache $cid based on devide type.
   *
   * @return string
   *   The $cid prefix
   */
  protected function mobile_detect_caching_alter_cid() {
    $device = '';

    if (class_exists('Mobile_Detect')) {
      try {
        $detect = new Mobile_Detect();

        if ($detect->isMobile()) {
          $device = 'mobile:';
        }
        elseif ($detect->isTablet()) {
          $device = 'tablet:';
        }

      } catch (Exception $e) {
        // nop
      }
    }
    return $device;
  }

}
