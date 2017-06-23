<?php
/**
 * @file
 * Default theme implementation for the Slick carousel template.
 *
 * Available variables:
 * - $items: The array of items containing main image/video/audio, and optional
 *     image/video/audio overlay and captions.
 * - $settings: A cherry-picked settings that mostly defines the slide HTML or
 *     layout, and none of JS settings/options which are defined at data-slick.
 * - $attributes: The array of attributes to hold the container classes, and id.
 * - $content_attributes: The array of attributes to hold the slick-slider and
 *     data-slick containing JSON object aka JS settings the Slick expects to
 *     override default options. We don't store these JS settings in the normal
 *     <head>, but inline within data-slick attribute instead.
 */
?>
<div<?php print $attributes; ?>>
  <?php if (empty($settings['unslick'])): ?>
    <div<?php print $content_attributes; ?>>
  <?php endif; ?>

    <?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>

  <?php if (empty($settings['unslick'])): ?>
    </div>
    <nav<?php print $arrow_attributes; ?>>
      <?php print $settings['prev_arrow']; ?>
      <?php isset($arrow_down) && print $arrow_down; ?>
      <?php print $settings['next_arrow']; ?>
    </nav>
  <?php endif; ?>
</div>
