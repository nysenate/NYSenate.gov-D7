<?php if($content['position_index'] == 0) :?>
<?php $url_ext = ((arg(1) == 'term') && (is_numeric(arg(2)))) ? '/?f[0]=im_field_committee%3A'.arg(2).'&f[1]=bundle%3Abill' : '';?>
<div class="c-container--header__top-border">
	<h3 class="c-container--title search">Featured Legislation</h3>
	<a href="/search/global<?php echo $url_ext;?>" class="nys-arrow-link">See all legislation</a>
</div>
<?php endif; ?>
<?php //echo '<pre>';print_r(array_keys($content['field_featured_bill'][0]['node'])); die();
$bill_id = (isset($content['field_featured_bill'])) ? array_keys($content['field_featured_bill'][0]['node']) : FALSE;

if($bill_id === FALSE) $path = '';
else $path = $GLOBALS['base_url'].'/'.drupal_get_path_alias('node/'.$bill_id[0], array('absolute' => TRUE));

$collapsed = ($content['position_index'] == 0) ? '' : 'c-block__collapsed';
$title = $content['field_featurer_senator']['#items'][0]['entity']->title;
$senator_last_name = explode(' ', $title);
$senator_last_name = end($senator_last_name);
?>
<section class="c-block c-block-legislation c-block-legislation-featured <?php echo $collapsed; ?>">
	
      <button class="js-leg-toggle c-block--btn c-block--btn-toggle">close</button>
      <div class="c-social">
        <ul class="c-social--list">
          <li><a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php echo $path;?>" class="icon-replace__facebook">facebook</a></li>
          <li><a target="_blank" href="http://twitter.com/share?url=<?php echo $path;?>" class="icon-replace__twitter">twitter</a></li>
        </ul>
      </div>
      
		<?php print drupal_render($content['field_featured_bill']); ?>
		<div class="c-legislation--quote">
	      <div class="c-quote--content">
	        <p class="c-pullquote icon-before__quotes">
	          <?php echo $content['field_featured_quote'][0]['#markup'];?>"
	        </p>
	        <span class="c-pullquote--citation icon-before__minus">senator <?php echo $senator_last_name;?>'s Position</span>
	        <div class="c-legislation--sponsor">
	        	<?php print drupal_render($content['field_featurer_senator']); ?>
	        </div>
	      </div>
	    </div>
</section>
