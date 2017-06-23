<?php
/**
 * @file
 * Master template theming file for NY Senate theme.
 */

require_once 'includes/views/preprocess.views.view_fields.inc';

/**
 * Implements hook_theme().
 */
function nysenate_theme() {
  return array(
    // The form ID.
    'user_profile_form' => array(
      // Forms always take the form argument.
      'arguments' => array('form' => NULL),
      'render element' => 'form',
      'template' => 'templates/user/user-profile-edit',
    ),
    'social_buttons' => array(
      'arguments' => array('vars' => array()),
      'template' => 'templates/social-buttons',
    ),
    'nysenate_event_date' => array(
      'variables' => array(
        'start_date' => NULL,
        'end_date' => NULL,
        'prefix' => 'c-event-date',
      ),
      'template' => 'templates/nysenate-event-date',
    ),
  );
}

function nysenate_date_combo($variables) {
  return theme('form_element', $variables);
}

/**
 * Implements template_preprocess_page
 *
  // example url is: 'http://domain.com/node/123/edit'
  // - page__node
  // - page__node__%
  // - page__node__123
  // - page__node__edit
  // - page__type_article
  // - page__type_article__%
  // - page__type_article__123
  // - page__type_article__edit
  //
  // Which connects to these templates:
  //
  // - page--node.tpl.php
  // - page--node--%.tpl.php
  // - page--node--123.tpl.php
  // - page--node--edit.tpl.php
  // - page--type-article.tpl.php          << this is what you want.
  // - page--type-article--%.tpl.php
  // - page--type-article--123.tpl.php
  // - page--type-article--edit.tpl.php
  //
  // Latter items take precedence.
 *
 */

function nysenate_preprocess_html(&$variables){
  // Add conditional stylesheets for IE
  // IE 9
  module_invoke('admin_menu', 'suppress');

  drupal_add_css(
    path_to_theme() . '/css/nysenate_ie9-blessed2.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 9',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE
    )
  );
  drupal_add_css(
    path_to_theme() . '/css/nysenate_ie9-blessed1.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 9',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE
    )
  );
  drupal_add_css(
    path_to_theme() . '/css/nysenate_ie9.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 9',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE
    )
  );
  // IE 8
  drupal_add_css(
    path_to_theme() . '/css/nysenate_ie8-blessed2.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lt IE 9',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE
    )
  );
  drupal_add_css(
    path_to_theme() . '/css/nysenate_ie8-blessed1.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lt IE 9',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE
    )
  );
  drupal_add_css(
    path_to_theme() . '/css/nysenate_ie8.css',
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lt IE 9',
        '!IE' => FALSE
      ),
      'preprocess' => FALSE
    )
  );

  if(drupal_is_front_page()) {
   $homepage_hero_content_type = (string) db_query("SELECT n.type FROM nodequeue_nodes nn JOIN node n ON n.nid = nn.nid WHERE nn.qid = 1 LIMIT 1;")->fetchField();
   if(!empty($homepage_hero_content_type)) {
     $variables['classes_array'][] = 'homepage-hero-content-type-' . $homepage_hero_content_type;
   }
  }

}

