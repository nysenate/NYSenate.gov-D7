<?php
/**
 * @file
 * This template file outputs a senator search result.
 */
?>
<div class="c-block c-block-search-result c-block-search-result--senator">
  <div class="l-col l-col-1-of-2">
    <div class="c-search-result--title">
      <?php print drupal_render($content['node_type']); ?>
    </div>
  </div>
  <div class="l-col l-col-2-of-2">
    <?php print render($content['field_image_headshot']); ?>
    <div class="c-search-result--descript">
      <?php print drupal_render($content['title']); ?>
    </div>
    <div class="c-search-result--date">
      <?php print drupal_render($content['field_party']); ?>
      <?php print drupal_render($content['field_confenrence']); ?> |
      <?php
        if ($node->field_active[LANGUAGE_NONE][0]['value'] == 0):
          print 'Former New York State Senator';
        else:
          print nys_utils_get_senator_district($node->nid) . '&nbsp;Senate District';
        endif;
      ?>
    <br /><br />
    <?php print $node->body[LANGUAGE_NONE][0]['search_summary']; ?>
    </div>
  </div>
</div>
