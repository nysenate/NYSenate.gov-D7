<?php if(isset($fields['field_image_main']->content)): ?>
  <section class="c-block c-block-press-release">
  <div class="c-press-release--header">
    <h4 class="c-press-release--title"><?php echo $fields['type']->content; ?></h4>
    <?php echo $fields['term_node_tid']->content;?>
  </div>
  <div class="c-press-release--body c-press-release--body__has-img">
    <p class="c-press-release--descript"><?php echo $fields['title']->content; ?></p>
    <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
      <!-- if has image it would go here -->
      <div class="c-press-release--img"><?php echo $fields['field_image_main']->content; ?></div>
  </div>
  </section>
<?php else: ?>
    <section class="c-block c-block-press-release">
    <div class="c-press-release--header">
      <h2 class="c-press-release--title"><?php echo $fields['type']->content; ?></h2>
      <a href="#" class="c-press-release--topic"><?php echo $fields['term_node_tid']->content;?></a>
    </div>
    <div class="c-press-release--body <!-- if img:  c-press-release--body__has-img-->">
      <p class="c-press-release--descript"><?php echo $fields['title']->content; ?></p>
      <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
      <!-- if has image it would go here -->
    </div>
  </section>
<?php endif;?>