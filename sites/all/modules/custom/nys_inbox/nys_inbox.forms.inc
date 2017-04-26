<?php 

function nys_inbox_form($form, &$form_state, $argument, $account) {

  $query_cache = &drupal_static(__FUNCTION__);

  $user = NULL;
  if ($form_state['rebuild']) {
    $user = user_load($form_state['input']['uid']);
  }
  else {
    $user = user_load(arg(1));
  }
  if (empty($user)) {
    return '';
  }

  $is_senator = user_is_senator($user->uid);

  $allowed_get_vars = array(
    'messagesearch', 
    'issuesearch', 
    'billsearch',
    'usersearch'
  );
  
  foreach($allowed_get_vars as $var) {
    if (isset($_GET[$var]) && empty($form_state['input'][$var])) {
      $form_state['input'][$var] = $_GET[$var];
    }   
  }

  // Load the themed list headers based on the available data.
  $headers = privatemsg_get_headers(TRUE);

  unset($headers['name']['field']); // remove sort on field
  unset($headers['last_updated']['field']); // remove sort on last_updated


  $form = array(
    '#list_argument' => $argument,
    //'#submit' => array('privatemsg_list_submit'),
    'updated' => array(
      '#prefix' => '<div id="nys_inbox></h2>',
      '#suffix' => '</div>',
    ),
    '#attributes' => array('id' => 'nys-inbox-form'),
    '#prefix' => '<div id="nys_inbox">',
    '#suffix' => '</div>',
  );
  
  
    $unread_messages = nys_inbox_unread_count($user);
  
  $title = "INBOX";
  if(!empty($_GET['sent']) && $_GET['sent'] == 1) {
     $title = 'SENT MESSAGES';
  }
 
 
  if($unread_messages) {
    $form['title'] = array('#markup' => '<h2 class="c-container--title">' . $title . ' (' . $unread_messages .' NEW)</h2>');
  } else {
    $form['title'] = array('#markup' => '<h2 class="c-container--title">' . $title . '</h2>');
  }
  
  
  if(empty($_GET['sent'])) {
   $form['sent'] = array(
     '#markup' => l('View Sent Messages', 'user/' . arg(1) . '/dashboard/inbox', array('attributes' => array('class' => array('back-to-inbox icon-after__right')), 'query' => array('sent' => 1))),
   );
 } else {
   $form['sent'] = array(
     '#markup' => nys_inbox_back_to_inbox_button(),
   );   
 }

 
 $form['uid'] = array(
   '#type' => 'hidden',
   '#value' => $user->uid,
 );

  if (empty($form['REQUEST_URI'])) {
    $form['REQUEST_URI'] = array(
      '#type' => 'hidden',
      '#value' => $_SERVER['REQUEST_URI'],
    );
  }

 $form['messagesearch'] = array(
    '#type' => 'textfield', 
    '#title' => t('Message Search'),
    '#title_display' => 'invisible',
    '#default_value' => isset($form_state['input']['messagesearch']) ? $form_state['input']['messagesearch'] : '', 
    '#size' => 60, 
    '#maxlength' => 128,
    '#attributes' => array('class' => array('c-site-search--box', 'icon_after__search', 'form-text'), 'type' => 'search'),
    '#prefix' => '<div class="search-wrapper">',
    '#suffix' => '</div>',
    '#post_render' => array('nys_dashboard_search_textfield_post_render'),
  );
 
 if(user_access('dashboard inbox search names', $user)) {
   $form['usersearch'] = array(
      '#type' => 'textfield', 
      '#title' => t('Name Search'),
      '#title_display' => 'invisible',
      '#default_value' => isset($form_state['input']['usersearch']) ? $form_state['input']['usersearch'] : '', 
      '#size' => 60, 
      '#maxlength' => 128,
      '#attributes' => array('class' => array('c-site-search--box', 'icon_after__search', 'form-text'), 'type' => 'search'),
      '#prefix' => '<div class="search-wrapper">',
      '#suffix' => '</div>',
      '#post_render' => array('nys_dashboard_search_textfield_post_render'),
    );
 }
  
  if(user_access('dashboard inbox search issues', $user)) {

    $form['issuesearch'] = array(
       '#type' => 'textfield', 
       '#title' => t('Issue Search'),
       '#title_display' => 'invisible',
       '#default_value' => isset($form_state['input']['issuesearch']) ? $form_state['input']['issuesearch'] : '',
       '#size' => 60, 
       '#maxlength' => 128,
       '#autocomplete_path' => 'taxonomy/autocomplete/field_issues', 
       '#attributes' => array('class' => array('c-site-search--box', 'icon_after__search', 'form-text')),
       '#prefix' => '<div class="search-wrapper">',
       '#suffix' => '</div>',
       '#post_render' => array('nys_dashboard_search_textfield_post_render'),
      );
  
   }
  
  if (user_access('dashboard inbox search bills', $user)) {

    $form['billsearch'] = array(
      '#type' => 'textfield',
      '#title' => t('Bill Search'),
      '#title_display' => 'invisible',
      '#default_value' => isset($form_state['input']['billsearch']) ? $form_state['input']['billsearch'] : '',
      '#size' => 60,
      '#maxlength' => 128,
      '#autocomplete_path' => 'nys-inbox/autocomplete/bill-search',
      '#attributes' => array(
        'class' => array(
          'c-site-search--box',
          'icon_after__search',
          'form-text',
        ),
        'onchange' => 'this.form.submit();',
      ),
      '#prefix' => '<div class="search-wrapper">',
      '#suffix' => '</div>',
      '#post_render' => array('nys_dashboard_search_textfield_post_render'),
    );

  }

  $form['go'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  $form['inbox_action_links'] = array(
    '#prefix' => '<div class="inbox-action-links">',
    '#suffix' => '</div>',  
  );

  if(user_access('dashboard inbox check all', $user)) {
  
    $form['inbox_action_links']['check_all'] = array(
      '#type' => 'checkbox',
      '#title' => t('Check All'),
      '#prefix' => '<div class="select-all-messages">',
      '#suffix' => '</div>',
      '#attributes' => array('id' => 'checkall'),
    );
  
  }

  if ($is_senator) {
    $form['inbox_action_links']['in_district'] = array(
      '#type' => 'checkbox',
      '#title' => t('In-District Only'),
      '#prefix' => '<div class="show-in-district">',
      '#suffix' => '</div>',
      '#ajax' => array(
        'callback' => 'nys_inbox_district_checkbox_ajax',
        'wrapper' => 'nys_inbox',
      )
    );
  }

  if (!empty($_GET['in_district'])) {
    $form['inbox_action_links']['in_district']['#attributes'] = array('checked' => 'checked');
    $form_state['values']['in_district'] = 1;
  }

  $form['inbox_action_links']['actions'] = array(
    '#type' => 'actions',
    '#prefix' => '<div class="action-button-wrapper">',
    '#suffix' => '</div>',
  );

  $form['inbox_action_links']['actions']['delete'] = array(
    '#type' => 'button',
    '#name' => 'delete',
    '#value' => t('Delete'),
    '#ajax' => array(
      'callback' => 'nys_inbox_delete_button_ajax',
      'wrapper' => 'inbox_confirmation_div',
      'effect' => 'fade',
     ),
  );

  $form['inbox_action_links']['actions']['message'] = array(
    '#type' => 'submit',
    '#value' => t('Message'),
    '#attributes' => array('class' => array('icon-before__contact')),
  );

  // Psuedo delete button for ajax confirm form handling.
  $form['delete_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );
  hide($form['delete_submit']);

  $form['confirm_placeholder'] = array(
    '#markup' => '<div id="inbox_confirmation_div"></div>', 
  );
  
  $form['updated'] = array(
    '#weight' => 2,
  );

  $form['updated']['list'] = array(
    '#type' => 'tableselect',
    '#header' => $headers,
    '#js_select' => FALSE, // turns off default check all solution
    '#options' => array(),
    '#attributes' => array('class' => array('privatemsg-list', 'tableheader-processed'), 'width' => '100%'),
    '#empty' => t('No messages available.'),
    '#weight' => 5,
    '#pre_render' => array('_privatemsg_list_thread'),
    '#prefix' => '<div id="inbox_message_table">',
    '#suffix' => '</div>',
  );
  
  /*if (!$total_message_count) { // hide actions if no results
    unset($form['inbox_action_links']); 
  }*/

  if(!empty($_GET['sent']) && $_GET['sent'] == 1) {
    $inbox_view = 'sent';
  } else {
    $inbox_view = 'inbox';
  }

  if (!isset($query_cache['privatemsg']) || !isset($query_cache['msgcount'])) {
    $query = _privatemsg_assemble_query('list', $user, $inbox_view);
    $count_query = $query->getCountQuery();

    if (!empty($form_state['input']['messagesearch'])) {
      $query->where("CONCAT(pm.subject, pm.body) LIKE :q", array(':q' => '%' . $form_state['input']['messagesearch'] . '%'));
      $count_query->where("CONCAT(pm.subject, pm.body) LIKE :q", array(':q' => '%' . $form_state['input']['messagesearch'] . '%'));
    }

    if (!empty($form_state['input']['issuesearch'])) {

      $results = taxonomy_get_term_by_name($form_state['input']['issuesearch'], 'issues');

      if (!empty($results)) {
        $search_term = array_shift($results);
        $tid = $search_term->tid;

      }
      else {
        $tid = 0;
      }

      $query->join('field_data_field_issues', 'fi', 'fi.entity_id = pm.mid');
      $query->condition('fi.field_issues_tid', (string) $tid);
      $query->condition('fi.entity_type', 'privatemsg_message');

      $count_query->join('field_data_field_issues', 'fi', 'fi.entity_id = pm.mid');
      $count_query->condition('fi.field_issues_tid', (string) $tid);
      $count_query->condition('fi.entity_type', 'privatemsg_message');

    }

    if (!empty($form_state['input']['billsearch'])) {

      $results = db_query("SELECT nid FROM node WHERE TYPE = 'bill' AND title LIKE :bill_search", array(':bill_search' => '%' . db_like($form_state['input']['billsearch']) . '%'));

      $nids = array();
      foreach ($results as $r) {
        $nids[] = $r->nid;
      }

      if (empty($nids)) {
        $nids = array(0);
      }


      $query->join('field_data_field_featured_bill', 'ffb', 'ffb.entity_id = pm.mid');
      $query->condition('ffb.field_featured_bill_target_id', $nids, 'IN');
      $query->condition('ffb.entity_type', 'privatemsg_message');

      $count_query->join('field_data_field_featured_bill', 'ffb', 'ffb.entity_id = pm.mid');
      $count_query->condition('ffb.field_featured_bill_target_id', $nids, 'IN');
      $count_query->condition('ffb.entity_type', 'privatemsg_message');

    }

    if (!empty($form_state['input']['usersearch'])) {

      $userquery = "SELECT uid, fn.field_first_name_value, fl.field_last_name_value from users u
     LEFT JOIN field_data_field_first_name fn ON fn.entity_id = u.uid and fn.entity_type = 'user' 
     LEFT JOIN field_data_field_last_name fl ON fl.entity_id = u.uid and fl.entity_type = 'user'
     WHERE CONCAT(u.name, fn.field_first_name_value, ' ', fl.field_last_name_value) LIKE :q";


      $result = db_query($userquery, array(':q' => '%' . $form_state['input']['usersearch'] . '%'));

      $uids = array();
      foreach ($result as $r) {
        $uids[$r->uid] = $r->uid;
      }

      if (!empty($uids[$user->uid])) {
        unset($uids[$user->uid]);
        if (empty($uids)) {
          drupal_set_message('It appears you\'re searching for yourself.  To see outgoing messages, visit the "Sent Messages" link', 'notice');
        }
      }


      if (empty($uids)) {
        $uids = array(0);
      }

      $query->condition('pm.author', $uids, 'IN');
      $count_query->condition('pm.author', $uids, 'IN');

    }

    if ($inbox_view == 'inbox') {
      $query->condition('pm.author', (string) $user->uid, '!=');
      $count_query->condition('pm.author', (string) $user->uid, '!=');
    }

    $query->orderBy('last_updated', 'DESC');
    $query_cache['privatemsg'] = $query->execute();
    $query_cache['msgcount'] = $count_query;
  }

  $i = 0;
  foreach ($query_cache['privatemsg'] as $row) {

    // Store the raw row data.
    $form['updated']['list']['#options'][$row->thread_id] = (array)$row;
    // Tableselect sorts the options, set a weight so that the order doesn't get
    // changed.

    $form['updated']['list']['#options'][$row->thread_id]['#weight'] = $i++;
  }

  if (!empty($form['updated']['list']['#options'])) {

    // Load the last reply that is not from the current user.
    if (!isset($query_cache['last_message'])) {
      $query_cache['last_message'] = db_query('SELECT pm.author, pmi.thread_id, MAX(pm.mid) AS last_message FROM {pm_message} pm INNER JOIN {pm_index} pmi ON pm.mid = pmi.mid WHERE pmi.thread_id IN (:thread_ids) AND pm.author <> :current_uid GROUP BY pmi.thread_id', array(
        ':current_uid' => $user->uid,
        ':thread_ids' => array_keys($form['updated']['list']['#options'])
      ));
    }
    foreach ($query_cache['last_message'] as $row) {
      $form['updated']['list']['#options'][$row->thread_id]['dash_uid'] = $form_state['input']['uid'];
      // Set replied flag if there is no newer message from another user than
      // the last replied.
      if ($row->last_message <= $form['updated']['list']['#options'][$row->thread_id]['last_reply_to_mid']) {
        $form['updated']['list']['#options'][$row->thread_id]['is_replied'] = TRUE;
      }
      // Add the sender's district and indicate if it is the same as the Senator's.
      $in_district = FALSE;
      if ($is_senator && !empty($row->author)) {
        $sender_info = user_get_district_senator_data_array($row->author);
        if ($sender_info) {
          $senator_nid = $sender_info['senator_nid'];
          $district = senator_get_district_number($senator_nid);
          $form['updated']['list']['#options'][$row->thread_id]['district'] = $district;
          if ($sender_info['senator_uid'] == $user->uid) {
            $in_district = TRUE;
            $form['updated']['list']['#options'][$row->thread_id]['in_district'] = TRUE;
            $row_district_class = 'privatemsg-indistrict';
          }
        }
      }

      if (!$in_district && !empty($form_state['values']['in_district'])) {
        unset($form['updated']['list']['#options'][$row->thread_id]);
      }
    }

    //$form['updated']['actions'] = _privatemsg_action_form($argument);
  }

  // Save the currently active account, used for actions.
  $form['account'] = array('#type' => 'value', '#value' => $user);

  // Define checkboxes, pager and theme
  $form['updated']['pager'] = array('#markup' => theme('pager'), '#weight' => 20);
  return $form;
}

function nys_inbox_form_submit($form, &$form_state) {

    
  $user = user_load(arg(1));
  if(empty($user)) {
    return;
  }
  $account = clone $user;
  
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'), 1);

  if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Delete') {
    if (!empty($form_state['input']['list'])) {
      // convert list of mids to list of threads
      $messages = privatemsg_message_load_multiple($form_state['input']['list']);
      $thread_ids = array();
      foreach($messages as $message) {
        $thread_ids[] = $message->thread_id;
      }
      privatemsg_thread_change_delete($thread_ids, 1, $account);
      return;
    }
    return;
  }
  
  else if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Message') {

    if ($form_state['input']['check_all'] == 1 && $form_state['input']['in_district'] != 1) {
      
      
      $queryArgs = array(
        'context' => 'inbox',
      );
              
      $allowed_get_vars = array('messagesearch', 'issuesearch', 'billsearch', 'usersearch');
      
      $has_query_args = 0;
      foreach($allowed_get_vars as $var) {
        if (isset($form_state['input'][$var]) && !empty($form_state['input'][$var])) {
          $queryArgs[$var] = $form_state['input'][$var];
          $has_query_args = 1;
        }   
      }
      
      if(!$has_query_args) {
        $queryArgs['messageall'] = 1;
      }
      
                  
      $form_state['redirect'] = array(
        $dashboard_link . '/inbox/new',
        array(
          'query' => $queryArgs,
        ),    
      );
      
      return;
    }
    
     
    else if (!empty($form_state['input']['list'])) {
      
      // remove null values
      $array = array_filter($form_state['input']['list'], 'strlen');
      if(user_is_senator($user)) {
        $uids = nys_inbox_get_participants_from_thread_ids($array);
      } else {
        $uids = array('temp'); // redirect to reply form
      }

      if(sizeof($uids) == 1) {      
      
        $list = array_filter($form_state['input']['list']); // remove empty array elements
        
        $thread_id = array_pop($list);
        
        $form_state['redirect'] = array(
          $dashboard_link . '/inbox/reply/' . $thread_id,
          array(
            'query' => array()
          ),    
        );
        return;       
      }
      
      
      // message the list
      $form_state['redirect'] = array(
        $dashboard_link . '/inbox/new',
        array(
          'query' => array('uids' => $uids)
        ),    
      );
      return;
    } 
  }

  else if ($form_state['input']['messagesearch'] != "") {

    $form_state['redirect'] = array(
      $dashboard_link . '/inbox',
      array(
        'query' => array('messagesearch' => $form_state['input']['messagesearch'])
      ),    
    );
  } 
  
  else if ($form_state['input']['issuesearch'] != "") {

    $form_state['redirect'] = array(
      $dashboard_link . '/inbox',
      array(
        'query' => array('issuesearch' => $form_state['input']['issuesearch'])
      ),    
    );
  } else if ($form_state['input']['billsearch'] != "") {

    $form_state['redirect'] = array(
      $dashboard_link . '/inbox',
      array(
        'query' => array('billsearch' => $form_state['input']['billsearch'])
      ),    
    );
  } else if ($form_state['input']['usersearch'] != "") {

    $form_state['redirect'] = array(
      $dashboard_link . '/inbox',
      array(
        'query' => array('usersearch' => $form_state['input']['usersearch'])
      ),    
    );
  } else {
    // if there are no search terms passed in the form, we need to strip out $_GET search parameters, 
    // otherwise, you can't clear the form by emptying search field and submitting it
    $form_state['redirect'] = array(
      $dashboard_link . '/inbox',  
    );
  } 
  
}

