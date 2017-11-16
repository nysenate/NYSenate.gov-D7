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

  private static $TYPES = [self::AGENDA, self::BILL, self::CALENDAR];

  /**
   * Get a string containing all available types.
   *
   * @return string - a formatted string displaying the available types
   */
  public static function getTypesStr() {
    return array_reduce(self::$TYPES, function ($carry, $item) {
      return $carry ? $carry . ', ' . $item : $item;
    });
  }

  /**
   * Verifies the content type of the passed in string.
   *
   * @param $contentTypeStr
   *
   * @return bool
   */
  public static function getSpotcheckContentType($contentTypeStr) {
    foreach (self::$TYPES as $type) {
      if ($type === $contentTypeStr) {
        return $type;
      }
    }
    return FALSE;
  }
}

/**
 * Class SpotcheckDumpQuery.
 *
 * Used to retrieve node data for use in OpenLegislation spotchecks
 * Provides base methods for data retrieval and node cleaning
 * Implemented by each content type for content-specific queries
 */
abstract class SpotcheckDumpQuery {

  protected static $node_alias = 'n';

  /* Abstract methods */

  /**
   * Gets the content type supported by this query.
   *
   * @return string SpotcheckContentType of the query implementation
   */
  public abstract function getContentType();

  /**
   * Returns true if the content type queried is session based.
   *
   * @return boolean returns true if the content is queried by session
   */
  public abstract function isSessionBased();

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
   * Adds WHERE conditions to the given query based on the given year.
   *
   * @param $query SelectQuery
   * @param $year int
   */
  protected abstract function addConditions($query, $year);

  /* Public methods */

  /**
   * Get a count of the total number of query results.
   *
   * @param $year int
   *
   * @return int the number of content nodes for the given year
   */
  public function getDumpTotalCount($year) {
    return $this->getBaseQuery($year)
      ->countQuery()
      ->execute()
      ->fetchField();
  }

  /**
   * Return content node ids for the given session year.
   *
   * Supports pagination via limit and offset params.
   *
   * @param $year int - year
   * @param $limit int - maximum number of node ids returned
   * @param $offset int - index of the first node id returned
   *
   * @return array of node ids
   */
  public function getNids($year, $limit, $offset) {
    $query = $this->getBaseQuery($year)
      ->range($offset, $limit);

    $result = $query->execute();

    $nids = [];

    foreach ($result->fetchAll() as $row) {
      array_push($nids, $row->nid);
    }

    return $nids;
  }

  /**
   * Performs cleaning and any necessary manipulations to the nodes.
   *
   * @param $nodes
   */
  public function prepareNodes(&$nodes) {
    nys_legislation_spotcheck_clean_nodes($nodes);
  }

  /* Internal Methods */

  /**
   * Gets a base query that retrieves all node ids for the given session year.
   *
   * @param $year int - year
   *
   * @return SelectQuery
   */
  private function getBaseQuery($year) {
    $query = db_select('node', $this::$node_alias);
    $this->addJoins($query);
    $query->fields($this::$node_alias, ['nid'])
      ->condition($this::$node_alias . '.type', $this->getNodeTypes(), 'IN');
    $this->addConditions($query, $year);
    return $query;
  }
}

/**
 * Class SessionSpotcheckDumpQuery.
 *
 * Abstract extension of SpotcheckDumpQuery
 * Meant for content types that are categorized by session year (as opposed to
 * standard year)
 */
abstract class SessionSpotcheckDumpQuery extends SpotcheckDumpQuery {

  protected static $session_alias = 's';

  protected static $session_field = 'field_ol_session_value';

  /**
   * {@inheritdoc}
   */
  public function isSessionBased() {
    return TRUE;
  }

  /**
   * Join to openleg session table.
   *
   * @param SelectQuery $query
   */
  protected function addJoins($query) {
    $query->join('field_data_field_ol_session', $this::$session_alias,
      $this::$session_alias . '.entity_id = ' . $this::$node_alias . '.nid');
  }

