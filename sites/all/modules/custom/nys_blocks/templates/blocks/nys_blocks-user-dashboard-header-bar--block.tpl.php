<section class="l-header-region l-row l-row--nav c-header-bar">
  <?php if (in_array('Constituent', array_values($user->roles))) { ?>
    <h1 class="c-page-title"><?php print $dashboard_display_name; ?> Dashboard</h1>
  <?php } else { ?>
    <h1 class="c-page-title"><a href="/user/dashboard"><?php print $dashboard_display_name; ?> Senator Dashboard</a></h1>
  <?php } ?>
  <div class="c-header--connect">
    <a class="c-dashboard-header--btn" href="/">NYSenate.gov</a>
  </div>
  <button id="#bashboard-mobil-m" class="js-mobile-nav--btn c-block--btn c-nav--toggle u-mobile-only icon-replace"></button>
</section>