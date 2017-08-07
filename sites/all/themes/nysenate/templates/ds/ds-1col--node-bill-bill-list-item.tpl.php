<div class="c-block c-list-item c-legislation-block">
  <div class="c-bill-meta">
    <h3 class="c-bill-num">Bill <?php echo $title ?></h3>
    <h4 class="c-bill-topic"><?php echo render($content['field_issues']); ?></h4>
  </div>
  <div class="c-bill-body">
    <p class="c-bill-descript"><?php echo render($content['field_ol_name']); ?></p>
    <?php print $variables['graph_html']; ?>
    <div class="c-bill-update">
      <p class="c-bill-update--date">
        <?php echo render($content['field_ol_last_status_date']); ?>
        <?php echo '&nbsp;&nbsp;|&nbsp;&nbsp;' . $variables['display_status']; ?>
        <?php if($node->field_ol_sponsor['und'][0]['target_id']): ?>
      <p class="c-bill-update--sponsor">
        Sponsor: <?php echo render($content['field_ol_sponsor']); ?>
      </p>
      <?php endif; ?>
      <?php if($node->field_ol_sponsor_name['und'][0]['value'] && !$node->field_ol_sponsor['und'][0]['target_id']): ?>
        <p class="c-bill-update--sponsor">
          Sponsor: <?php echo render($content['field_ol_sponsor_name']); ?>
        </p>
      <?php endif; ?>
      </p>
    </div>
  </div>
</div>