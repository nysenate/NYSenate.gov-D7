<?php

/**
 * Form-builder for the [Bills|Constituent Messages] tab on user dashboard.
 * The actual form consists of AJAX-enabled filters for the data table.
 *
 * @param $form
 * @param $form_state
 *
 * @return array Drupal Forms API array
 */
function nys_dashboard_senator_bills_form($form, &$form_state) {

  // Forms requires a rebuild under normal AJAX conditions.  Since this
  // has a heavy cost, we can just assume the old form.
  if (($form_state['input']['_triggering_element_name'] ?? '')
    && (is_array($form_state['input']['ajax_page_state'] ?? FALSE))
    && ($form_state['complete form'] ?? FALSE)
  ) {
    return $form_state['complete form'];
  }

  // For convenience.
  $values = &$form_state['input'];

  // Allow the page selector to report via form input or query parameter.
  // Query parameter takes precedence.  Mostly because the default pager
  // behavior demands GET parameters.
  $params = drupal_get_query_parameters();
  $new_page = $params['page'] ?? ($values['page'] ?? 0);
  if ($new_page === 'last') {
    $values['page'] = PHP_INT_MAX;
  }
  elseif ($new_page === 'first') {
    $values['page'] = 0;
  }
  else {
    $values['page'] = ((int) $new_page) - 1;
  }

  // This is to support legacy GET parameters.  Pretty sure
  // this is obsolete now.
  foreach (['namesearch', 'comm_status', 'vote_type'] as $var) {
    if ($params[$var] ?? FALSE) {
      $values[$var] = $params[$var];
    }
  }

  // Form element wrapper
  $title = 'MESSAGE CONSTITUENTS ABOUT BILL ACTIVITY';
  $form['#prefix'] = '<div id="nys_senators_constituents_bills" ' .
    'class="c-block c-container"><div class="c-active-list--header">' .
    '<h2 class="c-container--title">' . $title . '</h2></div>';
  $form['#suffix'] = '</div>';

  // Set up the filter inputs
  $form['filters'] = [
    'page' => [
      '#type' => 'hidden',
      '#default_value' => $values['page'] ?? 0,
      '#attributes' => ['class' => ['filter filter-page']],
    ],
    'namesearch' => [
      '#type' => 'textfield',
      '#prefix' => '<div class="search-wrapper filter-wrapper">',
      '#suffix' => '</div>',
      '#title' => t('Search Bills'),
      '#title_display' => 'invisible',
      '#default_value' => $values['namesearch'] ?? '',
      '#size' => 60,
      '#maxlength' => 128,
      '#attributes' => [
        'class' => [
          'c-site-search--box',
          'icon_after__search',
          'form-text',
          'bill-name-search',
        ],
        'type' => 'search',
      ],
      '#post_render' => ['nys_dashboard_search_textfield_post_render_span'],
      '#autocomplete_path' => 'nys-dashboard/autocomplete/bills',
      '#ajax' => [
        'callback' => 'nys_dashboard_senators_bills_table',
        'wrapper' => 'senator_constituents_table',
        'keypress' => TRUE,
      ],
    ],
    'comm_status' => [
      '#title' => t('Filter by Communication Status:'),
      '#prefix' => '<div class="filter-wrapper filter-wrapper--bill">',
      '#suffix' => '</div>',
      '#type' => 'select',
      '#options' => [
        'all' => t('All Types'),
        'no' => t('Not Messaged'),
        'yes' => t('Messaged'),
      ],
      '#default_value' => $values['comm_status'] ?? 'all',
      '#attributes' => ['class' => ['filter comm_status']],
      '#id' => 'comm_status',
      '#theme_wrappers' => ['nude_form_element'],
      '#ajax' => [
        'callback' => 'nys_dashboard_senators_bills_table',
        'wrapper' => 'senator_constituents_table',
      ],
    ],
    'vote_type' => [
      '#title' => t('Filter by Vote Type:'),
      '#prefix' => '<div class="filter-wrapper filter-wrapper--bill">',
      '#suffix' => '</div>',
      '#type' => 'select',
      '#options' => [
        'all' => t('All Votes'),
        'aye' => t('AYEs'),
        'nay' => t('NAYs'),
      ],
      '#default_value' => $values['vote_type'] ?? 'all',
      '#attributes' => ['class' => ['filter vote_type']],
      '#id' => 'vote_type',
      '#theme_wrappers' => ['nude_form_element'],
      '#ajax' => [
        'callback' => 'nys_dashboard_senators_bills_table',
        'wrapper' => 'senator_constituents_table',
      ],
    ],
  ];

  // The "Message" button
  $form['inbox_action_links'] = [
    '#prefix' => '<div class="inbox-action-links">',
    '#suffix' => '</div>',
    'actions' => [
      '#type' => 'actions',
      '#prefix' => '<div class="action-button-wrapper">',
      '#suffix' => '</div>',
      'message' => [
        '#type' => 'submit',
        '#value' => t('Message'),
        '#attributes' => ['class' => ['icon-before__contact']],
      ],
    ],
  ];

  // The actual data table
  $form['messages_table'] = ['#markup' => nys_dashboard_senators_bills_table($form, $form_state)];

  return $form;
}


