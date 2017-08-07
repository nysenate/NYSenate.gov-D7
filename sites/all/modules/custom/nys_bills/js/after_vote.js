Drupal.behaviors.nys_bill_voted = {
  attach: function (context, settings) {

     jQuery('.c-bill--message-form').show();
     jQuery('div.form-item.form-type-select.form-item-nys-bill-vote').hide();
     jQuery('.c-bill--sentiment-update').hide();
     jQuery('.c-bill--vote-attach').hide();
     jQuery('.c-bill--vote-widget').addClass('c-bill--vote-attach');
     jQuery('.c-bill--vote-widget').removeClass('c-bill--vote-widget');

     var vote_value = jQuery('[name="vote_value"]').val();
     var uid = jQuery('[name="uid"]').val();

     if (vote_value == "0" && uid == "0") {
       jQuery('div.nys-bill-vote p.c-bill-polling--cta').text("YOU ARE OPPOSED TO THIS BILL");
     }
     else if (vote_value == "1" && uid == "0") {
       jQuery('div.nys-bill-vote p.c-bill-polling--cta').text("YOU ARE IN FAVOR OF THIS BILL");
     }


     if (jQuery('div.c-bill--sentiment-text').text().length) {
       jQuery('html,body').animate({scrollTop: jQuery('div.nys-bill-vote').offset().top - 150}, 'slow');
     }

  }
};
