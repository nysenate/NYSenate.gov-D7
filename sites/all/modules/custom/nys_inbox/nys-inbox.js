(function ($) {
  Drupal.behaviors.nys_inbox = {
    attach: function (context, settings) {
      if($(".select-all-messages input.form-checkbox").length) {
        Drupal.behaviors.nys_inbox.initialize_checkall();
      } 
        
      if($("#nys_inbox").length == 1) {
        Drupal.behaviors.nys_inbox.initialize_inbox();
      } else if($("#nys_senators_constituents").length == 1) {
        Drupal.behaviors.nys_inbox.initialize_senators_constituents();
      } else if($("#nys_senators_constituents_bills").length == 1) {
        Drupal.behaviors.nys_inbox.disable_multicheck();
      }
      
    },
    initialize_checkall: function() {
      $(".select-all-messages input.form-checkbox").each(function() {
        $(this).change(function() {
          var check_all_is_checked = this.checked;
          $(this).closest('form').find(".row-checkbox, .privatemsg-list").prop('checked', check_all_is_checked);
        });
      });
      $("#edit-in-district").change(function() {
        if (!this.checked) {
          $("#checkall").attr('checked', false);
        }
      });
    },
    initialize_inbox: function() {
      $toggle = $("#inbox_message_table tr");
      var $checkboxes = $(".form-type-checkbox input.privatemsg-list, #checkall");
     
      var $messagesearch = $("#edit-messagesearch");
      var $issuesearch = $("#edit-issuesearch");
      var $billsearch = $("#edit-billsearch");
      var $usersearch = $("#edit-usersearch");
      var $sendmessagebutton = $("#edit-message");
      var $deletemessagebutton = $('#edit-delete');
      
      $messagesearch.focus(function() { 
        $issuesearch.val(''); 
        $billsearch.val('');
        $usersearch.val('');
      });
      $issuesearch.focus(function() { 
        Drupal.behaviors.nys_inbox.clear_search_filters();
      });
      $billsearch.focus(function() { 
        Drupal.behaviors.nys_inbox.clear_search_filters();
      });
      $usersearch.focus(function() { 
        Drupal.behaviors.nys_inbox.clear_search_filters();
      });
      
      $sendmessagebutton.prop('disabled', true);
      $deletemessagebutton.prop('disabled', true);
      
      $checkboxes.each(function() {
          var currentChecked = this.checked;
          if(currentChecked) {
            $sendmessagebutton.prop('disabled', false); 
            $deletemessagebutton.prop('disabled', false);
          }        
      });

      
      $toggle.click(function(event) { 
        var toggle_old = $(this).find(".message-body-toggle");     
        var thread_id = $(this).find(".message-body-toggle").data().thread_id;
         if( ! $( event.target).is('a') ) {
          $("#message-preview-" + thread_id).toggleClass('visible');  
          $("#message-body-" + thread_id).toggleClass('visible');
          $("#reply-button-" + thread_id).toggleClass('visible');
          $("#forward-button-" + thread_id).toggleClass('visible');          
          $(toggle_old).toggleClass('up_arrow');
        } 
      });

      
      if (Drupal.settings.nys_inbox.check_all == 0) {
        Drupal.behaviors.nys_inbox.disable_multicheck();
      }
      
      $checkboxes.change(function() {
          var currentChecked = this.checked;
          if(currentChecked) {
            $sendmessagebutton.prop('disabled', false); 
            $deletemessagebutton.prop('disabled', false);
          } else {
            $sendmessagebutton.prop('disabled', true);
            $deletemessagebutton.prop('disabled', true);
            $(".select-all-messages input.form-checkbox").attr('checked', false);
          }
      });
      
    },
    initialize_senators_constituents: function() {
      $form = $("#nys-inbox-senator-constituents-form");
      $filterselect = $("select.filter");
      $zipsearch = $("#zipsearch");
      
      $filterselect.change(function() {
        $form.submit();
      });
      
      $zipsearch.on('click focusin', function() {
        this.value = '';
      });
    },
    disable_multicheck: function() {
      $(".form-type-checkbox input").click(function() {
        var currentChecked = this.checked;
        $(".row-checkbox, .privatemsg-list").not(this).prop('checked', false); //.not(this).prop('checked', currentChecked);
      });
    },
    clear_search_filters: function() {
      $("#edit-messagesearch").val('');
      $("#edit-issuesearch").val(''); 
      $("#edit-billsearch").val('');
      $("#edit-usersearch").val('');
    }
  };
})(jQuery);
