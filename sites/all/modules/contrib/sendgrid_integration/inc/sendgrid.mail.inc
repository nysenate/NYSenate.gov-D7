<?php

/**
 * @file
 * Implements Drupal MailSystemInterface.
 */
class SendGridMailSystem implements MailSystemInterface {

  /**
   * Email formatting, example strip away html.
   *
   * @param array $message
   * @return array
   */
  public function format(array $message) {
    // Join message array.
    $message['body'] = implode("\n\n", $message['body']);

    return $message;
  }


  /**
   * Implement mail method to send mail via Sendgrid.
   *
   * @param array $message
   * @return bool
   */
  public function mail(array $message) {

    $key_secret = variable_get('sendgrid_integration_apikey', '');
    if (empty($key_secret)) {
      // Set a warning int he logs of there is no key.
      watchdog('sendgrid_integration', t('No API Secret key has been set'), 'warning');
      // Return false to indicate message was not able to send.
      return FALSE;
    }
    $options = [
      'turn_off_ssl_verification' => FALSE,
      'protocol' => 'https',
      'port' => NULL,
      'url' => NULL,
      'raise_exceptions' => FALSE,
    ];
    // Create a new SendGrid object.
    $sendgrid = new SendGrid\Client($key_secret, $options);
    $sendgrid_message = new SendGrid\Email();
    $sitename = variable_get('site_name');
    // Defining default unique args.
    $unique_args = [
      'id' => $message['id'],
      'module' => $message['module'],
    ];
    // If this is a password reset. Bypass spam filters.
    if (strpos($message['id'], 'password')) {
      $sendgrid_message->addFilter('bypass_list_management', 'enable', 1);
    }
    // If this is a Drupal Commerce message. Bypass spam filters.
    if (strpos($message['id'], 'commerce')) {
      $sendgrid_message->addFilter('bypass_list_management', 'enable', 1);
    }

    if (isset($message['params']['account']->uid)) {
      $unique_args['uid'] = $message['params']['account']->uid;
    }

    // Allow other modules to modify unique arguments.
    $args = module_invoke_all('sendgrid_integration_unique_args_alter', $unique_args);

    // Check if we got any variable back.
    if (!empty($args)) {
      $unique_args = $args;
    }

    // Checking if 'from' email-address already exist.
    if (isset($message['headers']['from']) || isset($message['headers']['From']) && $message['headers']['from'] = $message['headers']['From']) {
      $fromaddrarray = sendgrid_integration_parse_address($message['headers']['from']);
      $data['from'] = $fromaddrarray[0];
      $data['fromname'] = $fromaddrarray[1];
    }
    else {
      $data['from'] = variable_get('site_mail');
      $data['fromname'] = $sitename;
    }

    // Check if $send is set to be true.
    if ($message['send'] != 1) {
      watchdog('SendGrid Integration', 'Email was not sent because send value was disabled', NULL, WATCHDOG_NOTICE, $link = NULL);
      return TRUE;
    }
    // Build the Sendgrid mail object.
    // The message MODULE and ID is used for the Category. Category is the only
    // thing in the Sendgrid UI you can use to sort mail.

    // This is an array of categories for Sendgrid statistics.
    $categories = [
      $sitename,
      $message['module'],
      $message['id'],
    ];

    // Allow other modules to modify categories.
    $result = module_invoke_all('sendgrid_integration_categories_alter', $message, $categories);

    // Check if we got any variable back.
    if (!empty($result)) {
      $categories = $result;
    }

    $sendgrid_message
      ->setFrom($data['from'])
      ->setSubject($message['subject'])
      ->setCategories($categories)
      ->setUniqueArgs($unique_args);
    if (!empty($data['fromname'])) {
      $sendgrid_message->setFromName($data['fromname']);
    }

    // If there are multiple recipients we use a different method for To:
    if (strpos($message['to'], ',')) {
      $sendtosarry = explode(',', $message['to']);
      // Don't bother putting anything in "to" and "toName" for
      // multiple addresses. Only put multiple addresses in the Smtp header.
      $sendgrid_message->setSmtpapiTos($sendtosarry);
    }
    else {
      $toaddrarray = sendgrid_integration_parse_address($message['to']);
      $sendgrid_message->addTo($toaddrarray[0]);
      if (!empty($toaddrarray[1])) {
        $sendgrid_message->addToName($toaddrarray[1]);
      }
    }

    //Add cc and bcc in mail if they exist.
    $cc_bcc_keys = ['cc', 'bcc'];
    $address_cc_bcc = [];

    // Beginning of consolidated header parsing.
    foreach ($message['headers'] as $key => $value) {
      switch (drupal_strtolower($key)) {
        case 'content-type':
          // Parse several values on the Content-type header, storing them in an array like
          // key=value -> $vars['key']='value'
          $vars = explode(';', $value);
          foreach ($vars as $i => $var) {
            if ($cut = strpos($var, '=')) {
              $new_var = trim(drupal_strtolower(drupal_substr($var, $cut + 1)));
              $new_key = trim(drupal_substr($var, 0, $cut));
              unset($vars[$i]);
              $vars[$new_key] = $new_var;
            }
          }
          // If $vars is empty then set an empty value at index 0 to avoid a PHP warning in the next statement
          $vars[0] = isset($vars[0]) ? $vars[0] : '';
          // Nested switch to process the various content types. We only care
          // about the first entry in the array.
          switch ($vars[0]) {
            case 'text/plain':
              // The message includes only a plain text part.
              $sendgrid_message->setText(drupal_wrap_mail(drupal_html_to_text($message['body'])));
              break;

            case 'text/html':
              // The message includes only an HTML part.
              $sendgrid_message->setHtml($message['body']);
              // Also include a text only version of the email.
              $sendgrid_message->setText(drupal_wrap_mail(drupal_html_to_text($message['body'])));
              break;

            case 'multipart/related':
              // @todo determine how to handle this content type.
              // Get the boundary ID from the Content-Type header.
              $boundary = $this->_get_substring($message['body'], 'boundary', '"', '"');

              break;

            case 'multipart/alternative':
              // Get the boundary ID from the Content-Type header.
              $boundary = $this->_get_substring($message['body'], 'boundary', '"', '"');

              // Parse text and HTML portions

              // Split the body based on the boundary ID.
              $body_parts = $this->_boundary_split($message['body'], $boundary);
              foreach ($body_parts as $body_part) {
                // If plain/text within the body part, add it to $mailer->AltBody.
                if (strpos($body_part, 'text/plain')) {
                  // Clean up the text.
                  $body_part = trim($this->_remove_headers(trim($body_part)));
                  // Include it as part of the mail object.
                  $sendgrid_message->setText(drupal_wrap_mail(drupal_html_to_text($body_part)));
                }
                // If plain/html within the body part, add it to $mailer->Body.
                elseif (strpos($body_part, 'text/html')) {
                  // Clean up the text.
                  $body_part = trim($this->_remove_headers(trim($body_part)));
                  // Include it as part of the mail object.
                  $sendgrid_message->setHtml($body_part);
                }
              }
              break;

            case 'multipart/mixed':
              // Get the boundary ID from the Content-Type header.
              $boundary = $this->_get_substring($value, 'boundary', '"', '"');
              // Split the body based on the boundary ID.
              $body_parts = $this->_boundary_split($message['body'], $boundary);

              // Parse text and HTML portions
              foreach ($body_parts as $body_part) {
                if (strpos($body_part, 'multipart/alternative')) {
                  // Get the second boundary ID from the Content-Type header.
                  $boundary2 = $this->_get_substring($body_part, 'boundary', '"', '"');
                  // Clean up the text.
                  $body_part = trim($this->_remove_headers(trim($body_part)));
                  // Split the body based on the internal boundary ID.
                  $body_parts2 = $this->_boundary_split($body_part, $boundary2);

                  // Process the internal parts.
                  foreach ($body_parts2 as $body_part2) {
                    // If plain/text within the body part, add it to $mailer->AltBody.
                    if (strpos($body_part2, 'text/plain')) {
                      // Clean up the text.
                      $body_part2 = trim($this->_remove_headers(trim($body_part2)));
                      $sendgrid_message->setText(drupal_wrap_mail(drupal_html_to_text($body_part2)));
                    }
                    // If plain/html within the body part, add it to $mailer->Body.
                    elseif (strpos($body_part2, 'text/html')) {
                      // Get the encoding.
                      $body_part2_encoding = trim($this->_get_substring($body_part2, 'Content-Transfer-Encoding', ':', "\n"));
                      // Clean up the text.
                      $body_part2 = trim($this->_remove_headers(trim($body_part2)));
                      // Check whether the encoding is base64, and if so, decode it.
                      if (drupal_strtolower($body_part2_encoding) == 'base64') {
                        // Save the decoded HTML content.
                        $sendgrid_message->setHtml(base64_decode($body_part2));
                      }
                      else {
                        // Save the HTML content.
                        $sendgrid_message->setHtml($body_part2);
                      }
                    }
                  }
                }
                else {
                  // This parses the message if there is no internal content
                  // type set after the multipart/mixed.

                  // If text/plain within the body part, add it to $mailer->Body.
                  if (strpos($body_part, 'text/plain')) {
                    // Clean up the text.
                    $body_part = trim($this->_remove_headers(trim($body_part)));
                    // Set the text message.
                    $sendgrid_message->setText(drupal_wrap_mail(drupal_html_to_text($body_part)));
                  }
                  // If text/html within the body part, add it to $mailer->Body.
                  elseif (strpos($body_part, 'text/html')) {
                    // Clean up the text.
                    $body_part = trim($this->_remove_headers(trim($body_part)));
                    // Set the HTML message.
                    $sendgrid_message->setHtml($body_part);
                  }
                }
              }
              break;

            default:
              // Everything else is unknown so we log and send the message as text.
              drupal_set_message(t('The %header of your message is not supported by SendGrid and will be sent as text/plain instead.', ['%header' => "Content-Type: $value"]), 'error');
              watchdog('sendgrid_integration', 'The %header of your message is not supported by PHPMailer and will be sent as text/plain instead.', ['%header' => "Content-Type: $value"], WATCHDOG_ERROR);
              // Force the email to be text.
              $sendgrid_message->setText(drupal_wrap_mail(drupal_html_to_text($message['body'])));
          }
          break;

        case 'reply-to':
          $sendgrid_message->setReplyTo($message['headers']['Reply-To']);
          break;
      }

      // Handle latter case issue for cc and bcc key
      if (in_array(drupal_strtolower($key), $cc_bcc_keys)) {
        $mail_ids = explode(',', $value);
        foreach ($mail_ids as $mail_id) {
          list($mail_cc_address, $cc_name) = sendgrid_integration_parse_address($mail_id);
          $address_cc_bcc[drupal_strtolower($key)][] = [
            'mail' => $mail_cc_address,
            'name' => $cc_name,
          ];
        }
      }
    }
    if (array_key_exists('cc', $address_cc_bcc)) {
      foreach ($address_cc_bcc['cc'] as $item) {
        $sendgrid_message->addCc($item['mail']);
        $sendgrid_message->addCcName($item['name']);
      }
    }
    if (array_key_exists('bcc', $address_cc_bcc)) {
      foreach ($address_cc_bcc['bcc'] as $item) {
        $sendgrid_message->addBcc($item['mail']);
        $sendgrid_message->addBccName($item['name']);
      }
    }

    // Prepare attachments.
    $attachments = [];
    if (isset($message['attachments']) && !empty($message['attachments'])) {
      foreach ($message['attachments'] as $attachmentitem) {
        if (is_file($attachmentitem)) {
          $attachments[$attachmentitem] = $attachmentitem;
        }
      }
    }

    // If we have attachments, add them.
    if (!empty($attachments)) {
      $sendgrid_message->setAttachments($attachments);
    }
    // Integration with the Maillog module to use for debugging.
    if (module_exists('maillog')) {
      if (variable_get('sendgrid_integration_maillog_log', TRUE)) {
        $record = new stdClass;

        $record->header_message_id = isset($message->MessageID) ? $message->MessageID : NULL;
        $record->subject = $sendgrid_message->getSubject();
        $record->header_from = $sendgrid_message->getFrom();
        // This returns an array of emails so we have to make a string.
        $record->header_to = implode(',', $sendgrid_message->getTos());
        $record->header_reply_to = $sendgrid_message->getReplyTo();
        $record->header_all = serialize($message['headers']);
        $record->sent_date = REQUEST_TIME;

        // Used to separate different portions of the body string.
        $divider = str_repeat('-', 120) . "\n";
        // Initialize object
        $record->body = '';
        // Load the attachments.
        $attachments = $sendgrid_message->getAttachments();
        $toaddresses = $sendgrid_message->getTos();
        $toaddressesnames = $sendgrid_message->getToNames();
        $record->body .= 'Addressing Information' . "\n";
        $i = 0;
        foreach ($toaddresses as $item) {
          $record->body .= 'To Address ' . $i . ' : ' . $item . "\n";
          $i++;
        }
        $i = 0;
        foreach ($toaddressesnames as $item) {
          $record->body .= 'To Address Names ' . $i . ' : ' . $item . "\n";
          $i++;
        }
        $record->body .= $divider;
        $record->body .= $divider;
        $fromaddresses = $sendgrid_message->getFrom(TRUE);
        if (is_array($fromaddresses)) {
          $i = 0;
          foreach ($fromaddresses as $key => $value) {
            $record->body .= 'From Address ' . $i . ' : ' . $key . "\n";
            $record->body .= 'From Names ' . $i . ' : ' . $value . "\n";
            $record->body .= $divider;
            $record->body .= $divider;
          }
        }
        else {
          $record->body .= 'From Address: ' . $fromaddresses . "\n";
          $record->body .= $divider;
          $record->body .= $divider;
        }

        if (!empty($filters = $sendgrid_message->smtpapi->getFilters())) {
          $record->body .= 'Filters:' . "\n";
          foreach ($filters as $item) {
            $record->body .= print_r($item) . "\n";
          }
          $record->body .= $divider;
          $record->body .= $divider;
        }
        else {
          $record->body .= 'No Filters Declared.' . "\n";
          $record->body .= $divider;
          $record->body .= $divider;
        }


        $record->body .= 'Raw Message' . "\n";
        $record->body .= $divider;
        $record->body .= $message['body'];
        $record->body .= $divider;
        $record->body .= $divider;

        // Check Content-Type of message body and get the appropriate content.
        if (!empty($sendgrid_message->getHtml())) {
          $record->body .= 'Body HTML' . "\n";
          $record->body .= $divider;
          $record->body .= $sendgrid_message->getHtml() . "\n";
          $record->body .= $divider;
          $record->body .= $divider;
        }
        if (!empty($sendgrid_message->getText())) {
          // Message body is text/plain.
          $record->body .= 'Body Plain Text' . "\n";
          $record->body .= $divider;
          $record->body .= $sendgrid_message->getText() . "\n";
          $record->body .= $divider;
          $record->body .= $divider;
        }

        // List the attachments.
        if (!empty($attachments)) {

          $record->body .= t('Attachments') . ":\n";
          $record->body .= $divider;
          foreach ($attachments as $file) {
            $record->body .= t('Filename') . ':' . $file['filename'] . "\n";
            $record->body .= t('Directory Name') . ':' . $file['dirname'] . "\n";
            $record->body .= t('Extension') . ':' . $file['extension'] . "\n";
            $record->body .= t('Basename') . ':' . $file['basename'] . "\n";
            $record->body .= "\n";
          }
          $record->body .= $divider;
          $record->body .= $divider;
        }
        drupal_write_record('maillog', $record);
      }

      // Display the e-mail using Devel module.
      if (variable_get('sendgrid_integration_maillog_devel', TRUE) && function_exists('dpm')) {
        $bodydevel = '';
        // Check Content-Type of message body and get the appropriate content.
        if (!empty($sendgrid_message->getHtml())) {
          $bodydevel .= 'Body HTML' . "\n" . $divider . "\n" . $sendgrid_message->getHtml() . $divider;
        }
        elseif (!empty($sendgrid_message->getText())) {
          $bodydevel .= 'Body Plain Text' . "\n" . $divider . "\n" . $sendgrid_message->getText() . $divider;
        }
        $devel_msg = [];
        $devel_msg[t('Subject')] = $sendgrid_message->getSubject();
        $devel_msg[t('From')] = $sendgrid_message->getFrom();
        $devel_msg[t('To')] = implode(',', $sendgrid_message->getTos());
        $devel_msg[t('Reply-To')] = !empty($sendgrid_message->getReplyTo()) ? $sendgrid_message->getReplyTo() : NULL;
        $devel_msg[t('Headers')] = $sendgrid_message->getHeaders();
        $devel_msg[t('Body')] = $bodydevel;
        $devel_msg[t('Attachments')] = $sendgrid_message->getAttachments();
        $devel_msg[t('Message ID')] = $message['id'];

        dpm($devel_msg, 'maillog');
      }
    }


    // Lets try and send the message and catch the error.
    try {
      $response = $sendgrid->send($sendgrid_message);
    }
    catch (\SendGrid\Exception $e) {
      $error_code = filter_xss($e->getCode());
      watchdog('SendGrid Integration', 'Sending emails to Sengrind service failed with error code @error_code', ['@error_code' => $error_code], WATCHDOG_ERROR, $link = NULL);
      foreach ($e->getErrors() as $er) {
        $error_info = filter_xss($er);
        watchdog('SendGrid Integration', 'Sendgrid generated error @error_info', ['@error_info' => $error_info], NULL, WATCHDOG_ERROR, $link = NULL);
      }
      // Add message to queue if reason for failing was timeout or
      // another valid reason. This adds more error tolerance.
      $codes = [
        -110,
        404,
        408,
        500,
        502,
        503,
        504,
      ];
      if (in_array($error_code, $codes)) {
        $queue = DrupalQueue::get('SendGridResendQueue')->createItem($message);
      }
      return FALSE;
    }
    // Sanitize and store the response code for easy processing.
    $response_code = filter_xss($response->getCode());

    // Creating hook, allowing other modules react on sent email.
    module_invoke_all('sendgrid_integration_sent', $message['to'], $response_code, $unique_args, $response);

    if ($response_code = 200) {
      // If the code is 200 we are good to finish and proceed.
      return TRUE;
    }
    // Default to low. Sending failed.
    return FALSE;
  }

