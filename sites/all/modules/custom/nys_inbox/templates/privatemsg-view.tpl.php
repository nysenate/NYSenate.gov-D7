<?php
/**
 * @file Template file for the private message inbox.
 */

/**
 * Variables.
 *
 * @var $anchors
 * @var $message_classes
 * @var $mid
 * @var $author_name_link
 * @var $message_timestamp
 * @var $message_subject
 * @var $message_body
 * @var string $district
 *   The district of the user who sent the message.
 */
?>

<?php print $anchors; ?>

<div <?php if (!empty($message_classes)): ?>class="<?php echo implode(' ', $message_classes); ?>" <?php endif; ?> id="privatemsg-mid-<?php print $mid; ?>">

  <div class="privatemsg-message-information">
    <span class="privatemsg-author-name"><?php print $author_name_link; ?></span> <span class="private-message-dot">&middot;</span> <span class="privatemsg-message-date"><?php print $message_timestamp; ?></span>
    <?php if (isset($message_actions)): ?>
      <?php print $message_actions ?>
    <?php endif ?>
  </div>

  <div class="privatemsg-message-subject">
    <?php print $message_subject; ?>
  </div>

  <div class="privatemsg-message-body">
    <?php print $message_body; ?>
  </div>

  <div class="clearfix"></div>
</div>