function nysenate_preprocess_page(&$variables) {

  // Init $node to avoid PHP errors.
  $node = '';

  if(arg(0) == 'taxonomy' && arg(1) == 'term') {
    $term = taxonomy_term_load(arg(2));
    if($term->vocabulary_machine_name == 'districts' && !empty($term->field_senator[LANGUAGE_NONE][0]['target_id'])) {
      $senator_node = node_load($term->field_senator[LANGUAGE_NONE][0]['target_id']);

      $variables['pallette_class'] = '';
      if(isset($senator_node->field_pallette_selector[LANGUAGE_NONE][0]['value']) && $senator_node->field_active[LANGUAGE_NONE][0]['value'] !== "0") {
        $variables['pallette_class'] = $senator_node->field_pallette_selector[LANGUAGE_NONE][0]['value'];
      } else {
        $variables['pallette_class'] = 'inactive-pallette';
      }
    }
  }

  if (isset($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__type__'. $variables['node']->type;
    // Add pallette variable
    $variables['pallette_class'] = '';
    // Check that the node is a senator type
    if (($node = menu_get_object())) {
      if($node->type === 'senator'){
        // This will expose $pallette in the page template.
        if(isset($node->field_pallette_selector[LANGUAGE_NONE][0]['value']) && $node->field_active[LANGUAGE_NONE][0]['value'] !== "0") {
          $variables['pallette_class'] = $node->field_pallette_selector[LANGUAGE_NONE][0]['value'];
        } else {
          $variables['pallette_class'] = 'inactive-pallette';
        }
      }
      else if(in_array($node->type, array('article', 'press_release', 'petition', 'questionnaire', 'initiative', 'in_the_news', 'event', 'video'))){
        $senator = entity_metadata_wrapper('node', $node)->field_senator->value();
        //Exposing variables for Senator full name, user name and hero image
        if(isset($senator)){
          $active_state = $senator->field_active[LANGUAGE_NONE][0]['value'];
          $variables['senator_url'] = drupal_get_path_alias( 'node/' . $senator->nid);
          $variables['senator_full_name'] = $senator->title;
          if ($active_state !== "0"){
            $variables['pallette_class'] = $senator->field_pallette_selector[LANGUAGE_NONE][0]['value'];
          }else{
            $variables['pallette_class'] = 'inactive-pallette';
          }
          if(!empty($senator->field_image_headshot[LANGUAGE_NONE][0]['uri'])) {
            $variables['senator_headshot'] = _nyss_img($senator->field_image_headshot[LANGUAGE_NONE][0]['uri'], '160x160');
          }
        }
      }
    }

    $term_links = array();
    if (isset($variables['node']->field_issues[LANGUAGE_NONE][0]['target_id'])) {
      foreach ($variables['node']->field_issues[LANGUAGE_NONE][0]['target_id'] as $term) {
        $term_links[] = l($term->tid, 'taxonomy/term/' . $term->tid,
          array(
            'attributes' => array(
              'title' => $term->tid
          )));
      }
    }

    $variables['node_issues'] = 'Releated Issues: ' . implode(', ', $term_links);
  }

  // if this is a panel page, add template suggestions
  if($panel_page = page_manager_get_current_page()) {
    $alias = current_path();
    $args = explode('/', $alias);
    if (!empty($args[1])) {
      $node = node_load($args[1]);
    }
    //Exposing variables for Senator full name, user name and hero image
    if (is_object($node) && $node->type == 'senator') {
      $senator = $node;
    } else if ($panel_page['name'] == 'node_view' && in_array($node->type, array('article', 'press_release', 'in_the_news'))) {
      if(!empty($node->field_senator[LANGUAGE_NONE][0]['entity'])) {
        $senator = $node->field_senator[LANGUAGE_NONE][0]['entity'];

      }
    }

    if(!empty($senator)) {
      $active_state = $senator->field_active[LANGUAGE_NONE][0]['value'];
      $variables['senator_url'] = drupal_get_path_alias( 'node/' . $senator->nid);
      $variables['senator_full_name'] = $senator->title;
      $variables['senator_headshot'] = _nyss_img($senator->field_image_headshot[LANGUAGE_NONE][0]['uri'], '160x160');
      // ensure your using the right pallette
      if ($active_state !== "0"){
        $variables['pallette_class'] = $senator->field_pallette_selector[LANGUAGE_NONE][0]['value'];
      }else{
        $variables['pallette_class'] = 'inactive-pallette';
      }
    }

    // add a generic suggestion for all panel pages
    $variables['theme_hook_suggestions'][] = 'page__panel';
    // add the panel page machine name to the template suggestions
    $variables['theme_hook_suggestions'][] = 'page__' . $panel_page['name'];
    if(arg(0) == 'taxonomy' && arg(1) == 'term') {
      $term = taxonomy_term_load(arg(2));
      $variables['theme_hook_suggestions'][] = 'page__term_view_' . $term->vocabulary_machine_name;
    }
    if($panel_page['name'] == 'node_view') {
      $variables['theme_hook_suggestions'][] = 'page__node_view';
    }
  }

  // Applies a few overrides to global search page for output customization
  if (arg(0) == 'search' && arg(1) == 'global') {
    if (!isset($variables['page']['content']['system_main']['search_results']['search_results'])) {
      $variables['page']['content']['current_search_standard']['#block']->subject = 'No Results Found&hellip;';
      $variables['page']['content']['system_main']['search_results']['#markup'] = '<div class="c-block-search-result--no-results">' . $variables['page']['content']['system_main']['search_results']['#markup'] . '</div>';
    }
    $search_query = strtoupper(arg(2));
    $variables['advanced_search_message'] = '';
    // If we detect user is searching for a bill/resolution, change advanced leg link message
    if (preg_match('/[ARJBCEKLSarjbcekls]\d{1,5}[A-Z]{0,2}/', $search_query)) {
      $variables['advanced_search_message'] = '<div class="c-block c-block-advanced-search-link"><a class="c-advanced-search--link icon-after__right" href="/search/legislation">To Find Legislation From Prior Sessions, Use Advanced Legislation Search</a></div>';
    }
  }
}

/**
 * Override or insert variables into the node template.
 */
function nysenate_preprocess_node(&$variables) {
  // Sets a variable for outputting a shorter version of the
  // senator's bio on Display Suite-powered search results.
  if ($variables['type'] == 'senator') {
    $search_summary = mb_strimwidth($variables['node']->body[LANGUAGE_NONE][0]['summary'], 0, 300);
    $search_summary = mb_strimwidth($search_summary, 0, strrpos($search_summary, ' ')) . ' &#8230;</p>';
    $variables['node']->body[LANGUAGE_NONE][0]['search_summary'] = $search_summary;
  }

  if (!empty($variables['field_senator'][0])) {
    $senator = $variables['field_senator'][0]['entity'];
    $variables['senator'] = $senator;
    $variables['senator_url'] = drupal_get_path_alias( 'node/' . $senator->nid);
    $variables['senator_full_name'] = $senator->title;
    $variables['senator_headshot'] = _nyss_img($senator->field_image_headshot[LANGUAGE_NONE][0]['uri'], '160x160');
  }
  else {
    $variables['senator'] = '';
    $variables['senator_url'] = '';
    $variables['senator_full_name'] = '';
    $variables['senator_headshot'] = '';
  }

  if (!empty($variables['field_article_author'][0]['#markup'])) {
    $author = $variables['field_article_author'][0]['#markup'];
    if ($author == $variables['senator_full_name']) {
      $variables['author'] = l($variables['senator_full_name'], $variables['senator_url']);
    }
    else {
      $variables['author'] = $author;
    }
  }
  elseif (!empty($variables['senator'])) {
    $variables['author'] = l($variables['senator_full_name'], $variables['senator_url']);
  }
  else {
    $variables['author'] = FALSE;
  }

  if ($variables['type'] == 'questionnaire' && !empty($variables['field_webform'][0]['entity']->nid)) {
    $webform = node_load($variables['field_webform'][0]['entity']->nid);
    $node_view = node_view($webform);
    $rendered_node = drupal_render($node_view);
    $variables['embedded_webform'] = $rendered_node;
  }

  if ($variables['type'] === 'press_release') {
    // OG Tags
    $full_url = drupal_get_path_alias('node/'.$variables['nid']);
    $og_url = array('#tag' => 'meta', '#attributes' => array('property' => 'og:url','content' => url($variables['node_url'])));
    $og_type = array('#tag' => 'meta', '#attributes' => array('property' => 'og:type','content' => 'article'));
    $og_title = array('#tag' => 'meta', '#attributes' => array('property' => 'og:title','content' => $variables['title']));
    if (isset($variables['body'][0]['value'])) {
      $og_description = array('#tag' => 'meta', '#attributes' => array('property' => 'og:description','content' => $variables['body'][0]['value']));
    }
    $og_image = !empty($variables['field_image_main'][0]['uri']) ? array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:image',
        'content' => image_style_url('760x377', $variables['field_image_main'][0]['uri'])
        )
      )
    : NULL;

    drupal_add_html_head($og_url, 'og_url');
    drupal_add_html_head($og_type, 'og_type');
    drupal_add_html_head($og_title, 'og_title');
    if (isset($og_description) && !empty($og_description)) {
      drupal_add_html_head($og_description, 'og_description');
    }
    drupal_add_html_head($og_image, 'og_image');

  }

  if ($variables['type'] === 'meeting') {
    // Pull Agenda location and notes fields in the event of non-populated Meeting fields.
    if (empty($variables['body']) || empty($variables['field_meeting_location'])) {
      if (!empty($variables['field_meeting_agenda'])) {
        $emw = entity_metadata_wrapper('node', $variables['field_meeting_agenda'][0]['target_id']);
        if (empty($variables['body']) && $emw->__isset('field_ol_agenda_notes') && !empty($emw->field_ol_agenda_notes->value())) {
          $variables['body'][0]['value'] = $emw->field_ol_agenda_notes->value();
        }
        if (empty($variables['field_meeting_location']) && $emw->__isset('field_ol_agenda_location') && !empty($emw->field_ol_agenda_location->value())) {
          $variables['field_meeting_location'][0]['value'] = $emw->field_ol_agenda_location->value();
        }
      }
    }
  }

  /** --- Transcripts --- */

  if ($variables['type'] === 'transcript' &&
      isset($variables['field_ol_filename'][0]['value']) &&
      isset($variables['field_ol_transcript_type'][0]['value']) &&
      isset($variables['field_ol_session_type'][0]['value']) &&
      isset($variables['field_ol_publish_date'][0]['value'])) {
    $transcript_file_name = $variables['field_ol_filename'][0]['value'];
    $is_hearing = ($variables['field_ol_transcript_type'][0]['value'] === 'public_hearing');

    // Set a label indicating the type of transcript.
    $tx_type_field = ($is_hearing)
      ? t('Public Hearing')
      : check_plain(ucwords(strtolower($variables['field_ol_session_type'][0]['value'])));

    // Open Leg url paths for PDFs are different for hearings and transcripts.
    $ol_base_url         = variable_get("openleg_base_url");
    $transcript_base_url = $ol_base_url. '/pdf/' . (($is_hearing) ? 'hearings/' : 'transcripts/');

    // Trailing slash is needed in the pdf url.
    $variables['pdf_url'] = $transcript_base_url . $transcript_file_name . '/';
    $variables['transcript_title'] = $tx_type_field . ' - ' .
                                     format_date($variables['field_ol_publish_date'][0]['value']);
  }

  // for some reason $page not avaiable when node loaded in full content mode in panel page
  if($variables['page'] && empty($variables['title'])) {
    $variables['title'] = drupal_get_title();
  }

  /** --- Bills / Resolutions --- */

  if ($variables['type'] === 'bill') {
    // Set up the user's senator or the sponsor of the bill if user has no senator.
    if (user_is_logged_in()) {
      global $user;
      if (!user_is_out_of_state($user)) {
        $senator_nid = user_get_senator_nid($user);
        if (!empty($senator_nid) && is_numeric($senator_nid)) {
          $sen_emw = entity_metadata_wrapper('node', $senator_nid);
          if ($sen_emw->__isset('field_last_name') && !empty($sen_emw->field_last_name->value())) {
            $bill_widget_senator = 'Sen. ' . $sen_emw->field_last_name->value();
          }
        }
      }
      elseif (!empty($variables['field_ol_sponsor_name'][0]['value'])) {
        $bill_widget_senator = 'Sen. ' . ucfirst(strtolower($variables['field_ol_sponsor_name'][0]['value']));
      }
    }
    else {
      $bill_widget_senator = t('the sponsor of this bill');
    }

    // Prepare the markup for the post-vote message to the user.
    if (!empty($bill_widget_senator && user_is_logged_in())) {
      $variables['bill_widget_markup'] = t('Your <span class="bill-widget-sentiment">
      sentiment</span> has been shared with ') . $bill_widget_senator . t('. Thank you
      for participating.') . ' <a class="closer" href="#">X</a>';
    }
    else {
      $variables['bill_widget_markup'] = t('You must fill out the form below in order
      to support or oppose this bill.') . ' <a class="closer" href="#">X</a>';
    }

    $bill_nid = $variables['node']->nid;
    if (!empty($variables['field_ol_active_version'][0]['value'])) {
      $active_amendment_version = $variables['field_ol_active_version'][0]['value'];
    }
    else {
      $active_amendment_version = NULL;
    }

    $bill_wrapper = entity_metadata_wrapper('node', $bill_nid);

    $variables['bill_wrapper'] = $bill_wrapper;

    $bill_print_no = $bill_wrapper->field_ol_print_no->value();
    $bill_session_year = $bill_wrapper->field_ol_session->value();
    $bill_base_print_no = $bill_wrapper->field_ol_base_print_no->value();
    $variables['active_amendment_version'] = $active_amendment_version;
    $variables['is_substituted'] = FALSE;
    $sub_bill_versions = array();

    // Check if the bill has a substituted bill and load it if it does.
    if (!empty($bill_wrapper->field_ol_substituted_by->value())) {
      $sub_bill_base_print_no = $bill_wrapper->field_ol_substituted_by->value();
      $sub_bill_versions = nysenate_get_bill_versions($variables['type'], $sub_bill_base_print_no, $bill_session_year);
      if (!empty($sub_bill_versions)) {
        $variables['sub_bill_node'] = node_load(end($sub_bill_versions)['nid']);
        if (!empty($variables['sub_bill_node'])) {
          $variables['is_substituted'] = TRUE;
          $variables['sub_bill_base_print_no'] = $sub_bill_base_print_no;
        }
      }
    }

    ctools_include('object-cache');
    ctools_object_cache_set('is_bill_substituted', 'is_substituted_' . arg(1), $variables['is_substituted']);

    $info_status = field_info_field('field_ol_last_status');
    $status_list = $info_status['settings']['allowed_values'];

    $variables['bill_session_year'] = $bill_session_year;

    $i = array_search($bill_wrapper->field_ol_last_status->value(), array_keys($info_status['settings']['allowed_values']));
    $variables['status_value'] = $i;
    $variables['status_allowed_values'] = $status_list;
    $variables['last_status'] = $status_list[$variables['field_ol_last_status'][0]['value']];

    $amended_versions_result = nysenate_amended_versions($bill_wrapper);
    $variables['amended_version_ids'] = $amended_versions_result;
    $variables['amended_versions'] = nysenate_render_amended_versions_dd($amended_versions_result);

    $variables['amendments'] = array();
    foreach($amended_versions_result as $r) {
      $variables['amendments'][$r['title']] = node_load($r['nid']);
      // Query for Quotes
      // Loops over amendments, and finds featured legislation quote, if it exists
      $quote_query = db_select('field_data_field_featured_quote', 'fq');
      $quote_query->leftJoin('field_collection_item', 'fc', 'fq.entity_id = fc.item_id');
      $quote_query->leftJoin('field_data_field_featured_legislation', 'fl', 'fc.item_id = fl.field_featured_legislation_value');
      $quote_query->leftJoin('field_data_field_featured_bill', 'fb', 'fb.entity_id = fl.field_featured_legislation_value');
      $quote_query->leftJoin('node', 'n', 'n.nid = fl.entity_id');
      $quote_query->addField('fq', 'field_featured_quote_value', 'quote');
      $quote_query->condition('fq.entity_type', 'field_collection_item', '=');
      $quote_query->condition('fq.bundle', 'field_featured_legislation', '=');
      $quote_query->condition('fb.bundle', 'field_featured_legislation');
      if (isset($variables['amendments'][$r['title']]->field_ol_sponsor[LANGUAGE_NONE][0]['target_id'])) {
        $quote_query->condition('n.nid', $variables['amendments'][$r['title']]->field_ol_sponsor[LANGUAGE_NONE][0]['target_id'], '=');
      }
      $quote_query->condition('fb.field_featured_bill_target_id', $variables['amendments'][$r['title']]->nid, '=');
      $quote_query->condition('fl.bundle', 'senator', '=');
      $variables['amendments'][$r['title']]->quote_text = $quote_query->execute()->fetchField();
    }

    // Setup the bill statuses.
    $frontend_statuses = array(
      array(
        "value" => 0,
        "name"  => "Introduced"
      ),
      array(
        "value" => 1,
        "name"  => "In Committee"
      ),
      array(
        "value" => 2,
        "name"  => "On Floor Calendar"
      ),
      array(
        "value" => 3,
        "name"  => "Passed Senate",
        "type"  => "senate"
      ),
      array(
        "value" => 3,
        "name"  => "Passed Assembly",
        "type"  => "assembly"
      ),
      array(
        "value" => 4,
        "name"  => "Delivered to Governor"
      ),
      array(
        "value" => 5,
        "name"  => "Signed/Vetoed by Governor"
      ),
    );

    $backend_statuses_to_values = array(
      "INTRODUCED"       => array(0, 0),
      "IN_ASSEMBLY_COMM" => array(1, 1),
      "IN_SENATE_COMM"   => array(1, 1),
      "ASSEMBLY_FLOOR"   => array(2, 2),
      "SENATE_FLOOR"     => array(2, 2),
      "PASSED_ASSEMBLY"  => array(3, 4),
      "PASSED_SENATE"    => array(3, 3),
      "DELIVERED_TO_GOV" => array(4, 5),
      "SIGNED_BY_GOV"    => array(5, 6),
      "VETOED"           => array(5, 6),
      "STRICKEN"         => array(-1,-1),
      "LOST"             => array(-1,-1),
      "SUBSTITUTED"      => array(-1,-1),
      "ADOPTED"          => array(-1,-1)
    );

    if ($variables['is_substituted']) {
      $current_status = $variables['sub_bill_node']->field_ol_last_status[LANGUAGE_NONE][0]['value'];
      $variables['current_status_chamber'] = $variables['sub_bill_node']->field_ol_chamber[LANGUAGE_NONE][0]["value"];
      $variables['current_all_statuses'] = $variables['sub_bill_node']->field_ol_all_statuses[LANGUAGE_NONE][0]['value'];
    }
    else {
      $current_status = $bill_wrapper->field_ol_last_status->value();
      $variables['current_status_chamber'] = $bill_wrapper->field_ol_chamber->value();
      $variables['current_all_statuses'] = $bill_wrapper->field_ol_all_statuses->value();
    }
    $current_status_value = $backend_statuses_to_values[$current_status][0];

    // Get the current legislative cycle for the bill.
    $legislative_session = intval($bill_wrapper->field_ol_session->value());
    if (!empty($legislative_session)) {

      // The odd numbered year needs to be the first year in the legislative cycle to match Senate procedure.
      if (($legislative_session % 2) > 0) {
        $curr_leg_cycle = $legislative_session . '-' . ($legislative_session + 1);
      }
      else {
        $curr_leg_cycle = ($legislative_session - 1) . '-' . $legislative_session;
      }
    }

    // Set the variable for passing to template if it exists.
    if (isset($curr_leg_cycle)) {
      $variables['current_legislative_cycle'] = t($curr_leg_cycle);
    }

    // Show if the bill has been signed or vetoed if it's reached the governor.
    $signed_or_vetoed = "Signed/Vetoed by Governor";
    if ($current_status == "SIGNED_BY_GOV") {
      $signed_or_vetoed = "Signed by Governor";
    } else if ($current_status == "VETOED") {
      $signed_or_vetoed = "Vetoed by Governor";
    }
    $frontend_statuses[6]["name"] = $signed_or_vetoed;

    // Wrap Committee in a link if it is a Senate committee.
    $variables['com_status_prefix'] = '';
    if ($bill_wrapper->field_ol_last_status->value() == 'IN_SENATE_COMM') {
      $committee_bill_details = 'Senate ' . $bill_wrapper->field_ol_latest_status_committee->value();
      $variables['com_status_prefix'] = l(t($committee_bill_details), '/committees/' . drupal_html_class($bill_wrapper->field_ol_latest_status_committee->value()));
    }
    elseif ($bill_wrapper->field_ol_last_status->value() == 'IN_ASSEMBLY_COMM') {
      $committee_bill_details = 'Assembly ' . $bill_wrapper->field_ol_latest_status_committee->value();
      $variables['com_status_prefix'] = $committee_bill_details;
    }

    // Build actions list, including subsituted actions if applicable
    $actions = drupal_json_decode($bill_wrapper->field_ol_all_actions->value());
    $actions = $actions['items'];
    $grouped_actions = array();
    // Mark the actions from this bill as the original actions
    foreach ($actions as &$action) {
      $action['orig'] = TRUE;
    }
    if ($variables['is_substituted']) {
      // If the bill was subsititued, add the subbed bill's actions from the point of subsitution.
      $sub_actions = drupal_json_decode($variables['sub_bill_node']->field_ol_all_actions[LANGUAGE_NONE][0]['value']);
      $action_text_to_find = 'SUBSTITUTED FOR';
      $action_text_to_find_len = strlen($action_text_to_find);
      $from_index = 0;
      foreach ($sub_actions['items'] as $i => $v) {
        if (substr($v['text'], 0, $action_text_to_find_len) === $action_text_to_find) {
          $from_index = $i;
          break;
        }
      }
      $actions = array_merge($actions, array_slice($sub_actions['items'], $from_index));
    }
    // Sort by reverse chronological date and group by base print no -> version -> date
    $actions = array_reverse($actions);
    $variables['actions_count'] = count($actions);
    foreach ($actions as &$action) {
      $basePrintNo = $action['billId']['basePrintNo'];
      $version = $action['billId']['version'];
      $date = $action['date'];
      if (!isset($grouped_actions[$basePrintNo])) {
        $grouped_actions[$basePrintNo] = array();
      }
      if (!isset($grouped_actions[$basePrintNo][$version])) {
        $grouped_actions[$basePrintNo][$version] = array();
      }
      if (!isset($grouped_actions[$basePrintNo][$version][$date])) {
        $grouped_actions[$basePrintNo][$version][$date] = array();
      }
      array_push($grouped_actions[$basePrintNo][$version][$date], $action);
    }
    $variables['grouped_actions'] = $grouped_actions;

    // Create an array containing node ids / print nos for same as bills
    $same_as_billids = json_decode($bill_wrapper->field_ol_same_as->value());
    $same_as = array();
    foreach ($same_as_billids as $billid) {
      $same_as_bill_query = new EntityFieldQuery();
      $same_as_bill_result = $same_as_bill_query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'bill')
        ->fieldCondition('field_ol_session', 'value', $billid->session)
        ->fieldCondition('field_ol_print_no', 'value', $billid->printNo)
        ->range(0,1)
        ->execute();
      if (isset($same_as_bill_result['node'])) {
        $same_as[] = array(
          'nid' => array_keys($same_as_bill_result['node'])[0],
          'print_no' => $billid->printNo,
        );
      }
    }
    $variables['same_as'] = $same_as;

    // Initialize previous version data points.
    $variables['previous_versions_multiyear'] = NULL;
    $variables['previous_versions'] = NULL;

    // Print out previous versions of bill if there are any.
    $previous_versions = drupal_json_decode($bill_wrapper->field_ol_previous_versions->value());

    if (!empty($previous_versions)) {
      $prev_vers_array = array();
      foreach ($previous_versions as $index => $prev_vers) {
        // Check to see what year the legislative session is in.
        $prev_vers_session = $prev_vers['session'];

        if (is_int($prev_vers_session)) {
          // The odd numbered year needs to be the first year in the legislative cycle to match Senate procedure.
          if (($prev_vers_session % 2) > 0) {
            $prev_leg_session = $prev_vers_session . '-' . ($prev_vers_session + 1);
          }
          else {
            $prev_leg_session = ($prev_vers_session - 1) . '-' . $prev_vers_session;
          }
        }
        // Set up links for bills in each legislative session.
        $prev_vers_printno = $prev_vers['printNo'];
        $prev_vers_query = new EntityFieldQuery();
        $prev_vers_result = $prev_vers_query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'bill')
          ->fieldCondition('field_ol_session', 'value', $prev_vers_session)
          ->fieldCondition('field_ol_print_no', 'value', $prev_vers_printno)
          ->range(0,1)
          ->execute();
        if (isset($prev_vers_result['node'])) {
          $prev_vers_array[$prev_leg_session][$prev_vers_printno] = l(t($prev_vers_printno), '/' . drupal_get_path_alias('node/' . array_keys($prev_vers_result['node'])[0]));
        }
      }
      // Check for values in the Same As field for opposite chamber versions.
      $same_as_version = drupal_json_decode($bill_wrapper->field_ol_same_as->value());

      if (!empty($same_as_version)) {
        $same_as_session = $same_as_version[0]['session'];
        $same_as_printno = $same_as_version[0]['printNo'];

        // Query the database for previous versions of opposite chamber bills.
        if (is_int($same_as_session) && isset($same_as_printno)) {
          $query = db_select('field_data_field_ol_previous_versions', 'f');

          $query->join('node', 'n', 'f.entity_id = n.nid');
          $query->join('field_data_field_ol_session', 's', 'n.nid = s.entity_id');

          // Cross-reference node title with session to get previous versions.
          $query->fields('f', array('field_ol_previous_versions_value'))
            ->condition('f.bundle', 'bill')
            ->condition('f.deleted', 0)
            ->condition('n.title', strtoupper($same_as_printno))
            ->condition('n.status', 1)
            ->condition('s.field_ol_session_value', $same_as_session)
            ->range(0, 1);

          $result = $query->execute();
          $same_as_prev_versions = $result->fetchAssoc();

          $same_as_prev_array = drupal_json_decode($same_as_prev_versions['field_ol_previous_versions_value']);

          foreach ($same_as_prev_array as $prev_add_array) {
            $same_prev_session = $prev_add_array['session'];
            $same_prev_printno = $prev_add_array['printNo'];

            if (is_int($same_prev_session)) {
              // The odd numbered year needs to be the first year in the legislative cycle to match Senate procedure.
              if (($same_prev_session % 2) > 0) {
                $same_leg_session = $same_prev_session . '-' . ($same_prev_session + 1);
              }
              else {
                $same_leg_session = ($same_prev_session - 1) . '-' . $same_prev_session;
              }

              $same_prev_query = new EntityFieldQuery();
              $same_prev_result = $same_prev_query->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', 'bill')
                ->fieldCondition('field_ol_session', 'value', $same_prev_session)
                ->fieldCondition('field_ol_print_no', 'value', $same_prev_printno)
                ->range(0,1)
                ->execute();
              if (isset($same_prev_result['node'])) {
                $prev_vers_array[$same_leg_session][$same_prev_printno] = l(t($same_prev_printno), '/' . drupal_get_path_alias('node/' . array_keys($same_prev_result['node'])[0]));
              }
            }
          }
        }
      }

      // Create variable array for bills in legislative sessions.
      foreach ($prev_vers_array as $index => $prev_leg) {
        $variables['previous_versions'][$index] = implode(', ', $prev_leg);
      }

      $variables['prev_vers_prefix'] = t('Versions Introduced in Previous Legislative Sessions:');

      if (count($prev_vers_array) == 1 && $variables['previous_versions'] != NULL && is_array($variables['previous_versions']) ) {
        $variables['prev_vers_prefix'] = t('Versions Introduced in ' . key($variables['previous_versions']) . ' Legislative Session:');
      }
      else {
        $variables['previous_versions_multiyear'] = '<dt></dt>';
      }

      if (count($prev_vers_array, COUNT_RECURSIVE) == 1) {
        $variables['prev_vers_prefix'] = t('Version Introduced in ' . key($variables['previous_versions']) . ' Legislative Session:');
      }

      $previous_versions_info = array();
      $previous_versions_info['previous_versions_multiyear'] = $variables['previous_versions_multiyear'];
      $previous_versions_info['prev_vers_prefix'] = $variables['prev_vers_prefix'];
      $previous_versions_info['previous_versions'] = $variables['previous_versions'];
    }
    else {
      $previous_versions_info = array();
    }

    // If the bill has passed it's house's floor vote and gone back to the other houses committee,
    // show the last status as passing the bill's house.
    if (
      ($current_status_value == 1  || $current_status_value == 2) &&
      ($variables['current_status_chamber'] == 'senate' && strrpos($variables['current_all_statuses'], 'PASSED_SENATE') !== false)
      ) {
      $current_status       = "PASSED_SENATE";
      $current_status_value = $backend_statuses_to_values[$current_status][0];
    } else if (
      ($current_status_value == 1  || $current_status_value == 2) &&
      ($variables['current_status_chamber'] == 'assembly' && strrpos($variables['current_all_statuses'], 'PASSED_ASSEMBLY') !== false)
      ) {
      $current_status       = "PASSED_ASSEMBLY";
      $current_status_value = $backend_statuses_to_values[$current_status][0];
    }

    $variables["frontend_statuses"]    = $frontend_statuses;
    $variables["current_status_value"] = $current_status_value;
    $variables["current_status_name"]  = ($current_status_value >= 0) ? $frontend_statuses[$backend_statuses_to_values[$current_status][1]]['name'] : $current_status;
    $variables["passed_other_house"]   = $variables['current_status_chamber'] == 'senate' ? strrpos($variables['current_all_statuses'], 'PASSED_ASSEMBLY') !== false : strrpos($variables['current_all_statuses'], 'PASSED_SENATE') !== false;

    // This block has been converted from code in node--bill.tpl.php

    $variables['current_year'] = variable_get('nys_session_year');
    $variables['current_session_year'] = $variables['current_year'] - (1 - $variables['current_year'] % 2);
    $variables['show_status'] = false;


    // Show status tag?
    if ($variables['current_session_year'] == $bill_wrapper->field_ol_session->value()) {
      // Show the status no matter within the current session.
      $variables['show_status'] = true;
    }
    else if ($bill_wrapper->field_ol_last_status->value() == 'SIGNED_BY_GOV') {
      // Outside of the current session, only show signed or vetoed status.
      $variables['show_signed_status'] = true;
    }

    switch (strtolower($variables["current_status_name"])) {
      case 'signed by governor':
        $variables['signed_veto_status'] = '<span class="c-bill--flag">Signed By Governor</span>';
        break;
      case 'vetoed by governor':
        $variables['signed_veto_status'] = '<span class="c-bill--flag">Vetoed By Governor</span>';
        break;
      default:
        $variables['signed_veto_status'] = '';
        break;
    }

    $variables['session_year'] = $bill_wrapper->field_ol_session->value();
    $variables['legislative_session'] = '<div class="c-bill--session-year">' . $variables['session_year'] . '-' . ($variables['session_year'] + 1) . ' Legislative Session</div>';

    $variables['active_amend_url'] = $GLOBALS['base_url'].'/legislation/bills/' . $bill_wrapper->field_ol_session->value() . '/' . $bill_wrapper->field_ol_base_print_no->value();
    $variables['ol_base_url'] = variable_get('openleg_base_url');

    // Get the rendered sponsor block.
    $variables['sponsored_by'] = _nysenate_render_bill_sponsor_list($bill_wrapper);

    // Build Bill Status Content Section
    $bill_status_graph = nys_dashboard_render_bill_status($bill_nid, '', true);
    $variables['bill_status_graph'] = $bill_status_graph->graph_html;
    $variables['bill_display_status'] = $bill_status_graph->display_status;

    // Process Actions for Output
    $variables['actions_table'] = '';
    foreach ($grouped_actions as $base_print_no => &$versions) {
      foreach ($versions as $version => &$dates) {
        foreach ($dates as $date => &$items) {
          $variables['actions_table'] .= '
          <tr class="cbill--actions-table--row">
            <td class="c-bill--actions-table-col1">' . date('M d, Y', strtotime($date)) . '</td>
            <td class="c-bill--actions-table-col2">';
          foreach ($items as $i => &$item) {
            // The logic contained here helps define classes for action line items.
            switch ($item['chamber']) {
              case('SENATE'):
                $line_item_class = 'c-bill--action-line-senate';
                break;
              case('ASSEMBLY'):
                $line_item_class = 'c-bill--action-line-assembly';
                break;
            }
            switch (true) {
              case(stristr(strtolower($item['text']), 'substituted by')):
                $line_item_class .= ' substituted';
                break;
              case(stristr(strtolower($item['text']), 'amended') || stristr(strtolower($item['text']), 'print number')):
                $line_item_class .= ' amended';
                break;
              case(stristr(strtolower($item['text']), 'stricken')):
                $line_item_class .= ' stricken';
                break;
            }
            $variables['actions_table'] .= '<span class="' . $line_item_class . '">' . check_plain(strtolower($item['text'])) . '</span><br />';
          }
          $variables['actions_table'] .= '</td></tr>';
        }
      }
    }

    // Build Vote Block Output
    $votes_render = module_invoke('nys_blocks', 'block_view', 'bill_detail_votes', 'node', $bill_nid);
    $variables['votes_block'] = $votes_render['content'];

    // Generate Views Blocks
    $variables['view_related_bills'] = views_get_view('bill_related_content');
    $variables['view_related_bills']->set_display('related_bills');
    $variables['view_related_bills']->pre_execute();
    $variables['view_related_bills']->execute();

    $variables['view_bill_related_issues'] = views_get_view('bill_related_content');
    $variables['view_bill_related_issues']->set_display('bill_related_issues');
    $variables['view_bill_related_issues']->pre_execute();
    $variables['view_bill_related_issues']->execute();

    $variables['view_related_content'] = views_get_view('bill_related_content');
    $variables['view_related_content']->set_display('related_content');
    $variables['view_related_content']->pre_execute();
    $variables['view_related_content']->execute();

    $variables['amendments_block'] = _nysenate_render_bill_amendments($variables['amendments'], $base_print_no, $bill_wrapper, $same_as, $previous_versions_info, $active_amendment_version);

    //print_r($variables['amendments']); exit();
  }

  if ($variables['type'] == 'resolution') {
    // Get a wrapper for the current node.
    $bill_nid = $variables['node']->nid;
    $bill_wrapper = entity_metadata_wrapper('node', $bill_nid);
    $chamber = $bill_wrapper->field_ol_chamber->value();

    // Get the rendered sponsor block.
    $variables['sponsored_by'] = _nysenate_render_bill_sponsor_list($bill_wrapper);

    // Build multi/co-sponsor blocks
    $sponsor_array = _nysenate_resolve_amendment_sponsors(node_load($bill_nid), $chamber);
    $variables['sponsor_block'] = '';
    if (count($sponsor_array['co']) || count($sponsor_array['multi'])) {
      $variables['sponsor_block'] = _nysenate_render_bill_amendment_sponsors(
        $sponsor_array, $bill_nid, $chamber
      );
    }
  }

   // important to only load these in full view_mode, or else you can get duplicates
   // on certain content types that use the same template for teaser and full view_modes
  if($variables['view_mode'] == 'full') {
    $full_node_url = $GLOBALS['base_url'] . $variables['node_url'];
    $content_type = str_replace('_', ' ', $variables['type']);
    $social_share_vars = array(
      'social_share_title' => 'share this ' . $content_type,
      'node_url' => $full_node_url,
      'title' => $variables['title'],
      'CTA' => 'Check out this ' . $content_type,
    );

    if(in_array($variables['type'], array('webform', 'page_content'))) {
      $social_share_vars['social_share_title'] = 'share this page';
      $social_share_vars['CTA'] = 'Check out this page';
    }

    if(in_array($variables['type'], array('student_program', 'in_the_news'))) {
      $social_share_vars['social_share_title'] = 'share this article';
      $social_share_vars['CTA'] = 'Check out this article';
    }

    if(in_array($variables['type'], array('open_data'))) {
      $social_share_vars['social_share_title'] = 'share this open data report';
      $social_share_vars['CTA'] = 'Check out this open data report';
    }



    if(arg(0) == 'node' && $variables['nid'] == arg(1)) { // don't show on embedded nodes, such as webform embedded within questionnaire
      $variables['social_buttons'] = theme('social_buttons', $social_share_vars);
    }

  }

  $variables['isSenateUser'] = module_invoke('nys_wtis', 'is_internal');

  return $variables;
}


