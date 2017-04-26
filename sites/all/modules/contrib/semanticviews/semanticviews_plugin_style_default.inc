<?php
/**
 * @file
 * Contains the default style plugin.
 */

/**
 * Default style plugin to render rows one after another with no decorations.
 *
 * @ingroup views_style_plugins
 */
class semanticviews_plugin_style_default extends views_plugin_style {
  /**
   * Set default options
   */
  function options(&$options) {
    parent::options($options);
  }

  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    // Group option definition.
    $options['group'] = array(
      'contains' => array(
        'element_type' => array('default' => 'h3'),
        'class' => array('default' => 'title'),
      ),
    );

    // List option definition.
    $options['list'] = array(
      'contains' => array(
        'element_type' => array('default' => ''),
        'class' => array('default' => ''),
      ),
    );

    // Row option definition.
    $options['row'] = array(
      'contains' => array(
        'element_type' => array('default' => 'div'),
        'class' => array('default' => ''),
        'first_class' => array('default' => 'first'),
        'last_class' => array('default' => 'last'),
        'last_every_nth' => array('default' => '0'),
        'striping_classes' => array('default' => 'odd even'),
      ),
    );

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Group options.
    $form['group'] = array(
      '#type' => 'fieldset',
      '#title' => t('Grouping title'),
      '#description' => t('If using groups, the view will insert the grouping&rsquo;s title field.'),
      '#attributes' => array(
        'class' => array('clearfix'),
      ),
    );
    $form['group']['element_type'] = array(
      '#prefix' => '<div class="views-left-30">',
      '#suffix' => '</div>',
      '#title' => t('Element'),
      '#type' => 'textfield',
      '#size' => '10',
      '#default_value' => $this->options['group']['element_type'],
    );
    $form['group']['class'] = array(
      '#prefix' => '<div class="views-right-70">',
      '#suffix' => '</div>',
      '#title' => t('Class attribute'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['group']['class'],
    );

    // List options.
    $form['list'] = array(
      '#type' => 'fieldset',
      '#title' => t('List'),
      '#description' => t('If the output should be a HTML list, select the element and class attribute. The row element should also be set to %li.', array('%li' => 'li')),
      '#attributes' => array(
        'class' => array('clearfix'),
      ),
    );
    $form['list']['element_type'] = array(
      '#prefix' => '<div class="views-left-30">',
      '#suffix' => '</div>',
      '#type' => 'radios',
      '#title' => t('List type'),
      '#options' => array(
        '' => t('None'),
        'ul' => t('Unordered list'),
        'ol' => t('Ordered list'),
        'dl' => t('Definition list'),
      ),
      '#default_value' => $this->options['list']['element_type'],
    );
    $form['list']['class'] = array(
      '#prefix' => '<div class="views-right-70">',
      '#suffix' => '</div>',
      '#title' => t('Class attribute'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['list']['class'],
    );

    // Row options.
    $form['row'] = array(
      '#type' => 'fieldset',
      '#title' => t('Row'),
      '#attributes' => array(
        'class' => array('clearfix'),
      ),
    );
    $form['row']['element_type'] = array(
      '#prefix' => '<div class="clearfix"><div class="views-left-30">',
      '#suffix' => '</div>',
      '#title' => t('Element'),
      '#type' => 'textfield',
      '#size' => '10',
      '#default_value' => $this->options['row']['element_type'],
    );
    $form['row']['class'] = array(
      '#prefix' => '<div class="views-right-70">',
      '#suffix' => '</div></div>',
      '#title' => t('Class attribute'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['row']['class'],
      '#description' => t('Insert a %hash where you want row enumeration.', array('%hash' => '#')),
    );

    // First and last class options.
    $form['row']['first_last'] = array(
      '#type' => 'fieldset',
      '#title' => t('First and last classes'),
      // The #parents attribute must be set to avoid another array layer around
      // the group of FIRST/LAST class attribute options.
      '#parents' => array('style_options', 'row'),
      '#description' => t('If the %last_every_nth option is empty or zero, the %first_class and %last_class are added once to only the first and last rows in the pager set. If this option is greater than 1, these classes are added to every n<sup>th</sup> row, which may be useful for grid layouts where the initial and final unit&rsquo;s lateral margins must be 0.', array(
          '%last_every_nth' => 'FIRST/LAST every nth',
          '%first_class' => 'FIRST class attribute',
          '%last_class' => 'LAST class attribute',
        )
      ),
      '#attributes' => array(
        'class' => array('clearfix'),
      ),
    );
    $form['row']['first_last']['last_every_nth'] = array(
      '#type' => 'textfield',
      '#size' => '10',
      '#title' => t('FIRST/LAST every n<sup>th</sup>'),
      '#default_value' => $this->options['row']['last_every_nth'],
    );
    $form['row']['first_last']['first_class'] = array(
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
      '#title' => t('FIRST class attribute'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['row']['first_class'],
    );
    $form['row']['first_last']['last_class'] = array(
      '#prefix' => '<div class="views-right-50">',
      '#suffix' => '</div>',
      '#title' => t('LAST class attribute'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['row']['last_class'],
    );

    // Striping class options.
    $form['row']['striping_classes'] = array(
      '#title' => t('Striping class attributes'),
      '#type' => 'textfield',
      '#size' => '30',
      '#default_value' => $this->options['row']['striping_classes'],
      '#description' => t('One striping class attribute is applied to each row. Separate multiple attributes with a space.'),
    );

    // Get a list of the available fields for token replacement.
    $options = array();
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      $options[t('Fields')]["[$field]"] = $handler->ui_name();
    }

    // Default text.
    $output = t('<p>Add additional fields to this display in order to get any available replacement patterns.</p>');
    // We have some options, so make a list.
    if (!empty($options)) {
      $output = t('<p>The following replacement patterns are available for this display. Use the pattern shown on the left to display the value indicated on the right.</p>');
      foreach (array_keys($options) as $type) {
        if (!empty($options[$type])) {
          $items = array();
          foreach ($options[$type] as $key => $value) {
            $items[] = $key . ' == ' . $value;
          }
          $output .= theme('item_list', $items, $type);
        }
      }
    }

    $form['row']['alter'] = array(
      '#type' => 'markup',
      '#value' => '<fieldset id="views-tokens-help"><legend>' . t('Replacement patterns') . '</legend>' . $output . '</fieldset>',
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
   * Return the token replaced class for the specified row.
   */
  function tokenize_class($row_index, $class) {
    // Replaces the # to the row enumeration.
    $class = strtr($class, array('#' => $row_index));

    if ($this->uses_fields() && $this->view->field) {
      $class = strip_tags($this->tokenize_value($class, $row_index));
    }

    $classes = explode(' ', $class);
    foreach ($classes as &$class) {
      $class = drupal_clean_css_identifier($class);
    }

    return implode(' ', $classes);
  }
}
