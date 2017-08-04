<?php if(isset($fields['field_image_main']->content)): ?>
<div class="c-update-block c-update-block--image">
  <div class="l-left">
    <?php if ($fields['type']->content !== 'Event'): ?>
      <div class="c-date"><div class="c-type"><?php echo $fields['type']->content; ?></div></div>
    <?php else:?>
      <div class="c-date"><div class="c-type">Meeting</div></div>
    <?php endif?>    
    <div class="c-category"><?php echo $fields['term_node_tid']->content;?></div>
  </div>
  <div class="l-right">
    <h3 class="c-name"><?php echo $fields['title']->content; ?></h3>
    <?php if ($fields['type']->content !== 'Event'): ?>
      <div class="c-date"><?php echo $fields['field_date']->content; ?></div>
    <?php else:?>
      <div class="c-date"><?php echo $fields['field_date']->content; ?></div>
    <?php endif?>
  </div>
  <div class="c-image"><?php echo $fields['field_image_main']->content;?></div>
</div>
<?php else: ?>
  <div class="c-update-block">
    <div class="l-left">
      <?php if ($fields['type']->content !== 'Event'): ?>
        <div class="c-date"><div class="c-type"><?php echo $fields['type']->content; ?></div></div>
      <?php else:?>
        <div class="c-date"><div class="c-type">Meeting</div></div>
      <?php endif?> 
      <div class="c-category"><?php echo $fields['term_node_tid']->content;?></div>
    </div>
    <div class="l-right">
      <h3 class="c-name"><?php echo $fields['title']->content; ?></h3>
      <?php if ($fields['type']->content !== 'Event'): ?>
        <div class="c-date"><?php echo $fields['field_date']->content; ?></div>
      <?php else:?>
        <div class="c-date"><?php echo $fields['field_date']->content; ?></div>
      <?php endif?>
    </div>
  </div>
<?php endif;?>