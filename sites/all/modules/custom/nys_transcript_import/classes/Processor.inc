<?php

/**
 * Class NysTranscriptImportProcessor
 */
abstract class NysTranscriptImportProcessor {

  /**
   * @var string Cache for the OpenLeg API key, read from variables.
   */
  protected static $openleg_key = '';

  /**
   * @var array Array of configuration points for child classes.
   *            Every key must be populated in the child.
   */
  protected static $type_info = [
    'url_id' => '',
    'type_index' => '',
  ];

  /**
   * @var callable The logging function to use
   * TODO: this should be a service reference, but we don't have that in D7.
   */
  protected static $log;

  /**
   * @var object JSON-decoded update block
   */
  protected $update_block;

  /**
   * @var object JSON-decoded transcript block
   */
  protected $transcript;

  /**
   * @var object Drupal node object
   */
  protected $node;

  /**
   * NysTranscriptImportProcessor constructor.
   */
  public function __construct() {
  }

  /**
   * Transcribes values from the transcript block into a matched
   * Drupal node.  The method must be provided by the child.
   */
  abstract public function transcribeToNode();

  /**
   * Fetches the key value for a transcript block.  The method
   * must be provided by the child.
   *
   * @return mixed
   */
  abstract public function getId();

  /**
   * Fetches the key value for an update block.  The method must
   * be provided by the child.
   *
   * @return mixed
   */
  abstract public function getUpdateId();

  /**
   * Loads the OpenLeg API key from Drupal variables and caches it statically.
   *
   * @return string
   */
  public static function getOpenLegKey() {
    static $warned = FALSE;

    // Only attempt to load the key once to avoid spamming watchdog with
    // multiple API failures.
    if (!$warned) {
      if (!static::$openleg_key) {
        static::$openleg_key = variable_get('openleg_key', FALSE);
      }

      if (!static::$openleg_key) {
        watchdog('nys_transcript_import', "No OpenLeg API key was found", [], WATCHDOG_WARNING);
      }

      $warned = TRUE;
    }

    return static::$openleg_key;
  }

  /**
   * Formats a timestamp.  By default, it uses a format which aligns
   * with OpenLeg expectations.  The timestamp can be any string, as
   * interpreted by strtotime().
   *
   * @param string $timestamp
   * @param string $format
   *
   * @return false|string
   */
  public static function formatTimestamp($timestamp, $format = NULL) {
    if (!$format) {
      $format = 'Y-m-d\TH:i:s';
    }
    $time = strtotime($timestamp);

    return $time ? date($format, $time) : $timestamp;
  }

  /**
   * Fetches a list of updates ranging from $timestamp to the present.
   * Returns FALSE if the API call failed, otherwise an array (could
   * be an empty array!).
   *
   * @param string $timestamp Any valid time/date string.
   *
   * @return bool|array FALSE on API failure, or an array of items.
   */
  public static function fetchUpdatesSince($timestamp) {
    // Set params to get all available updates.
    $params = [
      'offset' => 1,
      'limit' => 0,
      'order' => 'asc',
      'key' => static::getOpenLegKey(),
    ];
    // Build the full URL
    $url = static::buildUpdateUrl() . static::formatTimestamp($timestamp) .
      '?' . drupal_http_build_query($params);
    static::log("Fetching: {$url}", 'debug');

    // Get the list.
    $list_result = json_decode(file_get_contents($url));

    // If API call returned a failure, record it for posterity and return FALSE.
    if (!($list_result->success ?? FALSE)) {
      watchdog('nys_transcript_import',
        "API call for " . static::$type_info['type_index'] . " updates failed",
        [
          'msg' => $list_result->message,
          'errorData' => $list_result->errorData,
        ],
        WATCHDOG_ERROR);
      return FALSE;
    }

    static::log('Found ' . ($list_result->total ?? 0) . ' import items', 'debug');

    return $list_result->result->items;
  }

  /**
   * Attempts to instantiate a transcript processor instance, based on
   * the passed $type.  The type must be known to Drupal (via an option
   * from field_ol_transcript_type), and a class file must exist in the
   * classes directory.  Will throw a RuntimeException if the class
   * cannot be instantiated.
   *
   * @param $type
   * @param null $id
   *
   * @return \NysTranscriptImportProcessor
   * @see self::getTranscriptTypes()
   *
   */
  public static function getInstance($type, $id = NULL): NysTranscriptImportProcessor {
    // Discover the type information from Drupal.
    $type_info = static::getTranscriptTypes($type);

    // Set up the type and class names.
    $type_name = $type_info['class'] . 'Processor';
    $class = 'NysTranscriptImport' . $type_name;

    // Attempt to load the class file.  This will error if it can't be found.
    $file = DRUPAL_ROOT . '/' .
      drupal_get_path('module', 'nys_transcript_import') .
      "/classes/" . $type_name . ".inc";
    require_once $file;

    // Attempt to instantiate the class, with the ID, if passed.
    if (!($ret = new $class($id))) {
      throw new RuntimeException('Could not instantiate processor for ' . $type);
    }

    return $ret;
  }

