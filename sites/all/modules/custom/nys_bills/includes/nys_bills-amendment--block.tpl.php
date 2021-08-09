<?php
// need amendment active or not, as compared with bill's active_version
// need bill chamber
// need same_as information
// need bill_wrapper
// need previous version info

?>
<!-- Amendment Tabs -->
<?php if (count($amendments) > 1): ?>
  <div class="c-bill--amendment-details c-bill-section">
    <div id="amendment-details"></div>
    <h3 class="c-detail--subhead c-detail--section-title">Bill Amendments</h3>
    <?php
    /*
     * There are different sections here for mobile and tablet-plus (desktop), because
     * we want mobile only to be overridden with special actions.  Pay attention to what section you are working on.
     * They are notated below.
     */
    ?>
    <?php // BEGIN DESKTOP SECTION ?>
    <dl class="l-tab-bar u-tablet-plus">
      <?php
      foreach ($amended_versions as $amendment_id):
        $version = str_replace($base_print_no, '', $amendment_id['title']);
        $is_active_version = ($version == $active_version);
        $is_active_tab = ($bill_wrapper->label() === $amendment_id['title'])
        ?>
        <dd class="c-tab <?php print $is_active_tab ? 'active' : '' ?>">
          <a class="c-tab-link bill-version-tab"
             data-version="<?php print render($amendment_id['title']); ?>"
             data-target="/<?php print drupal_get_path_alias('node/' . $amendment_id['nid']); ?>">
            <?php
            print (empty($version) ? "Original" : $version);
            print ($is_active_version ? " (Active) " : "");
            ?>
          </a>
        </dd>
      <?php endforeach; ?>
    </dl>
    <?php // END DESKTOP SECTION ?>

    <?php // BEGIN MOBILE SECTION ?>
    <dl class="l-tab-bar u-mobile-only"
        id="mobile-bill-tab"><?php //This is the MOBILE section. ?>
      <div class="c-tab--arrow u-mobile-only" id="mobile-bill-arrow"></div>
      <?php foreach ($amended_versions as $amendment_id):
        $version = str_replace($base_print_no, '', $amendment_id['title']);
        $is_active_version = ($version == $active_version);
        $is_active_tab = ($bill_wrapper->label() === $amendment_id['title'])
        ?>
        <dd data-isactive="<?php print $is_active_tab ? 'active' : 'inactive' ?>"
            class="c-tab <?php print $is_active_tab ? 'active' : '' ?>">
          <a class="c-tab-link bill-version-tab-mobile"
             data-version="<?php print render($amendment_id['title']); ?>"
             data-target="/<?php print drupal_get_path_alias('node/' . $amendment_id['nid']); ?>">
            <?php
            print (empty($version) ? "Original" : $version);
            print ($is_active_version ? " (Active) " : "");
            ?>
          </a>
        </dd>
      <?php endforeach; ?>
    </dl>
    <?php
    /*
     * See /sites/all/themes/nysenate/js/scripts.js for JS overridden controls.
     */
    ?>
    <?php // END MOBILE SECTION ?>
    <!-- Wrap amendment details in tab content -->
  </div>
<?php endif; ?>


