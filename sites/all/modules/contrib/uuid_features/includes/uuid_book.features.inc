<?php

/**
 * @file
 * Features hooks for the uuid_book features component.
 *
 * Select a book adds all book nodes to the pipe so they can be processed as
 * normal nodes with book processing handled by uuid_node_feature hooks.
 * Unfortunately order is not preserved so a little post load processing is
 * required.
 */

/**
 * Implements hook_features_export_options().
 */
function uuid_book_features_export_options() {
  $options = array();

  // Use nid as no uuid for books.
  $book_nids = array();
  // Call with param for possible fix from here:
  // @link https://www.drupal.org/node/760102
  $books = book_get_books(TRUE);
  foreach ($books as $book) {
    $book_nids[] = $book['nid'];
  }

  if (!empty($book_nids)) {
    $query = new EntityFieldQuery();
    $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('nid', $book_nids, 'IN')
      ->propertyOrderBy('title')
      ->addTag('uuid_book_features_export_options');
    $result = $query->execute();
    if (!empty($result['node'])) {
      $nodes = node_load_multiple(array_keys($result['node']));
      foreach ($nodes as $node) {
        $options[$node->uuid] = $node->title;
      }
    }
  }
  return $options;
}

/**
 * Traverse the book tree to get all nodes uuids in the book.
 *
 * @param array $tree
 *   A subtree of the book menu hierarchy, rooted at the current page.
 *
 * @return array
 *   An array of book node uuids.
 */
function uuid_book_features_export_traverse(array $tree) {
  $book_uuids = array();

  foreach ($tree as $data) {
    // Note- access checking is already performed when building the tree.
    if ($node = node_load($data['link']['nid'], FALSE)) {
      $book_uuids[] = $node->uuid;

      if ($data['below']) {
        $book_uuids = array_merge($book_uuids, uuid_book_features_export_traverse($data['below']));
      }
    }
  }
  return $book_uuids;
}

/**
 * Implements hook_features_export().
 */
function uuid_book_features_export($data, &$export, $module_name = '') {
  $pipe = array();

  $export['dependencies']['uuid_features'] = 'uuid_features';

  $book_uuids = array();
  $nodes = entity_uuid_load('node', $data, array(), TRUE);

  foreach ($nodes as $node) {
    if (isset($node->book)) {
      $tree = book_menu_subtree_data($node->book);
      $book_uuids = array_merge($book_uuids, uuid_book_features_export_traverse($tree));
    }
    $export['features']['uuid_book'][$node->uuid] = $node->uuid;
  }

  if (!empty($book_uuids)) {
    if (!empty($pipe['uuid_node'])) {
      $pipe['uuid_node'] = array_merge($pipe['uuid_node'], $book_uuids);
    }
    else {
      $pipe['uuid_node'] = $book_uuids;
    }
  }
  return $pipe;
}
