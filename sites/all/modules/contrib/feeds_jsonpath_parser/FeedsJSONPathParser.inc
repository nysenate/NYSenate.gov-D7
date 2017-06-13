<?php

/**
 * @file
 * Contains FeedsJSONPathParser.
 */

/**
 * Parses JSON using JSONPath.
 */
class FeedsJSONPathParser extends FeedsParser {

  /**
   * A regular expression that finds four byte UTF-8 chars.
   *
   * @var string
   */
  protected static $fourByteRegex = '/(?:\xF0[\x90-\xBF][\x80-\xBF]{2}|[\xF1-\xF3][\x80-\xBF]{3}|\xF4[\x80-\x8F][\x80-\xBF]{2})/s';

  /**
   * The source fields to debug.
   *
   * @var array
   */
  protected $debug = array();

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $mappings = $this->getOwnMappings();
    $source_config = $source->getConfigFor($this);
    // Allow config inheritance.
    if (empty($source_config)) {
      $source_config = $this->config;
    }
    $this->debug = array_keys(array_filter($source_config['debug']['options']));

    $raw = trim($fetcher_result->getRaw());
    $result = new FeedsParserResult();
    // Set link so we can set the result link attribute.
    $fetcher_config = $source->getConfigFor($source->importer->fetcher);
    $result->link = $fetcher_config['source'];

    $array = json_decode($raw, TRUE);

    // Support JSON lines format.
    if (!is_array($array)) {
      $raw = preg_replace('/}\s*{/', '},{', $raw);
      $raw = '[' . $raw . ']';
      $array = json_decode($raw, TRUE);
    }

    if (!is_array($array)) {
      throw new Exception(t('There was an error decoding the JSON document.'));
    }
    require_once feeds_jsonpath_parser_library_path();

    $all_items = $this->jsonPath($array, $source_config['context']);
    unset($array);

    // Batch.
    $state = $source->state(FEEDS_PARSE);
    if (!$state->total) {
      $state->total = count($all_items);
    }

    $start = (int) $state->pointer;
    $state->pointer = $start + $source->importer->getLimit();
    $all_items = array_slice($all_items, $start, $source->importer->getLimit());

    // Set progress state.
    $state->progress($state->total, $state->pointer);

    // Debug output.
    $this->debug($all_items, 'context');

