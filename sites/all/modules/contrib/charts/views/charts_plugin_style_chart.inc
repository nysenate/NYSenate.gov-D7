<?php
/**
 * @file
 * Contains the Chart style (format) plugin (similar to Table, HTML List, etc.)
 */

/**
 * Style plugin to render view as a chart.
 *
 * @ingroup views_style_plugins
 */
class charts_plugin_style_chart extends views_plugin_style {
  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    // Get the default chart values
    module_load_include('inc', 'charts', 'includes/charts.pages');
    $defaults = variable_get('charts_default_settings', array());
    $defaults += charts_default_settings();
    foreach ($defaults as $default_key => $default_value) {
      $options[$default_key]['default'] = $default_value;
    }

    // Remove the default setting for chart type so it can be inherited if this
    // is a chart extension type.
    if ($this->plugin_name === 'chart_extension') {
      $options['type']['default'] = NULL;
    }

    return $options;
  }

  /**
   * Generate a form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $handlers = $this->display->handler->get_handlers('field');
    if (empty($handlers)) {
      $form['error_markup'] = array(
        '#markup' => '<div class="error messages">' . t('You need at least one field before you can configure your table settings') . '</div>',
      );
      return;
    }

    // Merge in the global chart settings form.
    module_load_include('inc', 'charts', 'includes/charts.pages');
    $field_options = $this->display->handler->get_field_labels();
    $form = charts_settings_form($form, $this->options, $field_options, array('style_options'));

    // Reduce the options if this is a chart extension.
    if ($parent_display = $this->get_parent_chart_display()) {
      $parent_chart_type = chart_get_type($parent_display->display_options['style_options']['type']);
      if (empty($form['type']['#default_value'])) {
        $form['type']['#default_value'] = $parent_display->display_options['style_options']['type'];
      }

      $form['type']['#description'] = empty($form['type']['#description']) ? '' : $form['type']['#description'] . ' ';
      $form['type']['#description'] .= t('This chart will be combined with the parent display "@display_title", which is a "@type" chart. Not all chart types may be combined. Selecting a different chart type than the parent may cause errors.', array('@display_title' => $parent_display->display_title, '@type' => $parent_chart_type['label']));
      $form['fields']['label_field']['#disabled'] = TRUE;
      $form['display']['#access'] = FALSE;
      $form['xaxis']['#access'] = FALSE;
      if ($this->display->handler->get_option('inherit_yaxis')) {
        $form['yaxis']['#access'] = FALSE;
      }
      else {
        $form['yaxis']['#title'] = t('Secondary axis');
        $form['yaxis']['#attributes']['class'] = array();
      }
    }
  }

  /**
   * Generate a form for setting options.
   */
  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
  }

  /**
   * Make sure the display and all associated handlers are valid.
   *
   * @return
   *   Empty array if the display is valid; an array of error strings if it is not.
   */
  function validate() {
    $errors = array();
    $field_handlers = $this->display->handler->get_handlers('field');

    // Don't execute validation on the new view page.
    if ($_GET['q'] === 'admin/structure/views/add') {
      return;
    }

    // Make sure that all chart extensions first have a parent chart selected.
    if ($this->plugin_name === 'chart_extension' && $this->get_parent_chart_display() === FALSE) {
      $errors[] = t('This chart add-on must have a parent chart selected under the chart settings.');
    }
    // Make sure that at least one data column has been selected.
    elseif (count($field_handlers)) {
      $data_field_key = !empty($this->options['data_fields']) ? current($this->options['data_fields']) : NULL;
      if (empty($data_field_key)) {
        $errors[] = t('At least one data field must be selected in the chart configuration before this chart may be shown');
      }
      else {
        $data_field = isset($field_handlers[$data_field_key]) ? $field_handlers[$data_field_key] : NULL;
        if (!isset($data_field)) {
          $errors[] = t('A field you have specified as a data field in your chart settings no longer exists. Edit the chart settings and select at least one data field.');
        }
      }
    }

    return $errors;
  }

  /**
   * Render the entire view from the view result.
   */
  function render() {
    $field_handlers = $this->display->handler->get_handlers('field');

    // Calculate the labels field alias.
    $label_field = FALSE;
    $label_field_key = NULL;
    if ($this->options['label_field'] && array_key_exists($this->options['label_field'], $field_handlers)) {
      $label_field = $field_handlers[$this->options['label_field']];
      $label_field_key = $this->options['label_field'];
    }

    // Assemble the fields to be used to provide data access.
    $data_field_options = array_filter($this->options['data_fields']);
    $data_fields = array();
    foreach ($data_field_options as $field_key) {
      if (isset($field_handlers[$field_key])) {
        $data_fields[$field_key] = $field_handlers[$field_key];
      }
    }
    // Do not allow the label field to be used as a data field.
    if (isset($data_fields[$label_field_key])) {
      unset($data_fields[$label_field_key]);
    }

    $chart_id = $this->view->name . '__' . $this->view->current_display;
    $chart = array(
      '#type' => 'chart',
      '#chart_type' => $this->options['type'],
      '#chart_library' => $this->options['library'],
      '#chart_id' => $chart_id,
      '#id' => drupal_clean_css_identifier('chart_' . $chart_id),
      '#title' => $this->options['title_position'] ? $this->options['title'] : FALSE,
      '#title_position' => $this->options['title_position'],
      '#colors' => $this->options['colors'],
      '#background' => $this->options['background'] ? $this->options['background'] : 'transparent',
      '#legend' => $this->options['legend_position'] ? TRUE : FALSE,
      '#legend_position' => $this->options['legend_position'] ? $this->options['legend_position'] : NULL,
      '#width' => $this->options['width'],
      '#height' => $this->options['height'],
    );
    $chart_type_info = chart_get_type($this->options['type']);

    if ($chart_type_info['axis'] === CHARTS_SINGLE_AXIS) {
      $data_field_key = key($data_fields);
      $data_field = $data_fields[$data_field_key];

      $data = array();
      $renders = $this->render_fields($this->view->result);
      foreach ($renders as $row_number => $row) {
        $data_row = array();
        if ($label_field_key) {
          // Labels need to be decoded, as the charting library will re-encode.
          $data_row[] = htmlspecialchars_decode($renders[$row_number][$label_field_key], ENT_QUOTES);
        }
        // Convert empty strings to NULL.
        if ($renders[$row_number][$data_field_key] === '') {
          $value = NULL;
        }
        else {
          $value = (float) $renders[$row_number][$data_field_key];
        }
        $data_row[] = $value;
        $data[] = $data_row;
      }

      if ($label_field) {
        $chart['#legend_title'] = $label_field->options['label'];
      }

      $chart[$this->view->current_display . '_series'] = array(
        '#type' => 'chart_data',
        '#data' => $data,
        '#title' => $data_field->options['label'],
      );
    }
    else {
      $chart['xaxis'] = array(
        '#type' => 'chart_xaxis',
        '#title' => $this->options['xaxis_title'] ? $this->options['xaxis_title'] : FALSE,
        '#labels_rotation' => $this->options['xaxis_labels_rotation'],
      );
      $chart['yaxis'] = array(
        '#type' => 'chart_yaxis',
        '#title' => $this->options['yaxis_title'] ? $this->options['yaxis_title'] : FALSE,
        '#labels_rotation' => $this->options['yaxis_labels_rotation'],
        '#max' => $this->options['yaxis_max'],
        '#min' => $this->options['yaxis_min'],
      );
      foreach ($data_fields as $field_key => $field_handler) {
        $chart[$this->view->current_display . '__' . $field_key] = array(
          '#type' => 'chart_data',
          '#data' => array(),
          '#color' => isset($this->options['field_colors'][$field_key]) ? $this->options['field_colors'][$field_key] : NULL,
          '#title' => $field_handler->options['label'],
          '#prefix' => $this->options['yaxis_prefix'] ? $this->options['yaxis_prefix'] : NULL,
          '#suffix' => $this->options['yaxis_suffix'] ? $this->options['yaxis_suffix'] : NULL,
          '#decimal_count' => $this->options['yaxis_decimal_count'] ? $this->options['yaxis_decimal_count'] : NULL,
        );
      }

      $renders = $this->render_fields($this->view->result);
      foreach ($renders as $row_number => $row) {
        if ($label_field_key) {
          $chart['xaxis']['#labels'][] = $renders[$row_number][$label_field_key];
        }
        foreach ($data_fields as $field_key => $field_handler) {
          // Convert empty strings to NULL.
          if ($renders[$row_number][$field_key] === '') {
            $value = NULL;
          }
          // Strip thousands placeholders if present, then cast to float.
          else {
            $value = (float) str_replace(array(',', ' '), '', $renders[$row_number][$field_key]);
          }
          $chart[$this->view->current_display . '__' . $field_key]['#data'][] = $value;
        }
      }
    }

    // Check if this display has any children charts that should be applied
    // on top of it.
    $parent_display_id = $this->view->current_display;
    $children_displays = $this->get_children_chart_displays();
    foreach ($children_displays as $child_display_id => $child_display) {
      // If the user doesn't have access to the child display, skip.
      if (!$this->view->access($child_display_id)) {
        continue;
      }

      // Generate the subchart by executing the child display. We load a fresh
      // view here to avoid collisions in shifting the current display while in
      // a display.
      $subview = $this->view->clone_view();
      $subview->set_display($child_display_id);

      // Copy the settings for our axes over to the child view.
      foreach ($this->options as $option_name => $option_value) {
        if (strpos($option_name, 'yaxis') === 0 && $child_display->handler->get_option('inherit_yaxis')) {
          $subview->display_handler->options['style_options'][$option_name] = $option_value;
        }
        elseif (strpos($option_name, 'xaxis') === 0) {
          $subview->display_handler->options['style_options'][$option_name] = $option_value;
        }
      }

      // Execute the subview and get the result.
      $subview->pre_execute();
      $subview->execute();

      // If there's no results, don't attach the subview.
      if (empty($subview->result)) {
        continue;
      }

      $subchart = $subview->style_plugin->render($subview->result);
      $subview->post_execute();
      unset($subview);

      // Create a secondary axis if needed.
      if (!$child_display->handler->get_option('inherit_yaxis') && isset($subchart['yaxis'])) {
        $chart['secondary_yaxis'] = $subchart['yaxis'];
        $chart['secondary_yaxis']['#opposite'] = TRUE;
      }

      // Merge in the child chart data.
      foreach (element_children($subchart) as $key) {
        if ($subchart[$key]['#type'] === 'chart_data') {
          $chart[$key] = $subchart[$key];
          // If the subchart is a different type than the parent chart, set
          // the #chart_type property on the individual chart data elements.
          if ($subchart['#chart_type'] !== $chart['#chart_type']) {
            $chart[$key]['#chart_type'] = $subchart['#chart_type'];
          }
          if (!$child_display->handler->get_option('inherit_yaxis')) {
            $chart[$key]['#target_axis'] = 'secondary_yaxis';
          }
        }
      }
    }

    // Print the chart.
    return $chart;
  }

  /**
   * Utility function to check if this chart has a parent display.
   */
  function get_parent_chart_display() {
    $parent_display = FALSE;
    if ($this->plugin_name === 'chart_extension' && $this->display && $this->display->handler->options['parent_display']) {
      $parent_display_name = $this->display->handler->options['parent_display'];
      if (isset($this->view->display[$parent_display_name])) {
        $parent_display = $this->view->display[$parent_display_name];
      }
    }
    // Ensure the parent is a chart.
    if ($parent_display && $parent_display->display_options['style_plugin'] !== 'chart') {
      $parent_display = FALSE;
    }
    return $parent_display;
  }

  /**
   * Utility function to check if this chart has children displays.
   */
  function get_children_chart_displays() {
    $children_displays = array();
    foreach ($this->view->display as $display_name => $display) {
      $display_enabled = $this->view->display[$display_name]->handler->get_option('enabled');
      if ($display->display_plugin === 'chart' && $display->display_options['parent_display'] && empty($display->deleted) && $display_enabled) {
        $parent_display_name = $display->display_options['parent_display'];
        if ($parent_display_name === $this->view->current_display) {
          $children_displays[$display_name] = $this->view->display[$display_name];
        }
      }
    }
    return $children_displays;
  }
}
