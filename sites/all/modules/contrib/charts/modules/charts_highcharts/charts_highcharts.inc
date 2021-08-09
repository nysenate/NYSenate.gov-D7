<?php
/**
 * @file
 * Callbacks and utility functions for rendering a Highcharts Chart.
 */

/**
 * Chart render callback; Convert all chart-level data.
 *
 * This essentially is an additional #pre_render callback. It operates in the
 * same way and is simply called as part of the normal #pre_render process.
 *
 * @param array $chart
 *   The chart renderable.
 * @return
 *   The modified chart renderable, with necessary #attached, #theme, and
 *   similar properties prepared for rendering.
 */
function _charts_highcharts_render($chart) {

  // Populate chart settings.
  $chart_definition = array();
  $chart_definition = _charts_highcharts_populate_chart_options($chart, $chart_definition);
  $chart_definition = _charts_highcharts_populate_chart_axes($chart, $chart_definition);
  $chart_definition = _charts_highcharts_populate_chart_data($chart, $chart_definition);

  // Remove machine names from series. Highcharts series must be an array.
  $series = array_values($chart_definition['series']);
  unset($chart_definition['series']);

  // Trim out empty options (excluding "series" for efficiency).
  charts_trim_array($chart_definition);

  // Put back the data.
  $chart_definition['series'] = $series;

  if (!isset($chart['#id'])) {
    $chart['#id'] = drupal_html_id('highchart-render');
  }

  $chart['#attached']['library'][] = array('charts_highcharts', 'charts_highcharts');
  $chart['#attributes']['class'][] = 'charts-highchart';
  $chart['#chart_definition'] = $chart_definition;

  return $chart;
}

/**
 * Utility to convert a Drupal renderable type to a Google visualization type.
 */
function _charts_highcharts_type($renderable_type) {
  $types = array(
    'area_chart' => 'AreaChart',
    'bar_chart' => 'BarChart',
    'column_chart' => 'ColumnChart',
    'line_chart' => 'LineChart',
    'pie_chart' => 'PieChart',
    'scatter_chart' => 'ScatterChart',
  );
  drupal_alter('charts_highcharts_types', $types);
  return isset($types[$renderable_type]) ? $types[$renderable_type] : FALSE;
}

/**
 * Utility to populate main chart options.
 */
function _charts_highcharts_populate_chart_options($chart, $chart_definition) {
  $chart_definition['chart']['type'] = $chart['#chart_type'];
  $chart_definition['title']['text'] = $chart['#title'] ? $chart['#title'] : '';
  $chart_definition['title']['style']['color'] = $chart['#title_color'];
  $chart_definition['title']['style']['fontWeight'] = $chart['#title_font_weight'];
  $chart_definition['title']['style']['fontStyle'] = $chart['#title_font_style'];
  $chart_definition['title']['style']['fontSize'] = $chart['#title_font_size'];
  $chart_definition['title']['verticalAlign'] = $chart['#title_position'] === 'in' ? 'top' : NULL;
  $chart_definition['title']['y'] = $chart['#title_position'] === 'in' ? 24: NULL;
  $chart_definition['colors'] = $chart['#colors'];
  $chart_definition['chart']['style']['fontFamily'] = $chart['#font'];
  $chart_definition['chart']['style']['fontSize'] = $chart['#font_size'];
  $chart_definition['chart']['backgroundColor'] = $chart['#background'];
  $chart_definition['plotOptions']['series']['stacking'] = !is_string($chart['#stacking']) && $chart['#stacking'] ? 'normal' : $chart['#stacking'];
  $chart_definition['tooltip']['enabled'] = $chart['#tooltips'] ? TRUE : FALSE;
  $chart_definition['tooltip']['useHTML'] = $chart['#tooltips_use_html'] ? TRUE : FALSE;
  $chart_definition['plotOptions']['series']['dataLabels']['enabled'] = $chart['#data_labels'] ? TRUE : FALSE;

  // These changes are for consistency with Google. Perhaps too specific?
  if ($chart['#chart_type'] === 'pie') {
    $chart_definition['plotOptions']['pie']['dataLabels']['distance'] = -30;
    $chart_definition['plotOptions']['pie']['dataLabels']['color'] = 'white';
    $chart_definition['plotOptions']['pie']['dataLabels']['format'] = '{percentage:.1f}%';
    $chart_definition['tooltip']['pointFormat'] = '<b>{point.y} ({point.percentage:.1f}%)</b><br/>';
  }

  $chart_definition['legend']['enabled'] = $chart['#legend'];
  $chart_definition['legend']['title']['text'] = $chart['#legend_title'];
  $chart_definition['legend']['title']['style']['fontWeight'] = $chart['#legend_title_font_weight'];
  $chart_definition['legend']['title']['style']['fontStyle'] = $chart['#legend_title_font_style'];
  $chart_definition['legend']['title']['style']['fontSize'] = $chart['#legend_title_font_size'];
  if ($chart['#legend_position'] === 'bottom') {
    $chart_definition['legend']['verticalAlign'] = 'bottom';
    $chart_definition['legend']['layout'] = 'horizontal';
  }
  elseif ($chart['#legend_position'] === 'top') {
    $chart_definition['legend']['verticalAlign'] = 'top';
    $chart_definition['legend']['layout'] = 'horizontal';
  }
  else {
    $chart_definition['legend']['align'] = $chart['#legend_position'];
    $chart_definition['legend']['verticalAlign'] = 'middle';
    $chart_definition['legend']['layout'] = 'vertical';
  }
  $chart_definition['legend']['itemStyle']['fontWeight'] = $chart['#legend_font_weight'];
  $chart_definition['legend']['itemStyle']['fontStyle'] = $chart['#legend_font_style'];
  $chart_definition['legend']['itemStyle']['fontSize'] = $chart['#legend_font_size'];
  $chart_definition['chart']['width'] = $chart['#width'] ? $chart['#width'] : NULL;
  $chart_definition['chart']['height'] = $chart['#height'] ? $chart['#height'] : NULL;
  $chart_definition['credits']['enabled'] = FALSE;

  return $chart_definition;
}

