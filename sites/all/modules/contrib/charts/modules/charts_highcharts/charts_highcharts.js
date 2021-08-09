/**
 * @file
 * JavaScript integration between Highcharts and Drupal.
 */
(function ($) {

Drupal.behaviors.chartsHighcharts = {};
Drupal.behaviors.chartsHighcharts.attach = function(context, settings) {
  $('.charts-highchart').once('charts-highchart', function() {
    if ($(this).attr('data-chart')) {
      var config = $.parseJSON($(this).attr('data-chart'));
      $(this).highcharts(config);
    }
  });
};

})(jQuery);
