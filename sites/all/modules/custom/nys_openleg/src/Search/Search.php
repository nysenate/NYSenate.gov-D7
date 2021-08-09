<?php

namespace Nys_Openleg\Search;

use Nys_Openleg\ApiRequest;

/**
 * Class Search
 *
 * Base class for OpenLegislation's Search API.  This must be
 * extended into the specific search types (e.g., Statute).
 *
 * NOTE: OL Search API indices start with 1.  This class does
 * not assume any zero-based values.
 *
 * @package Nys_Openleg\Search
 */
abstract class Search {

  /**
   * @var int
   */
  protected $page;

  /**
   * @var int
   */
  protected $per_page;

  /**
   * @var int
   */
  protected $offset;

  /**
   * @var array
   */
  protected $count;

  /**
   * @var array
   */
  protected $data;

  /**
   * @var string
   */
  protected $search_term;

  /**
   * @var string
   */
  protected $endpoint = '';

  public function __construct($search_term, $params = []) {
    $this->setParams($params);
    $this->execute($search_term);
  }

  public function setParams($params = []) {
    $this->page = (int) ($params['page'] ?? 1);
    $this->per_page = (int) ($params['per_page'] ?? 10);
    $this->offset = (int) ($params['offset'] ?? 0);
  }

  public function execute($search_term = '') {
    $offset = $this->offset ?: ((($this->page - 1) * $this->per_page) + 1);
    $params = [
      'term' => urlencode($search_term),
      'offset' => $offset,
      'limit' => $this->per_page,
    ];

    $request = new ApiRequest($this->endpoint . '/search');
    $result = $request->get('', $params);
    $this->data = $result->result->items ?? [];
    $this->count = [
      'total' => (int) $result->total,
      'start' => (int) $result->offsetStart,
      'end' => (int) $result->offsetEnd,
    ];
  }

  public function getCount($type = NULL) {
    if (!is_null($type)) {
      return $this->count[$type] ?? 0;
    }
    else {
      return $this->count;
    }
  }

  public function getResults() {
    return $this->data;
  }
}
