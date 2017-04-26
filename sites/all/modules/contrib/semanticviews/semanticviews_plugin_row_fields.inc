<?php
/**
 * @file
 * Contains the semantic row style plugin.
 */

/**
 * The semantic 'fields' row plugin
 *
 * This displays fields one after another, giving options for HTML element and
 * class.
 *
 * @ingroup views_row_plugins
 */
class semanticviews_plugin_row_fields extends views_plugin_row {
  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['skip_blank'] = array('default' => FALSE);
    // Field element_type and classes cannot be defined in the options
    // definition because the field handlers are not attached when the option
    // defaults are set up in the object's init() method.
    $options['semantic_html'] = array('default' => array());
    return $options;
  }

  /**
   * Provide a form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['semantic_html'] = array(
      '#tree' => TRUE,
    );
    $form['semantic_html']['help'] = array(
      '#markup' => t('These settings will override each Fields "Style Settings".')
    );
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if (!$handler->options['exclude']) {
        $default_value = (isset($this->options['semantic_html'][$field]) && is_array($this->options['semantic_html'][$field])) ? $this->options['semantic_html'][$field] : array(
          'element_type' => 'div',
          'class' => '',
          'label_element_type' => 'label',
          'label_class' => ''
        );
        $form['semantic_html'][$field] = array(
          '#title' => $handler->label() ? $handler->label() : $handler->ui_name(),
          '#type' => 'fieldset',
          '#attributes' => array(
            'class' => array('clearfix'),
          ),
        );
        $form['semantic_html'][$field]['element_type'] = array(
          '#prefix' => '<div class="views-left-30">',
          '#suffix' => '</div>',
          '#title' => 'Element',
          '#type' => 'textfield',
          '#size' => '10',
          '#default_value' => $default_value['element_type'],
        );
        $form['semantic_html'][$field]['class'] = array(
          '#prefix' => '<div class="views-right-70">',
          '#suffix' => '</div>',
          '#title' => 'Class attribute',
          '#type' => 'textfield',
          '#size' => '30',
          '#default_value' => $default_value['class'],
        );
        if ($handler->label()) {
          $form['semantic_html'][$field]['label_element_type'] = array(
            '#prefix' => '<div class="views-left-30">',
            '#suffix' => '</div>',
            '#title' => 'Label element',
            '#type' => 'textfield',
            '#size' => '10',
            '#default_value' => $default_value['label_element_type'],
          );
          $form['semantic_html'][$field]['label_class'] = array(
            '#prefix' => '<div class="views-right-70">',
            '#suffix' => '</div>',
            '#title' => 'Label class attribute',
            '#type' => 'textfield',
            '#size' => '30',
            '#default_value' => $default_value['label_class'],
          );
        }
      }
    }
    $form['skip_blank'] = array(
      '#type' => 'checkbox',
      '#default_value' => $this->options['skip_blank'],
      '#title' => t('Skip empty fields'),
      '#description' => t('Do not output anything when a field has no content. This has the same outcome as enabling the <em>Hide if empty</em> option for every field in this display.'),
    );
  }

  /**
   * Validate the options form.
   */
  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    // TODO: validate that the elements and classes are valid HTML. This is not
    // a substitute for output filtering.
  }

  /**
   * Validate the view.
   */
  function validate() {
    $errors = parent::validate();

    $display_handler = $this->display->handler;

    if (!$display_handler->is_defaulted('fields') && $display_handler->is_defaulted('row_plugin')) {
      $errors[] = t('Display "@display" overrides fields and must also override the row style plugin.', array('@display' => $this->display->display_title));
    }

    return $errors;
  }
}
