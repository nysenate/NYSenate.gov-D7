<?php

/**
 * @file
 * Attachments collecting cache backend.
 */

require_once __DIR__ . '/d8cache.cache.inc';
require_once __DIR__ . '/includes/core-attachments-collector.inc';

/**
 * Adds reset() and some properties to DrupalAttachmentsCollector().
 */
class D8CacheDrupalAttachmentsCollector extends DrupalAttachmentsCollector {

  /**
   * A count for how many cache IDs this collector should be used.
   *
   * @var int
   */
  public $count = 0;

  /**
   * The stored previous collector.
   *
   * @var \DrupalAttachmentsCollector
   */
  public $previousCollector = NULL;

  /**
   * Reset the attachments in the collector.
   */
  public function reset() {
    $this->attachments = array();
  }

}

/**
 * Special cache backend that tracks attachments.
 *
 * @ingroup cache
 */
class D8CacheAttachmentsCollector extends D8Cache {

  /**
   * An array of attachment collectors, keyed by cache id.
   *
   * @var array
   */
  protected $attachmentsCollectors;

  /**
   * The currently active attachments collector for this bin.
   *
   * @var array
   */
  protected $currentAttachmentsCollector;

  /**
   * Whether this D8CacheAttachmentsCollector is in a valid state or not.
   * If not valid, behavior falls back to D8Cache behavior.
   *
   * The most common cause of an invalid state is attempting to use this
   * class to handle early page cache.
   *
   * @var boolean
   */
  protected $isValid;

  /**
   * {@inheritdoc}
   */
  public function __construct($bin) {
    $this->isValid = TRUE;
    if (!function_exists('drupal_process_attached')) {
      // Something is trying to use us during early bootstrap.
      // Fall back to baseline D8Cache behavior for safety.
      $this->isValid = FALSE;

      // Additionally, prevent the request from saving to cache, and warn
      // loudly that we are in an unsupported configuration.
      $t = get_t();
      drupal_set_message($t('D8CacheAttachmentsCollector is not designed for early page cache! Please switch cache_page to D8Cache in settings.php!'), 'error');
    }
    parent::__construct($bin);
  }

  /**
   * {@inheritdoc}
   */
  public function getMultiple(&$cids, $allow_invalid = FALSE) {
    // The parent will properly populate $cids, so we can rely on it.
    $cache = parent::getMultiple($cids, $allow_invalid);

    if (!$this->isValid) {
      return $cache;
    }

    // Unpack the cached data and process attachments.
    foreach ($cache as $cid => $item) {
      if (is_array($item->data) && isset($item->data['#d8cache_data'])) {
        drupal_process_attached($item->data);
        $cache[$cid]->data = $item->data['#d8cache_data'];
      }
    }

    // In case there are no cids left, return.
    if (empty($cids)) {
      return $cache;
    }

    // We have multiple cids, so we need to reset after each cache set.
    $attachments_collector = new D8CacheDrupalAttachmentsCollector();
    $attachments_collector->count = count($cids);
    $attachments_collector->previousCollector = $this->currentAttachmentsCollector;
    $this->currentAttachmentsCollector = $attachments_collector;

    foreach ($cids as $cid) {
      $this->attachmentsCollectors[$cid] = $attachments_collector;
    }

    return $cache;
  }

  /**
   * {@inheritdoc}
   */
  public function set($cid, $data, $expire = CACHE_PERMANENT, $tags = array()) {
    // Fall back to regular D8Cache if we are not in a valid state.
    if (!$this->isValid) {
      parent::set($cid, $data, $expire, $tags);
      return;
    }

    $attachments = array();

    if (isset($this->attachmentsCollectors[$cid])) {
      $attachments_collector = $this->attachmentsCollectors[$cid];
      $attachments = $attachments_collector->getAttachments();
      unset($this->attachmentsCollectors[$cid]);

      // Reset the attachments for re-use.
      $attachments_collector->reset();

      $attachments_collector->count--;
      if ($attachments_collector->count == 0) {
        $this->currentAttachmentsCollector = $attachments_collector->previousCollector;
      }
    }

    // Create a pseudo render array.
    $data = array(
      '#d8cache_data' => $data,
      '#attached' => $attachments,
    );

    parent::set($cid, $data, $expire, $tags);
  }

  /**
   * Reset the currently active attachments collector - if any.
   */
  public function resetCurrentAttachmentsCollector() {
    if ($this->currentAttachmentsCollector) {
      $this->currentAttachmentsCollector->reset();
    }
  }

}
