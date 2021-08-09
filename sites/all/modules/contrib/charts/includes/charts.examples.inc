<?php

/**
 * Menu callback; Display all examples in the system.
 */
function charts_examples($library = NULL, $id = NULL) {
  $functions = get_defined_functions();
  if ($library && $library_info = chart_get_library($library)) {
    $charts_info = array($library => $library_info);
  }
  else {
    $charts_info = charts_info();
  }
  $output = array();

  $table = array();
  foreach ($charts_info as $library => $chart_library_info) {
    $table['header'][] = array(
      'width' => (1 / count($charts_info) * 100) . '%',
      'data' => $chart_library_info['label'],
    );
  }

  $table['rows'] = array();
  foreach ($functions['user'] as $function) {
    if (($id && '_charts_examples_' . $id === $function) || (!$id && strpos($function, '_charts_examples_') === 0)) {
      $row = array();
      foreach ($charts_info as $library => $chart_library_info) {
        $example = $function();
        $example['chart']['#chart_library'] = $library;
        $example['chart']['#height'] = 200;
        $notes = '';
        if (isset($example['notes'][$library])) {
          $notes = '<p>' . t('Note') . ': ' . $example['notes'][$library] . '</p>';
        }
        $row[] = array(
          'data' => drupal_render($example['chart']) . l(t('View'), 'charts/examples/built-in/' . $library . '/' . str_replace('_charts_examples_', '', $function)) . $notes,
          'valign' => 'top',
        );
      }
      $table['rows'][] = $row;
    }
  }

  return theme('table', $table);

}

function _charts_examples_pie_simple() {
  $chart = array(
    '#type' => 'chart',
    '#title' => t('Pie simple'),
    '#chart_type' => 'pie',
    '#chart_library' => 'highcharts',
    '#legend_position' => 'right',
    '#data_labels' => TRUE,
    '#tooltips' => FALSE,
  );
  $chart['pie_data'] = array(
    '#type' => 'chart_data',
    '#title' => t('Gender'),
    '#labels' => array('Male', 'Female'),
    '#data' => array(10, 20),
  );

  $example['chart'] = $chart;

  return $example;
}

function _charts_examples_pie_tooltips() {
  $example = _charts_examples_pie_simple();
  $example['chart']['#title'] = t('Pie tooltips');
  $example['chart']['#tooltips'] = TRUE;
  $example['chart']['#data_labels'] = FALSE;
  return $example;
}

function _charts_examples_pie_alternative_syntax() {
  $chart = array(
    '#type' => 'chart',
    '#title' => t('Pie alternative syntax'),
    '#chart_type' => 'pie',
    '#chart_library' => 'highcharts',
    '#legend_position' => 'right',
    '#data_labels' => TRUE,
    '#tooltips' => FALSE,
  );
  $chart['pie_data'] = array(
    '#type' => 'chart_data',
    '#title' => t('Gender'),
    '#data' => array(array('Male', 10), array('Female', 20)),
  );

  $example['chart'] = $chart;

  return $example;
}

function _charts_examples_pie_data_overrides() {
  $example = _charts_examples_pie_simple();
  $example['chart']['#title'] = t('Pie data overrides');
  $example['chart']['#tooltips'] = TRUE;
  $example['chart']['pie_data'][0] = array(
    '#type' => 'chart_data_item',
    '#data' => 15,
    '#color' => 'red',
    '#title' => t('Dudes'),
  );
  $example['chart']['pie_data'][1] = array(
    '#type' => 'chart_data_item',
    '#data' => 20,
    '#title' => t('Chicks'),
  );

  $example['notes']['google'] = t('Google cannot assign a color to an individual item. See this <a href="https://code.google.com/p/google-visualization-api-issues/issues/detail?id=1267">feature request</a>.');

  return $example;
}

function _charts_examples_column_simple() {
  $chart = array(
    '#type' => 'chart',
    '#chart_type' => 'column',
    '#title' => t('Column simple'),
  );
  $chart['male'] = array(
    '#type' => 'chart_data',
    '#title' => t('Male'),
    '#data' => array(10, 20, 30),
    '#suffix' => 'lbs',
  );
  $chart['female'] = array(
    '#type' => 'chart_data',
    '#title' => t('Female'),
    '#data' => array(12, 22, 32),
    '#suffix' => 'lbs',
  );
  $chart['xaxis'] = array(
    '#type' => 'chart_xaxis',
    '#labels' => array('Jan', 'Feb', 'Mar'),
  );

  $example['chart'] = $chart;

  return $example;
}

