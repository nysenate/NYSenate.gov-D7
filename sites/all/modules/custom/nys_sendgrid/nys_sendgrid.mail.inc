<?php

use \SendGrid\Mail as SG;

/**
 * Class NYSSendGridMailSystem
 *
 * An implementation of MailSystemInterface using SendGrid's API v3.
 * https://sendgrid.com/docs/API_Reference/api_v3.html
 */
class NYSSendGridMailSystem implements MailSystemInterface {

  /**
   * @var string A regex used to detect full name+email addresses.
   */
  protected static $email_regex = '/^\s*(.+?)\s*<\s*([^>]+)\s*>$/';

  /**
   * @var array An array of headers forbidden by SendGrid's API spec.
   */
  protected static $forbidden_headers = [
    'x-sg-id',
    'x-sg-eid',
    'received',
    'dkim-signature',
    'Content-Type',
    'Content-Transfer-Encoding',
    'To',
    'From',
    'Subject',
    'Reply-To',
    'CC',
    'BCC',
  ];

  /**
   * @var array Default options for the SendGrid HTTP client.
   */
  protected static $default_options = [
    'turn_off_ssl_verification' => FALSE,
    'protocol' => 'https',
    'port' => NULL,
    'url' => NULL,
    'raise_exceptions' => FALSE,
  ];

  /**
   * Ensures the SendGrid\Mail object exists in the message, creating it
   * if necessary.
   *
   * @param array $message
   *
   * @return array $message
   *
   * @throws \SendGrid\Mail\TypeException
   */
  public function format(Array $message) {
    // If sending should be cancelled, set $message['send'] = FALSE
    // This is an unreported "failure", so reporting should be handled locally.

    // Set up some references.
    /* @var $sgm SG\Mail */
    $params = &$message['params'];
    $sgm = &$params['sendgrid_mail'];

    // If no SendGrid\Mail object has been passed, create one and populate
    // it with the basic information.
    // TODO: Fix this once the library is patched.
    /* @see https://github.com/sendgrid/sendgrid-php/issues/686 */
    // Personalization created by the library.
    if (!($sgm instanceof SG\Mail)) {
      $sgm = new SG\Mail(new SG\From());
    }

    // Make sure the From has an address.  If not, populate it from the $message.
    if (!(($sgm->getFrom() instanceof SG\From)
      && $sgm->getFrom()->getEmail())) {
      $message = $this->validateFrom($message);
    }

    // Ensure we have at least one valid recipient.  If not, add a new one
    // from the $message data.
    $message = $this->validateRecipients($message);

    // Make sure the global Subject is set.  This may be overridden by
    // personalizations, or not even be needed for the template.
    if (!$sgm->getGlobalSubject()) {
      $sgm->setGlobalSubject($params['subject'] ?? $message['subject']);
    }

    // If no contents are set, generate a body from the $message. Assume HTML email.
    if (!$sgm->getContents()) {
      $body = $params['body'] ?? implode("\n\n", $message['body']);
      // SG API breaks if body is blank, even with templates.  Set a fall-back.
      if (!$body) {
        $body = "blank content";
      }
      $content_type = $params['Content-Type'] ?? SG\MimeType::HTML;
      $sgm->addContent($content_type, $body);
    }

    // Add the calling module as a category, if not suppressed.
    // TODO: Cannot remove categories in current lib.
    // Categories must be unique, so we have to be sure we aren't duplicating.
    if ($message['module']) {
      $suppressed = ($params['suppress_categories'] ?? FALSE) || variable_get('nys_sendgrid_suppress_categories', FALSE);
      if (!$suppressed) {
        // Get the list of current categories.
        $categories = ($sgm->getCategories())
          ? array_map(function ($v) {
            /* @var $v SG\Category */
            return $v->getCategory();
          }, $sgm->getCategories())
          : [];

        // Figure out what we're trying to add.
        $add = [$message['module']];
        if ($message['key']) {
          $add[] = $message['key'];
          $add[] = $message['id'];
        }

        // Add only the ones that don't exist yet.
        $sgm->addCategories(array_diff($add, $categories));
      }
    }

    // Add any message headers.  Note that these are filtered through the
    // list of headers SendGrid does not allow (such as "Content-Type"),
    // and only considers the headers added to the message.  If the Mail
    // object was passed in with a bad header, it will get through here.
    foreach ($message['headers'] as $key => $val) {
      if (!in_array($key, static::$forbidden_headers)) {
        $sgm->addGlobalHeader($key, $val);
      }
    }

    // Attempt to apply a template ID to the Mail object.
    static::_apply_template($message);

    // Allow other modules the opportunity to tune the message.
    drupal_alter('nys_sendgrid_format', $message);

    return $message;
  }

