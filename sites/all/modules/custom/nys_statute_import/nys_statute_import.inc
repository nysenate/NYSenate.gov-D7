<?php

/**
 * @file
 * NY Senate Statute Lib.
 */

/**
 * Iterates thru all statutes for a given lawId.
 *
 * This is the main iterator for
 *   $law_id - The three letter law id.
 *   $run_type - IMPORT-ALL | UPDATE-ALL | UPDATE-RANGE | AUDIT-ALL |.
 */
function nys_statute_import_process_statutes($law_id, $run_type) {
  if (NYS_STATUTE_IMPORT_DEBUG == TRUE) {
    print "NYS_STATUTE_IMPORT_UPDATE_DEBUG - process_statutes($law_id, $run_type)\r\n";
    return 0;
  }

  $law_tree = nys_statute_import_get_law_tree_from_node($law_id, '', '');

  if ($run_type != 'AUDIT-ALL' || $run_type != 'AUDIT-SOME' || $run_type != 'AUDIT-ONE') {
    print "===================================================================\r\n";
    print "$run_type - PROCESSING LAW-ID - $law_id \r\n";
    print "===================================================================\r\n";
  }

  // Create or update ancestor nodes if necessary.
  nys_statute_import_process_ancestors('ANCESTORS');

  // Process the law tree.
  if ($law_tree != NULL &&
        is_object($law_tree) == TRUE &&
        property_exists($law_tree, 'documents') == TRUE &&
        property_exists($law_tree->documents, 'documents') == TRUE &&
        property_exists($law_tree->documents->documents, 'items') == TRUE &&
        is_array($law_tree->documents->documents->items) == TRUE &&
        count($law_tree->documents->documents->items) > 0
  ) {

    // Record the lawId in a variable.
    variable_set('nys_statute_import_process_statutes', $law_id);

    // Process the CHAPTER.
    $statute_chapter_document_obj_wrapper = new StdClass();
    $statute_chapter_document_obj_wrapper->documents = $law_tree->documents;
    $chapter_parent_location_id = nys_statute_get_law_type($law_tree->documents->lawId);
    nys_statute_import_process_a_statute_object($statute_chapter_document_obj_wrapper, $run_type, $chapter_parent_location_id);

    // Call the recursive process_document function to process document tree.
    $parent_location_id = $law_tree->documents->lawId;
    nys_statute_import_process_document($law_tree->documents->documents, $run_type, $parent_location_id);

    variable_set('nys_statute_import_process_statutes', '');

  }
  elseif ($law_tree != NULL &&
        is_object($law_tree) == TRUE
  ) {

    // Record the lawId in a variable.
    variable_set('nys_statute_import_process_statutes', $law_id);

    // Process the CHAPTER.
    $statute_chapter_document_obj_wrapper = new StdClass();
    $statute_chapter_document_obj_wrapper->documents = $law_tree->documents;
    $chapter_parent_location_id = nys_statute_get_law_type($law_tree->documents->lawId);
    nys_statute_import_process_a_statute_object($statute_chapter_document_obj_wrapper, $run_type, $chapter_parent_location_id);

    variable_set('nys_statute_import_process_statutes', '');

  }

}

/**
 * Recursive function that processes the document tree.
 *
 * Params:
 *   $documents_obj - The three letter law id
 *   $run_type - IMPORT-ALL | UPDATE-ALL | UPDATE-RANGE | AUDIT-ALL |.
 *   $parent_location_id - location ID of the parent node.
 */
function nys_statute_import_process_document($documents_obj, $run_type, $parent_location_id = '', $prev_sibling_location_id = '', $prev_sibling_link_title = '', $next_sibling_location_id = '', $next_sibling_link_title = '') {
  if (is_array($documents_obj->items) == TRUE && $documents_obj->size > 0) {
    foreach ($documents_obj->items as $index => $statute_document_obj) {
      $last_row_index = count($documents_obj->items) - 1;

      // Set the Sibling links for each page.
      if ($index == 0) {
        // This is a first child. Create next sibling link.
        $prev_sibling_location_id = '';
        $prev_sibling_link_title = '';
        $next_sibling_location_id = $documents_obj->items[$index + 1]->locationId;
        $next_sibling_link_title = substr($documents_obj->items[$index + 1]->docType . ' ' . $documents_obj->items[$index + 1]->docLevelId . ' - ' . $documents_obj->items[$index + 1]->title, 0, 255);
      }
      elseif ($index == $last_row_index) {
        // This is the last child. Create prev sibling link.
        $prev_sibling_location_id = $documents_obj->items[$index - 1]->locationId;
        $prev_sibling_link_title = substr($documents_obj->items[$index - 1]->docType . ' ' . $documents_obj->items[$index - 1]->docLevelId . ' - ' . $documents_obj->items[$index - 1]->title, 0, 255);
        $next_sibling_location_id = '';
        $next_sibling_link_title = '';
      }
      else {
        // This is a middle child. Create prev and next sibling link.
        $prev_sibling_location_id = $documents_obj->items[$index - 1]->locationId;
        $prev_sibling_link_title = substr($documents_obj->items[$index - 1]->docType . ' ' . $documents_obj->items[$index - 1]->docLevelId . ' - ' . $documents_obj->items[$index - 1]->title, 0, 255);
        $next_sibling_location_id = $documents_obj->items[$index + 1]->locationId;
        $next_sibling_link_title = substr($documents_obj->items[$index + 1]->docType . ' ' . $documents_obj->items[$index + 1]->docLevelId . ' - ' . $documents_obj->items[$index + 1]->title, 0, 255);
      }

      // Process the document here.
      $statute_document_obj_wrapper = new StdClass();
      $statute_document_obj_wrapper->documents = $statute_document_obj;
      nys_statute_import_process_a_statute_object($statute_document_obj_wrapper, $run_type, $parent_location_id, $prev_sibling_location_id, $prev_sibling_link_title, $next_sibling_location_id, $next_sibling_link_title);

      usleep(NYS_STATUTE_IMPORT_SLEEP_MICROSECONDS);

      // If it has a child parse it.
      if ($statute_document_obj->documents->size > 0) {
        // Recursive call to itself.
        nys_statute_import_process_document($statute_document_obj->documents, $run_type, $statute_document_obj->locationId, $prev_sibling_location_id, $prev_sibling_link_title, $next_sibling_location_id, $next_sibling_link_title);
      }

    }

  }

}

/**
 * Updates a range of statutes.
 *
 * Params:
 *   $law_id - The three letter law id
 *   $fromDateTime -  its the from date time.
 *   $toDateTime - its the from date time.
 *   $run_type - type of run.
 */
function nys_statute_import_process_update_range_statutes($law_id, $fromDateTime, $toDateTime, $run_type) {
  $changed_statutes_array = nys_statute_import_get_changed_statutes($law_id, $fromDateTime, $toDateTime);
  if ($changed_statutes_array !== FALSE) {
    foreach ($changed_statutes_array as $changed_statute_object) {
      // Available data in id: $changed_statute_object->id->lawId.
      // And ($changed_statute_object->id->locationId.
      // And $changed_statute_object->id->publishedDate.
      // Process a change to a statute.
      nys_statute_import_process_a_statute($changed_statute_object->id->lawId, $changed_statute_object->id->locationId, $run_type);

      usleep(NYS_STATUTE_IMPORT_SLEEP_MICROSECONDS);

    }

  }

}

/**
 * Function nys_statute_import_process_a_statute() Processes a single statute.
 *
 * Params:
 *   $law_id - The three letter law id.
 *   $law_location_id - The location id of the
 *                      starting node (leave blank for root).
 *   $run_type - IMPORT-ALL | UPDATE-ALL | UPDATE-RANGE | AUDIT-ALL |.
 */
