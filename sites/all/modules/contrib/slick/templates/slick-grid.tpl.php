<?php

/**
 * @file
 * Default theme implementation for the Slick grid template.
 *
 * Available variables:
 * - $attributes: An array of attributes to apply to the element.
 * - $items: A renderable array of the main image/background.
 * - $settings: A renderable array containing cherry-picked seetings.
 */
?>
<ul<?php print $attributes; ?>>
  <?php foreach($items as $delta => $item): ?>
    <li<?php print $item_attributes[$delta]; ?>>
      <div class="grid__content"><?php print render($item); ?></div>
    </li>
  <?php endforeach; ?>
</ul>
