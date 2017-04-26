<?php

/**
 * @file
 * Contains Drupal_SearchApi_Facetapi_QueryType_DateRangeQueryType.
 */

/**
 * Date range query type plugin for the Apache Solr Search Integration adapter.
 */
class Drupal_SearchApi_Facetapi_QueryType_DateRangeQueryType extends SearchApiFacetapiDate implements FacetapiQueryTypeInterface {

  /**
   * Implements FacetapiQueryTypeInterface::getType().
   */
  static public function getType() {
    return 'date_range';
  }

  /**
   * Implements FacetapiQueryTypeInterface::execute().
   */
  public function execute($query) {
    $this->adapter->addFacet($this->facet, $query);
    if ($active = $this->adapter->getActiveItems($this->facet)) {
      // Check the first value since only one is allowed.
      $filter = self::mapFacetItemToFilter(key($active));
      if ($filter) {
        $this->addFacetFilter($query, $this->facet['field'], $filter);
      }
    }
  }

  /**
   * Implements FacetapiQueryTypeInterface::build().
   *
   * Unlike normal facets, we provide a static list of options.
   */
  public function build() {
    $facet = $this->adapter->getFacet($this->facet);
    $search_ids = drupal_static('search_api_facetapi_active_facets', array());

    if (empty($search_ids[$facet['name']]) || !search_api_current_search($search_ids[$facet['name']])) {
      return array();
    }
    $search_id = $search_ids[$facet['name']];

    $build = array();
    $search = search_api_current_search($search_id);

    $results = $search[1];
    if (!$results['result count']) {
      return array();
    }

    // Executes query, iterates over results.
    if (isset($results['search_api_facets']) && isset($results['search_api_facets'][$this->facet['field']])) {
      $values = $results['search_api_facets'][$this->facet['field']];
      $build = date_facets_get_ranges();
      $now = $_SERVER['REQUEST_TIME'];
      // Calculate values by facet.
      foreach ($values as $value) {
        $value['filter'] = str_replace('"', '', $value['filter']);
        $diff = $now - $value['filter'];

        foreach ($build as $key => $item) {
          if ($diff < $item['#time_interval']) {
            $build[$key]['#count'] += $value['count'];
          }
        }
      }
    }

    // Unset empty items.
    foreach ($build as $key => $item) {
      if ($item['#count'] === NULL) {
        unset($build[$key]);
      }
    }

    // Gets total number of documents matched in search.
    $total = $results['result count'];
    $keys_of_active_facets = array();
    // Gets active facets, starts building hierarchy.
    foreach ($this->adapter->getActiveItems($this->facet) as $key => $item) {
      // If the item is active, the count is the result set count.
      $build[$key]['#count'] = $total;
      $keys_of_active_facets[] = $key;
    }

    // If we have active item, unset other items.
    $settings = $facet->getSettings()->settings;
    if ((isset($settings['operator'])) && ($settings['operator'] !== FACETAPI_OPERATOR_OR)) {
      if (!empty($keys_of_active_facets)) {
        foreach ($build as $key => $item) {
          if (!in_array($key, $keys_of_active_facets)) {
            unset($build[$key]);
          }
        }
      }
    }

    return $build;
  }

  /**
   * Maps a facet item to a filter.
   *
   * @param string $key
   *   Facet item key, for example 'past_hour'.
   *
   * @return string|false
   *   A string that can be used as a filter, false if no filter was found.
   */
  public function mapFacetItemToFilter($key) {
    $options = self::getFacetItems();
    return isset($options[$key]) ? $options[$key] : FALSE;
  }

  /**
   * Gets a list of facet items and matching filters.
   *
   * @return array
   *   List of facet items and their filters.
   */
  public function getFacetItems() {
    $now = $_SERVER['REQUEST_TIME'];
    $past_hour = strtotime('-1 hour');
    $past_24_hours = strtotime('-24 hour');
    $past_week = strtotime('-1 week');
    $past_month = strtotime('-1 month');
    $past_year = strtotime('-1 year');

    $options = array(
      'past_hour'     => "[$past_hour TO $now]",
      'past_24_hours' => "[$past_24_hours TO $now]",
      'past_week'     => "[$past_week TO $now]",
      'past_month'    => "[$past_month TO $now]",
      'past_year'     => "[$past_year TO $now]",
    );

    return $options;
  }
}
