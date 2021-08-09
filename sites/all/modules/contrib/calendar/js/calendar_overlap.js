/*
 *  Create the splitter, set the viewport size, and set the position of the scrollbar to the first item.
 */
(function($){
  Drupal.behaviors.calendarSetScroll = {
  attach: function(context) {
    // Make multi-day resizable - stolen/borrowed from textarea.js
    $('.header-body-divider:not(.header-body-divider-processed)').each(function() {
      var divider = $(this).addClass('header-body-divider-processed');
      var start_y = divider.offset().top;

      // Add the grippie icon
      $(this).prepend('<div class="grippie"></div>').mousedown(startDrag);

      function startDrag(e) {
        start_y = divider.offset().top;
        $(document).mousemove(performDrag).mouseup(endDrag);
        return false;
      }

      function performDrag(e) {
        var offset = e.pageY - start_y;
        var mwc = $('#multi-day-container');
        var sdc = $('#single-day-container');
        var mwc_height = mwc.height();
        var sdc_height = sdc.height();
        var max_height = mwc_height + sdc_height;
        mwc.height(Math.min(max_height,Math.max(0,mwc_height + offset)));
        sdc.height(Math.min(max_height,Math.max(0,sdc_height - offset)));
        start_y = divider.offset().top;
        return false;
      }

      function endDrag(e) {
        $(document).unbind("mousemove", performDrag).unbind("mouseup", endDrag);
      }
     });

    $('.single-day-footer:not(.single-day-footer-processed)').each(function() {
      var divider = $(this).addClass('single-day-footer-processed');
      var start_y = divider.offset().top;

      // Add the grippie icon
      $(this).prepend('<div class="grippie"></div>').mousedown(startDrag);

      function startDrag(e) {
        start_y = divider.offset().top;
        $(document).mousemove(performDrag).mouseup(endDrag);
        return false;
      }

      function performDrag(e) {
        var offset = e.pageY - start_y;
        var sdc = $('#single-day-container');
        sdc.height(Math.max(0,sdc.height() + offset));
        start_y = divider.offset().top;
        return false;
      }

      function endDrag(e) {
        $(document).unbind("mousemove", performDrag).unbind("mouseup", endDrag);
      }
     });
    }
  };
})(jQuery);

// Scroll the viewport to the first item
function calendar_scrollToFirst($) {
   if ($('div.first_item').size() > 0 ) {
      var y = $('div.first_item').offset().top - $('#single-day-container').offset().top ;
      if ($('#single-day-container').length > 0) {
        var top = $('#single-day-container').offset().top;
      }
   }
}

