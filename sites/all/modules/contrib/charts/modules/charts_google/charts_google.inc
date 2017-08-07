<?php
/**
 * @file
 * Callbacks and utility functions for rendering a Google Chart.
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
function _charts_google_render($chart) {
  // Convert the chart renderable to a proper definition.
  $chart_definition['visualization'] = _charts_google_visualization_type($chart['#chart_type']);
  $chart_definition = _charts_google_populate_chart_options($chart, $chart_definition);
  $chart_definition = _charts_google_populate_chart_axes($chart, $chart_definition);
  $chart_definition = _charts_google_populate_chart_data($chart, $chart_definition);

  if (!isset($chart['#id'])) {
    $chart['#id'] = drupal_html_id('google-chart-render');
  }

  // Trim out empty options.
  charts_trim_array($chart_definition['options']);

  $chart['#attached']['library'][] = array('charts_google', 'charts_google');
  $chart['#attributes']['class'][] = 'charts-google';
  $chart['#chart_definition'] = $chart_definition;

  return $chart;
}

/**
 * Utility to convert a Drupal renderable type to a Google visualization type.
 */
function _charts_google_visualization_type($renderable_type) {
  $types = array(
    'area' => 'AreaChart',
    'bar' => 'BarChart',
    'column' => 'ColumnChart',
    'line' => 'LineChart',
    'pie' => 'PieChart',
    'scatter' => 'ScatterChart',
  );
  drupal_alter('charts_google_visualization_types', $types);
  return isset($types[$renderable_type]) ? $types[$renderable_type] : FALSE;
}

/**
 * Utility to populate main chart options.
 */
function _charts_google_populate_chart_options($chart, $chart_definition) {
  $chart_definition['options']['title'] = $chart['#title'] ? $chart['#title'] : NULL;
  $chart_definition['options']['titleTextStyle']['color'] = $chart['#title_color'];
  $chart_definition['options']['titleTextStyle']['bold'] = $chart['#title_font_weight'] === 'bold' ? TRUE : FALSE;
  $chart_definition['options']['titleTextStyle']['italic'] = $chart['#title_font_style'] === 'italic' ? TRUE : FALSE;
  $chart_definition['options']['titleTextStyle']['fontSize'] = $chart['#title_font_size'];
  $chart_definition['options']['titlePosition'] = $chart['#title_position'];
  $chart_definition['options']['colors'] = $chart['#colors'];
  $chart_definition['options']['fontName'] = $chart['#font'];
  $chart_definition['options']['fontSize'] = $chart['#font_size'];
  $chart_definition['options']['backgroundColor']['fill'] = $chart['#background'];
  $chart_definition['options']['isStacked'] = $chart['#stacking'] ? TRUE : FALSE;
  $chart_definition['options']['tooltip']['trigger'] = $chart['#tooltips'] ? 'focus' : 'none';
  $chart_definition['options']['tooltip']['isHtml'] = $chart['#tooltips_use_html'] ? TRUE : FALSE;
  $chart_definition['options']['pieSliceText'] = $chart['#data_labels'] ? NULL : 'none';
  $chart_definition['options']['legend']['position'] = $chart['#legend_position'] ? $chart['#legend_position'] : 'none';
  $chart_definition['options']['legend']['alignment'] = 'center';
  $chart_definition['options']['interpolateNulls'] = TRUE;

  // TODO: Legend title (and thus these properties) not supported by Google.
  $chart_definition['options']['legend']['title'] = $chart['#legend_title'];
  $chart_definition['options']['legend']['titleTextStyle']['bold'] = $chart['#legend_title_font_weight'] === 'bold' ? TRUE : FALSE;
  $chart_definition['options']['legend']['titleTextStyle']['italic'] = $chart['#legend_title_font_style'] === 'italic' ? TRUE : FALSE;
  $chart_definition['options']['legend']['titleTextStyle']['fontSize'] = $chart['#legend_title_font_size'];

  $chart_definition['options']['legend']['textStyle']['bold'] = $chart['#legend_font_weight'] === 'bold' ? TRUE : FALSE;
  $chart_definition['options']['legend']['textStyle']['italic'] = $chart['#legend_font_style'] === 'italic' ? TRUE : FALSE;
  $chart_definition['options']['legend']['textStyle']['fontSize'] = $chart['#legend_font_size'];
  $chart_definition['options']['width'] = $chart['#width'] ? $chart['#width'] : NULL;
  $chart_definition['options']['height'] = $chart['#height'] ? $chart['#height'] : NULL;

  $chart_definition['options']['animation']['duration'] = 10000;
  $chart_definition['options']['animation']['easing'] = 'out';

  return $chart_definition;
}

/**
 * Utility to populate chart axes.
 */