function nysenate_preprocess_taxonomy_term(&$variables) {
  if ($variables['vocabulary_machine_name'] === 'districts'){
    //var_dump($variables['field_senator'][LANGUAGE_NONE][0]['value']);exit;
    if($variables['field_sage_data']) {
      $sage_data = unserialize($variables['field_sage_data'][0]['value']);
      // var_dump($sage_data);exit;
      $variables['offices'] = '';
      if ($sage_data->offices){
        $variables['offices'] = $sage_data->offices;
      }
    }
  }
  //var_dump($variables);exit;
  return $variables;
}

/**
 * Implements theme_links() targeting the secondary menu specifically.
 * Formats links for Top Bar http://foundation.zurb.com/docs/components/top-bar.html
 */
function nysenate_links__topbar_secondary_menu($variables) {
  // We need to fetch the links ourselves because we need the entire tree.
  $links = menu_tree_output(menu_tree_all_data(variable_get('menu_secondary_links_source', 'user-menu')));
  $output = _zurb_foundation_links($links);
  $variables['attributes']['class'] = 'f-dropdown';
  $variables['attributes']['id'] = 'account_settings';

  return '<ul' . drupal_attributes($variables['attributes']) . ' data-dropdown-content>' . $output . '</ul>';
}


function nysenate_preprocess_block(&$variables) {
  if($variables["block_html_id"] == "block-menu-menu-senator-s-microsite-menu"){
    $index = strpos($variables["content"],">");
    $variables["content"] = substr($variables["content"], $index+1);
    $variables["content"]= str_replace("</ul>","",$variables["content"]);
  }
}

