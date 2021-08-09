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
//dpm $fields;
?>
<div class="c-event-block c-event-block--list">
	<div class="c-event-date"><span><?php if (!empty($field_date_day)) echo $field_date_day;?></span> <?php if (!empty($field_date_month)) echo $field_date_month;?></div>
	<?php if (!empty($path->content) && !empty($title->content)): ?><a href="<?php echo $path->content;?>"><h3 class="c-event-name"><?php echo $title->content; ?></h3></a><?php endif; ?>
	<?php if (!empty($name->content)): ?><a class="c-event-location" target="_blank"><span class="icon-before__circle-pin"></span><?php echo $name->content; ?></a><?php endif; ?>
	<div class="c-event-time">
    <div class="c-location">
      <?php echo $fields['city']->content;?>, <?php echo $fields['province']->content;?>
    </div>
		<?php if (!empty($fields['field_date_2']->content)): ?>
			<span><?php echo $fields['field_date_2']->content;?></span>
		<?php endif; ?>
    </div>
    <?php if (!empty($fields['field_yt']->content)): ?>
      <div class="c-event-video">
        <span class="c-meeting-video--status icon-before__youtube">Archived Video</span><br>
        <?php echo $fields['field_yt']->content;?>
      </div>
    <?php endif; ?>
</div>