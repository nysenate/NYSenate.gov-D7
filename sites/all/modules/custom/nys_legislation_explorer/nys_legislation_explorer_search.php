<?php
/**
 * @file
 * Advanced Search Functions.
 */

/**
 * Page callback for the general search.
 *
 * @return mixed
 *   HTML output.
 */
function nys_legislation_explorer_general_search() {
  /** @var DrupalApacheSolrService $solr_service */
  $solr_service = get_solr_instance();
  $vars = array();

  $vars['session_years'] = get_session_year_list();
  $vars['years'] = get_year_list(2009);
  // Transcripts go back to 1993.
  $vars['tx_years'] = get_year_list(1993);
  $vars['bill_status_codes'] = get_bill_status_list();
  $vars['senator_list'] = get_senator_list();
  $vars['committees'] = get_committees();
  $vars['months'] = get_month_list();

  $type = (!empty($_GET['type'])) ? $_GET['type'] : NULL;
  $curr_page = (!empty($_GET['page'])) ? $_GET['page'] : 1;
  $per_page = 10;
  $redirect = (isset($_GET['redirect'])) ? $_GET['redirect'] : FALSE;
  $sort_order = (!empty($_GET['sort']) && $_GET['sort'] === 'asc') ? 'asc' : 'desc';
  $vars['search']['sort'] = $sort_order;

  $search_vars = array(
    'type',
    'searched',
    'bill_printno',
    'bill_session_year',
    'bill_sponsor',
    'bill_status',
    'bill_status_year',
    'bill_status_month',
    'bill_committee',
    'bill_text',
    'bill_issue',
    'resolution_printno',
    'resolution_text',
    'resolution_sponsor',
    'resolution_session_year',
    'calendar_month',
    'calendar_year',
    'calendar_date',
    'agenda_month',
    'agenda_year',
    'agenda_date',
    'agenda_committee',
    'session_trans_month',
    'session_trans_year',
    'session_trans_date',
    'session_trans_text',
    'hearing_trans_month',
    'hearing_trans_year',
    'hearing_trans_date',
    'hearing_trans_text',
  );
  foreach ($search_vars as $search_var) {
    $vars['search'][$search_var] = isset($_GET[$search_var]) ? htmlentities(filter_xss($_GET[$search_var], array()), ENT_QUOTES) : NULL;
  }

  if ($type) {
    $search = '';
    switch ($type) {
      case 'f_bill':
        $search = get_bill_search_query($vars['search']);
        break;

      case 'f_resolution':
        $search = get_reso_search_query($vars['search']);
        break;

      case 'f_calendar':
        $search = get_calendar_search_query($vars['search']);
        break;

      case 'f_agenda':
        $search = get_agenda_search_query($vars['search']);
        break;

      case 'f_session_trans':
        $search = get_sess_trans_search_query($vars['search']);
        break;

      case 'f_hearing_trans':
        $search = get_hearing_trans_search_query($vars['search']);
        break;
    }
    $search['params']['start'] = ($curr_page - 1) * $per_page;
    $search['params']['sort'] = get_solr_sort($type, $sort_order);
    $search['params']['fl'] = '*';
    $vars['total'] = 0;
    try {
      $resp = $solr_service->search(@$search['query'], $search['params'], 'GET');

      // If the bill has an active version, attach it to the object.
      foreach ($resp->response->docs as &$doc) {
        if (isset($doc->entity_id) && is_numeric($doc->entity_id)) {
          $doc_emw = entity_metadata_wrapper('node', $doc->entity_id);
          if ($doc_emw->__isset('field_ol_active_version') && !empty($doc_emw->field_ol_active_version->value())) {
            $doc->sm_field_ol_active_version = $doc_emw->field_ol_active_version->value();
          }
        }
      }
      /* @var object $resp JSON object. */
      $vars['pagination'] = get_pagination_state($resp->response->numFound, $per_page, $curr_page, 10);
      $vars['sort_desc'] = get_sort_desc($type);
      $vars = array_merge($vars,
        array(
          'resp' => $resp,
          'total' => $resp->response->numFound,
        )
      );

      // Handle direct url redirection for certain content types.
      if ($redirect && $resp && $resp->response->numFound == 1 && ($type == 'f_calendar' || $type == 'f_agenda')) {
        $doc = $resp->response->docs[0];
        if ($type == 'f_calendar') {
          drupal_goto('/calendar/sessions/' . strtolower(date('F-d-Y', $doc->its_ol_cal_date)) . '/session-' . date('n-j-y', $doc->its_ol_cal_date));
          return FALSE;
        }
        elseif ($type == 'f_agenda') {
          drupal_goto($doc->url);
          return FALSE;
        }
      }
      $vars['error'] = '';
    }
    catch (Exception $ex) {
      $vars['error'] = 'An unexpected error has occurred while searching. Please try again later.';
    }
  }
  drupal_set_title('Advanced Legislation Search');
  return theme('legislation_explorer_search_general', $vars);
}

