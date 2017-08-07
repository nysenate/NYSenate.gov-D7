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

<div class="c-block c-container c-container--want-to">
  <div class="c-container--header">
    <h2 class="c-container--title">I want to...</h2>
  </div>

  <div class="c-container--body">
    <div class="c-want-to--item c-want-to--item__senator">
      <p class="c-want-to--cta">...see what’s going on in my district.</p>

      <!-- TOOD: add to logic to check if user has senator associated -->
      <?php if ($user->uid == 0): ?>
        <?php echo ctools_modal_text_button(t('find your senator'), 'registration/nojs/login', t('find your senator'), 'c-block--btn ctools-modal-login-modal');?>
      <?php else: ?>
        <a href="<?php echo $senator_url; ?>" class="c-block--btn loggedin">
          <span class="nys-senator--thumb">
            <?php echo $senator_img ?>
          </span>
          <span class="c-senator--cta">go to your senator's page</span>
        </a>
      <?php endif; ?>

    </div>
    <div class="c-want-to--item c-want-to--item__explore">
      <p class="c-want-to--cta">...find out more about issues that matter to me.</p>
      <a href="/explore-issues" class="c-block--btn">explore issues</a>
    </div>
    <div class="c-want-to--item c-want-to--item__news">
      <p class="c-want-to--cta">...keep up with Senate news</p>
      <a href="/news-and-issues" class="c-block--btn">see all news</a>
    </div>
  </div>
</div>
