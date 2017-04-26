<div class="c-block c-block--chair c-block--chair__has-img lgt-bg">
    <?php echo _nyss_img($fields['uri']->content, '280x280', array()); ?>
    <div class="c-chair--content">
      <div class="c-chair--inner">
      	<p class="c-chair-block--position">Committee <?php echo $fields['field_committee_member_role']->content;?></p>
        <h4 class="c-chair--title"><?php echo $fields['title']->content;?></h4>
       	<div class="c-party-conf">
		<?php
			$party = $fields['field_party']->content;
			if(!empty($party)) $associations = explode(', ', $party);

			$conference_parts = explode (" ",$fields['field_conference']->content);			
			$conference ="";
			foreach($conference_parts as $index=>$part)
				if(($index != 0) && ($index%2 == 1)) $associations[] = substr($conference_parts[$index-1],0,1).substr($part,0,1);

			if(!empty($associations)) echo '('.implode(', ', $associations).')';
		?>
		<?php if(isset($fields['field_district_number']->content)):?>
			District <?php echo $fields['field_district_number']->content;?>
		<?php endif;?>
		</div>
      </div>
    </div>
    <a href="<?php echo $fields['path']->content;?>/message" class="c-block--btn icon-before__mail med-bg">contact senator</a>
 </div>