/**
 * form callback to write a message to one or more user from the inbox
 */
function nys_inbox_message_form($form, &$form_state, $recipients = '', $subject = '') {
    
  $user = user_load(arg(1));
  
  if(empty($user)) {
    return array();
  }
  
  $form = array();
  
  $form['backbutton'] = array(
    '#markup' => nys_inbox_back_to_inbox_button(),
  );
  
  $form['header'] = array(
    '#markup' => '<div class="privatemsg-message-participants">Send Message</div>',
  );

  $form['to'] = array(
    '#type'               => 'textfield',
    '#title'              => t('To'),
    '#default_value'      => '',
    '#size'               => 50,
  );
  
  $form['recipient_uid'] = array(
    '#type'               => 'hidden',
    '#value'              => '',
  );
  
  $form['context'] = array(
    '#type'               => 'hidden',
    '#value'              => !empty($_GET['context']) ? $_GET['context'] : '',

  );
  
  $form['bill_id'] = array(
    '#type'               => 'hidden',
    '#value'              => !empty($_GET['bill_id']) ? $_GET['bill_id'] : '',
  );
  
  $form['issue_id'] = array(
    '#type'               => 'hidden',
    '#value'              => !empty($_GET['issue_id']) ? $_GET['issue_id'] : '',
  );
  
  $form['committee_id'] = array(
    '#type'               => 'hidden',
    '#value'              => !empty($_GET['committee_id']) ? $_GET['committee_id'] : '',
  );
  
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => '',

  );
  
  $form['body'] = array(
    '#type'               => 'text_format',
    '#title'              => t('Message'),
    '#rows'               => 6,
    '#resizable'          => TRUE,
    '#format'             => 'plain_text',
    '#after_build'        => array('privatemsg_check_format_access'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send Message'),
  );
  
  if (
      ($_GET['context'] == 'senators_constituents_tab')
      ||
      ($_GET['context'] == 'senators_issues_tab')
      ||
      ($_GET['context'] == 'senators_petitions_tab')
      ||
      ($_GET['context'] == 'senators_questionnaires_tab')
      ||
      ($_GET['context'] == 'senators_bills_tab')
    ) {
    $to = nys_inbox_get_to_value_constituents_tab_context();
  } 
  else if ($_GET['context'] == 'message_senator') {
    $senator_uid = user_get_senator_uid($user);
    $form['to']['#default_value'] = strip_tags(theme('nys_dashboard_user_link', array('uid' => $senator_uid)));
    $form['to']['#disabled'] = TRUE;
    $form['recipient_uid']['#value'] = array($senator_uid);
  } 
  else if (in_array($_GET['context'], array('bill_vote', 'following_bill'))) {
    $senator_uid = user_get_senator_uid($user);
    $form['to']['#default_value'] = strip_tags(theme('nys_dashboard_user_link', array('uid' => $senator_uid)));
    $form['to']['#disabled'] = TRUE;
    $bill_nid = $_GET['bill_id'];
    $bill = node_load($bill_nid);

    $form['subject']['#default_value'] = 'Bill ' . $bill->title;

    if ($_GET['context'] == 'bill_vote') {

      $user_first_name = check_plain($user->field_first_name[LANGUAGE_NONE][0]['value']);
      $user_last_name = check_plain($user->field_last_name[LANGUAGE_NONE][0]['value']);

      $bill_vote_uid = $user->uid;

      if (!empty($user_first_name) && !empty($user_last_name)) {
        $bill_vote_user = $user_first_name . ' ' . $user_last_name;
      }

      $result = db_select('votingapi_vote', 'v')
        ->fields('v', array('value'))
        ->condition('entity_id', $bill_nid)
        ->condition('uid', $bill_vote_uid)
        ->condition('tag', 'nys_bill_vote')
        ->condition('entity_type', 'node')
        ->range(0 ,1)
        ->execute()
        ->fetchAssoc();

      if (count($result) > 0 && isset($bill_vote_user)) {
        $vote_value = $result['value'];
        if (!empty($vote_value)) {
          $vote_status = '"Aye"';
        }
        else {
          $vote_status = '"Nay"';
        }
        $form['subject']['#default_value'] = $bill_vote_user . ' voted ' . $vote_status . ' on ' . $bill->title;
      }
    }

    $form['subject']['#disabled'] = TRUE;
    $form['recipient_uid']['#value'] = array($senator_uid);
  } 
  else if ($_GET['context'] == 'issue') {
    $senator_uid = user_get_senator_uid($user);
    $form['to']['#default_value'] = strip_tags(theme('nys_dashboard_user_link', array('uid' => $senator_uid)));
    $form['to']['#disabled'] = TRUE;
    $issue_tid = $_GET['issue_id'];    
    $issue = taxonomy_term_load($issue_tid);
    $form['subject']['#default_value'] = $issue->name;
    $form['subject']['#disabled'] = TRUE;
    $form['recipient_uid']['#value'] = array($senator_uid);
  } 
  else if ($_GET['context'] == 'following_committee') {
    $senator_uid = user_get_senator_uid($user);
    $form['to']['#default_value'] = strip_tags(theme('nys_dashboard_user_link', array('uid' => $senator_uid)));
    $form['to']['#disabled'] = TRUE;
    $committee_id = $_GET['committee_id'];    
    $committee = taxonomy_term_load($committee_id);
    $form['subject']['#default_value'] = $committee->name;
    $form['subject']['#disabled'] = TRUE;
    $form['recipient_uid']['#value'] = array($senator_uid);
  } 
  else if ($_GET['context'] == 'inbox') {
    $to = nys_inbox_get_to_value_inbox_tab_context();    
  } 
  
  if (!empty($to)) {
    if (
      ($_GET['context'] == 'senators_constituents_tab')
      ||
      ($_GET['context'] == 'senators_issues_tab')
      ||
      ($_GET['context'] == 'senators_petitions_tab')
      ||
      ($_GET['context'] == 'senators_questionnaires_tab')
      ||
      ($_GET['context'] == 'senators_bills_tab')
    ) {
      $form['to']['#default_value'] = 'Constituents ' . implode(', ', $to);
    } else if ($_GET['context'] == 'inbox') {
      $form['to']['#default_value'] = implode(', ', $to);
    }
    
    $form['to']['#disabled'] = TRUE;
    $form['recipient_uid']['#value'] = 'query';
    
    $form['queryArgs'] = array(
      '#type'               => 'hidden',
      '#value'              => $_GET,
      '#weight'             => -10
    );
    
  }
  
  else if (!empty($_GET['uids'])) {
    if (!empty($_GET['uids'])) {
      $users = user_load_multiple($_GET['uids']);
      $names = array();
      foreach($users as $account) {
        $names[] = $account->name;
      }
      
      $form['to']['#default_value'] = ($_GET['all_constituents'] == 1) ? 'All Constituents' : implode(', ', $names);
      $form['to']['#disabled'] = TRUE;
      $form['recipient_uid']['#value'] = $_GET['uids'];
    }
  }
  
  if(empty($_GET['context'])) {
    $form['to']['#autocomplete_path'] = 'nys-inbox/autocomplete/user';
  }


  return $form;

}

