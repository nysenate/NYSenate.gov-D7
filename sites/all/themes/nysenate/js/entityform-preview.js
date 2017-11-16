(function ($) {
    //add drupal 7 code
    Drupal.behaviors.hideintro = {
        attach: function(context, settings) {
//end drupal calls
    //$("div.view-mode-review").prev(".pre-instructions").fadeOut(100, "easeOutQuad");
    $("div.view-mode-review").prev(".pre-instructions").hide();
    $("ds-1col.entity.entity-entityform.entityform-hannon-photo-contest.view-mode-review").closest("div.c-block").hide();
//some jquery goodness here...
    $("div.field-name-field-school-stud-earthday-subm").next("#edit-submit").text('Submit for Review');
    $("div.field-name-field-school-stud-earthday-subm").next().next("#edit-submit").text('Submit for Review');
    $("button#edit-change").next("#edit-submit").html('Your Final Submission');
    $("div.field-name-field-school-student-submissions").next("#edit-submit").text('Review Your Submission');
    $("div.field-name-field-school-student-submissions").next().next("#edit-submit").text('Review Your Submission');

  }}})
(jQuery);
