<?php
/**
 * API specific integration
 */

namespace Fastglass\SendGrid;

use Client;
use Response;

class API {

  public $api_key,
    $api_key_id;

  public function __construct($api_key, $api_key_id) {
    $this->api_key = $api_key;
    $this->api_key_id = $api_key_id;
  }

  public function getApiKeys() {
    $client = new \Client($this->api_key);

  }
}
