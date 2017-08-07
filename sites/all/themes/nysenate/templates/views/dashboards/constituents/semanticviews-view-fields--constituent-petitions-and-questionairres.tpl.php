<?php

$node_url = url('node/'.$row->nid, array('absolute' => TRUE));
$node_title = $row->node_title;

$tids = array();
if(!empty($row->_field_data['nid']['entity']->field_issues[LANGUAGE_NONE])) {

  foreach($row->_field_data['nid']['entity']->field_issues[LANGUAGE_NONE] as $key => $item) {
    $tids[] = '&f[' . ($key+1) . ']=im_field_issues%3A' . $item['tid'];
  }
}

switch($view->current_display) {
	case 'constituent_petitions_signed':
		$promote_text = 'Promote this Petition';
		$explore_text = 'Explore related Petitions';
    if(!empty($tids)) {
		  $explore_link = '/search/global/?f[0]=bundle%3Apetition'.implode('', $tids);
    }
		$view_type = 'petitions';
	break;

	default:
		$promote_text = 'Promote this Questionnaire';
		$explore_text = 'Explore related Questionnaires';
    if(!empty($tids)) {
		  $explore_link = '/search/global/?f[0]=bundle%questionnaire'.implode('', $tids);
    }
		$view_type = 'questionnaire';
	break;
}

$start_time = $row->_field_data['nid']['entity']->field_date[LANGUAGE_NONE][0]['value'];
$end_time = $row->_field_data['nid']['entity']->field_date[LANGUAGE_NONE][0]['value2'];

if((($start_time < time() && $end_time > time()) || ($start_time < time() && is_null($end_time)) || ($start_time == $end_time)) && $row->_field_data['nid']['entity']->status == 1) {
  $petition_is_active = 1;
}
else {
  $petition_is_active = 0;
}
?>

<article>
	<div class="pet-body">
		<h3 class="entry-title"><?php echo $fields['title']->content; ?></h3>
		<div class="pet-type"><?php echo $fields['field_issues']->content; ?></div>
		<div class="author"><?php echo $fields['field_senator']->content; ?></div>
		<?php if($view_type == 'petitions'): ?><div class="article-date"><?php echo $fields['timestamp']->content; ?></div><?php endif; ?>
		<?php if($view_type == 'questionnaire'): ?><div class="article-date"><?php echo 'Signed on '.date('F d, Y', $row->field_timestamp); ?></div><?php endif; ?>
	</div>
	<div class="pet-share-bar">
		<?php if($petition_is_active): ?>
		<p><?php echo $promote_text;?></p>
		<a href="https://www.facebook.com/sharer/sharer.php?u=<?php echo $node_url;?>" class="pet-facebook-share icon-after__facebook"></a>
		<a href="http://twitter.com/share?url=<?php echo $node_url;?>&text=<?php echo $node_title;?>" class="pet-twitter-share icon-after__twitter"></a>
		<?php else: ?>
		<p>This Petition is No Longer Active</p>  
		<?php endif; ?>
		<?php if (!empty($explore_link)): ?>
		  <a href="<?php echo $explore_link; ?>" class="explore-link icon-after__right"><?php echo $explore_text; ?></a>
		<?php endif; ?>
	</div>
</article>
