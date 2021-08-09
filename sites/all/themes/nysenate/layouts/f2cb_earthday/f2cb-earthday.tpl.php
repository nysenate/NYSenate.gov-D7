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
<?php !empty($css_id) ? print '<div id="' . $css_id . '">' : ''; ?>
    <div class="l-row">
    <?php print $content['top']; ?>
  </div>

  <div class="l-row">
      <!--ADD BACK WHEN 2018 Results are ready-->
      <dl class="l-tab-bar" data-tab>
          <div class="c-tab--arrow u-mobile-only"></div>
          <dd class="c-tab active"><a class="c-tab-link first" href="#panel1">Current Year</a></dd>
          <dd class="c-tab"><a class="c-tab-link" href="#panel2">Past Submissions</a></dd>
         <!-- <dd class="c-tab"><a class="c-tab-link" href="#panel3">Past Winners</a></dd>-->
      </dl>
    <div class="tabs-content"><?php print $content['tabs']; ?></div>

  </div>

  <div class="l-row">
    <?php print $content['bottom']; ?>
  </div>

<?php !empty($css_id) ? print '</div>' : ''; ?>
