<?php

/**
 * @file
 * Picture Mapping class.
 */

/**
 * Picture mapping class.
 */
class PictureMapping {

  /**
   * The picture mapping ID (machine name).
   *
   * @var string
   */
  protected $machine_name;

  /**
   * The picture mapping label.
   *
   * @var string
   */
  protected $label;

  /**
   * The picture mappings.
   *
   * @var array
   */
  protected $mapping = array();

  /**
   * The breakpoint group.
   */
  protected $breakpoint_group = '';

  /**
   * Boolean flag, used internally.
   */
  protected $isExporting = FALSE;

  /**
   * Set data values based on schema.
   *
   * @see picture_mapping_object_factory()
   */
  public function setValues($schema, $data) {
    foreach ($schema['fields'] as $field => $info) {
      if (isset($data->{$field})) {
        $this->{$field} = !empty($info['serialize']) && is_string($data->{$field}) ? unserialize($data->{$field}) : $data->{$field};
      }
      else {
        $this->{$field} = NULL;
      }
      unset($data->{$field});
    }

    if (isset($schema['join'])) {
      foreach ($schema['join'] as $join) {
        $join_schema = ctools_export_get_schema($join['table']);
        if (!empty($join['load'])) {
          foreach ($join['load'] as $field) {
            $info = $join_schema['fields'][$field];
            $this->{$field} = empty($info['serialize']) ? $data->{$field} : unserialize($data->{$field});
            unset($data->field);
          }
        }
      }
    }

    foreach ((array) $data as $field => $val) {
      $this->{$field} = $val;
    }
    $this->loadBreakpointGroup();
    $this->loadAllMappings();
  }

  /**
   * Save the picture mapping.
   *
   * @return false||int
   *   If the record insert or update failed, returns FALSE. If it succeeded,
   *   returns SAVED_NEW or SAVED_UPDATED, depending on the operation performed.
   */
  public function save() {
    $update = array();
    $this->cleanMappings();
    $data = $this->toArray();
    if (isset($this->id) && $this->id) {
      $update = array('id');
      $data['id'] = $this->id;
    }
    $return = drupal_write_record('picture_mapping', $data, $update);
    module_load_include('info.inc', 'field');
    field_info_cache_clear();
    $this->setValues(ctools_export_get_schema('picture_mapping'), $data);
    $this->loadBreakpointGroup();
    return $return;
  }

  /**
   * Returns an array of all property values.
   *
   * @return mixed[]
   *   An array of property values, keyed by property name.
   */
  public function toArray() {
    return array(
      'machine_name' => $this->machine_name,
      'label' => $this->label,
      'breakpoint_group' => $this->breakpoint_group && is_object($this->breakpoint_group) ? $this->breakpoint_group->machine_name : $this->breakpoint_group,
      'mapping' => $this->mapping,
    );
  }

  /**
   * Create a duplicate.
   *
   * @return PictureMapping
   *   The duplicate.
   */
  public function createDuplicate() {
    $clone = clone $this;
    $clone->id = NULL;
    $clone->machine_name = $this->machine_name . '_clone';
    $clone->label = t('Clone of !label', array('!label' => check_plain($this->label)));
    $clone->mapping = $this->mapping;
    return $clone;
  }

  /**
   * Loads the breakpoint group.
   */
  protected function loadBreakpointGroup() {
    if ($this->breakpoint_group && !is_object($this->breakpoint_group)) {
      $breakpoint_group = breakpoints_breakpoint_group_load($this->breakpoint_group);
      $this->breakpoint_group = $breakpoint_group;
    }
  }

  /**
   * Loads all mappings and removes non-existing ones.
   */
  protected function loadAllMappings() {
    $loaded_mappings = $this->mapping;
    $all_mappings = array();
    if ($breakpoint_group = $this->breakpoint_group) {
      $breakpoints = $breakpoint_group->breakpoints;
      foreach ($breakpoints as $breakpoint_id) {
        $breakpoint = breakpoints_breakpoint_load_by_fullkey($breakpoint_id);
        if ($breakpoint) {
          // Get the mapping for the default multiplier.
          $all_mappings[$breakpoint_id]['1x'] = '';
          if (isset($loaded_mappings[$breakpoint->machine_name]['1x'])) {
            $all_mappings[$breakpoint_id]['1x'] = $loaded_mappings[$breakpoint->machine_name]['1x'];
          }

          // Get the mapping for the other multipliers.
          if (isset($breakpoint->multipliers) && !empty($breakpoint->multipliers)) {
            foreach ($breakpoint->multipliers as $multiplier => $status) {
              if ($status) {
                $all_mappings[$breakpoint_id][$multiplier] = '';
                if (isset($loaded_mappings[$breakpoint->machine_name][$multiplier])) {
                  $all_mappings[$breakpoint_id][$multiplier] = $loaded_mappings[$breakpoint->machine_name][$multiplier];
                }
              }
            }
          }
        }
      }
    }
    $this->mapping = $all_mappings;
  }

