<div class="c-senator-block">
	<a href="<?php echo $fields['path']->content;?>"><?php echo $fields['field_image_headshot']->content;?></a>
	<div class="c-position"><?php if($fields['field_committee_member_role']->content != "Member") echo $fields['field_committee_member_role']->content; ?></div>
	<h3 class="c-name"><?php echo $fields['title']->content;?></h3>
	<div class="c-party-conf">
		<?php
			$party = substr($fields['field_party']->content,0,1);
			$conference_parts = explode (" ",$fields['field_conference']->content);
			$conference ="";
			foreach($conference_parts as $part)
				$conference .= substr($part,0,1);
			echo "(".$party.",".$conference.")";
		?>
	</div>
	<span class="c-district"><?php echo nys_utils_ordinal_suffix($fields['field_district_number']->content) . ' District'; ?></span>
</div>