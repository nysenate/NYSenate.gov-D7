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

<div class="c-block c-container c-senate-works-container c-senate-works-container--budget">
  <div class="c-container--header">
    <h2 class="c-container--title">How we create a budget</h2>
    <a href="/content/how-budget-works" class="c-container--link">Learn More</a>
  </div>
  
  <div class="c-carousel--nav u-mobile-only">
    <button class="c-carousel--btn prev hidden">prev</button>
    <button class="c-carousel--btn next">next</button>
  </div>

  <ul id="js-carousel-budget" class="js-carousel c-carousel">
    <li class="c-carousel--item l-first">
      <p class="c-senate-works--illustration"><span>Mid - Late<br/>January</span></p>
      <p class="c-senate-works-step-description">Executive Budget Proposal</p>
    </li>
    <li class="c-carousel--item">
      <p class="c-senate-works--illustration"><span>Mid - Late<br/>February</span></p>
      <p class="c-senate-works-step-description">End of 30 Day Amendments</p>
    </li>
    <li class="c-carousel--item">
      <p class="c-senate-works--illustration"><span>Early<br/>March</span></p>
      <p class="c-senate-works-step-description">Executive, Senate, Assembly Economic Forecasts</p>
    </li>
    <li class="c-carousel--item">
      <p class="c-senate-works--illustration"><span>Early - Mid<br/>March</span></p>
      <p class="c-senate-works-step-description">Senate and Assembly Budget Resolutions</p>
    </li>
    <li class="c-carousel--item l-last">
      <p class="c-senate-works--illustration"><span>April <br/>1st</span></p>
      <p class="c-senate-works-step-description">Final Budget Language Due</p>
    </li>
  </ul>
</div>



