<?php

/**
 * @file
 * File nys_legislation_spotcheck.inc
 */

/**
 * Class SpotcheckContentType.
 *
 * Enumeration of spotcheck content types
 */
abstract class SpotcheckContentType {

  const AGENDA = 'agenda';

  const BILL = 'bill';

  const CALENDAR = 'calendar';

  private const TYPES
    = [
      self::AGENDA,
      self::BILL,
      self::CALENDAR,
    ];

  /**
   * Get a string containing all available types.
   *
   *
   * @return string - a formatted string displaying the available types
   */
  public static function getTypesStr() {
    return array_reduce(
      static::TYPES, function ($carry, $item) {
      return $carry ? $carry . ', ' . $item : $item;
    }
    );
  }

  /**
   * Verifies the content type of the passed in string.
   *
   * @param $contentTypeStr
   *
   * @return string|bool
   */
  public static function getSpotcheckContentType($contentTypeStr) {
    foreach (static::TYPES as $type) {
      if ($type === $contentTypeStr) {
        return $type;
      }
    }
    return FALSE;
  }
}

/**
 * Class SpotcheckDumpLoader.
 *
 * Used to retrieve batches of nodes for use in OpenLegislation spotchecks.
 * Implemented by each content type for content-specific queries.
 */
abstract class SpotcheckDumpLoader implements Iterator {

  protected const NODE_ALIAS = 'n';

  /** @var null/int cache the total number of results for the query */
  private $totalResults = NULL;

  /** @var int indicates the part number of the current batch */
  protected $part = 1;

  /** @var int the number of a selected part if applicable. */
  protected $selectedPart = NULL;

  /** @var array passed in params that may limit the results. */
  protected $params;

  /**
   * SpotcheckDumpLoader constructor.
   *
   * @param $params
   */
  public function __construct($params) {
    $this->params = $params;
    $selectedPart = $this->getParam('part');
    if (is_numeric($selectedPart)) {
      $this->part = $this->selectedPart = $selectedPart;
    }
  }

  /* Iterator implementation */

  /**
   * Load and return nodes for the current window.
   *
   * @return array
   */
  public function current() {
    return $this->getCurrentNodes();
  }

  /**
   * Determine if the current part is valid.
   *
   * @return bool
   */
  public function valid() {
    // If there is a selected part, then it is the only valid part.
    if (is_numeric($this->selectedPart)) {
      return $this->part == $this->selectedPart;
    }
    return $this->part > 0 && $this->part <= $this->getPartCount();
  }


  /**
   * Increment the part number
   *
   * This should be extended with content-specific logic.
   */
  public function next() {
    $this->part++;
  }

  /**
   * Return the part number as key.
   *
   * @return int
   */
  public function key() {
    return $this->part;
  }

  /**
   * Reset the part number.
   */
  public function rewind() {
    if (is_numeric($this->selectedPart)) {
      // If there is a selected part, go right to it.
      $this->part = $this->selectedPart;
    }
    else {
      // Otherwise start at 1
      $this->part = 1;
    }
  }

  /* Public methods */

  /**
   * Compute and return the total number of expected parts for the dump.
   *
   * @return int part count
   */
  public abstract function getPartCount();

  /**
   * Get the total number of nodes using the cached value if possible.
   *
   * @return int the total number of nodes
   */
  public function getTotal() {
    if ($this->totalResults === NULL) {
      $this->totalResults = $this->getBaseQuery()
        ->countQuery()
        ->execute()
        ->fetchField();
    }
    return $this->totalResults;
  }

  /* Internal Methods */

  /**
   * Load and return the next batch of nodes.
   *
   * @return array
   */
  protected function getCurrentNodes() {
    $nids = $this->getCurrentNids();
    $nodes = node_load_multiple($nids, [], TRUE);
    $this->prepareNodes($nodes);
    return $nodes;
  }

