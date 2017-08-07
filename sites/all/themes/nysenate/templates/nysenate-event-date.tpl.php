<?php
// Set up reference variables indicating if this event spans multiple days.
$is_multiday = !(date('Ymd', $start_date) == date('Ymd', $end_date));

// Scrub the class prefix, just in case.
$prefix = ((string) $prefix) ? $prefix : 'c-event-date';
?>
<div class="<?php echo $prefix; if ($is_multiday) echo " {$prefix}-multiday"; ?>">
  <div class="<?php echo $prefix; ?>-start">
    <span class="<?php echo $prefix; ?>-day"><?php print format_date($start_date, "custom", "d"); ?></span>
    <span class="<?php echo $prefix; ?>-month"><?php print format_date($start_date, "custom", "M"); ?></span>
    <span class="<?php echo $prefix; ?>-year"><?php print format_date($start_date, "custom", "Y"); ?></span>
  </div>
  <?php if ($is_multiday): ?>
  <div class="<?php echo $prefix; ?>-separator">&dash;</div>
  <div class="<?php echo $prefix; ?>-end">
    <span class="<?php echo $prefix; ?>-day"><?php print format_date($end_date, "custom", "d"); ?></span>
    <span class="<?php echo $prefix; ?>-month"><?php print format_date($end_date, "custom", "M"); ?></span>
    <span class="<?php echo $prefix; ?>-year"><?php print format_date($end_date, "custom", "Y"); ?></span>
  </div>
  <?php endif; ?>
</div>

