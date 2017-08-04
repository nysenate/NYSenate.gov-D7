<?php
/**
 * @file
 * Class definition of FeedsFieldCollectionProcessor.
 */

/**
 * Creates field collection from feed items.
 */
class FeedsFieldCollectionProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'field_collection_item';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info += array('label plural' => $info['label']);
    return $info;
  }

  /**
   * Creates a new field collection item in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $field_collection_item = new FieldCollectionItemEntity(array('field_name' => $this->config['field_name']), $this->config['host_entity_type']);
    $field_collection_item->is_new = TRUE;
    return $field_collection_item;
  }

  /**
   * Loads an existing entity.
   *
   */
  protected function entityLoad(FeedsSource $source, $id) {
    return entity_load_single($this->entityType(), $id);
  }

  /**
   * Save a entity.
   */
  public function entitySave($entity) {
    if(method_exists($entity, 'hostEntityId')) {
      $entityid = $entity->hostEntityId();
    }
    else {
      $entityid = $entity->hostEntityId;
    }
    if (!empty($entityid)) {
      $entity->save();
    }
  }

  /**
   * Delete a series of entities.
   */
  protected function entityDeleteMultiple($ids) {
    //Why not delete multiple?
    $entities = field_collection_item_load_multiple($ids);
    foreach ($entities as $entity) {
      $entity->delete();
    }
  }
  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'field_name' => NULL,
      'host_entity_type' => NULL,
      'host_entity_importer_id' => NULL,
      'host_entity_importer_nid' => NULL,
      'guid_field_name' => '',
      'is_field' => NULL,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    $field_names = array();
    foreach (field_read_fields(array('type' => 'field_collection')) as $field_name => $field) {
      $field_names[$field_name] = $field_name;
    }

    // This setting is redundant, can be derived from bundle name?
    $form['field_name'] = array(
      '#type' => 'select',
      '#title' => t('Field name'),
      '#options' => $field_names,
      '#default_value' => isset($this->config['field_name']) ? $this->config['field_name'] : NULL,
      '#description' => t('The machine-readable name of the field collection field containing this item.'),
    );

    //TODO: list only entity types with bundles with field collections?
    $entity_types = array();
    foreach (entity_get_info() as $entity_type => $entity_info) {
      $entity_types[$entity_type] = $entity_info['label'];
    }
    //TODO: use states api for better ux
    //TODO: these should really be replaced with targets with custom settings
    // using form_callbacks/summary_callbacks
    // this is a total kludge:
    $form['host_entity_type'] = array(
      '#type' => 'select',
      '#title' => t('Host entity type'),
      '#options' => $entity_types,
      '#default_value' => isset($this->config['host_entity_type']) ? $this->config['host_entity_type'] : NULL,
    );
    $form['host_entity_importer_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Host entity importer id'),
      '#description' => t('The importer feed id of the importer importing host entities. Can be left empty if host entity GUIDs are globally unique among importers or if feed item GUIDs are not used for host entity look-ups.'),
      '#default_value' => isset($this->config['host_entity_importer_id']) ? $this->config['host_entity_importer_id'] : NULL,
    );
    $form['host_entity_importer_feed_nid'] = array(
      '#type' => 'textfield',
      '#title' => t('Host entity feed nid'),
      '#description' => t(''),
      '#description' => t('The importer feed nid of the importer importing host entities. Can be left empty if host entity GUIDs are globally unique among importers, the importer is not attached a node, or if feed item GUIDs are not used for host entity look-ups.'),
      '#default_value' => isset($this->config['host_entity_importer_feed_nid']) ? $this->config['host_entity_importer_feed_nid'] : NULL,
    );
    $form['guid_field_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Field/property name of Host entity GUID'),
      '#description' => t('Machine name of the field/property that used for host entity GUID. If left empty GUID of the host entity feed item will be used for host entity lookup.'),
      '#default_value' => isset($this->config['guid_field_name']) ? $this->config['guid_field_name'] : '',
    );
    $form['is_field'] = array(
      '#type' => 'checkbox',
      '#title' => t('Is field'),
      '#description' => t('A flag that indicate that whether it is a property or field. If field/property name of host entity GUID is left empty this setting has no effect.'),
      '#default_value' => isset($this->config['is_field']) ? $this->config['is_field'] : NULL,
    );
    return $form;
  }

  /**
   * Override setTargetElement to operate on a target item that is a entity.
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value) {
    switch ($target_element) {
      case 'host_entity_guid':
        $entity_id = NULL;
        if (!empty($this->config['guid_field_name'])) {
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', $this->config['host_entity_type']);
          if (!empty($this->config['is_field'])) {
            $query->fieldCondition($this->config['guid_field_name'], 'value', $value);
          }
          else{
            $query->propertyCondition($this->config['guid_field_name'], $value);
          }
          $result = $query->execute();
          if(!empty($result)) {
            list(, $data) = each($result);
            $entity_id = key($data);
          }
        }
        else {
          $query = db_select('feeds_item')
            ->fields('feeds_item', array('entity_id'))
            ->condition('entity_type', $this->config['host_entity_type']);
          if (!empty($this->config['host_entity_importer_id'])) {
            $query->condition('id', $this->config['host_entity_importer_id']);
          }
          if (!empty($this->config['host_entity_importer_feed_nid'])) {
            $query->condition('feed_nid', $this->config['host_entity_importer_feed_nid']);
          }
          //TODO: make target configurable, guid/url?
          $entity_id = $query->condition('guid', $value)
            ->execute()
            ->fetchField();
        }
        if (!empty($entity_id)) {
          //Load skipping cache with $reset = TRUE, or will static cache reset on
          //save?
          $host_entity = entity_load($this->config['host_entity_type'], array($entity_id), array(), TRUE);
          $host_entity = current($host_entity);
          if(!$target_item->hostEntityId()) {
            $target_item->setHostEntity($this->config['host_entity_type'], $host_entity);
          }
          else {
            $target_item->updateHostEntity($host_entity);
          }
        }
        break;
      default:
        parent::setTargetElement($source, $target_item, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
     $targets = parent::getMappingTargets();

    // Add general GUID target
    $targets['guid'] = array(
      'name' => t('GUID'),
      'description' => t('The globally unique identifier of the item. E. g. the feed item GUID in the case of a syndication feed. May be unique.'),
      'optional_unique' => TRUE,
    );

    // Add hostEntity GUID target
    $targets['host_entity_guid'] = array(
      'name' => t('Host Entity GUID'),
      'description' => t('The globally unique identifier of the host entity. Must be unique. We used this value to fetch hostEntityId.'),
    );

    $targets['item_id'] = array(
      'name' => t('Item ID'),
      'description' => t('The item id of the field collection. NOTE: use this feature with care, field collection item ids are usually assigned by Drupal.'),
      'optional_unique' => TRUE,
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    $entity_type = $this->entityType();
    $bundle = $this->config['field_name'];
    drupal_alter('feeds_processor_targets', $targets, $entity_type, $bundle);

    return $targets;
  }
}