  /**
   * Return the next batch of node ids
   *
   * @return array of node ids
   */
  protected function getCurrentNids() {
    $query = $this->getCurrentNidsQuery();

    $result = $query->execute();

    $nids = [];

    foreach ($result->fetchAll() as $row) {
      array_push($nids, $row->nid);
    }

    return $nids;
  }


  /**
   * Get an array of node ids for the current position.
   *
   * @return SelectQuery
   */
  protected abstract function getCurrentNidsQuery();

  /**
   * Performs cleaning and any necessary manipulations to the nodes.
   *
   * @param $nodes
   */
  protected function prepareNodes(&$nodes) {
    nys_legislation_spotcheck_clean_nodes($nodes);
  }

  /**
   * Gets the node types queried.
   *
   * @return array - the node types corresponding to the content type
   */
  protected abstract function getNodeTypes();

  /**
   * Adds the appropriate table joins to the given query.
   *
   * @param $query SelectQuery
   */
  protected abstract function addJoins($query);

  /**
   * Adds WHERE conditions to the given query based on the given params.
   *
   * @param $query SelectQuery
   */
  protected abstract function addConditions($query);

  /**
   * Adds an order by clause to the query.
   *
   * Defaults to sorting by node id.
   *
   * @param $query SelectQuery
   */
  protected function addOrderBy($query) {
    $query->orderBy(static::NODE_ALIAS . '.nid');
  }

  /**
   * Gets a base query that retrieves all node ids for the given params
   *
   * @return SelectQuery
   */
  protected function getBaseQuery() {
    $query = db_select('node', static::NODE_ALIAS);
    $this->addJoins($query);
    $query->fields(static::NODE_ALIAS, ['nid'])
      ->condition(static::NODE_ALIAS . '.type', $this->getNodeTypes(), 'IN');
    $this->addConditions($query);
    $this->addOrderBy($query);
    return $query;
  }

  /**
   * Get the value of the given param or null if it doesn't exist.
   *
   * @param $name
   *
   * @return mixed|null
   */
  protected function getParam($name) {
    return $this->params[$name] ?? NULL;
  }
}

/**
 * Class LimitedSpotcheckDumpLoader
 *
 * Implements dump splitting logic such that results are returned in limited
 * chunks.
 */
abstract class LimitedSpotcheckDumpLoader extends SpotcheckDumpLoader {

  protected const DEFAULT_LIMIT = 100;

  /**
   * Compute and return the total number of expected parts for the dump.
   *
   * Calculate using total results / part size limit.
   *
   * @return int part count
   */
  public function getPartCount() {
    return (int) ceil($this->getTotal() / $this->getLimit());
  }

  /**
   * Get the part size limit.
   *
   * @return int the part size limit
   */
  protected function getLimit() {
    return static::DEFAULT_LIMIT;
  }

  /**
   * Compute the offset for the current part.
   *
   * @return int
   */
  protected function getOffset() {
    return ($this->part - 1) * $this->getLimit();
  }

  /**
   * Get an array of node ids for the current position.
   *
   * Simply restricts the base query using computed limit and offset.
   *
   * @return SelectQuery
   */
  protected function getCurrentNidsQuery() {
    return $this->getBaseQuery()
      ->range($this->getOffset(), $this->getLimit());
  }
}

/**
 * Class SessionSpotcheckDumpLoader.
 *
 * Meant for content types that are categorized by session year (as opposed to
 * standard year).
 */
abstract class SessionSpotcheckDumpLoader extends LimitedSpotcheckDumpLoader {

  protected const session_alias = 's';

  protected const session_field = 'field_ol_session_value';

  private $session;

  /**
   * SessionSpotcheckDumpQuery constructor.
   *
   * @param $params
   */
  public function __construct($params) {
    parent::__construct($params);
    $year = $this->getParam('year');
    $this->session = nys_legislation_spotcheck_get_session_year($year);
  }

  /**
   * Join to openleg session table.
   *
   * @param SelectQuery $query
   */
  protected function addJoins($query) {
    $query->join(
      'field_data_field_ol_session', static::session_alias,
      static::session_alias . '.entity_id = ' . static::NODE_ALIAS . '.nid'
    );
  }

