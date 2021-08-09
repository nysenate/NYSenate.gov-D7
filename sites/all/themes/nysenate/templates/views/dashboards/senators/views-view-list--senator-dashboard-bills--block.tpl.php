<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */

// TODO: delete this file once all references are resolved
watchdog(
  'nys_dashboard',
  'deprecated template file being used: ' . __FILE__,
  [
    'args' => arg(),
    'stack' => debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS),
    'file' => __FILE__,
  ],
  WATCHDOG_WARNING
);
?>
<h3 class="tab-title">Popular Amongst Your Constituents</h3>
<table dir="ltr" width="100%" border="0" class="bill-data">
  <thead>
  <tr>
    <th scope="col" class="active-list-date" width="33%"></th>
    <th scope="col" class="active-list-header" width="33%">Your Constituents
      Positions
    </th>
    <th scope="col" class="active-list-header" width="33%">All Votes</th>
  </tr>
  </thead>
  <tbody>
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
  </tbody>
</table>
