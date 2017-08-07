<?php global $user; ?>

<div class="comm-follow-widget">
  <h3><?php echo $fields['name']->content; ?></h3>
  <?php
  $committee                 = taxonomy_term_load($fields['tid']->content);
  $follow_committee_or_group = $committee->field_assemblymen_chair[LANGUAGE_NONE][0]['value'] == '1' ? 'follow_group' : 'follow_committee';
  if(!senator_viewing_constituent_dashboard() && !(arg(0) == 'user' && arg(2) == 'dashboard' && $user->uid != arg(1))) {
    echo flag_create_link($follow_committee_or_group, $fields['tid']->content);
  }
  ?>
</div>