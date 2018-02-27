<?php

function nys_dashboard_senator_bills_form($form, &$form_state) {
  $form = array();

  $getvars = array(
    'namesearch',
    'agesearch',
    'gender',
    'zipsearch',
    'fb'
  );

  foreach($getvars as $var) {
    if (isset($_GET[$var]) && empty($form_state['input'][$var])) {
      $form_state['input'][$var] = $_GET[$var];
    }
  }


  $title = 'MESSAGE CONSTITUENTS ABOUT BILL ACTIVITY';
  $form['#prefix'] = '<div id="nys_senators_constituents_bills" class="c-block c-container"><div class="c-active-list--header"><h2 class="c-container--title">' . $title .'</h2></div>';
  $form['#suffix'] = '<input type="hidden" id="loaded_user" value="'.arg(1).'" name="loaded_user"/></div>';

  $form['#attributes']['class'][] = 'issue-filters';

  $form['filters']['namesearch'] = array(
    '#type' => 'textfield',
    '#title' => t('Search Bills'),
    '#title_display' => 'invisible',
    '#default_value' => isset($form_state['input']['namesearch']) ? $form_state['input']['namesearch'] : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#attributes' => array('class' => array('c-site-search--box', 'icon_after__search', 'form-text', 'bill-name-search'), 'type' => 'search'),
    '#prefix' => '<div class="search-wrapper filter-wrapper">',
    '#suffix' => '</div>',
    '#post_render' => array('nys_dashboard_search_textfield_post_render_span'),
    '#autocomplete_path' => 'nys-dashboard/autocomplete/bills',
  );

  $form['filters']['comm_status'] = array(
    '#title' => t('Filter by Communication Status:'),
    '#type' => 'select',
     '#options' => array(
        'all' => t('All Types'),
        'no' => t('Not Messaged'),
        'yes' => t('Messaged'),
     ),
     '#default_value' => isset($form_state['input']['comm_status']) ? $form_state['input']['comm_status'] : 'all',
     '#attributes' => array('class' => array('filter comm_status'), 'id' => 'comm_status'),
     '#theme_wrappers' => array('nude_form_element'),
     '#prefix' => '<div class="filter-wrapper filter-wrapper--bill">',
     '#suffix' => '</div>',
  );

  $form['filters']['vote_type'] = array(
    '#type' => 'select',
    '#options' => array(
        'all' => t('All Votes'),
        'aye' => t('AYEs'),
        'nay' => t('NAYs'),
    ),
    '#default_value' => isset($form_state['input']['vote_type']) ? $form_state['input']['vote_type'] : 'all',
    '#attributes' => array('class' => array('filter vote_type'), 'id' => 'vote_type'),
    '#theme_wrappers' => array('nude_form_element'),
    '#title' => t('Filter by Vote Type:'),
    '#prefix' => '<div class="filter-wrapper filter-wrapper--bill">',
    '#suffix' => '</div>',
  );

  $form['inbox_action_links'] = array(
    '#prefix' => '<div class="inbox-action-links">',
    '#suffix' => '</div>',
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

  $form['messages_table'] = array('#markup' => nys_dashboard_senators_bills_table($form_state));


  return $form;
}


function nys_dashboard_senator_bills_form_submit($form, &$form_state) {

  $user = user_load(arg(1));
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'),1);

 if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Message') {

    $queryArgs = array();
    $page_context = 'senators_bills_tab';
    $combo = split_ids($form_state['input']['list']);
    $uids = $combo[0];
    $bill_ids = $combo[1];

    if ($form_state['input']['check_all'] == 1) {

      // to do: need to be able to message all constituents,
      // so a all_constituents filter needs to be added if no
      // queryArgs are present

      $queryArgs = nys_dashboard_senator_constituents_get_query_args($form_state['input']);
      if(empty($queryArgs)) { $queryArgs['all_constituents'] = true; }
      $queryArgs['uids'] = $uids;
      $queryArgs['context'] = $page_context;
      $queryArgs['bill_ids'] = $bill_ids;

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
      $queryArgs['bill_ids'] = $bill_ids;
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
    'fb'
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
    $dashboard_link . '/bills',
    array(
      'query' => $queryArgs,
    ),
  );


}


function nys_dashboard_senators_bills_table($form_state) {
  $messaged_bills_string = array();
  $vote_type = '';

  $queryArgs = array();
  $comm_status = 'all';
  if(isset($form_state['build_info']['args'][0])) $page = $form_state['build_info']['args'][0];
  if(isset($form_state['build_info']['args'][1])) $vote_type = $form_state['build_info']['args'][1];
  if(isset($form_state['build_info']['args'][2])) $comm_status = $form_state['build_info']['args'][2];
  if(isset($form_state['build_info']['args'][3])) $bill_name = $form_state['build_info']['args'][3];
  if(isset($form_state['build_info']['args'][4])) $userid = $form_state['build_info']['args'][4];

  $user = (isset($userid)) ? user_load($userid) : user_load(arg(1));

  $comm_status = ($comm_status === 'no') ? '0' : (($comm_status === 'yes') ? '1' : 'all');
  $vote_type = ($vote_type == 'nay') ? 0 : (($vote_type == 'aye') ? 1 : 'all');

  $limit = 10;
  $start = 0;
  if(isset($page)) $start = $limit * $page;

  /********** Get all bills followed by the senator constituents **********/

  /*Get all constituents of the senator*/
  $senator_nid = user_get_senator_nid($user);
  $senator_uid = user_get_senator_uid($user);
  $data = user_get_district_senator_data_array($user);
  $constituents = get_constituents_by_district($data['district_tid']);
  // $constituents = get_constituents($senator_nid);

  /*Get the list of users who have been messaged and bills which have been voted on*/
  $contacted_users = array();
  $messaged_bills = array();
  if($comm_status !== 'all') {
    $messaged_users = db_select('field_data_field_featured_bill', 'fi');
    $messaged_users->leftJoin('pm_index', 'pmi', 'fi.entity_id = pmi.mid');
    $messaged_users->leftJoin('pm_message', 'pm', 'pm.mid = pmi.mid');
    $messaged_users->fields('pmi', array('recipient'));
    $messaged_users->fields('fi', array('field_featured_bill_target_id'));
    // $messaged_users->distinct();
    $messaged_users->condition('pmi.recipient', $senator_uid, '!=');
    $messaged_users->condition('pm.timestamp', '', '!=');
    $messaged_users->condition('fi.field_featured_bill_target_id', '', '!=');
    $messaged_users->condition('pm.author', $senator_uid, '=');
    $messaged_users->condition('pmi.deleted', 0, '=');
    $messaged_users = $messaged_users->execute();
    $messaged_users = $messaged_users->fetchAll();

    /*Make three arrays for further filtering*/
    if(count($messaged_users) > 0) {
      foreach($messaged_users as $user) {
        $messaged_bills[] = $user->recipient;
        $messaged_bill_ids[] = $user->field_featured_bill_target_id;
        $messaged_bills_string[] = $user->recipient.$user->field_featured_bill_target_id;
      }
    }

    /*When filtering for messaged users, confine the user list to the messaged user ids*/
    if($comm_status == 1) $constituents = $messaged_bills;
    // if($comm_status == 0) $constituents = array_diff($constituents, $messaged_bills);
  }

  // Set the constituents array to a default value so that the query builder does not error out
  if(empty($constituents)) $constituents[] = $user->uid;

  // Get bills followed by these users
  $bills_query = db_select('flagging', 'f');
  $bills_query->leftJoin('node', 'n', 'f.entity_id = n.nid ');
  $bills_query->leftJoin('votingapi_vote', 'v', 'v.entity_id = f.entity_id AND v.uid = f.uid');
  $bills_query->leftJoin('users', 'u', 'u.uid = f.uid');
  $bills_query->leftJoin('field_data_field_first_name', 'fn', 'fn.entity_id = u.uid');
  $bills_query->leftJoin('field_data_field_last_name', 'ln', 'ln.entity_id = u.uid');
  $bills_query->leftJoin('fboauth_users', 'fb', 'fb.uid = u.uid');
  $bills_query->fields('f', array('entity_id', 'uid'));
  $bills_query->addField('v', 'timestamp', 'votedate');
  $bills_query->fields('v', array('value', 'timestamp'));
  $bills_query->fields('u', array('name'));
  $bills_query->addField('fb', 'fbid', 'facebook_verified');
  $bills_query->fields('n', array('title', 'nid'));
  $bills_query->addField('fn', 'field_first_name_value', 'first');
  $bills_query->addField('ln', 'field_last_name_value', 'last');
  $bills_query->condition('f.fid', 8, '=');
  $bills_query->condition('f.entity_type', 'node', '=');
  $bills_query->condition('fn.bundle', 'user', '=');
  $bills_query->condition('ln.bundle', 'user', '=');


  // Handle conditional filters based on the filter params from URL
  switch($comm_status) {
    case '0':
      /*When filtering for not messaged users, do not query the messaged userid and billid combination*/
      $not_messaged_bills_query = db_select('flagging', 'f');
      $not_messaged_bills_query->fields('f', array('entity_id', 'uid'));
      $not_messaged_bills_query->condition('f.fid', 8, '=');
      $not_messaged_bills_query->condition('f.uid', $constituents, 'IN');
      $not_messaged_bills = $not_messaged_bills_query->execute();
      $not_messaged_bills = $not_messaged_bills->fetchAll();

      foreach($not_messaged_bills as $not_messaged_bill) {
        $not_messaged_bill_string[] = $not_messaged_bill->uid.$not_messaged_bill->entity_id;
      }
      $not_messaged_bill_string = array_diff($not_messaged_bill_string, $messaged_bills_string);

      $or = db_or();
      foreach($not_messaged_bill_string as $index=>$not_messaged_bill) {
        $or->condition(db_and()->condition('n.nid', $not_messaged_bills[$index]->entity_id, '=')->condition('f.uid', $not_messaged_bills[$index]->uid, '='));
      }
      $bills_query->condition($or);

    break;

    case '1':
      $or = db_or();
      foreach($constituents as $index=>$constituent) {
        $or->condition(db_and()->condition('n.nid', $messaged_bill_ids[$index], '=')->condition('f.uid', $constituent, '='));
      }
      $bills_query->condition($or);
    break;

    default:
      $bills_query->condition('f.uid', $constituents, 'IN');
  }

  if(isset($vote_type) && $vote_type !== 'all') $bills_query->condition('v.value', $vote_type, '=');
  if(isset($bill_name) && $bill_name != '') $bills_query->condition('n.title', '%'.$bill_name.'%', 'LIKE');

  $bills_query->orderBy('f.timestamp', 'DESC');
  $bills_query->range($start, $limit);

  $result = $bills_query->execute();


  $rows = array();
  while($records = $result->fetchAll()) {
    foreach($records as $r) {

      // Query to get the last messaged time
      $last_message_time = '';
      $last_message_result = db_select('pm_message', 'pm');
      $last_message_result->fields('pm', array('timestamp'));
      $last_message_result->leftJoin('pm_index', 'pmi', 'pmi.mid = pm.mid');
      $last_message_result->leftJoin('field_data_field_featured_bill', 'fi', 'pmi.mid = fi.entity_id');
      $last_message_result->condition('fi.field_featured_bill_target_id', $r->entity_id, '=');
      $last_message_result->condition('pm.author', $senator_uid, '=');
      $last_message_result->condition('pmi.deleted', 0, '=');
      $last_message_result->condition('pmi.recipient', $r->uid, '=');
      $ls_result = $last_message_result->execute();
      $last_message_time = $ls_result->fetchField();

      $last_message_time = (!empty($last_message_time)) ? 'YES<div class="date">'.date('m/d/Y', $last_message_time).'</div>' : 'NO';

      $output = "";

      $name = theme('nys_dashboard_user_link', array('uid' => $r->uid));

      $facebook_verified = !empty($r->facebook_verified) ? '<a href="#" class="poll-facebook-share icon-after__facebook"></a>' : '';
      $bill_name = $r->title;
      $bill_vote_time = ($r->votedate != NULL) ? date('m/d/Y', $r->votedate) : '';
      $bill_vote = ($r->value == NULL) ? '' : (($r->value == 0) ? 'NAY' : 'AYE');
      $bill_vote = $bill_vote.'<div class="date">'.$bill_vote_time.'</div>';

      $columns = array(
         array('data' => '<input class="row-checkbox" type="checkbox" name="list[' . $r->uid . '-'. $r->entity_id . ']" value="' . $r->uid . '-'. $r->entity_id . '">', 'class' => 'form-type-checkbox'),
         array('data' => $name, 'class' =>'name'),
         array('data' => $facebook_verified, 'class' =>'verified'),
         array('data' => $bill_name, 'class' =>'bill_name'),
         array('data' => $bill_vote, 'class' =>'vote'),
         array('data' => $last_message_time, 'class' =>'last-messaged'),
      );

      $rows[] = $columns;
    }
  }
  // print_r($rows);
  // die();

  $header = array("",
    array('data' => "NAME", 'class' =>'name'),
    array('data' => "Verified", 'class' =>'verified'),
    array('data' => "Bill Name", 'class' =>'bill_name'),
    array('data' => "Vote", 'class' =>'vote'),
    array('data' => "Messaged", 'class' =>'last-messaged'));

  $table = theme('table', array(
   'header' => $header,
   'rows' => $rows,
   'attributes' => array('width' => '100%', 'class' => array('stat-data'))
  ));

  $bills_query->range();
  $total_bills_count = $bills_query->execute();
  $total_bills_count = count($total_bills_count->fetchAll());
  if($total_bills_count < 1) return '';

  pager_default_initialize($total_bills_count, $limit);

  $quantity = floor($total_bills_count / $limit) + 1; // max number of pages, plus one

  if ($quantity > 5) {
    $quantity = 5;
  }

  $pager = "";
  $quantity = round($quantity);
  if ($total_bills_count > $limit) {
    $pager = theme('pager', array('quantity' => $quantity, 'tags' => array('<<', '<', '', '>', '>>'), 'parameters' => array('view' => 'senator_bills')));
  }

  return '<div id="senator_constituents_table">' . $table . $pager . '</div>';
}

/**
 * given an eage, return a textual output of the age range, in groups of five years
 */
function nys_dashboard_age_to_age_range($age = 0) {

  if(empty($age)) {
    return '';
  }

  $modulo = $age % 5;

  $age_range_start = ($age - $modulo);
  $age_range_end = $age_range_start + 5;

  return "$age_range_start-$age_range_end";
}

function nys_dashboard_gender_render($int) {
  if(!isset($int)) {
    return '';
  }

  if($int == 0) {
    return 'Female';
  } elseif($int == 1) {
    return 'Male';
  }
}

function split_ids($input) {
  foreach($input as $index=>$value) {
    $values = explode('-', $value);
    $users[] = $values[0];
    $bills[] = $values[1];
  }
  $combo = array($users, $bills);

  return $combo;
}

function nys_dashboard_senator_constituents_get_query_args($input) {
  $getvars = array(
    'namesearch',
    'agesearch',
    'gender',
    'fb'
  );

  $queryArgs = array();



  foreach($getvars as $var) {
    if ($input[$var] != "" && $input[$var] != 'all') {
      $queryArgs[$var] = $input[$var];
    }
  }

 if (!empty($input['zipsearch']) && $input['zipsearch'] != "Zip Code" && is_numeric($input['zipsearch'])) {
   $queryArgs['zipsearch'] = $input['zipsearch'];
 }
 return $queryArgs;
}