  /**
   * Validates the "From" address for an outbound mail object.
   *
   * @param $message
   *
   * @return array $message
   */
  public function validateFrom($message) {
    // Set up some references.
    /* @var $sgm SG\Mail */
    $params = &$message['params'];
    $sgm = $params['sendgrid_mail'] ?? FALSE;

    // The mail object must already be populated.  If not, cancel the send.
    if ($sgm) {
      // Parse the address from the $message.
      $from = $params['from'] ?? $message['from'];
      $from_addr = static::_parse_address($from);

      // If this email address is not valid, we can't send.
      try {
        $sgm->setFrom(new SG\From($from_addr[0], $from_addr[1]));
      }
      catch (SG\TypeException $e) {
        watchdog(
          'nys_sendgrid',
          'An email attempt was rejected due to a poorly-formed "From" address. (id=%id, addr=%addr)',
          ['%id' => $message['id'], '%addr' => $from_addr],
          WATCHDOG_ERROR
        );
        drupal_set_message(t('Unable to send e-mail. Contact the site administrator if the problem persists.'), 'error');
        $message['send'] = FALSE;
      }
    }
    else {
      $message['send'] = FALSE;
    }

    return $message;
  }

  /**
   * Split an email address into it's name and address components.  If $email
   * does not match the detection regex, the return will use the original
   * input as the email, with a blank full name.
   *
   * @param $email string
   * An RFC-compliant email address "full name <email@domain.com>".
   *
   * @return array Holding [ <email>, <full name> ]
   */
  protected static function _parse_address($email) {
    if (preg_match(static::$email_regex, $email, $matches)) {
      return [$matches[2], $matches[1]];
    }
    else {
      return [$email, ''];
    }
  }

  /**
   * Validates the recipients for an outbound mail object.  This first checks
   * to ensure at least one personalization with at least one recipient is
   * set.  If not, it attempts to set one from the message meta-data (i.e.,
   * $message['to'] and $message['params']['to']).
   *
   * Also, the function detects if the reroute_email module is active and has
   * attempted to reroute this email.  If so, the destination address set in
   * that module is used to reset every Personalization object.
   *
   * @param $message
   *
   * @return mixed
   */
  public function validateRecipients($message) {
    // Set up some references.
    /* @var $sgm SG\Mail */
    $params = &$message['params'];
    $sgm = &$params['sendgrid_mail'];

    // Detect any existing recipients.
    $persons = $sgm->getPersonalizations() ?? [];
    $found_to = FALSE;
    foreach ($persons as $one_person) {
      if (count($this->getAllRecipients($one_person))) {
        $found_to = TRUE;
      }
    }

    // If no recipients were found, try to create one from message params
    // or metadata.  Note that this info *may* already have been rerouted.
    if (!$found_to) {
      try {
        $to_addr = static::_parse_address($params['to'] ?? $message['to']);
        $sgm->addTo(new SG\To($to_addr[0], $to_addr[1]));
      }
      catch (Exception $e) {
        // Email address was likely not valid.
        watchdog(
          'nys_sendgrid',
          'An email attempt was aborted due to a malformed recipient address. (id=%id, addr=%addr)',
          ['%id' => $message['id'], '%addr' => $to_addr ?? []],
          WATCHDOG_ERROR
        );
        drupal_set_message(t('Unable to send e-mail. Contact the site administrator if the problem persists.'), 'error');
        $message['send'] = FALSE;
      }
      $persons = $sgm->getPersonalizations() ?? [];
    }

    // Handle rerouting, if the module is enabled.
    if (module_exists('reroute_email') && variable_get(REROUTE_EMAIL_ENABLE, FALSE)) {
      // Get the new destination.  If other reroute headers have been set,
      // this *should* be in $message['to'].  If not, get the address the
      // same way reroute_email does it.
      /* @see reroute_email.module:146 */
      $dest = ($message['headers']['X-Rerouted-Mail-Key'] ?? NULL)
        ? $message['to'] ?? ''
        : variable_get(REROUTE_EMAIL_ADDRESS, variable_get('site_mail', ini_get('sendmail_from')));
      // If the address is still blank, use reroute_email's default.
      if (empty($dest)) {
        $dest = REROUTE_EMAIL_ADDRESS_EMPTY_PLACEHOLDER;
      }

      // If a reroute address is found, iterate through each personalization
      // and update the email and name.
      if ($dest) {
        try {
          foreach ($persons as $one_person) {
            // Get *all* the possible recipients.
            $recipients = $this->getAllRecipients($one_person);

            // Iterate through recipients and change the name/email, if needed.
            foreach ($recipients as $recipient) {
              $email = $recipient->getEmailAddress();
              if ($email != $dest) {
                $name = $recipient->getName();
                $recipient->setName("{$email}|{$name}");
                $recipient->setEmailAddress($dest);
              }
              elseif (!$recipient->getName()) {
                $original_email = $message['headers']['X-Rerouted-Original-To'] ?? '';
                $new_name = 'reroute_email' .
                  ($original_email ? '|' . $original_email : '');
                $recipient->setName($new_name);
              }
            }
          }
        }
        catch (Exception $e) {
          // Something went wrong with rerouting.  Cancel the send, just to be safe.
          watchdog(
            'nys_sendgrid',
            'An email attempt was aborted due to a failed attempt to reroute. (id=%id, dest=%dest)',
            ['%id' => $message['id'], '%dest' => $dest],
            WATCHDOG_ERROR
          );
          drupal_set_message(t('Unable to send e-mail. Contact the site administrator if the problem persists.'), 'error');
          $message['send'] = FALSE;
        }
      }
    }

    return $message;
  }