/**
 * Returns an instance of the Solr Search Service used to perform the searches.
 */
function get_solr_instance() {
  $solr_instance_cache_key = 'leg-explorer-solr-instance';
  $solr_name_cache_key = 'leg-explorer-solr-name';
  // Determine if the configured solr instance was changed.
  $solr_env_id = variable_get('apachesolr_default_environment', 'solr');
  $config_changed = cache_get($solr_name_cache_key) == FALSE ||
                    cache_get($solr_name_cache_key)->data != $solr_env_id;
  // Create a new solr service object if the cached one is not valid.
  if (cache_get($solr_instance_cache_key) == FALSE || $config_changed) {
    $environments = apachesolr_load_all_environments();
    $solr_url = $environments[$solr_env_id]['url'];
    $solr_service = class_exists('PantheonApacheSolrService') ? new PantheonApacheSolrService($solr_url, $solr_env_id) : new DrupalApacheSolrService($solr_url, $solr_env_id);
    cache_set($solr_name_cache_key, $solr_env_id);
    cache_set($solr_instance_cache_key, $solr_service);
  }
  return cache_get($solr_instance_cache_key)->data;
}

/**
 * Return a solr sort param based on the content type and the sort direction.
 *
 * @param string $type
 *   Content type to sort on.
 * @param string $sort_order
 *   Order to sort content type.
 *
 * @return string
 *   String describing the sort order.
 */
function get_solr_sort($type, $sort_order) {
  switch ($type) {
    // Bill falls through to resolution.
    case 'f_bill':

    case 'f_resolution':
      $solr_sort = "its_field_ol_session $sort_order, score desc";
      break;

    case 'f_agenda':
      $solr_sort = "its_meeting_date $sort_order";
      break;

    case 'f_calendar':
      $solr_sort = "its_ol_cal_date $sort_order";
      break;

    // Session falls through to hearing transcript.
    case 'f_session_trans':

    case 'f_hearing_trans':
      $solr_sort = "its_ol_publish_date $sort_order";
      break;

    default: $solr_sort = "score $sort_order";
  }
  return $solr_sort;
}

/**
 * Returns a description for the asc./dec. order by content type.
 *
 * @param string $type
 *   Content type.
 *
 * @return array
 *   Strings describing the content type ordering.
 */
function get_sort_desc($type) {
  switch ($type) {
    case 'f_bill':
      return array('Older bills first', 'Recent bills first');

    case 'f_resolution':
      return array('Older resolutions first', 'Recent resolutions first');

    case 'f_agenda':
      return array('Older meetings first', 'Recent meetings first');

    case 'f_calendar':
      return array('Older sessions first', 'Recent sessions first');

    case 'f_session_trans':

    case 'f_hearing_trans':
      return array('Older transcripts first', 'Recent transcripts first');

  }
  return array('Asc', 'Desc');
}

/**
 * Returns a solr query for searching bills based on search parameters.
 *
 * @param array $search
 *   Provided search vars.
 *
 * @return array
 *   Solr query and parameters.
 */
