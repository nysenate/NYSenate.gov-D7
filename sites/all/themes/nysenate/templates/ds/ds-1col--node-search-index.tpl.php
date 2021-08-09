<div class="c-block c-block-search-result">
    <div class="l-col l-col-1-of-2">
        <div class="c-search-result--title">
          <?php print drupal_render($content['node_type']); ?>
        </div>

            <?php //print drupal_render($content['field_majority_issue_tag']); ?>
          <?php //print drupal_render($content['field_issues']); ?>
            <?php if (isset($content['field_issues']['#items']) || isset($content['field_majority_issue_tag'][0])): ?>
                <div class="c-search-result--topic">
                        <?php
                        if (!empty($content['field_majority_issue_tag'][0])):
                            print render($content['field_majority_issue_tag'][0]) . ' ';
                        endif;
                        for ($i = 0; $i < count($content['field_issues']['#items']); $i++) :
                            if (!empty($content['field_issues'][$i])):
                                print render($content['field_issues'][$i]);
                            endif;
                        endfor;
                        ?>
                </div>
            <?php endif; ?>
          <?php if ($node->type == 'meeting'): ?>
            <?php print drupal_render($content['field_committee']); ?>
          <?php endif; ?>

    </div>
    <div class="l-col l-col-2-of-2">
        <div class="c-search-result--descript">
          <?php print drupal_render($content['title']); ?>
        </div>
        <div class="c-search-result--date">
          <?php if (!empty($node->field_date[LANGUAGE_NONE][0]['value'])): ?>
            <?php print drupal_render($content['field_date']); ?>
          <?php endif; ?>
          <?php if (!empty($node->field_senator[LANGUAGE_NONE][0]['target_id'])): ?>
            <?php print '| <span>Senator </span>' . drupal_render($content['field_senator']); ?>
          <?php endif; ?>
          <?php if (!empty($node->field_author[LANGUAGE_NONE][0]['value'])): ?>
            <?php print '| <span>Author </span>' . drupal_render($content['field_senator']); ?>
          <?php endif; ?>
          <?php if ($node->type == 'senator'): ?>
            <?php echo drupal_render($content['field_party']); ?>
            <?php echo drupal_render($content['field_confenrence']); ?>
            <?php echo nys_utils_get_senator_district($node->nid) . '&nbsp;Senate District'; ?>
          <?php endif; ?>
        </div>
    </div>
</div>