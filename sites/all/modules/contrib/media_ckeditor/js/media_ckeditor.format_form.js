/**
 * @file
 * Overrides of some functions in media and media_wysiwyg javascript.
 */

(function ($) {

// Sanity check, because javascript errors are bad.
if (typeof Drupal.media === 'undefined' ||
    typeof Drupal.media.formatForm === 'undefined') {
  return;
}

/**
 * This overrides the function of the same name from media/modules/media_wysiwyg/js/media_wysiwyg.format_form.js
 * It provides an implementation of that function that knows how to extract content from CKEditor instances.
 */
Drupal.media.formatForm.getEditorContent = function(fieldKey) {
  if (typeof CKEDITOR !== 'undefined' && CKEDITOR.instances[fieldKey]) {
    return CKEDITOR.instances[fieldKey].getData();
  }
  else {
    // Default case => no CKEditor instance for this field.
    return null;
  }
};

/**
 * This overrides the function of the same name from media/modules/media_wysiwyg/js/media_wysiwyg.format_form.js
 * It provides an implementation of that function that escapes user input from
 * overridden fields on the format form.
 */
Drupal.media.formatForm.escapeFieldInput = function(input) {
  // We escape the input here, in a similar manner to what CKEditor's widget
  // system does. This helps to make the "tagmap" accurate when the content is
  // edited again in the future, and so CKEditor will recognize the token as a
  // widget that needs to be upcast.
  return $('<div>').text(input).html();
}

})(jQuery);
