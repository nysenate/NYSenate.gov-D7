<div class="c-block c-block--chair c-block--chair__has-img lgt-bg">
    <?php echo $fields['field_image_headshot']->content;?>
    <div class="c-chair--content">
      <div class="c-chair--inner">
      	<p class="c-chair-block--position">Committee Chair</p>
        <h4 class="c-chair--title"><?php echo $fields['title']->content;?></h4>
       	<div class="c-party-conf">
		<?php
			$party = $fields['field_party']->content;
			$conference_parts = explode (" ",$fields['field_conference']->content);
			$conference ="";
			foreach($conference_parts as $part)
				$conference .= substr($part,0,1);
			echo "(".$party.",".$conference.") ";
		?>
		<?php echo $fields['field_district']->content;?>
		</div>
      </div>
    </div>
    <a href="<?php echo $fields['path']->content;?>" class="c-block--btn icon-before__mail med-bg">contact senator</a>
 </div>