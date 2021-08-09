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
//dpm($fields);
?>
<?php $city = $fields['city']->content;
        $city = str_replace(' ', '', $city); ?>
<?php $url = $fields['path']->content; ?>
<?php if ($view->current_display == 'page'): ?>
    <div class="c-event-date">
      <?php if ($fields['field_video_status_1']->content !== 'cancelled'): ?>
        <?php echo $fields['field_date_1']->content; ?>
      <?php endif; ?>
    </div>
<?php endif; ?>
<h3 class="c-event-name">
  <?php echo $fields['title']->content; ?>
</h3>
<?php if (!empty($fields['field_senator']->content)): ?>
    <div class="c-senator">
      <?php echo $fields['field_senator']->content; ?>
    </div>
<?php endif; ?>

<?php if ((!empty($fields['name']->content)) && ($fields['field_event_place']->content === 'in_albany' || $fields['field_event_place']->content === 'in_district')): ?>

    <a class="c-event-location"
       href="http://maps.google.com/?q=<?php echo $fields['street']->content; ?>+<?php echo $fields['city']->content; ?>%2C+<?php echo $fields['province']->content; ?>%2C+<?php echo $fields['postal_code']->content; ?>"
       target="_blank">
        <span class="icon-before__circle-pin"></span><?php echo $fields['name']->content; ?>
    </a>
  <?php elseif($fields['type_1']->content === 'Session'):  ?>
    <a class="c-event-location"
       href="http://maps.google.com/?q=<?php echo $fields['street']->content; ?>+<?php echo $fields['city']->content; ?>%2C+<?php echo $fields['province']->content; ?>%2C+<?php echo $fields['postal_code']->content; ?>"
       target="_blank">
        <span class="icon-before__circle-pin"></span><?php echo $fields['name']->content; ?>
    </a>
<?php endif; ?>


<?php if($fields['field_event_place']->content === 'online'): ?>
    <?php if($fields['type_1']->content === 'Public Hearing'): ?>

        <?php if(!empty($fields['field_event_online_link']->content)): ?>
        <a class="c-event-location" href="<?php echo $fields['field_event_online_link']->content; ?>"><span class="icon-before__circle-pin"></span><span>Online Hearing</span></a>
        <?php else: ?>
            <div class="c-event-location"><span class="icon-before__circle-pin"></span><span>Online Hearing</span></div>
        <?php endif; ?>

    <?php elseif($fields['type_1']->content === 'Meeting'): ?>

        <?php if(!empty($fields['field_event_online_link']->content)): ?>
            <a class="c-event-location" href="<?php echo $fields['field_event_online_link']->content; ?>"><span class="icon-before__circle-pin"></span><span>Online Meeting</span></a>
        <?php else: ?>
            <div class="c-event-location"><span class="icon-before__circle-pin"></span><span>Online Meeting</span></div>
        <?php endif; ?>

    <?php elseif($fields['type_1']->content === 'Event'):  ?>
        <a class="c-event-location" href="<?php echo $fields['field_event_online_link']->content; ?>"><span class="icon-before__circle-pin"></span><span>Online Event</span></a>
    <?php endif; ?>

<?php elseif($fields['field_event_place']->content === 'teleconference'): ?>
    <a class="c-event-location" href="<?php echo $fields['path']->content; ?>"><span class="icon-before__circle-pin"></span><span>Teleconference Event</span></a>
<?php elseif($fields['field_event_place']->content === 'cap'): ?>
    <a class="c-event-location" href="https://www.google.com/maps/place/New+York+State+Capitol/@42.652602,-73.757388,17z/data=!3m1!4b1!4m2!3m1!1s0x89de0a3aa5dc0b2b:0x72aed557f8df2510" title="NYS Capitol Building" target="_blank" ><span class="icon-before__circle-pin"></span><span>NYS Capitol Building</span></a>
<?php elseif($fields['field_event_place']->content === 'lob'): ?>
    <a class="c-event-location" href="https://www.google.com/maps/place/Legislative+Office+Building/@42.6526202,-73.7614498,17z/data=!3m1!4b1!4m5!3m4!1s0x89de0a24d3a304b5:0x1012cb31c839dfe9!8m2!3d42.6526202!4d-73.7592611?hl=en" title="Legislative Office Building" target="_blank" ><span class="icon-before__circle-pin"></span><span>Legislative Office Building</span></a>
<?php endif; ?>



<div class="c-event-time">
  <?php if (!empty($fields['field_meeting_location']->content)): ?>
      <div class="c-location"><?php echo $fields['field_meeting_location']->content; ?></div>
  <?php endif; ?>
  <?php if ($fields['field_event_place']->content !== 'online' && $fields['field_event_place']->content !== 'teleconference') { ?>

    <div class="c-location">
      <?php if (!empty($fields['city']->content)) {
        echo $city . ',';
      } ?>
      <?php if (!empty($fields['province']->content)) {
        echo $fields['province']->content;
      } ?>
    </div>
  <?php } ?>

  <?php if ($fields['field_video_status_1']->content === 'cancelled'): ?>
    <?php if (isset($fields['field_video_status']->content)): ?>
          <div><?php echo $fields['field_video_status']->content; ?></div>
    <?php endif; ?>
  <?php else: ?>
    <?php if ($view->current_display != 'page') {
      echo $fields['field_date_1']->content;
    } ?>

    <?php if (isset($fields['field_video_status']->content)): ?>
      <?php if ($view->current_display != 'page'): ?>| <?php endif; ?>
          <div><a class="c-video-status icon-before__youtube"
                  href="<?php echo $url; ?>"><?php echo $fields['field_video_status']->content; ?></a>
          </div>
    <?php endif; ?>
  <?php endif; ?>
</div>
