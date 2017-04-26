<?php
/**
 * @file
 * Default simple view template to display all the fields as a row. The template
 * outputs a full row by looping through the $fields array, printing the field's
 * HTML element (as configured in the UI) and the class attributes. If a label
 * is specified for the field, it is printed wrapped in a <label> element with
 * the same class attributes as the field's HTML element.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output
 *     safe.
 *   - $field->element_type: The HTML element wrapping the field content and
 *     label.
 *   - $field->attributes: An array of attributes for the field wrapper.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use var_export to dump this object, as it can't handle the
 *     recursion.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @see template_preprocess_semanticviews_view_fields()
 * @ingroup views_templates
 * @todo Justify this template. Excluding the PHP, this template outputs angle
 * brackets, the label element, slashes and whitespace.
 */
?>
<?php
if(isset($fields['field_committee_member_role']->content)) {
	if($fields['field_committee_member_role']->content == 'Other') $position = $fields['field_other_member_role']->content;
	else if($fields['field_committee_member_role']->content == 'Member') $position = '';
	else $position = $fields['field_committee_member_role']->content;

	$co_chair_class = '';
	if(strpos(strtolower($fields['field_committee_member_role']->content), 'other') !== FALSE) $co_chair_class = 'co-chair';
}
?>
<a href="<?php echo $fields['path']->content;?>">
	<div class="c-senator-block c-senator-block--committee <?php echo $co_chair_class ?>">
		<div class="nys-senator--thumb">
			<?php echo _nyss_img($fields['uri']->content, '160x160', array()); ?>
		</div>
		<div class="nys-senator--info">
			<?php if(isset($position)):?>
				<h3 class="nys-senator--position"><?php echo $position; ?></h3>
			<?php endif; ?>
			<h4 class="nys-senator--name"><?php echo $fields['title']->content;?></h4>
			
			<?php
				$party = $fields['field_party']->content;
				if(!empty($party)) $associations = explode(', ', $party);

				$conference_parts = explode (" ",$fields['field_conference']->content);			
				$conference ="";
				foreach($conference_parts as $index=>$part)
					if(($index != 0) && ($index%2 == 1)) $associations[] = substr($conference_parts[$index-1],0,1).substr($part,0,1);

				// if(!empty($associations)) echo '('.implode(', ', $associations).')';
			?>
				<?php if(!empty($associations)):?>
					<span class="nys-senator--party">
						<?php echo '('.implode(', ', $associations).')'; ?>	
					</span>	
				<?php endif; ?>	

				<?php if(isset($fields['field_district_number']->content)):?>
					<span class="nys-senator--district">
						District <?php echo $fields['field_district_number']->content;?>
					</span>
				<?php endif; ?>
			</span>
		</div>
		
	</div>
</a>