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
<?php
$string = $fields['title']->raw;
if(substr($string, -6) == 'Jacobs'){ ?>
    <h2 class="nys-title">Contact Senator <?php print $fields['title']->raw; ?>' Office</h2>
    <?php } else { ?>
    <h2 class="nys-title">Contact Senator <?php print $fields['title']->raw; ?>'s Office</h2>
<?php }; ?>

<div class="c-block c-block--senator-office">

  <?php print $fields['field_offices']->content; ?>

      <div class="c-block--senator-email">
        <h3 class="c-office-info--title">Email Address:</h3>
        <?php print $fields['field_email']->content; ?>
      </div>


  <?php if (!empty($fields['office_contacts'])): ?>
    <div class="c-block--senator-office-contacts">
      <h3 class="c-office-info--title">Office Contacts:</h3>
      <?php foreach ($fields['office_contacts'] as $contact): ?>
        <div class="c-office-info--office-contact vcard">
          <?php print render($contact['office_contact_name']); ?><br />
          <?php print render($contact['office_contact_title']); ?><br />
		  <?php if (isset($contact['office_contact_phone'])): ?>
			<span>Phone: </span><?php print render($contact['office_contact_phone']); ?><br />
		  <?php endif; ?>
		  <?php if (isset($contact['office_contact_email'])): ?>
            <span>Email: </span><a href="mailto:<?php print render($contact['office_contact_email']); ?>"><?php print render($contact['office_contact_email']); ?></a>
		  <?php endif; ?>
        </div>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
</div>
