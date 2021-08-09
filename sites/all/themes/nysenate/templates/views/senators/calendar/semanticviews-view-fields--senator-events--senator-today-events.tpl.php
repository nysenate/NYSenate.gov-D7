<div class="c-event-block c-event-block--today">
	<div class="c-event-time"><?php echo $fields['field_date_2']->content;?></div>
	<a href="<?php echo $fields['path']->content;?>"><h3 class="c-event-name"><?php echo $fields['title']->content;?></h3></a>
  <?php if($fields['field_event_place']->content == 'online'): ?>
      <a class="c-event-location" href="<?php echo $fields['field_event_online_link']->content; ?>" > <span class="icon-before__circle-pin"></span><span>Online Event</span></a>
      <div class="c-event-address"><?php echo $fields['field_meeting_location']->content;?></div>
  <?php elseif($fields['field_event_place']->content == 'teleconference'): ?>
      <a class="c-event-location" href="<?php echo $fields['path']->content; ?>" > <span class="icon-before__circle-pin"></span><span>Teleconference Event</span></a>
  <?php else: ?>
    <a class="c-event-location" href="http://maps.google.com/?q=<?php echo $fields['street']->content;?>+<?php echo $fields['city']->content;?>%2C+<?php echo $fields['province']->content;?>%2C+<?php echo $fields['postal_code']->content;?>" target="_blank">
		<span class="icon-before__circle-pin"></span><?php echo $fields['name']->content;?>
	</a>
	<div class="c-event-address"><?php echo $fields['street']->content;?><br/><?php echo $fields['city']->content;?>, <?php echo $fields['province']->content;?> <?php echo $fields['postal_code']->content;?></div>
	<?php endif; ?>
</div>