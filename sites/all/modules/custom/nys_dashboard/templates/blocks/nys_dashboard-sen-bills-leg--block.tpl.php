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
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *   module is responsible for handling the default user navigation block. In
 *   that case the class would be "block-user".
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

/**
 * @see nys_looker_integration_senator_dashboard_bill_overview_alter()
 * @var $bills_overview_looker_iframe string
 *      The value of the src attribute for the Looker embed's iframe.
 *
 * @var $senator_bills string
 *      The table for bills sponsored by this senator, rendered as
 *      themed HTML.
 *
 * @var $bills_users string
 *      The table for users who have sent messages to this senator
 *      about legislation, rendered as themed HTML.
 */
$has_looker = !empty($bills_overview_looker_iframe);
$sponsor_class = $has_looker ? '' : 'active';
?>
<div class="c-block c-container c-container--bills-leg">
  <div class="c-active-list--header">
    <h2 class="c-container--title">Legislation</h2>
  </div>
  <div class="c-container--body">
    <dl class="tabs l-tab-bar" data-tab>
      <div class="c-tab--arrow u-mobile-only"></div>

      <?php if ($has_looker) { ?>
        <!-- Looker Integration embed -->
        <dd class="c-tab active">
          <a class="c-tab-link" href="#panel_looker">Bill Analytics</a>
        </dd>
      <?php } ?>

      <!-- Default bill overview. -->

      <dd class="c-tab <?php echo $sponsor_class; ?>">
        <a class="c-tab-link" href="#panel_sponsored">bills you sponsored</a>
      </dd>
      <dd class="c-tab">
        <a class="c-tab-link" href="#panel_messages">constituent messages</a>
      </dd>
    </dl>

    <div class="tabs-content">
      <?php if ($has_looker) { ?>
        <div class="content active your-petitions" id="panel_looker">
          <?php print $bills_overview_looker_iframe; ?>
        </div>
      <?php } ?>
      <div class="content your-petitions <?php echo $sponsor_class; ?>"
           id="panel_sponsored">
        <?php echo $senator_bills; ?>
      </div>
      <div class="content your-petitions" id="panel_messages">
        <?php echo $bills_users; ?>
      </div>
    </div>
  </div>
</div>