  /**
   * Returns an aggregated array of all possible recipients of a
   * SendGrid\Personalization object.
   *
   * @param SendGrid\Mail\Personalization $personalization
   *
   * @return array
   */
  public function getAllRecipients($personalization) {
    $temp_tos = $personalization->getTos() ?? [];
    $temp_ccs = $personalization->getCcs() ?? [];
    $temp_bccs = $personalization->getBccs() ?? [];
    return $temp_tos + $temp_ccs + $temp_bccs;
  }

  /**
   * Ensures a template ID is assigned to a mail message, if template
   * assignment is not suppressed.  The order of precedence from high
   * to low is caller assignment, message ID, message module, default.
   *
   * @param array $message A Drupal mail message array.
   *
   * @throws \SendGrid\Mail\TypeException
   */
  protected static function _apply_template(Array &$message) {
    // Set up some references.
    /* @var $sgm SG\Mail */
    $params = &$message['params'];
    $sgm = &$params['sendgrid_mail'];
    $templates = static::get_template_assignments();

    // Check if template assignment is suppressed.  Suppression could be in
    // the message params (preferred), or the global setting.
    $suppressed = ($params['suppress_template'] ?? FALSE) || variable_get('nys_sendgrid_suppress_template', 0);

    // Templates pre-assigned by the caller take precedence.  If no template,
    // and not suppressed, discover and assign a template.
    if (!($sgm->getTemplateId() || $suppressed)) {
      // Set up the check values.
      $caller = $params['template_id'] ?? FALSE;
      $id = $message['id'] ?? FALSE;
      $mod = $message['module'] ?? FALSE;
      $default = $templates['_default_'] ?? variable_get('nys_sendgrid_default_template', FALSE);
      $actual = NULL;

      // If a template has been requested by the caller, use it.
      if ($caller) {
        $actual = $caller;
      }
      // Otherwise, check if the message ID has an assignment.
      elseif ($id && array_key_exists($id, $templates)) {
        $actual = $templates[$id];
      }
      // Otherwise, check if the module has an assignment.
      elseif ($mod && array_key_exists($mod, $templates)) {
        $actual = $templates[$mod];
      }
      // Otherwise, check if the default is set.
      elseif ($default) {
        $actual = $default;
      }

      // If a template has been found, set it.
      if ($actual) {
        $sgm->setTemplateId($actual);
      }
    }
  }

  /**
   * Simple getter for hard-coded template assignments.
   *
   * @return array
   */
  public static function get_template_assignments() {
    static $templates = [];

    if (!count($templates)) {
      // Read and parse the global variable.
      $templates = variable_get('nys_sendgrid_template_assignments', []);

      // Add the overall default, if configured.
      if ($default = variable_get('nys_sendgrid_default_template', FALSE)) {
        $templates['_default_'] = $default;
      }
    }

    return $templates;
  }

  /**
   * @param array $message
   *
   * @return bool
   */
  public function mail(Array $message) {
    // Set up some references.
    $params = &$message['params'];
    $sgm = &$params['sendgrid_mail'];

    // If the key is not set, return a failure.
    if (!$sg = static::get_sg_client($params['options'] ?? [])) {
      return FALSE;
    }

    // Send the message to the API, and add the response to the message array.
    $response = $sg->send($sgm);
    $sgm->response = $response;

    // Provides an opportunity for the caller or other modules to deal
    // with the API result.
    module_invoke_all('nys_sendgrid_after_send', $message);

    // Return the success/failure.  We consider success a 200 or 202.
    return in_array($response->statusCode(), ['202', '200']);
  }

  /**
   * Instantiates the SendGrid HTTP client.
   *
   * @param array $options
   * Array of options for the client.  See class SendGrid.
   *
   * @return SendGrid|boolean Returns FALSE on failure to find API key.
   */
  public static function get_sg_client(Array $options = []) {
    $key = variable_get('nys_sendgrid_apikey', '');
    if (!$key) {
      watchdog('nys_sendgrid', 'Could not retrieve SendGrid API key', [], 'error');
      return FALSE;
    }
    else {
      // Merge options with minimum defaults, and return the \SendGrid\Client.
      $options = array_merge(static::get_default_options(), $options);
      return new SendGrid($key, $options);
    }
  }

  /**
   * Getter for static::$default_options.
   *
   * @return array
   */
  public static function get_default_options() {
    return static::$default_options;
  }
}
