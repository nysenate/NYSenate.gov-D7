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
	<dl class="accordion" data-accordion>
		<dd class="accordion-navigation">
			<a href="#active_list">Active List</a>
			<div id="active_list" class="content">
				<div class="c-panel--header">
					<h4 class="l-panel-col l-panel-col--lft">Bill #</h4>
					<h4 class="l-panel-col l-panel-col--ctr">title & sponsor</h4>
					<h4 class="l-panel-col l-panel-col--rgt">votes / cal no</h4>
				</div>
        <?php if ($rows): ?>
  					<div class="active-list-wrapper">
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
