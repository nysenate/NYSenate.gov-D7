<div class="c-block c-list-item c-legislation-block">
  <div class="c-bill-meta">
    <h3 class="c-bill-num"><?php echo $fields['title']->content; ?></h3>
      <h4 class="c-bill-topic"><?php echo $fields['term_node_tid']->content; ?></h4>
  </div>
  <div class="c-bill-body">
    <?php if($fields['type']->content === 'Resolution'): ?>
    <p class="c-bill-descript"><?php echo $fields['field_ol_name']->content; ?></p>
    <?php if(isset($fields['field_ol_sponsor']->content)): ?>
        <p class="c-bill-update--sponsor">Sponsor: <?php echo $fields['field_ol_sponsor']->content; ?></p>
    <?php endif; ?>
      <?php else: ?>
      <p class="c-bill-descript"><?php echo $fields['field_ol_name']->content; ?></p>
    <?php echo $row->graph_html; ?>
    <div class="c-bill-update">
      <p class="c-bill-update--date"><?php echo $fields['field_ol_last_status_date']->content; ?></p>
      <p class="c-bill-update--location"><?php echo $row->display_status; ?></p>
      <?php if(isset($fields['field_ol_sponsor']->content)): ?>
      <p class="c-bill-update--sponsor">Sponsor: <?php echo $fields['field_ol_sponsor']->content; ?></p>
      <?php endif; ?>
    </div>
  </div>
    <?php endif; ?>
</div>