  /**
   * Add where clause to select session year.
   *
   * @param SelectQuery $query
   */
  protected function addConditions($query) {
    $query->condition(
      static::session_alias . '.' . static::session_field, $this->session, '='
    );
  }
}

/**
 * Class YearlySpotcheckDumpLoader.
 *
 * Meant for content types that are categorized by year.
 */
abstract class YearlySpotcheckDumpLoader extends LimitedSpotcheckDumpLoader {

  protected const year_alias = 'y';

  protected const year_field = 'field_ol_year_value';

  private $year;

  /**
   * YearlySpotcheckDumpQuery constructor.
   *
   * @param $params
   */
  public function __construct($params) {
    parent::__construct($params);
    $this->year = $this->getParam('year');
    if (!is_numeric($this->year)) {
      throw new InvalidArgumentException(
        "Parameter \$year must be integer. Received '$this->year'"
      );
    }
  }

  /**
   * Joins openleg year table.
   *
   * @param SelectQuery $query
   */
  protected function addJoins($query) {
    $query->join(
      'field_data_field_ol_year', static::year_alias,
      static::year_alias . '.entity_id = ' . static::NODE_ALIAS . '.nid'
    );
  }

  /**
   * Adds where clause to select any of the two years under the given session.
   *
   * @param SelectQuery $query
   */
  protected function addConditions($query) {
    $query->condition(
      static::year_alias . '.' . static::year_field, $this->year, '='
    );
  }
}

/**
 * Class BillSpotcheckDumpLoader.
 *
 * Queries bill and resolution nodes.
 */
class BillSpotcheckDumpLoader extends SessionSpotcheckDumpLoader {

  /**
   * {@inheritdoc}
   */
  protected function getNodeTypes() {
    return ['bill', 'resolution'];
  }

  /**
   * Returns the content type.
   */
  public function getContentType() {
    return SpotcheckContentType::BILL;
  }

  /**
   * {@inheritdoc}
   */
  public function prepareNodes(&$nodes) {
    parent::prepareNodes($nodes);

    self::loadVotes($nodes);
  }

  /**
   * Load and set votes for the given bill nodes.
   *
   * @param $bill_nodes array - loaded bill nodes
   */
  private function loadVotes(&$bill_nodes) {
    // A map of vote eid -> vote data
    $vote_map = [];

    foreach ($bill_nodes as $node) {
      $vote_refs = nys_av(LANGUAGE_NONE, $node->field_ol_votes, []);
      if (is_array($vote_refs)) {
        foreach ($vote_refs as $vote_entity_ref) {
          // Initialize vote value to false
          $vote_map[$vote_entity_ref['value']] = FALSE;
        }
      }
    }

    $votes = entity_load(
      'field_collection_item', array_keys($vote_map), [], TRUE
    );
    nys_legislation_spotcheck_clean_nodes($votes);

    // Iterate though each vote,
    // setting committee and member id values for all references
    foreach ($votes as $eid => $vote) {
      // Set committee name
      $comm_field = 'field_ol_committee';
      $comm_list = nys_av(LANGUAGE_NONE, $vote->{$comm_field}, []);
      if (is_array($comm_list)) {
        foreach ($comm_list as $i => $comm_ref) {
          $tid = $comm_ref['target_id'];
          $term = taxonomy_term_load($tid);
          $comm_ref['value'] = $term !== FALSE ? $term->name : "Unknown";
          $votes[$eid]->{$comm_field}[LANGUAGE_NONE][$i] = $comm_ref;
        }
      }
      // Set member ids
      foreach (get_object_vars($vote) as $var => $value) {
        $member_field_suffix = "_members";
        if ($member_field_suffix === substr(
            $var, -strlen($member_field_suffix)
          )
        ) {
          $member_ref_list = nys_av(LANGUAGE_NONE, $value, []);
          if (is_array($member_ref_list)) {
            foreach ($member_ref_list as $i => $member_ref) {
              $nid = $member_ref['target_id'];
              $member_ref['value'] = nys_utils_get_member_id_from_senator_nid(
                $nid
              );
              $votes[$eid]->{$var}[LANGUAGE_NONE][$i] = $member_ref;
            }
          }
        }
      }
      $vote_map[$eid] = $vote;
    }

    // Set loaded votes for each bill
    foreach ($bill_nodes as $node_idx => $node) {
      $vote_refs = nys_av(LANGUAGE_NONE, $node->field_ol_votes, []);
      if (is_array($vote_refs)) {
        foreach ($vote_refs as $vote_idx => $vote_entity_ref) {
          // Set vote value
          $vote = $vote_map[$vote_entity_ref['value']];
          $bill_nodes[$node_idx]->field_ol_votes[LANGUAGE_NONE][$vote_idx]['value']
            = $vote;
        }
      }
    }
  }
}

