<?php if(isset($content['field_committee_member_name'][0]['#markup'])): ?>
	<div class="c-cong-member">
		<?php if(isset($content['field_committee_member_name'][0]['#markup'])): ?>
			<h3 class="c-cong-member-name"><?php echo $content['field_committee_member_name'][0]['#markup']; ?></h3>
		<?php endif; ?>
		<?php if(isset($content['field_misc_committee_member_role'][0]['#markup'])): ?>
			<div class="c-cong-member-role"><?php echo $content['field_misc_committee_member_role'][0]['#markup']; ?></div>
		<?php endif; ?>	
		<?php if(isset($content['field_committee_member_url'][0]['#markup'])): ?>
			<div class="c-cong-member-url"><a href="<?php echo $content['field_committee_member_url'][0]['#markup']; ?>"><?php echo $content['field_committee_member_url'][0]['#markup']; ?></a></div>
		<?php endif; ?>	
	</div>
<?php endif; ?>
