<!--.page -->
<div role="document" class="page <?php if(!empty($pallette_class)) : echo $pallette_class; endif; ?>">

  <?php if (!empty($page['header'])): ?>
    <header id="js-sticky" role="banner" class="l-header l-header__collapsed">
      <?php print render($page['header']); ?>
    </header>
    <!--/.l-header-region -->
  <?php endif; ?>

  <?php if (!empty($page['hero'])): ?>
      <?php print render($page['hero']); ?>
    <!--/.l-header-region -->
  <?php endif; ?>


<?php if (!empty($page['featured'])): ?>
  <!--.featured -->
  <section class="l-featured row">
    <div class="large-12 columns">
      <?php print render($page['featured']); ?>
    </div>
  </section>
  <!--/.l-featured -->
<?php endif; ?>
<?php if ($messages && !$zurb_foundation_messages_modal): ?>
  <!--.l-messages -->
  <section class="l-messages">
    <div class="large-12 columns">
      <?php if ($messages): print $messages; endif; ?>
    </div>
  </section>
  <!--/.l-messages -->
<?php endif; ?>
<?php if (!empty($page['help'])): ?>
  <!--.l-help -->
  <section class="l-help row">
    <div class="large-12 columns">
      <?php print render($page['help']); ?>
    </div>
  </section>
  <!--/.l-help -->
<?php endif; ?>

<main role="main" class="l-row l-row--main l-main">
  <div class="<?php print $main_grid; ?> <!--main columns-->">
    <?php if (!empty($page['highlighted'])): ?>
      <div class="highlight panel callout">
        <?php print render($page['highlighted']); ?>
      </div>
    <?php endif; ?>

    <a id="main-content"></a>
    <?php print render($page['content']); ?>
  </div>
  <!--/.l-main region -->

  <?php if (!empty($page['sidebar_first'])): ?>
    <aside role="complementary" class="<?php print $sidebar_first_grid; ?> l-sidebar-first columns sidebar">
      <?php print render($page['sidebar_first']); ?>
    </aside>
  <?php endif; ?>

  <?php if (!empty($page['sidebar_second'])): ?>
    <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> l-sidebar-second columns sidebar">
      <?php print render($page['sidebar_second']); ?>
    </aside>
  <?php endif; ?>
</main>
<!--/.l-main-->

<?php if (!empty($page['footer_first']) || !empty($page['footer_middle']) || !empty($page['footer_last'])): ?>
	<!--.l-footer-->
	<footer class="l-footer" role="contentinfo">
		<?php if (!empty($page['footer_first'])): ?>
			<div id="footer-first">
				<?php print render($page['footer_first']); ?>
			</div>
		<?php endif; ?>
		<?php if (!empty($page['footer_middle'])): ?>
			<div id="footer-middle">
				<?php print render($page['footer_middle']); ?>
			</div>
		<?php endif; ?>
		<?php if (!empty($page['footer_last'])): ?>
			<div id="footer-last">
				<?php print render($page['footer_last']); ?>
			</div>
		<?php endif; ?>
	</footer>
	<!--/.footer-->
<?php endif; ?>
</div>
<!--/.page -->