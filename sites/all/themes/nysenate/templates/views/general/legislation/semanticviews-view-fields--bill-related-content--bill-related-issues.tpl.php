<?php 
  //check to see if we are on a node page.
  ctools_include('modal');
  ctools_include('ajax');

  // Add CTools' javascript to the page.
  ctools_modal_add_js();

  drupal_add_js(array(
    'login-modal' => array(
      'modalSize' => array(
        'type' => 'fixed',
        'width' => 760,
        'height' => 620,
      ),
      'modalOptions' => array(
        'opacity' => 0.85,
        'background' => '#000',
      ),
      'animation' => 'fadeIn',
      'closeText' => t('X'),
      'throbber' => theme('image', array('path' => ctools_image_path('throbber.gif', 'nys_registration'), 'alt' => t('Loading...'), 'title' => t('Loading'))),
      'closeImage' => theme('image', array('path' => ctools_image_path('modal-close.png', 'nys_registration'), 'alt' => t('Close window'), 'title' => t('Close window'), 'class' => 'img-loader')),
    ),
  ), 'setting');

  
  // Add CTools' javascript to the page.
  ctools_add_css('login_modal', 'nys_registration');
  ctools_add_js('login_modal', 'nys_registration');
 ?>
 
<h4 class="c-issue-block--title"><?php echo $fields['name']->content; ?></h4>
<div class="c-block--btn">
<?php if ($user->uid === 0): ?>
	<?php echo ctools_modal_text_button(t('follow this issue'), 'nys_registration/nojs/login', t('follow this issue'), 'ctools-modal-login-modal');?>
<?php else: ?>
	<?php echo flag_create_link('follow_issue', $fields['tid']->content); ?>
<?php endif; ?>
</div>