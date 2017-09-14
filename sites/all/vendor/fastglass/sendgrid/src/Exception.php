<?php

namespace SendGrid;

/**
 * Class Exception
 *
 * An exception thrown when SendGrid does not return a 200.
 *
 * @package SendGrid
 */
class Exception extends \Exception {
  public function getErrors() {
    return json_decode($this->message)->errors;
  }
}
