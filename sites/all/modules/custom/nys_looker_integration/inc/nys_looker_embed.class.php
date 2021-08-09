<?php

/**
 * Class NYSLookerEmbed
 */
class NYSLookerEmbed {

  /**
   * @var array
   * Cache for loaded user details.  Prevents multiple loads of the
   * same user.
   */
  public static $user_cache = [];

  /**
   * @var array
   * An array of SSO parameters that should not be JSON-encoded.
   */
  public static $do_not_encode = ['signature', 'force_logout_login'];

  /**
   * @var int
   * User ID for which this embed is being generated.  Default of
   * zero acts as the logged in user. (from GLOBAL)
   */
  protected $user_id = 0;

  /**
   * @var string
   * The hostname to which the embed is sent.  Read from Drupal vars.
   */
  protected $hostname = '';

  /**
   * @var string
   * The secret key for the embed request.  Read from Drupal vars.
   */
  protected $secret_key = '';

  /**
   * @var array
   * The default models used for an embed.  Read from Drupal vars.
   */
  protected $default_models = [];

  /**
   * @var array
   * The actual models used for this embed.  Defaults to $default_models.
   */
  protected $models = [];

  /**
   * @var array
   * An array of options to encode into the embed's URL.
   */
  protected $embed_options = [];

  /**
   * @var array
   * An array of options to modify the SSO/signature generation.
   */
  protected $sso_options = [];

  /**
   * @var array
   * An array of options to apply to the <iframe> element.
   */
  protected $frame_options = [];

  /**
   * @var string
   * The path created for this request.
   */
  protected $target_path = '';

  /**
   * NYSLookerEmbed constructor.
   *
   * @param array $options
   *    Options to set during creation.  Recognizes user_id, embed, sso,
   *    and frame.
   */
  public function __construct($options = []) {
    $this->fetchPrivateVars();
    $this->setModels($this->default_models);

    // Callers can spoof a user context by passing in a uid.  If it is
    // not present, assume the current user.
    $this->user_id = $options['user_id'] ?? $GLOBALS['user']->uid;

    foreach (['embed', 'sso', 'frame'] as $val) {
      $p = "{$val}_options";
      $this->{$p} = $options[$val] ?? [];
    }
  }

  /**
   * Fetches private properties set through Drupal's variables.
   */
  protected function fetchPrivateVars(): void {
    // Get the stored hostname.
    $this->hostname = variable_get('nys_looker_integration_host', '');

    // Get the stored secret key.
    $this->secret_key = variable_get('nys_looker_integration_secret_key', '');

    // Get and parse the default models.
    $m = variable_get('nys_looker_integration_default_models', '');
    $this->setModels(explode(',', $m), TRUE);
  }

  /**
   * Generates the HTML for an embed of a looker resource.  Returns an empty
   * string if the access check fails.
   *
   * @see static::verifyAccess()
   * @see https://docs.looker.com/reference/embedding/sso-embed#parameters
   *
   * @param string $target
   *    The path to the looker resource (e.g., 'dashboards/xx')
   *
   * @param array $options
   *    An array of options to override the default frame options.
   *
   * @return string
   */
  public function generate($target, $options = []): string {
    $ret = '';
    $frame_params = $options + $this->frame_options;

    // Only Legislative Correspondents have access to these embeds.
    if (static::verifyAccess()) {
      // Generate the src URL.
      $frame_params['src'] = $this->generateUrl($target);

      // Create the HTML element with its attributes.
      $ret = '<iframe';
      foreach ($frame_params as $key => $val) {
        $ret .= ' ' . $key . '="' . $val . '"';
      }
      $ret .= '></iframe>';
    }

    return $ret;
  }

