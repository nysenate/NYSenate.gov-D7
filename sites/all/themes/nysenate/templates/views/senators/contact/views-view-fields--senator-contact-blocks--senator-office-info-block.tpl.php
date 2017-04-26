<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<h2 class="nys-title"><?php print $fields['title']->content; ?></h2>

<div class="c-block c-block--senator-office">

  <?php print $fields['field_offices']->content; ?>

  <div class="c-block--senator-email">
    <h4 class="c-office-info--title">Email Address:</h4>
    <?php print $fields['field_email']->content; ?>
  </div>

  <?php
  if (!empty($fields['office_contacts'])):
  ?>
    <div class="c-block--senator-office-contacts">
      <h4 class="c-office-info--title">Office Contacts:</h4>
      <?php
      foreach ($fields['office_contacts'] as $contact):
      ?>
        <div class="c-office-info--office-contact vcard">
          <strong><?php print render($contact['office_contact_name']); ?></strong><br />
          <?php print render($contact['office_contact_title']); ?><br />
          Phone: <?php print render($contact['office_contact_phone']); ?><br />
          Email: <?php print render($contact['office_contact_email']); ?>
        </div>
      <?php
      endforeach;
      ?>
  <?php
  endif;
  ?>
  </div>
</div>
