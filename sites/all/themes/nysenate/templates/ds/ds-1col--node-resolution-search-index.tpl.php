<?php
$all_statuses = json_decode($node->field_ol_all_statuses[LANGUAGE_NONE][0]['value']);
$resolution_path = url('node/' . $nid);
if ($all_statuses) {
  $resolution_status = array_pop($all_statuses->items);
  $resolution_status_date = strtotime($resolution_status->date);
}
?>

<div class="c-block c-list-item c-legislation-block">
    <div class="c-bill-meta">
        <h3 class="c-bill-num">
            <a href="<?php echo $resolution_path; ?>"
               title="<?php echo $title ?>">Reso. <?php echo $title ?></a>
        </h3>
        <h4 class="c-bill-topic"><?php echo render($content['field_issues']); ?></h4>
    </div>
    <div class="c-bill-body">
        <p class="c-bill-descript">
            <a href="<?php echo $resolution_path; ?>"><?php
              echo truncate_utf8(render($content['field_ol_name']), 135, TRUE, TRUE, 132); ?></a>
        </p>
        <div class="c-bill-update">
            <p class="c-bill-update--date">
              <?php if ($resolution_status) {
                echo date("M d, Y", $resolution_status_date);
              } ?>
              <?php if ($resolution_status->text) {
                echo '&nbsp;&nbsp;|&nbsp;&nbsp;' . $resolution_status->text;
              } ?>
            </p>
          <?php if (!empty($node->field_ol_sponsor[LANGUAGE_NONE][0]['target_id'])): ?>
              <p class="c-bill-update--sponsor">
                  Sponsor: <?php echo render($content['field_ol_sponsor']); ?>
              </p>
          <?php elseif (!empty($node->field_ol_sponsor_name[LANGUAGE_NONE][0]['value'])): ?>
              <p class="c-bill-update--sponsor">
                  Sponsor: <?php echo render($content['field_ol_sponsor_name']); ?>
              </p>
          <?php endif; ?>
        </div>
    </div>
</div>