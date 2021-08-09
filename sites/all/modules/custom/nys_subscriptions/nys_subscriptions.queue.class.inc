<?php
/**
 * @file
 * NYS Subscriptions Queue Class.
 *
 * Extends Drupal's SystemQueue class to add some convenient functionality.
 *  - Original returns only id and data fields.  This versions adds all
 *    other fields to the queue item object
 *  - Adds a 'references' property to the item and populates it with
 *    the loaded taxonomy term under the key 'taxonomy'
 *  - Implements a data reference population callback
 *  - Adds the queue as an item data property

 */

/**
 * Class NYSQueue
 *
 * Extends Drupal's SystemQueue class to expose the queue name, add metadata,
 * and return more of the base fields from the queue table.
 */
class NYSSubscriptionQueue extends SystemQueue {
  /* @var mixed[] $data Contains metadata for the queue itself */
  public $data = [];

  /**
   * A default queue name to be used if no queue name is provided, or if
   * the name could not be normalized.
   *
   * @var string
   */
  public static $default_queue = NYS_SUBSCRIPTIONS_DEFAULT_QUEUE;

  /**
   * Normalize a queue name, to prevent empty strings, etc.
   *
   * @param string $queue_name
   *
   * @return string
   */
  public static function normalizeName($queue_name = NULL) {
    return ((string) $queue_name) ? (string) $queue_name : static::$default_queue;
  }

  /**
   * Get the list of queues from all modules.
   *
   * A queue definition is an array containing meta-data about the queue
   * itself and its handlers.
   *
   * @see hook_nys_subscriptions_queue_list()
   *
   * @return array A list of defined queues.
   */
  public static function listQueues() {
    // Cache the list.
    $queues = &drupal_static(__FUNCTION__, []);

    // If the list is not populated, invoke the hook.
    if (!$queues) {
      $queues = module_invoke_all('nys_subscriptions_queue_list');
    }

    return $queues;
  }

  /**
   * Instantiates a queue object.  The queue name must be a valid queue,
   * as defined by hook_nys_subscriptions_queue_list().  If the queue
   * cannot be found, an instance of the default queue is returned.  If
   * data is passed, it is merged with the queue's meta-data.
   *
   * @param string $queue_name
   * @param array $data
   *
   * @return \NYSSubscriptionQueue
   */
  public static function getInstance($queue_name, $data = []) {
    // Verify the queue_name is populated.
    $queue_name = static::normalizeName($queue_name);

    // Verify the queue is defined.  If not, use the default.
    $all_queues = static::listQueues();
    if (!isset($all_queues[$queue_name])) {
      $queue_name = static::$default_queue;
    }

    $ret = new static($queue_name);

    // There is no harm in trying to recreate existing.  This will suppress issues
    // caused by a non-existent queue.
    $ret->createQueue();

    // Set the meta data.
    $ret->data = array_merge($all_queues[$queue_name], $data);

    return $ret;
  }

  /**
   * Getter function for the protected name property.
   *
   * @return string
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Returns the email subject for this queue, if defined.  If not defined,
   * the default subject for all subscriptions is used instead.
   *
   * @return string
   */
  public function getSubject() {
    return $this->data['#subject'] ?? NYS_SUBSCRIPTIONS_DEFAULT_SUBJECT;
  }

  /**
   * Override for parent::claimItem().  Adds all fields from the queue record.
   * Will return false if an item could not be loaded for any reason (e.g.,
   * none available, database error).
   *
   * @param int $lease_time
   *
   * @return false|\NYSSubscriptionQueueItem false if no item could be loaded
   */
  public function claimItem($lease_time = 30) {
    while (TRUE) {
      $query = 'SELECT data, item_id, name, expire, created FROM {queue} q ' .
        'WHERE expire = 0 AND name = :name ORDER BY created, item_id ASC';
      $item = db_query_range($query, 0, 1, array(':name' => $this->name))->fetchObject();
      if ($item) {
        $update = db_update('queue')
          ->fields(['expire' => time() + $lease_time])
          ->condition('item_id', $item->item_id)
          ->condition('expire', 0)
          ->execute();

        // If there are affected rows, this update succeeded.
        if ($update) {
          // Prep the item data points.
          $item->data = unserialize($item->data);

          if (!$ret = NYSSubscriptionQueueItem::getInstance($item, $this)) {
            watchdog('nys_subscriptions',
              'Queue :name may have an orphaned item :item',
              [':name' => $this->name, ':item' => $item,],
              WATCHDOG_WARNING);
            $ret = FALSE;
          }

          return $ret;
        }
      }
      else {
        // No items currently available to claim.
        return FALSE;
      }
    }
  }

  /**
   * Guarantee at least one subscriber is in the queue item data.
   *
   * @param $data
   *
   * @return bool
   */
  public function createItem($data) {
    $subs = $data['recipients'] ?? [];
    if (!$subs) {
      watchdog(
        'nys_subscriptions',
        'Attempted to create a queue item with no subscribers in :queue',
        [':queue' => $this->getName()],
        WATCHDOG_WARNING
      );
      return false;
    }
    return parent::createItem($data);
  }

  /**
   * Processes all items in this queue.  Will halt if an item failed to
   * process, or if no more items exist.
   *
   * TODO: this needs debug monitoring
   */
  public function process() {
    do {
      $success = $this->processItem();
    } while ($success);
  }

  /**
   * Attempts to process a single item.  The item will be claimed, and its
   * process() method called.  If $resolve is true, the item will be deleted
   * or released back to queue, depending if processing is successful
   *
   * @param bool $resolve
   *
   * @return bool
   */
  public function processItem($resolve = TRUE) {
    if (!($item = $this->claimItem())) {
      return FALSE;
    }

    try {
      $ret = $item->process();
    }
    catch (Exception $e) {
      watchdog('nys_subscriptions', 'Exception during queue item processing',
        ['msg' => $e->getMessage(), 'item' => $item], WATCHDOG_ERROR);
      $ret = FALSE;
    }

    if ($resolve) {
      if ($ret) {
        $this->deleteItem($item);
      }
      else {
        $this->releaseItem($item);
      }
    }

    return $ret;
  }
}
