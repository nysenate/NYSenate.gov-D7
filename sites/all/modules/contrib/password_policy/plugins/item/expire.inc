<?php
/**
 * @file
 * Expiration plugin for Password Policy module.
 */

$plugin = array(
  'admin form callback' => 'password_policy_expire_admin_form',
  'prime value' => 'expire_limit',
  'class' => 'PasswordPolicyExpire',
  'config' => array(
    'expire_enabled' => FALSE,
    'expire_limit' => "6 months",
    'expire_warning_message' => 'Your password has expired. Please change it now.',
    'expire_warning_email_sent' => "-14 days",
    'expire_warning_email_message' => '',
    'expire_warning_email_subject' => '[user:name], your password on [site:name] shall expire in [password_expiration_date:interval] ',
  ),
);

/**
 * Admin form callback for expiration plugin.
 */
function password_policy_expire_admin_form($form, &$form_state, $constraint) {
  $sub_form['expire_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Password expiration',
    '#collapsible' => TRUE,
    '#collapsed' => !$constraint->config['expire_enabled'],
  );
  $sub_form['expire_fieldset']['expire_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => 'Expire passwords',
    '#default_value' => $constraint->config['expire_enabled'],
    '#description' => t('Enable password expiration.'),
  );

  // Container for controls that should only be visible if expiration enabled.
  $sub_form['expire_fieldset']['enabled_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="expire_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  $enabled_container = &$sub_form['expire_fieldset']['enabled_container'];

  $enabled_container['expire_limit'] = array(
    '#type' => 'textfield',
    '#title' => 'Expire limit',
    '#default_value' => $constraint->config['expire_limit'],
    '#description' => t("Password will expire after being used for this long. (Use normal English, like 90 days or 5 hours.)"),
  );
  $enabled_container['expire_warning_message'] = array(
    '#type' => 'textfield',
    '#title' => 'Warning message',
    '#default_value' => $constraint->config['expire_warning_message'],
    '#description' => t('A message to show to users on screen when requiring them to change password. <strong>If left empty, no message will be shown.</strong>'),
  );
  $enabled_container['expire_warning_email_sent'] = array(
    '#type' => 'textfield',
    '#title' => 'When to send warning e-mails',
    '#default_value' => $constraint->config['expire_warning_email_sent'],
    '#description' => t('A comma separated list of time intervals, when to send warning e-mails. (Use normal English, like 90 days or 5 hours.)  If prefixed with a negative (like -2 days) then this will be before the expiration. If left empty, no e-mail will be sent.'),
  );
  $enabled_container['expire_warning_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => 'Warning e-mail subject',
    '#default_value' => $constraint->config['expire_warning_email_subject'],
    '#maxlength' => 180,
    '#states' => array(
      'visible' => array(
        ':input[name="expire_warning_email_sent"]' => array('empty' => FALSE),
      ),
    ),
  );
  $enabled_container['expire_warning_email_message'] = array(
    '#type' => 'textarea',
    '#title' => 'Warning e-mail message',
    '#default_value' => $constraint->config['expire_warning_email_message'],
    '#states' => array(
      'visible' => array(
        ':input[name="expire_warning_email_sent"]' => array('empty' => FALSE),
      ),
    ),
  );
  if (module_exists('token')) {
    $enabled_container['expire_warning_email_message_token'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array(
        'user',
        'site',
        'current-date',
        'password_expiration_date',
      ),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#states' => array(
        'visible' => array(
          ':input[name="expire_warning_email_sent"]' => array('empty' => FALSE),
        ),
      ),
    );
  }
  return $sub_form;
}

/**
 * Notifies user of upcoming password expiration by e-mail.
 *
 * @param object $account
 *   User object.
 * @param object $candidate
 *   Various expiration-related information pertaining to user.
 * @param int $expire
 *   Time when password will expire, in seconds since Unix epoch.
 * @param PasswordPolicyExpire $item
 *   Expiration policy item.
 */
function _password_policy_expire_notify($account, $candidate, $expire, PasswordPolicyExpire $item) {
  $body = token_replace($item->config['expire_warning_email_message'], array(
    'user' => $account,
    'password_expiration_date' => $expire,
  ));
  $subject = token_replace($item->config['expire_warning_email_subject'], array(
    'user' => $account,
    'password_expiration_date' => $expire,
  ));
  $message = drupal_mail('password_policy', 'warning', $account->mail, user_preferred_language($account), array('body' => $body, 'subject' => $subject));

  return $message;
}

/**
 * Queries users who are candidates for an expiration warning.
 *
 * They are "candidates" in that they may or may not be covered by the
 * expiration policy.
 *
 * @param int $notice_int
 *   Beginning of notice (i.e. warning) interval, in seconds since the Unix
 *   epoch.
 * @param string $policy_name
 *   Policy name.
 *
 * @return array
 *   Array of candidates for password expiration warning, containing
 *   information pertaining to expiration.
 */
function _password_policy_expire_query_users($notice_int, $policy_name) {
  $current_pw_query = db_select('password_policy_history', 'c');
  $current_pw_query
    ->fields('c', array('uid'))
    ->groupBy('uid')
    ->addExpression('MAX(created)', 'created');

  $query = db_select('password_policy_history', 'p');

  $query->fields('p', array('uid', 'hid', 'created'));

  // Join to our active password so we are only looking at the most recent.
  $query->join($current_pw_query, 'c', 'p.created = c.created AND p.uid = c.uid');

  // Add negative join to remove all items that have already sent this notice.
  // @TODO findout why we cannot use arguments here
  // $query->leftJoin('password_policy_notice_history', 'nh', "nh.hid = p.hid AND nh.timeframe = '%s' AND nh.name='%s'", array($notice_int, $policy_name));
  $condition = t("nh.hid = p.hid AND nh.name='@name' AND nh.timeframe = '@timeframe'", array('@name' => $policy_name, '@timeframe' => $notice_int));
  $query->leftJoin('password_policy_notice_history', 'nh', $condition);
  $query->isNull('nh.hid');

  // Check to see if the password needs a warning notification.
  $query->condition('p.created', REQUEST_TIME - $notice_int, '<');

  // Package up the candidates and return them.
  $candidates = array();
  $result = $query->execute();
  foreach ($result as $row) {
    $candidates[$row->uid] = $row;
  }

  return $candidates;
}

