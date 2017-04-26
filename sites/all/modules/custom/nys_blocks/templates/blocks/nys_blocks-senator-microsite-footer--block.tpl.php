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

$node = menu_get_object();

// If the node object is not loaded from the menu, try to load it based on the
// URI.
// This template is in use on sentator microsite pages as well, but they
// are not a node/%node menu route.
if (empty($node) && (arg(0) == 'node') && is_numeric(arg(1))) {
  $node = node_load(arg(1));
}

// In the case that node loads, but is not a senator, it should not have output.
if (!empty($node) && $node->type != 'senator') {
  unset($node);
}

?>
	<section class="c-senator-footer microsite">
		<div class="l-row">
			<div class="c-senator-footer-col c-senator-footer-col__home">
				<a title="nysenate.gov" href="/">
					<span class="lgt-text icon-before__left">go to nysenate.gov</span>
					<img src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/nys_logo224x224.png" alt="New York State Senate Seal" class="c-seal c-seal-footer"/>
				</a>
			</div>

			<div class="c-senator-footer-col c-senator-footer-col__nav">
				<nav>
					<?php
				        $senator_menu = module_invoke('menu', 'block_view', 'menu-senator-s-microsite-menu');
				        print render($senator_menu['content']);    
				      ?>
				</nav>
			</div>

			<?php if (isset($node)): ?>
			<div class="c-senator-footer-col c-senator-footer-col__social">
				<p class="c-senator-footer-caption">Follow <?php print $node->title; ?></p>
				<ul>
					<?php if(isset($node->field_facebook_url['und'][0]['value'])): ?>
						<li><a href="<?php print $node->field_facebook_url['und'][0]['value']; ?>" class="lgt-text icon-replace__facebook" target="_blank">facebook</a></li>
					<?php endif; ?>
					<?php if(isset($node->field_twitter_url['und'][0]['value'])): ?>
						<li><a href="<?php print $node->field_twitter_url['und'][0]['value']; ?>" class="lgt-text icon-replace__twitter" target="_blank">twitter</a></li>
					<?php endif; ?>
					<?php if(isset($node->field_youtube_url['und'][0]['value'])): ?>
						<li><a href="<?php print $node->field_youtube_url['und'][0]['value']; ?>" class="lgt-text icon-replace__youtube" target="_blank">youtube</a></li>
					<?php endif; ?>
				</ul>
			</div>
			<?php endif; ?>

		</div>
	</section>
