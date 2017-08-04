<!--.page -->
<div role="document" class="page gen_blue <?php if(!empty($pallette_class)) : echo $pallette_class; endif; ?>">
<!-- Main Conent from Homepage Panel -->
<?php print render($page['content']); ?>

<!-- Standard Footer -->
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