/**
 * Policy item that handles password expirations.
 */
class PasswordPolicyExpire extends PasswordPolicyItem {
  public $ppType = array('item', 'cron', 'init');

  /**
   * Checks on init if the user password has expired.
   *
   * If the password has expired, we send the user to the user edit page until
   * they set a new password.
   */
  public function init($account) {
    // Do not do anything if expiration is disabled.
    $enabled = $this->config['expire_enabled'];
    if (!$enabled) {
      return;
    }
    // An expiration interval equal to zero means expiration is disabled.
    $expire_int = password_policy_parse_interval($this->config['expire_limit']);
    if (!$expire_int) {
      return;
    }

    // If this is a command line request (Drush, etc), skip processing.
    if (drupal_is_cli()) {
      return FALSE;
    }

    $stop = module_invoke_all('password_policy_expire_url_exclude', $account);
    if (!empty($stop)) {
      return FALSE;
    }

    // @TODO this should not be necessary
    password_policy_user_load(array($account->uid => $account));
    if ($account->uid == 0) {
      return;
    }

    // If there is no password history, start one.
    if (!isset($account->password_history[0])) {
      $account->password_history[0] = (object) array(
        'uid' => $account->uid,
        'pass' => $account->pass,
        'created' => REQUEST_TIME,
      );
      password_policy_update_password_history($account->password_history[0]);
    }
    // Check to see that the password has expired.
    if ($account->password_history[0]->created + $expire_int < REQUEST_TIME) {
      // If we are on the check ajax page, then skip.
      if (current_path() != 'password_policy/check') {
        // If not on the password change page, go there.
        $password_change_path = $this->getPasswordChangePath($account);
        if (current_path() != $password_change_path) {
          $this->setExpiredWarningMessage();
          $this->goToPasswordChangePath($account);
        }
      }
    }
  }

  /**
   * Gets password change path.
   *
   * @param object $account
   *   User object.
   *
   * @return string
   *   Password change path for the user.
   */
  public function getPasswordChangePath($account) {
    return "user/{$account->uid}/edit";
  }

  /**
   * Redirects user to password change path.
   *
   * @param object $account
   *   User object of user to be redirected.
   */
  public function goToPasswordChangePath($account) {
    $password_change_path = $this->getPasswordChangePath($account);

    // Set query to redirect user back to their original destination after
    // leaving password change page.
    $options = array('query' => drupal_get_destination());
    unset($_GET['destination']);

    drupal_goto($password_change_path, $options);
  }

  /**
   * Sets warning message indicating password has expired.
   */
  public function setExpiredWarningMessage() {
    if (!empty($this->config['expire_warning_message'])) {
      drupal_set_message($this->config['expire_warning_message'], 'warning');
    }
  }

  /**
   * Cron task for expiration plugin.
   *
   * Pulls all users that have expired passwords, ensures they are active with
   * this policy, and then notifies them of their soon-to-be expired password.
   */
  public function cron() {
    // Do not do anything if expiration is disabled.
    $enabled = $this->config['expire_enabled'];
    if (!$enabled) {
      return;
    }

    // Don't do anything if the policy does not require notification e-mails.
    if (empty($this->config['expire_warning_email_sent'])) {
      return;
    }

    $notice_interval_strings = explode(',', $this->config['expire_warning_email_sent']);
    $expire_interval_string = $this->config['expire_limit'];
    $policy_name = $this->policy->name;

    foreach ($notice_interval_strings as $notice_interval_string) {
      $notice_interval_string = trim($notice_interval_string);
      // See if we should be subtracting from expire interval.
      $from_interval = drupal_substr($notice_interval_string, 0, 1) == '-';
      $notice_interval_string = ltrim($notice_interval_string, '-');

      // Convert notice interval to secs.
      $notice_int = password_policy_parse_interval($notice_interval_string);

      // If we need to subtract from expire do so.
      $expire_int = password_policy_parse_interval($expire_interval_string);
      if ($from_interval) {
        $notice_int = $expire_int - $notice_int;
      }
      $candidates = _password_policy_expire_query_users($notice_int, $policy_name);
      foreach ($candidates as $candidate) {
        $account = user_load($candidate->uid);
        if ($this->policy->match($account)) {
          $message = _password_policy_expire_notify($account, $candidate, $candidate->created + $expire_int, $this);
          if ($message['result']) {
            watchdog('password_policy', 'Password expiration warning mailed to %username at %email.', array('%username' => $account->name, '%email' => $account->mail));
            $notice_history = (object) array(
              'hid' => $candidate->hid,
              'name' => $this->policy->name,
              'timeframe' => $notice_int,
              // We use time() and not REQUEST_TIME so the stored sent time
              // will be as close as possible to the time the expiration
              // warning e-mail was sent.
              // @ignore upgrade7x_6
              'sent' => time(),
            );
            drupal_write_record('password_policy_notice_history', $notice_history);
          }
        }
      }
    }
  }

}
