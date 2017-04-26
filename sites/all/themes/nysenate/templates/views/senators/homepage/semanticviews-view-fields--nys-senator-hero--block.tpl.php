<?php
/**
 * @file semanticviews-view-fields.tpl.php
 * Default simple view template to display all the fields as a row. The template
 * outputs a full row by looping through the $fields array, printing the field's
 * HTML element (as configured in the UI) and the class attributes. If a label
 * is specified for the field, it is printed wrapped in a <label> element with
 * the same class attributes as the field's HTML element.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output
 *     safe.
 *   - $field->element_type: The HTML element wrapping the field content and
 *     label.
 *   - $field->attributes: An array of attributes for the field wrapper.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use var_export to dump this object, as it can't handle the
 *     recursion.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @see template_preprocess_semanticviews_view_fields()
 * @ingroup views_templates
 * @todo Justify this template. Excluding the PHP, this template outputs angle
 * brackets, the label element, slashes and whitespace.
 */
//check to see if we are on a node page.


// Add CTools' javascript to the page.


$senator_microsite_link = substr(url('node/' . $row->nid),1);
?>

<div id="largeShotImage" style="display:none;">
      <?php if(!empty($fields['field_image_hero']->content)) {; ?>
        <?php print $fields['field_image_hero']->content; ?>
      <?php } else {; ?>
        <img src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/default-senator-image.png">
      <?php } ?>
</div>

<div id="smallShotImage" style="display:none;">
      <?php if(!empty($fields['field_image_headshot']->content)) {; ?>
        <?php print $fields['field_image_headshot']->content; ?>
      <?php } else {; ?>
        <img src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/default-senator-image.png">
      <?php } ?>
</div>


<div class="<?php print $classes; ?>">
  <div class="l-header-region l-row l-row--hero c-senator-hero">
    <?php if (arg(2)) : ?>
      <a href="/<?php echo $senator_microsite_link; ?>">
    <?php endif; ?>
    <div class="c-senator-hero--img" id="senatorImage">
      <?php if(!empty($fields['field_image_hero']->content)) {; ?>
        <?php print $fields['field_image_hero']->content; ?>
      <?php } else {; ?>
        <img src="<?php print base_path() . drupal_get_path('theme', 'nysenate'); ?>/images/default-senator-image.png">
      <?php } ?>
    </div>
    <?php if (arg(2)): ?>
      </a>
    <?php endif; ?>

    <div class="c-senator-hero--info">
      <div>
        <h2 class="c-senator-hero--title"><?php if($fields['field_active']->content !== 'active'): ?>former <?php endif; ?>new york state senator</h2>
        <h3 class="c-senator-hero--name"><?php echo $fields['title']->content;?></h3>
        <div class="c-senator-hero--info-secondary">
          <p class="c-senator-hero--roles">

            <?php echo $fields['field_active']->content !== 'active' ?  $fields['field_inactive_senator_message']->content : $fields['field_current_duties']->content; ?>

          </p>
          <p class="c-senator-hero--district">
            <?php if(isset($fields['field_party']->content) || isset($fields['field_conference']->content)): ?>
              <span class="c-senator-hero--party">
                (
                <?php echo $fields['field_party']->content; ?>
                )
              </span>
            <?php endif; ?>
            <?php if(isset($fields['field_district_number'])): ?>
            <a href="/district/<?php echo $fields['field_district_number']->content;?>"><?php echo nys_utils_ordinal_suffix($fields['field_district_number']->content) . ' Senate District';?></a>
             <?php endif; ?>
          </p>

          <ul class="c-senator-hero--social">
	          <?php if(!empty($fields['field_facebook_url']->content)): ?>
            <li class="c-senator-hero--social-item facebook"><a href="<?php echo $fields['field_facebook_url']->content; ?>" target="_blank" class="icon-replace__facebook">facebook</a></li>
            <?php endif; ?>
            <?php if(!empty($fields['field_twitter_url']->content)): ?>
            <li class="c-senator-hero--social-item twitter"><a href="<?php echo $fields['field_twitter_url']->content; ?>" target="_blank" class="icon-replace__twitter">twitter</a></li>
            <?php endif; ?>
            <?php if(!empty($fields['field_youtube_url']->content)): ?>
            <li class="c-senator-hero--social-item youtube"><a href="<?php echo $fields['field_youtube_url']->content; ?>" target="_blank" class="icon-replace__youtube">youtube</a></li>
            <?php endif; ?>
            <?php if(!empty($fields['field_instagram_url']->content)): ?>
              <li class="c-senator-hero--social-item instagram"><a href="<?php echo $fields['field_instagram_url']->content; ?>" target="_blank" class="icon-replace__instagram2">instagram</a></li>
            <?php endif; ?>
          </ul>
        </div>
      </div>
    </div>
    <?php if ($user->uid === 0): ?>
      <?php if ($fields['field_active']->content === 'active'): echo l(t('message senator'), '/registration/nojs/form/start/message-senator', array(
          'external' => TRUE,
          'attributes' => array(
            'class' => array(
              'c-block--btn',
              'c-senator-hero--contact-btn',
              'icon-before__contact med-bg'
            )
          ),
          'query' => array(
            'senator' => $fields['nid']->content
          )
        )
      ) ?>
      <?php else: ?>
        <a href="/user/login/find-my-senator" class="c-block--btn c-senator-hero--contact-btn icon-before__find-senator med-bg">find your senator</a>
      <?php endif; ?>
    <?php else: ?>
      <?php if($fields['field_active']->content === 'active'): ?>
        <a class="c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg" href="/<?php print $senator_microsite_link . '/message'; ?>">message senator</a>
      <?php else: ?>
        <a class="c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg" href="<?php echo '/users/' . $user->name . '/dashboard/issues'; ?>">your dashboard</a>
      <?php endif; ?>
    <?php endif; ?>

  </div>

</div>
<?php /* class view */ ?>
