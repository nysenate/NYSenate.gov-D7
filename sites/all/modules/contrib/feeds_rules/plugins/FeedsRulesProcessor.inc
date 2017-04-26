<?php

/**
 * @file
 * Defines the Feeds Rules processor plugin.
 */

/**
 * Feeds processor plugin to process a rules component for each feed items.
 */
class FeedsRulesProcessor extends FeedsProcessor {

  /**
   * {@inheritdoc}
   */
  public function entityType() {
    return 'feeds_rules_action'; // 'feeds_rules_action_instance';
  }

  /**
   * {@inheritdoc}
   *
   * Pseudo entityInfo(), as we do not provide any entity.
   */
  protected function entityInfo() {
    return parent::entityInfo();
  }

  /**
   * {@inheritdoc}
   *
   * Creates a new pseudo entity in memory and returns it.
   * It holds only the component key, and an empty params array, that will be
   * filled during mapping.
   */
  protected function newEntity(FeedsSource $source) {
    $entity = new stdClass();
    $entity->component = $this->config['component'];
    $entity->params = array();
    return $entity;
  }

  /**
   * Load the log entity from database.
   */
  protected function entityLoad(FeedsSource $source, $entity_id) {
    return entity_load_single('feeds_rules_action', $entity_id);
  }

  /**
   * {@inheritdoc}
   *
   * Pseudo save method for executing the rule set execution.
   */
  protected function entitySave($entity) {

    // Invoke the action component, only if the action hasn't been executed
    // before.
    // (we do not use rules_invoke_component() because of its weird argument
    // passing).
    if (empty($entity->executed) && $component = rules_get_cache('comp_' . $entity->component)) {
      $return = $component->executeByArgs($entity->params);
      $entity->executed = time();
    }
    // Handle provided data, as it is provided as sole value array, we need to
    // rebuild the named keys.
    if (isset($return)) {
      $provides = $component->providesVariables();
      $entity->provided = array_combine(array_keys($provides), $return);
    }
    else {
      $entity->provided = array();
    }

    // And save it.
    return entity_save('feeds_rules_action', $entity);
  }

  /**
   * {@inheritdoc}
   *
   * Deletes the log entities.
   * Also initiates the revert component method, if it is configured.
   */
  protected function entityDeleteMultiple($entity_ids) {
    // Revert components if configuration is set.
    if (!empty($this->config['reverse-component']['component'])) {
      foreach ($entity_ids as $entity_id) {
        $this->revertComponent($entity_id);
      }
    }
    // Delete the entities.
    return entity_delete_multiple('feeds_rules_action', $entity_ids);
  }

