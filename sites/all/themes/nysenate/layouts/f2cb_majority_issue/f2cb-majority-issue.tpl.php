<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * each column roughly equal in width. It is 5 rows high; the top
 * middle and bottom rows contain 1 column, while the second
 * and fourth rows contain 2 columns.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['above_left']: Content in the left column in row 2.
 *   - $content['above_right']: Content in the right column in row 2.
 *   - $content['middle']: Content in the middle row.
 *   - $content['below_left']: Content in the left column in row 4.
 *   - $content['below_right']: Content in the right column in row 4.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>

<?php


$separate_contents = ['event'];
$tid = $display->args[0];
//check to see if we are on a node page.
ctools_include('modal');
ctools_include('ajax');

// Add CTools' javascript to the page.
ctools_modal_add_js();
ctools_add_css('login_modal', 'nys_registration');
ctools_add_js('login_modal', 'nys_registration');

$issue = taxonomy_term_load($tid);
$issue_url = drupal_lookup_path('alias', current_path(), 'en');
$absolute_url = $GLOBALS['base_url'] . '/' . check_plain(drupal_get_path_alias(current_path(), 'en'));

// Get count of followers for the issue
$flag_result = flag_get_counts('taxonomy_term', $tid);
if (isset($flag_result['follow_issue'])) {
  $flag_count = $flag_result['follow_issue'];
}
else {
  $flag_count = 0;
}

//$tid = $display->args[0];
//$issue = taxonomy_term_load($tid);
//$issue_url = drupal_lookup_path('alias', current_path(), 'en');
//$absolute_url = $GLOBALS['base_url'] . '/' . check_plain(drupal_get_path_alias(current_path(), 'en'));


?>

<div class="c-block c-detail--header">
    <h1 class="nys-article-title maj-issue"><?php echo $issue->name; ?></h1>
    <?php if ($flag_count): ?><p class="c-issue--followers">
        <span><?php echo $flag_count; ?></span> followers</p><?php endif; ?>
</div>
<!--
<div class="c-detail--social">
    <h3 class="c-detail--subhead">raise awareness</h3>
    <ul>
        <li><a target="_blank"
               href="https://www.facebook.com/sharer/sharer.php?u=<?php print $absolute_url; ?>"
               class="c-detail--social-item facebook"></a></li>
        <li><a target="_blank"
               href="https://twitter.com/intent/tweet?text=<?php print $issue->name; ?> Via: @nysenate: <?php print $absolute_url; ?>"
               class="c-detail--social-item twitter"></a></li>
        <li>
            <a href="mailto:?&subject=From NYSenate.gov: <?php print $issue->name; ?>&body=Check out this issue: <?php print $issue->name; ?>: < <?php print $absolute_url; ?> >."
               class="c-detail--social-item email"></a></li>
    </ul>
</div>-->

<div class="l-row c-block c-top-content-wrapper">
  <?php print $content['top']; ?>
</div>

<!--Check if tid is a budget page, and if not change tab to Legislation -->
<?php if ($tid == 77124) { ?>
<div class="l-row c-block">
    <dl class="l-tab-bar" data-tab>
        <div class="c-tab--arrow u-mobile-only"></div>
        <dd class="c-tab active">
            <a class="c-tab-link first" href="#panel1" id="tab1">News</a></dd>
        <dd class="c-tab">
            <a class="c-tab-link" href="#panel2" id="tab2">Public Hearings</a>
        </dd>
        <dd class="c-tab">
            <a class="c-tab-link" href="#panel3" id="tab3">Budget Bills</a>
        </dd>
    </dl>
    <div class="tabs-content"><?php print $content['tabs']; ?></div>
</div>
<?php } else { ?>
<div class="l-row c-block">
  <dl class="l-tab-bar" data-tab>
    <div class="c-tab--arrow u-mobile-only"></div>
    <dd class="c-tab active">
      <a class="c-tab-link first" href="#panel1" id="tab1">News</a></dd>
    <dd class="c-tab">
      <a class="c-tab-link" href="#panel2" id="tab2">Public Hearings</a>
    </dd>
    <dd class="c-tab">
      <a class="c-tab-link" href="#panel3" id="tab3">Legislation</a>
    </dd>
  </dl>
  <div class="tabs-content"><?php print $content['tabs']; ?></div>
</div>
<?php } ?>


<div class="c-block l-row c-latest-issue-video">
  <?php print $content['bottom']; ?>
</div>
