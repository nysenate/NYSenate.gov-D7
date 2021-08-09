<?php

/**
 * @file
 * Definition of the 'Responsive Tabs' panel style.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Responsive Tabs'),
  'description' => t('Show panel panes in a region as responsive tabs.'),
  'render region' => 'panels_responsive_tabs_style_render_region',
  'settings form' => 'panels_responsive_tabs_style_settings_form',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_responsive_tabs_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];

  $tab_id = drupal_html_id('tabs-' . $owner_id . '-' . $region_id);

  $element = array(
    '#prefix' => '<div id="' . $tab_id . '">',
    '#suffix' => '</div>',
    '#attached' => array(
      'libraries_load' => array(array('easy-responsive-tabs')),
      'js' => array(
        drupal_get_path('module', 'panels_responsive_tabs') . '/js/panels_responsive_tabs.js' => array('type' => 'file'),
      ),
    ),
  );

  $vars['settings']['tabidentify'] = panels_responsive_tabs_pane_tabidentifiers($display->did, $region_id);

  $settings = array(
    array(
      'identifier' => $tab_id,
    ) + $vars['settings'],
  );
  $js_settings['panels_responsive_tabs'] = $settings;

  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => $js_settings,
  );

  // Get the pane titles.
  $items = array();
  $delta = 1;

  if (isset($display->panels[$region_id])) {
    foreach ($display->panels[$region_id] as $pane_id) {
      // Make sure the pane exists.
      if (!empty($panes[$pane_id])) {
        $title = panels_responsive_tabs_pane_titles($display->did, $pane_id);
        $title = $title ? $title : t('Tab @delta', array('@delta' => $delta));
        $items[] = array(
          'data' => $title,
          'class' => array('tabs', 'tab--' . drupal_html_class($title)),
        );
        ++$delta;
      }
    }
  }

  if ($delta === 1) {
    // No tabs to show, the tabs wrapper must not be rendered.
    return '';
  }

  $element['tabs_title'] = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#attributes' => array(
      'class' => array('resp-tabs-list'),
    ),
  );

  $delta = 1;
  $element['tabs_content'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('resp-tabs-container'),
    ),
  );
  foreach ($panes as $pane_id => $item) {
    $element['tabs_content'][$pane_id] = array(
      '#prefix' => '<div id="' . $tab_id . '-' . $delta . '">',
      '#suffix' => '</div>',
      '#markup' => $item,
    );
    ++$delta;
  }

  return drupal_render($element);
}

/**
 * Settings form callback.
 */
function panels_responsive_tabs_style_settings_form($style_settings) {
  $defaults = array(
    'classes'                     => '',
    'type'                        => 'default',
    'width'                       => 'auto',
    'fit'                         => 1,
    'closed'                      => 0,
    'activetab_bg'                => '#B5AC5F',
    'inactive_bg'                 => '#E0D78C',
    'active_border_color'         => '#9C905C',
    'active_content_border_color' => '#9C905C',
    'tabidentify'                 => '',
  );

  // 'type': default, vertical, accordion.
  $form['type'] = array(
    '#title'         => t('Type'),
    '#description'   => t('The tab type to show in desktop devices.'),
    '#type'          => 'select',
    '#options'       => array(
      'default'   => 'Default',
      'vertical'  => 'Vertical',
      'accordion' => 'Accordion',
    ),
    '#default_value' => isset($style_settings['type']) ? $style_settings['type'] : $defaults['type'],
    '#weight'        => 1,
  );

  // 'width': auto or any custom width.
  $form['width'] = array(
    '#title'         => t('Width'),
    '#description'   => t('It can be auto or any custom width.'),
    '#type'          => 'textfield',
    '#default_value' => isset($style_settings['width']) ? $style_settings['width'] : $defaults['width'],
    '#weight'        => 1.5,
    '#element_validate' => array('_panels_responsive_tabs_validate_width'),
  );

  // 'fit': 100% fits in a container.
  $form['fit'] = array(
    '#title'         => t('Fit'),
    '#description'   => t('100% fits in a container.'),
    '#type'          => 'select',
    '#options'       => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
    '#default_value' => isset($style_settings['fit']) ? $style_settings['fit'] : $defaults['fit'],
    '#weight'        => 1.5,
  );

  // 'close': Close the panels on start, the options 'accordion' and 'tabs'
  // keep them closed in there respective view types.
  $form['closed'] = array(
    '#title'         => t('Closed'),
    '#description'   => t('Close the panels on start, the options "accordion" and "tabs" keep them closed in there respective view types.'),
    '#type'          => 'select',
    '#options'       => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
    '#default_value' => isset($style_settings['closed']) ? $style_settings['closed'] : $defaults['closed'],
    '#weight'        => 1.5,
  );

  // 'activetab_bg': background color for active tabs in this group.
  $form['activetab_bg'] = array(
    '#title'         => t('Active tab background'),
    '#description'   => t('Background color for active tab in this group.'),
    '#type'          => 'textfield',
    '#default_value' => isset($style_settings['activetab_bg']) ? $style_settings['activetab_bg'] : $defaults['activetab_bg'],
    '#weight'        => 1.5,
    '#element_validate' => array('_panels_responsive_tabs_validate_color'),
  );

  // 'inactive_bg': background color for inactive tabs in this group.
  $form['inactive_bg'] = array(
    '#title'         => t('Inactive tab background'),
    '#description'   => t('Background color for inactive tabs in this group.'),
    '#type'          => 'textfield',
    '#default_value' => isset($style_settings['inactive_bg']) ? $style_settings['inactive_bg'] : $defaults['inactive_bg'],
    '#weight'        => 1.5,
    '#element_validate' => array('_panels_responsive_tabs_validate_color'),
  );

  // 'active_border_color': border color for active tabs heads in this group.
  $form['active_border_color'] = array(
    '#title'         => t('Active tab border color'),
    '#description'   => t('Border color for active tab head in this group.'),
    '#type'          => 'textfield',
    '#default_value' => isset($style_settings['active_border_color']) ? $style_settings['active_border_color'] : $defaults['active_border_color'],
    '#weight'        => 1.5,
    '#element_validate' => array('_panels_responsive_tabs_validate_color'),
  );

  // 'active_content_border_color': border color for active tabs contect in
  // this group so that it matches the tab head border.
  $form['active_content_border_color'] = array(
    '#title'         => t('Active tab content border color'),
    '#description'   => t('bBrder color for active tabs contect in this group so that it matches the tab head border.'),
    '#type'          => 'textfield',
    '#default_value' => isset($style_settings['active_content_border_color']) ? $style_settings['active_content_border_color'] : $defaults['active_content_border_color'],
    '#weight'        => 1.5,
    '#element_validate' => array('_panels_responsive_tabs_validate_color'),
  );

  // 'tabidentify': The tab groups identifier *This should be a unique name
  // for each tab group and should not be defined in any styling or css file.
  $form['tabidentify'] = array(
    '#title'         => t('The tab groups identifier'),
    '#description'   => t('The tab groups identifier. *This should be a unique name for each tab group and should not be defined in any styling or css file.'),
    '#type'          => 'textfield',
    '#default_value' => isset($style_settings['tabidentify']) ? $style_settings['tabidentify'] : $defaults['tabidentify'],
    '#weight'        => 2,
  );

  return $form;
}
