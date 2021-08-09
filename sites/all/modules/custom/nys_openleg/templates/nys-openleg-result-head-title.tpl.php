<?php
/**
 * @file nys-openleg-result-head-title.tpl.php
 *
 * @var $title string|string[]
 *   Either a string with a single title, or an array of up to three
 *   strings representing location, short title, and parents
 */
if (!is_array($title)) {
  $title = [(string) $title];
}
$headline = array_shift($title) ?? 'No Title <!-- empty theme var -->';
$short_title = array_shift($title) ?? '';
$location = array_shift($title) ?? '';
?>
<div class="nys-openleg-result-title">
  <div class="nys-openleg-result-title-headline">
    <?php echo $headline; ?></div>
  <?php if ($short_title) { ?>
    <div class="nys-openleg-result-title-short">
      <?php echo $short_title; ?></div>
  <?php }
  if ($location) { ?>
    <div class="nys-openleg-result-title-location">
      <?php echo $location; ?></div>
  <?php } ?>
</div>

