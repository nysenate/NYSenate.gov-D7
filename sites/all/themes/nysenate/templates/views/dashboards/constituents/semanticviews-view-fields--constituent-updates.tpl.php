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
<?php if($fields['type']->content === 'bill' || $fields['type']->content === 'resolution'): ?>
<article>
  <div class="meta">
    <div class="section"><?php echo $fields['type_1']->content.' '.strip_tags($fields['title']->content); ?></div>
      <div class="issue-type">
          <?php echo $fields['term_node_tid']->content; ?>
      </div>
  </div>
  <div class="body">
    <h3 class="entry-title"><a href="<?php echo $fields['path']->content?>"><?php echo $fields['field_ol_name']->content; ?></a></h3>
    <?php if (isset($row->graph_html)) echo $row->graph_html; // See /sites/all/themes/template.php ?>
    <div class="article-date">
      <?php echo $fields['field_ol_publish_date']->content; ?>
      <?php if(isset($fields['field_ol_latest_status_committee']->content)):?>
        | <span class="issue-type">In <?php echo $fields['field_ol_latest_status_committee']->content; ?> Committee</span>
      <?php endif; ?>
    </div>
  </div>
</article>
<?php elseif($fields['type']->content === 'event'|| $fields['type']->content === 'meeting' || $fields['type']->content === 'session' || $fields['type']->content === 'public_hearing'): ?>
<article class="last">
  <div class="meta">
    <div class="section"><?php echo $fields['type_1']->content; ?></div>
      <div class="issue-type">
          <?php echo $fields['term_node_tid']->content; ?>
      </div>
  </div>
  <div class="body">
    <?php if ($fields['field_image_main']->content): ?>
      <?php echo $fields['field_image_main']->content; ?>
    <?php endif; ?>
    <h3 class="entry-title"><?php echo $fields['title']->content; ?></h3>
    <?php if($fields['field_date']->content): ?>
      <div class="article-date">
        <?php echo $fields['field_date']->content; ?>
          <?php if(isset($fields['field_committee']->content) && !in_array($fields['type']->content, array('meeting', 'article'))):?>
            | <span class="issue-type">
                <?php if($fields['type']->content != 'public_hearing'):?>In <?php endif;?>
                <?php echo $fields['field_committee']->content; ?>
              </span>
          <?php endif; ?>
      </div>
    <?php endif; ?>
    <?php if(isset($fields['field_meeting_location']->content)):?><div class="event-location icon-before__circle-pin"><?php echo $fields['field_meeting_location']->content;?></div><?php endif; ?>
    <?php if(isset($fields['field_date_1']->content)):?><div class="event-date-time"><?php echo $fields['field_date_1']->content;?></div><?php endif; ?>
  </div>
</article>
<?php else: ?>
<article>
  <div class="meta">
    <div class="section"><?php echo $fields['type_1']->content; ?></div>
    <div class="issue-type">
        <?php echo $fields['term_node_tid']->content; ?>
    </div>
  </div>
  <div class="body">
    <?php if ($fields['field_image_main']->content): ?>
      <?php echo $fields['field_image_main']->content; ?>
    <?php endif; ?>
    <h3 class="entry-title"><?php echo $fields['title']->content; ?></h3>
    <?php if ($fields['field_senator']->content): ?>
      <div class="author"><?php echo 'By: '. $fields['field_senator']->content; ?></div>
    <?php endif; ?>
    <?php if (isset($fields['field_author']->content) && $fields['field_author']->content): ?>
      <div class="author"><?php echo 'By: '. $fields['field_author']->content; ?></div>
    <?php endif; ?>
    <?php if($fields['field_date']->content): ?>
      <div class="article-date">
        <?php echo $fields['field_date']->content; ?>
        <?php if(isset($fields['field_committee']->content) && !in_array($fields['type']->content, array('meeting', 'article'))): ?>
         | <span class="issue-type">In <?php echo $fields['field_committee']->content; ?></span>
       <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>
</article>
<?php endif; ?>
