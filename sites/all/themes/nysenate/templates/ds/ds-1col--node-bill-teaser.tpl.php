<div class="c-block c-block-legislation c-block-legislation-featured c-block--half-wrap">
  
  <div class="c-legislation-info">
    <h3 class="c-bill-num"><a href="<?php echo $node_url;?>"><?php echo $title; ?></a></h3>
    <?php if(isset($content['field_issues'])): ?>
      <h4 class="c-bill-topic"><?php echo render($content['field_issues']);?></h4>
    <?php endif; ?>
    <p class="c-bill-descript"><?php echo render($content['field_ol_name']);?></p>
    <?php print $variables['graph_html']; ?>
    <div class="c-bill-update">
      <p class="c-bill-update--date"><?php echo render($content['field_ol_last_status_date']); ?></p>
      <p class="c-bill-update--location"><?php echo $variables['display_status']; ?></p>
    </div>

    <?php if(!empty($content['field_ol_sponsor'])): ?>
      <div class="sponsors">
        <span>Sponsored by</span>
        <span><?php echo render($content['field_ol_sponsor']); ?></span>
      </div>
    <?php endif; ?>
    <div class="c-bill-polling med-bg">
      <?php echo render($content['field__constituent_vote']); ?>
    </div>
  </div>
</div>
