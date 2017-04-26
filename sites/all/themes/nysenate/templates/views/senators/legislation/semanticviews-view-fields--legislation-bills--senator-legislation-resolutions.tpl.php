<?php
$all_statuses = drupal_json_decode($fields['field_ol_all_statuses']->content);

if (!empty($all_statuses)):
  $resolution_status = array_pop($all_statuses['items']);
  $resolution_status_date = strtotime($resolution_status['date']);
endif;
?>
<div class="c-block c-list-item c-legislation-block">
  <div class="c-bill-meta">
    <h3 class="c-bill-num"><?php echo $fields['title']->content; ?></h3>
    <h4 class="c-bill-topic"><?php echo $fields['field_issues']->content; ?></h4>
  </div>
  <div class="c-bill-body">
    <p class="c-bill-descript"><?php echo $fields['field_ol_name']->content; ?></p>
      <?php if (!empty($all_statuses)): ?>
      <div class="c-bill-update">
        <p class="c-bill-update--date"><?php if (!empty($resolution_status_date)): print date("M d, Y", $resolution_status_date); endif; ?></p>
        <p class="c-bill-update--location"><?php if (!empty($resolution_status['text'])): print $resolution_status['text']; endif; ?></p>
        <p class="c-bill-update--sponsor"><?php if (!empty($fields['field_ol_sponsor']->content)): print $fields['field_ol_sponsor']->content; endif; ?></p>
      </div>
      <?php endif; ?>
  </div>
</div>
