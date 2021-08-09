<?php
/**
 * @file
 * Features hooks for the uuid_nodequeue_item features component.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_nodequeue_item_features_export_options() {
  $options = array();
  $result = db_select('nodequeue_nodes', 'qn')
    ->fields('qn', array('qid', 'sqid', 'nid', 'position'))
    ->orderBy('position', 'ASC')
    ->addTag('uuid_nodequeue_item_features_export_options')
    ->execute();
  while ($row = $result->fetchAssoc()) {
    $queue = nodequeue_load($row['qid']);
    $uuids = entity_get_uuid_by_id('node', array($row['nid']));
    $uuid = reset($uuids);
    if ($uuid) {
      $item_name = $queue->name . ' - ' . $uuid;
      $options[$item_name] = $item_name;
    }
  }
  return $options;
}

/**
 * Implements hook_features_export().
 */
function uuid_nodequeue_item_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['nodequeue'] = 'nodequeue';
  $export['dependencies']['uuid'] = 'uuid';
  $export['dependencies']['uuid_features'] = 'uuid_features';

  foreach ($data as $item_id) {
    $export['features']['uuid_nodequeue_item'][$item_id] = $item_id;
  }
  return array();
}

/**
 * Implements hook_features_export_render().
 */
function uuid_nodequeue_item_features_export_render($module, $data) {
  $translatables = $code = array();
  $code[] = '  $nodequeue_items = array();';
  $code[] = '';

  if (!empty($data)) {
    foreach ($data as $item_id) {
      list($queue_name, $uuid) = explode(' - ', $item_id);
      $nodequeue = nodequeue_load_queue_by_name($queue_name);
      if ($nodequeue) {

        $nids = entity_get_id_by_uuid('node', array($uuid));
        $nid = reset($nids);
        if ($nid) {
          // We need to check if record exists to perform overriden state check.
          $result = db_select('nodequeue_nodes', 'qn')
            ->fields('qn', array('qid', 'sqid', 'nid'))
            ->condition('qn.nid', $nid)
            ->condition('qn.qid', $nodequeue->qid)
            ->range(0, 1)
            ->execute()
            ->rowCount();

          if (!$result) {
            continue;
          }
        }
        else {
          continue;
        }

        $uuids = entity_get_uuid_by_id('node', array($nid));
        $uuid = reset($uuids);
        if ($uuid) {
          $export = array(
            'queue_name' => $queue_name,
            'node_uuid' => $uuid,
          );
          $code[] = '  $nodequeue_items[] = ' . features_var_export($export, '  ') . ';';
        }
      }
    }
  }
  if (!empty($translatables)) {
    $code[] = features_translatables_export($translatables, '  ');
  }
  $code[] = '  return $nodequeue_items;';
  $code = implode("\n", $code);

  return array('uuid_features_default_nodequeue_items' => $code);

}

/**
 * Implements hook_features_revert().
 */
function uuid_nodequeue_item_features_revert($module) {
  uuid_nodequeue_item_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function uuid_nodequeue_item_features_rebuild($module) {
  $nodequeue_items = features_get_default('uuid_nodequeue_item', $module);
  if (!empty($nodequeue_items)) {
    foreach ($nodequeue_items as $nodequeue_item) {
      $queue = nodequeue_load_queue_by_name($nodequeue_item['queue_name']);
      $subqueue = reset(nodequeue_load_subqueues_by_queue($queue->qid));
      $nid = reset(entity_get_id_by_uuid('node', array($nodequeue_item['node_uuid'])));
      if ($nid && !empty($queue->qid) && !empty($subqueue->sqid)) {
        db_delete('nodequeue_nodes')
          ->condition('qid', $queue->qid)
          ->condition('sqid', $queue->sqid)
          ->condition('nid', $nid);
        nodequeue_subqueue_add($queue, $subqueue, $nid);
      }
    }
  }
}
