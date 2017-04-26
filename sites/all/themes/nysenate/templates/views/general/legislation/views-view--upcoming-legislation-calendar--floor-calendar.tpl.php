<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="c-updates-container <?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php if($view->current_display == 'floor_calendar'):?>
        <?php $cal_date = strtotime(trim(strip_tags($header)));?>
        <?php print '<span>'.date('d', $cal_date).'</span>'.date(' / F Y', $cal_date);?>
      <?php else: ?>
        <?php print $header; ?>
      <?php endif; ?>      
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>
	<dl class="accordion" data-accordion>
		<dd class="accordion-navigation">
			<a href="#floor_calendar">Floor Calendar</a>
			<div id="floor_calendar" class="content">
				<div class="c-panel--header">
					<h4 class="l-panel-col l-panel-col--lft">Bill #</h4>
					<h4 class="l-panel-col l-panel-col--ctr">title & sponsor</h4>
					<h4 class="l-panel-col l-panel-col--rgt">votes</h4>
				</div>
        <?php if ($rows): ?>
  					<div class="floor-calendar-wrapper">
  					<?php print $rows; ?>
  					</div>
         <?php elseif ($empty): ?>
            <div class="view-empty">
              <?php print $empty; ?>
            </div>
        <?php endif; ?>
				<?php if ($pager): ?>
					<?php print $pager; ?>
				<?php endif; ?>
		  </div>
		</dd>
	</dl>
  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>
</div><?php /* class view */ ?>
