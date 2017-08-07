	<div class="c-event-date">
		<span><?php echo $fields['field_date']->content;?></span> <?php echo $fields['field_date_1']->content;?>
	</div>
	
	<h3 class="c-event-name">
		<a href="<?php echo $fields['path']->content;?>">
			<?php echo $fields['title']->content;?>
		</a>
	</h3>

	<?php if(!empty($fields['name']->content)): ?>
		<a class="c-event-location" href="http://maps.google.com/?q=<?php echo $fields['street']->content;?>+<?php echo $fields['city']->content;?>%2C+<?php echo $fields['province']->content;?>%2C+<?php echo $fields['postal_code']->content;?>" target="_blank">
			<span class="icon-before__circle-pin"></span><?php echo $fields['name']->content;?>
		</a>
	<?php endif; ?>

	<?php if(!empty($fields['street']->content) && !empty($fields['city']->content) && !empty($fields['province']->content) && !empty($fields['postal_code']->content)) : ?>
		<div class="c-event-address">
			<?php echo $fields['street']->content;?><br/>
			<?php echo $fields['city']->content;?>, <?php echo $fields['province']->content;?> <?php echo $fields['postal_code']->content;?>
		</div>
	<?php endif; ?>

	<?php if(!empty($fields['field_date_2']->content)): ?>
		<div class="c-event-time">
			<?php echo $fields['field_date_2']->content;?>
		</div>
	<?php endif; ?>
