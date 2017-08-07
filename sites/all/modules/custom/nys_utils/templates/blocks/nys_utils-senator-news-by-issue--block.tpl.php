	<?php
	if (is_array($content)):
		$first_item = $content[key($content)];

		/*
		* Does any content contain an image_main?  Rotate through and see, if so,
		* the first one with an image should be shown in DIV.l-left below, along with up
		* to three other articles in DIV.l-right.
		* If no content contains images, then the display should be different.
		*/

		$display_large_image = false;

		foreach($content as $content_key => $item):
			if (!empty($item->field_image_main)):
				$first_item = $content[$content_key];
				$already_displayed_key = $content_key;
				$display_large_image = true;
				break;
			endif;
		endforeach;
	?>
		<!-- BEGIN Featured Issue -->
		<div class="<?php $display_large_image ? print 'c-event-cluster c-event-cluster-featured-issue' : print 'c-container c-news-container'; ?>">
			<?php $display_large_image == false ? print '<div class="view-content">' : print ''; ?>
			<div class="c-container--header">
				<h2 class="c-container--title">Featured Issue: <a href="/<?php echo $issue->path; ?>"><?php echo $issue->name; ?></a></h2>
			</div>

			<?php if($display_large_image): ?>
				<div class="l-left">
					<a class="c-link <?php echo (!isset($first_item->thumb) ? '' : 'c-link-with-image'); ?>" href="/<?php echo $first_item->path; ?>">
						<?php echo _nyss_img($first_item->field_image_main[LANGUAGE_NONE]['0']['uri'], '440x230', 'c-event-image'); ?>
					</a>
					<a class="" href="/<?php echo $first_item->path; ?>">
						<h3 class="c-link-title"><?php echo $first_item->title; ?></h3>
						<?php print $item->issues_content; ?>
					</a>
				</div>
			<div class="l-right">
				<?php if (is_array($content)): ?>
				  <?php foreach($content as $key => $item): ?>
					<?php if($key !== $already_displayed_key):?>
					<a class="c-link <?php echo (!isset($item->thumb) ? '' : 'c-link-with-image'); ?>" href="/<?php echo $item->path; ?>">
						<?php if (isset($item->field_image_main[LANGUAGE_NONE]['0']['uri'])):?>
							<?php echo _nyss_img($item->field_image_main[LANGUAGE_NONE]['0']['uri'], '80x60', 'c-link-image'); ?>
						<?php endif;?>
						<h3 class="c-link-title"><?php echo $item->title; ?></h3>
						<?php print $item->issues_content; ?>
					</a>
					<?php endif;?>
				  <?php endforeach; ?>
				<?php endif; ?>
			</div>
			<?php else:
				$i = 1;
				foreach ($content as $key => $item): ?>
					<div class="c-news-block <?php $i == 1 ? print 'first' : print ''; ?> <?php $i == sizeof($content) ? print 'last' : print ''; ?> u-<?php $i % 2 == 0 ? print 'even' : print 'odd'; ?>">
						<div class="c-title"><?php print str_replace('_', ' ', $item->type); ?></div>
						<div class="c-newsroom-name">
							<a href="/<?php print $item->path; ?>"><?php print $item->title; ?></a>
						</div>
						<?php print $item->issues_content; ?>
					</div>
			<?php
					$i++;
				endforeach;
			endif;
			?>

			<?php $display_large_image == false ? print '</div>' : print ''; ?>
		</div>
	<!-- END Featured Issue -->
<?php endif; ?>


