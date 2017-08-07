/**
 * @file
 * Sets up the Aye/Nay voting widget seen on bill nodes.
 */

// This looks like a workaround for https://www.drupal.org/node/1907932
// We should review that patch and see about applying it.
(function($){
  Drupal.ajax.prototype.commands.nysBillVoteUpdate = function (ajax, response, status) {
    response.selector = $('.nys-bill-vote', ajax.element.form);
    ajax.commands.insert(ajax, response, status);
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.nys_bill_vote = {
    attach: function (context, settings) {
      $('div.form-item-nys-bill-vote', context).once('nys-bill-vote', function () {
        var $this = this;
        var $container = $('<div class="nys-bill-vote-widget clearfix"></div>');
        var $select = $('select', $this);
        // Setup the Aye button.
        $('<a class="c-block--btn c-half-btn c-half-btn--left nys-bill-vote-yes" href="#yes">Aye</a>').appendTo($container).on('click', {
          choice: 'yes',
          value: 1,
          label: 'You are in favor of this bill'
        }, vote);
        // Setup the Nay button.
        $('<a class="c-block--btn c-half-btn c-half-btn--right nys-bill-vote-no" href="#no">Nay</a>').appendTo($container).on('click', {
          choice: 'no',
          value: 0,
          label: 'You are opposed to this bill'
        }, vote);

        // Attach the new widget and hide the existing widget.
        $select.after($container).css('display', 'none');
      });

      // Hide the message box if the form is re-loaded.
      if (!$('#nys-bills-bill-form input[name=register]').prop('checked') && $('body.not-logged-in').length) {
        $('.c-bill--message-form .form-item-message').hide();
      }
      // Add a click event handler for hiding the message form if 'Create an
      // account checkbox is unchecked. This needs to remain outside of the
      // .once() because the ajax processing of the form removes all event
      // handlers. This is not ideal as currently Drupal calls this behavior 3
      // times so we end up with duplicate event handlers registered.
      $('#nys-bills-bill-form input[name=register]').on('click', hide_message_box);

      function vote(event) {
        // Add our class for highlighting the voter's selection.
        $(event.target).addClass('selected accent-bg');
        $(event.target).siblings().removeClass('selected accent-bg');

        // Update the widget's label.
        $(event.target).closest('div.nys-bill-vote').find('p.c-bill-polling--cta').text(event.data.label);

        $('.c-bill--message-form').show();
        $('.c-bill--sentiment-update').show();
        $('input[name=vote_value]').val(event.data.value);
        $('.c-bill--vote-widget').addClass('c-bill--vote-attach');
        $('.c-bill--vote-widget').removeClass('c-bill--vote-widget');
        if ($('.c-bill--sentiment-text').length) {
          $('html,body').animate({scrollTop: $('.c-bill--sentiment-text').offset().top - 250}, 'slow');
        }

        // Set submit button text depending on how the user voted.
        if (event.data.value) {
          $('#nys-bills-bill-form button[type="submit"]').html('Support this bill');
        }
        else {
          $('#nys-bills-bill-form button[type="submit"]').html('Oppose this bill');
        }

        // Because the vote is processed via a Drupal ajax callback (only for
        // authenticated users) that's associated with the hidden select list
        // we must trigger a change to the select list and pass it the vote
        // value.
        $(event.target).closest('div.form-item-nys-bill-vote').find('select[name=nys_bill_vote]').val(event.data.choice).change();
      }
      function hide_message_box(event) {
        // If the user doesn't want to create an account we don't want them
        // sending a message.
        if (!event.target.checked) {
          $('.c-bill--message-form .form-item-message').hide();
        }
        else {
          $('.c-bill--message-form .form-item-message').show();
        }
      }
    },
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.nys_bill_vote_hilite = {
    attach: function (context, settings) {

      $("#edit-submit--2").click(function(){
        $("#edit-submit--2").css('background-color','#4DAFD2');
      });

  },
  };
})(jQuery);
