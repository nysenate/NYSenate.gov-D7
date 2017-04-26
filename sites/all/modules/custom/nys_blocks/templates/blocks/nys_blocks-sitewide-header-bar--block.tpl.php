
<section class="l-header-region l-row l-row--nav c-header-bar">
    <div class="c-topbar">

      <h1 class="c-page-title"><a href="/" rel="home" title="NY State Senate Home" class="active">The New York State Senate</a></h1>

      <div class="c-header--connect">
        <!-- if we're on the main site there are social buttons -->
        <ul class="c-nav--social u-tablet-plus">
            <li><a href="https://www.facebook.com/nysenate" class="icon-replace__facebook" target="_blank">facebook</a></li>
            <li><a href="https://www.twitter.com/nysenate"  class="icon-replace__twitter" target="_blank">twitter</a></li>
            <li><a href="https://www.youtube.com/user/NYSenate" class="icon-replace__youtube" target="_blank">youtube</a></li>
        </ul>

        <?php if ($user->uid == 0): ?>
          <a class="c-header--btn c-header--btn__primary u-tablet-plus" href="/user/login">login</a>
        <?php else: ?>
          <ul class="c-login--list u-tablet-plus">
            <li>
            <?php if (in_array('Senator', array_values($user->roles))) { ?>
              <a class="c-header--btn c-header--btn__primary <?php if(!is_null($user_avatar)){ print 'has-avatar'; } ?>" href="<?php print $dashboard_link; ?>">
                <?php if(!is_null($user_avatar) && $unread_messages == 0): ?>
                  <span>My Dashboard</span>
                  <?php print $user_avatar; ?>
                <?php elseif(!is_null($user_avatar) && $unread_messages > 0): ?>
                  <span>My Dashboard (<?php print $unread_messages; ?>)</span>
                  <?php print $user_avatar; ?>
                <?php elseif($unread_messages > 0): ?>
                  My Dashboard (<?php print $unread_messages; ?>)
                <?php else: ?>
                  My Dashboard
                <?php endif; ?>
              </a>
            <?php } else { ?>
              <a class="c-header--btn c-header--btn__primary <?php if(!is_null($user_avatar)){ print 'has-avatar'; } ?>" href="<?php print $dashboard_link . '/issues'; ?>">
                <?php if(!is_null($user_avatar) && $unread_messages == 0): ?>
                  <span>My Dashboard</span>
                  <?php print $user_avatar; ?>
                <?php elseif(!is_null($user_avatar) && $unread_messages > 0): ?>
                  <span>My Dashboard (<?php print $unread_messages; ?>)</span>
                  <?php print $user_avatar; ?>
                <?php elseif($unread_messages > 0): ?>
                  My Dashboard (<?php print $unread_messages; ?>)
                <?php else: ?>
                  My Dashboard
                <?php endif; ?>
              </a>
            <?php } ?>
            </li>
            <li class="c-login--edit">
              <a class="c-header--btn" href="<?php print url('user/' . $user->uid . '/edit'); ?>">Edit Account</a>
            </li>
            <li class="c-login--logout">
              <a class="c-header--btn" href="/user/logout?destination=<?php print drupal_get_path_alias(); ?>">Logout</a>
            </li>
            <?php if (user_access('Access Admin Link in Dashboard')): ?>
              <li class="c-login--admin">
                <a class="c-header--btn" href="/admin/dashboard">Admin</a>
              </li>
            <?php endif; ?>
          </ul>
          <?php if($senator_nid): ?>
            <a class="c-header--btn c-senator-header--btn" href="<?php print $senator_microsite_link; ?>">
              <div class="nys-senator">
                <div class="nys-senator--info">
                  <h3 class="nys-senator--title">My Senator</h3>
                </div>
                <div class="nys-senator--thumb">
                  <?php print $senator_image; ?>
                </div>
              </div>
            </a>
          <?php endif; ?>
        <?php endif; ?>
      </div>

    </div>
  </section>
  <!--.c-header-bar -->

  <button id="" class="js-mobile-nav--btn c-block--btn c-nav--toggle u-mobile-only icon-replace"></button>
    <?php if(user_is_logged_in() && $unread_messages > 0): ?><div class="messages-number"><?php print $unread_messages; ?></div><?php endif; ?>

  <div class="c-nav--wrap">
    <div class="c-nav l-row l-row--nav">

      <nav>
        <?php
        $main_menu['content'] = menu_tree('main-menu');
        $main_menu['content']['#contextual_links']['menu'] = array('admin/structure/menu/manage', array('main-menu'));
        print render($main_menu['content']);
        ?>

        <div class="u-mobile-only">
          <?php
            $search_box = module_invoke('apachesolr_search_blocks', 'block_view', 'core_search');
            print render($search_box['content']);
          ?>
        </div>

        <button class="js-search--toggle u-tablet-plus c-site-search--btn">search</button>

        <ul class="c-nav--social u-mobile-only">
          <li><a href="https://www.facebook.com/NYsenate" class="icon-replace__facebook" target="_blank">facebook</a></li>
          <li><a href="https://twitter.com/nysenate"  class="icon-replace__twitter" target="_blank">twitter</a></li>
          <li><a href="https://www.youtube.com/user/NYSenate" class="icon-replace__youtube" target="_blank">youtube</a></li>
        </ul>

        <div class="c-mobile-login--list u-mobile-only">
        <?php if ($user->uid == '0'): ?>
          <span class="c-header--btn c-header--btn-login">
            <a href="/user/login">login</a>
          </span>
        <?php else: ?>
          <a href="<?php print $dashboard_link . '/issues'; ?>" class="c-header--btn c-header--btn-login <?php if(!is_null($user_avatar)){ print 'has-avatar'; } ?>">
              <?php if(!is_null($user_avatar) && $unread_messages > 0): ?>
                <?php print $user_avatar; ?>
                <span>My Dashboard (<?php print $unread_messages; ?>)</span>
              <?php elseif($unread_messages > 0): ?>
                My Dashboard (<?php print $unread_messages; ?>)
              <?php else: ?>
                My Dashboard
              <?php endif; ?>
          </a>
          <?php if($senator_nid): ?>
            <a class="c-header--btn c-header--btn-senator" href="<?php print $senator_microsite_link; ?>">
              <div class="nys-senator">
                <div class="nys-senator--thumb">
                  <?php print $senator_image; ?>
                </div>
                <div class="nys-senator--info">
                  <h3 class="nys-senator--title">Your Senator</h3>
                  <h4 class="nys-senator--name"><?php print $senator_name; ?></h4>
                </div>
              </div>
            </a>
          <?php endif; ?>
          <a class="c-header--btn c-header--btn-edit" href="/user/<?php print $user->uid; ?>/edit">Edit Account</a>
          <a href="/user/logout" class="c-header--btn c-header--btn-logout">logout</a>
        <?php endif; ?>
        </div>
      </nav>
    </div>
    <div class="u-tablet-plus">
    <?php
      $search_box = module_invoke('apachesolr_search_blocks', 'block_view', 'core_search');
      print render($search_box['content']);
    ?>
    </div>
  </div>
