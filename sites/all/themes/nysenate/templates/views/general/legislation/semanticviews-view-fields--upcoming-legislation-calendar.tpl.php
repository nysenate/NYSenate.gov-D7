<div class="c-update-block">
	<div class="l-panel-col l-panel-col--lft">
		<h4 class="c-listing--bill-num"><?php echo $fields['title']->content; ?></h4>
		<a href="#" class="c-committee-link"></a>
		<div class="c-listing--related-issues"><?php echo $fields['field_issues']->content; ?></div>
	</div><!-- .l-panel-col -->
	<div class="l-panel-col l-panel-col--ctr">
		<p class="c-press-release--descript"><?php echo $fields['field_ol_name']->content; ?></p>
		<?php if(isset($fields['field_ol_sponsor']->content)): ?>
			<?php echo $fields['field_ol_sponsor']->content; ?>
		<?php elseif(!isset($fields['field_ol_sponsor']->content) && $fields['field_ol_sponsor_name']->content): ?>
			<br />
			<label>Sponsor: <?php echo $fields['field_ol_sponsor_name']->content; ?></label>
		<?php else: ?>
			<br />
			<label><?php echo $fields['field_ol_sponsor_name']->content; ?></label>		
		<?php endif; ?>
	</div><!-- .l-panel-col -->
	<div class="l-right-actions">
		<?php if (!empty($fields['field_ol_cal_no']) && isset($fields['field_ol_cal_no']->content) && !$fields['field_ol_votes']->content): ?>
			<p class="c-calendar--num"><span class="c-calendar--num-mark u-mobile-only">cal no.</span><?php echo $fields['field_ol_cal_no']->content; ?></p>
		<?php endif; ?>
		<?php if($fields['field_ol_votes']->content): ?>
			<?php echo $fields['field_ol_votes']->content; ?>
			<div class="vote-meta">
				<div class="meta-row">
					<div class="meta-comm-referral">
						<label><?php echo $fields['field_ol_last_status']->content; ?>:</label>
						<?php echo $fields['field_ol_last_status_date']->content; ?>
					</div>
				</div>
			</div>
		<?php endif; ?>
	</div>
</div>