function _charts_google_populate_chart_axes($chart, $chart_definition) {
  foreach (element_children($chart) as $key) {
    if ($chart[$key]['#type'] === 'chart_xaxis' || $chart[$key]['#type'] === 'chart_yaxis') {
      // Make sure defaults are loaded.
      if (empty($chart[$key]['#defaults_loaded'])) {
        $chart[$key] += element_info($chart[$key]['#type']);
      }

      // Populate the chart data.
      $axis = array();
      $axis['title'] = $chart[$key]['#title'] ? $chart[$key]['#title'] : '';
      $axis['titleTextStyle']['color'] = $chart[$key]['#title_color'];
      $axis['titleTextStyle']['bold'] = $chart[$key]['#title_font_weight'] === 'bold' ? TRUE : FALSE;
      $axis['titleTextStyle']['italic'] = $chart[$key]['#title_font_style'] === 'italic' ? TRUE : FALSE;
      $axis['titleTextStyle']['fontSize'] = $chart[$key]['#title_font_size'];
      // In Google, the row column of data is used as labels.
      if ($chart[$key]['#labels'] && $chart[$key]['#type'] === 'chart_xaxis') {
        foreach ($chart[$key]['#labels'] as $label_key => $label) {
          $chart_definition['data'][$label_key + 1][0] = $label;
        }
      }
      $axis['textStyle']['color'] = $chart[$key]['#labels_color'];
      $axis['textStyle']['bold'] = $chart[$key]['#labels_font_weight'] === 'bold' ? TRUE : FALSE;
      $axis['textStyle']['italic'] = $chart[$key]['#labels_font_style'] === 'italic' ? TRUE : FALSE;
      $axis['textStyle']['fontSize'] = $chart[$key]['#labels_font_size'];
      $axis['slantedText'] = isset($chart[$key]['#labels_rotation']) ? TRUE : NULL;
      $axis['slantedTextAngle'] = $chart[$key]['#labels_rotation'];
      $axis['gridlines']['color'] = $chart[$key]['#grid_line_color'];
      $axis['baselineColor'] = $chart[$key]['#base_line_color'];
      $axis['minorGridlines']['color'] = $chart[$key]['#minor_grid_line_color'];
      $axis['viewWindowMode'] = isset($chart[$key]['#max']) ? 'explicit' : NULL;
      $axis['viewWindow']['max'] = strlen($chart[$key]['#max']) ? (int) $chart[$key]['#max'] : NULL;
      $axis['viewWindow']['min'] = strlen($chart[$key]['#min']) ? (int) $chart[$key]['#min'] : NULL;

      // Multi-axis support only applies to the major axis in Google charts.
      $chart_type_info = chart_get_type($chart['#chart_type']);
      $axis_index = $chart[$key]['#opposite'] ? 1 : 0;
      if ($chart[$key]['#type'] === 'chart_xaxis') {
        $axis_keys = !$chart_type_info['axis_inverted'] ? array('hAxis') : array('vAxes', $axis_index);
      }
      else {
        $axis_keys = !$chart_type_info['axis_inverted'] ? array('vAxes', $axis_index) : array('hAxis');
      }
      $axis_drilldown = &$chart_definition['options'];
      foreach ($axis_keys as $key) {
        $axis_drilldown = &$axis_drilldown[$key];
      }
      $axis_drilldown = $axis;
    }
  }

  return $chart_definition;
}

/**
 * Utility to populate chart data.
 */
