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
<div id="section-0" class="l-row l-row--hero">
	<img src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/fpo-about-header.jpg" />

	<div class="l-row l-row--main c-hero--tout">
		<div class="c-about--welcome">
			<h2 class="nys-title nys-title--about">About the New York State Senate</h2>
			<p>The New York State Senate is the upper house of the New York State Legislature. Its sixty-three members represent New York State and its more than 19 million citizens. The legislature’s primary purpose is to draft and approve changes to the laws of New York.</p>
			<p>These changes are driven by complex public policy issues. To effectively represent the will of the people, senators must gain a deep understanding of those issues and how they impact New Yorkers.</p>
			<p> This website aids in that effort. NYSenate.gov is designed to increase public participation in the legislative process. By facilitating efficient communication between individual New Yorkers and the senators who represent them, lawmakers are able to craft a better set of laws by which we are governed.</p>
		</div>

    <div class="space-bottom">
      <iframe width="560" height="315" src="https://www.youtube.com/embed/YpaMRtWFULk" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </div>
	</div>
</div>
