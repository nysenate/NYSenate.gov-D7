<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<!-- BILL TEMPLATE -->
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="c-block c-detail--header c-detail--header__bill">
    <!-- Bill Title -->
    <div class="c-bill--heading-block">
      <h2 class="nys-title c-bill-title">
        <?php print $bill_wrapper->field_ol_chamber->value(); ?>
        Bill <?php print $bill_wrapper->label(); ?>
      </h2>
      <?php print $signed_veto_status; ?>
      <div class="clearfix"></div>
      <?php print $legislative_session; ?>
    </div>

    <div class="c-detail--header-meta" style="margin-bottom: 20px">
      <p class="c-detail--descript"><?php print $node->field_ol_name[LANGUAGE_NONE][0]['value']; ?></p>


          <?php if (isset($content['field_issues']['#items']) || isset($content['field_majority_issue_tag'][0])): ?>
              <div class="c-meeting-detail--related">
                  <ul class="c-meeting-detail--related">
                      <?php
                      if (!empty($content['field_majority_issue_tag'][0])):
                          print '<li>' . render($content['field_majority_issue_tag'][0]) . '</li>';
                      endif;
                      for ($i = 0; $i < count($content['field_issues']['#items']); $i++) :
                          if (!empty($content['field_issues'][$i])):
                              print '<li>' . render($content['field_issues'][$i]) . '</li>';
                          endif;
                      endfor;
                      ?>
                  </ul>
              </div>
          <?php endif; ?>
      </div>
      <!-- Bill Pdf Link -->
      <a href="<?php print $ol_base_url; ?>/pdf/bills/<?php print $bill_wrapper->field_ol_session->value() . '/' . $bill_wrapper->label(); ?>"
          class="c-detail--download" target="_blank">download bill text pdf</a>
    </div>

    <!-- Share -->
    <div class="c-detail--social" style="margin-bottom: 0; padding-bottom: 0">
      <h3 class="c-detail--subhead">Share this bill</h3>
      <ul>
        <li>
          <a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php print $active_amend_url; ?>"
             class="c-detail--social-item facebook">
            Facebook
          </a>
        </li>
        <li>
          <a target="_blank" class="c-detail--social-item twitter"
             href="https://twitter.com/intent/tweet?text=<?php print $bill_wrapper->field_ol_base_print_no->value(); ?> Via: @nysenate: <?php print $active_amend_url; ?>">
            Twitter
          </a>
        </li>
        <li>
          <a href="mailto:?&subject=From NYSenate.gov: <?php print $bill_wrapper->field_ol_base_print_no->value(); ?>&body=Check out this bill: <?php print $bill_wrapper->field_ol_base_print_no->value(); ?>: < <?php print $active_amend_url; ?> >."
             class="c-detail--social-item email">
            Email
          </a>
        </li>
      </ul>
    </div>
  </div>

  <?php print $sponsored_by; ?>

  <!-- Looker Embed -->

  <?php if (isset($looker_preview_iframe) && $looker_preview_iframe): ?>

  <div class="c-block c-detail--status c-bill-section">
    <h3 class="c-detail--subhead c-detail--section-title c-bill-detail--subhead">
      Senate District <?php print $lc_district; ?> Bill Analytics (Beta - Internal use only)
    </h3>
    <?php print $looker_preview_iframe; ?>
  </div>

  <div class="more_constituent_analytics">
    <dl  style="margin-bottom:0" class="c-block c-detail--actions accordion" data-accordion>
      <dd class="accordion-navigation">
        <a href="#accordion" class="accordion--btn nys-btn-more nys-btn-more--bg" data-open-text="hide additional analytics" data-closed-text="view more analytics">view more constituent analytics</a>
        <div id="accordion" class="content">
          <?php print $looker_extended_iframe; ?>
        </div>
      </dd>
    </dl>
  </div>
  <?php endif;?>


  <!-- Bill Status -->
  <div class="c-block c-detail--status c-bill-section">
    <h3 class="c-detail--subhead c-detail--section-title c-bill-detail--subhead">
      <?php ($current_session_year == $bill_wrapper->field_ol_session->value()) ? print 'Current ': print 'Archive: Last '; ?>Bill Status
      <?php print (($is_substituted) ? 'Via ' . $sub_bill_base_print_no : '') . ' - ' . $bill_display_status ?>
    </h3>
    <!-- Bill Graph Output --->
    <?php print $bill_status_graph; ?>
  </div>
    <!-- Your Voice -->
    <div class="c-block c-bill-section" id="your-voice">
        <h3 class="c-detail--subhead c-detail--section-title">Your Voice</h3>
    </div>
         <!-- Bill Vote Widget -->
        <div class="c-bill--vote-widget">
          <?php print render($content['vote_widget']); ?>
        </div>

  <!-- Bill Message Form -->
  <div class="c-bill--message-form clearfix">
    <?php if (!empty($content['bill_form'])): print render($content['bill_form']); endif; ?>
  </div>

  <!-- Bill Actions -->
  <div class="c-block c-bill-section">
    <h3 class="c-detail--subhead c-detail--section-title">Actions</h3>
    <dl  style="margin-bottom:10px" class="c-block accordion" data-accordion>
      <dd class="accordion-navigation">

        <a href="#accordion-actions" class="accordion--btn nys-btn-more nys-btn-more--bg"
           data-open-text="hide actions (<?php print $actions_count; ?>)" data-closed-text="view actions (<?php print $actions_count; ?>)">
          view actions (<?php print $actions_count; ?>)
        </a>

        <div id="accordion-actions" class="content">
          <div class="content" id="panel-actions">
            <div>
              <table width="100%" class="table c-bill--actions-table">
                <thead>
                <tr>
                  <th></th>
                  <th class="c-bill--actions-table-header">Assembly Actions - <strong>Lowercase</strong><br />Senate Actions - <strong>UPPERCASE</strong></th>
                </tr>
                </thead>
                <tbody>
                  <?php print $actions_table; ?>
                </tbody>
              </table>
            </div>
          </div>
        </div>
      </dd>
    </dl>
  </div>

  <?php if ($votes_block != '' && !ctype_space($votes_block)): ?>
  <div class="c-block c-bill-section">
    <h3 class="c-detail--subhead c-detail--section-title">Votes</h3>
    <dl  style="margin-bottom:10px" class="c-block accordion" data-accordion>
      <dd class="accordion-navigation">

        <a href="#accordion-votes" class="accordion--btn nys-btn-more nys-btn-more--bg"
           data-open-text="hide votes" data-closed-text="view votes">
          view votes
        </a>

        <div id="accordion-votes" class="content">
          <div class="content" id="panel-votes">
            <!-- Bill Votes -->
            <div class="c-block c-detail--votes-wrapper c-bill-section">
              <div class="c-detail--votes">
                <?php print $votes_block; ?>
              </div>
            </div>
          </div>
        </div>
      </dd>
    </dl>
  </div>
  <?php endif; ?>

