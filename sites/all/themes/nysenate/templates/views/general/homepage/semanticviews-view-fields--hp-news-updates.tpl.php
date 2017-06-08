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

$associated_senators_array = explode(", ", $fields['field_associated_senator']->content);
$associated_senators_count = count($associated_senators_array);
?>
<?php if($fields['type']->content === 'Article'): ?>
	<div class="c-title">Story <span class="c-news-date"><?php echo $fields['field_date']->content; ?></span></div> 
	
	<?php if(isset($fields['field_image_main']->content)): ?>
		<div class="c-newsroom-image">
			<?php echo $fields['field_image_main']->content; ?>
		</div>
	<?php endif; ?>
	<h3 class="c-newsroom-name"><?php echo $fields['title']->content; ?></h3>
	<div class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></div>
	<?php if(isset($fields['field_senator']->content)): ?>
		<div class="c-senator-card">
			<?php echo $fields['field_senator']->content; ?>
		</div>
	<?php endif; ?>
	
<?php elseif($fields['type']->content === 'Video'): ?>
	<div class="c-title">Video <span class="c-news-date"><?php echo $fields['field_date']->content; ?></span></div>
	<?php if(isset($fields['field_yt']->content)): ?>
		<div class="c-newsroom-image">
			<?php echo $fields['field_yt']->content; ?>
		</div>
	<?php endif; ?>
	<h3 class="c-newsroom-name"><?php echo $fields['title']->content; ?></h3>
	<div class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></div>
	<?php if(isset($fields['field_senator']->content)): ?>
		<div class="c-senator-card">
			<?php echo $fields['field_senator']->content; ?>
		</div>
	<?php endif; ?>
<?php elseif($fields['type']->content === 'Press Release'): ?>
	<div class="c-title"><?php echo $fields['type']->content; ?> <span class="c-news-date"><?php echo $fields['field_date']->content; ?></span></div>
	<?php if(isset($fields['field_image_main']->content)): ?>
		<div class="c-newsroom-image">
			<?php echo $fields['field_image_main']->content; ?>
		</div>
	<?php endif; ?>	
	<h3 class="c-newsroom-name"><?php echo $fields['title']->content; ?></h3>
	<div class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></div>
	<?php if(isset($fields['field_associated_senator']->content)): ?>
		<div class="c-senator-card">
			<h4 class="nys-senator--involved"><?php echo count($associated_senators_array).' Senators Involved'; ?></h4>
		</div>
	<?php elseif(isset($fields['field_senator']->content) && !isset($fields['field_associated_senator']->content)): ?>
		<div class="c-senator-card">
			<?php echo $fields['field_senator']->content; ?>
		</div>
	<?php else: ?>
		<div class="c-senator-card">
			<?php echo $fields['field_senator']->content; ?>
		</div>
	<?php endif; ?>
<?php else: ?>
		<div class="c-title"><?php echo $fields['type']->content; ?> <span class="c-news-date"><?php echo $fields['field_date']->content; ?></span></div>
		<?php if(isset($fields['field_image_main']->content)): ?>
			<div class="c-newsroom-image">
				<?php echo $fields['field_image_main']->content; ?>
			</div>
		<?php endif; ?>
		<h3 class="c-newsroom-name"><?php echo $fields['title']->content; ?></h3>
		<div class="c-newsroom-link"><?php echo $fields['term_node_tid']->content; ?></div>
		<?php if(isset($fields['field_senator']->content)): ?>
		<div class="c-senator-card">
			<?php echo $fields['field_senator']->content; ?>
		</div>
		<?php endif; ?>
<?php endif; ?>
