<?php

/**
 * @file
 * Hooks provided by the NYS SendGrid module.
 */

/**
 * Allows for altering a message after MailSystemInterface::format() has
 * done its work, but before the message is sent.
 *
 * @param $message array A Drupal mail message array, after formatting.
 */
function hook_nys_sendgrid_format_alter(&$message) {}

/**
 * Handles caller reporting, etc., after a message has been sent.  The
 * message array contains the original message, and a new key ('response'),
 * which holds a SendGrid\Response object.
 *
 * @param $message
 */
function hook_nys_sendgrid_after_send($message) {
  if ($message['response']->statusCode() == '200') {
    // SendGrid API call returned 200.
  }
}
