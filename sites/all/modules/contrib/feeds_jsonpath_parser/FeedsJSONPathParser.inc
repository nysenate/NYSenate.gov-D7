<?php
// $Id: FeedsJSONPathParser.inc,v 1.1.2.4.2.4 2011/02/05 19:28:01 twistor Exp $

/**
 * @file
 *
 * Provides the Class for Feeds JSONPath Parser.
 */

/**
 * Base class for the HTML and XML parsers.
 */
class FeedsJSONPathParser extends FeedsParser {

  /**
   * Implementation of FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $mappings = $source->importer->processor->config['mappings'];
    $mappings = $this->filterMappings($mappings);
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

    if (is_array($array)) {
      require_once 'jsonpath-0.8.1.php';

      $all_items = $this->jsonPath($array, $source_config['context']);
      $this->debug($all_items, 'context');
      unset($array);

      foreach ($all_items as $item) {
        $parsed_item = $variables = array();
        foreach ($source_config['sources'] as $source => $query) {
          $parsed = $this->parseSourceElement($item, $query, $source);
          // Avoid null values.
          if (isset($parsed)) {
            // Variable sunstitution can't handle arrays.
            if (!is_array($parsed)) {
              $variables['{' . $mappings[$source] . '}'] = $parsed;
            }
            else {
              $variables['{' . $mappings[$source] . '}'] = '';
            }
            $parsed_item[$source] = $parsed;
          }
        }
        $result->items[] = $parsed_item;
      }
    }
    else {
      throw new Exception(t('There was an error decoding the JSON document.'));
    }
    return $result;
  }

  /**
   * Utilizes the jsonPath function from jsonpath-0.8.1.php
   *
   * jsonPath returns false if the expression returns zero results and that will
   * mess up our for loops, so return an empty array instead.
   *
   * @todo
   *   Firgure out error handling.
   * @param $array
   *   The input array to parse
   * @$expression
   *   The JSONPath expression.
   * @return array
   *   Returns an array that is the output of jsonPath
   */
  private function jsonPath($array, $expression) {
    $result = jsonPath($array, $expression);
    return ($result === FALSE) ? array() : $result;
  }

  /**
   * Parses one item from the context array.
   *
   * @param $item
   *   A PHP array.
   * @param $query
   *   A JSONPath query.
   * @return array
   *   An array containing the results of the query.
   */
  protected function parseSourceElement($item, $query, $source) {
    
    if (empty($query)) {
      return;
    }
    $results = $this->jsonPath($item, $query);
    $this->debug($results, $source);
    unset($item);

    /**
     * If there is one result, return it directly.  If there are no results,
     * return. Otherwise return the results.
     */
    if (count($results) === 1) {
      return $results[0];
    }
    if (count($results) === 0) {
      return;
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
        if ($mapping['unique']) {
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
      $form['jsonpath']['error_message']['#markup'] = t('FeedsJSONPathParser: No mappings were defined.');
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
        $form['jsonpath']['sources'][$source]['#description'] .= '<br>' . t('The variables '. implode(', ', $variables). ' are availliable for replacement.');
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
    $form = $this->sourceForm($this->config);
    $form['jsonpath']['context']['#required'] = FALSE;
    $form['jsonpath']['#collapsed'] = FALSE;
    return $form;
  }

  /**
  * Override parent::getMappingSources().
  */
  public function getMappingSources() {
    $mappings = $this->filterMappings(feeds_importer($this->id)->processor->config['mappings']);
    $next = 0;
 
    if (!empty($mappings)) {
      $last_mapping = end(array_keys($mappings));
      $next = explode(':', $last_mapping);
      $next = $next[1] + 1;
    }
    return array(
      'jsonpath_parser:' . $next => array(
        'name' => t('JSONPath Expression'),
        'description' => t('Allows you to configure n JSONPath expression that will populate this field.'),
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
    );
  }

  /**
   * Override parent::sourceFormValidate().
   *
   * If the values of this source are the same as the base config we set them to
   * blank to that the values will be inherited from the importer defaults.
   *
   * @param &$values
   *   The values from the form to validate, passed by reference.
   */
  public function sourceFormValidate(&$values) {
    $values = $values['jsonpath'];
    asort($values);
    asort($this->config);
    if ($values === $this->config) {
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
    $values['context'] = trim($values['context']);
    foreach ($values['sources'] as &$source) {
      $source = trim($source);
    }
  }

  /**
   * Filters mappings, returning the ones that belong to us.
   */
  private function filterMappings($mappings) {
    $our_mappings = array();
    foreach ($mappings as $mapping) {
      if (strpos($mapping['source'], 'jsonpath_parser:') === 0) {
        $our_mappings[$mapping['source']] = $mapping['target'];
      }
    }
    return $our_mappings;
  }

  private function debug($item, $source) {
    if (in_array($source, $this->debug)) {
      $o = '<ul>';
      foreach ($item as $i) {
        $o .= '<li>' . check_plain(var_export($i, TRUE)) . '</li>';
      }
      $o .= '</ul>';
      drupal_set_message($source . ':' . $o);
    }
  }
}
