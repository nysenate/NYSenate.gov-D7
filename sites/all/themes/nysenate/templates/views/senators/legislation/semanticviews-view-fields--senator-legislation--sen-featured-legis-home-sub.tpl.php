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
<article class="c-block c-list-item c-legislation-block">
    <div class="c-bill-meta">
        <h3 class="c-bill-num"><?php echo $fields['field_featured_bill']->content; ?></h3>
        <p class="c-bill-topic"><?php echo $fields['field_issues']->content; ?></p>
    </div>
    <div class="c-bill-body">
        <h4 class="c-bill-descript"><?php echo $fields['field_ol_name']->content; ?></h4>
        <?php if(isset($row->graph_html)) echo $row->graph_html; // See /sites/all/themes/nysenate/template.php ?>
        <div class="c-bill-update">
            <?php if(isset($fields['field_ol_last_status_date']) && $fields['field_ol_last_status_date']): ?>
                <p class="c-bill-update--date"><?php if(isset($fields['field_ol_last_status_date']) && $fields['field_ol_last_status_date']) echo $fields['field_ol_last_status_date']->content; ?></p>
            <?php endif; ?>
            <p class="c-bill-update--location"><?php echo $row->display_status; ?></p>
        </div>
    </div>
</article>