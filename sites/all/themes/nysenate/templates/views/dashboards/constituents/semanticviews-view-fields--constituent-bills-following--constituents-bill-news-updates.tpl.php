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
<?php if($fields['type_1']->content === 'bill' || $fields['type_1']->content === 'resolution'): ?>
<article>
  <div class="meta">
    <div class="section">Bill S7876</div>
    <div class="issue-type">Common Core</div>
  </div>
  <div class="body">
    <h3 class="entry-title">Relates to implementing Common Core standards in the classroom.</h3>
    <div class="timeline">
      <div class="strike"></div>
      <div class="steps">
        <div class="step passed"></div>
        <div class="step passed"></div>
        <div class="step passed"></div>
        <div class="step current">
          <div class="curr-step-top"></div>
          <div class="curr-step-bottom"></div>
        </div>
        <div class="step"></div>
        <div class="step"></div>
      </div>
    </div>
    <div class="article-date">July 22, 2014</div>
    <div class="article-committee">In Education Committee</div>
  </div>
</article>
<?php elseif($fields['type_1'] === 'event'|| $fields['type_1'] === 'meeting' || $fields['type_1'] === 'session'): ?>
<article class="last">
  <div class="meta">
    <div class="section"><?php echo $fields['type']->content; ?></div>
    <div class="issue-type"><?php echo $fields['field_committee']->content; ?></div>
    <div class="issue-type"><?php echo $fields['field_issues']->content; ?></div>
  </div>
  <div class="body">
    <?php if ($fields['field_image_main']->content): ?>
      <?php echo $fields['field_image_main']->content; ?>
    <?php endif; ?>
    <h3 class="entry-title"><?php echo $fields['title']->content; ?></h3>
    <?php if($fields['field_date']->content): ?>
      <div class="article-date"><?php echo $fields['field_date']->content; ?></div>
    <?php endif; ?>
    <div class="event-location icon-before__circle-pin">Change Me: Carmel Town Hall</div>
    <div class="event-date-time">Change Me: 9:00 AM</div>
  </div>
</article>
<?php else: ?>
<article>
  <div class="meta">
    <div class="section"><?php echo $fields['type']->content; ?></div>
    <div class="issue-type"><?php echo $fields['field_issues']->content; ?></div>
    <div class="issue-type"><?php echo $fields['field_committee']->content; ?></div>
  </div>
  <div class="body">
    <?php if ($fields['field_image_main']->content): ?>
      <?php echo $fields['field_image_main']->content; ?>
    <?php endif; ?>
    <h3 class="entry-title"><?php echo $fields['title']->content; ?></h3>
    <?php if ($fields['field_senator']->content): ?>
      <div class="author"><?php echo 'By: '. $fields['field_senator']->content; ?></div>
    <?php endif; ?>
    <?php if ($fields['field_author']->content): ?>
      <div class="author"><?php echo 'By: '. $fields['field_author']->content; ?></div>
    <?php endif; ?>
    <?php if($fields['field_date']->content): ?>
      <div class="article-date"><?php echo $fields['field_date']->content; ?></div>
    <?php endif; ?>
  </div>
</article>
<?php endif; ?>
