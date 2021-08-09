<?php
/**
 * @file
 * 'Wrapper: Raw' style.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Wrapper: Raw'),
  'description' => t('Wrap regions and panes with raw HTML.'),
  'render region' => 'panels_extra_styles_wrapper_render_region',
  'render pane' => 'panels_extra_styles_wrapper_render_pane',
  'settings form' => 'panels_extra_styles_wrapper_raw_region_settings_form',
  'pane settings form' => 'panels_extra_styles_wrapper_raw_pane_settings_form',
);

/**
 * Region settings form callback.
 */
function panels_extra_styles_wrapper_raw_region_settings_form($style_settings) {
  $settings_default_value = isset($style_settings['content']) ? $style_settings['content'] : array();
  $form['content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content'),
  ) + _panels_extra_styles_wrapper_raw_prefix_suffix_options($settings_default_value);

  // Theming.
  $theme_default_value = !empty($style_settings['theme']) ? $style_settings['theme'] : FALSE;
  $form += _panels_extra_styles_wrapper_raw_theme_options($theme_default_value);

  return $form;
}

/**
 * Pane settings form callback.
 */
function panels_extra_styles_wrapper_raw_pane_settings_form($style_settings) {
  $settings_default_value = isset($style_settings['title']) ? $style_settings['title'] : array();
  $form['title'] = array(
    '#type' => 'fieldset',
    '#title' => t('Title'),
  ) + _panels_extra_styles_wrapper_raw_prefix_suffix_options($settings_default_value);

  // Content form items, grabbed from region settings.
  $form += panels_extra_styles_wrapper_raw_region_settings_form($style_settings);

  // Theming.
  $theme_default_value = !empty($style_settings['theme']) ? $style_settings['theme'] : FALSE;
  $form += _panels_extra_styles_wrapper_raw_theme_options($theme_default_value);

  return $form;
}

/**
 * Prefix & suffix options for settings form.
 */
function _panels_extra_styles_wrapper_raw_prefix_suffix_options($default_value = array()) {
  $options['prefix'] = array(
    '#type' => 'textarea',
    '#title' => t('Prefix'),
    '#description' => t('HTML code to go <em>before</em> the content.'),
    '#default_value' => isset($default_value['prefix']) ? $default_value['prefix'] : '',
  );
  $options['suffix'] = array(
    '#type' => 'textarea',
    '#title' => t('Suffix'),
    '#description' => t('HTML code to go <em>after</em> the content.'),
    '#default_value' => isset($default_value['suffix']) ? $default_value['suffix'] : '',
  );

  return $options;
}

/**
 * Theme options for settings forms.
 */
function _panels_extra_styles_wrapper_raw_theme_options($default_value = FALSE) {
  $options['theme'] = array(
    '#type' => 'checkbox',
    '#title' => t('Additionally, wrap the content with Panels theming layer.'),
    '#default_value' => $default_value,
  );

  return $options;
}
