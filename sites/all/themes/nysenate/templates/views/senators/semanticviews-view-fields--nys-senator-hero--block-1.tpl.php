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

?>
<div class="<?php echo $fields['field_pallette_selector']->content;?>">
<div class="<?php print $classes; ?>">
  <div class="l-header-region l-row l-row--hero c-senator-hero">
    <div class="c-senator-hero--img">
      <?php print $fields['field_image_hero']->content; ?>
    </div>
    <div class="c-senator-hero--info">
        <h2 class="c-senator-hero--title"><?php if($fields['field_active']->content !== 'active'): ?>former <?php endif; ?>new york state senator</h2>
        <h3 class="c-senator-hero--name"><?php echo $fields['title']->content;?></h3>
    </div>
    <?php if($fields['field_active']->content === 'active'): ?>
      <a class="c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg" href="/contact/">contact senator</a>
    <?php else: ?>
      <a class="c-block--btn c-senator-hero--contact-btn icon-before__find-senator med-bg" href="/contact/">find your senator</a>
    <?php endif; ?>
  </div>
</div><?php /* class view */ ?>
</div>

