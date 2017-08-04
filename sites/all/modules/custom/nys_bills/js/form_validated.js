/**
 * @file
 * Hides the form when an anonymous user submits a vote.
 */

(function($){

  Drupal.behaviors.nys_bills = {
    attach: function (context) {
      $('div.c-bill--sentiment-text').hide();
      $('div.form-item').hide();
      if ($('.icon-before__petition').length > 0) {
        $('html,body').animate({scrollTop: $('.icon-before__petition').offset().top - 250}, 'slow');
      }
    }
  };
})(jQuery);