function nys_statute_import_process_a_statute($law_id, $location_id, $run_type) {
  // Load the statute data from the api.
  $law_tree = nys_statute_import_get_law_tree_from_node($law_id, $location_id, '1');

  nys_statute_import_process_a_statute_object($law_tree, $run_type);

}

/**
 * Function nys_statute_import_process_a_statute_object().
 *
 * Sets fields in the $node with $law_doc / $law_tree.
 * Params:
 *   $law_tree - Statute Documents Object.
 *   $run_type - IMPORT-ALL  | UPDATE-ALL  | AUDIT-ALL  | UPDATE-RANGE |.
 *   $run_type - IMPORT-SOME | UPDATE-SOME | AUDIT-SOME |.
 *   $run_type - IMPORT-ONE  | UPDATE-ONE  | AUDIT-ONE  |.
 */
function nys_statute_import_process_a_statute_object($law_tree, $run_type, $parent_location_id = '', $prev_sibling_location_id = '', $prev_sibling_link_title = '', $next_sibling_location_id = '', $next_sibling_link_title = '') {
  // Load the statute detail data from the api.
  $law_id = $law_tree->documents->lawId;
  $location_id = $law_tree->documents->locationId;

  // Load the statute law_doc detail data from the api if -ONE run.
  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    $law_doc = nys_statute_import_get_law_doc($law_id, $location_id);
  }
  else {
    $law_doc = array();
  }

  // Try and load the matching node.
  // The node_load() is returning a warning.
  $old_err = error_reporting(0);
  $node = nys_statute_import_node_load_by_statute_document($law_tree);
  error_reporting($old_err);

  if ($node !== FALSE) {
    // A node was loaded.
    // Compare the $node values to the value in $law_tree and if -ONE $law_doc.
    $result = nys_statute_import_compare_values($node, $law_doc, $law_tree, $run_type, $parent_location_id, $prev_sibling_location_id, $prev_sibling_link_title, $next_sibling_location_id, $next_sibling_link_title);

    if ($result == 'MATCHED') {
      // The node already matches the $law_tree and if -ONE $law_doc.
      if ($run_type != 'UPDATE-ALL') {
        if ($run_type == 'AUDIT-ALL' || $run_type == 'AUDIT-SOME' || $run_type == 'AUDIT-ONE') {
          $doc_type = nys_statute_get_law_type($law_id);
          if ($law_tree->documents->docType != 'CHAPTER') {
            print "$law_id,$parent_location_id,$doc_type,$location_id,$law_id" . NYS_STATUTE_STATUTE_ID_DELIMITER . "$location_id,$node->nid,MATCHED\r\n";
          }
          else {
            print "$law_id,$parent_location_id,$doc_type,$location_id,$law_id,$node->nid,MATCHED\r\n";
          }

          return;
        }
        else {
          if ($law_tree->documents->docType != 'CHAPTER') {
            print ' MATCHED NODE = ' . $node->nid . ' | STATUTE_ID = ' . $law_id . NYS_STATUTE_STATUTE_ID_DELIMITER . $location_id . "\r\n";
          }
          else {
            // Its a Chapter.
            print ' MATCHED NODE = ' . $node->nid . ' | STATUTE_ID = ' . $law_id . "\r\n";
          }

        }

        // No further processing necessary for this statute.
        return;
      }

    }
    else {
      print $result . ' -  statuteId =  ' . $law_id . NYS_STATUTE_STATUTE_ID_DELIMITER . $location_id . "\r\n";

      if ($run_type == 'AUDIT-ALL' || $run_type == 'AUDIT-SOME' || $run_type == 'AUDIT-ONE') {
        $doc_type = nys_statute_get_law_type($law_id);
        print "$law_id,$parent_location_id,$doc_type,$location_id,$law_id" . NYS_STATUTE_STATUTE_ID_DELIMITER . "$location_id,$node->nid,NO-MATCH\r\n";

        return;
      }

    }

  }
  else {
    // No node was found.
    if ($run_type == 'AUDIT-ALL') {
      print "$law_id,$parent_location_id,$law_doc->docType,$location_id,$law_id" . NYS_STATUTE_STATUTE_ID_DELIMITER . "$location_id,,NO-NODE\r\n";
      return;
    }

    // No matching node was found Create a new node.
    $node = new StdClass();

    $node->type = 'statute';

    $node->status = 1;

    $node->language = LANGUAGE_NONE;

    node_object_prepare($node);

    $newly_created = TRUE;

  }

  // Set all the field values in the node.
  // With values from $law_tree and if -ONE $law_doc.
  nys_statute_import_set_values($node, $law_doc, $law_tree, $run_type, $parent_location_id, $prev_sibling_location_id, $prev_sibling_link_title, $next_sibling_location_id, $next_sibling_link_title);

  $node = node_submit($node);

  // Save the node.
  // The node_load() is returning a warning.
  $old_err = error_reporting(0);
  node_save($node);
  error_reporting($old_err);

  if (NYS_STATUTE_IMPORT_SET_PATH == TRUE && $newly_created == TRUE) {
    // Set the Alias path.
    if (empty($location_id) == FALSE && $law_tree->documents->docType != 'CHAPTER') {
      nys_statute_import_alias_save($node->nid, $law_id . NYS_STATUTE_STATUTE_ID_DELIMITER . $location_id);
    }
    else {
      nys_statute_import_alias_save($node->nid, $law_id);
    }
  }

  // Remove duplicte content aliases if they exist for this page.
  nys_statute_import_remove_duplicate_content_aliases($node->nid);

  // Report about it.
  if ($newly_created == TRUE) {
    if ($law_tree->documents->docType != 'CHAPTER') {
      print 'CREATED NODE = ' . $node->nid . ' | STATUTE_ID = ' . $law_id . NYS_STATUTE_STATUTE_ID_DELIMITER . $location_id . "\r\n";
    }
    else {
      // Its a chapter.
      print 'CREATED NODE = ' . $node->nid . ' | STATUTE_ID = ' . $law_id  . "\r\n";
    }
  }
  else {
    if ($law_tree->documents->docType != 'CHAPTER') {
      if ($law_tree->documents->docType != 'CHAPTER') {
        print 'UPDATED NODE = ' . $node->nid . ' | STATUTE_ID = ' . $law_id . NYS_STATUTE_STATUTE_ID_DELIMITER . $location_id . "\r\n";
      }
      else {
        // Its a chapter.
        print 'UPDATED NODE = ' . $node->nid . ' | STATUTE_ID = ' . $law_id . "\r\n";
      }
    }
  }

  return TRUE;

}

/**
 * Function nys_statute_import_set_values().
 *
 * Sets fields in the $node with $law_doc / $law_tree.
 * Params:
 *   $node - The new or loded node.
 *   $law_doc  - Law data including title, lawId,
 *               lawName, locationId, docType, docLevelId.
 *   $law_tree - More Law data including sequenceNo,
 *               fromSection, toSection, repealed.
 */
