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
<div class="c-block c-block--about-student-programs">
<h3 class="nys-subtitle-title">Student Programs</h3>
<p class="l-row">From the halls of higher-learning to the halls of the State Capitol, New York State Senate Student Programs offers undergraduate and graduate students exciting opportunities to learn about state government and to experience firsthand the legislative process. If you have ever thought about a career in public service or state government, now is the time to get started! Our on-site, experiential learning programs provide students with a work experience that is both professionally rewarding and academically enriching.</p>
<?php if (arg(0) != 'student-programs'): ?>
  <a href="/student-programs" class="c-container--link">Learn More</a>
<?php endif; ?>
</div>
<section class="c-block c-student-program-are-you">
	<div class="gen-wrapper">
		<div class="gen-col">
			<h3>Are you an Undergraduate Student?</h3>
			<a href="/newsroom/articles/undergraduate-program">Learn More About Our Undergraduate Session Assistants Program</a>
		</div>
		<div class="gen-col">
			<h3>Are you a Graduate Student?</h3>
			<a href="/newsroom/articles/graduate-program">Learn More About Our Graduate Fellowships</a>
		</div>
	</div>	
</section>
