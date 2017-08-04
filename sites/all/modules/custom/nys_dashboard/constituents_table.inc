<?php

function nys_inbox_senator_constituents_form($form, &$form_state) {
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


  $title = t("Your Constituents");

  $form['#prefix'] = '<div id="nys_senators_constituents" class="c-block c-container c-container--senator-constituents"><h2 class="c-container--title">' . $title .'</h2>';
  $form['#suffix'] = '</div>';

  $form['namesearch'] = array(
    '#type' => 'textfield',
    '#title' => t('Search'),
    '#title_display' => 'invisible',
    '#default_value' => isset($form_state['input']['namesearch']) ? $form_state['input']['namesearch'] : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#attributes' => array('class' => array('c-site-search--box', 'icon_after__search', 'form-text'), 'type' => 'search'),
    '#prefix' => '<div class="search-wrapper">',
    '#suffix' => '</div>',
    '#post_render' => array('nys_dashboard_search_textfield_post_render'),
    '#autocomplete_path' => 'nys-dashboard/autocomplete/user',
  );

  $form['filters']['label'] = array(
    '#markup' => '<label>Filter by</label>',
  );

   $form['filters']['fb'] = array(
    '#type' => 'select',
     '#options' => array(
        'all' => t('All Constituents'),
        0 => t('Not Facebook Verified'),
        1 => t('Facebook Verified'),
     ),
     '#default_value' => isset($form_state['input']['fb']) ? $form_state['input']['fb'] : 'all',
     '#attributes' => array('class' => array('filter'), 'id' => 'fb'),
     '#theme_wrappers' => array('nude_form_element'),
     '#prefix' => '<div class="filter-wrapper filter-wrapper--constituent">',
     '#suffix' => '</div>',
   );

  $form['filters']['agesearch'] = array(
    '#type' => 'select',
     '#options' => nys_dashboard_constituent_age_ranges(),
     '#default_value' => isset($form_state['input']['agesearch']) ? $form_state['input']['agesearch'] : 'all',
     '#attributes' => array('class' => array('filter'), 'id' => 'agesearch'),
     '#theme_wrappers' => array('nude_form_element'),
     '#prefix' => '<div class="filter-wrapper filter-wrapper--constituent">',
     '#suffix' => '</div>',
   );

   $form['filters']['gender'] = array(
    '#type' => 'select',
     '#options' => array(
        'all' => t('Men, Women and Other'),
        'men' => t('Men'),
        'women' => t('Women'),
        'other' => t('Other'),
     ),
     '#default_value' => isset($form_state['input']['gender']) ? $form_state['input']['gender'] : 'all',
     '#attributes' => array('class' => array('filter'), 'id' => 'gender'),
     '#theme_wrappers' => array('nude_form_element'),
     '#prefix' => '<div class="filter-wrapper filter-wrapper--constituent">',
     '#suffix' => '</div>',
   );

 $form['filters']['zipsearch'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($form_state['input']['zipsearch']) ? $form_state['input']['zipsearch'] : 'Zip Code',
    '#theme_wrappers' => array('nude_form_element'),
    '#autocomplete_path' => 'nys-dashboard/autocomplete/zip-code',
    '#attributes' => array('class' => array(''), 'id' => 'zipsearch'),
    '#post_render' => array('nys_dashboard_search_textfield_post_render'),
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

  $form['messages_table'] = array('#markup' => nys_dashboard_senators_constituents_table($form_state));


  return $form;
}


function nys_inbox_senator_constituents_form_submit($form, &$form_state) {
  $user = user_load(arg(1));
  $dashboard_link = substr(url('user/' . $user->uid . '/dashboard'),1);


 if (isset($form_state['input']['op']) && $form_state['input']['op'] == 'Message') {


    $queryArgs = array();
    $page_context = 'senators_constituents_tab';
    $uids = array_values($form_state['input']['list']);

    if ($form_state['input']['check_all'] == 1) {

      // to do: need to be able to message all constituents,
      // so an all_constituents filter needs to be added if no
      // queryArgs are present

      $queryArgs = nys_dashboard_senator_constituents_get_query_args($form_state['input']);

      if(empty($queryArgs)) {
        $queryArgs['all_constituents'] = true;
      }
      $queryArgs['context'] = $page_context;

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
    $dashboard_link . '/constituents',
    array(
      'query' => $queryArgs,
    ),
  );


}


function nys_dashboard_senators_constituents_table($form_state) {

  $user = user_load(arg(1));


  $limit = 10;

  if (isset($_REQUEST['page'])) {
    $start = $_REQUEST['page'] * $limit;
  }
  else {
    $start = 1 * $limit;
  }

  $data = nys_dashboard_constituents_query($form_state['input']);
  if(empty($data)) {
    drupal_set_message(t('Current User Must Have District Specified to See Constituents'));
    return;
  }
  $query = $data['query'];
  $queryArgs = $data['queryArgs'];

  $result = db_query_range($query, $start, $limit, $queryArgs);

  $rows = array();

  foreach($result as $r) {

    $output = "";


    if(!empty($r->first) && !empty($r->last)) {
      $name = $r->first . ' ' . $r->last;
    } else {
      $name = $r->name;
    }

    $name = theme('nys_dashboard_user_link', array('uid' => $r->uid));

    $facebook_verified = '';
    $city = !empty($r->city) ? $r->city : '';
    $zip_code = !empty($r->postal_code) ? $r->postal_code : '';



    $age_range = nys_dashboard_age_to_age_range($r->age);
    $gender =  strtoupper($r->gender);

    $facebook_verified = !empty($r->facebook_verified) ? '<a href="#" class="poll-facebook-share icon-after__facebook"></a>' : '';

    $columns = array(
      '<input class="row-checkbox" type="checkbox" name="list[' . $r->uid . ']" value="' . $r->uid . '">',
      array('data' => $name, 'class' =>'name'),
      array('data' => $facebook_verified, 'class' =>'verified'),
      array('data' => $city, 'class' =>'city'),
      array('data' => $zip_code, 'class' =>'zip'),
      array('data' => $age_range, 'class' =>'age'),
      array('data' => $gender, 'class' =>'gender'),
    );

    $rows[] = $columns;
  }

  $header = array("",
	  array('data' => "NAME", 'class' =>'name'),
		array('data' => "Verified", 'class' =>'verified'),
		array('data' => "City", 'class' =>'city'),
		array('data' => "Zip Code", 'class' =>'zip'),
		array('data' => "Age Range", 'class' =>'age'),
		array('data' => "Gender", 'class' =>'age'));

   $table = theme('table', array(
     'header' => $header,
     'rows' => $rows,
     'attributes' => array('width' => '100%', 'class' => array('stat-data'))
   ));

  $total_constituents_count = db_query($query, $queryArgs)->rowCount();

  pager_default_initialize($total_constituents_count, $limit, 0);

  $quantity = ceil(($total_constituents_count / $limit) + 1); // max number of pages, plus one

  if ($quantity > 5) {
    $quantity = 5;
  }

  $pager = "";

  if ($total_constituents_count > 10) {
    $pager = theme('pager',array('quantity'=> $quantity ,'tags' => array('<<','<','','>','>>')));
  }

  return '<div id="senator_constituents_table">' . $table . $pager . '</div>';
}

function nys_dashboard_constituent_age_ranges() {
  return array(
    'all' => t('All Ages'),
    '13-17' => '13-17',
    '18-39' => '18-39',
    '40-55' => '40-55',
    '56-69' => '56-69',
    '70-130' => '70+',
  );
}

/**
 * given an eage, return a textual output of the age range, in groups of five years
 */
function nys_dashboard_age_to_age_range($age = 0) {

  $age_ranges = nys_dashboard_constituent_age_ranges();
  unset($age_ranges['all']);

  if(empty($age)) {
    return '';
  }

  foreach($age_ranges as $key => $value) {
    $range = explode('-',$key);
    if($age >= $range[0] && $age <= $range[1]) {
      return $value;
    }
  }
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
