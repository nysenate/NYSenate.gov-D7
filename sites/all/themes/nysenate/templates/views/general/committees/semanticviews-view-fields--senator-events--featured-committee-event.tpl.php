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
//var_dump($fields);exit;
?>
<div class="c-event-block c-event-block--list">
  <?php if($fields['field_event_status']->content == 'live_now'): ?>
  <div class="c-title c-meeting-detail--live-flag">Live Now</div>
  <?php elseif($fields['field_event_status']->content == 'upcoming'): ?>
    <div class="c-title">Upcoming Event</div>
  <?php elseif(!is_null($fields['field_event_status']->content)): ?>
    <div class="c-title">Meeting Archive</div>
  <?php endif; ?>
  <div class="c-event-date"><span><?php echo $fields['field_date']->content;?></span> <?php echo $fields['field_date_1']->content;?></div>
  <div class="c-wrapper">
    <a href="<?php echo $fields['path']->content;?>"><h3 class="c-event-name"><?php echo $fields['title']->content;?></h3></a>
    <div class="c-category"><?php echo $fields['field_issues']->content;?></div>
    <?php if(!empty($fields['field_meeting_location']->content)):?>
      <a class="c-event-location" href="http://maps.google.com/?q=<?php echo $fields['field_meeting_location']->content;?>" target="_blank">
        <span class="icon-before__circle-pin"></span><?php echo $fields['field_meeting_location']->content;?>
      </a>
    <?php endif; ?>
    <?php if(!empty($fields['street']->content)):?>
      <div class="c-event-address"><?php echo $fields['street']->content;?></div>
    <?php endif; ?>
    <div class="c-event-time">
      <?php echo $fields['field_date_2']->content;?>
      <?php if(!empty($fields['field_video_status']->content)): ?>
        <span class="c-meeting-video--status icon-before__youtube"><?php print $fields['field_video_status']->content; ?></span>
      <?php endif; ?>
    </div>
  </div>
</div>