  /**
   * Returns a string that is contained within another string.
   *
   * Returns the string from within $source that is some where after $target
   * and is between $beginning_character and $ending_character.
   *
   * Swiped from SMTP module. Thanks!
   *
   * @param $source
   *   A string containing the text to look through.
   * @param $target
   *   A string containing the text in $source to start looking from.
   * @param $beginning_character
   *   A string containing the character just before the sought after text.
   * @param $ending_character
   *   A string containing the character just after the sought after text.
   * @return string
   *   A string with the text found between the $beginning_character and the
   *   $ending_character.
   */
  protected function _get_substring($source, $target, $beginning_character, $ending_character) {
    $search_start = strpos($source, $target) + 1;
    $first_character = strpos($source, $beginning_character, $search_start) + 1;
    $second_character = strpos($source, $ending_character, $first_character) + 1;
    $substring = drupal_substr($source, $first_character, $second_character - $first_character);
    $string_length = drupal_strlen($substring) - 1;

    if ($substring[$string_length] == $ending_character) {
      $substring = drupal_substr($substring, 0, $string_length);
    }

    return $substring;
  }

  /**
   * Splits the input into parts based on the given boundary.
   *
   * Swiped from Mail::MimeDecode, with modifications based on Drupal's coding
   * standards and this bug report: http://pear.php.net/bugs/bug.php?id=6495
   *
   * @param input
   *   A string containing the body text to parse.
   * @param boundary
   *   A string with the boundary string to parse on.
   * @return array
   *   An array containing the resulting mime parts
   */
  protected function _boundary_split($input, $boundary) {
    $parts = [];
    $bs_possible = drupal_substr($boundary, 2, -2);
    $bs_check = '\"' . $bs_possible . '\"';

    if ($boundary == $bs_check) {
      $boundary = $bs_possible;
    }

    $tmp = explode('--' . $boundary, $input);

    for ($i = 1; $i < count($tmp); $i++) {
      if (trim($tmp[$i])) {
        $parts[] = $tmp[$i];
      }
    }

    return $parts;
  }

  /**
   * Strips the headers from the body part.
   *
   * @param string $input
   *   A string containing the body part to strip.
   * @return string
   *   A string with the stripped body part.
   */
  protected function _remove_headers($input) {
    $part_array = explode("\n", $input);

    // will strip these headers according to RFC2045
    $headers_to_strip = [
      'Content-Type',
      'Content-Transfer-Encoding',
      'Content-ID',
      'Content-Disposition',
    ];
    $pattern = '/^(' . implode('|', $headers_to_strip) . '):/';

    while (count($part_array) > 0) {

      // ignore trailing spaces/newlines
      $line = rtrim($part_array[0]);

      // if the line starts with a known header string
      if (preg_match($pattern, $line)) {
        $line = rtrim(array_shift($part_array));
        // remove line containing matched header.

        // if line ends in a ';' and the next line starts with four spaces, it's a continuation
        // of the header split onto the next line. Continue removing lines while we have this condition.
        while (substr($line, -1) == ';' && count($part_array) > 0 && substr($part_array[0], 0, 4) == '    ') {
          $line = rtrim(array_shift($part_array));
        }
      }
      else {
        // no match header, must be past headers; stop searching.
        break;
      }
    }

    $output = implode("\n", $part_array);
    return $output;
  }


}
