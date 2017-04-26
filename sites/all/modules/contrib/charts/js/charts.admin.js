/**
 * @file
 * Scripting for administrative interfaces of Charts module.
 */
(function ($) {

Drupal.behaviors.chartsAdmin = {};
Drupal.behaviors.chartsAdmin.attach = function(context, settings) {
  // Change options based on the chart type selected.
  $(context).find('.form-radios.chart-type-radios').once('charts-axis-inverted-processed', function() {

    // Manually attach collapsible fieldsets first.
    if (Drupal.behaviors.collapse) {
      Drupal.behaviors.collapse.attach(context, settings);
    }

    var xAxisLabel = $('fieldset.chart-xaxis .fieldset-title').html();
    var yAxisLabel = $('fieldset.chart-yaxis .fieldset-title').html();

    $(this).find('input:radio').change(function() {
      if ($(this).is(':checked')) {
        // Flip X/Y axis fieldset labels for inverted chart types.
        if ($(this).attr('data-axis-inverted')) {
          $('fieldset.chart-xaxis .fieldset-title').html(yAxisLabel);
          $('fieldset.chart-xaxis .axis-inverted-show').closest('.form-item').show();
          $('fieldset.chart-xaxis .axis-inverted-hide').closest('.form-item').hide();
          $('fieldset.chart-yaxis .fieldset-title').html(xAxisLabel);
          $('fieldset.chart-yaxis .axis-inverted-show').closest('.form-item').show();
          $('fieldset.chart-yaxis .axis-inverted-hide').closest('.form-item').hide();
        }
        else {
          $('fieldset.chart-xaxis .fieldset-title').html(xAxisLabel);
          $('fieldset.chart-xaxis .axis-inverted-show').closest('.form-item').hide();
          $('fieldset.chart-xaxis .axis-inverted-hide').closest('.form-item').show();
          $('fieldset.chart-yaxis .fieldset-title').html(yAxisLabel);
          $('fieldset.chart-yaxis .axis-inverted-show').closest('.form-item').hide();
          $('fieldset.chart-yaxis .axis-inverted-hide').closest('.form-item').show();
        }

        // Show color options for single axis settings.
        if ($(this).attr('data-axis-single')) {
          $('fieldset.chart-xaxis').hide();
          $('fieldset.chart-yaxis').hide();
          $('th.chart-field-color, td.chart-field-color').hide();
          $('div.chart-colors').show();
        }
        else {
          $('fieldset.chart-xaxis').show();
          $('fieldset.chart-yaxis').show();
          $('th.chart-field-color, td.chart-field-color').show();
          $('div.chart-colors').hide();
        }
      }
    });

    // Set the initial values.
    $(this).find('input:radio:checked').triggerHandler('change');
  });

  // Disable the data checkbox when a field is set as a label.
  $(context).find('td.chart-label-field input').once('charts-axis-inverted-processed', function() {
    var $radio = $(this);
    $radio.change(function() {
      if ($radio.is(':checked')) {
        $('.chart-data-field input').show();
        $('.chart-field-color input').show();
        $('input.chart-field-disabled').remove();
        $radio.closest('tr').find('.chart-data-field input').hide().after('<input type="checkbox" name="chart_field_disabled" disabled="disabled" class="chart-field-disabled" />');
        $radio.closest('tr').find('.chart-field-color input').hide();
      }
    });
    $radio.triggerHandler('change');
  });

};

})(jQuery);