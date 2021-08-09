<?php
/**
 * @file nys-openleg-result-head-breadcrumbs.tpl.php
 *
 * @var $breadcrumbs array Each element is a parameter to the item theme
 */

if (is_array($breadcrumbs) && count($breadcrumbs)) {
  ?>
  <div class="nys-openleg-result-breadcrumbs-container"><?php
  foreach (array_filter($breadcrumbs) as $val) {
    echo _nys_openleg_theme_wrapper('nys_openleg_result_item', $val + ['item_type' => 'breadcrumb']);
  }
  ?></div><?php } ?>
