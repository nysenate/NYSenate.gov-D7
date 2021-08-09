<?php

namespace Nys_Openleg;

use SendGrid\Client;

/**
 * Class ApiRequest
 *
 * This class is a wrapper around \Sendgrid\Client.
 *
 * The Client object enforces a static "host/version" format in the URL
 * it builds.  This class works around that by building the host portion
 * with the help of a "path prefix", inserted between the actual host and
 * the version.  The host actually sent to the Client constructor will be:
 *
 * https://<host>/<path_prefix>/
 *
 * Class constants provide for transparent default configuration for
 * host, version, and path prefix.  All of these items may be overridden
 * using setters, or the $options parameter in __construct().   All
 * setters return $this to allow for chaining.
 *
 * If no API key is found, the "key" parameter will not be added to the
 * query string.  An API key passed in get() will take precedence over
 * the object's property.
 *
 * Note that the endpoint and API key are not validated.  Improper
 * values in either of these will likely return an HTTP 404, or an
 * ApiResponse\Error object.
 *
 * TODO: decide how to handle non-200 responses
 *
 * @package Nys_Openleg
 */
class ApiRequest {

  const DEFAULT_HOST = 'legislation.nysenate.gov';

  const DEFAULT_VERSION = '3';

  const DEFAULT_PATH_PREFIX = ['api'];

  protected static $default_api_key = '';

  /**
   * @var string
   */
  protected $api_key;

  /**
   * @var string
   */
  protected $host;

  /**
   * @var string
   */
  protected $version;

  /**
   * @var string|string[]
   */
  protected $path_prefix;

  /**
   * @var string|string[]
   */
  protected $endpoint;

  /**
   * @var \SendGrid\Client
   */
  protected $client;

  /**
   * Api constructor.
   *
   * Known options:
   *  - host:        the hostname of the server
   *  - path_prefix: the path portion after the host, but before version
   *  - version:     the API version to use
   *  - api_key:     the API key to use for just this instance
   *
   * @param string|string[] $endpoint
   * @param array $options
   */
  public function __construct($endpoint = '', array $options = []) {
    // Initialize requirements
    $this->setEndpoint($endpoint);

    // Set up the options
    $this->setApiKey($options['api_key'] ?? '');
    $this->setHost($options['host'] ?? static::DEFAULT_HOST);
    $this->setVersion($options['version'] ?? static::DEFAULT_VERSION);
    $this->setPathPrefix($options['path_prefix'] ?? static::DEFAULT_PATH_PREFIX);
  }

  /**
   * A convenience wrapper around (new self())->get().  The parameters
   * are as with __construct(), with two additional items in $options:
   *
   *  - resource: the resource parameter for get()
   *  - params:   the params parameter for get()
   *
   * @param string $endpoint
   * @param array $options
   *
   * @return object
   */
  public static function fetch($endpoint = '', array $options = []) {
    $request = new static($endpoint, $options);
    return $request->get($options['resource'] ?? NULL, $options['params'] ?? []);
  }

  /**
   * @param string $api_key
   */
  public static function useKey(string $api_key): void {
    self::$default_api_key = $api_key;
  }

  /**
   * @return string|string[]
   */
  public function getEndpoint() {
    return $this->endpoint;
  }

  /**
   * @param string|string[] $endpoint
   *
   * @return $this
   */
  public function setEndpoint($endpoint) {
    $this->endpoint = $this->buildPathArray($endpoint);
    return $this;
  }

  /**
   * Returns the source array of path parts if $as_array is true.
   * Otherwise, returns the built string.
   *
   * @return string|string[]
   */
  public function getPathPrefix($as_array = FALSE) {
    if ($as_array) {
      $ret = $this->path_prefix;
    }
    else {
      $ret = implode('/', $this->path_prefix);
    }
    return $ret;
  }

  /**
   * @param mixed $path_prefix A string path, or an array of parts.
   *
   * @return $this
   */
  public function setPathPrefix($path_prefix): ApiRequest {
    $this->path_prefix = $this->buildPathArray($path_prefix);
    return $this;
  }

  /**
   * @return string
   */
  public function getHost(): string {
    return $this->host;
  }

  /**
   * @param string $host
   *
   * @return $this
   */
  public function setHost(string $host = ''): ApiRequest {
    if (!$host) {
      $host = static::DEFAULT_HOST;
    }
    $this->host = trim($host, '/');
    return $this;
  }

  /**
   * @return string
   */
  public function getVersion(): string {
    return $this->version;
  }

  /**
   * @param string $version
   *
   * @return $this
   */
  public function setVersion(string $version): ApiRequest {
    $this->version = trim($version, '/');
    return $this;
  }

  /**
   * @param string $api_key
   *
   * @return $this
   */
  public function setApiKey(string $api_key): ApiRequest {
    $this->api_key = $api_key ?: static::$default_api_key;
    return $this;
  }

  /**
   * Instantiates an API client based on the host and path for this call.
   * The URL to be called is built as:
   *
   * https://<host>/<path_prefix>/<version>/<endpoint>/<resource>?<params>
   *
   * @param string|string[] $resource
   *   Resource to fetch; last part of the URL
   * @param array $params
   *   Query parameters to add to the call
   *
   * @return object JSON-decoded response (could be NULL)
   */
  public function get($resource = NULL, $params = []) {
    // Build the primary URL
    $url = $this->buildHost();
    $resource = implode('/', $this->buildPathArray($resource)) . '/';
    $extra_path = $this->buildEndpoint() . $resource;

    // Build URL parameters
    $params += $this->api_key ? ['key' => $this->api_key] : [];

    // Instantiate the client and make the call.
    $this->client = new Client($url, NULL, $this->getVersion(), [$extra_path]);

    // TODO: decide on error-handling here, or in caller?
    // simulate an Error response?
    $response = $this->client->get('', $params);
    return json_decode($response->body());
  }

  /**
   * Builds a host string, including host and "path prefix".  It is
   * always terminated with '/'.
   *
   * @return string
   */
  protected function buildHost() {
    $host = [
      'https:/',
      $this->getHost(),
      ($this->getPathPrefix() ?: ''),
    ];
    return implode('/', array_filter($host)) . '/';
  }

  /**
   * Builds the endpoint portion of the call's URL.  May also reset
   * the current endpoint, if a new one is passed.  The return is
   * always terminated with '/'.
   *
   * @param string|string[] $endpoint
   *
   * @return string;
   */
  protected function buildEndpoint($endpoint = NULL) {
    if (is_null($endpoint)) {
      $endpoint = $this->endpoint;
    }
    else {
      $this->setEndpoint($endpoint);
    }

    // Make sure it ends with a '/', per OpenLeg docs.
    // @see https://legislation.nysenate.gov/static/docs/html/laws.html#get-a-law-sub-document
    return implode('/', $this->buildPathArray($endpoint)) . '/';
  }

  /**
   * @param string $path
   *
   * @return array
   */
  protected function buildPathArray($path = '') {
    if (!is_array($path)) {
      $path = explode('/', trim((string) $path, '/'));
    }
    return array_values(array_filter($path));
  }

}
