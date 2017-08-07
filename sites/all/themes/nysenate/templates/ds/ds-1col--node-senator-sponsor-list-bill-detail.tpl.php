<?php
$parties = '';
if(count($content['field_party']['#items']) > 0) {
  foreach($content['field_party']['#items'] as $item) {
    $parties[] = $item['value'];
  }
  $parties = '(' . implode(', ', $parties) . ') ';
}
?>
<div class="nys-senator sponsor-list">
  <div class="nys-senator--thumb">
    <?php echo render($content['field_image_headshot']); ?>
  </div>
  <div class="nys-senator--info">
    <h4 class="nys-senator--name"><a href="/<?php echo drupal_get_path_alias('node/'.$node->nid)?>"><?php print $title; ?></a></h4>
    <p class="nys-senator--district">
      <span class="nys-senator--party">  
       <?php echo $parties . '<span>' . nys_utils_get_senator_district($node->nid) . '&nbsp;Senate District</span>'; ?>
      </span>
    </p>
  </div>
</div>