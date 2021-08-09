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
  <section class="c-block calendar-dls">
    <h2 class="block-title">Download Specific Calendars</h2>

    <?php if(!empty($session_calendar_pdf_href)): ?>
      <div class="cal-dl-wrapper c-block">
        <div class="l-col l-col-2">
          <h3>Session Calendar</h3>
          <ul class="cal-dl-list">
            <li>
              <a href="<?php print $session_calendar_pdf_href; ?>" class="cal-dl-link pdf-dl icon-before__bill">Download PDF</a>
              </li>
          </ul>
        </div>
      <?php endif; ?>

      <?php if(!empty($public_hearing_schedule_href) && empty($session_calendar_pdf_href)): ?>
        <div class="cal-dl-wrapper c-block">
          <div class="l-col l-col-2">
            <h3>Public Hearing Schedule</h3>
            <ul class="cal-dl-list">
              <li>
                <a href="<?php print $public_hearing_schedule_href; ?>" class="cal-dl-link pdf-dl icon-before__bill">Download PDF</a>
              </li>
            </ul>
          </div>
        </div>
      <?php endif; ?>

      <?php if(!empty($public_hearing_schedule_href) && !empty($session_calendar_pdf_href)): ?>
        <div class="l-col l-col-2">
          <h3>Public Hearing Schedule</h3>
          <ul class="cal-dl-list">
            <li>
              <a href="<?php print $public_hearing_schedule_href; ?>" class="cal-dl-link pdf-dl icon-before__bill">Download PDF</a>
            </li>
          </ul>
        </div>
      <?php endif; ?>
    </div>
  </section>
