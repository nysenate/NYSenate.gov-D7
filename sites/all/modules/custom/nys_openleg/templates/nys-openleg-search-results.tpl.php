<?php
/**
 * @file nys-openleg-search-results.tpl.php
 *
 * @var $search_results string
 * @var $pager string
 */
?>
<div class="nys-openleg-search-results-container">
  <?php if ($search_results) {
    echo $search_results . $pager;
  } ?>
</div>