/**
 * Utility to populate chart axes.
 */
function _charts_highcharts_populate_chart_axes($chart, $chart_definition) {
  foreach (element_children($chart) as $key) {
    if ($chart[$key]['#type'] === 'chart_xaxis' || $chart[$key]['#type'] === 'chart_yaxis') {
      // Make sure defaults are loaded.
      if (empty($chart[$key]['#defaults_loaded'])) {
        $chart[$key] += element_info($chart[$key]['#type']);
      }

      // Populate the chart data.
      $axisType = $chart[$key]['#type'] === 'chart_xaxis' ? 'xAxis' : 'yAxis';
      $axis = array();
      $axis['type'] = $chart[$key]['#axis_type'];
      $axis['title']['text'] = $chart[$key]['#title'];
      $axis['title']['style']['color'] = $chart[$key]['#title_color'];
      $axis['title']['style']['fontWeight'] = $chart[$key]['#title_font_weight'];
      $axis['title']['style']['fontStyle'] = $chart[$key]['#title_font_style'];
      $axis['title']['style']['fontSize'] = $chart[$key]['#title_font_size'];
      $axis['categories'] = $chart[$key]['#labels'];
      $axis['labels']['style']['color'] = $chart[$key]['#labels_color'];
      $axis['labels']['style']['fontWeight'] = $chart[$key]['#labels_font_weight'];
      $axis['labels']['style']['fontStyle'] = $chart[$key]['#labels_font_style'];
      $axis['labels']['style']['fontSize'] = $chart[$key]['#labels_font_size'];
      $axis['labels']['rotation'] = $chart[$key]['#labels_rotation'];
      $axis['gridLineColor'] = $chart[$key]['#grid_line_color'];
      $axis['lineColor'] = $chart[$key]['#base_line_color'];
      $axis['minorGridLineColor'] = $chart[$key]['#minor_grid_line_color'];
      $axis['endOnTick'] = isset($chart[$key]['#max']) ? FALSE : NULL;
      $axis['max'] = $chart[$key]['#max'];
      $axis['min'] = $chart[$key]['#min'];
      $axis['opposite'] = $chart[$key]['#opposite'];

      // Dealing with axis rotation in a reasonable manner is complicated in
      // Highcharts. We want the label to be reasonably positioned on the
      // outside of the chart when labels are rotated.
      if ($axis['labels']['rotation']) {
        $chart_type = chart_get_type($chart['#chart_type']);
        if ($axisType === 'xAxis' && !$chart_type['axis_inverted']) {
          $axis['labels']['align'] = 'left';
        }
        elseif ($axisType === 'yAxis' && $chart_type['axis_inverted']) {
          $axis['labels']['align'] = 'left';
        }
        else {
          // Rotation not allowed on left/right axis.
          unset($axis['labels']['rotation']);
        }
      }

      $chart_definition[$axisType][] = $axis;
    }
  }

  return $chart_definition;
}

/**
 * Utility to populate chart data.
 */
