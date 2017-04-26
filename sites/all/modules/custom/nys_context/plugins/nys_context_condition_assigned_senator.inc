<?php

/**
 * @file
 * Implement context condition class for entity field value.
 */

/**
 * Expose entity field as a context condition.
 */
class nys_context_condition_assigned_senator extends context_condition {
  /**
   * Omit condition values. We will provide a custom input form for our conditions.
   */
  public function condition_values() {
    return array();
  }

  /**
   * Condition form.
   */
  public function condition_form($context) {
    $form = array();
    $defaults = $this->fetch_from_context($context, 'values');

    $entity_types = array();
    foreach (node_type_get_types() as $node_type_name => $node_type) {
      $node_types[$node_type_name] = $node_type->name;
    }

    $form['intro'] = array(
      '#markup' => '<p>' . t('This context will evaluate to true if page is a node page of one of the selected content types and "field_senator" is not empty') . '</p>',
    );

    $form['node_type'] = array(
      '#title' => t('Node type'),
      '#type' => 'checkboxes',
      '#options' => $node_types,
      '#description' => t('Select node type to check'),
      '#default_value' => isset($defaults['node_type']) ? unserialize($defaults['node_type']) : array(),
    );

    $form['note'] = array(
      '#markup' => '<p>' . t('NOTE: This context will also evaluate to true if page is a "district" taxonomy term page and "field_senator" is not empty') . '</p>',
    );

    return $form;
  }

  /**
   * Condition form submit handler.
   */
  public function condition_form_submit($values) {
    return array(
      'node_type' => serialize($values['node_type']),
    );
  }

  /**
   * Execute.
   */
  public function execute($entity_type, $entity) {
    if ($this->condition_used()) {
      foreach ($this->get_contexts() as $context) {
        $settings = $this->fetch_from_context($context, 'values');
        if (arg(0) == 'node' && isset($entity->type) && in_array($entity->type, array_filter(unserialize($settings['node_type'])))) {
          if (!empty($entity->field_senator[LANGUAGE_NONE][0]['target_id']) && empty($entity->field_committee[LANGUAGE_NONE][0]['tid'])) {
            $this->condition_met($context);
          }
        }
        elseif (arg(0) == 'taxonomy' && arg(1) == 'term' && $entity_type = 'taxonomy_term' && $entity->vid == 8) {
          if (!empty($entity->field_senator[LANGUAGE_NONE][0]['target_id'])) {
            $this->condition_met($context);
          }
        }

      }
    }
  }

}