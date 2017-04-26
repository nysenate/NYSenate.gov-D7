<?php

/**
 * @file
 * Contains \views_handler_field_pm_subject.
 */

/**
 * Defines a field handler that renders private message subject.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_pm_subject extends views_handler_field_markup {

  /**
   * Constructor; calls to base object constructor.
   */
  function construct() {
    parent::construct();
    // Add fields to run token replacement when needed.
    $this->additional_fields['has_tokens'] = 'has_tokens';
    $this->additional_fields['mid'] = 'mid';
  }

  /**
   * {@inheritdoc}
   */
  function render($values) {
    $value = $this->get_value($values);
    if ($value) {
      $value = check_plain($value);
      if ($this->get_value($values, 'has_tokens') && ($mid = $this->get_value($values, 'mid'))) {
        // Apply internal token replacement.
        if ($privatemsg = privatemsg_message_load($mid)) {
          $value = privatemsg_token_replace($value, array('privatemsg_message' => $privatemsg), array('privatemsg-show-span' => FALSE));
        }
      }
      return $value;
    }
  }

}
