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

if (isset($row->_field_data['nid']['entity']->field_media_inquiries[LANGUAGE_NONE][0])) {
  $media_inquiries = $row->_field_data['nid']['entity']->field_media_inquiries[LANGUAGE_NONE][0];
  extract($media_inquiries);
}
?>
<?php if(!empty($media_inquiries)) { ?>
  <section class="c-block c-block-download">
    <hr class="lgt-bg">
    <h2 class="c-download--title">media inquiries</h2>
    
    <?php if(!empty($contact_name)): ?>
    <div class="c-download-contact-block c-download-contact-block-1">
      <h3 class="c-download-contact--name"><?php print $row->_field_data['nid']['entity']->title; ?></h3>
     
    </div>
    <?php endif; ?>
    <div class="c-download-contact-block c-download-contact-block-2">
      <?php if (!empty($contact_name)): ?><p class="c-download-contact--title"><?php print $contact_name; ?></p><?php endif; ?>
      <?php if (!empty($email)) { ?><a class="c-download-contact--email" href="mailto:<?php print $email; ?>"><?php print $email; ?></a><?php } ?>
      <?php if (!empty($phone)) { ?><p class="c-download-contact--phone"><span>Phone: </span><?php print $phone; ?></p><?php } ?>
      <?php if (!empty($fax)) { ?><p class="c-download-contact--fax"><span>Fax: </span><?php print $fax; ?></p><?php } ?>
    </div>
    <div class="c-download-contact-block c-download-contact-block-3">


    <?php if(!empty($name)): ?>
      <p class="c-download-location-name"><?php print $name; ?></p>  
    <?php endif; ?>
    <?php if (!empty($street) || !empty($additional)): ?>
          <div>
            <p itemprop="streetAddress"><?php print $street; ?></p>
            <?php if (!empty($additional)): ?>
              <p itemprop="streetAddress">
                <?php print ' ' . $additional; ?>
              </p>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      
      <?php if(!empty($city) && !empty( $postal_code)): ?>
        <p><?php print $city . ', ' . $province . ' ' . $postal_code; ?></p>
      <?php endif; ?>
      
    </div>
    <?php
    if (!empty($fields['field_press_kit']->content)) {
    ?>
    <a class="c-block--btn" href="<?php echo $fields['field_press_kit']->content; ?>" target="_blank">download press kit</a>
    <?php
    }
}
    ?>  
  </section>
  <!-- end download full-width -->