function get_bill_search_query($search) {
  $fq_params = array(
    'bundle' => 'bill',
    'sm_field_ol_print_no' => (!empty($search['bill_printno'])) ? strtoupper($search['bill_printno']) : '',
    'itm_field_ol_session' => (!empty($search['bill_session_year'])) ? $search['bill_session_year'] : '',
    'sm_field_ol_sponsor' => (!empty($search['bill_sponsor'])) ? '"node:' . $search['bill_sponsor'] . '"' : '',
    'sm_field_ol_last_status' => (!empty($search['bill_status'])) ? strtoupper($search['bill_status']) : '',
    'sm_vid_Issues' => (!empty($search['bill_issue'])) ? $search['bill_issue'] : '',
    'sm_field_ol_latest_status_commit' => (!empty($search['bill_committee'])) ? '"' . ucwords($search['bill_committee']) . '"' : '',
    'its_ol_last_status_date' => get_solr_date_search($search['bill_status_month'], NULL, $search['bill_status_year'], TRUE),
  );
  if (!$search['bill_printno']) {
    $fq_params['bs_field_ol_is_amended'] = "FALSE";
  }
  $params['fq'] = build_solr_query_from_params($fq_params);

  // We use one bill text field to search across the title, bill text, or memo.
  $query = (!empty($search['bill_text'])) ? $search['bill_text'] : '';
  $params['qf'] = implode(' ', array(
    'content',
    'ts_ol_full_text',
    'ts_ol_memo',
  ));

  return array(
    'query' => $query,
    'params' => $params,
  );
}

/**
 * Returns a solr query for searching resolutions based on search parameters.
 *
 * @param array $search
 *   Provided search vars.
 *
 * @return array
 *   Solr query and parameters.
 */
function get_reso_search_query($search) {
  $fq_params = array(
    'bundle' => 'resolution',
    'sm_field_ol_sponsor' => (!empty($search['resolution_sponsor'])) ? '"node:' . $search['resolution_sponsor'] .'"' : '',
    'its_field_ol_session' => (!empty($search['resolution_session_year'])) ? $search['resolution_session_year'] : '',
    'sm_field_ol_print_no' => (!empty($search['resolution_printno'])) ? strtoupper($search['resolution_printno']) : '',
  );
  $params['fq'] = build_solr_query_from_params($fq_params);

  $params['qf'] = 'ts_ol_full_text';
  $query = (!empty($search['resolution_text'])) ? $search['resolution_text'] : '';
  return array(
    'query' => $query,
    'params' => $params,
  );
}

/**
 * Returns a solr query for searching agendas based on search parameters.
 *
 * @param array $search
 *   Provided search vars.
 *
 * @return array
 *   Solr query and parameters.
 */
function get_agenda_search_query($search) {
  $fq_params = array(
    'bundle' => 'meeting',
    'sm_vid_Committees' => (!empty($search['agenda_committee'])) ? '"' . $search['agenda_committee'] . '"' : '',
    'its_meeting_date' => get_solr_date_search($search['agenda_month'], $search['agenda_date'], $search['agenda_year'], TRUE),
  );
  $params['fq'] = build_solr_query_from_params($fq_params);
  return array(
    'query' => '',
    'params' => $params,
  );
}

/**
 * Returns a solr query for searching calendars based on search parameters.
 *
 * @param array $search
 *   Provided search vars.
 *
 * @return array
 *   Solr query and parameters.
 */
function get_calendar_search_query($search) {
  $fq_params = array(
    'bundle' => 'calendar',
    'its_ol_cal_date' => get_solr_date_search($search['calendar_month'], $search['calendar_date'], $search['calendar_year'], TRUE),
  );
  $params['fq'] = build_solr_query_from_params($fq_params);
  return array(
    'query' => '',
    'params' => $params,
  );
}

/**
 * Returns a solr query for searching transcripts based on search parameters.
 *
 * @param array $search
 *   Provided search vars.
 *
 * @return array
 *   Solr query and parameters.
 */
