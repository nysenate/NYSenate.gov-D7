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
$inactive_class = '';
if(!$active_senator) $senator_copy = 'Your district is empty.';
else if(isset($no_district) && ($no_district === TRUE)) $senator_copy = 'Your address does not match a NY State Senate District';
?>
  <div class="c-block c-container c-container--dash-senator-card">
    <div class="c-user--header">
      <?php if($image) {; ?>
        <?php print $image; ?>
      <?php } else {; ?>
        <img class="dash-senator-img" src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/default-avatar.png">
      <?php } ?>
      <div class="dash-senator-info">
        <?php if($active_senator):?>
          <div class="c-container--your-s">Your Senator</div>
          <h2 class="c-container--title"><?php print $title; ?></h2>

          <p><?php print $duties; ?> <?php print $abbreviations; ?></p>
          <h3 class="c-container--district"><?php print $district; ?></h3>
        <?php else: ?>
          <?php $inactive_class = 'inactive';?>
          <div class="c-container--your-s"><?php echo $senator_copy;?></div>
        <?php endif; ?>
      </div>
    </div>

    <div class="c-container--body">
      <div class="c-dash-senator-action-links">
        <?php if ($display_message_senator_link): ?>
          <a href="<?php print $contact_link; ?>" class="c-dash-msg-senator icon-before__contact <?php echo $inactive_class;?>"><?php echo $contact_text;?></a>
        <?php endif; ?>
        <?php if(($active_senator === TRUE) && $is_senator):?><a href="/<?php echo drupal_get_path_alias("node/" . $microsite_link); ?>" class="c-dash-senator-site-link">Go to Microsite</a><?php endif;?>
      </div>
    </div>
  </div>

<?php if(!empty($managed_links)): ?>
  <div class="panel-pane pane-block pane-menu-menu-constituent-dashboard-menu">
    <ul class="menu">
      <?php foreach($managed_links as $link): ?>
        <li class="leaf"><?php echo $link; ?></li>
      <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>