<div class="c-block c-block--pg-two-columns <?php print $classes; ?> <?php echo $content['field_pg_full_width_bleed'][0]['#markup']; ?>">
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <?php if (!empty($content['field_pg_two_col_title'])): ?>
      <div>
        <h2 class="c-container--h2-title">
      	<?php echo $content['field_pg_two_col_title'][0]['#markup']; ?></h2>
      </div>
    <?php endif; ?>

    <div class="l-col l-col--padded l-col-2">
      <?php echo $content['field_pg_column_one'][0]['#markup']; ?>
    </div>

    <div class="l-col l-col--padded l-col-2">
      <?php echo $content['field_pg_column_two'][0]['#markup']; ?>
    </div>
</div>