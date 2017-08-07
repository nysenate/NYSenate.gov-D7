<?php if (isset($fields['field_image_main']->content)): ?>
  <article class="c-block c-block-press-release">
    <div class="l-col l-col-1-of-3">
      <p class="c-press-release--title"><?php echo $fields['type']->content; ?></p>
      <?php if (!empty($fields['field_issues'])): ?>
      <div class="c-tabs--related-issues">
        <?php echo $fields['field_issues']->content; ?>
      </div>
      <?php endif; ?>
    </div>
    <div class="l-col l-col-2-of-3">
      <h3 class="c-press-release--descript"><?php echo $fields['title']->content; ?></h3>
      <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
        <!-- if has image it would go here -->
    </div>
    <div class="l-col l-col-3-of-3">
        <?php echo $fields['field_image_main']->content;?>
    </div>
  </article>
<?php else: ?>
  <article class="c-block c-block-press-release">
    <div class="l-col l-col-1-of-2">
      <p class="c-press-release--title"><?php echo $fields['type']->content; ?></p>
      <?php if (!empty($fields['field_issues'])): ?>
      <div class="c-tabs--related-issues">
        <?php echo $fields['field_issues']->content; ?>
      </div>
      <?php endif; ?>
    </div>
    <div class="l-col l-col-2-of-2">
      <h3 class="c-press-release--descript"><?php echo $fields['title']->content; ?></h3>
      <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
    </div>
  </article>
<?php endif;?>