function nys_inbox_message_form_validate($form, &$form_state) {
  $account = user_load(arg(1));
  $values = $form_state['values'];
  
 // if user used autocomplete, parse the "to" field to fill the recipient_uid field
  if(empty($values['context']) && !empty($values['to']) && strpos($values['to'], '(')) {
    $users = nys_inbox_parse_autocomplete_to_list($values['to']);
    $form_state['values']['recipient_uid'] = $users;
    
    $recipients = array();
    foreach($users as $key => $value) {
      $recipients['user_' . $key] = user_load($value);
    }
  
    $blocked = nys_inbox_privatemsg_block_message($account,$recipients);
    if(!empty($blocked)) {
      form_set_error('to',$blocked[0]['message']);
    }
  }
  
  if(empty($values['subject'])) {
    form_set_error('subject', t('Subject field cannot be empty.')); 
  }
  
  if(empty($values['body']['value'])) {
    form_set_error('body', t('Body field cannot be empty.'));
  }
  
  
}


function nys_inbox_message_form_submit($form, &$form_state) {

  $values = $form_state['values'];

  if (!empty($values['message']) && empty($values['body']['value'])) {
    $values['body']['value'] = $values['message'];
  }
  
  
  if(arg(0) == 'user') {
    $user = user_load(arg(1)); // send message from this person's new message form
  } else if(arg(0) == 'node' && arg(2) == 'message') {
    global $user;
  }
  
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'),1);
  
  if ($values['recipient_uid'] == 'query') {

    $form_state['redirect'] = array(
      $dashboard_link . '/inbox',
      array(
        'query' => array()
      ),    
    );  
  
    
    $_SESSION['http_request_count'] = 0; // reset counter for debug information.
    
    $_SESSION['bulk_message_filters'] = $_GET;
    $_SESSION['author_uid'] = $user->uid;
  
    // Execute the function named batch_example_1 or batch_example_2.
    $batch = nys_inbox_bulk_message_by_query();
    batch_set($batch);
    return;
 
  }

  if (!is_array($values['recipient_uid'])) {
    $values['recipient_uid'] = array($values['recipient_uid']);
  }
  $recipients = user_load_multiple($values['recipient_uid']);

  $options = array(
    'author' => $user,
  );

  
  
  $message = privatemsg_new_thread($recipients, $values['subject'], $values['body']['value'], $options);

  // Associate the issue to the message while saving
  if(!empty($values['issue_id'])) {

    $mid = $message['message']->mid;
    $loaded_message = privatemsg_message_load($mid);
    $loaded_message->field_issues['und'][]['tid'] = $values['issue_id'];
    field_attach_update('privatemsg_message', $loaded_message);
  }


  if(empty($_GET['bill_ids']) && !empty($_GET['bill_id'])) {
    $_GET['bill_ids'] = array($_GET['bill_id']);
  }
  
  // Associate the bill(s) to the message while saving
  if(isset($_GET['bill_ids'])) {
    $mid = $message['message']->mid;
    $loaded_message = privatemsg_message_load($mid);
    foreach($_GET['bill_ids'] as $bill_id) {
      $loaded_message->field_featured_bill['und'][]['target_id'] = $bill_id;
    field_attach_update('privatemsg_message', $loaded_message);
    }
  }

  // Associate the issue to the message while saving
  if(isset($_GET['petition_id'])) {
    $mid = $message['message']->mid;
    $loaded_message = privatemsg_message_load($mid);
    
    $loaded_message->field_petitions_questionnaires['und'][]['target_id'] = $_GET['petition_id'];
    field_attach_update('privatemsg_message', $loaded_message);
  }

  if (isset($message) && $message['success'] == 1) {
    drupal_set_message(t("Your message has been sent!"), 'status');
  }
  
  // Set the right redirect URL based on the context
  
  if(empty($_GET['context']) && !empty($values['context'])) {
    $_GET['context'] = $values['context'];
  }
  
  switch($_GET['context']) {
    case 'senators_constituents_tab' : $redirect_url = $dashboard_link . '/constituents'; break;
    case 'senators_petitions_tab' : $redirect_url = $dashboard_link; break;
    case 'senators_questionnaires_tab' : $redirect_url = $dashboard_link . '/questionnaires'; break;
    case 'senators_issues_tab' : $redirect_url = $dashboard_link . '/issues'; break;
    case 'senators_bills_tab' : $redirect_url = $dashboard_link . '/bills'; break;
    case 'bill_vote' : $redirect_url = 'node/' . $values['bill_id']; break;
    case 'following_bill' : $redirect_url = 'node/' . $values['bill_id']; break;
    case 'issue' : $redirect_url = 'taxonomy/term/' . $values['issue_id']; break;
    case 'following_committee' : $redirect_url = 'taxonomy/term/' . $values['committee_id']; break;
    case 'nys_messaging_senator_message_form' :
      $redirect_url = 'node/' . arg(1);
    break;
    default: $redirect_url = $dashboard_link . '/inbox';
  }

  $form_state['redirect'] = array(
    $redirect_url,
    array(
      'query' => array()
    ),    
  );
  
  foreach (module_implements('nys_inbox_new_message_sent') as $module) {
    $function = $module . '_nys_inbox_new_message_sent';
    // will call all modules implementing hook_hook_name
    // and can pass each argument as reference determined
    // by the function declaration
    $function($values, $message);
  }

}

