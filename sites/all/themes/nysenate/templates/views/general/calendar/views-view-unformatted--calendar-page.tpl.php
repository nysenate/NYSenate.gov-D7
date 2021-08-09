<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<article class="c-event-block c-event-block--list">
  <?php $row_count = 0;
  $row_count = count($rows); ?>
  <?php if (!empty($title)): ?>
      <div class="c-event-date">
        <?php if ($view->current_display !== 'page'): ?>
            <span><?php echo date("d", strtotime(strip_tags($title))); ?></span>
          <?php echo date("M", strtotime(strip_tags($title))); ?>
        <?php endif; ?>
      </div>
  <?php endif; ?>
  <?php $row_count_id = 0; ?>
  <?php foreach ($rows as $id => $row): ?>
    <?php $row_count_id++; ?>
    <?php $class = (($row_count_id == $row_count) || (count($rows) == 1)) ? 'last' : ''; ?>
      <div class="c-event--list-by-group <?php echo $class; ?>">
        <?php print $row; ?>
      </div>
  <?php endforeach; ?>
</article>