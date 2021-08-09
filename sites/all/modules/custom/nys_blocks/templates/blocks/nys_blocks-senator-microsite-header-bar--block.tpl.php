<section class="l-header-region l-row l-row--nav c-header-bar">
  <div class="c-topbar">
  
    <h1 class="c-page-title"><a href="/" rel="home" title="NY State Senate Home" class="active">The New York State Senate</a></h1>
    
    <div class="c-header--connect">

      <?php if ($user->uid == 0): ?>
        <a class="c-header--btn c-header--btn__primary u-tablet-plus" href="/user/login">login</a>
      <?php else: ?>
        <ul class="c-login--list u-tablet-plus">
          <li>
            <?php if (in_array('Senator', array_values($user->roles))) { ?>
              <a class="c-header--btn c-header--btn__primary <?php if(!is_null($user_avatar)){ echo 'has-avatar'; } ?>" href="<?php print $dashboard_link; ?>">
                <?php if(!is_null($user_avatar)): ?>
                  <span>My Dashboard</span>
                  <?php echo $user_avatar; ?>
                <?php else: ?>
                  My Dashboard
                <?php endif; ?>
              </a>
            <?php } else { ?>
              <a class="c-header--btn c-header--btn__primary <?php if(!is_null($user_avatar)){ echo 'has-avatar'; } ?>" href="<?php print $dashboard_link . '/issues'; ?>">
                <?php if(!is_null($user_avatar)): ?>
                  <span>My Dashboard</span>
                  <?php echo $user_avatar; ?>
                <?php else: ?>
                  My Dashboard
                <?php endif; ?>
              </a>
            <?php } ?>
          </li>

          <li class="c-login--edit">
            <a class="c-header--btn" href="/user/<?php echo $user->uid; ?>/edit">Edit Account</a>
          </li>
          
          <li class="c-login--logout">
            <a class="c-header--btn" href="/user/logout">Logout</a>
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
                <?php echo $senator_image; ?>
              </div>
            </div>
          </a>
        <?php endif; ?>
      <?php endif; ?>
    </div>
  </div>
</section>