/**
 * form callback to write a message to one or more user from the inbox
 */
function nys_inbox_forward_form($form, &$form_state, $recipients = '', $subject = '') {
    
  $user = user_load(arg(1));
  
  $thread_id = arg(5);

  $thread = privatemsg_thread_load($thread_id); 
  
  module_load_include('inc', 'privatemsg', 'privatemsg.pages');
  
  $output = '';
  
  foreach($thread['messages'] as $message) {
    $author = strip_tags(theme('nys_dashboard_user_link', array('uid' => $message->author->uid)));
    $output .= 'from: ' . $author . "\n\n";
    $output .= 'subject: ' . $message->subject. "\n\n\n";
    $output .= strip_tags($message->body). "\n\n";
    $output .= '---';
  }

  
  if(empty($user)) {
    return array();
  }
  
  $form = array();
  
  $form['backbutton'] = array(
    '#markup' => nys_inbox_back_to_inbox_button(),
  );
  
  $form['header'] = array(
    '#markup' => '<div class="privatemsg-message-participants">Forward Message</div>',
  );

  $form['email'] = array(
    '#type'               => 'textfield',
    '#title'              => t('E-mail'),
    '#default_value'      => '',
    '#size'               => 50,

  );
  
  
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => '',

  );
  
  $form['message'] = array(
    '#title' => 'Message',
    '#type' => 'textarea',
    '#rows' => 5,
    '#default_value' => "---\n" . $output,

  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send Message'),
  );
  
  return $form;

}

