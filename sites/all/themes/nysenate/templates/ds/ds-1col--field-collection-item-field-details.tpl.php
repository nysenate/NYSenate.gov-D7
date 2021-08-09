<?php
/**
 * @file
 * Template theming for field collection items field details.
 */
  if(isset($content['field_link'][0]['#markup']) && !empty($content['field_honoree_name'])):
    $name = l($content['field_honoree_name'][0]['#markup'], $content['field_link'][0]['#markup'], array('html' => TRUE, 'attributes' => array('target' => '_blank')));
  elseif (isset($content['field_honoree_name'][0]['#markup'])):
    $name = $content['field_honoree_name'][0]['#markup'];
  endif;
  if (isset($content['field_link'][0]['#markup']) && !empty($content['field_subheading'])):
    $subhead = l($content['field_subheading'][0]['#markup'], $content['field_link'][0]['#markup'], array('html' => TRUE, 'attributes' => array('target' => '_blank')));
  elseif (isset($content['field_subheading'][0]['#markup'])):
    $subhead = $content['field_subheading'][0]['#markup'];
  endif;
?>
<div class="">
  <?php if (!empty($name)): ?>
  <span class="c-honoree--name"><?php echo $name; ?></span>
  <?php endif; ?>
  <?php if (!empty($subhead)): ?>
  <span class="c-honoree--meta"><?php echo $subhead; ?></span>
  <?php endif; ?>
</div>
