<?php
/**
* @file semanticviews-view-fields.tpl.php
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
<?php if($fields['type']->content === 'Article'): ?>
	<h3 class="c-title">Story</h3>
	<?php if(isset($fields['field_image_main']->content)): ?>
		<div class="c-newsroom-image">
			<?php echo $fields['field_image_main']->content; ?>
		</div>
	<?php endif; ?>
	<div class="c-newsroom-name"><?php echo $fields['title']->content; ?></div>
	<a href="" class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></a>
<?php elseif($fields['type']->content === 'Video'): ?>
	<h3 class="c-title">Video</h3>
	<?php if(isset($fields['field_yt']->content)): ?>
		<div class="c-newsroom-image">
			<?php echo $fields['field_yt']->content; ?>
		</div>
	<?php endif; ?>
	<p class="c-newsroom-name"><?php echo $fields['title']->content; ?></p>
	<a href="" class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></a>
<?php elseif($fields['type']->content === 'Press Release'): ?>
	<h3 class="c-title"><?php echo $fields['type']->content; ?></h3>
	<?php if(isset($fields['field_image_main']->content)): ?>
		<div class="c-newsroom-image">
			<?php echo $fields['field_image_main']->content; ?>
		</div>
	<?php endif; ?>
	<div class="c-newsroom-name"><?php echo $fields['title']->content; ?></div>
	<a href="" class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></a>
<?php else: ?>
		<h3 class="c-title"><?php echo $fields['type']->content; ?></h3>
		<?php if(isset($fields['field_image_main']->content)): ?>
			<div class="c-newsroom-image">
				<?php echo $fields['field_image_main']->content; ?>
			</div>
		<?php endif; ?>
		<div class="c-newsroom-name"><?php echo $fields['title']->content; ?></div>
		<a href="" class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></a>
<?php endif; ?>
