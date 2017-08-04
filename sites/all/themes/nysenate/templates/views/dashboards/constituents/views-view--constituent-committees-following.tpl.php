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
<div class="c-block c-container c-container--const-comm-wdgt-follow <?php echo $classes;?>">
  <div class="c-active-list--header">
    <h2 class="c-container--title">Committees You're Following</h2>
  </div>
  <div class="c-container--body">
    <section class="comm-widget-wrapper">
    <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
    <?php endif; ?>
    <?php if ($rows): ?>
        <?php print $rows; ?>
    <?php elseif ($empty): ?>
        <?php print $empty; ?>
    <?php endif; ?>  
    </section>

    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>  
    
  </div>
</div>