function _charts_google_populate_chart_data(&$chart, $chart_definition) {
  $chart_definition['options']['series'] = array();
  $chart_type_info = chart_get_type($chart['#chart_type']);
  $series_number = 0;
  foreach (element_children($chart) as $key) {
    if ($chart[$key]['#type'] === 'chart_data') {
      $series = array();

      // Make sure defaults are loaded.
      if (empty($chart[$key]['#defaults_loaded'])) {
        $chart[$key] += element_info($chart[$key]['#type']);
      }

      // Convert target named axis keys to integers.
      $axis_index = 0;
      if (isset($chart[$key]['#target_axis'])) {
        $axis_name = $chart[$key]['#target_axis'];
        foreach (element_children($chart) as $axis_key) {
          $multi_axis_type = $chart_type_info['axis_inverted'] ? 'chart_xaxis' : 'chart_yaxis';
          if ($chart[$axis_key]['#type'] === $multi_axis_type) {
            if ($axis_key === $axis_name) {
              break;
            }
            $axis_index++;
          }
        }
        $series['targetAxisIndex'] = $axis_index;
      }

      // Allow data to provide the labels. This will override the axis settings.
      if ($chart[$key]['#labels']) {
        foreach ($chart[$key]['#labels'] as $label_index => $label) {
          $chart_definition['data'][$label_index + 1][0] = $label;
        }
      }

      if ($chart[$key]['#title']) {
        $chart_definition['data'][0][$series_number + 1] = $chart[$key]['#title'];
      }
      foreach ($chart[$key]['#data'] as $index => $data_value) {
        // Nested array values typically used for scatter charts. This weird
        // approach leaves columns empty in order to make arbitrary pairings.
        // See https://developers.google.com/chart/interactive/docs/gallery/scatterchart#Data_Format
        if (is_array($data_value)) {
          $chart_definition['data'][] = array(
            0 => $data_value[0],
            $series_number + 1 => $data_value[1],
          );
        }
        // Most charts provide a single-dimension array of values.
        else {
          $chart_definition['data'][$index + 1][$series_number + 1] = $data_value;
        }
      }

      $series['color'] = $chart[$key]['#color'];
      $series['pointSize'] = $chart[$key]['#marker_radius'];
      $series['visibleInLegend'] = $chart[$key]['#show_in_legend'];

      // Labels only supported on pies.
      $series['pieSliceText'] = $chart[$key]['#show_labels'] ? 'label' : 'none';

      // These properties are not real Google Charts properties. They are
      // utilized by the formatter in charts_google.js.
      $decimal_count = $chart[$key]['#decimal_count'] ? '.' . str_repeat('0', $chart[$key]['#decimal_count']) : '';
      $prefix = _charts_google_escape_icu_characters($chart[$key]['#prefix']);
      $suffix = _charts_google_escape_icu_characters($chart[$key]['#suffix']);
      $format = $prefix . '#' . $decimal_count . $suffix;
      $series['_format']['format'] = $format;

      // TODO: Convert this from PHP's date format to ICU format.
      // See https://developers.google.com/chart/interactive/docs/reference#dateformatter.
      //$series['_format']['dateFormat'] = $chart[$key]['#date_format'];

      // Conveniently only the axis that supports multiple axes is the one that
      // can receive formatting, so we know that the key will always be plural.
      $axis_type = $chart_type_info['axis_inverted'] ? 'hAxes' : 'vAxes';
      $chart_definition['options'][$axis_type][$axis_index]['format'] = $format;

      // Convert to a ComboChart if mixing types.
      // See https://developers.google.com/chart/interactive/docs/gallery/combochart?hl=en.
      if ($chart[$key]['#chart_type']) {
        // Oddly Google calls a "column" chart a "bars" series. Using actual bar
        // charts is not supported in combo charts with Google.
        $main_chart_type = $chart['#chart_type'] === 'column' ? 'bars' : $chart['#chart_type'];
        $chart_definition['visualization'] = 'ComboChart';
        $chart_definition['options']['seriesType'] = $main_chart_type;

        $data_chart_type = $chart[$key]['#chart_type'] === 'column' ? 'bars' : $chart[$key]['#chart_type'];
        $series['type'] = $data_chart_type;
      }

      // Add the series to the main chart definition.
      charts_trim_array($series);
      $chart_definition['options']['series'][$series_number] = $series;

      // Merge in any point-specific data points.
      foreach (element_children($chart[$key]) as $sub_key) {
        if ($chart[$key][$sub_key]['#type'] === 'chart_data_item') {

          // Make sure defaults are loaded.
          if (empty($chart[$key][$sub_key]['#defaults_loaded'])) {
            $chart[$key][$sub_key] += element_info($chart[$key][$sub_key]['#type']);
          }

          $data_item = $chart[$key][$sub_key];
          if ($data_item['#data']) {
            $chart_definition['data'][$sub_key + 1][$series_number + 1] = $data_item['#data'];
          }
          // These data properties are manually applied to cells in JS.
          // Color role not yet supported. See https://code.google.com/p/google-visualization-api-issues/issues/detail?id=1267
          $chart_definition['_data'][$sub_key + 1][$series_number + 1]['color'] = $data_item['#color'];
          $chart_definition['_data'][$sub_key + 1][$series_number + 1]['tooltip'] = $data_item['#title'];
          charts_trim_array($chart_definition['_data'][$sub_key + 1][$series_number + 1]);
        }
      }

      $series_number++;

    }
  }

  // Once complete, normalize the chart data to ensure a full 2D structure.
  $data = $chart_definition['data'];

  // Stub out corner value.
  $data[0][0] = isset($data[0][0]) ? $data[0][0] : 'x';

  // Ensure consistent column count.
  $column_count = count($data[0]);
  foreach ($data as $row => $values) {
    for ($n = 0; $n < $column_count; $n++) {
      $data[$row][$n] = isset($data[$row][$n]) ? $data[$row][$n] : NULL;
    }
    ksort($data[$row]);
  }
  ksort($data);

  $chart_definition['data'] = $data;

  return $chart_definition;
}

/**
 * Utility to escape special characters in ICU number formats.
 *
 * Google will use the ICU format to auto-adjust numbers based on special
 * characters that are used in the format. This function escapes these special
 * characters so they just show up as the character specified.
 *
 * The format string is a subset of the ICU pattern set. For instance,
 * {pattern:'#,###%'} will result in output values "1,000%", "750%", and "50%"
 * for values 10, 7.5, and 0.5.
 */
function _charts_google_escape_icu_characters($string) {
  return preg_replace('/([0-9@#\.\-,E\+;%\'\*])/', "'$1'", $string);
}
