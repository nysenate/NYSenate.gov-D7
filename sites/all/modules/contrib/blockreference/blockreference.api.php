<?php

/**
 * Alter referenceable blocks, BEFORE the autocomplete match.
 *
 * These are always block objects, not options. You can change the option label by changing $block->info.
 *
 * For autocomplete fields, this alter happens AFTER the search, before slicing the results (ACDB does that).
 *
 * $context contains:
 * - instance
 * - type ("autocomplete" or "options_list", depending on where this list is requested)
 * - entity
 * - entity_type
 */
function hook_blockreference_blocks_pre_alter(&$blocks, $context) {
  // These are all the blocks that match the field instance's referenceable module option. If you were to change
  // a block's label now, that's the label the autocomplete will try to match.

  foreach ($blocks as $id => $block) {
    // Add module & delta to pretty label.
    $block->info .= ' (' . $block->module . '/' . $block->delta . ')';

    // Remove all Views blocks, except 'public_stuff'.
    if ($block->module == 'views' && strpos($block->delta, 'public_stuff-') !== 0) {
      unset($blocks[$id]);
    }
  }
}

/**
 * Alter referenceable blocks, AFTER the autocomplete match.
 *
 * Same exact API as hook_blockreference_blocks_pre_alter().
 */
function hook_blockreference_blocks_post_alter(&$blocks, $context) {
  // These are the exact blocks in the result. If the widget is an autocomplete, it will be cut off after 10 (?)
  // elements, so sorting is important. If you change the label here, the displayed labels will be different than
  // the matched labels, so probably don't do that.

  // Reverse sort, because I'm like that.
  uasort($blocks, function($a, $b) {
    return strnatcasecmp($b->info, $a->info);
  });
}
