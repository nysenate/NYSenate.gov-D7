<?php if (!empty($status)): ?>
<div class="c-senate-status">
  The New York State Senate is: <span class="c-status-text"><?php echo strtoupper($status); ?></span>
</div>
<?php endif; ?>
<!-- START SHOWING THE SENATOR ACTIONBAR ON INTERIOR SECTIONS OF THE SENATOR'S MICROSITE -->
<?php if (($type === 'senator') || ($type === 'districts' && $content->senator_is_active == '1')): ?>
<div class="l-row l-row--hero c-actionbar c-actionbar--loggedin">
  <div class="nys-senator">
    <div class="nys-senator--thumb">
      <?php echo $content->senator_headshot; ?>
    </div>
    <div class="nys-senator--info">
      <h3 class="nys-senator--title">NEW YORK STATE SENATOR</h3>
      <a href="/<?php echo $content->action_url; ?>"><h2 class="nys-senator--name"><?php echo $content->title; ?></h2></a>
    </div>
  </div>
  <!-- Check login state for action url -->
  <?php if($user && $user->uid !== '0'): ?>
    <span>
      <a href="contact_logged_in" class="c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg">contact senator</a>
    </span>
  <?php else:?>
    <span>
      <?php echo ctools_modal_text_button(t('contact senator'), 'registration/nojs/login', t('contact senator'), 'c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg');?>
    </span>
  <?php endif; ?>
</div>
<!-- END SHOWING THE SENATOR ACTIONBAR ON INTERIOR SECTIONS OF THE SENATOR'S MICROSITE -->
<!-- START SHOW ISSUE FOLLOW ACTIONBAR -->
<?php elseif($type === 'bill'): ?>
  <div class="l-row l-row--hero c-actionbar c-actionbar--issues">
    <div class="c-actionbar--info">
      <div class="nys-senator--info">
        <p class="c-actionbar--cta">Get updates on important news and legislation related to <?php echo $content->name; ?>.</p>
      </div>
    </div>
      <!-- Check login state for action url -->
      <?php if($user && $user->uid !== '0'): ?>
        <span class="c-block--btn c-btn--follow-bill">
          <?php print flag_create_link('follow_this_bill', $content->bill_id); ?>
        </span>
      <?php else:?>

          <span class="c-block--btn c-btn--follow-bill">
            <?php echo ctools_modal_text_button(t('follow this bill'), 'registration/nojs/login', t('follow this bill'),'c-block--btn ctools-modal-login-modal');?>
          </span>

      <?php endif; ?>
  </div>
<!-- END SHOW ISSUE FOLLOW ACTIONBAR -->

<!-- START SHOW ISSUE FOLLOW ACTIONBAR -->
<?php elseif($type === 'issues' || $type === 'majority_issues'):?>
  <?php
  $logged_out_issue_link = l(t('follow this issue'), '/registration/nojs/form/start/follow-issue', array(
      'external' => TRUE,
      'attributes' => array(
        'class' => array(
          'c-block--btn',
          'ctools-modal-login-modal'
        )
      ),
      'query' => array(
        'issue' => $content->tid,
        'majority_issues' => $content->tid
      )
    )
  );
  ?>
  <div class="l-row l-row--hero c-actionbar">
    <div class="c-actionbar--info">
      <div class="nys-senator--info">
        <p class="c-actionbar--cta">Get updates about Senate activity regarding <?php echo $content->name; ?>.</p>
      </div>
    </div>
      <!-- Check login state for action url -->
      <?php if($user && $user->uid !== '0'): ?>
        <span class="c-block--btn c-btn--follow-issue">
          <?php print flag_create_link('follow_issue', $content->tid); ?>
        </span>
      <?php else:?>
        <span class="c-block--btn c-btn--follow-issue">
            <?php echo $logged_out_issue_link;?>
        </span>
      <?php endif; ?>
  </div>
<!-- END SHOW ISSUE FOLLOW ACTIONBAR -->

<!-- START SHOW COMMITTEE FOLLOW ACTIONBAR -->
<?php elseif($type === 'committees'): ?>
  <?php $follow_committee_or_group = $content->field_assemblymen_chair['und'][0]['value'] == '1' ? 'follow_group' : 'follow_committee'; ?>
  <div class="l-row l-row--hero c-actionbar c-actionbar--committee">
    <div class="c-actionbar--info">
      <div class="nys-senator--info">
        <?php $committee_type = (isset($content->field_frontend_display_type['und'][0]['value'])) ? $content->field_frontend_display_type['und'][0]['value'] : 'committee'; ?>
        <?php $committee_cta = strlen($content->name) >= 40 ? 'this ' . $committee_type : 'the ' . $content->name . ' ' . $committee_type; ?>
        <p class="c-actionbar--cta">Get updates on important news and legislation from <?php echo $committee_cta; ?>.</p>
      </div>
    </div>
      <!-- Check login state for action url -->
      <?php if($user && $user->uid !== '0'): ?>
        <span class="c-block--btn c-btn--follow-committee">
          <?php print flag_create_link($follow_committee_or_group, $content->tid); ?>
        </span>
      <?php else:?>
        <span class="c-block--btn c-btn--follow-committee">
            <?php echo ctools_modal_text_button(t('follow this committee'), 'registration/nojs/login',t('follow this committee'),'c-block--btn ctools-modal-login-modal');?>
        </span>
      <?php endif; ?>
  </div>
<!-- END SHOW COMMITTEE FOLLOW ACTIONBAR -->

<!-- Inactive District -->
<?php elseif ($type === 'districts' && $content->senator_is_active != '1'): ?>
  <div class="inactive-pallette">
    <div class="l-row l-row--hero c-actionbar c-actionbar--loggedin ">
      <div class="c-actionbar--info">
        <p class="c-actionbar--cta">This district is currently vacant.</p>
      </div>
      <a class="c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg" href="/">senate home</a>
    </div>
  </div>
<!-- End Inactive District -->

<?php else: ?>

  <!-- ACTION BAR : NOT SIGNED IN -->
  <?php if($user && $user->uid == '0'): ?>
  <div class="l-row l-row--hero c-actionbar">
    <div class="c-actionbar--info">
      <p class="c-actionbar--cta">Find your Senator and share your views on important issues.</p>
    </div>
    <span class="c-block--btn">
      <a href="/registration/nojs/form/start/find-my-senator">find your senator</a>
    </span>
    <!-- <a href="/user/login?destination=<?php //echo drupal_get_path_alias(current_path()); ?>" class="c-block-btn ctools-use-modal ctools-use-modal-processed" title="Start">find your senator</a> -->
  </div>
  <!-- ACTION BAR : SIGNED IN -->
  <?php else: ?>
    <div class="l-row l-row--hero c-actionbar c-actionbar--loggedin">
      <div class="c-actionbar--info">
        <p class="c-actionbar--cta">See activity on Issues, Bills and Committees you're following.</p>
      </div>
      <a class="c-block--btn" href="<?php print url('user/' . $user->uid) . '/dashboard/issues'; ?>">your dashboard</a>
    </div>
  <?php endif; ?>

<?php endif; ?>
<!-- END GENERAL ACTIONBAR -->