/**
 * Implements hook_form_submit.
 *
 * 2020-10-16 Not sure why this is necessary now.  The form filters are
 * all 100% AJAX, so this should only handle redirecting to messaging if
 * the "Message" button was clicked.  Leaving in place until we can
 * determine was is actually necessary here.
 *
 * @param $form
 * @param $form_state
 */
function nys_dashboard_senator_bills_form_submit($form, &$form_state) {

  $user = user_load(arg(1));
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'), 1);

  if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Message') {

    $queryArgs = [];
    $page_context = 'senators_bills_tab';
    $combo = split_ids($form_state['input']['list']);
    $uids = $combo[0];
    $bill_ids = $combo[1];

    if ($form_state['input']['check_all'] == 1) {

      // to do: need to be able to message all constituents,
      // so a all_constituents filter needs to be added if no
      // queryArgs are present

      $queryArgs = nys_dashboard_senator_constituents_get_query_args($form_state['input']);
      if (empty($queryArgs)) {
        $queryArgs['all_constituents'] = TRUE;
      }
      $queryArgs['uids'] = $uids;
      $queryArgs['context'] = $page_context;
      $queryArgs['bill_ids'] = $bill_ids;

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
        $queryArgs['bill_ids'] = $bill_ids;
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
    'fb',
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
    $dashboard_link . '/bills',
    [
      'query' => $queryArgs,
    ],
  ];


}

/**
 * @param $form
 * @param $form_state
 *
 * @return string
 */
