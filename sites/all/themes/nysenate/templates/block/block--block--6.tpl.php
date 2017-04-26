<section class="l-header-region l-row l-row--nav c-header-bar">
  <h1 class="c-page-title"><a href="/" rel="home" title="NY State Senate Home" class="active">The New York State Senate</a></h1>
  
  <div class="c-header--connect">
    <!-- if we're on the main site there are social buttons -->
    <ul class="c-nav--social u-tablet-plus">
      <li><a href="<?php //echo $fields['field_facebook_url']->content; ?>" class="icon-replace__facebook">facebook</a></li>
      <li><a href="<?php //echo $fields['field_twitter_url']->content; ?>" class="icon-replace__twitter">twitter</a></li>
      <li><a href="<?php //echo $fields['field_youtube_url']->content; ?>" class="icon-replace__youtube">youtube</a></li>
    </ul>
    <?php if ((in_array('administrator', $user->roles)): ?>
      <a class="icon-after__recruit-friends c-login u-tablet-plus" href="<?php global $base_url; echo $base_url.'/user/login'; ?>">login</a>
    <?php else: ?>
      <a class="icon-after__recruit-friends c-login u-tablet-plus"  data-dropdown="account_settings" aria-controls="account_settings" aria-expanded="false"><?php echo $user->name; ?></a>
      <?php if ($top_bar_secondary_menu) :?>
        <?php print $top_bar_secondary_menu; ?>
      <?php endif; ?>
    <?php endif; ?>
  </div>
</section>