<div class="<?php print $classes; ?> c-senators-container">
  	<div class="c-members-title">Members</div>
</div>
<?php $path = drupal_lookup_path('alias','node/' . $content->vid); ?>
<div class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">
	<a href="/<?php print $path; ?>">
	<?php echo theme('image_style', array(
			'style_name' => '280x280',
			'path' => $content->field_image_main['und']['0']['uri'],
			'attributes' => array('class' => '')
	)); ?>
	</a>
	<div class="c-initiative--content">
	  <div class="c-initiative--inner">
		<a href="/<?php print $path; ?>"><h4 class="c-initiative--title"><?php echo $content->title; ?></h4></a>
	  </div>
	</div>
	<a href="<?php print $path; ?>" class="c-block--btn icon-before__contact med-bg">
	  <span>contact the senator</span>
	</a>
  </div>
</div>
