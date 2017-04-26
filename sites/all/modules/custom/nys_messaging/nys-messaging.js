// jQuery plugin to prevent double submission of forms
(function ($) {
$.fn.preventDoubleSubmission = function() {
  
  //$(this).find("#edit-submit").remove();
 
  $(this).on('submit', function( event ) {
    $(this).find("#edit-submit").replaceWith('<div class="ajax-progress-throbber"><img src="/sites/all/themes/nysenate/images/ajax-loader.gif" class="throbber" /></div>');
  });

  // Keep chainability
  return this;
};
})(jQuery);

(function ($) {
  Drupal.behaviors.nys_messaging = {
    attach: function (context, settings) {
      if($("#nys-messaging-senator-message-form").length == 1) {
        $("#nys-messaging-senator-message-form").preventDoubleSubmission();
      }
      if($("#nys-messaging-senator-contact-form").length == 1) {
        $("#nys-messaging-senator-contact-form").preventDoubleSubmission();
      }
      
    }
  };
})(jQuery);