<?php
/**
 * @file
 * Theme for Semantic Views.
 *
 * Holds template preprocess for Views Field and Views Rows.
 * @see semanticviews_views_plugins()
 */

/**
 * Preprocess theme function to print a single record from a row, with fields
 */
function template_preprocess_semanticviews_view_fields(&$vars) {
  $view = $vars['view'];

  // Loop through the fields for this view.
  $vars['fields'] = array(); // ensure it's at least an empty array.
  foreach ($view->field as $id => $field) {
    // render this even if set to exclude so it can be used elsewhere.
    $field_output = $view->style_plugin->get_field($view->row_index, $id);
    $empty = $field->is_value_empty($field_output, $field->options['empty_zero']);
    if (empty($field->options['exclude']) && (!$empty || (empty($field->options['hide_empty']) && empty($vars['options']['skip_blank'])))) {
      $object = new stdClass();

      $object->content = $field_output;
      if (isset($view->field[$id]->field_alias) && isset($vars['row']->{$view->field[$id]->field_alias})) {
        $object->raw = $vars['row']->{$view->field[$id]->field_alias};
      }
      else {
        $object->raw = NULL; // make sure it exists to reduce NOTICE
      }

      $object->handler = &$view->field[$id];

      // If Semantic Views: Fields settings havn't been saved with new fields
      // this is not set and then add empty array with no values.
      if (isset($vars['options']['semantic_html'][$id])) {
        $semantic_html = $vars['options']['semantic_html'][$id];
      }
      else {
        // Default empty values.
        $semantic_html = array(
          'element_type' => '',
          'class' => '',
          'label_element_type' => '',
          'label_class' => ''
        );
      }

      // Field content
      $object->element_type = check_plain($semantic_html['element_type']);
      $object->attributes = array();
      if ($semantic_html['class']) {
        $object->attributes['class'] = $semantic_html['class'];
      }

      // Field label
      $object->label = check_plain($view->field[$id]->label());
      if (!empty($object->label)) {
        $object->label_element_type = check_plain($semantic_html['label_element_type']);
        $object->label_attributes = array();
        if ($semantic_html['label_class']) {
          $object->label_attributes['class'] = $semantic_html['label_class'];
        }
      }

      $vars['fields'][$id] = $object;
    }
  }
}

/**
 * Display the simple view of rows one after another
 */
function template_preprocess_semanticviews_view_unformatted(&$vars) {
  $view = $vars['view'];

  $vars['group_element'] = check_plain($vars['options']['group']['element_type']);
  $vars['group_attributes'] = array();
  if ($vars['options']['group']['class']) {
    $vars['group_attributes']['class'] = $vars['options']['group']['class'];
  }

  $vars['list_element'] = check_plain($vars['options']['list']['element_type']);
  $vars['list_attributes'] = array();
  if ($vars['options']['list']['class']) {
    $vars['list_attributes']['class'] = $vars['options']['list']['class'];
  }

  // TODO: set a default or handle empty value.
  $vars['row_element'] = check_plain($vars['options']['row']['element_type']);
  $last_every_nth = $vars['options']['row']['last_every_nth'];

  $vars['row_attributes'] = array();

  // Set up striping class array.
  $stripes = array();
  if (trim($vars['options']['row']['striping_classes'])) {
    $stripes = explode(' ', trim($vars['options']['row']['striping_classes']));
  }
  $striping = count($stripes);

  // When grouping fields row index doesn't reset in each group so we have to do it manually,
  // otherwise "last_every_nth" may work incorrect.
  $index_in_group = 0;

  foreach ($vars['rows'] as $id => $row) {
    $vars['row_attributes'][$id] = array();
    $classes = array();

    if ($row_class = $view->style_plugin->tokenize_class($id, $vars['options']['row']['class'])) {
      $classes[] = $row_class;
    }

    if ($vars['options']['row']['first_class']) {
      // The FIRST class attribute can be used in two ways. When the "last every
      // nth" option is specified, the FIRST attribute is added to the class in
      // those intervals. This could be useful for grid designs where the first
      // unit in a row needs a zero width margin.
      if (($last_every_nth && $index_in_group % $last_every_nth == 0) ||
        // Otherwise when last every nth is not set, the FIRST class is added
        // to the first row in the pager set.
        (!$last_every_nth && $index_in_group == 0)) {
        if ($class = $view->style_plugin->tokenize_class($id, $vars['options']['row']['first_class'])) {
          $classes[] = $class;
        }
      }
    }

    if ($vars['options']['row']['last_class']) {
      // The LAST class attribute can be used in two ways. When the "last every
      // nth" option is specified, the LAST attribute is added to the class in
      // those intervals. This could be useful for grid designs where the last
      // unit in a row needs a zero width margin.
      if (($last_every_nth && ($index_in_group + 1) % $last_every_nth == 0) ||
        // Otherwise when last every nth is not set, the LAST class is added
        // to the last row in the pager set.
        (!$last_every_nth && ($index_in_group + 1) == count($vars['rows']))) {
        if ($class = $view->style_plugin->tokenize_class($id, $vars['options']['row']['last_class'])) {
          $classes[] = $class;
        }
      }
    }

    if ($striping) {
      if ($class = $view->style_plugin->tokenize_class($id, $stripes[$id % $striping])) {
        $classes[] = $class;
      }
    }

    if (!empty($classes)) {
      $vars['row_attributes'][$id]['class'] = implode(' ', $classes);
    }

    $index_in_group++;
  }
}