/**
 * Implements hook_ds_pre_render_alter
 **/

function nysenate_ds_pre_render_alter(&$layout_render_array, $context, &$vars) {
  /*
   * Templates to have a pre-render bill graph applied are listed here
   * in this array.  When adding a new DS display, use the template name
   * as a guide.
   *
   * Replace all dashes (-) with an underscore (_).
   *
   * For example, the template "ds-1col--node-bill-search-index.tpl.php"
   * would receive the following array entry:
   *
   * array('node', 'bill', 'search_index')
   */

  $templates = array(
      array('node', 'bill', 'search_index', 'nys-bill-status__sml'),
      array('node', 'bill', 'bill_list_item', 'nys-bill-status__sml'),
      array('node', 'bill', 'node_embed', 'nys-bill-status__drk'),
      array('node', 'bill', 'node_embed_no_quote', 'nys-bill-status__drk')
  );

  $draw = false;

  foreach($layout_render_array['ds_content'] as $key => $layout) {
    foreach ($templates as $template) {
  
      if (
          (isset($layout['#entity_type']) && $template[0] == $layout['#entity_type']) &&
          (isset($layout['#bundle']) && $template[1] == $layout['#bundle']) &&
          (isset($layout['#view_mode']) && $template[2] == $layout['#view_mode'])
      ) {
        $node_to_lookup = $layout['#object']->nid;
        $bill_graph_output = nys_dashboard_render_bill_status($node_to_lookup, $template[3]);
        $vars['graph_html'] = $bill_graph_output->graph_html;
        $vars['display_status'] = $bill_graph_output->display_status;
        break;
      }
    }
  }
}


