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

<?php if(isset($fields['field_media_inquiries'])): ?>
	<div class="c-block c-block--senator-media">
		<h4 class="c-office-info--title">media inquiries</h4> 
		<div class="l-col l-col-2">
			<ul class="c-senator-media--contact">
				<?php if(isset($fields['contact_name'])): ?>
					<li class="c-senator-media--item"><?php print $fields['contact_name']->raw; ?></li>
				<?php endif; ?>
				<?php if(isset($fields['email'])): ?>
					<li class="c-senator-media--item"><a href="mailto:<?php print $fields['email']->raw; ?>"><?php print $fields['email']->raw; ?></a></li>
				<?php endif; ?>
				<?php if(isset($fields['phone'])): ?>
					<li class="c-senator-media--item">Phone: <?php print $fields['phone']->raw; ?></li>
				<?php endif; ?>
				<?php if(isset($fields['fax'])): ?>
					<li class="c-senator-media--item">Fax: <?php print $fields['fax']->raw; ?></li>
				<?php endif; ?>
			</ul>
		</div>
	</div>
<?php endif; ?>

