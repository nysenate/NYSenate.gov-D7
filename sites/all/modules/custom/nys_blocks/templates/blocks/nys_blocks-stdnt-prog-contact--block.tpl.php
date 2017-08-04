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
	<section class="c-block c-student-program-contact">
		<div class="gen-wrapper">
			<h2 class="section-title">Contact us</h2>		
			<div class="gen-col">
				<div class="col">
					<h3>Nicholas J. Parrella, M.A.</h3>
					<h4>Director</h4>
					<p>Phone: 518-455-2611</p>
					
					<h3 class="padded">Kimberly A. Burke</h3>
					<h4>Confidential Assistant</h4>
					<p>Phone: 518-455-2611</p>

				</div>
				<div class="col">

					<h3 class="top-col-title">New York State Senate Office of Student Programs</h3>

					<h4 class="padded">Mailing Address:</h4>
					<p>Legislative Office Building<br>
					Suite 1426<br>
					Albany, NY 12247</p>
					
					<h4 class="padded">Location:</h4>
					<p>80 South Swan Street, <br>
					Suite 1426<br>
					Albany, NY 12247</p>
					
					<h4 class="padded">Email:</h4> 
					<p><a href="mailto:students@nysenate.gov">students@nysenate.gov</a></p>

				</div>
			</div>
		</div>	
	</section>
