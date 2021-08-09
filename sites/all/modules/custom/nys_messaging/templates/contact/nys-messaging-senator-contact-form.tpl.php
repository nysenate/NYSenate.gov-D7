<?php

/**
 * @file
 * Display the senator contact form.
 */

// Get the recipient value into a variable so we can display it.
$recipient = filter_xss($form['recipient']['#value']);
// Unset the recipient hidden form element so it cannot be altered.
unset($form['recipient']);
?>
<h3>Send a message to <?php print $recipient; ?>'s office</h3>
<p>If you would like to send a message related to legislation or issues, please create an account <a href="/user/login">here</a>.</p>

  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['inquiry_type']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['first_name']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['last_name']); ?>
  </div>
  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['subject']); ?>
  </div>
  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['email_body']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['from_email']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['phone']); ?>
  </div>
  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['address']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['city']); ?>
  </div>
  <div class="small-12 large-6 medium-6 columns">
    <?php print render($form['zip']); ?>
  </div>
  <div class="small-12 large-12 medium-12 columns">
    <?php print render($form['actions']); ?>
  </div>
<?php print drupal_render_children($form); ?>
