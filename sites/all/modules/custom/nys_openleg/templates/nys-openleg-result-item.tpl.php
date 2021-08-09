<?php
/**
 * @file nys-openleg-result-item.tpl.php
 *
 * @var $item_type string A marker embedded into the class names.
 * @var $url string An optional destination URL.  If populated, a link is created.
 * @var $name string The name/title of this item (required)
 * @var $description string An optional description.
 */
$item_type = $item_type ?? 'item';
?>
<div class="nys-openleg-result-<?php echo $item_type; ?>-container">
  <?php if ($name) {
    if ($url) { ?>
      <a href="<?php echo $url; ?>" class="nys-openleg-result-<?php echo $item_type; ?>-link">
    <?php } ?>
    <div class="nys-openleg-result-<?php echo $item_type; ?>-name">
      <?php echo $name; ?>
    </div>
    <?php if ($description) { ?>
      <div class="nys-openleg-result-<?php echo $item_type; ?>-description">
        <?php echo $description; ?>
      </div>
    <?php } ?>
    <?php if ($url) { ?>
      </a>
    <?php } ?>
  <?php } else { ?>
    <!-- empty item -->
  <?php } ?>
</div>
