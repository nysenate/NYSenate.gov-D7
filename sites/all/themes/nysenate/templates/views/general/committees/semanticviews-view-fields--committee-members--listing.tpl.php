<?php
if(isset($fields['field_committee_member_role']->content)) {
	if($fields['field_committee_member_role']->content == 'Other') $position = $fields['field_other_member_role']->content;
	else if($fields['field_committee_member_role']->content == 'Member') $position = '';
	else $position = $fields['field_committee_member_role']->content;
}
?>
<div class="c-senator-block <?php if($fields['field_committee_member_role']->content != "Member") echo 'co-chair'; ?>">
	<a href="<?php echo $fields['path']->content;?>"><?php echo $fields['field_image_headshot']->content;?></a>
	<div class="c-position"><?php echo $position; ?></div>
	<h3 class="c-name"><?php echo $fields['title']->content;?></h3>
	<div class="c-party-conf">
		<?php
			$party = $fields['field_party']->content;
			if(!empty($party)) $associations = explode(', ', $party);

			$conference_parts = explode (" ",$fields['field_conference']->content);			
			$conference ="";
			foreach($conference_parts as $index=>$part)
				if(($index != 0) && ($index%2 == 1)) $associations[] = substr($conference_parts[$index-1],0,1).substr($part,0,1);

			if(!empty($associations)) echo '('.implode(', ', $associations).')';
		?>
	</div>
	<span class="c-district"><?php echo nys_utils_ordinal_suffix($fields['field_district_number']->content) . ' District'; ?></span>
</div>