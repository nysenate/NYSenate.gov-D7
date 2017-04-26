<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
	<<?php print $group_element; ?><?php print drupal_attributes($group_attributes); ?>>
    <?php print $title; ?>
  </<?php print $group_element; ?>>
<?php endif; ?>
<?php if (!empty($list_element)): ?>
	<<?php print $list_element; ?><?php print drupal_attributes($list_attributes); ?>>
<?php endif; ?>
<div class="c-panel--header">
		<h4 class="l-panel-col l-panel-col--lft">Bill #</h4>
		<h4 class="l-panel-col l-panel-col--ctr">title & sponsor</h4>
		<h4 class="l-panel-col l-panel-col--rgt">votes</h4>
</div>
<?php foreach ($rows as $id => $row): ?>
	<?php if (!empty($row_element)): ?>
		<<?php print $row_element; ?><?php print drupal_attributes($row_attributes[$id]); ?>>
	<?php endif; ?>
	<?php print $row; ?>
	<?php if (!empty($row_element)): ?>
  </<?php print $row_element; ?>>
  <?php endif; ?>
<?php endforeach; ?>
<?php if (!empty($list_element)): ?>
  </<?php print $list_element; ?>>
<?php endif; ?>