<?php print $variables['amendments_block']; ?></div>

  <!-- Comments -->
  <div class="content c-bill-section" id="panel-comments">
    <?php $disqus = render($content['disqus']);?>
    <?php if (!empty($disqus)): ?>
      <div class="c-block c-detail--summary">
        <h3 class="c-detail--subhead c-detail--section-title c-bill-detail--subhead">Comments</h3>
        <p>Open Legislation comments facilitate discussion of New York State legislation. All comments are subject to moderation. Comments deemed off-topic, commercial, campaign-related, self-promotional; or that contain profanity or hate speech; or that link to sites outside of the nysenate.gov domain are not permitted, and will not be published. Comment moderation is generally performed Monday through Friday.</p>
        <p>By contributing or voting you agree to the Terms of Participation and verify you are over 13.</p>
        <p>&nbsp;</p>
        <?php print $disqus; ?>
      </div>
    <?php endif; ?>
  </div>

  <!-- Related Bills Content -->
  <?php if ($view_related_bills->result != NULL) : ?>
  <div class="c-block c-container">
    <div class="c-container--header">
      <h2 class="c-container--title">Related Recent Legislation</h2>
    </div>
    <?php print $view_related_bills->render(); ?>
  </div>
  <?php endif; ?>

  <!-- Related Bills Content -->
  <?php if ($view_bill_related_issues->result != NULL) : ?>
  <div class="c-block c-container">
    <div class="c-container--header">
      <h2 class="c-container--title">Related Issues</h2>
      <a href="/explore-issues" class="c-container--link">Explore Issues</a>
    </div>
    <div class="c-block">
      <?php print $view_bill_related_issues->render(); ?>
    </div>
  </div>
  <?php endif; ?>

  <!-- Related Content -->
  <?php if ($view_related_content->result != NULL) : ?>
  <div class="c-block c-container">
    <div class="c-container--header">
      <h2 class="c-container--title">Related News</h2>
      <a href="/news-and-issues" class="c-container--link">News and Issues</a>
    </div>
    <div class="c-block c-container">
      <?php print $view_related_content->render(); ?>
    </div>
  </div>
  <?php endif; ?>
</div>