    foreach ($all_items as $item) {
      // Invoke a hook to check whether the item should be skipped.
      if ($this->invokeHook($item, $source) === TRUE) {
        continue;
      }

      $parsed_item = $variables = array();
      foreach ($source_config['sources'] as $source_key => $query) {
        // Variable substitution.
        $query = strtr($query, $variables);
        $parsed = $this->parseSourceElement($item, $query, $source_key);

        $variables['{' . $mappings[$source_key] . '}'] = is_array($parsed) ? reset($parsed) : $parsed;

        // Avoid null values.
        if (isset($parsed)) {
          $parsed_item[$source_key] = $parsed;
        }
      }
      if (!empty($parsed_item)) {
        $result->items[] = $parsed_item;
      }
    }
    return $result;
  }

  /**
   * Utilizes the jsonPath function from jsonpath-0.8.1.php.
   *
   * jsonPath returns false if the expression returns zero results and that will
   * mess up our for loops, so return an empty array instead.
   *
   * @param array $array
   *   The input array to parse.
   * @param string $expression
   *   The JSONPath expression.
   *
   * @return array
   *   Returns an array that is the output of jsonPath.
   *
   * @todo
   *   Firgure out error handling.
   */
  protected function jsonPath($array, $expression) {
    $result = jsonPath($array, $expression);
    return ($result === FALSE) ? array() : $result;
  }

  /**
   * Parses one item from the context array.
   *
   * @param array $item
   *   An array containing one item from the context.
   * @param string $query
   *   A JSONPath query.
   * @param string $source
   *   The source element that corresponds to the query.
   *
   * @return array
   *   An array containing the results of the query.
   */
  protected function parseSourceElement($item, $query, $source) {
    if (empty($query)) {
      return;
    }
    $results = $this->jsonPath($item, $query);
    $this->debug($results, $source);

    $count = count($results);
    if ($count === 0) {
      return;
    }

    foreach ($results as $delta => $value) {
      if (is_string($value) && $value !== '') {
        $results[$delta] = !empty($this->config['convert_four_byte']) ? $this->convertFourBytes($value) : $this->stripFourBytes($value);
      }
    }

    if ($count === 1) {
      return reset($results);
    }

    return $results;
  }

  /**
   * Source form.
   */
  public function sourceForm($source_config) {
    $form = array();

    if (empty($source_config)) {
      $source_config = $this->config;
    }

    if (isset($source_config['allow_override']) &&
        !$source_config['allow_override'] &&
        empty($source_config['config'])) {
      return;
    }

    // Add extensions that might get importerd.
    $fetcher = feeds_importer($this->id)->fetcher;
    if (isset($fetcher->config['allowed_extensions'])) {
      if (strpos($fetcher->config['allowed_extensions'], 'json') === FALSE) {
        $fetcher->config['allowed_extensions'] .= ' json';
      }
    }
    $mappings_ = feeds_importer($this->id)->processor->config['mappings'];
    $uniques = $mappings = array();

    foreach ($mappings_ as $mapping) {
      if (strpos($mapping['source'], 'jsonpath_parser:') === 0) {
        $mappings[$mapping['source']] = $mapping['target'];
        if (!empty($mapping['unique'])) {
          $uniques[] = $mapping['target'];
        }
      }
    }
    $form['jsonpath'] = array(
      '#type' => 'fieldset',
      '#title' => t('JSONPath Parser Settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
    );
    if (empty($mappings)) {
      // Detect if Feeds menu structure has changed. This will take a while to
      // be released, but since I run dev it needs to work.
      $feeds_menu = feeds_ui_menu();
      if (isset($feeds_menu['admin/structure/feeds/list'])) {
        $feeds_base = 'admin/structure/feeds/edit/';
      }
      else {
        $feeds_base = 'admin/structure/feeds/';
      }
      $form['jsonpath']['error_message']['#markup'] = '<div class="help">' . t('No JSONPath mappings are defined. Define mappings !link.', array('!link' => l(t('here'), $feeds_base . $this->id . '/mapping'))) . '</div><br />';
      return $form;
    }
    $form['jsonpath']['context'] = array(
      '#type' => 'textfield',
      '#title' => t('Context'),
      '#required' => TRUE,
      '#description' => t('This is the base query, all other queries will execute in this context.'),
      '#default_value' => isset($source_config['context']) ? $source_config['context'] : '',
      '#maxlength' => 1024,
      '#size' => 80,
    );
    $form['jsonpath']['sources'] = array(
      '#type' => 'fieldset',
    );
    if (!empty($uniques)) {
      $items = array(
        format_plural(count($uniques),
          t('Field <strong>!column</strong> is mandatory and considered unique: only one item per !column value will be created.',
            array('!column' => implode(', ', $uniques))),
          t('Fields <strong>!columns</strong> are mandatory and values in these columns are considered unique: only one entry per value in one of these columns will be created.',
            array('!columns' => implode(', ', $uniques)))),
      );
      $form['jsonpath']['sources']['help']['#markup'] = '<div class="help">' . theme('item_list', array('items' => $items)) . '</div>';
    }
    $variables = array();
    foreach ($mappings as $source => $target) {
      $form['jsonpath']['sources'][$source] = array(
        '#type' => 'textfield',
        '#title' => $target,
        '#description' => t('The JSONPath expression to execute.'),
        '#default_value' => isset($source_config['sources'][$source]) ? $source_config['sources'][$source] : '',
        '#maxlength' => 1024,
        '#size' => 80,
      );
      if (!empty($variables)) {
        $variable_text = format_plural(count($variables),
          t('The variable %v is available for replacement.', array('%v' => implode(', ', $variables))),
          t('The variables %v are available for replacement.', array('%v' => implode(', ', $variables)))
        );
        $form['jsonpath']['sources'][$source]['#description'] .= '<br />' . $variable_text;
      }
      $variables[] = '{' . $target . '}';
    }
    $form['jsonpath']['debug'] = array(
      '#type' => 'fieldset',
      '#title' => t('Debug'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['jsonpath']['debug']['options'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Debug query'),
      '#options' => array_merge(array('context' => 'context'), $mappings),
      '#default_value' => isset($source_config['debug']['options']) ? $source_config['debug']['options'] : array(),
    );
    return $form;
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $config = $this->getConfig();
    $config['config'] = TRUE;
    $form = $this->sourceForm($config);
    $form['jsonpath']['context']['#required'] = FALSE;
    $form['jsonpath']['#collapsed'] = FALSE;
    $form['jsonpath']['allow_override'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow source configuration override'),
      '#description' => t('This setting allows feed nodes to specify their own JSONPath values for the context and sources.'),
      '#default_value' => $config['allow_override'],
    );
    $form['jsonpath']['convert_four_byte'] = array(
      '#type' => 'checkbox',
      '#title' => t('Convert four byte characters'),
      '#description' => t('Coverts four byte UTF-8 characters to their HTML entity. By default, four byte characters will be stripped.'),
      '#default_value' => !empty($config['convert_four_byte']),
    );

    return $form;
  }

  /**
   * Override parent::getMappingSources().
   */
  public function getMappingSources() {
    $mappings = $this->filterMappings(feeds_importer($this->id)->processor->config['mappings']);
    $next = 0;
    if (!empty($mappings)) {
      $keys = array_keys($mappings);

      $nums = array();
      foreach ($keys as $key) {
        list(, $num) = explode(':', $key);
        $nums[] = $num;
      }

      $max = max($nums);
      $next = ++$max;
    }
    return array(
      'jsonpath_parser:' . $next => array(
        'name' => t('JSONPath Expression'),
        'description' => t('Allows you to configure a JSONPath expression that will populate this field.'),
      ),
    ) + parent::getMappingSources();
  }

  public function sourceDefaults() {
    return array();
  }

  /**
   * Define defaults.
   */
  public function configDefaults() {
    return array(
      'context' => '',
      'sources' => array(),
      'debug' => array(),
      'allow_override' => FALSE,
      'convert_four_byte' => FALSE,
    );
  }

  /**
   * Override parent::sourceFormValidate().
   *
   * If the values of this source are the same as the base config we set them to
   * blank to that the values will be inherited from the importer defaults.
   *
   * @param array $values
   *   The values from the form to validate, passed by reference.
   */
  public function sourceFormValidate(&$values) {
    $config = $this->getConfig();
    $values = $values['jsonpath'];
    $allow_override = $config['allow_override'];
    unset($config['allow_override']);
    unset($config['convert_four_byte']);
    ksort($values);
    ksort($config);
    if ($values === $config || !$allow_override) {
      $values = array();
      return;
    }
    $this->configFormValidate($values);
  }

  /**
   * Override parent::sourceFormValidate().
   */
  public function configFormValidate(&$values) {
    if (isset($values['jsonpath'])) {
      $values = $values['jsonpath'];
    }

    $values['context'] = isset($values['context']) ? trim($values['context']) : '';
    if (!empty($values['sources'])) {
      foreach ($values['sources'] as &$source) {
        $source = trim($source);
      }
    }
  }

  /**
   * Gets the mappings that belong to this parser.
   *
   * @return array
   *   An array of mappings keyed source => target.
   */
  protected function getOwnMappings() {
    $importer_config = feeds_importer($this->id)->getConfig();
    return $this->filterMappings($importer_config['processor']['config']['mappings']);
  }

  /**
   * Filters mappings, returning the ones that belong to us.
   *
   * @param array $mappings
   *   A mapping array from a processor.
   *
   * @return array
   *   An array of mappings keyed source => target.
   */
  protected function filterMappings($mappings) {
    $our_mappings = array();
    foreach ($mappings as $mapping) {
      if (strpos($mapping['source'], 'jsonpath_parser:') === 0) {
        $our_mappings[$mapping['source']] = $mapping['target'];
      }
    }
    return $our_mappings;
  }

  protected function debug($item, $source) {
    if (in_array($source, $this->debug)) {
      $o = '<ul>';
      foreach ($item as $i) {
        $o .= '<li>' . check_plain(var_export($i, TRUE)) . '</li>';
      }
      $o .= '</ul>';
      drupal_set_message($source . ':' . $o);
    }
  }

  /**
   * Calls our filter hook.
   *
   * @param array &$item
   *   The item to alter.
   * @param FeedsSource $source
   *   The feed source.
   * @return true|null
   *   Returns true if the item should be skipped.
   */
  protected function invokeHook(array &$item, FeedsSource $source) {
    foreach (module_implements('feeds_jsonpath_parser_filter') as $module) {
      $function = $module . '_feeds_jsonpath_parser_filter';
      if ($function($item, $source) === TRUE) {
        return TRUE;
      }
    }
  }

  /**
   * Strips four byte characters from a string.
   *
   * @param string $string
   *   The input string.
   *
   * @return string
   *   The string with four byte characters removed.
   */
  public static function stripFourBytes($string) {
    return preg_replace(self::$fourByteRegex, '', $string);
  }

  /**
   * Replaces four byte characters with their HTML unicode codepoint.
   *
   * @param string $string
   *   The input string.
   *
   * @return string
   *   The string with four byte characters converted.
   */
  public static function convertFourBytes($string) {
    return preg_replace_callback(self::$fourByteRegex, array('FeedsJSONPathParser', 'doFourByteReplace'), $string);
  }

  /**
   * Callback for FeedsJSONPathParser::convertFourBytes().
   *
   * @param array $matches
   *   The regular expression matches.
   *
   * @return string
   *   A four byte unicode character converted to its HTML representation.
   */
  public static function doFourByteReplace(array $matches) {
    $char = $matches[0];

    // Calculate the codepoint of the character.
    $codepoint = ord($char[0]) - 0xF0 << 18;
    $codepoint += ord($char[1]) - 0x80 << 12;
    $codepoint += ord($char[2]) - 0x80 << 6;
    $codepoint += ord($char[3]) - 0x80;

    return '&#' . $codepoint . ';';
  }

}
