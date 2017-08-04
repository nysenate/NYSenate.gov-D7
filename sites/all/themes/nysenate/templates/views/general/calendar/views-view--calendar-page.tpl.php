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
<?php
switch($view->current_display) {
  case 'week': $view_text = 'View by Week'; break;
  case 'month': $view_text = 'View by Month'; break;
  default: $view_text = 'View by Day';
}
?>
<div class="<?php print $classes; ?> c-upcoming-container">
  <h2 class="nys-title">Statewide Senate Events Calendar</h2>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
      <?php print $header; ?>
  <?php endif; ?>
  <div class="view-header">
  <div id="datepicker"><div class="mobile-calendar-toggle icon-after__calendar-view"><?php echo $view_text; ?></div><input type="text" /><div id="container"></div></div>
  <?php if ($exposed): ?>
  <div class="view-filters">
    <?php print $exposed; ?>
  </div>
  <?php endif; ?>
  <section class="c-block calendar-nav">
    <div class="cal-nav-wrapper">
      <span class="title">Upcoming Events</span>
      <ul class="cal-nav-list">
        <?php if($view->current_display != 'page'): ?><li><a href="/events/day" class="cal-nav-link icon-after__calendar-day">View By Day</a></li><?php endif; ?>
        <?php if($view->current_display != 'week'): ?><li><a href="/events" class="cal-nav-link icon-after__calendar-week">View By Week</a></li><?php endif; ?>
        <?php if($view->current_display != 'month'): ?><li><a href="/events/month" class="cal-nav-link icon-after__calendar-month">View By Month</a></li><?php endif; ?>
      </ul>
    </div>  
  </section>
  </div>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
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