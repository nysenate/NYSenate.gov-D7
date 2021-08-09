<?php
/**
 * @file
 * Handles rendering for constituents petitions forms and tables.
 */

/**
 * Generates a render array for a constituent petition form.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   Form state array.
 * @param object $view
 *   View object to generate the form for.
 * @param string $argument
 *   Additional argument.
 * @param object $account
 *   Senator account to generate the form for.
 *
 * @return array
 *   Form render array.
 */
function nys_senator_constituents_petitions_form($form, &$form_state, $view, $argument, $account) {
  $form = array();
  $vid = is_object($view) ? $view->dom_id : $view;
  $form['#user'] = $account;

  $getvars = array(
    'namesearch',
    'agesearch',
    'gender',
    'zipsearch'
  );

  foreach($getvars as $var) {
    if (isset($_GET[$var]) && empty($form_state['input'][$var])) {
      $form_state['input'][$var] = $_GET[$var];
    }
  }

  $title = '';

  $form['#prefix'] = '';
  $form['#suffix'] = '';
  $form['#attributes']['class'][] = 'issue-filters';

  $form['filters']['label'] = array(
    '#markup' => '<label>Filter by Communication Status</label>',
  );

   $form['filters']['comm_status'] = array(
    '#type' => 'select',
     '#options' => array(
        'all' => t('All Types'),
        0 => t('Not Messaged'),
        1 => t('Messaged'),
     ),
     '#default_value' => 'all',
     '#theme_wrappers' => array('nude_form_element'),
     '#prefix' => '<div class="filter-wrapper filter-wrapper--msg">',
     '#suffix' => '</div>',
   );

$form['inbox_action_links'] = array(
    '#prefix' => '<div class="inbox-action-links">',
    '#suffix' => '</div>',
  );

   $form['inbox_action_links']['check_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check All'),
    '#prefix' => '<div class="select-all-messages">',
    '#suffix' => '</div>',
    '#attributes' => array('id' => 'checkall'),
  );

  $form['inbox_action_links']['actions'] = array(
    '#type' => 'actions',
    '#prefix' => '<div class="action-button-wrapper">',
    '#suffix' => '</div>',
  );

  $form['inbox_action_links']['actions']['message'] = array(
    '#type' => 'submit',
    '#value' => t('Message'),
    '#attributes' => array('class' => array('icon-before__contact')),
  );

  $form['senator_id'] = array(
    '#type' => 'hidden',
    '#value' => $account->uid,
  );

  $form['petition_id'] = array(
    '#type' => 'hidden',
    '#value' => $form_state['build_info']['args'][1],
  );

  $form['messages_table'] = array(
    '#markup' => nys_dashboard_senators_petitions_table($form, $form_state, $vid),
  );

  return $form;
}


function nys_senator_constituents_petitions_form_submit($form, &$form_state) {

  $user = user_load(arg(1));
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'),1);

 if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Message') {

    $queryArgs = array();
    $page_context = 'senators_petitions_tab';
    $uids = array_values($form_state['input']['list']);

    if ($form_state['input']['check_all'] == 1) {

      // to do: need to be able to message all constituents,
      // so a all_constituents filter needs to be added if no
      // queryArgs are present

      $queryArgs = nys_dashboard_senator_constituents_get_query_args($form_state['input']);
      if(empty($queryArgs)) { $queryArgs['all_constituents'] = true; }
      $queryArgs['uids'] = $uids;
      $queryArgs['context'] = $page_context;
      $queryArgs['petition_id'] = $form_state['input']['petition_id'];

      $form_state['redirect'] = array(
        $dashboard_link . '/inbox/new',
        array(
          'query' => $queryArgs,
        ),
      );
      return;
    }

    else if (!empty($form_state['input']['list'])) {
      $queryArgs['uids'] = $uids;
      $queryArgs['context'] = $page_context;
      $queryArgs['petition_id'] = $form_state['input']['petition_id'];
      // message the list
      $form_state['redirect'] = array(
        $dashboard_link . '/inbox/new',
        array(
          'query' => $queryArgs,
        ),
      );
      return;
    }
  }


  $getvars = array(
    'namesearch',
    'agesearch',
    'gender'
  );

  $queryArgs = array();

  foreach($getvars as $var) {
    if ($form_state['input'][$var] != "" && $form_state['input'][$var] != 'all') {
      $queryArgs[$var] = $form_state['input'][$var];
    }
  }

 if (!empty($form_state['input']['zipsearch']) && $form_state['input']['zipsearch'] != "Zip Code" && is_numeric($form_state['input']['zipsearch'])) {
   $queryArgs['zipsearch'] = $form_state['input']['zipsearch'];
 }

  $form_state['redirect'] = array(
    $dashboard_link . '/constituents',
    array(
      'query' => $queryArgs,
    ),
  );
}

