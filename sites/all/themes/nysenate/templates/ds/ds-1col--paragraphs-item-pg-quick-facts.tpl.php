
<div class="c-block c-stats--container c-senate-quick-facts--container <?php print $classes; ?>">
  <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <div class="c-container--header">
		<h3 class="c-container--title"><?php echo $content['field_pg_quickfacts_title'][0]['#markup']; ?></h3>
	</div>
	<span class="c-stats--highlight u-mobile-only"></span>

  <div class="c-carousel--nav u-mobile-only">
		<button class="c-carousel--btn prev hidden">prev</button>
		<button class="c-carousel--btn next">next</button>
	</div>
  <ul id="js-carousel-about-stats" class="js-carousel c-carousel <?php echo $content['field_pg_quick_facts_cols'][0]['#markup']; ?>">
    <?php print render($content['field_pg_fc_quick_facts']); ?>
  </ul>
</div>
