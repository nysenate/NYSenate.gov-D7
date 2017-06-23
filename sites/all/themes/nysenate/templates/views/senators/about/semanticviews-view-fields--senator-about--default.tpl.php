<div class="c-block">
  <h2 class="c-subpage-header--title">About <?php print $fields['title']->content; ?></h2>
  <p class="c-subpage-header--subtitle01"><?php print $fields['field_current_duties']->content;?></p>
  <p class="c-subpage-header--subtitle02 lgt-text">
    <span class="u-mobile-only"><?php print $fields['field_party']->content; ?></span>
    <span class="u-tablet-plus"><?php print $fields['field_party']->content; ?></span>
  </p>
  <p class="c-subpage-header--subtitle03"><?php print $fields['field_district_number']->content; ?></p>

  <?php print $fields['field_image_main']->content; ?>

  <?php
  // Committees Block
  $committees_block = module_invoke('nys_blocks', 'block_view', 'senator_committees');
  print $committees_block['content'];
  ?>

  <h4 class="c-blockquote"><?php if (isset($fields['field_pull_quote']->content)) print $fields['field_pull_quote']->content; ?></h4>
  <?php print $fields['body']->content; ?>
</div>

<div class="c-block">
  <?php print $fields['field_chapters']->content; ?>
  <?php //print render($content['links']); ?>
</div>
