<?php

/**
 * @file
 * General search template for legislation search.
 *
 * @var array $search
 *   Array of $_GET search variables.
 */

// Add css for this template.
$options = array(
  'type' => 'file',
  'group' => CSS_THEME,
);
drupal_add_css(drupal_get_path('module', 'nys_legislation_explorer') . '/css/search_general.css', $options);

if (!isset($total)) {
  $total = 0;
}
?>

<h1 class="c-adv-search--title">Advanced Legislation Search</h1>
<hr/>
<div class="c-adv-search-container">
  <form id="adv-search-form" action="" method="get">
  <?php if ($search['searched'] == TRUE): ?>
    <div class="page-search">
      <?php if (!empty($error) && $error): ?>
      <div class="c-adv-search--results">
        <p class="c-adv-search--no-results"><?php print $error ?></p>
      </div>
      <?php elseif (!empty($total) && $total == 0): ?>
      <div class="c-adv-search--results">
        <p class="c-adv-search--no-results">Sorry, your search returned no results.</p>
      </div>
      <?php else: ?>
      <div class="columns medium-7">
        <h2 class="search-results">Search Results</h2>
        <div class="ds-search-extra <?php print ($total == 0) ? 'c-no-results' : '' ?>">
          Your search gave back <?php echo $total ?> result(s).
        </div>
      </div>
	  <?php if (!empty($sort_desc[0]) && !empty($sort_desc[1])): ?>
	  <div class="columns medium-5">
		<label for="sort-by">Sort Results</label>
		<select id="sort-by" name="sort" onchange="this.form.submit()">
		  <option <?php echo ($search['sort'] == 'asc') ? 'selected' : ''?> value="asc"><?php print $sort_desc[0] ?></option>
		  <option <?php echo ($search['sort'] != 'asc') ? 'selected' : ''?> value="desc"><?php print $sort_desc[1] ?></option>
		</select>
	  </div>
	  <?php endif;?>
      <?php endif;?>
      <!-- Bill/Resolution Result -->
      <?php if (!empty($total) && $total > 0): ?>
        <?php if ($search['type'] == 'f_bill' || $search['type'] == 'f_resolution'): ?>
          <?php foreach($resp->response->docs as &$doc): ?>
            <?php $bill_session = $doc->itm_field_ol_session[0];
                  $bill_session_closing_year = $bill_session - 1999;
                  $bill_print_no = $doc->sm_field_ol_print_no[0];
                  $bill_chamber = $doc->sm_field_ol_chamber[0];
                  $bill_active = !empty($doc->sm_field_ol_active_version) ? $doc->sm_field_ol_active_version : NULL;
                  $url_path = ($search['type'] == 'f_bill') ? 'bills' : 'resolutions';

                  if(isset($doc->url)) {
                    $bill_url = parse_url($doc->url, PHP_URL_PATH);
                  }
                  elseif (empty($bill_active)) {
                    $bill_url = '/legislation/'  . $url_path . '/' . $bill_session . '/' . $bill_print_no;
                  }
            ?>
            <div class="c-block c-list-item c-block-legislation">
              <!-- Bill / Resolution search result listing -->
                <div class="c-bill-meta">
                  <h3 class="c-bill-num">
                    <a href="<?php print $bill_url; ?>">
                      <?php if ($search['type'] == 'f_bill'): ?> Bill <?php endif; ?>
                      <?php if ($search['type'] == 'f_resolution'): ?> Resolution<br/> <?php endif; ?>
                      <?php echo $bill_print_no ?>
                    </a>
                  </h3>
                  <h4 class="c-bill-topic"><?php print $bill_session . '-' . $bill_session_closing_year ?> Session
                    <?php if (!empty($doc->sm_vid_Issues[0])): ?>
                      <br/><?php print $doc->sm_vid_Issues[0] ?>
                    <?php endif; ?>
                  </h4>
                </div>
                <div class="c-bill-body">
                  <p class="c-bill-descript">
                    <a href="<?php print $bill_url; ?>">
                      <?php print $doc->ts_ol_title ?>
                    </a>
                  </p>
                  <?php if ($search['type'] == 'f_bill'): ?>
                    <?php print $doc->graph_html; ?>
                    <div class="c-bill-update">
                      <p class="c-bill-update--date">
                        <?php print date("F j, Y", strtotime($doc->dm_field_ol_last_status_date[0])) . '&nbsp;&nbsp;|&nbsp;&nbsp;' .  $doc->display_status ?>
                      </p>
                    </div>
                  <?php endif; ?>
                  <?php if ($doc->sm_field_ol_sponsor_name[0]): ?>
                    <p class="c-bill-update--sponsor">
                      Sponsor: <?php print $doc->sm_field_ol_sponsor_name[0] ?>
                     </p>
                  <?php endif; ?>
                </div>
              </div>
            <?php endforeach; ?>
        <!-- Agenda Result -->
        <?php elseif ($search['type'] == 'f_agenda'): ?>
            <?php foreach($resp->response->docs as &$doc): ?>
              <div class="c-block c-list-item c-block-legislation">
                <h3 class="c-bill-num">
                    <a href="<?php print '/' . $doc->path_alias ?>">
                      <?php echo $doc->label ?>
                    </a>
                </h3>
                <h4 class="c-bill-topic">
                  Meeting <?php print date("F j, Y", strtotime($doc->dm_field_date_end[0])) ?>
                </h4>
              </div>
            <?php endforeach; ?>
        <!-- Calendar Result -->
        <?php elseif ($search['type'] == 'f_calendar'): ?>
          <?php foreach($resp->response->docs as &$doc): ?>
            <div class="c-block c-list-item c-block-legislation">
              <h3 class="c-bill-num">
                <a href="<?php print '/calendar/sessions/' . strtolower(date('F-d-Y', $doc->its_ol_cal_date)) . '/session-' . date('n-j-y', $doc->its_ol_cal_date) ?>">
                  Floor Calendar <?php echo substr($doc->label, 5) . ' (' . $doc->its_field_ol_year . ')' ?>
                </a>
              </h3>
              <h4 class="c-bill-topic">
                <?php print 'Session date: ' . date("F j, Y", $doc->its_ol_cal_date) ?>
              </h4>
            </div>
          <?php endforeach; ?>
        <!-- Session Transcript result -->
        <?php elseif ($search['type'] == 'f_session_trans'): ?>
          <?php foreach($resp->response->docs as &$doc): ?>
            <div class="c-block c-list-item c-block-legislation">
              <h3 class="c-bill-num">
                <a href="<?php print '/' . $doc->path_alias ?>">
                  Session Transcript
                </a>
              </h3>
              <h4 class="c-bill-topic">
                <?php print $doc->content ?>
              </h4>
            </div>
          <?php endforeach; ?>
        <!-- Hearing Transcript result -->
        <?php elseif ($search['type'] == 'f_hearing_trans'): ?>
          <?php foreach($resp->response->docs as &$doc): ?>
            <div class="c-block c-list-item c-block-legislation">
              <h3 class="c-bill-num">
                <a href="<?php print '/' . $doc->path_alias ?>">
                  <?php echo $doc->label ?>
                </a>
              </h3>
              <?php if ($search['searched'] == TRUE): ?>
                <h4 class="c-bill-topic" style="margin-bottom:5px;">
                  <?php echo $doc->sm_vid_Committees[0] ?>
                </h4>
            <?php endif; ?>
              <h4 class="c-bill-topic" style="margin-top:0;">
                <?php echo date("F j, Y", strtotime($doc->dm_field_ol_publish_date[0])); ?>
              </h4>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>
        <!-- Pagination -->
        <?php print render_pagination($pagination, '/search/legislation?', $search, 'page'); ?>
        <?php endif; ?>
      </div>
  <?php endif; ?>
  <div>
    <?php if ($search['searched'] == true): ?>
      <p>Refine your search further or search for something else.</p>
    <?php else: ?>
      <p>Fill out one or more of the following filter criteria to perform a search.</p>
    <?php endif; ?>
  </div>
  <hr/>
    <input type="hidden" name="searched" value="true"/>
    <div class="c-adv-search-filter">
      <div class="view-filters">
        <label>Filter by content type</label>
        <select id="adv-search-leg-type" name="type" class="form-select">
          <option <?php echo (!$search['type'] || $search['type'] == 'f_bill') ? 'selected' : '' ?> value="f_bill">Bills</option>
          <option <?php echo ($search['type'] == 'f_resolution') ? 'selected' : '' ?> value="f_resolution">Resolutions</option>
          <option <?php echo ($search['type'] == 'f_agenda') ? 'selected' : '' ?> value="f_agenda">Committee Meeting Agendas</option>
          <option <?php echo ($search['type'] == 'f_calendar') ? 'selected' : '' ?> value="f_calendar">Session Calendars</option>
          <option <?php echo ($search['type'] == 'f_session_trans') ? 'selected' : '' ?> value="f_session_trans">Session Transcripts</option>
          <option <?php echo ($search['type'] == 'f_hearing_trans') ? 'selected' : '' ?> value="f_hearing_trans">Public Hearing Transcripts</option>
        </select>
      </div>
    </div>
    <hr/>
    <!-- Bill Search Form -->
    <div class="f_bill adv-search-ctrls">
      <div class="row">
        <div class="columns medium-6 l-padded-column">
          <label for="bill-printno">Print No</label>
          <input id="bill-printno" type="text" name="bill_printno" value="<?php echo $search['bill_printno'] ?>"/>
        </div>
        <div class="columns medium-6 r-padded-column">
          <label for="bill-session-year">Session Year</label>
          <select id="bill-session-year" name="bill_session_year">
              <option value="">Any</option>
            <?php foreach ($session_years as $session): ?>
              <option <?php echo ($search['bill_session_year'] == $session) ? 'selected' : '' ?>
                      value="<?php echo $session ?>"><?php echo ($session . "-" . ($session + 1)) ?>
              </option>
            <?php endforeach; ?>
          </select>
        </div>
      </div>
      <div class="row">
        <div class="columns medium-12">
          <label for="bill-text">Title / Sponsor Memo / Full Text</label>
          <input id="bill-text" type="text" name="bill_text" value="<?php echo $search["bill_text"] ?>"/>
        </div>
      </div>
      <div class="row">
        <div class="columns medium-6 l-padded-column">
          <label for="bill-sponsor">Senate Sponsor</label>
          <select id="bill-sponsor" name="bill_sponsor">
            <option value="">Any</option>
            <?php $optgroup_detect = 1; ?>
            <optgroup label="Current Senators">
              <?php foreach ($senator_list as $senator):
                if ($senator->active != $optgroup_detect):
                  $optgroup_detect = $senator->active;
                  echo '</optgroup><optgroup label="Former Senators"';
                endif;
                ?>
                <option  <?php echo ($search['bill_sponsor'] == $senator->nid) ? 'selected' : '' ?>
                  value="<?php print $senator->nid ?>">
                  <?php print $senator->full_name ?>
                </option>
              <?php endforeach; ?>
            </optgroup>
          </select>
        </div>
        <div class="columns medium-6 r-padded-column">
          <label for="bill-status">Bill Status</label>
          <select id="bill-status" name="bill_status">
            <option value="">Any</option>
            <?php foreach ($bill_status_codes as $code => $status_name): ?>
              <option <?php echo ($code == $search['bill_status']) ? 'selected' : '' ?>
                      value="<?php echo $code ?>"><?php echo $status_name?></option>
            <?php endforeach; ?>
          </select>
        </div>
      </div>
      <div class="row">
        <div class="columns medium-6 l-padded-column">
          <label for="bill-committee">In Committee</label>
          <select id="bill-committee" name="bill_committee">
            <option value="">Any</option>
            <?php foreach ($committees as $committee): ?>
                <?php if ($committee->field_committee_types[LANGUAGE_NONE][0]['value'] == 'standing'): ?>
                <option value="<?php print $committee->name ?>"
                  <?php echo ($committee->name == $search['bill_committee']) ? 'selected' : ''; ?>>
                  <?php print $committee->name ?></option>
                <?php endif; ?>
            <?php endforeach; ?>
          </select>
        </div>
        <div class="columns medium-6 r-padded-column">
          <label for="bill-issue">Issue</label>
          <select id="bill-issue" name="bill_issue">
            <option value="">Any</option>
            <?php foreach($issue_terms as $issue_term): ?>
              <option <?php echo ($issue_term->name == $search['bill_issue']) ? 'selected' : '' ?>
                      value="<?php echo $issue_term->name ?>"><?php echo $issue_term->name ?>
              </option>
            <?php endforeach; ?>
          </select>
        </div>
      </div>
      <hr/>
    </div>
    <!-- Resolution Search Form -->
    <div class="f_resolution adv-search-ctrls">
      <div class="row">
        <div class="columns medium-6 l-padded-column">
          <label for="resolution-printno">Print No</label>
          <input id="resolution-printno" type="text" name="resolution_printno" value="<?php echo $search['resolution_printno'] ?>"/>
        </div>
        <div class="columns medium-6 r-padded-column">
          <label for="resolution-text">Full Text</label>
          <input id="resolution-text" type="text" name="resolution_text" value="<?php echo $search["resolution_text"] ?>"/>
        </div>
      </div>
      <div class="row">
        <div class="columns medium-6 l-padded-column">
          <label for="resolution-sponsor">Senate Sponsor</label>
          <select id="resolution-sponsor" name="resolution_sponsor">
            <option value="">Any</option>
            <?php $optgroup_detect = 1; ?>
            <optgroup label="Current Senators">
              <?php foreach ($senator_list as $senator):
                if ($senator->active != $optgroup_detect):
                  $optgroup_detect = $senator->active;
                  echo '</optgroup><optgroup label="Former Senators"';
                endif;
                ?>
                <option  <?php echo ($search['resolution_sponsor'] == $senator->nid) ? 'selected' : '' ?>
                  value="<?php print $senator->nid ?>">
                  <?php print $senator->full_name ?>
                </option>
              <?php endforeach; ?>
            </optgroup>
          </select>
        </div>
        <div class="columns medium-6 r-padded-column">
          <label for="resolution-session-year">Session Year</label>
          <select id="resolution-session-year" name="resolution_session_year">
            <option value="">Any</option>
            <?php foreach ($session_years as $session): ?>
              <option <?php echo ($search['resolution_session_year'] == $session) ? 'selected' : '' ?>
                      value="<?php echo $session ?>"><?php echo ($session . "-" . ($session + 1)) ?>
              </option>
            <?php endforeach; ?>
          </select>
        </div>
      </div>

       <hr/>
    </div>
    <!-- Calendar Search Form -->
    <div class="f_calendar adv-search-ctrls">
      <div class="row">
        <div class="columns medium-6 l-padded-column">
          <label for="calendar-month">Month</label>
          <select id="calendar-month" name="calendar_month">
            <option value="">Any</option>
            <?php foreach ($months as $month_index => $month_name): ?>
              <option value="<?php print $month_index ?>" <?php echo ($month_index == $search['calendar_month']) ? 'selected' : '' ?>>
              <?php print $month_name ?></option>
            <?php endforeach; ?>
          </select>
        </div>
        <div class="columns medium-6 l-padded-column">
          <label for="calendar-year">Year</label>
          <select id="calendar-year" name="calendar_year">
            <?php foreach ($years as $year): ?>
              <option <?php echo ($search['calendar_year'] == $year) ? 'selected' : '' ?>
                      value="<?php echo $year ?>"><?php echo $year ?>
              </option>
            <?php endforeach; ?>
          </select>
        </div>
      </div>
      <hr/>
    </div>
    <!-- Agenda Search Form -->
    <div class="f_agenda adv-search-ctrls">
      <div class="row">
        <div class="columns medium-6 l-padded-column">
          <label for="agenda-month">Meeting Month</label>
          <select id="agenda-month" name="agenda_month">
            <option value="">Any</option>
            <?php foreach ($months as $month_index => $month_name): ?>
              <option value="<?php print $month_index ?>" <?php echo ($month_index == $search['agenda_month']) ? 'selected' : '' ?>>
              <?php print $month_name ?></option>
            <?php endforeach; ?>
          </select>
        </div>
        <div class="columns medium-6 r-padded-column">
          <label for="agenda-month">Meeting Year</label>
          <select id="agenda-year" name="agenda_year">
            <?php foreach ($years as $year): ?>
              <option value="<?php print $year ?>" <?php echo ($year == $search['agenda_year']) ? 'selected' : '' ?>>
                <?php print $year ?>
              </option>
            <?php endforeach; ?>
          </select>
        </div>
      </div>
      <div class="row">
        <div class="columns medium-12">
         <label for="agenda-committee">Committee</label>
         <select id="agenda-committee" name="agenda_committee">
            <option value="">Any</option>
            <?php foreach ($committees as $committee): ?>
                <?php if ($committee->field_committee_types[LANGUAGE_NONE][0]['value'] == 'standing'): ?>
                <option value="<?php print $committee->name ?>"
                  <?php echo ($committee->name == $search['agenda_committee']) ? 'selected' : ''; ?>>
                  <?php print $committee->name ?></option>
                <?php endif; ?>
            <?php endforeach; ?>
          </select>
        </div><?php /* can't get this to work...
        <div class="columns medium-6 r-padded-column">
          <label for="agenda-bill-print-no">Contains Bill Print Number</label>
          <input type="text" id="agenda-bill-print-no" name="agenda_bill_print_no"
                 value="<?php echo $search['agenda_bill_print_no'] ?>"/>
        </div> */?>
      </div>
      <hr/>
    </div>
    <!-- Transcript Search Form -->
    <div class="f_session_trans adv-search-ctrls">
      <div class="row">
        <div class="columns medium-4 l-padded-column">
           <label for="session-trans-month">Month</label>
          <select id="session-trans-month" name="session_trans_month">
            <option value="">Any</option>
            <?php foreach ($months as $month_index => $month_name): ?>
              <option value="<?php print $month_index ?>" <?php echo ($month_index == $search['session_trans_month']) ? 'selected' : '' ?>>
              <?php print $month_name ?></option>
            <?php endforeach; ?>
          </select>
        </div>
        <div class="columns medium-4 l-padded-column">
          <label for="session-trans-year">Year</label>
          <select id="session-trans-year" name="session_trans_year">
            <?php foreach ($tx_years as $year): ?>
              <option <?php echo ($search['session_trans_year'] == $year) ? 'selected' : '' ?>
                      value="<?php echo $year ?>"><?php echo $year ?>
              </option>
            <?php endforeach; ?>
          </select>
        </div>
        <div class="columns medium-4">
          <label for="session-trans-text">Full Text</label>
          <input type="text" id="session-trans-text" name="session_trans_text" value="<?php echo $search['session_trans_text']; ?>"/>
        </div>
      </div>
      <hr/>
    </div>
    <!-- Public Hearing Search Form -->
    <div class="f_hearing_trans adv-search-ctrls">
      <div class="row">
        <div class="columns medium-4 l-padded-column">
          <label for="hearing-trans-month">Month</label>
          <select id="hearing-trans-month" name="hearing_trans_month">
            <option value="">Any</option>
            <?php foreach ($months as $month_index => $month_name): ?>
              <option value="<?php print $month_index ?>" <?php echo ($month_index == $search['hearing_trans_month']) ? 'selected' : '' ?>>
              <?php print $month_name ?></option>
            <?php endforeach; ?>
          </select>
        </div>
        <div class="columns medium-4 l-padded-column">
          <label for="hearing-trans-year">Year</label>
          <select id="hearing-trans-year" name="hearing_trans_year">
            <?php foreach ($years as $year): ?>
              <option <?php echo ($search['hearing_trans_year'] == $year) ? 'selected' : '' ?> value="<?php echo $year ?>"><?php echo $year ?>
              </option>
            <?php endforeach; ?>
          </select>
        </div>
        <div class="columns medium-4">
          <label for="hearing-trans-text">Full Text</label>
          <input type="text" id="hearing-trans-text" name="hearing_trans_text" value="<?php echo $search['hearing_trans_text']; ?>"/>
        </div>
      </div>
      <hr/>
    </div>
    <input type="hidden" name="page" value="1"/>
    <p class="c-adv-search--searching">Searching...</p>
    <button id="adv-search-submit" class="c-block--btn c-btn--small c-btn--adv-search">Search</button>
    <br/>
  </form>
</div>
