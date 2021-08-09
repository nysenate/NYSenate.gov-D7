<?php

namespace Nys_Openleg\Request;

use Nys_Openleg\ApiRequest;

class Statute {

  /**
   * @var object Decoded JSON object representing an entry's tree.
   *
   * @see https://legislation.nysenate.gov/static/docs/html/laws.html#get-the-law-structure
   */
  public $tree;

  /**
   * @var object Decoded JSON object representing an entry's detail.
   *
   * @see https://legislation.nysenate.gov/static/docs/html/laws.html#get-a-law-sub-document
   */
  public $detail;

  /**
   * The Openleg endpoint used for this type of call.
   *
   * @var string
   */
  protected $endpoint = 'laws';

  protected $book = '';

  protected $location = '';

  protected $history = '';

  public function __construct($book, $location = '', $history = '') {
    $this->book = $book;
    $this->location = $location;
    $this->history = $this->resolveHistoryDate($history);

    if ($book) {
      $this->retrieveFull();
    }
  }

  protected function resolveHistoryDate($date = '') {
    if (!$date) {
      $date = $this->history;
    }
    $time = strtotime($date);
    return $time ? date('Y-m-d', $time) : '';
  }

  /**
   * @param string $book
   * @param string $location
   *
   * @return $this
   */
  public function retrieveFull($book = NULL, $location = NULL, $history = NULL) {
    // Reset local properties if a new request is being made.
    if (!is_null($book)) {
      $this->book = $book;
    }
    if (!is_null($location)) {
      $this->location = $location;
    }
    if (!is_null($history)) {
      $this->history = $this->resolveHistoryDate($history);
    }
    $history = $this->history ? ['date' => $this->history] : [];

    $request = new ApiRequest($this->endpoint);
    // Retrieve the law tree
    $params = array_merge(['depth' => 1, 'fromLocation' => $this->location], $history);
    $this->tree = $request->get($this->book, $params);

    // Retrieve the law detail
    $location = $this->location ?: $this->tree->result->documents->locationId;
    $this->detail = $request->get($this->book . '/' . $location, $history);

    return $this;
  }

  /**
   * @return \stdClass
   */
  public function document() {
    $ret = $this->tree->result->documents ?? (object) [];
    $ret->text = $this->detail->result->text ?? '';
    return $ret;
  }

  public function children() {
    return $this->tree->result->documents->documents->items ?? [];
  }

  public function parents() {
    return $this->detail->result->parents ?? [];
  }

  public function siblings() {
    return [
      'previous' => $this->detail->result->prevSibling ?? NULL,
      'next' => $this->detail->result->nextSibling ?? NULL,
    ];
  }

  public function fullTitle() {
    $detail = $this->detail->result;
    $parents = array_map(
      function ($v) {
        return $v->docType . ' ' . $v->docLevelId;
      },
      $this->parents()
    );
    $location = $parents
      ? $detail->lawName . ' (' . $detail->lawId . ') ' . implode(', ', $parents)
      : '';
    return [
      $detail->docType . ' ' . $detail->docLevelId,
      $detail->title,
      $location,
    ];
  }

  public function publishDates() {
    $sorted = $this->tree->result->publishedDates;
    sort($sorted);
    return $sorted;
  }

  public function text($raw = FALSE) {
    $ret = $this->detail->result->text ?? '';
    if (!$raw) {
      $ret = str_replace('\\n', '<br />', str_replace('\\n  ', '<br /><br />', htmlentities($ret, ENT_QUOTES)));
    }
    return $ret;
  }

}

