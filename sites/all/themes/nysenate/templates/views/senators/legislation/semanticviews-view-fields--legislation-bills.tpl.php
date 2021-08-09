<article class="c-block c-list-item c-legislation-block">
  <div class="c-bill-meta">
    <h3 class="c-bill-num"><?php echo $fields['title']->content; ?></h3>
    <p class="c-bill-topic"><?php echo $fields['field_issues']->content; ?></p>
  </div>
  <div class="c-bill-body">
    <h4 class="c-bill-descript"><?php echo $fields['field_ol_name']->content; ?></h4>
      <?php if(isset($row->graph_html)) echo $row->graph_html; // See /sites/all/themes/nysenate/template.php ?>
      <div class="c-bill-update">
        <?php if(isset($fields['field_ol_last_status_date']) && $fields['field_ol_last_status_date']): ?>
          <p class="c-bill-update--date"><?php
            if(isset($fields['field_ol_last_status_date']) && $fields['field_ol_last_status_date'])
              echo $fields['field_ol_last_status_date']->content; ?></p>
        <?php endif; ?>
        <p class="c-bill-update--location"><?php if(isset($row->display_status)) echo $row->display_status; ?></p>
      </div>
  </div>
</article>