<?php
/**
 * @file
 * Implements Drupal MailSystemInterface
 */

class SendGridMailSystem implements MailSystemInterface {

  /**
   * Email formatting, example strip away html
   */
  public function format(array $message) {
    // Join message array.
    $message['body'] = implode("\n\n", $message['body']);

    return $message;
  }

  /**
   * Send email message
   */
  public function mail(array $message) {
    // SendGrid authentication information.
    if(variable_get('sendgrid_integration_ssl', TRUE) == TRUE) {
      $protocol = 'https://';
    }
    else {
      $protocol = 'http://';
    }

    $server = $protocol . 'sendgrid.com/api/mail.send.json';
    $user = variable_get('sendgrid_integration_username', '');
    $key = variable_get('sendgrid_integration_apikey', '');

    // Defining default unique args.
    $unique_args = array(
      'id' => $message['id'],
      'uid' => $message['params']['account']->uid,
      'module' => $message['module'],
    );

    // Allow other modules to modify unique arguments.
    $args = module_invoke_all('sendgrid_integration_unique_args_alter', $unique_args);

    // Check if we got any variable back
    if(!empty($args)) {
      $unique_args = $args;
    }

    // SMTP API, we use these to identify messages.
    $smtp_api = array(
      'category' => variable_get('site_name', 'Drupal'),
      'unique_args' => $unique_args,
    );

    // Data sended to sendgrid.
    $data = array(
      'api_user' => $user,
      'api_key' => $key,
      'x-smtpapi' => drupal_json_encode($smtp_api),
      'to' => $message['to'],
      'subject' => $message['subject'],
    );

    // Checking if 'from' email-address already exist.
    if (isset($message['from'])) {
      $data['from'] = $message['from'];
    }
    else {
      $data['from'] = variable_get('site_mail');
      $data['fromname'] = variable_get('site_name');
    }

    // Check Content-Type of message body.
    if (strpos($message['headers']['Content-Type'], 'text/plain') !== FALSE) {
      // Message body is text/plain.
      $data['text'] = drupal_wrap_mail(drupal_html_to_text($message['body']));
    }
    else {
      $data['html'] = $message['body'];
    }

    // Options for drupal_http_request.
    $options = array(
      'method' => 'POST',
      'data' => http_build_query($data),
      'timeout' => 10,
      'headers' => array(
        'Content-Type' => 'application/x-www-form-urlencoded',
      ),
    );
    // Check if $send is set to be true.
    if ($message['send'] != 1) {
      watchdog('SendGrid Integration', 'Email was not sender because send value was disabled', NULL, WATCHDOG_NOTICE, $link = NULL);
      return TRUE;
    }

    $result = drupal_http_request($server, $options);

    // Checking if we got any result data
    // (connection didn't time out for example).
    $result_data = array();
    if (isset($result->data)) {
      $result_data = drupal_json_decode($result->data);
    }

    // Creating hook, allowing other modules react on sent email.
    module_invoke_all('sendgrid_integration_sent', $message['to'], $result->code, $smtp_api['unique_args'], $result_data);

    // Check if sending message succeeded.
    if (isset($result_data['message'])) {
      if ($result_data['message'] == 'success') {
        return TRUE;
      }
    }

    // Default response to message sending failed.
    // Create log entry.
    $errors = '';
    if (isset($result_data['errors'])) {
      foreach ($result_data['errors'] as $error) {
        $errors .= $error . ' ';
      }
    }

    $variables = array(
      '%code' => $result->code,
      '%msg' => $result->error,
      '%errors' => $errors,
    );
    watchdog('SendGrid Integration', 'Email sending failed with %code/%msg. %errors', $variables, WATCHDOG_ERROR, $link = NULL);

    // Add message to queue if reason for failing was timeout or
    // another valid reason. This adds more error tolerance.
    $codes = array(
      -110,
      404,
      408,
      500,
      502,
      503,
      504,
    );
    if (in_array($result->code, $codes)) {
      $queue = DrupalQueue::get('SendGridResendQueue')->createItem($message);
    }

    return FALSE;
  }

}
