<?php

/**
 * @file
 * This field handler aggregates entityform operation links with a single field.
 */
class entityform_handler_entityform_operations_field extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['entityform_id'] = 'entityform_id';
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $links = menu_contextual_links('entityform', 'entityform', array($this->get_value($values, 'entityform_id')));

    if (!empty($links)) {
      return theme('links', array(
        'links' => $links,
        'attributes' => array(
          'class' => array('links', 'inline', 'operations'),
        ),
      ));
    }
    return FALSE;
  }

}