/**
 * Implements hook_html_head_alter().
 */
function nysenate_html_head_alter(&$head_elements) {
  // Override the value in parent theme.
  $head_elements['mobile_viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1',
    ),
  );
}

/**
 * Implementation of hook_views_post_render
 */


/**
 * Implements hook_views_pre_render
 */

function nysenate_views_pre_render(&$view) {

  /*
   * The templates listed in this array correspond to those that use a bill status graph.
   * Templates are listed in machine name and CSS class pairs.
   * When drawn, the graph and display status are sent to the template
   * and can be found within the $row->graph_html and $row->display_status.
   */

  $templates = array(
      array(
          'senator_featured_legislation_sub', 'nys-bill-status__drk'
      ),
      array(
          'senator_featured_legislation_main', 'nys-bill-status__drk'
      ),
      array(
          'senator_legislation_bills', 'nys-bill-status__sml'
      ),
      array(
          'related_bills', 'nys-bill-status__sml'
      ),
      array(
          'news_by_bill', 'nys-bill-status__sml'
      ),
      array(
          'constituent_updates', 'nys-bill-status__sml wrapper'
      ),
      array(
          'constituent_bills_voted_on', 'nys-bill-status__drk'
      ),
      array(
          'node_bill_search_index', 'nys-bill-status__sml'
      )
  );

  $draw = false;
  $draw_classes = '';
  $query = $view->query;
  $nid_field = 'nid';

  // Process through our array of Views templates that have bill graphs.
  // Basically, this avoids processing anything for templates that DON'T
  // have bill status graphs.
  foreach ($templates as $template) {
    if ($view->current_display == $template[0]) {
      $draw = true;
      $draw_classes = $template[1];
      break;
    }
  }

  if ($draw) {
    // Contextual search thru $view->query->fields for the field containing our Node ID
    foreach ($query->fields as $key => $item) {
      if ($item['field'] == 'nid') {
        $nid_field = $key;
        break;
      }
    }

    // Now, apply the bill graph to our results.  This will set up variables available to the
    // individual templates in order to display the data.
    foreach ($view->result as $result) {
      $bill_to_load = $result->$nid_field;
      $bill_graph_output = nys_dashboard_render_bill_status($bill_to_load, $draw_classes);

      $result->graph_html = $bill_graph_output->graph_html;
      $result->display_status = $bill_graph_output->display_status;
    }
  }

  return $view;
}


function _nysenate_render_sponsor_boilerplate($sponsor, $chamber) {
  $ret = '';
  switch ($chamber) {
    case 'assembly':
      $ret = '<div class="nys-senator sponsor-list">' .
        '<div class="nys-senator--thumb"></div>' .
        '<div class="nys-senator--info">' .
        '<h4 class="nys-senator--name">' . $sponsor->fullName . '</h4>' .
        '<p class="nys-senator--district"></p></div></div>';
      break;
    case 'senate':
      if ($sponsor->nodeId) {
        $this_node = node_load($sponsor->nodeId);
        if ($this_node) {
          $sponsor_list_view = node_view($this_node, 'sponsor_list_bill_detail');
          $ret = render($sponsor_list_view);
        }
      } else {
        $fields = array(array('title'=>'Sponsor Array', 'value'=>var_export($sponsor,1), 'short'=>true));
        nys_utils_send_slack_notification("A bill sponsor's member ID could not be matched to a node", $fields);
      }
      break;
  }
  return $ret;
}


/**
 * @param array $sponsors An array of sponsor objects
 * @param integer $node_id The node id of the amendment being rendered
 * @param string $chamber A specifier indicating 'senate' or 'assembly'
 * @return string The fully rendered HTML for the sponsor list.
 */
