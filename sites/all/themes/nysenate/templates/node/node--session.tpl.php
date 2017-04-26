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
<!-- AddThisEvent Settings -->
<?php if (!empty($field_live_message_override[0]['value'])): ?>
  <section class="l-messages">
    <div data-alert="" class="alert-box success">
      <div class="alert-box-message">
      <h2 class="element-invisible">Status message</h2>
      <?php echo $field_live_message_override[0]['value']; ?><a href="#" class="close">×</a>
      </div>
    </div>
  </section>
  <?php elseif (!empty($field_live_message_status[0]['value'])): ?>
  <section class="l-messages">
    <div data-alert="" class="alert-box success">
      <div class="alert-box-message">
      <h2 class="element-invisible">Status message</h2>
      <?php print render($content['field_live_message_status']); ?>
      <a href="#" class="close">×</a>
      </div>
    </div>
  </section>
<?php endif; ?>

<div class="c-block c-meeting-detail--header">

  <div class="c-meeting-detail--meta">
    <?php if (!empty($field_event_status) && $field_event_status[0]['value'] === "live_now"): ?>
      <p class="c-meeting-detail--live-flag"><?php print render($content['field_event_status']); ?></p>
    <?php endif; ?>
    <?php if (!empty($field_off_the_floor) && $field_off_the_floor[0]['value'] === "1"): ?>
    <p class="c-meeting-detail--floor-flag">off the floor</p>
    <?php endif; ?>
  </div>

  <div class="c-meeting-detail--overview">
    <p class="c-meeting-detail--date">
      <?php if (!empty($field_date)): ?>
      <span class="c-meeting-date--num">
        <?php echo date("d", $field_date[0]['value']); ?>
      </span>
      <span class="c-meeting-date--month">
        <?php echo date("M", $field_date[0]['value']); ?>
      </span>
      <span class="c-meeting-date--year">
        <?php echo date("Y", $field_date[0]['value']); ?>
      </span>
    <?php endif; ?>
    </p>

    <div class="c-meeting-detail--info">
      <h2 class="c-meeting-detail--title">
        <?php print $title; ?>
      </h2>
      <a class="c-meeting-detail--location-link" href="https://www.google.com/maps/place/New+York+State+Capitol/@42.652602,-73.757388,17z/data=!3m1!4b1!4m2!3m1!1s0x89de0a3aa5dc0b2b:0x72aed557f8df2510" title="NYS Capitol Building" target="_blank" >NYS Capitol Building</a>
      <p class="c-meeting-detail--location">
        <?php if (!empty($field_location[0]['name'])): echo $field_location[0]['name']; endif; ?>
        <?php if (!empty($field_location[0]['street'])): echo $field_location[0]['street']; endif; ?>
        <?php if (!empty($field_location[0]['additional'])): echo $field_location[0]['additional']; endif; ?>
        <?php if (!empty($field_location[0]['city'])): echo $field_location[0]['city']; endif; ?>
        <?php if (!empty($field_location[0]['postal_code'])): echo $field_location[0]['postal_code']; endif; ?>
        <?php if (!empty($field_location[0]['state'])): echo $field_location[0]['state']; endif; ?>
      </p>
      <p class="c-meeting-detail--time">
        <?php if (!empty($field_date)): echo date("g:i A ", $field_date[0]['value']);?> to <?php echo date("g:i A ", $field_date[0]['value2']); endif; ?>
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
        <span class="location"><?php echo $node->field_location[LANGUAGE_NONE][0]['name'];?></span>
        <span class="date_format">MM/DD/YYYY</span>
        <span class="organizer">NY STATE SENATE</span>
      </div>
    </div>

    <div class="c-meeting-detail--descript">
      <?php print render($content['body']);?>
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

    <?php if ($field_video_status[0]['value'] === "streaming_live_now" && !empty($field_ustream)): ?>
    <div class="c-meeting-detail--descript">
      <?php print render($content['field_ustream']); ?>
    </div>
    <?php elseif ($field_video_status[0]['value'] === "streaming_redirect" && !empty($field_video_redirect)): ?>
      <?php print render($content['field_ustream']); ?>
    <?php endif; ?>

    <?php if (!empty($content['field_yt'])):?>
    <div class="c-meeting-detail--descript">
      <?php print render($content['field_yt']); ?>
    </div>
    <?php endif; ?>

  </div>
</div>
