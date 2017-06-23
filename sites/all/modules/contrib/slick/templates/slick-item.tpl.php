<?php
/**
 * @file
 * Default theme implementation for the individual Slick item/slide template.
 *
 * Available variables:
 * - $attributes: An array of attributes to apply to the element.
 * - $item: A renderable array of the main image/background.
 * - $caption: A renderable array containing caption fields if provided:
 *   - Title: slide title.
 *   - Alt: core Image field Alt as caption.
 *   - Link: slide links or buttons.
 *   - Overlay: may be audio/video Media, or image.
 *   - Data: any possible field for more complex data if crazy enough.
 *
 * @see template_preprocess_slick_item()
 */
?>
<?php print render($wrapper_prefix); ?>
  <?php if ($settings['current_item'] == 'thumbnail'): ?>
    <?php print render($item); ?>
    <?php if ($caption): ?>
      <div class="slide__caption"><?php print render($caption); ?></div>
    <?php endif; ?>

  <?php
    // Main slide may be grid items, nested slicks, or regular text/image/video.
    else: ?>
    <?php print render($content_prefix); ?>
      <?php print render($item_prefix); ?>
      <?php print render($item); ?>
      <?php print $slide_pattern; ?>
      <?php print render($item_suffix); ?>

      <?php if ($caption): ?>
        <?php print render($title_prefix); ?>
        <div class="slide__caption">
          <?php if (isset($caption['overlay'])): ?>
            <div class="slide__overlay"><?php print render($caption['overlay']); ?></div>
          <?php endif; ?>

          <?php if (isset($caption['data']) || isset($caption['title']) || isset($caption['alt'])): ?>
            <?php if (isset($caption['overlay'])): ?><div class="slide__data"><?php endif; ?>

            <?php if (!empty($caption['title'])): ?>
              <h2 class="slide__title"><?php print render($caption['title']); ?></h2>
            <?php endif; ?>

            <?php if (!empty($caption['alt'])): ?>
              <p class="slide__description"><?php print render($caption['alt']); ?></p>
            <?php endif; ?>

            <?php if (!empty($caption['data'])): ?>
              <div class="slide__description"><?php print render($caption['data']); ?></div>
            <?php endif; ?>

            <?php if (isset($caption['link'])): ?>
              <div class="slide__link"><?php print render($caption['link']); ?></div>
            <?php endif; ?>

            <?php if (isset($caption['overlay'])): ?></div><?php endif; ?>
          <?php endif; ?>
        </div>
        <?php print render($title_suffix); ?>
      <?php endif; ?>
      <?php print render($editor); ?>
    <?php print render($content_suffix); ?>
  <?php endif; ?>
<?php print render($wrapper_suffix); ?>
