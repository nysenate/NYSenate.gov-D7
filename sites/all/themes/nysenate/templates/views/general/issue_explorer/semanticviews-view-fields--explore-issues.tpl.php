<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
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

<h4 class="c-issue-block--title"><a href="<?php echo $fields['path_alias']->content; ?>"><?php echo $fields['label']->content; ?></a></h4>
<?php if($user && $user->uid !== 0): ?>
	<div class="c-block--btn">  
	  <?php echo flag_create_link('follow_issue', $fields['entity_id']->content); ?>
	</div>
<?php else: ?>
	<div class="c-block--btn">
    <a href="/registration/nojs/form/start/follow-issue/deploytest/<?php echo urlencode($fields['label']->content); ?>" class="ctools-use-modal ctools-modal-login-modal flag-action ctools-use-modal-processed">follow this issue</a>
	</div>
<?php endif; ?>

