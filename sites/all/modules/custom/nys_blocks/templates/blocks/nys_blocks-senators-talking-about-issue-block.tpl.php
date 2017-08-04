<div class="c-block c-issue--mentions">
	<h2 class="c-detail--subhead c-detail--section-title">Senators Talking About this Issue</h2>

    <?php if(count($senators) > 6): ?>
	    
	    <div class="initial_co-sponsors ">
			<?php for($i = 0; $i < 6; $i++): ?>
				<?php print $senators[$i]['markup']; ?>
			<?php endfor; ?>
	    </div>

	    <div class="other_co-sponsors">
            <dl class="c-block c-detail--actions accordion" data-accordion>
              <dd class="accordion-navigation">
                <a href="#accordion-11" class="accordion--btn nys-btn-more--bg" data-open-text="see less" data-closed-text="see more">see more</a>

                <div id="accordion-11" class="content">
	                <?php for($i = 6; $i < count($senators); $i++): ?>
	                	<?php print $senators[$i]['markup']; ?>
	                <?php endfor; ?>
                </div>
              </dd>
            </dl>
	    </div>

	<?php else: ?>

	    <div class="initial_co-sponsors c-issue--mentions">
			<?php foreach($senators as $nid => $senator): ?>
				<?php print $senator['markup']; ?>
			<?php endforeach; ?>
	    </div>

	<?php endif; ?>

</div>