function _charts_examples_column_stacking() {
  $example = _charts_examples_column_simple();
  $example['chart']['#title'] = t('Column stacked');
  $example['chart']['#stacking'] = TRUE;

  return $example;
}

function _charts_examples_bar_simple() {
  $example = _charts_examples_column_simple();
  $example['chart']['#title'] = t('Bar simple');
  $example['chart']['#chart_type'] = 'bar';
  return $example;
}

function _charts_examples_line_gap() {
  $chart = array(
    '#type' => 'chart',
    '#chart_type' => 'line',
    '#title' => t('Line with interpolated gap'),
  );
  // Test with a gap in the data.
  $chart['male'] = array(
    '#type' => 'chart_data',
    '#title' => t('Male'),
    '#data' => array(array(0, 0), array(10, NULL), array(20, 30), array(30, 30), array(40, 40)),
  );
  $chart['female'] = array(
    '#type' => 'chart_data',
    '#title' => t('Female'),
    '#data' => array(array(0, 5), array(10, 14), array(20, 16), array(30, 36), array(40, 48)),
  );

  $example['chart'] = $chart;

  return $example;
}

function _charts_examples_scatter() {
  $chart = array(
    '#type' => 'chart',
    '#chart_type' => 'scatter',
    '#title' => t('Scatter'),
  );
  $chart['male'] = array(
    '#type' => 'chart_data',
    '#title' => t('Male'),
    '#data' => array(array(10, 10), array(20, 20), array(30, 30)),
  );
  $chart['female'] = array(
    '#type' => 'chart_data',
    '#title' => t('Female'),
    '#data' => array(array(12, 12), array(20, 24), array(30, 36)),
  );

  $example['chart'] = $chart;

  return $example;
}

function _charts_examples_combo() {
  $chart = array(
    '#type' => 'chart',
    '#chart_type' => 'column',
    '#title' => t('Combo'),
    '#legend_position' => 'bottom',
  );
  $chart['male'] = array(
    '#type' => 'chart_data',
    '#title' => t('Male'),
    '#data' => array(10, 20, 30),
    '#suffix' => 'lbs',
  );
  $chart['female'] = array(
    '#type' => 'chart_data',
    '#title' => t('Female'),
    '#data' => array(12, 22, 32),
    '#suffix' => 'lbs',
  );
  $chart['female'][0] = array(
    '#type' => 'chart_data_item',
    '#title' => t('Special title'),
    '#color' => 'red',
    '#data' => 22,
  );

  $secondary_color = '#B617E5';
  $chart['line'] = array(
    '#type' => 'chart_data',
    '#chart_type' => 'line',
    '#data' => array(7, 44, 100),
    '#title' => t('Average'),
    '#target_axis' => 'yaxis2',
    '#color' => $secondary_color,
    //'#marker_radius' => 10,
    '#prefix' => '$',
  );
  $chart['line'][1] = array(
    '#type' => 'chart_data_item',
    //'#color' => 'red',
    //'#radius' => 10,
  );

  $chart['xaxis'] = array(
    '#type' => 'chart_xaxis',
    '#labels' => array('Jan', 'Feb', 'Mar'),
  );

  $chart['yaxis'] = array(
    '#type' => 'chart_yaxis',
    '#axis_type' => 'linear',
  );

  $chart['yaxis2'] = array(
    '#type' => 'chart_yaxis',
    '#axis_type' => 'linear',
    '#opposite' => TRUE,
    '#title' => t('Avg'),
    '#labels_color' => $secondary_color,
    '#title_color' => $secondary_color,
  );

  $example['chart'] = $chart;

  $example['notes']['google'] = t('Google charts cannot provide a legend on the same side as an axis, so legends cannot be displayed on the left or right in a combo chart.') . ' ' . t('Google cannot assign a color to an individual item. See this <a href="https://code.google.com/p/google-visualization-api-issues/issues/detail?id=1267">feature request</a>.');

  return $example;
}
