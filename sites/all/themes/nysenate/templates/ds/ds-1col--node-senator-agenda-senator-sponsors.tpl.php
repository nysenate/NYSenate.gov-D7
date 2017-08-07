<div class="nys-senator">
  <div class="nys-senator--thumb">
    <?php echo render($content['field_image_headshot']); ?>
  </div>
  <div class="nys-senator--info">
    <span>Sponsor</span>
    <h4 class="nys-senator--name"><a href="/<?php echo drupal_get_path_alias('node/'.$node->nid)?>"><?php print $title; ?></a></h4>
    <p class="nys-senator--district">
      <span class="nys-senator--party">
      <?php echo nys_utils_get_senator_district($node->nid) . '&nbsp;Senate District'; ?>
      </span>
    </p>
  </div>
</div>