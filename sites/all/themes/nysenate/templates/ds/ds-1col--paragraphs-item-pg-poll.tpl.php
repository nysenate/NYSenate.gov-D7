<?php

/**
 * @file
 * Default theme implementation to display an Advanced Poll in a Paragraph.
 */
?>
<section class="c-block c-block--pg-poll">
  <div class="c-container--header__top-border">
    <h3 class="c-container--title">Featured Poll</h3>
  </div>
  <?php print render($content['field_pg_poll']); ?>
</section>
