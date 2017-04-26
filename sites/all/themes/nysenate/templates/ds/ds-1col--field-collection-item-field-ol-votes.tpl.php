<?php
if (!isset($aye_count)) {
  $aye_count = (isset($content['field_ol_vote_type']['#object']->field_ol_aye_count[LANGUAGE_NONE][0]['value'])) ? $content['field_ol_vote_type']['#object']->field_ol_aye_count[LANGUAGE_NONE][0]['value'] : FALSE;
  $nay_count = (isset($content['field_ol_vote_type']['#object']->field_ol_nay_count[LANGUAGE_NONE][0]['value'])) ? $content['field_ol_vote_type']['#object']->field_ol_nay_count[LANGUAGE_NONE][0]['value'] : FALSE;
  $aye_wr_count = (isset($content['field_ol_vote_type']['#object']->field_ol_aye_wr_count[LANGUAGE_NONE][0]['value'])) ? $content['field_ol_vote_type']['#object']->field_ol_aye_wr_count[LANGUAGE_NONE][0]['value'] : FALSE;
  $excused_count = (isset($content['field_ol_vote_type']['#object']->field_ol_excused_count[LANGUAGE_NONE][0]['value'])) ? $content['field_ol_vote_type']['#object']->field_ol_excused_count[LANGUAGE_NONE][0]['value'] : FALSE;
  $abstained_count = (isset($content['field_ol_vote_type']['#object']->field_ol_abstained_count[LANGUAGE_NONE][0]['value'])) ? $content['field_ol_vote_type']['#object']->field_ol_abstained_count[LANGUAGE_NONE][0]['value'] : FALSE;
  $absent_count = (isset($content['field_ol_vote_type']['#object']->field_ol_absent_count[LANGUAGE_NONE][0]['value'])) ? $content['field_ol_vote_type']['#object']->field_ol_absent_count[LANGUAGE_NONE][0]['value'] : FALSE;
  $committee = (isset($content['field_ol_vote_type']['#object']->field_ol_committee[LANGUAGE_NONE][0]['entity']->name)) ? $content['field_ol_vote_type']['#object']->field_ol_committee[LANGUAGE_NONE][0]['entity']->name : FALSE;
}
// Show zero votes when no floor votes present on legislation page
if (((current_path() == 'legislation') || (current_path() == 'home')) && ($content['field_ol_vote_type']['#items'][0]['value'] != 'floor')) {
	//$aye_count = $nay_count = $aye_wr_count = $excused_count = $abstained_count = $absent_count = 0;
}
?>
<div class="vote-container">
	<?php if ($aye_count !== FALSE): ?>
		<div class="aye">
			<div class="vote-count"><?php print $aye_count; ?></div>
			<div class="vote-label">Aye</div>
		</div>
	<?php endif;?>
	<?php if ($nay_count !== FALSE): ?>
		<div class="nay">
		  <div class="vote-count"><?php print $nay_count; ?></div>
		  <div class="vote-label">Nay</div>
		</div>
	<?php endif; ?>
</div>
<div class="vote-meta">
	<?php if ($aye_wr_count !== FALSE): ?>
	  <div class="meta-row">
	    <div class="meta-count"><?php print $aye_wr_count; ?></div><div class="meta-label">aye with reservations</div>
	  </div>
	<?php endif; ?>
	<?php if ($absent_count !== FALSE): ?>
		<div class="meta-row">
		  <div class="meta-count"><?php print $absent_count; ?></div><div class="meta-label">absent</div>
		</div>
	<?php endif; ?>
	<?php if ($excused_count !== FALSE): ?>
		<div class="meta-row">
		  <div class="meta-count"><?php print $excused_count; ?></div><div class="meta-label">excused</div>
		</div>
	<?php endif; ?>
	<?php if ($abstained_count !== FALSE): ?>
		<div class="meta-row">
		  <div class="meta-count"><?php print $abstained_count; ?></div><div class="meta-label">abstained</div>
		</div>
	<?php endif; ?>
</div>


