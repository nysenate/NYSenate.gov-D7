<?php
// Get Sponsors list
foreach($node->field_ol_sponsor['und'] as $sponsor) {
  $sponsors[] = $sponsor['entity']->title;
}
foreach($content['field_ol_co_sponsors']['#items'] as $sponsor) {
  $sponsors[] = $sponsor['entity']->title;
}
foreach($content['field_ol_multi_sponsors']['#items'] as $sponsor) {
  $sponsors[] = $sponsor['entity']->title;
}

?>
<div class="c-block c-block-legislation c-block-legislation-featured c-block--half-wrap">
  <div class="c-legislation-info">
    <h3 class="c-bill-num"><a href="<?php echo $node_url;?>"><?php echo $title; ?></a></h3>
    <h4 class="c-bill-topic"><?php echo render($content['field_issues']);?></h4>
    <p class="c-bill-descript"><?php echo render($content['field_ol_name']);?></p>
    <?php echo $variables['graph_html']; ?>
    <?php //if(!empty($statuses)): ?>
    <div class="c-bill-update">
      <p class="c-bill-update--date"><?php echo $latest_status_date; ?></p>
      <p class="c-bill-update--location"><?php echo $variables['display_status']; ?></p>
    </div>
    <?php //endif; ?>

    <?php if(!empty($sponsors)): ?>
      <div class="sponsors">
        <span>Sponsors</span>
        <span><?php echo implode(', ', $sponsors);?></span>
      </div>
    <?php endif; ?>
    <div class="c-bill-polling med-bg">
      <?php echo render($content['field__constituent_vote']); ?>
    </div>
  </div>
</div>