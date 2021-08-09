<?php
/**
 * @file nys_subscriptions.queueitem.class.inc
 */

use \SendGrid\Mail as SG;

class NYSSubscriptionQueueItem {

  /**
   * @var \NYSSubscriptionQueue $queue The owning queue object.
   */
  public $queue;

  /**
   * @var array $references An array to hold object references
   */
  public $references;

  /**
   * @var array $substitutions An array to hold tokenization entries
   */
  public $substitutions;

  /**
   * @var array $content An array of HTML content to include.
   */
  public $content;

  /**
   * The mail key to send to drupal_mail() for this queue item.  Will
   * default to the queue's name.
   *
   * @var string
   */
  public $mail_key = '';

  /**
   * @var stdClass $item The original queue item object
   *
   * @see \SystemQueue::claimItem()
   */
  protected $item;

  /**
   * @var bool
   */
  protected $ready_to_send = TRUE;

  /**
   * NYSSubscriptionQueueItem constructor.
   *
   * @param stdClass $item The original queue item object
   *
   * @param ?\NYSSubscriptionQueue The owning queue.  If not passed, it
   * will be detected from $item->name
   *
   * @throws Exception if $item cannot be resolved to a queue item.
   * @see \SystemQueue::claimItem()
   *
   */
  public function __construct($item, $queue = NULL) {
    // A reference to the actual database record (an object)
    $this->item = $item;

    // Verify everything needed is present.
    if (!($this->validateItem($item) && ($this->queue = $this->validateQueue($queue)))) {
      throw new Exception("Cannot instantiate, invalid queue item data");
    }

    // Initialize the other properties
    $this->init();
  }

  /**
   * Convenience function to avoid needing try..catch in callers.
   *
   * @param $item
   * @param null $queue
   *
   * @return static|null
   */
  public static function getInstance($item, $queue = NULL) {
    try {
      return new static($item, $queue);
    } catch (\Exception $e) {
      return NULL;
    }
  }

  /**
   * To mimic the original object returned from SystemQueue::claimItem()
   *
   * @param $name
   *
   * @return null|mixed
   */
  public function __get($name) {
    return $this->item->{$name} ?? NULL;
  }

  /**
   * Marks the queue item as having failed sending.  This directly
   * translates to a parameter in drupal_mail().
   *
   * @see drupal_mail()
   */
  public function markFailed() {
    $this->ready_to_send = FALSE;
  }

  /**
   * Allows modules to load any per-item tokens (e.g., template ID).
   * This is called once during item processing.  Hooks can fail an
   * item's processing by throwing a Throwable.
   */
  public function populateItemTokens() {
    try {
      drupal_alter($this->getHookNames('item_tokens'), $this);
    } catch (\Throwable $e) {
      $this->ready_to_send = FALSE;
    }
  }

  /**
   * Allows modules to load any per-user tokens (e.g., name).  This is
   * called once for each subscriber being processed.  Hooks can fail an
   * item's processing by throwing a Throwable.
   */
  public function populateSubscriberTokens() {
    try {
      drupal_alter($this->getHookNames('user_tokens'), $this);
    } catch (\Throwable $e) {
      $this->ready_to_send = FALSE;
    }
  }

  /**
   * Processes the queue item.  Hooks called from this process can fail
   * an item by throwing a Throwable.
   *
   * @return array
   *
   */
  public function process() {
    $this->populateItemTokens();
    $this->populateSubscriberTokens();

    return $this->createMail();
  }

  /**
   * Call drupal_mail().  The actual mail creation is handled by
   * nys_subscriptions_queueitem_mail().
   *
   * @return array
   * @see drupal_mail()
   * @see nys_subscriptions_queueitem_mail()
   */
  public function createMail() {
    $ret = drupal_mail(
      'nys_subscriptions_queueitem',  // module
      'subscription',                 // key
      '',                             // to (irrelevant with SendGrid API mail)
      language_default(),             // language
      ['queue_item' => $this],        // params
      NULL,                           // from
      $this->ready_to_send            // send flag
    );
    if ($ret['result'] ?? FALSE) {
      $this->createLogEntry();
    }
    return $ret;
  }

