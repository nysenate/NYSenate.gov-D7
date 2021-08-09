<?php

namespace NYS_Looker_Integration;

use SendGrid\Client;

/**
 * Class LookerAPI
 */
class LookerAPI {

  /**
   * @var string
   * The type/path being called (e.g., scheduled_plans)
   */
  private $type;

  /**
   * @var \SendGrid\Client
   */
  private $client;

  /**
   * @var string
   */
  private $api_token;

  /**
   * @var int timestamp of the token's expiration
   */
  private $api_token_expire;

  /**
   * @var string
   */
  private $api_key;

  /**
   * @var string
   */
  private $api_secret;

  /**
   * @var string Part of the API path appearing between the host and version
   * e.g., $path_prefix = 'api', and $version = '3.1', then:
   *   $api_url = 'nysenate.looker.com/api/3.1'
   */
  private $path_prefix;

  /**
   * LookerAPI constructor.
   *
   * @param string $type
   * @param string $path_prefix
   */
  public function __construct($type, $path_prefix = 'api') {
    $this->type = $type;
    $this->path_prefix = $path_prefix;
    $this->fetchCredentials();
  }

  /**
   * @param null $data
   *
   * @param string $method
   *
   * @return \SendGrid\Response
   */
  public function execute($data = NULL, $method = "post") {
    static $debug = NULL;

    if (is_null($debug)) {
      $debug = variable_get('nys_looker_integration_api_debug', 0);
    }

    if (!$this->client) {
      $this->client = $this->getAPIClient($this->type);
    }

    // Ensure authentication is done.
    if ((!$this->api_token) || ($this->api_token_expire < time())) {
      $this->generateOAuth();
    }

    $headers = ["Authorization: token {$this->api_token}"];
    $method = $method ?: "post";

    $ret = $this->client->{$method}($data, NULL, $headers);
    if ($debug) {
      watchdog('nys_looker_integration',
        'API call debug',
        [
          'method' => $method,
          'data' => $data,
          'request' => $this,
          'response' => $ret,
        ],
        WATCHDOG_DEBUG);
    }
    return $ret;
  }

  /**
   * Instantiates an API client based on the host and path for this call.
   *
   * @param ?string $type
   *
   * @return \SendGrid\Client
   */
  private function getAPIClient($type = NULL) {
    $host = trim(variable_get('nys_looker_integration_host', ''), '/');
    $prefix = trim($this->path_prefix, '/');
    $port = variable_get('nys_looker_integration_api_port', '');
    $version = variable_get('nys_looker_integration_api_version', NYS_LOOKER_INTEGRATION_DEFAULT_API_VERSION);
    $path = array_filter(explode('/', $type ?? $this->type));
    $url = 'https://' . $host . ($port ? ':' . $port : '') .
      ($prefix ? '/' . $prefix : '') . '/';
    return new Client($url, NULL, $version, $path);
  }

  /**
   * Populates some properties from Drupal variables.
   */
  private function fetchCredentials() {
    $this->api_token = variable_get('nys_looker_integration_api_token', '');
    $this->api_token_expire = variable_get('nys_looker_integration_api_token_expire', 0);
    $this->api_key = variable_get('nys_looker_integration_api_client_key', '');
    $this->api_secret = variable_get('nys_looker_integration_api_client_secret', '');
  }

  /**
   * Generates an OAuth token for this API call.  The token and
   * expiration will be stored in Drupal variables.
   */
  private function generateOAuth() {
    // Make sure the properties are populated.
    $this->fetchCredentials();

    // Set up the parameters for the authentication call.
    $params = [
      'client_id' => $this->api_key,
      'client_secret' => $this->api_secret,
    ];

    // Execute the call.
    $response = $this->getAPIClient('login')->post(NULL, $params);

    // Verify and parse the return.
    if ($response->statusCode() == 200) {
      // Get the new token and expiration.
      $token = json_decode($response->body());
      $this->api_token = $token->access_token;
      $this->api_token_expire = $expire = time() - 5 + $token->expires_in;

      // Save the new token and expiration.
      variable_set('nys_looker_integration_api_token', $this->api_token);
      variable_set('nys_looker_integration_api_token_expire', $this->api_token_expire);
    }
    else {
      // Something went wrong... we should do something about that.
      watchdog('nys_looker_integration', 'Could not retrieve OAuth token from Looker', [], WATCHDOG_WARNING);
    }
  }

}