function get_sess_trans_search_query($search) {
  $fq_params = array(
    'bundle' => 'transcript',
    'label' => 'Floor',
    'its_ol_publish_date' => get_solr_date_search($search['session_trans_month'], $search['session_trans_date'], $search['session_trans_year'], TRUE),
  );
  $params['fq'] = build_solr_query_from_params($fq_params);

  $params['qf'] = 'ts_ol_text';
  $query = (!empty($search['session_trans_text'])) ? '"' . $search['session_trans_text'] . '"' : '';

  return array(
    'query' => $query,
    'params' => $params,
  );
}

/**
 * Returns a solr query for searching transcripts based on search parameters.
 *
 * @param array $search
 *   Provided search vars.
 *
 * @return array
 *   Solr query and parameters.
 */
function get_hearing_trans_search_query($search) {
  $fq_params = array(
    'bundle' => 'transcript',
    'label' => '"Public Hearing"',
    'its_ol_publish_date' => get_solr_date_search($search['hearing_trans_month'], $search['hearing_trans_date'], $search['hearing_trans_year'], TRUE),
  );
  $params['fq'] = build_solr_query_from_params($fq_params);

  $params['qf'] = 'ts_ol_text';
  $query = (!empty($search['hearing_trans_text'])) ? '"' . $search['hearing_trans_text'] . '"' : '';

  return array(
    'query' => $query,
    'params' => $params,
  );
}

/**
 * Constructs a solr field:value query based on params.
 *
 * @param array $params
 *   The field => value array to base the query off of.
 * @param string $glue
 *   The type of query string operator to use.
 *
 * @return string
 *   The solr field:value query.
 */
function build_solr_query_from_params(&$params, $glue = 'AND') {
  $solr_queries = array();
  foreach ($params as $field_name => &$val) {
    if (!empty($val)) {
      $solr_queries[] = "{$field_name}:{$val}";
    }
  }
  unset($val);
  return implode(" {$glue} ", $solr_queries);
}

/**
 * Returns a solr query string for searching within a certain month.
 *
 * @param int $month_val
 *   Month.
 * @param int $date_val
 *   Date.
 * @param int $year_val
 *   Year.
 * @param bool $use_timestamp
 *   Use the current timestamp.
 *
 * @return string
 *   Solr date query.
 */
function get_solr_date_search($month_val, $date_val, $year_val, $use_timestamp = FALSE) {
  if (!empty($year_val)) {
    $start_month = 1;
    $end_month = 13;
    $start_date = 1;
    $end_date = 0;
    if (!empty($month_val)) {
      $start_month = $month_val;
      if (!empty($date_val)) {
        $start_date = $end_date = $date_val;
        $end_month = $start_month;
      }
      else {
        $end_month = $start_month + 1;
      }
    }
    $start_timestamp = mktime(0, 0, 0, $start_month, $start_date, $year_val);
    $end_timestamp = mktime(23, 59, 59, $end_month, $end_date, $year_val);
    if ($use_timestamp) {
      return '[' . $start_timestamp . ' TO ' . $end_timestamp . ']';
    }
    else {
      $start_date = date('Y-m-d', $start_timestamp) . 'T00\:00\:00.000Z';
      $end_date = date('Y-m-d', $end_timestamp) . 'T59\:59\:59.999Z';
      return '[' . $start_date . ' TO ' . $end_date . ']';
    }
  }
  return '';
}

/**
 * Returns a list of session years in descending order.
 *
 * Restricts years from the current session year to the earliest session that
 * there is legislation data for (2009).
 *
 * @param int $min_year
 *   Minimum year restriction to fetch session years from.
 *
 * @return array
 *   Sessions years.
 */
function get_session_year_list($min_year = 2009) {
  $year = date("Y");
  $session_years = array();
  while ($year >= $min_year) {
    if ($year % 2 != 0) {
      $session_years[] = $year;
    }
    $year--;
  }
  return $session_years;
}

/**
 * Returns a list of years in descending order.
 *
 * Restricts years from the current year to the earliest year that there is
 * legislation data for (2009).
 *
 * @param int $min_year
 *   Minimum year restriction to fetch years from.
 *
 * @return array
 *   Years.
 */
