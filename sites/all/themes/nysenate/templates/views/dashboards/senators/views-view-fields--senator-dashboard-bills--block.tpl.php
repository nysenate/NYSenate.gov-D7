<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>

<?php 
$senator_nid = user_get_senator_nid($user);

foreach ($fields as $id => $field){

	switch($id) {
		case 'openleg_bill_id': $data['openleg_bill_id'] = $field->content; break;
		case 'openleg_law_section': $data['openleg_law_section'] = $field->content; break;
		case 'openleg_act_clause': $data['openleg_act_clause'] = $field->content; break;
		case 'field_openleg_sponsor': $data['main_sponsor'] = ($senator_nid == strip_tags($field->content)) ? TRUE : FALSE; break;
		case 'field_openleg_sponsor_1': $data['main_sponsor_name'] = $field->content; break;
		case 'view' : $data['con_aye_votes'] = ($field->content > 0) ? (int)trim($field->content) : 0; break;
		case 'view_1' : $data['con_nay_votes'] = ($field->content > 0) ? (int)trim($field->content) : 0; break;
		case 'view_2' : $data['total_aye_votes'] = ($field->content > 0) ? (int)trim($field->content) : 0; break;
		case 'view_3' : $data['total_nay_votes'] = ($field->content > 0) ? (int)trim($field->content) : 0; break;
	}
} 
?>
<tr>
	<td class="bill-details">
		<div class="bill-id"><?php echo $data['openleg_bill_id'];?></div>
		<div class="bill-type"><?php echo $data['openleg_law_section'];?></div>
		<div class="bill-desc"><?php echo $data['openleg_act_clause'];?></div>
		<?php if($data['main_sponsor'] === TRUE):?>
			<div class="bill-sponsor">you sponsored this bill</div>	
		<?php else: ?>
			<div class="bill-sponsor">Sponsor</div>
			<div class="bill-sponsor-other"><?php echo $data['main_sponsor_name'];?></div>
		<?php endif; ?>
		
	</td>
	<td> 
		<h3 class="active-list-header">Your Constituents Positions</h3>
		<div class="pieContainer"> 
			<div class="aye"><?php echo $data['con_aye_votes'] ?></div>
			<div class="nay"><?php echo $data['con_nay_votes'] ?></div>
			<div class="pieBackground"></div> 
			<div id="pieSlice1" class="hold"> 
				<div class="pie"></div> 
			</div> 
		</div>
		<div class="pie-legend">
			<div class="yes-votes">
				<div class="yes-value"><?php echo $data['con_aye_votes'] ?></div>
				<div class="option-label">aye</div>
			</div>
			<div class="no-votes">
				<div class="no-value"><?php echo $data['con_nay_votes'] ?></div>
				<div class="option-label">Nay</div>
			</div>
		</div>
	</td>
	<td> 
		<?php if(($data['main_sponsor'] === TRUE) || ($view->current_display == 'block_1')):?>
			<h3 class="active-list-header">All Votes</h3>
			<div class="pieContainer"> 
				<div class="aye"><?php echo $data['total_aye_votes']; ?></div>
				<div class="nay"><?php echo $data['total_nay_votes']; ?></div>
				<div class="pieBackground"></div> 
				<div id="pieSlice1" class="hold"> 
					<div class="pie"></div> 
				</div> 
			</div>
			<div class="pie-legend">
				<div class="yes-votes">
					<div class="yes-value"><?php echo $data['total_aye_votes']; ?></div>
					<div class="option-label">aye</div>
				</div>
				<div class="no-votes">
					<div class="no-value"><?php echo $data['total_nay_votes']; ?></div>
					<div class="option-label">Nay</div>
				</div>
			</div>
		<?php endif;?>
	</td>
</tr>