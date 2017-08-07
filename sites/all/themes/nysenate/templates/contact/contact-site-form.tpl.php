<h2 class="nys-title">Contact the New York State Senate</h2>

  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['cid']); ?>
  </div>
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
