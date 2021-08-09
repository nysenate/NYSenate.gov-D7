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

$node_url = url('node/'.$row->node_field_data_field_featured_bill_nid, array('absolute' => TRUE));
$bill_title = $row->_field_data['node_field_data_field_featured_bill_nid']['entity']->title;
//$bill_blurb = $row->field_field_ol_name[0]['rendered']['#markup'];
$bill_blurb = truncate_utf8($fields['field_ol_name']->content, 135, TRUE, TRUE, 132);

$sponsor = 'Senator';
if((arg(0) == 'node') && isset($fields['field_ol_sponsor_1']->content) && (arg(1) == $fields['field_ol_sponsor_1']->content)){
  $sponsor = 'Sponsor';
}
if((arg(0) == 'node') && isset($fields['field_ol_co_sponsors']->content) && (in_array(arg(1), explode(', ', $fields['field_ol_co_sponsors']->content)))){
  $sponsor = 'Sponsor';
}

// Twitter Share Blurb
$name_parts = explode(' ',strip_tags($fields['title']->content));
$twitter_share_blurb = '"'.$fields['field_featured_quote']->content.'" - Sen.'.end($name_parts);
// $twitter_share_blurb = $bill_title.':'.$bill_blurb.'. '.$fields['field_featured_quote']->content;

$bill_node_id = isset($row->node_field_data_field_featured_bill_nid)
  ? $row->node_field_data_field_featured_bill_nid
  : 0;
?>

<section class="c-legislation">
  <div class="c-container--header__top-border">
    <h3 class="c-container--title">Featured Legislation</h3>
  </div>

  <div class="c-block c-block-legislation c-block-legislation-featured">
    <button class="js-leg-toggle c-block--btn c-block--btn-toggle">close</button>
    <div class="c-social">
      <ul class="c-social--list">
        <li><a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>" class="icon-replace__facebook">facebook</a></li>
        <li><a target="_blank" href='http://twitter.com/share?url=<?php echo $node_url;?>&text=<?php echo $twitter_share_blurb;?>' class="icon-replace__twitter">twitter</a></li>
        <!-- <li><a href="#" class="icon-replace__youtube">youtube</a></li> -->
      </ul>
    </div>
    <div class="c-legislation-info">
      <h3 class="c-bill-num"><?php echo $fields['field_featured_bill']->content; ?></h3>
      <?php if(!empty($fields['field_issues']->content)): ?>
        <h4 class="c-bill-topic"><?php echo $fields['field_issues']->content; ?></h4>
      <?php endif; ?>
      <?php
      echo $row->graph_html;  // See /sites/all/themes/nysenate/template.php
      ?>
      <p class="c-bill-descript"><?php echo truncate_utf8($fields['field_ol_name']->content, 135, TRUE, TRUE, 132); ?></p>
      <div class="c-bill-update">
        <?php if($fields['field_ol_last_status_date']): ?>
          <p class="c-bill-update--date"><?php if($fields['field_ol_last_status_date']) echo $fields['field_ol_last_status_date']->content; ?></p>
        <?php endif; ?>
        <p class="c-bill-update--location"><?php echo $row->display_status; ?></p>
      </div>

      <?php if ($bill_node_id): ?>
        <div class="c-bill-polling med-bg">
          <?php echo render($view->vote_widgets[$bill_node_id]); ?>
        </div>
      <?php endif; ?>
    </div>

    <div class="c-legislation--quote">
      <div class="c-quote--content">
        <h4 class="c-quote--title"><?php echo $sponsor?>'s position</h4>
        <p class="c-pullquote icon-before__quotes">
          <?php echo $fields['field_featured_quote']->content;?>"
        </p>
        <span class="c-pullquote--citation icon-before__minus u-quote--has-img">senator <?php echo $fields['title']->content;?></span>

        <div class="c-legislation--sponsor">
          <div class="c-sponsor--img">
            <?php if($fields['field_image_headshot']->content) echo $fields['field_image_headshot']->content; ?>
          </div>
          <div class="c-sponsor--info">
            <p class="c-sponsor--name"><?php echo $fields['title']->content;?></p>
            <p class="c-sponsor--party"><?php if(isset($fields['field_party']->content)) echo '('.$fields['field_party']->content.')';?></p>
            <?php if(isset($fields['field_district_number']->content)) echo '<a class="c-sponsor--dist" href="">District '.$fields['field_district_number']->content.'</a>'; ?>
          </div>
          <!-- .c-sponsor--info -->
        </div>
        <!-- .c-legislation--sponsor -->
      </div>
      <!-- .c-quote--content -->
    </div>
    <!-- .c-legislation--quote -->

  </div>
  <!-- .c-block-legislation-featured -->


</section>
<!-- .c-legislation -->
