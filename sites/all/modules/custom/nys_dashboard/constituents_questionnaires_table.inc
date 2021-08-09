<?php

function nys_senator_constituents_questionnaires_form($form, &$form_state, $argument, $account) {
  $form = array();

  $getvars = array(
    'namesearch',
    'agesearch',
    'gender',
    'zipsearch',
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

  /**
   * Removed per Ryan 2019-05-10.  non-functional
   */
  /*
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
  */

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

  $form['petition_id'] = array(
    '#type' => 'hidden',
    '#value' => $form_state['build_info']['args'][0],
  );

  $form['messages_table'] = array('#markup' => nys_dashboard_senators_questionnaires_table($form_state));


  return $form;
}


function nys_senator_constituents_questionnaires_form_submit($form, &$form_state) {
  $user = user_load(arg(1));
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'),1);


 if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Message') {

    $queryArgs = array();
    $page_context = 'senators_questionnaires_tab';
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
    'gender',
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


function nys_dashboard_senators_questionnaires_table($form_state) {

  $user = user_load(arg(1));

  // echo '<pre>';
  // print_r($form_state);
  $comm_status = 'all';
  $nid = $form_state['build_info']['args'][0];
  if(!$nid) $nid = 0;
  if(isset($form_state['build_info']['args'][1])) $page = $form_state['build_info']['args'][1];
  if(isset($form_state['build_info']['args'][2])) $comm_status = $form_state['build_info']['args'][2];

  // Get the constituents of senator to filter user table
  $cons = array();
  $tid = user_get_district_tid($user);
  $cons = get_constituents_by_district($tid);

  $limit = 10;

  $start = 0;
  if(isset($page)) $start = $limit * $page;

  // Get the list of users that have been messaged about the issue
  switch($comm_status) {
    case '1':
      $user_list_query[] = "SELECT DISTINCT pmi.recipient as uid
                            FROM pm_index pmi
                            LEFT JOIN pm_message pm ON pm.mid = pmi.mid
                            LEFT JOIN field_data_field_petitions_questionnaires fi ON fi.entity_id = pmi.mid
                            WHERE pm.author = ".$user->uid." AND pmi.deleted = 0 AND fi.field_petitions_questionnaires_target_id = ".$nid." AND fi.bundle = 'privatemsg_message' AND pmi.recipient != ".$user->uid;
      break;
    case '0':
      $user_list_query[] = "SELECT uid FROM webform_submissions WHERE is_draft = 0 AND nid = ".$nid;
      $user_list_query[] = "SELECT DISTINCT pmi.recipient as uid
                            FROM pm_index pmi
                            LEFT JOIN pm_message pm ON pm.mid = pmi.mid
                            LEFT JOIN field_data_field_petitions_questionnaires fi ON fi.entity_id = pmi.mid
                            WHERE pm.author = ".$user->uid." AND pmi.deleted = 0 AND fi.field_petitions_questionnaires_target_id = ".$nid." AND fi.bundle = 'privatemsg_message' AND pmi.recipient != ".$user->uid;
      break;
    default:
      $user_list_query[] = "SELECT uid FROM webform_submissions WHERE is_draft = 0 AND nid = ".$nid;
      break;
  }

  if(count($user_list_query) == 1) {
    $r = db_query($user_list_query[0])->fetchAll();
    foreach($r as $index=>$uid) {
      $uids[] = $uid->uid;
    }
  }
  else {
    $r1 = db_query($user_list_query[0])->fetchAll();
    foreach($r1 as $index=>$uid) {
      $uids1[] = $uid->uid;
    }

    $r2 = db_query($user_list_query[1])->fetchAll();
    foreach($r2 as $index=>$uid) {
      $uids2[] = $uid->uid;
    }
    // print_r($uids1);
    // print_r($uids2);
    if($comm_status == 0) {
      $uids = array_diff($uids1, $uids2);
      if(empty($uids) && ($uids1 !== $uids2)) $uids = $uids1;
    }
  }

  // Show only senator's constituents in the user table
  $uids = array_intersect($cons, $uids);

  $user_ids_list = (count($uids) > 0) ? (string)implode(',', $uids) : '0';
  // print_r($user_ids_list);
  // Get the user details
  $query = "SELECT u.uid, u.name,
    fn.field_first_name_value AS first, ln.field_last_name_value AS last,
    l.city, l.postal_code,
    FLOOR((unix_timestamp() - dob.field_dateofbirth_value)/(86400*365)) AS age,
    fg.field_gender_user_value AS gender,
    FROM users u
    JOIN field_data_field_first_name fn ON fn.entity_id = u.uid and fn.bundle = 'user'
    JOIN field_data_field_last_name ln ON ln.entity_id = u.uid and fn.bundle = 'user'
    LEFT JOIN field_data_field_dateofbirth dob ON dob.entity_id = u.uid and dob.bundle = 'user'
    LEFT JOIN field_data_field_address fa ON fa.entity_id = u.uid and fa.bundle = 'user'
    LEFT JOIN field_data_field_gender_user fg ON fg.entity_id = u.uid and fg.bundle = 'user'
    LEFT JOIN location l ON l.lid = fa.field_address_lid
    WHERE u.uid IN (".$user_ids_list.") ";

    $queryArgs = array(
     ':nid' => $nid,
   );

   $query .= ' ORDER BY last, first';

   $result = db_query_range($query, $start, $limit, $queryArgs);

   $rows = array();
   foreach($result as $r) {

    $last_message_query = "SELECT pm.timestamp from pm_message pm
      LEFT JOIN pm_index pmi ON pmi.mid = pm.mid AND pmi.recipient = :rid
      LEFT JOIN field_data_field_petitions_questionnaires fi ON pmi.mid = fi.entity_id
      WHERE fi.field_petitions_questionnaires_target_id = :nid AND pm.author = :uid AND pmi.deleted = 0;";
    $last_message_args = array(':rid' => $r->uid, ':uid' => $user->uid, ':nid' => $nid);
    $last_message_time = db_query($last_message_query, $last_message_args)->fetchField();
    if(!empty($last_message_time))
      $last_message_time = 'YES<div class="date">'.date('m/d/Y', $last_message_time).'</div>';

     $output = "";


     if(!empty($r->first) && !empty($r->last)) {
       $name = $r->first . ' ' . $r->last;
     } else {
       $name = $r->name;
     }
     $name = theme('nys_dashboard_user_link', array('uid' => $r->uid));
     $city = !empty($r->city) ? $r->city : '';
     $zip_code = !empty($r->postal_code) ? $r->postal_code : '';
     $age_range = nys_dashboard_age_to_age_range($r->age);
     $gender =  ($r->gender == 'male') ? 'M' : (($r->gender == 'female') ? 'F' : '');
     $columns = array(
       '<input class="row-checkbox" type="checkbox" name="list[' . $r->uid . ']" value="' . $r->uid . '">',
       array('data' => $name, 'class' =>'name'),
       array('data' => $city, 'class' =>'city'),
       array('data' => $zip_code, 'class' =>'zip'),
       array('data' => $age_range, 'class' =>'age'),
       array('data' => $gender, 'class' =>'gender'),
       array('data' => $last_message_time, 'class' =>'last-messaged'),
     );

     $rows[] = $columns;
   }

   $header = array("",
		array('data' => "NAME", 'class' =>'name'),
		array('data' => "City", 'class' =>'city'),
		array('data' => "Zip Code", 'class' =>'zip'),
		array('data' => "Age Range", 'class' =>'age'),
		array('data' => "Gender", 'class' =>'age'),
    array('data' => "Messaged", 'class' =>'last-messaged'));

   $table = theme('table', array(
     'header' => $header,
     'rows' => $rows,
     'attributes' => array('width' => '100%', 'class' => array('stat-data'))
   ));

  $total_constituents_count = db_query($query, $queryArgs)->rowCount();
  if($total_constituents_count < 1) return '';

  pager_default_initialize($total_constituents_count, $limit);

  $quantity = ($total_constituents_count / $limit) + 1; // max number of pages, plus one

  if ($quantity > 5) {
    $quantity = 5;
  }

  $pager = "";
  $quantity = round($quantity);
  if ($total_constituents_count > $limit) {
    $pager = theme('pager',array('quantity'=> $quantity ,'tags' => array('<<','<','','>','>>'), 'parameters' => array('view' => 'senator_questionnaires', 'nid' => $nid)));
  }

  return '<div id="senator_constituents_table">' . $table . $pager . '</div>';
}
