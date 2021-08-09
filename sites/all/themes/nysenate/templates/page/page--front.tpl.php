<!--.page -->
<div role="document" class="page">

	<?php if ($messages && !$zurb_foundation_messages_modal): ?>
		<!--.l-messages -->
		<section class="l-messages">
			<?php if ($messages): print $messages; endif; ?>
		</section>
		<!--/.l-messages -->
	<?php endif; ?>
	<!-- Main Conent from Homepage Panel -->
	<?php print render($page['content']); ?>
</div>
<!--/.page -->
