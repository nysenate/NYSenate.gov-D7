<?php if($fields['type']->content == 'Session'):?>

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
					<h3><a href="<?php echo $fields['path']->content; ?>">Session</a></h3>
					
					<div class="livestream-date"><?php echo $fields['field_date']->content; ?></div>
				</div>
				<div class="c-hero-livestream-sched">
				<?php if(isset($fields['field_ol_bill']->content)): ?>
					<label>What’s Being Discussed</label>	
						
							<?php echo $fields['field_ol_bill']->content; ?>
						
				<?php endif; ?>
				</div>
				<a class="c-hero-session-link" href="<?php echo $fields['path']->content; ?>">View Full Session</a>
		</div>
	</div>
</div>
<?php else: ?>

<div class="l-header-region l-row l-row--hero c-hero">
	<?php if(isset($fields['field_image_hero']->content)): ?>
    	<?php echo $fields['field_image_hero']->content; ?>
	<?php else: ?>
		<?php echo _nyss_img(variable_get('hero_default_path'), '1280x510', ''); ?>
	<?php endif; ?>
    <div class="l-row c-hero--tout c-hero--featured">
      <p class="c-hero--date"><?php echo $fields['field_date']->content; ?></p>
      <p class="c-hero--committee"><?php echo $fields['field_issues']->content; ?></p>
      <h3 class="c-hero--title"><?php echo $fields['title']->content; ?></h3>
    </div>
</div>
	<?php
    $related_issues_block = module_invoke('nys_blocks', 'block_view', 'sitewide_actionbar_block');
    print render($related_issues_block['content']);
  ?>

<?php endif; ?>