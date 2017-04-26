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
$user = user_load(arg(1));
$senator_nid = user_get_senator_nid($user);


foreach ($fields as $id => $field){

	switch($id) {
		case 'title': $data['title'] = $field->content; break;
		case 'field_ol_law_section': $data['field_ol_law_section'] = $field->content; break;
		case 'field_ol_name': $data['field_ol_name'] = $field->content; break;
		case 'field_ol_sponsor': $data['main_sponsor'] = (($senator_nid == strip_tags($field->content)) && (strip_tags($field->content) != '')) ? TRUE : FALSE; break;
		case 'field_ol_sponsor_name': $data['main_sponsor_name'] = $field->content; break;
		case 'field_ol_co_sponsors': $data['co_sponsor'] = (($data['co_sponsor'] !== TRUE) && in_array($senator_nid, explode(', ', strip_tags($field->content)))) ? TRUE : FALSE; break;
	}
} 
$total_no_votes = ($row->votes['all_aye']+$row->votes['all_nay'] < 1) ? 'no-votes' : '';
$const_no_votes = ($row->votes['const_aye']+$row->votes['const_nay'] < 1) ? 'no-votes' : '';
?>
<tr>
	<td class="bill-details">
		<div class="wrapper">
			<div class="bill-id"><?php echo $data['title'];?></div>
			<div class="bill-type"><?php echo $data['field_ol_law_section'];?></div>
			<div class="bill-desc"><?php echo truncate_utf8($data['field_ol_name'], 135, TRUE, TRUE, 132);?></div>
			<?php if($data['main_sponsor'] === TRUE):?>
				<div class="bill-sponsor">you sponsored this bill</div>	
			<?php else: ?>
				<div class="bill-sponsor">Sponsor</div>
				<div class="bill-sponsor-other"><?php echo $data['main_sponsor_name'];?></div>
			<?php endif; ?>
		</div>
		
	</td>
	<td class="<?php echo $const_no_votes?>"> 
		<h3 class="active-list-header">Your Constituents' Positions</h3>
		<div class="pieContainer"> 
			<div class="aye"><?php echo $row->votes['const_aye']; ?></div>
			<div class="nay"><?php echo $row->votes['const_nay']; ?></div>
			<div class="pieBackground"></div> 
			<div id="pieSlice1" class="hold"> 
				<div class="pie"></div> 
			</div> 
		</div>
		<div class="pie-legend">
			<div class="yes-votes">
				<div class="yes-value"><?php echo $row->votes['const_aye']; ?></div>
				<div class="option-label">aye</div>
			</div>
			<div class="no-votes">
				<div class="no-value"><?php echo $row->votes['const_nay']; ?></div>
				<div class="option-label">Nay</div>
			</div>
		</div>
	</td>
	<td class="<?php echo $total_no_votes?>">
		<?php if(($data['main_sponsor'] === TRUE) || ($data['co_sponsor'] === TRUE)):?>
			<h3 class="active-list-header">All Votes</h3>
			<div class="pieContainer"> 
				<div class="aye"><?php echo $row->votes['all_aye']; ?></div>
				<div class="nay"><?php echo $row->votes['all_nay']; ?></div>
				<div class="pieBackground"></div> 
				<div id="pieSlice1" class="hold"> 
					<div class="pie"></div> 
				</div> 
			</div>
			<div class="pie-legend">
				<div class="yes-votes">
					<div class="yes-value"><?php echo $row->votes['all_aye']; ?></div>
					<div class="option-label">aye</div>
				</div>
				<div class="no-votes">
					<div class="no-value"><?php echo $row->votes['all_nay']; ?></div>
					<div class="option-label">Nay</div>
				</div>
			</div>
		<?php endif;?>
	</td>
</tr>