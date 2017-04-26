(function ($) {
  Drupal.behaviors.fancyFileDeleteViewRefresh = {
    attach: function() {
      // Refresh the view
      $('.ffd-refresh').click( function() {
        $('.view-id-fancy_file_list_unmanaged').trigger('RefreshView');
      });
    }
  }
})(jQuery);
