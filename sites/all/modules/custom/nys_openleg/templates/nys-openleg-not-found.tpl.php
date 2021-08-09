<?php
/**
 * @file nys-openleg-not-found.tpl.php
 *
 * @var $additional string Any additional text/HTML to render
 */

global $base_url;

$search_url = $base_url . '/' . NYS_OPENLEG_MENU_PATH . '/' . 'search';
$browse_url = $base_url . '/' . NYS_OPENLEG_MENU_PATH;
?>
<div class="nys-openleg-statute-container nys-openleg-not-found">
  <p>The requested entry could not be found.</p>
  <ul>
    <li><a href="<?php echo $search_url; ?>">Try searching OpenLegislation</a></li>
    <li><a href="<?php echo $browse_url; ?>">Browse all Laws of New York</a></li>
  </ul>
  <?php if ($additional) { ?>
    <div class="nys-openleg-not-found-additional"><?php echo $additional; ?></div>
  <?php } ?>
</div>
