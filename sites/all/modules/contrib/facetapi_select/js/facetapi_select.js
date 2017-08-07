/**
 * @file
 * Handles Facet API Select ajax functionality.
 */
(function ($) {
  Drupal.behaviors.facetapiSelect = {
    attach: function(context) {
      $(".facetapi-select-submit").hide();

      $('.facetapi-select').change(function() {
        var id = $(this).attr('id');
        var elem = document.getElementById(id);
        top.location.href=elem.options[elem.selectedIndex].value;
      });
    }
  };
})(jQuery);
