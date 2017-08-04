<?php

/**
 * @file
 * Defines a plugin for a multiselect facet API widget.
 */

/**
 * Widget that renders facets as a multiselect element.
 */
class FacetapiMultiSelectWidget extends FacetapiWidgetLinks {
  /**
   * Renders the facet.
   */
  public function execute() {
    // We need a separate form ID for each facet, so Drupal can distinguish
    // between multiple facets on the page. See facetapi_multiselect_forms().
    // Use drupal_static() because a regular static variable is buggy here for
    // some reason.
    $count = &drupal_static('FacetapiMultiSelectWidget:execute', 0);
    $form_id = 'facetapi_multiselect_form_' . ++$count;
    $element = &$this->build[$this->facet['field alias']];
    $element = drupal_get_form($form_id, $this, $element);
  }

  /**
   * Builds an array of #options for our select element.
   */
  public function buildOptions($element) {
    $options = array();
    foreach ($element as $item) {
      if (empty($item['#item_children'])) {
        $key = $this->getOptionKey($item);
        $options[$key] = $item['#markup'];
      }
      else {
        // Recursively add any children of the item to the #options array (this
        // will result in them being placed inside optgroups).
        $options[$item['#markup']] = $this->buildOptions($item['#item_children']);
      }
    }
    return $options;
  }

  /**
   * Builds a #default_value array for our select element.
   */
  public function buildDefaultValue($element) {
    $default_value = array();
    foreach ($element as $item) {
      if ($item['#active']) {
        $default_value[] = $this->getOptionKey($item);
        // If the item has children, add their default values to the array
        // also.
        if (!empty($item['#item_children'])) {
          $default_value = array_merge($default_value, $this->buildDefaultValue($item['#item_children']));
        }
      }
    }
    return $default_value;
  }

  /**
   * Gets the key to use for an item in the select element #options array.
   */
  protected function getOptionKey($item) {
    // Set the key to the filter that will appear in the URL if this item is
    // selected. We need to do it this way (rather than using $item['#query'])
    // so that multiple selections can be combined together in the form's
    // submit handler.
    return $this->facet['field alias'] . ':' . $item['#indexed_value'];
  }
}
