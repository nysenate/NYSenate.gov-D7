<?php
/**
 * @file
 * uuid_node hooks on behalf of the book module.
 */

/**
 * Implements hook_uuid_entity_features_export_alter().
 */
function book_uuid_node_features_export_alter(&$export, $node, $module) {
  if (isset($node->book['bid'])) {
    $pipe = &$export['__drupal_alter_by_ref']['pipe'];
    $uuid = current(entity_get_uuid_by_id('node', array($node->book['bid'])));
    $pipe['uuid_book'][$uuid] = $uuid;

    // If a parent is defined add the parent node as dependency.
    if (isset($node->book['plid']) && ($parent_menu_link = book_link_load($node->book['plid']))) {
      $parent_uuid = current(entity_get_uuid_by_id('node', array($parent_menu_link['nid'])));
      if (!empty($parent_uuid)) {
        $pipe['uuid_node'][$uuid]  = $uuid;
      }
    }
  }
}

/**
 * Implements hook_uuid_node_features_export_render_alter().
 *
 * For root book pages - set bid to new. For child pages set a parent_uuid
 * to use on rebuild. Clear all other book properties.
 */
function book_uuid_node_features_export_render_alter(&$export, $node, $module) {
  if (isset($node->book) && isset($node->book['bid']) && isset($node->book['nid'])) {
    $node_book_export = array();
    if ($node->book['bid'] == $node->book['nid']) {
      $node_book_export['bid'] = 'new';
      $node_book_export['parent_depth_limit'] = 1;
    }
    else {
      $book_uuid = current(entity_get_uuid_by_id('node', array($node->book['bid'])));
      $node_book_export['bid'] = $book_uuid;
    }

    // If a parent is defined ensure we export the parent uuid.
    if (isset($node->book['plid']) && ($parent_menu_link = book_link_load($node->book['plid']))) {
      $parent_uuid = current(entity_get_uuid_by_id('node', array($parent_menu_link['nid'])));
      if (!empty($parent_uuid)) {
        $node_book_export['parent_uuid'] = $parent_uuid;
        $node_book_export['weight'] = $node->book['weight'];
      }
    }

    $export->book = $node_book_export;
  }
}

/**
 * Implements hook_uuid_node_features_rebuild_alter().
 *
 * Replace book parent uuid's with the valid book parameters. As there is no way
 * to guarantee the correct top-down hierarchical order - collect orphan
 * book nodes for post node rebuild processing.
 */
function book_uuid_node_features_rebuild_alter($node, $module) {
  // Ensure we don't have a bogus book configuration. book_node_prepare() adds
  // defaults that trigger book_entity_uuid_presave() to create a new book where
  // none is. This just happens when an user with the right permissions reverts
  // the feature.
  if (empty($node->book['bid']) && isset($node->book['original_bid'])) {
    unset($node->book);
  }

  if (isset($node->book)) {
    if (isset($node->book['parent_uuid'])) {
      $parent_node = entity_load_single_by_uuid('node', $node->book['parent_uuid']);

      if ($parent_node && isset($parent_node->book['mlid'])) {
        // Set up node as for add child page.
        $node->book['plid'] = $parent_node->book['mlid'];
        $node->book['menu_name'] = $parent_node->book['menu_name'];
        $node->book['weight'] = $parent_node->book['weight'];
      }
      else {
        // Add to pending.
        _book_uuid_node_features_pending($node);
      }
    }
  }
  $existing = entity_load_single_by_uuid('node', $node->uuid);
  if (!empty($existing->book['mlid'])) {
    $node->book['mlid'] = $existing->book['mlid'];
    $node->book['plid'] = $existing->book['plid'];
  }
  elseif (!empty($existing->book) && !isset($node->book)) {
    // Delete a book that doesn't exist in the export. Abuse the hook_node_delte
    // integration.
    // @TODO is this the right approach?
    book_node_delete($existing);
  }
}

/**
 * Implements hook_uuid_entity_features_rebuild_complete().
 *
 * Ensure complete book structure has been set up.
 */
function book_uuid_entity_features_rebuild_complete($entity_type, $entities, $module) {
  if ($entity_type == 'node') {
    // Reset the node cache.
    node_load(FALSE, NULL, TRUE);

    $pending = _book_uuid_node_features_pending();
    if (!empty($pending)) {
      // Sort so that parent nodes come before child nodes.
      $pending = _book_uuid_node_features_pending_sort($pending);
    }

    foreach ($pending as $uuid => $book) {
      $book_page_node = entity_load_single_by_uuid('node', $uuid);
      $parent_node = entity_load_single_by_uuid('node', $book['parent_uuid']);

      // Set up node as for add child page.
      $book_page_node->book['bid'] = $parent_node->book['bid'];
      $book_page_node->book['plid'] = $parent_node->book['mlid'];
      $book_page_node->book['menu_name'] = $parent_node->book['menu_name'];
      $book_page_node->book['weight'] = $book['weight'];

      node_save($book_page_node);
      node_load($book_page_node->nid, NULL, TRUE);
    }
  }
}

/**
 * Any pages with no parent page are put here to be processed later.
 */
function _book_uuid_node_features_pending($node = NULL) {
  static $pending = array();

  if (!is_null($node)) {
    $pending[$node->uuid] = $node->book;
  }
  else {
    return $pending;
  }
}

/**
 * Sort callback to put parents before children.
 */
function _book_uuid_node_features_pending_sort($pending) {
  $pending_by_parent = array();

  // Group by parent.
  foreach ($pending as $uuid => $book) {
    $parent_uuid = $book['parent_uuid'];
    if (empty($pending_by_parent)) {
      $pending_by_parent[$parent_uuid] = array();
    }

    $pending_by_parent[$parent_uuid][$uuid] = $book;
  }

  $sorted_pending = array();

  // Find top-level parents and get all ancestors in order.
  foreach ($pending_by_parent as $parent_uuid => $books) {
    if (empty($pending[$parent_uuid])) {
      // This is a top-level pending - recurse from here.
      $sorted_pending = array_merge($sorted_pending, _book_uuid_node_features_pending_get_ancestors($parent_uuid, $pending_by_parent));
    }
  }

  return $sorted_pending;
}

/**
 * Recursively collect ancestor nodes in top-down order.
 */
function _book_uuid_node_features_pending_get_ancestors($parent_uuid, $pending_by_parent) {
  $sorted_pending = array();

  if (!empty($pending_by_parent[$parent_uuid])) {
    foreach ($pending_by_parent[$parent_uuid] as $uuid => $book) {
      $sorted_pending[$uuid] = $book;
      $sorted_pending = array_merge($sorted_pending, _book_uuid_node_features_pending_get_ancestors($uuid, $pending_by_parent));
    }
  }

  return $sorted_pending;
}
