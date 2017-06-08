<?php
/**
 * @file
 * Default simple view template to display all the fields as a row.
 *
 * The template outputs a full row by looping through the $fields array, printing
 * the field's HTML element (as configured in the UI) and the class attributes. If
 * a label is specified for the field, it is printed wrapped in a <label> element with
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
 *
 * @ingroup views_templates
 *
 * @todo Justify this template. Excluding the PHP, this template outputs angle
 *
 * brackets, the label element, slashes and whitespace.
 */

?>
<article class="c-block c-meeting-detail--header">
  <div class="c-meeting-detail--meta">
    <?php if ($field_event_status[0]['value'] === "live_now"): ?>
    <p class="c-meeting-detail--live-flag"><?php print render($content['field_event_status']); ?></p>
    <?php endif; ?>
    <?php if ($field_off_the_floor[0]['value'] === "1"): ?>
    <p class="c-meeting-detail--floor-flag">off the floor</p>
    <?php endif; ?>
  </div>

  <div class="c-meeting-detail--overview">
    <div class="c-block">
      <p class="c-meeting-detail--date">
        <span class="c-meeting-date--num">
          <?php echo date("d", $field_date[0]['value']);?>
        </span>
        <span class="c-meeting-date--month">
          <?php echo date("M", $field_date[0]['value']);?>
        </span>
        <span class="c-meeting-date--year">
          <?php echo date("Y", $field_date[0]['value']);?>
        </span>

      </p>

      <div class="c-meeting-detail--info">
        <h1 class="c-meeting-detail--title">
          <?php print $title; ?>
        </h1>
        <a class="c-meeting-detail--location-link" href="https://www.google.com/maps/place/New+York+State+Capitol/@42.652602,-73.757388,17z/data=!3m1!4b1!4m2!3m1!1s0x89de0a3aa5dc0b2b:0x72aed557f8df2510" title="NYS Capitol Building" target="_blank" >NYS Capitol Building</a>
        <p class="c-meeting-detail--location">
          <?php if (!empty($field_meeting_location[0]['value'])): print $field_meeting_location[0]['value']; endif; ?>
        </p>
        <p class="c-meeting-detail--time">
          <?php echo date("g:i A ", $field_date[0]['value']);?> to <?php echo date("g:i A ", $field_date[0]['value2']); ?>
          <?php if (!empty($field_video_status) && $field_video_status[0]['value'] != 'streaming_redirect'): ?>
            <span class="c-meeting-video--status icon-before__youtube"><?php print render($content['field_video_status']); ?></span>
          <?php endif; ?>
        </p>
        <div title="Add to Calendar" class="addthisevent">
          Add to Calendar
          <span class="start"><?php print format_date($node->field_date[LANGUAGE_NONE][0]['value'], "custom", "m/d/Y"); ?> <?php print format_date($node->field_date[LANGUAGE_NONE][0]['value'], "custom", "g:i A"); ?></span>
          <span class="end"><?php print format_date($node->field_date[LANGUAGE_NONE][0]['value2'], "custom", "m/d/Y"); ?> <?php print format_date($node->field_date[LANGUAGE_NONE][0]['value2'], "custom", "g:i A"); ?></span>
          <span class="timezone">America/New_York</span>
          <span class="title"><?php print $title; ?></span>
          <span class="location"><?php echo $node->field_meeting_location[LANGUAGE_NONE][0]['safe_value'];?></span>
          <span class="date_format">MM/DD/YYYY</span>
          <span class="organizer">NY STATE SENATE</span>
          <span class="organizer_email">content@senate.state.ny.us</span>
        </div>
      </div>

      <div class="c-meeting-detail--descript">
        <?php if (!empty($body[0]['value'])): print check_markup($body[0]['value'], 'full_html'); endif;?>
      </div>

      <?php if (!empty($content['field_chapters'])):?>
      <div class="c-meeting-detail--descript">
        <?php print render($content['field_chapters']); ?>
      </div>
      <?php endif; ?>

      <?php if (!empty($content['field_issues'])):?>
      <div class="c-meeting-detail--related">
        <p>related issues: </p>
        <?php print render($content['field_issues']); ?>
      </div>
      <?php endif; ?>
      </div>
    </div>
  
      <?php if (!empty($field_video_status) && $field_video_status[0]['value'] === "streaming_live_now" && !empty($field_ustream_url)): ?>
      <div class="c-meeting-detail--descript flex-video">
        <?php print render($content['field_ustream_url']); ?>
      </div>
      <?php elseif (!empty($field_video_status) && $field_video_status[0]['value'] === "streaming_redirect" && !empty($field_video_redirect)): ?>
        <?php print render($content['field_ustream_url']); ?>
      <?php endif; ?>

    <?php if (!empty($content['field_yt'])):?>
    <div class="c-meeting-detail--descript flex-video">
      <?php print render($content['field_yt']); ?>
    </div>
    <?php endif; ?>

</article>
