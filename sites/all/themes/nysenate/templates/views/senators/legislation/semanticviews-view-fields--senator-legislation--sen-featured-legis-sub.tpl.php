<?php
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
?>


<div class="c-block c-block-legislation c-block-legislation-featured c-block__collapsed">
    <button class="c-block--btn c-block--btn-toggle js-leg-toggle">close</button>
    <div class="c-social">
        <ul class="c-social--list">
            <li><a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>" class="icon-replace__facebook">facebook</a></li>
            <li><a target="_blank" href='http://twitter.com/share?url=<?php echo $node_url;?>&text=<?php echo $twitter_share_blurb;?>' class="icon-replace__twitter">twitter</a></li>
            <!-- <li><a href="#" class="icon-replace__youtube">youtube</a></li> -->
        </ul>
    </div>
    <div class="c-legislation-info">
        <h3 class="c-bill-num"><?php echo $fields['field_featured_bill']->content; ?></h3>
        <h4 class="c-bill-topic"><?php echo $fields['field_issues']->content;?></h4>
        <p class="c-bill-descript"><?php echo truncate_utf8($fields['field_ol_name']->content, 135, TRUE, TRUE, 132); ?></p>
        <?php echo $row->graph_html; // See /sites/all/themes/template.php ?>
        <div class="c-bill-update">
            <?php if($fields['field_ol_last_status_date']): ?>
                <p class="c-bill-update--date"><?php if($fields['field_ol_last_status_date']) echo $fields['field_ol_last_status_date']->content; ?></p>
            <?php endif; ?>
            <p class="c-bill-update--location"><?php echo $row->display_status; ?></p>
        </div>
        <?php if(!empty($fields['field__constituent_vote']->content)):?>
            <div class="c-bill-polling med-bg">
                <?php echo $fields['field__constituent_vote']->content; ?>
            </div>
        <?php endif; ?>
    </div>

    <div class="c-legislation--quote">
        <div class="c-quote--content">
            <h4 class="c-quote--title">sponsor's position</h4>
            <p class="c-pullquote icon-before__quotes">
                <?php echo $fields['field_featured_quote']->content;?>"
            </p>
            <!--
              TODO: Logic - if this block is NOT on the microsite
                    this element only shows when collapsed
                    - for now just adding a class - "u-quote--has-img"
            -->
            <span class="c-pullquote--citation icon-before__minus u-quote--has-img">senator <?php echo $fields['title']->content;?></span>

            <div class="c-legislation--sponsor">
                <div class="c-sponsor--img">
                    <?php if(isset($fields['field_image_headshot']->content)) echo $fields['field_image_headshot']->content; ?>
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
    </div>
</div>