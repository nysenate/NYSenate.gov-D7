<div class="c-block c-list-item c-legislation-block">
  <div class="c-bill-meta">
    <h3 class="c-bill-num"><?php echo $fields['title']->content; ?></h3>
    <h4 class="c-bill-topic"><?php echo $fields['field_issues']->content; ?></h4>
  </div>
  <div class="c-bill-body">
    <p class="c-bill-descript"><?php echo truncate_utf8($fields['field_ol_name']->content, 135, TRUE, TRUE, 132); ?></p>
    <?php echo $row->graph_html; // See /sites/all/themes/nysenate/template.php ?>
    <div class="c-bill-update">
      <p class="c-bill-update--date"><?php if($fields['field_ol_last_status_date']) echo $fields['field_ol_last_status_date']->content; ?></p>
      <p class="c-bill-update--location"><?php echo $row->display_status; ?></p>
    </div>
  </div>
</div>