function get_year_list($min_year = 2009) {
  $year = date("Y");
  $years = array();
  while ($year >= $min_year) {
    $years[] = $year;
    $year--;
  }
  return $years;
}

/**
 * Returns a list of months.
 *
 * @return array
 *   Months.
 */
function get_month_list() {
  $info = cal_info(0);
  return $info['months'];
}

/**
 * Returns a mapping of bill status codes to it's text representation.
 *
 * @return array
 *   Bill status map.
 */
function get_bill_status_list() {
  return array(
    'INTRODUCED' => 'Introduced',
    'IN_ASSEMBLY_COMM' => 'In Assembly Committee',
    'IN_SENATE_COMM' => 'In Senate Committee',
    'ASSEMBLY_FLOOR' => 'Assembly Floor Calendar',
    'SENATE_FLOOR' => 'Senate Floor Calendar',
    'PASSED_ASSEMBLY' => 'Passed Assembly',
    'PASSED_SENATE' => 'Passed Senate',
    'DELIVERED_TO_GOV' => 'Delivered to Governor',
    'SIGNED_BY_GOV' => 'Signed by Governor',
    'VETOED' => 'Vetoed',
    'STRICKEN' => 'Stricken',
    'LOST' => 'Lost',
  );
}

/**
 * Returns issue code taxonomy.
 *
 * @return mixed
 *   Issue codes.
 */
function get_issue_codes() {
  $vocabulary = taxonomy_vocabulary_machine_name_load('issues');
  return entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
}

/**
 * Returns committee taxonomy.
 *
 * @return mixed
 *   Committees.
 */
function get_committees() {
  $vocabulary = taxonomy_vocabulary_machine_name_load('committees');
  return entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
}

/**
 * Returns a cached list of senator short name -> full name mappings.
 *
 * @return array
 *   Senator name map.
 */
function get_senator_list() {
  $cache_key = 'nys_legislation_explorer_senator_list';
  if (cache_get($cache_key) == FALSE) {
    $senator_query = db_select('node', 'n');
    $senator_query->join('field_data_field_active', 'fa', 'n.nid = fa.entity_id');
    $senator_query->join('field_data_field_shortname', 'fs', 'n.nid = fs.entity_id');
    $senator_query->addField('n', 'nid');
    $senator_query->addField('n', 'title', 'full_name');
    $senator_query->addField('fs', 'field_shortname_value', 'shortname');
    $senator_query->addField('fa', 'field_active_value', 'active');
    $senator_query->condition('n.type', 'senator', '=');
    $senator_query->orderBy('fa.field_active_value DESC, fs.field_shortname_value', 'ASC');

    $senators_list = $senator_query->execute()->fetchAll();

    cache_set($cache_key, $senators_list);
  }
  return cache_get($cache_key)->data;
}

/**
 * Comparison function to sort the senator list by short name.
 *
 * @param array $s1
 *   First senator array to compare.
 * @param array $s2
 *   Second senator array to compare.
 *
 * @return int
 *   PHP strcmp result of the short names provided.
 */
function senator_nodes_sort($s1, $s2) {
  return strcmp($s1['short_name'], $s2['short_name']);
}

/**
 * Print out the nodes from JSON response.
 *
 * Useful for debugging.
 *
 * @param object &$resp
 *   JSON object.
 * @param string $type
 *   Node type filter.
 * @param bool $die
 *   Terminate the processing after completing the command.
 */
function debug_nodes(&$resp, $type, $die = TRUE) {
  $node_ids = array();
  foreach ($resp->response->docs as &$doc) {
    array_push($node_ids, $doc->entity_id);
  }
  $nodes = node_load_multiple($node_ids);
  foreach ($nodes as &$node) {
    if (!empty($type) && $node->bundle != $type) {
      // Skip printing if type is provided and unmatched.
    }
    else {
      print_r($node);
    }
  }
  if ($die) {
    die();
  }
}