/**
 * Class CalendarSpotcheckDumpLoader.
 *
 * Queries calendar nodes.
 */
class CalendarSpotcheckDumpLoader extends YearlySpotcheckDumpLoader {

  /**
   * {@inheritdoc}
   */
  protected function getNodeTypes() {
    return ['calendar'];
  }

  /**
   * Returns the content type.
   */
  public function getContentType() {
    return SpotcheckContentType::CALENDAR;
  }

  /**
   * {@inheritdoc}
   */
  public function prepareNodes(&$nodes) {
    parent::prepareNodes($nodes);

    self::getCalendars($nodes);
  }

  /**
   * Extracts individual calendars from calendar nodes.
   *
   * @param $nodes
   */
  private function getCalendars(&$nodes) {
    $cal_eids = [];
    foreach ($nodes as $node) {
      foreach ($node->field_ol_cal[LANGUAGE_NONE] as $cal_entity_ref) {
        array_push($cal_eids, $cal_entity_ref['value']);
      }
    }

    $calendars = entity_load('field_collection_item', $cal_eids, [], TRUE);

    $bill_nid_map = self::getBillTitles($cal_eids);

    foreach ($nodes as $node) {
      foreach ($node->field_ol_cal[LANGUAGE_NONE] as &$cal_entity_ref) {
        $cal_eid = $cal_entity_ref['value'];
        $calendar = $calendars[$cal_eid];
        unset($calendar->field_ol_bill_names);

        self::setBillIds($calendar, $bill_nid_map);

        $cal_entity_ref['value'] = $calendar;
      }
    }
  }

  /**
   * Gets bill print nos from calendar bill references.
   *
   * @param $cal_eids
   *
   * @return array
   */
  private function getBillTitles($cal_eids) {
    $bill_nid_map = [];
    $bill_query_result = db_query(
      "SELECT DISTINCT node.nid, node.title " .
      "FROM field_data_field_ol_bill bill " .
      "JOIN node ON bill.field_ol_bill_target_id = node.nid " .
      "WHERE bill.entity_id IN (:calids)",
      [":calids" => $cal_eids]
    );

    // Map bill titles to their node ids.
    foreach ($bill_query_result->fetchAll() as $row) {
      $bill_nid_map[$row->nid] = $row->title;
    }
    return $bill_nid_map;
  }

  /**
   * Replaces bill nids with corresponding print_nos.
   *
   * @param $calendar
   * @param $bill_nid_map
   */
  private function setBillIds($calendar, $bill_nid_map) {
    foreach ($calendar->field_ol_bill[LANGUAGE_NONE] as &$bill_ref) {
      $nid = $bill_ref['target_id'];
      if (!array_key_exists($nid, $bill_nid_map)) {
        echo t("Bill nid not found: [$nid]!!!\n");
        continue;
      }
      $bill_ref['value'] = $bill_nid_map[$nid];
    }
  }

}

/**
 * Class AgendaSpotcheckDumpLoader.
 *
 * Queries agenda nodes.
 */
class AgendaSpotcheckDumpLoader extends YearlySpotcheckDumpLoader {