  /**
   * Fetches a transcript object from OpenLeg API.  Returns FALSE on
   * failure, otherwise returns the JSON-decoded transcript object.
   *
   * @param string $id A transcript ID, usually a formatted timestamp.
   *
   * @return bool|object
   */
  public static function fetchTranscript($id = NULL) {
    // No work to do if no ID is passed.
    if (!$id) {
      return FALSE;
    }

    // Build the URL to get a transcript instance.
    $params = ['key' => static::getOpenLegKey()];
    $url = static::buildInstanceUrl() . rawurlencode($id) . '?' .
      drupal_http_build_query($params);
    static::log("Fetching: {$url}", 'debug');

    // Get the results.
    $result = json_decode(file_get_contents($url));

    // If the API call returned a failure, log and return false.
    if (!($result->success ?? FALSE)) {
      watchdog('nys_transcript_import',
        "API call for " . static::$type_info['type_index'] . " item failed",
        [
          'msg' => $result->message,
          'errorData' => $result->errorData,
        ],
        WATCHDOG_ERROR);
      return FALSE;
    }

    return $result->result;
  }

  /**
   * Discovers known transcript types from Drupal's field_ol_transcript_type
   * custom field.  If an index is passed, that type's array will be returned.
   * Otherwise, all types are returned as an array.  Throws an exception if
   * a type is passed but cannot be found.
   *
   * @param string $index The transcript type's machine name.
   *
   * @return array The transcript type, or all transcript types.
   */
  public static function getTranscriptTypes($index = NULL) {
    // Local cache for type discovery.
    static $types = [];

    // If types have not been discovered, try to load them.
    if (!$types) {
      $info = field_info_field('field_ol_transcript_type');
      $types = $info['settings']['allowed_values'];
      array_walk($types, function (&$v, $i) {
        $v = [
          'name' => $v,
          'class' => str_replace(' ', '', (ucwords(str_replace('_', ' ', $v)))),
        ];
      });
    }

    // If a specific type was requested, make sure it exists.
    if ($index && !($types[$index] ?? NULL)) {
      throw new UnexpectedValueException("Could not locate transcript type '$index'");
    }

    return $index ? $types[$index] : $types;
  }

  /**
   * Attempts to locate a node matched by field_ol_publish_date.  EMW/EFQ
   * can generate exceptions.  Returns the Drupal node object or NULL if
   * not found.
   *
   * @param int|string $publish A timestamp or time string.
   *
   * @return object|null
   */
  public static function findMatchingNode($publish) {
    // Format the publish date as an epoch timestamp.
    $time_id = is_numeric($publish) ? $publish : strtotime($publish);

    // Build EFQ to search on field_ol_publish_date, for thie transcript type.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'transcript')
      ->fieldCondition('field_ol_transcript_type', 'value', static::$type_info['type_index'])
      ->fieldCondition('field_ol_publish_date', 'value', $time_id)
      ->execute();

    // Return the loaded node, or NULL.
    $ret = NULL;
    if (count($result['node'] ?? [])) {
      $nid = array_keys($result['node'])[0];
      $ret = node_load($nid);
    }
    return $ret;
  }

  /**
   * @param callable $log
   */
  public static function setLog(callable $log): void {
    self::$log = $log;
  }

  /**
   * @param $message
   * @param string $level
   */
  protected static function log($message, $level = 'debug') {
    if (function_exists($log = static::$log)) {
      $log($message, $level);
    }
  }

  /**
   * Builds the base URL used to call OpenLeg API.
   *
   * @return string
   */
  protected static function buildBaseUrl() {
    return rtrim(variable_get('openleg_base_url'), '/');
  }

  /**
   * Build a URL to retrieve a transcript object.
   *
   * @return string
   */
  protected static function buildInstanceUrl() {
    return static::buildBaseUrl() . '/api/3/' . static::$type_info['url_id'] . '/';
  }

