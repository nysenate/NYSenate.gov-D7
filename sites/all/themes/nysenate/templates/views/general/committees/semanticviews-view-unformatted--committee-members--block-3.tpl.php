<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php
switch(strtolower($title)) {
  case 'officer' : $title = 'Officers'; $float = 'office';break;
  case 'assembly' : $title = 'Assembly Members'; $float = 'assembly'; break;
  case 'senate' : $title = 'Senate Members'; $float = 'senate'; break;
  default: $title = $title;
}
?>
<div class="member-group <?php echo $float;?>">
  <?php if (!empty($title)): ?>
    <<?php print $group_element; ?><?php print drupal_attributes($group_attributes); ?>>
      <?php print $title; ?>
    </<?php print $group_element; ?>>
  <?php endif; ?>
  <?php if (!empty($list_element)): ?>
    <<?php print $list_element; ?><?php print drupal_attributes($list_attributes); ?>>
  <?php endif; ?>
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
</div>