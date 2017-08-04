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

<div class="c-block c-container c-container--const-bills-wdgt-follow">
  <div class="c-active-list--header">
    <h2 class="c-container--title">Bills You Are Following</h2>
  </div>
  <div class="c-container--body">
		<section class="bill-widget-wrapper">
			<div class="bill-follow-widget">
				<h3>S7226</h3>
				<div class="bill-type">Healthcare</div>
				<div class="bill-blurb">An act to amend the public health law, in relation to establishing the eating disorders awareness and prevention program.</div>
				<div class="timeline">
					<div class="strike"></div>
					<div class="steps">
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step current">
							<div class="curr-step-top"></div>
							<div class="curr-step-bottom"></div>
						</div>
						<div class="step"></div>
						<div class="step"></div>
					</div>
				</div>
				<div class="bill-date">July 9, 2014</div>
				<div class="bill-committee">In Health Committee</div>
				<div class="bill-sponsor-hdr">Sponsors</div>
				<div class="bill-sponsor">Greg Ball, Kemp Hannon</div>
				<div class="bill-vote-wrapper">
					<p>you are in favor of this bill</p>
					<div class="bill-vote-yes"><span class="icon-before__check">Aye</span></div>
					<div class="bill-vote-no"><span class="icon-before__x">Nay</span></div>
				</div>
			</div>
			<div class="bill-follow-widget">
				<h3>S7226</h3>
				<div class="bill-type">Healthcare</div>
				<div class="bill-blurb">An act to amend the public health law, in relation to establishing the eating disorders awareness and prevention program.</div>
				<div class="timeline">
					<div class="strike"></div>
					<div class="steps">
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step current">
							<div class="curr-step-top"></div>
							<div class="curr-step-bottom"></div>
						</div>
						<div class="step"></div>
						<div class="step"></div>
					</div>
				</div>
				<div class="bill-date">July 9, 2014</div>
				<div class="bill-committee">In Health Committee</div>
				<div class="bill-sponsor-hdr">Sponsors</div>
				<div class="bill-sponsor">Greg Ball, Kemp Hannon</div>
				<div class="bill-vote-wrapper">
					<p>you are in favor of this bill</p>
					<div class="bill-vote-yes"><span class="icon-before__check">Aye</span></div>
					<div class="bill-vote-no"><span class="icon-before__x">Nay</span></div>
				</div>
			</div>
			<div class="bill-follow-widget">
				<h3>S7226</h3>
				<div class="bill-type">Healthcare</div>
				<div class="bill-blurb">An act to amend the public health law, in relation to establishing the eating disorders awareness and prevention program.</div>
				<div class="timeline">
					<div class="strike"></div>
					<div class="steps">
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step current">
							<div class="curr-step-top"></div>
							<div class="curr-step-bottom"></div>
						</div>
						<div class="step"></div>
						<div class="step"></div>
					</div>
				</div>
				<div class="bill-date">July 9, 2014</div>
				<div class="bill-committee">In Health Committee</div>
				<div class="bill-sponsor-hdr">Sponsors</div>
				<div class="bill-sponsor">Greg Ball, Kemp Hannon</div>
				<div class="bill-vote-wrapper">
					<p>you are in favor of this bill</p>
					<div class="bill-vote-yes"><span class="icon-before__check">Aye</span></div>
					<div class="bill-vote-no"><span class="icon-before__x">Nay</span></div>
				</div>
			</div>
			<div class="bill-follow-widget">
				<h3>S7226</h3>
				<div class="bill-type">Healthcare</div>
				<div class="bill-blurb">An act to amend the public health law, in relation to establishing the eating disorders awareness and prevention program.</div>
				<div class="timeline">
					<div class="strike"></div>
					<div class="steps">
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step passed"></div>
						<div class="step current">
							<div class="curr-step-top"></div>
							<div class="curr-step-bottom"></div>
						</div>
						<div class="step"></div>
						<div class="step"></div>
					</div>
				</div>
				<div class="bill-date">July 9, 2014</div>
				<div class="bill-committee">In Health Committee</div>
				<div class="bill-sponsor-hdr">Sponsors</div>
				<div class="bill-sponsor">Greg Ball, Kemp Hannon</div>
				<div class="bill-vote-wrapper">
					<p>you are in favor of this bill</p>
					<div class="bill-vote-yes"><span class="icon-before__check">Aye</span></div>
					<div class="bill-vote-no"><span class="icon-before__x">Nay</span></div>
				</div>
			</div>
		</section>
			<div class="pager-load-more icon-after__see-more">See More</div>
  </div>
</div>