function nys_statute_import_set_values(&$node, $law_doc, $law_tree, $run_type, $parent_location_id, $prev_sibling_location_id, $prev_sibling_link_title, $next_sibling_location_id, $next_sibling_link_title) {
  $node->title = substr($law_tree->documents->title, 0, 255);

  $node->field_lawid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawId;

  $node->field_lawname[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawName;
  $node->field_locationid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->locationId;
  $node->field_doctype[LANGUAGE_NONE][0]['value'] = $law_tree->documents->docType;
  $node->field_doclevelid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->docLevelId;

  $node->field_activedate[LANGUAGE_NONE][0]['value'] = strtotime($law_tree->documents->activeDate);
  $node->field_text[LANGUAGE_NONE][0]['value'] = $law_tree->documents->text;

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    // Its a -ONE run so get the location Ids from $law_doc.
    if (is_array($law_doc->parentLocationIds) == TRUE && count($law_doc->parentLocationIds) > 0) {
      $index = 0;
      foreach ($law_doc->parentLocationIds as $parentLocationId) {
        $node->field_parentlocationids[LANGUAGE_NONE][$index]['value'] = $parentLocationId;
        $index++;
      }
    }
  }
  else {
    // Get the parentLocationIds by climbing down the tree.
    $node->field_parentlocationids = nys_statute_import_get_parentlocationids($law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $parent_location_id);
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    if (isset($law_doc->prevSibling->lawId) == TRUE) {
      $node->field_prevsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $law_doc->prevSibling->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_doc->prevSibling->locationId;
      $node->field_prevsibling[LANGUAGE_NONE][0]['title'] = substr($law_doc->prevSibling->docType . ' ' . $law_doc->prevSibling->docLevelId . ' - ' . $law_doc->prevSibling->title, 0, 255);
      $node->field_prevsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }

    if (isset($law_doc->nextSibling->lawId) == TRUE) {
      $node->field_nextsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $law_doc->nextSibling->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_doc->nextSibling->locationId;
      $node->field_nextsibling[LANGUAGE_NONE][0]['title'] = substr($law_doc->nextSibling->docType . ' ' . $law_doc->nextSibling->docLevelId . ' - ' . $law_doc->nextSibling->title, 0, 255);
      $node->field_nextsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }
  }

  elseif ($run_type == 'PARENT') {
    // Parent sibling links.
    $prev_sibling_info = nys_statute_import_get_sibling_law_info($law_tree->documents->lawId, 'PREVIOUS');
    if ($prev_sibling_info !== FALSE) {
      $node->field_prevsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $prev_sibling_info->lawId;
      $node->field_prevsibling[LANGUAGE_NONE][0]['title'] = $prev_sibling_info->name;
      $node->field_prevsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }

    $next_sibling_info = nys_statute_import_get_sibling_law_info($law_tree->documents->lawId, 'NEXT');
    if ($prev_sibling_info !== FALSE) {
      $node->field_nextsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $next_sibling_info->lawId;
      $node->field_nextsibling[LANGUAGE_NONE][0]['title'] = $next_sibling_info->name;
      $node->field_nextsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }

  }
  elseif ($run_type == 'GRAND-PARENT') {
    // Grandparent links dont have a NYS_STATUTE_STATUTE_ID_DELIMITER.
    if (empty($prev_sibling_location_id) == FALSE && empty($prev_sibling_link_title) == FALSE) {
      $node->field_prevsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $prev_sibling_location_id;
      $node->field_prevsibling[LANGUAGE_NONE][0]['title'] = $prev_sibling_link_title;
      $node->field_prevsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }

    if (empty($next_sibling_location_id) == FALSE && empty($next_sibling_link_title) == FALSE) {
      $node->field_nextsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $next_sibling_location_id;
      $node->field_nextsibling[LANGUAGE_NONE][0]['title'] = $next_sibling_link_title;
      $node->field_nextsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }
  }
  else {
    // For the -ALL AND -SOME run types info from the arguments if available.
    if (empty($prev_sibling_location_id) == FALSE && empty($prev_sibling_link_title) == FALSE) {
      $node->field_prevsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $prev_sibling_location_id;
      $node->field_prevsibling[LANGUAGE_NONE][0]['title'] = $prev_sibling_link_title;
      $node->field_prevsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }

    if (empty($next_sibling_location_id) == FALSE && empty($next_sibling_link_title) == FALSE) {
      $node->field_nextsibling[LANGUAGE_NONE][0]['url'] = NYS_STATUTE_IMPORT_BASE_PATH . $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $next_sibling_location_id;
      $node->field_nextsibling[LANGUAGE_NONE][0]['title'] = $next_sibling_link_title;
      $node->field_nextsibling[LANGUAGE_NONE][0]['attributes'] = array();
    }
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    $node->field_lawtype[LANGUAGE_NONE][0]['value'] = $law_tree->info->lawType;
  }
  else {
    $node->field_lawtype[LANGUAGE_NONE][0]['value'] = nys_statute_get_law_type($law_tree->documents->lawId);
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    $node->field_chapter[LANGUAGE_NONE][0]['value'] = $law_tree->info->chapter;
  }
  else {
    $node->field_chapter[LANGUAGE_NONE][0]['value'] = nys_statute_get_law_chapter($law_tree->documents->lawId);
  }

  $node->field_sequenceno[LANGUAGE_NONE][0]['value'] = $law_tree->documents->sequenceNo;

  if (empty($law_tree->documents->repealedDate) == FALSE) {
    $node->field_repealeddate[LANGUAGE_NONE][0]['value'] = strtotime($law_tree->documents->repealedDate);
  }

  $node->field_fromsection[LANGUAGE_NONE][0]['value'] = $law_tree->documents->fromSection;
  $node->field_tosection[LANGUAGE_NONE][0]['value'] = $law_tree->documents->toSection;

  if (empty($law_tree->documents->repealed) == TRUE) {
    $node->field_repealed[LANGUAGE_NONE][0]['value'] = 0;
  }
  else {
    if (strcasecmp($law_tree->documents->repealed, 'TRUE') == 0) {
      $node->field_repealed[LANGUAGE_NONE][0]['value'] = 1;
    }
    elseif (strcasecmp($law_tree->documents->repealed, 'FALSE') == 0) {
      $node->field_repealed[LANGUAGE_NONE][0]['value'] = 0;
    }
    else {
      $node->field_repealed[LANGUAGE_NONE][0]['value'] = 0;
    }

  }



  if ($run_type == 'PARENT' && empty($law_tree->documents->lawId) == FALSE) {
    $node->field_statuteid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawId;
  }
  elseif (empty($law_tree->documents->lawId) == FALSE && empty($law_tree->documents->locationId) == FALSE) {
    $node->field_statuteid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_tree->documents->locationId;
  }
  elseif (empty($law_tree->documents->lawId) == FALSE && empty($law_tree->documents->locationId) == TRUE) {
    $node->field_statuteid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawId;
  }

  if ($law_tree->documents->docType == 'CHAPTER') {
    $node->field_statuteid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawId;
  }

  if (NYS_STATUTE_IMPORT_SET_SUGGESTED_PATH == TRUE) {
    $node->path['alias'] = NYS_STATUTE_IMPORT_BASE_PATH . $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_tree->documents->locationId;
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    // There is no tree so get the parent from it.
    if (empty($law_doc->parentLocationIds) == FALSE) {
      $node->field_parentstatuteid[LANGUAGE_NONE][0]['value'] = $law_doc->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . end($law_doc->parentLocationIds);
    }
  }
  elseif ($run_type == 'PARENT') {
    // For PARENT use the law_type for the statuteID.
    $node->field_parentstatuteid[LANGUAGE_NONE][0]['value'] = nys_statute_get_law_type($law_tree->documents->lawId);
  }
  elseif ($run_type == 'GRAND-PARENT') {
    // For GRAND-PARENT use the hard coded great grand parent statuteID.
    $node->field_parentstatuteid[LANGUAGE_NONE][0]['value'] = NYS_STATUTE_STATUTE_GREAT_GRAND_PARENT_PATH;
  }
  else {
    // Use the parent_id supplied in the $parent_location_id argument.
    if (empty($parent_location_id) == FALSE) {
      if ($law_tree->documents->docType == 'CHAPTER') {
        $node->field_parentstatuteid[LANGUAGE_NONE][0]['value'] = $parent_location_id;
      }
      else {

        if ($law_tree->documents->lawId != $parent_location_id) {
          $node->field_parentstatuteid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $parent_location_id;
        }
        else {
          $node->field_parentstatuteid[LANGUAGE_NONE][0]['value'] = $law_tree->documents->lawId;
        }

      }
    }
  }
}

/**
 * Function nys_statute_import_compare_values().
 *
 * Compares the $node to the $law_doc, $law_tree.
 * Params:
 *   $node - The new or loded node.
 *   $law_doc  - Law data including title, lawId,
 *               lawName, locationId, docType, docLevelId.
 *   $law_tree - More Law data including sequenceNo,
 *               fromSection, toSection, repealed.
 */