function _charts_highcharts_populate_chart_data(&$chart, $chart_definition) {
  $chart_definition['series'] = array();
  foreach (element_children($chart) as $key) {
    if ($chart[$key]['#type'] === 'chart_data') {
      $series = array();
      $series_data = array();

      // Make sure defaults are loaded.
      if (empty($chart[$key]['#defaults_loaded'])) {
        $chart[$key] += element_info($chart[$key]['#type']);
      }

      // Convert target named axis keys to integers.
      if (isset($chart[$key]['#target_axis'])) {
        $axis_name = $chart[$key]['#target_axis'];
        $axis_index = 0;
        foreach (element_children($chart) as $axis_key) {
          if ($chart[$axis_key]['#type'] === 'chart_yaxis') {
            if ($axis_key === $axis_name) {
              break;
            }
            $axis_index++;
          }
        }
        $series['yAxis'] = $axis_index;
      }

      // Allow data to provide the labels. This will override the axis settings.
      if ($chart[$key]['#labels']) {
        foreach ($chart[$key]['#labels'] as $label_index => $label) {
          $series_data[$label_index][0] = $label;
        }
      }

      // Populate the data.
      foreach ($chart[$key]['#data'] as $data_index => $data) {
        if (isset($series_data[$data_index])) {
          $series_data[$data_index][] = $data;
        }
        else {
          $series_data[$data_index] = $data;
        }
      }

      $series['type'] = $chart[$key]['#chart_type'];
      $series['name'] = $chart[$key]['#title'];
      $series['color'] = $chart[$key]['#color'];
      $series['marker']['radius'] = $chart[$key]['#marker_radius'];
      $series['showInLegend'] = $chart[$key]['#show_in_legend'];
      $series['connectNulls'] = TRUE;

      $series['tooltip']['valueDecimals'] = $chart[$key]['#decimal_count'];
      $series['tooltip']['xDateFormat'] = $chart[$key]['#date_format'];
      $series['tooltip']['valuePrefix'] = $chart[$key]['#prefix'];
      $series['tooltip']['valueSuffix'] = $chart[$key]['#suffix'];

      if ($chart[$key]['#prefix'] || $chart[$key]['#suffix']) {
        $yaxis_index = isset($series['yAxis']) ? $series['yAxis'] : 0;
        // For axis formatting, we need to use a format string.
        // See http://docs.highcharts.com/#formatting.
        $decimal_formatting = $chart[$key]['#decimal_count'] ? (':.' . $chart[$key]['#decimal_count'] . 'f') : '';
        $chart_definition['yAxis'][$yaxis_index]['labels']['format'] = $chart[$key]['#prefix'] . "{value$decimal_formatting}" . $chart[$key]['#suffix'];
      }

      // Remove unnecessary keys to trim down the resulting JS settings.
      charts_trim_array($series);
      $series['data'] = $series_data;

      // Add the series to the main chart definition.
      $chart_definition['series'][$key] = $series;

      // Merge in any point-specific data points.
      foreach (element_children($chart[$key]) as $sub_key) {
        if ($chart[$key][$sub_key]['#type'] === 'chart_data_item') {

          // Make sure defaults are loaded.
          if (empty($chart[$key][$sub_key]['#defaults_loaded'])) {
            $chart[$key][$sub_key] += element_info($chart[$key][$sub_key]['#type']);
          }

          $data_item = $chart[$key][$sub_key];
          $series_point = &$chart_definition['series'][$key]['data'][$sub_key];

          // Convert the point from a simple data value to a complex point.
          if (!isset($series_point['data'])) {
            $data = $series_point;
            $series_point = array();
            if (is_array($data)) {
              $series_point['name'] = $data[0];
              $series_point['y'] = $data[1];
            }
            else {
              $series_point['y'] = $data;
            }
          }
          if (isset($data_item['#data'])) {
            if (is_array($data_item['#data'])) {
              $series_point['x'] = $data_item['#data'][0];
              $series_point['y'] = $data_item['#data'][1];
            }
            else {
              $series_point['y'] = $data_item['#data'];
            }
          }
          if ($data_item['#title']) {
            $series_point['name'] = $data_item['#title'];
          }

          // Setting the color requires several properties for consistency.
          $series_point['color'] = $data_item['#color'];
          $series_point['fillColor'] = $data_item['#color'];
          $series_point['states']['hover']['fillColor'] = $data_item['#color'];
          $series_point['states']['select']['fillColor'] = $data_item['#color'];
          charts_trim_array($series_point);
        }
      }

    }
  }

  return $chart_definition;
}