/**
 * Generates a petitions signature table based on form state.
 *
 * @param array $form
 *   The current dashboard petition form.
 * @param array $form_state
 *   The current dashboard petition form state.
 * @param string $vid
 *   The view id of the view the table is being generated for.
 *   This is required to set the pager correctly via the cache.
 *
 * @return string
 *   Rendered markup for a petitions signature form.
 */
function nys_dashboard_senators_petitions_table($form, $form_state, $vid) {
  // @Todo: remove hard-coding and have it pull the view parameters.
  $limit = 10;

  $data = &drupal_static(__FUNCTION__);
  if ($cache = cache_get('nys_dashboard_petitions')) {
    $cache = $cache->data;
  }
  $user = isset($data['user']) ? $data['user'] : $form['#user'];
  $data['user'] = $user;
  $comm_status = 'all';
  $nid = $form_state['build_info']['args'][1];
  $page = (isset($form_state['build_info']['args'][3])) ? $form_state['build_info']['args'][3] : 0;
  $start = $page * $limit;
  if (isset($form_state['build_info']['args'][4])) {
    $comm_status = $form_state['build_info']['args'][4];
  }

  // Set the ranges of constituents to pull.
  // Attempt to use the cache to reduce size of the query.
  $con_start = 0;
  $anon_start = 0;
  $cache[$user->uid][$nid][$vid][$page]['con_disp_count'] = 0;
  $cache[$user->uid][$nid][$vid][$page]['anon_disp_count'] = 0;
  $query_limit = $limit;
  if (isset($cache[$user->uid][$nid][$vid]) & $page > 0) {
    for ($i = 1; $i <= $page; $i++) {
      $con_start += $cache[$user->uid][$nid][$vid][$i - 1]['con_disp_count'];
      $anon_start += $cache[$user->uid][$nid][$vid][$i - 1]['anon_disp_count'];
      $start = 0;
      if (!isset($cache[$user->uid][$nid][$vid][$i])) {
        $missing_pages = ($page - $i);
        $start = ($page - $missing_pages) * $limit;
        $query_limit = ($missing_pages + 1) * $limit;
        break;
      }
    }
  }
  elseif ($page > 0) {
    $query_limit = $limit * ($page + 1);
  }

  // Get the constituents of senator to filter user table.
  $data['district_tid'] = isset($data['district_tid']) ? $data['district_tid'] : user_get_district_tid($user);
  $data['cons'] = isset($data['constituent_list']) ? $data['constituent_list'] : get_constituents_by_district($data['district_tid']);

  // Get the list of users that have been messaged about the issue.
  switch ($comm_status) {
    case '1':
      $user_list_query[]
        = "
SELECT DISTINCT pmi.recipient as uid
  FROM {pm_index} pmi
  LEFT JOIN {pm_message} pm ON pm.mid = pmi.mid
  LEFT JOIN {field_data_field_petitions_questionnaires} fi ON fi.entity_id = pmi.mid
 WHERE pm.author = " . $user->uid . " AND pmi.deleted = 0 AND fi.field_petitions_questionnaires_target_id = " . $nid . " AND fi.bundle = 'privatemsg_message' AND pmi.recipient != " . $user->uid;
      break;

    case '0':
      $user_list_query[] = "SELECT uid FROM {flagging} WHERE fid = 6 AND entity_type = 'node' AND entity_id = " . $nid;
      $user_list_query[]
        = "
SELECT DISTINCT pmi.recipient as uid
  FROM {pm_index} pmi
  LEFT JOIN {pm_message} pm ON pm.mid = pmi.mid
  LEFT JOIN {field_data_field_petitions_questionnaires} fi ON fi.entity_id = pmi.mid
 WHERE pm.author = " . $user->uid . " AND pmi.deleted = 0 AND fi.field_petitions_questionnaires_target_id = " . $nid . " AND fi.bundle = 'privatemsg_message' AND pmi.recipient != " . $user->uid;
      break;

    default:
      $user_list_query[] = "SELECT uid FROM {flagging} WHERE fid = 6 AND entity_type = 'node' AND entity_id = " . $nid;
      break;
  }

  $uids = array();
  $uids1 = array();
  $uids2 = array();
  if (count($user_list_query) == 1) {
    $r = db_query($user_list_query[0])->fetchAll();
    foreach ($r as $index => $uid) {
      $uids[] = $uid->uid;
    }
  }
  else {
    $r1 = db_query($user_list_query[0])->fetchAll();
    foreach ($r1 as $index => $uid) {
      $uids1[] = $uid->uid;
    }

    $r2 = db_query($user_list_query[1])->fetchAll();
    foreach ($r2 as $index => $uid) {
      $uids2[] = $uid->uid;
    }
    if ($comm_status == 0) {
      $uids = array_diff($uids1, $uids2);
      if (empty($uids) && ($uids1 !== $uids2)) {
        $uids = $uids1;
      }
    }
  }

  // Show only senator's constituents in the user table.
  $uids = array_values(array_intersect($data['cons'], $uids));
  $uids = !empty($uids) ? $uids : 0;

  // Get the user details.
  $query
    = "
SELECT u.uid
     , u.name
     , fn.field_first_name_value AS first
     , ln.field_last_name_value AS last
     , l.city
     , l.postal_code
     , FLOOR((unix_timestamp() - dob.field_dateofbirth_value)/(86400*365)) AS age
     , fg.field_gender_user_value AS gender
     , m.timestamp AS last_message_time
  FROM {users} u
  JOIN {field_data_field_first_name} fn ON fn.entity_id = u.uid and fn.bundle = 'user'
  JOIN {field_data_field_last_name} ln ON ln.entity_id = u.uid and fn.bundle = 'user'
  LEFT JOIN {field_data_field_dateofbirth} dob ON dob.entity_id = u.uid and dob.bundle = 'user'
  LEFT JOIN {field_data_field_address} fa ON fa.entity_id = u.uid and fa.bundle = 'user'
  LEFT JOIN {field_data_field_gender_user} fg ON fg.entity_id = u.uid and fg.bundle = 'user'
  LEFT JOIN {location} l ON l.lid = fa.field_address_lid
  LEFT JOIN (
    SELECT pm.author
         , pm.timestamp
      FROM {pm_message} pm
      LEFT JOIN {pm_index} pmi ON pmi.mid = pm.mid AND pmi.recipient IN (:uids)
      LEFT JOIN {field_data_field_petitions_questionnaires} fi ON pmi.mid = fi.entity_id
     WHERE fi.field_petitions_questionnaires_target_id = :nid AND pm.author = :uid AND pmi.deleted = 0
    ) AS m ON u.uid = m.author
 WHERE u.uid IN (:uids)
 ";
  $query_args = array(
    ':nid' => $nid,
    ':uid' => $user->uid,
    ':uids' => $uids,
  );
  $query .= ' ORDER BY last, first';
  $result_count = db_query($query, $query_args)->rowCount();
  $result = db_query_range($query, $con_start, $query_limit, $query_args);

  // Get anonymous constituent petition data.
  $anon_result = array();
  $anon_result_count = 0;
  if ($comm_status != 1) {
    $anon_query = db_select('nys_petitions', 'p')
      ->condition('district_id', $data['district_tid'])
      ->condition('pid', $nid)
      ->fields('p')
      ->orderBy('last_name');
    $anon_result_count = $anon_query->countQuery()
      ->execute()
      ->fetchAssoc()['expression'];
    $anon_result = $anon_query->range($anon_start, $query_limit)
      ->execute()
      ->fetchAll();
  }

  // Build the table from the query data.
  $constituents = array();
  $i = 0;
  foreach ($result as $r) {
    $constituent = array();
    $constituent['last_message_time'] = !empty($r->last_message_time) ? 'YES<div class="date">' . date('m/d/Y', $r->last_message_time) . '</div>' : '';
    $constituent['uid'] = $r->uid;
    $constituent['name'] = theme('nys_dashboard_user_link', array('uid' => $r->uid));
    $constituent['city'] = !empty($r->city) ? $r->city : '';
    $constituent['zip_code'] = !empty($r->postal_code) ? $r->postal_code : '';
    $constituent['age_range'] = nys_dashboard_age_to_age_range($r->age);
    $constituent['gender'] = ($r->gender == 'male') ? 'M' : (($r->gender == 'female') ? 'F' : '');
    $constituents[$r->last . $r->first . $i] = $constituent;
    $i++;
  }
  foreach ($anon_result as $r) {
    $constituent = array();
    $constituent['last_message_time'] = '';
    $constituent['name'] = $r->first_name . ' ' . $r->last_name;
    $constituent['city'] = $r->addr_city;
    $constituent['zip_code'] = $r->addr_zip;
    $constituent['age_range'] = '';
    $constituent['gender'] = '';
    $constituents[$r->last_name . $r->first_name . $i] = $constituent;
    $i++;
  }
  array_multisort(array_keys($constituents), SORT_NATURAL, $constituents);
  $constituents = array_values($constituents);
  $rows = array();
  for ($i = 0; $i < min(count($constituents) - $start, $limit); $i++) {
    $rows[] = _nys_dashboard_build_constituent_table_row($constituents[$i + $start]);
    if (isset($constituents[$i + $start]['uid'])) {
      $cache[$user->uid][$nid][$vid][$page]['con_disp_count']++;
    }
    else {
      $cache[$user->uid][$nid][$vid][$page]['anon_disp_count']++;
    }
  }

  $header = array(
    "",
    array('data' => "NAME", 'class' => 'name'),
    "",
    array('data' => "City", 'class' => 'city'),
    array('data' => "Zip Code", 'class' => 'zip'),
    array('data' => "Age Range", 'class' => 'age'),
    array('data' => "Gender", 'class' => 'age'),
    array('data' => "Messaged", 'class' => 'last-messaged'),
  );
  $table = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('width' => '100%', 'class' => array('stat-data')),
   ));

  // Build the pager from query counts.
  $total_constituents_count = $result_count + $anon_result_count;
  if ($total_constituents_count < 1) {
    return '';
  }
  pager_default_initialize($total_constituents_count, $limit);
  // Max number of pages, plus one.
  $quantity = ($total_constituents_count / $limit) + 1;
  if ($quantity > 5) {
    $quantity = 5;
  }
  $pager = "";
  $quantity = round($quantity);
  if ($total_constituents_count > $limit) {
    $pager = theme('pager', array(
      'quantity' => $quantity,
      'tags' => array('<<', '<', '', '>', '>>'),
      'parameters' => array(
        'view' => 'senator_petitions',
        'vid' => $vid,
        'senator_id' => $user->uid,
        'nid' => $nid,
      ),
    ));
  }
  cache_set('nys_dashboard_petitions', $cache, 'cache');

  return '<div id="senator_constituents_table">' . $table . $pager . '</div>';
}
