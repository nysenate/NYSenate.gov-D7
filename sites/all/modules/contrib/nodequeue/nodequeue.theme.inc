<?php
/**
 * @file
 * Theme and preprocess functions for the Nodequeue module.
 */

/**
 * Theme the subqueue overview as a sortable list.
 *
 * @ingroup themeable
 */
function theme_nodequeue_arrange_subqueue_form_table($variables) {
  $form = $variables['form'];

  $output = '';

  // Get css to hide some of the help text if javascript is disabled.
  drupal_add_css(drupal_get_path('module', 'nodequeue') . '/nodequeue.css');

  $table_id = 'nodequeue-dragdrop-' . $form['#subqueue']['sqid'];
  $table_classes = array(
    'nodequeue-dragdrop',
    'nodequeue-dragdrop-qid-' . $form['#subqueue']['qid'],
    'nodequeue-dragdrop-sqid-' . $form['#subqueue']['sqid'],
    'nodequeue-dragdrop-reference-' . $form['#subqueue']['reference'],
  );
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'node-position');
  drupal_add_js(drupal_get_path('module', 'nodequeue') . '/nodequeue_dragdrop.js');

  $reverse[str_replace('-', '_', $table_id)] = (bool) $form['#queue']['reverse'];
  drupal_add_js(
    array(
      'nodequeue' => array(
        'reverse' => $reverse,
      )
    ),
    array(
      'type' => 'setting',
      'scope' => JS_DEFAULT,
    )
  );

  // Render form as table rows.
  $rows = array();
  $counter = 1;
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['title'])) {
      $row = array();

      $row[] = drupal_render($form[$key]['title']);
      $row[] = drupal_render($form[$key]['author']);
      $row[] = drupal_render($form[$key]['date']);
      $row[] = drupal_render($form[$key]['position']);
      $row[] = (!empty($form[$key]['edit'])) ? drupal_render($form[$key]['edit']) : '&nbsp;';
      $row[] = drupal_render($form[$key]['remove']);
      $row[] = array(
        'data' => $counter,
        'class' => array('position')
      );

      $classes = !empty($form[$key]['#attributes']['class']) ? $form[$key]['#attributes']['class'] : array();
      $classes[] = 'draggable';
      $rows[] = array(
        'data'  => $row,
        'class' => $classes,
      );
    }

    $counter++;
  }
  if (empty($rows)) {
    $rows[] = array(array('data' => t('No nodes in this queue.'), 'colspan' => 7));
  }

  // Render the main nodequeue table.
  $header = array(t('Title'), t('Author'), t('Post Date'), t('Position'), array('data' => t('Operations'), 'colspan' => 2), t('Position'));

  // Allow other modules to alter the table setup before output.
  drupal_alter('nodequeue_arrange_subqueue_form', $form, $header, $rows);

  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => $table_id, 'class' => $table_classes)));

  return $output;
}

/**
 * Return a "queue is empty" message.
 *
 * @ingroup themeable
 */
function theme_nodequeue_subqueue_empty_text() {
  return t('Queue empty');
}

/**
 * Return a "queue is full" message.
 *
 * @ingroup themeable
 */
function theme_nodequeue_subqueue_full_text() {
  return t('Queue full');
}

/**
 * Return a count of elements in the queue.
 *
 * @ingroup themeable
 */
function theme_nodequeue_subqueue_count_text($variables) {
  return t('@count in queue', array('@count' => $variables['count']));
}