  /**
   * Callback to revert a single rules component call represented by the feeds
   * rules action entity.
   *
   * @param integer $entity_id
   */
  protected function revertComponent($entity_id) {
    $reverse_action = rules_get_cache('comp_'. $this->config['reverse-component']['component']);
    if ($reverse_action) {
      $entity = entity_load_single('feeds_rules_action', $entity_id);

      $args = array();
      // Build the argument array if mapping is set.
      if (!empty($this->config['reverse-component']['mapping'])) {
        foreach ($this->config['reverse-component']['mapping'] as $target => $source) {
          list($type, $source_key) = explode('::', $source, 2);
          $args[$target] = isset($entity->{$type}[$source_key]) ? $entity->{$type}[$source_key] : '';
        }
      }
      $reverse_action->executeByArgs($args);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function configDefaults() {
    return array(
      'mappings' => array(),
      'component' => '',
      'source-mapping' => '',
      'reverse-component' => array(
        'component' => '',
        'mapping' => array(),
      ),
    );
  }

  /**
   * {@inheritdoc}
   *
   * As we do not process any entities directly, we only provide configuration
   * on what rule set/action shall be used.
   */
  public function configForm(&$form_state) {

    $components = rules_get_components(TRUE, 'action');
    $form['component'] = array(
      '#type' => 'select',
      '#title' => t('Import rules component'),
      '#required' => TRUE,
      '#description' => t('Select a rules action or rule set to be used to process each item of the source. Each parameter of that component can be set in this processor\'s mapping.'),
      '#options' => $components,
      '#default_value' => $this->config['component'],
    );

    // Feeds source mapping.
    $form['source-mapping'] = array(
      '#type' => 'select',
      '#title' => t('Source mapping'),
      '#required' => FALSE,
      '#description' => t('Besides mapping the parsed items to the rules params, you can pass the feeds source object to the rules component.'),
      '#empty_value' => '',
      '#options' => feeds_rules_get_rules_component_params($this->config['component'], array('params'), array('feeds_source')),
      '#default_value' => $this->config['source-mapping'],
    );

    /**
     * Configure the reverse component.
     */
    $form['reverse-component'] = array(
      '#type' => 'fieldset',
      '#title' => t('Reverse component'),
      '#description' => t('This component/action will be called when an imported item is about to be reverted. This way you can make sure to update or deleted data that was related to the imported item.'),
      '#tree' => TRUE,
    );
    $form['reverse-component']['component'] = array(
      '#type' => 'select',
      '#title' => t('Action'),
      '#required' => FALSE,
      '#empty' => TRUE,
      '#description' => t('Select a defined action or rule set'),
      '#empty_value' => '',
      '#options' => $components,
      '#default_value' => $this->config['reverse-component']['component'],
    );

    // If a component is selected show the mapping array.
    if (!empty($this->config['reverse-component']['component'])) {
      $reverse_action = rules_get_cache('comp_'. $this->config['reverse-component']['component']);

      // Stop if component can not be loaded (e.g. component was removed)
      if (!$reverse_action)
        return $form;

      $reverse_parameter_info = $reverse_action->parameterInfo();

      $form['reverse-component']['mapping'] = array(
        '#type' => 'fieldset',
        '#title' => t('Mapping'),
      );

      // No params, no mapping needed.
      if (empty($reverse_parameter_info)) {
        $form['reverse-component']['mapping']['#description'] = t('This component has no parameters to configure.');
      }
      else {
        // Provide parameters and provided variables, as values for the target
        // "reverse" component.
        $sources = feeds_rules_get_rules_component_params($this->config['component']);

        // Provide the mapping form elements.
        $mapping = (isset($this->config['reverse-component']['mapping'])) ? $this->config['reverse-component']['mapping'] : array();
        foreach ($reverse_parameter_info as $key => $info) {
          $form['reverse-component']['mapping'][$key] = array(
            '#type' => 'select',
            '#title' => $info['label'],
            '#description' => t('Rules data of type "@type".', array('@type' => $info['type'])),
            '#options' => $sources,
            '#default_value' => (isset($mapping[$key])) ? $mapping[$key] : '',
          );
        }
        $form['reverse-component']['mapping']['#description'] = t('Select the mapping for the reverse component. If your import component provided any data, you can reuse that in the mapping too.');
      }
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function getMappingTargets() {

    $action = rules_get_cache('comp_'. $this->config['component']);
    $parameter_info = $action->parameterInfo();
    $targets = array();
    foreach ($parameter_info as $key => $info) {
      $targets[$key] = array(
        'name' => $info['label'],
        'description' => t('Rules data of type @type.', array('@type' => $info['type'])),
      );
    }

    // @TODO: Let other modules expose mapping targets, after we defined a pseudo
    // entity that represents execution of a rule execution.
    //self::loadMappers();
    //feeds_alter('feeds_processor_targets', $targets, 'rules_action', $this->config['content_type']);

    return $targets;
  }

  /**
   * {@inheritdoc}
   *
   * Override setTargetElement to operate on a target item that is the parameter
   * array for the selected component.
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value) {
    switch ($target_element) {
      default:
        $target_item->params[$target_element] = $value;
        break;
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function map(FeedsSource $source, FeedsParserResult $result, $target_item = NULL) {
    $target_item = parent::map($source, $result, $target_item);

    // In addition to the mappings, we may add the source to the params.
    if (!empty($this->config['source-mapping'])) {
      list( , $key) = explode('::', $this->config['source-mapping'], 2);

      $target_item->params[$key] = $source;
    }

    return $target_item;
  }

}
