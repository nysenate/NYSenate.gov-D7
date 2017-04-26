<?php
$aye_count = ($fields['field_ol_aye_count']->content) ? $fields['field_ol_aye_count']->content : 0;
$nay_count = ($fields['field_ol_nay_count']->content) ? $fields['field_ol_nay_count']->content : 0;
$ayewr_count = ($fields['field_ol_aye_wr_count']->content) ? $fields['field_ol_aye_wr_count']->content : 0;
$excused_count = ($fields['field_ol_excused_count']->content) ? $fields['field_ol_excused_count']->content : 0;
$abstained_count = ($fields['field_ol_abstained_count']->content) ? $fields['field_ol_abstained_count']->content : 0;
?>
<div class="c-update-block">
	<div class="l-panel-col l-panel-col--lft">
		<h4 class="c-listing--bill-num"><?php echo $fields['title']->content; ?></h4>
		<div class="c-tabs--related-issues"><?php echo $fields['field_issues']->content; ?></div>
	</div><!-- .l-panel-col -->
	<div class="l-panel-col l-panel-col--ctr">
		<p><?php echo truncate_utf8($fields['field_ol_name']->content, 135, TRUE, TRUE, 132); ?></p>
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
		<?php if(isset($fields['field_ol_cal_no']->content) && $fields['field_ol_cal_no']->content): ?>
			<p class="c-calendar--num"><span class="c-calendar--num-mark u-mobile-only">cal no.</span><?php echo $fields['field_ol_cal_no']->content; ?></p>
		<?php endif; ?>
		<div class="vote-container">
			<div class="aye">
				<div class="vote-count"><?php echo $aye_count; ?></div>
				<div class="vote-label">Aye</div>
			</div>
			<div class="nay">
				<div class="vote-count"><?php echo $nay_count; ?></div>
				<div class="vote-label">Nay</div>
			</div>
		</div>
		<div class="vote-meta">
			<div class="meta-row">
				<div class="meta-count"><?php echo $ayewr_count; ?></div><div class="meta-label">ayewr</div>
			</div>
				<div class="meta-row">
				<div class="meta-count"><?php echo $excused_count; ?></div><div class="meta-label">excused</div>
			</div>
				
			<div class="meta-row">
				<div class="meta-count"><?php echo $abstained_count; ?></div><div class="meta-label">abstained</div>
			</div>
		</div>
		<?php //echo $fields['field_ol_votes']->content; ?>
		<div class="vote-meta">
			<div class="meta-row">
				<div class="meta-comm-referral">
					<?php if (!empty($fields['field_ol_bill_message']->content) && isset($row->committee_url)) { echo 'Referred to<br /><a class="link-text" href="/' . $row->committee_url . '">' . $row->committee_name . ' committee</a>'; } ?>
				</div>
			</div>
		</div>
	</div>
</div>