(function ($) {
  // Polyfill for jQuery less than 1.6.
  if (typeof $.fn.prop != 'function') {
    jQuery.fn.extend({
      prop: jQuery.fn.attr
    });
  }

  Drupal.behaviors.viewsSend = {
    attach: function(context) {
      $('.views-send-selection-form', context).each(function() {
        Drupal.viewsSend.initTableBehaviors(this);
        Drupal.viewsSend.initGenericBehaviors(this);
      });
    }
  }

  Drupal.viewsSend = Drupal.viewsSend || {};
  Drupal.viewsSend.initTableBehaviors = function(form) {
    $('.views-send-table-select-all', form).show();
    // This is the "select all" checkbox in (each) table header.
    $('.views-send-table-select-all', form).click(function() {
      var table = $(this).closest('table')[0];
      $('input[id^="edit-views-send"]:not(:disabled)', table).prop('checked', this.checked).change();
    });
  }

  Drupal.viewsSend.initGenericBehaviors = function(form) {
    // Show the "select all" fieldset.
    $('.views-send-select-all-markup', form).show();

    $('.views-send-select-this-page', form).click(function() {
      $('input[id^="edit-views-send"]', form).prop('checked', this.checked).change();

      // Toggle the "select all" checkbox in grouped tables (if any).
      $('.views-send-table-select-all', form).prop('checked', this.checked).change();
    });

    $('.views-send-select', form).click(function() {
      // If a checkbox was deselected, uncheck any "select all" checkboxes.
      if (!this.checked) {
        $('.views-send-select-this-page', form).prop('checked', false).change();

        var table = $(this).closest('table')[0];
        if (table) {
          // Uncheck the "select all" checkbox in the table header.
          $('.views-send-table-select-all', table).prop('checked', false).change();
        }
      }
    });
  }

})(jQuery);