  /**
   * Build a URL to retrieve updates for a type of transcript.
   *
   * @return string
   */
  protected static function buildUpdateUrl() {
    return static::buildInstanceUrl() . 'updates/';
  }

  /**
   * Attempts to load the node matching this transcript.  If a node is not
   * found, returns a created object with minimum-bar data populated.  Will
   * throw an exception is no transcript has been loaded.
   *
   * @return $this
   */
  public function loadNode() {
    // If no transcript is loaded, something has gone wrong.
    if (!$this->transcript) {
      throw new RuntimeException('Attempted to load a node with no transcript');
    }

    // Try to find a matching node.  If no match, build a stdClass
    // object to use as a new node.
    $this->node = static::findMatchingNode($this->getId())
      ?? (object) [
        'title' => $this->generateTitle(),
        'type' => "transcript",
        'field_ol_transcript_type' => ['und' => [['value' => static::$type_info['type_index']]]],
        'field_ol_publish_date' => ['und' => [['value' => $this->getId()]]],
      ];
    if (isset($this->node->nid)) {
      $message = 'Using node id ' . $this->node->nid;
    }
    else {
      $message = 'Using new node, type "' . $this->node->field_ol_transcript_type .
        '", date/id "' . $this->node->field_ol_publish_date . '"';
    }
    static::log($message, 'debug');
    return $this;
  }

  /**
   * Generates a title for the current transcript.
   * Override in the child if the title needs customization.
   *
   * @return string
   */
  public function generateTitle() {

    if (!$this->transcript) {
      return '';
    }
    $info = static::getTranscriptTypes(static::$type_info['type_index']);

    return $info['name'] . ' ' . static::formatTimestamp($this->getId());
  }

  /**
   * Attempts to save the current transcript.  If no transcript is loaded,
   * it attempts to load the transcript identified by this ID.  If no node
   * is loaded, it will call loadNode() to fetch/create one.  Returns
   * FALSE if a transcript or node could not be loaded/prepared.
   *
   * @return bool
   * @throws \Exception
   */
  public function save() {
    // If no transcript is loaded, try to load it.  If still no
    // transcript, return FALSE.
    if (!$this->transcript) {
      if (!($this->transcript = static::fetchTranscript($this->getId()))) {
        static::log('Could not find a transcript to save', 'error');
        return FALSE;
      }
    }

    // If no node has been loaded, try to load/create one.
    if (!$this->node) {
      $this->loadNode();
    }

    // Call the child's transcription process and save the node.
    if ($this->transcript && $this->node) {
      $this->transcribeToNode();
      node_object_prepare($this->node);
      node_save($this->node);
      static::log('Saved node ' . $this->node->nid ?? '<unknown!>', 'debug');
    }
    else {
      static::log('save() called without valid transcript/node', 'error');
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Initializes the transcript and node objects based on a JSON-decoded
   * update block ($item).
   *
   * @param object $item a JSON-decoded update block
   *
   * @return $this
   */
  public function initFromUpdate($item) {
    $this->reset();
    $this->setUpdateBlock($item);
    $this->transcript = static::fetchTranscript($this->getUpdateId());
    return $this;
  }

  /**
   * Getter for private update block object.
   *
   * @return object
   */
  public function getUpdateBlock() {
    return $this->update_block;
  }

  /**
   * Getter for private transcript block object.
   *
   * @return object
   */
  public function getTranscript() {
    return $this->transcript;
  }

  /**
   * Builds URLs for OpenLeg API based on this transcript's properties.
   * If no timestamp is passed, the current ID is used.  Returns the
   * URL for a transcript instance if $update is FALSE, otherwise returns
   * the URL for a list of updates.
   *
   * @param null $timestamp
   * @param bool $update
   *
   * @return string
   */
  public function getUrl($timestamp = NULL, $update = FALSE) {
    $url = $update ? static::buildUpdateUrl() : static::buildInstanceUrl();
    if (!$timestamp) {
      $timestamp = $this->getId();
    }
    $url .= static::formatTimestamp($timestamp);

    return $url;
  }

  /**
   * Getter for private node object.
   *
   * @return mixed
   */
  public function getNode() {
    if (!$this->node) {
      $this->loadNode();
    }
    return $this->node;
  }

  public function reset() {
    $this->node = NULL;
    $this->update_block = NULL;
    $this->transcript = NULL;
  }

  /**
   * Getter for private update block object.
   *
   * @param mixed $update_block
   */
  protected function setUpdateBlock($update_block) {
    $this->update_block = $update_block;
  }

}
