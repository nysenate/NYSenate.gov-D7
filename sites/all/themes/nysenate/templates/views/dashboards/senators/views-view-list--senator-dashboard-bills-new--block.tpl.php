<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */

/**
 * @var $view \view
 * @var $rows string[] Rendered HTML of each table row
 */
// TODO: move this to hook_views_pre_render().
$table_title = "Popular Amongst Your Constituents";
if ($view->current_display == 'block_2') {
  $table_title = date('F j, Y');
}
if (!empty($view->args[0])) {
  $table_title = check_plain($view->args[0]);
}
$all_rows = implode('', $rows);
?>
<h3 class="tab-title"><?php echo $table_title; ?></h3>
<table dir="ltr" width="100%" border="0" class="bill-data">
  <thead>
  <tr>
    <th scope="col" class="active-list-date" width="33%"></th>
    <th scope="col" class="active-list-header" width="33%">
      Your Constituents' Positions
    </th>
    <th scope="col" class="active-list-header" width="33%">All Votes</th>
  </tr>
  </thead>
  <tbody>
  <?php echo $all_rows; ?>
  </tbody>
</table>
