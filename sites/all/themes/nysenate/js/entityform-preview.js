(function ($) {
    //add drupal 7 code
    Drupal.behaviors.hideintro = {
        attach: function(context, settings) {
//end drupal calls
    $("div.view-mode-review").prev(".pre-instructions").fadeOut(100, "easeOutQuad");
//some jquery goodness here...
    $("div.field-name-field-school-stud-earthday-subm").next("#edit-submit").text('Submit for Review');
    $("div.field-name-field-school-stud-earthday-subm").next().next("#edit-submit").text('Submit for Review');

  }}})
(jQuery);
