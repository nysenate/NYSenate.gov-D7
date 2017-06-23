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
<?php print render($wrapper_prefix); ?>
<?php foreach($items as $delta => $item): ?>
  <?php print render($item); ?>
<?php endforeach; ?>
<?php print render($wrapper_suffix); ?>
