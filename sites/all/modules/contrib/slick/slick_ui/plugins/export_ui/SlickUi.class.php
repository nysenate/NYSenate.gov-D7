<?php
/**
 * @file
 * Contains the CTools export UI integration code.
 */

/**
 * CTools Export UI class handler for Slick UI.
 */
class SlickUi extends ctools_export_ui {

  /**
   * Overrides the actual editing form.
   */
  public function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);

    ctools_form_include($form_state, 'slick.admin', 'slick');

    $module_path = drupal_get_path('module', 'slick');
    $optionset = $form_state['item'];

    $options = $optionset->options;
    $slick_options = slick_get_options();

    if (variable_get('slick_admin_css', TRUE)) {
      $form['#attached']['library'][] = array('slick_ui', 'slick.ui');
      $form['#attached']['css'][] = $module_path . '/css/admin/slick.admin--vertical-tabs.css';
    }

    // $form['#attributes']['class'][] = 'no-js';
    $form['#attributes']['class'][] = 'form--slick';
    $form['#attributes']['class'][] = 'form--compact';
    $form['#attributes']['class'][] = 'form--optionset';
    $form['#attributes']['class'][] = 'clearfix';

    $form['info']['name']['#attributes']['class'][] = 'is-tooltip';
    $form['info']['label']['#attributes']['class'][] = 'is-tooltip';
    $form['info']['label']['#prefix'] = '<div class="form--slick__header has-tooltip clearfix">';

    // Skins. We don't provide skin_thumbnail as each optionset may be deployed
    // as main display, or thumbnail navigation.
    $skins = slick_skins_options();
    $form['skin'] = array(
      '#type' => 'select',
      '#title' => t('Skin'),
      '#options' => $skins,
      '#default_value' => $optionset->skin,
      '#empty_option' => t('- None -'),
      '#description' => t('Skins allow swappable layouts like next/prev links, split image and caption, etc. Be sure to provide a dedicated slide layout per field. However a combination of skins and options may lead to unpredictable layouts, get dirty yourself. See main <a href="@skin">README</a> for details on Skins. Keep it simple for thumbnail navigation skin.', array('@skin' => url($module_path . '/README.txt'))),
      '#attributes' => array('class' => array('is-tooltip')),
    );

    $form['breakpoints'] = array(
      '#title' => t('Breakpoints'),
      '#type' => 'textfield',
      '#description' => t('The number of breakpoints added to Responsive display, max 9. This is not Breakpoint Width (480px, etc).'),
      '#default_value' => isset($form_state['values']['breakpoints']) ? $form_state['values']['breakpoints'] : $optionset->breakpoints,
      '#suffix' => '</div>',
      '#ajax' => array(
        'callback' => 'slick_ui_add_breakpoints',
        'wrapper' => 'breakpoints-ajax-wrapper',
        'event' => 'blur',
      ),
      '#attributes' => array('class' => array('is-tooltip')),
      '#maxlength' => 1,
    );

    // Options.
    $form['options'] = array(
      '#type' => 'vertical_tabs',
      '#tree' => TRUE,
    );

    // Image styles.
    $image_styles = function_exists('image_style_options') ? image_style_options(FALSE) : array();
    $form['options']['general'] = array(
      '#type' => 'fieldset',
      '#title' => t('General'),
      '#attributes' => array('class' => array('has-tooltip', 'fieldset--no-checkboxes-label')),
    );

    $form['options']['general']['normal'] = array(
      '#type' => 'select',
      '#title' => t('Image style'),
      '#description' => t('Image style for the main/background image, overriden by field formatter. Useful for custom work.'),
      '#empty_option' => t('None (original image)'),
      '#options' => $image_styles,
      '#default_value' => isset($options['general']['normal']) ? $options['general']['normal'] : '',
      '#attributes' => array('class' => array('is-tooltip')),
    );

    // More useful for custom work, overriden by sub-modules.
    $form['options']['general']['thumbnail'] = array(
      '#type' => 'select',
      '#title' => t('Thumbnail style'),
      '#description' => t('Image style for the thumbnail image if using asNavFor, overriden by field formatter. Useful for custom work.'),
      '#empty_option' => t('None (original image)'),
      '#options' => $image_styles,
      '#default_value' => isset($options['general']['thumbnail']) ? $options['general']['thumbnail'] : '',
      '#attributes' => array('class' => array('is-tooltip')),
    );

    $form['options']['general']['template_class'] = array(
      '#type' => 'textfield',
      '#title' => t('Wrapper class'),
      '#description' => t('Additional template wrapper classes separated by spaces. No need to prefix it with a dot (.).'),
      '#default_value' => isset($options['general']['template_class']) ? $options['general']['template_class'] : '',
      '#attributes' => array('class' => array('is-tooltip')),
    );

    $form['options']['general']['goodies'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Goodies'),
      '#default_value' => !empty($options['general']['goodies']) ? array_values((array) $options['general']['goodies']) : array(),
      '#options' => array(
        'arrow-down' => t('Use arrow down'),
        'pattern' => t('Use pattern overlay'),
        'random' => t('Randomize'),
      ),
      '#description' => t('Applies to main display, not thumbnail pager. <ol><li>Pattern overlay is background image with pattern placed over the main stage.</li><li>Arrow down to scroll down into a certain page section, make sure to provide target selector.</li><li>Randomize the slide display, useful to manipulate cached blocks.</li></ol>'),
      '#attributes' => array('class' => array('is-tooltip')),
    );

    $form['options']['general']['arrow_down_target'] = array(
      '#type' => 'textfield',
      '#title' => t('Arrow down target'),
      '#description' => t('Valid CSS selector to scroll to, e.g.: #main, or #content.'),
      '#default_value' => isset($options['general']['arrow_down_target']) ? $options['general']['arrow_down_target'] : '',
      '#states' => array(
        'visible' => array(
          ':input[name*=arrow-down]' => array('checked' => TRUE),
        ),
      ),
      '#attributes' => array('class' => array('is-tooltip')),
    );

    $form['options']['general']['arrow_down_offset'] = array(
      '#type' => 'textfield',
      '#title' => t('Arrow down offset'),
      '#description' => t('Offset when scrolled down from the top.'),
      '#default_value' => isset($options['general']['arrow_down_offset']) ? $options['general']['arrow_down_offset'] : '',
      '#states' => array(
        'visible' => array(
          ':input[name*=arrow-down]' => array('checked' => TRUE),
        ),
      ),
      '#attributes' => array('class' => array('is-tooltip')),
    );

    // Add empty suffix to style checkboxes like iOS.
    if (variable_get('slick_admin_css', TRUE)) {
      foreach ($form['options']['general']['goodies']['#options'] as $key => $value) {
        $form['options']['general']['goodies'][$key]['#field_suffix'] = '';
        $form['options']['general']['goodies'][$key]['#title_display'] = 'before';
      }
    }

    // Main options.
    $slick_elements = $this->getSlickElements();
    $form['options']['settings'] = array(
      '#title' => t('Settings'),
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#tree' => TRUE,
      '#attributes' => array('class' => array('fieldset--settings', 'has-tooltip')),
    );

    foreach ($slick_elements as $name => $element) {
      $default_value = isset($options['settings'][$name]) ? $options['settings'][$name] : $element['default'];
      $form['options']['settings'][$name] = array(
        '#title' => isset($element['title']) ? $element['title'] : '',
        '#description' => isset($element['description']) ? $element['description'] : '',
        '#type' => $element['type'],
        '#default_value' => $default_value,
        '#attributes' => array('class' => array('is-tooltip')),
      );

      if (isset($element['field_suffix'])) {
        $form['options']['settings'][$name]['#field_suffix'] = $element['field_suffix'];
      }

      if ($element['type'] == 'textfield') {
        $form['options']['settings'][$name]['#size'] = 20;
        $form['options']['settings'][$name]['#maxlength'] = 255;
      }

      if (variable_get('slick_admin_css', TRUE)) {
        if (!isset($element['field_suffix']) && is_bool($element['default'])) {
          $form['options']['settings'][$name]['#field_suffix'] = '';
          $form['options']['settings'][$name]['#title_display'] = 'before';
        }
      }

      if (is_int($element['default'])) {
        $form['options']['settings'][$name]['#maxlength'] = 60;
        $form['options']['settings'][$name]['#attributes']['class'][] = 'form-text--int';
      }

      if (isset($element['states'])) {
        $form['options']['settings'][$name]['#states'] = $element['states'];
      }

      if (isset($element['options'])) {
        $form['options']['settings'][$name]['#options'] = $element['options'];
      }

      if (isset($element['empty_option'])) {
        $form['options']['settings'][$name]['#empty_option'] = $element['empty_option'];
      }

      // Expand textfield for easy edit.
      if (in_array($name, array('prevArrow', 'nextArrow'))) {
        $form['options']['settings'][$name]['#attributes']['class'][] = 'js-expandable';
      }
    }

    // Responsive options.
    $form['options']['responsives'] = array(
      '#title' => t('Responsive display'),
      '#type' => 'fieldset',
      '#description' => t('Containing breakpoints and settings objects. Settings set at a given breakpoint/screen width is self-contained and does not inherit the main settings, but defaults. Be sure to set Breakpoints option above.'),
      '#collapsible' => FALSE,
      '#tree' => TRUE,
    );

    $form['options']['responsives']['responsive'] = array(
      '#title' => t('Responsive'),
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#attributes' => array('class' => array('has-tooltip', 'fieldset--responsive--ajax')),
      '#prefix' => '<div id="breakpoints-ajax-wrapper">',
      '#suffix' => '</div>',
    );

    $breakpoints_count = isset($form_state['values']['breakpoints']) ? $form_state['values']['breakpoints'] : $optionset->breakpoints;
    $form_state['breakpoints_count'] = $breakpoints_count;

    if ($form_state['breakpoints_count'] > 0) {
      $slick_responsive_elements = $this->getSlickResponsiveElements($form_state['breakpoints_count']);

      foreach ($slick_responsive_elements as $i => $responsives) {
        // Individual breakpoint fieldset.
        $fieldset_class = drupal_clean_css_identifier(drupal_strtolower($responsives['title']));
        $form['options']['responsives']['responsive'][$i] = array(
          '#title' => $responsives['title'],
          '#type' => $responsives['type'],
          '#description' => isset($responsives['description']) ? $responsives['description'] : '',
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
          '#attributes' => array(
            'class' => array(
              'fieldset--responsive',
              'fieldset--' . $fieldset_class,
              'has-tooltip',
            ),
          ),
        );

        foreach ($responsives as $key => $responsive) {
          switch ($key) {
            case 'breakpoint':
            case 'unslick':
              $form['options']['responsives']['responsive'][$i][$key] = array(
                '#title' => $responsive['title'],
                '#description' => $responsive['description'],
                '#type' => $responsive['type'],
                '#default_value' => isset($options['responsives']['responsive'][$i][$key]) ? $options['responsives']['responsive'][$i][$key] : $responsive['default'],
                '#attributes' => array('class' => array('is-tooltip')),
              );

              if ($responsive['type'] == 'textfield') {
                $form['options']['responsives']['responsive'][$i][$key]['#size'] = 20;
                $form['options']['responsives']['responsive'][$i][$key]['#maxlength'] = 255;
              }
              if (is_int($responsive['default'])) {
                $form['options']['responsives']['responsive'][$i][$key]['#maxlength'] = 60;
              }
              if (isset($responsive['states'])) {
                $form['options']['responsives']['responsive'][$i][$key]['#states'] = $responsive['states'];
              }
              if (isset($responsive['options'])) {
                $form['options']['responsives']['responsive'][$i][$key]['#options'] = $responsive['options'];
              }
              if (isset($responsive['field_suffix'])) {
                $form['options']['responsives']['responsive'][$i][$key]['#field_suffix'] = $responsive['field_suffix'];
              }

              if (variable_get('slick_admin_css', TRUE)) {
                if (!isset($responsive['field_suffix']) && $responsive['type'] == 'checkbox') {
                  $form['options']['responsives']['responsive'][$i][$key]['#field_suffix'] = '';
                  $form['options']['responsives']['responsive'][$i][$key]['#title_display'] = 'before';
                }
              }
              break;

            case 'settings':
              $form['options']['responsives']['responsive'][$i][$key] = array(
                '#title' => t('Settings'),
                '#title_display' => 'invisible',
                '#type' => 'fieldset',
                '#collapsible' => FALSE,
                '#collapsed' => FALSE,
                '#attributes' => array(
                  'class' => array(
                    'fieldset--settings',
                    'fieldset--' . $fieldset_class,
                    'has-tooltip',
                  ),
                ),
                '#states' => array('visible' => array(':input[name*="[responsive][' . $i . '][unslick]"]' => array('checked' => FALSE))),
              );
              unset($responsive['title'], $responsive['type']);

              if (!is_array($responsive)) {
                continue;
              }
              foreach ($responsive as $k => $item) {
                if ($item && !is_array($item)) {
                  continue;
                }
                $form['options']['responsives']['responsive'][$i][$key][$k] = array(
                  '#title' => isset($item['title']) ? $item['title'] : '',
                  '#description' => isset($item['description']) ? $item['description'] : '',
                  '#type' => $item['type'],
                  '#attributes' => array('class' => array('is-tooltip')),
                  '#default_value' => isset($options['responsives']['responsive'][$i][$key][$k]) ? $options['responsives']['responsive'][$i][$key][$k] : $item['default'],
                );

                // Specify proper states for the breakpoint elements.
                if (isset($item['states'])) {
                  $states = '';
                  switch ($k) {
                    case 'pauseOnHover':
                    case 'pauseOnDotsHover':
                    case 'autoplaySpeed':
                      $states = array('visible' => array(':input[name*="[' . $i . '][settings][autoplay]"]' => array('checked' => TRUE)));
                      break;

                    case 'centerPadding':
                      $states = array('visible' => array(':input[name*="[' . $i . '][settings][centerMode]"]' => array('checked' => TRUE)));
                      break;

                    case 'touchThreshold':
                      $states = array('visible' => array(':input[name*="[' . $i . '][settings][touchMove]"]' => array('checked' => TRUE)));
                      break;

                    case 'swipeToSlide':
                      $states = array('visible' => array(':input[name*="[' . $i . '][settings][swipe]"]' => array('checked' => TRUE)));
                      break;

                    case 'cssEase':
                    case 'cssEaseOverride':
                      $states = array('visible' => array(':input[name*="[' . $i . '][settings][useCSS]"]' => array('checked' => TRUE)));
                      break;

                    case 'verticalSwiping':
                      $states = array('visible' => array(':input[name*="[' . $i . '][settings][vertical]"]' => array('checked' => TRUE)));
                      break;
                  }

                  if ($states) {
                    $form['options']['responsives']['responsive'][$i][$key][$k]['#states'] = $states;
                  }
                }
                if (isset($item['options'])) {
                  $form['options']['responsives']['responsive'][$i][$key][$k]['#options'] = $item['options'];
                }
                if (isset($item['empty_option'])) {
                  $form['options']['responsives']['responsive'][$i][$key][$k]['#empty_option'] = $item['empty_option'];
                }
                if (isset($item['field_suffix'])) {
                  $form['options']['responsives']['responsive'][$i][$key][$k]['#field_suffix'] = $item['field_suffix'];
                }

                if (variable_get('slick_admin_css', TRUE)) {
                  if (!isset($item['field_suffix']) && is_bool($item['default'])) {
                    $form['options']['responsives']['responsive'][$i][$key][$k]['#field_suffix'] = '';
                    $form['options']['responsives']['responsive'][$i][$key][$k]['#title_display'] = 'before';
                  }
                }
              }
              break;

            default:
              break;
          }
        }
      }
    }

    // Allows form elements information to be altered without a class.
    // @see ctools_export_ui_edit_item_form
    drupal_alter('slick_ui_optionset_form', $form, $form_state);
  }

  /**
   * Overrides the edit form submit handler.
   *
   * At this point, submission is successful. Our only responsibility is
   * to copy anything out of values onto the item that we are able to edit.
   *
   * If the keys all match up to the schema, this method will not need to be
   * overridden.
   */
  public function edit_form_submit(&$form, &$form_state) {
    parent::edit_form_submit($form, $form_state);

    $options = $form_state['values']['options'];
    $optionset = $form_state['item'];
    // Map and update the friendly CSS easing to its bezier equivalent.
    $override = '';
    if ($form_state['values']['options']['settings']['cssEaseOverride']) {
      $override = _slick_css_easing_mapping($form_state['values']['options']['settings']['cssEaseOverride']);
    }

    $optionset->options['settings']['cssEaseBezier'] = $override;

    if (isset($options['responsives']['responsive'])) {
      foreach ($options['responsives']['responsive'] as $key => $responsive) {
        if (isset($responsive['settings']['cssEaseOverride'])) {
          $responsive_override = $responsive['settings']['cssEaseOverride'] ? _slick_css_easing_mapping($responsive['settings']['cssEaseOverride']) : '';
          $optionset->options['responsives']['responsive'][$key]['settings']['cssEaseBezier'] = $responsive_override;
        }
      }
    }

    // Typecast the values.
    _slick_typecast_optionset($optionset->options, $form_state['values']['breakpoints']);

    // Remove useless option.
    if (isset($options['options__active_tab'])) {
      unset($optionset->options['options__active_tab']);
    }
  }

  /**
   * Defines a list of form elements available for the Slick.
   *
   * @return array
   *   All available Slick form elements.
   *
   * @see http://kenwheeler.github.io/slick
   */
  public function getSlickElements() {
    $elements = &drupal_static(__METHOD__, NULL);

    if (!isset($elements)) {
      $elements = array();

      $elements['mobileFirst'] = array(
        'title' => t('Mobile first'),
        'description' => t('Responsive settings use mobile first calculation, or equivalent to min-width query.'),
        'type' => 'checkbox',
      );

      $elements['asNavFor'] = array(
        'title' => t('asNavFor target'),
        'description' => t('Leave empty if using sub-modules to have it auto-matched. Set the slider to be the navigation of other slider (Class or ID Name). Use selector identifier ("." or "#") accordingly. See HTML structure section at README.txt for more info. Overriden by field formatter, or Views style.'),
        'type' => 'textfield',
      );

      $elements['accessibility'] = array(
        'title' => t('Accessibility'),
        'description' => t('Enables tabbing and arrow key navigation.'),
        'type' => 'checkbox',
      );

      $elements['adaptiveHeight'] = array(
        'title' => t('Adaptive height'),
        'description' => t('Enables adaptive height for SINGLE slide horizontal carousels. This is useless with variableWidth.'),
        'type' => 'checkbox',
      );

      $elements['autoplay'] = array(
        'title' => t('Autoplay'),
        'description' => t('Enables autoplay.'),
        'type' => 'checkbox',
      );

      $elements['autoplaySpeed'] = array(
        'title' => t('Autoplay speed'),
        'description' => t('Autoplay speed in milliseconds.'),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][autoplay]"]' => array('checked' => TRUE))),
      );

      $elements['pauseOnHover'] = array(
        'title' => t('Pause on hover'),
        'description' => t('Pause autoplay on hover.'),
        'type' => 'checkbox',
        'states' => array('visible' => array(':input[name*="options[settings][autoplay]"]' => array('checked' => TRUE))),
      );

      $elements['pauseOnDotsHover'] = array(
        'title' => t('Pause on dots hover'),
        'description' => t('Pauses autoplay when a dot is hovered.'),
        'type' => 'checkbox',
        'states' => array('visible' => array(':input[name*="options[settings][autoplay]"]' => array('checked' => TRUE))),
      );

      $elements['arrows'] = array(
        'title' => t('Arrows'),
        'description' => t('Show prev/next arrows'),
        'type' => 'checkbox',
      );

      $elements['prevArrow'] = array(
        'title' => t('Previous arrow'),
        'description' => t("Customize the previous arrow markups. Be sure to keep the expected class: slick-prev."),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][arrows]"]' => array('checked' => TRUE))),
      );

      $elements['nextArrow'] = array(
        'title' => t('Next arrow'),
        'description' => t("Customize the next arrow markups. Be sure to keep the expected class: slick-next."),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][arrows]"]' => array('checked' => TRUE))),
      );

      $elements['centerMode'] = array(
        'title' => t('Center mode'),
        'description' => t('Enables centered view with partial prev/next slides. Use with odd numbered slidesToShow counts.'),
        'type' => 'checkbox',
      );

      $elements['centerPadding'] = array(
        'title' => t('Center padding'),
        'description' => t('Side padding when in center mode (px or %). Be aware, too large padding at small breakpoint will screw the slide calculation with slidesToShow.'),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][centerMode]"]' => array('checked' => TRUE))),
      );

      $elements['dots'] = array(
        'title' => t('Dots'),
        'description' => t('Show dot indicators.'),
        'type' => 'checkbox',
      );

      $elements['dotsClass'] = array(
        'title' => t('Dot class'),
        'description' => t('Class for slide indicator dots container. Do not prefix with dot. If you change this, edit its CSS accordingly.'),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][dots]"]' => array('checked' => TRUE))),
      );

      $elements['appendDots'] = array(
        'title' => t('Append dots'),
        'description' => t('Change where the navigation dots are attached (Selector, htmlString). If you change this, be sure to provide its relevant markup. Try <strong>.slick__arrow</strong> to achieve this style: <br />&lt; o o o o o o o &gt;<br />Be sure to enable Arrows in such a case.'),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][dots]"]' => array('checked' => TRUE))),
      );

      $elements['draggable'] = array(
        'title' => t('Draggable'),
        'description' => t('Enable mouse dragging.'),
        'type' => 'checkbox',
      );

      $elements['fade'] = array(
        'title' => t('Fade'),
        'description' => t('Enable fade. Warning! This wants slidesToShow 1. Larger than 1, and Slick may be screwed up.'),
        'type' => 'checkbox',
      );

      $elements['focusOnSelect'] = array(
        'title' => t('Focus on select'),
        'description' => t('Enable focus on selected element (click).'),
        'type' => 'checkbox',
      );

      $elements['infinite'] = array(
        'title' => t('Infinite'),
        'description' => t('Infinite loop sliding.'),
        'type' => 'checkbox',
      );

      $elements['initialSlide'] = array(
        'title' => t('Initial slide'),
        'description' => t('Slide to start on.'),
        'type' => 'textfield',
      );

      $elements['lazyLoad'] = array(
        'title' => t('Lazy load'),
        'description' => t("Set lazy loading technique. 'ondemand' will load the image as soon as you slide to it, 'progressive' loads one image after the other when the page loads. Note: dummy image is no good for ondemand. If ondemand fails to generate images, try progressive instead. Or use <a href='@url' target='_blank'>imageinfo_cache</a>. To share images for Pinterest, leave empty, otherwise no way to read actual image src.", array('@url' => '//www.drupal.org/project/imageinfo_cache')),
        'type' => 'select',
        'options' => drupal_map_assoc(array('ondemand', 'progressive')),
        'empty_option' => t('- None -'),
      );

      $elements['respondTo'] = array(
        'title' => t('Respond to'),
        'description' => t("Width that responsive object responds to. Can be 'window', 'slider' or 'min' (the smaller of the two)."),
        'type' => 'select',
        'options' => drupal_map_assoc(array('window', 'slider', 'min')),
      );

      $elements['rtl'] = array(
        'title' => t('RTL'),
        'description' => t("Change the slider's direction to become right-to-left."),
        'type' => 'checkbox',
      );

      $elements['rows'] = array(
        'title' => t('Rows'),
        'description' => t("Setting this to more than 1 initializes grid mode. Use slidesPerRow to set how many slides should be in each row."),
        'type' => 'textfield',
      );

      $elements['slidesPerRow'] = array(
        'title' => t('Slides per row'),
        'description' => t("With grid mode intialized via the rows option, this sets how many slides are in each grid row."),
        'type' => 'textfield',
      );

      $elements['slide'] = array(
        'title' => t('Slide element'),
        'description' => t("Element query to use as slide. Slick will use any direct children as slides, without having to specify which tag or selector to target."),
        'type' => 'textfield',
      );

      $elements['slidesToShow'] = array(
        'title' => t('Slides to show'),
        'description' => t('Number of slides to show at a time. If 1, it will behave like slideshow, more than 1 a carousel. Provide more if it is a thumbnail navigation with asNavFor. Only works with odd number slidesToShow counts when using centerMode (e.g.: 3, 5, 7, etc.). Not-compatible with variableWidth.'),
        'type' => 'textfield',
      );

      $elements['slidesToScroll'] = array(
        'title' => t('Slides to scroll'),
        'description' => t('Number of slides to scroll at a time, or steps at each scroll.'),
        'type' => 'textfield',
      );

      $elements['speed'] = array(
        'title' => t('Speed'),
        'description' => t('Slide/Fade animation speed in milliseconds.'),
        'type' => 'textfield',
        'field_suffix' => 'ms',
      );

      $elements['swipe'] = array(
        'title' => t('Swipe'),
        'description' => t('Enable swiping.'),
        'type' => 'checkbox',
      );

      $elements['swipeToSlide'] = array(
        'title' => t('Swipe to slide'),
        'description' => t('Allow users to drag or swipe directly to a slide irrespective of slidesToScroll.'),
        'type' => 'checkbox',
        'states' => array('visible' => array(':input[name*="options[settings][swipe]"]' => array('checked' => TRUE))),
      );

      $elements['edgeFriction'] = array(
        'title' => t('Edge friction'),
        'description' => t("Resistance when swiping edges of non-infinite carousels. If you don't want resistance, set it to 1."),
        'type' => 'textfield',
      );

      $elements['touchMove'] = array(
        'title' => t('Touch move'),
        'description' => t('Enable slide motion with touch.'),
        'type' => 'checkbox',
      );

      $elements['touchThreshold'] = array(
        'title' => t('Touch threshold'),
        'description' => t('Swipe distance threshold.'),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][touchMove]"]' => array('checked' => TRUE))),
      );

      $elements['useCSS'] = array(
        'title' => t('Use CSS'),
        'description' => t('Enable/disable CSS transitions.'),
        'type' => 'checkbox',
      );

      $elements['cssEase'] = array(
        'title' => t('CSS ease'),
        'description' => t('CSS3 animation easing. <a href="@ceaser">Learn</a> <a href="@bezier">more</a>. Ignored if <strong>CSS ease override</strong> is provided.', array('@ceaser' => '//matthewlein.com/ceaser/', '@bezier' => '//cubic-bezier.com')),
        'type' => 'textfield',
        'states' => array('visible' => array(':input[name*="options[settings][useCSS]"]' => array('checked' => TRUE))),
      );

      $elements['cssEaseBezier'] = array(
        'type' => 'hidden',
      );

      $elements['cssEaseOverride'] = array(
        'title' => t('CSS ease override'),
        'description' => t('If provided, this will override the CSS ease with the pre-defined CSS easings based on <a href="@ceaser">CSS Easing Animation Tool</a>. Leave it empty to use your own CSS ease.', array('@ceaser' => '//matthewlein.com/ceaser/')),
        'type' => 'select',
        'options' => _slick_css_easing_options(),
        'empty_option' => t('- None -'),
        'states' => array('visible' => array(':input[name*="options[settings][useCSS]"]' => array('checked' => TRUE))),
      );

      $elements['useTransform'] = array(
        'title' => t('Use transform'),
        'description' => t('Enable/disable CSS transforms.'),
        'type' => 'checkbox',
      );

      $elements['easing'] = array(
        'title' => t('jQuery easing'),
        'description' => t('Add easing for jQuery animate as fallback. Use with <a href="@easing">easing</a> libraries or default easing methods. This will be ignored and replaced by CSS ease for supporting browsers, or effective if useCSS is disabled.', array('@easing' => '//gsgd.co.uk/sandbox/jquery/easing/')),
        'type' => 'select',
        'options' => _slick_easing_options(),
        'empty_option' => t('- None -'),
      );

      $elements['variableWidth'] = array(
        'title' => t('variableWidth'),
        'description' => t('Disables automatic slide width calculation. Best with uniform image heights, use scale height image effect. Useless with adaptiveHeight, and non-uniform image heights. Useless with slidesToShow > 1 if the container is smaller than the amount of visible slides. Troubled with lazyLoad ondemand.'),
        'type' => 'checkbox',
      );

      $elements['vertical'] = array(
        'title' => t('Vertical'),
        'description' => t('Vertical slide direction. See <a href="@url" target="_blank">relevant issue</a>.', array('@url' => '//github.com/kenwheeler/slick/issues/1001')),
        'type' => 'checkbox',
      );

      $elements['verticalSwiping'] = array(
        'title' => t('Vertical swiping'),
        'description' => t('Changes swipe direction to vertical.'),
        'type' => 'checkbox',
        'states' => array('visible' => array(':input[name*="options[settings][vertical]"]' => array('checked' => TRUE))),
      );

      $elements['waitForAnimate'] = array(
        'title' => t('waitForAnimate'),
        'description' => t('Ignores requests to advance the slide while animating.'),
        'type' => 'checkbox',
      );

      // Clone the default values.
      $slick_options = slick_get_options();
      foreach ($slick_options as $name => $value) {
        if (isset($elements[$name])) {
          $elements[$name]['default'] = $value;
        }
      }

      // Allows form elements information to be altered.
      drupal_alter('slick_ui_elements_info', $elements);
    }
    return $elements;
  }

  /**
   * Defines available options for the responsive Slick.
   *
   * @param int $count
   *   The number of breakpoints.
   *
   * @return array
   *   An array of Slick responsive options.
   */
  public function getSlickResponsiveElements($count = 0) {
    $elements = array();

    $breakpoints = drupal_map_assoc(range(0, ($count - 1)));
    $slick_elements = slick_clean_options($this->getSlickElements());

    foreach ($breakpoints as $key => $breakpoint) {
      $elements[$key] = array(
        'title' => t('Breakpoint #@key', array('@key' => ($key + 1))),
        'type' => 'fieldset',
      );

      $elements[$key]['breakpoint'] = array(
        'title' => t('Breakpoint'),
        'description' => t('Breakpoint width in pixel. If mobileFirst enabled, equivalent to min-width, otherwise max-width.'),
        'type' => 'textfield',
        'field_suffix' => 'px',
        'default' => FALSE,
      );

      $elements[$key]['unslick'] = array(
        'title' => t('Unslick'),
        'description' => t("Disable Slick at a given breakpoint. Note, you can't window shrink this, once you unslick, you are unslicked."),
        'type' => 'checkbox',
        'default' => '',
      );

      $elements[$key]['settings'] = array();

      // Duplicate relevant main settings.
      foreach ($slick_elements as $name => $element) {
        $elements[$key]['settings'][$name] = $element;
      }

      // Allows form responsive elements information to be altered.
      drupal_alter('slick_ui_responsive_elements_info', $elements);
    }
    return $elements;
  }

  /**
   * Overrides parent::list_build_row.
   */
  public function list_build_row($item, &$form_state, $operations) {
    parent::list_build_row($item, $form_state, $operations);

    $name = $item->{$this->plugin['export']['key']};
    $skins = slick_skins();
    $breakpoints = $this->items[$name]->breakpoints ? $this->items[$name]->breakpoints : 0;
    $skin = $this->items[$name]->skin;
    $skin_name = $skin ? check_plain($skin) : t('None');

    if ($skin) {
      $description = isset($skins[$skin]['description']) && $skins[$skin]['description'] ? filter_xss_admin($skins[$skin]['description']) : '';
      if ($description) {
        $skin_name .= '<br /><em>' . $description . '</em>';
      }
    }

    $breakpoints_row[] = array(
      'data' => $breakpoints,
      'class' => array('ctools-export-ui-breakpoints'),
    );
    array_splice($this->rows[$name]['data'], 2, 0, $breakpoints_row);

    $skin_row[] = array(
      'data' => $skin_name,
      'class' => array('ctools-export-ui-skin'),
      'style' => "white-space: normal; word-wrap: break-word; max-width: 320px;",
    );
    array_splice($this->rows[$name]['data'], 3, 0, $skin_row);
  }

  /**
   * Overrides parent::list_table_header.
   */
  public function list_table_header() {
    $headers = parent::list_table_header();

    $breakpoints_header[] = array('data' => t('Breakpoint'), 'class' => array('ctools-export-ui-breakpoints'));
    array_splice($headers, 2, 0, $breakpoints_header);

    $skin_header[] = array('data' => t('Skin'), 'class' => array('ctools-export-ui-skin'));
    array_splice($headers, 3, 0, $skin_header);

    return $headers;
  }

}

/**
 * Callback for ajax-enabled breakpoints textfield, no method allowed for D7.
 *
 * Selects and returns the responsive options.
 */
function slick_ui_add_breakpoints($form, $form_state) {
  if ($form_state['values']['breakpoints'] && $form_state['values']['breakpoints'] >= 8) {
    drupal_set_message(t('You are trying to load too many Breakpoints. Try reducing it to reasonable numbers say, between 1 to 5.'));
  }
  return $form['options']['responsives']['responsive'];
}
