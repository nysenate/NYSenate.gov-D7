<?php

/**
 * PhpRedis client specific implementation.
 */
class Redis_Client_PhpRedis implements Redis_Client_FactoryInterface {

  public function getClient($options = array()) {
    $client = new Redis;

    if (!empty($options['socket'])) {
      $client->connect($options['socket']);
    } else {
      $client->connect($options['host'], $options['port']);
    }

    if (isset($options['password'])) {
      $client->auth($options['password']);
    }

    if (isset($options['base'])) {
      $client->select($options['base']);
    }

    // Do not allow PhpRedis serialize itself data, we are going to do it
    // ourself. This will ensure less memory footprint on Redis size when
    // we will attempt to store small values.
    $client->setOption(Redis::OPT_SERIALIZER, Redis::SERIALIZER_NONE);

    return $client;
  }

  public function getName() {
    return 'PhpRedis';
  }
}
