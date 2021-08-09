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

<div class="c-block c-meeting-detail--header">

    <div class="c-meeting-detail--meta">
    <?php if($fields['field_event_status']->content === "live_now"): ?>
      <p class="c-meeting-detail--live-flag">live now</p>
    <?php endif; ?>
    <?php if($fields['field_off_the_floor']->content === "1"): ?>
    <p class="c-meeting-detail--floor-flag">off the floor</p>
    <?php endif; ?>
  </div>



	<div class="c-meeting-detail--overview">
		<p class="c-meeting-detail--date">
			<span class="c-meeting-date--num">
				<?php print $fields['field_date_1']->content; ?>
			</span>
			<span class="c-meeting-date--month">
				<?php print $fields['field_date']->content; ?>
			</span>
		</p>

		<div class="c-meeting-detail--info">
			<h2 class="c-meeting-detail--title">
				<?php print $fields['title']->content; ?>
			</h2>
			<a class="c-meeting-detail--location-link" href="https://www.google.com/maps/place/New+York+State+Capitol/@42.652602,-73.757388,17z/data=!3m1!4b1!4m2!3m1!1s0x89de0a3aa5dc0b2b:0x72aed557f8df2510" title="NYS Capitol Building" target="_blank" >NYS Capitol Building</a>
			<p class="c-meeting-detail--location">
				<?php print $fields['field_meeting_location']->content; ?>
			</p>
			<p class="c-meeting-detail--time">
				<?php print $fields['field_date_2']->content; ?>
				<?php if(!empty($fields['field_video_status']->content)): ?>
					<span class="c-meeting-video--status icon-before__youtube"><?php print $fields['field_video_status']->content; ?></span>
				<?php endif; ?>	
			</p>
			
		</div>

		<div class="c-meeting-detail--descript">
			<?php print $fields['body']->content; ?>
		</div>

		<div class="c-meeting-detail--related">
			<p>related issues: </p>
			<?php print $fields['field_issues']->content; ?>
		</div>
	</div>
</div>
