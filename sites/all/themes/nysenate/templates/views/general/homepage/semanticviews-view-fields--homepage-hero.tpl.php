<?php if ($fields['type']->content == 'Session'): ?>

    <div class="l-row--hero-live">
      <?php
      $related_issues_block = module_invoke('nys_blocks', 'block_view', 'sitewide_actionbar_block');
      print render($related_issues_block['content']);
      ?>
    </div>
    <div class="l-header-region l-row l-row--hero c-hero">
        <div class="c-hero-livestream-wrapper">
            <div class="c-hero-livestream-video">
              <?php if (!empty($streaming_redirect)): ?>
                <?php echo $streaming_redirect; ?>
              <?php elseif (isset($fields['field_ustream_url']->content)): ?>
                <?php echo $fields['field_ustream_url']->content; ?>
              <?php elseif (isset($fields['field_ustream']->content)): ?>
                <?php echo $fields['field_ustream']->content; ?>
              <?php endif; ?>

            </div>
            <div class="c-hero-livestream-data">
                <div class="c-hero-livestream-meta">
                    <label>Live Broadcast</label>
                    <h3><a href="<?php echo $fields['path']->content; ?>">Session</a>
                    </h3>

                    <div class="livestream-date"><?php echo $fields['field_date']->content; ?></div>
                </div>
                <div class="c-hero-livestream-description">
                    <div>Live floor proceedings of the New York State Senate,
                        taking place at the NY State Capitol
                        in Albany, NY.
                    </div>
                    <ul class="c-hero-livestream-links">
                        <li><?php echo l('Review the active list, calendar, and other agenda items.', $fields['path']->content); ?></li>
                        <li><?php echo l('Review the senate rules.', '/rules'); ?></li>
                        <li><a href="https://twitter.com/nysenate">Follow along
                                with session proceedings on Twitter.</a></li>
                        <li><?php echo l('Learn more about the NY State Senate.', '/about'); ?></li>
                        <li><a href="/citizen-guide/bill-alerts"><strong style="color:#A84535">NEW: </strong>Short on time? Get bill status alerts in your email inbox.</a></li>
                    </ul>
                    <div><?php echo l('Learn more', '/taking-action'); ?> about how you can participate in NY's legislative process with
                      <?php echo l(' NYSenate.gov.', '/register'); ?>
                    </div>

                </div>
            </div>
        </div>
    </div>
<?php else: ?>

    <div class="l-header-region l-row l-row--hero c-hero">
      <?php if (isset($fields['field_image_hero']->content)): ?>
        <?php echo $fields['field_image_hero']->content; ?>
      <?php else: ?>
        <?php echo _nyss_img(variable_get('hero_default_path'), '1280x510', ''); ?>
      <?php endif; ?>
        <div class="l-row c-hero--tout c-hero--featured">
            <p class="c-hero--date"><?php echo $fields['field_date']->content; ?></p>
            <p class="c-hero--committee"><?php echo $fields['term_node_tid']->content; ?></p>
            <h3 class="c-hero--title"><?php echo $fields['title']->content; ?></h3>
        </div>
    </div>
  <?php
  $related_issues_block = module_invoke('nys_blocks', 'block_view', 'sitewide_actionbar_block');
  print render($related_issues_block['content']);
  ?>

<?php endif; ?>
