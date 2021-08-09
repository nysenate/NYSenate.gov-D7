<?php if(isset($fields['field_image_main']->content)): ?>
  <section class="c-block c-block-press-release">
    <div class="l-col l-col-1-of-3">
      <h4 class="c-press-release--title"><?php echo $fields['type']->content; ?></h4>
      <div class="c-tabs--related-issues">
          <?php echo $fields['term_node_tid']->content; ?>
      </div>
    </div>
    <div class="l-col l-col-2-of-3">
      <p class="c-press-release--descript"><?php echo $fields['title']->content; ?></p>
      <?php if($fields['field_senator']->content): ?>
      <p class="c-press-release--senator"><?php echo $fields['field_senator']->content; ?></p>
      <?php endif; ?>
      <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
    </div>
    <div class="l-col l-col-3-of-3">
      <?php echo $fields['field_image_main']->content;?>
    </div>
  </section>
<?php else: ?>
  <section class="c-block c-block-press-release">
    <div class="l-col l-col-1-of-2">
      <h4 class="c-press-release--title"><?php echo $fields['type']->content; ?></h4>
      <div class="c-tabs--related-issues">
          <?php echo $fields['term_node_tid']->content; ?>
      </div>
    </div>
    <div class="l-col l-col-2-of-2">
      <p class="c-press-release--descript"><?php echo $fields['title']->content; ?></p>
      <?php if($fields['field_senator']->content): ?>
      <p class="c-press-release--senator"><?php echo $fields['field_senator']->content; ?></p>
      <?php endif; ?>
      <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
    </div>
  </section>
<?php endif;?>