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
	<section class="c-senator-footer">
		<div class="l-row">
			<div class="c-senator-footer-col c-senator-footer-col__home">
				<a title="nysenate.gov" href="/">
					<span class="lgt-text icon-before__left">NYsenate.gov</span>
					<img src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/nys_logo224x224.png" alt="New York State Senate Seal" class="c-seal c-seal-footer"/>
				</a>
			</div>

			<div class="c-senator-footer-col c-senator-footer-col__nav">
				<nav>
					<ul>
						<li><a class="lgt-text" href="/news-and-issues">news & issues</a></li>
						<li><a class="lgt-text" href="/senators-committees">senators & committees</a></li>
						<li><a class="lgt-text" href="/legislation">bills & laws</a></li>
                        <li><a class="lgt-text" href="/2020-new-york-state-budget">budget</a></li>
						<li><a class="lgt-text" href="/events">events</a></li>
						<li><a class="lgt-text" href="/about">about the senate</a></li>
					</ul>
				</nav>
			</div>

			<div class="c-senator-footer-col c-senator-footer-col__social">
				<p class="c-senator-footer-caption">Follow the New York Senate</p>
				<ul>
					<li><a href="https://www.facebook.com/NYsenate" class="lgt-text icon-replace__facebook" target="_blank">facebook</a></li>
					<li><a href="https://twitter.com/nysenate" class="lgt-text icon-replace__twitter" target="_blank">twitter</a></li>
					<li><a href="https://www.youtube.com/user/NYSenate" class="lgt-text icon-replace__youtube" target="_blank">youtube</a></li>
					<!-- <li><a href="#" class="lgt-text icon-replace__instagram">instagram</a></li> -->
				</ul>
			</div>
			
		</div>
	</section>
