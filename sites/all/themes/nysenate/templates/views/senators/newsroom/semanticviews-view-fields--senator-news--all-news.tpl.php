<?php if(!empty($fields['field_image_main']->content)): ?>
  <article class="c-block c-block-press-release">
  <div class="c-press-release--header">
    <p class="c-press-release--title"><?php echo $fields['type']->content; ?></p>
    <?php echo $fields['term_node_tid']->content;?>
  </div>
  <div class="c-press-release--body c-press-release--body__has-img">
    <h3 class="c-press-release--descript"><?php echo $fields['title']->content; ?></h3>
    <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
      <!-- if has image it would go here -->
      <div class="c-press-release--img"><?php echo $fields['field_image_main']->content;?></div>
  </div>
  </article>
  <?php elseif(!empty($fields['field_yt']->content)): ?>
  <article class="c-block c-block-press-release">
  <div class="c-press-release--header">
    <p class="c-press-release--title"><?php echo $fields['type']->content; ?></p>
    <?php echo $fields['term_node_tid']->content;?>
  </div>
  <div class="c-press-release--body c-press-release--body__has-img">
    <h3 class="c-press-release--descript"><?php echo $fields['title']->content; ?></h3>
    <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
      <!-- if has video thumbnail it would go here -->
    <div class="c-press-release--img"><?php echo $fields['field_yt']->content;?></div>
  </div>
  </article>
  <?php else: ?>
    <article class="c-block c-block-press-release">
    <div class="c-press-release--header">
      <p class="c-press-release--title"><?php echo $fields['type']->content; ?></p>
      <a href="#" class="c-press-release--topic"><?php echo $fields['term_node_tid']->content;?></a>
    </div>
    <div class="c-press-release--body <!-- if img:  c-press-release--body__has-img-->">
      <h3 class="c-press-release--descript"><?php echo $fields['title']->content; ?></h3>
      <p class="c-press-release--date"><?php echo $fields['field_date']->content; ?></p>
      <!-- if has image it would go here -->
    </div>
  </article>
<?php endif;?>