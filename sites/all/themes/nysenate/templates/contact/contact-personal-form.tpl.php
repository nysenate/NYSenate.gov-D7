
<?php if (in_array('Senator',$form['recipient']['#value']->roles)): ?>
<h2 class="c-page-header--title">Contact Senator <?php print $form['recipient']['#value']->name; ?></h2>

  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['name']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['last_name']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['mail']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['phone']); ?>
  </div>
  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['subject']); ?>
  </div>
  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['message']); ?>
  </div>
  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['actions']); ?>
  </div>
<?php print drupal_render_children($form); ?>
<?php else: ?>
  Currently contact form is only allowed to contact senators and <?php print $form['recipient']['#value']->name; ?> is not. 
<?php endif; ?>