<?php
/**
 * @file
 * 'Wrapper: Element' style.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Wrapper: Element'),
  'description' => t('Wrap regions and panes with HTML elements.'),
  'render region' => 'panels_extra_styles_wrapper_render_region',
  'render pane' => 'panels_extra_styles_wrapper_render_pane',
  'settings form' => 'panels_extra_styles_wrapper_element_region_settings_form',
  'pane settings form' => 'panels_extra_styles_wrapper_element_pane_settings_form',
);

/**
 * Region settings form callback.
 */
function panels_extra_styles_wrapper_element_region_settings_form($style_settings) {
  // Content.
  $element_default_value = isset($style_settings['content']['element']) ? $style_settings['content']['element'] : '';
  $form['content']['element'] = array(
    '#title' => t('Content'),
    '#description' => t('HTML element to wrap around the content.'),
  ) + _panels_extra_styles_wrapper_element_options($element_default_value);

  // Content attributes.
  $attributes_default_value = isset($style_settings['content']['attributes']) ? $style_settings['content']['attributes'] : array();
  $form['content']['attributes'] = array(
    '#title' => t('Content Attributes'),
  ) + _panels_extra_styles_wrapper_attribute_options($attributes_default_value);

  // Theming.
  $theme_default_value = !empty($style_settings['theme']) ? $style_settings['theme'] : FALSE;
  $form += _panels_extra_styles_wrapper_element_theme_options($theme_default_value);

  return $form;
}

/**
 * Pane settings form callback.
 */
function panels_extra_styles_wrapper_element_pane_settings_form($style_settings) {
  // Title.
  $element_default_value = isset($style_settings['title']['element']) ? $style_settings['title']['element'] : '';
  $form['title']['element'] = array(
    '#title' => t('Title'),
    '#description' => t('HTML element to wrap around the title.'),
  ) + _panels_extra_styles_wrapper_element_options($element_default_value);

  // Title attributes.
  $attributes_default_value = isset($style_settings['title']['attributes']) ? $style_settings['title']['attributes'] : array();
  $form['title']['attributes'] = array(
    '#title' => t('Title Attributes'),
  ) + _panels_extra_styles_wrapper_attribute_options($attributes_default_value);

  // Content form items, grabbed from the region settings.
  $form += panels_extra_styles_wrapper_element_region_settings_form($style_settings);

  // Theming.
  $theme_default_value = !empty($style_settings['theme']) ? $style_settings['theme'] : FALSE;
  $form += _panels_extra_styles_wrapper_element_theme_options($theme_default_value);

  return $form;
}

/**
 * Element options for settings forms.
 */
function _panels_extra_styles_wrapper_element_options($default_value = '') {
  $options = array(
    '#type' => 'select',
    '#default_value' => $default_value,
  );

  if (module_exists('fences') && function_exists('fences_get_fences_options')) {
    // Element options, grabbed from the fences module.
    $options['#options'] = fences_get_fences_options('field');
  }
  else {
    // Notify user of fences awesomenss.
    drupal_set_message(t('Install the <a href="@fences_link">fences</a> module for a <em>plethora</em> of options!',
      array('@fences_link' => url('http://drupal.org/project/fences'))),
      'warning', FALSE);

    // Fallback element options, grabbed from View's defaults.
    $options['#options'] = variable_get('views_field_rewrite_elements', array(
      '' => t('- Use default -'),
      '0' => t('- None -'),
      'div' => 'DIV',
      'span' => 'SPAN',
      'h1' => 'H1',
      'h2' => 'H2',
      'h3' => 'H3',
      'h4' => 'H4',
      'h5' => 'H5',
      'h6' => 'H6',
      'p' => 'P',
      'strong' => 'STRONG',
      'em' => 'EM',
    ));
  }

  return $options;
}

/**
 * Attribute options for settings forms.
 */
function _panels_extra_styles_wrapper_attribute_options($default_value = array()) {
  $options = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $options['id'] = array(
    '#type' => 'textfield',
    '#title' => t('id'),
    '#description' => t('CSS id to apply to the element, without the hash.'),
    '#default_value' => isset($default_value['id']) ? $default_value['id'] : '',
  );
  $options['class'] = array(
    '#type' => 'textfield',
    '#title' => t('class'),
    '#description' => t('CSS classes to apply to the element, separated by spaces.'),
    '#default_value' => isset($default_value['class']) ? $default_value['class'] : '',
  );

  return $options;
}

/**
 * Theme options for settings forms.
 */
function _panels_extra_styles_wrapper_element_theme_options($default_value = FALSE) {
  $options['theme'] = array(
    '#type' => 'checkbox',
    '#title' => t('Additionally, wrap the content with Panels theming layer.'),
    '#default_value' => $default_value,
  );

  return $options;
}