function nys_statute_import_compare_values(&$node, $law_doc, $law_tree, $run_type, $parent_location_id, $prev_sibling_location_id, $prev_sibling_link_title, $next_sibling_location_id, $next_sibling_link_title) {
  if (strcmp($node->title, $law_tree->documents->title) != 0) {
    return 'title MISMATCH';
  }

  if (strcmp($node->field_lawid[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawId) != 0) {
    return 'lawId MISMATCH';
  }

  if (strcmp($node->field_lawname[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawName) != 0) {
    return 'lawName MISMATCH';
  }

  if (strcmp($node->field_locationid[LANGUAGE_NONE][0]['value'], $law_tree->documents->locationId) != 0) {
    return 'locationId MISMATCH';
  }

  if (strcmp($node->field_doctype[LANGUAGE_NONE][0]['value'], $law_tree->documents->docType) != 0) {
    return 'docType MISMATCH';
  }

  if (strcmp($node->field_doclevelid[LANGUAGE_NONE][0]['value'], $law_tree->documents->docLevelId) != 0) {
    return 'docLevelId MISMATCH';
  }

  $field_activedate = $node->field_activedate[LANGUAGE_NONE][0]['value'];
  $activeDate = $law_tree->documents->activeDate;
  if ($field_activedate == $activeDate) {
    return 'activeDate MISMATCH';
  }

  if (strcmp($node->field_text[LANGUAGE_NONE][0]['value'], $law_tree->documents->text) != 0) {
    return 'title MISMATCH';
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    if (is_array($law_doc->parentLocationIds) == TRUE && count($law_doc->parentLocationIds) > 0) {
      $index = 0;
      foreach ($law_doc->parentLocationIds as $parentLocationId) {
        if (strcmp($node->field_parentlocationids[LANGUAGE_NONE][$index]['value'], $parentLocationId) != 0) {
          return 'parentLocationId MISMATCH';
        }

        $index++;
      }

    }
  }
  else {
    $parentlocationid_array = nys_statute_import_get_parentlocationids($law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $parent_location_id);
    if (empty($parentlocationid_array) == FALSE) {
      // The looked up data is populated.
      if (empty($node->field_parentlocationids) == FALSE) {
        // The existing field is populated.
        if (empty(array_diff($node->field_parentlocationids,
                       nys_statute_import_get_parentlocationids($law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $parent_location_id))
           ) == FALSE) {
          // The data is different.
          return 'parentLocationId MISMATCH';
        }
      }
    }
    else {
      // The looked up data was empty.
      if (empty($node->field_parentlocationids[LANGUAGE_NONE][$index]['value']) == FALSE) {
        // The field is not empty.
        return 'parentLocationId MISMATCH - EMPTY DATA';
      }
    }
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    // For the -ONE run types the info coming in is from the $law_doc structure.
    if (isset($law_doc->prevSibling->lawId) == TRUE) {
      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $law_doc->prevSibling->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_doc->prevSibling->locationId) != 0) {
        return 'prevSibling - url MISMATCH';
      }

      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['title'], $law_doc->prevSibling->docType . ' ' . $law_doc->prevSibling->docLevelId . ' - ' . $law_doc->prevSibling->title) != 0) {
        return 'prevSibling - title  MISMATCH';
      }
    }

    if (isset($law_doc->nextSibling->lawId) == TRUE) {

      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $law_doc->nextSibling->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_doc->nextSibling->locationId) != 0) {
        return 'nextSibling - url MISMATCH';
      }

      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['title'], $law_doc->nextSibling->docType . ' ' . $law_doc->nextSibling->docLevelId . ' - ' . $law_doc->nextSibling->title) != 0) {
        return 'nextSibling - title MISMATCH';
      }
    }
  }
  elseif ($run_type == 'PARENT') {
    // Parent sibling links.
    $prev_sibling_info = nys_statute_import_get_sibling_law_info($law_tree->documents->lawId, 'PREVIOUS');
    if ($prev_sibling_info !== FALSE) {
      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $prev_sibling_info->lawId) != 0) {
        return 'prevSibling - url MISMATCH';
      }
      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['title'], $prev_sibling_info->name) != 0) {
        return 'prevSibling - title  MISMATCH';
      }
    }

    $next_sibling_info = nys_statute_import_get_sibling_law_info($law_tree->documents->lawId, 'NEXT');
    if ($prev_sibling_info !== FALSE) {
      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $next_sibling_info->lawId) != 0) {
        return 'nextSibling - url MISMATCH';
      }
      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['title'], $next_sibling_info->name) != 0) {
        return 'nextSibling - title MISMATCH';
      }
    }
  }
  elseif ($run_type == 'GRAND-PARENT') {
    // Grandparent links dont have a NYS_STATUTE_STATUTE_ID_DELIMITER.
    if (empty($prev_sibling_location_id) == FALSE && empty($prev_sibling_link_title) == FALSE) {
      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $prev_sibling_location_id) != 0) {
        return 'prevSibling - url MISMATCH';
      }
      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['title'], $prev_sibling_link_title) != 0) {
        return 'prevSibling - title  MISMATCH';
      }
    }

    if (empty($next_sibling_location_id) == FALSE && empty($next_sibling_link_title) == FALSE) {
      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $next_sibling_location_id) != 0) {
        return 'nextSibling - url MISMATCH';
      }
      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['title'], $next_sibling_link_title) != 0) {
        return 'nextSibling - title MISMATCH';
      }
    }
  }
  else {
    // For the -ALL AND -SOME run types get the info from arguments.
    if (empty($prev_sibling_location_id) == FALSE && empty($prev_sibling_link_title) == FALSE) {
      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $prev_sibling_location_id) != 0) {
        return 'prevSibling - url MISMATCH';
      }

      if (strcmp($node->field_prevsibling[LANGUAGE_NONE][0]['title'], $prev_sibling_link_title) != 0) {
        return 'prevSibling - title  MISMATCH';
      }
    }

    if (empty($next_sibling_location_id) == FALSE && empty($next_sibling_link_title) == FALSE) {
      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['url'], NYS_STATUTE_IMPORT_BASE_PATH . $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $next_sibling_location_id) != 0) {
        return 'nextSibling - url MISMATCH';
      }

      if (strcmp($node->field_nextsibling[LANGUAGE_NONE][0]['title'], $next_sibling_link_title) != 0) {
        return 'nextSibling - title MISMATCH';
      }
    }
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    if (strcmp($node->field_lawtype[LANGUAGE_NONE][0]['value'], $law_tree->info->lawType) != 0) {
      return 'lawType MISMATCH';
    }
  }
  else {
    if (strcmp($node->field_lawtype[LANGUAGE_NONE][0]['value'], nys_statute_get_law_type($law_tree->documents->lawId)) != 0) {
      return 'lawType MISMATCH';
    }
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    if (strcmp($node->field_chapter[LANGUAGE_NONE][0]['value'], $law_tree->info->chapter) != 0) {
      return 'chapter MISMATCH';
    }
  }
  else {
    if (strcmp($node->field_chapter[LANGUAGE_NONE][0]['value'], nys_statute_get_law_chapter($law_tree->documents->lawId)) != 0) {
      return 'chapter MISMATCH';
    }
  }

  if (strcmp($node->field_sequenceno[LANGUAGE_NONE][0]['value'], $law_tree->documents->sequenceNo) != 0) {
    return 'sequenceNo MISMATCH';
  }

  if (empty($law_tree->documents->repealedDate) == FALSE) {
    $field_repealeddate = $node->field_repealeddate[LANGUAGE_NONE][0]['value'];
    $repealedDate = strtotime($law_tree->documents->repealedDate);
    if ($field_repealeddate != $repealedDate) {
      return 'repealedDate MISMATCH';
    }

  }

  if (strcmp($node->field_fromsection[LANGUAGE_NONE][0]['value'], $law_tree->documents->fromSection) != 0) {
    return 'fromSection MISMATCH';
  }

  if (strcmp($node->field_tosection[LANGUAGE_NONE][0]['value'], $law_tree->documents->toSection) != 0) {
    return 'toSection MISMATCH';
  }

  // Repealed boolean.
  if (empty($law_tree->documents->repealed) == TRUE) {
    $field_repealed = $node->field_repealed[LANGUAGE_NONE][0]['value'];
    if ($field_repealed != 0) {
      return 'repealed MISMATCH';
    }
  }
  else {
    if (strcasecmp($law_tree->documents->repealed, 'TRUE') == 0) {
      $field_repealed = $node->field_repealed[LANGUAGE_NONE][0]['value'];
      if ($field_repealed != 1) {
        return 'repealed MISMATCH';
      }
    }
    elseif (strcasecmp($law_tree->documents->repealed, 'FALSE') == 0) {
      $field_repealed = $node->field_repealed[LANGUAGE_NONE][0]['value'];
      if ($field_repealed != 0) {
        return 'repealed MISMATCH';
      }

    }
    else {
      $field_repealed = $node->field_repealed[LANGUAGE_NONE][0]['value'];
      if ($field_repealed != 0) {
        return 'repealed MISMATCH';
      }
    }
  }

  if (empty($law_tree->documents->lawId) == FALSE && empty($law_tree->documents->locationId) == FALSE) {
    if ($law_tree->documents->docType != 'CHAPTER') {
      if (strcmp($node->field_statuteid[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_tree->documents->locationId) != 0) {
        return 'field_statuteid MISMATCH';
      }
    }
    else {
      // Its a Parent Chapter statute.
      if (strcmp($node->field_statuteid[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawId) != 0) {
        return 'field_statuteid MISMATCH';
      }
    }
  }
  elseif (empty($law_tree->documents->lawId) == FALSE && empty($law_tree->documents->locationId) == TRUE) {
    if (strcmp($node->field_statuteid[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawId) != 0) {
      return 'field_statuteid MISMATCH';
    }
  }

  if ($law_tree->documents->docType == 'CHAPTER') {
    if (strcmp($node->field_statuteid[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawId) != 0) {
      return 'field_statuteid MISMATCH';
    }
  }

  if (NYS_STATUTE_IMPORT_SET_SUGGESTED_PATH == TRUE) {
    // Check suggested node path.
    if (strcmp($node->path['alias'], NYS_STATUTE_IMPORT_BASE_PATH . $law_doc->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $law_doc->locationId) != 0) {
      return 'path MISMATCH';
    }
  }

  if ($run_type == 'IMPORT-ONE' || $run_type == 'UPDATE-ONE' || $run_type == 'AUDIT-ONE') {
    // There is no tree so get the parent from it.
    if (strcmp($node->field_parentstatuteid[LANGUAGE_NONE][0]['value'], $law_doc->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . end($law_doc->parentLocationIds)) != 0 &&
        strcmp($law_doc->docType, 'CHAPTER') != 0) {
      return 'field_parentstatuteid MISMATCH';
    }
  }
  elseif ($run_type == 'PARENT') {
    // For PARENT use the law_type for the statuteID.
    if (strcmp($node->field_parentstatuteid[LANGUAGE_NONE][0]['value'], nys_statute_get_law_type($law_tree->documents->lawId)) != 0 &&
        strcmp($law_doc->docType, 'CHAPTER') != 0) {
      return 'field_parentstatuteid MISMATCH';
    }
  }
  elseif ($run_type == 'GRAND-PARENT') {
    // For GRAND-PARENT use the hard coded great grand parent statuteID.
    if (strcmp($node->field_parentstatuteid[LANGUAGE_NONE][0]['value'], NYS_STATUTE_STATUTE_GREAT_GRAND_PARENT_PATH) != 0 &&
        strcmp($law_doc->docType, 'CHAPTER') != 0) {
      return 'field_parentstatuteid MISMATCH';
    }
  }
  else {
    if (empty($parent_location_id) == FALSE) {
      if ($law_tree->documents->docType == 'CHAPTER') {
        if (strcmp($node->field_parentstatuteid[LANGUAGE_NONE][0]['value'], $parent_location_id) != 0) {
          return 'field_parentstatuteid MISMATCH';
        }
      }
      else {

        if ($law_tree->documents->lawId != $parent_location_id) {

          if (strcmp($node->field_parentstatuteid[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $parent_location_id) != 0) {
            return 'field_parentstatuteid MISMATCH';
          }

        }
        else {
          if (strcmp($node->field_parentstatuteid[LANGUAGE_NONE][0]['value'], $law_tree->documents->lawId) != 0) {
            return 'field_parentstatuteid MISMATCH';
          }
        }

      }
    }
  }

  return 'MATCHED';

}

/**
 * Function nys_statute_import_node_load_by_statute_id().
 *
 * Returns a node given a unique $statuteId.
 * Params:
 *   $statuteId - A Unique statuteId like ABP-210.
 */
function nys_statute_import_node_load_by_statute_id($statuteId) {
  $result = db_query("SELECT `entity_id` FROM `field_data_field_statuteid` WHERE field_statuteid_value = :statuteId",
                             array(':statuteId' => $statuteId));

  if ($result->num_rows > 1) {
    print "MORE THAN ONE $statuteId FOUND\r\n";
  }

  foreach ($result as $item) {
    $entity_id = $item->entity_id;
  }

  if (empty($entity_id) == FALSE && is_numeric($entity_id) == TRUE) {
    $node = node_load($entity_id);
    return node_load($entity_id);
  }

  return FALSE;

}

/**
 * Function nys_statute_import_node_load().
 *
 * Returns a $lawId and a $locationId.
 * Params:
 *   $law_id - The three letter law id
 *   $law_location_id - The location id of.
 *                      the starting node (leave blank for root).
 */
function nys_statute_import_node_load($lawId, $locationId) {
  $result = db_query("SELECT field_data_field_lawid.entity_id FROM field_data_field_lawid, field_data_field_locationid WHERE
                       field_data_field_lawid.entity_id = field_data_field_locationid.entity_id AND
                       field_data_field_lawid.bundle = field_data_field_locationid.bundle AND
                       field_lawid_value = :lawid AND
                       field_locationid_value = :locationId",
                      array(':lawid' => $lawId, ':locationId' => $locationId));

  if ($result->num_rows > 1) {
    print "MORE THAN ONE $statuteId FOUND\r\n";
  }

  foreach ($result as $item) {
    $entity_id = $item->entity_id;
  }

  if (empty($entity_id) == FALSE && is_numeric($entity_id) == TRUE) {
    $node = node_load($entity_id);
    return node_load($entity_id);
  }

  return FALSE;

}

/**
 * Function statute_document_obj().
 *
 * Returns a node given a unique $statute_document_obj.
 * Params:
 *   $statute_document_obj - the document object from a law_tree.
 */
function nys_statute_import_node_load_by_statute_document($statute_document_obj) {
  if ($statute_document_obj != NULL && is_object($statute_document_obj) == TRUE && property_exists($statute_document_obj, 'documents') == TRUE) {

    $lawId = $statute_document_obj->documents->lawId;
    $locationId = $statute_document_obj->documents->locationId;

    if (empty($lawId) == FALSE && empty($locationId) == FALSE) {
      if ( $statute_document_obj->documents->docType != 'CHAPTER') {
        $statuteId = $lawId . NYS_STATUTE_STATUTE_ID_DELIMITER . $locationId;
      }
      else {
        // Its a chapter just ise the lawID.
        $statuteId = $lawId;
      }

    }
    elseif (empty($lawId) == FALSE && empty($locationId) == TRUE) {
      $statuteId = $lawId;
    }

    $result = db_query("SELECT `entity_id` FROM `field_data_field_statuteid` WHERE field_statuteid_value = :statuteId",
                             array(':statuteId' => $statuteId));

    if ($result->num_rows > 1) {
      print "MORE THAN ONE $statuteId FOUND\r\n";
    }

    foreach ($result as $item) {
      $entity_id = $item->entity_id;
    }

    if (empty($entity_id) == FALSE && is_numeric($entity_id) == TRUE) {
      return node_load($entity_id);
    }

    return FALSE;

  }

  return FALSE;

}

/**
 * Function nys_statute_import_node_count_by_statute_id().
 *
 * Returns number of nodes with the given $statuteId.
 * Params:
 *   $statuteId - A Unique statuteId like ABP-210.
 */
function nys_statute_import_node_count_by_statute_id($statuteId) {
  $node_count = db_query("SELECT count(*) FROM `field_data_field_statuteid` WHERE field_statuteid_value = :statuteId", array("statuteId" => $statuteId))->fetchField();
  return $node_count;
}

/**
 * Function nys_statute_import_node_count().
 *
 * Returns number of nodes with the given $lawId and $locationId.
 * Should always be 1.
 * Params:
 *   $law_id - The three letter law id.
 *   $law_location_id - The location id of
 *                      the starting node (leave blank for root).
 */
function nys_statute_import_node_count($lawId, $locationId) {
  $node_count = db_query("SELECT count(*) FROM field_data_field_lawid, field_data_field_locationid WHERE
                       field_data_field_lawid.entity_id = field_data_field_locationid.entity_id AND
                       field_data_field_lawid.bundle = field_data_field_locationid.bundle AND
                       field_lawid_value = :lawid AND
                       field_locationid_value = :locationId",
                    array(':lawid' => $lawId, ':locationId' => $locationId))->fetchField();

  return $node_count;
}

/**
 * Returns a json node containing the statutes that have changed.
 *
 * Params:
 *   $arg1 - If empty its going to be changed since the last modified date
 *   $fromDateTime - If empty the last run date is used.
 *                   If supplied its the from date time.
 *   $toDateTime   - If empty the current date time is used.
 *                   If supplied its the from date time.
 *   Note . The fromDateTime and toDateTime should
 *          be formatted as the ISO Date Time format.
 *          December 10, 2014, 1:30:02 PM should be
 *          inputted as 2014-12-10T13:30:02.
 * Returns:
 *   An array of objects. Each one has an id member
 *   with lawId, locationId, publishedDate
 *   object->id->lawId,  object->id->locationId,
 *   object->id->publishedDate.
 */
function nys_statute_import_get_changed_statutes($law_id, $fromDateTime = '', $toDateTime = '') {

  if (empty($fromDateTime) == TRUE) {
    $fromDateTime_value = variable_get("statute_import_last_update", $run_start_time);
  }
  else {
    $fromDateTime_value = $fromDateTime;
  }

  if (empty($toDateTime) == TRUE) {
    $toDateTime_value = date('Y-m-d\TH:i:s', time());
  }
  else {
    $toDateTime_value = $toDateTime;
  }

  $url = get_base_openleg_law_url() . "/{$law_id}/updates/{$fromDateTime_value}/{$toDateTime_value}?limit=1000&view=info" . nys_statute_get_openleg_key(FALSE);

  $ctx1 = stream_context_create(array(
    'http' => array(
      'timeout' => 240,
    ),
  )
  );

  $changed_laws_json = file_get_contents($url, 0, $ctx1);
  $changed_laws = json_decode($changed_laws_json);
  if ($changed_laws != NULL && $changed_laws !== FALSE) {
    if ($changed_laws->responseType == "update-digest list") {
      if ($changed_laws->total <= $changed_laws->limit) {
        return $changed_laws->result->items;
      }
      else {
        print "THE REQUEST RETURNED THE MAXIMUM-LIMIT NUMBER OF RESULTS. THERE ARE LIKELY MORE RESULTS AVAILABLE.\r\n";
        return $changed_laws->result->items;
      }
    }

    if ($changed_laws->responseType == "empty list") {
      return FALSE;
    }

  }

  return FALSE;

}

/**
 * Retrieves the law listings from open leg and caches them.
 */
function nys_statute_import_get_law_listings() {
  $CACHE_KEY = 'nys_statute_import_law_listings';
  $law_listings = cache_get($CACHE_KEY);
  if (!$law_listings) {

    $ctx1 = stream_context_create(array(
      'http' => array(
        'timeout' => 240,
      ),
    )
    );

    $base_result = file_get_contents(nys_statute_import_get_base_openleg_law_url() . nys_statute_get_openleg_key(TRUE), 0, $ctx1);
    if ($base_result === FALSE) {
      $base_result = file_get_contents(nys_statute_import_get_base_openleg_law_url() . nys_statute_get_openleg_key(TRUE), 0, $ctx1);
    }
    if ($base_result === FALSE) {
      $base_result = file_get_contents(nys_statute_import_get_base_openleg_law_url() . nys_statute_get_openleg_key(TRUE), 0, $ctx1);
    }
    if ($base_result === FALSE) {
      return FALSE;
    }

    $json_response = json_decode($base_result);
    $law_listings = array();
    foreach ($json_response->result->items as $k => &$v) {
      $law_listings[$v->lawId] = $v;
    }

    cache_set($CACHE_KEY, $law_listings);
  }
  else {
    $law_listings = $law_listings->data;
  }
  return $law_listings;
}

/**
 * Returns a json node containing.
 *
 * The actual text body of the given law document.
 *
 * Params:
 *   $law_id - The three letter law id
 *   $law_loc_id - The location id of the law document
 *                 (obtained from the law tree result).
 */
function nys_statute_import_get_law_doc($law_id, $law_loc_id) {
  $url = nys_statute_import_get_base_openleg_law_url() . "/{$law_id}/{$law_loc_id}/" . nys_statute_get_openleg_key(TRUE);

  $ctx1 = stream_context_create(array(
    'http' => array(
      'timeout' => 240,
    ),
  )
  );

  $contents = file_get_contents($url, 0, $ctx1);
  if ($contents === FALSE) {
    $contents = file_get_contents($url, 0, $ctx1);
  }
  if ($contents === FALSE) {
    $contents = file_get_contents($url, 0, $ctx1);
  }
  if ($contents === FALSE) {
    return FALSE;
  }
  $law_doc = json_decode($contents);
  // Clean up law doc text.
  $law_doc->result->text = html_format_raw_law_text($law_doc->result->title, $law_doc->result->text);
  return $law_doc->result;
}

/**
 * Returns a json node containing the law hierarchy using the given parameters.
 *
 * Params:
 *   $law_id - The three letter law id
 *   $law_location_id - The location id of
 *                      the starting node (leave blank for root)
 *   $depth - The depth of the children nodes
 *            (set to 1 to view only immediate children law docs).
 */
function nys_statute_import_get_law_tree_from_node($law_id, $law_location_id, $depth) {
  $url = nys_statute_import_get_base_openleg_law_url() . "/{$law_id}/?fromLocation=${law_location_id}&depth={$depth}&full=true" . nys_statute_get_openleg_key(FALSE);

  $ctx1 = stream_context_create(array(
    'http' => array(
      'timeout' => 240,
    ),
  )
  );

  $base_result = file_get_contents($url, 0, $ctx1);
  if ($base_result === FALSE) {
    $base_result = file_get_contents($url, 0, $ctx1);
  }
  if ($base_result === FALSE) {
    $base_result = file_get_contents($url, 0, $ctx1);
  }
  if ($base_result === FALSE) {
    return FALSE;
  }
  $law_tree = json_decode($base_result);
  return $law_tree->result;
}

/**
 * Returns a string containing the base openleg laws api url.
 */
function nys_statute_import_get_base_openleg_law_url() {
  $ol_base_url   = variable_get("openleg_base_url");
  $base_url = $ol_base_url . '/api/3/laws';
  return $base_url;
}


/**
 * Updates the nodes alias if needed.
 *
 * Much simpler than drupal_lookup_path() and path_save()
 */
function nys_statute_import_alias_save($nid, $statute_id) {
  // Specify source.
  $source = "node/$nid";
  // Create desired path.
  $path = ltrim(NYS_STATUTE_IMPORT_BASE_PATH . $statute_id, '/');

  $alias_count = db_query("SELECT COUNT(*) FROM `url_alias` WHERE `alias` = :alias", array(":alias" => $path))->fetchField();

  if ($alias_count == 0) {
    $result = db_query("INSERT INTO `url_alias` (`pid`, `source`, `alias`, `language`) VALUES (:pid, :source, :alias, :language)",
                       array(
                         ':pid' => NULL,
                         ':source' => $source,
                         ':alias' => $path,
                         ':language' => LANGUAGE_NONE,
                       )
                       );

  }

}

/**
 * This function removes duplicate content aliases.
 *
 * There is an issue with duplicate aliases being added on update.
 * This function removes any duplicate content aliases,
 * that exist or added by an update.
 */
function nys_statute_import_remove_duplicate_content_aliases($nid) {
  $source = "node/$nid";
  $found = 0;

  $result = db_query("SELECT * FROM `url_alias` WHERE `source` = :source ORDER BY `pid`", array(":source" => $source));
  foreach ($result as $record) {
    if (strncmp($record->alias, 'content/', 8) == 0) {
      $found++;

      if ($found > 1) {
        db_query("DELETE FROM `url_alias` WHERE `pid` = :pid", array(":pid" => $record->pid));
      }
    }
  }

  return $found - 1;

}

/**
 * Returns an array of parents ready for attachment.
 *
 * Argument $parent_location_id - The parents location_id.
 */
function nys_statute_import_get_parentlocationids($parent_statute_id) {
  $index = 0;
  $data_array = array();

  // Climb the food chain and build array.
  do {
    $index++;
    $old_err = error_reporting(0);
    $parent_node = nys_statute_node_load_by_statute_id($parent_statute_id);
    error_reporting($old_err);
    if ($parent_node !== FALSE) {
      $parent_statute_id = $parent_node->field_parentstatuteid['und'][0]['value'];

      $data_array[] = $parent_node->field_locationid['und'][0]['value'];

    }
  } while (empty($parent_node->field_parentstatuteid['und'][0]['value']) == FALSE && $index < 20);

  $sorted_data_array = array_reverse($data_array);

  foreach ($sorted_data_array as $index => $ancestor) {
    // Populate the output array.
    $output_array[LANGUAGE_NONE][$index] = array(
      'value' => $ancestor,
      'format' => '',
      'safe_value' => $ancestor,
    );
  }

  return $output_array;
}

/**
 * Creates or updates ancestor nodes if necessary.
 *
 * Argument:
 *   $run_type - type of run.
 */
function nys_statute_import_process_ancestors($run_type) {
  // Create The Great Grand Parent - All statutes are ancestors of this node.
  $law_id = NYS_STATUTE_STATUTE_GREAT_GRAND_PARENT_PATH;
  $name = 'Laws of New York State';
  $law_type = NYS_STATUTE_STATUTE_GREAT_GRAND_PARENT_PATH;
  $chapter = NYS_STATUTE_STATUTE_GREAT_GRAND_PARENT_PATH;
  $parent_location_id = '';
  $active_date = '1970-01-01';
  create_ancestor_node('GREAT-GRAND-PARENT', $law_id, $name, $law_type, $chapter, $parent_location_id, $active_date);

  // Create grand parents.
  $law_types_array = nys_statute_import_get_law_types();
  foreach ($law_types_array as $index => $law_type) {

    // Override any captions.
    switch ($law_type) {
      case "COURTACTS":
        $name = 'Court Acts';
        break;

      default:
        $name = ucfirst(strtolower($law_type));
    }

    $law_id = $law_type;
    $law_type = $law_type;
    $chapter = $law_type;
    $parent_location_id = NYS_STATUTE_STATUTE_GREAT_GRAND_PARENT_PATH;
    $active_date = '1970-01-01';
    create_ancestor_node('GRAND-PARENT', $law_id, $name, $law_type, $chapter, $parent_location_id, $active_date);

  }

}

/**
 * Get unique list of law types.
 *
 * Sterilized out Underscores if they exist.
 */
function nys_statute_import_get_law_types() {
  $output_array = array();

  $law_listings = nys_statute_import_get_law_listings();

  foreach ($law_listings as $law_listing) {
    if (in_array(str_replace('_', '', $law_listing->lawType), $output_array) == FALSE) {
      $output_array[] = str_replace('_', '', $law_listing->lawType);
    }
  }

  return $output_array;

}

/**
 * Gets the law_type of a grandparents siblings.
 *
 * Params:
 *   $law_type - UNCONSILIDATED etc
 *   $direction - PREVIOUS - NEXT.
 */
function nys_statute_import_get_sibling_law_type($law_type, $direction) {
  $law_types = nys_statute_import_get_law_types();
  $last_element = count($law_types) - 1;

  $index = array_search($law_type, $law_types);
  if ($index !== FALSE) {
    if ($direction == 'PREVIOUS') {
      if (($index - 1) >= 0) {
        return $law_types[$index - 1];
      }
      elseif ($index == 0) {
        return $law_types[$last_element];
      }
    }
    elseif ($direction == 'NEXT') {
      if (($index + 1) <= $last_element) {
        return $law_types[$index + 1];
      }
      elseif ($index == $last_element) {
        return $law_types[0];
      }
    }
  }
}

/**
 * Creates generic nodes if they do not exist already for ancestors.
 *
 * Params:
 *   $run_type     'ANCESTORS' 'GRAND-PARENT' | 'GREAT-GRAND-PARENT'
 *   $law_id
 *    $name
 *    $law_type
 *    $chapter
 *    $active_date.
 */
function create_ancestor_node($run_type, $law_id, $name, $law_type, $chapter, $parent_location_id = '', $active_date = '1970-01-01', $text = NULL) {

  // Create a statute object.
  $statute_ancestor_document_obj_wrapper = new StdClass();
  $statute_ancestor_document_obj_wrapper->documents = new StdClass();
  $statute_ancestor_document_obj_wrapper->documents->lawId = $law_id;
  $statute_ancestor_document_obj_wrapper->documents->lawName = $name;
  $statute_ancestor_document_obj_wrapper->documents->locationId = '';
  $statute_ancestor_document_obj_wrapper->documents->title = $name;
  $statute_ancestor_document_obj_wrapper->documents->docType = 'SECTION';
  $statute_ancestor_document_obj_wrapper->documents->docLevelId = NULL;
  $statute_ancestor_document_obj_wrapper->documents->activeDate = $active_date;
  $statute_ancestor_document_obj_wrapper->documents->sequenceNo = NULL;
  $statute_ancestor_document_obj_wrapper->documents->repealedDate = $active_date;
  $statute_ancestor_document_obj_wrapper->documents->fromSection = NULL;
  $statute_ancestor_document_obj_wrapper->documents->toSection = NULL;
  $statute_ancestor_document_obj_wrapper->documents->text = $text;
  $statute_ancestor_document_obj_wrapper->documents->documents = new StdClass();
  $statute_ancestor_document_obj_wrapper->documents->documents->items = array();
  $statute_ancestor_document_obj_wrapper->documents->documents->size = 0;
  $statute_ancestor_document_obj_wrapper->documents->repealed = NULL;

  // A $run_type set by argument.
  // None of the grandparents or the great grandparent have a locationID.
  // The $parent_location_id is an argument.
  // Great grand father was an only child.
  if ($run_type == 'GREAT-GRAND-PARENT') {
    // Great grand father was an only child.
    $prev_sibling_location_id = '';
    $prev_sibling_link_title = '';
    $next_sibling_location_id = '';
    $next_sibling_link_title = '';
  }
  elseif ($run_type == 'GRAND-PARENT') {
    // Grand fathers siblings come from a 'PREVIOUS' 'NEXT' function.
    $prev_sibling_location_id = nys_statute_import_get_sibling_law_type($law_type, 'PREVIOUS');
    $prev_sibling_link_title = ucfirst(strtolower(nys_statute_import_get_sibling_law_type($law_type, 'PREVIOUS')));
    $next_sibling_location_id = nys_statute_import_get_sibling_law_type($law_type, 'NEXT');
    $next_sibling_link_title = ucfirst(strtolower(nys_statute_import_get_sibling_law_type($law_type, 'NEXT')));
  }
  else {
    // The sibling info comes from the cached array.
    $prev_sibling_location_id = '';
    $prev_sibling_link_title = '';
    $next_sibling_location_id = '';
    $next_sibling_link_title = '';
  }

  // Process the object.
  nys_statute_import_process_a_statute_object($statute_ancestor_document_obj_wrapper, $run_type, $parent_location_id, $prev_sibling_location_id, $prev_sibling_link_title, $next_sibling_location_id, $next_sibling_link_title);

}

/**
 * Gets the of parents siblings.
 *
 * Params:
 *   $law_type - UNCONSILIDATED etc
 *   $direction - PREVIOUS - NEXT.
 */
function nys_statute_import_get_sibling_law_info($law_type, $direction) {
  $law_listings = nys_statute_get_law_listings();
  $last_element = count($law_listings) - 1;
  $index = 0;

  if ($law_type == 'YTS') {
    if ($direction == 'PREVIOUS') {
      return $law_listings['YFA'];
    }
    elseif ($direction == 'NEXT') {
      return FALSE;
    }
  }

  foreach ($law_listings as $key => $law_listing) {
    $index++;

    if ($key == $law_type) {
      if ($direction == 'PREVIOUS') {

        $dummy = prev($law_listings);
        return prev($law_listings);
      }
      elseif ($direction == 'NEXT') {
        return current($law_listings);
      }
    }
  }

  return FALSE;

}

/**
 * Produces a report of open leg vs drupal for each lawid.
 */
function nys_statute_import_audit_statutes() {
  drupal_set_time_limit(3600);
  $num_law_ids = 0;
  $sum_from_ol = 0;
  $sum_from_differences = 0;
  $sum_from_drupal = 0;
  $law_listings = nys_statute_import_get_law_listings();

  print "+------------+-----------------+-------------+--------------+\r\n";
  print "| LAW ID     | FROM OPEN LEG   | FROM NYS    | DIFFERENCE   |\r\n";
  print "+------------+-----------------+-------------+--------------+\r\n";

  foreach ($law_listings as $law_id => $law_listing) {

    $quantity_from_ol = nys_statute_import_ol_get_num_bills($law_id);
    $quantity_from_drupal = nys_statute_import_get_num_bills($law_id);

    print '| ' . str_pad($law_id, 10) . ' | ' . str_pad($quantity_from_ol, 15) . ' | ' . str_pad($quantity_from_drupal, 11) . ' | ' . str_pad($quantity_from_ol - $quantity_from_drupal, 13) . "|\r\n";
    $num_law_ids++;
    $sum_from_differences = $sum_from_differences + ($quantity_from_ol - $quantity_from_drupal);
    $sum_from_ol = $sum_from_ol + $quantity_from_ol;
    $sum_from_drupal = $sum_from_drupal + $quantity_from_drupal;
    $number_of_statute_nodes = nys_statute_import_get_num_statute_nodes();

  }

  print "+------------+-----------------+-------------+--------------+\r\n";
  print '| ' . str_pad($num_law_ids, 10) . ' | ' . str_pad($sum_from_ol, 15) . ' | ' . str_pad($sum_from_drupal, 11) . ' | ' . str_pad($sum_from_differences, 13) . "|\r\n";
  print "+------------+-----------------+-------------+--------------+\r\n";
  print "| LAW ID     | FROM OPEN LEG   | FROM NYS    | DIFFERENCE   |\r\n";
  print "+------------+-----------------+-------------+--------------+\r\n";
  print '|          NUMBER OF GRAND PARENT BILL NODES' . ' | ' . str_pad(5, 13) . "|\r\n";
  print "+--------------------------------------------+--------------+\r\n";
  print '|                 TOTAL NUMBER OF BILL NODES' . ' | ' . str_pad($number_of_statute_nodes, 13) . "|\r\n";
  print "+--------------------------------------------+--------------+\r\n";

}

/**
 * Produces a report of open leg vs drupal for a particular lawid.
 */
function nys_statute_import_audit_statute($law_id) {

  print "+------------+-----------------+-------------+--------------+\r\n";
  print "| LAW ID     | FROM OPEN LEG   | FROM NYS    | DIFFERENCE   |\r\n";
  print "+------------+-----------------+-------------+--------------+\r\n";

  $quantity_from_ol = nys_statute_import_ol_get_num_bills($law_id);
  $quantity_from_drupal = nys_statute_import_get_num_bills($law_id);

  print '| ' . str_pad($law_id, 10) . ' | ' . str_pad($quantity_from_ol, 15) . ' | ' . str_pad($quantity_from_drupal, 11) . ' | ' . str_pad($quantity_from_ol - $quantity_from_drupal, 13) . "|\r\n";
  print "+------------+-----------------+-------------+--------------+\r\n";

}

/**
 * Get the number of statutes with for the specified $law_id.
 */
function nys_statute_import_get_num_bills($law_id) {
  $quantity_of_bills = db_query("SELECT COUNT(*) FROM field_data_field_lawid WHERE `field_lawid_value` = :law_id", array(":law_id" => $law_id))->fetchField();
  return $quantity_of_bills;
}

/**
 * Get the total number of statute nodes.
 *
 * Includes the 4 Grand Parent nodes and 1 Great Grand Parent node.
 */
function nys_statute_import_get_num_statute_nodes() {
  $num_bill_nodes = db_query("SELECT COUNT(*) FROM `node` WHERE `type` = 'statute'")->fetchField();
  return $num_bill_nodes;
}

/**
 * Get the numberof Bills for a $law_id.
 */
function nys_statute_import_ol_get_num_bills($law_id) {
  $count = 1;

  // Load the law tree.
  $law_tree = nys_statute_import_get_law_tree_from_node($law_id, '', '');

  // Process the law tree.
  if ($law_tree != NULL &&
        is_object($law_tree) == TRUE &&
        property_exists($law_tree, 'documents') == TRUE &&
        property_exists($law_tree->documents, 'documents') == TRUE &&
        property_exists($law_tree->documents->documents, 'items') == TRUE &&
        is_array($law_tree->documents->documents->items) == TRUE
  ) {

    // Call the recursive process_document function to process document tree.
    nys_statute_import_get_document_count($law_tree->documents->documents, $count);

    return $count;
  }

  return FALSE;
}

/**
 * Recursive function that processes the document tree.
 *
 * Params:
 *   $documents_obj - The three letter law id.
 */
function nys_statute_import_get_document_count($documents_obj, &$counter) {

  if (is_array($documents_obj->items) == TRUE && $documents_obj->size > 0) {
    foreach ($documents_obj->items as $index => $statute_document_obj) {
      $last_row_index = count($documents_obj->items) - 1;

      // For the child.
      $counter++;

      // If it has a child parse it.
      if ($statute_document_obj->documents->size > 0) {
        // Recursive call to itself.
        nys_statute_import_get_document_count($statute_document_obj->documents, $counter);
      }

    }

  }

}