  /**
   * {@inheritdoc}
   */
  public function prepareNodes(&$nodes) {
    parent::prepareNodes($nodes);

    self::getAgendaBills($nodes);
  }

  /**
   * Returns the content type.
   */
  public function getContentType() {
    return SpotcheckContentType::AGENDA;
  }

  /**
   * {@inheritdoc}
   */
  protected function getNodeTypes() {
    return ['agenda'];
  }

  /**
   * Retrieves agenda bill info and sets on agenda.
   *
   * Replaces the list of eids for bill agenda info in an agenda nodes,
   * with actual bill agenda infos
   *
   * @param $agenda_nodes
   */
  private function getAgendaBills(&$agenda_nodes) {
    /** Mapping of EID -> bill agenda info */
    $bill_infos = [];

    // Get the EIDs for all bills referenced in the agendas.
    foreach ($agenda_nodes as $agenda_node) {
      $agenda_bill_refs = $agenda_node->field_ol_agenda_bills[LANGUAGE_NONE];
      if (empty($agenda_bill_refs)) {
        continue;
      }
      foreach ($agenda_bill_refs as $bill_info_ref) {
        $eid = $bill_info_ref["value"];
        // Store false as bill data for now, we will load data soon.
        $bill_infos[$eid] = FALSE;
      }
    }

    // Bulk load all referenced bills.
    $bill_infos = entity_load(
      "field_collection_item", array_keys($bill_infos), [], TRUE
    );
    nys_legislation_spotcheck_clean_nodes($bill_infos);

    // Map loaded bills to their eid.
    foreach ($bill_infos as $bill_info) {
      $bill_infos[$bill_info->item_id] = $bill_info;
    }

    // for each agenda, replace eid array with array of bills.
    foreach ($agenda_nodes as $agenda_node) {
      $agenda_bill_refs = &$agenda_node->field_ol_agenda_bills[LANGUAGE_NONE];
      if (empty($agenda_bill_refs)) {
        continue;
      }
      foreach ($agenda_bill_refs as &$bill_info_ref) {
        $eid = $bill_info_ref["value"];
        $bill_info_ref["value"] = $bill_infos[$eid];
      }
    }
  }
}

/**
 * Gets a dump querier for the given content type.
 *
 * @param $content_type string
 *
 * @param $params       array - content-specific parameters.
 *
 * @return SpotcheckDumpLoader A query object appropriate to the passed in
 *   SpotcheckContentType
 */
function nys_legislation_spotcheck_get_dump_loader($content_type, $params) {
  switch ($content_type) {
    case SpotcheckContentType::AGENDA:
      return new AgendaSpotcheckDumpLoader($params);
    case SpotcheckContentType::BILL:
      return new BillSpotcheckDumpLoader($params);
    case SpotcheckContentType::CALENDAR:
      return new CalendarSpotcheckDumpLoader($params);
    default:
      throw new InvalidArgumentException(
        "Unsupported spotcheck content type: $content_type"
      );
  }
}

/**
 * Gets the session year of the given year.
 *
 * @param $year int year
 *
 * @return int - the session year corresponding to the passed in year
 */
function nys_legislation_spotcheck_get_session_year($year) {
  if (!is_numeric($year)) {
    throw new InvalidArgumentException(
      "Parameter \$year must be integer. Received '$year'"
    );
  }
  return $year - 1 + $year % 2;
}

/**
 * Remove format and safe values from node objects to compress data.
 *
 * @param $nodes
 */
function nys_legislation_spotcheck_clean_nodes(&$nodes) {
  foreach ($nodes as &$node) {
    foreach ($node as $key => &$value) {
      if (isset($value[LANGUAGE_NONE][0]['format'])) {
        $value[LANGUAGE_NONE][0]['format'] = NULL;
      }
      if (isset($value[LANGUAGE_NONE][0]['safe_value'])) {
        $value[LANGUAGE_NONE][0]['safe_value'] = NULL;
      }
    }
  }
}
