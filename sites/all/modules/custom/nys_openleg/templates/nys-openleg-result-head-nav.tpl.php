<?php
/**
 * @file nys-openleg-result-head-nav.tpl.php
 *
 * @var $nav array With expected keys for 'previous', 'next', and 'up'.  Each
 *   value is an array, which can describe 'name', 'description', and 'url'.
 *   Any key not present will be rendered as an empty element.
 */
?>
<div class="nys-openleg-result-nav-bar">
  <?php
foreach (['previous', 'up', 'next'] as $key) {
  $current = $nav[$key] ?? [];
  ?>
  <div class="nys-openleg-result-nav-bar-item nys-openleg-result-nav-bar-item-<?php echo $key; ?>">
    <?php if (!empty($current['description']) && !empty($current['url'])) { ?>
      <div class="nys-openleg-result-nav-item-dir"><?php echo $key; ?></div>
      <?php
      echo _nys_openleg_theme_wrapper('nys_openleg_result_item', $current + ['item_type' => 'nav-item']);
    }
    ?>
  </div>
<?php } ?>
</div>