  /**
   * Add where clause to select session year.
   *
   * @param SelectQuery $query
   * @param int $year
   */
  protected function addConditions($query, $year) {
    $session = nys_legislation_spotcheck_get_session_year($year);
    $query->condition($this::$session_alias . '.' . $this::$session_field, $session, '=');
  }
}

/**
 * Class YearlySpotcheckDumpQuery.
 *
 * Abstract extension of SpotcheckDumpQuery.
 *
 * Meant for content types that are categorized by year.
 */
abstract class YearlySpotcheckDumpQuery extends SpotcheckDumpQuery {

  protected static $year_alias = 'y';

  protected static $year_field = 'field_ol_year_value';

  /**
   * {@inheritdoc}
   */
  public function isSessionBased() {
    return FALSE;
  }

  /**
   * Joins openleg year table.
   *
   * @param SelectQuery $query
   */
  protected function addJoins($query) {
    $query->join('field_data_field_ol_year', $this::$year_alias,
      $this::$year_alias . '.entity_id = ' . $this::$node_alias . '.nid');
  }

  /**
   * Adds where clause to select any of the two years under the given session.
   *
   * @param SelectQuery $query
   * @param int $year
   */
  protected function addConditions($query, $year) {
    $or = db_or();
    $or->condition($this::$year_alias . '.' . $this::$year_field, $year, '=');
    $or->condition($this::$year_alias . '.' . $this::$year_field, $year + 1, '=');
    $query->condition($or);
  }
}

/**
 * Class BillSpotcheckDumpQuerier.
 *
 * Queries bill and resolution nodes.
 */
class BillSpotcheckDumpQuerier extends SessionSpotcheckDumpQuery {

  /**
   * {@inheritdoc}
   */
  protected function getNodeTypes() {
    return ['bill', 'resolution'];
  }

  /**
   * {@inheritdoc}
   */
  public function getContentType() {
    return SpotcheckContentType::BILL;
  }
}

/**
 * Class CalendarSpotcheckDumpQuerier.
 *
 * Queries calendar nodes.
 */
class CalendarSpotcheckDumpQuerier extends YearlySpotcheckDumpQuery {

  /**
   * {@inheritdoc}
   */
  protected function getNodeTypes() {
    return ['calendar'];
  }

  /**
   * {@inheritdoc}
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

    echo sizeof($cal_eids) . " calendar eids " . $cal_eids[0] . "\n";
    $calendars = entity_load('field_collection_item', $cal_eids, [], TRUE);
    echo sizeof($calendars) . " calendar entities\n";

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
      [":calids" => $cal_eids]);

    // Map bill titles to their node ids.
    foreach ($bill_query_result->fetchAll() as $row) {
      $bill_nid_map[$row->nid] = $row->title;
    }
    echo "got " . sizeof($bill_nid_map) . " billids\n";
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
        echo "Bill nid not found: [$nid]!!!\n";
        continue;
      }
      $bill_ref['value'] = $bill_nid_map[$nid];
    }
  }

}

/**
 * Class AgendaSpotcheckDumpQuerier.
 *
 * Queries agenda nodes.
 */
class AgendaSpotcheckDumpQuerier extends YearlySpotcheckDumpQuery {

  /**
   * {@inheritdoc}
   */
  public function prepareNodes(&$nodes) {
    parent::prepareNodes($nodes);

    self::getAgendaBills($nodes);
  }

  /**
   * {@inheritdoc}
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
    $bill_infos = entity_load("field_collection_item", array_keys($bill_infos), [], TRUE);
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
 * @param $content_type SpotcheckContentType
 *
 * @return SpotcheckDumpQuery A query object appropriate to the passed in
 *   SpotcheckContentType
 */
function nys_legislation_spotcheck_get_dump_querier($content_type) {
  switch ($content_type) {
    case SpotcheckContentType::AGENDA:
      return new AgendaSpotcheckDumpQuerier();
    case SpotcheckContentType::BILL:
      return new BillSpotcheckDumpQuerier();
    case SpotcheckContentType::CALENDAR:
      return new CalendarSpotcheckDumpQuerier();
  }
  throw new InvalidArgumentException("Invalid spotcheck content type: $content_type");
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
    throw new InvalidArgumentException("Parameter \$year must be integer. Received '$year'");
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
