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
  if (drupal_is_front_page()) {
   $homepage_hero_content_type = (string) db_query("SELECT n.type FROM nodequeue_nodes nn JOIN node n ON n.nid = nn.nid WHERE nn.qid = 1 LIMIT 1;")->fetchField();
   if (!empty($homepage_hero_content_type)) {
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
      else if(in_array($node->type, array('article', 'press_release', 'petition', 'questionnaire', 'initiative', 'in_the_news', 'event', 'video', 'advpoll'))){
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

    $variables['node_issues'] = 'Related Issues: ' . implode(', ', $term_links);
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
  if ($variables['node'] && ($variables['node']->type ?? '') == 'transcript') {
    $transcript_file_name = $variables['field_ol_filename'][0]['value'];
    $is_hearing = ($variables['field_ol_transcript_type'][0]['value'] === 'public_hearing');

    // Set a label indicating the type of transcript.
    $tx_type_field = ($is_hearing)
      ? t('Public Hearing')
      : check_plain(ucwords(strtolower($variables['field_ol_session_type'][0]['value'])));

    // Open Leg url paths for PDFs are different for hearings and transcripts.
    $ol_base_url = variable_get("openleg_base_url");
    $transcript_base_url = $ol_base_url. '/api/3/' . (($is_hearing) ? 'hearings/' : 'transcripts/');

    // Trailing slash is needed in the pdf url.
    $variables['pdf_url'] = $transcript_base_url . rawurlencode($transcript_file_name) . '.pdf/';
    $variables['transcript_title'] = $tx_type_field . ' - ' .
                                     format_date($variables['field_ol_publish_date'][0]['value']);
  }

  // for some reason $page not avaiable when node loaded in full content mode in panel page
  if($variables['page'] && empty($variables['title'])) {
    $variables['title'] = drupal_get_title();
  }

  /** --- Bills / Resolutions --- */

  if ($variables['type'] === 'bill') {
    $bill_nid = $variables['node']->nid;
    $bill_wrapper = entity_metadata_wrapper('node', $bill_nid);
    $variables['bill_wrapper'] = $bill_wrapper;
    $state_node = $bill_wrapper;

    $variables['active_amendment_version'] = $bill_wrapper->field_ol_active_version->value();

    // A few immediate references for the bill object.
    $bill_session_year  = $bill_wrapper->field_ol_session->value();
    $bill_base_print_no = $bill_wrapper->field_ol_base_print_no->value();
    $bill_sub_by        = $bill_wrapper->field_ol_substituted_by->value();
    $variables['sub_bill_base_print_no'] = ($bill_wrapper->field_ol_substituted_by->value()  ?? '');

    // Detect bill substitutions.  If a substitution exists, load the target.
    $variables['is_substituted'] = FALSE;
    if ($bill_sub_by) {
      $sub_temp = nys_bills_get_bill_versions($variables['type'], $bill_sub_by, $bill_session_year);
      $subst_versions = array_combine(
          array_map(function($v){return $v['title'];}, $sub_temp),
          array_map(function($v){return $v['nid'];}, $sub_temp)
      );
      krsort($subst_versions);
      if (!empty($subst_versions)) {
        $subst_node = entity_metadata_wrapper('node', reset($subst_versions));
        if ($subst_node) {
          $variables['is_substituted'] = TRUE;
          $state_node = $subst_node;
        }
      }
    }

    // Populate the amendments for this bill.
    $variables['amendments'] = array();
    $amended_versions_result = nys_bills_get_bill_versions(
      $bill_wrapper->type->value(),
      $bill_base_print_no,
      $bill_session_year
    );

    // Loop over amendments, and finds featured legislation quote, if it exists.
    foreach($amended_versions_result as $r) {
      $variables['amendments'][$r['title']] = node_load($r['nid']);
      // Query for Quotes
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

    // Render the amendments.
    $t_vars = [
      'amendments' => $variables['amendments'],
      'bill_wrapper' => $bill_wrapper,
    ];
    $variables['amendments_block'] = theme('nys_bills_amendment_block', $t_vars);

    // Get the current session year.
    $current_year = variable_get('nys_session_year');
    $variables['current_session_year'] = $current_year - (1 - $current_year % 2);

    // Detect signed/vetoed status.
    switch ($state_node->field_ol_last_status->value()) {
      case 'SIGNED_BY_GOV':
        $variables['signed_veto_status'] = '<span class="c-bill--flag">Signed By Governor</span>';
        break;
      case 'VETOED':
        $variables['signed_veto_status'] = '<span class="c-bill--flag">Vetoed By Governor</span>';
        break;
      default:
        $variables['signed_veto_status'] = '';
        break;
    }

    // Create the HTML for the bill's session.
    $variables['legislative_session'] = '<div class="c-bill--session-year">' .
      $bill_session_year . '-' . ($bill_session_year + 1) . ' Legislative Session</div>';

    // Create the URL for the bill.
    $variables['active_amend_url'] = $GLOBALS['base_url'] . '/legislation/bills/' .
      $bill_wrapper->field_ol_session->value() . '/' .
      $bill_wrapper->field_ol_base_print_no->value();

    // Get the base URL for OpenLeg.
    $variables['ol_base_url'] = variable_get('openleg_base_url');

    // Get the rendered sponsor block.
    $variables['sponsored_by'] = _nysenate_render_bill_sponsor_list($bill_wrapper);

    // Build Bill Status Content Section
    $bill_status_graph = nys_dashboard_render_bill_status($bill_nid, '', true);
    $variables['bill_status_graph'] = $bill_status_graph->graph_html;
    $variables['bill_display_status'] = $bill_status_graph->display_status;

    // Build actions list, including substituted actions if applicable
    $actions = drupal_json_decode($bill_wrapper->field_ol_all_actions->value());
    $actions = $actions['items'];
    $grouped_actions = array();
    // Mark the actions from this bill as the original actions
    foreach ($actions as &$action) {
      $action['orig'] = TRUE;
    }
    if ($variables['is_substituted']) {
      // If the bill was substituted, add the subbed bill's actions from the point of substitution.
      $sub_actions = drupal_json_decode($state_node->field_ol_all_actions->value());
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

    $bill_vote_form_settings = ['entity_type' => 'bill', 'entity_id' => $variables['nid']];
    $variables['vote_widget'] = drupal_get_form('nys_bill_vote_vote_widget', $bill_vote_form_settings);
  }

  if ($variables['type'] == 'resolution') {
    // Get a wrapper for the current node.
    $bill_nid = $variables['node']->nid;
    $bill_wrapper = entity_metadata_wrapper('node', $bill_nid);
    $chamber = $bill_wrapper->field_ol_chamber->value();

    // Get the rendered sponsor block.
    $variables['sponsored_by'] = _nysenate_render_bill_sponsor_list($bill_wrapper);

    // Build multi/co-sponsor blocks
    $sponsor_array = nys_bills_resolve_amendment_sponsors(node_load($bill_nid), $chamber);
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
            $social_share_vars['social_share_title'] = t('share this page');
            $social_share_vars['CTA'] = t('Check out this page');
        }

        if(in_array($variables['type'], array('student_program', 'in_the_news'))) {
            $social_share_vars['social_share_title'] = t('share this article');
            $social_share_vars['CTA'] = t('Check out this article');
        }

      if(in_array($variables['type'], array('initiative'))) {
          $social_share_vars['social_share_title'] = t('share this honoree');
          $social_share_vars['CTA'] = t('Check out this honoree');
      }

        if(in_array($variables['type'], array('open_data'))) {
            $social_share_vars['social_share_title'] = t('share this open data report');
            $social_share_vars['CTA'] = t('Check out this open data report');
        }

        if(in_array($variables['type'], array('advpoll'))) {
            $social_share_vars['social_share_title'] = t('share this poll');
            $social_share_vars['CTA'] = t('Check out this poll');
        }

        if(arg(0) == 'node' && $variables['nid'] == arg(1)) { // don't show on embedded nodes, such as webform embedded within questionnaire
            $variables['social_buttons'] = theme('social_buttons', $social_share_vars);
        }

    }
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
   * The templates array describes the combinations of entities, bundles,
   * and view modes which are scheduled to receive a bill graph.  The key
   * is generated as <type>-<bundle>-<view_mode>.  Note that the view mode
   * has all '-' replaced with '_' to match the machine name presented
   * in the layout.  Each value of the array is the CSS class(es) to be
   * added to the bill graph.
   *
   * For example, the template "ds-1col--node-bill-search-index.tpl.php"
   * would receive the following array entry:
   *
   * 'node-bill-search_index' => 'class_name'
   */

  $templates = [
    'node-bill-search_index' => 'nys-bill-status__sml',
    'node-bill-bill_list_item' => 'nys-bill-status__sml',
    'node-bill-teaser' => 'nys-bill-status__drk',
    'node-bill-node_embed_no_quote' => 'nys-bill-status__drk',
  ];

  foreach ($layout_render_array['ds_content'] as $key => $layout) {
    $layout_key = ($layout['#entity_type'] ?? '') . '-' .
      ($layout['#bundle'] ?? '') . '-' .
      ($layout['#view_mode'] ?? '');
    if (array_key_exists($layout_key, $templates)) {
      $nid = $layout['#object']->nid;
      $class = $templates[$layout_key];
      $bill_graph_output = nys_dashboard_render_bill_status($nid, $class);
      $vars['graph_html'] = $bill_graph_output->graph_html;
      $vars['display_status'] = $bill_graph_output->display_status;
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
 * Implements hook_views_pre_render
 */
function nysenate_views_pre_render(&$view) {

  /**
   * The templates listed in this array correspond to those that use a bill
   * status graph.  Each template machine name is assigned a CSS class.
   * When drawn, the graph and display status are sent to the template
   * and can be found within the $row->graph_html and $row->display_status.
   */

$templates = [
  'senator_featured_legislation_sub' => 'nys-bill-status__drk',
  'senator_featured_legislation_main' => 'nys-bill-status__drk',
  'sen_featured_legis' => 'nys-bill-status__drk',
  'sen_featured_legis_sub' => 'nys-bill-status__drk',
  'sen_featured_legis_home_sub' => 'nys-bill-status__sml',
  'featured_legis_list_pane' => 'nys-bill-status__sml',
  'featured_legis_pane' => 'nys-bill-status__drk',
  'senator_legislation_bills' => 'nys-bill-status__sml',
  'related_bills' => 'nys-bill-status__sml',
  'news_by_bill' => 'nys-bill-status__sml',
  'constituent_updates' => 'nys-bill-status__sml wrapper',
  'constituent_bills_voted_on' => 'nys-bill-status__drk',
  'node_bill_search_index' => 'nys-bill-status__sml',
  'bills' => 'nys-bill-status__sml',
];

  // Process through our array of Views templates that have bill graphs.
  // Basically, this avoids processing anything for templates that DON'T
  // have bill status graphs.  Also, make sure a field exists for the
  // node id.
  $draw = array_key_exists($view->current_display, $templates);
  $nid_field = (isset($view->field['nid']->field_alias) ? $view->field['nid']->field_alias : '');
  if (!$nid_field && $view->base_field == 'nid') {
    $nid_field = 'nid';
  }
  if ($draw && $nid_field) {
    $draw_classes = $templates[$view->current_display];

    // Add the rendered bill graph to each result.
    foreach ($view->result as &$result) {
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

/**
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
  if ($form_id == 'article_node_form') {
	  $form['body'][LANGUAGE_NONE][0]['summary']['#title'] = t('Custom Social Description');
  }
    if ($form_id == 'ctools_block_content_type_edit_form') {
        $form['override_title']['#access'] = FALSE;
        $form['override_title_text']['#access'] = FALSE;
        $form['override_title_heading']['#access'] = FALSE;
        $form['override_title_markup']['#markup'] = NULL;
        $form['buttons']['return']['#value'] = 'Add to Page';
    }
    if ($form_id == 'fieldable_panels_panes_fieldable_panels_pane_content_type_edit_form'){
        $form['reusable']['#access'] = FALSE;
        $form['link']['#access'] = FALSE;
        $form['view_mode']['#access'] = FALSE;
        $form['buttons']['return']['#value'] = 'Add to Page';
    }
}

/**
 * Implements hook_pager_link().
 *
 * Used to overwrite the pager links for Users on senator dashboard tabs like
 * Issues, Petitions and Questionnaires.
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

  $attributes['href'] = url($_GET['q'], array('query' => $query));

  return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
}

/**
 * Overriding the main menu output.
 */
function nysenate_menu_tree__main_menu($variables) {
  return '<ul class="c-nav--list">' . $variables['tree'] . '</ul>';
}

/**
 * Overriding the microsite menu output.
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
 *
 * Customize the colors within the _settings.scss file.
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
  $ret = '<h3 style="margin-top:20px;margin-bottom:0;" class="c-detail--subhead c-detail--section-title c-bill-detail--subhead">Sponsored By</h3><div class="c-sponsor" style="overflow:auto;">';

  $add_sponsor_names = json_decode($wrapper->field_ol_add_sponsor_names->raw());
  $render_sponsors = ($wrapper->field_ol_sponsor->raw()) ||
    ($wrapper->field_ol_sponsor_name->raw()) ||
    ($wrapper->field_ol_add_sponsors->raw()) ||
    ($add_sponsor_names);

  if ($render_sponsors) {
    $this_node = node_load($wrapper->getIdentifier());
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
    elseif ($add_sponsor_names) {
      $sponsor_names = [];
      foreach ($add_sponsor_names as $key => $val) {
        $sponsor_names[] = $val->fullName;
      }
      if (count($sponsor_names)) {
        $ret .= '<div class="nys-senator sponsor-list c-bill--nys-senator">' .
          '<div class="nys-senator--info"><label>Additional Sponsors:</label>' .
          '<h4 class="nys-senator--name">' .
          implode(', ', $sponsor_names) .
          '</h4></div></div>';
      }
    }

  }
  else {
    $ret .= '<p style="margin:.75em 0">There are no sponsors of this bill.</p>';
  }
  $ret .= '</div>';

  return $ret;
}

/**
 * Helper function to return previous versions of a bill.
 *
 * @param string $prev_vers_session
 *   OL Session.
 * @param string $prev_vers_printno
 *   Print Number.
 *
 * @return array
 *   Array of query results.
 */
function nysenate_bill_get_prev_versions($prev_vers_session, $prev_vers_printno) {
  // We're using drupal_html_class() ensure that parameters have no spaces in
  // them.
  $cid = 'nysenate_bill_prev_versions_' . drupal_html_class($prev_vers_session) . '-' . drupal_html_class($prev_vers_printno);
  if ($cache = cache_get($cid)) {
    return $cache->data;
  }

  $prev_vers_query = new EntityFieldQuery();
  $prev_vers_result = $prev_vers_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'bill')
    ->fieldCondition('field_ol_session', 'value', $prev_vers_session)
    ->fieldCondition('field_ol_print_no', 'value', $prev_vers_printno)
    ->range(0, 1)
    ->execute();

  // Cache data for later use.
  $cache_ttl = variable_get('nys_access_permissions_prev_query_ttl', '+24 hours');
  $expire_timestamp = strtotime($cache_ttl, time());
  cache_set($cid, $prev_vers_result, 'cache', $expire_timestamp);

  return $prev_vers_result;
}