<div class="tabs-content">
  <?php foreach ($amendments as $amendment):
    $is_active_version = ((int) $amendment->field_ol_is_active_version[LANGUAGE_NONE][0]['value']); ?>

    <div class="bill-amendment-detail content<?php
    print ($bill_wrapper->label() === $amendment->title ? ' active' : '') ? ' active' : ''
    ?>" data-version="<?php print render($amendment->title); ?>">

      <!-- Amendment Details -->
      <!-- Quote Block -->
      <?php if (!empty($amendment->quote_text)) : ?>
        <div class="c-quote--content bill-sponsor-quote">
          <h4 class="c-quote--title">Sponsor's Position</h4>
          <p class="c-pullquote icon-before__quotes"><?php print $amendment->quote_text; ?></p>
          <?php
          // Is this the same as $amendment??
          //$amendment_node = node_load($amendment->nid);
          $sponsor_pre_render = field_view_field('node', $amendment, 'field_ol_sponsor', 'Sponsor List');
          print render($sponsor_pre_render);
          ?>
          <button class="js-quote-toggle c-block--btn c-block--btn-toggle">close
          </button>
          <div class="c-social">
            <ul class="c-social--list">
              <li><a target="_blank"
                     href="https://www.facebook.com/sharer/sharer.php?u=https://www.nysenate.gov/<?php print drupal_get_path_alias('node/' . $amendment->nid); ?>"
                     class="icon-replace__facebook">facebook</a></li>
              <li><a target="_blank"
                     href="http://twitter.com/share?url=https://www.nysenate.gov/<?php print drupal_get_path_alias('node/' . $amendment->nid); ?>"
                     class="icon-replace__twitter">twitter</a></li>
            </ul>
          </div>
        </div>
      <?php endif; ?>

      <!-- Bill Co/Multi Sponsors -->
      <?php
      // This is a list of Assembly co-sponsors and multi-sponsors.
      $sponsors_array = nys_bills_resolve_amendment_sponsors($amendment, $bill_wrapper->field_ol_chamber->value());

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
      <div class="c-block c-bill-section c-bill--details"
           style="margin-bottom:30px;">
        <h3 class="c-detail--subhead c-detail--section-title"><?php print render($amendment->title); ?> <?php print $is_active_version ? ' (ACTIVE)' : '' ?>
          - Details</h3>
        <dl>
          <?php
          if ($same_as):
            if (count($same_as) > 1):
              $same_bills = t('See other versions of this Bill:');
            elseif (strtoupper($same_as[0]->printNo[0]) == 'S'):
              $same_bills = t('See Senate Version of this Bill:');
            elseif (strtoupper($same_as[0]->printNo[0]) == 'A'):
              $same_bills = t('See Assembly Version of this Bill:');
            else:
              $same_bills = t('See Version in other house:');
            endif;
            ?>
            <dt><?php print $same_bills; ?></dt>
            <?php
            $first = TRUE;
            foreach ($same_as as $bill_id):
              ?>
              <dd>
                <?php
                if ($first):
                  $first = FALSE;
                else:
                  print ",";
                endif;
                ?>
                <a href="/<?php print drupal_get_path_alias('node/' . $bill_id->nid) ?>"><?php
                  print $bill_id->basePrintNo; ?></a>
              </dd>
            <?php
            endforeach;
          endif;

          if ($bill_wrapper->field_ol_latest_status_committee->value()) :
            $term = taxonomy_get_term_by_name($bill_wrapper->field_ol_latest_status_committee->value(), 'committees');
            $path = '';
            if (!empty($term)) {
              $path = drupal_get_path_alias('taxonomy/term/' . reset($term)->tid);
            }
            ?>
            <?php if (isset($comm_status_pre) && !empty($path)): ?>
            <dt>Current Committee:</dt>
            <dd><?php print $comm_status_pre; ?></dd>
          <?php
          endif;
          endif;

          if ($bill_wrapper->field_ol_law_section->value()):
            ?>
            <dt>Law Section:</dt>
            <dd><?php print $bill_wrapper->field_ol_law_section->value(); ?></dd>
          <?php
          endif;

          if ($bill_wrapper->field_ol_law_code->value()) :
            ?>
            <dt>Laws Affected:</dt>
            <dd><?php print $bill_wrapper->field_ol_law_code->value(); ?></dd>
          <?php
          endif;

          if (!empty($prev_vers)):
            ?>
            <dt><?php print $prev_vers_pre; ?></dt>
            <dd>
              <?php
              $multiyear = count($prev_vers) > 1;
              foreach ($prev_vers as $leg_session => $prev_bills):
                if ($multiyear):
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
          $summary_show_expander = preg_match_all('/;/', $amendment->field_ol_summary[LANGUAGE_NONE][0]['value']) > 3 ? TRUE : FALSE;
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
            <h3 class="c-detail--subhead c-detail--section-title"><?php print render($amendment->title); ?> <?php print $is_active_version ? ' (ACTIVE)' : '' ?>
              - Summary</h3>
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
        $sponsor_memo_show_expander = preg_match_all('/\n/', $amendment->field_ol_memo[LANGUAGE_NONE][0]['value']) > 25 ? TRUE : FALSE;
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
            print $is_active_version ? ' (ACTIVE)' : ''
            ?> - Sponsor Memo</h3>
          <div id="sponsor-memo-<?php print $bill_wrapper->label(); ?>"
               class="c-text--preformatted">
            <div class="c-detail--memo">
            <pre
                class="c-bill-fulltext"><?php print $amendment_text['part_1']; ?></pre>
            </div>
            <?php
            if ($sponsor_memo_show_expander) {
              ?>
              <div id="memo-expand-<?php print $amendment->title; ?>"
                   style="display:none;" data-linecount="<?php
              print number_format($amendment_text['extra_line_count']); ?>"
                   class="c-detail--memo test">
              <pre
                  class="c-bill-fulltext"><?php print $amendment_text['part_2']; ?></pre>
              </div>
              <div class="item-list">
                <ul class="pager pager-load-more">
                  <li class="pager-next first last">
                    <a class="text-expander">View More
                      (<?php echo number_format($amendment_text['extra_line_count']); ?>
                      Lines)</a>
                  </li>
                </ul>
              </div>
            <?php } ?>
          </div>
        </div>
      <?php endif; ?>

      <!-- Full Text -->
      <?php
      $bill_text_show_expander = FALSE;
      if (!empty($amendment->field_ol_full_text)) {
        $bill_text_show_expander = preg_match_all('/\n/', $amendment->field_ol_full_text[LANGUAGE_NONE][0]['value']) > 50;
        if ($bill_text_show_expander) {
          $amendment_text = str_split_at_nth($amendment->field_ol_full_text[LANGUAGE_NONE][0]['value'], chr(10), 50);
        }
        else {
          $amendment_text['part_1'] = $amendment->field_ol_full_text[LANGUAGE_NONE][0]['value'];
          $amendment_text['part_2'] = '';
          $amendment_text['extra_line_count'] = 0;
        }
      }
      ?>
      <div class="c-bill-text__bill" style="clear:both;">
        <a name="bill-text-top"></a>
        <h3 class="c-detail--subhead c-detail--section-title"><?php
          print render($amendment->title);
          print $is_active_version ? ' (ACTIVE)' : ''
          ?> - Bill Text
          <span style="float:right;">
            <a href="<?php print $ol_base_url; ?>/pdf/bills/<?php print $bill_wrapper->field_ol_session->value(); ?>/<?php print strtolower($amendment->title); ?>"
               class="c-detail--download" target="_blank">download pdf</a>
          </span>
        </h3>
        <?php
        if (!empty($amendment->field_ol_full_text)):
          ?>
          <div id="full-text-<?php print $bill_wrapper->label(); ?>"
               class="c-text--preformatted">
            <div class="c-detail--memo">
            <pre
                class="c-bill-fulltext"><?php print $amendment_text['part_1']; ?></pre>
            </div>
            <?php
            if ($bill_text_show_expander) {
              ?>
              <div id="expand-<?php print $amendment->title; ?>"
                   style="display:none;" data-linecount="<?php
              print number_format($amendment_text['extra_line_count']); ?>"
                   class="c-detail--memo">
              <pre
                  class="c-bill-fulltext"><?php print $amendment_text['part_2']; ?></pre>
              </div>
              <div class="item-list">
                <ul class="pager pager-load-more">
                  <li class="pager-next first last">
                    <a class="text-expander">View More (<?php
                      print number_format($amendment_text['extra_line_count']); ?>
                      Lines)</a>
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
  <?php endforeach; ?>
</div>