function _nysenate_render_bill_amendment_sponsors($sponsors, $node_id, $chamber) {
  // This section originally kept track of specific sponsors being displayed
  // by maintaining the sponsor node id's in an array.  It was refactored
  // to use a simple walking counter under the assumption that the sponsor
  // fields will not contain duplicate objects.

  // Initialize the return.
  $ret = '<div class="c-block c-detail--sponsors c-bill-section">';

  // Used for iteration, and to indicate part of the accordion id
  $sections = array('co' => 10, 'multi' => 11);

  foreach ($sections as $type => $idnum) {
    $the_count = count($sponsors[$type]);

    if ($the_count) {
      $ret .= '<div class="c-' . $type . '-sponsors c-sponsors-detail">' .
        '<h3 class="c-detail--subhead c-detail--section-title c-bill-detail--subhead">' .
        ucfirst($type) . '-Sponsors</h3>';

      // Render the first four in a preface block.
      $ret .= '<div class="initial_co-sponsors">';
      $i = 0;
      // Render the first four as traditional views.
      while ($i < $the_count && $i < 4) {
        $ret .= _nysenate_render_sponsor_boilerplate($sponsors[$type][$i], $chamber);
        $i++;
      }
      $ret .= '</div>';

      // Now render any remaining sponsors.
      if ($i < $the_count) {
        $ret .= '<div class="other_' . $type . '-sponsors">' .
          '<dl style="margin-bottom:0" class="c-block c-detail--actions accordion" ' .
          'data-accordion>' . '<dd class="accordion-navigation">' .
          '<a href="#accordion-' . $idnum . '-' . $node_id .
          '" class="accordion--btn nys-btn-more nys-btn-more--bg" ' .
          'data-open-text="hide additional ' . $type . '-sponsors" data-closed-text="view ' .
          'additional ' . $type . '-sponsors">view additional ' . $type . '-sponsors</a>' .
          '<div id="accordion-' . $idnum . '-' . $node_id . '" class="content">';
        while ($i < $the_count) {
          $ret .= _nysenate_render_sponsor_boilerplate($sponsors[$type][$i], $chamber);
          $i++;
        }
        $ret .= '</div></dd></dl></div>';
      }


      $ret .= '</div>';
    }

  }

  $ret .= '</div>';

  return $ret;
}

function _nysenate_resolve_amendment_sponsors($amendment, $chamber) {
  $ret = array();
  $cycle = array('co', 'multi');
  $senators = get_senator_name_mapping();
  foreach ($cycle as $type) {
    $ret[$type] = array();
    $propname = "field_ol_{$type}_sponsor_names";
    $sponsors = json_decode($amendment->{$propname}[LANGUAGE_NONE][0]['value']);
    foreach ($sponsors as $one_sponsor) {
      switch ($chamber) {
        case 'senate':
          $nodeid = nys_utils_get_senator_nid_from_member_id($one_sponsor->memberId);
          $ret[$type][] = (object) array(
            'memberId' => $one_sponsor->memberId,
            'nodeId' => $nodeid,
            'fullName' => $senators[$nodeid]['full_name'],
          );
          break;
        case 'assembly':
          $ret[$type][] = (object) array(
            'memberId' => NULL,
            'nodeId' => NULL,
            'fullName' => $one_sponsor->fullName,
          );
          break;
      }
    }
  }

  return $ret;
}

function _nysenate_render_bill_amendments($amendments, $base_print_no, &$bill_wrapper, $same_as, $previous_versions_info, $active_amendment_version) {
  $ol_base_url = variable_get("openleg_base_url");
  ob_start();

  foreach($amendments as $amendment):
    $version = str_replace($base_print_no, '', $amendment->title);
    ?>
    <div class="bill-amendment-detail content<?php
      print $bill_wrapper->label() === $amendment->title ? ' active': ''
      ?>" data-version="<?php print render($amendment->title); ?>">

      <!-- Amendment Details -->
      <!-- Quote Block -->
      <?php if (!empty($amendment->quote_text)) : ?>
      <div class="c-quote--content bill-sponsor-quote">
        <h4 class="c-quote--title">Sponsor's Position</h4>
        <p class="c-pullquote icon-before__quotes"><?php print $amendment->quote_text; ?></p>
        <?php
        $amendment_node = node_load($amendment->nid);
        $sponsor_pre_render = field_view_field('node', $amendment_node, 'field_ol_sponsor', 'Sponsor List');
        print render($sponsor_pre_render);
        ?>
        <button class="js-quote-toggle c-block--btn c-block--btn-toggle">close</button>
        <div class="c-social">
          <ul class="c-social--list">
            <li><a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=https://www.nysenate.gov/<?php print drupal_get_path_alias('node/' . $amendment->nid); ?>" class="icon-replace__facebook">facebook</a></li>
            <li><a target="_blank" href="http://twitter.com/share?url=https://www.nysenate.gov/<?php print drupal_get_path_alias('node/' . $amendment->nid); ?>" class="icon-replace__twitter">twitter</a></li>
          </ul>
        </div>
      </div>
      <?php endif; ?>

      <!-- Bill Co/Multi Sponsors -->
      <?php
      // This is a list of Assembly co-sponsors and multi-sponsors.
      $sponsors_array = _nysenate_resolve_amendment_sponsors($amendment, $bill_wrapper->field_ol_chamber->value());

      // For co- OR multi- sponsored bills
      if (count($sponsors_array['co']) || count($sponsors_array['multi'])) {
        print _nysenate_render_bill_amendment_sponsors(
          $sponsors_array,
          $amendment->nid,
          $bill_wrapper->field_ol_chamber->value()
        );
      }
      ?>

      <!-- Bill Amendment Details -->
      <div class="c-block c-bill-section c-bill--details" style="margin-bottom:30px;">
        <h3 class="c-detail--subhead c-detail--section-title"><?php print render($amendment->title); ?> <?php print $version === $active_amendment_version ? ' (ACTIVE)' : '' ?> - Details</h3>
        <dl>
          <?php
          if ($same_as):
            if (count($same_as) > 1):
              $same_bills = t('See other versions of this Bill:');
            elseif (isset($same_as[0]['print_no']) && strtoupper($same_as[0]['print_no'][0]) == 'S'):
              $same_bills = t('See Senate Version of this Bill:');
            elseif (isset($same_as[0]['print_no']) && strtoupper($same_as[0]['print_no'][0]) == 'A'):
              $same_bills = t('See Assembly Version of this Bill:');
            else:
              $same_bills = t('See Version in other house:');
            endif;
          ?>
          <dt><?php print $same_bills; ?></dt>
          <?php
            $first = TRUE;
            foreach($same_as as $bill_id):
          ?>
          <dd>
          <?php
              if ($first):
                $first = FALSE;
              else:
                print ",";
              endif;
          ?>
            <a href="/<?php print drupal_get_path_alias('node/' . $bill_id['nid']) ?>"><?php
              print $bill_id['print_no']; ?></a>
          </dd>
          <?php
            endforeach;
          endif;

          if ($bill_wrapper->field_ol_latest_status_committee->value()) :
            $term = taxonomy_get_term_by_name($bill_wrapper->field_ol_latest_status_committee->value(), 'committees');
            $path = '';
            if (!empty($term)) {
              $path = drupal_get_path_alias('taxonomy/term/'.reset($term)->tid);
            }
          ?>
          <?php if (isset($com_status_prefix) && !empty($path)): ?>
          <dt>Current Committee:</dt>
          <dd><?php print $com_status_prefix; ?></dd>
          <?php
          endif;
          endif;

          if ($bill_wrapper->field_ol_law_section->value()):
          ?>
          <dt>Law Section:</dt>
          <dd><?php print $bill_wrapper->field_ol_law_section->value();?></dd>
          <?php
          endif;

          if($bill_wrapper->field_ol_law_code->value()) :
          ?>
          <dt>Laws Affected:</dt>
          <dd><?php print $bill_wrapper->field_ol_law_code->value();?></dd>
          <?php
          endif;

          if (!empty($previous_versions_info['previous_versions'])):
          ?>
          <dt><?php print $previous_versions_info['prev_vers_prefix']; ?></dt>
          <dd>
          <?php
            foreach ($previous_versions_info['previous_versions'] as $leg_session => $prev_bills):
              if (!empty($previous_versions_info['previous_versions_multiyear'])):
                print $leg_session . ': ';
              endif;
              print $prev_bills . '<br />';
            endforeach;
          ?>
           </dd>
          <?php
          endif;
          ?>
        </dl>
      </div>

      <!-- Bill Texts -->
      <div class="c-block c-bill-section" id="panel-text">
        <!-- Summary -->
        <?php
        if ($amendment->field_ol_summary[LANGUAGE_NONE][0]['value'] != ''):
          $summary_show_expander = preg_match_all('/;/', $amendment->field_ol_summary[LANGUAGE_NONE][0]['value']) > 3 ? true : false;
          if ($summary_show_expander) {
            $amendment_text = str_split_at_nth($amendment->field_ol_summary[LANGUAGE_NONE][0]['value'], ';', 3);
          }
          else {
            $amendment_text['part_1'] = $amendment->field_ol_summary[LANGUAGE_NONE][0]['value'];
            $amendment_text['part_2'] = '';
          }
        ?>
        <div class="c-bill-text__summary">
          <a name="summary-text-top"></a>
          <h3 class="c-detail--subhead c-detail--section-title"><?php print render($amendment->title); ?> <?php print $version === $active_amendment_version ? ' (ACTIVE)' : '' ?> -  Summary</h3>
          <div id="summary-<?php print $bill_wrapper->label(); ?>">
            <div class="c-block c-detail--summary c-bill-section">
              <p>
              <?php
                print trim($amendment_text['part_1']);
                if ($summary_show_expander) {
                  echo '<span class="u-inline-expand-ellipsis">&hellip;</span>';
                  echo '&nbsp;<a style="cursor:pointer;" class="u-text-expander--inline">(view more)</a>';
                  echo '<span class="u-text-expander--inline__more-text">' . $amendment_text['part_2'] . '</span>';
                }
                ?>
              </p>
            </div>
          </div>
        </div>
        <?php endif; ?>
      </div>

      <!-- Sponsor Memo -->
      <?php
      if ($amendment->field_ol_memo[LANGUAGE_NONE][0]['value'] != ''):
        $sponsor_memo_show_expander = preg_match_all('/\n/', $amendment->field_ol_memo[LANGUAGE_NONE][0]['value']) > 25 ? true : false;
        if ($sponsor_memo_show_expander) {
          $amendment_text = str_split_at_nth($amendment->field_ol_memo[LANGUAGE_NONE][0]['value'], chr(10), 25);
        }
        else {
          $amendment_text['part_1'] = $amendment->field_ol_memo[LANGUAGE_NONE][0]['value'];
          $amendment_text['part_2'] = '';
        }
      ?>
      <div class="c-bill-text__memo" style="clear:both;">
        <a name="memo-text-top"></a>
        <h3 class="c-detail--subhead c-detail--section-title">
      <?php
        print render($amendment->title);
        print $version === $active_amendment_version ? ' (ACTIVE)' : ''
      ?> - Sponsor Memo</h3>
        <div id="sponsor-memo-<?php print $bill_wrapper->label(); ?>" class="c-text--preformatted">
          <div class="c-detail--memo">
            <pre class="c-bill-fulltext"><?php print $amendment_text['part_1']; ?></pre>
          </div>
      <?php
        if ($sponsor_memo_show_expander) {
      ?>
          <div id="memo-expand-<?php print $amendment->title; ?>" style="display:none;" data-linecount="<?php
          print number_format($amendment_text['extra_line_count']); ?>" class="c-detail--memo test">
            <pre class="c-bill-fulltext"><?php print $amendment_text['part_2']; ?></pre>
          </div>
          <div class="item-list">
            <ul class="pager pager-load-more">
              <li class="pager-next first last">
                <a class="text-expander">View More (<?php echo number_format($amendment_text['extra_line_count']); ?> Lines)</a>
              </li>
            </ul>
          </div>
      <?php } ?>
        </div>
      </div>
      <?php endif; ?>

      <!-- Full Text -->
      <?php
      $bill_text_show_expander = preg_match_all('/\n/', $amendment->field_ol_full_text[LANGUAGE_NONE][0]['value']) > 50 ? true : false;
      if ($bill_text_show_expander) {
        $amendment_text = str_split_at_nth($amendment->field_ol_full_text[LANGUAGE_NONE][0]['value'], chr(10), 50);
      }
      else {
        $amendment_text['part_1'] = $amendment->field_ol_full_text[LANGUAGE_NONE][0]['value'];
        $amendment_text['part_2'] = '';
        $amendment_text['extra_line_count'] = 0;
      }
      ?>
      <div class="c-bill-text__bill" style="clear:both;">
        <a name="bill-text-top"></a>
        <h3 class="c-detail--subhead c-detail--section-title"><?php
          print render($amendment->title);
          print $version === $active_amendment_version ? ' (ACTIVE)' : ''
          ?> -  Bill Text
          <span style="float:right;">
            <a href="<?php print $ol_base_url; ?>/pdf/bills/<?php print $bill_wrapper->field_ol_session->value(); ?>/<?php print strtolower($amendment->title); ?>" class="c-detail--download" target="_blank">download pdf</a>
          </span>
        </h3>
      <?php
      if ($amendment->field_ol_full_text[LANGUAGE_NONE][0]['value']):
      ?>
        <div id="full-text-<?php print $bill_wrapper->label(); ?>" class="c-text--preformatted">
          <div class="c-detail--memo">
            <pre class="c-bill-fulltext"><?php print $amendment_text['part_1']; ?></pre>
          </div>
      <?php
        if ($bill_text_show_expander) {
      ?>
          <div id="expand-<?php print $amendment->title; ?>" style="display:none;" data-linecount="<?php
          print number_format($amendment_text['extra_line_count']); ?>"  class="c-detail--memo">
            <pre class="c-bill-fulltext"><?php print $amendment_text['part_2']; ?></pre>
          </div>
          <div class="item-list">
            <ul class="pager pager-load-more">
              <li class="pager-next first last">
                <a class="text-expander">View More (<?php
                  print number_format($amendment_text['extra_line_count']); ?> Lines)</a>
              </li>
            </ul>
          </div>
      <?php } ?>
        </div>
      <?php else: ?>
        <div class="c-bill-fulltext">The Bill text is not available.</div>
      <?php endif; ?>
      </div>
    </div>
  <?php
  endforeach;

  $test = ob_get_contents();
  ob_end_clean();
  return $test;
}

