<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
  <section class="c-cluster c-legislation">

    <div class="c-cluster-header">
      <h2 class="c-cluster-header--title">Legislation</h2>
      <a href="legislation" class="c-cluster-header--link icon-after__arrow lgt-text">go to legislation</a>
    </div>


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

</section>