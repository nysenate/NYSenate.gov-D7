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
//var_dump($fields['field_image_main']);exit;
?>
<?php if(isset($fields['image_main']->content)):?>
<div class="c-event-block c-event-block--list">
  <div class="c-event-date"><span><?php echo $fields['field_date']->content;?></span> <?php echo $fields['field_date_1']->content;?></div>
  <a href="<?php echo $fields['path']->content;?>"><h3 class="c-event-name"><?php echo $fields['title']->content;?></h3></a>
  <a class="c-event-location" href="http://maps.google.com/?q=<?php echo $fields['street']->content;?>+<?php echo $fields['city']->content;?>%2C+<?php echo $fields['province']->content;?>%2C+<?php echo $fields['postal_code']->content;?>" target="_blank">
    <span class="icon-before__circle-pin"></span><?php echo $fields['name']->content;?>
  </a>
  <div class="c-event-address"><?php echo $fields['street']->content;?><br/><?php echo $fields['city']->content;?>, <?php echo $fields['province']->content;?> <?php echo $fields['postal_code']->content;?></div>
  <div class="c-event-time"><?php echo $fields['field_date_2']->content;?></div>
</div>
<?php else: ?>
  <div class="c-event-block c-event-block--featured-image">
    <div class="c-title">Featured Event</div>
    <div class="c-event-image"><?php echo $fields['field_feature_image']->content; ?></div>
    <div class="c-event-date">
      <span><?php echo $fields['field_date']->content;?></span> <?php echo $fields['field_date_1']->content;?>
    </div>
    <a href="<?php echo $fields['path']->content;?>">
      <h3 class="c-event-name"><?php echo $fields['title']->content;?></h3>
    </a>
    <a class="c-event-location" href="http://maps.google.com/?q=<?php echo $fields['street']->content;?>+<?php echo $fields['city']->content;?>%2C+<?php echo $fields['province']->content;?>%2C+<?php echo $fields['postal_code']->content;?>" target="_blank">
      <span class="icon-before__circle-pin"></span><?php echo $fields['name']->content;?>
    </a>
    <div class="c-event-address"><?php echo $fields['street']->content;?><br/><?php echo $fields['city']->content;?>, <?php echo $fields['province']->content;?> <?php echo $fields['postal_code']->content;?></div>
    <div class="c-event-time"><?php echo $fields['field_date_2']->content;?></div>
  </div>
  <!-- end Featured With Image -->
<?php endif; ?>