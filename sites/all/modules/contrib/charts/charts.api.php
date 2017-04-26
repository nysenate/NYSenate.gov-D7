<?php
/**
 * @file
 * Documentation on hooks provided by the Charts module.
 *
 * Charts module provides 4 element types that can be used to construct a chart.
 * In its most basic form, a chart may be created by specifying an element
 * with the #type property "chart".
 *
 * @code
 * $chart = array(
 *   '#type' => 'chart',
 *   '#chart_type' => 'pie',
 *   '#data' => array(array('Male', 10), array('Female')),
 * );
 * @endcode
 *
 * On charts that have multiple axes, you'll need to add individual sub-elements
 * for each series of data. If you desire, you may also customize the axes by
 * providing an axis element too.
 *
 * @code
 * $chart = array(
 *   '#type' => 'chart',
 *   '#chart_type' => 'column',
 * );
 * $chart['male'] = array(
 *   '#type' => 'chart_data',
 *   '#title' => t('Male'),
 *   '#data' => array(10, 20, 30),
 * );
 * $chart['xaxis'] = array(
 *   '#type' => 'chart_xaxis',
 *   '#title' => t('Month'),
 *   '#labels' => array(t('Jan'), t('Feb'), t('Mar')),
 * );
 * @endcode
 *
 * Once you have generated a chart object, you can run drupal_render() on it
 * to turn it into HTML:
 *
 * @code
 * $output = drupal_render($chart);
 * @endcode
 *
 * There are many, many properties available for the four chart types (chart,
 * chart_data, chart_xaxis, and chart_yaxis). For a full list, see the
 * charts_element_info() function.
 *
 * This module also includes a number of examples for reference, which can be
 * views at "charts/examples". The source code may be read in the
 * "charts.examples.inc" file in the includes directory.
 *
 * @see charts_element_info()
 */

/**
 * Alter an individual chart before it is printed.
 *
 * @param $chart
 *   The chart renderable. Passed in by reference.
 * @param $chart_id
 *   The chart identifier, pulled from the $chart['#chart_id'] property (if
 *   any). Not all charts have a chart identifier.
 */
function hook_chart_alter(&$chart, $chart_id) {
  if ($chart_id === 'view_name__display_name') {
    // Individual properties may be modified.
    $chart['#title_font_size'] = 20;
  }
}

/**
 * Alter an individual chart before it's rendered.
 *
 * Same as hook_chart_alter(), only including the $chart_id in the function
 * name instead of being passed in as an argument.
 *
 * @see hook_chart_alter()
 */
function hook_chart_CHART_ID_alter(&$chart) {
}

/**
 * Alter an individual chart's raw library representation.
 *
 * This hook is called AFTER hook_chart_alter(), after Charts module has
 * converted the renderable into the chart definition that will be used by the
 * library. Note that the structure of $definition will differ based on the
 * charting library used. Switching charting libraries may cause your code
 * to break when using this hook.
 *
 * Even though this hook may be fragile, it may provide developers with access
 * to library-specific functionality.
 *
 * @param $definition
 *   The chart definition to be modified. The raw values are passed directly to
 *   the charting library.
 * @param $chart
 *   The chart renderable. This may be used for reference (or read to add
 *   support for new properties), but any changes to this variable will not
 *   have an effect on output.
 * @param $chart_id
 *   The chart ID, derived from the $chart['#chart_id'] property. Note that not
 *   all charts may have a $chart_id.
 */
function hook_chart_definition_alter(&$definition, $chart, $chart_id) {
  if ($chart['#chart_library'] === 'google') {
    $definition['options']['titleTextStyle']['fontSize'] = 20;
  }
  elseif ($chart['#chart_library'] === 'highcharts') {
    $definition['title']['style']['fontSize'] = 20;
  }
}

/**
 * Alter an individual chart before it's rendered.
 *
 * Same as hook_chart_definition_alter(), only including the $chart_id in the
 * function name instead of being passed in as an argument.

 * @see hook_chart_definition_alter()
 */
function hook_chart_definition_CHART_ID_alter(&$chart) {
}

/**
 * Provide a new charting library to the system.
 *
 * Libraries provided by this function will be made available as a choice for
 * rendering charts in the Charts interface. Any libraries specified in this
 * hook may be used as a #chart_library property on $chart renderables.
 */
function hook_charts_info() {
  $info['my_charting_library'] = array(
    'label' => t('New charting library'),
    // Specify a callback function which will be responsible for accepting a
    // $chart renderable and printing a chart on the page.
    'render' => '_my_charting_library_render',
    // Specify the chart types your library is capable of providing.
    'types' => array('area', 'bar', 'column', 'line', 'pie', 'scatter'),
    // If your callback function is in a separate file, specify it's location.
    'file' => 'includes/my_charting_library.inc',
  );
  return $info;
}

/**
 * Alter the chart types in the system.
 *
 * If your module needs to modify the capabilities of a charting library, such
 * as to add support for a new chart type, it may do so with this hook.
 */
function hook_charts_info_alter(&$info) {
  // Say the Google charts library supports geo charts.
  $info['google']['types'][] = 'geo';
}

/**
 * Provide a new chart type to the system.
 *
 * Any chart types provided by this hook may be used as a #chart_type property
 * on a $chart renderable. Note that not all chart types may be supported by
 * all charting libraries.
 */
function hook_charts_type_info() {
  $chart_types['bar'] = array(
    'label' => t('Bar'),
    // If this chart supports both an X and Y axis, set this to
    // CHARTS_DUAL_AXIS. If only a single axis is supported (e.g. pie), then
    // set this to CHARTS_SINGLE_AXIS.
    'axis' => CHARTS_DUAL_AXIS,
    // Many charting libraries always refer to the main axis as the "y-axis",
    // even if the chart's main axis is horizontal. An example of this is a
    // bar chart, where the values are along the horizontal axis.
    'axis_inverted' => TRUE, // Meaning x/y axis are flipped.
    // For bar/area/other charts that support stacking of series, set this value
    // to TRUE.
    'stacking' => TRUE,
  );
  return $chart_types;
}

/**
 * Alter the chart types in the system.
 *
 * If your module needs to modify the capabilities or labels of a paricular
 * chart type, it may alter the definitions provided by other modules.
 */
function hook_charts_type_info_alter(&$chart_types) {
  $chart_types['bar']['stacking'] = FALSE;
}
