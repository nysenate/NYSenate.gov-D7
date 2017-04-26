<?php

/**
 * @file
 * Contains \views_handler_field_pm_thread_link.
 */

/**
 * Provides a field handler that renders a link to the private message thread.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_pm_thread_link extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['link_text'] = array('default' => t('View thread'), 'translatable' => TRUE);
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#description' => t('The text to show in the link'),
      '#default_value' => $this->options['link_text'],
    );
  }

  /**
   * {@inheritdoc}
   */
  function access() {
    return privatemsg_user_access();
  }


  /**
   * {@inheritdoc}
   */
  function render($values) {
    $value = $this->get_value($values);
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = 'messages/view/' . $value;
    return $this->sanitize_value($this->options['link_text']);
  }

}
