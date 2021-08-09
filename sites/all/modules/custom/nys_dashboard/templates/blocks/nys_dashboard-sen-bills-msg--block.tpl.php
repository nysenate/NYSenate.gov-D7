<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user module
 *     is responsible for handling the default user navigation block. In that case
 *     the class would be "block-user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */
?>

<div class="c-block c-container c-container--senator-bills-messaging">
  <div class="c-active-list--header">
    <h2 class="c-container--title">Message Constituents About Bill Activity</h2>
  </div>
  <div class="c-container--body">
				<form class="bills-search">
					<label>Search</label>
					<div class="container-inline form-wrapper" id="edit-basic">
						<div class="form-item form-type-textfield form-item-keys">
				  	<input class="c-site-search--box icon_after__search form-text" type="text" id="edit-keys" name="keys" value="" size="50" maxlength="255">
						</div>
						<button class="c-site-search--btn form-submit" id="edit-submit" name="op" value="Search" type="submit">Search Bills</button>
					</div>
				</form>
				<form class="bills-filter">
					<div class="col1">
						<label>Filter by Position:</label>
						<select class="filter">
							<option>All Positions</option>
						</select>
					</div>
					<div class="col2">
						<label>Filter by Communication Status</label>
						<select class="filter">
							<option>All types</option>
						</select>
					</div>
				</form>
				<form class="bills-msg">
					<div>
						<div class="select-all-messages">
					    <input type="checkbox" name="checkbox">
					    <label for="checkbox ">Check All</label>
						</div>
						<button class="icon-before__contact">Message</button>
					</div>
				</form>
			<table width="100%" border="0" class="stat-data">
				<thead>
					<tr>
						<th></th>
						<th class="name">Name</th>
						<th class="verified">Verified</th>
						<th class="bill">Bill Name</th>
						<th class="vote">Vote</th>
						<th class="messaged ">Messaged</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td><input type="checkbox" name="checkbox"></td>
						<td class="name">Marcus Johnson</td>
						<td class="bill">S7876</td>
						<td class="vote">AYE <div class="date">1/9/2015</div></td>
						<td class="messaged">YES <div class="date">1/9/2015</div></td>
					</tr>
					<tr>
						<td><input type="checkbox" name="checkbox"></td>
						<td class="name">Marcus Johnson</td>
						<td class="bill">S7876</td>
						<td class="vote">NAY <div class="date">1/9/2015</div></td>
						<td class="messaged">YES <div class="date">1/9/2015</div></td>
					</tr>
					<tr>
						<td><input type="checkbox" name="checkbox"></td>
						<td class="name">Marcus Johnson</td>
						<td class="verified"></td>
						<td class="bill">S7876</td>
						<td class="vote">NAY <div class="date">1/9/2015</div></td>
						<td class="messaged">YES <div class="date">1/9/2015</div></td>
					</tr>
					<tr>
						<td><input type="checkbox" name="checkbox"></td>
						<td class="name">Marcus Johnson</td>
						<td class="bill">S7876</td>
						<td class="vote">NAY <div class="date">1/9/2015</div></td>
						<td class="messaged">YES <div class="date">1/9/2015</div></td>
					</tr>
					<tr>
						<td><input type="checkbox" name="checkbox"></td>
						<td class="name">Marcus Johnson</td>
						<td class="verified"></td>
						<td class="bill">S7876</td>
						<td class="vote">AYE <div class="date">1/9/2015</div></td>
						<td class="messaged">YES <div class="date">1/9/2015</div></td>
					</tr>
					<tr>
						<td><input type="checkbox" name="checkbox"></td>
						<td class="name">Marcus Johnson</td>
						<td class="verified"></td>
						<td class="bill">S7876</td>
						<td class="vote">YES <div class="date">1/9/2015</div></td>
						<td class="messaged">YES <div class="date">1/9/2015</div></td>
					</tr>
					<tr>
						<td><input type="checkbox" name="checkbox"></td>
						<td class="name">Marcus Johnson</td>
						<td class="bill">S7876</td>
						<td class="vote">AYE <div class="date">1/9/2015</div></td>
						<td class="messaged">YES <div class="date">1/9/2015</div></td>
					</tr>
					<tr>
						<td class="pager-cell" colspan="6">
							<ul class="pager">
								<li class="pager-item"><a href="#">1</a></li>
								<li class="pager-item"><a href="#">2</a></li>
								<li class="pager-item"><a href="#">3</a></li>
								<li class="pager-item"><a href="#">4</a></li>
								<li class="pager-item"><a href="#">5</a></li>
								<li class="pager-item"><a href="#">></a></li>
							</ul>
						</td>
					</tr>
				</tbody>
			</table>
  </div>
</div>
