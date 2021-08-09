<?php

/**
 * Allowed values sort handler.
 */
class views_list_sort_handler_sort_allowed_values extends views_handler_sort {

  /**
   * Options definition.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['allowed_values'] = array('default' => 0);
    return $options;
  }

  /**
   * Options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['allowed_values'] = array(
      '#type' => 'radios',
      '#title' => t('Sort by allowed values'),
      '#options' => array(t('No'), t('Yes')),
      '#default_value' => $this->options['allowed_values'],
    );
  }

  /**
   * Affect the query.
   */
  function query() {
    // Skip if disabled.
    if (!$this->options['allowed_values']) {
      return;
    }

    // Get database connection.
    $target = !empty($this->query->options) ? 'slave' : 'default';
    $key = isset($this->view->base_database) ? $this->view->base_database : 'default';
    $connection = Database::getConnection($target, $key);

    // Build sanitized list of keys from field's allowed values.
    $keys = array();
    $allowed_values = list_allowed_values(field_info_field($this->definition['field_name']));
    foreach ($allowed_values as $key => $value) {
      $keys[] = $connection->quote($key);
    }

    // Add order by expression.
    $this->ensure_my_table();
    $expression = "FIELD($this->table_alias.$this->real_field, " . join(', ', $keys) . ")";
    $this->query->add_orderby(NULL, NULL, $this->options['order'], $expression);
  }

}
