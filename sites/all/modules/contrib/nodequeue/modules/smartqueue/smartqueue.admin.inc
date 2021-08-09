<?php
/**
 * @file
 * Admin page callbacks for the smartqueue module.
 */

/**
 * Display the queue controls for a taxonomy term.
 *
 * @param $term
 *   The fully loaded taxonomy term that will be loaded by the hook_menu.
 *
 * @return string
 *   return data in html table
 */
function smartqueue_term_tab($term) {

  $title = t('Queues for @title', array('@title' => check_plain($term->name)));
  drupal_set_title($title);

  $output = '';

  // Fetch all of the queues for this term.
  //$queues = smartqueue_term_load_queues($term);
  // Fetch all of the subqueues for this term.
  $subqueues = smartqueue_get_subqueues_by_term($term);

  if (empty($subqueues)) {
    return t('No subqueues.');
  }

  $header = array(
    array('data' => t('Title'), 'field' => 'title', 'sort' => 'asc'),
    array('data' => t('Queue ID'), 'field' => 'qid'),
    array('data' => t('Max nodes'), 'field' => 'size'),
    array('data' => t('Operations')),
  );

  $rows = array();
  foreach ($subqueues as $subqueue_info) {
    $queue = nodequeue_load($subqueue_info['qid']);
    $subqueue = subqueue_load($subqueue_info['subqueue_id']);

    $operations = array();
    $operations['view'] = array(
      'title' => t('Manage Queue'),
      'href' => $subqueue_info['path'],
    );

    if (user_access('administer nodequeue')) {
      $operations['edit'] = array(
        'title' => t('Edit'),
        'href' => 'admin/structure/nodequeue/' . $queue->qid . '/edit',
      );
      $operations['delete'] = array(
        'title' => t('Delete'),
        'href' => 'admin/structure/nodequeue/' . $queue->qid . '/delete',
      );
    }
    $links = theme('links', array('links' => $operations, 'attributes' => array('class' => array('inline'))));

    // @todo add subqueue info?
    //$sub_text = nodequeue_subqueue_size_text($queue->size, $subqueue->count, FALSE);

    $rows[] = array(
      array('class' => array('nodequeue-title'), 'data' => check_plain($queue->title)),
      array('class' => array('nodequeue-id'), 'data' => $queue->qid),
      array('class' => array('nodequeue-max-nodes'), 'data' => $queue->size == 0 ? t('Infinite') : $queue->size),
      array('class' => array('nodequeue-operations'), 'data' => $links),
    );
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  $output .= theme('pager', array('tags' => NULL));

  return $output;
}


