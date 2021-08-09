<?php 
// Setup the bill statuses.
$frontend_statuses = array(
  array(
    "value" => 0,
    "name"  => "Introduced"
  ),
  array(
    "value" => 1,
    "name"  => "In Committee"
  ),
  array(
    "value" => 2,
    "name"  => "On Floor Calendar"
  ),
  array(
    "value" => 3,
    "name"  => "Passed Senate",
    "type"  => "senate"
  ),
  array(
    "value" => 3,
    "name"  => "Passed Assembly",
    "type"  => "assembly"
  ),
  array(
    "value" => 4,
    "name"  => "Delivered to Governor"
  ),
  array(
    "value" => 5,
    "name"  => "Signed/Vetoed by Governor"
  ),
);

$backend_statuses_to_values = array(
  "INTRODUCED"       => 0,
  "IN_ASSEMBLY_COMM" => 1,
  "IN_SENATE_COMM"   => 1,
  "ASSEMBLY_FLOOR"   => 2,
  "SENATE_FLOOR"     => 2,
  "PASSED_ASSEMBLY"  => 3,
  "PASSED_SENATE"    => 3,
  "DELIVERED_TO_GOV" => 4,
  "SIGNED_BY_GOV"    => 5,
  "VETOED"           => 5,
  "STRICKEN"         => -1,
  "LOST"             => -1,
  "SUBSTITUTED"      => -1,
  "ADOPTED"          => -1,
);

switch($fields['value']->content) {
  case '1': $support_text = "Your position is 'AYE'"; break;
  case '0': $support_text = "Your position is 'NAY'"; break;
  default: $support_text = "Do you support this bill?"; break;
}

$current_status       = $fields['field_ol_last_status']->content;
$current_status_value = $backend_statuses_to_values[$current_status];

// Show if the bill has been signed or vetoed if it's reached the governor.
$signed_or_vetoed = "Signed/Vetoed by Governor";
if ($current_status == "SIGNED_BY_GOV") {
  $signed_or_vetoed = "Signed by Governor";
} else if ($current_status == "VETOED") {
  $signed_or_vetoed = "Vetoed by Governor";
}
$frontend_statuses[6]["name"] = $signed_or_vetoed;

// If the bill has passed it's house's floor vote and gone back to the other houses committee,
// show the last status as passing the bill's house.
if (
  ($current_status_value == 1  || $current_status_value == 2) &&
  ($fields['field_ol_chamber']->content == 'senate' && strrpos($fields['field_ol_all_statuses']->content, 'PASSED_SENATE') !== false)
  ) {
  $current_status       = "PASSED_SENATE";
  $current_status_value = $backend_statuses_to_values[$current_status];
} else if (
  ($current_status_value == 1  || $current_status_value == 2) &&
  ($fields['field_ol_chamber']->content == 'assembly' && strrpos($fields['field_ol_all_statuses']->content, 'PASSED_ASSEMBLY') !== false)
  ) {
  $current_status       = "PASSED_ASSEMBLY";
  $current_status_value = $backend_statuses_to_values[$current_status];
}

$passed_other_house = $fields['field_ol_chamber']->content == 'senate' ? strrpos($fields['field_ol_all_statuses']->content, 'PASSED_ASSEMBLY') !== false : strrpos($fields['field_ol_all_statuses']->content, 'PASSED_SENATE') !== false;
?>
<div class="bill-follow-widget gen_blue" id="bill-follow-widget-<?php echo $row->nid; ?>">
	<h3><?php echo $fields['title']->content; ?></h3>
	<div class="bill-type"><?php echo $fields['field_issues']->content; ?></div>
	<div class="bill-blurb"><?php echo truncate_utf8($fields['field_ol_name']->content, 135, TRUE, TRUE, 132); ?></div>
	<div class="timeline">
      <?php echo $row->graph_html; // See /sites/all/themes/template.php ?>
	</div>
  <?php if ($fields['field_ol_last_status_date']->content): ?>
	<div class="bill-date"><?php echo $fields['field_ol_last_status_date']->content; ?></div>
  <?php endif;?>
  <p class="bill-committee"><?php echo $row->display_status; ?></p>
	<div class="bill-sponsor-hdr">Sponsors</div>
  <?php if($fields['field_ol_sponsor']->content): ?>
	 <div class="bill-sponsor"><?php echo $fields['field_ol_sponsor']->content; ?></div>
  <?php endif; ?>
  <?php if (!senator_viewing_constituent_dashboard() && isset($view->vote_widgets[$row->nid])): ?>
    <div class="c-bill-polling med-bg">
    <?php echo render($view->vote_widgets[$row->nid]); ?>
    </div>
  <?php endif; ?>
</div>