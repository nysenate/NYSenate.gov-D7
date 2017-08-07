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

<!-- TEMPORARY MODULE EXAMPLE - HOW THE SENATE WORKS -->
<!-- Assumed Static HTML -->

<button class="js-mobile-nav--btn c-block--btn c-nav--toggle u-mobile-only icon-replace"></button>

<div class="c-nav--wrap c-senator-nav--wrap">
  <div class="c-nav c-senator-nav l-row l-row--nav">
    
    <nav>

      <ul class="c-nav--list c-senator-nav--list">
      	<?php 
      		//dpm($text);
      		print $links;
      	?>
      </ul>

      <button class="js-search--toggle u-tablet-plus c-site-search--btn icon-replace__search">search</button>

      <?php
       $search_box = module_invoke('apachesolr_search_blocks', 'block_view', 'core_search'); 
       print render($search_box['content']);    
      ?>

      <ul class="c-nav--social u-mobile-only">
        <li><a href="" class="icon-replace__facebook">facebook</a></li>
        <li><a href="" class="icon-replace__twitter">twitter</a></li>
        <li><a href="" class="icon-replace__youtube">youtube</a></li>
      </ul>

      
    </nav>
  </div>
</div>