  /**
   * Clean mappings.
   */
  protected function cleanMappings() {
    foreach ($this->mapping as $breakpoint => $multipliers) {
      foreach ($multipliers as $multiplier => $mapping_definition) {
        switch ($mapping_definition['mapping_type']) {
          case '_none':
            unset($mapping_definition['image_style']);
            unset($mapping_definition['sizes']);
            unset($mapping_definition['sizes_image_styles']);
            break;

          case 'image_style':
            unset($mapping_definition['sizes']);
            unset($mapping_definition['sizes_image_styles']);
            break;

          case 'sizes':
            unset($mapping_definition['image_style']);
            $mapping_definition['sizes_image_styles'] = array_filter($mapping_definition['sizes_image_styles']);
            break;
        }
        $this->mapping[$breakpoint][$multiplier] = $mapping_definition;
      }
    }
  }

  /**
   * Check if there are mappings.
   *
   * @return bool
   *    TRUE if this PictureMapping has mappings, FALSE otherwise.
   */
  public function hasMappings() {
    $mapping_found = FALSE;
    foreach ($this->mapping as $multipliers) {
      foreach ($multipliers as $mapping_definition) {
        if (!PictureMapping::isEmptyMappingDefinition($mapping_definition)) {
          $mapping_found = TRUE;
          break 2;
        }
      }
    }
    return $mapping_found;
  }

  /**
   * Check if a mapping definition is empty.
   *
   * @return bool
   *    TRUE if this mapping definition is considered empty, FALSE otherwise.
   */
  public static function isEmptyMappingDefinition($mapping_definition) {
    if (!empty($mapping_definition) && isset($mapping_definition['mapping_type'])) {
      switch ($mapping_definition['mapping_type']) {
        case 'sizes':
          if ($mapping_definition['sizes'] && array_filter($mapping_definition['sizes_image_styles'])) {
            return FALSE;
          }
          break;

        case 'image_style':
          if ($mapping_definition['image_style']) {
            return FALSE;
          }
          break;
      }
    }
    return TRUE;
  }

  /**
   * Get the machine name.
   *
   * @return string
   *    The machine name.
   */
  public function getMachineName() {
    return $this->machine_name;
  }

  /**
   * Set the machine name.
   */
  public function setMachineName($machine_name) {
    $this->machine_name = $machine_name;
  }

  /**
   * Get the picture mappings.
   *
   * @return array
   *    The mappings.
   */
  public function getMappings() {
    return $this->mapping;
  }

  /**
   * Set the picture mappings.
   */
  public function setMappings($mappings) {
    $this->mapping = $mappings;
  }

  /**
   * Set the label.
   */
  public function setLabel($label) {
    $this->label = $label;
  }

  /**
   * Get the label.
   *
   * @return string
   *    The label.
   */
  public function label() {
    return $this->label;
  }

  /**
   * Set the breakpoint group.
   */
  public function setBreakpointGroup($breakpoint_group) {
    if (!$this->getBreakpointGroup() || $breakpoint_group != $this->getBreakpointGroup()->name) {
      $this->breakpoint_group = $breakpoint_group;
      $this->loadBreakpointGroup();
      $this->loadAllMappings();
    }
  }

  /**
   * Get the breakpoint group.
   *
   * @return object
   *   The breakpoint group object.
   */
  public function getBreakpointGroup() {
    $this->loadBreakpointGroup();
    return $this->breakpoint_group;
  }

  /**
   * Is utilized for reading data from inaccessible properties.
   */
  public function __get($name) {
    switch ($name) {
      case 'machine_name':
        return $this->getMachineName();

      case 'label':
        return $this->label();

      case 'mapping':
        return $this->getMappings();

      case 'breakpoint_group':
        if ($this->isExporting) {
          return $this->breakpoint_group;
        }
        return $this->getBreakpointGroup();

      default:
        return $this->{$name};
    }
  }

  /**
   * Is run when writing data to inaccessible properties.
   */
  public function __set($name, $value) {
    switch ($name) {
      case 'machine_name':
        $this->setMachineName($value);
        break;

      case 'label':
        $this->setLabel($value);
        break;

      case 'mapping':
        $this->setMappings($value);
        break;

      case 'breakpoint_group':
        $this->setBreakpointGroup($value);
        break;

      default:
        $this->{$name} = $value;
        break;
    }
  }

  /**
   * Is triggered by calling isset() or empty() on inaccessible properties.
   */
  public function __isset($name) {
    return isset($this->{$name});
  }

  /**
   * Export this PictureMapping.
   *
   * @return string
   *    The export string.
   */
  public function export($indent = '') {
    $this->cleanMappings();
    $this->breakpoint_group = $this->getBreakpointGroup() ? $this->getBreakpointGroup()->machine_name : $this->breakpoint_group;
    $this->isExporting = TRUE;
    $export = ctools_export_object('picture_mapping', $this, $indent);
    $this->isExporting = TRUE;
    $this->loadBreakpointGroup();
    return $export;
  }

}
