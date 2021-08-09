<?php

function nys_senator_constituents_issues_form($form, &$form_state, $argument, $account) {
  $form = [];

  $getvars = [
    'namesearch',
    'agesearch',
    'gender',
    'zipsearch',
  ];

  foreach ($getvars as $var) {
    if (isset($_GET[$var]) && empty($form_state['input'][$var])) {
      $form_state['input'][$var] = $_GET[$var];
    }
  }


  $title = '';
  // $form['#prefix'] = '<div id="nys_senators_constituents" class="c-block c-container c-container--senator-constituents"><h2 class="c-container--title">' . $title .'</h2>';
  // $form['#suffix'] = '</div>';

  $form['#prefix'] = '';
  $form['#suffix'] = '';
  $form['#attributes']['class'][] = 'issue-filters';

  $form['filters']['label'] = [
    '#markup' => '<label>Filter by Communication Status</label>',
  ];

  $form['filters']['comm_status'] = [
    '#type' => 'select',
    '#options' => [
      'all' => t('All Types'),
      0 => t('Not Messaged'),
      1 => t('Messaged'),
    ],
    '#default_value' => isset($form_state['input']['comm_status']) ? $form_state['input']['comm_status'] : 'all',
    '#attributes' => ['class' => ['filter'], 'id' => 'comm_status'],
    '#theme_wrappers' => ['nude_form_element'],
    '#prefix' => '<div class="filter-wrapper filter-wrapper--msg">',
    '#suffix' => '</div>',
  ];

  $form['inbox_action_links'] = [
    '#prefix' => '<div class="inbox-action-links">',
    '#suffix' => '</div>',
  ];

  $form['inbox_action_links']['check_all'] = [
    '#type' => 'checkbox',
    '#title' => t('Check All'),
    '#prefix' => '<div class="select-all-messages">',
    '#suffix' => '</div>',
    '#attributes' => ['id' => 'checkall'],
  ];

  $form['inbox_action_links']['actions'] = [
    '#type' => 'actions',
    '#prefix' => '<div class="action-button-wrapper">',
    '#suffix' => '</div>',
  ];

  $form['inbox_action_links']['actions']['message'] = [
    '#type' => 'submit',
    '#value' => t('Message'),
    '#attributes' => ['class' => ['icon-before__contact']],
  ];

  $form['issue_id'] = [
    '#type' => 'hidden',
    '#value' => $form_state['build_info']['args'][0],
  ];

  $form_table = nys_dashboard_senators_constituents_table($form_state);
  $form['#prefix'] = '<div class="issue-follower-header icon-after__see-more pager-load-more"><span class="field-content">See ' . $form_table[1] . ' Constituents</span></div>';
  $form['messages_table'] = ['#markup' => $form_table[0]];


  return $form;
}


function nys_senator_constituents_issues_form_submit($form, &$form_state) {

  $user = user_load(arg(1));

  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'), 1);


  if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Message') {

    $queryArgs = [];
    $page_context = 'senators_issues_tab';
    $uids = array_values($form_state['input']['list']);

    if ($form_state['input']['check_all'] == 1) {

      // to do: need to be able to message all constituents,
      // so a all_constituents filter needs to be added if no
      // queryArgs are present

      $queryArgs = nys_dashboard_senator_constituents_get_query_args($form_state['input']);
      if (empty($queryArgs)) {
        $queryArgs['all_constituents'] = TRUE;
      }
      //$queryArgs['uids'] = $uids;
      $queryArgs['context'] = $page_context;
      $queryArgs['issue_id'] = $form_state['input']['issue_id'];


      $form_state['redirect'] = [
        $dashboard_link . '/inbox/new',
        [
          'query' => $queryArgs,
        ],
      ];
      return;
    }

    else {
      if (!empty($form_state['input']['list'])) {
        $queryArgs['uids'] = $uids;
        $queryArgs['context'] = $page_context;
        $queryArgs['issue_id'] = $form_state['input']['issue_id'];
        // message the list
        $form_state['redirect'] = [
          $dashboard_link . '/inbox/new',
          [
            'query' => $queryArgs,
          ],
        ];
        return;
      }
    }
  }

  $getvars = [
    'namesearch',
    'agesearch',
    'gender',
  ];

  $queryArgs = [];

  foreach ($getvars as $var) {
    if ($form_state['input'][$var] != "" && $form_state['input'][$var] != 'all') {
      $queryArgs[$var] = $form_state['input'][$var];
    }
  }

  if (!empty($form_state['input']['zipsearch']) && $form_state['input']['zipsearch'] != "Zip Code" && is_numeric($form_state['input']['zipsearch'])) {
    $queryArgs['zipsearch'] = $form_state['input']['zipsearch'];
  }

  $form_state['redirect'] = [
    $dashboard_link . '/issues',
    [
      'query' => $queryArgs,
    ],
  ];


}


