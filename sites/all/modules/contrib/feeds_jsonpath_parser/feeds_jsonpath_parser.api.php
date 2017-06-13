<?php

/**
 * @file
 * Documentation of Feeds JSONPath parser hooks.
 */

 /**
  * Allows filtering or modifying a feed item.
  *
  * @param array &$item
  *   The feed item to modify.
  *
  * @return bool
  *   Returns true if the item should be skipped.
  */
 function hook_feeds_jsonpath_parser_filter(array &$item, FeedsSource $source) {
   // Check for the importer.
   if ($source->id  != 'my_importer') {
     return;
   }
   // 1) Alter the items array.
   $item['title'] = 'A hard coded title';

   // 2) Return TRUE which will cause this item to be skipped.
   if ($item['title'] == 'An item I would like to skip.') {
     return TRUE;
   }
 }
