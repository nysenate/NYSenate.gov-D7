<article>


		<h2 class="c-subpage-header--title">About <?php print $fields['title']->content; ?></h2>
		<p class="c-subpage-header--subtitle01"><?php print $fields['field_current_duties']->content; ?></p>
		<p class="c-subpage-header--subtitle02 lgt-text">
			<span class="u-mobile-only">(R, C, IP)</span>
			<span class="u-tablet-plus">republican, conservative, independence</span>
		</p>
		<p class="c-subpage-header--subtitle03">9th senate district</p>


		<?php print $fields['field_image_main']->content; ?>

		<div class="l-row c-listing-block">
			<h3>Committees</h3>
			<div class="l-col l-col-3">
				<div class="c-listing-block--item">
					<a class="lgt-text">Rules</a>
					<span>chair</span>
				</div>
				<div class="c-listing-block--item">
					<a class="lgt-text">Veterans, Homeland Security & Military Affairs</a>
					<span>CO-CHAIR</span>
				</div>
			</div>
			<div class="l-col l-col-3">
				<div class="c-listing-block--item">
					<a class="lgt-text">Commerce, Economic Development & Small Business</a>
				</div>
				<div class="c-listing-block--item">
					<a class="lgt-text">Crime Victims, Crime & Correction</a>
				</div>
				<div class="c-listing-block--item">
					<a class="lgt-text">Finance</a>
				</div>
			</div>
			<div class="l-col l-col-3">
				<div class="c-listing-block--item">
					<a class="lgt-text">Health</a>
				</div>
				<div class="c-listing-block--item">
					<a class="lgt-text">Hudson Valley Delegation</a>
				</div>
				<div class="c-listing-block--item">
					<a class="lgt-text">Judiciary</a>
				</div>
				<div class="c-listing-block--item">
					<a class="lgt-text">Social Services</a>
				</div>
			</div>
		</div>

		<h4 class="c-blockquote"><?php print $fields['field_pull_quote']->content; ?></h4>

		<?php print $fields['body']->content; ?>
		<?php print $fields['field_chapters']->content; ?>

</article>
