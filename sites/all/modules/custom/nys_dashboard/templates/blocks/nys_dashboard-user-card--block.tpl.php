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
<div class="c-block c-container c-container--dash-user-card">
  <div class="c-user--header">
    <?php if($avatar) {; ?>
	     <?php print $avatar; ?>
	  <?php } else {; ?>
	  <img class="dash-user-img" src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/default-avatar.png">
	  <?php } ?>
	  <div class="dash-user-info">
    <h2 class="c-container--title">
      <?php print $name; ?>
    </h2>
    <h3 class="c-container--district"><?php print $district; ?></h3>
	  </div>
  </div>
  <div class="c-container--body">
    <div class="c-dash-user-addr">
      <?php print $location; ?>
    </div>
    <div class="c-container--email vcard">
      <?php print $email; ?>
    </div>
    <?php if(!empty($edit_url)): ?>
      <div class="c-dash-user-action-links">
        <a href="<?php print $edit_url; ?>" class="c-dash-edit-profile icon-before__petition">Edit</a>
      </div>
    <?php endif; ?>
  </div>
</div>
