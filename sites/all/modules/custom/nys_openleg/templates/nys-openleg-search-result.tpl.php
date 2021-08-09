<?php
/**
 * @file nys-openleg-search-result.tpl.php
 *
 * @var $name string,
 * @var $title string,
 * @var $url string,
 * @var $snippets string[]
 */

if ($name && $title && $url) {
  ?>
  <a href="<?php echo $url; ?>">
    <div class="search-results-item-container">
      <div class="item-location"><?php echo $name; ?></div>
      <div class="item-title"><?php echo $title; ?></div>
      <?php if (count($snippets)) { ?>
        <div class="item-snippets"><?php
          echo count($snippets) . ' instance' . ((count($snippets) == 1) ? '' : 's');
          ?></div>
      <?php } ?>
    </div>
  </a>
  <?php
}
else { ?><!-- Empty search result; no content -->
<?php } ?>
