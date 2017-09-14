<?php

namespace SendGrid;

/**
 * Class Response
 * @package SendGrid
 */
class Response {
  public
    $code,
    $headers,
    $raw_body,
    $body;

  /**
   * Response constructor.
   * @param $code
   * @param $headers
   * @param $raw_body
   * @param $body
   */
  public function __construct($code, $headers, $raw_body, $body) {
    $this->code = $code;
    $this->headers = $headers;
    $this->raw_body = $raw_body;
    $this->body = $body;
  }

  /**
   * Get Response code.
   *
   * @return string $this->code
   */
  public function getCode() {
    return $this->code;
  }

  /**
   * Return message headers after sending.
   *
   * @return array $this->headers
   */
  public function getHeaders() {
    return $this->headers;
  }

  /**
   * Return the raw body of the email after sending.
   *
   * @return string $this->raw_body
   */
  public function getRawBody() {
    return $this->raw_body;
  }

  /**
   * Return the body of the email after sending.
   *
   * @return string $this->body
   */
  public function getBody() {
    return $this->body;
  }
}
