  <div class="l-header-region l-row l-row--hero c-senator-hero">
    <div class="c-senator-hero--img">
      <?php //print $fields['field_image_hero']->content; ?>
      <img src="http://placekitten.com/g/700/525" />

    </div>
    <div class="c-senator-hero--info">
      <div>
        <?php //if($fields['field_active']->content !== 'active'): ?>
          <!--
          <p class="c-senator-hero--not-active">This Senator is no longer serving in the New York State Senate</p>
          <hr class="c-senator-hero--rule" />
          -->
        <?php //endif; ?>
        <h2 class="c-senator-hero--title">
          new york state senator
        </h2>
        <h3 class="c-senator-hero--name">
          Fake Madeupman
          <?php //echo $fields['title']->content;?>
        </h3>
        <div class="c-senator-hero--info-secondary">
          <p class="c-senator-hero--roles">
            <?php //echo $fields['field_active']->content !== 'active' ?  'Served from january 2011 - December 2013' : $fields['field_current_duties']->content; ?>
            political stuff, shaking hands
          </p>
          <p class="c-senator-hero--district"><?php if (!empty($abbreviations)) { echo '(' . $abbreviations . ')'; } ?> <a href="<?php echo $district_uri; ?>"><?php //echo $fields['field_district']->content; ?>District 11</a></p>

          <ul class="c-senator-hero--social">
            <li><a href="<?php echo $fields['field_facebook_url']->content; ?>" class="icon-replace__facebook">facebook</a></li>
            <li><a href="<?php echo $fields['field_twitter_url']->content; ?>" class="icon-replace__twitter">twitter</a></li>
            <li><a href="<?php echo $fields['field_youtube_url']->content; ?>" class="icon-replace__youtube">youtube</a></li>
          </ul>
        </div>
      </div>
    

    </div>
    <?php if($fields['field_active']->content === 'active'): ?>
      <a class="c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg" href="/contact/">contact senator</a>
    <?php else: ?>
      <a class="c-block--btn c-senator-hero--contact-btn icon-before__find-senator med-bg" href="/contact/">find your senator</a>
    <?php endif; ?>
  </div>