  /**
   * Generates the entire URL for an SSO/Embed call to looker.
   *
   * @param $target
   *    The path to the looker resource (e.g., 'dashboards/xx')
   *
   * @return string
   */
  public function generateUrl($target): string {
    // Build the embed resource path.
    $this->target_path = $this->generatePath($target);

    // Build the SSO parameters.
    $sso = $this->processSsoParams();

    // Encode all the SSO parameters.  Note that "signature" and
    // "force_logout_login" *MUST NOT* be JSON encoded.
    array_walk(
      $sso,
      function (&$v, $k) {
        if (!in_array($k, static::$do_not_encode)) {
          $v = json_encode($v);
        }
      }
    );

    // Return the built URL.
    return "https://" . $this->hostname . $this->target_path .
      "?" . drupal_http_build_query($sso);
  }

  /**
   * @param array $models
   * @param bool $default
   */
  public function setModels(array $models, bool $default = FALSE): void {
    $m = array_filter(array_map('trim', $models));
    if ($default) {
      $this->default_models = $m;
    }
    else {
      $this->models = $m;
    }
  }

  /**
   * Prepares the SSO parameters for an embed request.
   *
   * @param array $params
   *    Any parameters used to override SSO defaults.
   *
   * @return array
   */
  protected function processSsoParams($params = []): array {
    $ret = [];

    // Use the same timezone as the looker server.
    $old_tz = date_default_timezone_get();
    date_default_timezone_set('America/Los_Angeles');

    // Fetch user's information.
    $uid = $params['external_user_id'] ?? $this->user_id;
    $user_info = static::fetchUserDetails($uid);

    // Set the user info.
    $ret['external_user_id'] = $user_info['uid'];
    $ret['first_name'] = $user_info['first_name'];
    $ret['last_name'] = $user_info['last_name'];

    // Add any parameters passed in, and the defaults.
    $ret += $params + $this->sso_options;

    // Generate the signature for the call.
    $this->generateSignature($ret);

    // Restore default timezone.
    date_default_timezone_set($old_tz);

    return $ret;
  }

  /**
   * Generate the embed request signature, to be included in the embed request.
   * This algorithm is generated per Looker's instructions.
   *
   * @see https://docs.looker.com/reference/embedding/sso-embed#signature
   *
   * @param $params
   *    Array of URL parameters for the SSO embed request.  $params will
   *    be modified to include all fields required by SSO.
   */
  protected function generateSignature(&$params): void {
    // Ensure the secret, host, and path are all available.
    $process = ((boolean) $this->secret_key)
      && ((boolean) $this->hostname)
      && ((boolean) $this->target_path);

    // These fields must exist in params in order for the signature to be
    // calculated.  Some of these come with sane defaults.  If the user's
    // id or name is missing, that's a deal-breaker.
    $check = [
      'nonce' => md5(uniqid('', TRUE)),
      'time' => time(),
      'session_length' => 3600,
      'external_user_id' => NULL,
      'first_name' => NULL,
      'last_name' => NULL,
      'permissions' => [
        'see_user_dashboards',
        'see_lookml_dashboards',
        'access_data',
        'see_looks',
      ],
      'models' => $this->models,
      'group_ids' => [],
      'external_group_id' => '',
      'user_attributes' => new stdClass,
      'access_filters' => new stdClass,
      'force_logout_login' => 'true',
      'signature' => '',
    ];

    // Make sure each of the necessary fields exists.  If a "NULL-default"
    // field is missing, trigger the kill flag.
    foreach ($check as $fld => $val) {
      if (!array_key_exists($fld, $params)) {
        if (is_null($val)) {
          $process = FALSE;
        }
        else {
          $params[$fld] = $val;
        }
      }
    }

    // If all good, generate the signature and drop it in the params.  If not,
    // leave the blank signature to ensure the call fails.
    if ($process) {
      $sign = $this->hostname . "\n" .
        $this->target_path . "\n" .
        json_encode($params['nonce']) . "\n" .
        json_encode($params['time']) . "\n" .
        json_encode($params['session_length']) . "\n" .
        json_encode($params['external_user_id']) . "\n" .
        json_encode($params['permissions']) . "\n" .
        json_encode($params['models']) . "\n" .
        json_encode($params['group_ids']) . "\n" .
        json_encode($params['external_group_id']) . "\n" .
        json_encode($params['user_attributes']) . "\n" .
        json_encode($params['access_filters']);
      $params['signature'] = trim(
        base64_encode(
          hash_hmac("sha1", utf8_encode($sign), $this->secret_key, TRUE)
        )
      );
    }
  }