  /**
   * Creates a subscription log entry for each recipient in this item.
   */
  protected function createLogEntry() {
    // Initialize the failure counter and an easy reference.
    $failed = 0;
    $data = $this->item->data;

    // Insert a log entry for each recipient
    foreach ($data['recipients'] as $key => $val) {
      $fields = [
        'email' => $val['email'],
        'alert_node' => $data['nid'],
        'lineage_node' => $data['tid'],
        // TODO: This is a bill notifications item.  replace with something useful
        'alert_type' => $this->references['primary_event']['name'] ?? 'no_event_found',
        'send_ts' => time(),
      ];
      try {
        db_insert('nys_subscription_log')->fields($fields)->execute();
      } catch (Exception $e) {
        // if the insert failed, report to watchdog, but only once.
        if (!$failed) {
          watchdog(
            'nys_subscriptions',
            'Failed to insert to subscription log',
            [
              'msg' => $e->getMessage(),
              'recipient' => $val,
              'fields' => $fields,
            ],
            WATCHDOG_ERROR
          );
        }
        $failed++;
      }
    }

    // If more than one failure occurred, notify of how many repetitions occurred.
    if ($failed > 1) {
      watchdog('nys_subscriptions', 'Previous error repeated :num times', [':num' => $failed], WATCHDOG_ERROR);
    }
  }

  /**
   * Generates names for queue item-related hooks.  Hooks always use two
   * forms, one general and one specific to the owning queue:
   *   - hook_queueitem_<type>
   *   - hook_queueitem_<type>_<queue_name>
   *
   * E.g., for the item tokens hook, in bill notifications:
   *   - hook_queueitem_item_tokens()
   *   - hook_queueitem_item_tokens_nys_bill_notifications_queue()
   *
   * @param string $type
   *
   * @return string[] An array of hook names appropriate for drupal_alter()
   */
  protected function getHookNames($type) {
    return [
      'queueitem_' . $type,
      'queueitem_' . $type . '_' . $this->queue->getName(),
    ];
  }

  /**
   * Loads reference objects for the taxonomy and related nodes.  Also
   * invokes hook_queueitem_reference_alter() to allow other modules to
   * load their own.  The invocation will call two forms:
   *   - hook_queueitem_reference_alter()
   *   - hook_queueitem_reference_<queue_name>_alter()
   *
   */
  protected function populateReferences() {
    // Populate the taxonomy term and vocabulary objects
    $this->references['source'] = taxonomy_term_load($this->data['tid'] ?? 0);
    $this->references['source_vocabulary'] = taxonomy_vocabulary_load($this->references['source']->vid ?? 0);

    // Populate the subscribed node
    $this->references['node'] = node_load($this->data['nid']);

    // Load the root node.
    // Commented, here for reference.
    /*
    [$session, $print_num] = explode('-', $this->references['source']->name);
    $nid = nys_bills_load_active_from_session_base_print($session, $print_num);
    $item->references['root_node'] = node_load($nid);
    */

    // Allow modules to alter references.
    drupal_alter($this->getHookNames('reference'), $this);
  }

  /**
   * Initialize properties to support SendGrid templates.
   */
  protected function init() {
    // Arrays for tokens/substitutions, references, and content.
    $this->substitutions = ['common' => [], 'subscribers' => []];
    $this->references = [];
    $this->content = [];
    $this->mail_key = $this->queue->getName();

    // Get the reference objects.
    $this->populateReferences();
  }

  /**
   * Verifies the minimum required for a queue item's record ($item).
   * $item may be an object or array.  If it is an array but otherwise
   * meets the criteria, it will be cast to an object.
   *
   * @param array|object $item
   *
   * @return bool
   */
  protected function validateItem(&$item) {
    $ret = FALSE;
    // Absolute minimum is a stdClass with data, name, and item_id.
    if (
      ($item instanceof stdClass)
      && (isset($item->data))
      && (isset($item->name))
      && (isset($item->item_id))
    ) {
      $ret = TRUE;
    }
    // We can also accept an array, which will be cast to an object.
    elseif (
      (is_array($item))
      && (array_key_exists('data', $item))
      && (array_key_exists('name', $item))
      && (array_key_exists('item_id', $item))
    ) {
      $ret = TRUE;
      $item = (object) $item;
    }
    return $ret;
  }

  /**
   * Verifies a queue object is available for this queue item.  If $queue
   * is an NYSSubscriptionQueue instance, return it.  Otherwise, check if
   * $queue is a string, or if this item data contains a queue name.  If
   * so, return that instantiated queue.  Otherwise, return false.
   *
   * @param \NYSSubscriptionQueue|string $queue
   *
   * @return false|\NYSSubscriptionQueue
   */
  protected function validateQueue($queue) {
    if ($queue instanceof NYSSubscriptionQueue) {
      $ret = $queue;
    }
    else {
      $name = ((string) $queue) ?: ($this->data['name'] ?? '');
      $ret = NYSSubscriptionQueue::getInstance($name);
    }
    return $ret;
  }

}
