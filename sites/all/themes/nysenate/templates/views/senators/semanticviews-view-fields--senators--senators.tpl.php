<a href="<?php echo $fields['path']->content;?>">
	<div class="c-senator-block">	
		<div class="nys-senator--thumb">
			<?php echo $fields['field_image_headshot']->content;?>
		</div>
		<div class="nys-senator--info">
			<h4 class="nys-senator--name"><?php echo $fields['title']->content;?></h4>
			<span class="nys-senator--district">
				<span class="nys-senator--party">
				<?php
					if(isset($fields['field_party']->content)) $combo[] = $fields['field_party']->content;
					if(isset($fields['field_conference']->content)) $combo[] = $fields['field_conference']->content;
					if(!empty($combo)) print '('.implode(', ', $combo).')';
				?>
				</span>
				<?php if(isset($fields['field_district_number']->content)) : ?>
					<?php echo nys_utils_ordinal_suffix($fields['field_district_number']->content) .' District';?>
				<?php endif; ?>
			</span>
		</div>
	</div>
</a>

