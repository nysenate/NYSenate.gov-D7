<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user module
 *     is responsible for handling the default user navigation block. In that case
 *     the class would be "block-user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */
?>

<?php
// Calculate which date range to display for the title, and session year to use
// in our search URLs.
// TODO: Add to preprocess function?
$current_year = date('Y');
if ($current_year % 2 == 0) {
    $session_year = $current_year - 1;
    $first_year   = $session_year;
    $second_year  = substr($current_year,-2);
}
else {
    $session_year = $current_year;
    $first_year   = $current_year;
    $second_year  = substr($current_year + 1, -2);
}
?>

<div class="c-block c-container c-stats--container">
  <div class="c-container--header">
    <h3 class="c-container--title"><?php echo $first_year . '-' . $second_year; ?>, by the numbers</h3>
  </div>

  <div class="c-carousel--nav u-mobile-only">
    <button class="c-carousel--btn prev hidden">prev</button>
    <button class="c-carousel--btn next">next</button>
  </div>

  <span class="c-stats--highlight"></span>
  
  <div id="js-carousel-up-to" class="js-carousel c-carousel">
    <div href="" title="" class="c-carousel--item c-stats--item">
      <a href="/search/legislation?searched=true&type=f_bill&bill_session_year=<?php echo $session_year; ?>&bill_status=SIGNED_BY_GOV&page=1">
        <h4 class="c-stat"><?php echo variable_get('bills_signed_gov');?></h4>
        <p class="c-stat--descript">Bills Signed into Law</p>
      </a>
      <span class="c-stat--illus c-illus__signed"></span>
    </div>
    <div href="" title="" class="c-carousel--item c-stats--item">
      <a href="/search/legislation?searched=true&type=f_bill&bill_session_year=<?php echo $session_year; ?>&bill_status=DELIVERED_TO_GOV&page=1">
        <h4 class="c-stat"><?php echo variable_get('bills_awaiting_gov_signature');?></h4>
        <p class="c-stat--descript">BILLS AWAITING THE GOVERNOR’S SIGNATURE</p>
      </a>
      <span class="c-stat--illus c-illus__waiting"></span>
    </div>
    <div href="" title="" class="c-carousel--item c-stats--item">
      <a href="/search/legislation?searched=true&type=f_bill&bill_session_year=<?php echo $session_year; ?>&bill_status=VETOED&page=1">
        <h4 class="c-stat"><?php echo variable_get('bills_vetoed_gov');?></h4>
        <p class="c-stat--descript">BILLS VETOED BY THE GOVERNOR</p>
      </a>
      <span class="c-stat--illus c-illus__vetoed"></span>
    </div>
  </div>
</div>
