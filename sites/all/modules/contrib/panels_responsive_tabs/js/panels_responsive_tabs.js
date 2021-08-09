(function ($) {
  Drupal.behaviors.PanelsResponsiveTabsToAccordion = {
    attach: function (context, settings) {
      $(settings.panels_responsive_tabs).each(function(key, value){
        $("#" + value.identifier, context).once('panels-responsive-tabs').easyResponsiveTabs({
          type: value.type,
          width: value.width,
          fit: value.fit,
          closed: value.closed,
          activate: function () {},
          tabidentify: value.tabidentify,
          activetab_bg: value.activetab_bg,
          inactive_bg: value.inactive_bg,
          active_border_color: value.active_border_color,
          active_content_border_color: value.active_content_border_color
        });
      });
    }
  };
})(jQuery);