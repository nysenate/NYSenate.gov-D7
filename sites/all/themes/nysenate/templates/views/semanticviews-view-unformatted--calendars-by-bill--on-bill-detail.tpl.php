<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
  <div class="c-block c-bill--calendars">
    <h3 class="c-detail--subhead c-detail--section-title">Calendars</h3>
    <?php if (!empty($title)): ?>
      <<?php print $group_element; ?><?php print drupal_attributes($group_attributes); ?>>
        <?php print $title; ?>
      </<?php print $group_element; ?>>
    <?php endif; ?>
    <?php if (!empty($list_element)): ?>
      <<?php print $list_element; ?><?php print drupal_attributes($list_attributes); ?>>
    <?php endif; ?>
    <?php foreach ($rows as $id => $row): ?>
        <?php print '<ul>'.$row.'</ul>'; ?>
    <?php endforeach; ?>
    <?php if (!empty($list_element)): ?>
      </<?php print $list_element; ?>>
    <?php endif; ?>
  </div>