function str_split_at_nth($haystack, $needle, $nth) {
  $max = strlen($haystack);
  $n = 0;
  for ($i = 0; $i < $max; $i++) {
    if ($haystack[$i] == $needle) {
      $n++;
      if ($n > $nth) {
        break;
      }
    }
  }

  $output['part_1'] = substr($haystack, 0, $i);
  $output['part_2'] = substr($haystack, $i + 1, $max);

  $output['extra_line_count'] = preg_match_all('/\n/', $output['part_2']) + 1;


  return $output;
}


function nysenate_preprocess_semanticviews_view_fields(&$vars) {

  // limit display of issues fields to three terms on given views
  if (in_array($vars['view']->name, array('newsroom', 'homepage_news', 'homepage_hero'))) {
    $issues_fields = array('term_node_tid', 'field_issues');
    foreach ($issues_fields as $field_name) {
      if (!empty($vars['fields'][$field_name]->content)) {
        $terms = explode(', ', $vars['fields'][$field_name]->content);
        $up_to_three_terms = implode(', ', array_slice($terms, 0, 3));
        $vars['fields'][$field_name]->content = $up_to_three_terms;
      }
    }
  }

  $vars['isSenateUser'] = module_invoke('nys_wtis', 'is_internal');

  if (isset($vars['fields']['nid']) && !empty($vars['fields']['nid']->content)) {
    $emw = entity_metadata_wrapper('node', $vars['fields']['nid']->content);
    if ($emw->__isset('field_video_status') && !empty($emw->field_video_status->value())) {
      if ($emw->field_video_status->value() == 'streaming_redirect') {
        if ($emw->__isset('field_video_redirect') && !empty($emw->field_video_redirect->value())) {
          $url = $emw->field_video_redirect->value();
          if (!empty($vars['isSenateUser'])) {
            $vars['streaming_redirect'] = '<h3 class="c-video-redirect">' .
              t('Please stream this video from !u.', array(
                '!u' => l($url, $url),
              )) .
            '</h3>';
          }
        }
      }
    }
  }

  if (isset($vars['fields']['field_date']->content) && strpos($vars['fields']['field_date']->content, 'to')) {
    $date_array = explode('to', $vars['fields']['field_date']->content);
    $pre_date = intval(trim($date_array[0]));
    $vars['field_date_month'] = date('M', $pre_date);
    $vars['field_date_day'] = date('d', $pre_date);
    $vars['field_date_year'] = date('Y', $pre_date);
  }

  return $vars;
}


/*
 * Implementation of hook_form_alter()
 */
function nysenate_form_alter(&$form, &$form_state, $form_id){
  // update views form exposed fields
  if($form_id == "views_exposed_form"){
    $form['field_senator_party_tid']['#options']['All'] = t('- Party -'); // overrides <All> on the dropdown
    $form['field_senator_conference_tid']['#options']['All'] = t('- Conference -');
    $form['tid_1']['#options']['All'] = t('- Committee -');
  }

  if ($form_id === 'apachesolr_search_custom_page_search_form' || $form_id === 'apachesolr_search_blocks_core_search') {
    $form['html'] = array(
     '#type' => 'markup',
     '#markup' => '<h2 class="c-site-search--title">Search</h2>',
     '#weight' => -99
    );
    $form['basic']['keys']['#title'] = 'Search';
    $form['basic']['keys']['#title'] = 'Search';
    $form['#attributes']['class'][0] = 'search-form c-site-search'; // Change the text on the label element
    $form['basic']['keys']['#title'] = '';
    $form['basic']['keys']['#size'] = 50;
    $form['basic']['keys']['#attributes']['class'][] = 'c-site-search--box icon_after__search';
    $form['basic']['keys']['#attributes']['placeholder'][] = 'Search';
    $form['basic']['submit']['#attributes']['class'][] = 'c-site-search--btn';
    $form['basic']['submit']['#suffix'] = '<a class="c-site-search--link icon-after__right u-tablet-plus" href="/search/legislation">Advanced Legislation Search</strong></a>';

    if ($form['#action'] == '/legislation') {
      // Set up the lucene filter to pass through to the URL by json_encoding it.
      $form['basic']['get']['#value'] = drupal_json_encode(array(
          'fq[]' => 'bundle:(bill OR resolution)',
        )
      );
    }
  }
  if ($form_id == 'earth_day_entityform_edit_form') {
    $form['field_school_name'][LANGUAGE_NONE]['#options']['_none'] = t('- Start typing school name to narrow list -');
  }
}

/*
* Implements hook_pager_link
* Used to overwrite the pager links for Users on senator dashboard tabs like Issues, Peititons and Questionnaires
 */