function nys_dashboard_senators_bills_table($form, $form_state) {

  // For easy reference.
  $values = &$form_state['input'];
  $args = [
    'page' => $values['page'] ?? 0,
    'vote_type' => $values['vote_type'] ?? 'all',
    'comm_status' => $values['comm_status'] ?? 'all',
    'bill_name' => $values['namesearch'] ?? '',
  ];
  if ($args['page'] === 'last') {
    $args['page'] = PHP_INT_MAX;
  }

  // Set the GET parameter for the pager
  $_GET['page'] = max(0, $args['page'] - 1);

  $user = user_load(arg(1));
  $senator_data = user_get_district_senator_data_array($user);

  // Build the query
  // Get a list of constituents in this senator's district, who have
  // sent to the senator at least one message tagged with a bill node.
  // Also, get a count of how many replies have been sent from the
  // senator back to the constituent.

  // Base table is users.
  $q = db_select('users', 'author')->extend('PagerDefault');

  // Defining all the joins
  $joins = [
    // first name, last name, and district fields from user
    'ffn' => [
      'type' => 'INNER',
      'table' => 'field_data_field_first_name',
      'join' => 'ffn.entity_id=author.uid AND ffn.bundle=:fbundle',
      'arg' => [':fbundle' => 'user'],
    ],
    'fln' => [
      'type' => 'INNER',
      'table' => 'field_data_field_last_name',
      'join' => 'fln.entity_id=author.uid AND fln.bundle=:lbundle',
      'arg' => [':lbundle' => 'user'],
    ],
    'fda' => [
      'type' => 'INNER',
      'table' => 'field_data_field_district',
      'join' => 'fda.entity_id=author.uid AND fda.bundle=:dbundle',
      'arg' => [':dbundle' => 'user'],
    ],
    // join messages based on the user being the author
    'pm' => [
      'type' => 'INNER',
      'table' => 'pm_message',
      'join' => 'pm.author=author.uid',
    ],
    'pmi' => [
      'type' => 'INNER',
      'table' => 'pm_index',
      'join' => 'pmi.mid=pm.mid',
    ],
    // limiting join based on a message having a bill property
    'fb' => [
      'type' => 'INNER',
      'table' => 'field_data_field_featured_bill',
      'join' => 'fb.entity_id=pmi.mid AND fb.entity_type=:btype',
      'arg' => [':btype' => 'privatemsg_message'],
    ],
    // the node for the message's bill reference
    'n' => [
      'type' => 'INNER',
      'table' => 'node',
      'join' => 'n.nid=fb.field_featured_bill_target_id',
    ],
    // Re-add the messages table for reply counts.  Note the reverse
    // between recipient and author.
    'pmi_c' => [
      'type' => 'LEFT',
      'table' => 'pm_index',
      'join' => 'pmi_c.recipient=pm.author',
    ],
    'pm_c' => [
      'type' => 'LEFT',
      'table' => 'pm_message',
      'join' => 'pm_c.mid=pmi_c.mid AND pm_c.author=pmi.recipient AND pm_c.reply_to_mid<>0',
    ],
    // Add voting table.  LEFT join since user might not have voted
    // TODO: change the JOIN to an equality once #13596 is addressed
    'vv' => [
      'type' => 'LEFT',
      'table' => 'votingapi_vote',
      'join' => 'vv.entity_type IN (:vtype) AND vv.entity_id=n.nid AND vv.uid=author.uid',
      'arg' => [':vtype' => ['node']],
    ],
  ];

  // Add all the joins
  foreach ($joins as $key => $val) {
    $q->addJoin($val['type'], $val['table'], $key, $val['join'], $val['arg'] ?? []);
  }

  // Add the fields to be returned
  $q->addField('author', 'uid', 'constituent_user_id');
  $q->addField('n', 'nid', 'bill_nid');
  $q->addExpression('CONCAT(ffn.field_first_name_value, \' \', fln.field_last_name_value)', 'constituent_name');
  $q->addField('ffn', 'field_first_name_value', 'constituent_first_name');
  $q->addField('fln', 'field_last_name_value', 'constituent_last_name');
  $q->addField('n', 'title', 'bill_print_number');
  $q->addField('vv', 'value', 'vote_value');
  $q->addField('vv', 'timestamp', 'vote_time');
  $q->addExpression('COUNT(pm_c.timestamp)', 'num_replies');
  $q->addExpression('MAX(pm_c.timestamp)', 'last_reply');

  // Add groupings
  $group_fields = [
    'constituent_user_id',
    'bill_nid',
    'constituent_name',
    'constituent_first_name',
    'constituent_last_name',
    'bill_print_number',
    'vote_value',
    'vote_time',
  ];
  foreach ($group_fields as $val) {
    $q->groupBy($val);
  }

  // Add base conditions
  $q->where('pmi.recipient <> pm.author')
    ->condition('fda.field_district_target_id', $senator_data['district_tid'])
    ->condition('pmi.recipient', $senator_data['senator_uid']);

  // Handle filter conditions
  // Bill print number
  if ($args['bill_name']) {
    $q->condition('n.title', '%' . $args['bill_name'] . '%', 'LIKE');
  }
  // Vote type
  if (in_array($args['vote_type'], ['aye', 'nay',])) {
    $q->condition('vv.value', ($args['vote_type'] == 'aye' ? '1' : '0'));
  }
  // Reply status
  if (in_array($args['comm_status'], ['yes', 'no',])) {
    $clause = 'num_replies ' . ($args['comm_status'] == 'yes' ? '>' : '=') . ' 0';
    $q->having($clause);
  }

  // Set sort order
  $q->orderBy('fda.field_district_target_id')
    ->orderBy('fln.field_last_name_value')
    ->orderBy('author.uid')
    ->orderBy('n.title', 'DESC');

  $result = $q->execute()->fetchAll();

  $rows = [];
  foreach ($result as $r) {
    $id_hash = $r->constituent_user_id . '-' . $r->bill_nid;
    $checkbox = '<input class="row-checkbox" type="checkbox" ' .
      'name="list[' . $id_hash . ']" value="' . $id_hash . '">';
    try {
      $name = theme('nys_dashboard_user_link', ['uid' => $r->constituent_user_id]);
    } catch (Exception $e) {
      $name = '';
      watchdog('nys_dashboard', 'Exception during theme(nys_dashboard_user_link)', ['msg' => $e->getMessage()], WATCHDOG_ERROR);
    }
    if ($r->vote_time ?? 0) {
      $vote_time = date('Y-m-d', $r->vote_time);
      $vote_value = ((int) $r->vote_value) ? 'AYE' : 'NAY';
    }
    else {
      $vote_time = '';
      $vote_value = '';
    }
    $vote = $vote_value . '<div class="date">' . $vote_time . '</div>';
    $last_reply = $r->last_reply ?? 0;
    $last_message_time = $last_reply
      ? 'YES<div class="date">' . date('Y-m-d', $last_reply) . '</div>'
      : 'NO';

    $rows[] = [
      ['data' => $checkbox, 'class' => 'form-type-checkbox',],
      ['data' => $name, 'class' => 'name'],
      ['data' => $r->bill_print_number, 'class' => 'bill_name'],
      ['data' => $vote, 'class' => 'vote'],
      ['data' => $last_message_time, 'class' => 'last-messaged'],
    ];
  }

  $header = [
    "",
    ['data' => "NAME", 'class' => 'name'],
    ['data' => "Bill Name", 'class' => 'bill_name'],
    ['data' => "Vote", 'class' => 'vote'],
    ['data' => "Messaged", 'class' => 'last-messaged'],
  ];

  try {
    $table = theme('table', [
      'header' => $header,
      'rows' => $rows,
      'empty' => 'No rows were found',
      'attributes' => ['width' => '100%', 'class' => ['stat-data']],
    ]);
  } catch (Exception $e) {
    $table = "<div>Error while generating table output</div>";
    watchdog('nys_dashboard', 'Exception during theme(table)', ['msg' => $e->getMessage()], WATCHDOG_ERROR);
  }
  try {
    $pager = theme('pager');
  } catch (Exception $e) {
    $pager = "<div>Error while generating pager controls</div>";
    watchdog('nys_dashboard', 'Exception during theme(pager)', ['msg' => $e->getMessage()], WATCHDOG_ERROR);
  }

  return '<div id="senator_constituents_table">' . $table . $pager . '</div>';
}

function split_ids($input) {
  foreach ($input as $index => $value) {
    $values = explode('-', $value);
    $users[] = $values[0];
    $bills[] = $values[1];
  }
  $combo = [$users, $bills];

  return $combo;
}
