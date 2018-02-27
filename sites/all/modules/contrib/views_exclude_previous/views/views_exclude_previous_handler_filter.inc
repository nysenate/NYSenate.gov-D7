<?php
/**
 * @file
 *  Class definition of views_exclude_previous_handler_filter.
 */
class views_exclude_previous_handler_filter extends views_handler_filter_in_operator {

  function get_value_options() {
    // @todo: Make this pluggable.
    $this->value_options = array(
      'node_load' => 'Exclude nodes previously loaded (hook_node_load).',
      'node_view' => 'Exclude nodes previously viewd (hook_node_view).',
      'views' => 'Exclude nodes that where loaded in any node based view.',
    );
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['operator']['default'] = 'not in';
    $options['value']['default'] = array();

    return $options;
  }

  /**
   * Provide inclusive/exclusive matching
   */
  function operator_options($which = 'title') {
    return array(
      'not in' => t('Is not in'),
    );
  }

  function query() {
    $alias = $this->query->ensure_table('node');
    if (!$alias) {
      return;
    }
    if (!$this->value) {
      return;
    }
    $excludes = array();
    foreach ($this->value AS $category) {
      $excludes += _views_exclude_previous($category);
    }

    if (!empty($excludes)) {
      $this->query->add_where($this->options['group'], $alias . '.nid', $excludes, 'NOT IN');
    }
  }

}
