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
$node_url = url('node/'.$row->nid, array('absolute' => TRUE));
$node_title = $row->node_title;
foreach ($fields as $id => $field){

	switch($id) {
		case 'title': $data['title'] = '<a href="'.$node_url.'">'.$row->node_title.'</a>'; break;
		case 'field_date': $data['field_date'] = $row->field_field_date[0]['rendered']['#markup']; break;
		case 'webform_submission_count_node': $data['count'] = $row->webform_count; break;
	}
} 
?>
<div class="poll-container">
	<div class="poll-main-info">
		<h3><?php echo $data['title']; ?></h3>
		<div class="poll-create-date">Created on <?php echo $data['field_date']; ?></div>
		<div class="poll-share-bar">
			<p>Promote this questionnaire</p>
			<a href="https://www.facebook.com/sharer/sharer.php?u=<?php echo $node_url;?>" class="poll-facebook-share icon-after__facebook"></a>
			<a href="http://twitter.com/share?url=<?php echo $node_url;?>&text=<?php echo $node_title;?>" class="poll-twitter-share icon-after__twitter"></a>
		</div>
	</div>
	<div class="poll-results">
		<?php $total_percent = ($data['count'] < 1) ? 1 : 100; ?>
		<?php $percent = ($data['count'] < 1) ? 1 : (($row->constituent_count == 0) ? 1 : ($row->constituent_count/$data['count']*100)); ?>
		<?php if($row->main_sponsor):?>
			<div class="result-container result-1" style="width:<?php echo $total_percent?>%"><span><?php echo $data['count'];?></span></div>
			<label>All Responses</label>
		<?php endif; ?>
		<div class="result-container result-2" style="width:<?php echo $percent?>%" ><span><?php echo $row->constituent_count;?></span></div>
		<label>Your Constituents' Responses</label>
	</div>
	<div class="poll-signature">
		<?php if($row->constituent_count > 0):?>
			<div class="poll-signature-header pager-load-more icon-after__see-more"><?php //echo $data['count']; ?>Constituents' Responses</div>
			<div class="poll-signature-list">
				<div class="user-list"><?php print $row->user_list; ?></div>
			</div>
		<?php else: ?>
			<div class="poll-signature-header pager-load-more"><?php //echo $data['count']; ?>Sorry there are no Constituents' Responses.</div>
		<?php endif; ?>
	</div>
</div>