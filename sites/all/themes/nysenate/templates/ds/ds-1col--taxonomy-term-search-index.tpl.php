
<div class="c-block c-block-search-result">
  <div class="l-col l-col-1-of-2">
    <div class="c-search-result--title">
      <?php print drupal_render($content['term_type']); ?>
    </div>
  </div>
  <div class="l-col l-col-2-of-2">
    <div class="c-search-result--descript">
      <?php print drupal_render($content['title']); ?>
    </div>
    <div class="c-search-result--date">
    <?php if($term->field_senator[LANGUAGE_NONE][0]['target_id']):?>
        <?php print '<span>Senator </span>' .drupal_render($content['field_senator']); ?>
    <?php endif; ?>
    <?php if($term->field_chair[LANGUAGE_NONE][0]['target_id']):?>
        <?php print '<span>Chair </span>' .drupal_render($content['field_chair']); ?>
    <?php endif; ?>
    </div>
    <?php if($term->vocabulary_machine_name == 'committees' && $node->field_assemblymen_chair[LANGUAGE_NONE][0]['value'] == 1): ?>
    <div class="c-search-result--follow">
      <?php print drupal_render($content['flag_follow_group']); ?>
    </div>
    <?php elseif($term->vocabulary_machine_name == 'committees' && $node->field_assemblymen_chair[LANGUAGE_NONE][0]['value'] == 0): ?>
    <div class="c-search-result--follow">
      <?php print drupal_render($content['flag_follow_committee']); ?>
    </div>
    <?php else: ?>
    <div class="c-search-result--follow">
      <?php print drupal_render($content['flag_follow_issue']); ?>
    </div>
    <?php endif; ?>
  </div>
</div>
