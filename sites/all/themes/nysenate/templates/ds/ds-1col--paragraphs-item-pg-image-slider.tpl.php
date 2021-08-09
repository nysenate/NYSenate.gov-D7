<div class="c-block c-block--pg-image-slider <?php print $classes; ?>">
  <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
  <?php if (!empty($content['field_pg_imageslider_title'])): ?>
		<h2 class="pg-subtitle"><?php print render($content['field_pg_imageslider_title'][0]['#markup']); ?></h2>
  <?php endif; ?>

  <div>
		<?php print render($content['field_pg_slider_images']); ?>
  </div>

</div>