/**
 * Form validation logic for the contact form.
 */
function nys_inbox_forward_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('That e-mail address is not valid.'));
  }
}

function nys_inbox_forward_form_submit($form, &$form_state) {

  
  $form_values = $form_state['values'];
  
  $user = user_load(arg(1)); // send message from this person's new message form
  
  $module = 'nys_inbox';
  $key = 'nys_inbox_forward';

  $to = $form_values['email'];
  $from = variable_get('site_mail');

  // "params" loads in additional context for email content completion in
  // hook_mail(). In this case, we want to pass in the values the user entered
  // into the form, which include the message body in $form_values['message'].
  $params = $form_values;

  $language = language_default();

  // Whether or not to automatically send the mail when drupal_mail() is
  // called. This defaults to TRUE, and is normally what you want unless you
  // need to do additional processing before drupal_mail_send() is called.
  $send = TRUE;
  // Send the mail, and check for success. Note that this does not guarantee
  // message delivery; only that there were no PHP-related issues encountered
  // while sending.
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);

  if ($result['result'] == TRUE) {
    drupal_set_message(t('Your message has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }
  
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'),1);
  $redirect_url = $dashboard_link . '/inbox';

  $form_state['redirect'] = array(
    $redirect_url,
    array(
      'query' => array()
    ),    
  );

}

function nys_inbox_reply_form($form, &$form_state) {
  $form = array();
  global $user;
  
  $account = user_load(arg(1));
  
  $thread_id = arg(5);
  
  $original_author_uid = (int) db_query("SELECT author from pm_message WHERE mid = :thread_id", array(':thread_id' => $thread_id))->fetchField();
  $original_recipient_number = (int) db_query("select count(pmi.recipient) as count from pm_index pmi JOIN pm_message pm ON pm.mid = pmi.mid where pmi.mid = :thread_id AND pmi.recipient != pm.author;", array(':thread_id' => $thread_id))->fetchField();
  
  
  if($original_recipient_number > 1) {
    $is_bulk_message = 1;
  } else {
    $is_bulk_message = 0;
  }
  
  $form['backbutton'] = array(
    '#markup' => nys_inbox_back_to_inbox_button(),
  );
 
  $total_count = nys_inbox_thread_get_recipient_count($thread_id);
  
  
  if($is_bulk_message) {
    $account_themed = theme('nys_dashboard_user_link', array('uid' => $account->uid)); // theme dashboard user
    if (user_is_constituent($account)) {
      $author_themed = theme('nys_dashboard_user_link', array('uid' => $original_author_uid));
      $participants_themed = 'Message between ' . $author_themed . ' & ' . $account_themed;
    } else if (user_is_senator($account)) {
      $participants_themed = 'Message from ' . $account_themed . ' to ' . ($total_count - 1) . ' constituents'; 
    }
    
  } 

  else if (!$is_bulk_message) {
    
    $thread = privatemsg_thread_load($thread_id);

    $participants_themed =_nys_inbox_format_participants($thread['participants'], 4);

  
  }
  
      $form['participants'] = array(
      '#markup' => '<div class="privatemsg-message-participants">' . $participants_themed . '</h3>',
    );  

  
  $query = privatemsg_sql_messages(array($thread_id));
  
  
  $mids = array();
  foreach ($query->execute() as $row) {
    $mids[$row->mid] = $row->mid; 
  }
  
  $messages = array();
  if(!empty($mids)) {
      $messages = privatemsg_message_load_multiple($mids, array('account' => $account));
    // Render the messages.
  }
  
  
  $i = 1;
  $count = count($messages);
  foreach ($messages as $pmid => $message) {
    // Set message as read and theme it.
    // Add CSS classes.
    $message->classes = array('privatemsg-message', 'privatemsg-message-' . $i, $i % 2 == 1 ? 'privatemsg-message-even' : 'privatemsg-message-odd');
    if (!empty($message->is_new)) {
      // Mark message as read.
      privatemsg_message_change_status($pmid, PRIVATEMSG_READ, $account);
      $message->classes[] = 'privatemsg-message-new';
    }

    if ($i == 1) {
      $message->classes[] = 'privatemsg-message-first';
    }
    if ($i == $count) {
      $message->classes[] = 'privatemsg-message-last';
    }
    $i++;
    $form['messages'][$pmid] = array(
      '#markup' => theme('privatemsg_view', array('message' => $message)),
      '#attached' => array(
        'css' => array(
          drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.base.css',
          drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.theme.css',
        ),
      ),
    );
  }
  
  $reply_to_mid = (int) db_query("select min(mid) from pm_index WHERE thread_id = :thread_id", array(':thread_id' => $thread_id))->fetchField();


  $form['reply_to_mid'] = array(
    '#type' => 'value',
    '#value' => $reply_to_mid,
  );
  
  $form['author'] = array(
    '#type' => 'value',
    '#value' => $account,
  );
  
  $form['subject'] = array(
    '#type' => 'value',
    '#value' => $messages[$reply_to_mid]->subject,
  );
    
  $form['body'] = array(
    '#type'               => 'text_format',
    '#title'              => t('Reply'),
    '#rows'               => 6,
    '#resizable'          => TRUE,
    '#format'             => 'plain_text',
    '#after_build'        => array('privatemsg_check_format_access'),
  );
  
  $form['thread_id'] = array(
    '#type' => 'hidden',
    '#value' => arg(5),
  );

  
  $form['submitbutton'] = array(
    '#type' => 'submit',
    '#value' => t('Send Reply'),
  );
  
  
  if(!$is_bulk_message || arg(1) == $original_author_uid) {
    $form['#submit'] = array('nys_inbox_reply_submit', 'privatemsg_new_submit');
    $form['#validate'] = array('privatemsg_new_validate');
  } else {
    
    $form['recipient_uid'] = array(
      '#type'  => 'hidden',
      '#value' => array($original_author_uid),
    );
    $form['#submit'] = array('nys_inbox_reply_form_bulk_message_submit');
  }

  return $form;
}

function nys_inbox_reply_submit($form, &$form_state) {

  foreach (module_implements('nys_inbox_reply_sent') as $module) {
    $function = $module . '_nys_inbox_reply_sent';
    // will call all modules implementing hook_hook_name
    // and can pass each argument as reference determined
    // by the function declaration
    $function($form_state["values"]);
  }
  
}

function nys_inbox_reply_form_bulk_message_submit($form, &$form_state) {

  $user = user_load(arg(1));

  $values = $form_state['values'];
    $options = array(
    'author' => $values['author'],
  );

  $recipients = user_load_multiple($values['recipient_uid']); 
  $return = privatemsg_new_thread($recipients, $values['subject'], $values['body']['value'], $options);
  
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'),1);

  $form_state['redirect'] = array(
    $dashboard_link . '/inbox/reply/' . $return['message']->thread_id,
    array(
      'query' => array()
    ),    
  );
  
}


function nys_inbox_delete($form, $form_state) {
  
  $account = user_load(arg(1));

  
  $thread = privatemsg_thread_load(arg(5), $account);
  
  $inbox_link = substr(url('user/' . $account->uid . '/dashboard/inbox'),1);
  
  if(empty($thread)) {   
    drupal_set_message(t('That is not a valid thread'),'warning');
    drupal_goto($inbox_link);
  }
  
  $form['pmid'] = array(
    '#type' => 'value',
    '#value' => arg(6),
  );

  $form['delete_destination'] = array(
    '#type' => 'value',
    '#value' => count($thread['messages']) > 1 ? $inbox_link . '/reply/' . arg(5) : $inbox_link,
  );

  return confirm_form($form,
    t('Are you sure you want to delete this message?'),
    isset($_GET['destination']) ? $_GET['destination'] : $inbox_link,
    t('<p>This action cannot be undone.</p>'),
    t('Delete'),
    t('Cancel')
  );
}

function nys_inbox_delete_submit($form, &$form_state) {

  $user = user_load(arg(1));
  $account = clone $user;

  if ($form_state['values']['confirm']) {
    if (isset($form_state['values']['delete_options']) && $form_state['values']['delete_options']) {
      privatemsg_message_change_delete($form_state['values']['pmid'], 1);
      drupal_set_message(t('Message has been deleted for all users.'));
    }
    else {
      privatemsg_message_change_delete($form_state['values']['pmid'], 1, $account);
      drupal_set_message(t('Message has been deleted.'));
    }
  }
  $form_state['redirect'] = $form_state['values']['delete_destination'];
}