function nysenate_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  if(isset($parameters['view']) && ($parameters['view'] == 'senator_issues'))
    $attributes['href'] = url('nys-dashboard/issues-users', array('query' => $query));
  else if(isset($parameters['view']) && ($parameters['view'] == 'senator_questionnaires'))
    $attributes['href'] = url('nys-dashboard/questionnaires-users', array('query' => $query));
  else if(isset($parameters['view']) && ($parameters['view'] == 'senator_petitions'))
    $attributes['href'] = url('nys-dashboard/petitions-users', array('query' => $query));
  else if(isset($parameters['view']) && ($parameters['view'] == 'senator_bills')){
    if(!isset($query['comm_status'])) $query['comm_status'] = 'all';
    if(!isset($query['vote_type'])) $query['vote_type'] = 'all';
    if(!isset($query['bill_name'])) $query['bill_name'] = '';
    if(!isset($query['userid'])) $query['userid'] = arg(1);
    $attributes['href'] = url('nys-dashboard/bills-users', array('query' => $query));
  }
  else
    $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
}

/*
 * Overriding the main menu output
 */

function nysenate_menu_tree__main_menu($variables) {
  return '<ul class="c-nav--list">' . $variables['tree'] . '</ul>';
}
/*
 * Overriding the microsite menu output
 */

function nysenate_menu_tree__menu_senator_s_microsite_menu($variables) {
  return '<ul class="c-nav--list">' . $variables['tree'] . '</ul>';
}

/**
 * Implements template_preprocess_entity().
 */
function nysenate_preprocess_entity(&$variables, $hook) {
  if (!empty($variables['content']['field_bill_id']) && $variables['content']['field_bill_id']['#bundle'] == 'bill') {
    $variables['vote_settings'] = array(
      'entity_type' => 'bill',
      'entity_id' => 2,
      'axis' => 'nys_bill_vote_aye_nay',
    );

    $variables['object']= $variables['content']['field_bill_id']['#object'];
    $variables['wrapper'] = entity_metadata_wrapper('bill', $variables['object']->bill_id);

    if($variables['wrapper']->field_openleg_sponsor->value())
      foreach ($variables['wrapper']->field_openleg_sponsor->field_featured_legislation as $item)
        if($item->field_featured_bill->bill_id->value() == $variables['wrapper']->bill_id->value())
          $variables['sp_position'] = $item->field_featured_quote->value();

    $variables['status_value'] = $variables['wrapper']->field_openleg_actions_status->value() ? $variables['wrapper']->field_openleg_actions_status->value() : 0;

    $info_status = field_info_field('field_openleg_actions_status');
    $variables['status_allowed_values'] = $info_status['settings']['allowed_values'];

    foreach ($variables['wrapper']->field_openleg_votes as $item){
      $variables['votes']['aye'] += count($item->field_openleg_ayes_voters->value());
      $variables['votes']['nay'] += count($item->field_openleg_nays_voters->value());
      $variables['votes']['abst'] += count($item->field_openleg_abstains->value());
      $variables['votes']['absn'] += count($item->field_openleg_absent->value());
      $variables['votes']['exc'] += count($item->field_openleg_excused->value());
      $variables['votes']['ayw'] += count($item->field_openleg_ayeswr->value());
    }

    $array_issues = $variables['wrapper']->field_openleg_issues->value();
    if(count($array_issues))
      $variables['rrl_view_params'] = $array_issues[0]->tid;
    for ($i=1; $i < count($array_issues); $i++)
      $variables['rrl_view_params'].="+".$array_issues[$i]->tid;

  }
}

/**
 * Override drupal core messages with zurb foundation alert-box messages.
 * Customize the colors within the _settings.scss file.
 *
 * http://foundation.zurb.com/docs/elements.php#panelEx
 */
function nysenate_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'error' => t('Error message'),
    'status' => t('Status message'),
    'warning' => t('Warning message'),
  );

  $status_mapping = array(
    'error' => 'alert',
    'status' => 'success',
    'warning' => 'secondary'
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    if (isset($status_mapping[$type])) {
      $output .= "<div data-alert class=\"alert-box $status_mapping[$type]\">\n";
      $output .= '<div class="alert-box-message">';
    }
    else {
      $output .= "<div data-alert class=\"alert-box\">\n";
      $output .= '<div class="alert-box-message">';

    }

    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul class=\"no-bullet\">\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }

    if(!theme_get_setting('zurb_foundation_messages_modal'))
      $output .= '<a href="#" class="close">&times;</a>';

    $output .= "</div></div>\n";
  }

  $is_ajax = !empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
  if ($output != '' && $is_ajax) {
    $output = '<div class="l-messages">' . $output . '</div>';
  }

  if ($output != '' && theme_get_setting('zurb_foundation_messages_modal')) {
    $output = '<div id="status-messages" class="reveal-modal" role="alertdialog">'. $output;
    $output .= '<a class="close-reveal-modal">&#215;</a>';
    $output .= "</div>";
  }

  return $output;
}

/**
 * Overrides theme_fboauth_action() from the fboauth module
 *
 * Forces class that gets us the FB Connect button that users would normally
 * expect.
 *
 */
function nysenate_fboauth_action($variables) {
  $action = $variables['action'];
  $link = $variables['properties'];
  // Because most Facebook actions initiate one-time actions, render it as a
  // button instead of a link. This makes for expected behavior that buttons
  // execute actions, not links.
  $link['attributes']['class'] = '';
  $link['attributes']['name'] = isset($link['attributes']['name']) ? $link['attributes']['name'] : 'facebook_action_' . $action['name'];
  $link['attributes']['type'] = 'button';
  $attributes = drupal_attributes($link['attributes']);
  $url = url($link['href'], array('query' => $link['query']));
  $content = '<button class="form-button facebook-button facebook-action-nys-registration-fb-connect"' . $attributes . ' onclick="window.location = \'' . $url . '\'; return false;">' . check_plain($action['title']) . '</button>';
  return $content;
}


/**
 * given a bill or resolution, return bills (including current bill) with same base_version, bundle (bill vs resolution) and session_year
 */
function nysenate_amended_versions($node_wrapper) {
  return nysenate_get_bill_versions(
    $node_wrapper->type->value(),
    $node_wrapper->field_ol_base_print_no->value(),
    $node_wrapper->field_ol_session->value()
  );
}

function nysenate_get_bill_versions($node_type, $bill_base_print_no, $bill_session_year) {
  $results = [];
  if ($bill_base_print_no && $bill_session_year && $node_type) {
    $query = "SELECT n.title, n.nid, os.field_ol_session_value
      FROM field_data_field_ol_base_print_no pn JOIN node n ON n.nid = pn.entity_id
      JOIN field_data_field_ol_session os ON os.entity_id = pn.entity_id AND os.bundle = pn.bundle
      WHERE pn.field_ol_base_print_no_value = :base_print_no
      AND pn.bundle = :bundle AND os.field_ol_session_value = :session_year;";
    $queryargs = [
      ':base_print_no' => $bill_base_print_no,
      ':bundle' => $node_type,
      ':session_year' => $bill_session_year,
    ];

    $db_results = db_query($query, $queryargs);
    foreach ($db_results as $key => $r) {
      $results[] = ['nid' => $r->nid, 'title' => $r->title];
    }
  }
  return $results;
}

/**
 * Given the output of nysenate_amended_versions, format the results into a definition
 * list string
 */
function nysenate_render_amended_versions_dd($results) {
  $output = array();
  foreach($results as $r) {
    $output[] = '<dd class="amended-version">' . l($r['title'], 'node/' . $r['nid']) . '</dd>';
  }
  return implode('<dd>,&nbsp;</dd> ', $output);
}

/**
 * Render the sponsor and additional sponsor lists for bill detail pages.
 *
 * @param $bill_wrapper An entity wrapper object of the bill being displayed.
 *
 * @return string HTML of the rendered sponsors.
 */
function _nysenate_render_bill_sponsor_list($wrapper) {
  $ret = '';

  $render_sponsors = ($wrapper->field_ol_sponsor->raw() != '') ||
    ($wrapper->field_ol_sponsor_name->raw() != '') ||
    ($wrapper->field_ol_add_sponsors->raw() != '') ||
    ($wrapper->field_ol_add_sponsor_names->raw() != '');

  if ($render_sponsors) {
    $this_node = node_load($wrapper->getIdentifier());
    $ret = '<h3 style="margin-top:20px;margin-bottom:0;" class="c-detail--subhead c-detail--section-title c-bill-detail--subhead">Sponsored By</h3><div class="c-sponsor" style="overflow:auto;">';
    if ($wrapper->field_ol_sponsor->raw()) {
      $this_output = field_view_field('node', $this_node, 'field_ol_sponsor', 'sponsor_list');
      $ret .= render($this_output);
    }
    elseif ($wrapper->field_ol_sponsor_name->raw()) {
      $ret .= '<div class="nys-senator sponsor-list c-bill--nys-senator">' .
        '<div class="nys-senator--info">' .
        '<h4 class="nys-senator--name">' .
        $wrapper->field_ol_sponsor_name->raw() .
        '</h4></div></div></div>';
    }
    if ($wrapper->field_ol_add_sponsors->raw()) {
      $this_output = field_view_field('node', $this_node, 'field_ol_add_sponsors', 'sponsor_list');
      $ret .= render($this_output);
    }
    elseif ($wrapper->field_ol_add_sponsor_names->raw() != '') {
      $added_sponsors = json_decode($wrapper->field_ol_add_sponsor_names->raw());
      $sponsor_names = [];
      foreach ($added_sponsors as $key => $val) {
        $sponsor_names[] = $val->fullName;
      }
      if (count($sponsor_names)) {
        $ret .= '<div class="nys-senator sponsor-list c-bill--nys-senator">' .
          '<div class="nys-senator--info"><label>Additional Sponsors:</label>' .
          '<h4 class="nys-senator--name">' .
          implode(', ', $sponsor_names) .
          '</h4></div></div></div>';
      }
    }
    $ret .= '</div>';
  }

  return $ret;
}