function nys_dashboard_senators_constituents_table($form_state) {

  if (isset($form_state['build_info']['args'][3])) {
    $user = user_load($form_state['build_info']['args'][3]);
  }
  else {
    global $user;
  }

  $data = user_get_district_senator_data_array($user);

  $senator_constituents = get_constituents_by_district($data['district_tid']);

  $comm_status = 'all';
  $tid = $form_state['build_info']['args'][0];
  if (isset($form_state['build_info']['args'][1])) {
    $page = $form_state['build_info']['args'][1];
  }
  if (isset($form_state['build_info']['args'][2])) {
    $comm_status = $form_state['build_info']['args'][2];
  }

  $limit = 10;

  $start = 0;
  if (isset($page)) {
    $start = $limit * $page;
  }

  // Get the list of users that have been messaged about the issue
  switch ($comm_status) {
    case '1':
      $user_list_query[] = "SELECT DISTINCT pmi.recipient as uid
                            FROM pm_index pmi
                            LEFT JOIN pm_message pm ON pm.mid = pmi.mid
                            LEFT JOIN field_data_field_issues fi ON fi.entity_id = pmi.mid
                            WHERE pm.author = " . $user->uid . " AND pmi.deleted = 0 AND fi.field_issues_tid = " . $tid . " AND fi.bundle = 'privatemsg_message' AND pmi.recipient != " . $user->uid;
      break;
    case '0':
      $user_list_query[] = "SELECT uid FROM flagging WHERE fid=4 AND entity_type = 'taxonomy_term' AND entity_id = " . $tid;
      $user_list_query[] = "SELECT DISTINCT pmi.recipient as uid
                            FROM pm_index pmi
                            LEFT JOIN pm_message pm ON pm.mid = pmi.mid
                            LEFT JOIN field_data_field_issues fi ON fi.entity_id = pmi.mid
                            WHERE pm.author = " . $user->uid . " AND pmi.deleted = 0 AND fi.field_issues_tid = " . $tid . " AND fi.bundle = 'privatemsg_message' AND pmi.recipient != " . $user->uid;
      break;
    default:
      $user_list_query[] = "SELECT uid FROM flagging WHERE fid=4 AND entity_type = 'taxonomy_term' AND entity_id = " . $tid;
      break;
  }

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
    // print_r($uids1);
    // print_r($uids2);
    if ($comm_status == 0) {
      $uids = array_diff($uids1, $uids2);
      if (empty($uids) && ($uids1 !== $uids2)) {
        $uids = $uids1;
      }
    }
  }

  $uids = array_intersect($uids, $senator_constituents);
  $user_ids_list = (count($uids) > 0) ? (string) implode(',', $uids) : '0';

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
    WHERE u.uid IN (" . $user_ids_list . ")
    ";

  $queryArgs = [
    ':tid' => $tid,
  ];

  $query .= ' ORDER BY last, first';

  $result = db_query_range($query, $start, $limit, $queryArgs);

  $rows = [];
  foreach ($result as $r) {

    $last_message_query = "SELECT pm.timestamp from pm_message pm
      LEFT JOIN pm_index pmi ON pmi.mid = pm.mid AND pmi.recipient = :rid
      LEFT JOIN field_data_field_issues fi ON pmi.mid = fi.entity_id
      WHERE fi.field_issues_tid = :tid AND pm.author = :uid AND pmi.deleted = 0;";
    $last_message_args = [
      ':rid' => $r->uid,
      ':uid' => $user->uid,
      ':tid' => $tid,
    ];
    $last_message_time = db_query($last_message_query, $last_message_args)->fetchField();
    if (!empty($last_message_time)) {
      $last_message_time = 'YES<div class="date">' . date('m/d/Y', $last_message_time) . '</div>';
    }

    if (!empty($r->first) && !empty($r->last)) {
      $name = $r->first . ' ' . $r->last;
    } else {
      $name = $r->name;
    }
    $name = theme('nys_dashboard_user_link', array('uid' => $r->uid));
    $city = !empty($r->city) ? $r->city : '';
    $zip_code = !empty($r->postal_code) ? $r->postal_code : '';
    $age_range = nys_dashboard_age_to_age_range($r->age);
    $gender = ($r->gender == 'male') ? 'M' : (($r->gender == 'female') ? 'F' : '');

    $columns = [
      '<input class="row-checkbox" type="checkbox" name="list[' . $r->uid . ']" value="' . $r->uid . '">',
      ['data' => $name, 'class' => 'name'],
      ['data' => $city, 'class' => 'city'],
      ['data' => $zip_code, 'class' => 'zip'],
      ['data' => $age_range, 'class' => 'age'],
      ['data' => $gender, 'class' => 'gender'],
      ['data' => $last_message_time, 'class' => 'last-messaged'],
    ];

    $rows[] = $columns;
  }

  $header = [
    "",
    ['data' => "NAME", 'class' => 'name'],
    ['data' => "City", 'class' => 'city'],
    ['data' => "Zip Code", 'class' => 'zip'],
    ['data' => "Age Range", 'class' => 'age'],
    ['data' => "Gender", 'class' => 'age'],
    ['data' => "Messaged", 'class' => 'last-messaged'],
  ];

  $table = theme('table', [
    'header' => $header,
    'rows' => $rows,
    'attributes' => ['width' => '100%', 'class' => ['stat-data']],
  ]);

  $total_constituents_count = db_query($query, $queryArgs)->rowCount();

  pager_default_initialize($total_constituents_count, $limit);

  $quantity = ($total_constituents_count / $limit) + 1; // max number of pages, plus one

  if ($quantity > 5) {
    $quantity = 5;
  }

  $pager = "";
  $quantity = round($quantity);
  if ($total_constituents_count > $limit) {
    $pager = theme('pager', [
      'quantity' => $quantity,
      'tags' => ['<<', '<', '', '>', '>>'],
      'parameters' => ['view' => 'senator_issues', 'tid' => $tid],
    ]);
  }

  return [
    '<div id="senator_constituents_table">' . $table . $pager . '</div>',
    $total_constituents_count,
  ];
}