  /**
   * Builds the path used for an SSO/Embed call for a looker resource.
   *
   * @param $target
   *    Path to the looker resource being embedded.
   * @param $params
   *    Array of URL parameters for the embed (e.g., filters)
   *
   * @return string
   */
  protected function generatePath($target, $params = []): string {
    $path = '';

    // Remove the leading slash, if it exists.
    $target = preg_replace('=^/?(.*)=', '$1', (string) $target);

    if ($target) {
      // Half of this path is encoded.  The double-slash "typo" is intentional.
      // See: https://docs.looker.com/reference/embedding/sso-embed#creating_the_embed_url
      $embed = '/embed/' . $target;
      $p = $params + $this->embed_options;
      if (count($p)) {
        $embed .= '?' . drupal_http_build_query($p);
      }
      $path = '/login/embed/' . urlencode($embed);
    }
    return $path;
  }

  /**
   * Fetches the details of a user, identified by $uid.  Returns an
   * array including the keys 'first_name', 'last_name', 'uid', and
   * 'senator_district'. The return will be NULL if access check fails.
   *
   * TODO: this belongs in a different file
   *
   * @see static::verifyAccess()
   *
   * @param integer $uid The user ID to fetch
   *
   * @return array|NULL
   */
  public static function fetchUserDetails($uid = 0): ?array {
    // Cache these results to prevent extra work.
    $details = &static::$user_cache;

    // Default to the logged in user.
    if (!$uid) {
      $uid = $GLOBALS['user']->uid;
    }

    // If the user's details are not loaded, load them.
    if (!array_key_exists($uid, $details)) {
      // Default return if access checks fail.
      $result = NULL;

      // Only LC roles have access to embeds.
      if (static::verifyAccess($uid)) {
        // Make sure we have an assigned senator.
        $auth_user = user_load($uid);
        $inbox_count = count($auth_user->field_senator_inbox_access[LANGUAGE_NONE]);
        if ($inbox_count == 1) {
          //Collect the necessary info.
          $senator_uid = $auth_user->field_senator_inbox_access[LANGUAGE_NONE][0]['target_id'];
          $senator_nid = nys_utils_get_senator_nid_from_senator_uid($senator_uid);
          $district = senator_get_district_number($senator_nid);
          $result = [
            'first_name' => $auth_user->field_first_name[LANGUAGE_NONE][0]['value'],
            'last_name' => $auth_user->field_last_name[LANGUAGE_NONE][0]['value'],
            'uid' => $auth_user->uid,
            'senator_district' => $district,
          ];
        }
      }

      // Save the result in cache.
      $details[$uid] = $result;
    }

    // Return the cached information.
    return $details[$uid];
  }

  /**
   * @param array $embed_options
   */
  public function setEmbedOptions(array $embed_options): void {
    $this->embed_options = $embed_options;
  }

  /**
   * @param array $sso_options
   */
  public function setSsoOptions(array $sso_options): void {
    $this->sso_options = $sso_options;
  }

  /**
   * @param array $frame_options
   */
  public function setFrameOptions(array $frame_options): void {
    $this->frame_options = $frame_options;
  }

  /**
   * Discover if a user has the Legislative Correspondent role.  A wrapper
   * around nys_utils_user_has_role_name() using only LC role.  The $uid
   * parameter defaults to the logged in user's ID.
   *
   * TODO: this belongs in a different file
   *
   * @param integer $uid
   *
   * @return bool
   */
  public static function verifyAccess($uid = 0): bool {
    // Default to the currently logged-in user.
    if (!($uid)) {
      $uid = $GLOBALS['user']->uid;
    }
    return nys_utils_user_has_role_name('Legislative Correspondent', $uid);
  }
}