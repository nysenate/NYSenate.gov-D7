<?php
/**
 * @file
 * Menu callbacks for Charts module.
 */

/**
 * Module settings page. Users can set the default layout of their charts.
 *
 * @param $form
 *   The form array to which this form will be added.
 * @param $defaults
 *   An array of existing values which will be used to populate defaults.
 * @param $field_options
 *   An array of key => value names of fields within this chart.
 * @param $parents
 *   If all the contents of this form should be parented under a particular
 *   namespace, an array of parent names that will be prepended to each
 *   element's #parents property.
 * @return
 *   The form with the chart settings added.
 */
function charts_settings_form($form, $defaults = array(), $field_options = array(), $parents = array()) {
  // Ensure all defaults are set.
  $options = array_merge(charts_default_settings(), $defaults);

  $form['#attached']['library'][] = array('charts', 'charts.admin');

  // Get a list of available chart libraries.
  $charts_info = charts_info();
  $library_options = array();
  foreach ($charts_info as $library_name => $library_info) {
    $library_options[$library_name] = $library_info['label'];
  }
  $form['library'] = array(
    '#title' => t('Charting library'),
    '#type' => 'select',
    '#options' => $library_options,
    '#default_value' => $options['library'],
    '#required' => TRUE,
    '#access' => count($library_options) > 1,
    '#attributes' => array('class' => array('chart-library-select')),
    '#weight' => -15,
    '#parents' => array_merge($parents, array('library')),
  );

  $chart_types = charts_type_info();
  $type_options = array();
  foreach ($chart_types as $chart_type => $chart_type_info) {
    $type_options[$chart_type] = $chart_type_info['label'];
  }
  $form['type'] = array(
    '#title' => t('Chart type'),
    '#type' => 'radios',
    '#default_value' => $options['type'],
    '#options' => $type_options,
    '#required' => TRUE,
    '#weight' => -20,
    '#attributes' => array('class' => array('chart-type-radios', 'container-inline')),
    '#parents' => array_merge($parents, array('type')),
  );

  // Set data attributes to identify special properties of different types.
  foreach ($chart_types as $chart_type => $chart_type_info) {
    if ($chart_type_info['axis_inverted']) {
      $form['type'][$chart_type]['#attributes']['data-axis-inverted'] = TRUE;
    }
    if ($chart_type_info['axis'] === CHARTS_SINGLE_AXIS) {
      $form['type'][$chart_type]['#attributes']['data-axis-single'] = TRUE;
    }
  }

  if ($field_options) {
    $first_field = key($field_options);
    $field_keys = array_diff($field_options, array($first_field => NULL));
    $form['fields']['#theme'] = 'charts_settings_fields';
    $form['fields']['label_field'] = array(
      '#type' => 'radios',
      '#title' => t('Label field'),
      '#options' => $field_options + array('' => t('No label field')),
      '#default_value' => isset($options['label_field']) ? $options['label_field'] : $first_field,
      '#weight' => -10,
      '#parents' => array_merge($parents, array('label_field')),
    );
    $form['fields']['data_fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Data fields'),
      '#options' => $field_options,
      '#default_value' => isset($options['data_fields']) ? $options['data_fields'] : array_diff(array_keys($field_options), array($first_field)),
      '#weight' => -9,
      '#parents' => array_merge($parents, array('data_fields')),
    );
    $color_count = 0;
    foreach ($field_options as $field_name => $field_label) {
      $form['fields']['field_colors'][$field_name] = array(
        '#type' => 'textfield',
        '#attributes' => array('TYPE' => 'color'),
        '#size' => 10,
        '#maxlength' => 7,
        '#theme_wrappers' => array(),
        '#default_value' => !empty($options['field_colors'][$field_name]) ? $options['field_colors'][$field_name] : $options['colors'][$color_count],
        '#parents' => array_merge($parents, array('field_colors', $field_name)),
      );
      $color_count++;
    }
  }

  $form['display'] = array(
    '#title' => t('Display'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['display']['title'] = array(
    '#title' => t('Chart title'),
    '#type' => 'textfield',
    '#default_value' => $options['title'],
    '#parents' => array_merge($parents, array('title')),
  );
  $form['display']['title_position'] = array(
    '#title' => t('Title position'),
    '#type' => 'select',
    '#options' => array(
      '' => t('None'),
      'out' => t('Outside'),
      'in' => t('Inside'),
    ),
    '#default_value' => $options['title_position'],
    '#parents' => array_merge($parents, array('title_position')),
  );

  $form['display']['legend_position'] = array(
    '#title' => t('Legend position'),
    '#type' => 'select',
    '#options' => array(
      '' => t('None'),
      'top' => t('Top'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
      'left' => t('Left'),
    ),
    '#default_value' => $options['legend_position'],
    '#parents' => array_merge($parents, array('legend_position')),
  );

  $form['display']['colors'] = array(
    '#title' => t('Chart colors'),
    '#theme_wrappers' => array('form_element'),
    '#prefix' => '<div class="chart-colors">',
    '#suffix' => '</div>',
  );
  for ($color_count = 0; $color_count < 10; $color_count++) {
    $form['display']['colors'][$color_count] = array(
      '#type' => 'textfield',
      '#attributes' => array('TYPE' => 'color'),
      '#size' => 10,
      '#maxlength' => 7,
      '#theme_wrappers' => array(),
      '#suffix' => ' ',
      '#default_value' => $options['colors'][$color_count],
      '#parents' => array_merge($parents, array('colors', $color_count)),
    );
  }
  $form['display']['background'] = array(
    '#title' => t('Background color'),
    '#type' => 'textfield',
    '#size' => 10,
    '#maxlength' => 7,
    '#attributes' => array('placeholder' => t('transparent')),
    '#description' => t('Leave blank for a transparent background.'),
    '#default_value' => $options['background'],
    '#parents' => array_merge($parents, array('background')),
  );

  $form['display']['dimensions'] = array(
    '#title' => t('Dimensions'),
    '#theme_wrappers' => array('form_element'),
    '#description' => t('If dimensions are left empty, the chart will fill its containing element.'),
  );
  $form['display']['dimensions']['width'] = array(
    '#type' => 'textfield',
    '#attributes' => array('TYPE' => 'number', 'step' => 1, 'min' => 0, 'max' => 9999, 'placeholder' => t('auto')),
    '#default_value' => $options['width'],
    '#size' => 8,
    '#suffix' => ' x ',
    '#theme_wrappers' => array(),
    '#parents' => array_merge($parents, array('width')),
  );
  $form['display']['dimensions']['height'] = array(
    '#type' => 'textfield',
    '#attributes' => array('TYPE' => 'number', 'step' => 1, 'min' => 0, 'max' => 9999, 'placeholder' => t('auto')),
    '#default_value' => $options['height'],
    '#size' => 8,
    '#suffix' => ' px',
    '#theme_wrappers' => array(),
    '#parents' => array_merge($parents, array('height')),
  );

  $form['xaxis'] = array(
    '#title' => t('Horizontal axis'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attributes' => array('class' => array('chart-xaxis')),
  );
  $form['xaxis']['title'] = array(
    '#title' => t('Custom title'),
    '#type' => 'textfield',
    '#default_value' => $options['xaxis_title'],
    '#parents' => array_merge($parents, array('xaxis_title')),
  );
  $form['xaxis']['labels_rotation'] = array(
    '#title' => t('Labels rotation'),
    '#type' => 'select',
    '#options' => array(
      0 => '0°',
      30 => '30°',
      45 => '45°',
      60 => '60°',
      90 => '90°',
    ),
    // This is only shown on non-inverted charts.
    '#attributes' => array('class' => array('axis-inverted-hide')),
    '#default_value' => $options['xaxis_labels_rotation'],
    '#parents' => array_merge($parents, array('xaxis_labels_rotation')),
  );

  $form['yaxis'] = array(
    '#title' => t('Vertical axis'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attributes' => array('class' => array('chart-yaxis')),
  );
  $form['yaxis']['title'] = array(
    '#title' => t('Custom title'),
    '#type' => 'textfield',
    '#default_value' => $options['yaxis_title'],
    '#parents' => array_merge($parents, array('yaxis_title')),
  );
  $form['yaxis']['minmax'] = array(
    '#title' => t('Value range'),
    '#theme_wrappers' => array('form_element'),
  );
  $form['yaxis']['minmax']['min'] = array(
    '#type' => 'textfield',
    '#attributes' => array('TYPE' => 'number', 'max' => 999999, 'placeholder' => t('Minimum')),
    '#default_value' => $options['yaxis_min'],
    '#size' => 12,
    '#parents' => array_merge($parents, array('yaxis_min')),
    '#suffix' => ' ',
    '#theme_wrappers' => array(),
  );
  $form['yaxis']['minmax']['max'] = array(
    '#type' => 'textfield',
    '#attributes' => array('TYPE' => 'number', 'max' => 999999, 'placeholder' => t('Maximum')),
    '#default_value' => $options['yaxis_max'],
    '#size' => 12,
    '#parents' => array_merge($parents, array('yaxis_max')),
    '#theme_wrappers' => array(),
  );
  $form['yaxis']['prefix'] = array(
    '#title' => t('Value prefix'),
    '#type' => 'textfield',
    '#default_value' => $options['yaxis_prefix'],
    '#size' => 12,
    '#parents' => array_merge($parents, array('yaxis_prefix')),
  );
  $form['yaxis']['suffix'] = array(
    '#title' => t('Value suffix'),
    '#type' => 'textfield',
    '#default_value' => $options['yaxis_suffix'],
    '#size' => 12,
    '#parents' => array_merge($parents, array('yaxis_suffix')),
  );
  $form['yaxis']['decimal_count'] = array(
    '#title' => t('Decimal count'),
    '#type' => 'textfield',
    '#attributes' => array('TYPE' => 'number', 'step' => 1, 'min' => 0, 'max' => 20, 'placeholder' => t('auto')),
    '#default_value' => $options['yaxis_decimal_count'],
    '#size' => 5,
    '#description' => t('Enforce a certain number of decimal-place digits in displayed values.'),
    '#parents' => array_merge($parents, array('yaxis_decimal_count')),
  );
  $form['yaxis']['labels_rotation'] = array(
    '#title' => t('Labels rotation'),
    '#type' => 'select',
    '#options' => array(
      0 => '0°',
      30 => '30°',
      45 => '45°',
      60 => '60°',
      90 => '90°',
    ),
    // This is only shown on inverted charts.
    '#attributes' => array('class' => array('axis-inverted-show')),
    '#default_value' => $options['yaxis_labels_rotation'],
    '#parents' => array_merge($parents, array('yaxis_labels_rotation')),
  );

  return $form;
}

/**
 * Menu callback; Configure the site-wide defaults for charts.
 */
function charts_default_settings_form($form, $form_state) {
  $defaults = variable_get('charts_default_settings', array());
  $defaults += charts_default_settings();
  $field_options = array();
  $parents = array('charts_default_settings');

  // Add help.
  $form['help'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('The settings on this page are used to set <strong>default</strong> settings. They do not affect existing charts. To make a new chart, <a href="!views">create a new view</a> and select the display format of "Chart".', array('!views' => url('admin/structure/views/add'))) . '</p>',
    '#weight' => -100,
  );

  // Reuse the global settings form for defaults, but remove JS classes.
  $form = charts_settings_form($form, $defaults, $field_options, $parents);
  $form['xaxis']['#attributes']['class'] = array();
  $form['yaxis']['#attributes']['class'] = array();
  $form['display']['colors']['#prefix'] = NULL;
  $form['display']['colors']['#suffix'] = NULL;

  // Put settings into vertical tabs.
  $form['display']['#group'] = 'defaults';
  $form['xaxis']['#group'] = 'defaults';
  $form['yaxis']['#group'] = 'defaults';
  $form['defaults'] = array(
    '#type' => 'vertical_tabs',
  );

  // Add submit buttons and normal saving behavior.
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save defaults'),
  );

  return $form;
}

/**
 * Submit handler for charts_default_settings_form().
 */
function charts_default_settings_form_submit($form, $form_state) {
  variable_set('charts_default_settings', $form_state['values']['charts_default_settings']);
}

/**
 * Provides default options used by charts_settings_form().
 */
function charts_default_settings() {
  $defaults = array();
  $defaults['type'] = 'pie';
  $defaults['library'] = NULL;
  $defaults['label_field'] = NULL;
  $defaults['data_fields'] = NULL;
  $defaults['field_colors'] = NULL;
  $defaults['title'] = '';
  $defaults['title_position'] = 'out';
  $defaults['legend'] = TRUE;
  $defaults['legend_position'] = 'right';
  $defaults['colors'] = charts_default_colors();
  $defaults['background'] = '';
  $defaults['tooltips'] = TRUE;
  $defaults['tooltips_use_html'] = FALSE;
  $defaults['width'] = NULL;
  $defaults['height'] = NULL;

  $defaults['xaxis_title'] = '';
  $defaults['xaxis_labels_rotation'] = 0;

  $defaults['yaxis_title'] = '';
  $defaults['yaxis_min'] = '';
  $defaults['yaxis_max'] = '';
  $defaults['yaxis_prefix'] = '';
  $defaults['yaxis_suffix'] = '';
  $defaults['yaxis_decimal_count'] = '';
  $defaults['yaxis_labels_rotation'] = 0;

  drupal_alter('charts_default_settings', $defaults);
  return $defaults;
}

/**
 * Output the table of field settings within the charts settings form.
 */
function theme_charts_settings_fields($variables) {
  $element = $variables['element'];

  $table = array(
    'sticky' => FALSE,
  );
  $table['header'] = array(
    array('data' => t('Field name')),
    array('data' => t('Provides labels'), 'class' => array('chart-label-field', 'checkbox')),
    array('data' => t('Provides data'), 'class' => array('chart-data-field', 'checkbox')),
    array('data' => t('Color'), 'class' => array('chart-field-color', 'checkbox')),
  );
  foreach ($element['label_field']['#options'] as $field_name => $field_label) {
    $element['label_field'][$field_name]['#title_display'] = 'attribute';
    $element['data_fields'][$field_name]['#title_display'] = 'attribute';
    $element['field_colors'][$field_name]['#title_display'] = 'attribute';

    $row = array();
    $row[] = array(
      'data' => $field_label,
    );
    $row[] = array(
      'data' => drupal_render($element['label_field'][$field_name]),
      'class' => array('chart-label-field', 'checkbox'),
    );
    $row[] = array(
      'data' => $field_name ? drupal_render($element['data_fields'][$field_name]) : '',
      'class' => array('chart-data-field', 'checkbox'),
    );
    $row[] = array(
      'data' => $field_name ? drupal_render($element['field_colors'][$field_name]) : '',
      'class' => array('chart-field-color', 'checkbox'),
    );
    $table['rows'][] = $row;
  }

  $wrapper = array(
    '#title' => t('Chart fields'),
    '#id' => 'chart-fields',
    '#theme_wrappers' => array('form_element'),
    '#markup' => theme('table', $table),
    '#description' => t('Any field may be used to provide labels. Usually this is the first field configured in the view. e.g. Month names, types of content, etc. Subsequent fields typically provide numeric data which can be charted. In some chart types, no label field may be used at all to utilize a continuous axis.'),
  );

  return drupal_render($wrapper);
}