function nys_dashboard_senator_issues_form($form, &$form_state) {
  $uid = (int) ($form_state['values']['senator_uid'] ?? 0);
  if (!$uid ?? NULL) {
    $uid = (int) arg(1);
  }
  if (!$uid) {
    return [
      'issues_view' => [
        '#markup' => 'Could not find a senator for this view',
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      ],
    ];
  }

  $selected = $form_state['values']['issues_list'] ?? FALSE;

  $form = [
    'senator_uid' => [
      '#type' => 'value',
      '#value' => $uid,
    ],
    'issues_list_container' => [
      '#type' => 'container',
      '#attributes' => ['id' => 'dashboard-senator-issue-list'],
      'issues_list' => nys_dashboard_create_issues_select($uid),
    ],
    'issues_detail_container' => [
      '#type' => 'container',
      '#attributes' => ['id' => 'dashboard-senator-issue-detail'],
      'issues_detail' => nys_dashboard_get_issue_detail($uid, $selected),
    ],
  ];

  $form['issues_list_container']['issues_count'] = [
    '#markup' => '<div class="dashboard-senator-issue-list-count">' .
      count($form['issues_list_container']['issues_list']['#options']) .
      ' Issues found</div>',
  ];

  return $form;
}

function nys_dashboard_senator_issues_form_submit($form, &$form_state) {
  $issue_id = $form_state['values']['issues_list'] ?? 0;
  if ($issue_id) {
    $dashboard = url('user/' . arg(1) . '/dashboard') . '/inbox/new';
    $form_state['redirect'] = [
      $dashboard,
      [
        'query' => [
          'context' => 'senators_issues_tab',
          'issue_id' => $issue_id,
        ],
      ],
    ];
  }
}

function nys_dashboard_create_issues_detail_ajax($form, $form_state) {
  return $form['issues_detail_container'] ?? NULL;
}

function nys_dashboard_create_issues_select($uid, $show_all = FALSE) {
  if (!((int) $uid)) {
    $uid = (int) $GLOBALS['user']->uid;
  }

  $issues = _nys_dashboard_query_flag_counts('follow_issue', $uid, $show_all);

  $list_options = [];
  foreach ($issues as $key => $val) {
    $list_options[$key] = $val->name . ' (' . (string) ($val->user_count ?? 0) . ')';
  }

  return [
    '#type' => 'select',
    '#options' => $list_options,
    '#size' => 12,
    '#weight' => 10,
    '#ajax' => [
      'callback' => 'nys_dashboard_create_issues_detail_ajax',
      'wrapper' => 'dashboard-senator-issue-detail',
      'keypress' => TRUE,
    ],
  ];
}

function nys_dashboard_get_issue_detail($uid, $selected) {
  if ($uid && $selected) {
    $ret = [
      'send' => [
        '#type' => 'submit',
        '#value' => 'Send Message',
      ],
      'detail' => [
        '#markup' => views_embed_view('issues_followed', 'senator_constituents', $uid, $selected),
      ],
    ];
  }
  else {
    $ret = [];
  }
  return $ret;
}
