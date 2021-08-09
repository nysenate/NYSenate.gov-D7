<div class="c-block c-block--pg-feature-image <?php print $classes; ?><?php echo $content['field_pg_full_width_bleed'][0]['#markup']; ?>">
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <?php if (!empty($content['field_pg_feature_image_title'])): ?>
        <h2 class="pg-subtitle"><?php echo $content['field_pg_feature_image_title'][0]['#markup']; ?></h2>
    <?php endif; ?>
    <?php print render($content['field_pg_feature_image']); ?>

</div>